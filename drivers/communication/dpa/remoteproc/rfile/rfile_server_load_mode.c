/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 */
#include "bsp_rfile.h"

#define THIS_MODU mod_rfile

bsp_fs_status_e g_rfile_fs_is_support = BSP_FS_OK;


bsp_fs_status_e rfile_get_fs_is_support(void)
{
    return g_rfile_fs_is_support;
}
