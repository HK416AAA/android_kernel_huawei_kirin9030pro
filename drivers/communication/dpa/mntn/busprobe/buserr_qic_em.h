/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
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
 *//*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 */

#ifndef __BUSERR_QIC_EM_H__
#define __BUSERR_QIC_EM_H__

/* error monitor register */
#define  QIC_EM_INT_MASK    0x04
#define  QIC_EM_INT_ST      0x08
#define  QIC_EM_INT_CLR     0x0C
#define  QIC_EM_CKG_CTRL    0x10
#define  QIC_EM_ERR_LOG0    0x20
#define  QIC_EM_ERR_LOG1    0x28
#define  QIC_EM_ERR_LOG2    0x2C
#define  QIC_EM_ERR_LOG3    0x30
#define  QIC_EM_ERR_LOG4    0x34
#define  QIC_EM_ERR_LOG5    0x40
#define  QIC_EM_ERR_LOG6    0x44
#define  QIC_EM_ERR_LOG7    0x48

#define QIC_EMP_CMD_TSIZE_BIT    20
#define QIC_EMP_CMD_TSIZE_MASK   0xFFF
#define QIC_EMP_CMD_STATUS_BIT   12
#define QIC_EMP_CMD_STATUS_MASK  0xF
#define QIC_EMP_CMD_EXCL_BIT     8
#define QIC_EMP_CMD_EXCL_MASK    0x1
#define QIC_EMP_CMD_BURST_BIT    7
#define QIC_EMP_CMD_BURST_MASK   0x1
#define QIC_EMP_CMD_OPC_BIT      0
#define QIC_EMP_CMD_OPC_MASK     0x4

#define QIC_EMP_CMD_IBID_BIT     16
#define QIC_EMP_CMD_IBID_MASK    0xFF
#define QIC_EMP_CMD_TBID_BIT     8
#define QIC_EMP_CMD_TBID_MASK    0xFF
#define QIC_EMP_CMD_MMIDX_BIT    0
#define QIC_EMP_CMD_MMIDX_MASK   0xFF

/* QIC_EM_ERR_LOG5 */
#define QIC_EMP_CMD_MID_BIT      0
#define QIC_EMP_CMD_MID_MASK     0xFF

#define QIC_EM_STATUS_CNT        0xB
#define QIC_EM_OPCODE_CNT        0x7
#define QIC_EM_STATUS_DECERR     0x3

#define QIC_IBQ_DECERR_CLR       0x780
#define QIC_IBQ_DECERR_STATUS    0x784
#define QIC_IBQ_DECERR_ADDR0     0x788
#define QIC_IBQ_DECERR_ADDR1     0x78C

#define QIC_IBQ_MAX              32

#endif
