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

#ifndef BSP_MODULE_INIT_H
#define BSP_MODULE_INIT_H

typedef int (*dpa_host_module_init_func)(void);

extern int dpa_rproc_init(void);
extern int bsp_dpa_nmi_init(void);
extern int bsp_slice_init(void);
extern int bsp_dpa_ipc_int(void);
extern int bsp_dpa_fipc_init(void);
extern int dpa_fipc_device_init(void);
extern int dpa_msg_crosscore_init(void);
extern int dpa_msg_init(void);
extern int bsp_fw_dt_init(void);

int booster_all_init(void);
extern int bsp_dpa_dump_init(void);
extern int dmi_client_init(void);

#ifdef CONFIG_DPA_DRA
extern int dra_dpa_init(void);
extern int dra_thread_init(void);
#endif
extern int dmi_client_device_init(void);
#ifdef CONFIG_DPA_MDM_RESET_AGENT
extern int bsp_sys_reset_init(void);
#endif
#ifdef CONFIG_DPA_RESET
extern int bsp_dpa_reset_pre_init(void);
extern int bsp_dpa_reset_init(void);
#endif
extern int syslog_output_init(void);
#ifdef CONFIG_DPA_WHITE_LIST
extern int white_list_init(void);
#endif

#ifdef CONFIG_DPA_SC_GID_CTRL
extern int gid_ctrl_dpa_init(void);
#endif

extern int bsp_memory_init(void);
extern int bsp_memory_layout_init(void);

int bsp_dpa_dump_resave_log(void);
int bsp_dpa_dump_mem_init(void);
int dpa_diag_init(void);

extern int dshell_init(void);
extern int dshell_logger_init(void);

extern int dpa_loader_load_modem_teeos_early_init(void);
extern int dpa_loader_load_modem_teeos_later_init(void);
extern int dpa_loader_loader_init(void);
extern int dpa_loader_dump_init(void);

#ifdef CONFIG_DPA_RFILE
extern int dpa_rfile_init(void);
#endif

#ifdef CONFIG_MDMPERI_QIC
extern int bsp_buserr_init(void);
#endif

extern int bsp_dpa_wdt_init(void);
extern int syslog_dmi_switch_init(void);
extern int syslog_user_dev_init(void);
#ifdef CONFIG_DPA_NSTACK
s32 bridge_module_init(void);
#endif
#ifdef CONFIG_DPA_TC
extern int dpa_tc_init(void);
extern int tc_wifishare_statistics_init(void);
#endif
int udx_agent_init(void);
int dpa_rproc_add(void);

#ifdef CONFIG_DPA_SMS
extern int bsp_sms_init(void);
#endif
#ifdef CONFIG_DPA_PROTO_OM
int dpa_stack_om_init(void);
#endif
int dpa_freq_init(void);

#ifdef CONFIG_DPA_CHR
int dpa_chr_init(void);
#endif

#ifdef CONFIG_DPA_DFA
int dfa_alloc_cma_init(void);
#endif

#ifdef CONFIG_DPA_BOOSTER
int booster_all_init(void);
#endif

extern int net_om_dpa_report_init(void);
#ifdef CONFIG_UDX_BUFFER
int udx_heap_init(void);
#endif

#ifdef CONFIG_DPA_SAMPLER
extern int dpa_sampler_init(void);
#endif

#ifdef CONFIG_UDX_SERVER
int udx_init(void);
#endif
#ifdef CONFIG_UDX_DFS
int udx_dfs_init(void);
#endif
#ifdef CONFIG_UDX_DSS
int udx_dss_init(void);
#endif

/*
 * @brief dpa host初始化函数列表，不依赖dpa启动
 */
static dpa_host_module_init_func g_dpa_module_init_step1[] = {
   /* 融合架构平台依赖memory layout的模块初始化需要放在
    dpa_loader_load_modem_teeos_early_init与dpa_loader_load_modem_teeos_later_init之间
    */
    dpa_loader_load_modem_teeos_early_init,
    dpa_loader_loader_init,
    bsp_fw_dt_init,
    dpa_loader_load_modem_teeos_later_init,

    dpa_rproc_init,
    bsp_slice_init,
#ifdef CONFIG_DPA_RESET
    bsp_dpa_reset_pre_init,
#endif
    bsp_memory_init,
    bsp_memory_layout_init,
    bsp_dpa_dump_mem_init,
    dpa_loader_dump_init,
    bsp_dpa_ipc_int,
    bsp_dpa_dump_init,
    bsp_dpa_fipc_init,
    dpa_msg_crosscore_init,
    bsp_dpa_nmi_init,
    dmi_client_device_init,
#ifdef CONFIG_DPA_RESET
    bsp_dpa_reset_init,
#endif
    syslog_output_init,
#ifdef CONFIG_DPA_MDM_RESET_AGENT
    bsp_sys_reset_init,
#endif
#ifdef CONFIG_DPA_WHITE_LIST
    white_list_init,
#endif
    dshell_init,
    dshell_logger_init,
#ifdef CONFIG_DPA_SC_GID_CTRL
    gid_ctrl_dpa_init,
#endif
#ifdef CONFIG_DPA_DRA
    dra_dpa_init,
#endif
#ifdef CONFIG_DPA_TC
    dpa_tc_init,
#endif
    dpa_rproc_add,
    dpa_freq_init,
#ifdef CONFIG_UDX_SERVER
    udx_init,
#endif
#ifdef CONFIG_UDX_BUFFER
    udx_heap_init,
#endif
#ifdef CONFIG_UDX_HTTP
    udx_agent_init,
#endif
#ifdef CONFIG_DPA_NET_OM
    net_om_dpa_report_init,
#endif
#ifdef CONFIG_DPA_SAMPLER
    dpa_sampler_init,
#endif
};

/*
 * @brief dpa host初始化函数列表，dpa解复位后执行
 */
static dpa_host_module_init_func g_dpa_module_init_step2[] = {
#ifdef CONFIG_MDMPERI_QIC
    bsp_buserr_init,
#endif
#ifdef CONFIG_DPA_DRA
    dra_thread_init,
#endif
    bsp_dpa_wdt_init,

    dpa_fipc_device_init,
    dpa_msg_init,
    dmi_client_init,
    dpa_diag_init,
};

/*
 * @brief dpa host初始化函数列表，dpa fw module_init执行完成并且g_dpa_module_init_step2执行完成
 * 业务组件初始化放该阶段
 */
static dpa_host_module_init_func g_dpa_module_init_step3[] = {
#ifdef CONFIG_DPA_RFILE
    dpa_rfile_init,
#endif
    syslog_dmi_switch_init,
    syslog_user_dev_init,
#ifdef CONFIG_DPA_NSTACK
    bridge_module_init,
#endif

#ifdef CONFIG_DPA_SMS
    bsp_sms_init,
#endif
#ifdef CONFIG_UDX_DFS
    udx_dfs_init,
#endif
#ifdef CONFIG_UDX_DSS
    udx_dss_init,
#endif

#ifdef CONFIG_DPA_PROTO_OM
    dpa_stack_om_init,
#endif

#ifdef CONFIG_DPA_TC
    tc_wifishare_statistics_init,
#endif

#ifdef CONFIG_DPA_CHR
    dpa_chr_init,
#endif

#ifdef CONFIG_DPA_DFA
    dfa_alloc_cma_init,
#endif

#ifdef CONFIG_DPA_BOOSTER
    booster_all_init,
#endif
};

#endif
