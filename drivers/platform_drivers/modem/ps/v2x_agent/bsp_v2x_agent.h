/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BSP_V2X_AGENT_H
#define BSP_V2X_AGENT_H

#include <mdrv_bmi_pc5_adaptor.h>
#include <mdrv_pcv.h>

#define V2X_DATA_UPLINK_BUFFER_SIZE (L1_CACHE_ALIGN(60 * 1024))
#define V2X_DATA_DOWNLINK_BUFFER_SIZE (L1_CACHE_ALIGN(60 * 1024))

/**
 * @brief v2x用户态和内核态交互的设备节点
 */
#define V2X_DEVICE_NAME "v2x_agent"

/**
 * @brief v2x用户态和内核态ioctl交互的枚举
 */
enum v2x_agent_ioctl_op_type {
    V2X_AGENT_IOCRL_CMD_MIN = 0x5a5a,
    /* ------v2x ioctl支持的CMD------ */
    V2X_AGENT_GET_DOWNLINK_BUF_LEN,       /* 获取下行buffer的长度 */
    V2X_AGENT_GET_UPLINK_BUF_LEN,         /* 获取上行buffer的长度 */
    V2X_AGENT_READ_DOWNLINK_RPTR,         /* 读取下行buffer读指针 */
    V2X_AGENT_READ_DOWNLINK_WPTR,         /* 读取下行buffer写指针 */
    V2X_AGENT_WRITE_DOWNLINK_RPTR,        /* 更新下行buffer读指针 */
    V2X_AGENT_READ_UPLINK_RPTR,           /* 读取上行buffer读指针 */
    V2X_AGENT_READ_UPLINK_WPTR,           /* 读取上行buffer写指针 */
    V2X_AGENT_WRITE_UPLINK_WPTR,          /* 更新上行buffer写指针 */
    V2X_AGENT_GET_PM_STATE,               /* 获取系统低功耗状态 */
    V2X_AGENT_SET_KEY,                    /* 配置公私钥对 */
    V2X_AGENT_SIGN_DATA,                  /* 签名 */
    V2X_AGENT_IOCRL_CMD_MAX
};
enum v2x_agent_pm_state {
    V2X_AGENT_PM_NORMAL = 0xa5a5,     /* 系统未经过低功耗睡眠唤醒 */
    V2X_AGENT_PM_RESUME = 0x5a5a,     /* 系统已被唤醒低功耗 */
};

/* v2x_agent err code */
#define  V2X_AGRNT_CMD_NOT_SUPPORT (1)
#define  V2X_AGRNT_OK              (0)
#define  V2X_INVALID_PARA          (-1)
#define  V2X_AGRNT_EXCEED_BUF      (-2)
#define  V2X_AGRNT_ERR_FIPC        (-3)
#define  V2X_AGRNT_UPLINK_DATABUF_OVERFLOW   (-4)
#define  V2X_AGRNT_UPLINK_RINGBUF_OVERFLOW   (-5)
#define  V2X_AGRNT_ERR_SEND        (-6)
#define  V2X_AGRNT_ERR_PTR         (-7)
#define  V2X_AGRNT_ERR_INTERRUPT   (-8)
#define  V2X_AGRNT_IOC_DOWN_PTR    (-9)
#define  V2X_AGRNT_IOC_UP_PTR      (-10)
#define  V2X_AGRNT_IOC_SEC_CALL    (-11)
#define  V2X_AGRNT_ERR_OPS         (-12)
#define  V2X_AGRNT_ERR_INIT        (-13)

/* v2x_agent dump记录的事件ID */
typedef enum {
    V2X_AGENT_RECV_CHN,
    V2X_AGENT_SEND_CHN,
    V2X_AGENT_MMAP_COUNT,
    V2X_AGENT_DOWNLINK_LEN_IOCTL_COUNT,
    V2X_AGENT_UPLINK_LEN_IOCTL_COUNT,
    V2X_AGENT_READ_DOWNLINK_WPTR_IOCTL_COUNT,
    V2X_AGENT_WRITE_DOWNLINK_RPTR_IOCTL_COUNT,
    V2X_AGENT_READ_UPLINK_RPTR_IOCTL_COUNT,
    V2X_AGENT_WRITE_UPLINK_WPTR_IOCTL_COUNT,
    V2X_AGENT_GET_PM_IOCTL_COUNT,
    V2X_AGENT_SET_GMECC_IOCTL_COUNT,
    V2X_AGENT_LTEV_SEND_COUNT,
    V2X_AGENT_LTEV_RECV_COUNT,
    V2X_AGENT_LTEV_DOWNLINK_COUNT,
    V2X_AGENT_LTEV_UPLINK_COUNT,
    V2X_AGENT_DOWNLINK_INTR_COUNT,
    V2X_AGENT_UPLINK_INTR_COUNT,
    V2X_AGENT_DOWNLINK_RPTR,
    V2X_AGENT_DOWNLINK_WPTR,
    V2X_AGENT_UPLINK_RPTR,
    V2X_AGENT_UPLINK_WPTR,

    V2X_AGENT_EVENT_MAX,
} v2x_agent_debug_event_type_e;

int bsp_v2x_agent_ltev_work_init(void);
int bsp_v2x_agent_ltev_work_exit(void);
int bsp_v2x_agent_send_data(unsigned char *buffer, unsigned int buffer_size);

#endif
