/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash hd interface
 * Create: 2024/04/11
 */
#include "hicrypto_alg_hd_cipher.h"
#include "hicrypto_alg_hd_api.h"
#include "hicrypto_inner_standard.h"

#include "hicrypto_driver.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_dft.h"
#include "hicrypto_regs.h"

#include "hicrypto_common.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_eng_ctrl.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static int hicrypto_skcipher_dev_prepare_param(struct hi_skcipher_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int in_num,
	struct hi_base_data *out, struct hisi_dev_symm_data_proc *pdrv_cfg,
	struct hisi_dev_cipher_param *pcipher_param,
	struct hisi_drv_symm_sg_list_info *plist_info)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hi_data_addr data = { 0 };
	struct hi_data_addr data_in = { 0 };

	/* drv cipher para */
	pcipher_param->keytype = ctx->keytype;
	pcipher_param->pkey = ctx->key;
	pcipher_param->algorithm = ctx->alg;
	pcipher_param->mode = ctx->mode;
	pcipher_param->direction = ctx->dir;
	pcipher_param->keylen = ctx->keylen;
	pcipher_param->padding_en = HISI_SCE_REG_PADDING_ENABLE;

	/* drv cfg para */
	pdrv_cfg->rxmode = HISI_SYMM_TRANSFER_LIST;
	pdrv_cfg->txmode = HISI_SYMM_TRANSFER_LIST;

	pdrv_cfg->pivin = ctx->iv;
	pdrv_cfg->ivinlen = ctx->iv_len;

	data.addr.cpu_addr = out->buffer;
	data.len = ctx->crypto_len;
	data.type = out->type;
	pdrv_cfg->pdout[0] = data;
	pdrv_cfg->dout_num = 1;
	pdrv_cfg->outlen = ctx->crypto_len;

	if (in_num == 1) {
		data_in.addr.cpu_addr = in->buffer;
		data_in.len = ctx->crypto_len;
		data_in.type = in->type;
		pdrv_cfg->pdin[0] = data_in;
		pdrv_cfg->din_num = 1;
	} else {
			hi_gen_data(data_in, in[0].buffer, in[0].size, in[0].type);
			pdrv_cfg->pdin[0] = data_in;
			hi_gen_data(data_in, in[1].buffer, in[1].size, in[1].type);
			pdrv_cfg->pdin[1] = data_in;
			pdrv_cfg->din_num = 2;	
	}
	pdrv_cfg->inlen = ctx->crypto_len;

	pdrv_cfg->pivout = ctx->iv;
	pdrv_cfg->ivoutlen = ctx->iv_len;

	/* gen list info */
	ret = hisi_dev_symm_build_hwaddr(ctx->hdev, pdrv_cfg, plist_info);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

static int hicrypto_do_hd_cipher_processs(struct hi_skcipher_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int in_num,
					  struct hi_base_data *out, unsigned int cryptolen)
{
	struct hisi_dev_cipher_param cipher_param = { 0 };
	struct hisi_dev_symm_data_proc drv_symm_data = { 0 };
	struct hisi_drv_symm_sg_list_info drv_list_info = { 0 };
	int ret = err_api(ERRCODE_UNKNOWN);
	int ret_temp = err_api(ERRCODE_UNKNOWN);
	if (pal_check(in->buffer == NULL || out->buffer == NULL || (in->size != cryptolen && in_num == 1) || out->size < cryptolen))
		return err_api(ERRCODE_PARAMS);

	/* prepare dev parameter */
	ctx->crypto_len = cryptolen;
	ret = hicrypto_skcipher_dev_prepare_param(ctx, in, in_num, out, &drv_symm_data, &cipher_param, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* cal dev process */
	ret = hisi_dev_cipher_main(ctx->hdev, &drv_symm_data, &cipher_param, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
	out->size = cryptolen;
	ret = hisi_dev_symm_tx_out_process(ctx->hdev, &drv_symm_data, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
end_handle:
	/* clean parameter */
	ret_temp = hisi_dev_symm_clean_workspace(&drv_symm_data, &drv_list_info);
	if (pal_check(ret_temp != BSP_RET_OK))
		pal_error("clean workspace fail ret =%x", ret_temp);
	return ret == BSP_RET_OK ? ret_temp : ret;
}

int hicrypto_hd_cipher_encrypt(struct hi_skcipher_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
			       unsigned int cryptolen)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_cipher_processs(ctx, in, 1, out, cryptolen));

	return ret;
}

int hicrypto_hd_cipher_decrypt(struct hi_skcipher_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
			       unsigned int cryptolen)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);

	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_cipher_processs(ctx, in, 1, out, cryptolen));

	return ret;
}