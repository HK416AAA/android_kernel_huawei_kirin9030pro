/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: msg
 * Author:
 * Created: 2021-12-13
 * Last Modified:
 * History:
 * Modification: Create file
 */


#ifndef __DPA_FIPC_OPS_H__
#define __DPA_FIPC_OPS_H__

#include "dpa_msg_core.h"
#include "dpa_msg_cmsg.h"
#include "bsp_dpa_msg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DPA_CMSG_FICC_ALIGN_SIZE 128
#define DPA_MSG_MAX_SIZE 1024

int dpa_fipc_default_open_send(struct dpa_channel_ctrl_t *chn_ctrl);
int dpa_fipc_default_open_recv(struct dpa_channel_ctrl_t *chn_ctrl);
int dpa_fipc_default_send(dpa_msg_blkx3_desc_t *send_desc);
int dpa_fipc_default_recv(struct dpa_channel_ctrl_t *chn_ctrl, void *buf, unsigned int len);
int dpa_fipc_nextpkt_len(struct dpa_channel_ctrl_t *chn_ctrl);
int dpa_fipc_phychn_init(struct dpa_channel_ctrl_t *channel_ctrl, dpa_msg_phychn_dts_t *phy_node);

#ifdef __cplusplus
}
#endif
#endif
