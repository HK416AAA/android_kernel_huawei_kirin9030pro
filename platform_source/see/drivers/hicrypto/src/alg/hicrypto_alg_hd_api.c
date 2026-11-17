/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine api inner interface
 * Create: 2024/04/11
 */
#ifndef __HICRYPTO_ALG_HD_API_H__
#define __HICRYPTO_ALG_HD_API_H__

#include "hicrypto_alg_hd_api.h"
#include "hicrypto_alg_def.h"

#include "hicrypto_errno.h"
#include "hicrypto_macro.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static const unsigned int g_symm_alg_table[] = {
	/* cipher */
	HISI_CIPHER_ALG_AES_ECB_NOPAD, HISI_CIPHER_ALG_AES_CBC_NOPAD, HISI_CIPHER_ALG_AES_CTR_NOPAD,
	HISI_CIPHER_ALG_AES_OFB_NOPAD, HISI_CIPHER_ALG_AES_XTS_NOPAD, HISI_CIPHER_ALG_SM4_ECB_NOPAD,
	HISI_CIPHER_ALG_SM4_CBC_NOPAD, HISI_CIPHER_ALG_SM4_CTR_NOPAD, HISI_CIPHER_ALG_SM4_OFB_NOPAD,
	HISI_CIPHER_ALG_DES_ECB_NOPAD, HISI_CIPHER_ALG_DES_CBC_NOPAD, HISI_CIPHER_ALG_AES_ECB_BUFF_KEY_NOPAD,
	HISI_CIPHER_ALG_AES_ECB_DERIVE_KEY_NOPAD, HISI_CIPHER_ALG_AES_CBC_DERIVE_KEY_NOPAD,
	HISI_CIPHER_ALG_SM4_CBC_DERIVE_KEY_NOPAD,
	/* hash */
	HISI_HASH_ALG_SHA256, HISI_HASH_ALG_SHA224, HISI_HASH_ALG_SHA384, HISI_HASH_ALG_SHA512, HISI_HASH_ALG_SHA1,
	HISI_HASH_ALG_SM3,
	/* mac */
	HISI_HMAC_ALG_SHA256, HISI_HMAC_ALG_SHA224, HISI_HMAC_ALG_SHA384, HISI_HMAC_ALG_SHA512, HISI_HMAC_ALG_SHA1,
	HISI_HMAC_ALG_SM3, HISI_CIPHER_ALG_AES_CMAC_NOPAD, HISI_CIPHER_ALG_AES_CBCMAC_NOPAD, HISI_CIPHER_ALG_AES_XCBCMAC_NOPAD,
	/* aead */
	HISI_AEAD_ALG_AES_CCM, HISI_AEAD_ALG_AES_GCM
};

int hicrypto_hd_check_is_support(int alg_id)
{
	unsigned int flag;

	/* check para */
	flag = hicrypto_find_in_array(g_symm_alg_table, ARRAY_SIZE(g_symm_alg_table), alg_id);
	if (pal_check(flag == 0))
		return err_api(ERRCODE_UNSUPPORT);
	return BSP_RET_OK;
}

#endif