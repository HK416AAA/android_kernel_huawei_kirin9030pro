/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
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

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <linux/types.h>
#include <securec.h>
#include <bsp_syscache.h>
#include <bsp_print.h>
#include "sc_pmu.h"

#define THIS_MODU mod_syscache

sc_pmu_sppm_info_s g_sc_pmu_sppm_info;

int sc_pmu_sppm_init(sppm_client_pd_notify pdfunc)
{
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;
    info->regs_pmu = ioremap((void *)(uintptr_t)SYSCACHE_CFG_BASE, SYSCACHE_CFG_LEN);
    g_sc_pmu_sppm_info.sppm_notify = pdfunc;
    return 0;
}

int sc_pmu_sppm_deinit(void)
{
    (void)memset_s(&g_sc_pmu_sppm_info.sppm_cfg, sizeof(sc_pmu_sppm_cfg_s), 0, sizeof(sc_pmu_sppm_cfg_s));
    return 0;
}

int sc_pmu_sppm_config(sppm_event_entry *pentry, sppm_rchan_regs *pregs)
{
    u32 private_data;
    unsigned int i;
    unsigned int reg_index;

    if ((pentry == NULL) || (pregs == NULL)) {
        return SPPM_ERROR;
    }

    private_data = *(u32 *)pentry->private_data;

    g_sc_pmu_sppm_info.sppm_cfg.sel = SC_PMU_SPPM_SEL(private_data);

    for (i = 0; i < pentry->nums; i++) {
        reg_index = pentry->events_list[i];
        pregs->uregs[i] = (unsigned long)(SYSCACHE_CFG_BASE + SC_PMU_EVCNT((reg_index / SC_PMU_MAX) + 1 , reg_index % SC_PMU_MAX));
    }
    bsp_err("select cfg %u \n", g_sc_pmu_sppm_info.sppm_cfg.sel);
    return 0;
}

void sc_pmu_cfg_event(void)
{
    unsigned int i;
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;

    for (i = 1; i < SC_SLICE_CNT + 1; i++) {
        writel_relaxed(SC_PMU_EVENT_SC_FLT0, info->regs_pmu + SC_PMU_EVTYPE(i, 0));
        writel_relaxed(SC_PMU_EVENT_TAG_HIT_FLT0, info->regs_pmu + SC_PMU_EVTYPE(i, 1));
        writel_relaxed(SC_PMU_EVENT_SF_ACCESS_FLT0, info->regs_pmu + SC_PMU_EVTYPE(i, 2));
        writel_relaxed(SC_PMU_EVENT_SF_HIT_FLT0, info->regs_pmu + SC_PMU_EVTYPE(i, 3));
        writel_relaxed(SC_PMU_EVENT_SC_FLT1, info->regs_pmu + SC_PMU_EVTYPE(i, 4));
        writel_relaxed(SC_PMU_EVENT_TAG_HIT_FLT1, info->regs_pmu + SC_PMU_EVTYPE(i, 5));
        writel_relaxed(SC_PMU_EVENT_SF_ACCESS_FLT1, info->regs_pmu + SC_PMU_EVTYPE(i, 6));
        writel_relaxed(SC_PMU_EVENT_SF_HIT_FLT1, info->regs_pmu + SC_PMU_EVTYPE(i, 7));
    }
}

void sc_pmu_cnt_en(void)
{
    unsigned int i;
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;

    writel_relaxed(1, info->regs_pmu + SC_STATIS_GLB_EN);
    for (i = 1; i < SC_SLICE_CNT + 1; i++) {
        writel_relaxed(0xFF, info->regs_pmu + SC_PMU_CNTEN(i));
    }

}

void sc_pmu_cnt_dis(void)
{
    unsigned int i;
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;

    writel_relaxed(0, info->regs_pmu + SC_STATIS_GLB_EN);
    for (i = 1; i < SC_SLICE_CNT + 1; i++) {
        writel_relaxed(0x1, info->regs_pmu + SC_PMU_CNTEN(i));
    }
}

int sc_pmu_sppm_start(void)
{
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;
    sc_pmu_cfg cfg = {0};

    writel_relaxed(0, info->regs_pmu + SC_PMU_CNTEN(0));

    cfg.bits.pmu_en = 1;
    cfg.bits.pmu_ovcap_en = 1;
    cfg.bits.pmu_ckg_byp = 1;
    cfg.bits.pmu_cfg_non_ull_en = 1;
    writel_relaxed(cfg.val, info->regs_pmu + SC_PMU_CFG(0));
    writel_relaxed(SC_PMU_GID_CFG, info->regs_pmu + SC_PMU_FLT_CTRL0(0));

    if (info->sppm_cfg.sel == 0) {
        writel_relaxed(COUNT_TYPE_CHI, info->regs_pmu + SC_PMU_FLT_CTRL3(1));
        writel_relaxed(COUNT_TYPE_CHI, info->regs_pmu + SC_PMU_FLT_CTRL3(2));
        writel_relaxed(COUNT_TYPE_QTPE, info->regs_pmu + SC_PMU_FLT_CTRL3(3));
        writel_relaxed(COUNT_TYPE_QTPE, info->regs_pmu + SC_PMU_FLT_CTRL3(4));

        writel_relaxed(SC_PMU_FLT_MID_ACPU_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(1));
        writel_relaxed(SC_PMU_FLT_MID_ACPU_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(2));
        writel_relaxed(SC_PMU_FLT_MID_SNE_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(3));
        writel_relaxed(SC_PMU_FLT_MID_SNE_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(4));

        writel_relaxed(SC_PMU_REQ_OPC_CFG_READONCE_READCLEAN, info->regs_pmu + SC_PMU_FLT_CTRL4(1));
        writel_relaxed(SC_PMU_REQ_OPC_CFG_READONSD_READUNIQUE, info->regs_pmu + SC_PMU_FLT_CTRL4(2));
        writel_relaxed(SC_PMU_REQ_OPC_CFG_WRITENOSNP_WRITENOSNPPTRL, info->regs_pmu + SC_PMU_FLT_CTRL4(3));
        writel_relaxed(SC_PMU_REQ_OPC_CFG_WRITEUNIQUE_WRITEUNIQUEPTRL, info->regs_pmu + SC_PMU_FLT_CTRL4(4));
    } else {
        writel_relaxed(COUNT_TYPE_QTPE, info->regs_pmu + SC_PMU_FLT_CTRL3(0));

        writel_relaxed(SC_PMU_FLT_MID_L2DLE_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(1));
        writel_relaxed(SC_PMU_FLT_MID_L2DLE_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(2));
        writel_relaxed(SC_PMU_FLT_MID_SNE_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(3));
        writel_relaxed(SC_PMU_FLT_MID_SNE_CFG, info->regs_pmu + SC_PMU_FLT_CTRL1(4));

        writel_relaxed(SC_PMU_REQ_OPC_CFG_WRITENOSNP_WRITENOSNPPTRL, info->regs_pmu + SC_PMU_FLT_CTRL4(1));
        writel_relaxed(SC_PMU_REQ_OPC_CFG_WRITEUNIQUE_WRITEUNIQUEPTRL, info->regs_pmu + SC_PMU_FLT_CTRL4(2));
        writel_relaxed(SC_PMU_REQ_OPC_CFG_READNOSNP, info->regs_pmu + SC_PMU_FLT_CTRL4(3));
        writel_relaxed(SC_PMU_REQ_OPC_CFG_READ_ONCE_CLEAN_INVALID, info->regs_pmu + SC_PMU_FLT_CTRL4(4));
    }

    sc_pmu_cfg_event();

    sc_pmu_cnt_en();
    return 0;
}


int sc_pmu_sppm_stop(void)
{
    sc_pmu_cnt_dis();

    return 0;
}

static sppm_reg_interface g_sc_pmu_sppm = {
    .name = "sc_pmu_sppm_client",
    .init = sc_pmu_sppm_init,
    .deinit = sc_pmu_sppm_deinit,
    .config = sc_pmu_sppm_config,
    .start = sc_pmu_sppm_start,
    .stop = sc_pmu_sppm_stop,
};

static int sc_pmu_probe(struct platform_device *pdev)
{
    return 0;
}

static int sc_pmu_remove(struct platform_device *pdev)
{
    return 0;
}

int sc_pmu_pm_suspend(struct device *pdev)
{
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;

    if (bsp_sppm_get_chan_status(info->sppm_chan)) {
        info->sppm_bak_flag = 1;
    } else {
        info->sppm_bak_flag = 0;
    }

    if (info->sppm_notify != NULL) {
        (void)info->sppm_notify(info->sppm_chan, SPPM_CLIENT_OFF);
    }

    return 0;
}

void sc_pmu_pm_resume(struct device *pdev)
{
    sc_pmu_sppm_info_s *info = &g_sc_pmu_sppm_info;
    int ret;

    if (info->sppm_bak_flag) {
        ret = sc_pmu_sppm_start();
        if (ret != 0) {
            bsp_err("sc_pmu_sppm_start fail.\n");
        }
    }

    if (info->sppm_notify != NULL) {
        (void)info->sppm_notify(info->sppm_chan, SPPM_CLIENT_ON);
    }
}

static struct dev_pm_ops g_sc_pmu_dev_pm_ops = {
    .prepare = sc_pmu_pm_suspend,
    .complete = sc_pmu_pm_resume,
};

static struct platform_device g_sc_pmu_device = {
    .name = "sc_pmu",
    .id = -1,
    .num_resources = 0,
};

static struct platform_driver g_sc_pmu_pltfm_driver = {
    .probe = sc_pmu_probe,
    .remove = sc_pmu_remove,
    .driver = {
        .name = "sc_pmu",
        .pm = &g_sc_pmu_dev_pm_ops,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

void sc_pmu_sppm_register(void)
{
    int ret;

    if (platform_device_register(&g_sc_pmu_device)) {
        bsp_err("dev register fail.\n");
        return;
    }

    if (platform_driver_register(&g_sc_pmu_pltfm_driver)) {
        bsp_err("driver register fail.\n");
        return;
    }

    ret = bsp_sppm_client_reg(&g_sc_pmu_sppm, &g_sc_pmu_sppm_info.sppm_chan);
    if (ret != SPPM_OK) {
        bsp_err("sc_pmu_sppm_register fail.\n");
        return;
    }
    bsp_err("sc_pmu_sppm_register ok,chan:%u\n", g_sc_pmu_sppm_info.sppm_chan);
    return;
}

