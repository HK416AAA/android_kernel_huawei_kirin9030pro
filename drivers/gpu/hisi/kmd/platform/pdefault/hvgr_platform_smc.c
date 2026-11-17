/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include "hvgr_platform_api.h"

uint64_t __attribute__((weak)) hvgr_platform_protected_cfg(struct hvgr_device *gdev, u32 mode)
{
	return 0;
}

int __attribute__((weak)) hvgr_platform_smmu_tcu_on(struct hvgr_device *gdev)
{
	return 0;
}

int __attribute__((weak)) hvgr_platform_smmu_tcu_off(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_smmu_set_sid(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_smmu_tbu_connect(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_smmu_tbu_disconnect(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_smmu_bypass(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_sec_cfg(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_set_mode(struct hvgr_device *gdev)
{
	return 0;
}

uint64_t __attribute__((weak)) hvgr_platform_set_qos(struct hvgr_device *gdev)
{
	return 0;
}
