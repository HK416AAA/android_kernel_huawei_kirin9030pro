/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
 */

#include <bsp_msg.h>
#include <bsp_print.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>
#include <linux/kfifo.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/poll.h>
#include <linux/uaccess.h>
#include <linux/wait.h>
#include <mdrv_msg.h>
#include <mdrv_timer.h>
#include <msg_id.h>
#include <securec.h>
#include <stdbool.h>
#include <bsp_dpa.h>
#include <linux/slab.h>

#include "fun_call/fun_call.h"
#include "protocol/proto_enum.h"
#include "protocol/func_item.h"
#include "protocol/return_msg.h"
#include "stream/stream_buffer.h"
#include "return_code.h"

#include "st_kernel.h"
#ifdef CONFIG_DPA_DMI
#include <dpa_dmi.h>
#endif

MODULE_LICENSE("GPL");

#define MAX_PARA_NUM 6
#define THIS_MODU mod_btest
#define BTEST_DATA_MAX_LEN 0x1000
#define BTEST_TASK_STOP 0x77

struct btest_msg_file_ctx g_btest_ctx;
msg_chn_t g_btest_msghdl;

#define DEVICE_NAME "st_file_device"
#define CLASS_NAME "st_file_class"

#define PACK_MAX_LEN 1024
#define FIFO_SIZE 128

#define FUN_CALL_CMD 0
#define FUN_RET_GET_CMD 1

struct usr_ker_msg {
    unsigned char func_loc;
    int len;
    char *buf;
};

DECLARE_KFIFO(st_fifo, struct usr_ker_msg, FIFO_SIZE);

void register_msg_read_cb(msg_read_cb cb)
{
    g_btest_ctx.acore_msg_read_cb = cb;
}

msg_chn_t get_btest_msghdl(void)
{
    return g_btest_msghdl;
}

static int add_kfifo(char *buff, int len)
{
    int ret;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;
    struct usr_ker_msg msg_to_usr;

    char *msg_buf = kmalloc(sizeof(char) * len, GFP_KERNEL);
    if (!msg_buf) {
        bsp_err("malloc failed\n");
        return -1;
    }
    memcpy_s(msg_buf, len, buff, len);

    msg_to_usr.len = len;
    msg_to_usr.buf = msg_buf;

    spin_lock(&ctx->fifo_lock);
    ret = kfifo_in(&st_fifo, &msg_to_usr, 1);
    if (ret != 1) {
        bsp_err("kfifo_in failed, ret = %d\n", ret);
        kfree(msg_buf);
        return -ENOSPC;
    }
    ctx->file_readable = 1;
    spin_unlock(&ctx->fifo_lock);
    wake_up_interruptible(&ctx->read_queue);

    return 0;
}

static int st_file_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int st_file_release(struct inode *inode, struct file *file)
{
    return 0;
}

long long unsigned int get_fun_addr(char *fun_name)
{
    return (long long unsigned int)kallsyms_lookup_name(fun_name);
}

int add_return_msg(char *buff, int size)
{
    return add_kfifo(buff, size);
}

static int parse_M_msg(struct btest_msg *bsp_msg)
{
    call_msg *cmsg = NULL;
    unsigned char *func_name, *ptr_buf;
    int total_len, param_num, i = 0;
    char *temp_buf = NULL;
    call_param *ptr_params = NULL;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;
    struct btest_lpmcu_cmsg * csmg_node = NULL;

    if (get_call_msg(&cmsg, (char *)bsp_msg->buf, bsp_msg->len)) {
        bsp_err("get call msg for lpmcu failed\n");
        return -1;
    }

    if (get_return_type(cmsg) != ST_INT) {
        bsp_err("return type of lpmcu not int\n");
        goto free_cmsg;
    }

    param_num = get_params_num(cmsg);
    if (param_num < 0 || param_num > MAX_PARA_NUM) {
        bsp_err("param number error\n");
        goto free_cmsg;
    }

    func_name = (char *)get_func_name(cmsg);
    if(!func_name){
        bsp_err("func_name is NULL");
        goto free_cmsg;
    }

    total_len = ST_UUID_SIZE + strlen(func_name) + 1 + (param_num + 1) * sizeof(int); // params[param_num]、param_num
    temp_buf = (char *) kmalloc(total_len, GFP_KERNEL);
    if(temp_buf == NULL) {
        bsp_err("temp_buf after kmalloc is null\n");
        goto free_cmsg;
    }

    if(memcpy_s(temp_buf, ST_UUID_SIZE, get_st_uuid(cmsg), ST_UUID_SIZE) !=  EOK){
        bsp_err("temp_buf memcpy_s uuid failed\n");
        goto free_buf;
    }
    ptr_buf = temp_buf + ST_UUID_SIZE;

    if(strcpy_s(ptr_buf, strlen(func_name)+1, func_name)) {
        bsp_err("fail to copy ptr_func_name\n");
        goto free_buf;
    }
    ptr_buf += strlen(func_name) + 1;

    if (memcpy_s(ptr_buf, sizeof(int), &param_num, sizeof(int)) != EOK) {
        bsp_err("temp_buf memcpy_s param_num failed\n");
        goto free_buf;
    }
    ptr_buf += sizeof(int);

    ptr_params = get_call_params(cmsg);

    for(i = 0; i < param_num; i++){
        if (*get_call_param_type(ptr_params) != ST_INT){
            bsp_err("param for lpmcu not int\n");
            goto free_buf;
        }
        else {
            if (memcpy_s(ptr_buf, sizeof(int), get_call_param_data(ptr_params), sizeof(int)) != EOK ) {
                bsp_err("temp_buf memcpy_s param[%d] failed\n", i);
                goto free_buf;
            }
            ptr_buf += sizeof(int);
            ptr_params = iter_call_param(ptr_params);
        }
    }

    csmg_node = (struct btest_lpmcu_cmsg *)kmalloc(sizeof(struct btest_lpmcu_cmsg) + bsp_msg->len, GFP_KERNEL);
    if(csmg_node == NULL) {
         bsp_err("csmg_node after kmalloc is null\n");
         goto free_buf;
    }
    if (memcpy_s(csmg_node->cmsg_buf, bsp_msg->len, bsp_msg->buf, bsp_msg->len) != EOK) {
        bsp_err("csmg_node memcpy_s bsp_msg failed\n");
        goto free_buf;
    }
    csmg_node->len = bsp_msg->len;
    list_add_tail(&csmg_node->list, &ctx->lpmcu_cmsg_list.list);

    if (memcpy_s(bsp_msg->buf, total_len, temp_buf, total_len) != EOK) {
        bsp_err("bsp_msg memcpy_s temp_buf failed\n");
        goto free_buf;
    }
    kfree(temp_buf);
    destroy_call_msg(cmsg);
    return total_len;

free_buf:
    kfree(temp_buf);
free_cmsg:
    destroy_call_msg(cmsg);
    return -1;
}

#ifdef CONFIG_DPA_DMI
int btest_msg_sendto_dpa(void *buf, unsigned int len)
{
    int ret;
    struct dmi_msg *msg = NULL;
 
    msg = kmalloc(sizeof(struct dmi_msg) + len, GFP_KERNEL);
    if (msg == NULL) {
        return -1;
    }
    msg->dmi_id = DMI_SERVICE_BTEST;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->data.len = len;
    ret = memcpy_s(msg->data.buf, len, buf, len);
    if (ret) {
        kfree(msg);
        return -1;
    }
    ret = dpa_dmi_client_request_comm_wake(msg, sizeof(struct dmi_msg) + len);
    kfree(msg);
    return ret;
}
#endif

static int fun_call_cmd(struct usr_ker_msg *msg_from_usr)
{
    int ret = 0;
    struct msg_addr dst;
    struct btest_msg *bsp_msg;
    struct usr_ker_msg ker_msg;

    if (copy_from_user(&ker_msg, msg_from_usr, sizeof(struct usr_ker_msg))) {
        bsp_err("copy_from_user failed\n");
        return -EFAULT;
    }

    if (ker_msg.len > PACK_MAX_LEN) {
        bsp_err("msg size too large\n");
        return 0;
    }

    bsp_msg = (struct btest_msg *)kmalloc(sizeof(struct btest_msg) + PACK_MAX_LEN, GFP_KERNEL);
    if (copy_from_user(bsp_msg->buf, ker_msg.buf, ker_msg.len)) {
        kfree(bsp_msg);
        return -EFAULT;
    }
    bsp_msg->cmd = BTEST_ST_FUN_CALL;
    bsp_msg->len = ker_msg.len;

    switch (ker_msg.func_loc) {
        case ACORE_KERNEL:
            ret = handle_input_stream((char *)bsp_msg->buf, ker_msg.len);
            break;
        case MCORE:
            bsp_err("case MCORE: success\n");
            dst.core = MSG_CORE_LPM;
            dst.chnid = MSG_CHN_BTEST;
            ret = parse_M_msg(bsp_msg);
            if (ret < 0) {
                bsp_err("parse msg for lpmcu failed\n");
                break;
            }
            bsp_msg->len = ret;
            bsp_msg->cmd = BTEST_ST_LPMCU_FUN_CALL;
            ret = bsp_msg_lite_sendto(
                g_btest_msghdl, &dst, bsp_msg, sizeof(struct btest_msg) + bsp_msg->len);  
            break;
        case CCORE_MREE:
            bsp_err("case CCORE_MREE: success\n");
            dst.core = MSG_CORE_TSP;
            dst.chnid = MSG_CHN_BTEST;
            ret = bsp_msg_lite_sendto(g_btest_msghdl, &dst, bsp_msg, sizeof(struct btest_msg) + bsp_msg->len);
            break;
        case DPA:
            bsp_err("case DPA: success\n");
            dst.core = MSG_CORE_DPA;
            dst.chnid = MSG_CHN_BTEST;
#ifdef CONFIG_DPA_DMI
            ret = btest_msg_sendto_dpa(bsp_msg, sizeof(struct btest_msg) + bsp_msg->len);
#else
            ret = bsp_msg_sendto_dpa(g_btest_msghdl, &dst, bsp_msg, sizeof(struct btest_msg) + bsp_msg->len);
#endif
            break;
        default:
            bsp_err("error core loaction\n");
    }
    if (ret) {
        bsp_err("core location = %d\n send failed, ret = %d\n", msg_from_usr->func_loc, ret);
    }
    kfree(bsp_msg);
    return ret;
}

static int fun_ret_get_cmd(struct usr_ker_msg *recv_buf)
{
    int ret;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;
    struct usr_ker_msg msg_to_usr;
    struct usr_ker_msg ker_msg;

    if (copy_from_user(&ker_msg, recv_buf, sizeof(struct usr_ker_msg))) {
        bsp_err("copy_from_user failed\n");
        return -EFAULT;
    }

    if (wait_event_interruptible(ctx->read_queue, ctx->file_readable)) {
        return -ERESTARTSYS;
    }

    spin_lock(&ctx->fifo_lock);
    ret = kfifo_out(&st_fifo, &msg_to_usr, 1);
    if (ret != 1) {
        spin_unlock(&ctx->fifo_lock);
        bsp_err("kfifo_out error, ret = %d\n", ret);
        return -EIO;
    }
    if (kfifo_is_empty(&st_fifo)) {
        ctx->file_readable = 0;
    }
    spin_unlock(&ctx->fifo_lock);

    if (ker_msg.len < msg_to_usr.len) {
        bsp_err("recv_buf size too small\n");
        add_kfifo((char *)&msg_to_usr, sizeof(msg_to_usr));
        return 0;
    }

    if (copy_to_user(ker_msg.buf, msg_to_usr.buf, msg_to_usr.len)) {
        add_kfifo((char *)&msg_to_usr, sizeof(msg_to_usr));
        return -EFAULT;
    }
    kfree(msg_to_usr.buf);

    return msg_to_usr.len;
}

static stream_buffer form_lpmcu_return(struct btest_msg *msg)
{
    bool flag = false;
    unsigned char *ptr_buf;
    int ret_code = 0, fun_return = 0, ret, i = 0, params_num = 0;
    mem_fd sock_wfd;
    call_msg *cmsg = NULL;
    return_param rparam;
    call_param *ptr_params;
    stream_buffer return_buffer;
    struct list_head *p = NULL, *n = NULL;
    struct btest_lpmcu_cmsg * csmg_node;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;

    list_for_each_safe(p, n, &ctx->lpmcu_cmsg_list.list){
        csmg_node = list_entry(p, struct btest_lpmcu_cmsg, list);
        if (memcmp(csmg_node->cmsg_buf, msg->buf, ST_UUID_SIZE) == 0) {
            flag = true;
            ret = get_call_msg(&cmsg, (char *)csmg_node->cmsg_buf, csmg_node->len);
            if (ret) {
                bsp_err("get call msg for lpmcu failed\n");
                return NULL;
            }
            list_del(&csmg_node->list);
            break;
        }
    }
    if (!flag) {
        bsp_err("can't find msg info for lpmcu\n");
        return NULL;
    }

    params_num = get_params_num(cmsg);

    ptr_buf = (unsigned char *)msg->buf + ST_UUID_SIZE; 
    if (memcpy_s(&ret_code, sizeof(int), ptr_buf, sizeof(int)) != EOK) {
        bsp_err("memcpy_s ret_code from buf failed\n");
        return NULL;
    }
    ptr_buf += sizeof(int);
    if (ret_code != 0) {
        params_num = 0;
    }

    if (memcpy_s(&fun_return, sizeof(int), ptr_buf, sizeof(int)) != EOK) {
        bsp_err("memcpy_s fun_return from buf failed\n");
        return NULL;
    }
    ptr_buf += sizeof(int);

    ret = set_return_param(&rparam, (unsigned char)ST_INT,
                        sizeof(int),
                        (unsigned char *)&fun_return);
    if (!ret) {
        bsp_err("set_return_param of lpmcu return failed\n");
        return NULL;
    }

    ptr_params = get_call_params(cmsg);
    for(i=0; i< params_num; i++) {
        if (memcpy_s(get_call_param_data(ptr_params), sizeof(int), ptr_buf, sizeof(int)) != EOK) {
            bsp_err("memcpy_s param[%d] from buf failed\n", i);
        }
        ptr_buf += sizeof(int);
        ptr_params = iter_call_param(ptr_params);
    }
    return_buffer = create_buffer();
    if (return_buffer == NULL) {
        st_error("create stream_buffer failed\n");
        goto free_cmsg;
    }
    sock_wfd = open_w(return_buffer);
    if (sock_wfd == NULL) {
        st_error("open sock wfd failed\n");
        goto free_return_buff;
    }

    if (!write_return_msg(sock_wfd, cmsg, ret_code, &rparam)) {
        bsp_err("write return msg failed\n");
        goto free_sock_wfd;
    }
    bsp_err("finish write\n");
    kfree(csmg_node);
    return return_buffer;

free_sock_wfd:
    close_memory_io(sock_wfd);
free_return_buff:
    destroy_buffer(return_buffer);
free_cmsg:
    destroy_call_msg(cmsg);
    return NULL;
}

static long st_file_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int ret;

    switch (cmd) {
        case FUN_CALL_CMD:
            ret = fun_call_cmd((struct usr_ker_msg *)arg);
            bsp_err("fun_call_cmd ret = %d\n", ret);
            break;
        case FUN_RET_GET_CMD:
            ret = fun_ret_get_cmd((struct usr_ker_msg *)arg);
            bsp_err("fun_ret_get_cmd ret = %d\n", ret);
            break;
        default:
            bsp_err("undefined cmd\n");
            ret = -1;
    }
    return ret;
}

static unsigned int st_file_poll(struct file *file, poll_table *wait)
{
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;
    unsigned int mask = 0;
    poll_wait(file, &ctx->read_queue, wait);
    spin_lock(&ctx->fifo_lock);
    if (ctx->file_readable) {
        mask |= POLLIN | POLLRDNORM;
    }
    spin_unlock(&ctx->fifo_lock);
    return mask;
};

static struct file_operations fops = {
    .open = st_file_open,
    .release = st_file_release,
    .unlocked_ioctl = st_file_ioctl,
    .poll = st_file_poll,
};

int btest_parse_msg(struct btest_msg_file_ctx *ctx, struct btest_msg_list *msg)
{
    int ret = 0;

    ret = add_kfifo((char *)msg->buf, msg->len);
    if (ret) {
        bsp_err("add kfifo failed\n");
        return ret;
    }

    return 0;
}

static int btest_task(void *data)
{
    unsigned long flags;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;
    struct btest_msg_list *local_msg = NULL;

    while (1) {
        (void)down_interruptible(&ctx->task_sem);

        spin_lock_irqsave(&ctx->lock, flags);
        local_msg = list_first_entry_or_null(&ctx->msg_list, struct btest_msg_list, list);
        if (local_msg == NULL) {
            spin_unlock_irqrestore(&ctx->lock, flags);
            continue;
        }
        list_del(&local_msg->list);
        spin_unlock_irqrestore(&ctx->lock, flags);

        btest_parse_msg(ctx, local_msg);
        kfree((void *)local_msg);
    }
    return 0;
}

void btest_add_msg(struct btest_msg_file_ctx *ctx, struct btest_msg *msg)
{
    unsigned long flags;
    struct btest_msg_list *local_msg = NULL;
    int ret;
    unsigned int buf_len = msg->len;
    stream_buffer return_buffer;

    if (msg->cmd == BTEST_ST_LPMCU_FUN_CALL) {
        return_buffer = form_lpmcu_return(msg);
        if (return_buffer == NULL) {
            bsp_err("form return_cmsg failed\n");
            return;
        }
        buf_len = get_buffer_length(return_buffer);
    }

    if (msg->cmd == BTEST_ST_FUN_CALL || msg->cmd == BTEST_ST_LPMCU_FUN_CALL) {
        local_msg = kmalloc(sizeof(struct btest_msg_list) + buf_len, GFP_KERNEL);
        if (local_msg == NULL) {
            bsp_err("kmalloc fail\n");
            return;
        }

        ret = memcpy_s(&local_msg->cmd, sizeof(struct btest_msg) + msg->len, msg, sizeof(struct btest_msg) + msg->len);
        if (ret != EOK) {
            bsp_err("copy fail\n");
        }

        if (msg->cmd == BTEST_ST_LPMCU_FUN_CALL) {
            ret = memcpy_s(&local_msg->buf, buf_len, get_buffer_data(return_buffer), buf_len);
            local_msg->len = buf_len;
            destroy_buffer(return_buffer);
            if (ret != EOK) {
                bsp_err("copy return_buffer fail\n");
            }
        }

        spin_lock_irqsave(&ctx->lock, flags);
        list_add_tail(&local_msg->list, (&ctx->msg_list));
        spin_unlock_irqrestore(&ctx->lock, flags);
        up(&ctx->task_sem);
    }
    else {
        if (g_btest_ctx.acore_msg_read_cb != NULL) {
            g_btest_ctx.acore_msg_read_cb(msg, msg->len);
        }
        else {
            bsp_err("acore_msg_read_cb is null\n");
        }
    }
}

#ifdef CONFIG_DPA_DMI
static int btest_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *dmi_msg)
{
    struct btest_msg *msg = NULL;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;

    if (dmi_msg->len < sizeof(struct btest_msg) || dmi_msg->len > BTEST_DATA_MAX_LEN) {
        bsp_err("msg param err:%d\n", dmi_msg->len);
        dpa_dmi_msg_free(dmi_msg);
        return -1;
    }

    msg = (struct btest_msg *)dmi_msg->buf;
    btest_add_msg(ctx, msg);
    dpa_dmi_msg_free(dmi_msg);

    return 0;
}

int btest_msg_dmi_init(void)
{
    struct dmi_client client;
    int ret;

    ret = dpa_dmi_client_init(&client);
    if (ret != 0) {
        bsp_err("btest dpa_dmi_client_init fail %d\n", ret);
        return -1;
    }

    client.dmi_id = DMI_SERVICE_BTEST;
    client.service_cb = btest_service_cb;

    ret = dpa_dmi_client_register(&client);
    if (ret != 0) {
        bsp_err("wan dpa_dmi_client_register fail %d\n", ret);
        return -1;
    }

    return 0;
}
#else
int btest_msg_dmi_init(void)
{
    return 0;
}
#endif

static int btest_msg_read_cb(const struct msg_addr *src_info, void *buf, u32 len)
{
    struct btest_msg *msg = NULL;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;

    if (src_info == NULL || (src_info->core != MSG_CORE_TSP && src_info->core != MSG_CORE_LPM && src_info->core != MSG_CORE_DPA) || buf == NULL || len > BTEST_DATA_MAX_LEN) {
        bsp_err("msg param err:%d\n", src_info->core);
        return -1;
    }

    msg = (struct btest_msg *)buf;
    btest_add_msg(ctx, msg);

    return 0;
}

int btest_msg_init(void)
{
    int ret;
    struct msgchn_attr lite_attr;

    bsp_msgchn_attr_init(&lite_attr);
    lite_attr.chnid = MSG_CHN_BTEST;
    lite_attr.coremask = MSG_CORE_MASK(MSG_CORE_TSP) | MSG_CORE_MASK(MSG_CORE_LPM) | MSG_CORE_MASK(MSG_CORE_DPA);
    lite_attr.lite_notify = btest_msg_read_cb;
    ret = bsp_msg_lite_open(&g_btest_msghdl, &lite_attr);
    if (ret) {
        bsp_err("open msg fail:%d\n", ret);
        return ret;
    }
    if (btest_msg_dmi_init()) {
        bsp_err("btest dmi msg init fail\n");
    }

    bsp_err("btest msg init ok\n");
    return ret;
}

static int btest_file_init(void)
{
    int ret;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;

    ret = alloc_chrdev_region(&ctx->dev_num, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        bsp_err("Failed alloc_chrdev_region\n");
        return ret;
    }

    cdev_init(&ctx->cdevp, &fops);
    ret = cdev_add(&ctx->cdevp, ctx->dev_num, 1);
    if (ret < 0) {
        bsp_err("Failed cdev_add\n");
        return ret;
    }

    ctx->st_file_class = class_create(THIS_MODULE, CLASS_NAME);
    if (IS_ERR(ctx->st_file_class)) {
        bsp_err("Failed to create class\n");
        cdev_del(&ctx->cdevp);
        unregister_chrdev_region(ctx->dev_num, 1);
        return PTR_ERR(ctx->st_file_class);
    }

    if (IS_ERR(device_create(ctx->st_file_class, NULL, ctx->dev_num, NULL, DEVICE_NAME))) {
        bsp_err("Failed to create device\n");
        class_destroy(ctx->st_file_class);
        cdev_del(&ctx->cdevp);
        unregister_chrdev_region(ctx->dev_num, 1);
        return PTR_ERR(ctx->st_file_class);
    }
    bsp_err("btest file init ok\n");

    ctx->file_readable = 0;

    init_waitqueue_head(&ctx->read_queue);
    
    INIT_KFIFO(st_fifo);
    spin_lock_init(&ctx->fifo_lock);

    return 0;
}

int st_file_init(void)
{
    int ret;
    struct btest_msg_file_ctx *ctx = &g_btest_ctx;

    ret = btest_file_init();
    if (ret != 0) {
        bsp_err("msg init fail, ret = %d\n", ret);
        return -1;
    }

    spin_lock_init(&ctx->lock);
    INIT_LIST_HEAD(&ctx->msg_list);
    sema_init(&ctx->task_sem, 0);
    ctx->task = kthread_run(btest_task, NULL, "btest_task");

    INIT_LIST_HEAD(&ctx->lpmcu_cmsg_list.list);

    ret = btest_msg_init();
    if (ret != 0) {
        bsp_err("msg init fail, ret = %d\n", ret);
        return -1;
    }
    bsp_err("btest init succees\n");

    return 0;
}

EXPORT_SYMBOL(register_msg_read_cb);
EXPORT_SYMBOL(get_btest_msghdl);

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(st_file_init);
#endif
