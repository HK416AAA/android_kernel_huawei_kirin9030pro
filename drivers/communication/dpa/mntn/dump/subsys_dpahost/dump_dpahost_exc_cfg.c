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

#include <linux/types.h>
#include <dump_rdr_wrapper.h>
#include <dump_subsys_mgr.h>
#include <dump_modid.h>
#include "dump_dpahost_exc_cfg.h"

/* e_exce_type 在EXCH_SOURCE枚举中申明，需要AP和DPAHOST同时修改
 */
#define DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT \
            (DUMP_SUBSYS_DPA_EXC_NOTIFY_DEFAULT_MASK | DUMP_SUBSYS_MASK_AP)
#define DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_ADD_CP \
            (DUMP_SUBSYS_DPA_EXC_NOTIFY_DEFAULT_MASK | DUMP_SUBSYS_MASK_AP | DUMP_SUBSYS_MASK_CP)
__ro_after_init dump_exc_cfg_s g_dump_dpahost_exc_cfg[] = {
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_ADD_CP, DPA_S_HOST, DPA_QIC, DRV_ERRNO_AP_DETECT_DPA_QIC,
        DRV_ERRNO_AP_DETECT_DPA_QIC, RDR_ACPU_QIC_DPA_EXC_MODID, "DPA QIC DETECT BY AP"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_ADD_CP, DPA_S_HOST, DPA_QIC, DRV_ERRNO_DPA_QIC,
        DRV_ERRNO_DPA_QIC, RDR_DPA_HOST_DPA_QIC_MODID, "DPA QIC"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_ADD_CP, DPA_S_HOST, DPA_MDMPERI_QIC, DRV_ERRNO_MDMPERI_QIC,
        DRV_ERRNO_MDMPERI_QIC, RDR_DPA_HOST_MODEM_PERI_QIC_MODID, "MDMPERI QIC"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_ADD_CP, DPA_S_HOST, DPA_MDMPERI_QIC, DRV_ERRNO_MDMPERI_PDLOCK,
        DRV_ERRNO_MDMPERI_PDLOCK, RDR_DPA_HOST_MODEM_PERI_PDLOCK_MODID, "MDMPERI PDLOCK"
    },
// 防止user版本有人误用测试错误码，这里必须使用编译隔离
#ifdef CONFIG_DPA_FULL_DUMP
    // normalreset类型暂时使用CP_S_NORMALRESET，等在AP侧添加了DPA_NORMAL_RESET类型后，再修改这个
    {
        DUMP_SUBSYS_MASK_DPAFW, 0, CP_S_NORMALRESET, 0, DRV_ERRNO_DPA_RESET_TEST_NORMALRST,
        DRV_ERRNO_DPA_RESET_TEST_NORMALRST, RDR_DPA_HOST_RST_DPA_TEST_NORMALRESET, "DPA NORMALRST TEST"
    },
    {
        DUMP_SUBSYS_MASK_DPAFW, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_DRV, DRV_ERRNO_DPA_RESET_TEST,
        DRV_ERRNO_DPA_RESET_TEST, RDR_DPA_HOST_RST_DPA_TEST, "DPA RST TEST"
    },
#endif
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_RST_FAIL, DRV_ERRNO_RST_FAIL,
        DRV_ERRNO_RST_FAIL, RDR_DPA_DPA_RESET_FAIL_MODID, "DPA RST FAIL"
    },
    {
        DUMP_SUBSYS_MASK_DPAFW, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_DRV, DRV_ERRNO_PM_SR,
        DRV_ERRNO_PM_SR, RDR_DPA_HOST_RPM_MODID, "DPA RPM FAIL"
    },
    {
        DUMP_SUBSYS_MASK_DPAFW, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_DRV, DRV_ERRNO_DMI,
        DRV_ERRNO_DMI, RDR_DPA_HOST_DMI_MODID, "DPA DMI FAIL"
    },
    {
        DUMP_SUBSYS_MASK_DPAFW, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_DRV, DRV_ERRNO_DPA_FREQ,
        DRV_ERRNO_DPA_FREQ, RDR_DPA_HOST_DPA_FREQ_MODID, "DPA FREQ FAIL"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_DRV, DRV_ERRNO_START,
        DRV_ERRNO_BUTT, RDR_DPA_HOST_DRV_MODID, "DPAHOST DRV EXC"
    },
    // wlan默认都是单独复位
    {
        DUMP_SUBSYS_MASK_DPAFW, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_WLAN, WLAN_ERRNO_START,
        WLAN_ERRNO_BUTT, RDR_DPA_HOST_WLAN_MODID, "DPAHOST WLAN"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_STACK, NSTACK_ERRNO_START,
        NSTACK_ERRNO_BUTT, RDR_DPA_HOST_STACK_MODID, "DPAHOST STACK"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST_BOOSTER, BOOSTER_ERRNO_START,
        BOOSTER_ERRNO_BUTT, RDR_DPA_HOST_BOOSTER_MODID, "DPAHOST BOOSTER"
    },
    {
        DUMP_SUBSYS_MASK_AP, DUMP_DPAHOST_EXC_NOTIFY_SUBSYS_DEFAULT, DPA_S_HOST, DPA_HOST, DUMP_DPA_MOD_ID_START,
        DUMP_DPA_MOD_ID_END, RDR_DPA_HOST_MODID, "DPAHOST EXCEPTION"
    },
};

int dump_get_dpahost_exc_cfg(dump_subsys_exc_cfg_s *cfg)
{
    if (cfg == NULL) {
        return DUMP_ERRNO_INVA_PARAM;
    }
    cfg->num = ARRAY_SIZE(g_dump_dpahost_exc_cfg);
    cfg->cfg_list = (const dump_exc_cfg_s *)g_dump_dpahost_exc_cfg;
    return DUMP_OK;
}

/* 若某个异常需要子系统A复位，但是子系统A又不支持单独复位，那么就配置成整机复位 */
__init void dump_dpahost_subsys_update_exc_cfg(u64 reset_support_subsysmask)
{
    int i;
    for (i = 0; i < ARRAY_SIZE(g_dump_dpahost_exc_cfg); i++) {
        if (g_dump_dpahost_exc_cfg[i].reset_subsys_mask & (~reset_support_subsysmask)) {
            g_dump_dpahost_exc_cfg[i].reset_subsys_mask = DUMP_SUBSYS_MASK_AP;
        }
    }
}