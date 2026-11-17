/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef _BSP_MSG_H
#define _BSP_MSG_H
#define DPA_MSG_CORE_MASK(x) (1 << (x))
enum dpa_msg_core {
    DPA_MSG_CORE_STUB = 0, /* 编号为0的空着不用 */
    DPA_MSG_CORE_APP = 1,
    DPA_MSG_CORE_TSP = 2,
    DPA_MSG_CORE_LPM_MDM = 4,
    DPA_MSG_CORE_TEE = 6,
    DPA_MSG_CORE_SENSOR = 7,
    DPA_MSG_CORE_LPM_AP = 8,
    DPA_MSG_CORE_DPA = 9,
};

enum dpa_msg_chnid {
    DPA_MSG_CHN_LOOP0,
    DPA_MSG_CHN_LOOP1,
    DPA_MSG_CHN_DIAG = 0x1a,
    DPA_MSG_CHN_BTEST = 0x24,
    DPA_MSG_CHN_HTS = 0x41,
    DPA_MSG_CHN_DMI = 0x43,
    DPA_MSG_CHN_CNT_MAX
};

struct dpa_msg_addr {
    unsigned int core;
    unsigned int chnid;
};

struct dpa_msgchn_attr {
    unsigned magic;
    unsigned chnid;
    unsigned coremask;
    int (*lite_notify)(const struct dpa_msg_addr *src, void *msg, unsigned len);
};

typedef struct dpa_msg_chn_hdl *dpa_msg_chn_t;

void bsp_dpa_msgchn_attr_init(struct dpa_msgchn_attr *pattr);
int bsp_dpa_msg_lite_open(struct dpa_msg_chn_hdl **ppchn_hdl, struct dpa_msgchn_attr *pattr);
int bsp_dpa_msg_lite_sendto(struct dpa_msg_chn_hdl *chn_hdl, const struct dpa_msg_addr *dst, void *msg, unsigned len);
#endif