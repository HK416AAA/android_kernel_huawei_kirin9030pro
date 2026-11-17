/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: Implementation of the ini configuration
 * Author: common drivers
 */
#ifdef CONN_INI_FILE_PRE_PARSE
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
/* 头文件包含 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/ctype.h>
#include <linux/string.h>
#endif

#include "hisi_ini.h"
#include "oam_ext_if.h"
#include "board.h"

#include "oal_kernel_file.h"
#include "oal_util.h"
#include "securec.h"
#include "plat_ini_parse.h"


/* ---------- 数据结构 ---------- */
struct config_item {
    char *key;
    char *value;
    struct config_item *next;
};

struct section_node {
    char *name;
    struct config_item *items;
    struct section_node *next;
};

OAL_STATIC struct section_node *g_section_list = NULL;

OAL_STATIC int32_t g_total_mem = 0;

/* ---------- 辅助函数 ---------- */

OAL_STATIC char *trim_whitespace(char *str)
{
    char *end;
    while (isspace(*str)) {
        str++;
    }

    if (*str == '\0') {
        return str;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';
    return str;
}

OAL_STATIC struct section_node *find_section(const char *name)
{
    struct section_node *cur = g_section_list;

    if ((name == NULL) || (name[0] != '[') || (name[strlen(name) - 1] != ']')) {
        ini_error("name %s invalid", name);
        return NULL;
    }

    while (cur) {
        if (strcmp(cur->name, name) == 0) {
            return cur;
        }

        cur = cur->next;
    }
    return NULL;
}

OAL_STATIC struct section_node *create_section(const char *name)
{
    struct section_node *sec = os_kmalloc(sizeof(*sec), GFP_KERNEL);
    if (!sec) {
        return NULL;
    }

    sec->name = oal_kstrdup(name, GFP_KERNEL);
    if (!sec->name) {
        os_mem_kfree(sec);
        return NULL;
    }
    sec->items = NULL;
    sec->next = g_section_list;
    g_section_list = sec;

    g_total_mem += sizeof(*sec) + strlen(name) + 1;
    return sec;
}

OAL_STATIC int32_t add_config_item(struct section_node *sec, const char *key, const char *value)
{
    struct config_item *item = os_kmalloc(sizeof(*item), GFP_KERNEL);
    if (!item) {
        return -OAL_ENOMEM;
    }

    item->key = oal_kstrdup(key, GFP_KERNEL);
    item->value = oal_kstrdup(value, GFP_KERNEL);
    if (!item->key || !item->value) {
        os_mem_kfree(item->key);
        os_mem_kfree(item->value);
        os_mem_kfree(item);
        return -OAL_ENOMEM;
    }
    item->next = sec->items;
    sec->items = item;

    g_total_mem += sizeof(*item) + (strlen(key) + 1) + (strlen(value) + 1);

    ini_debug("[%s]: add %s=%s\n", sec->name, item->key, item->value);
    return INI_SUCC;
}

/* ---------- 解析一行 ---------- */

/* 处理节名行，例如 [section] */
OAL_STATIC int32_t handle_section_line(char *line, struct section_node **current_sec)
{
    char *sec_name;
    struct section_node *sec;

    char *p = strchr(line, ']');
    if (!p) {
        ini_error("INI: malformed section line: %s\n", line);
        return -OAL_EINVAL;
    }
    /* 将完整的[section]作为节名,包括方括号 */
    sec_name = trim_whitespace(line);
    sec = find_section(sec_name);
    if (!sec) {
        sec = create_section(sec_name);
        if (!sec) {
            return -OAL_ENOMEM;
        }
    }
    *current_sec = sec;
    ini_info("current section: %s\n", sec_name);
    return INI_SUCC;
}

/* 处理键值对行，例如 key=value */
OAL_STATIC int32_t handle_key_value_line(char *line, struct section_node *current_sec)
{
    char *key, *value;
    char *p = strchr(line, '=');
    if (!p) {
        ini_warning("INI: ignoring invalid line (no '='): %s\n", line);
        return INI_SUCC;
    }
    *p = '\0';

    key = trim_whitespace(line);
    value = trim_whitespace(p + 1);
    if (*key == '\0' || *value == '\0') {
        ini_warning("INI: empty key or value: %s\n", line);
        return INI_SUCC;
    }
    return add_config_item(current_sec, key, value);
}

/* 主解析函数：处理一行，根据首字符区分节名或键值对 */
OAL_STATIC int32_t process_line(char *line, struct section_node **current_sec)
{
    line = trim_whitespace(line);
    if (line[0] == '\0' || line[0] == '#') {
        return INI_SUCC;
    }

    if (line[0] == '[') {
        return handle_section_line(line, current_sec);
    }

    /* 确保当前section存在（无section则添加位置不正确，跳过） */
    if (!*current_sec) {
        ini_error("INI: not in valid section: %s\n", line);
        return INI_SUCC;
    }

    return handle_key_value_line(line, *current_sec);
}

/* ---------- 文件读取与解析 ---------- */

/* 逐行解析缓冲区内容 */
OAL_STATIC int32_t parse_buffer(char *buf, loff_t size)
{
    char *line_start = buf;
    char *next_line;
    struct section_node *current_sec = NULL;
    int32_t line_num = 0;

    while ((next_line = strchr(line_start, '\n')) != NULL) {
        *next_line = '\0';
        line_num++;
        if (process_line(line_start, &current_sec) < 0) {
            ini_error("INI: error at line %d\n", line_num);
            return -OAL_EINVAL;
        }
        line_start = next_line + 1;
    }

    if (*line_start) {
        line_num++;
        if (process_line(line_start, &current_sec) < 0) {
            ini_error("INI: error at line %d\n", line_num);
            return -OAL_EINVAL;
        }
    }
    return INI_SUCC;
}

/* ---------- 公共接口 ---------- */
/* 读取ini文件并解析，返回值INI_SUCC避免解析文件失败导致整个驱动不加载 */
int32_t plat_parse_ini(const char *filename)
{
    int32_t size;
    char *buf;
    int32_t ret;
    oal_file_stru *fp = NULL;

    ini_info("plat_parse_ini: %s start", filename);
    fp = oal_file_open_readonly(filename);
    if (fp == NULL) {
        ini_error("open %s failed!!!", filename);
        return INI_SUCC;
    }

    size = oal_file_size(fp);
    if (size <= 0) {
        oal_file_close(fp);
        ini_error("file %s size error!!!", filename);
        return INI_SUCC;
    }

    buf = os_kmalloc(size + 1, GFP_KERNEL);
    if (!buf) {
        oal_file_close(fp);
        ini_error("file %s malloc error!!!", filename);
        return INI_SUCC;
    }

    if (oal_file_read(fp, buf, (uint32_t)size) != size) {
        os_mem_kfree(buf);
        oal_file_close(fp);
        ini_error("file %s file read error!!!", filename);
        return INI_SUCC;
    }
    buf[size] = '\0';
    oal_file_close(fp);

    ret = parse_buffer(buf, size);
    if (ret != INI_SUCC) {
        // 解析失败则释放内存, 后续ini配置的读取方式将回退到从文件中读取查找的方式
        plat_ini_free_config();
    }
    os_mem_kfree(buf);
    ini_info("plat_parse_ini: %s end, ret = %d, memmory consume %d byte\n", filename, ret, g_total_mem);

    return INI_SUCC;
}
oal_module_symbol(plat_parse_ini);

int32_t plat_get_config_string(const char *section, const char *key, char *value, uint32_t size)
{
    struct config_item *item;
    struct section_node *sec = find_section(section);
    if (!sec) {
        ini_error("plat_get_config_string:section %s not find, key=%s", section, key);
        return -OAL_EINVAL;
    }

    item = sec->items;
    while (item) {
        if (strcmp(item->key, key) == 0) {
            if (strcpy_s(value, size, item->value)) {
                ini_error("plat_get_config_string:strncpy_s space is not enough");
                return -OAL_EINVAL;
            }
            ini_debug("plat_get_config_string:%s=%s", key, value);
            return INI_SUCC;
        }
        item = item->next;
    }
    ini_debug("plat_get_config_string:no item %s", key);
    return -OAL_EINVAL;
}
oal_module_symbol(plat_get_config_string);

void plat_ini_free_config(void)
{
    struct section_node *sec = g_section_list;
    while (sec) {
        struct section_node *next_sec = sec->next;
        struct config_item *item = sec->items;
        while (item) {
            struct config_item *next_item = item->next;
            os_mem_kfree(item->key);
            os_mem_kfree(item->value);
            os_mem_kfree(item);
            item = next_item;
        }
        os_mem_kfree(sec->name);
        os_mem_kfree(sec);
        sec = next_sec;
    }
    g_section_list = NULL;
    g_total_mem = 0;
    ini_info("plat_ini_free_config done");
}
oal_module_symbol(plat_ini_free_config);

uint32_t plat_ini_file_parsed(void)
{
    return (g_section_list == NULL) ? OAL_FALSE : OAL_TRUE;
}
oal_module_symbol(plat_ini_file_parsed);
#endif