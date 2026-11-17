/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: Contexthub 9030 driver, include code related to hardware.
 * Create: 2024-10-8
 */
#ifndef __IODIE__DEV__
#define __IODIE__DEV__

unsigned int iodie_dev_readl(unsigned int module, unsigned int addr);
void iodie_dev_writel(unsigned int module, unsigned int addr, unsigned int val);

void iodie_dev_hiphy_dump(void);
int iodie_dev_hiphy_vote_kernel(unsigned int status);
int iodie_dev_hiphy_vote_boot(unsigned int status);
int iodie_dev_fnpll_enable(void);
void iodie_dev_fnpll_disable(void);
int iodie_dev_clk_cfg(unsigned int op, unsigned int freq);
void iodie_dev_set_hio_availble(bool val);

void iodie_dev_clk_en(unsigned int module);
void iodie_dev_clk_dis(unsigned int module);

unsigned int iodie_dev_lp_status(void);

int get_iodie_dts_status(void);

void intr_hub_irq_recovery(void);
void intr_hub_irq_freeze(void);

#endif

