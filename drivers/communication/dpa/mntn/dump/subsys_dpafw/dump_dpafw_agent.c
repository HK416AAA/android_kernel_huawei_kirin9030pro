/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
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

#include <securec.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <bsp_slice.h>
#include <bsp_wdt.h>
#include <dpa_reset.h>
#include <bsp_dpa_ipc.h>
#include <bsp_om_enum.h>
#include <bsp_dump.h>
#include <bsp_coresight.h>
#include <dump_rdr_wrapper.h>
#include <dump_infra.h>
#include <dump_frame.h>
#include <dump_errno.h>
#include <dump_subsys_mgr.h>
#include <dump_area.h>
#include "dump_dpafw_exc_cfg.h"
#include "dump_dpafw_log.h"
#include "dump_dpafw_agent.h"

int dump_dpafw_prepare_handler(const dump_exc_log_desc_s *exc_desc);
int dump_dpafw_event_handler(int event, const dump_exc_log_desc_s *exc_desc);

dump_dpafw_agent_ctrl_s g_dump_dpafw_agent;
__ro_after_init dump_subsys_drv_s g_dump_dpafw_subsys = {
    .dump_sys = DUMP_SUBSYS_DPAFW,
    .name = "DPAFW",
    /* g_dump_dpafw_exc_cfg 数组较大，在另一个文件中声名；也方便后续版本有差异时，拆分到hal层
    .exc_cfg = {
        .num = ARRAY_SIZE(g_dump_dpafw_exc_cfg),
        .cfg_list = &g_dump_dpafw_exc_cfg,
    },
    */
    .work_ctrl = &g_dump_dpafw_agent.work_ctrl,
    .dump_prepare_handler = dump_dpafw_prepare_handler,
    .reset_ops = NULL, /* 支持单独复位时才挂接 */
    .event_handler = dump_dpafw_event_handler,
};

int dump_fill_dpafw_exc_info(dump_base_info_s *base_info, dump_subsys_exc_info_s *subsys_exc)
{
    int ret = DUMP_OK;
    int len;
    
    subsys_exc->e_from_subsys = DUMP_SUBSYS_DPAFW;
    subsys_exc->data = NULL;
    subsys_exc->length = 0;

    if (base_info != NULL) {
        subsys_exc->modid = base_info->mod_id;
        subsys_exc->arg1 = base_info->arg1;
        subsys_exc->arg2 = base_info->arg2;
        subsys_exc->reboot_context = base_info->reboot_context;
        subsys_exc->reason = (base_info->mod_id != DRV_ERRNO_DUMP_PROCESSOR_EXC) ? DUMP_REASON_NORMAL : DUMP_REASON_PROCESSOR;
        if (subsys_exc->reboot_context == DUMP_CTX_INT) {
            subsys_exc->int_no = base_info->reboot_int;
            (void)memset_s(subsys_exc->task_name, DUMP_EXCINFO_TASKNAME_LEN, 0, DUMP_EXCINFO_TASKNAME_LEN);
        } else {
            subsys_exc->task_id = base_info->reboot_task;
            len = sizeof(base_info->task_name);
            len = (len >= DUMP_EXCINFO_TASKNAME_LEN) ? DUMP_EXCINFO_TASKNAME_LEN : len;
            if (memcpy_s(subsys_exc->task_name, DUMP_EXCINFO_TASKNAME_LEN, base_info->task_name, len) != EOK) {
                ret = DUMP_ERRNO_MEM_OPS;
            }
            subsys_exc->task_name[DUMP_EXCINFO_TASKNAME_LEN - 1] = '\0';
        }
    } else {
        subsys_exc->modid = 0;
        subsys_exc->arg1 = 0;
        subsys_exc->arg2 = 0;
        subsys_exc->reboot_context = DUMP_CTX_INT;
        subsys_exc->reason = DUMP_REASON_NORMAL;
        subsys_exc->int_no = 0xFFFFFFFF;
        (void)memset_s(subsys_exc->task_name, DUMP_EXCINFO_TASKNAME_LEN, 0, DUMP_EXCINFO_TASKNAME_LEN);
        ret = DUMP_ERRNO_GET_BASEINFO;
    }
    return ret;
}

/*******************************DPA狗超时复位事件接收&上报 ***************************/
void dump_dpafw_wdt_hook(unsigned int mod_id, unsigned int core_id)
{
    int rpt_ret;
    u32 timestamp = bsp_get_slice_value();
    dump_base_info_s *baseinfo = NULL;
    dump_subsys_exc_info_s subsys_exc;
    baseinfo = dump_save_dpafw_base_info_wdt(mod_id, core_id);
    /* 应该在baseinfo准备好之后，立刻通知DPA(因为baseinfo中保存了一些核间交互的信息，所以一定要等他完成) */
    dump_dpafw_async_exc_proc(mod_id);
    dump_fill_dpafw_exc_info(baseinfo, &subsys_exc);
    rpt_ret = (int)dump_report_exception(&subsys_exc);
    if (!dump_is_exc_rpt_accept(rpt_ret)) {
        dump_error("reject handle dpa exc by %d\n", rpt_ret);
        return;
    }
    dump_print("[0x%x]dpa wdt enter system error! \n", timestamp);

    bsp_dpa_ocd_stop();
    /* 如果当前不是第一现场，不需要执行后面的步骤 */
    if (rpt_ret != DUMP_EXC_ACCEPT_NOW) {
        return;
    }
}

__init void dump_dpafw_wdt_init(void)
{
    int ret = DUMP_OK;
    ret = bsp_dpa_wdt_register_hook(WDT_DPACORE_ID, dump_dpafw_wdt_hook);
    if (ret != DUMP_OK) {
        dump_error("fail to register wdt hook\n");
    }
}

/******************************* DPA主动复位事件接收&上报 ***************************/
int dump_dpafw_ipc_handler(void *arg)
{
    int ret, rpt_ret;
    dump_subsys_exc_info_s subsys_exc;
    dump_base_info_s *base_info = (dump_base_info_s *)bsp_dpa_dump_get_field_addr(OM_DPAFW_BASE_INFO);
    u32 timestamp = bsp_get_slice_value();

    /* 不论本次异常是否被rdr接纳，都将dpa_exc_flag置true，并关狗
     * 上报异常被拒绝的情况：1、当前正在dpa 单独复位，2、或者已经有整机复位的异常了
     * 如果是case 1，
     *   1.1 发生在单独复位前，此时异常不需要处理，这里置位的标记，关闭的wdt；会在单独复位时重新打开
     *   1.2 发生在单独复位中，此时异常需要处理，但是当前机制是交由单独复位失败处理，而不是此时上报；关闭的wdt不影响功能
     * 如果是case 2，该异常不需要处理，关闭wdt也不影响功能
     */
    g_dump_dpafw_agent.dpa_exc_flag = true; 
    bsp_dpa_wdt_disable();

    ret = dump_fill_dpafw_exc_info(base_info, &subsys_exc); 

    rpt_ret = (int)dump_report_exception(&subsys_exc);
    if (!dump_is_exc_rpt_accept(rpt_ret)) {
        dump_error("reject handle dpafw exc by %d\n", rpt_ret);
        return 0;
    }

    if (ret != DUMP_OK) {
        dump_print("get dpafw exc info fail ret %d\n", ret);
    }
    dump_print("dpafw enter system error! timestamp:0x%x\n", timestamp);
    /* 如果当前不是第一现场，不需要执行后面的步骤 */
    if (ret != DUMP_EXC_ACCEPT_NOW) {
        return 0;
    }

    return 0;
}

__init int dump_dpafw_ipc_init(void)
{
    int ret;

    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_DUMP, (dpa_ipc_cbk)dump_dpafw_ipc_handler, NULL);
    if (ret != DUMP_OK) {
        dump_print("conn dpa ipc fail\n");
        return DUMP_ERRNO_IPC_CONNECT;
    }
    return DUMP_OK;
}

/******************************* pre-dump：通知DPA ***************************/
void dump_notify_dpa(u32 mod_id)
{
    int ret;
    
    ret = bsp_dpa_ipc_send(DPA_IPC_DPA_INT_SRC_ACPU_DUMP);
    if (ret == DUMP_OK) {
        dump_print("notify dpa fw success\n");
    } else {
        dump_error("notify dpa fw fail,please let ipc check\n");
    }
}

void dump_dpafw_async_exc_proc(u32 mod_id)
{
    /* mark dpa_exc_flag, so will not notify dpa(proc in func dump_dpafw_notify_callback) later in rdr callback */
    if (!g_dump_dpafw_agent.dpa_exc_flag) {
        g_dump_dpafw_agent.dpa_exc_flag = true;
        dump_notify_dpa(mod_id);
        dump_error("dpa exc catch by ap!\n");
    }
}

int dump_dpafw_prepare_handler(const dump_exc_log_desc_s *exc_desc)
{
    u32 modid = 0;
    /* 不应该走到 */
    if (!dump_valid_exc_desc(exc_desc)) {
        dump_debug("exc_desc inv\n");
    } else {
        modid = exc_desc->exc_info->subsys_info.modid;
    }

    if (g_dump_dpafw_agent.dpa_exc_flag == true) {
        dump_print("DPA exception,no need to notify dpa core,modid=0x%x\n", modid);
        return DUMP_OK;
    }
    if (bsp_reset_dpa_is_reboot() != 0) {
        dump_print("dpa is reseting now,do not notify\n");
        dump_set_save_done(DUMP_SUBSYS_DPAFW);
        return DUMP_OK;
    }
    dump_notify_dpa(modid);
    return DUMP_OK;
}

/******************************* 复位DPA ***************************/
void dump_dpafw_area_reset(dump_area_id_e areaid)
{
    int ret;
    struct dump_area_mntn_addr_info_s area_info = { 0 };
    struct dump_area_s *area;
    ret = bsp_dpa_dump_get_area_info(areaid, &area_info);
    if (ret == DUMP_OK && area_info.vaddr != NULL && area_info.paddr != NULL && area_info.len != 0) {
         area = (struct dump_area_s *)area_info.vaddr;
         area->area_head.magic_num = DUMP_LEVEL1_AREA_EXPIRED_MAGICNUM;
         area->area_head.share_info.done_flag = 0;
         dump_print("area[%d] reset done\n", areaid);
    }
    dump_clear_aslrinfo();
}

dump_reset_result_e dump_dpa_reset_proc(u32 modid)
{
    int ret;
    dump_print("enter dump reset, mod id:0x%x\n", modid);
    ret = bsp_dpa_reset();
    if (ret != DPA_RESET_SUCCESS) {
        dump_error("dpa reset fail!\n");
        return DUMP_RESET_NOT_SUCCESS;
    }
    return DUMP_RESET_SUCCESS;
}

dump_reset_result_e dump_dpafw_reset_handler(const dump_exc_log_desc_s *exc_desc)
{
    int ret;
    u32 modid = 0xFFFFFFFF;

    if ((exc_desc != NULL) && (exc_desc->exc_info != NULL)) {
        modid = exc_desc->exc_info->rdr_info.modid;
    }

    ret = dump_dpa_reset_proc(modid);
    return (dump_reset_result_e)ret;
}

void dump_clear_dpafw_area_head(void)
{
    // 复用单独复位代码,将DPAFW的维测内存头置位invalid
    dump_dpafw_area_reset(DUMP_AREA_DPAFW);
}

int dump_dpafw_reset_before_cb(const dump_exc_log_desc_s *exc_desc)
{
    if (dump_valid_exc_desc(exc_desc)) {
        /* 单独复位前重置DPA area，防止后续单独复位失败且DPA在启动早期异常，dump未初始化时，AP获取到残留的DPA信息，
        * 例如DPAlog是否保存完成，一些DPA_FIELD里用作交互的信息 */
        if (exc_desc->exc_info->exc_cfg->reset_subsys_mask & DUMP_SUBSYS_MASK_DPAFW) {
            dump_clear_dpafw_area_head();
            /* 如果要进行DPA reset；那本次的dpa_exc_flag要清理掉 */
            g_dump_dpafw_agent.dpa_exc_flag = false;
            dump_print("dpa_exc_flag clear!\n");
        }
    } else {
        /* 不应该走到这，但如果走到了，不知道当前是什么异常的情况下，都把DPA的exc_flag清掉，这样后面再有dpa异常的时候，也能通知到DPA
         * 但是这里不能重置DPA_AREA的valid标记，因为这里如果不是DPA异常了，清理掉了的话，后续的DPA异常，无法保存很多日志
         */
        if (g_dump_dpafw_agent.dpa_exc_flag) {
            g_dump_dpafw_agent.dpa_exc_flag = false;
            dump_print("dpa_exc_flag clear!\n");
        }
    }
    return DUMP_OK;
}

/******************************* dump_event：dump事件处理 ***************************/
int dump_dpafw_event_handler(int event, const dump_exc_log_desc_s *exc_desc)
{
    int ret = DUMP_OK;
    switch (event) {
        case DUMP_EVENT_RESET_START:
            ret = dump_dpafw_reset_before_cb(exc_desc);
            break;
        default:
            break;
    }
    return ret;
}

/* 允许多次调用 */
void dump_dpafw_subsys_drv_prepare(void)
{
    int ret;
    /* 使用默认workqueue和async work fn；work ctrl需要先初始化，后面注册work时会用到 */
    ret = dump_work_ctrl_factory(&g_dump_dpafw_agent.work_ctrl, NULL, NULL);
    if (ret != DUMP_OK) {
        dump_print("dpafw work ctrl init fail\n");
    }

    dump_get_dpafw_exc_cfg(&g_dump_dpafw_subsys.exc_cfg);
    dump_register_subsys(&g_dump_dpafw_subsys);
}

__init void dump_dpafw_subsys_init(void)
{
    int ret;

    if (bsp_dpa_reset_is_feature_on() == DPA_RESET_SUPPORT) {
        g_dump_dpafw_subsys.reset_ops = dump_dpafw_reset_handler;
    }

    ret = dump_dpafw_ipc_init();
    if (ret != DUMP_OK) {
        dump_print("reg dpa ipc fail\n");
    }
    dump_dpafw_wdt_init();

    dump_dpafw_log_init();

    // 初始化时，先将dump维测内存头清掉，防止dpa没启动时，导出来了的log里，自动解析出上次重启的dpa_log导致误导
    dump_clear_dpafw_area_head();

    g_dump_dpafw_agent.init_done = true;
    dump_print("dump dpa init ok\n");
}