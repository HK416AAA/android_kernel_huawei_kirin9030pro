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
#ifndef __HMFS_INTF_H__
#define __HMFS_INTF_H__

#pragma pack(push)
#pragma pack(4)
// DPA--HMFS接口
// LBA:
struct dpa_fiemap_extent_t {
    uint64_t fe_logical;       // 逻辑偏移（从文件开始）,单位：bytes
    uint64_t fe_physical;      // 物理偏移（从磁盘开始），从当前磁盘开始的物理地址偏移，还需要给你一个当前磁盘的物理地址,DPA
    uint64_t fe_length;        // extent 长度，从该数组成员物理地址开始的连续空间长度,DPA
    uint32_t fe_flags;         // FIEMAP_EXTENT_* 标志位
};

struct dpa_fiemap_data_t {
    uint32_t fm_mapped_extents; // 已映射的 extent 数量，DPA
    struct dpa_fiemap_extent_t fm_extents[0]; // 映射的 extent 数组
};

struct dpa_fiemap_data_s {
    uint32_t fm_mapped_extents; // 已映射的 extent 数量，DPA
    struct dpa_fiemap_extent_t *fm_extents; // 映射的 extent 数组
};

#define METADATA_BYTE_IN_KDF 16

struct dpa_ci_data_t {
    uint32_t ci_key_index;
    uint8_t ci_metadata[METADATA_BYTE_IN_KDF];
    uint32_t hash_res;
    uint32_t invalid;
};

struct dpa_file_info {
    struct dpa_ci_data_t ci_data;
    struct dpa_fiemap_data_t fiemap_data;
};
#pragma pack(pop)

int dpa_fs_ioctl_fiemap(int fd, int pid, struct dpa_fiemap_data_s *fm);
int dpa_fs_ioctl_cidata(int fd, int pid, struct dpa_ci_data_t *dpa_ci_data);

int dpa_fs_ioctl_fiemap_cidata(int fd, int pid, struct dpa_fiemap_data_s *fm, struct dpa_ci_data_t *dpa_ci_data);
int dpa_fs_fallocate_fiemap(int fd, int pid, unsigned long size_bytes, struct dpa_fiemap_data_s *fm,
    struct dpa_ci_data_t *dpa_ci_data);
#endif