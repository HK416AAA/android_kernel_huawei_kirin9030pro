/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: nvme wrapper driver
 * in kernel.
 */
#ifndef __HICRYPTO_UDK_FOR_LDK_H__
#define __HICRYPTO_UDK_FOR_LDK_H__

/* for UDK call LDK */
#define  HICRYPTO_PROXY_MAJOR_CMD     11
enum {
	HICRYPTO_UDKCLDK_CCZ_KEY_CMD = 0,
	HICRYPTO_UDKCLDK_TEE_OEM_MAC_CMD = 1,
	HICRYPTO_UDKCLDK_CMD_MAX,
};

/* for LDK call UDK */
#define  UDK_HICRYPTO_PROXY_MAJOR_CMD 11
enum {
	HICRYPTO_LDKCUDK_NVE_MAC_CMD = 0,
	HICRYPTO_LDKCUDK_CMD_MAX,
};

struct hicrypto_nve_mac_info {
    unsigned char *salt;
    unsigned int salt_len;
    unsigned char *in;
    unsigned int in_len;
    unsigned char *out;
    unsigned int out_len;
};

#endif
