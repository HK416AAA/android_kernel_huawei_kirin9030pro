/******************************************************************
 * Copyright    Copyright (c) 2020- Hisilicon Technologies CO., Ltd.
 * File name    pcie_com.h
 * Description:
 *
 * Version      1.0
 ******************************************************************/

#ifndef __PCIE_COM_H_INCLUDED__
#define __PCIE_COM_H_INCLUDED__

#include <linux/pci.h>

struct isp_pcie_cfg {
	struct pci_dev *isp_pci_dev;
	void __iomem *isp_pci_reg;
	unsigned int isp_pci_addr;
	unsigned int isp_pci_size;
	unsigned int isp_pci_irq;
	unsigned int isp_pci_inuse_flag;
	unsigned int isp_pci_ready;
};

int hisp_check_pcie_stat(void);
struct pci_dev *hisp_get_pcie_dev(void);
struct isp_pcie_cfg *hisp_get_pcie_cfg(void);
#ifdef CONFIG_HISP_FFA_SUPPORT
extern int hisp_ffa_media2_power_up(void);
extern int hisp_ffa_media2_power_down(void);
#endif

#endif
