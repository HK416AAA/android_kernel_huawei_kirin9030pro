/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/list.h>
#include <linux/rwlock_types.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#ifdef CONFIG_LIBLINUX
#include <trace/hooks/liblinux.h>
#include <linux/preempt.h>
#include <linux/irqflags.h>
#endif
#include <asm/current.h>
#include <net/sock.h>
#include <securec.h>
#include <bsp_sms.h>
#include <bsp_print.h>

#define WHITE_LIST_ADD 0x1
#define WHITE_LIST_DEL 0x2
#define WHITE_LIST_CMD_LEN 3
#define WHITE_LIST_MAX 500

#define DATA_PATH_LINUX_STACK   1
#define DATA_PATH_DPA_OFFLOAD   2
#define DATA_PATH_DPA_STACK     3

static DEFINE_RWLOCK(g_white_list_rwlock);
static unsigned int g_dpa_white_list_cnt;
static LIST_HEAD(g_dpa_white_list);

struct white_list_node {
    struct list_head list;
    char name[];
};

unsigned int g_white_list_flag = 0;
#define wl_err_once(fmt, ...)               \
    do {                                    \
        if (g_white_list_flag) {            \
            dpa_pr_err(fmt, ##__VA_ARGS__); \
        }                                   \
    } while (0)

void white_list_set_debug(unsigned int enable)
{
    g_white_list_flag = enable;
}


// 终端接口
#ifdef CONFIG_LOWPOWER_PROTOCOL
extern unsigned int dpa_uid_match(uid_t kuid);
#else
unsigned int dpa_uid_match(uid_t kuid)
{
    return 0;
}
#endif

static bool dpa_white_list_match(char *task_name)
{
    bool match = false;
    struct white_list_node *node = NULL;
    struct white_list_node *tmp_node = NULL;

    write_lock(&g_white_list_rwlock);
    list_for_each_entry_safe(node, tmp_node, &g_dpa_white_list, list) {
        if (strcmp(node->name, task_name) == 0) {
            match = true;
            break;
        }
    }
    write_unlock(&g_white_list_rwlock);
    wl_err_once("match name:%s, result:%d\n", task_name, match);
    return match;
}

// echo "add xx yy zz" > /sys/devices/platform/dpa_white_list/dpa_task_name
// echo "del xx yy zz" > /sys/devices/platform/dpa_white_list/dpa_task_name
int dpa_task_name_add(char *task_name, unsigned int len)
{
    bool exist = false;
    struct white_list_node *node = NULL;
    struct white_list_node *tmp_node = NULL;
    int ret;

    write_lock(&g_white_list_rwlock);
    if (g_dpa_white_list_cnt >= WHITE_LIST_MAX) {
        write_unlock(&g_white_list_rwlock);
        return -EFBIG;
    }

    list_for_each_entry_safe(node, tmp_node, &g_dpa_white_list, list) {
        if (strcmp(node->name, task_name) == 0) {
            exist = true;
            break;
        }
    }

    if (!exist) {
        node = kzalloc(sizeof(*node) + len + 1, GFP_ATOMIC);
        if (node != NULL) {
            ret = memcpy_s(node->name, len + 1, task_name, len);
            if (ret != EOK) {
                write_unlock(&g_white_list_rwlock);
                kfree(node);
                return -EFBIG;
            }

            list_add_tail(&node->list, &g_dpa_white_list);
            g_dpa_white_list_cnt++;
            dpa_pr_err("add task name:%s\n", task_name);
        }
    }
    write_unlock(&g_white_list_rwlock);
    return 0;
}

static int dpa_task_name_del(char *task_name, unsigned int len)
{
    struct white_list_node *node = NULL;
    struct white_list_node *tmp_node = NULL;

    write_lock(&g_white_list_rwlock);
    list_for_each_entry_safe(node, tmp_node, &g_dpa_white_list, list) {
        dpa_pr_err("del task name:%s-%s\n", node->name, task_name);
        if (strcmp(node->name, task_name) == 0) {
            list_del(&node->list);
            if (g_dpa_white_list_cnt) {
                g_dpa_white_list_cnt--;
            }
            kfree((void *)node);
            break;
        }
    }
    write_unlock(&g_white_list_rwlock);
    return 0;
}

int parse_task_name(char *args, unsigned int args_len, int type)
{
    int ret = 0;
    char seps[] = " ,\n";
    char *token = NULL;
    char *next_token = NULL;
    char *buf_tmp = NULL;

    buf_tmp = kzalloc(args_len + 1, GFP_ATOMIC);
    if (buf_tmp == NULL) {
        dpa_pr_err("alloc buf fail\n");
        return -1;
    }

    ret = strcpy_s(buf_tmp, args_len + 1, args);
    if (ret != EOK) {
        dpa_pr_err("strcpy_s fail:%d\n", ret);
        kfree(buf_tmp);
        return -1;
    }

    token = strtok_s(buf_tmp, seps, &next_token);
    while (token != NULL) {
        if (type == WHITE_LIST_ADD) {
            ret = dpa_task_name_add(token, strlen(token));
        } else {
            ret = dpa_task_name_del(token, strlen(token));
        }
        if (ret != 0) {
            kfree(buf_tmp);
            return ret;
        }
        token = strtok_s(NULL, seps, &next_token);
    }

    kfree(buf_tmp);
    return 0;
}

static int dpa_white_list_process_name(const char *buf, size_t size, int type)
{
    char *args = NULL;
    unsigned int opt_len;
    unsigned int data_len;

    // split into cmd and argslist
    args = strchr(buf, ' ');
    if (!args) {
        dpa_pr_err("cmd fmt invalid\n");
        return -EINVAL;
    }

    // cmd is add or del, len is 3
    opt_len = args - buf;
    if (opt_len != WHITE_LIST_CMD_LEN) {
        dpa_pr_err("cmd len invalid:%d\n", opt_len);
        return -EINVAL;
    }

    data_len = size - (opt_len + 1);
    return parse_task_name(args + 1, data_len, type);
}

static ssize_t dpa_white_list_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
    int type;

    if (strncmp(buf, "add", WHITE_LIST_CMD_LEN) == 0) {
        type = WHITE_LIST_ADD;
    } else if (strncmp(buf, "del", WHITE_LIST_CMD_LEN) == 0) {
        type = WHITE_LIST_DEL;
    } else {
        dpa_pr_err("cmd unknown\n");
        return size;
    }

    if (dpa_white_list_process_name(buf, size, type) != 0) {
        dpa_pr_err("fail to parse dpa uids\n");
        return size;
    }

    return size;
}

static ssize_t dpa_white_list_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct white_list_node *node = NULL;
    struct white_list_node *tmp_node = NULL;
    ssize_t size = 0;

    read_lock(&g_white_list_rwlock);
    size += sprintf_s(buf, PAGE_SIZE, "task name list num: %u\n", g_dpa_white_list_cnt);
    list_for_each_entry_safe(node, tmp_node, &g_dpa_white_list, list) {
        size += sprintf_s(buf + size, PAGE_SIZE - size, "%s\n", node->name);
    }
    read_unlock(&g_white_list_rwlock);
    return size;
}
static DEVICE_ATTR(dpa_task_name, S_IWUSR|S_IRUSR, dpa_white_list_show, dpa_white_list_store);

static void dpa_show_data_path(bool is_dpa_stack)
{
    int dpa_path = DATA_PATH_LINUX_STACK;

    if (dpa_sms_filter_cpu_port_offload_en()) {
        dpa_path = DATA_PATH_DPA_OFFLOAD;
    }

    if (is_dpa_stack) {
        dpa_path = DATA_PATH_DPA_STACK;
    }

    dpa_pr_info("use dpa_data_path: %d\n", dpa_path);
}

unsigned int bsp_dpa_white_list_match(struct sock *sk)
{
    struct task_struct *task = NULL;
    unsigned int ret = 0;

    // UID匹配
    ret = dpa_uid_match(sk->sk_uid.val);
    if (ret) {
        dpa_show_data_path(true);
        return ret;
    }

    // 应用名匹配
    task = (struct task_struct *)current;
    if (task == NULL) {
        dpa_pr_err("current task null\n");
        dpa_show_data_path(false);
        return 0;
    }

#ifdef CONFIG_LIBLINUX
    if (!(in_interrupt() || irqs_disabled())) {
        trace_ldk_rvh_get_thread_name(task->pid, task->comm, TASK_COMM_LEN);
    }
#endif
    if (!dpa_white_list_match(task->comm)) {
        dpa_show_data_path(false);
        return 0;
    }

    dpa_show_data_path(true);
    return 1;
}
EXPORT_SYMBOL(bsp_dpa_white_list_match);

int white_list_probe(struct platform_device *pdev)
{
    int ret;

    ret = device_create_file(&pdev->dev, &dev_attr_dpa_task_name);
    if (ret) {
        printk(KERN_ERR "fail to create dpa_task_name node, ret = %d\n", ret);
        return ret;
    }
    printk(KERN_ERR "white list probe out\n");

    return ret;
}

#ifdef CONFIG_DPA_WHITE_LIST_NODE
static struct platform_device g_white_list_device = {
    .name = "dpa_white_list",
    .id = -1,
};

struct platform_driver g_white_list_driver = {
    .probe      = white_list_probe,
    .driver     = {
        .name     = "dpa_white_list",
        .owner    = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

int white_list_init(void)
{
    int ret = 0;

    ret = platform_device_register(&g_white_list_device);
    if (ret) {
        printk(KERN_ERR "fail to register white_list device\n");
        return ret;
    }

    ret = platform_driver_register(&g_white_list_driver);
    if (ret) {
        platform_device_unregister(&g_white_list_device);
        printk(KERN_ERR "fail to register white_list driver\n");
        return ret;
    }

    return ret;
}
#else
int white_list_init(void)
{
    return 0;
}
#endif

void dpa_task_name_match_test(void)
{
    struct sock sk;
    int ret;

    ret = bsp_dpa_white_list_match(&sk);
    dpa_pr_err("match result:%d", ret);
    dpa_pr_err("the process is %s pid:%d", current->comm, current->pid);
}

void dpa_task_show(char *name)
{
    if (dpa_white_list_match(name)) {
        dpa_pr_err("task match\n");
    } else {
        dpa_pr_err("task not match\n");
    }
}
