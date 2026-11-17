/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine mac inner interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_INNER_MAC_H__
#define __HICRYPTO_INNER_MAC_H__
#include "hicrypto_ctx_def.h"
#include "hicrypto_data_type.h"
#include "hicrypto_ioctl.h"

#define MAX_OEM_MAC_APP_DIN_SIZE   (128 * 1024)

/* cbcmac xcbcmac  default iv is 0, not support set iv */
int hicrypto_mac_new_ctx(enum hi_mac_alg_id id, struct hi_mac_req_ctx_inner **ctx);
int hicrypto_mac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key);
int hicrypto_mac_digest(struct hi_mac_req_ctx_inner *ctx, enum hi_mac_alg_id id, struct hi_base_data *key, struct hi_base_data *iv,
			struct hi_base_data *in, struct hi_base_data *out, unsigned int nbytes);
int hicrypto_mac_init(struct hi_mac_req_ctx_inner *ctx, enum hi_mac_alg_id id, struct hi_base_data *iv);
int hicrypto_mac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes);
int hicrypto_mac_dofinal(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *out);
int hicrypto_mac_free_ctx(struct hi_mac_req_ctx_inner *ctx);

/* for nve compute mac multiplexing */
int hicrypto_oeminfo_mac_process(struct hicrypto_device *hdev, struct hi_base_data *derive_in,
								struct hi_base_data *in, struct hi_base_data *out);
#endif