/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/time.h>
#include <linux/rtc.h>
#include "dpu_mntn.h"
#include "dpu_comp_mgr.h"
#include "dkmd_log.h"
#include "cmdlist_interface.h"
#include <regulator_mdfx_mntn.h>
#include "dpu_dacc_log_read.h"

#ifdef CONFIG_DDR_DDRC_STAT
#include "ddr_stat.h"
#define DDR_STAT_BUF_SIZE 4096
#endif // CONFIG_DDR_DDRC_STAT

#define FILE_PREFIX_LEN 256
#define DPU_MNTN_DUMP_REG_OFFSET (16)
#define DUMP_BUF_SIZE 8192

static int clk_mdfx_notifier_call(struct notifier_block *self, unsigned long action, void *data)
{
	if (!self || !data) {
		dpu_pr_warn("clk_mdfx_notifier_call self or data is null");
		return -1;
	}
    
    return media_regs_dump();
} // register
 
static struct notifier_block clk_mdfx_notifier = {
    .notifier_call = clk_mdfx_notifier_call,
    .priority = 0,
};

static bool dkmd_mntn_write_to_file(struct file *file, int32_t size, char *buf, uint32_t *write_len)
{
    if (size < 0) {
        mdfx_file_write(file, buf, *write_len);
        *write_len = 0;
        return true;
    }

    *write_len += (uint32_t)size;
    if (*write_len >= DUMP_BUF_SIZE) {
        mdfx_file_write(file, buf, DUMP_BUF_SIZE);
        *write_len = 0;
    }
    return false;
}

static uint32_t dkmd_mntn_format_module_reg(struct file *file, struct dpu_mntn_reg_module *module,
    char __iomem *dpu_base, char *buf, uint32_t count)
{
    uint32_t j;
    uint32_t len = count;
    int32_t size = 0;
    struct rtc_time tm = {0};
    struct timespec64 tv = {0};

    ktime_get_real_ts64(&tv);
    tv.tv_sec -= (long)sys_tz.tz_minuteswest * 60;
    rtc_time64_to_tm(tv.tv_sec, &tm);

    do {
        size = snprintf_s(buf + len, DUMP_BUF_SIZE - len,
                DUMP_BUF_SIZE - len - 1, "--------------- %s --- %.4d-%.2d-%.2d %.2d:%.2d:%.2d.%03d -\n",
                module->module_name, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                tm.tm_hour, tm.tm_min, tm.tm_sec, tv.tv_nsec / 1000000);
    } while (dkmd_mntn_write_to_file(file, size, buf, &len));

    for (j = 0; j < module->reg_count; j++) {
        if (j % 4 == 0) {
            if ((j / 4) > 0) {
                do {
                    size = snprintf_s(buf + len, DUMP_BUF_SIZE - len,
                                      1, "\n");
                } while (dkmd_mntn_write_to_file(file, size, buf, &len));
            }

            do {
                size = snprintf_s(buf + len, DUMP_BUF_SIZE - len,
                                  DUMP_BUF_SIZE - len - 1, "0x%05x: ",
                                  module->reg_offset + (j / 4) * DPU_MNTN_DUMP_REG_OFFSET);
            } while (dkmd_mntn_write_to_file(file, size, buf, &len));
        }

        do {
            size = snprintf_s(buf + len, DUMP_BUF_SIZE - len,
                              DUMP_BUF_SIZE - len - 1, "%8x ",
                              inp32(dpu_base + module->reg_offset + j * 4));
        } while (dkmd_mntn_write_to_file(file, size, buf, &len));
    }
    // add a line break at the end of the module
    do {
        size = snprintf_s(buf + len, DUMP_BUF_SIZE - len, 1 , "\n");
    } while (dkmd_mntn_write_to_file(file, size, buf, &len));

    return len;
}

static void dkmd_mntn_dump_cmdlist_reg(struct composer_manager *comp_mgr, struct dpu_mntn_dump_ctrl *ctrl, char *buf, char *event_name, char *timestamp)
{
    char file_prefix[FILE_PREFIX_LEN] = {0};
    struct dpu_mntn_reg_module *module = NULL;
    struct file *file = NULL;
    mm_segment_t old_fs;
    int size;
    size_t len = 0;
    uint32_t i;
    uint32_t module_count = 0;

    size = scnprintf(file_prefix, FILE_PREFIX_LEN, "_%s_dpu_reg_scene_id_%u_FrameIdx_%u.txt", 
        event_name, ctrl->frames[0].scene_id, ctrl->frames[0].frame_index);
    if (size <= 0) {
        dpu_pr_warn("create dump file name fail size %d", size);
        return;
    }

    old_fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

    file = mdfx_file_create_file(DFX_DUMPER_DIR, timestamp, file_prefix);
    if (file == NULL) {
        dpu_pr_warn("create dump %s %s fail", DFX_DUMPER_DIR, file_prefix);
        set_fs(old_fs);
        return;
    }

    module_count = sizeof(g_dss_addr_dump_info) / sizeof(g_dss_addr_dump_info[0]);

    for (i = 0; i < module_count; i++) {
        module = &ctrl->modules[i];
        if (module->reg_count == 0)
            continue;

        len = dkmd_mntn_format_module_reg(file, module, comp_mgr->dpu_base, buf, len);
    }
    if (len >= DUMP_BUF_SIZE)
        len = DUMP_BUF_SIZE;

    mdfx_file_write(file, buf, len);

	filp_close(file, NULL);
    set_fs(old_fs);
}

static void dkmd_mntn_dump_cmdlist_dm(struct composer_manager *comp_mgr, struct dpu_mntn_dump_ctrl *ctrl, char *buf, char *event_name, char *timestamp)
{
    char file_prefix[FILE_PREFIX_LEN] = {0};
    struct dpu_cmdlist_frame_info *frame = NULL;
    struct file* file = NULL;
    mm_segment_t old_fs;
    uint32_t i;
    int size;

    if (!ukmd_cmdlist_is_kernel_mode(CMDLIST_DEV_ID_DPU)) {
		return;
	}

    old_fs = get_fs();
    set_fs(KERNEL_DS); //lint !e501

    for (i = 0; i < ARRAY_SIZE(ctrl->frames); i++) {
        frame = &ctrl->frames[i];
        size = scnprintf(file_prefix, FILE_PREFIX_LEN, "_%s_scene_id_%u_cmdlist_id_%llu_frame_index_%u.txt", 
                              event_name, frame->scene_id, frame->cmdlist_id, frame->frame_index);
        if (size <= 0) {
            dpu_pr_warn("create dump file name fail size %d", size);
            continue;
        }

        file = mdfx_file_create_file(DFX_DUMPER_DIR, timestamp, file_prefix);
        if (file == NULL) {
            dpu_pr_info("create dump %s %s fail", DFX_DUMPER_DIR, file_prefix);
            continue;
        }

        mdfx_cmdlist_dump_dm(frame->scene_id, frame->cmdlist_id, file, buf, DUMP_BUF_SIZE);

        filp_close(file, NULL);
    }

    set_fs(old_fs);
}

static void dkmd_mntn_dump_cmdlist(void *data, void *value, char *event_name, char *timestamp)
{
    struct composer_manager *comp_mgr = (struct composer_manager *)data;
    struct dpu_mntn_dump_ctrl *ctrl = (struct dpu_mntn_dump_ctrl *)value;
    char *buf = NULL;

    if (IS_ERR_OR_NULL(comp_mgr) || IS_ERR_OR_NULL(ctrl) || IS_ERR_OR_NULL(event_name) || IS_ERR_OR_NULL(timestamp)) {
        dpu_pr_err("comp_mgr or ctrl is null");
        return;
    }

    dpu_pr_info("dump cmdlist start +");

    buf = kzalloc(DUMP_BUF_SIZE, GFP_KERNEL);
    if (unlikely(!buf)){
        dpu_pr_err("kzalloc fail");
        return;
    }    

    dkmd_mntn_dump_cmdlist_reg(comp_mgr, ctrl, buf, event_name, timestamp);
    dkmd_mntn_dump_cmdlist_dm(comp_mgr, ctrl, buf, event_name, timestamp);

    kfree(buf);
}

#ifdef CONFIG_DDR_DDRC_STAT
void dkmd_mntn_dump_ddr_info(char *event_name, char *timestamp)
{
    struct file *file = NULL;
    unsigned char *buffer = NULL; 
    int length = 0;
    int ret = 0;
    mm_segment_t old_fs;
    char file_prefix[FILE_PREFIX_LEN] = {0};

    ret = scnprintf(file_prefix, FILE_PREFIX_LEN, "_%s_log_mdfx_ddr_stat.txt", event_name);
    if (ret <= 0) {
        dpu_pr_warn("create ddr dump file name fail ret=%d", ret);
        return;
    }

    buffer = kzalloc(DDR_STAT_BUF_SIZE, GFP_KERNEL);
    if (!buffer) {
        dpu_pr_err("kzalloc size failed!\n");
        return;
    }
 
    length = ddr_stat_record_for_dss(buffer, DDR_STAT_BUF_SIZE);
    if (length < 0) {
        dpu_pr_err("ddr stat record for dss fail");
        kfree(buffer);
        return;
    }
    dpu_pr_debug("ddr_stat_record_for_dss length = %d", length);

    old_fs = get_fs();
    set_fs(KERNEL_DS); //lint !e501

    file = mdfx_file_create_file(DFX_DDR_DIR, timestamp, file_prefix);
	if (file == NULL) {
		dpu_pr_warn("create dump %s%s fail", DFX_DDR_DIR, file_prefix);
        set_fs(old_fs);
        kfree(buffer);
        return;
	}

    mdfx_file_write(file, buffer, length);
 
    kfree(buffer);

    filp_close(file, NULL);
    set_fs(old_fs); //lint !e501

    mdfx_remove_redundant_files(DFX_DDR_DIR);
}
#endif // CONFIG_DDR_DDRC_STAT

static void dkmd_mntn_mdfx_callback(visitor_cb_param_t *param)
{
    if (IS_ERR_OR_NULL(param))
        return;

    dpu_pr_info("dpu mdfx callback actions=0x%llx, id=0x%llx, g_dkmd_mdfx_id=0x%llx", param->actions, param->id, g_dkmd_mdfx_id);
    if (param->id != g_dkmd_mdfx_id)
        return;

    if (IS_ENABLE_BITS_FIELD(param->actions, NOTIFY_DETAIL_DUMP_CMDLIST))
        dkmd_mntn_dump_cmdlist(param->data, param->value, param->even_name, param->timestamp);

#ifdef CONFIG_DDR_DDRC_STAT
    if (IS_ENABLE_BITS_FIELD(param->actions, NOTIFY_DETAIL_DDR_INFO))
        dkmd_mntn_dump_ddr_info(param->even_name, param->timestamp);
#endif

    if (IS_ENABLE_BITS_FIELD(param->actions, DUMP_DETAIL_DACC_LOG))
        dpu_exception_dacc_log_dump();
}

void dkmd_create_mdfx_client(void *data)
{
	if (g_dkmd_mdfx_id < 0)
		g_dkmd_mdfx_id = mdfx_create_visitor(VISITOR_GRAPHIC_HDM, dkmd_mntn_mdfx_callback, data);
    
    if (g_dkmd_mdfx_id > 0) {
		mdfx_register_client(&clk_mdfx_notifier, VISITOR_GRAPHIC_HDM);
	}
}

void dkmd_destroy_mdfx_client(void)
{
	if (g_dkmd_mdfx_id > 0) {
        mdfx_unregister_client(&clk_mdfx_notifier, VISITOR_GRAPHIC_HDM);
		mdfx_destroy_visitor(g_dkmd_mdfx_id);
		g_dkmd_mdfx_id = -1;
	}
}

void dpu_mntn_report_event(uint32_t event_type, const struct comp_online_present *present)
{
    struct dpu_mntn_dump_ctrl mntn_dump_ctrl;
    const struct disp_frame *preFrame = NULL;
    const struct disp_frame *currentFrame = NULL;

    if (unlikely(!present))
		return;

    preFrame = &present->frames[present->displayed_idx].in_frame;
    currentFrame = &present->frames[present->displaying_idx].in_frame;

    dpu_pr_info("event_type=%u preFrame-currentFrame frame_index=%u, scene_id=%d, cmdlist_id=%llu, frame_index=%u, scene_id=%d, cmdlist_id=%llu", event_type, 
        preFrame->frame_index, preFrame->scene_id, preFrame->cmdlist_id, currentFrame->frame_index, currentFrame->scene_id, currentFrame->cmdlist_id);

    mntn_dump_ctrl.frames[0].scene_id = currentFrame->scene_id;
    mntn_dump_ctrl.frames[0].cmdlist_id = currentFrame->cmdlist_id;
    mntn_dump_ctrl.frames[0].frame_index = currentFrame->frame_index;
    mntn_dump_ctrl.frames[1].scene_id = preFrame->scene_id;
    mntn_dump_ctrl.frames[1].cmdlist_id = preFrame->cmdlist_id;
    mntn_dump_ctrl.frames[1].frame_index = preFrame->frame_index;
    mntn_dump_ctrl.modules = g_dss_addr_dump_info;
    mdfx_report_default_event(g_dkmd_mdfx_id, event_type, currentFrame->frame_index, &mntn_dump_ctrl);
}
