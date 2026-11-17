/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * License terms: GNU General Public License (GPL)
 * Author: liyue
 *
 * Util function of MinTP Tail Delay Latency Alg.
 */

#include "../../mintp_log.h"
#include "utils.h"
#define LOW_LATENCY_TWO 2

int remove_duplicates(u64 arr[], int n)
{
	u64 *result;  /* 临时数组存储唯一元素 */
	int size = 0;   /* 去重后的数组大小 */
	int i = 0;
    if (n <= 0) {
        return 0; // 处理n为0或负数的情况
    }
    result = (u64 *)kmalloc(n * sizeof(u64), GFP_ATOMIC);
    if (result == NULL) {
        mtp_debug("[tail_delay] resuly kmalloc failed.");
        return 0;
    }
	for (i = 0; i < n; i++) {
		int isDuplicate = 0;  /* 检查是否重复 */
		int j = 0;
		for (j = 0; j < size; j++) {
			if (arr[i] == result[j]) {
				isDuplicate = 1;  /* 如果重复，标记为 1 */
				break;
			}
		}
		if (!isDuplicate) {  /* 如果不重复，添加到结果数组 */
			result[size] = arr[i];
			size++;
		}
	}

	/* 将去重后的结果写回到原数组 */
	for (i = 0; i < size; i++) {
		arr[i] = result[i];
	}
    kfree(result);
	return size;  /* 返回去重后数组的大小 */
}

void calculate_cdf(u64 *data, int size, u64 *cdf)
{
	int i = 0;
	for (i = 0; i < size; ++i) {
		/* 计算累积分布函数（放大后的固定点表示） */
		cdf[i] = ((i + 1) * SCALE) / size;
	}
}

u64 percentile(u64 *data, int size, u64 percent_fp)
{
	/* 1. data 数组中的每个元素也应使用固定点表示（比如实际值乘以 SCALE 保存） */
	/* 2. percent_fp 采用固定点运算表示百分比。例如，50%的固定点值为 50 * SCALE。 */
	/* 如果百分比为 100%，计算结果可能等于 size，需要修正为 size - 1（数组下标范围为 0 到 size-1） */
	int index = (int)((percent_fp * size) / (ONE_HUNDRED * SCALE));
	if (index >= size) {
		index = size - 1;
	}
	return data[index];
}

u64 *linspace(u64 start, u64 end, int num)
{
    if (num == 0) {
        mtp_debug("[tail_delay] num is zero, failed.");
        return NULL;
    }
	u64 *arr = (u64 *)kmalloc(num * sizeof(u64), GFP_ATOMIC);
	if (arr == NULL) {
		return NULL;  /* 内存分配失败 */
	}
	/* 当只有一个数时直接返回起点 */
	if (num == 1) {
		arr[0] = start;
		return arr;
	}
	/* 计算步长：应为 (end - start) 除以 (num - 1) */
	u64 step = (end - start) / (num - 1);
	int i = 0;
	for (i = 0; i < num; ++i) {
		arr[i] = start + i * step;
	}
	/* 为确保最后一个值精确为 end，可进行手动修正 */
	arr[num - 1] = end;
	return arr;
}

/* 自定义样条插值函数（这里使用简单的线性插值作为示例） */
void spline_interpolate(spline_interpolate_param spline_interpolate_p)
{
	int i, j = 0;
	u64 numerator = 0;
	u64 denominator = 0;
    // 检查n是否至少为2
    if (spline_interpolate_p.n < LOW_LATENCY_TWO) {
        // 无法插值，直接返回
        return;
    }
	for (i = 0; i < spline_interpolate_p.nnew; i++) {
		/* 找到 xnew[i] 落在区间 [x[j], x[j+1]] 内 */
        // 处理xnew[i]超出范围的情况
        if (spline_interpolate_p.xnew[i] < spline_interpolate_p.x[0]) {
            j = 0;
        } else if (spline_interpolate_p.xnew[i] > spline_interpolate_p.x[spline_interpolate_p.n - 1]) {
            j = spline_interpolate_p.n - LOW_LATENCY_TWO;
        } else {
            // 找到xnew[i]落在区间[x[j], x[j+1]]内
            j = 0;
            while (j < spline_interpolate_p.n - 1 && spline_interpolate_p.x[j + 1] <= spline_interpolate_p.xnew[i]) {
                j++;
            }
            // 防止越界
            if (j >= spline_interpolate_p.n - 1) {
                j = spline_interpolate_p.n - LOW_LATENCY_TWO;
            }
        }
		/* 计算比例 t，原公式： t = (xnew[i] - x[j]) / (x[j+1] - x[j]) */
		/* 固定点转换后： t_fixed = ((xnew[i] - x[j]) * SCALE) / (x[j+1] - x[j]) */
        u64 t_fixed = 0;
        if (spline_interpolate_p.x[j + 1] != spline_interpolate_p.x[j]) {
            numerator = (u64)(spline_interpolate_p.xnew[i] - spline_interpolate_p.x[j]) * SCALE;
            denominator = spline_interpolate_p.x[j + 1] - spline_interpolate_p.x[j];
            t_fixed = (u64)(numerator / denominator);
        } else {
            // x[j+1] == x[j]，无法插值，使用y[j]
            t_fixed = 0;
        }

		/* 用固定点的 t 计算插值： ynew[i] = y[j] + t * (y[j+1] - y[j]) */
		/* 转换为固定点后： ynew[i] = y[j] + (t_fixed * (y[j+1] - y[j])) / SCALE */
		spline_interpolate_p.ynew[i] =
			spline_interpolate_p.y[j] + (t_fixed * (spline_interpolate_p.y[j + 1] - spline_interpolate_p.y[j])) / SCALE;
	}
}

/* 计算梯度（有限差分法） */
void compute_gradient(const u64 *y, const u64 *x, u64 *dy_dx, int n)
{
	int i = 0;
    if (n <= 0 || y == NULL || x == NULL || dy_dx == NULL) {
        mtp_debug("[tail_delay] compute_gradient invalid args, failed.");
        return; // 处理无效输入
    }
	for (i = 0; i < n; i++) {
		if (i == 0) {
			/* 左边界梯度 */
            if (n == 1) {
                dy_dx[i] = 0; // 无法计算梯度，设置为0
                continue;
            }
			if (x[i + 1] != x[i])
				dy_dx[i] = ((y[i + 1] - y[i]) * GRAD_SCALE) / (x[i + 1] - x[i]);
			else
				dy_dx[i] = 0;
		} else if (i == n - 1) {
			/* 右边界梯度 */
            if (n == 1) {
                dy_dx[i] = 0; // 无法计算梯度，设置为0
                continue;
            }
			if (x[i] != x[i - 1])
				dy_dx[i] = ((y[i] - y[i - 1]) * GRAD_SCALE) / (x[i] - x[i - 1]);
			else
				dy_dx[i] = 0;
		} else {
			/* 内部点采用中心差分法 */
			if (x[i + 1] != x[i - 1])
				dy_dx[i] = ((y[i + 1] - y[i - 1]) * GRAD_SCALE) / (x[i + 1] - x[i - 1]);
			else
				dy_dx[i] = 0;
		}
	}
}

int find_max_index(u64 arr[], int size)
{
	int max_index = 0;
	int i = 1;
	if (size == 1)
        return arr[0];
	for (i = 1; i < size; i++) {
		if (arr[i] > arr[max_index]) {
			max_index = i;
		}
	}
	return max_index;
}
