/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_AES_H
#define OAL_AES_H

#include "oal_types.h"


#define OAL_AES_MAX_KEYLENGTH       60

struct oal_aes_key_stru {
    uint32_t ul_key_enc[OAL_AES_MAX_KEYLENGTH];
    uint32_t ul_key_dec[OAL_AES_MAX_KEYLENGTH];
    uint32_t ul_key_length;
} __attribute__((__packed__));

typedef struct oal_aes_key_stru oal_aes_key_stru;

#endif
