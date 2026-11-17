/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine api hd cipher interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_ALG_HD_CIPHER_H__
#define __HICRYPTO_ALG_HD_CIPHER_H__
#include "hicrypto_ctx_def.h"
#include "hicrypto_data_type.h"

int hicrypto_hd_cipher_encrypt(struct hi_skcipher_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
			       unsigned int cryptolen);
int hicrypto_hd_cipher_decrypt(struct hi_skcipher_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
			       unsigned int cryptolen);
#endif