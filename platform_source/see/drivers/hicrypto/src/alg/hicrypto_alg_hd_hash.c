/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash hd interface
 * Create: 2024/04/11
 */
#include <securec.h>

#include "hicrypto_alg_hd_hash.h"
#include "hicrypto_inner_hash.h"
#include "hicrypto_dev_hash.h"
#include "hicrypto_driver.h"

#include "hicrypto_common.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_dft.h"
#include "hicrypto_eng_ctrl.h"
#include "hicrypto_io.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static const unsigned char hicrypto_sm3_zero_message_hash[SYMM_OUTLEN_SM3] = {
	0x1A, 0xB2, 0x1D, 0x83, 0x55, 0xCF, 0xA1, 0x7F, 0x8e, 0x61, 0x19, 0x48, 0x31, 0xE8, 0x1A, 0x8F,
	0x22, 0xBE, 0xC8, 0xC7, 0x28, 0xFE, 0xFB, 0x74, 0x7E, 0xD0, 0x35, 0xEB, 0x50, 0x82, 0xAA, 0x2B
};

static const unsigned char hicrypto_sha384_zero_message_hash[SYMM_OUTLEN_SHA384] = {
	0x38, 0xb0, 0x60, 0xa7, 0x51, 0xac, 0x96, 0x38, 0x4c, 0xd9, 0x32, 0x7e, 0xb1, 0xb1, 0xe3, 0x6a,
	0x21, 0xfd, 0xb7, 0x11, 0x14, 0xbe, 0x07, 0x43, 0x4c, 0x0c, 0xc7, 0xbf, 0x63, 0xf6, 0xe1, 0xda,
	0x27, 0x4e, 0xde, 0xbf, 0xe7, 0x6f, 0x65, 0xfb, 0xd5, 0x1a, 0xd2, 0xf1, 0x48, 0x98, 0xb9, 0x5b
};

static const unsigned char hicrypto_sha512_zero_message_hash[SYMM_OUTLEN_SHA512] = {
	0xcf, 0x83, 0xe1, 0x35, 0x7e, 0xef, 0xb8, 0xbd, 0xf1, 0x54, 0x28, 0x50, 0xd6, 0x6d, 0x80, 0x07,
	0xd6, 0x20, 0xe4, 0x05, 0x0b, 0x57, 0x15, 0xdc, 0x83, 0xf4, 0xa9, 0x21, 0xd3, 0x6c, 0xe9, 0xce,
	0x47, 0xd0, 0xd1, 0x3c, 0x5d, 0x85, 0xf2, 0xb0, 0xff, 0x83, 0x18, 0xd2, 0x87, 0x7e, 0xec, 0x2f,
	0x63, 0xb9, 0x31, 0xbd, 0x47, 0x41, 0x7a, 0x81, 0xa5, 0x38, 0x32, 0x7a, 0xf9, 0x27, 0xda, 0x3e
};

static const unsigned char hicrypto_sha224_zero_message_hash[SYMM_OUTLEN_SHA224] = { 0xd1, 0x4a, 0x02, 0x8c, 0x2a, 0x3a, 0x2b,
								     0xc9, 0x47, 0x61, 0x02, 0xbb, 0x28, 0x82,
								     0x34, 0xc4, 0x15, 0xa2, 0xb0, 0x1f, 0x82,
								     0x8e, 0xa6, 0x2a, 0xc5, 0xb3, 0xe4, 0x2f };

static const unsigned char hicrypto_sha256_zero_message_hash[SYMM_OUTLEN_SHA256] = { 0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14,
								     0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24,
								     0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
								     0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55 };

static const unsigned char hicrypto_sha1_zero_message_hash[SYMM_OUTLEN_SHA1] = { 0xda, 0x39, 0xa3, 0xee, 0x5e, 0x6b, 0x4b,
								 0x0d, 0x32, 0x55, 0xbf, 0xef, 0x95, 0x60,
								 0x18, 0x90, 0xaf, 0xd8, 0x07, 0x09 };

static const unsigned char *hicrypto_zero_hash(unsigned char alg_flags)
{
	const unsigned char *sha_zero = NULL;

	switch (alg_flags) {
		case HISI_HASH_ALGORITHM_SHA1:
			sha_zero = hicrypto_sha1_zero_message_hash;
			break;
		case HISI_HASH_ALGORITHM_SHA256:
			sha_zero = hicrypto_sha256_zero_message_hash;
			break;
		case HISI_HASH_ALGORITHM_SM3:
			sha_zero = hicrypto_sm3_zero_message_hash;
			break;
		case HISI_HASH_ALGORITHM_SHA224:
			sha_zero = hicrypto_sha224_zero_message_hash;
			break;
		case HISI_HASH_ALGORITHM_SHA384:
			sha_zero = hicrypto_sha384_zero_message_hash;
			break;
		case HISI_HASH_ALGORITHM_SHA512:
			sha_zero = hicrypto_sha512_zero_message_hash;
			break;
		default:
			return NULL;
	}

	return sha_zero;
}

int hicrypto_hash_pre_process_indata(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes,
				     struct hisi_dev_symm_data_proc *pdrv_symm_data, unsigned int *flag)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	unsigned long long len;
	int ret;

	/* check for buffer from previous updates and append it */
	len = (unsigned long long)ctx->un_processed_len + (unsigned long long)nbytes;
	pdrv_symm_data->rxmode = HISI_SYMM_TRANSFER_LIST;
	pdrv_symm_data->txmode = HISI_SYMM_TRANSFER_CPU;
	*flag = 1;

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	if ((ctx->stage == HISI_SYMM_STAGE_UPDATE) && (len <= ctx->blk_len)) {
		/* copy data to buf(in nbytes flag, -> buf) */
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
	ctx->cur_process_bytes = len - ctx->cur_remain_bytes;
	ctx->total_bytes = (ctx->stage == HISI_SYMM_STAGE_DOFINAL) ? (ctx->total_bytes + ctx->cur_process_bytes) :
								   ctx->total_bytes;

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
		if (ctx->stage == HISI_SYMM_STAGE_DOFINAL && ctx->total_bytes == 0) {
			(void)memset_s(ctx->digest, sizeof(ctx->digest), 0, sizeof(ctx->digest));
			(void)memcpy_s(ctx->digest, sizeof(ctx->digest), hicrypto_zero_hash(ctx->alg), ctx->digest_len);
			pdrv_symm_data->din_num = 0;
		}
		pdrv_symm_data->rxmode = HISI_SYMM_TRANSFER_MASTER;
	}
	pdrv_symm_data->inlen = ctx->cur_process_bytes;
	pdrv_symm_data->dout_num = 0;
	pdrv_symm_data->outlen = 0;

	return BSP_RET_OK;
}

static int hicrypto_hash_post_process(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in,
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
		hicrypto_data_copy_to_user(ctx->digest, ctx->digest_len, out, 0, ctx->digest_len, out->type);
		out->size = ctx->digest_len;
	}

	if (ctx->stage != HISI_SYMM_STAGE_DOFINAL)
		ctx->total_bytes += ctx->cur_process_bytes;

	return BSP_RET_OK;
}

int hicrypto_do_hd_hash_procss(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
			       unsigned int nbytes)
{
	int ret;
	unsigned int flag;
	struct hisi_dev_symm_data_proc drv_symm_data = { 0 };
	struct hisi_drv_symm_sg_list_info drv_list_info = { 0 };
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret_temp = err_api(ERRCODE_UNKNOWN);

	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	if ((ctx->stage == HISI_SYMM_STAGE_UPDATE) && (nbytes == 0))
		return BSP_RET_OK;
	/* process data */
	ret = hicrypto_hash_pre_process_indata(ctx, in, nbytes, &drv_symm_data, &flag);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	/* not enough one blk */
	if (flag == 0)
		return ret;

	/* list process rx data */
	ret = hisi_dev_symm_build_hwaddr(hdev, &drv_symm_data, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
	drv_symm_data.txmode = HISI_SYMM_TRANSFER_CPU;
	/* call hard cal hash */
	ret = hisi_dev_hash_run_cmd(hdev, ctx, &drv_symm_data, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	ret = hisi_dev_symm_tx_out_process(hdev, &drv_symm_data, &drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* copy ctx digest to out ioctl:copy_to_user  hmmgr: memcpy to out */
	ret = hicrypto_hash_post_process(ctx, in, out, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

end_handle:
	/* clean parameter */
	ret_temp = hisi_dev_symm_clean_workspace(&drv_symm_data, &drv_list_info);
	if (pal_check(ret_temp != BSP_RET_OK))
		pal_error("clean workspace fail ret =%x", ret_temp);
	return ret == BSP_RET_OK ? ret_temp : ret;
}

int hicrypto_hd_hash_digest(struct hi_hash_req_ctx_inner *ctx, enum hi_hash_alg_id id, struct hi_base_data *in,
			    struct hi_base_data *out, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);

	ret = hicrypto_hash_init(ctx, id);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	ctx->stage = HISI_SYMM_STAGE_UPDATE;
	ret = hicrypto_do_hd_hash_procss(ctx, in, NULL, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	ctx->stage = HISI_SYMM_STAGE_DOFINAL;
	ret = hicrypto_do_hd_hash_procss(ctx, NULL, out, 0);
	if (pal_check(ret != BSP_RET_OK))
		return ret;
	return ret;
}

int hicrypto_hd_hash_update(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret;
	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_hash_procss(ctx, in, NULL, nbytes));

	return ret;
}

int hicrypto_hd_hash_dofinal(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *out)
{
	struct hicrypto_device *hdev = hicrypto_find_dev(&(ctx->hdev));
	int ret;
	if (pal_check(hdev == NULL))
		return err_api(ERRCODE_NULL);
	seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_do_hd_hash_procss(ctx, NULL, out, 0));

	return ret;
}
