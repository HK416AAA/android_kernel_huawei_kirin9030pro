/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine aead hd interface
 * Create: 2024/04/11
 */
#include <linux/slab.h>

#include "hicrypto_inner_mac.h"
#include "hicrypto_alg_def.h"
#include "hicrypto_driver.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_dft.h"
#include "hicrypto_macro.h"
#include "hicrypto_io.h"
#include "hicrypto_eng_ctrl.h"
#include "hicrypto_dev_data.h"

#include "platform_include/see/hicrypto_engine.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

#define UDK_HICRYPTO_PROXY_MAJOR_CMD  11
#define HICRYPTO_NVE_MAC_CMD          0
#define HICRYPTO_NVE_KEY_SEL          0

// 0xB0000
#define NVE_LDK_FOR_UDK_CMD_ID (((((UDK_HICRYPTO_PROXY_MAJOR_CMD) & 0xFFFF) << 16)) | ((HICRYPTO_NVE_MAC_CMD) & 0xFFFF))

static int hicrypto_nve_aes_cmac_check(const struct hi_base_data *salt, const struct hi_base_data *data_in,
									   struct hi_base_data *data_out)
{
	if (pal_check((unsigned char *)ptr(salt->buffer) == NULL || (unsigned char *)ptr(data_in->buffer) == NULL ||
				  (unsigned char *)ptr(data_out->buffer) == NULL))
		return err_api(ERRCODE_NULL);

	if (pal_check(salt->size != HISI_SYMM_BLKLEN_AES))
		return err_api(ERRCODE_PARAMS);

	if (pal_check(data_out->size < HISI_SYMM_BLKLEN_AES))
		return err_api(ERRCODE_PARAMS);

	if (pal_check(data_in->size == 0 || data_in->size > MAX_OEM_MAC_APP_DIN_SIZE))
		return err_api(ERRCODE_PARAMS);

	return BSP_RET_OK;
}

static int hicrypto_nve_gen_derivein(uint32_t cmd, struct hi_base_data *salt,
									 struct hi_base_data *derivein)
{
	unsigned int start_idx = 0;
	unsigned int *pdata = (unsigned int *)derivein->buffer;
	int ret = err_api(ERRCODE_UNKNOWN);
	km_derive_label_union nve_label = { 0 };

	nve_label.label.module_id = CRYPTO_KEYTYPE_NVE;
	nve_label.label.product_id = PRODUCT_DEFAULT;
	nve_label.label.component_id = CRYPTO_COMPONENT_REE;
	nve_label.label.alg = 0;
	nve_label.label.cmd_id = cmd;

	/* module_id | product_id | component_id | alg */
	pdata[start_idx++] = u32_inv(nve_label.labels[0]);
	/* cmd_id */
	pdata[start_idx++] = u32_inv(nve_label.labels[1]);
	/* reserve 0 */
	pdata[start_idx++] = u32_inv(nve_label.labels[2]);
	/* reserve 0 */
	pdata[start_idx++] = u32_inv(nve_label.labels[3]);

	/* add salt */
	ret = hicrypto_data_copy_from_user(&pdata[start_idx], derivein->size - start_idx * sizeof(unsigned int),
									   salt, 0, salt->size, salt->type);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	return ret;
}

int hicrypto_nve_mac(struct hicrypto_nve_mac_info *info)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	int ret_temp = err_api(ERRCODE_UNKNOWN);
	struct hicrypto_device *hdev = NULL;
	struct hi_base_data salt = {0};
	struct hi_base_data in = {0};
	struct hi_base_data out = {0};
	struct hi_base_data derive_in = {0};
	unsigned char *derive_data = NULL;

	if (pal_check(info == NULL))
		return err_api(ERRCODE_PARAMS);

	hi_gen_base(salt, info->salt, info->salt_len, ADDR_TYPE_KERNEL_VA);
	hi_gen_base(in, info->in, info->in_len, ADDR_TYPE_KERNEL_VA);
	hi_gen_base(out, info->out, info->out_len, ADDR_TYPE_KERNEL_VA);

	/* 参数检查: hicrypto_nve_mac_check */
	ret = hicrypto_nve_aes_cmac_check(&salt, &in, &out);
	if (pal_check(ret != BSP_RET_OK))
		return err_api(ERRCODE_PARAMS);

	derive_data = (unsigned char *)kzalloc(NVE_DERIVE_DATA_SIZE, GFP_KERNEL);
	if (pal_check(!derive_data))
		return err_api(ERRCODE_MEMORY);

	hi_gen_base(derive_in, derive_data, NVE_DERIVE_DATA_SIZE, ADDR_TYPE_KERNEL_VA);
	/* 根据cmd+盐值+nve派生id+默认产品形态和组件值拼接派生分量: hicrypto_nve_gen_derivein */
	ret = hicrypto_nve_gen_derivein(NVE_LDK_FOR_UDK_CMD_ID, &salt, &derive_in);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handler;

	/* 获取驱动设备信息: hicrypto_find_dev */
	hdev = hicrypto_find_dev(&hdev);
	if (pal_check(hdev == NULL)) {
		ret = err_api(ERRCODE_NOREADY);
		goto end_handler;
	}

	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_oeminfo_mac_process(hdev, &derive_in, &in, &out));
	if (pal_check(ret != BSP_RET_OK))
		goto end_handler;
	ret = 0;
end_handler:
	ret_temp = memset_s(derive_data, NVE_DERIVE_DATA_SIZE, 0, NVE_DERIVE_DATA_SIZE);
	if(pal_check(ret_temp != 0))
		pal_error("hicrypto memset_s fail, ret = %d\n", ret_temp);
	kfree(derive_data);
	derive_data = NULL;
	return ret == 0 ? ret_temp : ret;
}
