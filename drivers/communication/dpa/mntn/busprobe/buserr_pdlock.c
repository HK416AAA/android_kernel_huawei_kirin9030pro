/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
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
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <securec.h>
#include <bsp_dt.h>
#include <bsp_dump.h>
#include <bsp_dpa.h>
#include "buserr_base.h"
#include "buserr_probe.h"
#include "buserr_pdlock.h"

#ifdef __cplusplus
extern "C" {
#endif

struct pdlock_dump_record *g_pdlock_dump_record = NULL;
pdlock_axb_err_info_s g_pdlock_axb_err_info;

pdlock_axb_err_info_s *pdlock_get_axb_err_info(void)
{
    return &g_pdlock_axb_err_info;
}

static void pdlock_set_reg(unsigned int value, void *address, unsigned int start_bit, unsigned int end_bit)
{
    unsigned int temp, mask, start_mask;

    start_mask = end_bit - start_bit + 1;
    if (start_mask >= PDLK_REG_VER_LEN) {
        return;
    }

    mask = ((1U << start_mask) - 1) << start_bit;

    temp = readl(address);
    value = (temp & (~mask)) | ((value << start_bit) & mask);
    writel(value, address);
}

void *pdlock_get_sysctrl_addr(device_node_s *child, u32 *phy_addr)
{
    int ret;
    void *vir_addr = NULL;
    u32 sysctrl_base_info[PDLOCK_SCTRL_REG_ARRY] = { 0, 0 };

    ret = bsp_dt_property_read_u32_array(child, "sysctrl_base", sysctrl_base_info, PDLOCK_SCTRL_REG_ARRY);
    if (ret) {
        pdlock_print("rd sysctrl_base fail\n");
        return NULL;
    }

    vir_addr = ioremap(sysctrl_base_info[0], sysctrl_base_info[1]);
    if (vir_addr == NULL) {
        pdlock_print("ioremap base addr failed!\n");
        return NULL;
    }
    *phy_addr = sysctrl_base_info[0];
    return vir_addr;
}

void pdlock_apb_ahb_config(void)
{
    int config_idx;
    pdlock_config_reg_s *config_reg = NULL;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    config_reg = pdlock_info->config_reg;
    if (config_reg == NULL) {
        return;
    }
    for (config_idx = 0; config_idx < pdlock_info->config_reg_cnt; config_idx++) {
        if (config_reg->vir_addr == NULL) {
            continue;
        }
        pdlock_set_reg(config_reg->set_val,
                       config_reg->vir_addr + config_reg->offset,
                       config_reg->start_bit,
                       config_reg->end_bit);
    }
}

s32 pdlock_config_reg_init(device_node_s *node, pdlock_config_reg_s *config_reg, u32 reg_max)
{
    u32 i = 0;
    u32 u = 0;
    u32 config_idx = 0;
    s32 idx;
    const __be32 *p = NULL;
    struct property *prop = NULL;
    u32 reg_value[PDLOCK_REG_BUTT] = { 0 };

    bsp_dt_property_for_each_u32(node, "pdlock_config", prop, p, u) {
        reg_value[i++] = u;
        if (i == PDLOCK_REG_BUTT) {
            i = 0;
            config_reg[config_idx].phy_addr = reg_value[PDLOCK_REG_BASE];
            config_reg[config_idx].vir_addr = (void *)ioremap((uintptr_t)reg_value[PDLOCK_REG_BASE], 0x1000);
            if (config_reg[config_idx].vir_addr == NULL) {
                if (config_idx > 0) {
                    for (idx = (s32)(config_idx - 1); idx >= 0; idx--) {
                        iounmap(config_reg[idx].vir_addr);
                    }
                }
                pdlock_print("not get addr\n");
                return PDLOCK_ERROR;
            }
            config_reg[config_idx].offset    = reg_value[PDLOCK_REG_OFFSET];
            config_reg[config_idx].start_bit = reg_value[PDLOCK_REG_START_BIT];
            config_reg[config_idx].end_bit   = reg_value[PDLOCK_REG_END_BIT];
            config_reg[config_idx].set_val   = reg_value[PDLOCK_REG_SET_VAL];
            config_idx++;
            if (config_idx >= reg_max) {
                break; /* 避免数组越界 */
            }
        }
    }
    return PDLOCK_OK;
}

int pdlock_apb_ahb_config_init(const char *name)
{
    s32 ret;
    u32 config_idx = 0;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();
    device_node_s *dev = NULL;

    dev = bsp_dt_find_compatible_node(NULL, NULL, name);
    if (dev == NULL) {
        pdlock_print("%s rd fail\n", name);
        return PDLOCK_ERROR;
    }
    if (bsp_dt_property_read_u32(dev, "pdlock_config_cnt", &config_idx)) {
        pdlock_print("get pdlock_config_cnt fail\n");
        return PDLOCK_ERROR;
    }

    if (config_idx > PDLOCK_COFIG_REG_MAX) {
        pdlock_print("%s config_cnt oversize %d \n", name, config_idx);
        config_idx = PDLOCK_COFIG_REG_MAX;
    }

    pdlock_info->config_reg =
        (pdlock_config_reg_s *)kmalloc(config_idx * sizeof(pdlock_config_reg_s), GFP_KERNEL);
    if (pdlock_info->config_reg == NULL) {
        pdlock_print("config_reg malloc fail\n");
        return PDLOCK_ERROR;
    }
    (void)memset_s(pdlock_info->config_reg, config_idx * sizeof(pdlock_config_reg_s), 0,
                   config_idx * sizeof(pdlock_config_reg_s));

    pdlock_info->config_reg_cnt = config_idx;
    ret = pdlock_config_reg_init(dev, pdlock_info->config_reg, config_idx);
    if (ret) {
        pdlock_print("pdlock_config_reg_init fail\n");
        kfree(pdlock_info->config_reg);
        pdlock_info->config_reg= NULL;
        return PDLOCK_ERROR;
    }
    return PDLOCK_OK;
}

s32 pdlock_err_reg_base_alloc(u32 base_num)
{
    u32 err_base_size;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    err_base_size = base_num * sizeof(pdlock_apb_ahb_state_reg_s);

    pdlock_info->err_base = (pdlock_apb_ahb_state_reg_s *)kmalloc(err_base_size, GFP_KERNEL);
    if (pdlock_info->err_base == NULL) {
        pdlock_print("err_base malloc fail\n");
        return PDLOCK_ERROR;
    }
    (void)memset_s(pdlock_info->err_base, err_base_size, 0, err_base_size);
    pdlock_info->err_base_num = base_num;
    return PDLOCK_OK;
}

s32 pdlock_err_reg_init(device_node_s *child, pdlock_apb_ahb_state_reg_s *err_base)
{
    const char *err_bus_name = NULL;

    if (child == NULL) {
        pdlock_print("para err!\n");
        return PDLOCK_ERROR;
    }

    err_base->vir_addr = pdlock_get_sysctrl_addr(child, &err_base->phy_addr);
    if (err_base->vir_addr == NULL) {
        pdlock_print("get addr fail\n");
        return PDLOCK_ERROR;
    }

    if (bsp_dt_property_read_u32(child, "err_reg", &err_base->err_reg)) {
        pdlock_print("get err_reg fail\n");
        return PDLOCK_ERROR;
    }
    if (bsp_dt_property_read_u32(child, "err_addr", &err_base->err_addr)) {
        pdlock_print("get err_addr fail\n");
        return PDLOCK_ERROR;
    }
    if (bsp_dt_property_read_u32_array(child, "srst_reg", (u32 *)&err_base->srst_reg, PDLOCK_SRST_BUTT)) {
        pdlock_print("get srst_reg fail\n");
        return PDLOCK_ERROR;
    }
    if (bsp_dt_property_read_string(child, "err_name", &err_bus_name)) {
        pdlock_print("read err_name fail\n");
        return PDLOCK_ERROR;
    }
    if (strncpy_s(err_base->err_bus_name, PDLK_BUS_NAME_LEN, err_bus_name, strlen(err_bus_name))) {
        pdlock_print("copy err_name fail\n");
        return PDLOCK_ERROR;
    }

    return PDLOCK_OK;
}

s32 pdlock_apb_apb_err_info_init(void)
{
    u32 reg_num;
    u32 i = 0;
    device_node_s *dev = NULL, *child = NULL;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    dev = bsp_dt_find_compatible_node(NULL, NULL, "pdlock_info");
    if (dev == NULL) {
        pdlock_print("skip init\n");
        return PDLOCK_OK;
    }
    if (bsp_dt_property_read_u32(dev, "chipid", &pdlock_info->chipid)) {
        pdlock_print("get chipid fail\n");
        pdlock_info->chipid = 0;
    }

    if (bsp_dt_property_read_u32(dev, "pdlock_err_reg_num", &reg_num)) {
        pdlock_print("get reg_num fail\n");
        return PDLOCK_ERROR;
    }

    if (reg_num == 0) {
        pdlock_print(" no err_state_reg\n");
        return PDLOCK_OK;
    }
    /* 分配内存记录寄存器 */
    if (pdlock_err_reg_base_alloc(reg_num)) {
        return PDLOCK_ERROR;
    }

    bsp_dt_for_each_child_of_node(dev, child) {
        if (i >= reg_num) {
            pdlock_print("child size err\n");
            return PDLOCK_ERROR;
        }
        if (pdlock_err_reg_init(child, pdlock_info->err_base + i)) {
            return PDLOCK_ERROR;
        }
        i++;
    }
    pdlock_info->init_flag = PDLOCK_ENABLE;
    return PDLOCK_OK;
}

void pdlock_clr_axb_int(void)
{
    pdlock_apb_ahb_state_reg_s *err_base = NULL;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    if (pdlock_info->init_flag != PDLOCK_ENABLE) {
        return;
    }
    err_base = &pdlock_info->err_base[pdlock_info->err_base_idx];
    /* rst all mst_err irq & state */
    pdlock_set_reg(1, err_base->vir_addr + err_base->srst_reg.offset,
                    err_base->srst_reg.start_bit, err_base->srst_reg.end_bit);
    udelay(10); /* 10 us */
    /* enable all mst_err irq & state */
    pdlock_set_reg(0, err_base->vir_addr + err_base->srst_reg.offset,
                    err_base->srst_reg.start_bit, err_base->srst_reg.end_bit);
}

void pdlock_save_dump(void)
{
    u32 value;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();
    u32 err_base_idx = pdlock_info->err_base_idx;

    g_pdlock_dump_record->idx = err_base_idx;
    g_pdlock_dump_record->axi_base_addr = (uintptr_t)pdlock_info->err_base[err_base_idx].phy_addr;
    if (strncpy_s(g_pdlock_dump_record->err_bus_name, PDLK_BUS_NAME_LEN,
        pdlock_info->err_base[err_base_idx].err_bus_name, strlen(pdlock_info->err_base[err_base_idx].err_bus_name))) {
        pdlock_print("save err_opc_name fail\n");
    }
    value = readl(pdlock_info->err_base[err_base_idx].vir_addr + pdlock_info->err_base[err_base_idx].err_reg);
    g_pdlock_dump_record->errlog1 = value;
    value = readl(pdlock_info->err_base[err_base_idx].vir_addr + pdlock_info->err_base[err_base_idx].err_addr);
    g_pdlock_dump_record->errlog2 = value;
    g_pdlock_dump_record->magic_num = PDLOCK_RECORD_MAGIC_NUM;
}

void pdlock_show_dump_reg(void)
{
    pdlock_print("bus: %s\n", g_pdlock_dump_record->err_bus_name);
    pdlock_print("reg: %08x %08x\n", g_pdlock_dump_record->errlog1, g_pdlock_dump_record->errlog2);
}
unsigned int pdlock_get_mid(void)
{
    return ((g_pdlock_dump_record->errlog1 >> PDLOCK_ERR_ID_BIT) & PDLOCK_ERR_ID_MASK);
}

unsigned int pdlock_get_access_addr(void)
{
    return g_pdlock_dump_record->errlog2;
}

void pdlock_check_apb_err(void)
{
    int i;
    u32 value;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    if (pdlock_info->init_flag != PDLOCK_ENABLE) {
        pdlock_print("not init\n");
        return;
    }

    /* 扫描各总线错误，如果状态置1 说明此处有异常 */
    for (i = 0; i < pdlock_info->err_base_num; i++) {
        value = readl(pdlock_info->err_base[i].vir_addr + pdlock_info->err_base[i].err_reg);
        /* err state flag */
        if ((value & PDLOCK_ERR_STATE_MASK) == 0) {
            continue;
        }

        pdlock_info->err_base_idx = i;
        pdlock_save_dump();
        pdlock_show_dump_reg();
    }
    pdlock_print("check done\n");
}

irqreturn_t pdlock_fault_irq_handler(void)
{
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    pdlock_print("axi err in\n");
    if (pdlock_info->init_flag != PDLOCK_ENABLE) {
        pdlock_print("pdlock not init\n");
        return IRQ_HANDLED;
    }

    pdlock_check_apb_err();

    if (bsp_buserr_ctrl()->cfg.axi_rst == true) {
        pdlock_print("enter rst\n");
        dpa_system_error(DRV_ERRNO_MDMPERI_PDLOCK, pdlock_get_mid(), pdlock_get_access_addr(), NULL, 0);
        return IRQ_HANDLED;
    }

    pdlock_clr_axb_int();
    pdlock_info->err_base_idx = 0;
    pdlock_print("no rst, irq clr\n");
    return IRQ_HANDLED;
}

void pdlock_fault_dump_handler(void)
{
    if (g_pdlock_dump_record == NULL) {
        pdlock_print("pdlock_dump_records is NULL!\n");
        return;
    }
    if (g_pdlock_dump_record->magic_num == PDLOCK_RECORD_MAGIC_NUM) {
        pdlock_print("record skip\n");
        return;
    }

    pdlock_check_apb_err();
}

s32 pdlock_dump_init(void)
{
    s32 ret;
    pdlock_axb_err_info_s *pdlock_info = pdlock_get_axb_err_info();

    g_pdlock_dump_record = (struct pdlock_dump_record *)bsp_dpa_dump_register_field(OM_DPAHOST_DPA_PDLOCK, \
        "pdlock", sizeof(struct pdlock_dump_record), 0);
    if (g_pdlock_dump_record == NULL) {
        pdlock_print("pdlock get dump space fail\n");
        return PDLOCK_ERROR;
    }
    (void)memset_s(g_pdlock_dump_record, sizeof(struct pdlock_dump_record), 0, sizeof(struct pdlock_dump_record));

    ret = bsp_dpa_dump_register_hook("dw_axi_fault", pdlock_fault_dump_handler);
    if (ret == PDLOCK_ERROR) {
        pdlock_print("register pdlock dump fail\n");
        return PDLOCK_ERROR;
    }
    g_pdlock_dump_record->chip_version = pdlock_info->chipid;
    return PDLOCK_OK;
}

s32 bsp_pdlock_init(void)
{
    s32 ret;

    pdlock_print("[init]start\n");

    ret = pdlock_apb_ahb_config_init("mdmperi_pdlock");
    if (ret) {
        return PDLOCK_ERROR;
    }

    pdlock_apb_ahb_config();

    ret = pdlock_apb_apb_err_info_init();
    if (ret) {
        return PDLOCK_ERROR;
    }

    ret = pdlock_dump_init();
    if (ret) {
        return PDLOCK_ERROR;
    }

    ret = bsp_buserr_register_hook("pdlock_fault_hdle", pdlock_fault_irq_handler, BUS_ERROR_AHB_APB_AXI);
    if (ret) {
        pdlock_print("register handler fail\n");
        return PDLOCK_ERROR;
    }
    pdlock_print("[init]ok\n");
    return PDLOCK_OK;
}

#ifdef __cplusplus
}
#endif
