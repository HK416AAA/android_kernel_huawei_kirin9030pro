/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#ifndef __SENSORHUB_DUMP_H__
#define __SENSORHUB_DUMP_H__

#define SENSORHUB_RST_DUMP_SIZE    150
#define SENSORHUB_RST_DUMP_VERSION 0x0

typedef enum {
    // notifier函数维测点
    SENSORHUB_RST_NOTIFIER_BEGIN,
    SENSORHUB_RST_NOTIFIER_END,

    // sensorhub_rst_proc函数维测点
    SENSORHUB_RST_PROC_BEGIN,
    SENSORHUB_RST_PROC_IPC_SEND,
    SENSORHUB_RST_PROC_WAIT,

    // sensorhub_before_recv_handler维测点
    SENSORHUB_RST_BEFORE_HANDLER_BEGIN,
    SENSORHUB_RST_BEFORE_HANDLER_END,

    // sensorhub_after_recv_handler维测点
    SENSORHUB_RST_AFTER_HANDLER_BEGIN,
    SENSORHUB_RST_AFTER_HANDLER_END,

    SENSHUB_RST_STAMP_NUM,
}sensorhub_rst_stamp_id;

struct sensorhub_rst_record_point {
    unsigned int timestamp;
    unsigned int arg1;
    unsigned int arg2;
};

struct sensorhub_rst_dump_info {
    unsigned int version;
    unsigned int len;
    struct sensorhub_rst_record_point record_point[SENSHUB_RST_STAMP_NUM];
};

void sensorhub_rst_dump_record(sensorhub_rst_stamp_id idx, unsigned int arg1, unsigned int arg2);
int sensorhub_rst_dump_init(void);

#endif