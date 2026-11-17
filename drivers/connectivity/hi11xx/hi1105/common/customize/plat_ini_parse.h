/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: hisi_ini_parse.c header file
 * Author: common drivers
 */

#ifndef HISI_INI_PARSE_H
#define HISI_INI_PARSE_H

#ifdef CONN_INI_FILE_PRE_PARSE

int32_t plat_parse_ini(const char *filename);
int32_t plat_get_config_string(const char *section, const char *key, char *value, uint32_t size);
void plat_ini_free_config(void);
uint32_t plat_ini_file_parsed(void);
#else
OAL_STATIC OAL_INLINE int32_t plat_parse_ini(const char *filename)
{
    return 0;
}

OAL_STATIC OAL_INLINE int32_t plat_get_config_string(const char *section, const char *key, char *value, uint32_t size)
{
    return 0;
}

OAL_STATIC OAL_INLINE void plat_ini_free_config(void)
{
    return;
}

OAL_STATIC OAL_INLINE uint32_t plat_ini_file_parsed(void)
{
    return OAL_FALSE;
}
#endif

#endif
