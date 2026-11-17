/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine aead hd interface
 * Create: 2024/04/11
 */
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/sched/mm.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/path.h>
#include <linux/slab.h>

#include <securec.h>

#include "hicrypto_alg_oeminfo_mac.h"
#include "hicrypto_alg_def.h"
#include "hicrypto_inner_mac.h"
#include "hicrypto_alg_hd_mac.h"
#include "hicrypto_alg_hd_km.h"
#include "hicrypto_driver.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_dft.h"
#include "hicrypto_macro.h"

#include "hicrypto_common.h"
#include "hicrypto_regs.h"
#include "hicrypto_dev_chip.h"
#include "hicrypto_dev_data.h"
#include "hicrypto_dev_km.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_register.h"
#include "hicrypto_eng_ctrl.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

#define OEM_IOCTL_FOR_UDK_CMD_ID    0xDFAA
#define OEM_INFO_SERVER_PATH              "/vendor/bin/oeminfo_nvme_server"
#define OEM_INFO_SERVER_PATH_LINUX        "/vendor/bin/oeminfo_nvm_server"
#define OEM_PROCESS_MAX_PATH         32
#define OEM_KEY_SEL                  0
static const char g_oeminfo_path[] = OEM_INFO_SERVER_PATH;
static const char g_oeminfo_path_linux[] = OEM_INFO_SERVER_PATH_LINUX;

#if defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) && CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
static const char g_msptest_path[] = "/vendor/bin/msptest";
#endif

#define OEM_DERIVE_DATA_SIZE         (sizeof(km_derive_label_union) + HISI_SYMM_BLKLEN_AES + sizeof(g_oeminfo_path))

static unsigned char g_non_oeminfo_path[] = {
	0xf3, 0x76, 0xd5, 0xb9, 0xd3, 0xc1, 0x72, 0x73,
	0xe3, 0x77, 0x10, 0x35, 0x2d, 0xc1, 0xf7, 0x92,
	0xd3, 0x13, 0xb5, 0xaf, 0xc4, 0x6a, 0xdf, 0x0a,
	0x31, 0x46, 0xba, 0x24, 0x35, 0x18, 0x90, 0x38,
};

static int hicrypto_oeminfo_mac_check(const struct hi_base_data *salt, const struct hi_base_data *in,
									  struct hi_base_data *out)
{
	if (pal_check(in->size == 0)) {
		pal_error("hicrypto_ioctl_oeminfo_mac check len fail.\n");
		return err_api(ERRCODE_PARAMS);
	}
	if (pal_check(in->size > MAX_OEM_MAC_APP_DIN_SIZE)) {
		pal_error("hicrypto_ioctl_nve_mac check len too big.\n");
		return err_api(ERRCODE_PARAMS);
	}
	if (pal_check(salt->size != HISI_SYMM_BLKLEN_AES))
		return err_api(ERRCODE_PARAMS);

	if (pal_check(out->size < HISI_SYMM_BLKLEN_AES))
		return err_api(ERRCODE_PARAMS);
	return BSP_RET_OK;
}

static int check_mm_struct(struct mm_struct *mm)
{
	if (!mm)
		return -EINVAL;

	if (!mm->exe_file) {
		mmput(mm);
		return -EINVAL;
	}

	return 0;
}

static char *get_proc_dpath(char *path_buffer, int path_len)
{
	char *dpath = NULL;
	struct path base_path = {
		.mnt = NULL,
		.dentry = NULL
	};
	struct mm_struct *mm = NULL;
	struct file *exe_file = NULL;

	if (!path_buffer || path_len != OEM_PROCESS_MAX_PATH) {
		pal_error("hicrypto invalid path_buffer or path_len\n");
		return NULL;
	}

	if (memset_s(path_buffer, (size_t)path_len, '\0', (size_t)OEM_PROCESS_MAX_PATH) != 0) {
		pal_error("hicrypto memset error\n");
		return NULL;
	}

	mm = get_task_mm(current);
	if (check_mm_struct(mm) != 0) {
		pal_error("hicrypto check mm_struct failed\n");
		return NULL;
	}
	exe_file = mm->exe_file;
	base_path.mnt = exe_file->f_path.mnt;
	base_path.dentry = exe_file->f_path.dentry;
	path_get(&base_path);
	dpath = d_path(&base_path, path_buffer, OEM_PROCESS_MAX_PATH);
	path_put(&base_path);
	mmput(mm);

	return dpath;
}

static int hicrypto_oeminfo_get_process_path(char **pro_dpath, char *buf, unsigned int buf_size)
{
	char *dpath = get_proc_dpath(buf, buf_size);
	if (IS_ERR_OR_NULL(dpath)) {
		return -ENOMEM;
	}
	*pro_dpath = dpath;
	return 0;
}

static int hicrypto_oeminfo_gen_derivein(uint32_t cmd, struct hi_base_data *salt,
										 struct hi_base_data *derivein)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	km_derive_label_union oem_label = { 0 };
	unsigned int start_idx = 0;
	unsigned int *pdata = (unsigned int *)derivein->buffer;
	char *process_path = NULL;
	errno_t libc_ret = EINVAL;

	char *path_buffer = kzalloc(sizeof(g_oeminfo_path), GFP_KERNEL);
	if (pal_check(path_buffer == NULL)) {
		ret = err_api(ERRCODE_MEMORY);
		goto end_handle;
	}

	/* add id */
	oem_label.label.module_id = CRYPTO_KEYTYPE_OEM;
	oem_label.label.product_id = PRODUCT_DEFAULT;
	oem_label.label.component_id = CRYPTO_COMPONENT_REE;
	oem_label.label.alg = 0;
	oem_label.label.cmd_id = cmd;

	/* module_id | product_id | component_id | alg */
	pdata[start_idx++] = u32_inv(oem_label.labels[0]);
	/* cmd_id */
	pdata[start_idx++] = u32_inv(oem_label.labels[1]);
	/* reserve 0 */
	pdata[start_idx++] = u32_inv(oem_label.labels[2]);
	/* reserve 0 */
	pdata[start_idx++] = u32_inv(oem_label.labels[3]);
	/* add salt */
	ret = hicrypto_data_copy_from_user(&pdata[start_idx], derivein->size - start_idx * sizeof(unsigned int),
									   salt, 0, salt->size, salt->type);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	start_idx = start_idx + (salt->size) / sizeof(uint32_t);
	libc_ret = hicrypto_oeminfo_get_process_path(&process_path, path_buffer, sizeof(g_oeminfo_path));
	if (pal_check(libc_ret != 0)) {
		pal_error("hicrypto_oeminfo_get_process_path failed\n");
		ret = err_api(ERRCODE_SYS);
		goto end_handle;
	}

	// 路径鉴权，但派生分量和单框架一致
	if (strncmp(process_path, (char *)ptr(g_oeminfo_path_linux), sizeof(g_oeminfo_path_linux)) == 0) {
		libc_ret = memcpy_s(&pdata[start_idx], derivein->size - start_idx * sizeof(uint32_t),
					g_oeminfo_path, strlen(g_oeminfo_path));
	}
#if defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) && CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
	else if (strncmp(process_path, (char *)ptr(g_msptest_path), sizeof(g_msptest_path)) == 0){
		libc_ret = memcpy_s(&pdata[start_idx], derivein->size - start_idx * sizeof(uint32_t),
					g_oeminfo_path, strlen(g_oeminfo_path));
	}
#endif
	else
	{
		pal_error("hicrypto caller process_path = %s\n", process_path);
		libc_ret = memcpy_s(&pdata[start_idx], derivein->size - start_idx * sizeof(uint32_t),
					g_non_oeminfo_path, sizeof(g_non_oeminfo_path));
	}
	ret = libc_mem_cnv_errcode(libc_ret);
	if (pal_check(ret != BSP_RET_OK)){
		goto end_handle;
	}

end_handle:
	if (path_buffer != NULL) {
		kfree(path_buffer);
		path_buffer = NULL;
	}
	return ret;
}

static int hicrypto_oeminfo_km_unreable_derive(struct hicrypto_device *hdev, const struct hi_base_data *derive_in,
											   uint32_t *out_len)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hidev_km km;
	struct hidev_km_derive derive_para;
	unsigned char iv[HISI_SYMM_IVLEN_AES] = {0};

	if (pal_check(out_len == NULL))
		return err_api(ERRCODE_NULL);

	hidev_km_derive_init(&km, &derive_para, SEC_NO, HISI_SYMM_KEYTYPE_KDR);

	km.pdin = derive_in->buffer;
	km.dinlen = derive_in->size;
	km.pivin = iv;
	km.ivinlen = sizeof(iv);
	ret = hidev_km_function(hdev, &km);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	*out_len = KEY_DERIVE_BASIC_OUTLEN;
	return ret;
}

static int hicrypto_oeminfo_aes_cmac_nopad_calc(struct hi_base_data *in,
												struct hi_base_data *out)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hi_mac_req_ctx_inner *smac_req = NULL;
	struct hi_base_data key = { 0 };

	ret = hicrypto_mac_new_ctx(HISI_CIPHER_ALG_AES_CMAC_DERIVE_KEY_NOPAD, &smac_req);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	ret = hicrypto_mac_init(smac_req, HISI_CIPHER_ALG_AES_CMAC_DERIVE_KEY_NOPAD, NULL);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	hi_gen_base(key, NULL, HISI_SYMM_BLKLEN_AES, ADDR_TYPE_KERNEL_VA);
	ret = hicrypto_mac_setkey(smac_req, &key);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* update */
	smac_req->stage = HISI_SYMM_STAGE_UPDATE;
	ret = hicrypto_do_hd_smac_process(smac_req, in, NULL, in->size);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* dofinal */
	smac_req->stage = HISI_SYMM_STAGE_DOFINAL;
	ret = hicrypto_do_hd_smac_process(smac_req, NULL, out, 0);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

end_handle:
	hicrypto_mac_free_ctx(smac_req);
	smac_req = NULL;
	return ret;
}

int hicrypto_oeminfo_mac_process(struct hicrypto_device *hdev, struct hi_base_data *derive_in,
								struct hi_base_data *in, struct hi_base_data *out)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	int temp_ret = err_api(ERRCODE_UNKNOWN);
	uint32_t out_len = HISI_SYMM_BLKLEN_AES;

	if (pal_check(hdev->km_valid_flag == HISI_KM_VALID_UNINIT)) {
		pal_error("hicrypto km is not ready.\n");
		return err_api(ERRCODE_NOREADY);
	}
	if (pal_check(hdev->km_valid_flag != HISI_KM_VALID_EN)) {
		pal_error("hicrypto km is not available.\n");
		return err_api(ERRCODE_UNSUPPORT);
	}
	ret = hicrypto_km_kdr_derive_check(hdev);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	ret = hicrypto_oeminfo_km_unreable_derive(hdev, derive_in, &out_len);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	if (pal_check(out_len != HISI_SYMM_BLKLEN_AES)){
		ret = err_api(ERRCODE_PARAMS);
		goto end_handle;
	}

	ret = hicrypto_oeminfo_aes_cmac_nopad_calc(in, out);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	if (pal_check(out->size != HISI_SYMM_BLKLEN_AES)){
		ret = err_api(ERRCODE_PARAMS);
		goto end_handle;
	}
end_handle:
	temp_ret = hidev_km_clear_derive_key_by_id(hdev, OEM_KEY_SEL);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	else
		return temp_ret;
}

int hicrypto_oeminfo_mac(struct hicrypto_oem_mac_info *info)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	int ret_temp = err_api(ERRCODE_UNKNOWN);
	struct hi_base_data salt = {0};
	struct hi_base_data in = {0};
	struct hi_base_data out = {0};
	unsigned char *derive_data = NULL;
	struct hi_base_data derive_in = {0};
	struct hicrypto_device *hdev = NULL;

	hi_gen_base(salt, info->salt, info->salt_len, ADDR_TYPE_USER_VA);
	hi_gen_base(in, info->in, info->in_len, ADDR_TYPE_USER_VA);
	hi_gen_base(out, info->out, info->out_len, ADDR_TYPE_USER_VA);

	/* 参数检查: hicrypto_oeminfo_mac_check */
	ret = hicrypto_oeminfo_mac_check(&salt, &in, &out);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	derive_data = (unsigned char *)kzalloc(OEM_DERIVE_DATA_SIZE, GFP_KERNEL);
	if (pal_check(derive_data == NULL))
		return err_api(ERRCODE_MEMORY);

	hi_gen_base(derive_in, derive_data, OEM_DERIVE_DATA_SIZE, ADDR_TYPE_KERNEL_VA);
	/* 根据cmd+进程路径+盐值+oem派生id+默认产品形态和组件值拼接派生分量: hicrypto_oeminfo_gen_derivein */
	ret = hicrypto_oeminfo_gen_derivein(OEM_IOCTL_FOR_UDK_CMD_ID, &salt, &derive_in);
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

end_handler:
	ret_temp = libc_mem_cnv_errcode(memset_s(derive_data, NVE_DERIVE_DATA_SIZE, 0, NVE_DERIVE_DATA_SIZE));
	if(pal_check(ret_temp != BSP_RET_OK))
		pal_error("hicrypto memset_s fail, ret = %d\n", ret_temp);
	kfree(derive_data);
	derive_data = NULL;
	return ret == BSP_RET_OK ? ret_temp : ret;
}