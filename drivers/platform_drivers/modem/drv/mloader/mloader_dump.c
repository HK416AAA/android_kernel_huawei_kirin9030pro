/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
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

#include <linux/slab.h>
#include <bsp_dump.h>
#include <bsp_print.h>
#include <securec.h>
#include <bsp_slice.h>
#include "mloader_dump.h"

#define THIS_MODU mod_mloader
#define MLOADER_DUMP_MAGIC (0x11223344)
#define MLOADER_DUMP_SIZE (1024)
#define MLOADER_RESULT_FAILED (0xdeadbeef)
#define MLOADER_RESULT_SUCCESS (0x33445566)

struct mloader_dump_info *g_mdm_mloader_dump_info = NULL;

static int mloader_dump_check_proc(enum mloader_dump_proc curr_proc, enum mloader_dump_proc start_proc, enum mloader_dump_proc end_proc)
{
    if (curr_proc < start_proc || curr_proc >= end_proc) {
        bsp_err("mloader proc check failed, curr_proc is %d, start_proc is %d, end_proc is %d\n", curr_proc,
                start_proc, end_proc);
        return -1;
    }
    return 0;
}

static inline int mloader_dump_is_inited(void)
{
    if (g_mdm_mloader_dump_info == NULL) {
        bsp_err("mloader dump init failed\n");
        return 0;
    }
    return 1;
}

static struct mloader_dump_final_info* mloader_dump_get_final_info(enum mloader_dump_stage stage, uint32_t node_idx)
{
    switch (stage) {
        case INIT_STAGE:
            return &(g_mdm_mloader_dump_info->loader_init_info[node_idx].final_info);
        case LOAD_IMAGE_STAGE:
            return &(g_mdm_mloader_dump_info->img_load_info[node_idx].final_info);
        default:
            bsp_err("mloader dump stage %d is invalid\n", stage);
            return NULL;
    }
}

static void mloader_dump_set_final_info(enum mloader_dump_stage stage, uint32_t node_idx,
        uint32_t proc, uint32_t result)
{
    struct mloader_dump_final_info *node_info = NULL;

    if (mloader_dump_is_inited() == 0) {
        return;
    }

    node_info = mloader_dump_get_final_info(stage, node_idx);
    if (node_info == NULL) {
        return;
    }
    node_info->final_proc = proc;
    node_info->result = result;
}

static struct mloader_dump_node* mloader_dump_get_node(enum mloader_dump_stage stage, uint32_t node_idx, uint32_t proc)
{
    switch (stage) {
        case INIT_STAGE:
            return &(g_mdm_mloader_dump_info->loader_init_info[node_idx].nodes[proc - MLOADER_INIT_START]);
        case MSG_STAGE:
            return &(g_mdm_mloader_dump_info->msg_info[node_idx].nodes[proc - MLOADER_MSG_FROM_CP]);
        case LOAD_IMAGE_STAGE:
            return &(g_mdm_mloader_dump_info->img_load_info[node_idx].nodes[proc - MLOADER_LOAD_IMAGE_START]);
        case NOTIFY_MCU_STAGE:
            return &(g_mdm_mloader_dump_info->notify_mcu_info[node_idx].nodes[proc - MLOADER_NOTIFY_MCU_START]);
        case BOOT_TIME_STAGE:
            return &(g_mdm_mloader_dump_info->boot_time_info[node_idx].nodes[proc - MLOADER_BOOT_TIME_START]);
        default:
            bsp_err("mloader dump stage %d is invalid\n", stage);
            return NULL;
    }
}

static int mloader_dump_check_param(enum mloader_dump_stage stage, uint32_t proc, uint32_t *final_info_support)
{
    int ret;
    switch (stage) {
        case INIT_STAGE:
            ret = mloader_dump_check_proc(proc, MLOADER_INIT_START, MLOADER_INIT_MAX_PROC);
            *final_info_support = 1;
            break;
        case MSG_STAGE:
            ret = mloader_dump_check_proc(proc, MLOADER_MSG_FROM_CP, MLOADER_MSG_MAX);
            *final_info_support = 0;
            break;
        case LOAD_IMAGE_STAGE:
            ret = mloader_dump_check_proc(proc, MLOADER_LOAD_IMAGE_START, MLOADER_LOAD_IMAGE_MAX_PROC);
            *final_info_support = 1;
            break;
        case NOTIFY_MCU_STAGE:
            ret = mloader_dump_check_proc(proc, MLOADER_NOTIFY_MCU_START, MLOADER_NOTIFY_MCU_END);
            *final_info_support = 0;
            break;
        case BOOT_TIME_STAGE:
            ret = mloader_dump_check_proc(proc, MLOADER_BOOT_TIME_START, MLOADER_BOOT_TIME_END);
            *final_info_support = 0;
            break;
        default:
            bsp_err("mloader dump stage %d is invalid\n", stage);
            ret = -1;
            break;
    }
    return ret;
}

static void mloader_dump_set_node_info(enum mloader_dump_stage stage, uint32_t node_idx, 
        uint32_t proc, uint32_t slice_idx, uint32_t result)
{
    int ret;
    struct mloader_dump_final_info *final_info = NULL;
    struct mloader_dump_node* node_info = NULL;
    uint32_t final_info_support = 1;

    if (mloader_dump_is_inited() == 0) {
        return;
    }

    ret = mloader_dump_check_param(stage, proc, &final_info_support);
    if (ret) {
        return;
    }

    node_info = mloader_dump_get_node(stage, node_idx, proc);
    if (node_info == NULL) {
        return;
    }
    if (slice_idx >= 2U) {
        bsp_err("slice_idx %u is invalid\n", slice_idx);
        return;
    }
    node_info->proc = proc;
    node_info->proc_result = result;
    node_info->slice[slice_idx] = bsp_get_slice_value();

    if (final_info_support == 0) {
        return;
    }
    final_info = mloader_dump_get_final_info(stage, node_idx);
    if (final_info == NULL) {
        return;
    }
    final_info->final_proc = proc;
}

void mloader_dump_driver_init_start(void)
{
    mloader_dump_set_final_info(INIT_STAGE, 0, 0, MLOADER_RESULT_FAILED);
}

void mloader_dump_driver_init_end(void)
{
    mloader_dump_set_final_info(INIT_STAGE, 0, MLOADER_INIT_MAX_PROC, MLOADER_RESULT_SUCCESS);
}

void mloader_dump_driver_init_proc_start(enum mloader_dump_proc proc)
{
    mloader_dump_set_node_info(INIT_STAGE, 0, proc, 0, MLOADER_RESULT_FAILED);
}

void mloader_dump_driver_init_proc_end(enum mloader_dump_proc proc, int32_t ret)
{
    mloader_dump_set_node_info(INIT_STAGE, 0, proc, 1, ret);
}

void mloader_dump_img_load_start(const char *img_name, unsigned int retry_times)
{
    int ret;
    uint32_t trace;
    struct mloader_dump_load_img_node *node = NULL;

    if (mloader_dump_is_inited() == 0) {
        return;
    }

    if (g_mdm_mloader_dump_info->load_img_trace >= MLOADER_LOAD_IMAGE_MAX_PROC) {
        g_mdm_mloader_dump_info->load_img_trace = 0;
    }
    trace = g_mdm_mloader_dump_info->load_img_trace;

    node = &(g_mdm_mloader_dump_info->img_load_info[trace]);
    (void)memset_s(node, sizeof(*node), 0, sizeof(*node));

    ret = strcpy_s(&(node->img_name[0]), sizeof(node->img_name), img_name);
    if (ret) {
        bsp_err("mloader cpy img_name failed,ret=0x%x\n", ret);
        return;
    }

    node->final_info.result = MLOADER_RESULT_FAILED;
    node->final_info.final_proc = 0;
    node->load_retry_times = retry_times;
}

void mloader_dump_img_load_end(void)
{
    uint32_t node_idx;
    if (mloader_dump_is_inited() == 0) {
        return;
    }
    node_idx = g_mdm_mloader_dump_info->load_img_trace;
    mloader_dump_set_final_info(LOAD_IMAGE_STAGE, node_idx, MLOADER_LOAD_IMAGE_MAX_PROC, MLOADER_RESULT_SUCCESS);
    g_mdm_mloader_dump_info->load_img_trace++;
    if (g_mdm_mloader_dump_info->load_img_trace >= MLOADER_IMG_LOAD_INFO_MAX) {
        g_mdm_mloader_dump_info->load_img_trace = 0;
    }
}

void mloader_dump_img_load_proc_start(enum mloader_dump_proc proc)
{
    uint32_t node_idx;
    if (mloader_dump_is_inited() == 0) {
        return;
    }
    node_idx = g_mdm_mloader_dump_info->load_img_trace;
    mloader_dump_set_node_info(LOAD_IMAGE_STAGE, node_idx, proc, 0, MLOADER_RESULT_FAILED);
}

void mloader_dump_img_load_proc_end(enum mloader_dump_proc proc, int32_t ret)
{
    uint32_t node_idx;
    if (mloader_dump_is_inited() == 0) {
        return;
    }
    node_idx = g_mdm_mloader_dump_info->load_img_trace;
    mloader_dump_set_node_info(LOAD_IMAGE_STAGE, node_idx, proc, 1, ret);
}

void mloader_dump_msg_start(enum mloader_dump_proc proc)
{
    mloader_dump_set_node_info(MSG_STAGE, 0, proc, 0, MLOADER_RESULT_FAILED);
}

void mloader_dump_msg_end(enum mloader_dump_proc proc, int32_t ret)
{
    mloader_dump_set_node_info(MSG_STAGE, 0, proc, 1, ret);
}

void mloader_dump_notifier_mcu_start(void)
{
    mloader_dump_set_node_info(NOTIFY_MCU_STAGE, 0, MLOADER_NOTIFY_MCU_START, 0, MLOADER_RESULT_FAILED);
}

void mloader_dump_notifier_mcu_end(int32_t ret)
{
    mloader_dump_set_node_info(NOTIFY_MCU_STAGE, 0, MLOADER_NOTIFY_MCU_START, 1, ret);
}

void mloader_dump_boot_time_start(void)
{
    mloader_dump_set_node_info(BOOT_TIME_STAGE, 0, MLOADER_BOOT_TIME_START, 0, MLOADER_RESULT_FAILED);
}

void mloader_dump_boot_time_end(void)
{
    mloader_dump_set_node_info(BOOT_TIME_STAGE, 0, MLOADER_BOOT_TIME_START, 1, 0);
}

void mloader_dump_clear_info(void)
{
    unsigned int len;
    if (g_mdm_mloader_dump_info == NULL) {
        bsp_err("mloader dump init failed\n");
        return;
    }
    len = sizeof(g_mdm_mloader_dump_info->img_load_info);
    (void)memset_s(g_mdm_mloader_dump_info->img_load_info, len, 0, len);
    len = sizeof(g_mdm_mloader_dump_info->notify_mcu_info);
    (void)memset_s(&(g_mdm_mloader_dump_info->notify_mcu_info), len, 0, len);
}

void mloader_dump_init(void)
{
    g_mdm_mloader_dump_info =
        (struct mloader_dump_info *)bsp_dump_register_field(DUMP_MODEMAP_MLOADER, "mloader_acore", MLOADER_DUMP_SIZE, 0);
    if (g_mdm_mloader_dump_info != NULL) {
        (void)memset_s((void *)g_mdm_mloader_dump_info, MLOADER_DUMP_SIZE, 0, MLOADER_DUMP_SIZE);
        g_mdm_mloader_dump_info->magic = MLOADER_DUMP_MAGIC;
        return;
    }

    bsp_err("register mloader dump filed failed\n");
    g_mdm_mloader_dump_info = (struct mloader_dump_info *)kzalloc(sizeof(struct mloader_dump_info), GFP_KERNEL);
    if (g_mdm_mloader_dump_info == NULL) {
        bsp_err("malloc mloader dump info failed\n");
        return;
    }
    (void)memset_s((void *)g_mdm_mloader_dump_info, sizeof(struct mloader_dump_info), 0, sizeof(struct mloader_dump_info));
    g_mdm_mloader_dump_info->magic = MLOADER_DUMP_MAGIC;
    return;
}

void mloader_dump_node_show(struct mloader_dump_node *nodes, unsigned int size)
{
    unsigned int i;
    for (i = 0; i < size; i++) {
        bsp_err("proc:0x%x, proc_result:0x%x, start_slice:0x%x, end_slice:0x%x\n", nodes[i].proc, nodes[i].proc_result,
            nodes[i].slice[0], nodes[i].slice[1]);
    }
}

void mloader_dump_load_img_node(void)
{
    unsigned int i;

    for (i = 0; i < MLOADER_IMG_LOAD_INFO_MAX; i++) {
        bsp_err("img_name:%s\n", g_mdm_mloader_dump_info->img_load_info[i].img_name);
        bsp_err("retry_times:%u\n", g_mdm_mloader_dump_info->img_load_info[i].load_retry_times);
        bsp_err("result:0x%x\n", g_mdm_mloader_dump_info->img_load_info[i].final_info.result);
        bsp_err("curr_proc:0x%x\n", g_mdm_mloader_dump_info->img_load_info[i].final_info.final_proc);
        mloader_dump_node_show(g_mdm_mloader_dump_info->img_load_info[i].nodes, MLOADER_LOAD_IMAGE_MAX_PROC -
            MLOADER_LOAD_IMAGE_START);
    }
}

void mloader_dump_show(void)
{
    if (g_mdm_mloader_dump_info == NULL) {
        bsp_err("mloader dump info is NULL\n");
        return;
    }

    bsp_err("magic:0x%x\n", g_mdm_mloader_dump_info->magic);
    bsp_err("load_img_trace:0x%x\n", g_mdm_mloader_dump_info->load_img_trace);

    bsp_err("loader_init_info:\n");
    bsp_err("result:0x%x\n", g_mdm_mloader_dump_info->loader_init_info[0].final_info.result);
    bsp_err("curr_proc:0x%x\n", g_mdm_mloader_dump_info->loader_init_info[0].final_info.final_proc);
    mloader_dump_node_show(g_mdm_mloader_dump_info->loader_init_info[0].nodes, MLOADER_INIT_MAX_PROC -
        MLOADER_INIT_START);

    bsp_err("img_load_info:\n");
    mloader_dump_load_img_node();

    bsp_err("msg info:\n");
    mloader_dump_node_show(&(g_mdm_mloader_dump_info->msg_info[0].nodes[0]), MLOADER_MSG_MAX -
        MLOADER_MSG_FROM_CP);

    bsp_err("notify_mcu_info:\n");
    mloader_dump_node_show(&(g_mdm_mloader_dump_info->notify_mcu_info[0].nodes[0]), MLOADER_NOTIFY_MCU_END -
        MLOADER_NOTIFY_MCU_START);

    bsp_err("boot_time_info:\n");
    mloader_dump_node_show(&(g_mdm_mloader_dump_info->boot_time_info[0].nodes[0]), MLOADER_BOOT_TIME_END -
        MLOADER_BOOT_TIME_START);
}



