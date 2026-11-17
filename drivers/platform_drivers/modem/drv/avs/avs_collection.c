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

#include <securec.h>
#include <osl_module.h>
#include <osl_malloc.h>
#include <osl_thread.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <bsp_mci.h>
#include <bsp_print.h>
#include <bsp_dump.h>
#include <bsp_avs.h>
#include "avs_base.h"
#include "avs_collection.h"

#undef THIS_MODU
#define THIS_MODU mod_avs

int g_write_file_flag = -1;
avs_hpm_coll_test_ctrl g_hpm_coll_test_ctrl = {
    .hpm_coll_cfg.temp_flag = 0xf,
};
int g_single_test_idx = 0;
avs_vtrim_test_ctrl g_vtrim_test_ctrl = {0};
avs_hpm_single_test_ctrl g_hpm_single_test_ctrl = {0};
avs_coll_workqueue_s g_avs_coll_workqueue = {0};

static int create_avs_file(const char *base_name, int temp, struct file **fp)
{
    int ret;
    char file_name[AVS_TEST_FILE_NAME_LEN];

    ret = strncpy_s(file_name, AVS_TEST_FILE_NAME_LEN, base_name, strlen(base_name));
    if (ret) {
        avs_err("strncpy file name err%d\n", ret);
        return -1;
    }
    
    if (temp != VTRIM_TEST_TEMP) {
        char temp_str[TEMP_STR_NAME_LEN];
        if (g_hpm_coll_test_ctrl.hpm_coll_cfg.temp_flag == AVS_COLL_HPM_TEMP_UP_TEST) {
            ret = snprintf_s(temp_str, TEMP_STR_NAME_LEN, TEMP_STR_NAME_LEN - 1, "_%d_temp_up", temp);
            if (ret < 0) {
                avs_err("snprintf temp up %d err %d\n", temp, ret);
                return -1;
            }
        } else if (g_hpm_coll_test_ctrl.hpm_coll_cfg.temp_flag == AVS_COLL_HPM_TEMP_DOWN_TEST) {
            ret = snprintf_s(temp_str, TEMP_STR_NAME_LEN, TEMP_STR_NAME_LEN - 1, "_%d_temp_down", temp);
            if (ret < 0) {
                avs_err("snprintf temp down %d err %d\n", temp, ret);
                return -1;
            }
        } else {
            ret = snprintf_s(temp_str, TEMP_STR_NAME_LEN, TEMP_STR_NAME_LEN - 1, "_%d_idx%d", temp, g_single_test_idx);
            if (ret < 0) {
                avs_err("snprintf temp %d err %d\n", temp, ret);
                return -1;
            }
        }
        ret = strncat_s(file_name, AVS_TEST_FILE_NAME_LEN, temp_str, strlen(temp_str));
        if (ret) {
            avs_err("strcat file name err%d\n", ret);
            return -1;
        }
    }
    file_name[sizeof(file_name) - 1] = '\0';

    *fp = filp_open(file_name, O_CREAT | O_WRONLY | O_TRUNC, AVS_FILE_DATA_CHMOD);
    if (IS_ERR(*fp)) {
        avs_err("open file %s err, %d\n", file_name, PTR_ERR(*fp));
        return -1;
    }

    return 0;
}

static void close_avs_file(struct file *fp)
{
    int ret;
    ret = filp_close(fp, NULL);
    if (ret) {
        avs_err("close avs test file err%d\n", ret);
    }
}

static int read_config_file(const char *path, char *buffer, size_t max_size)
{
    struct file *fp = NULL;
    loff_t file_size;
    loff_t offset = 0;
    int ret;

    fp = filp_open(path, O_RDONLY, 0);
    if (IS_ERR_OR_NULL(fp)) {
        avs_err("open %s err\n", path);
        return -1;
    }

    file_size = i_size_read(file_inode(fp));
    if (file_size > max_size - 1) {
        avs_err("File %s too large: %lld\n", path, file_size);
        close_avs_file(fp);
        return -1;
    }

    ret = kernel_read(fp, buffer, file_size, &offset);
    close_avs_file(fp);

    if (ret < 0) {
        avs_err("read %s err ret: %d\n", path, ret);
        return ret;
    }

    buffer[ret] = '\0';
    return 0;
}

static int parse_space_separated(char *str, unsigned long *values, int max_count)
{
    char *token;
    int count = 0;
    char *next_token = NULL;

    token = strtok_s(str, " ", &next_token);
    while (token && count < max_count) {
        char *endptr;
        values[count] = simple_strtoul(token, &endptr, 0);

        if (*endptr != '\0') {
            avs_err("Invalid number: %s\n", token);
            return -1;
        }

        count++;
        token = strtok_s(NULL, " ", &next_token);
    }

    return count;
}

static int write_voltage_header(struct file *fp, loff_t *pos, u16 volt)
{
    char line[RESULT_DATA_LINE_LEN];
    int len = snprintf_s(line, RESULT_DATA_LINE_LEN, RESULT_DATA_LINE_LEN - 1, "volt %d:\n", volt);
    if (len < 0) {
        avs_err("voltage %d, len %d\n", volt, len);
        return -1;
    }
    if(kernel_write(fp, line, len, pos) != len) {
        avs_err("write volt %d err, len %d\n", volt, len);
        return -1;
    }
    (void)vfs_fsync(fp, 0);
    return 0;
}

static int write_group_header(struct file *fp, loff_t *pos, int group_id)
{
    char line[RESULT_DATA_LINE_LEN];
    int len = snprintf_s(line, RESULT_DATA_LINE_LEN, RESULT_DATA_LINE_LEN - 1, "group %d:\n", group_id);
    if (len < 0) {
        avs_err("group %d, len %d\n", group_id, len);
        return len;
    }
    if(kernel_write(fp, line, len, pos) != len) {
        avs_err("write group %d err, len %d\n", group_id, len);
        return -1;
    }
    (void)vfs_fsync(fp, 0);
    return 0;
}

static int write_hpm_values(struct file *fp, loff_t *pos, u16 *values)
{
    int ret;
    u32 len = 0;
    char *line = (char *)osl_malloc(RESULT_DATA_LINE_LEN);
    if (line == NULL) {
        avs_err("alloc line buf err\n");
        return -1;
    }

    ret = kernel_write(fp, "hpm:  ", strlen("hpm:  "), pos);
    if (ret != strlen("hpm:  ")) {
        avs_err("write hpm err%d\n", ret);
        return -1;
    }
    for (unsigned int vt = 0; vt < HPM_VT_MAX; vt++) {
        len += snprintf_s(line + len, RESULT_DATA_LINE_LEN - len, RESULT_DATA_LINE_LEN - len - 1, "%d  ", values[vt]);
        if (len <= 0) {
            avs_err("vt %d, len %d\n", vt, len);
            return -1;
        }
    }
    ret = kernel_write(fp, line, len, pos);
    if (ret != len) {
        avs_err("write hpm val err%d\n", ret);
        return -1;
    }

    if(kernel_write(fp, "\n", 1, pos) != 1) {
        avs_err("write newline err\n");
        return -1;
    }
    (void)vfs_fsync(fp, 0);
    osl_free(line);
    return 0;
}

static int write_hpm_test_data(struct file *fp, loff_t *pos)
{
    int ret;
    avs_hpm_coll_cfg *cfg = &g_hpm_coll_test_ctrl.hpm_coll_cfg;
    avs_hpm_coll_result *res = g_hpm_coll_test_ctrl.hpm_coll_res;
    if (res == NULL) {
        avs_err("hpm_coll_res NULL\n");
        return -1;
    }

    for (unsigned int volt_id = 0; volt_id < cfg->volt_num; volt_id++) {
        ret = write_voltage_header(fp, pos, res[volt_id].hpm_val.volt);
        if (ret) {
            avs_err("write volt err%d, ret %d\n", volt_id, ret);
            continue;
        }

        for (unsigned int group_id = 0; group_id < HPM_G_MAX; group_id++) {
            ret = write_group_header(fp, pos, group_id);
            if (ret) {
                avs_err("write group err%d, volt %d, ret %d\n", group_id, volt_id, ret);
                continue;
            }

            ret = write_hpm_values(fp, pos, res[volt_id].hpm_val.hpm_value[group_id]);
            if (ret) {
                avs_err("write HPM val err, group %d, volt %d\n", group_id, volt_id);
            }
        }

        if (volt_id < cfg->volt_num - 1) {
            (void)kernel_write(fp, "\n", 1, pos);
            (void)vfs_fsync(fp, 0);
        }
    }
    return 0;
}

static int write_single_hpm_data(struct file *fp, loff_t *pos)
{
    int ret;
    avs_hpm_coll_result *hpm_single_result = &g_hpm_single_test_ctrl.hpm_single_result;

    ret = write_voltage_header(fp, pos, hpm_single_result->hpm_val.volt);
    if (ret) {
        avs_err("write volt err%d\n", ret);
        return ret;
    }
    for (unsigned int group_id = 0; group_id < HPM_G_MAX; group_id++) {
        ret = write_group_header(fp, pos, group_id);
        if (ret) {
            avs_err("write group err%d\n", group_id);
            continue;
        }
        ret = write_hpm_values(fp, pos, hpm_single_result->hpm_val.hpm_value[group_id]);
        if (ret) {
            avs_err("write HPM val err, group %d\n", group_id);
            continue;
        }
    }
    return 0;
}

static int write_vtrim_test_data(struct file *fp, loff_t *pos)
{
    int ret;
    char line[RESULT_DATA_LINE_LEN];
    int len = 0;

    for (unsigned int hpm_idx = 0; hpm_idx < HPM_VT_MAX; hpm_idx++) {
        len += snprintf_s(line + len, RESULT_DATA_LINE_LEN - len, RESULT_DATA_LINE_LEN - len - 1, "%d  ",
            g_vtrim_test_ctrl.vtrim_test_res[hpm_idx]);
        if (len < 0) {
            avs_err("hpm_idx %d snprintf_s err\n", hpm_idx);
            return len;
        }
    }

    ret = kernel_write(fp, line, len, pos);
    if (ret != len) {
        avs_err("write vtrim test res err%d\n", ret);
        if (ret < 0) {
            return ret;
        }
    }
    (void)vfs_fsync(fp, 0);
    return 0;
}

static void generate_avs_data_file(int test_type, int test_temp)
{
    struct file *fp = NULL;
    loff_t pos = 0;
    int ret;
    const char *base_name = NULL;

    switch (test_type) {
        case WRITE_HPM_TEST_DATA:
            base_name = "/data/avs_test/avs_hpm_test_temp";
            break;
        case WRITE_SINGLE_HPM_TEST_DATA:
            base_name = "/data/avs_test/avs_hpm_single_test";
            break;
        case WRITE_VTRIM_TEST_DATA:
            base_name = "/data/avs_test/avs_vtrim_test";
            break;
        default:
            avs_err("test type err: %d\n", test_type);
            return;
    }

    ret = create_avs_file(base_name, test_temp, &fp);
    if (ret) {
        avs_err("create avs data file err%d\n", ret);
        return;
    }

    switch (test_type) {
        case WRITE_HPM_TEST_DATA:
            ret = write_hpm_test_data(fp, &pos);
            break;
        case WRITE_SINGLE_HPM_TEST_DATA:
            ret = write_single_hpm_data(fp, &pos);
            break;
        case WRITE_VTRIM_TEST_DATA:
            ret = write_vtrim_test_data(fp, &pos);
            break;
        default:
            break;
    }

    if (ret) {
        avs_err("write data err, type %d\n", test_type);
    }

    close_avs_file(fp);
}

void result_write_workqueue(struct work_struct *work)
{
    switch (g_write_file_flag) {
        case WRITE_HPM_TEST_DATA:
            generate_avs_data_file(WRITE_HPM_TEST_DATA, g_hpm_coll_test_ctrl.cur_test_temp);
            avs_err("hpm file ok\n");
            break;

        case WRITE_SINGLE_HPM_TEST_DATA:
            generate_avs_data_file(WRITE_SINGLE_HPM_TEST_DATA, g_hpm_single_test_ctrl.cur_test_temp);
            avs_err("single hpm file ok\n");
            break;

        case WRITE_VTRIM_TEST_DATA:
            generate_avs_data_file(WRITE_VTRIM_TEST_DATA, VTRIM_TEST_TEMP);
            avs_err("vtrim file ok\n");
            break;

        default:
            break;
    }
    g_write_file_flag = -1;
    return;
}

int parse_hpm_test_cfg(const char *path, avs_hpm_coll_cfg *cfg)
{
    char buffer[MAX_FILE_SIZE];
    unsigned long values[CFG_HPM_TEST_NUM_MAX];
    int ret, count;

    ret = read_config_file(path, buffer, sizeof(buffer));
    if (ret) {
        return ret;
    }

    count = parse_space_separated(buffer, values, CFG_HPM_TEST_NUM_MAX);
    if (count != CFG_HPM_TEST_NUM_MAX) {
        avs_err("Expected 10 values, got %d\n", count);
        return -1;
    }

    cfg->core_id = (u8)values[CFG_CORE_ID];
    cfg->temp_num = (u8)values[CFG_TEMP_NUM];
    cfg->volt_num = (u8)values[CFG_VOLT_NUM];
    cfg->temp_step = (u8)values[CFG_TEMP_STEP];
    cfg->volt_step = (u8)values[CFG_VOLT_STEP];
    cfg->target_temp_gap = (u8)values[CFG_TARGET_TEMP_GAP];
    cfg->upper_limit_temp = (u8)values[CFG_UPPER_LIMIT_TEMP];
    cfg->lower_limit_temp = (u8)values[CFG_LOWER_LIMIT_TEMP];
    cfg->upper_limit_volt = (u16)values[CFG_UPPER_LIMIT_VOLT];
    cfg->lower_limit_volt = (u16)values[CFG_LOWER_LIMIT_VOLT];

    return 0;
}

void parse_vtrim_third_line(avs_vtrim_test_cfg *cfg, char *lines)
{
    unsigned long *gap_values = (unsigned long *)osl_malloc(sizeof(unsigned long) * cfg->target_hpm_num);
    if (!gap_values) {
        avs_err("alloc gap val buf err\n");
        return;
    }

    int count = parse_space_separated(lines, gap_values, cfg->target_hpm_num);
    if (count != cfg->target_hpm_num) {
        avs_err("Expected %d gap values, got %d\n", cfg->target_hpm_num, count);
        osl_free(gap_values);
        return;
    }

    for (int i = 0; i < cfg->target_hpm_num; i++) {
        cfg->target_hpm_gap[i] = (u16)gap_values[i];
    }
    osl_free(gap_values);
}

void parse_vtrim_second_line(avs_vtrim_test_cfg *cfg, char *lines)
{
    unsigned long *hpm_values = (unsigned long *)osl_malloc(sizeof(unsigned long) * cfg->target_hpm_num);
    if (!hpm_values) {
        avs_err("alloc hpm val buf err\n");
        return;
    }

    int count = parse_space_separated(lines, hpm_values, cfg->target_hpm_num);
    if (count != cfg->target_hpm_num) {
        avs_err("Expected %d HPM values, got %d\n", cfg->target_hpm_num, count);
        osl_free(hpm_values);
        return;
    }

    for (int i = 0; i < cfg->target_hpm_num; i++) {
        cfg->target_hpm_val[i] = (u16)hpm_values[i];
    }
    osl_free(hpm_values);
}

void parse_vtrim_first_line(avs_vtrim_test_cfg *cfg, char *lines)
{
    unsigned long values[CFG_VTRIM_TEST_NUM_MAX];
    int count = parse_space_separated(lines, values, CFG_VTRIM_TEST_NUM_MAX);
    if (count != CFG_VTRIM_TEST_NUM_MAX) {
        avs_err("First line requires 5 values, got %d\n", count);
        return;
    }
    
    cfg->core_id = (u8)values[CFG_VTRIM_TEST_CORE_ID];
    cfg->group_id = (u16)values[CFG_VTRIM_TEST_GROUP_ID];
    cfg->target_hpm_num = (u16)values[CFG_VTRIM_TEST_TARGET_HPM_NUM];
    cfg->vtrim_test_max_volt = (u32)values[CFG_VTRIM_TEST_MAX_VOLT];
    cfg->vtrim_test_min_volt = (u32)values[CFG_VTRIM_TEST_MIN_VOLT];
}

int parse_vtrim_test_cfg(const char *path, avs_vtrim_test_cfg *cfg)
{
    char buffer[MAX_FILE_SIZE];
    char *lines[VTRIM_CFG_LINE] = {NULL};
    int line_count = 0;
    int ret;

    ret = read_config_file(path, buffer, sizeof(buffer));
    if (ret) {
        return ret;
    }
    char *cur_strptr = buffer;
    for (int i = 0; i < VTRIM_CFG_LINE && cur_strptr; i++) {
        char *cr = strchr(cur_strptr, '\r');
        if (cr) {
            *cr = '\0';
        }
        char *lf = strchr(cur_strptr, '\n');
        if (lf) {
            *lf = '\0';
            lines[i] = cur_strptr;
            cur_strptr = lf + 1;
            line_count++;
        } else {
            lines[i] = cur_strptr;
            line_count++;
            break;
        }
    }
    if (line_count < VTRIM_CFG_LINE) {
        avs_err("Expected 3 lines, found %d\n", line_count);
        return -1;
    }
    parse_vtrim_first_line(cfg, lines[0]);
    parse_vtrim_second_line(cfg, lines[1]);
    parse_vtrim_third_line(cfg, lines[VTRIM_CFG_LINE - 1]);
    return 0;
}

void avs_coll_hpm_test_start(unsigned int test_flag)
{
    int ret;
    if (g_hpm_coll_test_ctrl.hpm_coll_res != NULL) {
        osl_free(g_hpm_coll_test_ctrl.hpm_coll_res);
        g_hpm_coll_test_ctrl.hpm_coll_res = NULL;
    }
    avs_hpm_coll_cfg *hpm_coll_cfg = &g_hpm_coll_test_ctrl.hpm_coll_cfg;
    memset_s(hpm_coll_cfg, sizeof(avs_hpm_coll_cfg), 0, sizeof(avs_hpm_coll_cfg));

    hpm_coll_cfg->temp_flag = (u8)test_flag;
    g_hpm_coll_test_ctrl.share_mem = bsp_dump_get_field_addr(DUMP_TSP_AVS_HPM_TEST);
    if (g_hpm_coll_test_ctrl.share_mem == NULL) {
        avs_err("get share mem err\n");
        return;
    }

    ret = parse_hpm_test_cfg(HPM_TEST_CONFIG_FILE_PATH, hpm_coll_cfg);
    if (ret) {
        avs_err("parse hpm test cfg err\n");
        return;
    }

    g_hpm_coll_test_ctrl.hpm_coll_res =
        (avs_hpm_coll_result*)osl_malloc(hpm_coll_cfg->volt_num * sizeof(avs_hpm_coll_result));
    if (g_hpm_coll_test_ctrl.hpm_coll_res == NULL) {
        avs_err("alloc hpm_coll_res err\n");
        return;
    }
    avs_err("hpm coll test start\n");
    avs_val_notify(AVS_TEST_HPM_START, (char *)(hpm_coll_cfg), sizeof(avs_hpm_coll_cfg));
}

void avs_coll_hpm_single_test_start(unsigned int test_flag)
{
    unsigned int core_id = 0;
    g_hpm_single_test_ctrl.share_mem = bsp_dump_get_field_addr(DUMP_TSP_AVS_HPM_TEST);
    if (g_hpm_single_test_ctrl.share_mem == NULL) {
        avs_err("single test get share mem err\n");
        return;
    }
    avs_hpm_coll_cfg *hpm_coll_cfg = &g_hpm_coll_test_ctrl.hpm_coll_cfg;
    memset_s(hpm_coll_cfg, sizeof(avs_hpm_coll_cfg), 0, sizeof(avs_hpm_coll_cfg));
    hpm_coll_cfg->temp_flag = (u8)test_flag;
    avs_err("hpm single test start\n");
    avs_val_notify(AVS_TEST_HPM_SINGLE, (char *)(&core_id), sizeof(unsigned int));
}

void avs_vtrim_test_start(void)
{
    int ret;
    (void)memset_s((void *)(&g_vtrim_test_ctrl), sizeof(avs_vtrim_test_ctrl), 0, sizeof(avs_vtrim_test_ctrl));
    avs_vtrim_test_cfg *vtrim_test_cfg = &g_vtrim_test_ctrl.vtrim_test_cfg;

    ret = parse_vtrim_test_cfg(VTRIM_TEST_CONFIG_FILE_PATH, vtrim_test_cfg);
    if (ret) {
        avs_err("parse vtrim test cfg err\n");
        return;
    }
    avs_err("vtrim test start\n");
    avs_val_notify(AVS_TEST_VTRIM, (char *)vtrim_test_cfg, sizeof(avs_vtrim_test_cfg));
}

static ssize_t avs_coll_test_write(struct file *filp, const char __user *buf, size_t count, loff_t *ppos)
{
    int ret;
    unsigned long val;
    unsigned int test_flag;
    unsigned char kbuf[MAX_U64_STR_SIZE] = {0};
    if (filp == NULL || buf == NULL) {
        return -1;
    }
    if (ppos == NULL) {
        return -1;
    }
    if (*ppos) {
        return 0;
    }
    if (count >= MAX_U64_STR_SIZE) {
        avs_err("buffer overflow: %lu > %u\n", count, MAX_U64_STR_SIZE);
        return -1;
    }
    ret = copy_from_user(kbuf, buf, count);
    if (ret) {
        avs_err("copy from user err\n");
        return -1;
    }
    if (kstrtoul(kbuf, 0, &val)) {
        return -1;
    }
    test_flag = (unsigned int)val;
    if (test_flag == AVS_COLL_HPM_TEMP_UP_TEST) {
        avs_coll_hpm_test_start(test_flag);
    } else if (test_flag == AVS_COLL_HPM_TEMP_DOWN_TEST) {
        avs_coll_hpm_test_start(test_flag);
    } else if (test_flag == AVS_COLL_HPM_SINGLE_TEST) {
        g_single_test_idx++; // idx add when start new single test
        avs_coll_hpm_single_test_start(test_flag);
    } else if (test_flag == AVS_COLL_VTRIM_TEST) {
        avs_vtrim_test_start();
    }
    *ppos += count;
    return count;
}

static int avs_vtrim_test_cb(char *data, unsigned int len)
{
    int ret;
    if (len != sizeof(u32) * HPM_VT_MAX) {
        avs_err("vtrim res len err %d\n", len);
        return -1;
    }

    ret = memcpy_s(g_vtrim_test_ctrl.vtrim_test_res, sizeof(u32) * HPM_VT_MAX, data, len);
    if (ret != 0) {
        avs_err("mcpy vtrim test res err%d\n", ret);
        return -1;
    }

    g_write_file_flag = WRITE_VTRIM_TEST_DATA;
    queue_work(g_avs_coll_workqueue.avs_coll_wq, &g_avs_coll_workqueue.avs_coll_work);
    return 0;
}

static int avs_hpm_single_test_cb(char *data, unsigned int len)
{
    int ret;
    if (len != sizeof(signed char)) {
        avs_err("single hpm test data len err %d\n", len);
        return -1;
    }
    g_hpm_single_test_ctrl.cur_test_temp = *data;
    if (g_hpm_single_test_ctrl.share_mem == NULL) {
        avs_err("single test share mem NULL\n");
        return -1;
    }
    ret = memcpy_s(&g_hpm_single_test_ctrl.hpm_single_result, sizeof(avs_hpm_coll_result),
        g_hpm_single_test_ctrl.share_mem, sizeof(avs_hpm_coll_result));
    if (ret) {
        avs_err("mcpy single hpm test res err%d\n", ret);
    }
    (void)memset_s(g_hpm_single_test_ctrl.share_mem, sizeof(avs_hpm_coll_result), 0, sizeof(avs_hpm_coll_result));
    g_write_file_flag = WRITE_SINGLE_HPM_TEST_DATA;
    queue_work(g_avs_coll_workqueue.avs_coll_wq, &g_avs_coll_workqueue.avs_coll_work);
    return 0;
}

static int avs_hpm_test_cb(char *data, unsigned int len)
{
    int ret;
    u8 recive_flag = 0;
    avs_hpm_coll_result *hpm_coll_res = g_hpm_coll_test_ctrl.hpm_coll_res;
    avs_hpm_coll_cfg *hpm_coll_cfg = &g_hpm_coll_test_ctrl.hpm_coll_cfg;
    if (len != sizeof(signed char)) {
        avs_err("test temp data len err %d\n", len);
        return -1;
    }
    g_hpm_coll_test_ctrl.cur_test_temp = (*data);
    if (g_hpm_coll_test_ctrl.share_mem == NULL || hpm_coll_res == NULL) {
        avs_err("share mem or test res NULL\n");
        return -1;
    }
    ret = memcpy_s(hpm_coll_res, sizeof(avs_hpm_coll_result) * hpm_coll_cfg->volt_num,
        g_hpm_coll_test_ctrl.share_mem, sizeof(avs_hpm_coll_result) * hpm_coll_cfg->volt_num);
    if (ret != 0) {
        avs_err("mcpy hpm cfg err%d\n", ret);
        return -1;
    }
    (void)memset_s(g_hpm_coll_test_ctrl.share_mem, sizeof(avs_hpm_coll_result) * hpm_coll_cfg->volt_num,
        0, sizeof(avs_hpm_coll_result) * hpm_coll_cfg->volt_num);

    recive_flag = 1;
    g_write_file_flag = WRITE_HPM_TEST_DATA;
    queue_work(g_avs_coll_workqueue.avs_coll_wq, &g_avs_coll_workqueue.avs_coll_work);

    avs_val_notify(AVS_TEST_ACORE_REC, (char *)(&recive_flag), sizeof(u8));
    return 0;
}

struct proc_ops g_avs_coll_test_ops = {
    .proc_write = avs_coll_test_write,
};

int avs_coll_test_init(void)
{
    int ret;
    ret = bsp_mci_proc_create("avs_collect_test", AVS_COLLECT_MODE, &g_avs_coll_test_ops);
    if (ret) {
        avs_err("avs coll proc create err\n");
        return -1;
    }

    avs_msg_cb_register(AVS_HPM_COLL_TEST, avs_hpm_test_cb);
    avs_msg_cb_register(AVS_HPM_SINGLE_TEST_REPLY, avs_hpm_single_test_cb);
    avs_msg_cb_register(AVS_VTRIM_TEST_FINISH, avs_vtrim_test_cb);

    INIT_WORK(&(g_avs_coll_workqueue.avs_coll_work), result_write_workqueue);
    g_avs_coll_workqueue.avs_coll_wq = alloc_ordered_workqueue("result_write_workqueue", 0);
    if (g_avs_coll_workqueue.avs_coll_wq == NULL) {
        avs_err("coll result write wq create err");
        return -1;
    }
    return 0;
}