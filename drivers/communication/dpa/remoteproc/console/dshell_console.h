#ifndef DSHELL_CONSOLE_H
#define DSHELL_CONSOLE_H

#include <linux/kfifo.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <bsp_print.h>
#include <linux/miscdevice.h>

#undef THIS_MODU
#define THIS_MODU mod_dshell

#define VIRTSHL_MAX_PACKAGE_LEN 256
#define LOG_BUF_SHIFT 14
#define CMD_BUF_SHIFT 8
#define dshell_port_info(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dshell_port_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dshell_port_print(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)


struct dshell_info {
    struct kfifo *cmdbuf;
    struct kfifo *logbuf;
    struct miscdevice misc;
    struct semaphore send_tsk_sem;
    struct task_struct *send_tsk_id;
    void (*start_tx)(struct dshell_info *con);
    int (*start_shell)(struct dshell_info *con);
    int (*logbuff_out)(struct kfifo *logbuf, unsigned char *outbuf, unsigned int size);
    int (*cmdbuff_in)(struct dshell_info *dshell, unsigned char *inbuf, unsigned int size);
    void (*logbuff_in)(struct kfifo *logbuf, unsigned char *inbuf, unsigned int size);
    int (*cmdbuff_out)(struct kfifo *cmdbuf, unsigned char *outbuf, unsigned int size);
};

extern struct dshell_info g_dshell_ap;
extern wait_queue_head_t g_read_waitq;


#endif