#ifndef WRITE_COV_FILE
#define WRITE_COV_FILE

#define HITEST_STR_LEN 32

struct cov_data_hdr {
    unsigned long long data_len;
    char build_id[HITEST_STR_LEN];
    char project_name[HITEST_STR_LEN];
    unsigned char data[0];
};


int write_lpmcu_cov(void);

int write_dpa_cov(void);

#endif