/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash hd interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_ALG_HD_HASH_H__
#define __HICRYPTO_ALG_HD_HASH_H__
#include "hicrypto_ctx_def.h"
#include "hicrypto_data_type.h"

int hicrypto_hd_hash_digest(struct hi_hash_req_ctx_inner *ctx, enum hi_hash_alg_id id, struct hi_base_data *in,
			    struct hi_base_data *out, unsigned int nbytes);

int hicrypto_do_hd_hash_procss(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
			       unsigned int nbytes);

int hicrypto_hd_hash_update(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes);
int hicrypto_hd_hash_dofinal(struct hi_hash_req_ctx_inner *ctx, struct hi_base_data *out);

#endif