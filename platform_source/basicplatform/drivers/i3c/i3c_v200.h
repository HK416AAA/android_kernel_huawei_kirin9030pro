/*
 * I3C-V200 Head File.
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
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

#ifndef I3C_V200_H
#define I3C_V200_H

#include <linux/bitops.h>
#include <linux/clk.h>
#include <linux/completion.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/i3c/master.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/iopoll.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/pinctrl/consumer.h>
#include <linux/overflow.h>
#include <linux/workqueue.h>
#include <securec.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>

#define I3C_V200_FRAME_CTRL1        0x0
#define I3C_V200_IBI_CTRL           BIT(5)
#define I3C_V200_HOT_JOIN_CTRL      BIT(4)
#define I3C_V200_I2C_SLAVE_PRESENT  BIT(3)
#define I3C_V200_IBA_INCLUDE        BIT(2)
#define I3C_V200_SW_INIT            BIT(0)

#define I3C_V200_TRANSFER_CMD1      0x4
#define I3C_V200_CMD_TOC           BIT(27)
#define I3C_V200_CMD_RNW           BIT(26)
#define I3C_V200_CMD_SDAP          BIT(25)
#define i3c_v200_cmd_dev_index(x)  (((x) << 16) & GENMASK(19, 16))
#define I3C_V200_CMD_CP            BIT(15)
#define i3c_v200_cmd_cmd(x)        (((x) << 7) & GENMASK(14, 7))
#define i3c_v200_cmd_tid(x)        (((x) << 3) & GENMASK(6, 3))
#define I3C_V200_TRANSFER_CMD       0x0

#define I3C_V200_TRANSFER_CMD2      0x8
#define i3c_v200_data_len(x)        (((x) << 12) & GENMASK(31, 12))
#define I3C_V200_DMA_EN             BIT(11)
#define I3C_V200_TRANS_ARG          0x1

#define I3C_V200_TRANSFER_CMD3      0xc
#define i3c_v200_byte_strb(x)       (GENMASK(2 + ((x) - 1), 2) & GENMASK(4, 2))
#define i3c_v200_short_data1(x)     (((x) << 8) & GENMASK(15, 8))
#define i3c_v200_short_data2(x)     (((x) << 16) & GENMASK(23, 16))
#define i3c_v200_short_data3(x)     (((x) << 24) & GENMASK(31, 24))
#define I3C_V200_SHORT_ARG          0x2

#define I3C_V200_TRANSFER_CMD4      0x10
#define I3C_V200_AAC_TOC            BIT(27)
#define i3c_v200_aac_dev_count(x)   (((x) << 20) & GENMASK(23, 20))
#define i3c_v200_aac_dev_index(x)   (((x) << 16) & GENMASK(19, 16))
#define i3c_v200_aac_cmd(x)         (((x) << 7) & GENMASK(14, 7))
#define i3c_v200_aac_tid(x)         (((x) << 3) & GENMASK(6, 3))
#define I3C_V200_AAC_ARG            0x3

#define I3C_V200_TX_DATA_PORT       0x14
#define I3C_V200_RX_DATA_PORT       0x18

#define I3C_V200_FIFO_CTRL          0x1C
#define i3c_v200_tx_fifo_ae(x)      (((x) << 24) & GENMASK(27, 24))
#define i3c_v200_rx_fifo_af(x)      (((x) << 20) & GENMASK(23, 20))
#define i3c_v200_cmd_fifo_ae(x)     (((x) << 14) & GENMASK(15, 14))
#define I3C_V200_TX_FIFO_CLEAR      BIT(13)
#define I3C_V200_RX_FIFO_CLEAR      BIT(12)
#define I3C_V200_CX_FIFO_CLEAR      BIT(11)
#define I3C_V200_FIFO_CLEAR (I3C_V200_TX_FIFO_CLEAR | I3C_V200_RX_FIFO_CLEAR | \
	I3C_V200_CX_FIFO_CLEAR)

#define I3C_V200_DEVICE_TABLE              0x24
#define I3C_DEVICE_TABLE_I2C              BIT(31)
#define i3c_device_table_nack_cnt(x)      (((x) << 29) & GENMASK(30, 29))
#define i3c_device_table_dynamic_add(x)   (((x) << 16) & GENMASK(23, 16))
#define i3c_device_table_static_add(x)    ((x) & GENMASK(6, 0))

#define I3C_V200_RESP_STATE                0x5C
#define i3c_v200_resp_error(x)             ((x) & GENMASK(2, 0))
#define I3C_V200_RESP_NO_ERROR             0
#define I3C_V200_RESP_BROADCAST_ERROR      1
#define I3C_V200_RESP_SLAVE_NACK           2
#define I3C_V200_RESP_I2C_WRITE_NACK       3
#define I3C_V200_RESP_ENTDAA_NACK          4
#define I3C_V200_RESP_SLAVE_ADDR_START     8
#define SLAVE_ADDR_MASK                    0x7F

#define I3C_V200_TRANS_STATE     0x60

#define I3C_V200_INT_STATE       0x68
#define i3c_v200_int_status(x)   ((x) & GENMASK(4, 0))
#define I3C_V200_INT_TRANS_ERR   BIT(0)
#define I3C_V200_INT_RESP        BIT(1)
#define I3C_V200_INT_IBI         BIT(2)
#define I3C_V200_SLAVE_READ_STOP BIT(3)
#define I3C_V200_INT_FIFO_ERROR  BIT(4)

#define I3C_V200_INT_CLEAR       0x6C

#define I3C_V200_INT_MASK	 0x70
#define I3C_V200_INTR_ALL	 0x1B

#define I3C_V200_CLK_I2C        0x88
#define I3C_V200_CLK_OD         0x90
#define I3C_V200_CLK_PP_LCNT    0x9C
#define I3C_V200_CLK_PP_HCNT    0x100

#define I3C_V200_CMD_FIFO_NUM   2
#define I3C_V200_DATA_FIFO_DEP  64
#define I3C_V200_MAX_DEVS       11
#define I3C_RESET_REG_CNT       4
#define I3C_WAIT_RESET_STATUS_TIMES 10

#define I3C_SLAVE_ADDR_BITS     7
#define MAX_ADDR_NUM            32

#define I3C_SCL_FREQ_1M                 1000
#define I3C_I2C_FMP_THIGH_MIN_NS        260
#define I3C_I2C_FMP_TLOW_MIN_NS         500

#define I3C_SCL_FREQ_400K               400
#define I3C_I2C_FM_THIGH_MIN_NS         600
#define I3C_I2C_FM_TLOW_MIN_NS          1300

#define I3C_PP_THIGH_MIN_NS             32
#define I3C_PP_TLOW_MIN_NS              32
#define I3C_PP_HCNT_START_BIT           8

#define I3C_MAX_OD_HCNT         0x3F
#define I3C_MAX_OD_LCNT         0xFFFF
#define I3C_OD_HCNT_START_BIT   10
#define I3C_OD_LCNT_START_BIT   16

#define I3C_I2C_MAX_HCNT        0xFF
#define I3C_I2C_MAX_LCNT        0x3FF
#define I3C_I2C_LCNT_START_BIT  9

#define I3C_TRANSFER_MODE_IRQ   0
#define I3C_TRANSFER_MODE_DMA   1

#define I3C_TIMEOUT (msecs_to_jiffies(1000))

struct i3c_v200_cmd {
	u32 cmd_lo;
	u32 cmd_hi;
	u16 tx_len;
	const void *tx_buf;
	u16 rx_len;
	void *rx_buf;
	u8 error;
};

struct i3c_v200_xfer {
	struct list_head node;
	struct completion comp;
	int ret;
	unsigned int ncmds;
	struct i3c_v200_cmd cmds[0];
};

struct i3c_v200_reset {
	u32 rst_enable;
	u32 rst_disable;
	u32 rst_status;
	u32 rst_bit;
};

struct i3c_v200_dma_data {
	struct dma_chan *chan;
	struct scatterlist sg;
	u8 *buf;
};

struct i3c_v200_master {
	struct i3c_master_controller controller;
	u32 maxdevs;
	u32 free_pos;
	struct {
		struct list_head list;
		struct i3c_v200_xfer *cur;
		spinlock_t lock;
	} xferqueue;
	void __iomem *regs;
	struct clk *core_clk;
	char version[5];
	char type[5];
	u8 addrs[MAX_ADDR_NUM];
	struct pinctrl  *pinctrl;
	int  pinctrl_flag;
	struct mutex lock;
	int i3c_resume_init;
	u64 clk_rate;
	u32 trans_mode;
	u32 slave_addr[I3C_V200_MAX_DEVS];
	int irq;
	u32 i2c_scl_hz;
	void __iomem  *reset_reg_base;
	struct i3c_v200_reset  priv;
#ifdef CONFIG_DMA_ENGINE
	/* DMA stuff */
	resource_size_t mapbase;
	bool using_tx_dma;
	bool using_rx_dma;
	struct i3c_v200_dma_data dmarx;
	struct i3c_v200_dma_data dmatx;
#endif
};

struct i3c_v200_i2c_dev_data {
	u8 index;
};

void i3c_reset_controller(struct i3c_v200_master *master);
void i3c_v200_enqueue_xfer(struct i3c_v200_master *master,
	struct i3c_v200_xfer *xfer);
void i3c_v200_master_dequeue_xfer(struct i3c_v200_master *master,
	struct i3c_v200_xfer *xfer);
struct i3c_v200_xfer *i3c_v200_alloc_xfer(struct i3c_v200_master *master,
	unsigned int ncmds);

void i3c_v200_dma_start_xfer(struct i3c_v200_master *master);
void i3c_v200_dma_probe_initcall(struct i3c_v200_master *master);
void i3c_v200_dma_remove(struct i3c_v200_master *master);
int i3c_v200_i2c_dma_transfer(struct i3c_v200_master *master,
	const struct i2c_msg *i2c_xfers, int xfer_num,
	struct i3c_v200_i2c_dev_data *data);
#endif