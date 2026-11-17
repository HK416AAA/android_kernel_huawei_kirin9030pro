/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine sha const
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_INNER_SHA_H__
#define __HICRYPTO_INNER_SHA_H__

struct hisi_symm_iv_list {
	unsigned int alg;
	unsigned char *init_iv;
	unsigned int iv_size;
	unsigned int blk_size;
	unsigned int digest_size;
};

const struct hisi_symm_iv_list *hicrypto_get_hash_std_iv(void);

const struct hisi_symm_iv_list *hicrypto_get_smac_std_iv(void);

unsigned int hicrypto_hash_std_iv_list_size(void);

unsigned int hicrypto_smac_std_iv_list_size(void);

unsigned int symm_get_doutlen(unsigned int alg, unsigned int mode, unsigned int dinlen);

unsigned int symm_get_ivlen(unsigned int alg);

unsigned int symm_get_blklen(unsigned int alg);
#endif