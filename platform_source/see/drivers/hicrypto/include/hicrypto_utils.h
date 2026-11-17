/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine general small tools
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_UTILS_H__
#define __HICRYPTO_UTILS_H__
#include <linux/types.h>

#include "hicrypto_macro.h"
#include "hicrypto_data_type.h"
#include "hicrypto_log.h"

static inline int hicrypto_find_in_array(const unsigned int *arr, unsigned int arr_size, unsigned int val)
{
	unsigned int i, flag;

	flag = 0;
	for (i = 0; i < arr_size; i++) {
		if (arr[i] == val) {
			flag = 1;
			break;
		}
	}

	return flag;
}

#endif /* end of __UTILS_H__ */
