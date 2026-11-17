/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash inner interface
 * Create: 2024/04/11
 */
#include <linux/mm.h>
#include <linux/slab.h>

#include <securec.h>

#include "hicrypto_alg_def.h"
#include "hicrypto_alg_hd_api.h"
#include "hicrypto_alg_hd_hash.h"
#include "hicrypto_inner_hash.h"
#include "hicrypto_inner_standard.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"
#include "hicrypto_common.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static const unsigned int g_hash_alg_table[] = {
	HISI_HASH_ALG_SHA256, HISI_HASH_ALG_SHA224, HISI_HASH_ALG_SHA384,
	HISI_HASH_ALG_SHA512, HISI_HASH_ALG_SHA1,	HISI_HASH_ALG_SM3,
};

/* malloc ctx memeory */
int hicrypto_hash_new_ctx(enum hi_hash_alg_id id, struct hi_hash_req_ctx_inner **ctx)
{
	struct hi_hash_req_ctx_inner *hash_ctx = NULL;
	union hi_hash_id *algorithm = (union hi_hash_id *)(&id);
	unsigned int flag;

	/* check para */
	flag = hicrypto_find_in_array(g_hash_alg_table, ARRAY_SIZE(g_hash_alg_table), id);
	if (pal_check(flag == 0))
		return err_api(ERRCODE_PARAMS);

	hash_ctx = (struct hi_hash_req_ctx_inner *)kzalloc(sizeof(struct hi_hash_req_ctx_inner), GFP_KERNEL);
	if (pal_check(!hash_ctx)) {
		pal_error("hicrypto hash_new_ctx failed\n");
		return err_api(ERRCODE_MEMORY);
	}
	*ctx = hash_ctx;
	unused(ctx);
	return BSP_RET_OK;
}

/* init iv to ctx */
int hicrypto_hash_init(struct hi_hash_req_ctx_inner *ctx, enum hi_hash_alg_id id)
{
	unsigned int i;
	int ret = err_api(ERRCODE_UNKNOWN);
	union hi_hash_id *algorithm = (union hi_hash_id *)(&id);
	unsigned int flag;
	const struct hisi_symm_iv_list *hash_iv_list = hicrypto_get_hash_std_iv();
	unsigned int iv_list_size = hicrypto_hash_std_iv_list_size();

	/* check para */
	if (pal_check(ctx == NULL))
		return err_api(ERRCODE_NULL);

	flag = hicrypto_find_in_array(g_hash_alg_table, ARRAY_SIZE(g_hash_alg_table), id);
	if (pal_check(flag == 0))
		return err_api(ERRCODE_PARAMS);

	(void)memset_s(ctx, sizeof(struct hi_hash_req_ctx_inner), 0, sizeof(struct hi_hash_req_ctx_inner));
	ctx->alg = algorithm->id.alg;

	/* store iv */
	ret = err_api(ERRCODE_PARAMS);
	for (i = 0; i < iv_list_size; i++) {
		if (hash_iv_list[i].alg == ctx->alg) {
			ctx->digest_len = hash_iv_list[i].digest_size;
			ctx->iv_len = hash_iv_list[i].iv_size;
			ctx->blk_len = hash_iv_list[i].blk_size;
			(void)memset_s(ctx->digest, sizeof(ctx->digest), 0, sizeof(ctx->digest));
			(void)memcpy_s(ctx->digest, sizeof(ctx->digest), hash_iv_list[i].init_iv, ctx->iv_len);
			ret = BSP_RET_OK;
			break;
		}
	}

	if (pal_check(ret != BSP_RET_OK))
		return ret;
	ctx->stage = HISI_SYMM_STAGE_INIT;
	return ret;
}

/* check para and process common section and call specific ops update */
int hicrypto_hash_update(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int alg_id;

	/* check para */
	if (pal_check(ctx == NULL || in == NULL))
		return err_api(ERRCODE_NULL);

	ctx->stage = HISI_SYMM_STAGE_UPDATE;
	alg_id = hi_hash_id_build(ctx->alg);
	ret = hicrypto_hd_check_is_support(alg_id);
	if (pal_check(ret != BSP_RET_OK))
			return ret;

	/* 调用 hash */
	ret = hicrypto_hd_hash_update(ctx, in, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

/* check para and process common section and call specific ops dofinal */
int hicrypto_hash_dofinal(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *out)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned int alg_id;

	/* check para */
	if (pal_check(ctx == NULL || out == NULL || out->size < ctx->digest_len))
		return err_api(ERRCODE_NULL);

	ctx->stage = HISI_SYMM_STAGE_DOFINAL;
	alg_id = hi_hash_id_build(ctx->alg);
	ret = hicrypto_hd_check_is_support(alg_id);
	if (pal_check(ret != BSP_RET_OK))
			return ret;

	/* 调用 hash */
	ret = hicrypto_hd_hash_dofinal(ctx, out);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

int hicrypto_hash_digest(struct hi_hash_req_ctx_inner *ctx, enum hi_hash_alg_id id, struct hi_base_data *in,
			 struct hi_base_data *out, unsigned int nbytes)
{
	int ret = err_api(ERRCODE_UNKNOWN);

	ret = hicrypto_hash_init(ctx, id);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	ret = hicrypto_hash_update(ctx, in, nbytes);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	ret = hicrypto_hash_dofinal(ctx, out);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

/* free ctx memeory */
int hicrypto_hash_free_ctx(struct hi_hash_req_ctx_inner *ctx)
{
	/* check para */
	if (pal_check(ctx == NULL))
		return err_api(ERRCODE_NULL);

	(void)memset_s(ctx, sizeof(struct hi_hash_req_ctx_inner), 0, sizeof(struct hi_hash_req_ctx_inner));
	kfree(ctx);
	ctx = NULL;
	return BSP_RET_OK;
}