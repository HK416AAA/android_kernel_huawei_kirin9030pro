/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: crypto engine api hd custom oeminfo mac interface
 * Create: 2025/05/24
 */
#ifndef __HICRYPTO_ALG_OEMINFO_MAC_H__
#define __HICRYPTO_ALG_OEMINFO_MAC_H__

struct hicrypto_oem_mac_info {
    unsigned char *salt;
    unsigned int salt_len;
    unsigned char *in;
    unsigned int in_len;
    unsigned char *out;
    unsigned int out_len;
};

int hicrypto_oeminfo_mac(struct hicrypto_oem_mac_info *info);

#endif