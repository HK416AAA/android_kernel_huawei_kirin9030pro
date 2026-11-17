/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine api hd api interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_ALG_HD_API_H__
#define __HICRYPTO_ALG_HD_API_H__

int hicrypto_hd_check_is_support(int id);
int hicrypto_alg_hd_init(void);
int hicrypto_alg_hd_deinit(void);

#endif