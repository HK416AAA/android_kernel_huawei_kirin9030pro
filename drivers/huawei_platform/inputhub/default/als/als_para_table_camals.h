/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 * Description: als para table camAls header file
 * Author: chenxu c30072497
 * Create: 2025-06-05
 */

#ifndef __ALS_PARA_TABLE_CAM_ALS_H__
#define __ALS_PARA_TABLE_CAM_ALS_H__

#include "als_para_table.h"

camals_als_para_table *als_get_camals_table_by_id(uint32_t id);
camals_als_para_table *als_get_camals_first_table(void);
uint32_t als_get_camals_table_count(void);

#endif
