/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine ioctl driver
 * Create: 2024/12/23
 */
#include <linux/fs.h>
#include <linux/compat.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#include "hicrypto_ioctl.h"
#include "hicrypto_utils.h"
#include "hicrypto_log.h"
#include "hicrypto_errno.h"
#include "hicrypto_macro.h"
#include "hicrypto_dft.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

#define HICRYPTO_ADB_DEV_NAME        "hicrypto"

static DEFINE_MUTEX(hicrypto_ioctl_lock);

struct hicrypto_ioctl_func_t {
	unsigned int func_id;
	int (*ioctl_func)(unsigned int cmd, unsigned long arg);
};

#define DECLARE_HICRYPTO_IOCTL_FUNC(type, func) 		\
static int ioctl_entry_##func(unsigned int cmd, unsigned long arg)                           	\
{																							 	\
	int ret = -EINVAL;                                                                      	\
	struct type info = {0};                                                                 	\
	if (_IOC_SIZE(cmd) != sizeof(struct type)) {                                                \
		pal_error("error, size_in_cmd=0x%08x, exp=0x%08x\n", _IOC_SIZE(cmd), sizeof(struct type)); \
		return -EINVAL;                                                							\
	}                                                										   \
	mutex_lock(&hicrypto_ioctl_lock);  														\
	ret = copy_from_user(&info, (const void *)arg, sizeof(info));							\
	if (pal_check(ret != 0)) {             														\
		pal_error("[ %s :%d]: cal Failed in copy_from_user ret =0x%x\n",  __func__, __LINE__, ret); \
		goto end_handle;             															\
	}             																				\
	ret = func(&info);             																\
	if (pal_check(ret != 0)) {             														\
		pal_error("[ %s :%d]: cal Failed ret =0x%x\n", __func__, __LINE__, ret);                   \
		goto end_handle;              												            \
	}             																				\
	ret = copy_to_user((void *)arg, &info, sizeof(info));             						   \
	if (pal_check(ret != 0)) {             														\
		pal_error("[ %s :%d]:  cal Failed in copy_to_user ret =0x%x\n", __func__, __LINE__, ret); \
		goto end_handle;             															\
	}             																				\
end_handle:             																		\
	mutex_unlock(&hicrypto_ioctl_lock);    													\
	return ret;             																	\
}

DECLARE_HICRYPTO_IOCTL_FUNC(hicrypto_oem_mac_info, hicrypto_ioctl_oeminfo_mac)
DECLARE_HICRYPTO_IOCTL_FUNC(hicrypto_nve_mac_info, hicrypto_ioctl_nve_mac)
DECLARE_HICRYPTO_IOCTL_FUNC(hicrypt_hash_single_ctx, hicrypto_ioctl_hash)
DECLARE_HICRYPTO_IOCTL_FUNC(hicrypt_cipher_ctx, hicrypto_ioctl_cipher_single)

static const struct hicrypto_ioctl_func_t g_hicrypto_ioctl_tbl[] = {
	{HICRYPTO_AES_CMAC_OEM, ioctl_entry_hicrypto_ioctl_oeminfo_mac},
#if defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) && CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
	{HICRYPTO_AES_CMAC_NVE, ioctl_entry_hicrypto_ioctl_nve_mac},
	{HICRYPTO_HASH, ioctl_entry_hicrypto_ioctl_hash},
	{HICYPTO_CIPHER_SINGLE, ioctl_entry_hicrypto_ioctl_cipher_single},
	{HICRYPTO_DFT_PERF, hicrypto_ioctl_get_perf},
	{HICRYPTO_EN_PERF, hicrypto_ioctl_en_perf},
#endif
};

static long hicrypto_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned int i;
	unused(filp);
	for (i = 0; i < ARRAY_SIZE(g_hicrypto_ioctl_tbl); i++) {
		if (g_hicrypto_ioctl_tbl[i].func_id == cmd && g_hicrypto_ioctl_tbl[i].ioctl_func) {
			return g_hicrypto_ioctl_tbl[i].ioctl_func(cmd, arg);
		}
	}
	pal_error("can not find match cmd:0x%x\n", cmd);
	return -EINVAL;
}

static const struct file_operations g_hicrypto_prof_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = hicrypto_ioctl,
};

int hicrypto_prof_register_cdev(struct hicrypto_device *hdev)
{
	int ret = 0;
	struct device *pdevice = NULL;

	hdev->major = register_chrdev(0, HICRYPTO_ADB_DEV_NAME, &g_hicrypto_prof_fops);
	if (hdev->major < 0) {
		pal_error("hicrypto_prof_register_cdev unable to get major");
		ret = -EFAULT;
		goto dev_major_err;
	}

	mutex_lock(&hicrypto_ioctl_lock);
	hdev->dev_class = class_create(THIS_MODULE, HICRYPTO_ADB_DEV_NAME);
	if (IS_ERR(hdev->dev_class)) {
		pal_error("hicrypto_prof_register_cdev class_create error\n");
		ret = -EFAULT;
		mutex_unlock(&hicrypto_ioctl_lock);
		goto dev_class_err;
	}

	pdevice = device_create(hdev->dev_class, NULL,
			MKDEV((unsigned int)hdev->major, 0), NULL, HICRYPTO_ADB_DEV_NAME);
	if (IS_ERR(pdevice)) {
		pal_error("hicrypto_prof_register_cdev: device_create error\n");
		ret = -EFAULT;
		mutex_unlock(&hicrypto_ioctl_lock);
		goto dev_create_err;
	}

	mutex_unlock(&hicrypto_ioctl_lock);
	pal_error("hicrypto_prof_register_cdev success\n");
	return ret;

dev_create_err:
	class_destroy(hdev->dev_class);
	hdev->dev_class = NULL;

dev_class_err:
	unregister_chrdev(hdev->major, HICRYPTO_ADB_DEV_NAME);
	hdev->major = 0;

dev_major_err:
	return ret;
}

int hicrypto_prof_unregister_cdev(struct hicrypto_device *hdev)
{
	device_destroy(hdev->dev_class, MKDEV((unsigned int)hdev->major, 0));
	class_destroy(hdev->dev_class);
	hdev->dev_class = NULL;
	unregister_chrdev(hdev->major, HICRYPTO_ADB_DEV_NAME);
	hdev->major = 0;
	return 0;
}