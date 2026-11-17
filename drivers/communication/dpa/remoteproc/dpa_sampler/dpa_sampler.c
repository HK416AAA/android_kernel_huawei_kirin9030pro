/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
 */
#include <linux/module.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/fcntl.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/version.h>
#include <linux/init_syscalls.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/semaphore.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <securec.h>
#include <bsp_nmi.h>
#include <bsp_dmi.h>
#include <bsp_dump.h>
#include <bsp_file_ops.h>
#include <bsp_dt.h>
#include "dpa_sampler.h"

#undef THIS_MODU
#define THIS_MODU mod_dpa_sampler

dpa_sampler_config_params g_config_params = {0};
dpa_sampler_ctrl_t g_dpa_sampler_ctrl = {0};
dpa_sampler_pc_regs g_dpa_sampler_pc_regs = {0};

struct semaphore dpa_sampler_task_sem;
struct semaphore dpa_sampler_msg_sem;

int dpa_sampler_stop(void);
int dpa_sampler_send_dpa(unsigned int msg_type);

dpa_sampler_config_params *dpa_sampler_get_config(void)
{
    return &g_config_params;
}

dpa_sampler_ctrl_t *dpa_sampler_get_ctrl(void)
{
    return &g_dpa_sampler_ctrl;
}

unsigned int dpa_sampler_sample_core_num(unsigned int sample_core)
{
    unsigned int num = 0;
    while (sample_core) {
        sample_core &= sample_core - 1;
        num++;
    }
    return num;
}

unsigned int dpa_sampler_get_core_idx(unsigned int num)
{
    unsigned int count = 0;
    u32 i;
    for (i = 0; i < g_dpa_sampler_ctrl.dpa_core_num; i++) {
        if (((g_config_params.sample_core >> i) & 1) == 1) {
            count++;
            if (count == num) {
                return i + 1;
            }
        }
    }
    return 0;
}

void dpa_sampler_help(void)
{
    dpa_sampler_err("dpa_sampler cmd:\n");
    dpa_sampler_err("dpa_sampler [sample_type] [sample_freq] [sample_dur] [sample_core] [buffer_size] [buffer_mode]\n");
    dpa_sampler_err("---------------------------param usage---------------------------\n");
    dpa_sampler_err("sample_type : 0-flame graph, 1-hotspot function, 2-pmu, 3-flame graph + pmu.\n");
    dpa_sampler_err("sample_freq : sample frequency, unit is Hz. 1 ~ 10kHz(pc:50kHz).\n");
    dpa_sampler_err("sample_dur  : sample duration, unit is second.\n");
    dpa_sampler_err("sample_core : bit mask set 1.\n");
    dpa_sampler_err("buffer_size : buffer size, unit is byte, must be a multiple of 256.\n");
    dpa_sampler_err("buffer_mode : 0-cycle write, 1-stop when write full.\n");
    dpa_sampler_err("-----------------------------------------------------------------\n");
    return;
}

void dpa_sampler_debug(void)
{
    u32 i;
    dpa_sampler_err("dpa_sampler config_params:\n");
    dpa_sampler_err("sample_type:%d\n", g_config_params.sample_type);
    dpa_sampler_err("sample_freq:%d\n", g_config_params.sample_freq);
    dpa_sampler_err("sample_dur:%d\n", g_config_params.sample_dur);
    dpa_sampler_err("sample_core:%d\n", g_config_params.sample_core);
    dpa_sampler_err("buffer_size:%d\n", g_config_params.buffer_size);
    dpa_sampler_err("buffer_mode:%d\n", g_config_params.buffer_mode);
    dpa_sampler_err("dpa_sampler ctrl:\n");
    dpa_sampler_err("state:%d\n", g_dpa_sampler_ctrl.state);
    for (i = 0; i < g_dpa_sampler_ctrl.sample_core_num; i++) {
        dpa_sampler_err("buffer%d\n", i);
        dpa_sampler_err("phy_addr:0x%llx\n", g_dpa_sampler_ctrl.buffers[i].phy_addr);
        dpa_sampler_err("virt_addr:0x%llx\n", g_dpa_sampler_ctrl.buffers[i].virt_addr);
        dpa_sampler_err("buffer_size:%d\n", g_dpa_sampler_ctrl.buffers[i].buffer_size);
        dpa_sampler_err("rb_rptr:%d\n", g_dpa_sampler_ctrl.buffers[i].rb_rptr);
        dpa_sampler_err("rb_wptr:%d\n", g_dpa_sampler_ctrl.buffers[i].rb_wptr);
        dpa_sampler_err("data_size:%d\n", g_dpa_sampler_ctrl.buffers[i].data_size);
    }
    return;
}

static int dpa_sample_flame_graph(void)
{
    // 触发nmi
    return bsp_dpa_nmi_trigger(g_dpa_sampler_ctrl.dpa_core_bitmask, DPA_NMI_DPA_SAMPLER);
}

static int dpa_sample_hotspot_function(void)
{
    u32 buf_idx = 0;
    u32 i;
    for (i = 0; i < g_dpa_sampler_ctrl.dpa_core_num; i++) {
        if (((g_config_params.sample_core >> i) & 1) == 1) {
            // 获取PC值，写入rb
            unsigned int pc = readl((void *)((uintptr_t)g_dpa_sampler_ctrl.dpa_core_pc_regs_virt[i]));
            dpa_sampler_rb_write(&g_dpa_sampler_ctrl.buffers[buf_idx], g_config_params.buffer_mode, &pc, sizeof(int));
            buf_idx++;
        }
    }
    return DPA_SAMPLER_OK;
}

static enum hrtimer_restart dpa_sampler_hrtimer_callback(struct hrtimer *timer)
{
    if ((g_config_params.sample_type & 0xFF) != MODE_DPA_PC) {
        dpa_sample_flame_graph();
    } else {
        dpa_sample_hotspot_function();
    }
    g_dpa_sampler_ctrl.sample_count++;
    if (g_dpa_sampler_ctrl.sample_count < g_config_params.sample_dur * g_config_params.sample_freq) {
        hrtimer_forward_now(timer, g_dpa_sampler_ctrl.hrtimer_period);
        return HRTIMER_RESTART;
    } else {
        up(&dpa_sampler_task_sem);
        return HRTIMER_NORESTART;
    }
}

int dpa_sampler_timed(void)
{
    g_dpa_sampler_ctrl.sample_count = 0;
    hrtimer_init(&g_dpa_sampler_ctrl.hrtimer_handle, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
    g_dpa_sampler_ctrl.hrtimer_handle.function = dpa_sampler_hrtimer_callback;
    g_dpa_sampler_ctrl.hrtimer_period = ktime_set(0, 1000000000LL / g_config_params.sample_freq);
    hrtimer_start(&g_dpa_sampler_ctrl.hrtimer_handle, g_dpa_sampler_ctrl.hrtimer_period, HRTIMER_MODE_REL);
    return DPA_SAMPLER_OK;
}

int dpa_sampler_timed_delete(void)
{
    return hrtimer_try_to_cancel(&g_dpa_sampler_ctrl.hrtimer_handle);
}

int dpa_sampler_start_sample(void)
{
    int ret;
    // 开始采集，计时
    ret = dpa_sampler_timed();
    if (ret) {
        dpa_sampler_rb_release();
        return DPA_SAMPLER_ERR;
    }
    g_dpa_sampler_ctrl.state = DPA_SAMPLER_RUNNING;
    dpa_sampler_err("dpa_sampler start ok.\n");
    return DPA_SAMPLER_OK;
}

int dpa_sampler_start(void)
{
    int ret;
    // 申请buffer
    ret = dpa_sampler_rb_alloc();
    if (ret) {
        dpa_sampler_rb_release();
        return DPA_SAMPLER_ERR;
    }
    // 从dpa fw获取aslr和base_pa
    ret = dpa_sampler_send_dpa(DPA_SAMPLER_MSG_GET_ASLR);
    if (ret) {
        dpa_sampler_err("dpa_sampler get aslr err.\n");
        dpa_sampler_rb_release();
        return DPA_SAMPLER_ERR;
    }

    if ((g_config_params.sample_type & 0xFF) != MODE_DPA_PC) {
        // 向dpa传递buffer信息
        ret = dpa_sampler_send_dpa(DPA_SAMPLER_MSG_BUF_TO_DPA);
        if (ret) {
            dpa_sampler_err("dpa_sampler send buf err.\n");
            dpa_sampler_rb_release();
            return DPA_SAMPLER_ERR;
        }
    }

    return dpa_sampler_start_sample();
}

/*
    热点函数file data:
    {
        version;
        config_params;
        aslr;
        base_pa;
        [
            {data_len; core; pc_data},
            {data_len; core; pc_data},
        ]
    }
    pc_data: [u32,......]
    火焰图file data:
    {
        version;
        config_params;
        aslr;
        base_pa;
        [
            {data_len; core; callstack_data},
            {data_len; core; callstack_data},
        ]
    }
    callstack_data:[{magic, type, depth, callstack[depth]},......]
*/
int dpa_sampler_write_file(unsigned long fs, struct file *filp)
{
    loff_t pos = 0;
    u32 j;
    unsigned int version = DPA_SAMPLER_VERSION;
    unsigned int pack_size, data_size, rb_wrptr, core;

    set_fs((mm_segment_t)KERNEL_DS);

    (void)kernel_write(filp, &version, sizeof(int), &pos);
    (void)kernel_write(filp, &g_config_params, sizeof(dpa_sampler_config_params), &pos);
    (void)kernel_write(filp, &g_dpa_sampler_ctrl.aslr_data, sizeof(int), &pos);
    (void)kernel_write(filp, &g_dpa_sampler_ctrl.bsae_pa, sizeof(int), &pos);
    (void)kernel_write(filp, &g_dpa_sampler_ctrl.mo_base_pa, sizeof(int), &pos);
    (void)kernel_write(filp, &g_dpa_sampler_ctrl.pl1text_base_pa, sizeof(int), &pos);

    for (j = 0; j < g_dpa_sampler_ctrl.sample_core_num; j++) {
        data_size = g_dpa_sampler_ctrl.buffers[j].data_size;
        rb_wrptr = g_dpa_sampler_ctrl.buffers[j].rb_wptr;
        pack_size = data_size + sizeof(int);
        core = dpa_sampler_get_core_idx(j+1);
        (void)kernel_write(filp, &pack_size, sizeof(int), &pos);
        (void)kernel_write(filp, &core, sizeof(int), &pos);

        if (rb_wrptr < data_size) {
            (void)kernel_write(filp, (const void*)g_dpa_sampler_ctrl.buffers[j].virt_addr + rb_wrptr,
                data_size - rb_wrptr, &pos);
            (void)kernel_write(filp, (const void*)g_dpa_sampler_ctrl.buffers[j].virt_addr, rb_wrptr, &pos);
        } else {
            (void)kernel_write(filp, (const void*)g_dpa_sampler_ctrl.buffers[j].virt_addr, data_size, &pos);
        }
    }

    (void)vfs_fsync(filp, 0);
    (void)filp_close(filp, NULL);
    set_fs(fs);

    dpa_sampler_rb_release();
    return DPA_SAMPLER_OK;
}

int dpa_sampler_save_file(void)
{
    struct file *filp = NULL;
    unsigned long fs;
    if (bsp_eaccess(DPA_SAMPLER_DATA_FILE) == 0) {  // old file存在，删除
        (void)bsp_unlink(DPA_SAMPLER_DATA_FILE);
    }
    fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    filp = filp_open(DPA_SAMPLER_DATA_FILE, O_CREAT | O_RDWR | O_TRUNC, DPA_SAMPLER_RW_FILE_MODE);
    set_fs(fs);
    if (IS_ERR_OR_NULL(filp)) {
        dpa_sampler_err("fail to open file %s,error: %ld !\n", DPA_SAMPLER_DATA_FILE, PTR_ERR(filp));
        dpa_sampler_rb_release();
        return DPA_SAMPLER_ERR;
    }
    return dpa_sampler_write_file(fs, filp);
}

int dpa_sampler_stop(void)
{
    int ret;
    ret = dpa_sampler_timed_delete();
    if (ret) {
        dpa_sampler_err("hrtimer delete fail.\n");
        dpa_sampler_rb_release();
        return DPA_SAMPLER_ERR;
    }
    ret = dpa_sampler_save_file();
    if (ret) {
        dpa_sampler_rb_release();
        return DPA_SAMPLER_ERR;
    }
    g_dpa_sampler_ctrl.state = DPA_SAMPLER_STOP;
    dpa_sampler_err("dpa_sampler stop ok.\n");
    return DPA_SAMPLER_OK;
}

static int dpa_sampler_check_params(u32 type, u32 freq, u32 dur, u32 core, u32 buffer_size, u32 buffer_mode)
{
    if ((type & 0xFF) > MODE_MAX-1) {
        dpa_sampler_err("dpa_sampler param [sample_type] err.\n");
        return DPA_SAMPLER_ERR;
    }
    if (freq == 0 || ((type & 0xFF)!= MODE_DPA_PC && freq > DPA_SAMPLER_MAX_FREQ) || freq > DPA_SAMPLER_PC_MAX_FREQ) {
        dpa_sampler_err("dpa_sampler param [sample_freq] err.\n");
        return DPA_SAMPLER_ERR;
    }
    if (dur == 0) {
        dpa_sampler_err("dpa_sampler param [sample_dur] err.\n");
        return DPA_SAMPLER_ERR;
    }
    if (core == 0 || core > g_dpa_sampler_ctrl.dpa_core_bitmask) {
        dpa_sampler_err("dpa_sampler param [sample_core] err.\n");
        return DPA_SAMPLER_ERR;
    }
    if (buffer_size == 0 || buffer_size < DPA_SAMPLER_MIN_BUF_SIZE || buffer_size % DPA_SAMPLER_MIN_BUF_SIZE != 0) {
        dpa_sampler_err("dpa_sampler param [buffer_size] err.\n");
        return DPA_SAMPLER_ERR;
    }
    if (buffer_mode != CYCLE_WRITE && buffer_mode != WRITE_FULL) {
        dpa_sampler_err("dpa_sampler param [buffer_mode] err.\n");
        return DPA_SAMPLER_ERR;
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler(u32 type, u32 freq, u32 dur, u32 core, u32 buffer_size, u32 buffer_mode)
{
    u32 i;
    if (g_dpa_sampler_ctrl.state == DPA_SAMPLER_RUNNING) {
        dpa_sampler_err("dpa_sampler is running, start fail.\n");
        return DPA_SAMPLER_ERR;
    }

    if (dpa_sampler_check_params(type, freq, dur, core, buffer_size, buffer_mode)) {
        return DPA_SAMPLER_ERR;
    }
    g_config_params.sample_type = type;
    g_config_params.sample_freq = freq;
    g_config_params.sample_dur = dur;
    g_config_params.sample_core = core;
    g_config_params.buffer_size = buffer_size;
    g_config_params.buffer_mode = buffer_mode;
    g_dpa_sampler_ctrl.sample_core_num = dpa_sampler_sample_core_num(core);
    for (i = 0; i < g_dpa_sampler_ctrl.sample_core_num; i++) {
        g_dpa_sampler_ctrl.buffers[i].buffer_size = buffer_size;
        g_dpa_sampler_ctrl.buffers[i].buffer_mode = buffer_mode;
    }

    return dpa_sampler_start();
}

int dpa_sampler_dmi_msg_response(void)
{
    u32 ret;
    ret = down_timeout(&dpa_sampler_msg_sem, DPA_SAMPLER_DMI_TIMEOUT);
    if (ret) {
        dpa_sampler_err("dpa_sampler sem timeout %d\n", ret);
        return DPA_SAMPLER_ERR;
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler_dmi_send(void *data, u32 data_len)
{
    int ret;
    struct dmi_msg *msg = NULL;
    unsigned int msg_len = ALIGN(sizeof(struct dmi_msg) + data_len, 4);
    msg = (struct dmi_msg *)kmalloc(msg_len, GFP_KERNEL);
    if (msg == NULL) {
        dpa_sampler_err("dpa_sampler dmi msg malloc fail\n");
        return DPA_SAMPLER_ERR;
    }

    msg->plane = DMI_SERVICE_TYPE_COMM;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_DPA_SAMPLER;

    msg->data.len = msg_len - sizeof(struct dmi_msg);
    ret = memcpy_s(msg->data.buf, msg->data.len, data, data_len);
    if (ret) {
        dpa_sampler_err("dpa_sampler memcpy fail\n");
        kfree(msg);
        return ret;
    }
    ret = bsp_dmi_client_request_comm_wake(msg, sizeof(*msg) + msg->data.len);
    if (ret) {
        dpa_sampler_err("dpa_sampler dmi send fail:%d\n", ret);
    }
    kfree(msg);
    return ret;
}

int dpa_sampler_send_dpa(unsigned int msg_type)
{
    dpa_sampler_msg msg;
    msg.msg_type = msg_type;
    msg.sample_type = g_config_params.sample_type;
    msg.sample_core = g_config_params.sample_core;
    memcpy_s(&msg.buffers, sizeof(msg.buffers), g_dpa_sampler_ctrl.buffers, sizeof(msg.buffers));
    if (dpa_sampler_dmi_send(&msg, sizeof(dpa_sampler_msg))) {
        return DPA_SAMPLER_ERR;
    }
    return dpa_sampler_dmi_msg_response();
}

int dpa_sampler_dmi_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    if (msg == NULL || msg->len != sizeof(dpa_sampler_msg)) {
        dpa_sampler_err("dpa_sampler dmi msg is null.\n");
        return DPA_SAMPLER_ERR;
    }
    dpa_sampler_msg *sampler_msg = (dpa_sampler_msg *)msg->buf;
    switch (sampler_msg->msg_type) {
        case DPA_SAMPLER_MSG_GET_ASLR_RES:
            up(&dpa_sampler_msg_sem);
            g_dpa_sampler_ctrl.aslr_data = sampler_msg->aslr;
            g_dpa_sampler_ctrl.bsae_pa = sampler_msg->bsae_pa;
            g_dpa_sampler_ctrl.mo_base_pa = sampler_msg->mo_base_pa;
            g_dpa_sampler_ctrl.pl1text_base_pa = sampler_msg->pl1text_base_pa;
            break;
        case DPA_SAMPLER_MSG_BUF_TO_DPA_RES:
            up(&dpa_sampler_msg_sem);
            break;
        case DPA_SAMPLER_MSG_GET_BUF_RES:
            memcpy_s(&g_dpa_sampler_ctrl.buffers, sizeof(g_dpa_sampler_ctrl.buffers), sampler_msg->buffers,
                sizeof(g_dpa_sampler_ctrl.buffers));
            up(&dpa_sampler_msg_sem);
            break;
        default:
            dpa_sampler_err("dpa_sampler dmi msg type err.\n");
            break;
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler_dmi_client_init(void)
{
    int ret;
    struct dmi_client dpa_sampler_dmi_client;

    ret = bsp_dmi_client_init(&dpa_sampler_dmi_client);
    if (ret != 0) {
        dpa_sampler_err("dpa_sampler dmi init fail:%d.\n", ret);
        return ret;
    }

    dpa_sampler_dmi_client.dmi_id = DMI_SERVICE_DPA_SAMPLER;
    dpa_sampler_dmi_client.service_cb = dpa_sampler_dmi_cb;

    ret = bsp_dmi_client_register(&dpa_sampler_dmi_client);
    if (ret != 0) {
        dpa_sampler_err("dpa_sampler_dmi_client fail %d\n", ret);
        return ret;
    }

    return ret;
}

int dpa_sampler_task(void *data)
{
    while (1) {
        down(&dpa_sampler_task_sem);
        if ((g_config_params.sample_type & 0xFF) != MODE_DPA_PC) {
            if (dpa_sampler_send_dpa(DPA_SAMPLER_MSG_GET_BUF)){
                dpa_sampler_err("dpa_sampler get buf err.\n");
                return DPA_SAMPLER_ERR;
            }
        }
        dpa_sampler_stop();
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler_task_init(void)
{
    struct task_struct *pid = NULL;

    sema_init(&dpa_sampler_task_sem, 0);
    sema_init(&dpa_sampler_msg_sem, 0);
    pid = kthread_run(dpa_sampler_task, NULL, "dpa_sampler_task");
    if (IS_ERR(pid)) {
        dpa_sampler_err(" dpa_sampler_task init error!\n");
        return DPA_SAMPLER_ERR;
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler_suspend(struct device *dev)
{
    if (g_dpa_sampler_ctrl.state == DPA_SAMPLER_RUNNING) {
        up(&dpa_sampler_task_sem);
    }
    return DPA_SAMPLER_OK;
}

static const struct dev_pm_ops g_dpa_sampler_pmops = {
    .suspend = dpa_sampler_suspend,
};

static struct platform_driver g_dpa_sampler_pltfm_driver = {
    .driver =
        {
            .name = "dpa_sampler",
            .pm = &g_dpa_sampler_pmops,
            .probe_type = PROBE_FORCE_SYNCHRONOUS,
        },
};

static struct platform_device g_dpa_sampler_device = {
    .name = "dpa_sampler",
    .id = -1,
    .num_resources = 0,
};

int dpa_sampler_driver_init(void)
{
    if (platform_device_register(&g_dpa_sampler_device)) {
        dpa_sampler_err("dpa_sampler dev register fail.\n");
        return DPA_SAMPLER_ERR;
    }

    if (platform_driver_register(&g_dpa_sampler_pltfm_driver)) {
        dpa_sampler_err("dpa_sampler drv register fail.\n");
        return DPA_SAMPLER_ERR;
    }

    return DPA_SAMPLER_OK;
}

void dpa_sampler_dump_hook(void)
{
    if (g_dpa_sampler_ctrl.state == DPA_SAMPLER_RUNNING) {
        up(&dpa_sampler_task_sem);
    }
}

int dpa_sampler_dump_init(void)
{
    int ret;
    ret = bsp_dpa_dump_register_hook("dpa_sampler", dpa_sampler_dump_hook);
    if (ret == -1) {
        dpa_pr_err("dpa_sampler register dump fail\n");
        return ret;
    }
    return 0;
}


int dpa_sampler_dtsi_init(void)
{
    int ret;
    u32 i;
    device_node_s *dev = bsp_dt_find_compatible_node(NULL, NULL, "dpa_sampler,dpa");
    if (dev == NULL) {
        dpa_sampler_err("dpa_sampler dtsi not found.\n");
        return DPA_SAMPLER_ERR;
    }

    ret = bsp_dt_property_read_u32_array(dev, "dpa_core_num", &g_dpa_sampler_ctrl.dpa_core_num, 1);
    if (ret) {
        dpa_sampler_err("no dpa_core_num\n");
        return DPA_SAMPLER_ERR;
    }
    if (g_dpa_sampler_ctrl.dpa_core_num > DPA_CORE_MAX_NUM) {
        dpa_sampler_err("dpa_core_num err\n");
        return DPA_SAMPLER_ERR;
    }

    ret = bsp_dt_property_read_u32_array(dev, "dpa_core_bitmask", &g_dpa_sampler_ctrl.dpa_core_bitmask, 1);
    if (ret) {
        dpa_sampler_err("no dpa_core_bitmask\n");
        return DPA_SAMPLER_ERR;
    }

    ret = bsp_dt_property_read_u32_array(dev, "dpa_core_pc_regs",
        (u32 *)&g_dpa_sampler_ctrl.dpa_core_pc_regs, g_dpa_sampler_ctrl.dpa_core_num);
    if (ret) {
        dpa_sampler_err("no dpa_core_pc_regs\n");
        return DPA_SAMPLER_ERR;
    }

    for (i = 0; i < g_dpa_sampler_ctrl.dpa_core_num; i++) {
        g_dpa_sampler_ctrl.dpa_core_pc_regs_virt[i] =
            ioremap((phys_addr_t)((uintptr_t)g_dpa_sampler_ctrl.dpa_core_pc_regs[i]), 0x1000);
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler_init(void)
{
    if (dpa_sampler_dtsi_init()) {
        return DPA_SAMPLER_ERR;
    }
    if (dpa_sampler_dmi_client_init()) {
        return DPA_SAMPLER_ERR;
    }
    if (dpa_sampler_task_init()) {
        return DPA_SAMPLER_ERR;
    }
    if (dpa_sampler_driver_init()) {
        return DPA_SAMPLER_ERR;
    }
    if (dpa_sampler_dump_init()) {
        return DPA_SAMPLER_ERR;
    }
    dpa_sampler_err("dpa_sampler init ok.\n");
    return DPA_SAMPLER_OK;
}
