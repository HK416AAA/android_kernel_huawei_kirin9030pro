/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: nvme wrapper driver
 * in kernel.
 */
#ifndef __HICRYPTO_ENGINE_H__
#define __HICRYPTO_ENGINE_H__

struct hicrypto_nve_mac_info {
    unsigned char *salt;
    unsigned int salt_len;
    unsigned char *in;
    unsigned int in_len;
    unsigned char *out;
    unsigned int out_len;
};

int hicrypto_nve_mac(struct hicrypto_nve_mac_info *info);

#endif
