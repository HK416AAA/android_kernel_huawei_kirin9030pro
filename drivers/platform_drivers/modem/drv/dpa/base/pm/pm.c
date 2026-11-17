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
 *
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/of_device.h>
#include <linux/pm_runtime.h>
#include <linux/spinlock.h>
#include <securec.h>
#include <bsp_print.h>
#include <bsp_dump.h>
#include <bsp_dt.h>
#include <bsp_slice.h>
#include "bsp_ipc_fusion.h"
#include "bsp_dpa.h"
#include "pm.h"
#include "rpm.h"
#include "wakeup.h"
#include <bsp_diag.h>
#include "dump.h"
#include <bsp_pmctrl.h>

dpa_pm_ctrl_s g_dpa_pm_ctrl = { 0 };
dpa_pm_mntn_s g_dpa_pm_mntn = { 0 };

dpa_pm_mntn_s *dpa_pm_get_mntn(void)
{
    return &g_dpa_pm_mntn;
}

inline dpa_pm_ctrl_s* dpa_pm_get_ctrl(void)
{
    return &g_dpa_pm_ctrl;
}

void pm_get_base_addr_from_dt(dpa_pm_ctrl_s *ctrl, reg_ctrl_e id, device_node_s *np, const char *node_name)
{
    void __iomem *ioaddr = NULL;
    unsigned int para_value[2] = {0};

    if (bsp_dt_property_read_u32_array(np, node_name, para_value, 2)) {
        dpa_pm_err("bsp_dt_property_read_u32_array err.\n");
        return;
    }

    // ioremap 映射是device属性，访问要求4B对齐
    ioaddr = ioremap((phys_addr_t)para_value[0], (size_t)para_value[1]);

    ctrl->reg_info[id].virt_addr = ioaddr;
    ctrl->reg_info[id].phy_addr = (phys_addr_t)para_value[0];
    ctrl->reg_info[id].size = (size_t)para_value[1];

    return;
}

void dpa_pm_record_slice(dpa_pm_flow_id_e flow, slice_step_e step)
{
    dpa_pm_ctrl_s *ctrl = NULL;
    dpa_pm_mntn_s *mntn = NULL;

    if (step >= SLICE_STEP_MAX || flow >= DPA_PM_FLOW_MAX) {
        dpa_pm_err("step=0x%x, flow=0x%x err\n", step, flow);
        return;
    }

    ctrl = dpa_pm_get_ctrl();
    if (ctrl == NULL) {
        return;
    }

    mntn = dpa_pm_get_mntn();
    if (mntn == NULL) {
        return;
    }

    if (ctrl->init_type == FIRST_INIT) {
        return;
    }
    mntn->sr_flow_slice[flow][step] = bsp_get_slice_value();
}

void dpa_alloc_tcm_backup_ddr(dpa_pm_ctrl_s *ctrl)
{
    ctrl->itcm_bak = kzalloc(ctrl->reg_info[DPA_ITCM_GLOCAL].size, GFP_KERNEL);
    if (ctrl->itcm_bak == NULL) {
        dpa_pm_fatal("alloc itcm back up memory failed!\n");
        return;
    }

    ctrl->dtcm_bak = kzalloc(ctrl->reg_info[DPA_DTCM_GLOCAL].size, GFP_KERNEL);
    if (ctrl->dtcm_bak == NULL) {
        dpa_pm_fatal("alloc dtcm back up memory failed!\n");
        goto dtcm_alloc_fail;
    }

    return;

dtcm_alloc_fail:
    if (ctrl->itcm_bak) {
        kfree(ctrl->itcm_bak);
        ctrl->itcm_bak = NULL;
    }

    return;
}

int dpa_pm_common_init(dpa_pm_ctrl_s *ctrl, device_node_s *np)
{
    if (bsp_get_version_info() == NULL) {
        dpa_pm_err("bsp get version fail \n");
        return DPA_PM_ERR;
    }

    ctrl->dss_num = 1;
    ctrl->core_mask = 0x5;

    ctrl->plat_type = (version_plat_type_e)bsp_get_version_info()->plat_type;
    ctrl->cses_type = (version_cses_type_e)bsp_get_version_info()->cses_type;
    ctrl->chip_type = (version_chip_type_e)bsp_get_version_info()->chip_type;

    if (ctrl->chip_type == CHIP_MAXWELL || ctrl->chip_type == CHIP_FARADAY) {
        ctrl->reg_info[AO_SYSCTRL_BASE].virt_addr = bsp_sysctrl_addr_byindex(SYSCTRL_AO);   // 0xEDF00000
        ctrl->reg_info[PERI_CRG_BASE].virt_addr = bsp_sysctrl_addr_byindex(SYSCTRL_AP_PERICRG);  // 0xE0400000
        ctrl->reg_info[PERI_SYSCTRL_BASE].virt_addr = bsp_sysctrl_addr_byindex(SYSCTRL_AP_PERI);  // 0xE0401000
        pm_get_base_addr_from_dt(ctrl, PERI_FIX0_SYSCTRL_BASE, np, "peri_fix0_sysctrl");
        pm_get_base_addr_from_dt(ctrl, PERI_FIX1_SYSCTRL_BASE, np, "peri_fix1_sysctrl");
    } else if (ctrl->chip_type == CHIP_CHANGSHA) {
        pm_get_base_addr_from_dt(ctrl, ACTRL_BASE, np, "actrl");  // 0xFDB22000
        pm_get_base_addr_from_dt(ctrl, SCTRL_BASE, np, "sctrl");  // 0xFDB23000
        pm_get_base_addr_from_dt(ctrl, PCTRL_BASE, np, "pctrl");  // 0xFF00C000
        pm_get_base_addr_from_dt(ctrl, BISR_CTRL_BASE, np, "bisr_ctrl");  // 0xFDB4E000
        pm_get_base_addr_from_dt(ctrl, MDMPERI_CRG_REG_BASE, np, "mdm_peri_crg");  // 0xE6800000
        pm_get_base_addr_from_dt(ctrl, PERIPH_CRG_BASE, np, "peri_crg");  //0xFFB85000
        pm_get_base_addr_from_dt(ctrl, MDMPERI_SYSCTRL_BASE, np, "mdm_peri_sysctrl");  // 0xE6801000
    } else {
        dpa_pm_err("else, ctrl->chip_type=%u \n", ctrl->chip_type);
        pm_get_base_addr_from_dt(ctrl, ACTRL_BASE, np, "actrl");  // 0xFDB22000
        pm_get_base_addr_from_dt(ctrl, SCTRL_BASE, np, "sctrl");  // 0xFDB23000
        pm_get_base_addr_from_dt(ctrl, PCTRL_BASE, np, "pctrl");  // 0xFF00C000
        pm_get_base_addr_from_dt(ctrl, BISR_CTRL_BASE, np, "bisr_ctrl");  // 0xFDB4E000
        pm_get_base_addr_from_dt(ctrl, MDMPERI_CRG_REG_BASE, np, "mdm_peri_crg");  // 0xE6800000
        pm_get_base_addr_from_dt(ctrl, PERIPH_CRG_BASE, np, "peri_crg");  //0xFFB85000
        pm_get_base_addr_from_dt(ctrl, MDMPERI_SYSCTRL_BASE, np, "mdm_peri_sysctrl");  // 0xE6801000
    }
    pm_get_base_addr_from_dt(ctrl, DPA_SYSCTRL_BASE, np, "dpa_sysctrl_reg");
    pm_get_base_addr_from_dt(ctrl, DPA_CRG_BASE, np, "dpa_crg_reg");
    pm_get_base_addr_from_dt(ctrl, DPA_TSP_BASE, np, "tsp_reg");
    pm_get_base_addr_from_dt(ctrl, DPA_ITCM_GLOCAL, np, "dss0_l1itcm_global");
    pm_get_base_addr_from_dt(ctrl, DPA_DTCM_GLOCAL, np, "dss0_l1dtcm_global");
    pm_get_base_addr_from_dt(ctrl, DPA_ITCM_LOCAL, np, "dss0_l1itcm_local");
    bsp_dt_property_read_u32(np, "dump_size", &ctrl->dump_size);

    ctrl->scu_init_addr = ctrl->reg_info[DPA_ITCM_LOCAL].phy_addr;      // memmap DPA_L1ITCM_LOCAL

    dpa_alloc_tcm_backup_ddr(ctrl);

    return DPA_PM_OK;
}

bool dpa_pm_get_dss_state(unsigned int dss_id)
{
    dpa_pm_ctrl_s *ctrl = dpa_pm_get_ctrl();
    if (ctrl == NULL) {
        return false;
    }

    if ((ctrl->dss_state & (1U << dss_id)) > 0) {
        return true;
    } else {
        return false;
    }
}

static int dpa_pm_pu(dpa_pm_ctrl_s *ctrl, unsigned int dss_id)
{
    int ret;

    if (dss_id >= ctrl->dss_num) {
        dpa_pm_fatal("dss_id(%d) out of range!\n", dss_id);
        return DPA_PM_ERR;
    }

    if ((ctrl->dss_state & (1U << dss_id)) > 0) {
        dpa_pm_fatal("dss_id(%d) repeat power on!\n", dss_id);
        return DPA_PM_ERR;
    }

    if (ctrl->cb_ops.pm_powerup_subsys != NULL) {
        ret = ctrl->cb_ops.pm_powerup_subsys(ctrl);
        if (ret) {
            dpa_pm_fatal("dss_id(%d) dpa_pm_powerup_subsys fail \n", dss_id);
            goto timeout;
        }
    }

    if (ctrl->cb_ops.auto_dfs != NULL) {
        ctrl->cb_ops.auto_dfs();
    }

    if (ctrl->cb_ops.pm_powerup_dss != NULL) {
        ret = ctrl->cb_ops.pm_powerup_dss(ctrl, dss_id);
        if (ret) {
            dpa_pm_fatal("dss_id(%d) dpa_pm_powerup_dss fail \n", dss_id);
            goto timeout;
        }
    }

    ctrl->dss_state |= (1U << dss_id);

    return DPA_PM_OK;

timeout:
    if (unlikely(ctrl->plat_type == PLAT_ESL)) {
        return DPA_PM_OK;
    }
    system_error(DRV_ERRNO_DPA_RPM_EXC, 0, 0, NULL, 0);
    return DPA_PM_ERR;
}

int dpa_pm_pd(dpa_pm_ctrl_s *ctrl, unsigned int dss_id)
{
    int ret;

    if (dss_id >= ctrl->dss_num) {
        dpa_pm_fatal("dss_id(%d) out of range!\n", dss_id);
        return DPA_PM_ERR;
    }
    if ((ctrl->dss_state & (1U << dss_id)) == 0) {
        dpa_pm_err("dss_id(%d) repeat power down!\n", dss_id);
        return DPA_PM_ERR;
    }

    if (ctrl->cb_ops.pm_powerdown_dss != NULL) {
        ret = ctrl->cb_ops.pm_powerdown_dss(ctrl, dss_id);
        if (ret) {
            goto timeout;
        }
    }

    if (ctrl->cb_ops.pm_powerdown_subsys != NULL) {
        ret = ctrl->cb_ops.pm_powerdown_subsys(ctrl);
        if (ret) {
            goto timeout;
        }
    }

    ctrl->dss_state &= ~(1U << dss_id);

    return 0;

timeout:
    if (unlikely(ctrl->plat_type == PLAT_ESL)) {
        ctrl->dss_state &= ~(1U << dss_id);
        return DPA_PM_OK;
    }
    system_error(DRV_ERRNO_DPA_RPM_EXC, 0, 0, NULL, 0);
    return DPA_PM_ERR;
}

int dpa_pm_startup(dpa_pm_ctrl_s *ctrl, dpa_pm_init_type_e type)
{
    unsigned int i;
    int ret;

    ctrl->init_type = type;

    for (i = 0; i < ctrl->dss_num; i++) {
        ret = dpa_pm_pu(ctrl, i);
        if (ret) {
            dpa_pm_err("dss-%d power up fail \n", i);
            return ret;
        }
    }
    return DPA_PM_OK;
}

int dpa_pm_powerdown(dpa_pm_ctrl_s *ctrl)
{
    unsigned int i;
    int ret;

    ctrl->init_type = DPA_PM_DOWN;

    for (i = 0; i < ctrl->dss_num; i++) {
        ret = dpa_pm_pd(ctrl, i);
        if (ret) {
            dpa_pm_err("dss-%d power down fail \n", i);
            return ret;
        }
    }

    return DPA_PM_OK;
}

irqreturn_t dpa_wake_acore_irq_handler(int irq, void *dev_id)
{
    UNUSED(irq);
    UNUSED(dev_id);
    return IRQ_HANDLED;
}

// A核唤醒源，pm框架会统一备份恢复，只需要初始化使能一次即可。
static int dpa_wake_acore_irq_init(dpa_pm_ctrl_s *ctrl)
{
    int ret;
    device_node_s *wake_node = NULL;

    wake_node = bsp_dt_find_node_by_path("/dpa_wake_irq");
    if (wake_node == NULL) {
        dpa_pm_err("dpa_wake_irq node find fail\n");
        return DPA_PM_ERR;
    }

    ctrl->wake_acore_irq = bsp_dt_irq_parse_and_map(wake_node, 0);
    ret = request_irq(ctrl->wake_acore_irq, dpa_wake_acore_irq_handler, 0, "dpa_wake_acore_irq", NULL);
    if (ret) {
        dpa_pm_err("dpa_wake_acore_irq(%u) register fail, ret = %d \n", ctrl->wake_acore_irq, ret);
        return DPA_PM_ERR;
    }

    enable_irq_wake(ctrl->wake_acore_irq);

    if (ctrl->cb_ops.enable_dpa_wake_acore_irq != NULL) {
        ctrl->cb_ops.enable_dpa_wake_acore_irq();
    }

    return DPA_PM_OK;
}

static irqreturn_t wakeup_dpa_interrupt(int irq, void *dev_id)
{
    dpa_pm_ctrl_s *ctrl = NULL;
    dpa_pm_mntn_s *mntn = NULL;
    struct device *dev = bsp_dpa_get_runtime_dev();
    unsigned int time;

    UNUSED(irq);
    UNUSED(dev_id);

    ctrl = dpa_pm_get_ctrl();
    if (ctrl == NULL) {
        bsp_diag_drv_log_report(BSP_P_ERR, "wakeup_dpa_interrupt ctrl == NULL \n");
        return IRQ_HANDLED;
    }

    // 已上电，直接返回，该唤醒源中断不处理；
    if (dpa_pm_get_dss_state(0)) {
        return IRQ_HANDLED;
    }

    time = bsp_get_slice_value();
    bsp_diag_drv_log_report(BSP_P_ERR, "wakeup_dpa_interrupt b time:0x%x\n", time);

    // 记录唤醒源
    if (ctrl->cb_ops.record_dpa_wakeup_src != NULL) {
        ctrl->cb_ops.record_dpa_wakeup_src();
    }

    // step4: 去使能DPA唤醒源中断（ACPU响应）
    if (ctrl->cb_ops.disable_wakeup_irq != NULL) {
        ctrl->cb_ops.disable_wakeup_irq();
    }

    // 该处需要走RPM唤醒resume流程
    dpa_runtime_resume(dev);

    time = bsp_get_slice_value();
    bsp_diag_drv_log_report(BSP_P_ERR, "wakeup_dpa_interrupt e time:0x%x\n", time);

    mntn = dpa_pm_get_mntn();
    if (mntn == NULL) {
        return IRQ_HANDLED;
    }

    mntn->wakeup_time[mntn->wakeup_cnt_total % SR_CNT_MAX] = bsp_get_slice_value();
    mntn->wakeup_cnt_total++;

    return IRQ_HANDLED;
}

int dpa_wakeup_int_init(dpa_pm_ctrl_s *ctrl, device_node_s *np)
{
    int ret;

    ctrl->wake_dpa_irq = bsp_dt_irq_parse_and_map(np, 0);
    if (ctrl->wake_dpa_irq < 0) {
        dpa_pm_err("dpa_wakeup_int irq not found\n");
        return DPA_PM_ERR;
    }

    ret = request_irq(ctrl->wake_dpa_irq, wakeup_dpa_interrupt, 0, "dpa_wakeup_int", NULL);
    if (unlikely(ret < 0)) {
        dpa_pm_err("ERROR: request the IRQ %d (error: %d)\n", ctrl->wake_dpa_irq, ret);
        return DPA_PM_ERR;
    }

    return DPA_PM_OK;
}

void pm_pd_dpa_ipc_cb(void *arg)
{
    dpa_pm_ctrl_s *ctrl = NULL;
    dpa_pm_mntn_s *mntn = NULL;
    struct device *dev = bsp_dpa_get_runtime_dev();
    unsigned int time;
    unsigned long flags;

    time = bsp_get_slice_value();

    ctrl = dpa_pm_get_ctrl();
    if (ctrl == NULL) {
        return;
    }

    if (!dpa_pm_get_dss_state(0)) {
        return;
    }

    bsp_diag_drv_log_report(BSP_P_ERR, "pm_pd_dpa_ipc_cb b time:0x%x\n", time);

    spin_lock_irqsave(&ctrl->sleep_lock, flags);
    dpa_runtime_suspend(dev);
    spin_unlock_irqrestore(&ctrl->sleep_lock, flags);

    time = bsp_get_slice_value();
    bsp_diag_drv_log_report(BSP_P_ERR, "pm_pd_dpa_ipc_cb e time:0x%x\n", time);

    mntn = dpa_pm_get_mntn();
    if (mntn == NULL) {
        return;
    }

    mntn->sleep_time[mntn->sleep_cnt % SR_CNT_MAX] = bsp_get_slice_value();
    mntn->sleep_cnt++;
}

int dpa_pmctrl_creat(dpa_pm_ctrl_s *ctrl)
{
    int ret;
    unsigned int pmctrl_handle = 0;
    static const char name[] = "dpa_dvfs";

    ret = bsp_pmctrl_create(PERI_PMCTRL, name, &pmctrl_handle);
    if (ret != 0) {
        dpa_pm_err("dpa pmctrl creat fail, ret = 0x%x \n", ret);
        return ret;
    }

    ctrl->div_pmctrl = pmctrl_handle;

    return 0;
}

static int dpa_probe(struct platform_device *pdev)
{
    int ret;
    dpa_pm_ctrl_s *ctrl = NULL;
    device_node_s *np = NULL;
    ipc_handle_t phandle = NULL;

    dpa_pm_err("dpa_probe_init begin \n");

    np = bsp_dt_find_compatible_node(NULL, NULL, "dpa");
    if (np == NULL) {
        dpa_pm_err("dts read fail \n");
        return DPA_PM_ERR;
    }

    ctrl = dpa_pm_get_ctrl();
    if (ctrl == NULL) {
        return DPA_PM_ERR;
    }

    ctrl->dev = &pdev->dev;

    ret = dpa_pm_common_init(ctrl, np);
    if (ret) {
        return ret;
    }

    dpa_pm_cb_ops_register(ctrl);

    ret = dpa_pmctrl_creat(ctrl);
    if (ret) {
        dpa_pm_err("pmctrl creat fail \n");
        return ret;
    }

    ret = dpa_pm_startup(ctrl, FIRST_INIT);
    if (ret) {
        dpa_pm_err("dpa_pm_startup fail.\n");
        return ret;
    }

    ret = bsp_dpa_load_init();
    if (ret) {
        dpa_pm_err("bsp_dpa_load_init fail.\n");
        return ret;
    }

    ret = dpa_wakeup_int_init(ctrl, np);
    if (ret) {
        dpa_pm_err("dpa_wakeup_int_init fail.\n");
        return ret;
    }

    ret = dpa_wake_acore_irq_init(ctrl);
    if (ret) {
        dpa_pm_err("dpa_wake_acore_irq_init fail.\n");
        return ret;
    }
    ret = bsp_ipc_open(IPC_ACPU_INT_SRC_DPA_POWERDOWN, &phandle);
    if (ret) {
        dpa_pm_err("dpa ipc open fail \n");
        return ret;
    }
    ret = bsp_ipc_connect(phandle, pm_pd_dpa_ipc_cb, NULL);
    if (ret) {
        dpa_pm_err("dpa ipc connect fail \n");
        return ret;
    }
    ctrl->ipc_handle = phandle;

    ret = dpa_pm_wakeup_init();
    if (ret) {
        dpa_pm_err("dpa wakeup init fail \n");
        return ret;
    }

    ret = dpa_pm_dump_init();
    if (ret) {
        dpa_pm_err("dpa pm dump init fail \n");
        return ret;
    }

    spin_lock_init(&ctrl->sleep_lock);

    dpa_pm_err("dpa_probe_init end \n");
    return DPA_PM_OK;
}

static int dpa_remove(struct platform_device *pdev)
{
    bsp_dpa_load_exit();

    return 0;
}

static struct platform_driver g_dpa_pltfm_driver = {
    .probe = dpa_probe,
    .remove = dpa_remove,
    .driver = {
        .name = "dpa",
        .owner = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

static struct platform_device g_dpa_device = {
    .name = "dpa",
    .id = -1,
    .num_resources = 0,
};

int dpa_init(void)
{
    device_node_s *np = bsp_dt_find_compatible_node(NULL, NULL, "dpa");
    if (np == NULL) {
        dpa_pm_err("dpa dts fail.\n");
        return -1;
    }

    if (bsp_dt_device_is_available(np) == false) {
        if (platform_device_register(&g_dpa_device)) {
            dpa_pm_err("dpa dev register fail.\n");
            return -1;
        }
    }

    if (platform_driver_register(&g_dpa_pltfm_driver)) {
        dpa_pm_err("dpa drv register fail.\n");
        return -1;
    }

    return 0;
}

subsys_initcall_sync(dpa_init);

void* bsp_dpa_pm_get_ctrl(void)
{
    return (void *)dpa_pm_get_ctrl();
}