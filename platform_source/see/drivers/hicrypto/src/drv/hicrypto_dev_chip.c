/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine chip define
 * Create: 2024/01/27
 */
#include <asm/io.h>

#include "hicrypto_driver.h"
#include "hicrypto_common.h"
#include "hicrypto_dev_chip.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

int hicrypto_reserved_mmap(struct hicrypto_device *hdev)
{
	hdev->reserved_vir_basei = ioremap_wc(hdev->reserved_phy_base, hdev->reserved_size);
	if (!hdev->reserved_vir_basei) {
			pr_err("hicrypto ree ioremap_wc failed\n");
			return -ENOMEM;
	}

	hdev->reserved_vir_baseo = hdev->reserved_vir_basei + (hdev->reserved_size >> 1);
	pr_err("hicrypto reserved vir_base =%llx, vir_bo=%llx, size=%x\n",
		   hdev->reserved_vir_basei,
		   hdev->reserved_vir_baseo,
		   hdev->reserved_size);
	return 0;
}
