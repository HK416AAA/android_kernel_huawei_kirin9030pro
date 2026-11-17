/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: header file to provide plat utils
 * Create: 2025/04/10
 */
#ifndef __DEV_HICRYPTO_UDK_CALLBACK_H__
#define __DEV_HICRYPTO_UDK_CALLBACK_H__
#include <linux/types.h>
#include <platform_include/see/hicrypto_udk_for_ldk.h>

#define CCZ_KEY_QUEUE_NAME       "ccz_key"
#define CCZ_KEY_BUFF_LEN         24

struct hicrypt_oeminfo_mac {
    u8 *salt;
    u32 salt_len;
    u8 *in;
    u32 in_len;
    u8 *out;
    u32 out_len;
};

int hicrypto_udk_callback(unsigned int cmd, void *rd, size_t rd_size, void *wr, size_t wr_size);

u32 hicrypto_cfg_ccz_key_by_tee(unsigned char *key_wrap, size_t key_size);

u32 hicrypto_oem_mac_by_tee(struct hicrypt_oeminfo_mac *info);
s32 hicrypto_tee_oem_mac(void *rd, size_t rd_size , void *wr, size_t wr_size);

#endif /* __DEV_HICRYPTO_UDK_CALLBACK_H__ */
