/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: UART Function Implementation
 * Author: platform drivers
 */

#include <linux/tty.h>
#include <linux/tty_flip.h>

#include "chr_user.h"
#include "plat_exception_rst.h"
#include "plat_debug.h"

#include "bfgx_dev.h"
#include "bfgx_core.h"
#include "bfgx_data_parse.h"
#include "plat_uart.h"

#ifdef _PRE_CONFIG_USE_OCTTY

#define HISI_LDISC_TIME 2000  /* time in msec to wait for line discipline to be installed */

enum TTY_COMPLETE_TYPE_ENUM {
    TTY_LDISC_UNINSTALL = 0, /* 通知octty关闭uart */
    TTY_LDISC_INSTALL = 1,   /* 通知octty打开uart */
    TTY_LDISC_RECONFIG = 2,  /* 通知octty修改uart的配置参数，波特率和流控 */

    TTY_LDISC_TYPE_BUTT,
};

STATIC uint32_t g_ldisc_complete_status = TTY_LDISC_TYPE_BUTT;
STATIC oal_completion g_ldisc_uninstalled;
STATIC oal_completion g_ldisc_installed;
STATIC oal_completion g_ldisc_reconfiged;

/*
 * Prototype    : ps_get_plat_reference
 * Description  : reference the plat's dat,This references the per-PS
 *                  platform device in the arch/arm/board-xx.c file.
 */
STATIC int32_t ps_get_plat_reference(struct ps_plat_s **plat_data)
{
    struct ps_core_s *ps_core_d = ps_get_core_reference(BUART);
    if (ps_core_d == NULL) {
        ps_print_err("ps_core_d is NULL\n");
        return -EFAULT;
    }
    *plat_data = (struct ps_plat_s *)ps_core_d->ps_plat;

    return OAL_SUCC;
}

STATIC ssize_t show_install(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    PS_PRINT_FUNCTION_NAME;

    if (buf == NULL) {
        ps_print_err("buf is NULL\n");
        return -EINVAL;
    }

    return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", g_ldisc_complete_status);
}

/* read by octty from hal to decide open which uart */
STATIC ssize_t show_dev_name(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    struct ps_plat_s *pm_data = NULL;

    PS_PRINT_FUNCTION_NAME;

    if (buf == NULL) {
        ps_print_err("buf is NULL\n");
        return -EINVAL;
    }

    ps_get_plat_reference(&pm_data);
    if (pm_data == NULL) {
        ps_print_err("pm_data is NULL!\n");
        return -EPERM;
    }

    return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", pm_data->uart_name);
}

/* read by octty from hal to decide what baud rate to use */
STATIC ssize_t show_baud_rate(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    struct ps_plat_s *pm_data = NULL;

    PS_PRINT_FUNCTION_NAME;

    if (buf == NULL) {
        ps_print_err("buf is NULL\n");
        return -EINVAL;
    }

    ps_get_plat_reference(&pm_data);
    if (pm_data == NULL) {
        ps_print_err("pm_data is NULL!\n");
        return -EPERM;
    }

    return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%lu\n", pm_data->baud_rate);
}

/* read by octty from hal to decide whether or not use flow cntrl */
STATIC ssize_t show_flow_cntrl(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    struct ps_plat_s *pm_data = NULL;

    PS_PRINT_FUNCTION_NAME;

    if (buf == NULL) {
        ps_print_err("buf is NULL\n");
        return -EINVAL;
    }

    ps_get_plat_reference(&pm_data);
    if (pm_data == NULL) {
        ps_print_err("pm_data is NULL!\n");
        return -EPERM;
    }

    return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", pm_data->flow_cntrl);
}

STATIC struct kobj_attribute g_ldisc_install =
    __ATTR(install, 0444, (void *)show_install, NULL);

STATIC struct kobj_attribute g_uart_dev_name =
    __ATTR(dev_name, 0444, (void *)show_dev_name, NULL);

STATIC struct kobj_attribute g_uart_baud_rate =
    __ATTR(baud_rate, 0444, (void *)show_baud_rate, NULL);

STATIC struct kobj_attribute g_uart_flow_cntrl =
    __ATTR(flow_cntrl, 0444, (void *)show_flow_cntrl, NULL);

STATIC struct attribute *g_bfgx_octty_attrs[] = {
    &g_ldisc_install.attr,
    &g_uart_dev_name.attr,
    &g_uart_baud_rate.attr,
    &g_uart_flow_cntrl.attr,
};

STATIC struct attribute_group g_bfgx_octty_attr_grp = {
    .attrs = g_bfgx_octty_attrs,
};

/* no lock while getting the state, just statistic */
/* call only in one place!!! */
void ps_tty_tx_cnt_add(struct ps_core_s *ps_core_d, uint32_t cnt)
{
    oal_atomic_add(&(ps_core_d->tty_tx_cnt), cnt);
}

/* call only in one place!!! */
static void ps_tty_rx_cnt_add(struct ps_core_s *ps_core_d, uint32_t cnt)
{
    oal_atomic_add(&(ps_core_d->tty_rx_cnt), cnt);
}

static void ps_uart_state_print(struct tty_struct *tty)
{
    struct serial_icounter_struct icount;

    chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                         CHR_PLT_DRV_EVENT_UART, CHR_PLAT_DRV_ERROR_UART_PRINT);

    ps_print_info("stopped:%x  hw_stopped:%x\n", tty->stopped, tty->hw_stopped);

    if (tty->ops->get_icount(tty, &icount) < 0) {
        ps_print_err("get icount error\n");
        return;
    }

    ps_print_info("uart tx:%x    rx:%x\n", icount.tx, icount.rx);
    ps_print_info("uart cts:%x,dsr:%x,rng:%x,dcd:%x,frame:%x,overrun:%x,parity:%x,brk:%x,buf_overrun:%x\n",
                  icount.cts, icount.dsr, icount.rng, icount.dcd,
                  icount.frame, icount.overrun, icount.parity, icount.brk,
                  icount.buf_overrun);
    return;
}

static void ps_tty_buffer_print(struct tty_struct *tty)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35))
    struct tty_buffer *thead = NULL;
    struct tty_bufhead *buf = NULL;

    if (tty->port == NULL) {
        return;
    }

    if ((oal_in_interrupt() != 0) || (oal_in_atomic() != 0)) {
        ps_print_info("in_interrupt or in_atomic\n");
        return;
    }

    tty_buffer_lock_exclusive(tty->port);
    buf = &(tty->port->buf);
    thead = buf->head;
    while (thead != NULL) {
        ps_print_info("tty rx buf:used=0x%x,size=0x%x,commit=0x%x,read=0x%x\n",
                      thead->used, thead->size, thead->commit, thead->read);
        thead = thead->next;
    }
    tty_buffer_unlock_exclusive(tty->port);
#endif
}

void ps_uart_state_dump(struct ps_core_s *ps_core_d)
{
    struct tty_struct *tty = NULL;

    /* user版本受控 */
    if (is_hi110x_debug_type() == OAL_FALSE) {
        ps_print_info("uart state dump ignore\n");
        return;
    }

    tty = ps_core_d->tty;
    if (tty_kref_get(tty) == NULL) {
        ps_print_err("ps_core_d or tty is NULL\n");
        return;
    }

    ps_print_info("===uart&tty state===\n");
    ps_print_info("tty tx:%x, rx:%x\n", oal_atomic_read(&(ps_core_d->tty_tx_cnt)),
                  oal_atomic_read(&(ps_core_d->tty_rx_cnt)));
    ps_print_info("chars in tty tx buf len=%x\n", tty_chars_in_buffer(tty));

    ps_uart_state_print(tty);
    ps_tty_buffer_print(tty);
    ps_print_info("tty_kref_put:\n");
    tty_kref_put(tty);

    return;
}

/*
 * Prototype    : ps_tty_complete
 * Description  : to signal completion of line discipline installation
 *                called from PS Core, upon tty_open.
 */
STATIC int32_t ps_tty_complete(uint8_t install)
{
    ps_print_info("[%d]: %s\n", __LINE__, __func__);
    switch (install) {
        case TTY_LDISC_UNINSTALL:
            complete(&g_ldisc_uninstalled);
            ps_print_info("octty uninstall complete done!\n");
            break;

        case TTY_LDISC_INSTALL:
            complete(&g_ldisc_installed);
            ps_print_info("octty install complete done!\n");
            break;

        case TTY_LDISC_RECONFIG:
            complete(&g_ldisc_reconfiged);
            ps_print_info("octty reconfig complete done!\n");
            break;

        default:
            ps_print_err("unknown install type [%d]\n", install);
            break;
    }
    return 0;
}

/*
 * Prototype    : is_hisi_connetivity_tty
 * Description  : check the tty can match hisi connectivity ldisc
 */
static bool is_hisi_connetivity_tty(struct ps_core_s *ps_core_d)
{
    struct ps_plat_s *ps_plat_d = NULL;
    const char *tty_name = NULL;

    if (ps_core_d == NULL) {
        ps_print_err("ps core is NULL\n");
        return false;
    }

    ps_plat_d = (struct ps_plat_s *)(ps_core_d->ps_plat);
    if (unlikely(ps_plat_d == NULL)) {
        ps_print_err("ps_plat_d is NULL\n");
        return false;
    }

    tty_name = get_tty_name(ps_plat_d);
    if (strcmp(tty_name, ps_core_d->tty->name) != 0) {
        return false;
    }
    return true;
}

/*
 * Prototype    : ps_tty_open
 * Description  : called by tty uart itself when open tty uart from octty
 * input        : tty -> have opened tty
 */
static int32_t ps_tty_open(struct tty_struct *tty)
{
    uint8_t install;
    struct ps_core_s *ps_core_d = NULL;

    ps_print_info("%s enter\n", __func__);

    ps_core_d = ps_get_core_by_uart_name(tty->name);
    if (unlikely(ps_core_d == NULL)) {
        ps_print_err("ps_core_d is NULL\n");
        return -EINVAL;
    }

    ps_core_d->tty = tty;
    tty->disc_data = ps_core_d;

    /* don't do an wakeup for now */
    clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);

    /* set mem already allocated */
    tty->receive_room = PUBLIC_BUF_MAX;
    /* Flush any pending characters in the driver and discipline. */
    tty_ldisc_flush(tty);
    tty_driver_flush_buffer(tty);

    install = g_ldisc_complete_status;
    if (install == TTY_LDISC_INSTALL || install == TTY_LDISC_RECONFIG) {
        ps_tty_complete(install);
    } else {
        ps_print_err("ldisc_install [%d] is error!\n", install);
        return -EINVAL;
    }

    return 0;
}

/*
 * Prototype    : ps_tty_close
 * Description  : called by tty uart when close tty uart from octty
 * input        : tty -> have opened tty
 */
static void ps_tty_close(struct tty_struct *tty)
{
    ps_print_info("[%s]%s enter\n", tty_name(tty), __func__);

    if (!is_hisi_connetivity_tty(tty->disc_data)) {
        ps_print_err("tty %s recognize fail\n", tty_name(tty));
        return;
    }

    /* Flush any pending characters in the driver and discipline. */
    tty_ldisc_flush(tty);
    tty_driver_flush_buffer(tty);

	/* signal to complate that N_HW_BFG ldisc is un-installed */
    ps_tty_complete(TTY_LDISC_UNINSTALL);

    tty->disc_data = NULL;
    ps_print_info("tty %s flush done!\n", tty_name(tty));
}

static int32_t ps_tty_receive_check(struct tty_struct *tty, int32_t count, const uint8_t *data)
{
#ifdef PLATFORM_DEBUG_ENABLE
    struct ps_core_s *ps_core_d = NULL;
#endif

    if (unlikely(st_tty_recv == NULL)) {
        ps_print_err("[%s] st_tty_recv is NULL\n", tty_name(tty));
        return -EINVAL;
    }

    if (!is_hisi_connetivity_tty(tty->disc_data)) {
        ps_print_err("tty %s recognize fail\n", tty_name(tty));
        return -EINVAL;
    }

    if (unlikely(data == NULL)) {
        ps_print_err("[%s] received null from TTY\n", tty_name(tty));
        return -EINVAL;
    }

    if (unlikely(count < 0)) {
        ps_print_err("[%s] received count from TTY err\n", tty_name(tty));
        return -EINVAL;
    }

#ifdef PLATFORM_DEBUG_ENABLE
    // 心跳超时DFR打桩验证
    ps_core_d = tty->disc_data;
    if (is_dfr_test_en(HEARTBEATER_TIMEOUT_FAULT, (uintptr_t)ps_core_d)) {
        if (oal_print_rate_limit(PRINT_RATE_SECOND)) {
            ps_print_info("[%s]heartbeat dfr test, drop TTY data\n", tty_name(tty));
        }
        return -EINVAL;
    }
#endif

    return 0;
}

static int32_t ps_tty_parity_check(struct tty_struct *tty, const uint8_t *data, char *tty_flags, int32_t count)
{
    int i;
    char flags;
    const unsigned char *cp = NULL;
    int32_t ret = OAL_SUCC;

    if (tty_flags == NULL) {
        // uart parity check
        return ret;
    }

    for (i = 0, cp = tty_flags; i < count; i++, cp++) {
        flags = *cp;
        switch (flags) {
            case TTY_NORMAL:
                // parity pass
                break;
            case TTY_OVERRUN:
            case TTY_BREAK:
            case TTY_PARITY:
            case TTY_FRAME:
                /* fall-throuth */
                // tty errors
                ret = -OAL_EIO;
                ps_print_err("[%s][%d][parity check error]: tty err flag:%d\n", tty_name(tty), i, flags);
                break;
            default:
                ret = -OAL_EIO;
                ps_print_err("[%s][%d][parity check error]: unkown tty flag:%d\n", tty_name(tty), i, flags);
                break;
        }

        if (oal_unlikely(ret != OAL_SUCC)) {
            break;
        }
    }

    if (oal_unlikely(ret != OAL_SUCC)) {
        // dump parity error memory
        oal_print_hex_dump((uint8_t *)data, count, 32, "tty receive: "); // 32B col
        oal_print_hex_dump((uint8_t *)tty_flags, count, 32, "tty flags: "); // 32B col
        declare_dft_trace_key_info("tty_parity_error", OAL_DFT_TRACE_EXCEP);
    }

    return ret;
}

/*
 * Prototype    : ps_tty_receive_parity_check
 * Description  : called by tty uart when recive data from tty uart, with uart parity check
 * input        : tty   -> have opened tty
 *                data -> recive data ptr
 *                count-> recive data count
 */
static int32_t ps_tty_receive_parity_check(struct tty_struct *tty, const uint8_t *data, char *tty_flags, int32_t count)
{
    int32_t ret = OAL_SUCC;
    struct ps_core_s *ps_core_d = tty->disc_data;
    struct ps_plat_s *ps_plat_data = (struct ps_plat_s *)(ps_core_d->ps_plat);

    oal_spin_lock(&ps_core_d->rx_lock);
    /* 没有使能奇偶校验，不做检查，避免性能损失 */
    if (ps_plat_data->paren == OAL_TRUE) {
        ret = ps_tty_parity_check(tty, data, tty_flags, count);
    }

    ps_tty_rx_cnt_add(ps_core_d, count);
    if (oal_likely(st_tty_recv != NULL)) {
        st_tty_recv(tty->disc_data, data, count);
    }
    oal_spin_unlock(&ps_core_d->rx_lock);
    return ret;
}

/*
 * Prototype    : ps_tty_receive
 * Description  : called by tty uart when recive data from tty uart
 * input        : tty   -> have opened tty
 *                data -> recive data ptr
 *                count-> recive data count
 */
static void ps_tty_receive(struct tty_struct *tty, const uint8_t *data, char *tty_flags, int32_t count)
{
    int32_t ret;

    if (ps_tty_receive_check(tty, count, data) < 0) {
        return;
    }

    ret = ps_tty_receive_parity_check(tty, data, tty_flags, count);
    if (oal_unlikely(ret != OAL_SUCC)) {
        // uart loss pkts, do dfr same as hb timeout
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_DEV, CHR_PLAT_DRV_ERROR_BEAT_TIMEOUT);
    }
}

/*
 * Prototype    : ps_tty_wakeup
 * Description  : called by tty uart when wakeup from suspend
 * input        : tty   -> have opened tty
 */
static void ps_tty_wakeup(struct tty_struct *tty)
{
    struct ps_core_s *ps_core_d = NULL;

    PS_PRINT_FUNCTION_NAME;

    if (!is_hisi_connetivity_tty(tty->disc_data)) {
        return;
    }

    ps_core_d = tty->disc_data;
    /* don't do an wakeup for now */
    clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);

    /* call our internal wakeup */
    ps_core_tx_work_add(ps_core_d);
}

static void ps_clean_tx_skb_buf(struct ps_core_s *ps_core_d)
{
#define WAIT_TX_WORK_DELAY 20
    uint8_t delay_times = RELEASE_DELAT_TIMES;
    if (ps_core_d == NULL) {
        ps_print_err("ps_core_d is NULL\n");
        return;
    }

    ps_kfree_skb(ps_core_d, TX_HIGH_QUEUE);
    ps_kfree_skb(ps_core_d, TX_LOW_QUEUE);

    ps_print_info("free tx sbk buf done!\n");

    /* clean all tx sk_buff */
    while ((oal_netbuf_list_len(&ps_core_d->tx_high_seq)
           || oal_netbuf_list_len(&ps_core_d->tx_low_seq)) && (delay_times)) {
        msleep(10); // sleep 10ms
        delay_times--;
    }

    if (oal_work_is_busy(&ps_core_d->tx_skb_work)) {
        ps_print_info("hisi bfgx notify tx work exit\n");
        atomic_set(&ps_core_d->force_tx_exit, 1);
        // wait for tx work exit
        msleep(WAIT_TX_WORK_DELAY);
    }

    if (!oal_is_err_or_null(ps_core_d->tty)) {
        if (tty_chars_in_buffer(ps_core_d->tty)) {
            ps_print_info("uart tx buf need clean, or it will block in uart close\n");
            tty_driver_flush_buffer(ps_core_d->tty);
        }
    }
}

/*
 * Prototype    : ps_tty_flush_buffer
 * Description  : called by tty uart when flush buffer
 * input        : tty   -> have opened tty
 */
static void ps_tty_flush_buffer(struct tty_struct *tty)
{
    struct ps_core_s *ps_core_d = NULL;

    ps_print_info("%s: entered\n", __func__);

    ps_core_d = tty->disc_data;
    if (!is_hisi_connetivity_tty(ps_core_d)) {
        ps_print_err("tty or tty->disc_data is NULL\n");
        return;
    }

    reset_uart_rx_buf(ps_core_d);
}

int32_t ps_tty_resume(struct tty_struct *tty)
{
#define MAX_TTYRESUME_LOOPCNT 300

#ifdef ASYNCB_SUSPENDED
    uint32_t loop_tty_resume_cnt = 0;
#endif

    if (tty == NULL || tty->port == NULL) {
        ps_print_err("tty port has not inited\n");
        return OAL_FALSE;
    }

#if ((LINUX_VERSION_CODE >= KERNEL_VERSION(4, 7, 0)) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION))
    while (tty_port_suspended(tty->port)) {
#ifdef ASYNCB_SUSPENDED
        if (loop_tty_resume_cnt++ >= MAX_TTYRESUME_LOOPCNT) {
            ps_print_err("tty is not ready, state:%d!\n", tty_port_suspended(tty->port));
            return OAL_FALSE;
        }
#endif
        oal_msleep(10); // 等待10ms，tty从suspend恢复
    }
#ifdef ASYNCB_SUSPENDED
    ps_print_info("tty state:0x%x,loop_cnt:%d\n", tty_port_suspended(tty->port), loop_tty_resume_cnt);
#endif
#else
    ps_print_info("tty port flag 0x%x\n", (unsigned int)tty->port->flags);
#ifdef ASYNCB_SUSPENDED
    while (test_bit(ASYNCB_SUSPENDED, (volatile unsigned long *)&(tty->port->flags))) {
        if (loop_tty_resume_cnt++ >= MAX_TTYRESUME_LOOPCNT) {
            ps_print_err("tty is not ready, flag is 0x%x!\n", (unsigned int)tty->port->flags);
            return OAL_FALSE;
        }
        oal_msleep(10); // 等待10ms，tty从suspend恢复
    }
#endif
#endif

    return OAL_TRUE;
}

unsigned long ps_get_default_baud_rate(struct ps_core_s *ps_core_d)
{
    struct ps_plat_s *ps_plat_d = (struct ps_plat_s *)(ps_core_d->ps_plat);

    return ps_plat_d->baud_rate;
}

/*
 * Prototype    : ps_change_uart_baud_rate_etc
 * Description  : change arm platform uart baud rate to secend
 *                baud rate for high baud rate when download patch
 */
int32_t ps_change_uart_baud_rate(struct ps_core_s *ps_core_d, long baud_rate, uint8_t enable_flowctl)
{
    uint64_t timeleft = 0;
    struct ps_plat_s *ps_plat_d = (struct ps_plat_s *)(ps_core_d->ps_plat);

    ps_print_info("%s:%s %lu\n", __func__, get_tty_name(ps_plat_d), baud_rate);

    ps_get_plat_reference(&ps_plat_d);
    if (unlikely(ps_plat_d == NULL)) {
        ps_print_err("ps_plat_d is NULL\n");
        return -EINVAL;
    }

    /* for debug only */
    dump_uart_rx_buf(ps_core_d);

    if (atomic_read(&ps_core_d->is_memdump_runing) == 1) {
        oal_reinit_completion(ps_core_d->wait_read_bfgx_stack);
        /* wait for read stack completion */
        timeleft = wait_for_completion_timeout(&ps_core_d->wait_read_bfgx_stack,
                                               msecs_to_jiffies(WAIT_BFGX_READ_STACK_TIME));
        if (!timeleft) {
            ps_uart_state_dump(ps_core_d);
            atomic_set(&ps_core_d->is_memdump_runing, 0);
            ps_print_err("read bfgx stack failed!\n");
        } else {
            ps_print_info("read bfgx stack success!\n");
        }
    }

    if (!oal_is_err_or_null(ps_core_d->tty)) {
        if (tty_chars_in_buffer(ps_core_d->tty)) {
            ps_print_info("uart tx buf is not empty\n");
            tty_driver_flush_buffer(ps_core_d->tty);
        }
    }

    oal_reinit_completion(g_ldisc_reconfiged);
    ps_plat_d->flow_cntrl = enable_flowctl;
    ps_plat_d->baud_rate = baud_rate;
    g_ldisc_complete_status = TTY_LDISC_RECONFIG;

    ps_print_info("ldisc_install = %d\n", TTY_LDISC_RECONFIG);
    sysfs_notify(bfgx_get_hi110x_bfgx_kobject(), NULL, "install");
    timeleft = wait_for_completion_timeout(&g_ldisc_reconfiged, msecs_to_jiffies(HISI_LDISC_TIME));
    if (!timeleft) {
        ps_print_err("hisi bfgx ldisc reconfig timeout\n");
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_UART, CHR_PLAT_DRV_ERROR_UART_BAURD);
        return -EINVAL;
    }

    ps_print_suc("hisi bfgx ldisc reconfig succ\n");

    return 0;
}
 
/*
 * Prototype    : open_tty_drv_etc
 * Description  : called from PS Core when BT protocol stack drivers
 *                registration,or FM/GNSS hal stack open FM/GNSS inode
 */
int32_t open_tty_drv(struct ps_core_s *ps_core_d)
{
    struct ps_plat_s *ps_plat_d = NULL;
    uint8_t retry = OPEN_TTY_RETRY_COUNT;
    uint64_t timeleft = 0;

    ps_print_info("%s\n", __func__);
    ps_plat_d = (struct ps_plat_s *)(ps_core_d->ps_plat);
    if (ps_plat_d == NULL) {
        ps_print_err("ps_plat_d is NULL\n");
        return 0;
    }

    if (ps_core_d->tty_have_open == true) {
        ps_print_err("hisi bfgx line discipline have installed\n");
        return 0;
    }

    reset_uart_rx_buf(ps_core_d);
    do {
        oal_reinit_completion(g_ldisc_installed);
        g_ldisc_complete_status = TTY_LDISC_INSTALL;

        ps_print_info("ldisc_install = %d,baud=%lu\n", TTY_LDISC_INSTALL, ps_plat_d->baud_rate);
        sysfs_notify(bfgx_get_hi110x_bfgx_kobject(), NULL, "install");
        timeleft = wait_for_completion_timeout(&g_ldisc_installed, msecs_to_jiffies(HISI_LDISC_TIME));
        if (!timeleft) {
            ps_print_err("hisi bfgx ldisc installation timeout\n");
            continue;
        } else {
            ps_print_info("hisi bfgx line discipline install succ\n");
            ps_core_d->tty_have_open = true;
            return 0;
        }
    } while (retry--);

    chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                         CHR_PLT_DRV_EVENT_UART, CHR_PLAT_DRV_ERROR_OPEN_TTY);

    return -EPERM;
}
 
/*
 * Prototype    : release_tty_drv_etc
 * Description  : called from PS Core when BT protocol stack drivers
 *                  unregistration,or FM/GNSS hal stack close FM/GNSS inode
 */
int32_t release_tty_drv(struct ps_core_s *ps_core_d)
{
    int32_t error;
    struct ps_plat_s *ps_plat_d = NULL;
    struct tty_struct *tty = NULL;
    uint64_t timeleft;

    ps_plat_d = (struct ps_plat_s *)(ps_core_d->ps_plat);
    if (ps_plat_d == NULL) {
        ps_print_err("ps_plat_d is NULL\n");
        return 0;
    }

    if (ps_core_d->tty_have_open == false) {
        ps_print_info("hisi bfgx line discipline have uninstalled, ignored\n");
        return 0;
    }

    ps_clean_tx_skb_buf(ps_core_d);

    mutex_lock(&ps_core_d->tty_mutex);
    atomic_set(&ps_core_d->force_tx_exit, 0);
    tty = ps_core_d->tty;
    if (tty != NULL) { /* can be called before ldisc is installed */
        /* Flush any pending characters in the driver and discipline. */
        ps_print_info(" %s--> into flush_buffer\n", __func__);
        tty_ldisc_flush(tty);
        tty_driver_flush_buffer(tty);
    }
    mutex_unlock(&ps_core_d->tty_mutex);

    oal_reinit_completion(g_ldisc_uninstalled);
    g_ldisc_complete_status = TTY_LDISC_UNINSTALL;

    ps_print_info("ldisc_install = %d\n", TTY_LDISC_UNINSTALL);
    sysfs_notify(bfgx_get_hi110x_bfgx_kobject(), NULL, "install");
    timeleft = wait_for_completion_timeout(&g_ldisc_uninstalled, msecs_to_jiffies(HISI_LDISC_TIME));
    if (!timeleft) {
        ps_print_err("hisi bfgx ldisc uninstall timeout\n");
        error = -ETIMEDOUT;
    } else {
        ps_print_suc("hisi bfgx line discipline uninstall succ\n");
        error = 0;
    }
    ps_core_d->tty_have_open = false;
    ps_plat_d->flow_cntrl = FLOW_CTRL_ENABLE;
    ps_plat_d->baud_rate = ps_get_default_baud_rate(ps_core_d);

    return error;
}

static int32_t ps_uart_octty_init(struct ps_plat_s *ps_plat_d)
{
    struct kobject *sysfs_hi110x_bfgx = bfgx_get_hi110x_bfgx_kobject();
    int status;
    status = sysfs_create_group(sysfs_hi110x_bfgx, &g_bfgx_octty_attr_grp);
    if (status) {
        ps_print_err("failed to create g_sysfs_hi110x_bfgx sysfs entries\n");
        goto fail_create_bfgx_octty_group;
    }
    oal_init_completion(&g_ldisc_uninstalled);
    oal_init_completion(&g_ldisc_installed);
    oal_init_completion(&g_ldisc_reconfiged);
    return 0;

fail_create_bfgx_octty_group:
    kobject_put(sysfs_hi110x_bfgx);
    return -EFAULT;
}

static struct tty_ldisc_ops g_ps_ldisc_ops = {
    .magic = TTY_LDISC_MAGIC,
    .name = "n_ps",
    .open = ps_tty_open,
    .close = ps_tty_close,
    .receive_buf = ps_tty_receive,
    .write_wakeup = ps_tty_wakeup,
    .flush_buffer = ps_tty_flush_buffer,
    .owner = THIS_MODULE
};

int32_t plat_uart_init(struct ps_plat_s *ps_plat_d)
{
#ifdef N_HW_BFG
    uint32_t ldisc_num = ps_plat_d->ldisc_num;
    int32_t ret;
    ret = ps_uart_octty_init(ps_plat_d);
    if (ret < 0) {
        ps_print_err("octty uart init fail\n");
        return -OAL_FAIL;
    }
    if (ldisc_num < 0 || ldisc_num > N_HW_BFG) {
        ps_print_err("ldisc num %d invalid\n", ldisc_num);
        return -OAL_FAIL;
    }

    return tty_register_ldisc(ldisc_num, &g_ps_ldisc_ops);
#else
    return OAL_SUCC;
#endif
}

void plat_uart_exit(int32_t ldisc_num)
{
#ifdef N_HW_BFG
    int32_t  ret;

    if (ldisc_num < 0 || ldisc_num > N_HW_BFG) {
        ps_print_err("ldisc num %d invalid\n", ldisc_num);
        return;
    }

    ret = tty_unregister_ldisc(ldisc_num);
    if (ret != 0) {
        ps_print_err("unregister ldisc ret %d\n", ret);
    }
#endif
}

#endif