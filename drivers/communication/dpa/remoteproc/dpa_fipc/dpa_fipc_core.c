#include "bsp_dpa.h"
#include "dpa_fipc_device.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_err_code.h"
#include "dpa_fipc_plat.h"
#include "bsp_dpa_fipc.h"
#include "dpa_fipc_core.h"
#include "dpa_fipc_mntn.h"

struct dpa_fipc_channel *g_fast_phychnl[DPA_FIPC_MAX_PIPES_NUM] = {NULL};


int dpa_fipc_pipe_align_fixed(const unsigned int depth, unsigned int fixed_len, unsigned int *p_off)
{
    unsigned int off = *(p_off);
    if (off + fixed_len >= depth) {
        off = off + fixed_len - depth;
    } else {
        off = off + fixed_len;
    }
    *p_off = off;
    return 0;
}

/* opipe中还有多少剩余空间 */
static inline u32 dpa_fipc_opipe_free_space_get(struct dpa_fipc_channel *pchannel)
{
    u32 w_off = pchannel->p_pipe_config->wptr;
    u32 r_off = *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr);
    u32 bufsz = pchannel->p_pipe_config->depth;
    dpa_fipc_trace("w_off : 0x%x  r_off : 0x%x\n", (unsigned)w_off, (unsigned)r_off);
    return (w_off >= r_off) ? (bufsz - w_off + r_off) : (r_off - w_off);
}

/* ipipe中还有多少数据未读取 */
static inline u32 dpa_fipc_ipipe_used_space_get(struct dpa_fipc_channel *pchannel)
{
    u32 r_off = pchannel->p_pipe_config->rptr;
    u32 w_off = *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr);
    u32 bufsz = pchannel->p_pipe_config->depth;
    dpa_fipc_trace("w_off : 0x%x  r_off : 0x%x\n", (unsigned)w_off, (unsigned)r_off);
    return (w_off >= r_off) ? (w_off - r_off) : (bufsz + w_off - r_off);
}

u32 bsp_dpa_fipc_chn_recv_used_space_get(dpa_fipc_chn_t chn)
{
    return dpa_fipc_ipipe_used_space_get(chn);
}

static int dpa_fipc_opipe_put_to_ringbuf(const struct dpa_fipc_channel *pchannel, const u8 *data, u32 data_len,
    u32 *pw_off)
{
    u8 *ringbuf = (u8 *)pchannel->p_pipe_config->ringbuf_va;
    u32 w_off = *(pw_off);
    u32 r_off = *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr);
    u32 bufsz = pchannel->p_pipe_config->depth;

    u32 tail_sz, wrapped_sz;

    if (bufsz < w_off || bufsz < r_off) {
        /* big error; */
        return DPA_FIPC_ERR_OUT_OF_RANGE;
    }
    /* w_off,r_off never be same as bufsz */
    if (w_off >= r_off) {
        tail_sz = bufsz - w_off;
        wrapped_sz = r_off; /* may be zero */
    } else {
        tail_sz = r_off - w_off;
        wrapped_sz = 0;
    }

    /*
     * 长度不能等于剩余空间，否则写指针会更新为和读指针相同的值,造成芯片认为buf为空
     */
    if (tail_sz + wrapped_sz <= data_len) {
        return DPA_FIPC_ERR_BAD_LEN;
    }

    if (tail_sz >= data_len) {
        if (memcpy_s(ringbuf + w_off, tail_sz, data, data_len)) {
            return DPA_FIPC_ERR_MEM_OP_FAILED;
        }
        w_off = (w_off + data_len == bufsz) ? 0 : (w_off + data_len);
    } else {
        if (memcpy_s(ringbuf + w_off, tail_sz, data, tail_sz)) {
            return DPA_FIPC_ERR_MEM_OP_FAILED;
        }
        if (memcpy_s(ringbuf, wrapped_sz, data + tail_sz, data_len - tail_sz)) { /*lint !e613*/
            return DPA_FIPC_ERR_MEM_OP_FAILED;
        }
        w_off = data_len - tail_sz;
    }
    *(pw_off) = w_off;
    return 0;
}

static int dpa_fipc_ipipe_get_from_ringbuf(const struct dpa_fipc_channel *pchannel, u8 *data, u32 data_len,
    u32 *pr_off)
{
    u8 *ringbuf = (u8 *)pchannel->p_pipe_config->ringbuf_va;
    u32 r_off = (*pr_off);
    u32 w_off = *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr);
    u32 bufsz = pchannel->p_pipe_config->depth;

    u32 tail_sz, wrapped_sz;
    mb();
    if (bufsz < w_off || bufsz < r_off) {
        /* big error; */
        return DPA_FIPC_ERR_OUT_OF_RANGE;
    }
    /* w_off,r_off never be same as bufsz */
    if (w_off >= r_off) {
        tail_sz = w_off - r_off; /* may be zero */
        wrapped_sz = 0;
    } else {
        tail_sz = bufsz - r_off;
        wrapped_sz = w_off; /* may be zero */
    }
    if (tail_sz + wrapped_sz == 0) {
        return 0;
    }
    /* big error should be detected by this function caller */
    if (tail_sz + wrapped_sz < data_len) {
        return DPA_FIPC_ERR_BAD_LEN;
    }
    if (tail_sz >= data_len) {
        if (memcpy_s(data, data_len, ringbuf + r_off, data_len)) {
            return DPA_FIPC_ERR_MEM_OP_FAILED;
        }
        r_off = (r_off + data_len == bufsz) ? 0 : (r_off + data_len);
    } else {
        if (memcpy_s(data, data_len, ringbuf + r_off, tail_sz)) {
            return DPA_FIPC_ERR_MEM_OP_FAILED;
        }
        if (memcpy_s(data + tail_sz, data_len - tail_sz, ringbuf, data_len - tail_sz)) {
            return DPA_FIPC_ERR_MEM_OP_FAILED;
        }
        r_off = data_len - tail_sz;
    }
    (*pr_off) = r_off;
    return 0;
}


int dpa_fipc_opipe_align_fixed(const struct dpa_fipc_channel *pchannel, u32 fixed_len, u32 *pw_off)
{
    u32 w_off = *(pw_off);
    if (w_off + fixed_len >= pchannel->p_pipe_config->depth) {
        w_off = w_off + fixed_len - pchannel->p_pipe_config->depth;
    } else {
        w_off = w_off + fixed_len;
    }
    *pw_off = w_off;
    return 0;
}

int dpa_fipc_ipipe_align_fixed(const struct dpa_fipc_channel *pchannel, u32 fixed_len, u32 *pr_off)
{
    u32 r_off = *(pr_off);
    if (r_off + fixed_len >= pchannel->p_pipe_config->depth) {
        r_off = r_off + fixed_len - pchannel->p_pipe_config->depth;
    } else {
        r_off = r_off + fixed_len;
    }
    *pr_off = r_off;
    return 0;
}

int bsp_dpa_fipc_chn_attr_init(dpa_fipc_chn_attr_t *pattr)
{
    int ret;
    if (pattr == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    ret = memset_s(pattr, sizeof(dpa_fipc_chn_attr_t), 0, sizeof(dpa_fipc_chn_attr_t));
    return ret;
}


int dpa_fipc_blk2ring_blk_head_fill(void *blk_head, unsigned long long src, unsigned short msg_len, unsigned int flags)
{
    struct dpa_fipc_bd_2_s *hdr = (struct dpa_fipc_bd_2_s *)blk_head;
    if (blk_head == NULL || msg_len == 0) {
        return DPA_FIPC_ERR_EIO;
    }
    hdr->cfg.OI_pos = (flags & DPA_FIPC_SEND_FLAGS_NODONENOTIFY) ? 0 : 1;
    hdr->cfg.II_pos = (flags & DPA_FIPC_SEND_FLAGS_NOARRVNOTIFY) ? 0 : 1;
    hdr->cfg.S_pos = 1;
    hdr->cfg.msg_len = msg_len;
    hdr->src_addr_l = (uintptr_t)src;
    hdr->ptr.src_addr_h = (uintptr_t)((src >> 32) & 0xff);
    return DPA_FIPC_OK;
}

int dpa_fipc_fill_hdr(struct dpa_fipc_channel *pchannel, struct dpa_fipc_send_packet *ppacket, struct dpa_fipc_send_helper *phelper)
{
    unsigned int blkidx;
    unsigned int total_msglen = 0;
    unsigned int pkt_struct_len = sizeof(struct dpa_fipc_packet);

    dpa_fipc_blk_desc_t *pblkdesc = (dpa_fipc_blk_desc_t *)phelper->send_desc;
    for (blkidx = 0; blkidx < pblkdesc->cnt; blkidx++) {
        if (pblkdesc->datablk[blkidx].buf == NULL || pblkdesc->datablk[blkidx].len == 0) { /* 不支持空消息发送 */
            dpa_fipc_err("dpa_fipc fill hdr failed: bad param\n");
            return DPA_FIPC_ERR_EIO;
        }
        total_msglen = total_msglen + pblkdesc->datablk[blkidx].len;
    }

    ppacket->bd_head.cfg.msg_len =
        (unsigned short)(pkt_struct_len + dpa_fipc_roundup(total_msglen, DPA_FIPC_CHN_DEFAULT_ALIGNBYTES));
    ppacket->bd_head.cfg.II_pos = 1;
    ppacket->data_head.user_id = pchannel->pipe_id;
    ppacket->data_head.len = (unsigned short)total_msglen;

    ppacket->data_head.align_bytes = DPA_FIPC_CHN_DEFAULT_ALIGNBYTES;
    ppacket->data_head.ldrvchn_id = pchannel->core_id;

    phelper->head_len = pkt_struct_len;
    phelper->total_msglen = total_msglen;
    phelper->write_len = ppacket->bd_head.cfg.msg_len + sizeof(struct dpa_fipc_bd1_s);

    return DPA_FIPC_OK;
}

int dpa_fipc_read_hdr(struct dpa_fipc_channel *pchannel, struct dpa_fipc_packet *ppkthdr, struct dpa_fipc_recv_helper *phelper)
{
    unsigned int used_len;
    int ret;
    unsigned int pkt_struct_len = sizeof(struct dpa_fipc_packet);
    used_len = dpa_fipc_ipipe_used_space_get(pchannel);
    dpa_fipc_trace("ipipe used length 0x%x\n", (unsigned)used_len);
    if (used_len == 0) {
        return DPA_FIPC_OK;
    }
    if (used_len < pkt_struct_len) {
        /* big error */
        return DPA_FIPC_ERR_BAD_LEN;
    }
    phelper->rptr = pchannel->p_pipe_config->rptr;
    ret = dpa_fipc_ipipe_get_from_ringbuf(pchannel, (unsigned char *)ppkthdr, sizeof(*ppkthdr), &phelper->rptr);
    if (ret) {
        return ret;
    }
    if (ppkthdr->align_bytes != DPA_FIPC_CHN_DEFAULT_ALIGNBYTES) {
        return DPA_FIPC_ERR_CHECK_FAILED;
    }
    if (used_len < dpa_fipc_roundup((unsigned int)(ppkthdr->len), DPA_FIPC_CHN_DEFAULT_ALIGNBYTES) + pkt_struct_len) {
        return DPA_FIPC_ERR_BAD_LEN;
    }
    return DPA_FIPC_OK;
}

int dpa_fipc_read_payload(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel, struct dpa_fipc_packet *ppkthdr,
    struct dpa_fipc_recv_helper *phelper)
{
    int ret = 0;
    unsigned int ret_len = 0;
    unsigned int rptr = phelper->rptr;
    if (phelper->len < ppkthdr->len) {
        ret_len = phelper->len;
    } else {
        ret_len = ppkthdr->len;
    }
    ret = dpa_fipc_ipipe_get_from_ringbuf(pchannel, (unsigned char *)phelper->buf, ret_len, &rptr);
    if (ret == 0) {
        dpa_fipc_pipe_align_fixed(pchannel->p_pipe_config->depth,
            dpa_fipc_roundup(ppkthdr->len, DPA_FIPC_CHN_DEFAULT_ALIGNBYTES) - ppkthdr->len, &rptr);
        pchannel->p_pipe_config->rptr = rptr; /* round check */
        dpa_fipc_ipipe_rptr_update(pdev->base_va, pchannel->pipe_id, pchannel->p_pipe_config->rptr);
        return (int)ret_len;
    }
    return ret;
}

int dpa_fipc_read_payload_raw(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel, void *buf, unsigned int len)
{
    int ret = 0;
    unsigned int ret_len = 0;
    unsigned int used_len = 0;
    unsigned int rptr = 0;

    if (pchannel->p_pipe_config == NULL || len == 0 || buf == NULL) {
        dpa_fipc_trace("dpa_fipc_read_payload_raw invalid input\n");
        return DPA_FIPC_ERR_EIO;
    }
    rptr = pchannel->p_pipe_config->rptr;
    used_len = dpa_fipc_ipipe_used_space_get(pchannel);
    if (used_len == 0) {
        return 0;
    }
    if (used_len < len) {
        ret_len = used_len;
    } else {
        ret_len = len;
    }
    ret = dpa_fipc_ipipe_get_from_ringbuf(pchannel, (unsigned char *)buf, ret_len, &rptr);
    if (ret == 0) {
        pchannel->p_pipe_config->rptr = rptr; /* round check */
        dpa_fipc_ipipe_rptr_update(pdev->base_va, pchannel->pipe_id, pchannel->p_pipe_config->rptr);
        return (int)ret_len;
    }
    return ret;
}

void dpa_fipc_opipe_en(void *base_va, struct dpa_fipc_pipe_config *p_opipe_config, u32 core_id)
{
    dpa_fipc_opipe_startup(base_va, p_opipe_config);
    dpa_fipc_opipe_devint_en(base_va, p_opipe_config->id, p_opipe_config->int_level);
    dpa_fipc_opipe_coreint_en(base_va, p_opipe_config->id, core_id, DPA_FIPC_INT_OFFSET);
    dpa_fipc_opipe_local_en(base_va, p_opipe_config->id);
}

static int dpa_fipc_opipe_open(void *base_va, struct dpa_fipc_pipe_config *p_opipe_config, u32 core_id, u32 int_level)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (base_va == NULL || p_opipe_config == NULL) {
        dpa_fipc_err("dpa_msg_opipe_en input failed!\n");
        return DPA_FIPC_ERR_EIO;
    }

    // 填写opipe_config配置
    if (p_opipe_config->ringbuf_va == NULL) {
        dpa_fipc_err("dpa_msg_opipe_en ringbuf malloc failed!\n");
        return DPA_FIPC_ERR_ENOMEM;
    }
    p_opipe_config->pipe_uctrl.opipe_uctrl.union_stru.priorv2 = 0x3;
    p_opipe_config->pipe_uctrl.opipe_uctrl.union_stru.priorv3 = 0x3;
    p_opipe_config->pipe_uctrl.opipe_uctrl.union_stru.type = 0;

    // 推送地址申请
    p_opipe_config->ptr_vaddr = &pdev->push_ptr_va[p_opipe_config->id];
    *p_opipe_config->ptr_vaddr = p_opipe_config->rptr;
    p_opipe_config->ptr_paddr = pdev->push_ptr_pa + sizeof(u32) * p_opipe_config->id;

    p_opipe_config->int_level = int_level | DPA_FIPC_INT_WR_PIPE_ERR;

    dpa_fipc_opipe_en(base_va, p_opipe_config, core_id);
    return 0;
}

void dpa_fipc_ipipe_en(void *base_va, struct dpa_fipc_pipe_config *p_ipipe_config, u32 core_id)
{
    dpa_fipc_ipipe_startup(base_va, p_ipipe_config);
    dpa_fipc_ipipe_devint_en(base_va, p_ipipe_config->id, p_ipipe_config->int_level);
    dpa_fipc_ipipe_coreint_en(base_va, p_ipipe_config->id, core_id, DPA_FIPC_INT_OFFSET);
    dpa_fipc_ipipe_local_en(base_va, p_ipipe_config->id);
    dpa_fipc_ipipe_devint_en(base_va, p_ipipe_config->id, DPA_FIPC_INT_RD_PIPE_WAKEUP);
}

static int dpa_fipc_ipipe_open(void *base_va, struct dpa_fipc_pipe_config *p_ipipe_config, u32 core_id)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (base_va == NULL || p_ipipe_config == NULL) {
        dpa_fipc_err("dpa_msg_ipipe_en input failed!\n");
        return DPA_FIPC_ERR_EIO;
    }
    // 填写ipipe_config配置
    if (p_ipipe_config->ringbuf_va == NULL) {
        dpa_fipc_err("dpa_msg_ipipe_en ringbuf malloc failed!\n");
        return DPA_FIPC_ERR_ENOMEM;
    }

    p_ipipe_config->ptr_vaddr = &pdev->push_ptr_va[p_ipipe_config->id];
    *p_ipipe_config->ptr_vaddr = p_ipipe_config->wptr;
    p_ipipe_config->ptr_paddr = pdev->push_ptr_pa + sizeof(u32) * p_ipipe_config->id;

    p_ipipe_config->pipe_uctrl.ipipe_uctrl.union_stru.prior = 1;
    p_ipipe_config->pipe_uctrl.ipipe_uctrl.union_stru.type = 0;
    p_ipipe_config->int_level = DPA_FIPC_INT_RD_DATA_ARV;
    if (p_ipipe_config->pipe_uctrl.ipipe_uctrl.union_stru.arv_timeout) {
        p_ipipe_config->int_level |= DPA_FIPC_INT_RD_ARV_TIMEOUT;
    }
    if (p_ipipe_config->pipe_uctrl.ipipe_uctrl.union_stru.up_thrh) {
        p_ipipe_config->int_level |= DPA_FIPC_INT_RD_OVERFLOW;
    }
    dpa_fipc_ipipe_en(base_va, p_ipipe_config, core_id);
    return 0;
}

// 不应该处理open失败情况，故在失败的流程中，未保证所有已经分配的内存均进行了回收
int dpa_fipc_device_phychn_open(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *p_phychnl, dpa_fipc_chn_attr_t *attr)
{
    int ret = 0;
    u32 int_level = 0;
    struct dpa_fipc_pipe_config *p_pipe_cfg = NULL;
    if (pdev == NULL || p_phychnl == NULL) {
        dpa_fipc_err("dpa_msg_device_phychn_open input failed!\n");
        return DPA_FIPC_ERR_EIO;
    }

    p_pipe_cfg = (struct dpa_fipc_pipe_config *)dpa_fipc_malloc(sizeof(struct dpa_fipc_pipe_config));
    if (p_pipe_cfg == NULL) {
        return DPA_FIPC_ERR_ENOMEM;
    }
    (void)memset_s(p_pipe_cfg, sizeof(struct dpa_fipc_pipe_config), 0, sizeof(struct dpa_fipc_pipe_config));
    p_phychnl->type = attr->type;
    p_phychnl->cbk = attr->cbk;
    p_phychnl->cbk_arg = attr->cbk_arg;
    p_phychnl->depth = attr->size;
    p_pipe_cfg->id = p_phychnl->pipe_id;
    p_pipe_cfg->depth = p_phychnl->depth;
    p_pipe_cfg->ringbuf_va = attr->va;
    p_pipe_cfg->ringbuf_pa = attr->ga;

    p_phychnl->p_pipe_config = p_pipe_cfg;
    spin_lock_init(&p_phychnl->lock);
    if (p_phychnl->type == DPA_FIPC_CHNL_SEND) {
        if (attr->cbk) {
            int_level = DPA_FIPC_INT_WR_DATA_DONE;
        }
        p_pipe_cfg->pipe_uctrl.opipe_uctrl.union_stru.dn_thrh = attr->underflow_th;
        ret = dpa_fipc_opipe_open(pdev->base_va, p_phychnl->p_pipe_config, p_phychnl->core_id, int_level);
    } else {
        // 填写ipipe_config配置
        p_pipe_cfg->pipe_uctrl.ipipe_uctrl.union_stru.up_thrh = attr->overflow_th;
        p_pipe_cfg->pipe_uctrl.ipipe_uctrl.union_stru.arv_timeout = attr->timeout_val;
        ret = dpa_fipc_ipipe_open(pdev->base_va, p_phychnl->p_pipe_config, p_phychnl->core_id);
    }
    if (ret) {
        dpa_fipc_err("dpa_fipc_device_phychn_open phy chnl probe failed!\n");
        return ret;
    }
    p_phychnl->state = DPA_FIPC_CHN_OPEN;
    return 0;
}

int bsp_dpa_fipc_chn_open(dpa_fipc_chn_t *pchn_hdl, dpa_fipc_chn_attr_t *pattr)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = NULL;
    int ret = DPA_FIPC_OK;

    dpa_fipc_trace("bsp_dpa_fipc_chn_open chnid=0x%x(%d)\n", pattr->chnid, pattr->type);
    if (pattr->chnid >= pdev->pipepair_cnt) {
        return DPA_FIPC_ERR_BAD_CHANNEL;
    }
    /* get device and channel */
    pchannel = pdev->p_phychnl[pattr->chnid];
    if (pchannel == NULL) {
        return DPA_FIPC_ERR_BAD_CHANNEL;
    }

    *pchn_hdl = pchannel;
    ret = dpa_fipc_device_phychn_open(pdev, pchannel, pattr);
    if (ret) {
        return ret;
    }

    return DPA_FIPC_OK;
}

static int dpa_fipc_write_packet(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel, struct dpa_fipc_send_packet *ppacket,
    struct dpa_fipc_send_helper *phelper)
{
    u32 space_left;
    unsigned int blkidx;
    unsigned int total_msglen;
    unsigned int wptr;
    dpa_fipc_blk_desc_t *pblkdesc = (dpa_fipc_blk_desc_t *)phelper->send_desc;

    total_msglen = phelper->total_msglen;

    space_left = dpa_fipc_opipe_free_space_get(pchannel);
    if (total_msglen >= space_left) {
        dpa_fipc_err("opipe nospace,write len: 0x%x, space left: 0x%x, send fail\n", total_msglen, space_left);
        return DPA_FIPC_ERR_EAGAIN;
    }

    wptr = pchannel->p_pipe_config->wptr;
    if (dpa_fipc_opipe_put_to_ringbuf(pchannel, (unsigned char *)ppacket, sizeof(*ppacket), &wptr)) {
        return DPA_FIPC_ERR_WRITE_FAILED;
    }

    for (blkidx = 0; blkidx < pblkdesc->cnt; blkidx++) {
        if (dpa_fipc_opipe_put_to_ringbuf(pchannel, pblkdesc->datablk[blkidx].buf, pblkdesc->datablk[blkidx].len,
            &wptr)) {
            return DPA_FIPC_ERR_WRITE_FAILED;
        }
    }
    dpa_fipc_pipe_align_fixed(pchannel->p_pipe_config->depth,
        dpa_fipc_roundup(total_msglen, DPA_FIPC_CHN_DEFAULT_ALIGNBYTES) - total_msglen, &wptr);

    pchannel->p_pipe_config->wptr = wptr;
    dpa_fipc_opipe_wptr_update(pdev->base_va, pchannel->pipe_id, pchannel->p_pipe_config->wptr);
    dpa_fipc_trace("dpa_fipc_opipe_wptr_update wptr: 0x%x\n,rptr:0x%x ", (unsigned)wptr,
        (unsigned)*(volatile unsigned int *)(pchannel->p_pipe_config->ptr_vaddr));
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_chn_blks_send(dpa_fipc_chn_t chn_hdl, dpa_fipc_blk_desc_t *pblkdesc)
{
    int ret;
    unsigned long lockflag;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;
    struct dpa_fipc_send_packet packet = { { { 0 } }, { 0 } };
    struct dpa_fipc_send_helper helper;

    if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_OPEN) {
        dpa_fipc_err("invaild param, bad chn_hdl\n");
        return DPA_FIPC_ERR_EIO;
    }

    helper.send_desc = pblkdesc;
    ret = dpa_fipc_fill_hdr(pchannel, &packet, &helper);
    if (ret) {
        return ret;
    }

    spin_lock_irqsave(&pchannel->lock, lockflag);
    ret = dpa_fipc_write_packet(pdev, pchannel, &packet, &helper);
    dpa_fipc_debug_info_update_send(pchannel->pipe_id, ret);
    if (ret) {
        dpa_fipc_mntn_report_pipe_regs(pdev, pchannel->pipe_id);
    }
    spin_unlock_irqrestore(&pchannel->lock, lockflag);
    if (ret) {
        return ret;
    }
    return (int)packet.data_head.len;
}

static int dpa_fipc_write_packet_raw(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel,
    void *msg, u32 len)
{
    u32 space_left;
    u32 wptr;

    space_left = dpa_fipc_opipe_free_space_get(pchannel);
    if (len >= space_left) {
        dpa_fipc_err("opipe nospace,write len: 0x%x, space left: 0x%x, send fail\n", len, space_left);
        return DPA_FIPC_ERR_EAGAIN;
    }

    wptr = pchannel->p_pipe_config->wptr;
    if (dpa_fipc_opipe_put_to_ringbuf(pchannel, (u8 *)msg, len, &wptr)) {
        dpa_fipc_err("opipe_put_to_ringbuf failed @%d\n", __LINE__);
        return DPA_FIPC_ERR_WRITE_FAILED;
    }

    pchannel->p_pipe_config->wptr = wptr;
    dpa_fipc_opipe_wptr_update(pdev->base_va, pchannel->pipe_id, pchannel->p_pipe_config->wptr);
    return 0;
}

int bsp_dpa_fipc_chn_blk2ring_send(dpa_fipc_chn_t pchn_hdl, unsigned long long data_pa, unsigned int len, u32 flags)
{
    unsigned long lk_flags;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = pchn_hdl;
    struct dpa_fipc_bd_2_s pkthdr = { 0 };
    int ret;

    if (pdev == NULL || pchannel == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    if (pchannel->state != DPA_FIPC_CHN_OPEN) {
        return DPA_FIPC_ERR_BAD_STATE;
    }
    ret = dpa_fipc_blk2ring_blk_head_fill(&pkthdr, data_pa, len, flags);
    if (ret) {
        dpa_fipc_err("dpa_fipc_fill_hdr_bd2 ret[%d]!\n", ret);
        return DPA_FIPC_ERR_WRITE_FAILED;
    }
    spin_lock_irqsave(&pchannel->lock, lk_flags);
    ret = dpa_fipc_write_packet_raw(pdev, pchannel, (void *)&pkthdr, sizeof(struct dpa_fipc_bd_2_s));
    dpa_fipc_debug_info_update_send(pchannel->pipe_id, ret);
    if (ret) {
        dpa_fipc_mntn_report_pipe_regs(pdev, pchannel->pipe_id);
    }
    spin_unlock_irqrestore(&pchannel->lock, lk_flags);
    return ret;
}

int bsp_dpa_fipc_chn_recv(dpa_fipc_chn_t chn_hdl, void *buf, unsigned len)
{
    int ret;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;
    struct dpa_fipc_packet pkthdr = { 0 };
    struct dpa_fipc_recv_helper helper;

    if (pchannel == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    helper.buf = buf;
    helper.len = len;
    ret = dpa_fipc_read_hdr(pchannel, &pkthdr, &helper);
    if (ret) {
        return ret;
    }
    return dpa_fipc_read_payload(pdev, pchannel, &pkthdr, &helper);
}


int bsp_dpa_fipc_chn_recv_raw(dpa_fipc_chn_t chn_hdl, void *buf, unsigned len)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL) {
        dpa_fipc_trace("bsp_dpa_fipc_chn_recv_raw invalid cahnnel\n");
        return DPA_FIPC_ERR_EIO;
    }

    return dpa_fipc_read_payload_raw(pdev, pchannel, buf, len);
}

int bsp_dpa_fipc_chn_ioctl(dpa_fipc_chn_t chn_hdl, unsigned req, void *arg, unsigned int size)
{
    struct dpa_fipc_channel *pchannel = chn_hdl;
    unsigned int rptr;
    struct dpa_fipc_packet pkthdr = { 0 };
    ioctl_dpa_nxtpkt *pktinfo = (ioctl_dpa_nxtpkt *)arg;

    if (pchannel == NULL || pchannel->p_pipe_config == NULL) {
        return DPA_FIPC_ERR_EIO;
    }

    rptr = pchannel->p_pipe_config->rptr;
    if (dpa_fipc_ipipe_get_from_ringbuf(pchannel, (unsigned char *)&pkthdr, sizeof(pkthdr), &rptr)) {
        pktinfo->len = 0;
        pktinfo->pkthdl = DPA_FIPC_DFT_INVAILD_VALUE; /* wptr和rptr不可能到这里 */
    } else {
        pktinfo->len = pkthdr.len;
        pktinfo->pkthdl = pchannel->p_pipe_config->rptr;
    }
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_chn_rptr_get(dpa_fipc_chn_t chn_hdl, unsigned int *rptr)
{
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if  (rptr == NULL || pchannel == NULL) {
        return DPA_FIPC_ERR_EIO;
    }

    if (pchannel->type == DPA_FIPC_CHNL_SEND && pchannel->p_pipe_config != NULL) {
        *rptr = *(volatile unsigned int *)pchannel->p_pipe_config->ptr_vaddr;
        return 0;
    }
    return DPA_FIPC_ERR_ENXIO;
}

int bsp_dpa_fipc_channel_int_en(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL) {
        return DPA_FIPC_ERR_ENXIO;
    }

    if (pchannel->type == DPA_FIPC_CHNL_SEND) {
        pchannel->p_pipe_config->int_level =
            dpa_fipc_opipe_devint_en(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_WR_DATA_DONE);
    } else {
        pchannel->p_pipe_config->int_level =
            dpa_fipc_ipipe_devint_en(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_RD_DATA_ARV);
    }
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_int_dis(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL) {
        return DPA_FIPC_ERR_ENXIO;
    }

    if (pchannel->type == DPA_FIPC_CHNL_SEND) {
        pchannel->p_pipe_config->int_level =
            dpa_fipc_opipe_devint_dis(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_WR_DATA_DONE);
    } else {
        pchannel->p_pipe_config->int_level =
            dpa_fipc_ipipe_devint_dis(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_RD_DATA_ARV);
    }
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_overflow_int_en(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL || pchannel->type == DPA_FIPC_CHNL_SEND) {
        return DPA_FIPC_ERR_ENXIO;
    }
    if (pchannel->p_pipe_config->pipe_uctrl.ipipe_uctrl.union_stru.up_thrh == 0) {
        return DPA_FIPC_OK;
    }

    pchannel->p_pipe_config->int_level =
        dpa_fipc_ipipe_devint_en(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_RD_OVERFLOW);
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_overflow_int_dis(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL || pchannel->type == DPA_FIPC_CHNL_SEND) {
        return DPA_FIPC_ERR_ENXIO;
    }

    if (pchannel->p_pipe_config->pipe_uctrl.ipipe_uctrl.union_stru.up_thrh == 0) {
        return DPA_FIPC_OK;
    }

    pchannel->p_pipe_config->int_level =
        dpa_fipc_ipipe_devint_dis(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_RD_OVERFLOW);
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_timeout_int_en(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL || pchannel->type == DPA_FIPC_CHNL_SEND) {
        return DPA_FIPC_ERR_ENXIO;
    }
    if (pchannel->p_pipe_config->pipe_uctrl.ipipe_uctrl.union_stru.arv_timeout == 0) {
        return DPA_FIPC_OK;
    }

    pchannel->p_pipe_config->int_level =
        dpa_fipc_ipipe_devint_en(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_RD_ARV_TIMEOUT);
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_timeout_int_dis(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL || pchannel->type == DPA_FIPC_CHNL_SEND) {
        return DPA_FIPC_ERR_ENXIO;
    }

    if (pchannel->p_pipe_config->pipe_uctrl.ipipe_uctrl.union_stru.arv_timeout == 0) {
        return DPA_FIPC_OK;
    }

    pchannel->p_pipe_config->int_level =
        dpa_fipc_ipipe_devint_dis(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_RD_ARV_TIMEOUT);
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_all_int_en(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL) {
        return DPA_FIPC_ERR_ENXIO;
    }

    if (pchannel->type == DPA_FIPC_CHNL_SEND) {
        dpa_fipc_opipe_coreint_en(pdev->base_va, pchannel->pipe_id, pchannel->core_id, DPA_FIPC_INT_OFFSET);
    } else if (pchannel->type == DPA_FIPC_CHNL_RECV) {
        dpa_fipc_ipipe_coreint_en(pdev->base_va, pchannel->pipe_id, pchannel->core_id, DPA_FIPC_INT_OFFSET);
    } else {
        return DPA_FIPC_ERR_BAD_CHANNEL;
    }
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_underflow_int_en(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL || pchannel->type != DPA_FIPC_CHNL_SEND) {
        return DPA_FIPC_ERR_ENXIO;
    }

    (void)dpa_fipc_opipe_devint_en(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_WR_UNDERFLOW);
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_underflow_int_dis(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL || pchannel->type != DPA_FIPC_CHNL_SEND) {
        return DPA_FIPC_ERR_ENXIO;
    }

    (void)dpa_fipc_opipe_devint_dis(pdev->base_va, pchannel->pipe_id, DPA_FIPC_INT_WR_UNDERFLOW);
    return DPA_FIPC_OK;
}

int bsp_dpa_fipc_channel_all_int_dis(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = chn_hdl;

    if (pchannel == NULL || pdev == NULL) {
        return DPA_FIPC_ERR_ENXIO;
    }

    if (pchannel->type == DPA_FIPC_CHNL_SEND) {
        dpa_fipc_opipe_coreint_dis(pdev->base_va, pchannel->pipe_id, pchannel->core_id, DPA_FIPC_INT_OFFSET);
    } else if (pchannel->type == DPA_FIPC_CHNL_RECV) {
        dpa_fipc_ipipe_coreint_dis(pdev->base_va, pchannel->pipe_id, pchannel->core_id, DPA_FIPC_INT_OFFSET);
    } else {
        return DPA_FIPC_ERR_BAD_CHANNEL;
    }
    return DPA_FIPC_OK;
}

void bsp_dpa_fipc_send_channel_regs_report(dpa_fipc_chn_t chn_hdl)
{
    struct dpa_fipc_channel *pchannel = chn_hdl;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
 
    if (pchannel == NULL || pdev == NULL) {
        return;
    }
    dpa_fipc_mntn_report_pipe_regs(pdev, pchannel->pipe_id);
}
