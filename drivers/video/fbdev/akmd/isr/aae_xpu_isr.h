/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef __AAE_XPU_ISR_H__
#define __AAE_XPU_ISR_H__
#ifndef BIT
#define BIT(x)  (1<<(x))
#endif
 
#define XPU_AAE_MSG_INTR_UMASK				BIT(1)
 
#define MSG_NONE							0	
#define MSG_AAE_INIT_SUCCUSS        	  	BIT(0)
#define MSG_AAE_INIT_FAILED        	  	    BIT(1)
#define MSG_AAE_DEINIT_SUCCESS          	BIT(2)
#define MSG_AAE_DEINIT_FAILED               BIT(3)
#define MSG_AAE_DACC_LOAD_FAILED            BIT(4)
#define MSG_AAE_RISCV_START_FAILED          BIT(5)
#define MSG_AAE_TBU_CONNECT_FAILED          BIT(6)
#define MSG_AAE_TBU_DISCONNECT_FAILED       BIT(7)
#define MSG_AAE_FFTS_DISCONNECT_FAILED      BIT(8)
#define MSG_AAE_CMDLIST_CH7_LOAD_FAILED     BIT(9)
#define MSG_AAE_MAX_NUM                     BIT(10)
#endif //__AAE_XPU_ISR_H__