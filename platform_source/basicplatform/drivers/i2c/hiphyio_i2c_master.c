/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 *
 * I2C Master adapter driver (master only).
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

#include <linux/delay.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/i2c.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/pm.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <platform_include/see/ffa/ffa_plat_drv.h>
#include <platform_include/see/ffa/ffa_msg_id.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_def.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
#include "hiphyio_i2c_master.h"

static struct hiphyio_i2c_status hiphyio_status;

static char *error_sources[] = {
	[ERROR_7B_ADDR_NOACK] =
		"slave address not acknowledged (7bit mode)",
	[ERROR_10ADDR1_NOACK] =
		"first address byte not acknowledged (10bit mode)",
	[ERROR_10ADDR2_NOACK] =
		"second address byte not acknowledged (10bit mode)",
	[ERROR_TXDATA_NOACK] =
		"data not acknowledged",
	[ERROR_GCALL_NOACK] =
		"no acknowledgement for a general call",
	[ERROR_GCALL_READ] =
		"read after general call",
	[ERROR_HS_ACKDET] =
	"the high-speed master code was achnowledged",
	[ERROR_SBYTE_ACKDET] =
		"start byte acknowledged",
	[ERROR_HS_NORSTRT] =
	"the restart is disabled and the user is trying to use the master to transfer data in high-speed mode",
	[ERROR_SBYTE_NORSTRT] =
		"trying to send start byte when restart is disabled",
};

static u32 hiphyio_i2c_readl(struct hiphyio_i2c_dev *d, u32 offset)
{
	u32 value;

	value = iodie_readl(d->i2c_hiphyio_module, offset);

	return value;
}

static void hiphyio_i2c_writel(struct hiphyio_i2c_dev *d, u32 val, u32 offset)
{
	iodie_writel(d->i2c_hiphyio_module, offset, val);
}

static u32 hiphyio_i2c_ffa_send_msg(struct hiphyio_i2c_dev *d, u32 mode, bool command)
{
    struct ffa_send_direct_data args = {0};

    args.data0 = IODIE_HIPHYIO_I2C_FID;
    args.data1 = mode;
    args.data2 = d->i2c_hiphyio_module;
    args.data3 = command;

    return ffa_platdrv_send_msg(&args);
}

static void hiphyio_i2c_reset_controller(struct hiphyio_i2c_dev *d)
{
	struct hiphyio_i2c_priv_data *priv = NULL;
	u32 val = 0, ret = 0;
	int timeout = I2C_TIMEOUT_DEFAULT_VAL;

	if (!d) {
		pr_err("%s:i2c ctrler doesn't be init\n", __func__);
		return;
	}

	priv = &d->priv;

    if (d->i2c_security) {
        ret = hiphyio_i2c_ffa_send_msg(d, HIPHYIO_IOMCU_I2C_RESET_HANDLE, ENABLE);
        if (ret != 0)
            dev_err(d->dev, "%s i2c reset enable failed, ret:%d!\n", __func__, ret);

        ret = hiphyio_i2c_ffa_send_msg(d, HIPHYIO_IOMCU_I2C_RESET_HANDLE, DISABLE);
        if (ret != 0)
            dev_err(d->dev, "%s i2c reset disable failed, ret:%d!\n", __func__, ret);

		return;
    }

	iodie_writel(IODIE_IP_PERI_CRG, priv->reset_enable_off, BIT(priv->reset_bit));
	do {
		val = iodie_readl(IODIE_IP_PERI_CRG, priv->reset_status_off);
		val &= BIT(priv->reset_bit);
		udelay(1);
	} while (!val && timeout--);

	if (timeout <= 0) {
		dev_err(d->dev, "%s:i2c reset enable timeout\n", __func__);
		return;
	}

	timeout = I2C_TIMEOUT_DEFAULT_VAL;

	iodie_writel(IODIE_IP_PERI_CRG, priv->reset_disable_off, BIT(priv->reset_bit));
	do {
		val = iodie_readl(IODIE_IP_PERI_CRG, priv->reset_status_off);
		val &= BIT(priv->reset_bit);
		udelay(1);
	} while (val && timeout--);

	if (timeout <= 0) {
		dev_err(d->dev, "%s:i2c reset disable timeout\n", __func__);
		return;
	}
}

static void hiphyio_i2c_fifo_clear(struct hiphyio_i2c_dev *d)
{
	u32 fifo_ctrl = 0;

	fifo_ctrl = hiphyio_i2c_readl(d, FIFO_CTRL);
	fifo_ctrl |= FIFO_CLEAR;
	hiphyio_i2c_writel(d, fifo_ctrl, FIFO_CTRL);
	fifo_ctrl = fifo_ctrl & (~FIFO_CLEAR);
	hiphyio_i2c_writel(d, fifo_ctrl, FIFO_CTRL);
}

static void hiphyio_i2c_speed_config(struct hiphyio_i2c_dev *d)
{
	u32 hcnt, lcnt;
	u32 speed_mode;
	u32 min_cnt;
	u32 input_clock_khz;

	/* set i2c speed */
	speed_mode = d->master_cfg & I2C_SPEED_MASK;
	input_clock_khz = d->clk_rate / I2C_MUL_1K;

	/* minimum value of hcnt, commonly used to SS/FS/HS */
	min_cnt = I2C_SPK_CNT + I2C_HCNT_RESERVED;

	/* standard-mode */
	hcnt = ((input_clock_khz / I2C_SPEED_STANDARD) * I2C_SS_FREQ_DIV_H) / I2C_MUL_1K \
	- I2C_SCL_FALL_TIME * input_clock_khz * I2C_MUL_1K;
	lcnt = (input_clock_khz / I2C_SPEED_STANDARD) - hcnt \
		- I2C_SCL_RISE_TIME * input_clock_khz * I2C_MUL_1K;
	hcnt = (hcnt > min_cnt) ? (hcnt - min_cnt) : 1;
	hiphyio_i2c_writel(d, hcnt, SS_SCL_HCNT);
	hiphyio_i2c_writel(d, lcnt, SS_SCL_LCNT);

	/* fast-mode */
	hcnt = ((input_clock_khz / I2C_SPEED_FAST) * I2C_FS_FREQ_DIV_H) / I2C_MUL_1K \
		- I2C_SCL_FALL_TIME * input_clock_khz * I2C_MUL_1K;
	lcnt = (input_clock_khz/ I2C_SPEED_FAST) - hcnt \
		- I2C_SCL_RISE_TIME * input_clock_khz * I2C_MUL_1K;
	hcnt = (hcnt > min_cnt) ? (hcnt - min_cnt) : 1;
	hiphyio_i2c_writel(d, hcnt, FS_SCL_HCNT);
	hiphyio_i2c_writel(d, lcnt, FS_SCL_LCNT);

	/* fast-plus-mode */
	hcnt = ((input_clock_khz / I2C_SPEED_FAST_PLUS) * I2C_FSP_FREQ_DIV_H) / I2C_MUL_1K \
		- I2C_SCL_FALL_TIME * input_clock_khz * I2C_MUL_1K;
	lcnt = (input_clock_khz / I2C_SPEED_FAST_PLUS) - hcnt \
		- I2C_SCL_RISE_TIME * input_clock_khz * I2C_MUL_1K;
	hcnt = (hcnt > min_cnt) ? (hcnt - min_cnt) : 1;
	hiphyio_i2c_writel(d, hcnt, HS_SCL_HCNT);
	hiphyio_i2c_writel(d, lcnt, HS_SCL_LCNT);
};

static int hiphyio_i2c_clk_cfg(struct hiphyio_i2c_dev *d, bool command)
{
    u32 ret;
	struct hiphyio_i2c_priv_data *priv = NULL;

    if (!d) {
		pr_err("%s:i2c ctrler doesn't be init\n", __func__);
		return -1;
	}
    
    if (command) {
        if (d->i2c_security) {
            ret = hiphyio_i2c_ffa_send_msg(d, HIPHYIO_IOMCU_I2C_CLK_HANDLE, command);
            if (ret != 0) {
                dev_err(d->dev, "%s failed to send_msg, ret:%d!\n", __func__, ret);
                return -1;
            }
        } else {
            iodie_clk_en(d->i2c_hiphyio_module);
        }
    } else {
        if (d->i2c_security) {
            ret = hiphyio_i2c_ffa_send_msg(d, HIPHYIO_IOMCU_I2C_CLK_HANDLE, command);
            if (ret != 0) {
                dev_err(d->dev, "%s failed to send_msg, ret:%d!\n", __func__, ret);
                return -1;
            }
        } else {
            iodie_clk_dis(d->i2c_hiphyio_module);
        }
    }
	return 0;
}

/**
 * hiphyio_i2c_init_master() - Initialize the I2C master hardware
 * @d: device private data
 *
 * This functions configures and enables the I2C master.
 * This function is called during I2C init function, and in case of timeout at
 * run time.
 */
static void hiphyio_i2c_init_master(struct hiphyio_i2c_dev *d)
{
	hiphyio_i2c_speed_config(d);

	/* Configure SDA Hold Time */
	hiphyio_i2c_writel(d, d->hold_time, SDA_HOLD);

	/* configure the i2c master */
	hiphyio_i2c_writel(d, d->master_cfg, FRAME_CTRL);

	hiphyio_i2c_fifo_clear(d);

	/* Configure FIFO */
	hiphyio_i2c_writel(d, FIFO_TX_THD | FIFO_RX_THD, FIFO_CTRL);
}

static void hiphyio_i2c_disable_int(struct hiphyio_i2c_dev *d)
{
	hiphyio_i2c_writel(d, 0, INT_MASK);
}

static void reset_i2c_controller(struct hiphyio_i2c_dev *d)
{
	spin_lock(&d->spinlock);
	hiphyio_i2c_reset_controller(d);
	hiphyio_i2c_init_master(d);
	hiphyio_i2c_disable_int(d);
	spin_unlock(&d->spinlock);
}

static int hiphyio_i2c_pin_select(struct hiphyio_i2c_dev *d, u32 command)
{
	int ret = 0;

    ret = hiphyio_i2c_ffa_send_msg(d, HIPHYIO_I2C_PIN_SELECT_HANDLE, command);
	if (ret != 0)
		dev_err(d->dev, "%s failed to send_msg, ret:%d!\n", __func__, ret);
	return ret;
}

static void i2c_scl_recover_bus(struct i2c_adapter *adap)
{
	struct hiphyio_i2c_dev *d = i2c_get_adapdata(adap);
	int ret = 0;

	if (!d) {
		pr_err("%s:i2c ctrler doesn't be init\n", __func__);
		return;
	}
	dev_info(d->dev, "bus prepares recovery ...\n");

	/* switch sda to gpio */
	ret = hiphyio_i2c_pin_select(d, HIPHYIO_PIN_GPIO_MODE);
	if (ret) {
		dev_err(d->dev, "i2c pins select error!\n");
		return;
	}

	udelay(10);
	/* config slave address to 0x7F */
	hiphyio_i2c_writel(d, I2C_TAR_RECOVERY_CFG, SLV_ADDR);

	/* recived data from bus */
	hiphyio_i2c_writel(d, I2C_RD_CFG, CMD_TXDATA);

	msleep(I2C_RECOVER_SLEEP_MS);

	/* switch sda to i2c */
	ret = hiphyio_i2c_pin_select(d, HIPHYIO_PIN_I2C_MODE);
	if (ret) {
		dev_err(d->dev, "i2c pins select error!\n");
		return;
	}

	hiphyio_i2c_init_master(d);

	dev_info(d->dev, "bus recovered completely!\n");
}

/*
 * Waiting for bus not busy
 */
static int hiphyio_i2c_wait_bus_not_busy(struct hiphyio_i2c_dev *d)
{
	int timeout = TIMEOUT;
	u32 stat;

	while (timeout > 0) {
		stat = hiphyio_i2c_readl(d, TRANS_STATE);
		if (!(stat & TRANS_STATE_MASK))
			return 0;
		timeout--;
		usleep_range(1000, 1100);
	}

	dev_err(d->dev, "timeout waiting for bus ready 0x%x\n", stat);

	reset_i2c_controller(d);

	return -ETIMEDOUT;
}

static void hiphyio_i2c_xfer_init(struct hiphyio_i2c_dev *d)
{
	struct i2c_msg *msgs = d->msgs;
	u32 ic_con;

	/* If the slave address is ten bit address, enable 10BITADDR */
	ic_con = hiphyio_i2c_readl(d, FRAME_CTRL);
	if (msgs[d->msg_write_idx].flags & I2C_M_TEN)
		ic_con |= I2C_CON_10BITADDR_MASTER;
	else
		ic_con &= ~I2C_CON_10BITADDR_MASTER;

	hiphyio_i2c_writel(d, ic_con, FRAME_CTRL);
	hiphyio_i2c_writel(d, msgs[d->msg_write_idx].addr, SLV_ADDR);

	/* Enforce disabled interrupts (due to HW issues) */
	hiphyio_i2c_disable_int(d);

	/* Clear and enable interrupts */
	hiphyio_i2c_writel(d, I2C_INT_CLEAR, INT_CLR);
	hiphyio_i2c_writel(d, I2C_INTR_DEFAULT_MASK, INT_MASK);
}

static int hiphyio_i2c_msg_check(struct hiphyio_i2c_dev *d, struct i2c_msg *msgs)
{
	u32 addr = msgs[d->msg_write_idx].addr;
	int ret = 0;
	/*
	 * If target address has changed, we need to
	 * reprogram the target address in the I2C
	 * adapter when we are done with this transfer.
	 */
	if (msgs[d->msg_write_idx].addr != addr) {
		dev_err(d->dev,
			"%s: invalid target address\n", __func__);
		d->msg_err = -EINVAL;
		return -EINVAL;
	}

	if (msgs[d->msg_write_idx].len == 0) {
		dev_err(d->dev,
			"%s: invalid message length\n", __func__);
		d->msg_err = -EINVAL;
		return -EINVAL;
	}

	return ret;
}

static void hiphyio_i2c_send(struct hiphyio_i2c_dev *d)
{
	struct i2c_msg *msgs = d->msgs;
	unsigned int tx_limit, rx_limit;
	u32 buf_len = d->tx_buf_len;
	u8 *buf = d->tx_buf;
	bool need_restart = false;
	int ret;
	u32 flags = msgs[d->msg_write_idx].flags;

	for (; d->msg_write_idx < d->msgs_num; d->msg_write_idx++) {
		ret = hiphyio_i2c_msg_check(d, msgs);
		if (ret)
			break;
		if ((d->status & STATUS_WRITE_IN_PROGRESS) == 0) {
			/* new i2c_msg */
			buf = msgs[d->msg_write_idx].buf;
			buf_len = msgs[d->msg_write_idx].len;

			/* If both IC_EMPTYFIFO_HOLD_MASTER_EN and
			* IC_RESTART_EN are set, we must manually
			* set restart bit between messages.
			*/
			if ((d->master_cfg & I2C_RESTART_EN) &&
					(d->msg_write_idx > 0))
				need_restart = true;
		}
		tx_limit = I2C_FIFO_TX_DEPTH;
		rx_limit = I2C_FIFO_RX_DEPTH;

		while (buf_len > 0 && tx_limit > 0 && rx_limit > 0) {
			u32 cmd = 0;
			u32 stat;

			stat = hiphyio_i2c_readl(d, FIFO_STATE);
			if (stat & (I2C_TX_FULL | I2C_RX_FULL))
				break;
			/*
			 * If IC_EMPTYFIFO_HOLD_MASTER_EN is set we must
			 * manually set the stop bit. However, it cannot be
			 * detected from the registers so we set it always
			 * when writing/reading the last byte.
			 */

			if (d->msg_write_idx == d->msgs_num - 1 &&
				buf_len == 1 && !(flags & I2C_M_RECV_LEN))
				cmd |= BIT(9);

			if (need_restart) {
				cmd |= BIT(10);
				need_restart = false;
			}

			if (msgs[d->msg_write_idx].flags & I2C_M_RD) {
				hiphyio_i2c_writel(d, cmd | I2C_READ_CMD, CMD_TXDATA);
				rx_limit--;
				d->rx_outstanding++;
			} else {
				hiphyio_i2c_writel(d, cmd | *buf++, CMD_TXDATA);
			}
			buf_len--;
			tx_limit--;
		}

		d->tx_buf = buf;
		d->tx_buf_len = buf_len;

		if ((buf_len > 0) || (flags & I2C_M_RECV_LEN)) {
			/* more bytes to be written */
			d->status |= STATUS_WRITE_IN_PROGRESS;
			break;
		} else {
			d->status &= ~STATUS_WRITE_IN_PROGRESS;
		}
	}
}
/*
 * Initiate (and continue) low level master read/write transaction.
 * This function is only called from hiphyio_i2c_isr, and pumping i2c_msg
 * messages into the tx buffer.  Even if the size of i2c_msg data is
 * longer than the size of the tx buffer, it handles everything.
 */
static void hiphyio_i2c_xfer_msg(struct hiphyio_i2c_dev *d)
{
	u32 intr_mask;

	if (d->cmd_err == (unsigned int)I2C_INT_TRERR)
		return;

	intr_mask = I2C_INTR_MASTER_MASK;

	hiphyio_i2c_send(d);
	/*
	 * If i2c_msg index search is completed, we don't need TX_EMPTY
	 * interrupt any more.
	 */
	if (d->msg_write_idx == d->msgs_num)
		intr_mask &= ~I2C_INT_TX_AEMPTY;

	if (d->msg_err)
		intr_mask = 0;

	hiphyio_i2c_writel(d, intr_mask, INT_MASK);
}

static u8 hiphyio_i2c_recv_len(struct hiphyio_i2c_dev *d, u8 len)
{
	struct i2c_msg *msgs = d->msgs;
	u32 flags = msgs[d->msg_read_idx].flags;

	/*
	 * Adjust the buffer length and mask the flag
	 * after receiving the first byte.
	 */
	len += (flags & I2C_CLIENT_PEC) ? 2 : 1;
	d->tx_buf_len = len - min_t(u8, len, d->rx_outstanding);
	msgs[d->msg_read_idx].len = len;
	msgs[d->msg_read_idx].flags &= ~I2C_M_RECV_LEN;

	return len;
}

static void hiphyio_i2c_recv(struct hiphyio_i2c_dev *d)
{
	struct i2c_msg *msgs = d->msgs;
	u32 stat;

	if (d->cmd_err == (unsigned int)I2C_INT_TRERR)
		return;

	for (; d->msg_read_idx < d->msgs_num; d->msg_read_idx++) {
		u32 len, tmp;
		u8 *buf = NULL;

		if ((msgs[d->msg_read_idx].flags & I2C_M_RD) == 0)
			continue;

		if ((d->status & STATUS_READ_IN_PROGRESS) == 0) {
			len = msgs[d->msg_read_idx].len;
			buf = msgs[d->msg_read_idx].buf;
		} else {
			len = d->rx_buf_len;
			buf = d->rx_buf;
		}

		for (; len > 0; len--) {
			u32 flags = msgs[d->msg_read_idx].flags;

			stat = hiphyio_i2c_readl(d, FIFO_STATE);
			if (stat & I2C_RX_EMPTY)
				break;
			tmp = hiphyio_i2c_readl(d, RXDATA);
			*buf = tmp & 0xff;
			/* Ensure length byte is a valid value */
			if (flags & I2C_M_RECV_LEN)
				len = hiphyio_i2c_recv_len(d, *buf);
			buf++;
			d->rx_outstanding--;
		}

		if (len > 0) {
			d->status |= STATUS_READ_IN_PROGRESS;
			d->rx_buf_len = len;
			d->rx_buf = buf;
			return;
		} else {
			d->status &= ~STATUS_READ_IN_PROGRESS;
		}
	}
}

static int hiphyio_i2c_handle_transfer_error(struct hiphyio_i2c_dev *d)
{
	unsigned long error_source = d->error_source;
	unsigned int i;

	for_each_set_bit(i, &error_source, ARRAY_SIZE(error_sources))
		dev_err(d->dev, "%s: %s\n", __func__, error_sources[i]);

	if (error_source & (unsigned int)I2C_TRANS_ERROR_NOACK) {
		for_each_set_bit(i, &error_source, ARRAY_SIZE(error_sources))
			dev_dbg(d->dev,
				"%s: %s\n", __func__, error_sources[i]);
		return -EREMOTEIO;
	} else if (error_source & (unsigned int)I2C_TRANS_ERROR_GCALL_READ) {
		return -EINVAL; /* wrong msgs[] data */
	} else {
		return -EIO;
	}
}

static void hiphyio_i2c_bus_recovery(struct i2c_adapter *adap)
{
	struct hiphyio_i2c_dev *d = i2c_get_adapdata(adap);

	if (d->recover_bus)
		d->recover_bus(adap);
	else
		dev_err(d->dev, "no recovered routine\n");
}

static int hiphyio_i2c_prepare_xfer(struct hiphyio_i2c_dev *d,
	struct i2c_msg msgs[], int num)
{
	u32 pin_state, tmp;
	int ret;

	if (d->initd == 0)
		hiphyio_i2c_init_master(d);

	if (hiphyio_status.sys_status == IODIE_ST_ERR) {
		if (hiphyio_status.err_status == IODIE_ERR_IODIE) {
			hiphyio_status.is_iodie_err_iodie = true;
			pr_err("%s:iodie error i2c doesn't init\n", __func__);
			return -hiphyio_status.err_status;
		}

	  	if (hiphyio_status.err_status == IODIE_ERR_HIPHY) {
			pr_err("%s:hiphy error\n", __func__);
			return -hiphyio_status.err_status;
		}
	} else if (hiphyio_status.sys_status == IODIE_ST_INITED && hiphyio_status.err_status == IODIE_ERR_NO) {
		if (hiphyio_status.is_iodie_err_iodie) {
			hiphyio_i2c_init_master(d);
			hiphyio_status.is_iodie_err_iodie = false;
		}
		pr_err("%s:iodie recover, i2c does init\n", __func__);
	}

	ret = hiphyio_i2c_wait_bus_not_busy(d);
	if (ret)
		return ret;

	tmp = hiphyio_i2c_readl(d, TRANS_STATE);
	pin_state = tmp & PIN_STATE_MASK;
	if (pin_state != I2C_PIN_STATUS) {
		dev_err(d->dev,
			"pins status are not correct! state 0x%x\n", pin_state);
		goto err;
	}

	reinit_completion(&d->cmd_complete);
	d->msgs = msgs;
	d->msgs_num = num;
	d->cmd_err = 0;
	d->msg_write_idx = 0;
	d->msg_read_idx = 0;
	d->msg_err = 0;
	d->status = STATUS_IDLE;
	d->error_source = 0;
	d->rx_outstanding = 0;

	hiphyio_i2c_fifo_clear(d);

	return 0;

err:
	hiphyio_i2c_bus_recovery(&(d->adapter));

	return -EINVAL;
}

static int hiphyio_i2c_wait_for_completion(struct hiphyio_i2c_dev *d)
{
	int ret;
	u32 irq_state = 0;

	ret = wait_for_completion_timeout(&d->cmd_complete, WAIT_FOR_COMPLETION);
	if (ret == 0) {
		irq_state = hiphyio_i2c_readl(d, INT_MSTAT);
		dev_err(d->dev, "dev timed out, irq state 0x%x\n", irq_state);
		hiphyio_i2c_writel(d, 0, INT_MASK);
		reset_i2c_controller(d);
		ret = -ETIMEDOUT;
	}
	return ret;
}

static int hiphyio_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
	struct hiphyio_i2c_dev *d = i2c_get_adapdata(adap);
	int ret;
	u32 stat;

	if (!d) {
		pr_err("%s:i2c ctrler doesn't be init\n", __func__);
		return -ENODEV;
	}
	mutex_lock(&d->lock);

    if (!d->i2c_security) {
		if (iodie_normal_request(IODIE_USER_I2C, IODIE_RT_NORMAL_LOW)) {
            dev_err(d->dev, "hiphyio status err\n");
            mutex_unlock(&d->lock);
            return -ENODEV;
        }
    }

    ret = hiphyio_i2c_clk_cfg(d, ENABLE);
    if (ret) {
        dev_err(d->dev, "hiphyio i2c clk cfg err\n");
        mutex_unlock(&d->lock);
        return -ENODEV;
    }

	reset_i2c_controller(d);

	ret = hiphyio_i2c_prepare_xfer(d, msgs, num);
	if (ret) {
        if (!d->i2c_security)
            iodie_normal_release(IODIE_USER_I2C, IODIE_RT_NORMAL_LOW);
		mutex_unlock(&d->lock);
		return ret;
	}

	/* start the transfers */
	hiphyio_i2c_xfer_init(d);

	stat = hiphyio_i2c_readl(d, FIFO_STATE);
	if (stat & I2C_FIFO_TX_EMPTY)
		hiphyio_i2c_xfer_msg(d);

	/* wait for tx to complete */
	ret = hiphyio_i2c_wait_for_completion(d);
	if (-ETIMEDOUT == ret)
		goto done;

	if (d->msg_err) {
		ret = d->msg_err;
		goto done;
	}

	/* no error */
	if (likely(d->cmd_err == 0)) {
		stat = hiphyio_i2c_readl(d, INT_MSTAT);
		if ((d->status &
			(STATUS_READ_IN_PROGRESS | STATUS_WRITE_IN_PROGRESS)) ||
			(I2C_INT_TX_EMPTY == (stat & I2C_INT_TX_EMPTY))) {
			dev_err(d->dev,
				"write or read is not complete, status 0x%x,\n", d->status);
			ret = -EAGAIN;
		} else {
			ret = num;
			d->timeout_count = 0;
		}
		goto done;
	}

	/* We have an error */
	if (d->cmd_err == (unsigned int)I2C_INT_TRERR) {
		ret = hiphyio_i2c_handle_transfer_error(d);
		goto done;
	}
	ret = -EIO;

done:
	if (-ETIMEDOUT == ret) {
		hiphyio_i2c_bus_recovery(adap);
		ret = -EAGAIN;
	}

    hiphyio_i2c_clk_cfg(d, DISABLE);
    if (!d->i2c_security)
        iodie_normal_release(IODIE_USER_I2C, IODIE_RT_NORMAL_LOW);
	mutex_unlock(&d->lock);
	if (ret < 0)
		dev_err(d->dev, "error info %d, slave addr 0x%x.\n",
			ret, msgs[0].addr);

	return ret;
}

static u32 hiphyio_i2c_func(struct i2c_adapter *adap)
{
	struct hiphyio_i2c_dev *d = i2c_get_adapdata(adap);

	return d->functionality;
}

static struct i2c_algorithm hiphyio_i2c_algo = {
	.master_xfer = hiphyio_i2c_xfer,
	.functionality = hiphyio_i2c_func,
};

static int hiphyio_i2c_new_dev(struct hiphyio_i2c_dev **i2c_dev,
	struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct hiphyio_i2c_dev *d = NULL;
	struct resource *iores = NULL;
	u32 hold_time = 0;
	u64 clk_rate = 0;
	u32 hiphyio_module_num = 0;
	u32 i2c_security = 0;
	int ret;

	d = devm_kzalloc(dev, sizeof(struct hiphyio_i2c_dev), GFP_KERNEL);
	if (!d)
		return -ENOMEM;

	d->dev = get_device(dev);
	iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!iores) {
		pr_err("%s get resource fail\n", __func__);
		return -EINVAL;
	}
	d->mapbase = iores->start;
	ret = of_property_read_u64(dev->of_node, "clock-rate", &clk_rate);
	if (ret) {
		dev_info(dev, "doesn't have clock-rate property!\n");
		return -EINVAL;
	}
	dev_info(dev, "clock rate is %llu\n", clk_rate);
	if (clk_rate == 0)
		return -EINVAL;
	d->clk_rate = clk_rate;

	ret = of_property_read_u32(dev->of_node, "hold-time", &hold_time);
	if (ret)
		hold_time = I2C_DEFULT_HOLD_TIME;
	dev_info(dev, "%s hold_time=%u\n", __func__, hold_time);
	d->hold_time = hold_time;

	ret = of_property_read_u32(dev->of_node, "i2c-hiphyio-module-num", &hiphyio_module_num);
	if (ret) {
		dev_info(dev, "doesn't have irq-bit property!\n");
		return -EINVAL;
	}
	d->i2c_hiphyio_module = (enum iodie_module)hiphyio_module_num;

	of_property_read_u32(dev->of_node, "hiphyio-sensorhub-i2c", &i2c_security);
	dev_info(dev, "%s i2c_security=%u\n", __func__, i2c_security);
	d->i2c_security = i2c_security;

	*i2c_dev = d;
	return 0;
}

static int hiphyio_i2c_dev_reset_cfg(struct hiphyio_i2c_dev *d,
	struct device *dev)
{
	int ret;
	u32 data[I2C_RESET_REG_CNT] = {0};

	ret = of_property_read_u32_array(dev->of_node, "reset-controller-reg",
		&data[0], ARRAY_SIZE(data));
	if (ret) {
		dev_err(dev, "doesn't have reset-controller-reg property!\n");
		return ret;
	}

	/* data[0~2] is reset register address, data[3] is reset bit for i2c */
	d->priv.reset_enable_off = data[0];
	d->priv.reset_disable_off = data[1];
	d->priv.reset_status_off = data[2];
	d->priv.reset_bit = data[3];

	return ret;
}

static u32 hiphyio_i2c_read_clear_intrbits(struct hiphyio_i2c_dev *dev)
{
	u32 stat, dummy;

	stat = hiphyio_i2c_readl(dev, INT_MSTAT);
	if (stat & I2C_INT_TRCMP)
		hiphyio_i2c_writel(dev, I2C_INT_TRCMP, INT_CLR);
	if (stat & I2C_INT_FIFOERR)
		hiphyio_i2c_writel(dev, I2C_INT_FIFOERR, INT_CLR);
	if (stat & I2C_INT_RX_AFULL)
		hiphyio_i2c_writel(dev, I2C_INT_RX_AFULL, INT_CLR);
	if (stat & I2C_INT_TX_AEMPTY)
		hiphyio_i2c_writel(dev, I2C_INT_TX_AEMPTY, INT_CLR);
	if (stat & I2C_INT_TRERR) {
		dummy = hiphyio_i2c_readl(dev, TRANS_ERR);
		dev->error_source = dummy;
		hiphyio_i2c_writel(dev, I2C_INT_TRERR, INT_CLR);
	}

	return stat;
}

static int hiphyio_i2c_irq_handler_master(struct hiphyio_i2c_dev *dev)
{
	u32 stat;

	stat = hiphyio_i2c_read_clear_intrbits(dev);
	if (stat & I2C_INT_TRERR)
		dev->cmd_err |= I2C_INT_TRERR;

	if (stat & I2C_INT_RX_AFULL)
		hiphyio_i2c_recv(dev);

	if (stat & I2C_INT_TX_AEMPTY)
		hiphyio_i2c_xfer_msg(dev);

	if ((stat & I2C_INT_TRCMP)) {
			hiphyio_i2c_recv(dev);
		hiphyio_i2c_writel(dev, 0, INT_MASK);
		complete(&dev->cmd_complete);
	}

	return 0;
}

static irqreturn_t hiphyio_i2c_isr(int this_irq, void *dev_id)
{
	struct hiphyio_i2c_dev *d = dev_id;

	if (!d) {
		pr_err("%s: i2c contrller do not be init.\n", __func__);
		return IRQ_HANDLED;
	}
	spin_lock(&d->spinlock);
	hiphyio_i2c_irq_handler_master(d);
	spin_unlock(&d->spinlock);
	return IRQ_HANDLED;
}

static void hiphyio_i2c_fill_i2c_dev(struct hiphyio_i2c_dev *d, struct device *dev)
{
	int ret;
	u32 speed_mode = 0;

	ret = of_property_read_u32(dev->of_node, "speed-mode", &speed_mode);
	if (ret) {
		dev_info(dev, "no speed-mode property, use default!\n");
		speed_mode = I2C_SPEED_FS;
	} else {
		if ((speed_mode != I2C_SPEED_STD) && (speed_mode != I2C_SPEED_FS) &&
			(speed_mode != I2C_SPEED_HIGH))
			speed_mode = I2C_SPEED_FS;

		dev_info(dev, "speed mode is %d!\n", speed_mode);
	}

	d->functionality = I2C_DEFAULT_FUNCTIONALITY | I2C_FUNC_10BIT_ADDR;

	d->master_cfg = I2C_RESTART_EN | speed_mode;

	hiphyio_i2c_reset_controller(d);
}

static int hiphyio_i2c_init_adapter(struct i2c_adapter *adap,
	struct platform_device *pdev, struct hiphyio_i2c_dev *d)
{
	int ret;
	struct device *dev = &pdev->dev;
	int retries = 0;
	int timeout = 0;

	ret = of_property_read_s32(dev->of_node, "retries", &retries);
	if (ret) {
		dev_info(dev, "no retries ,use default!\n");
		retries = I2C_PROPER_RETRIES;
	}

	ret = of_property_read_s32(dev->of_node, "timeout", &timeout);
	if (ret) {
		dev_info(dev, "no timeout ,use default!\n");
		timeout = I2C_TIMEOUT_DEFAULT_VAL;
	}

	i2c_set_adapdata(adap, d);
	adap->owner = THIS_MODULE;
	adap->class = I2C_CLASS_HWMON;
	strlcpy(adap->name, "Hisilicon HIPHYIO I2C adapter", sizeof(adap->name));
	adap->algo = &hiphyio_i2c_algo;
	adap->dev.parent = dev;
	adap->dev.of_node = dev->of_node;

	adap->nr = pdev->id;
	adap->retries = retries;
	adap->timeout = timeout;
	dev_info(dev, "adap->retries = %d adap->timeout = %d\n ", adap->retries,
		adap->timeout);

	ret = i2c_add_numbered_adapter(adap);
	if (ret) {
		dev_err(dev, "failure adding adapter\n");
		return ret;
	}

	return 0;
}

static void hiphyio_i2c_callback_func(enum iodie_sys_status sys_status, enum iodie_err_status err_status)
{
	hiphyio_status.err_status = err_status;
	hiphyio_status.sys_status = sys_status;
}

static int hiphyio_i2c_get_status(void)
{
	int ret = 0;

	ret = iodie_notify_register(IODIE_USER_I2C, hiphyio_i2c_callback_func);
	if (ret) {
		pr_err("%s iodie notify register err\n", __func__);
		return -1;
	}

	return ret;
}

static int hiphyio_i2c_master_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct hiphyio_i2c_dev *d = NULL;
	int ret;

    if (iodie_normal_request(IODIE_USER_I2C, IODIE_RT_NORMAL_LOW)) {
		dev_err(dev, "hiphyio request normal-low err\n");
		return -ENODEV;
	}

	ret = hiphyio_i2c_get_status();
	if (ret < 0 )
		goto normal_request_err;

	if ((hiphyio_i2c_new_dev(&d, pdev) != 0) || !d) {
		pr_err("%s: new dev fail\n", __func__);
		goto normal_request_err;
	}

	hiphyio_i2c_dev_reset_cfg(d, dev);
	hiphyio_i2c_fill_i2c_dev(d, dev);
    d->recover_bus = i2c_scl_recover_bus;
    
	init_completion(&d->cmd_complete);
	mutex_init(&d->lock);
	spin_lock_init(&d->spinlock);

    ret = hiphyio_i2c_clk_cfg(d, ENABLE);
    if (ret) {
        dev_err(d->dev, "hiphyio i2c clk cfg err\n");
        goto normal_request_err;
    }

	hiphyio_i2c_init_master(d);
	hiphyio_i2c_disable_int(d);
	d->initd = 1;
	hiphyio_status.is_iodie_err_iodie = false;
	
	d->irq = platform_get_irq(pdev, 0);
	if (d->irq < 0) {
		dev_err(dev, "no irq resource\n");
		goto normal_request_err;
	}

	ret = devm_request_irq(
		dev, d->irq, hiphyio_i2c_isr, IRQF_TRIGGER_NONE, pdev->name, d);
	if (ret) {
		dev_err(dev, "failure requesting irq %d\n", d->irq);
		goto normal_request_err;
	}

	if (hiphyio_i2c_init_adapter(&d->adapter, pdev, d)) {
		dev_err(dev, "%s: init adapter fail\n", __func__);
		goto err;
	}

	platform_set_drvdata(pdev, d);
    iodie_normal_release(IODIE_USER_I2C, IODIE_RT_NORMAL_LOW);

	dev_info(dev, "hiphyio i2c probe succeed!\n");
	return 0;

err:
    hiphyio_i2c_clk_cfg(d, DISABLE);

	put_device(dev);

normal_request_err:
	iodie_normal_release(IODIE_USER_I2C, IODIE_RT_NORMAL_LOW);

	return -1;
}

static int hiphyio_i2c_master_remove(struct platform_device *pdev)
{
	struct hiphyio_i2c_dev *d = platform_get_drvdata(pdev);

	if (!d) {
		pr_err("%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}

    hiphyio_i2c_clk_cfg(d, DISABLE);
	
	platform_set_drvdata(pdev, NULL);
	i2c_del_adapter(&d->adapter);
	put_device(&pdev->dev);

	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id hiphyio_i2c_master_of_match[] = {
	{
		.compatible = "hisilicon,hiphyio-i2c",
	},
	{},
};
MODULE_DEVICE_TABLE(of, hiphyio_i2c_master_of_match);
#endif

#ifdef CONFIG_PM
static int hiphyio_i2c_master_suspend(struct device *dev)
{
	unsigned long time, timeout;
	struct platform_device *pdev = to_platform_device(dev);
	struct hiphyio_i2c_dev *d = platform_get_drvdata(pdev);

	if (!d) {
		pr_err("%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}

	dev_info(&pdev->dev, "%s: suspend +\n", __func__);

	timeout = jiffies + msecs_to_jiffies(GET_DEV_LOCK_TIMEOUT);
	while (!mutex_trylock(&d->lock)) {
		time = jiffies;
		if (time_after(time, timeout)) {
			dev_info(&pdev->dev,
				"%s: mutex_trylock timeout fail\n", __func__);
			return -EAGAIN;
		}

		/* sleep between 1000 and 2000 us */
		usleep_range(1000, 2000);
	}
	d->initd = 0;
	
	dev_info(&pdev->dev, "%s: suspend -\n", __func__);
	return 0;
}

static int hiphyio_i2c_master_resume(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct hiphyio_i2c_dev *d = platform_get_drvdata(pdev);

	if (!d) {
		pr_err("%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}
	dev_info(&pdev->dev, "%s: resume +\n", __func__);
	mutex_unlock(&d->lock);
	dev_info(&pdev->dev, "%s: resume -\n", __func__);
	return 0;
}
#endif

static SIMPLE_DEV_PM_OPS(
	hiphyio_i2c_master_dev_pm_ops, hiphyio_i2c_master_suspend, hiphyio_i2c_master_resume);

static struct platform_driver hiphyio_i2c_master_driver = {
	.probe = hiphyio_i2c_master_probe,
	.remove = hiphyio_i2c_master_remove,
	.driver = {
		.name = "hiphyio_i2c_master",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hiphyio_i2c_master_of_match),
		.pm = &hiphyio_i2c_master_dev_pm_ops,
	},
};

static int __init hiphyio_i2c_init(void)
{
	return platform_driver_register(&hiphyio_i2c_master_driver);
}

static void __exit hiphyio_i2c_exit(void)
{
	platform_driver_unregister(&hiphyio_i2c_master_driver);
}

subsys_initcall_sync(hiphyio_i2c_init);
module_exit(hiphyio_i2c_exit);

