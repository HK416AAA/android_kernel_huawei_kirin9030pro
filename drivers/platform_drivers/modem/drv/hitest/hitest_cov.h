/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
 */

#ifndef __AP_DUMP_H__
#define __AP_DUMP_H__

#define HITEST_MAIN_INTERFACTION  "Hitest_Agent_GetCovDataSizeS_"
#define HITEST_MSG_TYPE 0xf1fe
#define HITEST_STR_LEN 32
#define HITEST_DATA_LEN_EACH_TIME 0x2000
#define HITEST_FILE_NAME_LEN 256
#define HITEST_FUNC_NAME_LEN 256


#define hitest_err(fmt, ...) pr_err("[hitest]: " fmt, ##__VA_ARGS__)

struct cov_data_hdr {
    unsigned int msg_type;
    unsigned int data_len;
    char build_id[HITEST_STR_LEN];
    char project_name[HITEST_STR_LEN];
    unsigned char data[0];
};

void creat_cov_file(struct cov_data_hdr *hdr);
void teeos_hitest_cov_run(void);
int creat_file_name(char *file_name, struct cov_data_hdr *hdr, char *random_str, unsigned int len);
#endif
