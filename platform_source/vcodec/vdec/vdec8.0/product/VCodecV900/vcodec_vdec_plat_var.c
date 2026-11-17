/*
 * vcodec_vdec_plat_v900.c
 *
 * This is for vdec platform
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/of.h>
#include "vcodec_vdec_plat.h"
#include "vcodec_vdec_regulator.h"
#include "vdec_memory_map.h"
#include "vdec/PXPC_SC_c_union_define.h"
#include "vcodec_osal.h"

#define VDEC_PXPC_SC_SIZE  (512 * 1024)
#define CORE_DATA_QIC_START_ADDR 0x00440000  // v900 CORE_DATA_QIC
#define SMMU_TBU_SWID_CFG_OFS 0x100


const char *pg_chip_bypass_vdec[] = {
	"cpu_normal",
	"hsdt_cdc",
	"unknown",
};


static bool bypass_vdec_by_soc_spec(void)
{
	int32_t ret;
	const char *soc_spec = NULL;
	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, soc_spec");
	size_t i;
	if (!np) {
		dprint(PRN_ERROR, "of_find_compatible_node fail or normal type chip\n");
		return false;
	}

	ret = of_property_read_string(np, "soc_spec_set", &soc_spec);
	if (ret) {
		dprint(PRN_ERROR, "of_property_read_string fail\n");
		return false;
	}

	for (i = 0; i < ARRAY_SIZE(pg_chip_bypass_vdec); i++) {
		ret = strcmp(soc_spec, pg_chip_bypass_vdec[i]);
		if (!ret) {
			dprint(PRN_ALWS, "is pg chip : %s, need bypass vdec\n", pg_chip_bypass_vdec[i]);
			return true;
		}
	}

	dprint(PRN_ALWS, " no need to bypss vdec\n");
	return false;
}

static bool need_cfg_tbu_max_tok_trans(void)
{
	return false;
}

// 下电时set bus idle, set为true, 上电的时候clear bus idle, set为false;
// target_value为写入值, expect_value为读预期值, 该寄存器写低位读高位, 高位为只读属性;
static void config_bus_idle(bus_idle_cfg* bus_idle, bool set)
{
	bus_idle->offset = 0x408540;
	bus_idle->expect_value = set ? 0x033f033f : 0x0;
	bus_idle->target_value = set ? 0x033f : 0x0;
}

static void pxp_config_bus_idle(bus_idle_cfg* bus_idle, bool set)
{
	bus_idle->offset = 0x408540;
	bus_idle->expect_value = set ? 0xf000f : 0x0;
	bus_idle->target_value = set ? 0xf : 0x0;
}

static void pxp_reset_config_subctrl_rst(U_VDEC_RST* reg_rst, bool enable)
{
	reg_rst->bits.calc_data_qic_clk_pxphw_soft_rst = enable ? 1: 0;
	reg_rst->bits.calc_data_qic_clk_pxpc_soft_rst = enable ? 1: 0;
}

static void pxp_reset_config_subctrl_crg(U_VDEC_CRG* reg_crg, bool enable)
{
	reg_crg->bits.calc_data_qic_clk_pxphw_en = enable ? 1: 0;
	reg_crg->bits.calc_data_qic_clk_pxpc_en = enable ? 1: 0;
}

static void pxp_powerup_softrst_bit(U_VDEC_RST* reg_rst) {
	reg_rst->bits.pxpc_dbg_soft_rst = 0;
}

static void pxp_powerup_config_syscache(uint8_t *reg_base_addr,
	uint32_t multi_core_enable, UADDR syscache_start_addr, uint32_t syscache_len)
{
	S_PXPC_SC_REGS_TYPE *pxpc_subctrl =
		(S_PXPC_SC_REGS_TYPE *)(reg_base_addr + OFFSET_OF_VDEC_BASE(PXPC_SCTRL));

	if (multi_core_enable == 0) {
		pxpc_subctrl->RV_CFG_S_2 = 0;
	} else {
		pxpc_subctrl->RV_CFG_S_2 = syscache_start_addr / 128;
		pxpc_subctrl->RV_CFG_S_3 = syscache_len / 2 / 128 - 1;
	}
	dprint(PRN_ALWS, "power on pxp config pxpc subctrl pass");
}

static uint32_t pxp_powerup_get_syscache_size(void)
{
	return VDEC_PXPC_SC_SIZE;
}

static void set_acpu_irq_mask(S_VDE_SUB_CTRL_NS_REGS_TYPE *subctrl_vir_addr)
{
	/* bit5:qic_cfg err, bit7:qic_core_data err, bit17:wdg_int */
	subctrl_vir_addr->INTR_MASK_NS_VDEC1 = 0xFFFDFF5F;
}

static bool is_open_qic_core_cfg_intr(void)
{
	return false;
}

static uint32_t get_qic_core_data_start_addr(void)
{
	return CORE_DATA_QIC_START_ADDR;
}

static void set_qic_irq_mask(uint8_t *reg_base_addr)
{
	uint32_t raw_status;
	rd_vreg(reg_base_addr, 0x4080F0, raw_status);
	dprint(PRN_ALWS, "others raw irq status:0x%x", raw_status);
	/* close bit5:qic_cfg err and bit7:qic_core_data err, hold bit17:wdg_int open. */
	wr_vreg(reg_base_addr, 0x4080B4, 0xFFFDFFFF);
}

static bool bsp_need_sw_buffer(void)
{
	return true;
}

static bool is_need_power_up_vdec_cal(void)
{
	return true;
}

static void get_media1_crg(uint8_t *media1_crg_vir_addr)
{
	uint32_t reg_value;

	rd_vreg(media1_crg_vir_addr, 0x8, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERCLKEN0 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0xc, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERSTAT0 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x18, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERCLKEN1 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x1c, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERSTAT1 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x38, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERRSTSTAT0 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x60, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV0 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x64, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV1 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x68, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV2 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x6c, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV3 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x70, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV4 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x78, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV5 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x84, reg_value);
	dprint(PRN_ALWS, "media1_crg:CLKDIV8 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0xA0, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERI_STAT0 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0xA4, reg_value);
	dprint(PRN_ALWS, "media1_crg:PERI_STAT1 %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x100, reg_value);
	dprint(PRN_ALWS, "media1_crg:DSS_DVFS %x", reg_value);

	rd_vreg(media1_crg_vir_addr, 0x104, reg_value);
	dprint(PRN_ALWS, "media1_crg:DSS_DVFS_AUTODIV %x", reg_value);
}

static void get_power_status(uint8_t *media1_crg_vir_addr)
{
	dprint(PRN_ALWS, "print media1 crg info");
	get_media1_crg(media1_crg_vir_addr);
}

static uint32_t get_smmu_tbu_swid_cfg_offset(uint32_t swid)
{
	return OFFSET_OF_VDEC_BASE(SMMU_TBU_REG_BASE) + swid * 0x4 + SMMU_TBU_SWID_CFG_OFS;
}

static void vdec_poweroff_config_retention(bool rt_enable)
{
	unused_param(rt_enable);
}

static vdec_plat_ops g_vdec_plat_v900_ops = {
	.vcodec_vdec_device_bypass = bypass_vdec_by_soc_spec,
	.smmu_need_cfg_max_tok_trans = need_cfg_tbu_max_tok_trans,
	.config_bus_idle = config_bus_idle,
	.pxp_config_bus_idle = pxp_config_bus_idle,
	.pxp_reset_config_subctrl_rst = pxp_reset_config_subctrl_rst,
	.pxp_reset_config_subctrl_crg = pxp_reset_config_subctrl_crg,
	.pxp_powerup_softrst_bit = pxp_powerup_softrst_bit,
	.pxp_powerup_config_syscache = pxp_powerup_config_syscache,
	.pxp_powerup_get_syscache_size = pxp_powerup_get_syscache_size,
	.set_acpu_irq_mask = set_acpu_irq_mask,
	.is_open_qic_core_cfg_intr = is_open_qic_core_cfg_intr,
	.get_qic_core_data_start_addr = get_qic_core_data_start_addr,
	.set_qic_irq_mask = set_qic_irq_mask,
	.bsp_need_sw_buffer = bsp_need_sw_buffer,
	.smmu_cfg_mcu_ssid = NULL,
	.is_need_power_up_vdec_cal = is_need_power_up_vdec_cal,
	.get_power_status = get_power_status,
	.get_smmu_tbu_swid_cfg_offset = get_smmu_tbu_swid_cfg_offset,
	.vdec_poweroff_config_retention = vdec_poweroff_config_retention,
};

vdec_plat_ops *get_vdec_plat_ops(void)
{
	return &g_vdec_plat_v900_ops;
}
