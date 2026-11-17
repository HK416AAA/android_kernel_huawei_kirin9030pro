
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash inner interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_INNER_HASH_H__
#define __HICRYPTO_INNER_HASH_H__
#include "hicrypto_ctx_def.h"
#include "hicrypto_data_type.h"

int hicrypto_hash_new_ctx(enum hi_hash_alg_id id, struct hi_hash_req_ctx_inner **ctx);
int hicrypto_hash_digest(struct hi_hash_req_ctx_inner *ctx, enum hi_hash_alg_id id, struct hi_base_data *in,
			 struct hi_base_data *out, unsigned int nbytes);
int hicrypto_hash_init(struct hi_hash_req_ctx_inner *ctx, enum hi_hash_alg_id id);
int hicrypto_hash_update(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes);
int hicrypto_hash_dofinal(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *out);
int hicrypto_hash_free_ctx(struct hi_hash_req_ctx_inner *ctx);

#endif