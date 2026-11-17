/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
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

#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/of_address.h>
#include <securec.h>
#include <soc_media_pmctrl_interface.h>
#include <dpu/soc_dpu_define.h>
#include "dksm_debug.h"
#if defined(CONFIG_DRMDRIVER)
#include <platform_include/see/bl31_smc.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#endif
#include "dpu/dpu_base_addr.h"
#include "dkmd_log.h"
#include "dkmd_object.h"
#include "dpu_config_utils.h"
#include "dpu_dvfs.h"
#include "dvfs.h"

#define SW_DVFS_OPT_NUM  8
#define HW_DVFS_OPT_NUM  32
#define MAX_INSTR_COUNT  40
#define HW_ACTIVE_OPT_NUM 8
#define HW_IDLE_OPT_NUM  12

#ifndef CONFIG_DVFS_RESERVE_TIME
#define DVFS_OV_RESERVE_TIME 0
#else
#define DVFS_OV_RESERVE_TIME CONFIG_DVFS_RESERVE_TIME
#endif

/* fpga do not support clk_sw, use nop op instead */
#define CLK_SW_OP (g_dpu_config_data.version.info.hw_type == DPU_HW_TYPE_FPGA ? 0b1110 : 0b0100)

enum {
	OPT_VOLT_UP_INDEX = 0,
	OPT_VOLT_DOWN_INDEX = 1,
	OPT_VOLT_MAX_INDEX,
};

enum {
	OPT_VOLT_IDLE_NORMAL_OR_DOZE1_INDEX = 0,
	OPT_VOLT_IDLE_DOZE1_ONLY_INDEX = 1,
	OPT_VOLT_IDLE_MAX_INDEX,
};

enum {
	INTRA_VOTE_TYPE,
	INTER_VOTE_TYPE,
};

struct intra_dvfs_record {
	uint32_t intra_prev_vote_level; // online previous frame vote perf level
	uint32_t intra_cur_vote_level; // online current frame vote perf level
	uint32_t inter_cur_vote_level; // offline current frame vote perf level
	uint32_t inter_effect_level; // actual effective level, when inter vote
	uint32_t last_vote_type; // 0 - INTRA_VOTE_TYPE; 1 - INTER_VOTE_TYPE
	uint32_t cur_frm_rate; // online cur frm rate
	uint32_t prev_frm_rate; // online prev frm rate
	bool is_last_vote_doze1;
};

struct intra_dvfs_record g_dvfs_record;

typedef union {
	uint16_t value;
	/* data include END, WAIT_CNT, WAIT_CHG, VOL_CFG, CLK_SW, CLK_DIV, PLL_EN, PLL_GT, NOP */
	struct dvfs_instruction {
		uint32_t op     : 4;     /* bit[3:0]  : OP code for dvfs */
		uint32_t halt   : 1;     /* bit[4]    : halt flag for dvfs */
		uint32_t instr  : 11;    /* bit[15:5] : instruction code for dvfs */
	} cmd;
} dpu_dvfs_instr;

struct dvfs_vote_info {
	uint16_t vote_vol;
	uint16_t vote_clk_sel;
	uint16_t vote_clk_div;
};

static uint32_t s_dpu_vivo_rate_tbl_v110[] = {
    DPU_VIVOBUS_FREQ0,
    DPU_VIVOBUS_FREQ1,
    DPU_VIVOBUS_FREQ2,
    DPU_VIVOBUS_FREQ3,
    DPU_VIVOBUS_FREQ4,
};

static uint32_t s_dpu_vivobus_bandwidth[] = {
    DPU_VIVOBUS_BANDWIDTH_OFF,
    DPU_VIVOBUS_BANDWIDTH1,
    DPU_VIVOBUS_BANDWIDTH2,
    DPU_VIVOBUS_BANDWIDTH3,
    DPU_VIVOBUS_BANDWIDTH4,
};

static uint64_t s_dpu_core_rate_tbl_v110[] = {
	DPU_CORE_FREQ_OFF, /* L0_POWER_OFF */
	DPU_CORE_FREQ1, /* 0.60V-335M */
	DPU_CORE_FREQ2, /* 0.65V-418M */
	DPU_CORE_FREQ3, /* 0.65V-480M */
	DPU_CORE_FREQ4, /* 0.70V-558M */
	DPU_CORE_FREQ5, /* 0.80V-640M */
};

uint32_t dpu_config_get_perf_level(uint64_t freq)
{
	uint32_t i;
	/* DPU_CORE_LEVEL_ON means L1_060V */
	for (i = DPU_CORE_LEVEL_ON; i <= DPU_PERF_LEVEL_MAX; ++i) {
		if (freq <= s_dpu_core_rate_tbl_v110[i])
			return i;
	}
	return DPU_PERF_LEVEL_MAX;
}

uint64_t dpu_dvfs_freq_add_offline_axi(uint64_t freq)
{
	return freq;
}

uint64_t dpu_config_get_core_rate(uint32_t level)
{
	if (level >= ARRAY_SIZE(s_dpu_core_rate_tbl_v110))
		return s_dpu_core_rate_tbl_v110[DPU_PERF_LEVEL_MAX];

	return s_dpu_core_rate_tbl_v110[level];
}

uint64_t dpu_config_get_vivo_rate(uint32_t level)
{
	if (level >= DPU_VIVOBUS_LEVEL_MAX)
		return s_dpu_vivo_rate_tbl_v110[DPU_VIVOBUS_LEVEL_MAX];
	else if (level <= DPU_VIVOBUS_LEVEL_OFF)
		return s_dpu_vivo_rate_tbl_v110[DPU_VIVOBUS_LEVEL_OFF];

	return s_dpu_vivo_rate_tbl_v110[level];
}


/* level1 0.6  - 211M, fll, 1div  */
static struct dvfs_vote_info g_doze1_vote_info = {
    .vote_vol = 0b0000,
	.vote_clk_sel = 0b1000,
	.vote_clk_div = 0b0000,
};

/*
 * clk sw pll 0b0001: ppll2_b 0b0010: ppll0 0b0100: ppll1 0b1000: ppll2
 * vol_cfg 0b0011: 0.8v 0b0010: 0.7v 0b0001: 0.65v 0b0000: 0.6v
 */
static struct dvfs_vote_info g_vote_info[] = {
	/* level0 0.5~  - 104M, ppll0, 16div  */
	{
		.vote_vol = 0b0101,
		.vote_clk_sel = 0b0010,
		.vote_clk_div = 0b1111,
	},
	/* level2 0.6  - 334M, ppll0, 5div  */
	{
		.vote_vol = 0b0000,
		.vote_clk_sel = 0b0010,
		.vote_clk_div = 0b0100,
	},
	/* level3 0.65  - 418M, ppll0, 4div  */
	{
		.vote_vol = 0b0001,
		.vote_clk_sel = 0b0010,
		.vote_clk_div = 0b0011,
	},
	/* level4 0.65  - 480M, ppll1, 3div  */
	{
		.vote_vol = 0b0001,
		.vote_clk_sel = 0b0100,
		.vote_clk_div = 0b0010,
	},
	/* level5 0.7  - 557M, ppll0, 3div  */
	{
		.vote_vol = 0b0010,
		.vote_clk_sel = 0b0010,
		.vote_clk_div = 0b0010,
	},
	/* level6 0.8  - 640M, ppll2_b, div detail see Macro  */
	{
		.vote_vol = 0b0011,
		.vote_clk_sel = 0b0001,
		.vote_clk_div = FREQ3_PLL2B_CLK_DIV,
	},
};

static void dpu_dvfs_peri_init(char __iomem *pmctrl_base)
{
	SOC_MEDIA_PMCTRL_DSS_DVFS_CNT_CFG1_UNION sctrl_cfg1;
	SOC_MEDIA_PMCTRL_DSS_DVFS_CNT_CFG2_UNION sctrl_cfg2;
	SOC_MEDIA_PMCTRL_DSS_DVFS_CNT_CFG3_UNION sctrl_cfg3;
	SOC_MEDIA_PMCTRL_DSS_DVFS_INTR_CFG_UNION sctrl_cfg;
	SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_UNION dvfs_en_cfg;

	sctrl_cfg1.value = 0;
	sctrl_cfg1.reg.apb_pclk_cnt_us = 0x54;
	sctrl_cfg1.reg.apb_vol_stable_cnt = 0x1;
	sctrl_cfg1.reg.apb_sw_stable_cnt = 0x1;
	sctrl_cfg1.reg.apb_sw_ack_cnt = 0x6;
	sctrl_cfg1.reg.apb_div_stable_cnt = 0x1;

	outp32(SOC_MEDIA_PMCTRL_DSS_DVFS_CNT_CFG1_ADDR(pmctrl_base), sctrl_cfg1.value);

	sctrl_cfg2.value = 0;
	sctrl_cfg2.reg.apb_div_ack_cnt = 0x6;
	sctrl_cfg2.reg.apb_pll_lock_mode = 0x0;
	sctrl_cfg2.reg.apb_lock_time = 0x32;
	sctrl_cfg2.reg.apb_pll_gt_stable_cnt = 0x1;
	outp32(SOC_MEDIA_PMCTRL_DSS_DVFS_CNT_CFG2_ADDR(pmctrl_base), sctrl_cfg2.value);

	sctrl_cfg3.value = 0;
	// hw channel dvfs need 5us to wait flush_en signal from dpu
	sctrl_cfg3.reg.apb_reload_instr_stable_cnt = 0x1A1;
	outp32(SOC_MEDIA_PMCTRL_DSS_DVFS_CNT_CFG3_ADDR(pmctrl_base), sctrl_cfg3.value);

	sctrl_cfg.value = 0;
	sctrl_cfg.reg.apb_intr_sf_dvfs_bypass = 0x1;
	sctrl_cfg.reg.apb_intr_sf_dvfs_bypass = 0x1;
	outp32(SOC_MEDIA_PMCTRL_DSS_DVFS_INTR_CFG_ADDR(pmctrl_base), sctrl_cfg.value);

	dvfs_en_cfg.value = 0;
	dvfs_en_cfg.reg.apb_hw_ch_fps_cnt = 0x0;
	dvfs_en_cfg.reg.apb_hw_ch_fps_cnt_dss_bypass = 0x0;
	dvfs_en_cfg.reg.apb_hw_ch_fps_cnt_dss2qice_bypass = 0x0;
	dvfs_en_cfg.reg.apb_hw_ch_fps_cnt_dss2ddr_bypass = 0x0;
	dvfs_en_cfg.reg.flush_pls_bypass = 0x0;
	dvfs_en_cfg.reg.vsync_pls_bypass  = 0x1;
	outp32(SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_ADDR(pmctrl_base), dvfs_en_cfg.value | 0x7E240000);
}

static void dpu_dvfs_apb_init(char __iomem *pmctrl_base)
{
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_SW_CFG_UNION sw_cfg;
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_DIV_CFG_UNION div_cfg;
	SOC_MEDIA_PMCTRL_APB_DSS_DVFS_PLL_CFG_UNION pll_cfg;
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_VF_CFG_UNION vf_cfg;
	SOC_MEDIA_PMCTRL_APB_DEBUG_CFG_UNION debug_cfg;

	sw_cfg.reg.apb_sw_init = 0x1;
	sw_cfg.reg.apb_sw = 0b0010; /* select pll0 */
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_SW_CFG_ADDR(pmctrl_base), sw_cfg.value);
	vf_cfg.reg.apb_sw_chg_init_pulse = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_VF_CFG_ADDR(pmctrl_base), vf_cfg.value);

	div_cfg.reg.apb_div_init = 0x1;
	div_cfg.reg.apb_div = 0x5; /* default 278M div 0x5 */
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_DIV_CFG_ADDR(pmctrl_base), div_cfg.value);
	vf_cfg.reg.apb_div_chg_init_pulse = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_VF_CFG_ADDR(pmctrl_base), vf_cfg.value);

	pll_cfg.reg.apb_pll_gt3 = 0x0; /* ppll2 disable   */
	pll_cfg.reg.apb_pll_en3 = 0x0;
	pll_cfg.reg.apb_pll_gt2 = 0x0; /* ppll1 disable   */
	pll_cfg.reg.apb_pll_en2 = 0x0;
	pll_cfg.reg.apb_pll_gt1 = 0x1; /* ppll0 enable    */
	pll_cfg.reg.apb_pll_en1 = 0x1;
	pll_cfg.reg.apb_pll_gt0 = 0x0; /* ppll2_b disable */
	pll_cfg.reg.apb_pll_en0 = 0x0;
	outp32(SOC_MEDIA_PMCTRL_APB_DSS_DVFS_PLL_CFG_ADDR(pmctrl_base), pll_cfg.value | (0xff << 16));

	vf_cfg.reg.apb_pll_gt3_init = 0x1;
	vf_cfg.reg.apb_pll_en3_init = 0x1;
	vf_cfg.reg.apb_pll_gt2_init = 0x1;
	vf_cfg.reg.apb_pll_en2_init = 0x1;
	vf_cfg.reg.apb_pll_gt1_init = 0x1;
	vf_cfg.reg.apb_pll_en1_init = 0x1;
	vf_cfg.reg.apb_pll_gt0_init = 0x1;
	vf_cfg.reg.apb_pll_en0_init = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_APB_VF_CFG_ADDR(pmctrl_base), vf_cfg.value);

	debug_cfg.value = 0;
	debug_cfg.reg.apb_dss2dq_debug_en = 0x1;
	debug_cfg.reg.apb_dss_dvfs_debug_en = 0x1;
	outp32(SOC_MEDIA_PMCTRL_APB_DEBUG_CFG_ADDR(pmctrl_base), debug_cfg.value);
}

static bool dpu_dvfs_is_spec_clk_order(bool is_doze1_supp, uint32_t doze1_vote_level, uint32_t other_vote_level)
{
    if (!is_doze1_supp || doze1_vote_level != DPU_CORE_LEVEL_IDLE) {
		return false;
	}

	return doze1_vote_level <= other_vote_level;
}

static int dpu_dvfs_sw_channel_cfg(char __iomem *pmctrl_base, dpu_dvfs_instr *cmd, int cmd_size, int opt_type, uint32_t vote_level)
{
	int i = 0;
	uint32_t value = 0;
	int new_opt_type = 0;
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_CH_UNION sf_ch;
	SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_UNION hw_en;

	/*
	 * OPT_VOLT_UP_INDEX: vol --> pll_en&pll_gt --> clk_sw --> clk_div --> pll_en&pll_gt --> end
	 * OPT_VOLT_DOWN_INDEX: pll_en&pll_gt --> clk_div --> clk_sw --> pll_en&pll_gt --> vol--> end
	 */
	int opt_table[OPT_VOLT_MAX_INDEX * OPT_VOLT_IDLE_MAX_INDEX][SW_DVFS_OPT_NUM] = {
		{ 0, 1, 2, 3, 4, 5, 6, 7 },
		{ 0, 1, 2, 4, 3, 5, 6, 7 },   /* ONLY DOZE1 */

		{ 1, 2, 4, 3, 5, 6, 0, 7 },
		{ 1, 2, 3, 4, 5, 6, 0, 7 }    /* ONLY DOZE1 */
	};

	if (unlikely(opt_type < 0 || opt_type >= OPT_VOLT_MAX_INDEX)) {
		dpu_pr_err("opt_type=%d is out of range", opt_type);
		return -1;
	}

    new_opt_type = opt_type * OPT_VOLT_IDLE_MAX_INDEX;
	if (dpu_dvfs_is_spec_clk_order(g_dvfs_record.is_last_vote_doze1, DPU_CORE_LEVEL_IDLE, vote_level)) {
		new_opt_type = new_opt_type + 1;
	}

	dpu_pr_debug("current peri dvfs %#x software channel status %#x hw status %#x",
		inp32(SOC_MEDIA_PMCTRL_PERI_M1_DVS_STAT7_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_RD_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_RD_ADDR(pmctrl_base)));

	/* disable hardware channel */
	hw_en.value = 0;
	outp32(SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_ADDR(pmctrl_base), hw_en.value | (0b01 << 16));

	/* clear software channel instr and state */
	sf_ch.value = 0;
	sf_ch.reg.apb_sf_instr_clr = 0x1;
	sf_ch.reg.apb_intr_sf_dvfs_clr = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_CH_ADDR(pmctrl_base), sf_ch.value);

	/* software channel command config */
	for (i = 0; i < SW_DVFS_OPT_NUM; i += 2) {
		dpu_pr_debug("dvfs high - low: %#x, %#x",
				cmd[opt_table[new_opt_type][i]].value, cmd[opt_table[new_opt_type][i + 1]].value);

		outp32(SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(pmctrl_base, i / 2),
				(cmd[opt_table[new_opt_type][i]].value << 16) | cmd[opt_table[new_opt_type][i + 1]].value);

		dpu_pr_debug("dvfs cmd-%d: %#x --> %#x \n", i/2, SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(0xFF024000, i / 2),
				inp32(SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(pmctrl_base, i / 2)));
	}

	/* enable software channel */
	sf_ch.value = 0;
	sf_ch.reg.apb_sf_dvfs_en = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_CH_ADDR(pmctrl_base), sf_ch.value);

	i = 0;
	while ((i++ < 45) && ((value & BIT(16)) != BIT(16))) {
		value = inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_RD_ADDR(pmctrl_base));
		dpu_pr_debug("dvfs apb_rd_intr_sf_dvfs_raw_stat = %#x", value);
		udelay(10);
	}

	if ((value & BIT(16)) != BIT(16)) {
		dpu_pr_warn("sw dvfs failed, sw instr: %#x %#x %#x %#x",
			inp32(SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(pmctrl_base, 0)),
			inp32(SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(pmctrl_base, 1)),
			inp32(SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(pmctrl_base, 2)),
			inp32(SOC_MEDIA_PMCTRL_APB_SF_INSTR_LIST_ADDR(pmctrl_base, 3)));
		dpu_pr_warn("curr dvfs level %#x, soft channel stat %#x, hard channel stat %#x",
			inp32(SOC_MEDIA_PMCTRL_PERI_M1_DVS_STAT7_ADDR(pmctrl_base)),
			inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_RD_ADDR(pmctrl_base)),
			inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_RD_ADDR(pmctrl_base)));
		return -1;
	}

	sf_ch.value = 0;
	sf_ch.reg.apb_sf_instr_clr = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_CH_ADDR(pmctrl_base), sf_ch.value);

	return 0;
}

static void dpu_dvfs_hw_channel_cfg(dpu_dvfs_instr *cmd, int cmd_size)
{
	int i = 0;
	char __iomem *pmctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_PMCTRL);
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_CH_UNION hw_ch;
	SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_UNION hw_en;

	dpu_check_and_no_retval(!pmctrl_base, err, "pmctrl_base is NULL!\n");
	dpu_pr_debug("current peri dvfs %#x software channel status %#x hw status %#x",
		inp32(SOC_MEDIA_PMCTRL_PERI_M1_DVS_STAT7_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_RD_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_RD_ADDR(pmctrl_base)));

	hw_ch.value = 0;
	hw_ch.reg.apb_intr_hw_dvfs_clr = 0x1;
	hw_ch.reg.apb_hw_instr_clr = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_CH_ADDR(pmctrl_base), hw_ch.value);

	hw_en.value = 0;
	hw_en.reg.apb_hw_ch_fps_cnt = 0x0;
	outp32(SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_ADDR(pmctrl_base), hw_en.value | (0xE00 << 16));

	for (i = 0; i < cmd_size; i += 2) {
		dpu_pr_debug("dvfs high - low: %#x, %#x", cmd[i].value, cmd[i + 1].value);
		outp32(SOC_MEDIA_PMCTRL_APB_HW_INSTR_LIST_ADDR(pmctrl_base, i / 2),
				(cmd[i].value << 16) | cmd[i + 1].value);
		dpu_pr_debug("dvfs cmd-%d: %#x --> %#x \n", i/2, SOC_MEDIA_PMCTRL_APB_HW_INSTR_LIST_ADDR(0xFF024000, i / 2),
				inp32(SOC_MEDIA_PMCTRL_APB_HW_INSTR_LIST_ADDR(pmctrl_base, i / 2)));
	}

	hw_en.value = 0;
	hw_en.reg.apb_hw_dvfs_enable = 0x1;
	outp32(SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_ADDR(pmctrl_base), hw_en.value | (0b01 << 16));
}

static void prepare_sf_instr(uint32_t vote_level, dpu_dvfs_instr *sf_dvfs_instr, uint32_t sf_instr_count)
{
	if (sf_instr_count > SW_DVFS_OPT_NUM)
		return;

	/* When the frequency is increased, the voltage is increased first,
	 * and then the frequency is decreased.
	 * When the PLL is switched, the DIV is switched first,
	 * and the SW is switched first when the frequency is increased.
	 */
	/* vol crg */
	sf_dvfs_instr[0].cmd.op = 0b0011;
	sf_dvfs_instr[0].cmd.halt = 0b0;
	sf_dvfs_instr[0].cmd.instr = g_vote_info[vote_level].vote_vol;

	/* pll en && pll gt */
	sf_dvfs_instr[1].cmd.op = 0b0110;
	sf_dvfs_instr[1].cmd.halt = 0b0;
	sf_dvfs_instr[1].cmd.instr = g_dvfs_record.is_last_vote_doze1 ? 0b1111 : 0b0111;
	sf_dvfs_instr[2].cmd.op = 0b0111;
	sf_dvfs_instr[2].cmd.halt = 0b0;
	sf_dvfs_instr[2].cmd.instr = g_dvfs_record.is_last_vote_doze1 ? 0b1111 : 0b0111;

	/* clk sw && clk div */
	sf_dvfs_instr[3].cmd.op = CLK_SW_OP;
	sf_dvfs_instr[3].cmd.halt = 0b0;
	sf_dvfs_instr[3].cmd.instr = g_vote_info[vote_level].vote_clk_sel;
	sf_dvfs_instr[4].cmd.op = 0b0101;
	sf_dvfs_instr[4].cmd.halt = 0b0;
	sf_dvfs_instr[4].cmd.instr = g_vote_info[vote_level].vote_clk_div;

	/* pll en && pll gt */
	sf_dvfs_instr[5].cmd.op = 0b0110;
	sf_dvfs_instr[5].cmd.halt = 0b0;
	sf_dvfs_instr[5].cmd.instr = g_vote_info[vote_level].vote_clk_sel;
	sf_dvfs_instr[6].cmd.op = 0b0111;
	sf_dvfs_instr[6].cmd.halt = 0b0;
	sf_dvfs_instr[6].cmd.instr = g_vote_info[vote_level].vote_clk_sel;

	/* end */
	sf_dvfs_instr[7].cmd.op = 0b1111;
	sf_dvfs_instr[7].cmd.halt = 0b0;
	sf_dvfs_instr[7].cmd.instr = 0b0000;
}

static void dpu_sw_dvfs_recovery(char __iomem *pmctrl_base, uint32_t vote_level)
{
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_RD_UNION hw_rd;
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_CH_UNION sf_ch;
	SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_CH_UNION hw_ch;

	dpu_dvfs_instr max_level_instr[SW_DVFS_OPT_NUM];
	dpu_dvfs_instr sf_dvfs_instr[SW_DVFS_OPT_NUM];

	/* sf dvfs has already wait 450us, there is a high probability that the hw dvfs is busy */
	hw_rd.value = inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_RD_ADDR(pmctrl_base));
	if (hw_rd.reg.apb_rd_hw_ch_dvfs_busy == 0)
		return;

	dpu_pr_warn("hw dvfs is busy, hw dvfs state is %#x", hw_rd.value);

	/* sf dvfs exits the process to avoid mis-execution */
	sf_ch.value = 0;
	sf_ch.reg.apb_sf_escape = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_CH_ADDR(pmctrl_base), sf_ch.value);

	/* hw dvfs exits busy status */
	hw_ch.value = 0;
	hw_ch.reg.apb_hw_escape = 0x1;
	outp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_CH_ADDR(pmctrl_base), hw_ch.value);

	/* dvfs status is uncontrollable after exit busy status. to make sure it's right, vote max level */
	prepare_sf_instr(DPU_PERF_LEVEL_MAX, max_level_instr, SW_DVFS_OPT_NUM);
	(void)dpu_dvfs_sw_channel_cfg(pmctrl_base, max_level_instr, SW_DVFS_OPT_NUM, OPT_VOLT_UP_INDEX, DPU_PERF_LEVEL_MAX);

	if (vote_level == DPU_PERF_LEVEL_MAX)
		return;

	/* down to vote level from max level */
	prepare_sf_instr(vote_level, sf_dvfs_instr, SW_DVFS_OPT_NUM);
	(void)dpu_dvfs_sw_channel_cfg(pmctrl_base, sf_dvfs_instr, SW_DVFS_OPT_NUM, OPT_VOLT_DOWN_INDEX, vote_level);

	return;
}

void dpu_sw_dvfs_vote_level(uint32_t vote_level, uint32_t opt_type)
{
	int32_t ret = 0;
	char __iomem *pmctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_PMCTRL);
	dpu_dvfs_instr sf_dvfs_instr[SW_DVFS_OPT_NUM];
	dpu_check_and_no_retval(!pmctrl_base, err, "pmctrl_base is NULL!\n");

	if (vote_level > DPU_PERF_LEVEL_MAX)
		return;

	dpu_pr_debug("dpu_sw_dvfs_vote_level:%d", (uint32_t)g_dvfs_record.is_last_vote_doze1);

	prepare_sf_instr(vote_level, sf_dvfs_instr, SW_DVFS_OPT_NUM);

	ret = dpu_dvfs_sw_channel_cfg(pmctrl_base, sf_dvfs_instr, SW_DVFS_OPT_NUM, (int32_t)opt_type, vote_level);
	if (ret != 0) {
		dpu_pr_info("sw dvfs vote failed, need recovery");
		dpu_sw_dvfs_recovery(pmctrl_base, vote_level);
	}

	g_dvfs_record.is_last_vote_doze1 = false;
}

static void dpu_dvfs_enable(void)
{
	char __iomem *pmctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_PMCTRL);
	char __iomem *media1_crg = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_CRG);
	dpu_check_and_no_retval(!pmctrl_base, err, "pmctrl_base is NULL!\n");
	dpu_check_and_no_retval(!media1_crg, err, "media1_crg is NULL!\n");

	/* hw init */
	dpu_dvfs_peri_init(pmctrl_base);

	/* enable media1 crg dvfs en */
	if (g_debug_dvfs_type == DVFS_INTER_SW_TYPE)
		outp32(SOC_MEDIA1_CRG_DSS_DVFS_ADDR(media1_crg), 0x0);
	else
		outp32(SOC_MEDIA1_CRG_DSS_DVFS_ADDR(media1_crg), 0x1);

	/* init select pll0 and div 0xf for power off by 104M */
	dpu_dvfs_apb_init(pmctrl_base);

	g_dvfs_record.last_vote_type = INTER_VOTE_TYPE;
	g_dvfs_record.inter_cur_vote_level = DPU_CORE_LEVEL_ON;
	g_dvfs_record.intra_cur_vote_level = DPU_CORE_LEVEL_ON;
	g_dvfs_record.intra_prev_vote_level = DPU_CORE_LEVEL_ON;
	g_dvfs_record.inter_effect_level = DPU_CORE_LEVEL_ON;
	g_dvfs_record.is_last_vote_doze1 = false;
	dpu_pr_debug("config is_last_vote_doze1 enable:%d", (uint32_t)g_dvfs_record.is_last_vote_doze1);
}

void dpu_dvfs_disable(void)
{
	char __iomem *media1_crg = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_CRG);
	dpu_check_and_no_retval(!media1_crg, err, "media1_crg is NULL!\n");

	outp32(SOC_MEDIA1_CRG_DSS_DVFS_ADDR(media1_crg), 0x0); // dvfs disable
}

static uint32_t prepare_active_hw_instr(uint32_t perf_level, uint32_t last_level,
	dpu_dvfs_instr *hw_instr, uint32_t hw_instr_count)
{
	uint32_t i = 0;
	int opt_idx = 0;
	struct dvfs_vote_info last_vote_info = { 0 };

	if (perf_level > DPU_PERF_LEVEL_MAX || last_level > DPU_PERF_LEVEL_MAX)
		return 0;

    /* last vote doze1, curr clk is fll */
    last_vote_info = (last_level == DPU_CORE_LEVEL_IDLE && g_dvfs_record.is_last_vote_doze1) ?
	    g_doze1_vote_info : g_vote_info[last_level];

    dpu_pr_debug("prepare_active_hw_instr:%u, %u", last_vote_info.vote_clk_sel, g_vote_info[perf_level].vote_clk_sel);

	dpu_dvfs_instr rise_vol_instr[] = {
		/* vol_cfg 0b0011: 0.8v 0b0010: 0.7v 0b0001: 0.65v 0b0000: 0.6v */
		{ .cmd.op = 0b0011, .cmd.halt = 0b0, .cmd.instr = g_vote_info[perf_level].vote_vol },

		/* pll_en && pll_gt */
		{ .cmd.op = 0b0110, .cmd.halt = 0b0, .cmd.instr = g_dvfs_record.is_last_vote_doze1 ? 0b1111 : 0b0111 },
		{ .cmd.op = 0b0111, .cmd.halt = 0b0, .cmd.instr = g_dvfs_record.is_last_vote_doze1 ? 0b1111 : 0b0111 },

		/* clk sw & clk_div */
		{ .cmd.op = CLK_SW_OP, .cmd.halt = 0b0, .cmd.instr = g_vote_info[perf_level].vote_clk_sel },
		{ .cmd.op = 0b0101, .cmd.halt = 0b0, .cmd.instr = g_vote_info[perf_level].vote_clk_div },

		/* pll_en && pll_gt */
		{ .cmd.op = 0b0110, .cmd.halt = 0b0, .cmd.instr = g_vote_info[perf_level].vote_clk_sel },
		{ .cmd.op = 0b0111, .cmd.halt = 0b0, .cmd.instr = g_vote_info[perf_level].vote_clk_sel },

		/* inter */
		{ .cmd.op = 0b1010, .cmd.halt = 0b0, .cmd.instr = 0b0 },
	};

    /*
	 * OPT_VOLT_UP_INDEX: vol --> pll_en&pll_gt --> clk_sw --> clk_div --> pll_en&pll_gt --> end
	 * OPT_VOLT_DOWN_INDEX: pll_en&pll_gt --> clk_div --> clk_sw --> pll_en&pll_gt --> vol--> end
	 */
	uint32_t opt_table[OPT_VOLT_MAX_INDEX * OPT_VOLT_IDLE_MAX_INDEX][HW_ACTIVE_OPT_NUM] = {
		{ 0, 1, 2, 3, 4, 5, 6, 7 },
		{ 0, 1, 2, 4, 3, 5, 6, 7 },    /* ONLY DOZE1 */

		{ 1, 2, 4, 3, 5, 6, 0, 7 },
		{ 1, 2, 3, 4, 5, 6, 0, 7 }     /* ONLY DOZE1 */
	};

    opt_idx = (perf_level < last_level ? OPT_VOLT_DOWN_INDEX : OPT_VOLT_UP_INDEX) * OPT_VOLT_IDLE_MAX_INDEX;
	if (dpu_dvfs_is_spec_clk_order(g_dvfs_record.is_last_vote_doze1, last_level, perf_level)) {
		opt_idx = opt_idx + 1;
	}

	for (i = 0; i < HW_ACTIVE_OPT_NUM; i++) {
		if (i >= hw_instr_count) {
			return 0;
		}

		hw_instr[i] = rise_vol_instr[opt_table[opt_idx][i]];
	}

	return ARRAY_SIZE(rise_vol_instr);
}

static uint32_t prepare_idle_hw_instr(uint32_t vote_level,
	dpu_dvfs_instr *hw_instr, uint32_t hw_instr_count, bool is_supp_doze1)
{
	uint32_t i = 0;
	uint32_t opt_idx = 0;
	uint32_t opt_temp_count = 0;
	uint32_t wait_doze1_wake_idx = is_supp_doze1 ? 10 : 0xFF;
	/* if doze1 sw FLL:211M */
    struct dvfs_vote_info idle_vote_info = is_supp_doze1 ? g_doze1_vote_info : g_vote_info[DPU_CORE_LEVEL_IDLE];

	if (vote_level > DPU_PERF_LEVEL_MAX)
		return 0;

    dpu_pr_debug("prepare_idle_hw_instr:%u, %u", idle_vote_info.vote_clk_sel, g_vote_info[vote_level].vote_clk_sel);

	dpu_dvfs_instr idle_vol_instr[HW_IDLE_OPT_NUM] = {
		/* wait ov_chg, when ov ycnt configured matching actual line */
		{ .cmd.op = 0b0010, .cmd.halt = 0b0, .cmd.instr = 0b0 },
		/* wait_cht for post processing after wait_ov_chg */
		{ .cmd.op = 0b0001, .cmd.halt = 0b0, .cmd.instr = (DVFS_OV_RESERVE_TIME >> 11)},
		{ .cmd.op = 0b0000, .cmd.halt = 0b0, .cmd.instr = (DVFS_OV_RESERVE_TIME & 0x7ff)},

		/* pll_en && pll_gt */
		{ .cmd.op = 0b0110, .cmd.halt = 0b0, .cmd.instr = g_vote_info[vote_level].vote_clk_sel |
			idle_vote_info.vote_clk_sel },
		{ .cmd.op = 0b0111, .cmd.halt = 0b0, .cmd.instr = g_vote_info[vote_level].vote_clk_sel |
			idle_vote_info.vote_clk_sel },

		/* clk_div & clk sw */
		{ .cmd.op = 0b0101, .cmd.halt = 0b0, .cmd.instr = idle_vote_info.vote_clk_div },
		{ .cmd.op = CLK_SW_OP, .cmd.halt = 0b0, .cmd.instr = idle_vote_info.vote_clk_sel },

		/* pll en & pll gt */
		{ .cmd.op = 0b0110, .cmd.halt = 0b0, .cmd.instr = idle_vote_info.vote_clk_sel },
		{ .cmd.op = 0b0111, .cmd.halt = 0b0, .cmd.instr = idle_vote_info.vote_clk_sel },

		/* vol_cfg */
		{ .cmd.op = 0b0011, .cmd.halt = 0b0, .cmd.instr = idle_vote_info.vote_vol },

		/* wait doze1 wake */
		{ .cmd.op = 0b1001, .cmd.halt = 0b0, .cmd.instr = 0b0 },

        /* inter */
		{ .cmd.op = 0b1010, .cmd.halt = 0b0, .cmd.instr = 0b0 },
	};

	/*
	 * normal|doze1: wait ov_chg&wait_cht --> pll_en&pll_gt --> clk_div --> clk_sw --> pll_en&pll_gt --> vol --> (wait doze1 wake) -- > inter
	 * doze1: wait ov_chg&wait_cht --> pll_en&pll_gt --> clk_sw --> clk_div --> pll_en&pll_gt --> vol --> wait doze1 wake -- > inter
	 */
	uint32_t opt_table[OPT_VOLT_IDLE_MAX_INDEX][HW_IDLE_OPT_NUM] = {
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, wait_doze1_wake_idx, 11 },
		{ 0, 1, 2, 3, 4, 6, 5, 7, 8, 9, wait_doze1_wake_idx, 11 }
	};

	opt_idx = dpu_dvfs_is_spec_clk_order(is_supp_doze1, DPU_CORE_LEVEL_IDLE, vote_level)  ?
	    OPT_VOLT_IDLE_DOZE1_ONLY_INDEX : OPT_VOLT_IDLE_NORMAL_OR_DOZE1_INDEX;

	for (i = 0; i < HW_IDLE_OPT_NUM; i++) {
		if (opt_table[opt_idx][i] == 0xFF) {
			continue;
		}

		if (opt_temp_count >= hw_instr_count) {
			return 0;
		}

		hw_instr[opt_temp_count] = idle_vol_instr[opt_table[opt_idx][i]];
		opt_temp_count++;
	}

	dpu_pr_debug("ov reserve time is %u", DVFS_OV_RESERVE_TIME);

	return opt_temp_count;
}

void dpu_hw_dvfs_vote_level(uint32_t vote_level, uint32_t last_level, bool is_supp_doze1)
{
	uint32_t instr_count = 0;
	uint32_t remain_count = 0;
	uint32_t idle_instr_cnt = 0;
	dpu_dvfs_instr hw_instr[MAX_INSTR_COUNT] = { {0} };

	dpu_pr_debug("perf_levl=%u last perf_level=%u", vote_level, last_level);
	instr_count = prepare_active_hw_instr(vote_level, last_level, hw_instr, MAX_INSTR_COUNT);
	if (instr_count == 0) {
		dpu_pr_err("prepare active instr failed");
		return;
	}

	remain_count = MAX_INSTR_COUNT - instr_count;
	idle_instr_cnt = prepare_idle_hw_instr(vote_level, &(hw_instr[instr_count]), remain_count, is_supp_doze1);
	if (idle_instr_cnt == 0) {
		dpu_pr_err("prepare idle instr failed");
		return;
	}
	instr_count += idle_instr_cnt;

	// If this frame do not need decrease voltage and no idle,
	// hardware channel just wait 5us and do nothing.
	if (instr_count == 0) {
		hw_instr[instr_count].cmd.op = 0b0001;
		hw_instr[instr_count].cmd.halt = 0b0;
		hw_instr[instr_count].cmd.instr = 0x0;
		instr_count++;

		hw_instr[instr_count].cmd.op = 0b0000;
		hw_instr[instr_count].cmd.halt = 0b0;
		hw_instr[instr_count].cmd.instr = 0x5;
		instr_count++;
	}

	/* end */
	hw_instr[instr_count].cmd.op = 0b1111;
	hw_instr[instr_count].cmd.halt = 0b0;
	hw_instr[instr_count].cmd.instr = 0b0000;
	instr_count++;

	dpu_dvfs_hw_channel_cfg(hw_instr, (int32_t)instr_count);
}

static void dpu_dvfs_intra_dvfs(struct intra_frame_dvfs_info *dvfs_info, uint32_t vote_level,
	uint32_t dpu_cur_vote_level, bool is_support_doze1)
{
	uint32_t sw_dvfs_frm_rate = dvfs_info->sw_dvfs_frm_rate;
	uint32_t target_level = vote_level >= dpu_cur_vote_level ? vote_level : dpu_cur_vote_level;
	uint32_t opt_volt_type = vote_level >= dpu_cur_vote_level ? OPT_VOLT_UP_INDEX : OPT_VOLT_DOWN_INDEX;

	if ((g_dvfs_record.cur_frm_rate == sw_dvfs_frm_rate) && (g_dvfs_record.prev_frm_rate == sw_dvfs_frm_rate) &&
		(g_dvfs_record.last_vote_type == INTRA_VOTE_TYPE)) {
		if (dvfs_info->frame_rate == sw_dvfs_frm_rate) {
			// If last 2 frames and cur frame rate equal sw_dvfs_frm_rate(90hz/120hz).
			// Only use sw channel to increase/decrease current voltage directly.
			dpu_sw_dvfs_vote_level(vote_level, opt_volt_type);
			dpu_qos_qic_media1_config(vote_level);
		} else {
			// If last 2 frames equal sw_dvfs_frm_rate(90hz/120hz), and cur frame rate is less than sw_dvfs_frm_rate(90hz/120hz).
			// Use sw channel to increase/decrease current voltage directly.
			dpu_sw_dvfs_vote_level(vote_level, opt_volt_type);

			// prepare hw channel instruct to decrease voltage: frame header and idle
			dpu_hw_dvfs_vote_level(vote_level, target_level, is_support_doze1);
			dpu_qos_qic_media1_config(target_level);
		}
	} else if ((g_dvfs_record.cur_frm_rate >= sw_dvfs_frm_rate || g_dvfs_record.prev_frm_rate >= sw_dvfs_frm_rate) &&
		g_dvfs_record.last_vote_type == INTRA_VOTE_TYPE) {
		// If next frame voltage less current frame voltage.
		// First use sw channel to increase current voltage directly.
		// Then use sw channel to decrease to next frame voltage.
		dpu_sw_dvfs_vote_level(target_level, OPT_VOLT_UP_INDEX);

		// prepare hw channel instruct to decrease voltage: frame header and idle
		dpu_hw_dvfs_vote_level(vote_level, target_level, is_support_doze1);
		dpu_qos_qic_media1_config(target_level);
	} else {
		dpu_hw_dvfs_vote_level(vote_level, dpu_cur_vote_level, is_support_doze1);
		dpu_qos_qic_media1_config(dpu_cur_vote_level);
	}

	// record current intra vote level and status
	if (g_dvfs_record.last_vote_type == INTRA_VOTE_TYPE)
		g_dvfs_record.inter_effect_level = DPU_CORE_LEVEL_ON;
	g_dvfs_record.last_vote_type = INTRA_VOTE_TYPE;
	g_dvfs_record.intra_prev_vote_level = g_dvfs_record.intra_cur_vote_level;
	g_dvfs_record.intra_cur_vote_level = vote_level;
	g_dvfs_record.prev_frm_rate = g_dvfs_record.cur_frm_rate;
	g_dvfs_record.cur_frm_rate = dvfs_info->frame_rate;
	g_dvfs_record.is_last_vote_doze1 = is_support_doze1;
	dpu_pr_debug("config is_last_vote_doze1 hw:%d", (uint32_t)g_dvfs_record.is_last_vote_doze1);
	return;
}

#ifdef DPU_NSV_SCOUT
static uint32_t dpu_map_perf_level(uint32_t vote_level)
{
	if (vote_level == DPU_CORE_FREQ1 || vote_level == DPU_CORE_FREQ2)
		return DPU_CORE_FREQ3;

	return vote_level;
}
#else
static uint32_t dpu_map_perf_level(uint32_t vote_level)
{
	return vote_level;
}
#endif /* DPU_NSV_SCOUT */

void dpu_dvfs_intra_process(struct intra_frame_dvfs_info *dvfs_info, uint32_t vote_level, bool inter_locked, bool is_support_doze1)
{
	uint32_t sw_dvfs_frm_rate;
	uint32_t need_vote_level;
	uint32_t dpu_cur_vote_level;
	uint32_t opt_type;

	if (unlikely(!dvfs_info)) {
		dpu_pr_err("dvfs_info is null\n");
		return;
	}

	dpu_pr_debug("intra dvfs info, last: %u curr: %u",
		g_dvfs_record.intra_cur_vote_level,
		vote_level);

	vote_level = dpu_map_perf_level(vote_level);

	if (inter_locked) {
		dpu_pr_info("cur frame sw dvfs inter_locked is %u", inter_locked);
		if (g_dvfs_record.last_vote_type == INTRA_VOTE_TYPE) {
			// although dpu_cur_vote_level may not the actual effective level here,
			// need_vote_level is sure higher than dpu_cur_vote_level, it must be the boost process
			dpu_cur_vote_level = max_of_three(g_dvfs_record.intra_prev_vote_level, g_dvfs_record.intra_cur_vote_level,
				g_dvfs_record.inter_effect_level);
			need_vote_level = max(vote_level, dpu_cur_vote_level);
		} else {
			dpu_cur_vote_level = g_dvfs_record.inter_effect_level;
			need_vote_level = dpu_cur_vote_level > vote_level ? dpu_cur_vote_level : vote_level;
		}
		// next voltage equal current voltage, also need up instructs.
		opt_type = need_vote_level >= dpu_cur_vote_level ? OPT_VOLT_UP_INDEX : OPT_VOLT_DOWN_INDEX;
		dpu_pr_debug("inter is locked, dpu_cur_vote_level=%u need_vote_level=%u",
			dpu_cur_vote_level, need_vote_level);
		dpu_sw_dvfs_vote_level(need_vote_level, opt_type);
		dpu_qos_qic_media1_config(need_vote_level);
		g_dvfs_record.last_vote_type = INTER_VOTE_TYPE;
		g_dvfs_record.inter_effect_level = need_vote_level;
		g_dvfs_record.intra_prev_vote_level = g_dvfs_record.intra_cur_vote_level;
		g_dvfs_record.intra_cur_vote_level = vote_level;
		g_dvfs_record.is_last_vote_doze1 = false;
		dpu_pr_debug("config is_last_vote_doze1 hw inter locked:%d", (uint32_t)g_dvfs_record.is_last_vote_doze1);
		return;
	}

	sw_dvfs_frm_rate = dvfs_info->sw_dvfs_frm_rate;
	dpu_pr_debug("sw_dvfs_frm_rate = %u", sw_dvfs_frm_rate);

	if (g_dvfs_record.last_vote_type == INTRA_VOTE_TYPE) {
		dpu_cur_vote_level = DPU_CORE_LEVEL_ON;
		if (g_dvfs_record.cur_frm_rate >= sw_dvfs_frm_rate || g_dvfs_record.prev_frm_rate >= sw_dvfs_frm_rate)
			dpu_cur_vote_level = g_dvfs_record.intra_cur_vote_level;
	} else {
		dpu_cur_vote_level = g_dvfs_record.inter_effect_level;
	}

	dpu_pr_debug("g_dvfs_record->prev frm rate=%u", g_dvfs_record.prev_frm_rate);
	dpu_dvfs_intra_dvfs(dvfs_info, vote_level, dpu_cur_vote_level, is_support_doze1);
}

void dpu_dvfs_inter_process(uint32_t vote_level, bool is_inter_invoke)
{
	uint32_t need_vote_level;
	uint32_t dpu_cur_vote_level;
	uint32_t opt_type;

	if (g_debug_dvfs_type == DVFS_INTER_SW_TYPE) {
		dpu_pr_debug("is inter sw type, not need reset vote");
		return;
	}

	vote_level = dpu_map_perf_level(vote_level);

	if (g_dvfs_record.last_vote_type == INTRA_VOTE_TYPE) {
		// although dpu_cur_vote_level may not the actual effective level here,
		// need_vote_level is sure higher than dpu_cur_vote_level, it must be the boost process
		dpu_cur_vote_level = max_of_three(g_dvfs_record.intra_prev_vote_level, g_dvfs_record.intra_cur_vote_level,
			g_dvfs_record.inter_effect_level);
		need_vote_level = max(vote_level, dpu_cur_vote_level);
	} else {
		dpu_cur_vote_level = g_dvfs_record.inter_effect_level;
		need_vote_level =
			max_of_three(vote_level, g_dvfs_record.intra_cur_vote_level, g_dvfs_record.intra_prev_vote_level);
	}

	dpu_pr_debug("vote_level =%u need_vote_level = %u dpu_cur_vote_level=%u",
		vote_level, need_vote_level, dpu_cur_vote_level);

	// next voltage equal current voltage, also need up instructs.
	opt_type = need_vote_level >= dpu_cur_vote_level ? OPT_VOLT_UP_INDEX : OPT_VOLT_DOWN_INDEX;

	dpu_sw_dvfs_vote_level(need_vote_level, opt_type);

	dpu_qos_qic_media1_config(need_vote_level);

	g_dvfs_record.last_vote_type = INTER_VOTE_TYPE;
	g_dvfs_record.inter_effect_level = need_vote_level;
	g_dvfs_record.is_last_vote_doze1 = false;
	dpu_pr_debug("config is_last_vote_doze1 inter:%d", (uint32_t)g_dvfs_record.is_last_vote_doze1);

	if (is_inter_invoke) {
		g_dvfs_record.inter_cur_vote_level = vote_level;
	} else {
		g_dvfs_record.intra_prev_vote_level = g_dvfs_record.intra_cur_vote_level;
		g_dvfs_record.intra_cur_vote_level = vote_level;
	}
}

void dpu_dvfs_direct_process(uint32_t vote_level, bool need_config_qos)
{
	uint32_t dpu_cur_vote_level;
	uint32_t opt_type;

	vote_level = dpu_map_perf_level(vote_level);

	dpu_cur_vote_level = max_of_three(g_dvfs_record.intra_prev_vote_level, g_dvfs_record.intra_cur_vote_level,
		g_dvfs_record.inter_cur_vote_level);

	// next voltage equal current voltage, also need up instructs.
	opt_type = vote_level >= dpu_cur_vote_level ? OPT_VOLT_UP_INDEX : OPT_VOLT_DOWN_INDEX;

	dpu_sw_dvfs_vote_level(vote_level, opt_type);

	if (need_config_qos)
		dpu_qos_qic_media1_config(vote_level);

	g_dvfs_record.last_vote_type = INTER_VOTE_TYPE;
	g_dvfs_record.inter_effect_level = vote_level;
	g_dvfs_record.inter_cur_vote_level = vote_level;
	g_dvfs_record.intra_cur_vote_level = vote_level;
	g_dvfs_record.intra_prev_vote_level = vote_level;
	g_dvfs_record.is_last_vote_doze1 = false;
	dpu_pr_debug("config is_last_vote_doze1 direct:%d", (uint32_t)g_dvfs_record.is_last_vote_doze1);
}

void dpu_legacy_direct_process_power_on(uint32_t vote_level, bool need_config_qos)
{
	dpu_legacy_inter_frame_dvfs_vote(DPU_CORE_LEVEL_ON, need_config_qos);
	dpu_dvfs_direct_process(vote_level, need_config_qos);
}

void dpu_legacy_direct_process_power_off(uint32_t vote_level, bool need_config_qos)
{
	dpu_dvfs_direct_process(vote_level, need_config_qos);
	dpu_legacy_inter_frame_dvfs_vote(vote_level, need_config_qos);
}

bool is_dpu_dvfs_enable(void)
{
	return true;
}

void dpu_qos_qic_media1_config(uint32_t level)
{
	uint32_t perf_level = (g_debug_dpu_qos_enable == 0) ? DPU_PERF_LEVEL_MAX : level;
#if defined(CONFIG_DRMDRIVER)
	/* if debug_dpu_qos_enable == 0, then lock qos config to no limit */
	configure_dss_service_security(DSS_QOS_CONFIG, perf_level, 0, BIG_DPU);
#endif
}

void dpu_sw_dvfs_enable(void)
{
	void_unused(0);
}

void dpu_dvfs_ctrl(char __iomem *dpu_base)
{
	void_unused(dpu_base);
}

/* qos qic-media1 config should follow dvfs level, after regulater is enabled */
void dpu_legacy_inter_frame_dvfs_vote(uint32_t vote_level, bool need_config_qos)
{
	dpu_check_and_no_retval((vote_level > DPU_PERF_LEVEL_MAX), err, "don't support perf level%u!", vote_level);

	dpu_pr_info("config clk rate=%llu vote_level=%u",
		dpu_config_get_core_rate(vote_level), vote_level);

	dpu_config_dvfs_vote_exec(dpu_config_get_core_rate(vote_level));

	if (need_config_qos)
		dpu_qos_qic_media1_config(vote_level);
}

void dpu_legacy_inter_frame_vivo_vote(uint32_t vote_level, bool need_config_qos)
{
	dpu_check_and_no_retval((vote_level > DPU_PERF_LEVEL_MAX), err, "don't support perf level%u!", vote_level);

	dpu_pr_info("config clk rate=%llu vote_level=%u",
		dpu_config_get_vivo_rate(vote_level), vote_level);

	dpu_config_vivo_vote_exec(dpu_config_get_vivo_rate(vote_level));
}

/* when power on or exit idle, dvfs set to low level first to climb quickly,
 * if higher level is needed, dvfs will adjust again
 * qos qic-media1 config should follow dvfs level, after regulater is enabled
 * (1) power on: enable core clk -> dvfs -> enable regulater -> config qic-media1, no need config qos
 * (2) exit idle: enable core clk -> dvfs -> config qic-media1, need config qos
 */
void dpu_enable_core_clock(bool is_power_on)
{
	dpu_pr_debug("+");

	if (g_dpu_config_data.clk_gate_edc == NULL) {
		dpu_pr_err("clk_gate_edc is null!");
		return;
	}

	if (clk_prepare_enable(g_dpu_config_data.clk_gate_edc) != 0) {
		dpu_pr_err("enable clk_gate_edc failed!");
		return;
	}

	if (is_power_on)
		dpu_dvfs_enable();

	dpu_pr_debug("-");
}

void dpu_disable_core_clock(bool is_power_off)
{
	dpu_pr_debug("+");

	if (g_dpu_config_data.clk_gate_edc != NULL)
		clk_disable_unprepare(g_dpu_config_data.clk_gate_edc);

	if (is_power_off)
		dpu_dvfs_disable();
}

void dpu_enable_vivo_clock(bool is_power_on)
{
	void_unused(is_power_on);
	dpu_pr_debug("+");

	if (g_dpu_config_data.clk_gate_dss_vivo == NULL) {
		dpu_pr_err("clk_gate_dss_vivo is null!");
		return;
	}

	if (clk_prepare_enable(g_dpu_config_data.clk_gate_dss_vivo) != 0) {
		dpu_pr_err("enable clk_gate_dss_vivo failed!");
		return;
	}

	dpu_pr_debug("-");
}

void dpu_disable_vivo_clock(void)
{
	dpu_pr_debug("+");

	if (g_dpu_config_data.clk_gate_dss_vivo != NULL)
		clk_disable_unprepare(g_dpu_config_data.clk_gate_dss_vivo);
}

void dpu_print_dvfs_vote_status(void)
{
	char __iomem *pmctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_PMCTRL);
	char __iomem *media1_crg = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_CRG);
	dpu_check_and_no_retval(!pmctrl_base, err, "pmctrl_base is NULL!\n");
	dpu_check_and_no_retval(!media1_crg, err, "media1_crg is NULL!\n");

	dpu_pr_info("DVFS:curr dvfs level %#x, soft channel stat %#x, hard channel stat %#x, freq states %#x",
		inp32(SOC_MEDIA_PMCTRL_PERI_M1_DVS_STAT7_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_SF_RD_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA_PMCTRL_HW_DSS_DVFS_HW_RD_ADDR(pmctrl_base)),
		inp32(SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_ADDR(media1_crg)));
}

void dpu_dvfs_auto_record_freq(void)
{
	uint32_t autodiv = 0;
	char __iomem *media1_crg = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_CRG);
	char __iomem *sctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_SCTRL);
	dpu_check_and_no_retval(!sctrl_base, err, "sctrl_base is NULL!\n");
	dpu_check_and_no_retval(!media1_crg, err, "media1_crg is NULL!\n");

	autodiv = inp32(SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_ADDR(media1_crg));
	set_reg(SOC_SCTRL_SCBAKDATA11_ADDR(sctrl_base), autodiv, 8, 0);
}

void dpu_skip_intra_frame_idle_dvfs(void)
{
	SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_UNION hw_en;
	char __iomem *pmctrl_base = dpu_config_get_ip_base(DISP_IP_BASE_MEDIA1_PMCTRL);
	dpu_check_and_no_retval(!pmctrl_base, err, "pmctrl_base is NULL!\n");

	/* disable hardware channel */
	hw_en.value = 0;
	hw_en.reg.apb_hw_dvfs_enable = 0x0;
	outp32(SOC_MEDIA_PMCTRL_APB_DSS_DVFS_HW_EN_ADDR(pmctrl_base), hw_en.value | (0b01 << 16));
}

uint32_t dpu_get_record_level(void)
{
	if (g_dvfs_record.last_vote_type == INTER_VOTE_TYPE) {
		return g_dvfs_record.inter_cur_vote_level;
	}

	return g_dvfs_record.intra_cur_vote_level;
}

void dpu_dvfs_notify_dacc_doze1_flag(bool is_support_doze1)
{
	char __iomem *dpu_base = NULL;
	if (g_debug_doze1_intra_flag_enable == 0) {
        return;
	}

	dpu_base = dpu_config_get_ip_base(DISP_IP_BASE_DPU);
	if (unlikely(!dpu_base)) {
		dpu_pr_err("dpu_base is null");
		return;
	}

    set_reg(DPU_DVFS_DOZE1_SUPP_ADDR(dpu_base), (uint32_t)is_support_doze1, 1, 0);

	dpu_pr_debug("notify is_supported_doze1=%d", is_support_doze1);
}

uint32_t dpu_vivobus_get_level_from_bandwidth(uint64_t bandwidth)
{
	uint32_t i;
	for (i = DPU_VIVOBUS_LEVEL_OFF; i <= DPU_VIVOBUS_LEVEL_MAX; ++i) {
		if (bandwidth <= s_dpu_vivobus_bandwidth[i])
			return i;
	}
	return DPU_VIVOBUS_LEVEL_MAX;
}
#ifdef CONFIG_DKMD_DEBUG_ENABLE
EXPORT_SYMBOL(dpu_sw_dvfs_vote_level);
EXPORT_SYMBOL(dpu_hw_dvfs_vote_level);
#endif
