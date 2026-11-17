/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#include <linux/delay.h>
#include <linux/io.h>
#include <bsp_dt.h>
#include <bsp_nmi.h>
#include <bsp_slice.h>
#include <bsp_mem_layout.h>
#include <bsp_print.h>
#include <securec.h>


#undef THIS_MODU
#define THIS_MODU mod_nmi

#define DPA_CORE_NUM 4
#define DPA_DSS_NUM 2
#define DPA_NMI_MAX 8  // MAX interrupt sources per thread
#define DPA_CORE_NUM_PER_REG (32 / DPA_NMI_MAX)
#define DPA_NMI_CHECK_TIME 2000U
#define DPA_NMI_DISABLE_VAL 0xFFFFFFFF

#define nmi_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define NMI_ERROR (-1)
#define NMI_OK 0

struct dpa_nmi_ctrl {
    unsigned int  nmi_init;
    unsigned int  phy_core_mask;
    unsigned int  logic_core_mask;
    unsigned int  recv_count[DPA_NMI_MAX];
    unsigned int  send_count[DPA_NMI_MAX];
    void *base_sysctrl;
    unsigned int  nmi_sysctrl[DPA_DSS_NUM][3];  // en, dis, status
};
struct dpa_nmi_ctrl g_dpa_nmi_ctrl;
#define IS_DPA_NMI_SYS_VALID(reg_id, idx) (g_dpa_nmi_ctrl.nmi_sysctrl[reg_id][idx] > 0)

int check_dpa_nmi_status(dpa_nmi_num nmi_id)
{
    unsigned int  reg_id;
    unsigned int  nmi_status[DPA_DSS_NUM] = { 0, 0 };
    unsigned int  res = 0;
    unsigned int  slice = bsp_get_slice_value(); // has triggered nmi a moment ago.
    udelay(DPA_NMI_CHECK_TIME);

    for (reg_id = 0; reg_id < DPA_DSS_NUM; reg_id++) {
        if (IS_DPA_NMI_SYS_VALID(reg_id, 2)) {
            nmi_status[reg_id] = readl((void *)(g_dpa_nmi_ctrl.base_sysctrl + g_dpa_nmi_ctrl.nmi_sysctrl[reg_id][0x2]));
            res += nmi_status[reg_id];
        }
        if (nmi_status[reg_id] != 0) {
            nmi_err("[dpa_nmi]id %d, dss_id: %u, send_cnt[%u], recv_cnt[%u], error, status:0x%x\n", nmi_id, reg_id,
                g_dpa_nmi_ctrl.send_count[nmi_id], g_dpa_nmi_ctrl.recv_count[nmi_id], nmi_status[reg_id]);
        }
    }
    if (res) {
        nmi_err("[dpa_nmi]recv fail, trigger slice: 0x%x\n", slice);
        return NMI_ERROR;
    }
    g_dpa_nmi_ctrl.recv_count[nmi_id]++;
    nmi_err("[dpa_nmi]id%d, send_cnt[%u], recv_cnt[%u], OK, trigger slice: 0x%x\n", nmi_id, g_dpa_nmi_ctrl.send_count[nmi_id],
                g_dpa_nmi_ctrl.recv_count[nmi_id], slice);

    return NMI_OK;
}

int bsp_dpa_nmi_trigger(unsigned int  core_mask, dpa_nmi_num nmi_id)
{
    unsigned int  reg_id = 0;
    unsigned int  reg_core_id = 0;
    unsigned int  core_id = 0;
    unsigned int  tmp = 0;
    unsigned int  phy_mask = g_dpa_nmi_ctrl.phy_core_mask;
    unsigned int phy_core_id = 0;
    unsigned int  trigger_value[DPA_DSS_NUM] = { 0, 0 };

    if (!g_dpa_nmi_ctrl.nmi_init) {
        nmi_err("[dpa_nmi]nmi init fail\n");
        return NMI_ERROR;
    }

    if (nmi_id >= DPA_NMI_MAX) {
        nmi_err("[dpa_nmi]nmi nmi_id %d error\n", nmi_id);
        return NMI_ERROR;
    }

    if ((core_mask & g_dpa_nmi_ctrl.logic_core_mask) != core_mask) {
        nmi_err("[dpa_nmi]nmi logici core_mask 0x%x error\n", core_mask);
        return NMI_ERROR;
    }
    g_dpa_nmi_ctrl.send_count[nmi_id]++;
    for (core_id = 0; core_id < DPA_CORE_NUM; core_id++) {
        tmp = ((unsigned int )0x1 << (unsigned int )core_id);
        if (tmp & core_mask) {
            while ((phy_mask & 0x1) == 0) {
                phy_core_id++;
                phy_mask >>= 0x1;
            }
            reg_core_id = (unsigned int )(phy_core_id % DPA_CORE_NUM_PER_REG);
            reg_id = (unsigned int )(phy_core_id / DPA_CORE_NUM_PER_REG);
            trigger_value[reg_id] |= ((unsigned int )0x1 << (unsigned int )(DPA_NMI_MAX * reg_core_id + nmi_id));
            phy_core_id++;
            phy_mask >>= 0x1;
        }
    }
    for (reg_id = 0; reg_id < DPA_DSS_NUM; reg_id++) {
        if (IS_DPA_NMI_SYS_VALID(reg_id, 0) && (trigger_value[reg_id] > 0)) {
            writel(trigger_value[reg_id], (void *)(g_dpa_nmi_ctrl.base_sysctrl + g_dpa_nmi_ctrl.nmi_sysctrl[reg_id][0]));
        }
    }
    return NMI_OK;
}

int bsp_send_dpa_nmi(dpa_nmi_num nmi_id)
{
    int ret;
    ret = bsp_dpa_nmi_trigger(g_dpa_nmi_ctrl.logic_core_mask, nmi_id);
    if (ret) {
        return ret;
    }

    return check_dpa_nmi_status(nmi_id);
}

int bsp_nmi_clear(void)
{
    unsigned int  reg_id = 0;
    if (!g_dpa_nmi_ctrl.nmi_init) {
        nmi_err("[dpa_nmi]nmi init fail\n");
        return NMI_ERROR;
    }
    for (reg_id = 0; reg_id < DPA_DSS_NUM; reg_id++) {
        if (IS_DPA_NMI_SYS_VALID(reg_id, 1)) {
            writel(DPA_NMI_DISABLE_VAL, (void *)(g_dpa_nmi_ctrl.base_sysctrl + g_dpa_nmi_ctrl.nmi_sysctrl[reg_id][1]));
        }
    }
    return 0;
}

static void nmi_phy_coremask_to_logic(void)
{
    unsigned int logic_id = 0;
    unsigned int tmp = g_dpa_nmi_ctrl.phy_core_mask;
    while (tmp) {
        if (tmp & 0x1) {
            g_dpa_nmi_ctrl.logic_core_mask |= (0x1U << logic_id);
            logic_id++;
        }
        tmp >>= 0x1;
    }
}

int get_dpa_nmi_dts(void)
{
    device_node_s *node = NULL;
    int ret;
    unsigned int sysctrl_flag;
    struct dpa_reg_info info = {NULL};

    node = bsp_dt_find_compatible_node(NULL, NULL, "dpa,nmi");
    if (node == NULL) {
        nmi_err("[dpa_nmi]can't find nmi node\n");
        return NMI_ERROR;
    }

    ret = bsp_dt_property_read_u32_array(node, "sysctrl_nmi", (unsigned int  *)&g_dpa_nmi_ctrl.nmi_sysctrl,
        sizeof(g_dpa_nmi_ctrl.nmi_sysctrl) / sizeof(unsigned int ));
    ret += bsp_dt_property_read_u32(node, "core_mask", &g_dpa_nmi_ctrl.phy_core_mask);
    ret += bsp_dt_property_read_u32(node, "sysctrl_flag", &sysctrl_flag);
    if (ret) {
        nmi_err("[dpa_nmi]read sysctrl_nmi err\n");
        return NMI_ERROR;
    }
    reg_ctrl_e ctrl_id = (sysctrl_flag == 0) ? PERI_SYSCTRL_BASE : MDMPERI_SYSCTRL_BASE;
    bsp_dpa_reg_info_get(ctrl_id, &info);
    g_dpa_nmi_ctrl.base_sysctrl = info.virt_addr;
    if (g_dpa_nmi_ctrl.base_sysctrl == NULL) {
        nmi_err("[dpa_nmi]get sysctrl_ap err\n");
        return NMI_ERROR;
    }
    nmi_phy_coremask_to_logic();
    return NMI_OK;
}

int bsp_dpa_nmi_init(void)
{
    // global value init
    if (memset_s((void *)&g_dpa_nmi_ctrl, sizeof(struct dpa_nmi_ctrl), 0, sizeof(struct dpa_nmi_ctrl))) {
        nmi_err("[dpa_nmi]g_dpa_nmi_ctrl memset fail\n");
        return NMI_ERROR;
    }

    // read dts config
    if (get_dpa_nmi_dts() != NMI_OK) {
        nmi_err("[dpa_nmi]get nmi dts error\n");
        return NMI_ERROR;
    }

    g_dpa_nmi_ctrl.nmi_init = 1;
    nmi_err("dpa nmi init ok\n");
    return NMI_OK;
}
