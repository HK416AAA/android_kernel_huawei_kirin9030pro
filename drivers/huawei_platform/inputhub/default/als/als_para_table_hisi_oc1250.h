
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: als para table ams tcs3743 header file
 * Author: chenjianchun 30067147
 * Create: 2023-11-01
 */

#ifndef __ALS_PARA_TABLE_HISI_OC1250_H__
#define __ALS_PARA_TABLE_HISI_OC1250_H__

#include "als_para_table.h"

hisi_oc1250_als_para_table *als_get_hisi_oc1250_table_by_id(uint32_t id);
hisi_oc1250_als_para_table *als_get_hisi_oc1250_first_table(void);
uint32_t als_get_hisi_oc1250_table_count(void);

#endif