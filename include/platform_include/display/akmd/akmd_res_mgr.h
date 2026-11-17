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

#ifndef AKMD_RES_MGR_H
#define AKMD_RES_MGR_H

#include <linux/types.h>

#ifndef BIT
#define BIT(x) (1U << (x))
#endif

#define RES_IOCTL_MAGIC 'R'

// for res_mgr ioctl
#define RES_REGISTER_TYPES   _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_REGISTER_TYPES, uint64_t) // enum res_types
#define RES_MAP_IOVA         _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_MAP_IOVA, struct aae_dma_buf)
#define RES_UNMAP_IOVA       _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_UNMAP_IOVA, struct aae_dma_buf)
#define RES_BIND_TASK        _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_BIND_TASK, struct aae_task)
#define RES_UNBIND_TASK      _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_UNBIND_TASK, struct aae_task)
#define RES_GET_SCENE_CONFIG _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_GET_SCENE_CONFIG, struct res_scene_config)
#define RES_REQUEST_SCENE    _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_REQUEST_SCENE, struct res_scene_cmd)
#define RES_RELEASE_SCENE    _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_RELEASE_SCENE, struct res_scene_cmd)
#define RES_REQUEST_SCENE_ID _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_REQUEST_SCENE_ID, struct scene_id_info)
#define RES_RELEASE_SCENE_ID _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_RELEASE_SCENE_ID, struct scene_id_info)
#define RES_VOTE_BW          _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_VOTE_BW, struct aae_bw_vote_info)
#define RES_CHECK_RES_CONFLICT _IOWR(RES_IOCTL_MAGIC, RES_IOCTL_CHECK_RES_CONFLICT, struct scene_id_info)

enum {
	RES_IOCTL_REGISTER_TYPES = 0x10,
	RES_IOCTL_MAP_IOVA,
	RES_IOCTL_UNMAP_IOVA,
	RES_IOCTL_REQUEST_SCENE_ID,
	RES_IOCTL_RELEASE_SCENE_ID,
	RES_IOCTL_BIND_TASK,
	RES_IOCTL_UNBIND_TASK,
	RES_IOCTL_GET_SCENE_CONFIG,
	RES_IOCTL_REQUEST_SCENE,
	RES_IOCTL_RELEASE_SCENE,
    RES_IOCTL_VOTE_BW,
    RES_IOCTL_CHECK_RES_CONFLICT,
	RES_IOCTL_CMD_MAX,
};

enum res_types {
	RES_OPERATORS = BIT(0),
	RES_DVFS = BIT(1),
	RES_MAPPER = BIT(2),
	RES_SCENE_ID = BIT(3),
	RES_TASK_BINDER = BIT(4),
	RES_SCENE = BIT(5),
};

struct res_opr_info {
	int32_t scene_id;
	uint32_t scene_type;
	int32_t opr_id;
	int32_t result;
};

struct aae_dma_buf {
	int32_t share_fd;
	uint64_t iova;
	uint64_t size;
};

#define AAE_SCENE_MAX_COUNT 3
struct res_scene_info {
	uint32_t id;
	uint64_t caps;
};

struct res_scene_config {
	uint32_t count;
	struct res_scene_info info[AAE_SCENE_MAX_COUNT];
};

union aae_caps {
    uint64_t caps;
    struct {
        uint64_t cld  : 1;
        uint64_t arsr : 1;
        uint64_t vscf : 1;
        uint64_t hdr : 1;
        uint64_t aihdr : 1;
        uint64_t ov : 1;
        uint64_t wdfc : 1;

        uint64_t blur : 1;
        uint64_t blpp : 1;
        uint64_t scf2d : 1;
        uint64_t hiof : 1;

        uint64_t reserved : 53;
    } value;
};

enum aae_user_type {
    AAE_USER_NONE = 0,
    AAE_USER_COPYBIT = 1,
    AAE_USER_HIANIM = 2,
    AAE_USER_HIOF = 3,
    AAE_USER_OTHERS = 4,
    AAE_USER_MAX,
};

enum task_priority {
    // hianimation 0 ~ 4
    AAE_TASK_PRI_HIANIM_MAX = 0,
    AAE_TASK_PRI_HIANIM_0 = AAE_TASK_PRI_HIANIM_MAX,
    AAE_TASK_PRI_HIANIM_1 = 1,
    AAE_TASK_PRI_HIANIM_2 = 2,
    AAE_TASK_PRI_HIANIM_3 = 3,
    AAE_TASK_PRI_HIANIM_4 = 4,
    AAE_TASK_PRI_HIANIM_MIN = AAE_TASK_PRI_HIANIM_4,

    // hiof 5 ~ 9
    AAE_TASK_PRI_HIOF_MAX = 5,
    AAE_TASK_PRI_HIOF_0 = AAE_TASK_PRI_HIOF_MAX,
    AAE_TASK_PRI_HIOF_1 = 6,
    AAE_TASK_PRI_HIOF_2 = 7,
    AAE_TASK_PRI_HIOF_3 = 8,
    AAE_TASK_PRI_HIOF_4 = 9,
    AAE_TASK_PRI_HIOF_MIN = AAE_TASK_PRI_HIOF_4,

    // copybit
    AAE_TASK_PRI_COPYBIT_MAX = 10,
    AAE_TASK_PRI_COPYBIT_0 = AAE_TASK_PRI_COPYBIT_MAX,
    AAE_TASK_PRI_COPYBIT_1 = 11,
    AAE_TASK_PRI_COPYBIT_2 = 12,
    AAE_TASK_PRI_COPYBIT_3 = 13,
    AAE_TASK_PRI_COPYBIT_4 = 14,
    AAE_TASK_PRI_COPYBIT_5 = 15,
    AAE_TASK_PRI_COPYBIT_MIN = AAE_TASK_PRI_COPYBIT_5,

    AAE_TASK_PRI_MAX
};

enum aae_scene_request_mode {
    AAE_SCENE_REQUEST_MODE_SHARED = 0,
    AAE_SCENE_REQUEST_MODE_MONO,
};

union aae_scene_user {
    uint64_t id;
    struct {
        uint64_t user_type : 16;
        uint64_t mode : 16;
        uint64_t priority : 32;
    } val;
};

struct res_scene_cmd {
	uint32_t scene_id;
	union aae_scene_user user;
};

struct aae_task {
	uint16_t uid; // output parameter
	uint16_t reserved;
};

enum scene_type {
	SCENE_TYPE_OFFLINE = 1,
	SCENE_TYPE_MAX,
};

enum scene_user_type {
	SCENE_USER_NONE = 0,
	SCENE_USER_HDM = 1,
	SCENE_USER_CAMERA = 2,
	SCENE_USER_VPE_HDR2SDR = 3,
    SCENE_USER_RS_PIC = 4,
    SCENE_USER_RS_VIDEO = 5,
    SCENE_USER_GPU_HIOF = 6,
    SCENE_USER_RS_VIDEO_HDR = 7,
	SCENE_USER_MAX
};

enum aae_scene_user_priority {
    AAE_SCENE_USER_PRIORITY_NULL = 0,
    AAE_SCENE_USER_PIRORITY_1 = 1,
    AAE_SCENE_USER_PIRORITY_2 = 2,
    AAE_SCENE_USER_PIRORITY_3 = 3,
    AAE_SCENE_USER_PIRORITY_4 = 4,
    AAE_SCENE_USER_PIRORITY_5 = 5,
    AAE_SCENE_USER_PIRORITY_6 = 6,
    AAE_SCENE_USER_PIRORITY_MAX
};

struct scene_id_user {
	enum scene_user_type user_type;
	enum scene_type scene_type;
};

struct aae_scene_user_info {
    enum scene_user_type user_type;
    enum aae_scene_user_priority priority;
    int32_t tgid;
    uint32_t ref;
};
struct scene_id_info {
	struct scene_id_user user;
	int32_t scene_id;
	int32_t result; // 0 is succ, not 0 is fail
};

struct aae_bw_vote_info {
    uint64_t bw;
    uint32_t uid;
};
#endif
