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
#include "hitest_cov.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define THIS_MODU mod_ecdc

typedef int (*fun_kallsyms_on_each_symbol)(int (*fn)(void*, const char*, struct module*, unsigned long), void* data);

typedef const char* (*ret_char_para_void)(void);
typedef unsigned long (*ret_long_para_void)(void);
typedef int (*ret_int_para_ptr)(unsigned int *pCovData, unsigned long ulLen);
typedef int (*ret_int_para_void)(void);

static fun_kallsyms_on_each_symbol pfun_kallsyms_on_each_symbol = 0;

char g_module_name[HITEST_FUNC_NAME_LEN] = {0};

extern const char* Hitest_Agent_GetBuildIDS(void);
extern const char* Hitest_Agent_GetPrjNameS(void);
extern unsigned long Hitest_Agent_GetCovDataSizeS(void);
extern int Hitest_Coverage_GetCoverageDataS(unsigned int *pCovData, unsigned long ulLen);
extern int Hitest_Coverage_InitCoverageData(void);

const char*  __attribute__((weak)) Hitest_Agent_GetBuildIDS(void)
{
    int ret;
    char symbol_name[HITEST_FILE_NAME_LEN] = "Hitest_Agent_GetBuildIDS_";
    ret_char_para_void address = NULL;

    ret = strcat_s(symbol_name, sizeof(symbol_name), g_module_name);
    if (ret) {
        hitest_err("strcat error!\n");
    }
    address = (ret_char_para_void)(uintptr_t)kallsyms_lookup_name(symbol_name);
    if (address == NULL) {
        goto call_no_symbol;
    }
    return address();

call_no_symbol:
    hitest_err("[Hitest_Agent_GetBuildIDS]:Invalid function:%s, value = -1\n", symbol_name);
    return "UnGetId";
}

const char*  __attribute__((weak)) Hitest_Agent_GetPrjNameS(void)
{
    int ret;
    char symbol_name[HITEST_FILE_NAME_LEN] = "Hitest_Agent_GetPrjNameS_";
    ret_char_para_void address = NULL;

    ret = strcat_s(symbol_name, sizeof(symbol_name), g_module_name);
    if (ret) {
        hitest_err("strcat error!\n");
    }
    address = (ret_char_para_void)(uintptr_t)kallsyms_lookup_name(symbol_name);
    if (address == NULL) {
        goto call_no_symbol;
    }
    return address();

call_no_symbol:
    hitest_err("[Hitest_Agent_GetPrjNameS]:Invalid function:%s, value = -1\n", symbol_name);
    return "UnGetId";
}

unsigned long __attribute__((weak)) Hitest_Agent_GetCovDataSizeS(void)
{
    int ret;
    char symbol_name[HITEST_FILE_NAME_LEN] = "Hitest_Agent_GetCovDataSizeS_";
    ret_long_para_void address = NULL;

    ret = strcat_s(symbol_name, sizeof(symbol_name), g_module_name);
    if (ret) {
        hitest_err("strcat error!\n");
    }
    address = (ret_long_para_void)(uintptr_t)kallsyms_lookup_name(symbol_name);
    if (address == NULL) {
        goto call_no_symbol;
    }
    return address();

call_no_symbol:
    hitest_err("[Hitest_Agent_GetCovDataSizeS]:Invalid function:%s, value = -1\n", symbol_name);
    return 0;
}

int __attribute__((weak)) Hitest_Coverage_GetCoverageDataS(unsigned int *pCovData, unsigned long ulLen)
{
    int ret;
    char symbol_name[HITEST_FILE_NAME_LEN] = "Hitest_Coverage_GetCoverageDataS_";
    ret_int_para_ptr address = NULL;

    ret = strcat_s(symbol_name, sizeof(symbol_name), g_module_name);
    if (ret) {
        hitest_err("strcat error!\n");
    }
    address = (ret_int_para_ptr)(uintptr_t)kallsyms_lookup_name(symbol_name);
    if (address == NULL) {
        goto call_no_symbol;
    }
    return address(pCovData, ulLen);

call_no_symbol:
    hitest_err("[Hitest_Coverage_GetCoverageDataS]:Invalid function:%s, value = -1\n", symbol_name);
    return 0;
}

int __attribute__((weak)) Hitest_Coverage_InitCoverageData(void)
{
    int ret;
    char symbol_name[HITEST_FILE_NAME_LEN] = "Hitest_Coverage_InitCoverageData_";
    ret_int_para_void address = NULL;

    ret = strcat_s(symbol_name, sizeof(symbol_name), g_module_name);
    if (ret) {
        hitest_err("strcat error!\n");
    }
    address = (ret_int_para_void)(uintptr_t)kallsyms_lookup_name(symbol_name);
    if (address == NULL) {
        goto call_no_symbol;
    }
    return address();

call_no_symbol:
    hitest_err("[Hitest_Coverage_InitCoverageData]:Invalid function:%s, value = -1\n", symbol_name);
    return 0;
}

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

int creat_file_name(char *file_name, struct cov_data_hdr *hdr, char *random_str, unsigned int len)
{
    int ret;
    ret = strcat_s(file_name, len, hdr->project_name);
    if (ret < 0) {
        hitest_err("fail strcat_s file_name:%s\n", file_name);
        return -1;
    }
    ret = strcat_s(file_name, len, "_");
    if (ret < 0) {
        hitest_err("fail strcat_s file_name:%s\n", file_name);
        return -1;
    }
    ret = strcat_s(file_name, len, hdr->build_id);
    if (ret < 0) {
        hitest_err("fail strcat_s file_name:%s\n", file_name);
        return -1;
    }
    ret = strcat_s(file_name, len, "_A");
    if (ret < 0) {
        hitest_err("fail strcat_s file_name:%s\n", file_name);
        return -1;
    }
    ret = strcat_s(file_name, len, random_str);
    if (ret < 0) {
        hitest_err("fail strcat_s file_name:%s\n", file_name);
        return -1;
    }
    hitest_err("file_name:%s\n", file_name);
    return 0;
}

void creat_cov_file(struct cov_data_hdr *hdr)
{
    mm_segment_t old_fs;
    struct file *fp = NULL;
    loff_t pos = 0;
    int ret;
    char file_name[HITEST_FILE_NAME_LEN] = "/data/hisi_logs/linuxavatar_";
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
int get_cov_data(void)
{
    unsigned int *cov_data = NULL;
    unsigned long data_len;
    const char *build_id =  NULL;
    const char *project_name = NULL;
    struct cov_data_hdr *hdr = NULL;
    int ret;

    build_id = Hitest_Agent_GetBuildIDS();
    project_name = Hitest_Agent_GetPrjNameS();
    data_len = Hitest_Agent_GetCovDataSizeS();

    if (data_len <= 0) {
        hitest_err("cov_data is NULL!\n");
        return -1;
    }

    cov_data = kzalloc(sizeof(struct cov_data_hdr) + data_len, GFP_KERNEL);
    if (NULL == cov_data) {
        hitest_err("[NCSAgentSendCoverageData]: Allocate memory error!\n");
        return -1;
    }

    (void)memset_s(cov_data, (sizeof(struct cov_data_hdr) + data_len), 0, (sizeof(struct cov_data_hdr) + data_len));
    hdr = (struct cov_data_hdr*)cov_data;
    hdr->msg_type = HITEST_MSG_TYPE;
    hdr->data_len = data_len;
    ret = memcpy_s(hdr->project_name, HITEST_STR_LEN, project_name, strlen(project_name));
    if (ret != 0) {
        hitest_err("mem cpy project_name failed:%d\n", ret);
        kfree(cov_data);
        return -1;
    }
    ret = memcpy_s(hdr->build_id, HITEST_STR_LEN, build_id, strlen(build_id));
    if (ret != 0) {
        hitest_err("mem cpy build_id failed:%d\n", ret);
        kfree(cov_data);
        return -1;
    }

    if (Hitest_Coverage_GetCoverageDataS((unsigned int *)hdr->data, data_len) != 1) {
        hitest_err("Error: get coverage data failed!\n");
        kfree(cov_data);
        return -1;
    }

    creat_cov_file(hdr);

    kfree(cov_data);

    return 0;
}
/* 清除末尾的空白字符 */
static void clear_black_last_char(char *pbuf)
{
    char ch = '\0';
    int index = strlen(pbuf);

    while (index) {
        ch = *(pbuf + (--index));
        if (ch > 32) {       //32为ASCII码的“空白”字符节点
            break;
        }
        *(pbuf + index) = '\0';
    }
}

/* 遍历Hitest开头的函数, 拷贝出符合要求的模块id后缀 */
static void list_module_name_for_buffer(char *func_name, size_t len)
{
    int ret;
    int prefix_len = strlen(HITEST_MAIN_INTERFACTION);

    if (len <= prefix_len) {
        hitest_err("func_name len is invalid\n");
        return;
    }

    clear_black_last_char(func_name);

    if (strncmp(func_name, HITEST_MAIN_INTERFACTION, prefix_len) == 0) {
        ret = strcpy_s(g_module_name, sizeof(g_module_name), func_name + prefix_len);
        if (ret) {
            hitest_err("strcpy_s error, error code is %d\n", ret);
        }
    }
}

static int list_kallsymcall(void *data, const char *name_buff, struct module *mu, unsigned long address)
{
    int ret;
    char func_name[HITEST_FUNC_NAME_LEN] = { 0 };
    if (strlen(name_buff) != 0 && name_buff == strstr(name_buff, "Hitest_")) {
        ret = sprintf_s(func_name, sizeof(func_name), "%s", name_buff);
        if (ret != 0) {
            hitest_err("sprintf_s failed with error code %d\n", ret);
            return -1;
        }
        list_module_name_for_buffer(func_name, sizeof(func_name));
    }
    return 0;
}

static int find_module_id_by_kallsym(void)
{
    /* kallsyms_on_each_symbol未EXPORT, 需要kallsyms_lookup_name找到符号地址调用 */
    pfun_kallsyms_on_each_symbol = (fun_kallsyms_on_each_symbol)(uintptr_t)kallsyms_lookup_name("kallsyms_on_each_symbol");
    if (pfun_kallsyms_on_each_symbol == 0) {
        hitest_err("Hitest can not find kallsyms_on_each_symbol.\n");
        return -1;
    }

    (void)pfun_kallsyms_on_each_symbol(list_kallsymcall, NULL);
    return 0;
}

int hitest_get_cov(void)
{
    int ret;
    const bsp_version_info_s *version_info = bsp_get_version_info();

    if (version_info->product_type == PRODUCT_PHONE) {
        ret = find_module_id_by_kallsym();
        if (ret) {
            hitest_err("Hitest failed to find module id by kallsym!\n");
            return -1;
        }
    }

    /* 采集覆盖率 */
    ret = get_cov_data();
    if (ret) {
        hitest_err("Hitest failed to collect code coverage!\n");
    }

    /* 清除覆盖率 */
    Hitest_Coverage_InitCoverageData();

#ifndef BSP_CONFIG_PHONE_TYPE
    /* 采集并清除teeos覆盖率 */
    (void)teeos_hitest_cov_run();
#endif

    hitest_err("get cov end\n");
    return 0;
}

EXPORT_SYMBOL(hitest_get_cov);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

/* lint -restore */