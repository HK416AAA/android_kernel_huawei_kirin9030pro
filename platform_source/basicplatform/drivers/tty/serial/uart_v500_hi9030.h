/*
 * Console Driver for UART serial ports
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __UART_V500_HI9030_H_
#define __UART_V500_HI9030_H_
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/init.h>
#include <linux/console.h>
#include <linux/sysrq.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/serial_core.h>
#include <linux/device.h>
#include <linux/clk.h>
#include <linux/slab.h>
#include <linux/serial.h>
#include <linux/scatterlist.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/types.h>
#include <linux/of_device.h>
#include <linux/pinctrl/consumer.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/sizes.h>
#include <linux/io.h>
#include <linux/kfifo.h>
#include <linux/kthread.h>
#include <linux/of_address.h>
#include <linux/version.h>
#include <linux/cpumask.h>
#include <linux/acpi.h>
#include <securec.h>
#include <platform_include/basicplatform/linux/pr_log.h>
#include <linux/debugfs.h>
#include "uart_v500_reg.h"
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>

#define PR_LOG_TAG                        "hi9030_uart"
#define HI9030_UART_DEVICENAME            "ttyIOD"
#define UART_SERIAL_MAJOR                 205
#define MINOR_START                       64
#define MAX_UART_IDX                      15
#define UART_RESET_WAIT_TIME              10
#define UAP_REG_CFG_NUM                   4
#define A53_CLUSTER0_CPU1                 1
#define TXFF_TIMEOUT                      100000
#define UART_CONFIG_BIT_MASK              16
#define FIFO_SIZE_UART_V500               64
#define PERI_CRG_BUS_CLK_SEL     0xC2C
#define IODIE_UART1_CLK_SEL      0x180010
#define IODIE_UART2_CLK_SEL      0x600040

#define IODIE_DMA_RST_OFFSET     0xc20
#define IODIE_DMA_RST_DIS        0x3
#define DMA_MEM_SHUTDOWN_OFFSET  0xc68
#define DMA_MEM_SHUTDOWN_VAL     0xF7F
#define IODIE_UART1_RX_BUFFER_A  0xfdf32000
#define IODIE_UART1_RX_BUFFER_B  0xfdf33000
#define IODIE_UART2_RX_BUFFER_A  0xfdf36000
#define IODIE_UART2_RX_BUFFER_B  0xfdf37000
#define IODIE_UART_BUFFER_SIZE   0x1000
#define IODIE_UART1_TX_BUFFER    0xfdf31000
#define IODIE_UART2_TX_BUFFER    0xfdf35000
#define IODIE_DMA_INT_TC1_MASK   0x18
#define IODIE_DMA_INT_ERR1_MASK  0x20
#define IODIE_DMA_INT_ERR2_MASK  0x24
#define IODIE_DMA_MASK_VAL       0x3f

#define UART_V500_DR_OE                   (1 << 11)
#define UART_V500_DR_BE                   (1 << 10)
#define UART_V500_DR_PE                   (1 << 9)
#define UART_V500_DR_FE                   (1 << 8)
#define UART_DUMMY_DR_RX                  (1 << 16)
#define UART_TX_WORDS                     0xFF
#define FIFO_MAX_COUNT                    7
#define TIMEOUT_IRQ_MAX_CNT               5

#define UART_V500_DR_ERROR                (UART_V500_DR_OE | UART_V500_DR_BE | \
	UART_V500_DR_PE | UART_V500_DR_FE)

#define UART_V500_INT_STAUS               (UART_V500_INT_OES | \
	UART_V500_INT_BES | UART_V500_INT_PES | UART_V500_INT_FES | \
	UART_V500_INT_RTS | UART_V500_INT_RXS)

#define UART_V500_INT_MASK                (UART_V500_INT_RXM | \
	UART_V500_INT_RTM | UART_V500_INT_FEM | UART_V500_INT_PEM | \
	UART_V500_INT_BEM | UART_V500_INT_OEM)

#define UART_EN        (1 << 0)
#define UART_TX_EN     (1 << 1)
#define UART_RX_EN     (1 << 2)
#define UART_CTS_EN    (1 << 3)
#define UART_RTS_EN    (1 << 4)
#define UART_TX_DMA_EN (1 << 5)
#define UART_RX_DMA_EN (1 << 6)
#define UART_LOOP_EN   (1 << 9)
#define UART_FIFO_EN   (1 << 10)


#define DEFULT_CONFIG_MASK  (UART_EN | UART_TX_EN | UART_RX_EN | \
	UART_CTS_EN | UART_RTS_EN | UART_TX_DMA_EN | UART_RX_DMA_EN | \
	UART_FIFO_EN)

struct hi9030_uart_dma_data {
	bool (*dma_filter)(struct dma_chan *chan, void *filter_param);
	void *dma_rx_param;
	void *dma_tx_param;
	void (*init)(void);
	void (*exit)(void);
};

struct vendor_data {
	const unsigned int *reg_offset;
	unsigned int fifo_cfg;
	unsigned int stat_busy;
	unsigned int stat_cts;
	bool access_32b;
};

static struct uart_driver g_hi9030_uart_v500 = {
	.owner = THIS_MODULE,
	.driver_name = "hi9030_uart_serial",
	.dev_name = HI9030_UART_DEVICENAME,
	.major = UART_SERIAL_MAJOR,
	.minor = MINOR_START,
	.nr = MAX_UART_IDX,
	.cons = NULL,
};

struct hi9030_uart_rx_sgbuf {
	struct scatterlist sg;
	char *buf;
	bool use_buf_b;
};

struct hi9030_dmarx_data {
	struct dma_chan *chan;
	struct completion complete;
	bool use_buf_b;
	char *buffer_a;
	char *buffer_b;
	unsigned int length;
	dma_cookie_t dma_cookie;
	bool running;
};

struct hi9030_dmatx_data {
	struct dma_chan *chan;
	char *buffer;
	unsigned int length;
	bool queued;
};

struct hi9030_uart_port {
	struct uart_port port;
	const unsigned int *reg_offset;
	struct clk *clk;
	unsigned int uart_num;
	unsigned int uart_user;
	/* Two optional pin states - default & sleep */
	struct pinctrl *pinctrl;
	struct pinctrl_state *pinctrls_default;
	struct pinctrl_state *pinctrls_idle;
	const struct vendor_data *vendor;
	struct hi9030_uart_rx_sgbuf *rx_sg;
	unsigned int int_msk; /* interrupt mask */
	unsigned int old_status;
	unsigned int dma_conctrl; /* dma control reg */
	unsigned int bind_interrupt_flag;
	unsigned int fifosize; /* vendor-specific */
	unsigned int old_config;
	bool auto_rts;
	char uart_type[12]; /* uart_type name less than 12 */
	unsigned int enable_dma;
	bool rx_sg_buf_alloced;
#ifdef CONFIG_DMA_ENGINE
	/* DMA stuff */
	bool using_9030_tx_dma;
	struct hi9030_dmarx_data dmarx;
	bool using_9030_rx_dma;
	struct hi9030_dmatx_data dmatx;
	bool is_dma_probed;
#endif
	bool reset_val;
	unsigned int reset_bit;
	unsigned int reset_enable;
	unsigned int reset_disable;
	unsigned int reset_status;
	unsigned int rx_use_global_sg_buf;
	bool rx_global_sg_buf_alloced;
	bool uart_rx_dma_disabled;
	unsigned int timeout_irq_cnt;
	unsigned int uart_cfg_mask;
};

static struct vendor_data g_vendor_hi9030_uart = {
	.reg_offset = g_uart_v500_std_offsets,
	.fifo_cfg = UART_V500_FIFO_RX_1_8 | UART_V500_FIFO_TX_1_2 |
		UART_V500_FIFO_RTS_7_8,
	.stat_busy = UART_V500_STAT_TX_BUSY,
	.stat_cts = UART_V500_STAT_CTS,
	.access_32b = true,
};

#endif
