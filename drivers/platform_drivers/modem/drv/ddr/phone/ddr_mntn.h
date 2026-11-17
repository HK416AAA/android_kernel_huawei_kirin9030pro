/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _DDR_DUMP_H_
#define _DDR_DUMP_H_

#include "securec.h"
#include "bsp_print.h"
#include "osl_types.h"

#define THIS_MODU mod_ddr

#define ddr_crit(fmt, ...) bsp_fatal(fmt, ##__VA_ARGS__)
#define ddr_err(fmt, ...) bsp_err(fmt, ##__VA_ARGS__)
#define ddr_warn(fmt, ...) bsp_wrn(fmt, ##__VA_ARGS__)
#define ddr_print(fmt, ...) bsp_info(fmt, ##__VA_ARGS__)
#define ddr_always(fmt, ...) bsp_err(fmt, ##__VA_ARGS__)
#define ddr_trace(fmt, ...)

#define DDR_ERR_UNINIT (-1)             /*DDR uninit*/
#define DDR_ERR_ESRCH (-3)             /* No such process */
#define DDR_ERR_EIO (-5)               /* Input/output error */
#define DDR_ERR_ENXIO (-6)             /* No such device or address */
#define DDR_ERR_ENOMEM (-12)           /* Cannot allocate memory */
#define DDR_ERR_EEXIST (-17)           /* File exists */
#define DDR_ERR_EINVAL (-22)           /* Invalid argument */
#define DDR_ERR_ECHRNG (-44)           /* Channel number out of range */
#define DDR_ERR_ETIME (-62)            /* Timer expired */
#define DDR_ERR_EPROTO (-71)           /* Protocol error */
#define DDR_ERR_EBADMSG (-74)          /* Bad message */
#define DDR_ERR_ENETUNREACH (-101)     /* Network is unreachable */
#define DDR_ERR_EHOSTUNREACH (-113)    /* No route to host */
#define DDR_ERR_ENOTRECOVERABLE (-131) /* State not recoverable */

#define DDR_DUMP_MAGIC 0xAAAAAAAA
#define DDR_BAND_EXCEPTION_MAGIC 0xBBBBBBBB
#define DDR_BAND_EVENT_MAGIC 0xCCCCCCCC

#define DDR_DUMP_SIZE 0x1000
#define DDR_BAND_EXCEPTION_SIZE 0x80
#define DDR_BAND_EVENT_SIZE 0xF00


typedef struct {
    u32 modid; /* this is type[tlv:t] */
    u32 len; /* this is len[tlv:l] */
} ddr_dump_head_s;

typedef struct {
    u8 *dump_base;
    u32 dump_size;
    u8 *band_exception_base;
    u32 band_exception_size;
    u8 *band_event_base;
    u32 band_event_size;
} ddr_dump_info_s;


#if ((DDR_BAND_EXCEPTION_SIZE + DDR_BAND_EVENT_SIZE) > (DDR_DUMP_SIZE))
#pragma message(PRINT_MACRO((DDR_BAND_EXCEPTION_SIZE + DDR_BAND_EVENT_SIZE) > (DDR_DUMP_SIZE)))
#error ddr_dump_size((DDR_BAND_EXCEPTION_SIZE + DDR_BAND_EVENT_SIZE)) used beyond (DDR_DUMP_SIZE)
#endif

#endif