/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef NSFW_RING_H
#define NSFW_RING_H

#include "stack_types.h"

#if defined(DPA_MODE) && defined(BUILD_STACK)
#define VALUE_LEN 24
#define VERSION_LEN 8
#ifndef USE_48BIT_ADDR
#define PERFRING_ADDR_RANGE (0xFFFFFL)
#endif
#else
#define VALUE_LEN 48 /* LLT malloc buff addr exceed 40bit, eg:0x7ffff7e0e040 */
#define VERSION_LEN 16
#ifndef USE_48BIT_ADDR
#define PERFRING_ADDR_RANGE (0xFFFFFFFFFFL)
#endif
#endif

#define VERSION_MASK ((1U << VERSION_LEN) - 1U)

/*
Ring Data has two part; Ver&Data
val is a pointer offset base on rtp_perf_ring::Addrbase, this struct support 1TB, it's enough now;
future __int128 maybe used, this type can perfectly solve the version & address rang problem.
*/
union ring_data_u {
    struct ring_data_s {
        /*
           value of data, indeed it's a pointer offset base on rtp_perf_ring::Addrbase;40bit is enough for user space
           addr ver must using 24bit, so val using 40bit; a CAS  now just support 64bit; in future, we may using
           __int128,now __int128 not support well.
         */
        volatile uintptr_t val : VALUE_LEN;
        /*
           version of data,  using 16b store version flg is more suitable for Address save, but using 16b version is too
           short, it's value range is [0-65535]; between two cpu schedule time (TM-SPACE) of one process/thread, other
           processes/threads do N times queue oper. if N > 65535, still have a chance of ABA. if using a 24bit  save
           version flg, if ABA happened, 16777216 times queue oper need done in one TM-SPACE, it's impossible for today
           cpu.
         */
        volatile uintptr_t ver : VERSION_LEN;
    } data_s;
    uintptr_t data_l;
};

typedef enum {
    NSFW_MRING_SPSC,    /* sigle producer sigle consumer ring */
    NSFW_MRING_MPSC,    /* multi producer sigle consumer ring */
    NSFW_MRING_SPMC,    /* sigle producer multi consumer ring */
    NSFW_MRING_MPMC,    /* multi producer multi consumer ring */
    NSFW_MRING_SPSC_ST  /* single producer single consumer and belong to one thread ring */
} nsfw_mpool_type;

typedef int (*ring_enq_cb)(void *owner, u32 enq_num);

/*
   this high perf Ring rely on the init value of Ring Slot;
   Ring Must init using PerfRingInit, Pool Must init using PerfPoolInit

   the addrbase is base addr for all element; now we support 1024G offset;
   for stack the Ring element is from hugepage, and the addr is in stack space.

   1. not support a ring who's element space range bigger than 1024GB
      [if one element from heep, one from stack, range will bigger than 1024GB, we not support]
   2. one more thing addr from mmap is in stack
   3. rtp_perf_ring must create by rtp_perf_ring_create/rtp_perf_pool_create
*/
struct nsfw_mem_ring {
    void *owner;
    ring_enq_cb enq_cb;
    u32 enq_num;
    u32 enq_cb_threshold;
    nsfw_mpool_type type;         // scmp, scsp, mcsp,mcmp
    u8 reserv[3];
    u32 eltsize;         // for sppool, it is the size of per buf, if is ring, eltsize is zero.
    void *addrbase;      /* Cause the Addr we support just 40b(1024G),  we using a basAddr+offset to get the real addr;
                     * ring[x].data_s.val just store offset; not used when no shared mode
                     */
    u32 size;            // size of the Ring, must 2^n
    u32 mask;            // mask of the Ring,  used mask mod Head/Tail to get real pos, must 2^n-1
    struct {
        volatile u32 head;  // Head of the Ring, used to indicat pos where to pull a val
        volatile u32 tail;  // for nshmem, shmem not used.
    } prod;
    struct {
        volatile u32 head;  // for nshmem, shmem not used.
        volatile u32 tail;  // Tail of the Ring, used to indicat pos where to push a val
    } cons;

    union ring_data_u ring[0];  // Value of Ring
};

typedef void *mring_handle;

mring_handle pool_create(nsfw_mpool_type type, u32 num, u32 useltsize, bool is_hf_used);
void pool_destroy(mring_handle handle, bool is_hf_used);
mring_handle ring_create(nsfw_mpool_type type, u32 num);
void ring_destroy(mring_handle handle);
void ring_set_enq_cb(mring_handle handle, void *owner, ring_enq_cb enq_cb, u32 enq_cb_threshold);
s32 ring_enqueue(mring_handle handle, void *box);
s32 ring_dequeue(mring_handle handle, void **box);
s32 ring_dequeuev(mring_handle handle, void **box, u32 n);
u32 ring_using_count(const mring_handle handle);
u32 ring_free_count(const mring_handle mhandle);

#endif /* NSFW_RING_DATA_H */
