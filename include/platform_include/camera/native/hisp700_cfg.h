/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: isp msg interfaces
 * Create: 2025-03-19
 */

#ifndef __HW_KERNEL_CAM_HISP700_CFG_H__
#define __HW_KERNEL_CAM_HISP700_CFG_H__

#include "hisp_cfg_base.h"

#define HISP_IOCTL_SEND_RPMSG _IOW('A', BASE_VIDIOC_PRIVATE + 0x03, struct isp_indirect_msg)
#define HISP_IOCTL_RECV_RPMSG _IOW('A', BASE_VIDIOC_PRIVATE + 0x04, struct isp_indirect_msg)

/* commonly used hisp_vtbl_t use hisp_msg_t as callback parameter,
 * to avoid modify all platforms, typedef isp_indirect_msg as hisp_msg_t
 */
typedef struct isp_indirect_msg hisp_msg_t;
#endif /* __HW_KERNEL_CAM_HISP700_CFG_H__ */
