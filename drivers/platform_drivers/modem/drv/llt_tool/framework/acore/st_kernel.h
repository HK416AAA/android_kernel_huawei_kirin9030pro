/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
 */

#include <linux/semaphore.h>
#include <linux/types.h>
#include <bsp_msg.h>
#include <linux/cdev.h>

#define BTEST_NAME_LEN 64
#define BTEST_FILE_LEN 200

// #define TEEOS_EXPECT_MAX 16
// #define TEEOS_TESTCASE_MAX 50

#define FLAGS_PRINT_TIMEROUT (1 * 1000000) // 1s

/* supported commands */
/* 后续新增cmd从最后增加*/
enum btest_cmd {
    BTEST_C_UNSPEC,
    BTEST_C_QUERY, /* Query for a list of tests */
    BTEST_M_QUERY,
    BTEST_C_RUN,     /* Run a test */
    BTEST_C_COV,     /* Enable/disable coverage support */
    BTEST_C_CTX_CFG, /* Configure a context */
    BTEST_C_EXEC_TSP_FUNC,
    BTEST_C_UNLOAD,
    BTEST_TEEOS_QUERY,
    BTEST_DPA_QUERY, /* Query for a list of tests */
    BTEST_MTEE_QUERY,
    BTEST_MTEE_RUN,

    BTEST_SEND_COMPLETED_CMD_BEGIN,
    BTEST_MREE_SEND_COMPLETED, /* list of tests sent completed*/
    BTEST_M_SEND_COMPLETED,
    BTEST_TEEOS_SEND_COMPLETED,
    BTEST_DPA_SEND_COMPLETED,
    BTEST_MTEE_SEND_COMPLETED,
    BTEST_SEND_COMPLETED_CMD_END,

    BTEST_FILE_BEGIN,
    BTEST_C_FILE,
    BTEST_M_FILE,
    BTEST_TEEOS_FILE,
    BTEST_DPA_FILE,
    BTEST_MTEE_FILE,
    BTEST_FILE_END,

    BTEST_ST_FUN_CALL,
    BTEST_ST_LPMCU_FUN_CALL,


    BTEST_C_MAX,
};

struct btest_msg {
    enum btest_cmd cmd;
    unsigned int len;
    char *buf[0];
};

struct btest_msg_list {
    struct list_head list;
    enum btest_cmd cmd;
    unsigned int len;
    char *buf[0];
};

struct btest_lpmcu_cmsg{
    struct list_head list;
    unsigned int len;
    char *cmsg_buf[0];
};


typedef int (*msg_read_cb)(struct btest_msg *buff, unsigned int len);

struct btest_msg_file_ctx {
    struct list_head msg_list;
    spinlock_t lock;
    struct task_struct *task;
    struct semaphore task_sem;
    unsigned int task_flag;
    msg_read_cb acore_msg_read_cb;

    wait_queue_head_t read_queue;
    int file_readable;
    spinlock_t fifo_lock;

    dev_t dev_num;
    struct cdev cdevp;
    struct class *st_file_class;
    struct btest_lpmcu_cmsg lpmcu_cmsg_list;
};

void register_msg_read_cb(msg_read_cb cb);

msg_chn_t get_btest_msghdl(void);