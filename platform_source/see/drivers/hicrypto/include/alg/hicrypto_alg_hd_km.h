/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine api hd km interface
 * Create: 2024/08/20
 */
#ifndef __HICRYPTO_ALG_HD_KM_H__
#define __HICRYPTO_ALG_HD_KM_H__
#include "hicrypto_ctx_def.h"
#include "hicrypto_data_type.h"
#include "hicrypto_driver.h"

int hicrypto_ree_wrap_key(struct hi_km_wrap_ctx_inner *wrap_ctx, struct hi_base_data *wrapping_key,
                          struct hi_base_data *key_in, struct hi_base_data *key_wrapped);
int hicrypto_ree_export_key(struct hi_km_export_ctx_inner *export_para, struct hi_base_data *cipher_key);
int hicrypto_ree_derive_root_key(unsigned int derive_type, struct hi_base_data *in, struct hi_base_data *out);
void hicrypto_km_gid_derive_selftest(struct hicrypto_device *hdev);
int hicrypto_km_kdr_derive_check(struct hicrypto_device *hdev);

int hicrypto_ree_derive_unreadable_key(unsigned int derive_type, struct hi_base_data *in, unsigned int *pdoutlen);
int hicrypto_ree_km_rtldec(void);
#endif