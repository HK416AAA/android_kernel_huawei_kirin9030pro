/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine platform-independ dft
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_DFT_H__
#define __HICRYPTO_DFT_H__
#include <linux/timer.h>
#include "hicrypto_data_type.h"
#include "hicrypto_errno.h"

#if !defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) || !CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
#define pal_hit_start(test_func) do_nothing()
#define pal_hit_end(test_func) do_nothing()
#define pal_hit_time() do_nothing()

#else /* CONFIG_CRYPTO_HICRYPTO_V2_DEBUG */
#define HAT_FUN_NAME_MAX  64
#define HAT_HIT_POINT_MAX 20

struct hat_hit_cost {
	const char  start_func[HAT_FUN_NAME_MAX];
	const char  end_func[HAT_FUN_NAME_MAX];
	u32 start_line;
	u32 end_line;
	uint64_t cost_time;
};

struct hat_fun_hit_info {
	struct hat_hit_cost *hat_cost_detail;
	u32 hat_cost_num;
	u32 hit_time_num;
};

void hat_hit_time(const char *pfunc, u32 line);

void hat_hit_start(const char *ptest_func, const char *pfunc, u32 line);

void hat_hit_end(const char *ptest_func, const char *pfunc, u32 line);

int hat_get_hit_detail(struct hat_fun_hit_info *pfunc_detail_cost);

uint64_t hat_get_detail_by_id(u32 indx);

int hat_set_hit_en(u32 enable);
void hat_hit_time(const char *pfunc, u32 line);

#define pal_hit_start(test_func) hat_hit_start(test_func, __func__, __LINE__)

#define pal_hit_end(test_func) hat_hit_end(test_func, __func__, __LINE__)

#define pal_hit_time() hat_hit_time(__func__, __LINE__)

#endif /* CONFIG_CRYPTO_HICRYPTO_V2_DEBUG */

#endif /* __HICRYPTO_DFT_H__ */
