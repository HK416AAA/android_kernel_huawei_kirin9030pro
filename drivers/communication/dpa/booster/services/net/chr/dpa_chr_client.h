/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: This file is the interface file of acpu communicate with data reg.
 * Author: tianlei
 * Create: 2024-12-12
 */
 
#ifndef DPA_CHR_CLIENT_H
#define DPA_CHR_CLIENT_H
 
void dpa_chr_reg_tech_dmi_client_init(void);
 
typedef void (*set_reg_tech)(int *data_reg);
extern void register_chr_reg_tech_dmi_ops(set_reg_tech func);

#endif // !DPA_CHR_CLIENT_H