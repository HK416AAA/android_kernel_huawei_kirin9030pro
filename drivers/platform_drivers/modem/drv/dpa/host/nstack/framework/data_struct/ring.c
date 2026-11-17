/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#include "ring.h"
#include "dmm_common.h"
#include "dmm_atomic.h"
#include "dmm_barrier.h"
#include "stack_sched_yield.h"
#include "stack_mem.h"
#include "stack_thread.h"

/*
this is a  multi thread/process enqueue function, please pay attention to the bellow point
1. while Enqueue corrupt,  we may lose one element; because no one to add the Head
*/
static s32 ring_mp_enqueue(mring_handle handle, void *box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    union ring_data_u expect_post_val;
    union ring_data_u cur_val;
    u32 tmp_head;
    u32 tmp_tail;
    u32 cur_head = ring->prod.head;
    u32 mask = ring->mask;
    u32 size = ring->size;
    void *prm_box = box;

#ifndef USE_48BIT_ADDR
    /* do box range check */
    if (((char *)prm_box <= (char *)ring->addrbase) ||
        ((char *)prm_box > ((char *)ring->addrbase + PERFRING_ADDR_RANGE))) {
        /* invalid addr of box, can't put in rtp_perf_ring, maybe should set a errno here */
        return -1;
    }
#endif
    do {
        /*
        if the ring is Full return directly; this not a exact check, cause we made tail++ after dequeue success.
        the thing we could make sure is ring[ring->Tail&mask] already dequeue
        */
        tmp_tail = ring->cons.tail;
        dmm_barrier();
        if ((tmp_tail + size) - cur_head == 0) {
            /*
            here we give enque a chance to recorrect the Tail,   if tail not has Data let tail++
            */
            if (ring->ring[tmp_tail & mask].data_s.val == 0) {
                (void)dmm_atomic_swap_u32(&ring->cons.tail, tmp_tail, tmp_tail + 1U);
            } else if (ring->ring[tmp_tail & mask].data_s.ver != (((uintptr_t)(cur_head - size)) & VERSION_MASK)) {
                /* if ring[tmp_tail & mask] has been enqed but deqed again, we should try the latest head and tail */
                cur_head = ring->prod.head;
                continue;
            } else {
                return 0;
            }
        }

        /*
        the old version of ring->ring[cur_head&mask] must cur_head - size, which enqueue set to this pos lasttime
        & the val must already dequeue. otherwise this pos can't enqueue;
        */
        expect_post_val.data_l = (((uintptr_t)(cur_head - size)) << VALUE_LEN);

        /*
         the new version of ring->ring[cur_head&mask] must cur_head, which enqueue set to this pos this time.
        */
#ifndef USE_48BIT_ADDR
        cur_val.data_l = ((((uintptr_t)cur_head) << VALUE_LEN) |
                (uintptr_t)((char *)prm_box - (char *)ring->addrbase));
#else
        cur_val.data_l = ((((uintptr_t)cur_head) << VALUE_LEN) |
            (((uintptr_t)((char *)prm_box)) & (((uintptr_t)-1) >> VERSION_LEN)));
#endif
        if ((ring->ring[cur_head & mask].data_s.ver == expect_post_val.data_s.ver) &&
            dmm_atomic_swap_uintptr((volatile uintptr_t *)&ring->ring[cur_head & mask].data_l,
                (uintptr_t)expect_post_val.data_l, (uintptr_t)cur_val.data_l)) {
            /* enqueue success, add Head Value now
            here we using  CAS set instead __sync_fetch_and_add(&ring->Head, 1) to assume that, if one process enque
            sucess && been killed before add Head, other process can recorrect the Head Value; one more thing the
            direction of Tail must been add-direction, so we using the condition (ring->Head - cur_head >0x80000000);
            while many thread do enque at same time, Head may not correct,exp:
            thread A get old head 10, thread A want set head to 11
            thread B get old head 10, thread B want set head to 12
            thread A do CAS && thread B do CAS at same time, thread A do CAS success;
            the result of head is 11, but the correct Value should be 12;

            then thread C get old head 11, thread C will set head to 13[cause pos 12 already has value, thread C will
            skill 12], the head will be recorrect by thread C. if no thread C, thread A& B are the last enque thread;
            the head must recorrect by the deque function. */
            tmp_head = ring->prod.head;
            dmm_barrier();
            if ((tmp_head == cur_head) || ((tmp_head - cur_head) > 0x80000000)) {
                (void)dmm_atomic_swap_u32(&ring->prod.head, tmp_head, cur_head + 1U);
            }

            break;
        }

        tmp_head = ring->prod.head;
        cur_head = ((cur_head - tmp_head) < (mask - 1U)) ? (cur_head + 1U) : tmp_head;
    } while (true);

    return 1;
}

/*
   this is a  single thread/process enqueue function
 */
static s32 ring_sp_enqueue(mring_handle handle, void *box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    union ring_data_u expect_post_val;
    union ring_data_u cur_val;
    u32 tmp_tail;
    u32 cur_head = ring->prod.head;
    u32 mask = ring->mask;
    u32 uisize = ring->size;
    void *prm_box = NULL;

    prm_box = box;
#ifndef USE_48BIT_ADDR
    if (((char *)prm_box <= (char *)ring->addrbase) ||
        ((char *)prm_box > ((char *)ring->addrbase + PERFRING_ADDR_RANGE))) {
        return -1;
    }
#endif
    do {
        tmp_tail = ring->cons.tail;
        dmm_barrier();
        if (unlikely((tmp_tail + uisize) - cur_head == 0)) {
            if (ring->ring[tmp_tail & mask].data_s.val == 0) {
                (void)dmm_atomic_swap_u32(&ring->cons.tail, tmp_tail, tmp_tail + 1U);
            } else {
                return 0;
            }
        }
        expect_post_val.data_l = (((uintptr_t)(cur_head - uisize)) << VALUE_LEN);

#ifndef USE_48BIT_ADDR
        cur_val.data_l = ((((uintptr_t)cur_head) << VALUE_LEN) |
                (uintptr_t)((char *)prm_box - (char *)ring->addrbase));
#else
        cur_val.data_l = ((((uintptr_t)cur_head) << VALUE_LEN) |
            (((uintptr_t)((char *)prm_box)) & (((uintptr_t)-1) >> VERSION_LEN)));
#endif
        if (ring->ring[cur_head & mask].data_l == expect_post_val.data_l) {
            ring->ring[cur_head & mask].data_l = cur_val.data_l;
            dmm_barrier();
            ring->prod.head = cur_head + 1U;
            break;
        }

        cur_head++;
    } while (true);

    return 1;
}

/* this is a  multi thread/process dequeue function, please pay attention to the bellow point
  */
static s32 ring_mc_dequeue(mring_handle handle, void **box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 cur_tail;
    u32 tmp_tail;
    u32 tmp_head;
    u32 mask = ring->mask;
    union ring_data_u cur_null_val;
    union ring_data_u excp_ring_val;

    cur_tail = ring->cons.tail;
    do {
        /* if ring is empty return directly */
        tmp_head = ring->prod.head;
        dmm_barrier();
        if (unlikely(cur_tail == tmp_head)) {
            /*
            here we give deque a chance to recorrect the Head,   if head has Data let Head++
            */
            if (ring->ring[tmp_head & mask].data_s.val != 0) {
                (void)dmm_atomic_swap_u32(&ring->prod.head, tmp_head, tmp_head + 1U);
            } else {
                return 0;
            }
        }
        cur_null_val.data_l = (((uintptr_t)cur_tail) << VALUE_LEN);
        excp_ring_val = ring->ring[cur_tail & mask];

        if ((cur_null_val.data_s.ver == excp_ring_val.data_s.ver) && (excp_ring_val.data_s.val != 0UL) &&
            dmm_atomic_swap_uintptr((volatile uintptr_t *)&ring->ring[cur_tail & mask].data_l,
                (uintptr_t)excp_ring_val.data_l, (uintptr_t)cur_null_val.data_l)) {
#ifndef USE_48BIT_ADDR
            *box = (void *)((char *)ring->addrbase + excp_ring_val.data_s.val);
#else
            *box = (void *)(excp_ring_val.data_s.val | (uintptr_t)(char *)ring->addrbase);
#endif
            /* dequeue success, add Tail Value now
            here we using  CAS set instead __sync_fetch_and_add(&ring->Tail, 1) to assume that, if one process dequeue
            sucess && been killed before add Tail, other process can recorrect the Tail Value; one more thing the
            direction of Tail must been add-direction, so we using the condition (rlTail - cur_tail >0x80000000); while
            multi CAS done the result value of cur_tail may not correct, but we don't care, it will be recorrect while
            next deque done. */
            tmp_tail = ring->cons.tail;
            dmm_barrier();
            if ((tmp_tail == cur_tail) || ((tmp_tail - cur_tail) > 0x80000000U)) {
                (void)dmm_atomic_swap_u32(&ring->cons.tail, tmp_tail, cur_tail + 1U);
            }

            break;
        }

        tmp_tail = ring->cons.tail;
        cur_tail = ((cur_tail - tmp_tail) < (mask - 1U)) ? (cur_tail + 1U) : tmp_tail;
    } while (true);

    return 1;
}

/*
   this is enhanced mc_ring_dequeue, support dequeue multi element one time.
*/
static s32 ring_mc_dequeuev(mring_handle handle, void **box, u32 n)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 cur_tail;
    u32 tmp_tail;
    u32 tmp_head;
    u32 uimask = ring->mask;
    union ring_data_u cur_null_val;
    union ring_data_u excp_ring_val;
    s32 deq_num = 0;
    cur_tail = ring->cons.tail;
    do {
        /* if ring is empty return directly */
        tmp_head = ring->prod.head;
        dmm_barrier();
        if (cur_tail == tmp_head) {
            /*
            here we give deque a chance to recorrect the Head,   if head has Data let Head++;
            here must done to avoid some msg can't deque.
            */
            if ((deq_num == 0) && (ring->ring[tmp_head & uimask].data_s.val != 0)) {
                (void)dmm_atomic_swap_u32(&ring->prod.head, tmp_head, tmp_head + 1U);
            } else {
                return deq_num;
            }
        }

        cur_null_val.data_l = (((uintptr_t)cur_tail) << VALUE_LEN);
        excp_ring_val = ring->ring[cur_tail & uimask];

        if ((cur_null_val.data_s.ver == excp_ring_val.data_s.ver) && (excp_ring_val.data_s.val != 0UL) &&
            dmm_atomic_swap_uintptr((volatile uintptr_t *)&ring->ring[cur_tail & uimask].data_l,
                (uintptr_t)excp_ring_val.data_l, (uintptr_t)cur_null_val.data_l)) {
#ifndef USE_48BIT_ADDR
            box[deq_num] = (void *)(((char *)ring->addrbase + excp_ring_val.data_s.val));
#else
            box[deq_num] = (void *)(excp_ring_val.data_s.val | (uintptr_t)(char *)ring->addrbase);
#endif
            /* enqueue success, add Tail Value now
            here we using  CAS set instead __sync_fetch_and_add(&ring->Tail, 1) to assume that, if one process dequeue
            sucess && been killed before add Tail, other process can recorrect the Tail Value; one more thing the
            direction of Tail must been add-direction, so we using the condition (rlTail - CurTail >0x80000000); */
            tmp_tail = ring->cons.tail;
            dmm_barrier();
            if ((tmp_tail == cur_tail) || ((tmp_tail - cur_tail) > 0x80000000U)) {
                (void)dmm_atomic_swap_u32(&ring->cons.tail, tmp_tail, cur_tail + 1U);
            }

            deq_num++;
        }

        tmp_tail = ring->cons.tail;
        cur_tail = ((cur_tail - tmp_tail) < (uimask - 1U)) ? (cur_tail + 1U) : tmp_tail;
    } while (n > (u32)deq_num);

    return deq_num;
}

/*
   this is enhanced mc_ring_dequeue, support dequeue multi element one time.
*/
static s32 ring_sc_dequeue(mring_handle handle, void **box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 cur_tail;
    u32 mask = ring->mask;
    union ring_data_u cur_null_val;
    union ring_data_u excp_ring_val;
    u32 tmp_head;

    cur_tail = ring->cons.tail;

    do {
        /* if ring is empty return directly */
        tmp_head = ring->prod.head;
        dmm_barrier();
        if (cur_tail == tmp_head) {
            /*
            here we give deque a chance to recorrect the Head,   if head has Data let Head++
            */
            if (ring->ring[tmp_head & mask].data_s.val != 0) {
                (void)dmm_atomic_swap_u32(&ring->prod.head, tmp_head, tmp_head + 1U);
            } else {
                return 0;
            }
        }
        cur_null_val.data_l = (((uintptr_t)cur_tail) << VALUE_LEN);
        excp_ring_val = ring->ring[cur_tail & mask];

        if ((cur_null_val.data_s.ver == excp_ring_val.data_s.ver) && (excp_ring_val.data_s.val != 0UL)) {
            ring->ring[cur_tail & mask].data_l = cur_null_val.data_l;
#ifndef USE_48BIT_ADDR
            *box = (void *)(((char *)ring->addrbase + excp_ring_val.data_s.val));
#else
            *box = (void *)(excp_ring_val.data_s.val | (uintptr_t)(char *)ring->addrbase);
#endif
            dmm_barrier();
            ring->cons.tail = cur_tail + 1U;
            break;
        }

        cur_tail++;
    } while (true);

    return 1;
}

/*
   this is a single thread/process dequeue function
*/
static s32 ring_sc_dequeuev(mring_handle handle, void **box, u32 n)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 cur_tail;
    u32 tmp_head;
    u32 mask = ring->mask;
    union ring_data_u cur_null_val;
    union ring_data_u excp_ring_val;
    s32 usd_eq_num = 0;

    cur_tail = ring->cons.tail;

    do {
        /* if ring is empty return directly */
        tmp_head = ring->prod.head;
        dmm_barrier();
        if (cur_tail == tmp_head) {
            /*
            here we give deque a chance to recorrect the Head,   if head has Data let Head++;
            here must done to avoid some msg can't deque.
            */
            if ((usd_eq_num == 0) && (ring->ring[tmp_head & mask].data_s.val != 0U)) {
                (void)dmm_atomic_swap_u32(&ring->prod.head, tmp_head, tmp_head + 1U);
            } else {
                return usd_eq_num;
            }
        }
        cur_null_val.data_l = (((uintptr_t)cur_tail) << VALUE_LEN);
        excp_ring_val = ring->ring[cur_tail & mask];

        /*
            the version of ring->ring[cur_tail&mask] must cur_tail&0xFFFFFF
            */
        if ((cur_null_val.data_s.ver == excp_ring_val.data_s.ver) && (excp_ring_val.data_s.val != 0UL)) {
            ring->ring[cur_tail & mask].data_l = cur_null_val.data_l;
#ifndef USE_48BIT_ADDR
            box[usd_eq_num] = (void *)(((char *)ring->addrbase + excp_ring_val.data_s.val));
#else
            box[usd_eq_num] = (void *)(excp_ring_val.data_s.val | (uintptr_t)(char *)ring->addrbase);
#endif
            dmm_barrier();
            ring->cons.tail = cur_tail + 1U;
            usd_eq_num++;
        }

        cur_tail++;
    } while ((n > (u32)usd_eq_num) && (ring->size > (u32)usd_eq_num));

    return usd_eq_num;
}

static s32 ring_singlethread_enqueue(mring_handle handle, void *box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 head;
    void *prm_box = NULL;

    /* if queue is full, just return 0 */
    if (ring->prod.head >= (ring->size + ring->cons.tail)) {
        return 0;
    }

    prm_box = box;

    head = ring->prod.head;
    ring->prod.head = head + 1U;
    ring->ring[head & ring->mask].data_s.ver = head;
    ring->ring[head & ring->mask].data_s.val = (uintptr_t)((char *)prm_box - (char *)ring->addrbase);
    return 1;
}

static s32 ring_singlethread_dequeue(mring_handle handle, void **box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 tail;

    /* if all entries are dequed return 0 */
    if (unlikely(ring->prod.head == ring->cons.tail)) {
        return 0;
    }

    tail = ring->cons.tail;
    *box = (void *)((char *)ring->addrbase + ring->ring[tail & ring->mask].data_s.val);
    ring->ring[tail & ring->mask].data_s.val = 0;
    ring->ring[tail & ring->mask].data_s.ver = tail;
    ring->cons.tail++;
    return 1;
}

static s32 ring_singlethread_dequeuev(mring_handle handle, void **box, u32 n)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    u32 tail = 0;
    u32 num = 0;

    while (num < n) {
        tail = ring->cons.tail;

        /* if all entries are dequed return 0 */
        if (unlikely(ring->prod.head == ring->cons.tail)) {
            return (int)num;
        }

        ring->cons.tail = tail + 1U;

        box[num] = (void *)((char *)ring->addrbase + ring->ring[tail & ring->mask].data_s.val);

        ring->ring[tail & ring->mask].data_s.val = 0;
        ring->ring[tail & ring->mask].data_s.ver = tail;
        num++;
    }

    return (int)num;
}

static inline void ring_init_head_tail(struct nsfw_mem_ring *ring, u32 size)
{
    ring->prod.head = 0;
    ring->prod.tail = 0;
    ring->cons.head = 0;
    ring->cons.tail = 0;
    ring->size = size;
    ring->eltsize = 0;
    ring->mask = size - 1U;
}

static inline void ring_init_data(struct nsfw_mem_ring *ring, u32 size)
{
    u32 loop;
    for (loop = 0; loop < size; loop++) {
        /*
           for a empty ring, version is the mapping head val - size
           so the empty ring's ver is loop-size;
         */
        ring->ring[loop].data_s.ver = (uintptr_t)loop - (uintptr_t)size;
        ring->ring[loop].data_s.val = 0U;
    }
}

static inline void ring_init(struct nsfw_mem_ring *ring, u32 size, nsfw_mpool_type type)
{
    if (ring == NULL) {
        return;
    }
    ring->owner = NULL;
    ring->enq_cb = NULL;
    ring->enq_num = 0;
    ring->enq_cb_threshold = 0;
    ring->type = type;
#ifdef USE_48BIT_ADDR
    /* Addrbase is used as mask the first 16 bits of ptr, which maybe 0xffff000000000000, or 0 */
    ring->addrbase = (void *)((uintptr_t)ring & (((uintptr_t)-1) << VALUE_LEN));
#else
    /* if shmem, addrbase already changed to primary memory address */
    ring->addrbase = ring;
#endif
    ring_init_head_tail(ring, size);
    ring_init_data(ring, size);
}

mring_handle pool_create(nsfw_mpool_type type, u32 num, u32 useltsize, bool is_hf_used)
{
    size_t len;
    u32 usnum = align32pow2(num);
    u32 uselt_size = useltsize;
    struct nsfw_mem_ring *pringhead = NULL;
    u32 uscnt;
    char *pmz = NULL;
    len = sizeof(struct nsfw_mem_ring) + ((size_t)usnum * sizeof(union ring_data_u));
    pringhead = (struct nsfw_mem_ring *)stack_vmalloc(len);
    if (pringhead == NULL) {
        return NULL;
    }
    stack_memleak_not_leak(pringhead);
    if (is_hf_used) {
        pmz = (char *)stack_tcm_alloc((size_t)usnum * uselt_size);
    } else {
        pmz = (char *)stack_vmalloc((size_t)usnum * uselt_size);
    }
    if (pmz == NULL) {
        stack_vfree(pringhead);
        return NULL;
    }
    stack_memleak_free(pmz);
    ring_init(pringhead, usnum, type);
    pringhead->eltsize = useltsize;
    pringhead->addrbase = (void *)(uintptr_t)((uintptr_t)pmz & (((uintptr_t)-1) << VALUE_LEN));

    for (uscnt = 0; uscnt < usnum; uscnt++) {
        if (ring_enqueue(pringhead, (void *)pmz) == 0) {
            /* error */
        }

        pmz = pmz + uselt_size;
    }

    return pringhead;
}

void pool_destroy(mring_handle handle, bool is_hf_used)
{
    (void)handle;
    (void)is_hf_used;
}

mring_handle ring_create(nsfw_mpool_type type, u32 num)
{
    size_t len;
    u32 usnum = align32pow2(num);
    struct nsfw_mem_ring *pringhead = NULL;
    len = sizeof(struct nsfw_mem_ring) + (usnum * sizeof(union ring_data_u));
    pringhead = (struct nsfw_mem_ring *)stack_vmalloc(len);
    if (pringhead == NULL) {
        return NULL;
    }

    ring_init(pringhead, usnum, type);
    return pringhead;
}

void ring_destroy(mring_handle handle)
{
    stack_vfree(handle);
}

void ring_set_enq_cb(mring_handle handle, void *owner, ring_enq_cb enq_cb, u32 enq_cb_threshold)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    ring->owner = owner;
    ring->enq_cb = enq_cb;
    ring->enq_cb_threshold = enq_cb_threshold;
}

s32 ring_enqueue(mring_handle handle, void *box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    s32 ret = 0;
    stack_local_bh_disable();
    switch (ring->type) {
        case NSFW_MRING_SPSC:
        case NSFW_MRING_SPMC:
            ret = ring_sp_enqueue(handle, box);
            break;
        case NSFW_MRING_MPSC:
        case NSFW_MRING_MPMC:
            ret = ring_mp_enqueue(handle, box);
            break;
        case NSFW_MRING_SPSC_ST:
            ret = ring_singlethread_enqueue(handle, box);
            break;
        default:
            break;
    }
    stack_local_bh_enable();

    if (ret == 1 && ring->enq_cb) {
        ring->enq_num += 1;
        if (ring->enq_num >= ring->enq_cb_threshold) {
            if (ring->enq_cb(ring->owner, ring->enq_num) == 0) {
                ring->enq_num = 0;
            }
        }
    }

    return ret;
}

s32 ring_dequeue(mring_handle handle, void **box)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    s32 ret = 0;
    stack_local_bh_disable();
    switch (ring->type) {
        case NSFW_MRING_SPSC:
        case NSFW_MRING_MPSC:
            ret = ring_sc_dequeue(handle, box);
            break;
        case NSFW_MRING_SPMC:
        case NSFW_MRING_MPMC:
            ret = ring_mc_dequeue(handle, box);
            break;
        case NSFW_MRING_SPSC_ST:
            ret = ring_singlethread_dequeue(handle, box);
            break;
        default:
            break;
    }
    stack_local_bh_enable();
    return ret;
}

s32 ring_dequeuev(mring_handle handle, void **box, u32 n)
{
    struct nsfw_mem_ring *ring = (struct nsfw_mem_ring *)handle;
    s32 ret = 0;
    stack_local_bh_disable();
    switch (ring->type) {
        case NSFW_MRING_SPSC:
        case NSFW_MRING_MPSC:
            ret = ring_sc_dequeuev(handle, box, n);
            break;
        case NSFW_MRING_SPMC:
        case NSFW_MRING_MPMC:
            ret = ring_mc_dequeuev(handle, box, n);
            break;
        case NSFW_MRING_SPSC_ST:
            ret = ring_singlethread_dequeuev(handle, box, n);
            break;
        default:
            break;
    }
    stack_local_bh_enable();

    return ret;
}

u32 ring_using_count(const mring_handle handle)
{
    const struct nsfw_mem_ring *temp = NULL;
    u32 thead;
    u32 ttail;
    u32 using_count;
    temp = (const struct nsfw_mem_ring *)handle;
    /*
     * avoid multi-thread issue, here we should get cons.tail firstly,
     * get prod.head later, because tail and head is always++
     */
    ttail = temp->cons.tail;
    thead = temp->prod.head;

    using_count = thead - ttail;
    if (using_count > temp->size) {
        using_count = 0;
    }

    return using_count;
}

u32 ring_free_count(const mring_handle mhandle)
{
    if (mhandle != NULL) {
        const struct nsfw_mem_ring *ring = (const struct nsfw_mem_ring *)mhandle;
        u32 using_count = ring->size - (ring->prod.head - ring->cons.tail);
        if ((s32)using_count >= 0) {
            return using_count;
        }
    }

    return 0;
}

