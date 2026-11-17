/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine mac inner interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_ALG_HD_MAC_H__
#define __HICRYPTO_ALG_HD_MAC_H__
#include "hicrypto_ctx_def.h"
#include "hicrypto_data_type.h"

int hicrypto_hd_mac_setkey(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *key);
int hicrypto_hd_mac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes);
int hicrypto_hd_mac_dofinal(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *out);
/* for support import data to update process, len to be processed is buflen + srclen */
int hicrypto_hd_smac_update(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, unsigned int nbytes);
/* in user not cache buf data */
int hicrypto_do_hd_smac_process(struct hi_mac_req_ctx_inner *ctx, struct hi_base_data *in, struct hi_base_data *out,
				unsigned int nbytes);
#endif