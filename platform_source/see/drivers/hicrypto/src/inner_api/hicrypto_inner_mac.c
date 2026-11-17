/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine mac inner interface
 * Create: 2024/04/11
 */
#include <linux/mm.h>
#include <linux/slab.h>
#include <securec.h>

#include "hicrypto_io.h"
#include "hicrypto_inner_mac.h"
#include "hicrypto_alg_hd_mac.h"
#include "hicrypto_alg_hd_api.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"
#include "hicrypto_common.h"
#include "hicrypto_inner_standard.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

/* inner 层的功能 处理硬件算法软件算法的公共部分  调度硬件或者软件 */
/* cbcmac xcbcmac  default iv is 0, not support set iv */
static const unsigned int g_mac_alg_table[] = {
	HISI_HMAC_ALG_SHA256,
	HISI_HMAC_ALG_SHA224,
	HISI_HMAC_ALG_SHA384,
	HISI_HMAC_ALG_SHA512,
	HISI_HMAC_ALG_SHA1,
	HISI_HMAC_ALG_SM3,
	HISI_CIPHER_ALG_AES_CMAC_NOPAD,
	HISI_CIPHER_ALG_AES_CBCMAC_NOPAD,
	HISI_CIPHER_ALG_AES_XCBCMAC_NOPAD,
	HISI_CIPHER_ALG_AES_CMAC_DERIVE_KEY_NOPAD,
};

#define hisi_half_value(value) ((value) / 2)

/* check alg, malloc ctx memory, memset memory */
int hicrypto_mac_new_ctx(enum hi_mac_alg_id id, struct hi_mac_req_ctx_inner **ctx)
{
	struct hi_mac_req_ctx_inner *mac_ctx = NULL;
	union hi_mac_id *algorithm = (union hi_mac_id *)(&id);
	unsigned int flag, extsize;

	/* check para */
	flag = hicrypto_find_in_array(g_mac_alg_table, ARRAY_SIZE(g_mac_alg_table), id);
	if (pal_check(flag == 0))
		return err_api(ERRCODE_PARAMS);

	extsize = (algorithm->id.mode == HASH_OPS_HMAC) ? sizeof(struct hi_hash_req_ctx_inner) : 0;
	mac_ctx = (struct hi_mac_req_ctx_inner *)kzalloc(sizeof(struct hi_mac_req_ctx_inner) + extsize, GFP_KERNEL);
	if (pal_check(!mac_ctx)) {
		pal_error("hicrypto mac_new_ctx failed\n");
		return err_api(ERRCODE_MEMORY);
	}

	mac_ctx->ext_ctx_size = extsize;
	*ctx = mac_ctx;
	unused(ctx);
	return BSP_RET_OK;
}

static int hicrypto_symm_mac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key)
{
	unsigned int mode = ctx->mode;
	int ret = err_api(ERRCODE_UNKNOWN);

	if (mode == HISI_CIPHER_MODE_XCBCMAC) {
		if (pal_check(key->size != HISI_SYMM_KEYLEN_16))
			return err_api(ERRCODE_PARAMS);
	} else if (mode == HISI_CIPHER_MODE_XTS) {
		if (pal_check(hi_aes_keylen_check(hisi_half_value(key->size))))
			return err_api(ERRCODE_PARAMS);
	} else {
		if (pal_check(hi_aes_keylen_check(key->size)))
			return err_api(ERRCODE_PARAMS);
	}

	if (ctx->keytype == HISI_SYMM_KEYTYPE_USER) {
		(void)memset_s(ctx->key, sizeof(ctx->key), 0, sizeof(ctx->key));
		ret = hicrypto_data_copy_from_user(ctx->key, sizeof(ctx->key), key, 0, key->size, key->type);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		ctx->key_len = key->size;
	} else {
		ctx->key_len = key->size; /* hd key */
	}

	return BSP_RET_OK;
}

/* hmac set key call specific ops process */
static int hicrypto_hmac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int alg_id;

	ctx->stage = HISI_SYMM_STAGE_SETKEY;
	alg_id = hi_hmac_id_build(ctx->alg);
	ret = hicrypto_hd_check_is_support(alg_id);
	if (pal_check(ret != BSP_RET_OK))
			return ret;

	/* 调用 hmac set key */
	ret = hicrypto_hd_mac_setkey(ctx, key);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

int hicrypto_mac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key)
{
	/* check para */
	if (pal_check(ctx == NULL || key == NULL || key->size == 0))
		return err_api(ERRCODE_NULL);

	/* set key */
	if (ctx->mode == HASH_OPS_HMAC)
		return hicrypto_hmac_setkey(ctx, key); /* not support hard key */
	else
		return hicrypto_symm_mac_setkey(ctx, key); /* support hard key */
}

/* set alg and init iv */
int hicrypto_mac_init(struct hi_mac_req_ctx_inner *ctx, enum hi_mac_alg_id id, struct hi_base_data *iv)
{
	unsigned int i;
	int ret = err_api(ERRCODE_UNKNOWN);
	union hi_mac_id *algorithm = (union hi_mac_id *)(&id);
	unsigned int flag, extsize;
	const struct hisi_symm_iv_list *hash_iv_list = hicrypto_get_hash_std_iv();
	const struct hisi_symm_iv_list *mac_iv_list = hicrypto_get_smac_std_iv();
	const struct hisi_symm_iv_list *iv_list = NULL;
	unsigned int iv_list_size = 0;
	unsigned int mac_alg = 0;

	/* check para */
	if (pal_check(ctx == NULL))
		return err_api(ERRCODE_NULL);

	flag = hicrypto_find_in_array(g_mac_alg_table, ARRAY_SIZE(g_mac_alg_table), id);
	if (pal_check(flag == 0))
		return err_api(ERRCODE_PARAMS);

	extsize = ctx->ext_ctx_size;
	(void)memset_s(ctx, sizeof(struct hi_mac_req_ctx_inner) + extsize, 0,
		       sizeof(struct hi_mac_req_ctx_inner) + extsize);
	ctx->ext_ctx_size = extsize;

	ctx->alg = algorithm->id.alg;
	ctx->mode = algorithm->id.mode;
	ctx->keytype = algorithm->id.type;
	ctx->pad = algorithm->id.pad;

	/* store iv */
	if (ctx->mode == HASH_OPS_HMAC) {
		iv_list = hash_iv_list;
		iv_list_size = hicrypto_hash_std_iv_list_size();
		mac_alg = ctx->alg;
	} else {
		iv_list = mac_iv_list;
		iv_list_size = hicrypto_smac_std_iv_list_size();
		mac_alg = ctx->mode;
	}

	ret = err_api(ERRCODE_PARAMS);
	for (i = 0; i < iv_list_size; i++) {
		if (iv_list[i].alg == mac_alg) {
			ctx->digest_len = iv_list[i].digest_size;
			ctx->iv_len = iv_list[i].iv_size;
			ctx->blk_len = iv_list[i].blk_size;
			(void)memset_s(ctx->digest, sizeof(ctx->digest), 0, sizeof(ctx->digest));
			(void)memcpy_s(ctx->digest, sizeof(ctx->digest), iv_list[i].init_iv, ctx->iv_len);
			ret = BSP_RET_OK;
			break;
		}
	}

	if (pal_check(ret != BSP_RET_OK))
		return ret;
	if (ctx->mode != HASH_OPS_HMAC && iv != NULL && iv->buffer != NULL && iv->size == ctx->iv_len) {
			(void)memset_s(ctx->digest, sizeof(ctx->digest), 0, sizeof(ctx->digest));
			ret = hicrypto_data_copy_from_user(ctx->digest, sizeof(ctx->digest), iv, 0, iv->size, iv->type);
			if (pal_check(ret != BSP_RET_OK))
				return ret;
	}
	ctx->stage = HISI_SYMM_STAGE_INIT;
	return ret;
}

/* check para and process common section and call specific ops update */
int hicrypto_mac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int alg_id;

	/* check para */
	if (pal_check(ctx == NULL || in == NULL))
		return err_api(ERRCODE_NULL);

	ctx->stage = HISI_SYMM_STAGE_UPDATE;

	/* check hmac or symm mac */
	if (ctx->mode == HASH_OPS_HMAC)
		alg_id = hi_hmac_id_build(ctx->alg);
	else
		alg_id = hi_cipher_id_build(ctx->alg, ctx->mode, ctx->pad, ctx->keytype);
	
	ret = hicrypto_hd_check_is_support(alg_id);
	if (pal_check(ret != BSP_RET_OK))
			return ret;

	/* 调用 hash */
	ret = hicrypto_hd_mac_update(ctx, in, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

int hicrypto_mac_dofinal(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *out)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int alg_id;

	/* check para */
	if (pal_check(ctx == NULL || out == NULL || out->size < ctx->digest_len))
		return err_api(ERRCODE_NULL);

	ctx->stage = HISI_SYMM_STAGE_DOFINAL;

	/* check hmac or symm mac */
	if (ctx->mode == HASH_OPS_HMAC)
		alg_id = hi_hmac_id_build(ctx->alg);
	else
		alg_id = hi_cipher_id_build(ctx->alg, ctx->mode, ctx->pad, ctx->keytype);

	ret = hicrypto_hd_check_is_support(alg_id);
	if (pal_check(ret != BSP_RET_OK))
			return ret;

	/* 调用 hash */
	ret = hicrypto_hd_mac_dofinal(ctx, out);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

int hicrypto_mac_digest(struct hi_mac_req_ctx_inner *ctx, enum hi_mac_alg_id id, struct hi_base_data *key, struct hi_base_data *iv,
			struct hi_base_data *in, struct hi_base_data *out, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);

	ret = hicrypto_mac_init(ctx, id, iv);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	ret = hicrypto_mac_setkey(ctx, key);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	ret = hicrypto_mac_update(ctx, in, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	ret = hicrypto_mac_dofinal(ctx, out);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

int hicrypto_mac_free_ctx(struct hi_mac_req_ctx_inner *ctx)
{
	/* check para */
	if (pal_check(ctx == NULL))
		return err_api(ERRCODE_NULL);

	(void)memset_s(ctx, sizeof(struct hi_mac_req_ctx_inner), 0, sizeof(struct hi_mac_req_ctx_inner));
	kfree(ctx);
	ctx = NULL;
	return BSP_RET_OK;
}
