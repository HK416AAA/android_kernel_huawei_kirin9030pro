/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */
#include "dpa_fipc_plat.h"

#include "dpa_fipc_device.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_mntn.h"
#include "bsp_dump.h"

#define DPA_FIPC_DUMP_MAGIC 0x0000F1CC
#define DPA_FIPC_DUMP_VERSION 0x2
struct dpa_fipc_dump_head {
    unsigned int magic;
    unsigned int version;
    unsigned int reserved;
    unsigned int len;
};

#define DPA_FIPC_DUMP_PMSR 0x0001
#define DPA_FIPC_DUMP_PMSR_VER 0x0001
#define DPA_FIPC_DUMP_HWREG 0x0002
#define DPA_FIPC_DUMP_HWREG_VER 0x0001
#define DPA_FIPC_DUMP_CHNS 0x0003
#define DPA_FIPC_DUMP_CHNS_VER 0x0001
#define DPA_FIPC_DUMP_DMA 0x0006
#define DPA_FIPC_DUMP_DMA_VER 0x0001
#define DPA_FIPC_DUMP_CHNS_SEND_RECV_TM 0x0007
#define DPA_FIPC_DUMP_CHNS_SEND_RECV_TM_VER 0x0001
#define DPA_FIPC_DUMP_DPA_RST 0x0008
#define DPA_FIPC_DUMP_DPA_RST_VER 0x0001
#define DPA_FIPC_DUMP_DPA_PMSR 0x0009
#define DPA_FIPC_DUMP_DPA_PMSR_VER 0x0001
struct dpa_fipc_dump_tlv {
    unsigned int modid; /* this is type[tlv:t] */
    unsigned int version;
    unsigned int reserved;
    unsigned int len; /* this is len[tlv:l] */
};           /* [tlv:v] is after this struct */

struct dpa_fipc_dump_chnsinfo {
    unsigned int ldrvchn_id;
    unsigned int type;
    unsigned int wptr; /* 对于ipipe，这个dump vptr指向的位置 */
    unsigned int rptr; /* 对于opipe，这个dump vptr指向的位置 */
    unsigned int reserved_1;
    unsigned int reserved_2;
};

static unsigned int dpa_fipc_chn_dump(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel, unsigned char *buf, unsigned int len)
{
    struct dpa_fipc_dump_chnsinfo chninfo = {0};
    struct dpa_fipc_dump_chnsinfo *pchninfo = &chninfo;

    unsigned int used_len = sizeof(chninfo);
    if (len < used_len) {
        return 0;
    }
    pchninfo->ldrvchn_id = pchannel->pipe_id;
    pchninfo->type = pchannel->type;
    if (pchannel->state == (unsigned int)DPA_FIPC_CHN_INIT) {
        pchninfo->wptr = 0xDEADBEEF;
        pchninfo->rptr = 0xDEADBEEF;
    } else {
        if (pchannel->type == DPA_FIPC_CHNL_SEND) {
            pchninfo->wptr = pchannel->p_pipe_config->wptr;
            pchninfo->rptr = *(pchannel->p_pipe_config->ptr_vaddr);
        } else {
            pchninfo->wptr = *(pchannel->p_pipe_config->ptr_vaddr);
            pchninfo->rptr = pchannel->p_pipe_config->rptr;
        }
    }

    if (memcpy_s(buf, len, &chninfo, sizeof(chninfo))) {
        return 0;
    }
    return used_len;
}

unsigned int dpa_fipc_chns_dump_save(unsigned char *buf, unsigned int len)
{
    u32 idx;
    u32 ret_len, used_len;
    struct dpa_fipc_device_t *pdev = NULL;
    struct dpa_fipc_channel *pchannel = NULL;
    idx = 0;
    used_len = 0;

    pdev = dpa_get_fipc_device();
    if (pdev == NULL) {
        return used_len;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (len < used_len) {
            return used_len;
        }
        if (pchannel == NULL || pchannel->state == (unsigned int)DPA_FIPC_CHN_INIT) {
            continue;
        }
        ret_len = dpa_fipc_chn_dump(pdev, pchannel, buf + used_len, len - used_len);
        if (ret_len == 0) {
            /* dump空间不够 没记录完 */
            dpa_fipc_err("dpa_fipc no enough dump space @%d\n", __LINE__);
            return used_len;
        }
        used_len += ret_len;
    }

    return used_len;
}

static unsigned int dpa_fipc_do_chns_dump(unsigned char *buf, unsigned int len)
{
    unsigned int ret_len;
    struct dpa_fipc_dump_tlv *tlv = (struct dpa_fipc_dump_tlv *)buf;
    unsigned int used_len = sizeof(struct dpa_fipc_dump_tlv);

    if (len < used_len) {
        return 0;
    }
    tlv->modid = DPA_FIPC_DUMP_CHNS;
    tlv->version = DPA_FIPC_DUMP_CHNS_VER;
    ret_len = dpa_fipc_chns_dump_save(buf + used_len, len - used_len);
    if (ret_len == 0) {
        /* 如果没有可save到内容，那该tlv头也不需要了 */
        dpa_fipc_err("dpa_fipc no enough dump space @%d\n", __LINE__);
        return 0;
    }
    tlv->len = ret_len;
    used_len += ret_len;
    return used_len;
}


static unsigned int dpa_fipc_do_chn_send_recv_tm_dump(unsigned char *buf, unsigned int len)
{
    unsigned int ret_len;
    struct dpa_fipc_dump_tlv *tlv = (struct dpa_fipc_dump_tlv *)buf;
    unsigned int used_len = sizeof(struct dpa_fipc_dump_tlv);

    if (len < used_len) {
        return 0;
    }
    tlv->modid = DPA_FIPC_DUMP_CHNS_SEND_RECV_TM;
    tlv->version = DPA_FIPC_DUMP_CHNS_SEND_RECV_TM_VER;
    ret_len = dpa_fipc_chn_send_recv_tm_dump(buf + used_len, len - used_len);
    if (ret_len == 0) {
        /* 如果没有可save到内容，那该tlv头也不需要了 */
        dpa_fipc_err("dpa_fipc_do_chn_send_recv_tm_dump no enough dump space @%d\n", __LINE__);
        return 0;
    }
    tlv->len = ret_len;
    used_len += ret_len;
    return used_len;
}

static unsigned int dpa_fipc_do_rst_dump(unsigned char *buf, unsigned int len)
{
    unsigned int ret_len;
    struct dpa_fipc_dump_tlv *tlv = (struct dpa_fipc_dump_tlv *)buf;
    unsigned int used_len = sizeof(struct dpa_fipc_dump_tlv);

    if (len < used_len) {
        return 0;
    }
    tlv->modid = DPA_FIPC_DUMP_DPA_RST;
    tlv->version = DPA_FIPC_DUMP_DPA_RST_VER;
    ret_len = dpa_fipc_rst_dump(buf + used_len, len - used_len);
    if (ret_len == 0) {
        /* 如果没有可save到内容，那该tlv头也不需要了 */
        dpa_fipc_err("dpa_fipc_do_rst_dump no enough dump space @%d\n", __LINE__);
        return 0;
    }
    tlv->len = ret_len;
    used_len += ret_len;
    return used_len;
}

static unsigned int dpa_fipc_do_pmsr_dump(unsigned char *buf, unsigned int len)
{
    unsigned int ret_len;
    struct dpa_fipc_dump_tlv *tlv = (struct dpa_fipc_dump_tlv *)buf;
    unsigned int used_len = sizeof(struct dpa_fipc_dump_tlv);

    if (len < used_len) {
        return 0;
    }
    tlv->modid = DPA_FIPC_DUMP_DPA_PMSR;
    tlv->version = DPA_FIPC_DUMP_DPA_PMSR_VER;
    ret_len = dpa_fipc_pmsr_dump(buf + used_len, len - used_len);
    if (ret_len == 0) {
        /* 如果没有可save到内容，那该tlv头也不需要了 */
        dpa_fipc_err("dpa_fipc_do_pmsr_dump no enough dump space @%d\n", __LINE__);
        return 0;
    }
    tlv->len = ret_len;
    used_len += ret_len;
    return used_len;
}

/* dpa_fipc dump使用tlv结构，便于脚本解析 */
void dpa_fipc_do_dump(unsigned char *buf, u32 len)
{
    u32 used_len;
    struct dpa_fipc_dump_head *dump_hdr = (struct dpa_fipc_dump_head *)buf;
    /* 写入magic num 和 版本号 长度， 占用16字节，方便对齐分析 */
    if (len < sizeof(struct dpa_fipc_dump_head)) {
        return;
    }

    dump_hdr->magic = bsp_get_slice_value();
    dump_hdr->version = DPA_FIPC_DUMP_VERSION;
    used_len = 0;
    dump_hdr->len = used_len;
    len -= sizeof(struct dpa_fipc_dump_head);
    buf += sizeof(struct dpa_fipc_dump_head);

    if (len - used_len > 0) {
        used_len += dpa_fipc_do_chns_dump(buf + used_len, len - used_len);
        dump_hdr->len = used_len;
    }

    if (len - used_len > 0) {
        used_len += dpa_fipc_do_chn_send_recv_tm_dump(buf + used_len, len - used_len);
        dump_hdr->len = used_len;
    }

    if (len - used_len > 0) {
        used_len += dpa_fipc_do_rst_dump(buf + used_len, len - used_len);
        dump_hdr->len = used_len;
    }

    if (len - used_len > 0) {
        used_len += dpa_fipc_do_pmsr_dump(buf + used_len, len - used_len);
        dump_hdr->len = used_len;
    }

    return;
}
