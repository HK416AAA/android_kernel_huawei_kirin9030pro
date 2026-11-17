/*
 * audio_io_aggre.h
 *
 * audio_io_aggre driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __AUDIO_IO_AGGRE_H__ 
#define __AUDIO_IO_AGGRE_H__

#include <linux/mutex.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>

#ifdef CONFIG_CONTEXTHUB_IO_DIE_STS
#include "sts.h"
#endif

#ifndef unused
#define unused(x) ((void)(x))
#endif

#define MODE_NAME "audio_io_aggre"

typedef void (*aggre_notifier_func)(void);

enum {
    AGGRE_NOTIFIER_BEGIN = 0,
    AGGRE_NOTIFIER_INITED = AGGRE_NOTIFIER_BEGIN,
    AGGRE_NOTIFIER_RECOVERY,
    AGGRE_NOTIFIER_END
};

enum {
    AGGRE_DEVICE_BEGIN = 0,
    AGGRE_DEVICE_SMARTPA = AGGRE_DEVICE_BEGIN,
    AGGRE_DEVICE_END
};

struct audio_io_aggre_priv {
    bool is_voted;
    unsigned int vote_cnt;
    sts_sys_status_enum sts_status;
    struct mutex vote_lock;
    struct mutex sts_status_lock;
    struct work_struct aggre_work;
};

int audio_io_aggre_regist_event_callback(unsigned int type, unsigned int device, aggre_notifier_func func);
void audio_io_aggre_vote(void);
void audio_io_aggre_unvote(void);
void audio_io_aggre_sts_inited_vote(void);
#endif