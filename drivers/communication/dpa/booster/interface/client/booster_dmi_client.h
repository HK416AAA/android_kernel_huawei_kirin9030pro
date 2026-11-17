/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: This file is the interface file of acpu communicate with dpa.
 * Author: wangdingbang
 * Create: 2024-12-12
 */

#ifndef BOOSTER_DMI_CLIENT_H
#define BOOSTER_DMI_CLIENT_H

#include "booster_features.h"
#include <linux/types.h>

/**
 * @brief booster dmi消息异步发送接口，调用者使用接口后直接返回，若有数据回传则在handle_response中后续处理
 * @param[in]  para0, booster特性区分不同业务的模块id;
 * @param[in]  para1, booster特性模块中的命令id;
 * @param[in]  para2, 用于通信的数据块指针;
 * @param[in]  para3, 用于通信的数据长度;
 * <ul><li>booster_dmi_client.h：该接口声明所在的头文件。</li></ul>
 */
int booster_dpa_request_async(unsigned short feature_id, unsigned short cmd_id,
                              unsigned char *buf, unsigned int buf_len);

typedef void (*handle_response_func)(unsigned short cmd, unsigned char *data, unsigned int len);

void register_handle_response_func(unsigned short feature_id, handle_response_func handler);

void init_booster_dmi_client(void);

#endif // !BOOSTER_DMI_CLIENT_H