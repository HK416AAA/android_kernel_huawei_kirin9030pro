/*
 * ffts_tid.c
 *
 * ffts tid
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "ffts_tid.h"

#include <linux/mutex.h>
#include <linux/bitmap.h>

#include "ffts_log.h"

static DECLARE_BITMAP(g_ffts_tid_bitmap, FFTS_TID_NUM_MAX);
static pid_t g_ffts_tid_pid_map[FFTS_TID_NUM_MAX];
static struct mutex g_ffts_tid_mutex;

uint16_t ffts_request_tid(pid_t pid)
{
	uint16_t tid = FFTS_INVALID_TID;
	unsigned long i = 0;

	if (pid <= 0) {
		ffts_drv_err("invalid pid %d\n", pid);
		return FFTS_INVALID_TID;
	}

	mutex_lock(&g_ffts_tid_mutex);
	// find tid-pid table
	for_each_set_bit(i, g_ffts_tid_bitmap, FFTS_TID_NUM_MAX) {
		if (g_ffts_tid_pid_map[i] == pid)
			break;
	}
	if (i < FFTS_TID_NUM_MAX) {
		tid = i + FFTS_TID_START;
		goto complete;
	}
	// get a new uid
	i = find_first_zero_bit(g_ffts_tid_bitmap, FFTS_TID_NUM_MAX);
	if (i < FFTS_TID_NUM_MAX) {
		g_ffts_tid_pid_map[i] = pid;
		set_bit(i, g_ffts_tid_bitmap);
		tid = i + FFTS_TID_START;
	} else {
		ffts_drv_err("uid table is full\n");
		tid = FFTS_INVALID_TID;
	}
complete:
	mutex_unlock(&g_ffts_tid_mutex);
	return tid;
}

void ffts_release_tid(uint16_t ffts_tid)
{
	int i = 0;
	if (ffts_tid < FFTS_TID_START || ffts_tid > FFTS_TID_END) {
		ffts_drv_err("invalid tid %u\n", ffts_tid);
		return;
	}

	i = ffts_tid - FFTS_TID_START;
	mutex_lock(&g_ffts_tid_mutex);
	if (test_bit(i, g_ffts_tid_bitmap) == 0) {
		mutex_unlock(&g_ffts_tid_mutex);
		ffts_drv_err("the tid has not been created, tid = %u\n", ffts_tid);
		return;
	}
	// free tid
	bitmap_clear(g_ffts_tid_bitmap, i, 1);
	g_ffts_tid_pid_map[i] = 0;
	mutex_unlock(&g_ffts_tid_mutex);
	return;
}

void ffts_tid_init(void)
{
	bitmap_zero(g_ffts_tid_bitmap, FFTS_TID_NUM_MAX);
	mutex_init(&g_ffts_tid_mutex);
	return;
}

void ffts_tid_deinit(void)
{
	mutex_destroy(&g_ffts_tid_mutex);
	return;
}