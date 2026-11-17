/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash hd interface
 * Create: 2024/04/18
 */
#include <linux/mm.h>
#include <linux/slab.h>

#include <securec.h>

#include "hicrypto_alg_hd_mac.h"
#include "hicrypto_dev_hash.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_inner_standard.h"
#include "hicrypto_inner_hash.h"
#include "hicrypto_alg_hd_hash.h"
#include "hicrypto_driver.h"

#include "hicrypto_io.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_dft.h"
#include "hicrypto_common.h"
#include "hicrypto_eng_ctrl.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static int hicrypto_hd_hmac_cpy_ctx(struct hi_mac_req_ctx_inner *hmac_ctx, struct hi_hash_req_ctx_inner *hash_ctx)
{
	hmac_ctx->alg = hash_ctx->alg;
	hmac_ctx->flags = hash_ctx->flags;

	hmac_ctx->hdev = hash_ctx->hdev;

	/* up final digest */
	hmac_ctx->stage = hash_ctx->stage;

	hmac_ctx->cur_process_bytes = hash_ctx->cur_process_bytes; /* cur process bytes in blknum * blklen */
	hmac_ctx->cur_remain_bytes = hash_ctx->cur_remain_bytes;   /* cur remain bytes */
	hmac_ctx->total_bytes = hash_ctx->total_bytes;		   /* processed total len bytes */
	hmac_ctx->un_processed_len = hash_ctx->un_processed_len;
	(void)memcpy_s(hmac_ctx->un_processed_buf, sizeof(hmac_ctx->un_processed_buf), hash_ctx->un_processed_buf,
		       sizeof(hash_ctx->un_processed_buf));

	(void)memcpy_s(hmac_ctx->digest, sizeof(hmac_ctx->digest), hash_ctx->digest, sizeof(hash_ctx->digest));

	hmac_ctx->digest_len = hash_ctx->digest_len;
	hmac_ctx->iv_len = hash_ctx->iv_len;
	hmac_ctx->blk_len = hash_ctx->blk_len;
	return BSP_RET_OK;
}

static int hicrypto_hd_hash_cpy_ctx(struct hi_mac_req_ctx_inner *hmac_ctx, struct hi_hash_req_ctx_inner *hash_ctx)
{
	hash_ctx->alg = hmac_ctx->alg;
	hash_ctx->flags = hmac_ctx->flags;

	hash_ctx->hdev = hmac_ctx->hdev;

	/* up final digest */
	hash_ctx->stage = hmac_ctx->stage;

	hash_ctx->cur_process_bytes = hmac_ctx->cur_process_bytes; /* cur process bytes in blknum * blklen */
	hash_ctx->cur_remain_bytes = hmac_ctx->cur_remain_bytes;   /* cur remain bytes */
	hash_ctx->total_bytes = hmac_ctx->total_bytes;		   /* processed total len bytes */
	hash_ctx->un_processed_len = hmac_ctx->un_processed_len;

	(void)memcpy_s(hash_ctx->un_processed_buf, sizeof(hash_ctx->un_processed_buf), hmac_ctx->un_processed_buf,
		       sizeof(hmac_ctx->un_processed_buf));

	(void)memcpy_s(hash_ctx->digest, sizeof(hash_ctx->digest), hmac_ctx->digest, sizeof(hmac_ctx->digest));

	hash_ctx->digest_len = hmac_ctx->digest_len;
	hash_ctx->iv_len = hmac_ctx->iv_len;
	hash_ctx->blk_len = hmac_ctx->blk_len;
	return BSP_RET_OK;
}

static int hicrypto_hd_hmac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int blklen, i;
	struct hi_hash_req_ctx_inner *opad_ctx = NULL;
	struct hi_hash_req_ctx_inner *ipad_ctx = NULL;
	struct hi_base_data out = { 0 };
	unsigned char *ppad = NULL;
	unsigned char *pkey_tmp = NULL;

	opad_ctx = (struct hi_hash_req_ctx_inner *)ctx->__ctx;
	if (pal_check(ctx->ext_ctx_size != sizeof(struct hi_hash_req_ctx_inner)))
		return err_api(ERRCODE_PARAMS);

	ppad = (unsigned char *)kmalloc(HISI_SYMM_BLKLEN_HASH_SHA512, GFP_KERNEL);
	if (pal_check(ppad == NULL))
		return err_api(ERRCODE_MEMORY);
	(void)memset_s(ppad, HISI_SYMM_BLKLEN_HASH_SHA512, 0x0, HISI_SYMM_BLKLEN_HASH_SHA512);

	pkey_tmp = (unsigned char *)kmalloc(HISI_SYMM_BLKLEN_HASH_SHA512, GFP_KERNEL);
	if (pal_check(pkey_tmp == NULL))
		goto end_handle;
	(void)memset_s(pkey_tmp, HISI_SYMM_BLKLEN_HASH_SHA512, 0x0, HISI_SYMM_BLKLEN_HASH_SHA512);

	/* keys longer than blklen are first hashed */
	blklen = symm_get_blklen(ctx->alg);
	if (key->size > blklen) {
		out.buffer = pkey_tmp;
		out.size = HISI_SYMM_BLKLEN_HASH_SHA512;
		out.type = ADDR_TYPE_KERNEL_VA;
		ret = hicrypto_hd_hash_digest(opad_ctx, hi_hash_id_build(ctx->alg), key, &out, key->size);
	} else {
		ret = hicrypto_data_copy_from_user(pkey_tmp, HISI_SYMM_BLKLEN_HASH_SHA512, key, 0, key->size, key->type);
	}
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* ipad key 0x36 is magic num for ikey pad */
	for (i = 0; i < byte2word(blklen); i++)
		((unsigned int *)ppad)[i] = ((unsigned int *)pkey_tmp)[i] ^ 0x36363636;

	/* update ipad key */
	ipad_ctx = opad_ctx;
	ret = hicrypto_hash_init(ipad_ctx, hi_hash_id_build(ctx->alg));
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	out.buffer = ppad;
	out.size = blklen;
	out.type = ADDR_TYPE_KERNEL_VA;
	ipad_ctx->stage = HISI_SYMM_STAGE_UPDATE;

	ret = hicrypto_do_hd_hash_procss(ipad_ctx, &out, NULL, blklen);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* cpy ipad ctx to hmac ctx */
	(void)hicrypto_hd_hmac_cpy_ctx(ctx, ipad_ctx);

	/* opad key 0x5c is magic num for okey pad */
	for (i = 0; i < byte2word(blklen); i++)
		((unsigned int *)ppad)[i] = ((unsigned int *)pkey_tmp)[i] ^ 0x5c5c5c5c;

	/* update opad key */
	ret = hicrypto_hash_init(opad_ctx, hi_hash_id_build(ctx->alg));
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	out.buffer = ppad;
	out.size = blklen;
	out.type = ADDR_TYPE_KERNEL_VA;
	opad_ctx->stage = HISI_SYMM_STAGE_UPDATE;
	ret = hicrypto_do_hd_hash_procss(opad_ctx, &out, NULL, blklen);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
end_handle:
	if (pkey_tmp != NULL) {
		(void)memset_s(pkey_tmp, HISI_SYMM_BLKLEN_HASH_SHA512, 0x0, HISI_SYMM_BLKLEN_HASH_SHA512);
		kfree(pkey_tmp);
		pkey_tmp = NULL;
	}
	if (ppad != NULL) {
		(void)memset_s(ppad, HISI_SYMM_BLKLEN_HASH_SHA512, 0x0, HISI_SYMM_BLKLEN_HASH_SHA512);
		kfree(ppad);
		ppad = NULL;
	}

	return ret;
}

int hicrypto_hd_mac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret;

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	if (pal_check(ctx->mode != HASH_OPS_HMAC || key == NULL || key->buffer == NULL || key->size == 0))
		return err_api(ERRCODE_PARAMS);

	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_hd_hmac_setkey(ctx, key));

	return ret;
}

int hicrypto_do_hd_hmac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	int temp_ret = err_api(ERRCODE_UNKNOWN);
	struct hi_hash_req_ctx_inner *pipad_ctx = NULL;

	ret = hicrypto_hash_new_ctx(hi_hash_id_build(ctx->alg), &pipad_ctx);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	/* copy hmac ctx to ipad hash ctx */
	ret = hicrypto_hd_hash_cpy_ctx(ctx, pipad_ctx);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	pipad_ctx->stage = HISI_SYMM_STAGE_UPDATE;
	ret = hicrypto_do_hd_hash_procss(pipad_ctx, in, NULL, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* copy ipad hash ctx to  hmac ctx */
	ret = hicrypto_hd_hmac_cpy_ctx(ctx, pipad_ctx);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
end_handle:
	temp_ret = hicrypto_hash_free_ctx(pipad_ctx);
	if (pal_check(temp_ret != BSP_RET_OK))
		pal_error("hd_hmac update free hash ctx failed\n");
	return ret == BSP_RET_OK ? temp_ret : ret;
}

int hicrypto_do_hd_hmac_dofinal(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *out, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	int temp_ret = err_api(ERRCODE_UNKNOWN);
	struct hi_hash_req_ctx_inner *pipad_ctx = NULL;
	struct hi_hash_req_ctx_inner *opad_ctx = NULL;
	struct hi_base_data out_ipad = { 0 };
	unsigned int dslen = 0;
	unsigned char *pout_tmp = NULL;

	unused(nbytes);
	if (pal_check(ctx->ext_ctx_size != sizeof(struct hi_hash_req_ctx_inner)))
		return err_api(ERRCODE_PARAMS);

	pout_tmp = (unsigned char *)kmalloc(HISI_SYMM_BLKLEN_HASH_SHA512, GFP_KERNEL);
	if (pal_check(pout_tmp == NULL))
		return err_api(ERRCODE_MEMORY);
	(void)memset_s(pout_tmp, HISI_SYMM_BLKLEN_HASH_SHA512, 0x0, HISI_SYMM_BLKLEN_HASH_SHA512);

	/* cal ipad dofinal */
	dslen = ctx->digest_len;
	ret = hicrypto_hash_new_ctx(hi_hash_id_build(ctx->alg), &pipad_ctx);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* copy hmac ctx to ipad hash ctx */
	ret = hicrypto_hd_hash_cpy_ctx(ctx, pipad_ctx);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	out_ipad.buffer = pout_tmp;
	out_ipad.size = HISI_SYMM_BLKLEN_HASH_SHA512;
	out_ipad.type = ADDR_TYPE_KERNEL_VA;
	pipad_ctx->stage = HISI_SYMM_STAGE_DOFINAL;
	ret = hicrypto_do_hd_hash_procss(pipad_ctx, NULL, &out_ipad, 0);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* cal opad dofinal */
	opad_ctx = (struct hi_hash_req_ctx_inner *)ctx->__ctx;
	opad_ctx->stage = HISI_SYMM_STAGE_UPDATE;
	ret = hicrypto_do_hd_hash_procss(opad_ctx, &out_ipad, NULL, dslen);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
	opad_ctx->stage = HISI_SYMM_STAGE_DOFINAL;
	ret = hicrypto_do_hd_hash_procss(opad_ctx, NULL, out, 0);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

end_handle:
	if (pout_tmp != NULL) {
		(void)memset_s(pout_tmp, HISI_SYMM_BLKLEN_HASH_SHA512, 0x0, HISI_SYMM_BLKLEN_HASH_SHA512);
		kfree(pout_tmp);
		pout_tmp = NULL;
	}

	if (pipad_ctx != NULL) {
		temp_ret = hicrypto_hash_free_ctx(pipad_ctx);
		if (pal_check(temp_ret != BSP_RET_OK))
			pal_error("hd_hmac dofinal free hash ctx failed\n");
	}

	return ret == BSP_RET_OK ? temp_ret : ret;
}

static void hicrypto_smac_build_drv_para(struct hi_mac_req_ctx_inner *ctx, struct hisi_dev_cipher_param *pcipher_param)
{
	pcipher_param->keytype = ctx->keytype;
	pcipher_param->pkey = ctx->key;
	pcipher_param->algorithm = ctx->alg;
	pcipher_param->mode = ctx->mode;
	pcipher_param->direction = HISI_SYMM_DIRECTION_ENCRYPT;
	pcipher_param->keylen = ctx->key_len;
	pcipher_param->padding_en = (ctx->stage == HISI_SYMM_STAGE_DOFINAL) ? 1 : 0;
}

static void hicrypto_smac_build_drvdata(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in,
					unsigned int nbytes, struct hisi_dev_symm_data_proc *pdrv_symm_data)
{
	/* Initialize the context scatterlist */
	pdrv_symm_data->din_num = 1;
	if (ctx->un_processed_len && nbytes) {
		/* Build the data scatterlist table - allocate enough entries
		 * for both data pieces (buffer and input data)
		 */
		pdrv_symm_data->pdin[0].addr.cpu_addr = ctx->un_processed_buf;
		pdrv_symm_data->pdin[0].len = ctx->un_processed_len;
		pdrv_symm_data->pdin[0].type = ADDR_TYPE_KERNEL_VA;

		if (ctx->un_processed_len < ctx->cur_process_bytes) {
			pdrv_symm_data->pdin[1].addr.cpu_addr = in->buffer;
			pdrv_symm_data->pdin[1].len = ctx->cur_process_bytes - ctx->un_processed_len;
			pdrv_symm_data->pdin[1].type = in->type;
			pdrv_symm_data->din_num = 2;
		}
	} else if (ctx->un_processed_len) {
		pdrv_symm_data->pdin[0].addr.cpu_addr = ctx->un_processed_buf;
		pdrv_symm_data->pdin[0].len = ctx->cur_process_bytes;
		pdrv_symm_data->pdin[0].type = ADDR_TYPE_KERNEL_VA;
	} else if (nbytes) {
		pdrv_symm_data->pdin[0].addr.cpu_addr = in->buffer;
		pdrv_symm_data->pdin[0].len = ctx->cur_process_bytes;
		pdrv_symm_data->pdin[0].type = in->type;
	} else {
		pal_info("hicrypto update sg_add nbytes= %d, rctx->blen = %d!\n", nbytes, ctx->un_processed_len);
		pdrv_symm_data->rxmode = HISI_SYMM_TRANSFER_MASTER;
	}
	pdrv_symm_data->inlen = ctx->cur_process_bytes;

	pdrv_symm_data->dout_num = 0;
	pdrv_symm_data->pb_out = ctx->pout;
	pdrv_symm_data->outlen = ctx->iv_len;

	pdrv_symm_data->pivin = ctx->digest;
	pdrv_symm_data->ivinlen = ctx->iv_len;
	pdrv_symm_data->pivout = ctx->digest;
	pdrv_symm_data->ivoutlen = ctx->iv_len;
}

static int hicrypto_smac_pre_process_indata(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in,
					    unsigned int nbytes, struct hisi_dev_symm_data_proc *pdrv_symm_data,
					    unsigned int *flag)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	unsigned long long len;
	int ret;

	/* check for buffer from previous updates and append it */
	len = (unsigned long long)ctx->un_processed_len + (unsigned long long)nbytes;
	pdrv_symm_data->rxmode = HISI_SYMM_TRANSFER_LIST;
	pdrv_symm_data->txmode = HISI_SYMM_TRANSFER_CPU;

	*flag = 1;

	if ((ctx->stage == HISI_SYMM_STAGE_UPDATE) && (len <= ctx->blk_len)) {
		// copy data to buf(in nbytes flag, -> buf)
		if (pal_check(!in))
			return err_api(ERRCODE_NULL);
		ret = hicrypto_data_copy_from_user(ctx->un_processed_buf + ctx->un_processed_len,
						   sizeof(ctx->un_processed_buf) - ctx->un_processed_len, in, 0, nbytes,
						   in->type);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		ctx->un_processed_len += nbytes;

		/* 返回不继续处理 */
		*flag = 0;
		return BSP_RET_OK;
	}

	/* process cur data */
	ctx->cur_remain_bytes = (ctx->stage == HISI_SYMM_STAGE_DOFINAL) ? 0 : len & (ctx->blk_len - 1);
	if (ctx->stage == HISI_SYMM_STAGE_UPDATE && ctx->cur_remain_bytes == 0)
		ctx->cur_remain_bytes = symm_get_blklen(ctx->alg);
	ctx->cur_process_bytes = len - ctx->cur_remain_bytes;
	ctx->total_bytes = (ctx->stage == HISI_SYMM_STAGE_DOFINAL) ? (ctx->total_bytes + ctx->cur_process_bytes) :
								   ctx->total_bytes;
	hicrypto_smac_build_drvdata(ctx, in, nbytes, pdrv_symm_data);
	return BSP_RET_OK;
}

static int hicrypto_smac_post_process(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in,
				      struct hi_base_data *out, unsigned int nbytes)
{
	int ret;
	unsigned int offset = nbytes - ctx->cur_remain_bytes;

	if (ctx->cur_remain_bytes) {
		if (pal_check(!in))
			return err_api(ERRCODE_NULL);
		ret = hicrypto_data_copy_from_user(ctx->un_processed_buf, sizeof(ctx->un_processed_buf), in, offset,
						   ctx->cur_remain_bytes, in->type);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		ctx->un_processed_len = ctx->cur_remain_bytes;
	} else {
		ctx->un_processed_len = 0;
	}

	/* Update result area if supplied */
	if (out && out->buffer && ctx->stage == HISI_SYMM_STAGE_DOFINAL && (out->size >= ctx->digest_len)) {
		hicrypto_data_copy_to_user(ctx->pout, ctx->iv_len, out, 0, ctx->iv_len, out->type);
		out->size = ctx->iv_len;
	}

	if (ctx->stage != HISI_SYMM_STAGE_DOFINAL)
		ctx->total_bytes += ctx->cur_process_bytes;
	return BSP_RET_OK;
}

static int hicrypto_do_hd_smac_core(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
				    unsigned int nbytes, struct hisi_dev_symm_data_proc *pdrv_symm_data)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	int temp_ret = err_api(ERRCODE_UNKNOWN);
	struct hisi_drv_symm_sg_list_info drv_list_info = { 0 };
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	struct hisi_dev_cipher_param cipher_param = { 0 };

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);

	/* drv cipher para */
	hicrypto_smac_build_drv_para(ctx, &cipher_param);

	/* list process rx data */
	ret = hisi_dev_symm_build_hwaddr(hdev, pdrv_symm_data, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
	pdrv_symm_data->txmode = HISI_SYMM_TRANSFER_CPU;

	/* call hard cipher */
	ret = hisi_dev_cipher_main(hdev, pdrv_symm_data, &cipher_param, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	ret = hisi_dev_symm_tx_out_process(hdev, pdrv_symm_data, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* copy ctx digest to out ioctl:copy_to_user  hmmgr: memcpy to out */
	ret = hicrypto_smac_post_process(ctx, in, out, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
end_handle:
	/* clean parameter */
	temp_ret = hisi_dev_symm_clean_workspace(pdrv_symm_data, &drv_list_info);
	if (pal_check(temp_ret != BSP_RET_OK))
		pal_error("clean workspace fail ret =%x", temp_ret);
	return ret == BSP_RET_OK ? temp_ret : ret;	
}

/* in user not cache buf data */
int hicrypto_do_hd_smac_process(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
				unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int flag;
	struct hisi_dev_symm_data_proc drv_symm_data = { 0 };

	if ((ctx->stage == HISI_SYMM_STAGE_UPDATE) && (nbytes == 0))
		return BSP_RET_OK;

	/* process data */
	ret = hicrypto_smac_pre_process_indata(ctx, in, nbytes, &drv_symm_data, &flag);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	/* not enough one blk */
	if (flag == 0)
		return ret;

	ret = hicrypto_do_hd_smac_core(ctx, in, out, nbytes, &drv_symm_data);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	return ret;	
}

int hicrypto_hd_mac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret;

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	if (ctx->mode == HASH_OPS_HMAC)
		seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_hmac_update(ctx, in, nbytes));
	else
		seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_smac_process(ctx, in, NULL, nbytes));
	return ret;
}

int hicrypto_hd_mac_dofinal(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *out)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret;

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	if (ctx->mode == HASH_OPS_HMAC)
		seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_hmac_dofinal(ctx, out, 0));
	else
		seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_smac_process(ctx, NULL, out, 0));

	return ret;
}

/* in user cache one block data for hard constraint, update data guarantee blks */
static int hicrypto_smac_pre_process_data(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in,
					    unsigned int nbytes, struct hisi_dev_symm_data_proc *pdrv_symm_data,
					    unsigned int *flag)
{
	unsigned long long len;
	int ret;

	/* check for buffer from previous updates and append it */
	len = (unsigned long long)ctx->un_processed_len + (unsigned long long)nbytes;
	pdrv_symm_data->rxmode = HISI_SYMM_TRANSFER_LIST;
	pdrv_symm_data->txmode = HISI_SYMM_TRANSFER_CPU;

	*flag = 1;
	/* not enough one blk no process in update */
	if ((ctx->stage == HISI_SYMM_STAGE_UPDATE) && (len < ctx->blk_len)) {
		if (nbytes == 0) {
			*flag = 0;
			return BSP_RET_OK;	
		}
		// copy data to buf(in nbytes flag, -> buf)
		ret = hicrypto_data_copy_from_user(ctx->un_processed_buf + ctx->un_processed_len,
						   sizeof(ctx->un_processed_buf) - ctx->un_processed_len, in, 0, nbytes,
						   in->type);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		ctx->un_processed_len += nbytes;

		/* 返回不继续处理 */
		*flag = 0;
		return BSP_RET_OK;
	}

	/* process cur data */
	ctx->cur_remain_bytes = 0;
	ctx->cur_process_bytes = len - ctx->cur_remain_bytes;
	ctx->total_bytes = (ctx->stage == HISI_SYMM_STAGE_DOFINAL) ? (ctx->total_bytes + ctx->cur_process_bytes) :
								   ctx->total_bytes;

	hicrypto_smac_build_drvdata(ctx, in, nbytes, pdrv_symm_data);
	return BSP_RET_OK;
}

static int hicrypto_do_hd_smac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
				      unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int flag;
	struct hisi_dev_symm_data_proc drv_symm_data = { 0 };

	if ((ctx->stage == HISI_SYMM_STAGE_UPDATE) && (nbytes == 0 && ctx->un_processed_len < ctx->blk_len))
		return BSP_RET_OK;

	/* process data */
	ret = hicrypto_smac_pre_process_data(ctx, in, nbytes, &drv_symm_data, &flag);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	/* not enough one blk */
	if (flag == 0)
		return ret;

	ret = hicrypto_do_hd_smac_core(ctx, in, out, nbytes, &drv_symm_data);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	return ret;	
}

/* for support import data to update process, len to be processed is buflen + srclen */
int hicrypto_hd_smac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret;

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);

	/* check para */
	if (pal_check(ctx == NULL || in == NULL))
		return err_api(ERRCODE_NULL);

	ctx->stage = HISI_SYMM_STAGE_UPDATE;
	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_smac_update(ctx, in, NULL, nbytes));
	return ret;
}