/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include <linux/delay.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#include <platform_include/see/bl31_smc.h>
#include <aae/soc_dpu_define.h>
#include <soc_media_pmctrl_interface.h>
#include <soc_media1_ctrl_interface.h>
#include <soc_media1_crg_interface.h>

#include "aae_manager.h"
#include "akmd_log.h"
#include "ukmd_utils.h"
#include "aae_exp_power.h"

void aae_power_up(struct aae_manager *aae_mgr)
{
	struct ukmd_reg_state reg_status;
	char __iomem *media1_crg_base = aae_mgr->media1_crg_base;
	char __iomem *media1_ctrl_base = aae_mgr->media1_ctrl_base;
	char __iomem *bisr_ctrl_base = aae_mgr->bisr_ctrl_base;

	aae_pr_info("+");

	/* module mtcmos on */
	set_reg(SOC_MEDIA1_CTRL_MEDIA1_CTRL_MSK1_ADDR(media1_ctrl_base), 0x00020002, 32, 0);
	udelay(100);

	/* module unrst */
	set_reg(SOC_MEDIA1_CRG_PERRSTDIS1_ADDR(media1_crg_base), 0x00000140, 32, 0);

	/* module clk enable */
	set_reg(SOC_MEDIA1_CRG_PEREN1_ADDR(media1_crg_base), 0x00038040, 32, 0);
	udelay(1);

	/* module clk disable */
	set_reg(SOC_MEDIA1_CRG_PERDIS1_ADDR(media1_crg_base), 0x00038040, 32, 0);
	udelay(1);

	// module iso disable
	set_reg((media1_ctrl_base + 0x400), 0x00200000, 32, 0);

	/* memory rempair */
	set_reg((bisr_ctrl_base + 0x30), 0x00400000, 32, 0); // MEDIA1_SUBSYS_ISO
	udelay(400);
	reg_status.bs = 16;
	reg_status.bw = 1;
	reg_status.expected_val = 0x1;
	if (!wait_reg_state(bisr_ctrl_base + 0x5C, &reg_status, 1, 10))
	 	aae_pr_info("wait bus idle set timeout!");

	/* module sd off */
	set_reg(SOC_MEDIA1_CTRL_MEDIA1_CTRL_MSK9_ADDR(media1_ctrl_base), 0x0c800000, 32, 0);
	udelay(1);
	configure_dss_service_security(AAE_SEC_CONFIG, 0 /* not shutdown aae retention */, AAE_SEC_RETENTION_SD, 0);
	udelay(1);

	/* module unrst */
	set_reg(SOC_MEDIA1_CRG_PERRSTDIS1_ADDR(media1_crg_base), 0x000002A0, 32, 0);

	/* module clk enable */
	set_reg(SOC_MEDIA1_CRG_PEREN1_ADDR(media1_crg_base), 0x00038040, 32, 0);

	/* bus idle clear */
	set_reg(SOC_MEDIA1_CTRL_MEDIA1_CTRL_MSK2_ADDR(media1_ctrl_base), 0x00400000, 32, 0);

	reg_status.bs = 6;
	reg_status.bw = 1;
	reg_status.expected_val = 0x0;
	if (!wait_reg_state(SOC_MEDIA1_CTRL_MEDIA1_CTRL_P1_0_ADDR(media1_ctrl_base), &reg_status, 1, 100))
	 	aae_pr_info("wait bus idle set timeout!");

	aae_pr_info("-");
}

void aae_power_down(struct aae_manager *aae_mgr)
{
	struct ukmd_reg_state reg_status;
	char __iomem *media1_crg_base = aae_mgr->media1_crg_base;
	char __iomem *media1_ctrl_base = aae_mgr->media1_ctrl_base;
	char __iomem *bisr_ctrl_base = aae_mgr->bisr_ctrl_base;

	aae_pr_info("+");

	/* bus idle set */
	set_reg(SOC_MEDIA1_CTRL_MEDIA1_CTRL_MSK2_ADDR(media1_ctrl_base), 0x00400040, 32, 0);

	reg_status.bs = 6;
	reg_status.bw = 1;
	reg_status.expected_val = 0x1;
	if (!wait_reg_state(SOC_MEDIA1_CTRL_MEDIA1_CTRL_P1_0_ADDR(media1_ctrl_base), &reg_status, 1, 100))
	 	aae_pr_info("wait bus idle set timeout!");

	/* module clk disable */
	set_reg(SOC_MEDIA1_CRG_PERDIS1_ADDR(media1_crg_base), 0x00038040, 32, 0);
	udelay(1);

	/* module sd off */
	set_reg(SOC_MEDIA1_CTRL_MEDIA1_CTRL_MSK9_ADDR(media1_ctrl_base), 0x0C800C80, 32, 0);
	configure_dss_service_security(AAE_SEC_CONFIG, 0 /* not shutdown aae retention */, AAE_SEC_RETENTION_SD, 0);
	udelay(1);

	/* module iso disable */
	set_reg((media1_ctrl_base + 0x400), 0x00200020, 32, 0);

	/* memory rempair */
	set_reg((bisr_ctrl_base + 0x30), 0x00400040, 32, 0); // MEDIA1_SUBSYS_ISO

	/* module rst */
	set_reg(SOC_MEDIA1_CRG_PERRSTEN1_ADDR(media1_crg_base), 0x000002A0, 32, 0);
	set_reg(SOC_MEDIA1_CRG_PERRSTEN1_ADDR(media1_crg_base), 0x00000140, 32, 0);

	/* module mtcmos off */
	set_reg(SOC_MEDIA1_CTRL_MEDIA1_CTRL_MSK1_ADDR(media1_ctrl_base), 0x00020000, 32, 0);

	aae_pr_info("-");
}