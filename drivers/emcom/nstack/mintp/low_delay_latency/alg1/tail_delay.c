/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * License terms: GNU General Public License (GPL)
 * Author: liyue
 *
 * MinTP Tail Delay Latency Alg.
 */

#include <linux/sort.h>

#include "../../mintp_log.h"
#include "utils.h"
#include "tail_delay.h"

#define NINTY 90
#define NINTY_FIVE 95
#define NINTY_NINE 99
#define ONE_THOUSAND 1000
#define TEN_THOUSAND 10000
#define FIFTY_THOUSAND 50000
#define NINE_NINE_FIVE 995
#define LARGE_NUM 1000000LL

typedef struct {
	u64 T;
	u64 P;
	u64 one_minus_p1;
	u64 t1;
	u64 t2;
} calc_result;

typedef struct {
	u64 t1;
	u64 t2;
} t_pair;

typedef struct {
	u64 *array_p90;
	u64 *array_p95;
	u64 *array_p99;
	int count;
	u64 t_90;
	u64 t_95;
	u64 t_99;
} history_data_param;

typedef struct {
	u64 *be_data;
	int count_be;
	u64 **owd_be;
	u64 **cdf_be;
	u64 **t1_values;
	int *t1_size;
} calc_be_param;

typedef struct {
	u64 *vi_data;
	int count_vi;
	u64 **rtt_vi;
	u64 **cdf_vi;
	u64 **t2_values;
	int *t2_size;
} calc_vi_param;

typedef struct {
	u64 *t1_values;
	int t1_size;
	u64 *t2_values;
	int t2_size;
	u64 *sort_owd_be;
	u64 *cdf_be;
	int n_be;
	u64 *sort_rtt_vi;
	u64 *cdf_vi;
	int n_vi;
	int result_size;
} calculate_p_t_grid_param;

typedef struct {
	u64 *be_data;
	int count_be;
	u64 *vi_data;
	int count_vi;
	u64 last_reTime;
	int *flag;
} calc_retx_time_param;

delay_tune_alg *init_alg(u64 re_tx_time)
{
	int j = 0;
	delay_tune_alg *alg_inst = (delay_tune_alg *)kmalloc(sizeof(delay_tune_alg), GFP_ATOMIC);
	if (alg_inst == NULL)
		return NULL;
	alg_inst->delay_be = (u64 *)kmalloc(MAX_DELAY_LENGTH * sizeof(u64), GFP_ATOMIC);
	if (alg_inst->delay_be == NULL)
		goto free_algInst;
	alg_inst->delay_vi = (u64 *)kmalloc(MAX_DELAY_LENGTH * sizeof(u64), GFP_ATOMIC);
	if (alg_inst->delay_vi == NULL)
		goto free_delay_be;
	for (j = 0; j < CHANNEL_COUNT; ++j) {
		alg_inst->arr_idx[j] = 0;
		alg_inst->full_flag[j] = 0;
	}
	alg_inst->curr_rate = 0;
	alg_inst->history_count = 0;

	alg_inst->last_retx_time = re_tx_time;
	alg_inst->new_retx_time = re_tx_time;
	alg_inst->update_flag = 0;
	alg_inst->new_data_count = 0;
	return alg_inst;

free_delay_be:
	kfree(alg_inst->delay_be);
	alg_inst->delay_be = NULL;
free_algInst:
	kfree(alg_inst);
	alg_inst = NULL;
	return alg_inst;
}

void de_init_alg(delay_tune_alg *implement)
{
	kfree(implement->delay_be);
	implement->delay_be = NULL;
	kfree(implement->delay_vi);
	implement->delay_vi = NULL;
	kfree(implement);
	implement = NULL;
}

void save_data(delay_tune_alg *implement, u64 delay, enum Channel chan)
{
	int idx = implement->arr_idx[chan];
	if (chan != BE && chan != VI)
		return;
	if (chan == BE)
		implement->delay_be[idx] = delay;
	else {
		implement->delay_vi[idx] = delay;
	}

	idx += 1;
	if (idx > MAX_DELAY_LENGTH - 1) {
		implement->full_flag[chan] = 1;
	}
	implement->arr_idx[chan] = idx % MAX_DELAY_LENGTH;
	mtp_debug("[tail_delay] save_data chan %d implement->new_data_count %d BE? %d",
		chan, implement->new_data_count, chan == BE);
	if (chan == BE)
		implement->new_data_count++;
}

void save_rate(delay_tune_alg *implement, u64 rate)
{
	implement->curr_rate = rate;
}

static int compare_u64(const void *a, const void *b)
{
	u64 arg1 = *(const u64 *)a;
	u64 arg2 = *(const u64 *)b;

	if (arg1 < arg2)
		return -1;
	if (arg1 > arg2)
		return 1;
	return 0;
}

static u64 get_percent_delay(delay_tune_alg *implement, int percent, enum Channel chan)
{
	int flag = 0;
	int i = 0;
	int index = 0;
	int length = 0;
	u64 result = 0;
	u64 *arrayCopy = NULL;
	if (chan != BE)
		return 0;
	flag = implement->full_flag[chan];
	length = implement->arr_idx[chan];

	if (flag) {
		length = MAX_DELAY_LENGTH;
	} else if (length < MIN_DELAY_LENGTH) {
		return 0;
	}

	arrayCopy = (u64 *)kmalloc(length * sizeof(u64), GFP_ATOMIC);
	if (arrayCopy == NULL)
		return 0;
	for (i = 0; i < length; i++)
		arrayCopy[i] = implement->delay_be[i];

	sort(arrayCopy, length, sizeof(u64), compare_u64, NULL);
	index = (int)(percent * length / ONE_HUNDRED);
	if (index >= length) {
		index = length - 1;  /* 索引超出范围时调整到最后一个元素 */
	}
	result = arrayCopy[index];

	kfree(arrayCopy);  /* 释放内存 */
	return result;
}

static t_pair get_opt_solution(calc_result *grid_results, int result_size)
{
	int i = 0;
	int p1_size = 0;
	t_pair optT = {0, 0};
	u64 *boundary_one_minus_p1 = NULL;
	u64 *boundary_T = NULL;
	calc_result *boundary_t1_t2 = NULL;
	u64 min_T = 0;
	u64 *smoothed_T = NULL;
	u64 *first_derivative = NULL;
	int max_idx = 0;
	calc_result min_t1_t2;
	int j = 0;
	u64 opt_t1 = 0;
	u64 opt_t2 = 0;
	int boundary_size = 0;
	spline_interpolate_param spline_interpolate_p = {};
	u64 *one_minus_p1_sort = (u64 *)kmalloc(result_size * sizeof(u64), GFP_ATOMIC);
	if (one_minus_p1_sort == NULL) {
		mtp_err("[tail_delay] kmalloc one_minus_p1_sort failed.");
		return optT;
	}

	for (i = 0; i < result_size; i++) {
		one_minus_p1_sort[i] = grid_results[i].one_minus_p1;
	}
	sort(one_minus_p1_sort, result_size, sizeof(u64), compare_u64, NULL);
	p1_size = remove_duplicates(one_minus_p1_sort, result_size);

	boundary_one_minus_p1 = (u64 *)kmalloc(p1_size * sizeof(u64), GFP_ATOMIC);
	if (boundary_one_minus_p1 == NULL) {
		mtp_err("[tail_delay] kmalloc boundary_one_minus_p1 size %d failed.", p1_size);
		goto free_one_minus_p1_sort;
	}
	boundary_T = (u64 *)kmalloc(p1_size * sizeof(u64), GFP_ATOMIC);
	if (boundary_T == NULL) {
		mtp_err("[tail_delay] kmalloc boundary_T size %d failed.", p1_size);
		goto free_boundary_one_minus_p1;
	}
	boundary_t1_t2 = (calc_result *)kmalloc(p1_size * sizeof(calc_result), GFP_ATOMIC);
	if (boundary_t1_t2 == NULL) {
		mtp_err("[tail_delay] kmalloc boundary_t1_t2 size %d failed.", p1_size);
		goto free_boundary_T;
	}

	/* 找到边界值 */
	for (i = 0; i < p1_size; i++) {
		min_T = LARGE_NUM;
		for (j = 0; j < result_size; j++) {
			if (grid_results[j].one_minus_p1 == one_minus_p1_sort[i] && grid_results[j].T < min_T) {
				min_T = grid_results[j].T;
				min_t1_t2 = grid_results[j];
			}
		}
		if (min_T < LARGE_NUM) {
			boundary_one_minus_p1[boundary_size] = one_minus_p1_sort[i];
			boundary_T[boundary_size] = min_T;
			boundary_t1_t2[boundary_size] = min_t1_t2;
			boundary_size++;
		}
	}

	/* 样条插值和平滑 */
	smoothed_T = (u64 *)kmalloc(boundary_size * sizeof(u64), GFP_ATOMIC);
	if (smoothed_T == NULL) {
		mtp_err("[tail_delay] kmalloc smoothed_T size %d failed.", boundary_size);
		goto free_boundary_t1_t2;
	}

	spline_interpolate_p.x = boundary_one_minus_p1;
	spline_interpolate_p.y = boundary_T;
	spline_interpolate_p.n = boundary_size;
	spline_interpolate_p.xnew = boundary_one_minus_p1;
	spline_interpolate_p.ynew = smoothed_T;
	spline_interpolate_p.nnew = boundary_size;

	spline_interpolate(spline_interpolate_p);
	/* 计算导数 */
	first_derivative = (u64 *)kmalloc(boundary_size * sizeof(u64), GFP_ATOMIC);
	if (first_derivative == NULL) {
		mtp_err("[tail_delay] kmalloc first_derivative size %d failed.", boundary_size);
		goto free_smoothed_T;
	}
	compute_gradient(smoothed_T, boundary_one_minus_p1, first_derivative, boundary_size);

	max_idx = find_max_index(first_derivative, boundary_size);
	opt_t1 = boundary_t1_t2[max_idx].t1;
	opt_t2 = boundary_t1_t2[max_idx].t2;
	optT.t1 = opt_t1;
	optT.t2 = opt_t2;
	kfree(first_derivative);

free_smoothed_T:
	kfree(smoothed_T);
free_boundary_t1_t2:
	kfree(boundary_t1_t2);
free_boundary_T:
	kfree(boundary_T);
free_boundary_one_minus_p1:
	kfree(boundary_one_minus_p1);
free_one_minus_p1_sort:
	kfree(one_minus_p1_sort);
	return optT;
}

static void calc_be_time(calc_be_param calc_be_time_p)
{
	int j = 0;
	*calc_be_time_p.owd_be = (u64 *)kmalloc(calc_be_time_p.count_be * sizeof(u64), GFP_ATOMIC);
	if (*calc_be_time_p.owd_be == NULL) {
		mtp_err("[tail_delay] owd_be is NULL, failed.");
		return;
	}
	for (j = 0; j < calc_be_time_p.count_be; ++j) {
		(*calc_be_time_p.owd_be)[j] = (u64)calc_be_time_p.be_data[j];  /* 单位ms */
	}

	/* 计算90-99百分位数 */
	sort(*calc_be_time_p.owd_be, calc_be_time_p.count_be, sizeof(u64), compare_u64, NULL);
	*calc_be_time_p.cdf_be = (u64 *)kmalloc(calc_be_time_p.count_be * sizeof(u64), GFP_ATOMIC);
	if (*calc_be_time_p.cdf_be == NULL) {
		kfree(*calc_be_time_p.owd_be);
		return;
	}
	calculate_cdf(*calc_be_time_p.owd_be, calc_be_time_p.count_be, *calc_be_time_p.cdf_be);

	u64 t1_90_percentile = percentile(*calc_be_time_p.owd_be, calc_be_time_p.count_be, NINTY * SCALE);
	u64 t1_99_percentile = percentile(*calc_be_time_p.owd_be, calc_be_time_p.count_be, NINTY_NINE * SCALE);
	*calc_be_time_p.t1_size = ONE_HUNDRED;
	if (t1_90_percentile == t1_99_percentile) {
		mtp_debug("[tail_delay] t1_90_percentile is equal to t1_99_percentile %lu", t1_90_percentile);
		return;
	}
	*calc_be_time_p.t1_values = linspace(t1_90_percentile, t1_99_percentile, *calc_be_time_p.t1_size);
	if (*calc_be_time_p.t1_values == NULL) {
		mtp_debug("[tail_delay] t1_values is NULL");
	}
}

static void calc_vi_time(calc_vi_param calc_vi_time_p)
{
	int j = 0;
	u64 rtt_vi_max = 0;
	u64 rtt_vi_min = 0;
	if (calc_vi_time_p.count_vi <= 0) {
		mtp_debug("[tail_delay] count_vi %d", calc_vi_time_p.count_vi);
		return;
	}
	*calc_vi_time_p.rtt_vi = (u64 *)kmalloc(calc_vi_time_p.count_vi * sizeof(u64), GFP_ATOMIC);
	if (*calc_vi_time_p.rtt_vi == NULL) {
		mtp_err("[tail_delay] kmalloc rtt_vi size %d failed.", calc_vi_time_p.count_vi);
		return;
	}
	for (j = 0; j < calc_vi_time_p.count_vi; ++j) {
		(*calc_vi_time_p.rtt_vi)[j] = (u64)calc_vi_time_p.vi_data[j];  /* 单位ms */
	}

	/* 计算RTT的范围 */
	sort(*calc_vi_time_p.rtt_vi, calc_vi_time_p.count_vi, sizeof(u64), compare_u64, NULL);
	*calc_vi_time_p.cdf_vi = (u64 *)kmalloc(calc_vi_time_p.count_vi * sizeof(u64), GFP_ATOMIC);
	if (*calc_vi_time_p.cdf_vi == NULL) {
		kfree(*calc_vi_time_p.rtt_vi);
		return;
	}
	calculate_cdf(*calc_vi_time_p.rtt_vi, calc_vi_time_p.count_vi, *calc_vi_time_p.cdf_vi);
	rtt_vi_min = (*calc_vi_time_p.rtt_vi)[0];
	rtt_vi_max = (*calc_vi_time_p.rtt_vi)[calc_vi_time_p.count_vi - 1];
	*calc_vi_time_p.t2_size = ONE_HUNDRED;
	*calc_vi_time_p.t2_values = linspace(rtt_vi_min, rtt_vi_max, *calc_vi_time_p.t2_size);
}

static u64 interp(u64 x, u64 *xp, u64 *fp, int n)
{
	int i = 0;
	if (n - 1 < 1) {
		mtp_err("[tail_delay] interp: invalid n");
		return 0;
	}
	if (x <= xp[0]) {
		return fp[0];
	}
	if (x >= xp[n - 1]) {
		return fp[n - 1];
	}
	for (i = 0; i < n - 1; i++) {
		if (x >= xp[i] && x <= xp[i + 1]) {
			u64 delta_x = xp[i + 1] - xp[i];
			if (delta_x == 0) {
				mtp_err("[tail_delay] interp: zero delta_x");
				return fp[i];
			}
			u64 slope = (fp[i + 1] - fp[i]) * (x - xp[i]) / delta_x;
			return fp[i] + slope;
		}
	}
	mtp_err("[tail_delay] interp: x out of bounds");
	return 0;
}

static calc_result *calculate_p_t_grid_with_constraints(calculate_p_t_grid_param *calculate_p_t_grid_p)
{
	int count = 0;
	int i = 0;
	int j = 0;
	u64 t1 = 0;
	u64 t2 = 0;
	u64 P = 0, T = 0, one_minus_p1 = 0;
	calc_result *results = (calc_result *)kmalloc(
		calculate_p_t_grid_p->t1_size * calculate_p_t_grid_p->t2_size * sizeof(calc_result), GFP_ATOMIC);
	if (results == NULL) {
		mtp_err("[tail_delay] kmalloc results size %d failed.",
			calculate_p_t_grid_p->t1_size * calculate_p_t_grid_p->t2_size);
		return NULL;
	}

	for (i = 0; i < calculate_p_t_grid_p->t1_size; i++) {
		for (j = 0; j < calculate_p_t_grid_p->t2_size; j++) {
			t1 = calculate_p_t_grid_p->t1_values[i];
			t2 = calculate_p_t_grid_p->t2_values[j];

			u64 p1 = interp(t1, calculate_p_t_grid_p->sort_owd_be, calculate_p_t_grid_p->cdf_be, calculate_p_t_grid_p->n_be);
			u64 p2 = interp(t2, calculate_p_t_grid_p->sort_rtt_vi, calculate_p_t_grid_p->cdf_vi, calculate_p_t_grid_p->n_vi);
			P = p1 + (SCALE - p1) * p2 / SCALE;
			T = t1 + t2;
			one_minus_p1 = SCALE - p1;
			if (T < FIFTY_THOUSAND && P > (NINE_NINE_FIVE * SCALE / ONE_THOUSAND)) {  /* 只要符合约束条件的t1和t2 */
				results[count].T = T;
				results[count].P = P;
				results[count].one_minus_p1 = one_minus_p1;
				results[count].t1 = t1;
				results[count].t2 = t2;
				count++;
			}
		}
	}

	calculate_p_t_grid_p->result_size = count;
	return results;
}

static u64 get_opt_retx_time(calc_retx_time_param *calc_retx_time_p)
{
	t_pair optT;
	u64 *owd_be, *cdf_be, *t1_values;
	int num_t1_values;
	u64 *rtt_vi, *cdf_vi, *t2_values;
	int num_t2_values;
	*calc_retx_time_p->flag = 0;
	calculate_p_t_grid_param calculate_p_t_grid_p = {};
	calc_be_param calc_be_p = {};
	calc_vi_param calc_vi_p = {};
	calc_be_p.be_data = calc_retx_time_p->be_data;
	calc_be_p.count_be = calc_retx_time_p->count_be;
	calc_be_p.owd_be = &owd_be;
	calc_be_p.cdf_be = &cdf_be;
	calc_be_p.t1_values = &t1_values;
	calc_be_p.t1_size = &num_t1_values;

	/* 计算原始流（BE）CDF */
	calc_be_time(calc_be_p);
	if (owd_be == NULL || cdf_be == NULL || num_t1_values == 0 || t1_values == NULL)
		return calc_retx_time_p->last_reTime;
	calc_vi_p.vi_data = calc_retx_time_p->vi_data;
	calc_vi_p.count_vi = calc_retx_time_p->count_vi;
	calc_vi_p.rtt_vi = &rtt_vi;
	calc_vi_p.cdf_vi = &cdf_vi;
	calc_vi_p.t2_values = &t2_values;
	calc_vi_p.t2_size = &num_t2_values;
	/* 计算重传流（VI）CDF */
	calc_vi_time(calc_vi_p);
	if (rtt_vi == NULL || cdf_vi == NULL || num_t2_values == 0 || t2_values == NULL)
		return calc_retx_time_p->last_reTime;

	calculate_p_t_grid_p.t1_values = t1_values;
	calculate_p_t_grid_p.t1_size = num_t1_values;
	calculate_p_t_grid_p.t2_values = t2_values;
	calculate_p_t_grid_p.t2_size = num_t2_values;
	calculate_p_t_grid_p.sort_owd_be = owd_be;
	calculate_p_t_grid_p.cdf_be = cdf_be;
	calculate_p_t_grid_p.n_be = calc_retx_time_p->count_be;
	calculate_p_t_grid_p.sort_rtt_vi = rtt_vi;
	calculate_p_t_grid_p.cdf_vi = cdf_vi;
	calculate_p_t_grid_p.n_vi = calc_retx_time_p->count_vi;

	/* 在0%-10%重传率范围内，寻找延时和可靠性要求（T<50ms, ）满足的(T, P, one_minus_p1, t1, t2) */
	calc_result *grid_results = calculate_p_t_grid_with_constraints(&calculate_p_t_grid_p);
	if (grid_results == NULL)
		goto free_resource;
	if (calculate_p_t_grid_p.result_size > 0) {
		/* 构建合流时间T与重传率的函数,并寻找最佳拐点 */
		optT = get_opt_solution(grid_results, calculate_p_t_grid_p.result_size);
		kfree(grid_results);
		*calc_retx_time_p->flag = 1;
	}
free_resource:
	kfree(owd_be);
	kfree(cdf_be);
	kfree(t1_values);
	kfree(rtt_vi);
	kfree(cdf_vi);
	kfree(t2_values);
	if (*calc_retx_time_p->flag == 1) {
		return (u64)(optT.t1);
	}
	*calc_retx_time_p->flag = 0;
	return calc_retx_time_p->last_reTime;
}

static u64 fine_tune(u64 retx_time, u64 rate)
{
	u64 theta = retx_time;
	/* 细调重传门限 */
	if (rate >= RATE_HIGH_THRES)
		theta += TUNE_COEF;

	if (rate <= RATE_HIGH_THRES)
		theta -= TUNE_COEF;

	if (theta > MAX_DELAY)
		theta = MAX_DELAY;

	if (theta < MIN_DELAY)
		theta = MIN_DELAY;

	return theta;
}

static void add_history_data(history_data_param history_data)
{
	int i = 0;
	if (history_data.count < HISTORY_LENGTH) {
		/* 直接追加数据 */
		history_data.array_p90[history_data.count] = history_data.t_90;
		history_data.array_p95[history_data.count] = history_data.t_95;
		history_data.array_p99[history_data.count] = history_data.t_99;
		history_data.count++;
	} else {
		/* 数组已满：删除最老的数据，移动剩余数据，最后存入新数据 */
		for (i = 0; i < HISTORY_LENGTH - 1; i++) {
			history_data.array_p90[i] = history_data.array_p90[i + 1];
			history_data.array_p95[i] = history_data.array_p95[i + 1];
			history_data.array_p99[i] = history_data.array_p99[i + 1];
		}
		history_data.array_p90[HISTORY_LENGTH - 1] = history_data.t_90;
		history_data.array_p95[HISTORY_LENGTH - 1] = history_data.t_95;
		history_data.array_p99[HISTORY_LENGTH - 1] = history_data.t_99;
	}
}

void run_alg(delay_tune_alg *implement)
{
	int be_len = 0;
	int vi_len = 0;
	u64 opt_re_time = 0;
	u64 t_90 = 0;
	u64 t_95 = 0;
	u64 t_99 = 0;
	history_data_param history_data_p = {};
	if (implement->new_data_count < MIN_DELAY_LENGTH) {
		implement->update_flag = 0;
		implement->last_retx_time = implement->new_retx_time;
	} else {
		be_len = (implement->full_flag[BE] > 0) ? MAX_DELAY_LENGTH : implement->arr_idx[BE];
		vi_len = (implement->full_flag[VI] > 0) ? MAX_DELAY_LENGTH : implement->arr_idx[VI];
		calc_retx_time_param calc_retx_time_p = {
			implement->delay_be, be_len, implement->delay_vi, vi_len, implement->last_retx_time, &implement->update_flag};
		opt_re_time = get_opt_retx_time(&calc_retx_time_p);

		if (implement->update_flag == 1) {
			implement->new_data_count = 0;
			t_99 = get_percent_delay(implement, NINTY_NINE, BE);
			t_95 = get_percent_delay(implement, NINTY_FIVE, BE);
			t_90 = get_percent_delay(implement, NINTY, BE);
			if (t_99 > 0 && t_95 > 0 && t_90 > 0) {
				history_data_p.array_p90 = implement->history_p90;
				history_data_p.array_p95 = implement->history_p95;
				history_data_p.array_p99 = implement->history_p99;
				history_data_p.count = implement->history_count;
				history_data_p.t_90 = t_90;
				history_data_p.t_95 = t_95;
				history_data_p.t_99 = t_99;
				add_history_data(history_data_p);
			}
		}
		implement->new_retx_time = opt_re_time;
		if (implement->history_count == HISTORY_LENGTH) {
			u64 opt_re_time_ft = fine_tune(opt_re_time, implement->curr_rate);
		}
	}
}

u64 get_retry_rtt(delay_tune_alg *implement)
{
	if (implement->update_flag == 1) {
		return implement->new_retx_time;
	} else {
		return implement->last_retx_time;
	}
}