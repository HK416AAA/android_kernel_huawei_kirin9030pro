/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine alg common def
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_CTX_DEF_H__
#define __HICRYPTO_CTX_DEF_H__
#include "hicrypto_alg_def.h"
#include "hicrypto_driver.h"

#define CRYPTO_MINALIGN 128
#define CRYPTO_MINALIGN_ATTR __attribute__((__aligned__(CRYPTO_MINALIGN)))

union hi_cipher_id {
	unsigned int value;
	struct {
		unsigned char mode;
		unsigned char pad;
		unsigned char alg;
		unsigned char type;
	} id;
};

union hi_aead_id {
	unsigned int value;
	struct {
		unsigned char mode;
		unsigned char reserved;
		unsigned char alg;
		unsigned char type;
	} id;
};

union hi_hash_id {
	unsigned int value;
	struct {
		unsigned char mode;
		unsigned char reserved;
		unsigned char alg;
		unsigned char type;
	} id;
};

union hi_mac_id {
	unsigned int value;
	struct {
		unsigned char mode;
		unsigned char pad;
		unsigned char alg;
		unsigned char type;
	} id;
};

union hi_ctx_flag {
	unsigned int value;
	struct {
		unsigned int in_flags : 4;  /* bit[0-3] */
		unsigned int out_flags : 4; /* bit[4:7] */
		unsigned int aad_flags : 4; /* bit[8:11] */
		unsigned int key_flags : 4; /* bit[8:11] */
		unsigned int iv_flags : 4;  /* bit[8:11] */
		unsigned int reserved : 12;
	} id;
};

/* aead ctx */
struct hi_aead_req_ctx_inner {
	/* device info */
	struct hicrypto_device *hdev;

	/* alg info */
	unsigned int alg;

	unsigned int mode;
	unsigned int keytype;
	unsigned int pad;
	unsigned int dir;
	unsigned int flags;
	unsigned char stage;
	/* key */
	unsigned char key[HICRYPTO_MAX_KEY_SIZE];
	unsigned int keylen;
	/* iv */
	unsigned int iv_len;
	unsigned char iv[AES_BLOCK_SIZE];

	unsigned char aes_mac_iv[AES_BLOCK_SIZE]; /* aes_ghash_iv */
	unsigned char aes_ctr_iv[AES_BLOCK_SIZE]; /* aes_gctr_iv */
	unsigned char aes_gctr_j0[AES_BLOCK_SIZE];

	unsigned int aadlen;
	unsigned int payload_len; /* current process payload len */
	unsigned int total_len; /* processed payload len */
	unsigned int taglen;
	unsigned char tag[AES_BLOCK_SIZE];
	unsigned char authtag[AES_BLOCK_SIZE];

	unsigned int blen; /* unprocess data */
	unsigned char buf[AES_KEYSIZE_256];

	/* extend para */
	unsigned int ext_ctx_size;
	void *__ctx[] CRYPTO_MINALIGN_ATTR; // extend para eg:crypto_async_request
};

/* cipher ctx */
struct hi_skcipher_req_ctx_inner {
	/* device info */
	struct hicrypto_device *hdev;

	/* cipher info */
	unsigned int alg;
	unsigned int mode;
	unsigned int keytype;
	unsigned int pad;
	unsigned int dir;
	unsigned int flags;
	unsigned char stage;

	unsigned char key[HICRYPTO_MAX_KEY_SIZE];
	unsigned int keylen;
	unsigned char iv[HISI_SHA_MAX_BLOCKSIZE];
	unsigned int iv_len;

	unsigned int crypto_len;
	unsigned int blen; /* unprocess data */
	unsigned char buf[AES_KEYSIZE_256];

	/* extend para */
	unsigned int ext_ctx_size;
	void *__ctx[] CRYPTO_MINALIGN_ATTR; // extend para eg:crypto_async_request
};

/* hash ctx */
struct hi_hash_req_ctx_inner {
	/* device info */
	struct hicrypto_device *hdev;

	/* alg info */
	unsigned int alg;
	unsigned int flags;

	/* up final digest */
	unsigned char stage;

	unsigned long long cur_process_bytes; /* cur process bytes in blknum * blklen */
	unsigned int cur_remain_bytes;	      /* cur remain bytes */
	unsigned int total_bytes;	      /* processed total len bytes */
	unsigned int un_processed_len;
	unsigned char un_processed_buf[HISI_SHA_MAX_BLOCKSIZE];

	unsigned char digest[HISI_MAX_SHA_CONTEXT_SIZE];
	unsigned int digest_len;
	unsigned int iv_len;
	unsigned int blk_len;

	/* extend para */
	unsigned int ext_ctx_size;
	void *__ctx[] CRYPTO_MINALIGN_ATTR; // extend para eg:crypto_async_request
};

/* mac ctx */
struct hi_mac_req_ctx_inner {
	/* device info */
	struct hicrypto_device *hdev;

	/* alg info */
	unsigned int alg;
	unsigned int mode;
	unsigned int keytype;
	unsigned int pad;
	unsigned int dir;
	unsigned int flags;
	/* key */
	unsigned int key_len;
	unsigned char key[HISI_SHA_MAX_BLOCKSIZE];

	/* up final digest */
	unsigned char stage;

	unsigned long long cur_process_bytes;	       /* cur process bytes in blknum * blklen */
	unsigned int cur_remain_bytes; /* cur remain bytes */
	unsigned int total_bytes;      /* processed total len bytes */
	unsigned int un_processed_len;
	unsigned char un_processed_buf[HISI_SHA_MAX_BLOCKSIZE];

	/* digest/iv in and out */
	unsigned char digest[HISI_MAX_SHA_CONTEXT_SIZE];
	unsigned int digest_len;
	unsigned int iv_len;
	unsigned int blk_len;
	/* symm mac out */
	unsigned char pout[HISI_SYMM_BLKLEN_AES];

	/* extend para */
	unsigned int ext_ctx_size;
	void *__ctx[]; // extend para eg:crypto_async_request
};

struct hi_km_wrap_ctx_inner {
	unsigned int wrapmode;
	unsigned int key_type;
	unsigned int alg_type;
	unsigned int keybuff_waddr; /* 0 ~ 15 */
};

struct hi_km_export_ctx_inner {
	unsigned int export_din_sel;
	unsigned int key_type;
	unsigned int alg_type;
	unsigned int dinlen;
	unsigned int key_len;
};
#endif