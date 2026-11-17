/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: Header file of the MP17C bfgx dev external implementation.
 * Author: platform drivers
 */

#ifndef _BFGX_MP17C_H_
#define _BFGX_MP17C_H_
struct bfgx_prj_desc *mp17c_bfgx_prj_desc_init(void);
void mp17c_prj_desc_remove(void);

struct bfgx_prj_desc *mp17a_bfgx_prj_desc_init(void);
void mp17a_prj_desc_remove(void);
#endif // _BFGX_MP17C_H_