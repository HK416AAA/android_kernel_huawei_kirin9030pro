/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine ioctl driver
 * Create: 2024/12/23
 */
#ifndef __HICRYPRO_LDK_IOCTL_H
#define __HICRYPRO_LDK_IOCTL_H

#include <linux/ioctl.h>
#include <linux/types.h>

#include "hicrypto_driver.h"
#include "hicrypto_alg_oeminfo_mac.h"

#include "platform_include/see/hicrypto_engine.h"

struct hicrypt_cipher_ctx {
	unsigned int alg_id;
	unsigned int dir;
	/* up final digest */
	unsigned char stage;
	/* key */
	unsigned int keytype;
	unsigned int key_len;
	unsigned char *key;

	unsigned int total_bytes;      /* processed total len bytes eg.cmac */
	unsigned int un_processed_len;
	unsigned char *un_processed_buf;

	unsigned char  *iv;
	unsigned int iv_len;

	unsigned char *src;
	unsigned int src_len;
	unsigned char *dst;
	unsigned int dst_len;
};

/* input of CIOCCRYPT */
struct hicrypt_hash_single_ctx {
    unsigned int stage;
    unsigned int alg_id;
    unsigned char *in;
    unsigned int in_len;
    unsigned char *out;
    unsigned int out_len;
};

/* magic number */
#define HICRYPTO_IOCTL 0xdf

/* cmd type */
enum hicrypto_ioctl_cmd {
	HICRYPTO_HASH_CMD = 0x5,
	HICRYPTO_DFT_PERF_CMD = 0x6,
	HICRYPTO_EN_PERF_CMD = 0x7,

	HICRYPTO_CIPHER_SINGLE_CMD = 0xA8,
	HICRYPTO_AES_CMAC_OEMINFO_CMD = 0xAA,
	HICRYPTO_AES_CMAC_NVE_CMD = 0xAC,
};

#define HICRYPTO_AES_CMAC_OEM _IOWR(HICRYPTO_IOCTL, HICRYPTO_AES_CMAC_OEMINFO_CMD, struct hicrypto_oem_mac_info)

#define HICRYPTO_AES_CMAC_NVE _IOWR(HICRYPTO_IOCTL, HICRYPTO_AES_CMAC_NVE_CMD, struct hicrypto_nve_mac_info)
#define HICRYPTO_HASH _IOWR(HICRYPTO_IOCTL, HICRYPTO_HASH_CMD, struct hicrypt_hash_single_ctx)
#define HICYPTO_CIPHER_SINGLE _IOWR(HICRYPTO_IOCTL, HICRYPTO_CIPHER_SINGLE_CMD, struct hicrypt_cipher_ctx)
#define HICRYPTO_DFT_PERF _IOWR(HICRYPTO_IOCTL, HICRYPTO_DFT_PERF_CMD, struct hat_fun_hit_info)
#define HICRYPTO_EN_PERF _IOWR(HICRYPTO_IOCTL, HICRYPTO_EN_PERF_CMD, unsigned int)

int hicrypto_ioctl_oeminfo_mac(struct hicrypto_oem_mac_info *info);

int hicrypto_ioctl_nve_mac(struct hicrypto_nve_mac_info *info);
int hicrypto_ioctl_cipher_single(struct hicrypt_cipher_ctx *cipher_ctx);
int hicrypto_ioctl_hash(struct hicrypt_hash_single_ctx *hash_ctx);
int hicrypto_ioctl_get_perf(unsigned int cmd, unsigned long arg);
int hicrypto_ioctl_en_perf(unsigned int cmd, unsigned long arg);

int hicrypto_prof_register_cdev(struct hicrypto_device *hdev);
int hicrypto_prof_unregister_cdev(struct hicrypto_device *hdev);
#endif