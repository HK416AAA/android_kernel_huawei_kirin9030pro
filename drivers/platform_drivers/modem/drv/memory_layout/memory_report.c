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

#include <linux/mm.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/fcntl.h>
#include <linux/spinlock.h>
#include <linux/syscalls.h>
#include <linux/io.h>
#include <linux/time.h>
#include <linux/kthread.h>
#include <../fs/internal.h>
#include <mdrv_memory_layout.h>
#include <bsp_dra.h>
#include <bsp_msg.h>
#include <bsp_rproc.h>
#include <bsp_print.h>
#include <bsp_onoff.h>
#include <msg_id.h>
#include <osl_types.h>
#include <osl_sem.h>
#include <dpa_dmi.h>
#include "memory_layout.h"
#include <securec.h>
#include <product_config.h>

#define COOKIE_NUM_MAX 4000
#define DYNMEM_DUMP_SIZE 0xC000
#define DYNMEM_REPORT_DEBUG_INFO_PTNO_MAX 2
#define DYNMEM_REPORT_DPA_DEBUG_INFO_PTNO_MAX 3
#define DYNMEM_REPORT_BUFFER_LEN 100
#define DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE 50
#define ACORE_RW_FILE_MODE (0660)

/* save acore total size */
#define DYNMEM_REPORT_ACORE_FILE "/data/vendor/log/dfx_logs/modem_log/drv/mem/acore.txt"
#define DYNMEM_REPORT_DPA_FILE "/data/hisi_logs/dpa.txt"
#define DPA_WAIT_TIMEOUT 10000
typedef struct {
    unsigned int type;   /* 分区类型：0-cache,1-uncache, dpa:0-dtcm,4-cache,5-uncache */
    unsigned int size;   /* 内存申请大小 */
    unsigned int cookie; /* 内存申请cookie信息 */
} dynmem_report_info_s;

typedef struct {
    unsigned int ap_used;
    unsigned int ap_available;
    unsigned int ap_maa_alloc;
    unsigned int aslr_offset;
    unsigned int total_size[DYNMEM_REPORT_DEBUG_INFO_PTNO_MAX];
    unsigned int free_size[DYNMEM_REPORT_DEBUG_INFO_PTNO_MAX];
    unsigned int mem_count;
    dynmem_report_info_s mem_info[COOKIE_NUM_MAX];
} dynmem_detail_dump_s;
dynmem_detail_dump_s *g_dynmem_dump_field = NULL;
static msg_chn_t g_acore_mem_msg_chn;

typedef struct {
    unsigned int total_size[DYNMEM_REPORT_DPA_DEBUG_INFO_PTNO_MAX];
    unsigned int free_size[DYNMEM_REPORT_DPA_DEBUG_INFO_PTNO_MAX];
    unsigned int mem_count;
    dynmem_report_info_s mem_info[COOKIE_NUM_MAX];
} dpa_dynmem_detail_dump_s;

osl_sem_id g_sem;

unsigned int get_acore_available_size(void)
{
    struct sysinfo si;
    unsigned long long available;
    si_meminfo(&si);
    available = (unsigned long long)(si_mem_available() * si.mem_unit);
    return (unsigned int)available;
}

#ifndef BSP_CONFIG_PHONE_TYPE
unsigned int get_acore_total_size(void)
{
    unsigned int total_size = 0;
    unsigned long pa;
    unsigned int size;
    int i = 0;
    char *name[] = {"acore_ddr", "acore_dts_ddr", NULL};
    while (name[i] != NULL) {
        pa = mdrv_mem_region_get(name[i], &size);
        if (pa != 0 && size != 0) {
            total_size += size;
        }
        i++;
    }
    return total_size;
}
#endif

static void mem_drop_pagecache(void)
{
#ifndef BSP_CONFIG_PHONE_TYPE
    char *value = "3";
    struct file *filp = NULL;
    unsigned long fs;
    loff_t pos = 0;

    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    filp = filp_open("/proc/sys/vm/drop_caches", O_WRONLY, 0);
    if (IS_ERR_OR_NULL(filp)) {
        set_fs(fs);
        bsp_err("fail to open file %s!\n", "/proc/sys/vm/drop_caches");
        return;
    }
    (void)kernel_write(filp, value, strlen(value), &pos);
    (void)vfs_fsync(filp, 0);
    (void)filp_close(filp, NULL);
    set_fs(fs);
#endif
}

static void acore_drop_cache(void)
{
#ifndef BSP_CONFIG_PHONE_TYPE
    ksys_sync();
    mem_drop_pagecache();
    drop_slab();
#endif
}

#ifdef BSP_CONFIG_PHONE_TYPE
static int acore_sendto_ccore(void *arg)
{
    int ret;
#if IS_ENABLED(CONFIG_DPA_DRIVERS)
    ret = osl_sem_downtimeout(&g_sem, msecs_to_jiffies(DPA_WAIT_TIMEOUT));
    if (ret != 0) {
        bsp_err("Get response from dpa reset timeout within 10s\n");
        return BSP_ERROR;
    }
#endif
    char buffer[DYNMEM_REPORT_BUFFER_LEN + 1] = {0};
    struct msg_addr dst;
    ret = snprintf_s(buffer, (DYNMEM_REPORT_BUFFER_LEN + 1), DYNMEM_REPORT_BUFFER_LEN,
        "ACORE DRV %u\nACORE OPENCPU %u\nACORE USER_PLANE %u\n", g_dynmem_dump_field->ap_used,
        g_dynmem_dump_field->ap_available, g_dynmem_dump_field->ap_maa_alloc);
    if (ret < 0) {
        bsp_err("snprintf_s fail!\n");
        return BSP_ERROR;
    }
    dst.core = MSG_CORE_TSP;
    dst.chnid = MSG_CHN_DMSS_AUTO;
    ret = bsp_msg_lite_sendto(g_acore_mem_msg_chn, &dst, buffer, strlen(buffer));
    if (ret) {
        bsp_err("send acore info to tsp fail!\n");
    }
    return ret;
}
#endif

#ifndef BSP_CONFIG_PHONE_TYPE
static void save_acore_meminfo(void)
{
    int ret;
    char buffer[DYNMEM_REPORT_BUFFER_LEN + 1] = {0};
    struct file *filp = NULL;
    unsigned long fs;
    loff_t pos = 0;

    ret = snprintf_s(buffer, (DYNMEM_REPORT_BUFFER_LEN + 1), DYNMEM_REPORT_BUFFER_LEN,
        "ACORE DRV %u\nACORE OPENCPU %u\nACORE USER_PLANE %u\n", g_dynmem_dump_field->ap_used,
        g_dynmem_dump_field->ap_available, g_dynmem_dump_field->ap_maa_alloc);
    if (ret < 0) {
        bsp_err("snprintf_s fail!\n");
        return;
    }
    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    filp = filp_open(DYNMEM_REPORT_ACORE_FILE, O_CREAT | O_RDWR, 0);
    set_fs(fs);
    if (IS_ERR_OR_NULL(filp)) {
        bsp_err("fail to open file %s!\n", DYNMEM_REPORT_ACORE_FILE);
        return;
    }
    set_fs((mm_segment_t)KERNEL_DS);
    (void)kernel_write(filp, buffer, strlen(buffer), &pos);
    (void)vfs_fsync(filp, 0);
    (void)filp_close(filp, NULL);
    set_fs(fs);
}
#else
static void save_acore_meminfo(void)
{
#if IS_ENABLED(CONFIG_DPA_DRIVERS)
    struct task_struct *thread = NULL;
    thread = kthread_run(acore_sendto_ccore, NULL, "acore_sendto_ccore");
    if (IS_ERR_OR_NULL(thread)) {
        bsp_err("fail to create thread, ret = %ld\n", PTR_ERR(thread));
        return;
    }
#else
    acore_sendto_ccore(NULL);
#endif
    
}
#endif

#if IS_ENABLED(CONFIG_DPA_DRIVERS)
struct dpa_msg_data {
    u64 addr;
    u32 len;
};

static int msg_sendto_dpa()
{
    int ret;
    struct dmi_msg *msg = NULL;
    unsigned int msg_len = sizeof(struct dmi_msg);

    msg = (struct dmi_msg *)kmalloc(msg_len, GFP_KERNEL);
    if (msg == NULL) {
        bsp_err("memory report dmi msg malloc fail\n");
        return BSP_ERROR;
    }

    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_DPA_DYNMEM;

    ret = dpa_dmi_client_request_comm_wake(msg, sizeof(*msg));
    if (ret) {
        bsp_err("acore dmi send fail:%d\n", ret);
    }

    kfree(msg);
    return ret;
}

int save_dpa_type(struct file *filp, dpa_dynmem_detail_dump_s *dpa_detail_info, loff_t *pos)
{
    u8 uc_pt_no;
    s32 i_ret;
    u32 count;
    unsigned long fs;
    char buffer[DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1] = {0};
    fs = get_fs();

    for (uc_pt_no = 0; uc_pt_no < DYNMEM_REPORT_DPA_DEBUG_INFO_PTNO_MAX; uc_pt_no++) {
        (void)memset_s(buffer, DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1, 0, DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1);
        i_ret = snprintf_s(buffer, (DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1), (DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE),
                           "Type:%d Total:0x%08x Reserved:0x%08x\r\n", uc_pt_no,
                           dpa_detail_info->total_size[uc_pt_no], dpa_detail_info->free_size[uc_pt_no]);
        if (i_ret == -1) {
            bsp_err("failed to store type info\n");
            return BSP_ERROR;
        }
        set_fs((mm_segment_t)KERNEL_DS);
        (void)kernel_write(filp, buffer, strlen(buffer), pos);
        set_fs(fs);
    }
    return BSP_OK;
}

int save_dpa_detail(struct file *filp, dpa_dynmem_detail_dump_s *dpa_detail_info, loff_t *pos)
{
    u8 uc_pt_no;
    s32 i_ret;
    u32 count;
    unsigned long fs;
    char buffer[DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1] = {0};
    fs = get_fs();

    unsigned int total_count = 0;
    for (count = 0; count < dpa_detail_info->mem_count; count++) {
        total_count += dpa_detail_info->mem_info[count].size;
        (void)memset_s(buffer, DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1, 0, DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1);
        i_ret = snprintf_s(buffer, (DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1), (DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE),
                               "Type:%d Size:%8u CooKie:0x%08x\r\n", dpa_detail_info->mem_info[count].type,
                                dpa_detail_info->mem_info[count].size, dpa_detail_info->mem_info[count].cookie);
        if (i_ret == -1) {
            bsp_err("failed to store detail info\n");
            return BSP_ERROR;
        }
        set_fs((mm_segment_t)KERNEL_DS);
        (void)kernel_write(filp, buffer, strlen(buffer), pos);
        set_fs(fs);
    }
    (void)memset_s(buffer, DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1, 0, DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1);
    i_ret = snprintf_s(buffer, (DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1), (DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE),
                       "Dynmem Total Count :%u \n", total_count);
    if (i_ret == -1) {
        bsp_err("failed to store total info\n");
        return BSP_ERROR;
    }
    set_fs((mm_segment_t)KERNEL_DS);
    (void)kernel_write(filp, buffer, strlen(buffer), pos);
    set_fs(fs);
    (void)vfs_fsync(filp, 0);
    
    return BSP_OK;
}

int save_dpa_file(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    struct file *filp = NULL;
    unsigned long fs;
    loff_t pos = 0;
    s32 i_ret;
    char buffer[DYNMEM_TOTAL_COUNT_INFO_STRING_SIZE + 1] = {0};

    if (msg == NULL) {
        bsp_err("recv msg from dap invalid\n");
        return BSP_ERROR;
    }
    if (msg->len != sizeof(struct dpa_msg_data)) {
        bsp_err("recv msg from dap invalid, msg->len:%d\n", msg->len);
        return BSP_ERROR;
    }
    struct dpa_msg_data *dpa_info = (struct dpa_msg_data *)msg->buf;
    dpa_dynmem_detail_dump_s *dpa_detail_info = NULL;

    dpa_detail_info = (dpa_dynmem_detail_dump_s *)phys_to_virt((uintptr_t)dpa_info->addr);
    if (dpa_detail_info == NULL) {
        bsp_err("phys_to_virt fail!\n");
        return BSP_ERROR;
    }
    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    s32 flags = O_RDWR | O_CREAT;
    filp = filp_open(DYNMEM_REPORT_DPA_FILE, flags, ACORE_RW_FILE_MODE);
    set_fs(fs);
    if (IS_ERR(filp)) {
        bsp_err("fail to open file %s,error: %ld !\n", DYNMEM_REPORT_DPA_FILE, PTR_ERR(filp));
        return BSP_ERROR;
    }

    i_ret = save_dpa_type(filp, dpa_detail_info, &pos);
    if (i_ret == -1) {
        goto log_save_error;
    }

    i_ret = save_dpa_detail(filp, dpa_detail_info, &pos);
    if (i_ret == -1) {
        goto log_save_error;
    }
    osl_sem_up(&g_sem);

log_save_error:
    (void)filp_close(filp, NULL);
    return 0;
}

static void save_dpa_meminfo()
{
    int ret;
    ret = msg_sendto_dpa();
    if (ret) {
        bsp_err("send acore info to dpa fail!\n");
    }
    return;
}
#endif

int memory_acore_msg_handler(const struct msg_addr *src, void *buf, unsigned int len)
{
    if (g_dynmem_dump_field == NULL) {
        return -1;
    }
    acore_drop_cache();
    g_dynmem_dump_field->ap_available = get_acore_available_size();
    g_dynmem_dump_field->ap_maa_alloc = bsp_dra_get_cur_mem();
#ifdef BSP_CONFIG_PHONE_TYPE
    g_dynmem_dump_field->ap_used = 0;
#else
    g_dynmem_dump_field->ap_used = get_acore_total_size() - g_dynmem_dump_field->ap_available -
        g_dynmem_dump_field->ap_maa_alloc;
#endif
    save_acore_meminfo();
#if IS_ENABLED(CONFIG_DPA_DRIVERS)
    save_dpa_meminfo();
#endif
#if (!defined BSP_CONFIG_PHONE_TYPE) && (defined CHOOSE_MODEM_USER)
    bsp_drv_power_reboot();
#endif
    return 0;
}

void bsp_dynmem_field_init(void)
{
    unsigned long pa;
    unsigned int size;
    unsigned int phy_addr;

    pa = mdrv_mem_region_get("mntn_ddr", &size);
    if (pa == 0 || size == 0) {
        bsp_err("get mntn_ddr addr fail!\n");
        return;
    }
    phy_addr = pa + size - DYNMEM_DUMP_SIZE;
    g_dynmem_dump_field = (dynmem_detail_dump_s *)ioremap_wc(phy_addr, DYNMEM_DUMP_SIZE);
    if (g_dynmem_dump_field == NULL) {
        bsp_err("dynmem_dump ioremap_wc error\n");
    }
}

int acore_mem_msg_init(void)
{
    int ret;
    struct msgchn_attr lite_attr = { 0 };

    bsp_msgchn_attr_init(&lite_attr);
    /* 复用DMSS自动化测试用例通道，自动化测试不涉及ccore发消息给acore */
    lite_attr.chnid = MSG_CHN_DMSS_AUTO;
    lite_attr.coremask = MSG_CORE_MASK(MSG_CORE_TSP);
    lite_attr.lite_notify = memory_acore_msg_handler;
    ret = bsp_msg_lite_open(&g_acore_mem_msg_chn, &lite_attr);
    return ret;
}
#if IS_ENABLED(CONFIG_DPA_DRIVERS)
void acore_dmi_client_init(void)
{
    int ret;
    struct dmi_client dpa_dmi_client;
    if (dpa_dmi_client_init(&dpa_dmi_client)) {
        bsp_err("memory report dmi client init err\n");
        return;
    }

    dpa_dmi_client.dmi_id = DMI_SERVICE_DPA_DYNMEM;
    dpa_dmi_client.service_cb = save_dpa_file;

    ret = dpa_dmi_client_register(&dpa_dmi_client);
    if (ret) {
        bsp_err("dpa dmi register fail:%d\n", ret);
        return;
    }
}
#endif

int bsp_memory_report_init(void)
{
    acore_mem_msg_init();
    bsp_dynmem_field_init();
#if IS_ENABLED(CONFIG_DPA_DRIVERS)
    acore_dmi_client_init();
    osl_sem_init(0,&g_sem);
#endif
    return OK;
}
#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(bsp_memory_report_init);
#endif
