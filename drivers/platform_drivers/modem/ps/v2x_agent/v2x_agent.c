
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <asm/current.h>
#include <asm/cacheflush.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/stat.h>
#include <linux/unistd.h>
#include <linux/types.h>
#include <linux/file.h>
#include <linux/wakelock.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/dma-mapping.h>
#include <linux/netdevice.h>
#include <linux/skbuff.h>
#include <securec.h>
#include <linux/semaphore.h>
#include "bsp_v2x_agent.h"
#include <mdrv_fipc.h>
#include <mdrv_crypto_engine.h>
#include <mdrv_timer.h>
#include <msg_id.h>
#include <mdrv_pcv.h>
#include "v2x_agent.h"
#include "v2x_agent_fipc.h"
#include "v2x_agent_dump.h"
#include "v2x_agent_log_print.h"

struct v2x_agent_info g_v2x_agent_info = {0};
struct v2x_agent_dump_t g_v2x_agent_debug_info = {0};

struct v2x_agent_info *bsp_v2x_agent_get_info(void)
{
    return &g_v2x_agent_info;
}
EXPORT_SYMBOL(bsp_v2x_agent_get_info);

struct v2x_agent_dump_t *v2x_agent_get_debug_info(void)
{
    return &g_v2x_agent_debug_info;
}

int v2x_agent_print_debug_info(void)
{
    pr_err("-----------------info start---------------");
    pr_err("up_wptr = 0x%x\n", g_v2x_agent_debug_info.uplink_wptr);
    pr_err("up_rptr = 0x%x\n", g_v2x_agent_debug_info.uplink_rptr);
    pr_err("uplink_ioctl_count = %d\n", g_v2x_agent_debug_info.write_uplink_wptr_ioctl_count);
    pr_err("uplink_intr_count = %d\n", g_v2x_agent_debug_info.uplink_intr_count);
    pr_err("uplink_ltev_count = %d\n", g_v2x_agent_debug_info.ltev_uplink_count);
    pr_err("---------------------------------------------");
    pr_err("down_wptr = 0x%x\n", g_v2x_agent_debug_info.downlink_wptr);
    pr_err("down_rptr = 0x%x\n", g_v2x_agent_debug_info.downlink_rptr);
    pr_err("downlink_ioctl_count = %d\n", g_v2x_agent_debug_info.write_downlink_rptr_ioctl_count);
    pr_err("downlink_intr_count = %d\n", g_v2x_agent_debug_info.downlink_intr_count);
    pr_err("downlink_ltev_count = %d\n", g_v2x_agent_debug_info.ltev_downlink_count);
    pr_err("-----------------info end---------------");
    return 0;
}

static inline void V2X_AGNET_FLUSH_CACHE(unsigned int cur_rptr, unsigned int data_size)
{
    dma_sync_single_for_device(g_v2x_agent_info.dev,
        g_v2x_agent_info.uplink_dma_addr + cur_rptr,
        L1_CACHE_ALIGN(data_size),
        DMA_TO_DEVICE);
}

static inline void V2X_AGNET_INVALID_CACHE(unsigned int cur_rptr, unsigned int data_size)
{
    dma_sync_single_for_cpu(g_v2x_agent_info.dev,
        g_v2x_agent_info.downlink_dma_addr + cur_rptr,
        L1_CACHE_ALIGN(data_size),
        DMA_FROM_DEVICE);
}

static int v2x_copy_to_uplink_buffer(unsigned int *cur_wptr, void *buffer, unsigned int buffer_size)
{
    int ret = 0;
    void *data_buffer = g_v2x_agent_info.uplink_data_buffer;
    int res_size = 0;
    int copy_size = 0;

    if (*cur_wptr + buffer_size <= V2X_DATA_UPLINK_BUFFER_SIZE) {
        ret = memcpy_s(data_buffer + *cur_wptr, V2X_DATA_UPLINK_BUFFER_SIZE - *cur_wptr, buffer, buffer_size);
        if (ret) {
            v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
            return -1;
        }
        *cur_wptr += buffer_size;
    } else {
        copy_size = V2X_DATA_UPLINK_BUFFER_SIZE - *cur_wptr;
        ret = memcpy_s(data_buffer + *cur_wptr, V2X_DATA_UPLINK_BUFFER_SIZE - *cur_wptr, buffer, copy_size);
        if (ret) {
            v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
            return -1;
        }

        res_size = buffer_size - copy_size;
        if (res_size != 0) {
            ret = memcpy_s(data_buffer, V2X_DATA_UPLINK_BUFFER_SIZE, buffer + copy_size, res_size);
            if (ret) {
                v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
                return -1;
            }
        }
        *cur_wptr = res_size;
    }

    if (*cur_wptr == V2X_DATA_UPLINK_BUFFER_SIZE) {
        *cur_wptr = 0;
    }
    return 0;
}

static int v2x_copy_from_downlink_buffer(unsigned int *cur_rptr, unsigned int *cur_wptr, void *buffer, unsigned int buffer_size)
{
    int ret = 0;
    void *data_buffer = g_v2x_agent_info.downlink_data_buffer;
    int res_size = 0;
    int copy_size = 0;

    if (*cur_wptr > *cur_rptr) {
        ret = memcpy_s(buffer, buffer_size, data_buffer + *cur_rptr, buffer_size);
        if (ret) {
            v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
            return -1;
        }
        *cur_rptr += buffer_size;
    } else if (*cur_wptr < *cur_rptr) {
        if (*cur_rptr + buffer_size <= V2X_DATA_DOWNLINK_BUFFER_SIZE) {
            ret = memcpy_s(buffer, buffer_size, data_buffer + *cur_rptr, buffer_size);
            if (ret) {
                v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
                return -1;
            }
            *cur_rptr += buffer_size;
        } else {
            copy_size = V2X_DATA_DOWNLINK_BUFFER_SIZE - *cur_rptr;
            ret = memcpy_s(buffer, buffer_size, data_buffer + *cur_rptr, copy_size);
            if (ret) {
                v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
                return -1;
            }

            res_size = buffer_size - copy_size;
            if (res_size != 0) {
                ret = memcpy_s(buffer + copy_size, buffer_size - copy_size, data_buffer, res_size);
                if (ret) {
                    v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
                    return -1;
                }
            }
            *cur_rptr = res_size;
        }
        if (*cur_rptr == V2X_DATA_DOWNLINK_BUFFER_SIZE) {
            cur_rptr = 0;
        }
    }
    return 0;
}

int v2x_agent_bd2_send_done_cb(fipc_event event, void *arg, const fipc_eventinfo *event_info)
{
    int ret;
    unsigned int cur_rptr = 0;
    unsigned int index = 0;
    struct fipc_operation *ops = &g_v2x_agent_info.ops;
    g_v2x_agent_debug_info.uplink_intr_count++;

    V2X_AGENT_RECORD_EVENT(V2X_AGENT_UPLINK_INTR_COUNT,
        g_v2x_agent_debug_info.uplink_intr_count);

    ret = ops->get_uplink_rptr(&cur_rptr);
    if (ret) {
        v2x_print_error("get rptr error, ret = %d\n", ret);
        return ret;
    }

    if (cur_rptr == 0) {
        cur_rptr = V2X_PIPE_BUFFER_SIZE;
    }
    index = cur_rptr / FIPC_BUFFER_BD_SIZE - 1;

    g_v2x_agent_info.uplink_rptr = g_v2x_agent_info.uplink_opipe_map_buffer[index];

    g_v2x_agent_debug_info.uplink_rptr = g_v2x_agent_info.uplink_rptr;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_UPLINK_RPTR, g_v2x_agent_info.uplink_rptr);
    return V2X_AGRNT_OK;
}

static inline void dl_cb_print_V2xAppDataInfo(unsigned int ptr)
{
    // 环回版本 60  非环回版本 64
    V2xAppDataInfo *info = (V2xAppDataInfo *)(g_v2x_agent_info.downlink_data_buffer + ptr + 64);
    if (((struct v2x_bypass_info *)(g_v2x_agent_info.downlink_data_buffer + ptr))->type == 2) {
        v2x_print_diag("<%d> dl msg, dataType = %d, ueId = %d, seqNum = %d,",
            __LINE__,
            info->dataType,
            info->ueId,
            info->sequenceNumber);
    }
}

int v2x_agent_fipc_recv_cb(fipc_event event, void *arg, const fipc_eventinfo *event_info)
{
    int ret;
    int data_size = 0;
    unsigned int cur_wptr = 0;
    unsigned int cur_rptr = 0;
    struct fipc_operation *ops = &g_v2x_agent_info.ops;

    g_v2x_agent_debug_info.downlink_intr_count++;

    V2X_AGENT_RECORD_EVENT(V2X_AGENT_DOWNLINK_INTR_COUNT,
        g_v2x_agent_debug_info.downlink_intr_count);

    ret = ops->get_downlink_rptr(&cur_rptr);
    if (ret) {
        v2x_print_error("get rptr error, ret = %d\n", ret);
        goto err_end;
    }

    ret = ops->get_downlink_wptr(&cur_wptr);
    if (ret) {
        v2x_print_error("get wptr error, ret = %d\n", ret);
        goto err_end;
    }

    if (cur_wptr >= cur_rptr) {
        data_size = cur_wptr - cur_rptr;
        V2X_AGNET_INVALID_CACHE(cur_rptr, data_size);
    } else {
        data_size = V2X_DATA_DOWNLINK_BUFFER_SIZE - cur_rptr;
        V2X_AGNET_INVALID_CACHE(cur_rptr, data_size);

        data_size = cur_wptr;
        V2X_AGNET_INVALID_CACHE(0, data_size);
    }

    dl_cb_print_V2xAppDataInfo(g_v2x_agent_info.downlink_wptr);
    g_v2x_agent_info.downlink_wptr = cur_wptr;

    g_v2x_agent_debug_info.downlink_wptr = cur_wptr;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_DOWNLINK_WPTR, cur_wptr);
err_end:
    if (g_v2x_agent_info.user_state == V2X_APP_RUNNING) {
        up(&g_v2x_agent_info.sem_downlink);
    } else if (g_v2x_agent_info.user_state == V2X_LTEV_RUNNING) {
        queue_work(g_v2x_agent_info.wq, &g_v2x_agent_info.ltev_work);
    } else {
        g_v2x_agent_info.downlink_rptr = cur_wptr;
        ret = ops->set_downlink_rptr(cur_wptr);
        if (ret) {
            v2x_print_error("ser rptr error, rptr = 0x%x, ret = %d\n", cur_wptr, ret);
            return ret;
        }
    }

    return ret;
}

static int v2x_agent_open(struct inode *inode, struct file *file)
{
    UNUSED(inode);
    UNUSED(file);

    if (g_v2x_agent_info.dev_status == V2X_DEV_OPEN_TWICE) {
        return -1;
    } else if (g_v2x_agent_info.dev_status == V2X_DEV_OPEN_ONECE) {
        g_v2x_agent_info.dev_status = V2X_DEV_OPEN_TWICE;
    } else {
        g_v2x_agent_info.dev_status = V2X_DEV_OPEN_ONECE;
    }
    return V2X_AGRNT_OK;
}

long v2x_agent_ioctl_get_downlink_buf_len(unsigned int *buffer_size)
{
    int ret;
    unsigned int size = 0;

    if (buffer_size == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }
    g_v2x_agent_debug_info.downlink_len_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_DOWNLINK_LEN_IOCTL_COUNT,
        g_v2x_agent_debug_info.downlink_len_ioctl_count);

    size = V2X_DATA_DOWNLINK_BUFFER_SIZE;
    ret = copy_to_user((void *)buffer_size, (void *)&size, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    return V2X_AGRNT_OK;
}

long v2x_agent_ioctl_get_uplink_buf_len(unsigned int *buffer_size)
{
    int ret;
    unsigned int size = 0;

    if (buffer_size == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }
    g_v2x_agent_debug_info.uplink_len_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_UPLINK_LEN_IOCTL_COUNT,
        g_v2x_agent_debug_info.uplink_len_ioctl_count);

    size = V2X_DATA_UPLINK_BUFFER_SIZE;
    ret = copy_to_user((void *)buffer_size, (void *)&size, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    return V2X_AGRNT_OK;
}

static inline void dl_print_V2xAppDataInfo(unsigned int ptr)
{
    // 环回版本 60  非环回版本 64
    V2xAppDataInfo *info = (V2xAppDataInfo *)(g_v2x_agent_info.downlink_data_buffer + ptr + 64);
    if (((struct v2x_bypass_info *)(g_v2x_agent_info.downlink_data_buffer + ptr))->type == 2) {
        v2x_print_diag("<%d> dl msg, dataType = %d, ueId = %d, seqNum = %d,",
            __LINE__,
            info->dataType,
            info->ueId,
            info->sequenceNumber);
    }
}

static inline void ul_print_V2xAppDataInfo(unsigned int wptr_new)
{
    // 环回版本 57  非环回版本 57
    V2xAppDataInfo *info = (V2xAppDataInfo *)(g_v2x_agent_info.uplink_data_buffer + wptr_new + 57);
    if (((struct v2x_bypass_info *)(g_v2x_agent_info.uplink_data_buffer + wptr_new))->type == 2) {
        v2x_print_diag("ul msg, dataType = %d, ueId = %d, seqNum = %d,",
            info->dataType,
            info->ueId,
            info->sequenceNumber, 0);
    }
}

long v2x_agent_ioctl_read_downlink_wptr(unsigned int *wptr_new)
{
    int ret;
    unsigned int cur_wptr = 0;
    struct fipc_operation *ops = &g_v2x_agent_info.ops;

    if (wptr_new == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }
    g_v2x_agent_debug_info.read_downlink_wptr_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_READ_DOWNLINK_WPTR_IOCTL_COUNT,
        g_v2x_agent_debug_info.read_downlink_wptr_ioctl_count);
    v2x_print_diag("dl ioctl read_wptr in, ioctl_count = %d, downlink_rptr = 0x%x, downlink_wptr = 0x%x",
        g_v2x_agent_debug_info.read_downlink_wptr_ioctl_count, g_v2x_agent_info.downlink_rptr,
        g_v2x_agent_info.downlink_wptr, 0);

    g_v2x_agent_info.user_state = V2X_APP_RUNNING;
    ret = down_interruptible(&g_v2x_agent_info.sem_downlink);
    if (ret) {
        v2x_print_info("read wakeup by softirq, not err, ret = %d.\n", ret);
        return V2X_AGRNT_ERR_INTERRUPT;
    }

    ret = ops->get_downlink_wptr(&cur_wptr);
    if (ret) {
        v2x_print_error("get wptr error, ret = %d\n", ret);
        return ret;
    }

    cur_wptr = (cur_wptr == V2X_DATA_DOWNLINK_BUFFER_SIZE) ? 0: cur_wptr;
    ret = copy_to_user((void *)wptr_new, (void *)&cur_wptr, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    v2x_print_diag("dl ioctl read_wptr out, ioctl_count = %d, downlink_rptr = 0x%x, downlink_wptr = 0x%x",
        g_v2x_agent_debug_info.read_downlink_wptr_ioctl_count, g_v2x_agent_info.downlink_rptr,
        g_v2x_agent_info.downlink_wptr, 0);

    dl_print_V2xAppDataInfo(g_v2x_agent_info.downlink_rptr);
    return V2X_AGRNT_OK;
}

long v2x_agent_ioctl_write_downlink_rptr(unsigned int rptr_new)
{
    int ret;
    struct fipc_operation *ops = &g_v2x_agent_info.ops;

    g_v2x_agent_debug_info.write_downlink_rptr_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_WRITE_DOWNLINK_RPTR_IOCTL_COUNT,
        g_v2x_agent_debug_info.write_downlink_rptr_ioctl_count);
    v2x_print_diag("dl ioctl write_rptr, ioctl_count = %d, downlink_rptr = 0x%x, downlink_wptr = 0x%x",
        g_v2x_agent_debug_info.write_downlink_rptr_ioctl_count, g_v2x_agent_info.downlink_rptr,
        g_v2x_agent_info.downlink_wptr, 0);
    rptr_new = V2X_EICC_ALIGN_LEN_4(rptr_new);
    ret = ops->set_downlink_rptr(rptr_new);
    if (ret) {
        v2x_print_error("ser rptr error, rptr = 0x%x, ret = %d\n", rptr_new, ret);
        return ret;
    }

    g_v2x_agent_info.downlink_rptr = rptr_new;
    g_v2x_agent_debug_info.downlink_rptr = rptr_new;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_DOWNLINK_RPTR, rptr_new);
    return 0;
}

long v2x_agent_ioctl_read_downlink_rptr(unsigned int *rptr_new)
{
    int ret;
    if (rptr_new == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }

    ret = copy_to_user((void *)rptr_new, (void *)&g_v2x_agent_info.downlink_rptr, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    return V2X_AGRNT_OK;
}

static int uplink_data_size(unsigned int wptr_old, unsigned int wptr_new)
{
    unsigned int data_size = 0;
    if (wptr_old <= wptr_new) {
        data_size = wptr_new - wptr_old;
    } else {
        data_size = V2X_DATA_UPLINK_BUFFER_SIZE - wptr_old + wptr_new;
    }
    return data_size;
}

static int uplink_data_buffer_is_overflow(unsigned int cur_rptr, unsigned int cur_wptr, unsigned data_size)
{
    if (cur_wptr < cur_rptr) {
        if (cur_rptr - cur_wptr < data_size) {
            return 1;
        } else {
            return 0;
        }
    } else if (cur_wptr > cur_rptr) {
        if (cur_rptr + V2X_DATA_UPLINK_BUFFER_SIZE - cur_wptr < data_size) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

static int uplink_ring_buffer_is_overflow(void)
{
    struct fipc_operation *ops = &g_v2x_agent_info.ops;
    unsigned int cur_wptr = 0;
    unsigned int cur_rptr = 0;
    unsigned int ret = 0;

    cur_wptr = g_v2x_agent_info.uplink_opipe_map_index * FIPC_BUFFER_BD_SIZE;
    ret = ops->get_uplink_rptr(&cur_rptr);
    if (ret) {
        v2x_print_error("get wptr error, ret = %d\n", ret);
        return ret;
    }

    if (cur_wptr < cur_rptr) {
        if (cur_rptr - cur_wptr <= V2X_RING_BUFFER_OVERFLOW_SIZE) {
            return 1;
        } else {
            return 0;
        }
    } else if (cur_wptr > cur_rptr) {
        if (cur_rptr + V2X_PIPE_BUFFER_SIZE - cur_wptr <= V2X_RING_BUFFER_OVERFLOW_SIZE) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

static int uplink_send_data_by_fipc(unsigned int wptr_new, unsigned int wptr_old, unsigned int data_size, int flags)
{
    int ret = 0;
    struct fipc_operation *ops = &g_v2x_agent_info.ops;
    unsigned int index = g_v2x_agent_info.uplink_opipe_map_index;
    if (data_size == 0) {
        return 0;
    }
    g_v2x_agent_info.uplink_opipe_map_buffer[index] = wptr_new;
    V2X_AGNET_FLUSH_CACHE(wptr_old, data_size);
    ret = ops->send_uplink_data((void *)g_v2x_agent_info.uplink_dma_addr + wptr_old, data_size, flags);
    if (ret) {
        if (ret == V2X_AGRNT_UPLINK_RINGBUF_OVERFLOW) {
            v2x_print_error("uplink ring buffer overflow, wptr = 0x%x.\n", wptr_old);
        } else {
            v2x_print_error("data_size 0x%x send error, wptr = 0x%x, ret = %d\n", data_size, wptr_old, ret);
        }
        return ret;
    }
    index++;
    if (index == V2X_PIPE_BUFFER_SIZE / FIPC_BUFFER_BD_SIZE) {
        index = 0;
    }
    g_v2x_agent_info.uplink_opipe_map_index = index;
    return 0;
}

static int uplink_buff_is_overflow(unsigned int cur_rptr, unsigned int wptr_old, unsigned data_size)
{
    if (uplink_data_buffer_is_overflow(cur_rptr, wptr_old, data_size)) {
        v2x_print_error("uplink data buffer overflow, rptr = 0x%x, wptr = 0x%x.\n", cur_rptr, wptr_old);
        return 1;
    }

    if (uplink_ring_buffer_is_overflow()) {
        v2x_print_error("uplink ring buffer overflow, rptr = 0x%x, wptr = 0x%x.\n", cur_rptr, wptr_old);
        return 1;
    }
    return 0;
}

long v2x_agent_ioctl_write_uplink_wptr(unsigned int wptr_new)
{
    int ret, eicc_flags = 0;
    unsigned int cur_rptr = g_v2x_agent_info.uplink_rptr;
    unsigned int wptr_old = g_v2x_agent_info.uplink_wptr;
    unsigned int data_size = uplink_data_size(wptr_old, wptr_new);

    g_v2x_agent_debug_info.write_uplink_wptr_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_WRITE_UPLINK_WPTR_IOCTL_COUNT,
        g_v2x_agent_debug_info.write_uplink_wptr_ioctl_count);
    v2x_print_diag("ul ioctl write_wptr in, ioctl_count = %d, ul_rptr = 0x%x, ul_wptr = 0x%x, ul_wptr_new = 0x%x",
        g_v2x_agent_debug_info.write_uplink_wptr_ioctl_count, g_v2x_agent_info.uplink_rptr,
        g_v2x_agent_info.uplink_wptr, wptr_new);

    if (uplink_buff_is_overflow(cur_rptr, wptr_old, data_size)) {
        return V2X_AGRNT_UPLINK_DATABUF_OVERFLOW;
    }

    ul_print_V2xAppDataInfo(wptr_old);
    if (wptr_new > wptr_old) {
        data_size = wptr_new - wptr_old;
        ret = uplink_send_data_by_fipc(wptr_new, wptr_old, data_size, 0);
        if (ret) {
            return ret;
        }
    } else {
        eicc_flags = (wptr_new == 0) ? 0: FIPC_SEND_FLAGS_NOARRVNOTIFY;
        data_size = V2X_DATA_UPLINK_BUFFER_SIZE - wptr_old;
        ret = uplink_send_data_by_fipc(0, wptr_old, data_size, eicc_flags);
        if (ret) {
            return ret;
        }

        data_size = wptr_new;
        ret = uplink_send_data_by_fipc(wptr_new, 0, data_size, 0);
        if (ret) {
            return ret;
        }
    }
    wptr_new = (wptr_new == V2X_DATA_UPLINK_BUFFER_SIZE) ? 0: wptr_new;
    g_v2x_agent_info.uplink_wptr = wptr_new;
    g_v2x_agent_debug_info.uplink_wptr = wptr_new;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_UPLINK_WPTR, wptr_new);
    v2x_print_diag("ul ioctl write_wptr out, ioctl_count = %d, ul_rptr = 0x%x, ul_wptr = 0x%x",
        g_v2x_agent_debug_info.write_uplink_wptr_ioctl_count, g_v2x_agent_info.uplink_rptr, wptr_new);
    return 0;
}

long v2x_agent_ioctl_read_uplink_rptr(unsigned int *rptr_new)
{
    int ret;
    if (rptr_new == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }

    g_v2x_agent_debug_info.read_uplink_rptr_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_READ_UPLINK_RPTR_IOCTL_COUNT,
        g_v2x_agent_debug_info.read_uplink_rptr_ioctl_count);
    ret = copy_to_user((void *)rptr_new, (void *)&g_v2x_agent_info.uplink_rptr, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    return V2X_AGRNT_OK;
}

long v2x_agent_ioctl_read_uplink_wptr(unsigned int *wptr_new)
{
    int ret;
    if (wptr_new == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }

    ret = copy_to_user((void *)wptr_new, (void *)&g_v2x_agent_info.uplink_wptr, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    return V2X_AGRNT_OK;
}

long v2x_agent_ioctl_get_pm_state(unsigned int *pm_state)
{
    int ret;

    if (pm_state == NULL) {
        v2x_print_error("invalid paras\n");
        return V2X_INVALID_PARA;
    }
    g_v2x_agent_debug_info.get_pm_ioctl_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_GET_PM_IOCTL_COUNT,
        g_v2x_agent_debug_info.get_pm_ioctl_count);

    ret = copy_to_user((void *)(uintptr_t)pm_state, (void *)&g_v2x_agent_info.pm_status, sizeof(unsigned int));
    if (ret) {
        v2x_print_error("copy to user fail, count = 0x%lx ,faild data_size = 0x%x \n", sizeof(unsigned int), ret);
        return V2X_AGRNT_EXCEED_BUF;
    }
    g_v2x_agent_info.pm_status = V2X_AGENT_PM_NORMAL;
    return V2X_AGRNT_OK;
}

static int buffer_size_is_valid(unsigned int cur_rptr, unsigned int cur_wptr, unsigned int buffer_size)
{
    if (cur_wptr > cur_rptr) {
        if (cur_wptr - cur_rptr >= buffer_size) {
            return 1;
        } else {
            return 0;
        }
    } else if (cur_wptr < cur_rptr) {
        if (cur_wptr + V2X_DATA_DOWNLINK_BUFFER_SIZE - cur_rptr >= buffer_size) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

static int v2x_recv_update_rptr(unsigned int *rptr)
{
    int ret;
    struct fipc_operation *ops = &g_v2x_agent_info.ops;

    *rptr = V2X_EICC_ALIGN_LEN_4(*rptr);
    ret = ops->set_downlink_rptr(*rptr);
    if (ret) {
        v2x_print_error("ser rptr error, rptr = 0x%x, ret = %d\n", *rptr, ret);
        return ret;
    }

    *rptr = (*rptr == V2X_DATA_DOWNLINK_BUFFER_SIZE) ? 0: *rptr;
    g_v2x_agent_info.downlink_rptr = *rptr;
    g_v2x_agent_debug_info.downlink_rptr = *rptr;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_DOWNLINK_RPTR, *rptr);
    return 0;
}

static inline int v2x_read_dl_head_data(unsigned int *cur_wptr, unsigned int *cur_rptr, struct v2x_bypass_info *bypass_info)
{
    int ret;
    // 开始读头的数据
    ret = v2x_copy_from_downlink_buffer(cur_rptr, cur_wptr, bypass_info, sizeof(struct v2x_bypass_info));
    if (ret) {
        v2x_print_error("read head data errpr, ret = 0x%x, wptr = 0x%x, rptr = 0x%x\n", ret, *cur_wptr, *cur_rptr);
        return ret;
    }

    // 解析头数据中的len，检查是否有数据读
    if (bypass_info->len > V2X_DATA_DOWNLINK_BUFFER_SIZE || bypass_info->version != V2X_BYPASS_VERSION) {
        v2x_print_error("bypass_info invalid, len = 0x%x, type = 0x%x, version = 0x%x\n", bypass_info->len, bypass_info->type, bypass_info->version);
        return ret;
    }
    return 0;
}

void v2x_agent_ltev_work(struct work_struct *work __attribute__((unused)))
{
    int ret;
    struct v2x_bypass_info bypass_info = {0};
    struct sk_buff* skb;
    unsigned int cur_wptr = g_v2x_agent_info.downlink_wptr;
    unsigned int cur_rptr = g_v2x_agent_info.downlink_rptr;

    while (cur_rptr != cur_wptr) {
        // 判断指针是否有头数据可以读
        if (buffer_size_is_valid(cur_rptr, cur_wptr, sizeof(struct v2x_bypass_info)) == 0) {
            break;
        }
        // 读取头数据
        if (v2x_read_dl_head_data(&cur_wptr, &cur_rptr, &bypass_info)) {
            goto err_end;
        }
        // 判断指针是否有消息数据可以读
        if (buffer_size_is_valid(cur_rptr, cur_wptr, bypass_info.len) == 0) {
            break;
        }

        // 开始读数据
        skb = netdev_alloc_skb_ip_align(NULL, bypass_info.len);
        if (skb == NULL) {
            goto err_end;
        }
        skb->len = bypass_info.len;

        if (v2x_copy_from_downlink_buffer(&cur_rptr, &cur_wptr, skb->data, skb->len)) {
            goto err_end;
        }

        if (g_v2x_agent_info.test_flags == 0) {
            ret = mdrv_pcv_xmit(skb);
            if (ret) {
                v2x_print_error("mdrv_pcv_xmit error, ret = 0x%x\n", ret);
                goto err_end;
            }
        } else {
            if (g_v2x_agent_info.test_flags & V2X_RANDON_LEN_MODE) {
                if (memcmp(skb->data, g_v2x_agent_info.test_buffer, skb->len)) {
                    v2x_print_error("memcmp error\n");
                    g_v2x_agent_info.data_cmp_result = DATA_CMP_FAIL;
                    goto err_end;
                }
            }
            consume_skb(skb);
        }

        // 更新读指针
        (void)v2x_recv_update_rptr(&cur_rptr);
        g_v2x_agent_debug_info.ltev_downlink_count++;
        V2X_AGENT_RECORD_EVENT(V2X_AGENT_LTEV_DOWNLINK_COUNT, g_v2x_agent_debug_info.ltev_downlink_count);
        cur_wptr = g_v2x_agent_info.downlink_wptr;
    }
    return;

err_end:
    (void)v2x_recv_update_rptr(&cur_wptr);
    return;
}

int bsp_v2x_agent_ltev_work_init(void)
{
    if (g_v2x_agent_info.user_state == V2X_LTEV_RUNNING) {
        v2x_print_error("ltev work is running, not need init again.\n");
        return V2X_AGRNT_ERR_INIT;
    }
    g_v2x_agent_info.user_state = V2X_LTEV_RUNNING;
    return V2X_AGRNT_OK;
}
EXPORT_SYMBOL(bsp_v2x_agent_ltev_work_init);

int bsp_v2x_agent_ltev_work_exit(void)
{
    if (g_v2x_agent_info.user_state != V2X_LTEV_RUNNING) {
        v2x_print_error("ltev work is not running, not need exit.\n");
        return V2X_AGRNT_ERR_INIT;
    }
    g_v2x_agent_info.user_state = V2X_NO_USER;
    return V2X_AGRNT_OK;
}
EXPORT_SYMBOL(bsp_v2x_agent_ltev_work_exit);

int bsp_v2x_agent_send_data(unsigned char *buffer, unsigned int buffer_size)
{
    int ret = 0;
    unsigned int cur_wptr;
    struct v2x_bypass_info bypass_info = {0};

    g_v2x_agent_debug_info.ltev_uplink_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_LTEV_UPLINK_COUNT, g_v2x_agent_debug_info.ltev_uplink_count);
    if (buffer == NULL || buffer_size > V2X_DATA_UPLINK_BUFFER_SIZE) {
        v2x_print_error("buffer invalid, buffer_size = 0x%x\n", buffer_size);
        return V2X_INVALID_PARA;
    }

    down(&g_v2x_agent_info.sem_ltev);
    v2x_print_info("send start, rptr = 0x%x, wptr = 0x%x.\n", g_v2x_agent_info.uplink_rptr, g_v2x_agent_info.uplink_wptr);
    pm_stay_awake(g_v2x_agent_info.dev);
    cur_wptr = g_v2x_agent_info.uplink_wptr;
    ret = uplink_data_buffer_is_overflow(g_v2x_agent_info.uplink_rptr, g_v2x_agent_info.uplink_wptr,
        V2X_EICC_ALIGN_LEN_4(buffer_size) + sizeof(struct v2x_bypass_info));
    if (ret) {
        v2x_print_error("uplink data buffer overflow, rptr = 0x%x, wptr = 0x%x.\n", g_v2x_agent_info.uplink_rptr, cur_wptr);
        return V2X_AGRNT_UPLINK_DATABUF_OVERFLOW;
    }
    bypass_info.version = V2X_BYPASS_VERSION;
    bypass_info.len = buffer_size;
    bypass_info.type = (g_v2x_agent_info.test_flags & V2X_DSM_SEND_MODE) ? V2X_VERIFY_TYPE : V2X_BYPASS_TYPE;

    ret = v2x_copy_to_uplink_buffer(&cur_wptr, (void *)&bypass_info, sizeof(struct v2x_bypass_info));
    if (!ret) {
        ret = v2x_copy_to_uplink_buffer(&cur_wptr, (void *)buffer, buffer_size);
    }
    if (ret) {
        v2x_print_error("memcpy error ret = 0x%x.\n", ret);
        ret = V2X_AGRNT_EXCEED_BUF;
        goto err_end;
    }

    cur_wptr = V2X_EICC_ALIGN_LEN_4(cur_wptr);
    cur_wptr = (cur_wptr == V2X_DATA_UPLINK_BUFFER_SIZE) ? 0: cur_wptr;
    ret = (int)(uintptr_t)v2x_agent_ioctl_write_uplink_wptr(cur_wptr);

err_end:
    pm_relax(g_v2x_agent_info.dev);
    v2x_print_info("send end, rptr = 0x%x, wptr = 0x%x.\n", g_v2x_agent_info.uplink_rptr, g_v2x_agent_info.uplink_wptr);
    up(&g_v2x_agent_info.sem_ltev);
    return ret;
}
EXPORT_SYMBOL(bsp_v2x_agent_send_data);

int v2x_agent_dev_mmap(struct file *file, struct vm_area_struct *vma)
{
    unsigned long size;
    unsigned long pfn_start;
    int ret;

    g_v2x_agent_debug_info.mmap_count++;
    V2X_AGENT_RECORD_EVENT(V2X_AGENT_MMAP_COUNT,
        g_v2x_agent_debug_info.mmap_count);
    if (vma == NULL) {
        v2x_print_error("<%s> vma is null.\n", __FUNCTION__);
        return -1;
    }
    size = vma->vm_end - vma->vm_start;
    vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
    // mmap buffer: [下行buffer 上行buffer]
    if (size == V2X_DATA_DOWNLINK_BUFFER_SIZE + V2X_DATA_UPLINK_BUFFER_SIZE) {
        pfn_start = g_v2x_agent_info.downlink_dma_addr >> PAGE_SHIFT;
        ret = remap_pfn_range(vma, vma->vm_start, pfn_start, size, vma->vm_page_prot);
    } else {
        v2x_print_error("user size(%ld) not match\n", size);
        ret = -1;
    }

    if (ret < 0) {
        v2x_print_error("<%s>: remap_pfn_range failed, ret = %d \n", __func__, ret);
        return ret;
    }
    return V2X_AGRNT_OK;
}

long v2x_agent_dev_ioctl(struct file *fp, unsigned int cmd, unsigned long __user arg)
{
    switch (cmd) {
        case V2X_AGENT_GET_DOWNLINK_BUF_LEN:
            return v2x_agent_ioctl_get_downlink_buf_len((unsigned int *)(uintptr_t)arg);
        case V2X_AGENT_GET_UPLINK_BUF_LEN:
            return v2x_agent_ioctl_get_uplink_buf_len((unsigned int *)(uintptr_t)arg);
        case V2X_AGENT_READ_DOWNLINK_WPTR:
            return v2x_agent_ioctl_read_downlink_wptr((unsigned int *)(uintptr_t)arg);
        case V2X_AGENT_READ_DOWNLINK_RPTR:
            return v2x_agent_ioctl_read_downlink_rptr((unsigned int *)(uintptr_t)arg);
        case V2X_AGENT_WRITE_DOWNLINK_RPTR:
            return v2x_agent_ioctl_write_downlink_rptr((unsigned int)(uintptr_t)arg);
        case V2X_AGENT_READ_UPLINK_RPTR:
            return v2x_agent_ioctl_read_uplink_rptr((unsigned int *)(uintptr_t)arg);
        case V2X_AGENT_READ_UPLINK_WPTR:
            return v2x_agent_ioctl_read_uplink_wptr((unsigned int *)(uintptr_t)arg);
        case V2X_AGENT_WRITE_UPLINK_WPTR:
            return v2x_agent_ioctl_write_uplink_wptr((unsigned int)(uintptr_t)arg);
        case V2X_AGENT_GET_PM_STATE:
            return v2x_agent_ioctl_get_pm_state((unsigned int *)(uintptr_t)arg);
        default:
            v2x_print_error("%s: ioctl cmd(%d) not valid\n", __FUNCTION__, cmd);
            return V2X_INVALID_PARA;
    }
    return V2X_AGRNT_OK;
}

int v2x_agent_dev_close(struct inode *inode, struct file *file)
{
    UNUSED(inode);
    UNUSED(file);
    if (g_v2x_agent_info.dev_status == V2X_DEV_OPEN_TWICE) {
        g_v2x_agent_info.dev_status = V2X_DEV_OPEN_ONECE;
    } else if (g_v2x_agent_info.dev_status == V2X_DEV_OPEN_ONECE) {
        g_v2x_agent_info.dev_status = V2X_DEV_CLOSE;
        g_v2x_agent_info.user_state = V2X_NO_USER;
    } else {
        v2x_print_error("v2x_agent not open\n");
        return -1;
    }

    return 0;
}


static const struct file_operations g_v2x_dev_fops = {
    .owner = THIS_MODULE,
    .open = v2x_agent_open,
    .mmap = v2x_agent_dev_mmap,
    .unlocked_ioctl = v2x_agent_dev_ioctl,
    .compat_ioctl = v2x_agent_dev_ioctl,
    .release = v2x_agent_dev_close,
};

static int v2x_dev_setup(void)
{
    int ret;
    const struct file_operations *fops = NULL;
    struct v2x_dev_info *v2x_dev = NULL;

    v2x_dev = &g_v2x_agent_info.v2x_dev;
    fops = &g_v2x_dev_fops;

    ret = alloc_chrdev_region(&v2x_dev->dev_no, V2X_FIRST_MINOR, V2X_DEVICES_NUMBER, V2X_DEVICE_NAME);
    if (ret) {
        v2x_print_error("alloc_chrdev_region failed\n");
        return ret;
    }

    cdev_init(&v2x_dev->cdev, fops);

    ret = cdev_add(&v2x_dev->cdev, v2x_dev->dev_no, V2X_DEVICES_NUMBER);
    if (ret) {
        v2x_print_error("add applog fail!\n");
        goto error_to_unregister;
    }

    v2x_dev->v2x_class = class_create(THIS_MODULE, V2X_DEVICE_CLASS);
    if (IS_ERR(v2x_dev->v2x_class)) {
        v2x_print_error("class create failed!\n");
        goto error_to_del;
    }

    v2x_dev->device = device_create(v2x_dev->v2x_class, NULL, v2x_dev->dev_no, NULL, V2X_DEVICE_NAME);
    if (IS_ERR(v2x_dev->device)) {
        v2x_print_error("<%s> device_create failed, err = %ld.\n", __FUNCTION__, PTR_ERR(v2x_dev->device));
        goto error_to_destory;
    }

    return 0;
error_to_destory:
    class_destroy(v2x_dev->v2x_class);
error_to_del:
    cdev_del(&v2x_dev->cdev);
error_to_unregister:
    unregister_chrdev_region(v2x_dev->dev_no, V2X_DEVICES_NUMBER);

    return ret;
}

static int crypto_engine_freq_handle(int arg)
{
    int ret = 0;
    unsigned int timer_count = g_v2x_agent_info.timer_intr_count;
    unsigned int cur_count = g_v2x_agent_debug_info.downlink_intr_count;
    unsigned int count_delta = 0;

    count_delta = get_timer_count_delta(timer_count, cur_count);

    if (count_delta >= V2X_DOWNLINK_MSG_UP) {
        if (g_v2x_agent_info.crypto_engine_freq_high == 0) {
            ret = mdrv_crypto_engine_set_freq(CRYPTO_ENGINE_FREQ_HIGH);
            if (ret) {
                v2x_print_error("crypto_engine set freq error, ret = %d\n", ret);
                return -1;
            }
            g_v2x_agent_info.crypto_engine_freq_high = 1;
        }
    } else if (count_delta < V2X_DOWNLINK_MSG_FLOOR) {
        if (g_v2x_agent_info.crypto_engine_freq_high == 1) {
            ret = mdrv_crypto_engine_set_freq(CRYPTO_ENGINE_FREQ_LOW);
            if (ret) {
                v2x_print_error("crypto_engine set freq error, ret = %d\n", ret);
                return -1;
            }
            g_v2x_agent_info.crypto_engine_freq_high = 0;
        }
    }

    g_v2x_agent_info.timer_intr_count = cur_count;

    return 0;
}

static int v2x_agent_crypto_engine_timer_init(void)
{
    timer_handle handle;
    timer_attr_s attr = {"crypto_engine", CRYPTO_ENGINE_MONITOR_TIMEROUT, TIMER_PERIOD, crypto_engine_freq_handle, 0};
    handle = mdrv_timer_add(&attr);
    if (handle < 0) {
        v2x_print_error("fail to add crypto_engine timer. handle=%d.\n", (s32)handle);
        return -1;
    }
    return 0;
}

int v2x_agent_work_init(void)
{
    device_init_wakeup(g_v2x_agent_info.dev, true);

    g_v2x_agent_info.wq = alloc_ordered_workqueue("v2x_agent_wq", 0);
    if (g_v2x_agent_info.wq == NULL) {
        v2x_print_error("wq create fail\n");
        return V2X_INVALID_PARA;
    }
    return V2X_AGRNT_OK;
}

int v2x_agent_buffer_init(void)
{
    /* sem int */
    sema_init(&g_v2x_agent_info.sem_ltev, 1);
    sema_init(&g_v2x_agent_info.sem_downlink, 0);

    INIT_WORK(&g_v2x_agent_info.ltev_work, v2x_agent_ltev_work);

    g_v2x_agent_info.downlink_data_buffer = kmalloc(V2X_DATA_UPLINK_BUFFER_SIZE + V2X_DATA_DOWNLINK_BUFFER_SIZE, GFP_KERNEL);
    if (IS_ERR_OR_NULL(g_v2x_agent_info.downlink_data_buffer)) {
        v2x_print_error("kmalloc return NULL\n");
        return V2X_AGRNT_EXCEED_BUF;
    }
    g_v2x_agent_info.uplink_data_buffer = g_v2x_agent_info.downlink_data_buffer + V2X_DATA_DOWNLINK_BUFFER_SIZE;

    g_v2x_agent_info.downlink_dma_addr = dma_map_single(g_v2x_agent_info.dev, g_v2x_agent_info.downlink_data_buffer,
        V2X_DATA_DOWNLINK_BUFFER_SIZE, DMA_FROM_DEVICE);
    g_v2x_agent_info.uplink_dma_addr = dma_map_single(g_v2x_agent_info.dev, g_v2x_agent_info.uplink_data_buffer,
        V2X_DATA_UPLINK_BUFFER_SIZE, DMA_TO_DEVICE);

    (void)memset_s(g_v2x_agent_info.downlink_data_buffer, V2X_DATA_UPLINK_BUFFER_SIZE + V2X_DATA_DOWNLINK_BUFFER_SIZE,
        0, V2X_DATA_UPLINK_BUFFER_SIZE + V2X_DATA_DOWNLINK_BUFFER_SIZE);

    g_v2x_agent_info.ops.fipc_recv_cb = v2x_agent_fipc_recv_cb;
    g_v2x_agent_info.ops.fipc_send_cb = v2x_agent_bd2_send_done_cb;
    return V2X_AGRNT_OK;
}

static int v2x_agent_probe(struct platform_device *pdev)
{
    int ret;
    g_v2x_agent_info.dev = &pdev->dev;

    ret = v2x_agent_buffer_init();
    if (ret) {
        v2x_print_error("buffer init fail! ret = %d\n", ret);
        return ret;
    }

    ret = v2x_agent_fipc_init(&g_v2x_agent_info);
    if (ret) {
        v2x_print_error("fipc init fail! ret = %d\n", ret);
        goto err_kfree;
    }

    ret = v2x_agent_crypto_engine_timer_init();
    if (ret) {
        v2x_print_error("timer init fail! ret = %d\n", ret);
        goto err_kfree;
    }

#ifdef CONFIG_V2X_AGENT_DUMP
    ret = v2x_agent_dump_init();
    if (ret) {
        v2x_print_error("dump init fail! ret = %d\n", ret);
        goto err_kfree;
    }
#endif
    ret = v2x_agent_work_init();
    if (ret) {
        v2x_print_error("work init fail! ret = %d\n", ret);
        goto err_kfree;
    }

    ret = v2x_dev_setup();
    if (ret) {
        v2x_print_error("setup dev fail! ret = %d\n", ret);
        goto err_kfree;
    }

    g_v2x_agent_info.pm_status = V2X_AGENT_PM_NORMAL;
    g_v2x_agent_info.user_state = V2X_NO_USER;
    v2x_print_error("v2x agent probe ok.\n");
    return 0;

err_kfree:
    kfree(g_v2x_agent_info.downlink_data_buffer);
    return ret;
}

#ifdef CONFIG_PM
static int v2x_agent_suspend(struct device *dev)
{
    return 0;
}
static int v2x_agent_resume(struct device *dev)
{
    g_v2x_agent_info.pm_status = V2X_AGENT_PM_RESUME;
    return 0;
}

static const struct dev_pm_ops g_v2x_agent_pm_ops = {
    .suspend = v2x_agent_suspend,
    .resume = v2x_agent_resume,
};

#define V2X_AGENT_PM_OPS (&g_v2x_agent_pm_ops)
#else
#define V2X_AGENT_PM_OPS NULL
#endif

static struct platform_device g_v2x_device = {
    .name = "v2x_agent",
    .id = -1,
};

struct platform_driver g_v2x_driver = {
    .probe      = v2x_agent_probe,
    .driver     = {
        .name     = "v2x_agent",
        .owner    = THIS_MODULE,
        .pm       = V2X_AGENT_PM_OPS,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

int v2x_agent_init(void)
{
    int ret = 0;

    ret = platform_device_register(&g_v2x_device);
    if (ret) {
        v2x_print_error("[init]platform_device_register v2x device fail!\n");
        return V2X_AGRNT_ERR_INIT;
    }

    ret = platform_driver_register(&g_v2x_driver);
    if (ret) {
        v2x_print_error("[init]platform_driver_register v2x driver fail!\n");
        platform_device_unregister(&g_v2x_device);
        return V2X_AGRNT_ERR_INIT;
    }
    return 0;
}
module_init(v2x_agent_init);
