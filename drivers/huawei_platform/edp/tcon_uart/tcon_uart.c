/*
 * Huawei tcon uart driver
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include <securec.h>
#include <linux/workqueue.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include "tcon_uart.h"
#include "edp_log.h"

#define TCON_UART_OPEN 0
#define TCON_UART_CLOSE 1

#define TCON_UART_CLEAR_RECV 0
#define TCON_UART_SET_RECV 1

#define TCON_UART_CLEAR_SEND 0
#define TCON_UART_SET_SEND 1

#define TCON_UART_CTR_NO_INIT 0
#define TCON_UART_CTR_INIT 1

#define TCON_UART 28
#define PUBLIC_BUF_MAX (8 * 1024)
#define TCON_UART_WRITE_TIMEOUT 1000
#define TCON_UART_SEND_MAX 4000
#define TCON_UART_BUFF_LEN 1024

/* tcon uart */
struct _tcon_uart_recv {
	int controll_init;
	int open_flag;
	int send_state;
	int recv_state;
	spinlock_t uart_lock;
	struct completion send_complete;
};

static struct _tcon_uart_recv g_uart_controll = {
	.send_state = TCON_UART_CLEAR_SEND,
	.recv_state = TCON_UART_CLEAR_RECV,
	.controll_init = TCON_UART_CTR_NO_INIT,
	.open_flag = TCON_UART_CLOSE,
};

static struct tty_struct *g_tcon_uart = NULL;
static spinlock_t *g_uart_lock = &g_uart_controll.uart_lock;
static struct completion *g_send_complete = &g_uart_controll.send_complete;
static struct tcon_uart *g_uart = NULL;
static u8 g_recv_tcon_buf[TCON_UART_BUFF_LEN] = {0};
struct file *g_fp = NULL;

static int tcon_tty_open(struct tty_struct *tty)
{
	if (!tty) {
		edp_err("tty is null!\n");
		return TCON_UART_FAIL;
	}

	edp_info("tty: open\n");

	/* don't do an wakeup for now */
	clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);

	/* set mem already allocated */
	tty->receive_room = PUBLIC_BUF_MAX;
	/* Flush any pending characters in the driver and discipline. */
	tty_ldisc_flush(tty);
	tty_driver_flush_buffer(tty);
	return TCON_UART_OK;
}

static void tcon_tty_close(struct tty_struct *tty)
{
	edp_info("tty: close\n");
	return;
}

static void tcon_tty_receive(struct tty_struct *tty,
	const unsigned char *cp, char *fp, int count)
{
	int i = 0;
	static char recv_tmp[TCON_UART_BUFF_LEN] = {0};
	static int recv_tmp_pos = 0;

	if (!tty || !cp || !g_uart || count > TCON_UART_BUFF_LEN) {
		edp_err("tty/cp/fp/count/g_uart err!\n");
		return;
	}

	spin_lock_bh(g_uart_lock);
	if (g_uart_controll.send_state == TCON_UART_SET_SEND ||
		g_uart_controll.recv_state == TCON_UART_SET_RECV) {
		spin_unlock_bh(g_uart_lock);
		edp_err("err recv or write state!\n");
		return;
	}
	g_uart_controll.recv_state = TCON_UART_SET_RECV;
	spin_unlock_bh(g_uart_lock);

	mb();
	for (i = 0; i < count; i++) {
		recv_tmp[recv_tmp_pos++] = cp[i];
		if (cp[i] == '\n' || recv_tmp_pos >= TCON_UART_BUFF_LEN) {
			flush_delayed_work(&g_uart->recv_work); 
			spin_lock_bh(g_uart_lock);
			if (memcpy_s(g_recv_tcon_buf, TCON_UART_BUFF_LEN, recv_tmp, sizeof(recv_tmp)) != EOK) {
				g_uart_controll.recv_state = TCON_UART_CLEAR_RECV;
				spin_unlock_bh(g_uart_lock);
				recv_tmp_pos = 0;
				edp_err("memcpy recv buf error!\n");
				return;
			}
			spin_unlock_bh(g_uart_lock);

			schedule_delayed_work(&g_uart->recv_work, 0);

			if (memset_s(recv_tmp, sizeof(recv_tmp), 0, sizeof(recv_tmp)) != EOK) {
				spin_lock_bh(g_uart_lock);
				g_uart_controll.recv_state = TCON_UART_CLEAR_RECV;
				spin_unlock_bh(g_uart_lock);
				recv_tmp_pos = 0;
				edp_err("memset recv buf error!\n");
				return;
			}

			recv_tmp_pos = 0;
		}
	}

	spin_lock_bh(g_uart_lock);
	g_uart_controll.recv_state = TCON_UART_CLEAR_RECV;
	spin_unlock_bh(g_uart_lock);

	return;
}

static void tcon_tty_wakeup(struct tty_struct *tty)
{
	if (!tty)
		return;
	/* clear wakeup flage for now */
	clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);

	spin_lock_bh(g_uart_lock);
	if (g_uart_controll.send_state != TCON_UART_SET_SEND) {
		spin_unlock_bh(g_uart_lock);
		return;
	}
	g_uart_controll.send_state = TCON_UART_CLEAR_SEND;
	spin_unlock_bh(g_uart_lock);

	complete(g_send_complete);
	return;
}

static struct tty_ldisc_ops tcon_ldisc_ops = {
	.magic = TTY_LDISC_MAGIC,
	.name = "tcon_tty",
	.open = tcon_tty_open,
	.close = tcon_tty_close,
	.receive_buf = tcon_tty_receive,
	.write_wakeup = tcon_tty_wakeup,
	.owner = THIS_MODULE
};

static void tcon_uart_set_termios(struct tty_struct *tty, long baud_rate)
{
	struct ktermios ktermios;

	if (!tty) {
		edp_err("tty is NULL\n");
		return;
	}

	ktermios = tty->termios;
	/* close soft flowctrl */
	ktermios.c_iflag = 0;
	/* set uart cts/rts flowctrl */
	ktermios.c_cflag &= ~CRTSCTS;
	/* set csize */
	ktermios.c_cflag &= ~(CSIZE);
	ktermios.c_cflag |= CS8;
	/* set uart baudrate */
	ktermios.c_cflag &= ~CBAUD;
	ktermios.c_cflag |= BOTHER;
	tty_termios_encode_baud_rate(&ktermios, baud_rate, baud_rate);
	tty_set_termios(tty, &ktermios);
	edp_info("set baud_rate=%d, except=%d\n",
		(int)tty_termios_baud_rate(&tty->termios), (int)baud_rate);
}

static int tcon_uart_open(const char *uart_port, long baud, dev_t *dev_no)
{
	int ret = TCON_UART_OK;

	if (!uart_port || !dev_no) {
		edp_err("uart_port/dev_no is null\n");
		return TCON_UART_FAIL;
	}

	/* open tty */
	g_tcon_uart = tty_kopen(*dev_no);
	if (IS_ERR_OR_NULL(g_tcon_uart) ||
		IS_ERR_OR_NULL(g_tcon_uart->ops) ||
		IS_ERR_OR_NULL(g_tcon_uart->ops->open)) {
		edp_err("open tty %s failed\n", uart_port);
		goto TCOU_UART_KOPEN_ERROR;
	}

	ret = g_tcon_uart->ops->open(g_tcon_uart, NULL);
	if (ret) {
		edp_err("g_tcon_uart->ops->open error\n");
		tty_unlock(g_tcon_uart);
		goto TCOU_UART_OPEN_ERROR;
	}

	tcon_uart_set_termios(g_tcon_uart, baud);
	tty_unlock(g_tcon_uart);

	ret = tty_set_ldisc(g_tcon_uart, TCON_UART);
	if (ret) {
		edp_err("tty_set_ldisc error\n");
		goto TCOU_UART_LDISC_ERROR;
	}
	g_uart_controll.open_flag = TCON_UART_OPEN;

	return TCON_UART_OK;
TCOU_UART_LDISC_ERROR:
	g_tcon_uart->ops->close(g_tcon_uart, NULL);
TCOU_UART_OPEN_ERROR:
	tty_kclose(g_tcon_uart);
TCOU_UART_KOPEN_ERROR:
	tty_unregister_ldisc(TCON_UART);
	g_tcon_uart = NULL;
	return TCON_UART_FAIL;
}

static int tcon_uart_init(const char *uart_port, long baud)
{
	int ret = TCON_UART_OK;
	dev_t dev_no = 0;

	if (!uart_port) {
		edp_err("uart_port is null!\n");
		return TCON_UART_FAIL;
	}

	if (g_uart_controll.open_flag == TCON_UART_OPEN) {
		edp_err("init have done\n");
		return TCON_UART_OK;
	}

	ret = tty_register_ldisc(TCON_UART, &tcon_ldisc_ops);
	if (ret != 0) {
		edp_err("tty_register_ldisc error ret=%d\n", ret);
		return TCON_UART_FAIL;
	}

	ret = tty_dev_name_to_number(uart_port, &dev_no);
	if (ret != 0) {
		edp_err("dev to number tty:%s ret=%d\n", uart_port, ret);
		tty_unregister_ldisc(TCON_UART);
		return TCON_UART_FAIL;
	}

	ret = tcon_uart_open(uart_port, baud, &dev_no);
	if (ret < 0) {
		edp_err("open uart fail! tty:%s ret=%d\n", uart_port, ret);
		tty_unregister_ldisc(TCON_UART);
		return TCON_UART_FAIL;
	}

	edp_info("%s end\n", uart_port);

	return TCON_UART_OK;
}
 
int tcon_uart_write(const char *buf, size_t len)
{
	if (!buf || len > TCON_UART_SEND_MAX || !g_tcon_uart || !g_tcon_uart->ops) {
		edp_err("buf/len, g_tcon_uart/g_tcon_uart->ops err!\n");
		return TCON_UART_FAIL;
	}

	if (g_uart_controll.controll_init != TCON_UART_CTR_INIT) {
		edp_err("tcon uart not init!\n");
		return TCON_UART_FAIL;
	}

	spin_lock_bh(g_uart_lock);
	if (g_uart_controll.send_state == TCON_UART_SET_SEND ||
		g_uart_controll.recv_state == TCON_UART_SET_RECV) {
		spin_unlock_bh(g_uart_lock);
		edp_err("err recv or write state!\n");
		return TCON_UART_FAIL;
	}
	g_uart_controll.send_state = TCON_UART_SET_SEND;
	spin_unlock_bh(g_uart_lock);

	set_bit(TTY_DO_WRITE_WAKEUP, &g_tcon_uart->flags);
	g_tcon_uart->ops->write(g_tcon_uart, buf, len);
	if (!wait_for_completion_timeout(g_send_complete, msecs_to_jiffies(TCON_UART_WRITE_TIMEOUT))) {
		edp_err("tcon uart write time out error!\n");
		return -EIO;
	}

	return TCON_UART_OK;
}

static int tcon_uart_deinit(void)
{
	if (g_uart_controll.open_flag != TCON_UART_OPEN)
		return TCON_UART_OK;

	if (!g_tcon_uart)
		return TCON_UART_FAIL;

	if (g_fp) {
		filp_close(g_fp, 0);
		g_fp = NULL;
	}

	tty_ldisc_release(g_tcon_uart);
	g_tcon_uart->ops->close(g_tcon_uart, NULL);
	tty_kclose(g_tcon_uart);
	tty_unregister_ldisc(TCON_UART);
	g_tcon_uart = NULL;

	spin_lock_bh(g_uart_lock);
	g_uart_controll.open_flag = TCON_UART_CLOSE;
	spin_unlock_bh(g_uart_lock);

	return TCON_UART_OK;
}

static void tcon_uart_recv_process(struct work_struct *work)
{
	tcon_log_pri("%s\n", g_recv_tcon_buf);

	spin_lock_bh(g_uart_lock);
	if (memset_s(g_recv_tcon_buf, TCON_UART_BUFF_LEN, 0, TCON_UART_BUFF_LEN) != EOK)
		edp_err("memset g_recv_tcon_buf error!\n");
	spin_unlock_bh(g_uart_lock);
}

int tcon_uart_register(struct tcon_uart *uart)
{
	edp_info("tcon_uart_register enter\n");
	g_uart = uart;
	if (!g_uart || !g_uart->tty_name) {
		edp_err("uart or g_uart->tty_name is null\n");
		return TCON_UART_FAIL;
	}

	if (g_uart_controll.controll_init == TCON_UART_CTR_NO_INIT) {
		spin_lock_init(g_uart_lock);
		init_completion(g_send_complete);
		INIT_DELAYED_WORK(&(g_uart->recv_work), tcon_uart_recv_process);
		g_uart_controll.controll_init = TCON_UART_CTR_INIT;
	}

	if (tcon_uart_init(g_uart->tty_name, g_uart->default_baud) < 0) {
		edp_err("uart init err!\n");
		return TCON_UART_FAIL;
	}
	return TCON_UART_OK;
}
