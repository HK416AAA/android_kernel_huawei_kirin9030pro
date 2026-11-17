/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/version.h>
#include <linux/syscalls.h>
#include <asm/uaccess.h>
#include <linux/string.h>
#include <linux/time.h>
#include <linux/random.h>
#include <linux/rtc.h>
#include <linux/kallsyms.h>
#include <securec.h>
#include <bsp_file_ops.h>
#include <bsp_version.h>
#include <linux/workqueue.h>
#include <linux/semaphore.h>
#include <bsp_sec_call.h>
#include "hitest_cov.h"

/* *
 * teeos DT支持的cmd ID
 */
typedef enum {
    DRV_MODULE_TEEOS_CASE_QUERY,
    DRV_MODULE_TEEOS_CASE_RUN,
    DRV_MODULE_TEEOS_CASE_RESULT,
    DRV_MODULE_TEEOS_COV_SIZE,
    DRV_MODULE_TEEOS_COV_DATA,

    DRV_MODULE_TEEOS_MAX,
} TEEOS_DT_CMD_ID;

struct teeos_hitest_cov_info_s {
    struct workqueue_struct *wq;
    struct work_struct work;
    struct semaphore workqueue_sem;
    int result;
};
struct teeos_hitest_cov_info_s g_teeos_hitest_cov_info;

static int creat_random_str(char *random_str, unsigned int len)
{
    int ret;
    u32 rand1, rand2;

    get_random_bytes(&rand1, sizeof(rand1));
    get_random_bytes(&rand2, sizeof(rand2));

    ret = sprintf_s(random_str, len, "%010d", rand1);
    if (ret < 0) {
        hitest_err("fail sprintf_s random_str\n");
        return -1;
    }

    ret = sprintf_s(random_str + 10, len, "%010d", rand2);
    if (ret < 0) {
        hitest_err("fail sprintf_s random_str\n");
        return -1;
    }

    hitest_err("random_str:%s\n", random_str);
    return 0;
}

void creat_teeos_cov_file(struct cov_data_hdr *hdr)
{
    mm_segment_t old_fs;
    struct file *fp = NULL;
    loff_t pos = 0;
    int ret;
    char file_name[HITEST_FILE_NAME_LEN] = "/data/hisi_logs/teeos_";
    char random_str[HITEST_STR_LEN] = "";

    hitest_err("project_name:%s\n", hdr->project_name);
    hitest_err("build_id:%s\n", hdr->build_id);

    ret = creat_random_str(random_str, HITEST_STR_LEN);
    if (ret) {
        return;
    }

    ret = creat_file_name(file_name, hdr, random_str, HITEST_FILE_NAME_LEN);
    if (ret) {
        return;
    }

    old_fs = get_fs();
    set_fs((mm_segment_t)KERNEL_DS);
    ret = bsp_file_mkdir("/data/hisi_logs", 0750);
    set_fs(old_fs);
    if (ret && ret != -EEXIST) {
        hitest_err("mkdir file fail:%d\n", ret);
        return;
    }

    fp = filp_open(file_name, O_CREAT | O_RDWR | O_APPEND, 0);
    if (IS_ERR_OR_NULL(fp)) {
        hitest_err("open file fail:0x%lx\n", PTR_ERR(fp));
        return;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);
    pos = fp->f_pos;
    ret = kernel_write(fp, hdr->data, hdr->data_len, &pos);
    fp->f_pos = pos;
    set_fs(old_fs);
    if (ret != hdr->data_len) {
        hitest_err("write file fail\n");
    }

    filp_close(fp, NULL);
}

static void get_teeos_hitest_cov(struct work_struct *work)
{
    int ret = 0;
    unsigned long data_len = 0;
    unsigned int *cov_data = NULL;
    struct cov_data_hdr *teeos_hdr = NULL;
    ret = bsp_sec_call_ext(FUNC_MDRV_TEEOS_PLATDRV_DT, DRV_MODULE_TEEOS_COV_SIZE, (void *)&data_len, sizeof(unsigned long));
    if (ret) {
        hitest_err("[teeos-hitest-cov]: get teeos cov_data len failed! ret = %lu\n", ret);
        return;
    }
    cov_data = kzalloc(sizeof(struct cov_data_hdr) + data_len, GFP_KERNEL);
    if (cov_data == NULL) {
        hitest_err("[teeos-hitest-cov]: Allocate memory error!\n");
        return;
    }
    (void)memset_s(cov_data, (sizeof(struct cov_data_hdr) + data_len), 0, (sizeof(struct cov_data_hdr) + data_len));
    teeos_hdr = (struct cov_data_hdr*)cov_data;
    teeos_hdr->msg_type = HITEST_MSG_TYPE;
    teeos_hdr->data_len = data_len;
    ret = bsp_sec_call_ext(FUNC_MDRV_TEEOS_PLATDRV_DT, DRV_MODULE_TEEOS_COV_DATA,
                           (void *)teeos_hdr, sizeof(struct cov_data_hdr) + data_len);
    if (ret) {
        hitest_err("[teeos-hitest-cov]: get teeos cov_data len failed! ret = %lu\n", ret);
        goto OUT;
    }
    creat_teeos_cov_file(teeos_hdr);
OUT:
    kfree(cov_data);
    up(&g_teeos_hitest_cov_info.workqueue_sem);
    return;
}

void teeos_hitest_cov_run(void)
{
    while (down_interruptible(&g_teeos_hitest_cov_info.workqueue_sem)) {
        continue;
    }
    queue_work(g_teeos_hitest_cov_info.wq, &g_teeos_hitest_cov_info.work);

    return;
}
EXPORT_SYMBOL(teeos_hitest_cov_run);

int teeos_hitest_cov_init(void)
{
    INIT_WORK(&g_teeos_hitest_cov_info.work, get_teeos_hitest_cov);
    g_teeos_hitest_cov_info.wq = alloc_ordered_workqueue("modem_teeos_hitest_wq", 0);
    if (g_teeos_hitest_cov_info.wq == NULL) {
        hitest_err("wq create fail\n");
        return -1;
    }
    sema_init(&g_teeos_hitest_cov_info.workqueue_sem, 1);
    return 0;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
    module_init(teeos_hitest_cov_init);
#endif