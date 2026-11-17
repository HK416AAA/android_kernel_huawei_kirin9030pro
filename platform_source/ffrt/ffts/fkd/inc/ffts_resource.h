/*
 * ffts_resource.h
 *
 * ffts_resource head file
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

#ifndef _FFTS_RESOURCE_H_
#define _FFTS_RESOURCE_H_


#define SIZE_1K  1024

#define FFTS_RESERVED_SIZE      (4 * SIZE_1K)
#define FFTS_USER_REG_SIZE      (4 * SIZE_1K)

#define FFTS_UID_MAX            1024

#define FFTS_QOS_NUM            8
#define FFTS_RTB_UNIT_SIZE      8
#define FFTS_RTB_UNIT_NUM       512
#define FFTS_RTB_SIZE           (FFTS_RTB_UNIT_SIZE * FFTS_RTB_UNIT_NUM * FFTS_QOS_NUM)

#define FFTS_SQ_UNIT_SIZE       64
#define FFTS_SQ_UNIT_NUM        64
#define FFTS_SQ_SIZE            (FFTS_SQ_UNIT_SIZE * FFTS_SQ_UNIT_NUM)

#endif