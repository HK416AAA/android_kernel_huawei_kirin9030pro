/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash inner interface
 * Create: 2024/04/11
 */
#include "hicrypto_inner_standard.h"

#include "hicrypto_alg_def.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_macro.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static const unsigned char std_iv_sha1[HISI_SYMM_IVLEN_SHA1] = { 0x67, 0x45, 0x23, 0x01, 0xEF, 0xCD, 0xAB,
							       0x89, 0x98, 0xBA, 0xDC, 0xFE, 0x10, 0x32,
							       0x54, 0x76, 0xC3, 0xD2, 0xE1, 0xF0 };

static const unsigned char std_iv_sha256[HISI_SYMM_IVLEN_SHA256] = { 0x6A, 0x09, 0xE6, 0x67, 0xBB, 0x67, 0xAE, 0x85,
								   0x3C, 0x6E, 0xF3, 0x72, 0xA5, 0x4F, 0xF5, 0x3A,
								   0x51, 0x0E, 0x52, 0x7F, 0x9B, 0x05, 0x68, 0x8C,
								   0x1F, 0x83, 0xD9, 0xAB, 0x5B, 0xE0, 0xCD, 0x19 };

static const unsigned char std_iv_sm3[HISI_SYMM_IVLEN_SM3] = { 0x73, 0x80, 0x16, 0x6F, 0x49, 0x14, 0xB2, 0xB9,
							     0x17, 0x24, 0x42, 0xD7, 0xDA, 0x8A, 0x06, 0x00,
							     0xA9, 0x6F, 0x30, 0xBC, 0x16, 0x31, 0x38, 0xAA,
							     0xE3, 0x8D, 0xEE, 0x4D, 0xB0, 0xFB, 0x0E, 0x4E };

/* sha224 iv len is 32 bytes */
static const unsigned char std_iv_sha224[HISI_SYMM_IVLEN_SHA224] = {
	0xc1, 0x05, 0x9e, 0xd8, 0x36, 0x7c, 0xd5, 0x07, 0x30, 0x70, 0xdd, 0x17, 0xf7, 0x0e, 0x59, 0x39,
	0xff, 0xc0, 0x0b, 0x31, 0x68, 0x58, 0x15, 0x11, 0x64, 0xf9, 0x8f, 0xa7, 0xbe, 0xfa, 0x4f, 0xa4,
};

static const unsigned char std_iv_sha384[HISI_SYMM_IVLEN_SHA384] = {
	0xcb, 0xbb, 0x9d, 0x5d, 0xc1, 0x05, 0x9e, 0xd8, 0x62, 0x9a, 0x29, 0x2a, 0x36, 0x7c, 0xd5, 0x07,
	0x91, 0x59, 0x01, 0x5a, 0x30, 0x70, 0xdd, 0x17, 0x15, 0x2f, 0xec, 0xd8, 0xf7, 0x0e, 0x59, 0x39,
	0x67, 0x33, 0x26, 0x67, 0xff, 0xc0, 0x0b, 0x31, 0x8e, 0xb4, 0x4a, 0x87, 0x68, 0x58, 0x15, 0x11,
	0xdb, 0x0c, 0x2e, 0x0d, 0x64, 0xf9, 0x8f, 0xa7, 0x47, 0xb5, 0x48, 0x1d, 0xbe, 0xfa, 0x4f, 0xa4,
};

static const unsigned char std_iv_sha512[HISI_SYMM_IVLEN_SHA512] = {
	0x6a, 0x09, 0xe6, 0x67, 0xf3, 0xbc, 0xc9, 0x08, 0xbb, 0x67, 0xae, 0x85, 0x84, 0xca, 0xa7, 0x3b,
	0x3c, 0x6e, 0xf3, 0x72, 0xfe, 0x94, 0xf8, 0x2b, 0xa5, 0x4f, 0xf5, 0x3a, 0x5f, 0x1d, 0x36, 0xf1,
	0x51, 0x0e, 0x52, 0x7f, 0xad, 0xe6, 0x82, 0xd1, 0x9b, 0x05, 0x68, 0x8c, 0x2b, 0x3e, 0x6c, 0x1f,
	0x1f, 0x83, 0xd9, 0xab, 0xfb, 0x41, 0xbd, 0x6b, 0x5b, 0xe0, 0xcd, 0x19, 0x13, 0x7e, 0x21, 0x79,
};

static const unsigned char zero_iv[AES_BLOCK_SIZE] = { 0 };

const struct hisi_symm_iv_list g_hash_iv_list[] = {
	{
		.alg = HISI_HASH_ALGORITHM_SHA1,
		.init_iv = (unsigned char *)std_iv_sha1,
		.iv_size = HISI_SYMM_IVLEN_SHA1,
		.blk_size = HISI_SYMM_BLKLEN_HASH,
		.digest_size = SYMM_OUTLEN_SHA1,
	},
	{
		.alg = HISI_HASH_ALGORITHM_SHA256,
		.init_iv = (unsigned char *)std_iv_sha256,
		.iv_size = HISI_SYMM_IVLEN_SHA256,
		.blk_size = HISI_SYMM_BLKLEN_HASH,
		.digest_size = SYMM_OUTLEN_SHA256,
	},
	{
		.alg = HISI_HASH_ALGORITHM_SM3,
		.init_iv = (unsigned char *)std_iv_sm3,
		.iv_size = HISI_SYMM_IVLEN_SM3,
		.blk_size = HISI_SYMM_BLKLEN_HASH,
		.digest_size = SYMM_OUTLEN_SM3,
	},
	{
		.alg = HISI_HASH_ALGORITHM_SHA224,
		.init_iv = (unsigned char *)std_iv_sha224,
		.iv_size = HISI_SYMM_IVLEN_SHA224,
		.blk_size = HISI_SYMM_BLKLEN_HASH,
		.digest_size = SYMM_OUTLEN_SHA224,
	},
	{
		.alg = HISI_HASH_ALGORITHM_SHA384,
		.init_iv = (unsigned char *)std_iv_sha384,
		.iv_size = HISI_SYMM_IVLEN_SHA384,
		.blk_size = HISI_SYMM_BLKLEN_HASH_SHA512,
		.digest_size = SYMM_OUTLEN_SHA384,
	},
	{
		.alg = HISI_HASH_ALGORITHM_SHA512,
		.init_iv = (unsigned char *)std_iv_sha512,
		.iv_size = HISI_SYMM_IVLEN_SHA512,
		.blk_size = HISI_SYMM_BLKLEN_HASH_SHA512,
		.digest_size = SYMM_OUTLEN_SHA512,
	},
};

const struct hisi_symm_iv_list g_symm_mac_iv_list[] = {
	{
		.alg = HISI_CIPHER_MODE_CMAC,
		.init_iv = (unsigned char *)zero_iv,
		.iv_size = AES_BLOCK_SIZE,
		.blk_size = AES_BLOCK_SIZE,
		.digest_size = AES_BLOCK_SIZE,
	},
	{
		.alg = HISI_CIPHER_MODE_CBCMAC,
		.init_iv = (unsigned char *)zero_iv,
		.iv_size = AES_BLOCK_SIZE,
		.blk_size = AES_BLOCK_SIZE,
		.digest_size = AES_BLOCK_SIZE,
	},
	{
		.alg = HISI_CIPHER_MODE_XCBCMAC,
		.init_iv = (unsigned char *)zero_iv,
		.iv_size = AES_BLOCK_SIZE,
		.blk_size = AES_BLOCK_SIZE,
		.digest_size = AES_BLOCK_SIZE,
	},
};

const struct hisi_symm_iv_list *hicrypto_get_hash_std_iv(void)
{
	return (struct hisi_symm_iv_list *)&g_hash_iv_list;
}

const struct hisi_symm_iv_list *hicrypto_get_smac_std_iv(void)
{
	return (struct hisi_symm_iv_list *)&g_symm_mac_iv_list;
}

unsigned int hicrypto_hash_std_iv_list_size(void)
{
	return ARRAY_SIZE(g_hash_iv_list);
}

unsigned int hicrypto_smac_std_iv_list_size(void)
{
	return ARRAY_SIZE(g_symm_mac_iv_list);
}

/**
 * @brief      : symm_get_blklen
 *               get one block length according to alg
 * @param[in]  : symm crypto algorithm
 * @return     : one block length in byte
 */
unsigned int symm_get_blklen(unsigned int alg)
{
	unsigned int blklen = 0;

	switch (alg) {
		case HISI_CIPHER_ALGORITHM_AES:
			blklen = HISI_SYMM_BLKLEN_AES;
			break;
		case HISI_CIPHER_ALGORITHM_SM4:
			blklen = HISI_SYMM_BLKLEN_SM4;
			break;
		case HISI_CIPHER_ALGORITHM_DES:
			blklen = HISI_SYMM_BLKLEN_DES;
			break;
		case HISI_HASH_ALGORITHM_SHA1:
		case HISI_HASH_ALGORITHM_MD5:
		case HISI_HASH_ALGORITHM_SHA256:
		case HISI_HASH_ALGORITHM_SM3:
		case HISI_HASH_ALGORITHM_SHA224:
			blklen = HISI_SYMM_BLKLEN_HASH;
			break;
		case HISI_HASH_ALGORITHM_SHA384:
		case HISI_HASH_ALGORITHM_SHA512:
			blklen = HISI_SYMM_BLKLEN_HASH_SHA512;
			break;
		default:
			pal_error("unsupport alg = %d\n", alg);
			break;
	}
	return blklen;
}

/**
 * @brief      : symm_get_ivlen
 *               get iv length according to alg
 * @param[in]  : symm crypto algorithm
 * @return     : iv length in byte
 */
unsigned int symm_get_ivlen(unsigned int alg)
{
	const unsigned int ivlen_list[] = {
		HISI_SYMM_IVLEN_AES,    HISI_SYMM_IVLEN_SM4,    HISI_SYMM_IVLEN_DES, HISI_SYMM_IVLEN_SHA1,
		HISI_SYMM_IVLEN_MD5,    HISI_SYMM_IVLEN_SHA256, HISI_SYMM_IVLEN_SM3, HISI_SYMM_IVLEN_SHA224,
		HISI_SYMM_IVLEN_SHA384, HISI_SYMM_IVLEN_SHA512,
	};
	if (alg < (unsigned int)(ARRAY_SIZE(ivlen_list)))
		return ivlen_list[alg];

	pal_error("unsupport alg = %d\n", alg);
	return 0;
}

/**
 * @brief      : symm_get_doutlen
 *               get length of outdata
 * @param[in]  : alg hash algorithm
 * @param[in]  : mode of operation
 * @param[in]  : dinlen length of input data
 * @return     : byte length of outdata
 */
unsigned int symm_get_doutlen(unsigned int alg, unsigned int mode, unsigned int dinlen)
{
	unsigned int ivlen;
	const unsigned int hash_outlen[] = {
		SYMM_OUTLEN_SHA1,   SYMM_OUTLEN_MD5,	SYMM_OUTLEN_SHA256, SYMM_OUTLEN_SM3,
		SYMM_OUTLEN_SHA224, SYMM_OUTLEN_SHA384, SYMM_OUTLEN_SHA512,
	};

	if (alg_is_hash(alg))
		return hash_outlen[alg - HISI_HASH_ALGORITHM_SHA1];

	/* when ctr, doutlen is same to dinlen */
	if (mode_is_ctr(mode) || mode_is_xts(mode))
		return dinlen;

	ivlen = symm_get_ivlen(alg);
	/* when hash or mac, outlen is ivlen */
	if (mode_is_cmac(mode) || mode_is_cbcmac(mode))
		return ivlen;

	/* when ecb,cbc doutlen is round up by blklen */
	return round_up(dinlen, ivlen);
}