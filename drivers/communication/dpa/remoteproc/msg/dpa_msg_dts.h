/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 */
#ifndef __DPA_MSG_DTS_H__
#define __DPA_MSG_DTS_H__
#include <linux/of_device.h>
#include "bsp_dpa_msg.h"

typedef struct {
    unsigned int msgid;
    unsigned int phychnid;
} dpa_msg_msgid_dts_t;

typedef struct {
    unsigned int dir;
    unsigned int phychnid;
    unsigned int smsg_sz;
    unsigned int buf_sz;
    unsigned int index;
} dpa_msg_phychn_dts_t;

typedef struct {
    unsigned int cpuid;
    unsigned int phychn_cnt;
    unsigned int msgid_cnt;
    dpa_msg_phychn_dts_t *msg_phychn_dts;
    dpa_msg_msgid_dts_t *msg_msgid_dts;
} dpa_msg_cpugroup_dts_t;

dpa_msg_cpugroup_dts_t *dpa_msg_of_find_root_node(void);
int dpa_msg_plat_probe(struct platform_device *pdev);
#endif
