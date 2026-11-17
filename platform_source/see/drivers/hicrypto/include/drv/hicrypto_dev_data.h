/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine dev data struct
 * Create: 2023/09/18
 */

#ifndef __HICRYPTO_DEV_DATA_H__
#define __HICRYPTO_DEV_DATA_H__
#include "hicrypto_alg_def.h"
#include "hicrypto_data_type.h"

#define HISI_CTX_DATA_SIZE 2

/**
 * @brief boolean type
 */
enum sec_bool_e {
	SEC_YES = (0x05),
	SEC_NO = (0x0A),

	SEC_TRUE = (0x5452A5A5),
	SEC_FALSE = (0x4641A5A5),
};

/**
 * @brief status type
 */
enum sec_status_e {
	SEC_ON = SEC_YES,
	SEC_OFF = SEC_NO,

	SEC_ENABLE = SEC_YES,
	SEC_DISABLE = SEC_NO,

	SEC_LOCK = SEC_YES,
	SEC_UNLOCK = SEC_NO,

	SEC_MASK = SEC_YES,
	SEC_UNMASK = SEC_NO,
};

struct hisi_sg_phy_list {
	unsigned int hw_len;
	unsigned long long hw_address;
};

struct hisi_cpy_list {
	unsigned int laddr;
	unsigned int haddr_and_len;
};

/* drv info struct */
struct hisi_drv_symm_sg_list_info {
	unsigned int dinlen;
	unsigned int doutlen;
	struct hisi_sg_phy_list *pdst_list;
	struct hisi_sg_phy_list *psrc_list;
	int sg_cnt_in;
	int sg_cnt_out;
};

struct hisi_dev_cipher_param {
	unsigned int algorithm;
	unsigned int mode;
	unsigned int direction;
	unsigned int keytype;
	unsigned int keylen;
	unsigned int padding_en;
	const unsigned char *pkey;
};

struct hisi_dev_symm_data_proc {
	unsigned char txmode;
	unsigned char rxmode;
	unsigned char *pmacivin;
	unsigned int macivinlen;
	unsigned char *pmacivout;
	unsigned int macivoutlen;
	unsigned char *pivin;
	unsigned int ivinlen;
	unsigned char *pivout;
	unsigned int ivoutlen;
	struct hi_data_addr pdin[HISI_CTX_DATA_SIZE]; /* unprocess buf and input data */
	unsigned int din_num;
	unsigned int inlen;
	struct hi_data_addr pdout[HISI_CTX_DATA_SIZE]; /* output data */
	unsigned char *pb_out; /* cpu mode */
	unsigned int dout_num;
	unsigned int outlen;
	const void *pextend;
};

/* extend param for AES-CCM */
struct hisi_dev_eparam_ccm {
	unsigned int eparam_id; /* ::eparam_id */
	unsigned int payload_len;
	unsigned int aadlen;
	unsigned int nonce_len;
	const unsigned char *pnonce;
	unsigned char *ptag;
	unsigned int taglen;
};

/* extend param for AES-GCM */
struct hisi_dev_eparam_gcm {
	unsigned int eparam_id; /* ::eparam_id */
	unsigned int aadlen;
	unsigned int payload_len;
	const unsigned char *pgctr_j0;
	unsigned int gctr_j0len;
	unsigned char *ptag;
	unsigned int taglen;
};

/* extend param ID, used by hal and reg */
enum hisi_dev_eparam_id {
	HISI_EPARAM_ID_CCM = 0,
	HISI_EPARAM_ID_GCM,
	HISI_EPARAM_ID_GMAC,
	HISI_EPARAM_ID_CIPHER,
};

enum hisi_drv_symm_mode {
	/* ccm mode, start from HISI_SYMM_BASE_MODE_MAX */
	HISI_SYMM_MODE_CCM_ENC = HISI_CIPHER_MODE_MAX + 1,

	/* gcm mode */
	HISI_SYMM_MODE_GCM_IV_INIT,
	HISI_SYMM_MODE_GHASH,
	HISI_SYMM_MODE_GMAC,
	HISI_SYMM_MODE_GCM_ENC,

	HISI_SYMM_MODE_MAX,

	HISI_SYMM_MODE_BYPASS = 0x7FFFFFFF
};

struct hisi_dev_data {
	unsigned int blk_len;
	/* cur to be processed */
	struct hi_data_addr pdin_cur[HISI_CTX_DATA_SIZE];
	unsigned int din_num_cur;
	unsigned int inlen_cur;
	struct hi_data_addr pdout_cur[HISI_CTX_DATA_SIZE];
	unsigned int dout_num_cur;
	unsigned int outlen_cur;
 
	/* unprocessed data */
	struct hi_data_addr pdin_unproc[HISI_CTX_DATA_SIZE];
	unsigned int din_num_unproc;
	unsigned int inlen_unproc;
	struct hi_data_addr pdout_unproc[HISI_CTX_DATA_SIZE];
	unsigned int dout_num_unproc;
	unsigned int outlen_unproc;
};

#endif