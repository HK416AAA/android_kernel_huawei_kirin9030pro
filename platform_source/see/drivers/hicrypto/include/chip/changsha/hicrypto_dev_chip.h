/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine chip define
 * Create: 2024/01/27
 */
#ifndef __HICRYPTO_DEV_CHIP_H__
#define __HICRYPTO_DEV_CHIP_H__

#include "hicrypto_dev_data.h"
#include "hicrypto_driver.h"
#include "hicrypto_regs.h"
#include "hicrypto_alg_def.h"
#include "hicrypto_macro.h"
#include "hicrypto_io.h"

static inline void hisi_reg_sce_tx_gid(struct hicrypto_device *hdev, unsigned int onoff)
{
#ifdef CONFIG_CRYPTO_HICRYPTO_V2_SYS_CACHE
	if (SEC_ON == onoff) {
		unsigned int value = pal_read_u32(ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AW_SIDEBAND1));
		value = value | HISI_CFG_AW_CACHE |HISI_CFG_AWR_DOMAIN;
		pal_write_u32(value, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AW_SIDEBAND1));
	} else {
		pal_write_u32(0, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AW_SIDEBAND1));
	}
#else
	unused(hdev);
	unused(onoff);
	pal_write_u32(0, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AW_SIDEBAND1));
	return;
#endif
}

static inline void hisi_reg_sce_rx_gid(struct hicrypto_device *hdev, unsigned int onoff)
{
#ifdef CONFIG_CRYPTO_HICRYPTO_V2_SYS_CACHE
	if (SEC_ON == onoff) {
		unsigned int value = pal_read_u32(ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AR_SIDEBAND1));
		value = value | HISI_CFG_AR_CACHE | HISI_CFG_AWR_DOMAIN;
		pal_write_u32(value, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AR_SIDEBAND1));
	} else {
		pal_write_u32(0, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AR_SIDEBAND1));
	}
#else
	unused(hdev);
	unused(onoff);
	pal_write_u32(0, ptr_add(ptr_to_ulong(hdev->cfg_base), HISI_CFG_OFF_AR_SIDEBAND1));
	return;
#endif
}

int hicrypto_reserved_mmap(struct hicrypto_device *hdev);
#endif /* __HICRYPTO_DEV_CHIP_H__ */