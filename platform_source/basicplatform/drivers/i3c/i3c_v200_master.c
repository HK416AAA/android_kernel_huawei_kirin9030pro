/*
 * I3C-V200 Master adapter driver (master only).
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

#include "i3c_v200.h"

static inline struct i3c_v200_master *
	to_i3c_master(struct i3c_master_controller *master)
{
	return container_of(master, struct i3c_v200_master, controller);
}

static u8 i3c_dynaddr_add_parity(u8 addr)
{
	u32 i;
	u8 cnt = 0;
	u8 ret_addr;

	for (i = 0; i < I3C_SLAVE_ADDR_BITS; i++) {
		if ((addr >> i) & 0x1)
			cnt++;
	}

	if (cnt & 0x1)
		ret_addr = addr & (~(0x1 << I3C_SLAVE_ADDR_BITS));
	else
		ret_addr = addr | (0x1 << I3C_SLAVE_ADDR_BITS);

	return ret_addr;
}

static void i3c_pp_cnt_set(struct i3c_v200_master *master)
{
	u32 pp_cnt;
	u32 pp_hcnt;
	u32 pp_lcnt;

	pp_cnt = DIV_ROUND_UP(master->clk_rate, I3C_BUS_TYP_I3C_SCL_RATE);
	pp_hcnt = (u32)(pp_cnt * I3C_PP_THIGH_MIN_NS /
		(I3C_PP_THIGH_MIN_NS + I3C_PP_TLOW_MIN_NS)); /* half hcnt */
	pp_hcnt = (pp_hcnt < I3C_PP_THIGH_MIN_NS) ? pp_hcnt : I3C_PP_THIGH_MIN_NS;
	pp_lcnt = pp_cnt - pp_hcnt;
	pp_lcnt = (pp_lcnt < I3C_PP_TLOW_MIN_NS) ? pp_lcnt : I3C_PP_TLOW_MIN_NS;

	writel(pp_lcnt, master->regs + I3C_V200_CLK_PP_LCNT);
	writel(pp_hcnt << I3C_PP_HCNT_START_BIT,
		master->regs + I3C_V200_CLK_PP_HCNT);
}

static void i3c_od_cnt_set(struct i3c_v200_master *master)
{
	u32 od_cnt;
	u32 od_hcnt;
	u32 od_lcnt;

	od_cnt = DIV_ROUND_UP(master->clk_rate, I3C_BUS_I2C_FM_PLUS_SCL_RATE);
	od_hcnt = DIV_ROUND_UP((od_cnt * I3C_I2C_FMP_THIGH_MIN_NS),
		(I3C_I2C_FMP_THIGH_MIN_NS + I3C_I2C_FMP_TLOW_MIN_NS));

	od_hcnt = (od_hcnt < I3C_MAX_OD_HCNT) ? od_hcnt : I3C_MAX_OD_HCNT;
	od_lcnt = od_cnt - od_hcnt;
	od_lcnt = (od_lcnt < I3C_MAX_OD_LCNT) ? od_lcnt : I3C_MAX_OD_LCNT;

	writel((od_lcnt << I3C_OD_LCNT_START_BIT) |
		(od_hcnt << I3C_OD_HCNT_START_BIT),
		master->regs + I3C_V200_CLK_OD);
}

static void i3c_i2c_cnt_set(struct i3c_v200_master *master)
{
	u32 i2c_cnt;
	u32 i2c_hcnt;
	u32 i2c_lcnt;

	if (master->i2c_scl_hz == I3C_BUS_I2C_FM_PLUS_SCL_RATE) {
		i2c_cnt = DIV_ROUND_UP(master->clk_rate, I3C_BUS_I2C_FM_PLUS_SCL_RATE);
		i2c_hcnt = DIV_ROUND_UP((i2c_cnt * I3C_I2C_FMP_THIGH_MIN_NS),
			(I3C_I2C_FMP_THIGH_MIN_NS + I3C_I2C_FMP_TLOW_MIN_NS));
	} else {
		i2c_cnt = DIV_ROUND_UP(master->clk_rate, I3C_BUS_I2C_FM_SCL_RATE);
		i2c_hcnt = DIV_ROUND_UP((i2c_cnt * I3C_I2C_FM_THIGH_MIN_NS),
			(I3C_I2C_FM_TLOW_MIN_NS + I3C_I2C_FM_THIGH_MIN_NS));
	}

	i2c_hcnt = (i2c_hcnt < I3C_I2C_MAX_HCNT) ? i2c_hcnt : I3C_I2C_MAX_HCNT;
	i2c_lcnt = i2c_cnt - i2c_hcnt;
	i2c_lcnt = (i2c_lcnt < I3C_I2C_MAX_LCNT) ? i2c_lcnt : I3C_I2C_MAX_LCNT;

	writel((i2c_lcnt << I3C_I2C_LCNT_START_BIT) | i2c_hcnt,
		master->regs + I3C_V200_CLK_I2C);
}

static void i3c_v200_config_init(struct i3c_v200_master *master)
{
	struct i3c_bus *bus = i3c_master_get_bus(&master->controller);

	switch (bus->mode) {
	case I3C_BUS_MODE_MIXED_FAST:
		i3c_i2c_cnt_set(master);
	case I3C_BUS_MODE_PURE:
		i3c_od_cnt_set(master);
		i3c_pp_cnt_set(master);
		break;
	default:
		dev_err(&master->controller.dev, "bus mode invalid\n");
		break;
	}

	writel(I3C_V200_INTR_ALL, master->regs + I3C_V200_INT_MASK);
	writel(I3C_V200_IBI_CTRL | I3C_V200_HOT_JOIN_CTRL |\
		I3C_V200_I2C_SLAVE_PRESENT | I3C_V200_SW_INIT,
		master->regs + I3C_V200_FRAME_CTRL1);
}

static int i3c_v200_set_info(struct i3c_master_controller *controller)
{
	struct i3c_v200_master *master = to_i3c_master(controller);
	struct i3c_device_info info = { };
	int ret;

	ret = i3c_master_get_free_addr(controller, 0);
	if (ret < 0)
		return ret;

	memset_s(&info, sizeof(info), 0, sizeof(info));
	info.dyn_addr = ret;

	ret = i3c_master_set_info(&master->controller, &info);
	if (ret)
		return ret;

	return 0;
}

static int i3c_v200_pins_cfg(struct i3c_master_controller *controller,
	const char *name)
{
	struct pinctrl_state *s = NULL;
	struct i3c_v200_master *master = NULL;
	int ret;

	master = to_i3c_master(controller);
	if (!master) {
		dev_err(&controller->dev, "i3c: i3c master doesn't be init\n");
		return -1;
	}

	if (!master->pinctrl_flag) {
		master->pinctrl = devm_pinctrl_get(controller->dev.parent);
		if (IS_ERR(master->pinctrl))
			return -1;
		master->pinctrl_flag = 1;
	}

	s = pinctrl_lookup_state(master->pinctrl, name);
	if (IS_ERR(s)) {
		devm_pinctrl_put(master->pinctrl);
		master->pinctrl_flag = 0;
		return -1;
	}

	ret = pinctrl_select_state(master->pinctrl, s);
	if (ret < 0) {
		devm_pinctrl_put(master->pinctrl);
		master->pinctrl_flag = 0;
		return -1;
	}

	return 0;
}

static void i3c_v200_reset_controller(struct i3c_v200_master *master)
{
	struct i3c_v200_reset *priv = NULL;
	u32 val = 0;
	int timeout = I3C_WAIT_RESET_STATUS_TIMES;

	priv = &master->priv;
	if (!priv) {
		dev_err(&master->controller.dev,
			"%s:i3c priv doesn't be init\n", __func__);
		return;
	}

	writel(BIT(priv->rst_bit),
		master->reset_reg_base + priv->rst_enable);
	do {
		val = readl(master->reset_reg_base + priv->rst_status);
		val &= BIT(priv->rst_bit);
		udelay(1);
	} while (!val && timeout--);
	if (timeout <= 0)
		dev_err(&master->controller.dev,
			"%s:i3c reset enable timeout\n", __func__);

	timeout = I3C_WAIT_RESET_STATUS_TIMES;

	writel(BIT(priv->rst_bit),
		master->reset_reg_base + priv->rst_disable);
	do {
		val = readl(master->reset_reg_base + priv->rst_status);
		val &= BIT(priv->rst_bit);
		udelay(1);
	} while (val && timeout--);
	if (timeout <= 0)
		dev_err(&master->controller.dev,
			"%s:i3c reset disable timeout\n", __func__);
}

void i3c_reset_controller(struct i3c_v200_master *master)
{
	int i;

	if (!master)
		return;

	disable_irq(master->irq);

	for (i = 0; i < I3C_V200_MAX_DEVS; i++)
		master->slave_addr[i] = readl(master->regs +
			I3C_V200_DEVICE_TABLE + i * 4);

	i3c_v200_reset_controller(master);

	i3c_v200_config_init(master);

	for (i = 0; i < I3C_V200_MAX_DEVS; i++)
		writel(master->slave_addr[i], master->regs +
			I3C_V200_DEVICE_TABLE + i * 4);

	enable_irq(master->irq);
}

static int i3c_v200_pin_check(struct i3c_v200_master *master)
{
	u32 status;
	int i;

	for (i = 0; i < 3; i++) {
		status = readl(master->regs + I3C_V200_TRANS_STATE);
		if (((status >> 28) & 0x3) == 0x3)
			return 0;
		mdelay(1);
	}

	dev_err(&master->controller.dev, "i3c sda/scl status err 0x%x\n", status);

	return -1;
}

static void i3c_v200_fifo_clear(struct i3c_v200_master *master)
{
	u32 fifo_ctrl = 0;

	fifo_ctrl = readl(master->regs + I3C_V200_FIFO_CTRL);
	fifo_ctrl |= I3C_V200_FIFO_CLEAR;
	writel(fifo_ctrl, master->regs + I3C_V200_FIFO_CTRL);
	fifo_ctrl &= (~I3C_V200_FIFO_CLEAR);
	writel(fifo_ctrl, master->regs + I3C_V200_FIFO_CTRL);
}

/* for i3c send waveform,must use with send_unprepare */
static int i3c_v200_send_prepare(struct i3c_master_controller *controller)
{
	struct i3c_v200_master *master = NULL;

	master = to_i3c_master(controller);
	if (!master) {
		dev_err(&controller->dev, "%s get i3c master failed!\n", __func__);
		return -EINVAL;
	}

	mutex_lock(&master->lock);

	if (i3c_v200_pins_cfg(controller, PINCTRL_STATE_DEFAULT))
		dev_err(&master->controller.dev, "i3c: set pin default failed\n");
	if (i3c_v200_pin_check(master))
		return -EINVAL;
	writel(readl(master->regs + I3C_V200_FRAME_CTRL1) & (~I3C_V200_SW_INIT),
		master->regs + I3C_V200_FRAME_CTRL1);
	i3c_v200_fifo_clear(master);

	return 0;
}

/* for i3c send Waveform,must use with send_prepare */
static void i3c_v200_send_unprepare(struct i3c_master_controller *controller)
{
	struct i3c_v200_master *master = NULL;

	master = to_i3c_master(controller);
	if (!master) {
		dev_err(&controller->dev, "%s get i3c master failed!\n", __func__);
		return;
	}

	writel(readl(master->regs + I3C_V200_FRAME_CTRL1) | I3C_V200_SW_INIT,
		master->regs + I3C_V200_FRAME_CTRL1);
	if (i3c_v200_pins_cfg(controller, PINCTRL_STATE_IDLE))
		dev_err(&controller->dev, "i3c: set pin idle failed\n");

	mutex_unlock(&master->lock);
}

static bool i3c_v200_supports_ccc_cmd(struct i3c_master_controller *controller,
	const struct i3c_ccc_cmd *cmd)
{
	if (cmd->ndests > 1)
		return false;

	switch (cmd->id) {
	case I3C_CCC_ENEC(true):
	case I3C_CCC_ENEC(false):
	case I3C_CCC_DISEC(true):
	case I3C_CCC_DISEC(false):
	case I3C_CCC_ENTAS(0, true):
	case I3C_CCC_ENTAS(0, false):
	case I3C_CCC_RSTDAA(true):
	case I3C_CCC_RSTDAA(false):
	case I3C_CCC_ENTDAA:
	case I3C_CCC_SETMWL(true):
	case I3C_CCC_SETMWL(false):
	case I3C_CCC_SETMRL(true):
	case I3C_CCC_SETMRL(false):
	case I3C_CCC_ENTHDR(0):
	case I3C_CCC_SETDASA:
	case I3C_CCC_SETNEWDA:
	case I3C_CCC_GETMWL:
	case I3C_CCC_GETMRL:
	case I3C_CCC_GETPID:
	case I3C_CCC_GETBCR:
	case I3C_CCC_GETDCR:
	case I3C_CCC_GETSTATUS:
	case I3C_CCC_GETMXDS:
	case I3C_CCC_GETHDRCAP:
		return true;
	default:
		return false;
	}
}

static int i3c_v200_master_get_addr_pos(struct i3c_v200_master *master, u8 addr)
{
	int pos;

	for (pos = 0; pos < master->maxdevs; pos++) {
		if (addr == master->addrs[pos])
			return pos;
	}

	return -EINVAL;
}

static int i3c_v200_get_free_pos(struct i3c_v200_master *master)
{
	if (!(master->free_pos & GENMASK(master->maxdevs - 1, 0)))
		return -ENOSPC;

	return ffs(master->free_pos) - 1;
}

static void i3c_v200_master_write(struct i3c_v200_master *master,
	const u8 *bytes, u16 nbytes)
{
	writesl(master->regs + I3C_V200_TX_DATA_PORT, bytes, nbytes / 4);
	if (nbytes & 3) {
		u32 tmp = 0;

		memcpy_s(&tmp, nbytes & 3, bytes + (nbytes & ~3), nbytes & 3);
		writesl(master->regs + I3C_V200_TX_DATA_PORT, &tmp, 1);
	}
}

static void i3c_v200_master_read(struct i3c_v200_master *master,
	u8 *bytes, u16 nbytes)
{
	readsl(master->regs + I3C_V200_RX_DATA_PORT, bytes, nbytes / 4);
	if (nbytes & 3) {
		u32 tmp;

		readsl(master->regs + I3C_V200_RX_DATA_PORT, &tmp, 1);
		memcpy_s(bytes + (nbytes & ~3), nbytes & 3, &tmp, nbytes & 3);
	}
}

struct i3c_v200_xfer *
	i3c_v200_alloc_xfer(struct i3c_v200_master *master, unsigned int ncmds)
{
	struct i3c_v200_xfer *xfer = NULL;

	xfer = kzalloc(struct_size(xfer, cmds, ncmds), GFP_KERNEL);
	if (!xfer)
		return NULL;

	INIT_LIST_HEAD(&xfer->node);
	xfer->ncmds = ncmds;
	xfer->ret = -ENOMEM;

	return xfer;
}

static void i3c_v200_start_xfer(struct i3c_v200_master *master)
{
	struct i3c_v200_xfer *xfer = master->xferqueue.cur;
	unsigned int i;

	if (!xfer)
		return;

	for (i = 0; i < xfer->ncmds; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		i3c_v200_master_write(master, cmd->tx_buf, cmd->tx_len);
	}

	for (i = 0; i < xfer->ncmds; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		writel(cmd->cmd_hi, master->regs + I3C_V200_TRANSFER_CMD2);
		writel(cmd->cmd_lo, master->regs + I3C_V200_TRANSFER_CMD1);
	}
}

void i3c_v200_enqueue_xfer(struct i3c_v200_master *master,
	struct i3c_v200_xfer *xfer)
{
	unsigned long flags;

	init_completion(&xfer->comp);

	spin_lock_irqsave(&master->xferqueue.lock, flags);
	if (master->xferqueue.cur) {
		list_add_tail(&xfer->node, &master->xferqueue.list);
	} else {
		master->xferqueue.cur = xfer;
		if (master->trans_mode == I3C_TRANSFER_MODE_DMA)
			i3c_v200_dma_start_xfer(master);
		else
			i3c_v200_start_xfer(master);
	}
	spin_unlock_irqrestore(&master->xferqueue.lock, flags);
}

static void i3c_v200_master_dequeue(struct i3c_v200_master *master,
	struct i3c_v200_xfer *xfer)
{
	if (master->xferqueue.cur == xfer)
		master->xferqueue.cur = NULL;
	else
		list_del_init(&xfer->node);
}

void i3c_v200_master_dequeue_xfer(struct i3c_v200_master *master,
	struct i3c_v200_xfer *xfer)
{
	unsigned long flags;

	spin_lock_irqsave(&master->xferqueue.lock, flags);
	i3c_v200_master_dequeue(master, xfer);
	spin_unlock_irqrestore(&master->xferqueue.lock, flags);
}

static void i3c_v200_xfer_end(struct i3c_v200_master *master)
{
	struct i3c_v200_xfer *xfer = master->xferqueue.cur;
	int error;
	int ret = 0;
	unsigned int addr = 0;
	unsigned int i, resp;

	if (!xfer)
		return;

	resp = readl(master->regs + I3C_V200_RESP_STATE);
	error = i3c_v200_resp_error(resp);
	addr = (resp >> I3C_V200_RESP_SLAVE_ADDR_START) & SLAVE_ADDR_MASK;

	switch (error) {
	case I3C_V200_RESP_NO_ERROR:
		for (i = 0; i < xfer->ncmds; i++) {
			struct i3c_v200_cmd *cmd = &xfer->cmds[i];

			if (cmd->rx_len)
				i3c_v200_master_read(master, cmd->rx_buf,
					cmd->rx_len);
		}
		break;
	case I3C_V200_RESP_BROADCAST_ERROR:
		ret = -I3C_V200_RESP_BROADCAST_ERROR;
		dev_err(&master->controller.dev, "i3c broadcast err,slave 0x%x\n", addr);
		break;
	case I3C_V200_RESP_SLAVE_NACK:
		ret = -I3C_V200_RESP_SLAVE_NACK;
		dev_err(&master->controller.dev, "i3c addr nack,slave 0x%x\n", addr);
		break;
	case I3C_V200_RESP_I2C_WRITE_NACK:
		ret = -I3C_V200_RESP_I2C_WRITE_NACK;
		dev_err(&master->controller.dev, "i3c write nack,slave 0x%x\n", addr);
		break;
	case I3C_V200_RESP_ENTDAA_NACK:
		ret = -I3C_V200_RESP_ENTDAA_NACK;
		dev_err(&master->controller.dev, "i3c entdaa nack,slave 0x%x\n", addr);
		break;
	default:
		ret = -EINVAL;
		break;
	}

	xfer->ret = ret;
	complete(&xfer->comp);
	if (ret < 0)
		i3c_v200_master_dequeue(master, xfer);

	xfer = list_first_entry_or_null(&master->xferqueue.list,
		struct i3c_v200_xfer, node);
	if (xfer)
		list_del_init(&xfer->node);

	master->xferqueue.cur = xfer;
	i3c_v200_start_xfer(master);
}

static int i3c_v200_master_init(struct i3c_master_controller *controller)
{
	int ret;
	struct i3c_v200_master *master = NULL;

	master = to_i3c_master(controller);
	if (!master) {
		dev_err(&controller->dev, "%s get i3c master failed!\n", __func__);
		return -EINVAL;
	}

	i3c_v200_config_init(master);

	ret = i3c_v200_set_info(controller);
	if (ret) {
		dev_err(&master->controller.dev, "%s i3c_v200_set_info failed!\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static int i3c_v200_ccc_set(struct i3c_v200_master *master,
	struct i3c_ccc_cmd *ccc)
{
	struct i3c_v200_xfer *xfer = NULL;
	struct i3c_v200_cmd *cmd = NULL;
	int ret, pos = 0;

	if (ccc->id & I3C_CCC_DIRECT) {
		pos = i3c_v200_master_get_addr_pos(master, ccc->dests[0].addr);
		if (pos < 0)
			return pos;
	}

	xfer = i3c_v200_alloc_xfer(master, 1);
	if (!xfer)
		return -ENOMEM;

	cmd = xfer->cmds;
	cmd->tx_buf = ccc->dests[0].payload.data;
	cmd->tx_len = ccc->dests[0].payload.len;

	cmd->cmd_hi = i3c_v200_data_len(ccc->dests[0].payload.len) |
		      I3C_V200_TRANS_ARG;
	cmd->cmd_lo = I3C_V200_CMD_CP |
		I3C_V200_CMD_SDAP |
		i3c_v200_cmd_dev_index(pos) |
		i3c_v200_cmd_cmd(ccc->id) |
		I3C_V200_CMD_TOC |
		I3C_V200_TRANSFER_CMD;

	i3c_v200_enqueue_xfer(master, xfer);

	if (!wait_for_completion_timeout(&xfer->comp, I3C_TIMEOUT)) {
		dev_err(&master->controller.dev, "%s timeout,resp stat 0x%x\n",
			__func__, readl(master->regs + I3C_V200_TRANS_STATE));
		xfer->ret = -ETIMEDOUT;
		i3c_reset_controller(master);
		i3c_v200_master_dequeue_xfer(master, xfer);
	}

	ret = xfer->ret;

	kfree(xfer);

	return ret;
}

static int i3c_v200_ccc_get(struct i3c_v200_master *master,
	struct i3c_ccc_cmd *ccc)
{
	struct i3c_v200_xfer *xfer = NULL;
	struct i3c_v200_cmd *cmd = NULL;
	int ret, pos;

	pos = i3c_v200_master_get_addr_pos(master, ccc->dests[0].addr);
	if (pos < 0)
		return pos;

	xfer = i3c_v200_alloc_xfer(master, 1);
	if (!xfer)
		return -ENOMEM;

	cmd = xfer->cmds;
	cmd->rx_buf = ccc->dests[0].payload.data;
	cmd->rx_len = ccc->dests[0].payload.len;

	cmd->cmd_hi = i3c_v200_data_len(ccc->dests[0].payload.len) |
		I3C_V200_TRANS_ARG;
	cmd->cmd_lo = I3C_V200_CMD_RNW |
		I3C_V200_CMD_CP |
		i3c_v200_cmd_dev_index(pos) |
		i3c_v200_cmd_cmd(ccc->id) |
		I3C_V200_CMD_TOC |
		I3C_V200_TRANSFER_CMD;

	i3c_v200_enqueue_xfer(master, xfer);

	if (!wait_for_completion_timeout(&xfer->comp, I3C_TIMEOUT)) {
		dev_err(&master->controller.dev, "%s timeout,resp stat 0x%x\n",
			__func__, readl(master->regs + I3C_V200_TRANS_STATE));
		xfer->ret = -ETIMEDOUT;
		i3c_reset_controller(master);
		i3c_v200_master_dequeue_xfer(master, xfer);
	}

	ret = xfer->ret;
	kfree(xfer);

	return ret;
}

static int i3c_v200_send_ccc(struct i3c_master_controller *controller,
	struct i3c_ccc_cmd *ccc)
{
	struct i3c_v200_master *master = to_i3c_master(controller);
	int ret = 0;

	if (!master)
		return -EINVAL;

	if (ccc->id == I3C_CCC_ENTDAA)
		return -EINVAL;

	i3c_v200_send_prepare(controller);
	if (ccc->rnw)
		ret = i3c_v200_ccc_get(master, ccc);
	else
		ret = i3c_v200_ccc_set(master, ccc);
	i3c_v200_send_unprepare(controller);

	return ret;
}

static int i3c_v200_prepare_for_dynamic_addr(
	struct i3c_master_controller *controller,
	struct i3c_v200_master *master, u32 *olddevs)
{
	u32 pos;
	u8 p;
	u8 last_addr = 0;
	int ret;

	*olddevs = ~(master->free_pos);

	/* Prepare DAT before launching DAA. */
	for (pos = 0; pos < master->maxdevs; pos++) {
		if (*olddevs & BIT(pos))
			continue;

		ret = i3c_master_get_free_addr(controller, last_addr + 1);
		if (ret < 0) {
			dev_err(&controller->dev, "%s get free addr failed!\n", __func__);
			return -ENOSPC;
		}
		master->addrs[pos] = ret;
		p = i3c_dynaddr_add_parity(ret);
		last_addr = ret;
		ret |= (p << 7);

		writel(i3c_device_table_dynamic_add(ret),
		       master->regs + I3C_V200_DEVICE_TABLE + pos * 4);
	}

	return 0;
}

static int i3c_v200_do_daa(struct i3c_master_controller *controller)
{
	struct i3c_v200_master *master = to_i3c_master(controller);
	struct i3c_v200_xfer *xfer = NULL;
	struct i3c_v200_cmd *cmd = NULL;
	u32 olddevs, newdevs;
	int ret, pos;

	if (!master)
		return -EINVAL;

	i3c_v200_send_prepare(controller);

	ret = i3c_v200_prepare_for_dynamic_addr(controller, master, &olddevs);
	if (ret) {
		i3c_v200_send_unprepare(controller);
		return ret;
	}

	xfer = i3c_v200_alloc_xfer(master, 1);
	if (!xfer) {
		i3c_v200_send_unprepare(controller);
		return -ENOMEM;
	}

	pos = i3c_v200_get_free_pos(master);
	cmd = &xfer->cmds[0];
	cmd->cmd_lo = i3c_v200_aac_dev_count(master->maxdevs - pos) |
		i3c_v200_aac_dev_index(pos) | i3c_v200_aac_cmd(I3C_CCC_ENTDAA) |
		I3C_V200_AAC_ARG | I3C_V200_AAC_TOC;

	init_completion(&xfer->comp);
	master->xferqueue.cur = xfer;

	writel(cmd->cmd_lo, master->regs + I3C_V200_TRANSFER_CMD4);

	if (!wait_for_completion_timeout(&xfer->comp, I3C_TIMEOUT)) {
		dev_err(&master->controller.dev, "%s timeout,resp stat 0x%x\n",
			__func__, readl(master->regs + I3C_V200_TRANS_STATE));
		i3c_reset_controller(master);
	}

	newdevs = GENMASK(master->maxdevs - 1, 0);
	newdevs &= ~olddevs;

	for (pos = 0; pos < master->maxdevs; pos++) {
		if (newdevs & BIT(pos))
			i3c_master_add_i3c_dev_locked(controller, master->addrs[pos]);
	}

	kfree(xfer);

	i3c_master_disec_locked(controller, I3C_BROADCAST_ADDR,
		I3C_CCC_EVENT_HJ | I3C_CCC_EVENT_MR | I3C_CCC_EVENT_SIR);

	i3c_v200_send_unprepare(controller);

	return 0;
}

static int i3c_v200_xfer_check(struct i3c_priv_xfer *i3c_xfers, int xfer_num)
{
	int i;

	if ((!i3c_xfers) || (!xfer_num))
		return -EINVAL;

	if (xfer_num > I3C_V200_CMD_FIFO_NUM)
		return -ENOTSUPP;

	for (i = 0; i < xfer_num; i++) {
		if (i3c_xfers[i].len > I3C_V200_DATA_FIFO_DEP)
			return -ENOTSUPP;
	}

	return 0;
}

static int i3c_v200_priv_xfers(struct i3c_dev_desc *dev,
	struct i3c_priv_xfer *i3c_xfers,
	int xfer_num)
{
	struct i3c_v200_i2c_dev_data *data = i3c_dev_get_master_data(dev);
	struct i3c_master_controller *controller = i3c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);
	struct i3c_v200_xfer *xfer = NULL;
	int ret = 0;
	int i;

	if ((!data) || (!controller) || (!master))
		return -EINVAL;

	i3c_v200_send_prepare(controller);

	ret = i3c_v200_xfer_check(i3c_xfers, xfer_num);
	if (ret) {
		dev_err(&master->controller.dev, "%s i3c xfer check failed\n", __func__);
		i3c_v200_send_unprepare(controller);
		return ret;
	}

	xfer = i3c_v200_alloc_xfer(master, xfer_num);
	if (!xfer) {
		i3c_v200_send_unprepare(controller);
		return -ENOMEM;
	}

	for (i = 0; i < xfer_num; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		cmd->cmd_hi = i3c_v200_data_len(i3c_xfers[i].len) |
			I3C_V200_TRANS_ARG;

		if (i3c_xfers[i].rnw) {
			cmd->rx_buf = i3c_xfers[i].data.in;
			cmd->rx_len = i3c_xfers[i].len;
			cmd->cmd_lo = I3C_V200_CMD_RNW;
		} else {
			cmd->tx_buf = i3c_xfers[i].data.out;
			cmd->tx_len = i3c_xfers[i].len;
		}

		cmd->cmd_lo |= i3c_v200_cmd_tid(i) |
			i3c_v200_cmd_dev_index(data->index) |
				I3C_V200_TRANSFER_CMD;

		if (i == (xfer_num - 1))
			cmd->cmd_lo |= I3C_V200_CMD_TOC;
	}

	i3c_v200_enqueue_xfer(master, xfer);

	if (!wait_for_completion_timeout(&xfer->comp, I3C_TIMEOUT)) {
		dev_err(&master->controller.dev, "%s timeout,resp stat 0x%x\n",
			__func__, readl(master->regs + I3C_V200_TRANS_STATE));
		xfer->ret = -ETIMEDOUT;
		i3c_reset_controller(master);
		i3c_v200_master_dequeue_xfer(master, xfer);
	}

	ret = xfer->ret;
	kfree(xfer);

	i3c_v200_send_unprepare(controller);
	return ret;
}

static int i3c_v200_reattach_i3c_dev(struct i3c_dev_desc *dev,
	u8 old_dyn_addr)
{
	struct i3c_v200_i2c_dev_data *data = i3c_dev_get_master_data(dev);
	struct i3c_master_controller *controller = i3c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);

	if ((!dev) || (!data) || (!master))
		return -EINVAL;

	mutex_lock(&master->lock);
	writel(dev->info.dyn_addr << 16,
		master->regs + I3C_V200_DEVICE_TABLE + data->index * 4);

	master->addrs[data->index] = dev->info.dyn_addr;
	mutex_unlock(&master->lock);

	return 0;
}

static int i3c_v200_attach_i3c_dev(struct i3c_dev_desc *dev)
{
	struct i3c_master_controller *controller = i3c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);
	struct i3c_v200_i2c_dev_data *data = NULL;
	int pos;

	if ((!dev) || (!master))
		return -EINVAL;

	mutex_lock(&master->lock);
	pos = i3c_v200_get_free_pos(master);
	if (pos < 0) {
		mutex_unlock(&master->lock);
		return pos;
	}

	data = kzalloc(sizeof(*data), GFP_KERNEL);
	if (!data) {
		mutex_unlock(&master->lock);
		return -ENOMEM;
	}

	data->index = pos;
	master->addrs[pos] = dev->info.dyn_addr ? : dev->info.static_addr;
	master->free_pos &= ~BIT(pos);
	i3c_dev_set_master_data(dev, data);

	writel(master->addrs[pos] << 16,
		master->regs + I3C_V200_DEVICE_TABLE + data->index * 4);
	mutex_unlock(&master->lock);

	return 0;
}

static void i3c_v200_detach_i3c_dev(struct i3c_dev_desc *dev)
{
	struct i3c_v200_i2c_dev_data *data = i3c_dev_get_master_data(dev);
	struct i3c_master_controller *controller = i3c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);

	if ((!data) || (!master))
		return;

	mutex_lock(&master->lock);
	writel(0,
		master->regs + I3C_V200_DEVICE_TABLE + data->index * 4);

	i3c_dev_set_master_data(dev, NULL);
	master->addrs[data->index] = 0;
	master->free_pos |= BIT(data->index);
	kfree(data);
	mutex_unlock(&master->lock);
}

static int i3c_v200_i2c_xfer_check(const struct i2c_msg *i2c_xfers, int xfer_num)
{
	int i;

	if ((!i2c_xfers) || (!xfer_num))
		return -EINVAL;

	if (xfer_num > I3C_V200_CMD_FIFO_NUM)
		return -ENOTSUPP;
	for (i = 0; i < xfer_num; i++) {
		if (i2c_xfers[i].len > I3C_V200_DATA_FIFO_DEP)
			return -ENOTSUPP;
	}

	return 0;
}

static int i3c_v200_i2c_irq_transfer(struct i3c_v200_master *master,
	const struct i2c_msg *i2c_xfers, int xfer_num,
	struct i3c_v200_i2c_dev_data *data)
{
	u32 i;
	struct i3c_v200_xfer *xfer = NULL;
	int ret = 0;

	ret = i3c_v200_i2c_xfer_check(i2c_xfers, xfer_num);
	if (ret) {
		dev_err(&master->controller.dev, "%s i3c i2c xfer check failed\n", __func__);
		return ret;
	}
	xfer = i3c_v200_alloc_xfer(master, xfer_num);
	if (!xfer) {
		dev_err(&master->controller.dev, "%s alloc xfer failed\n", __func__);
		return -ENOMEM;
	}

	for (i = 0; i < xfer_num; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		cmd->cmd_hi = i3c_v200_data_len(i2c_xfers[i].len) |
			I3C_V200_TRANS_ARG;
		cmd->cmd_lo = i3c_v200_cmd_tid(i) |
			i3c_v200_cmd_dev_index(data->index) |
			I3C_V200_TRANSFER_CMD;

		if (i2c_xfers[i].flags & I2C_M_RD) {
			cmd->cmd_lo |= I3C_V200_CMD_RNW;
			cmd->rx_buf = i2c_xfers[i].buf;
			cmd->rx_len = i2c_xfers[i].len;
		} else {
			cmd->tx_buf = i2c_xfers[i].buf;
			cmd->tx_len = i2c_xfers[i].len;
		}

		if (i == (xfer_num - 1))
			cmd->cmd_lo |= I3C_V200_CMD_TOC;
	}
	i3c_v200_enqueue_xfer(master, xfer);

	if (!wait_for_completion_timeout(&xfer->comp, I3C_TIMEOUT)) {
		dev_err(&master->controller.dev, "%s timeout,resp stat 0x%x\n",
			__func__, readl(master->regs + I3C_V200_TRANS_STATE));
		xfer->ret = -ETIMEDOUT;
		i3c_reset_controller(master);
		i3c_v200_master_dequeue_xfer(master, xfer);
	}

	ret = xfer->ret;
	kfree(xfer);

	return ret;
}

static int i3c_v200_i2c_xfers(struct i2c_dev_desc *dev,
	const struct i2c_msg *i2c_xfers, int xfer_num)
{
	struct i3c_v200_i2c_dev_data *data = i2c_dev_get_master_data(dev);
	struct i3c_master_controller *controller = i2c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);
	int ret = 0;

	if ((!data) || (!controller) || (!master))
		return -EINVAL;

	i3c_v200_send_prepare(controller);

	if (master->trans_mode == I3C_TRANSFER_MODE_DMA)
		ret = i3c_v200_i2c_dma_transfer(master, i2c_xfers, xfer_num, data);
	else
		ret = i3c_v200_i2c_irq_transfer(master, i2c_xfers, xfer_num, data);

	i3c_v200_send_unprepare(controller);
	return ret;
}

static int i3c_v200_attach_i2c_dev(struct i2c_dev_desc *dev)
{
	struct i3c_master_controller *controller = i2c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);
	struct i3c_v200_i2c_dev_data *data = NULL;
	int pos;

	if ((!dev) || (!master))
		return -EINVAL;

	mutex_lock(&master->lock);
	pos = i3c_v200_get_free_pos(master);
	if (pos < 0) {
		mutex_unlock(&master->lock);
		return pos;
	}

	data = kzalloc(sizeof(*data), GFP_KERNEL);
	if (!data) {
		mutex_unlock(&master->lock);
		return -ENOMEM;
	}

	data->index = pos;
	master->addrs[pos] = dev->boardinfo->base.addr;
	master->free_pos &= ~BIT(pos);
	i2c_dev_set_master_data(dev, data);

	writel(I3C_DEVICE_TABLE_I2C |
		dev->boardinfo->base.addr,
		master->regs + I3C_V200_DEVICE_TABLE + data->index * 4);
	mutex_unlock(&master->lock);
	return 0;
}

static void i3c_v200_detach_i2c_dev(struct i2c_dev_desc *dev)
{
	struct i3c_v200_i2c_dev_data *data = i2c_dev_get_master_data(dev);
	struct i3c_master_controller *controller = i2c_dev_get_master(dev);
	struct i3c_v200_master *master = to_i3c_master(controller);

	if ((!data) || (!master))
		return;

	mutex_lock(&master->lock);
	writel(0,
		master->regs + I3C_V200_DEVICE_TABLE + data->index * 4);

	i2c_dev_set_master_data(dev, NULL);
	master->addrs[data->index] = 0;
	master->free_pos |= BIT(data->index);
	kfree(data);
	mutex_unlock(&master->lock);
}

static u32 i3c_v200_i2c_funcs(struct i3c_master_controller *controller)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

static irqreturn_t i3c_v200_irq_handler(int irq, void *dev_id)
{
	struct i3c_v200_master *master = dev_id;
	u32 status;

	if (!master)
		return IRQ_NONE;

	status = i3c_v200_int_status(readl(master->regs + I3C_V200_INT_STATE));

	writel(status, master->regs + I3C_V200_INT_CLEAR);
	if (!(status & readl(master->regs + I3C_V200_INT_MASK)))
		return IRQ_NONE;

	spin_lock(&master->xferqueue.lock);
	i3c_v200_xfer_end(master);
	spin_unlock(&master->xferqueue.lock);

	return IRQ_HANDLED;
}

static const struct i3c_master_controller_ops i3c_v200_ops = {
	.bus_init = i3c_v200_master_init,
	.attach_i3c_dev = i3c_v200_attach_i3c_dev,
	.reattach_i3c_dev = i3c_v200_reattach_i3c_dev,
	.detach_i3c_dev = i3c_v200_detach_i3c_dev,
	.do_daa = i3c_v200_do_daa,
	.supports_ccc_cmd = i3c_v200_supports_ccc_cmd,
	.send_ccc_cmd = i3c_v200_send_ccc,
	.priv_xfers = i3c_v200_priv_xfers,
	.attach_i2c_dev = i3c_v200_attach_i2c_dev,
	.detach_i2c_dev = i3c_v200_detach_i2c_dev,
	.i2c_xfers = i3c_v200_i2c_xfers,
};

static void i3c_v200_read_ctrl_cfg(struct device *dev,
	struct i3c_v200_master *master)
{
	int ret;
	u32 data[I3C_RESET_REG_CNT] = {0};

	ret = of_property_read_u32_array(dev->of_node, "reset-reg-base",
		&data[0], ARRAY_SIZE(data));
	if (ret) {
		dev_err(dev, "doesn't have reset-reg-base property!\n");
	} else {
		master->reset_reg_base = devm_ioremap(dev, data[1], data[3]);
		dev_info(dev, "i3c reset register phy_addr is: %x\n", data[1]);
	}

	ret = of_property_read_u32_array(dev->of_node, "reset-controller-reg",
		&data[0], ARRAY_SIZE(data));
	if (ret)
		dev_err(dev, "doesn't have reset-controller-reg property!\n");

	/* data[0~2] is reset register address, data[3] is reset bit for i2c */
	master->priv.rst_enable = data[0];
	master->priv.rst_disable = data[1];
	master->priv.rst_status = data[2];
	master->priv.rst_bit = data[3];
}

static int i3c_v200_parse_dt(struct platform_device *pdev,
	struct i3c_v200_master *master)
{
	u64 clk_rate = 0;
	struct device *dev = NULL;
	u32 i2c_speed = 0;
	u32 transfer_mode = 0;
	int ret;

	if (!pdev)
		return -EINVAL;
	if ((!master) || (!master->core_clk))
		return -EINVAL;

	dev = &pdev->dev;
	master->pinctrl_flag = 0;
	master->pinctrl = NULL;

	ret = of_property_read_u64(dev->of_node, "clock-rate", &clk_rate);
	if (ret) {
		dev_err(dev, "i3c master doesn't have clock-rate property!\n");
	} else {
		master->clk_rate = clk_rate;
		ret = clk_set_rate(master->core_clk, clk_rate);
		if (ret) {
			dev_err(dev, "clock rate set failed r[0x%.x]\n", ret);
			return -EINVAL;
		}
	}

	ret = of_property_read_u32(dev->of_node, "i2c-scl-hz", &i2c_speed);
	if (ret)
		master->i2c_scl_hz = I3C_BUS_I2C_FM_SCL_RATE;
	else
		master->i2c_scl_hz = i2c_speed;

	ret = of_property_read_u32(dev->of_node, "trans-mode", &transfer_mode);
	if (ret) {
		dev_info(dev, "i3c master doesn't have trans-mode, use defult\n");
		master->trans_mode = I3C_TRANSFER_MODE_IRQ;
	} else {
		if (transfer_mode == I3C_TRANSFER_MODE_DMA)
			master->trans_mode = I3C_TRANSFER_MODE_DMA;
		else
			master->trans_mode = I3C_TRANSFER_MODE_IRQ;
	}

	i3c_v200_read_ctrl_cfg(dev, master);

	return 0;
}

static int i3c_v200_probe(struct platform_device *pdev)
{
	struct i3c_v200_master *master = NULL;
	struct resource *res = NULL;
	int ret;

	master = devm_kzalloc(&pdev->dev, sizeof(*master), GFP_KERNEL);
	if (!master)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	master->mapbase = res->start;
	master->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(master->regs)) {
		dev_err(&pdev->dev, "%s get resource fail\n", __func__);
		return -EINVAL;
	}

	master->core_clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(master->core_clk)) {
		dev_err(&pdev->dev, "get clk fail\n");
		return -ENODEV;
	}
	ret = clk_prepare_enable(master->core_clk);
	if (ret)
		goto err_disable_core_clk;

	ret = i3c_v200_parse_dt(pdev, master);
	if (ret)
		goto err_disable_core_clk;

	mutex_init(&master->lock);
	spin_lock_init(&master->xferqueue.lock);
	INIT_LIST_HEAD(&master->xferqueue.list);

	writel(I3C_V200_INTR_ALL, master->regs + I3C_V200_INT_MASK);
	master->irq = platform_get_irq(pdev, 0);
	ret = devm_request_irq(&pdev->dev, master->irq,
		i3c_v200_irq_handler, 0, dev_name(&pdev->dev), master);
	if (ret)
		goto err_disable_core_clk;

	platform_set_drvdata(pdev, master);

	/* Information regarding the FIFOs/QUEUEs depth */
	master->maxdevs = I3C_V200_MAX_DEVS;
	master->free_pos = GENMASK(master->maxdevs - 1, 0);

	ret = i3c_master_register(&master->controller, &pdev->dev,
		&i3c_v200_ops, false);
	if (ret)
		goto err_disable_core_clk;

	/* DMA probe */
	i3c_v200_dma_probe_initcall(master);

	dev_err(&pdev->dev, "probe succes\n");
	return 0;

err_disable_core_clk:
	clk_disable_unprepare(master->core_clk);

	return ret;
}

static int i3c_v200_remove(struct platform_device *pdev)
{
	struct i3c_v200_master *master = platform_get_drvdata(pdev);
	int ret;

	ret = i3c_master_unregister(&master->controller);
	if (ret)
		return ret;

	i3c_v200_dma_remove(master);

	clk_disable_unprepare(master->core_clk);

	return 0;
}

int i3c_v200_suspend(struct device *dev)
{
	unsigned long time, timeout;
	struct platform_device *pdev = to_platform_device(dev);
	struct i3c_v200_master *master = platform_get_drvdata(pdev);
	int i;

	if ((!master) || (!master->core_clk)) {
		dev_err(dev, "%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}

	dev_info(dev, "%s: suspend +\n", __func__);

	timeout = jiffies + msecs_to_jiffies(500);
	while (!mutex_trylock(&master->lock)) {
		time = jiffies;
		if (time_after(time, timeout)) {
			dev_info(&pdev->dev,
				"%s: mutex_trylock timeout fail\n", __func__);
			return -EAGAIN;
		}
		/* sleep between 1000 and 2000 us */
		usleep_range(1000, 2000);
	}

	for (i = 0; i < I3C_V200_MAX_DEVS; i++)
		master->slave_addr[i] = readl(master->regs +
			I3C_V200_DEVICE_TABLE + i * 4);

	clk_disable_unprepare(master->core_clk);
	dev_info(dev, "%s: suspend -\n", __func__);

	return 0;
}

int i3c_v200_resume(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct i3c_v200_master *master = platform_get_drvdata(pdev);
	int ret, i;

	if ((!master) || (!master->core_clk)) {
		dev_err(dev, "%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}

	dev_info(dev, "%s: resume +\n", __func__);

	ret = clk_prepare_enable(master->core_clk);
	if (ret)
		dev_err(dev, "enable clk failed\n");

	i3c_v200_config_init(master);

	for (i = 0; i < I3C_V200_MAX_DEVS; i++)
	writel(master->slave_addr[i], master->regs +
		I3C_V200_DEVICE_TABLE + i * 4);
	mutex_unlock(&master->lock);
	dev_info(dev, "%s: resume -\n", __func__);

	return 0;
}

static const struct of_device_id i3c_v200_master_of_match[] = {
	{ .compatible = "hisilicon,i3c-v200-master", },
	{},
};
MODULE_DEVICE_TABLE(of, i3c_v200_master_of_match);

static SIMPLE_DEV_PM_OPS(i3c_v200_pm_ops, i3c_v200_suspend, i3c_v200_resume);

static struct platform_driver i3c_v200_driver = {
	.probe = i3c_v200_probe,
	.remove = i3c_v200_remove,
	.driver = {
		.name           = "i3c-v200-master",
		.of_match_table = of_match_ptr(i3c_v200_master_of_match),
		.pm             = &i3c_v200_pm_ops,
	},
};

static int __init i3c_v200_init(void)
{
	return platform_driver_register(&i3c_v200_driver);
}

static void __exit i3c_v200_exit(void)
{
	platform_driver_unregister(&i3c_v200_driver);
}

subsys_initcall_sync(i3c_v200_init);
module_exit(i3c_v200_exit);

MODULE_DESCRIPTION("I3C V200 driver");
MODULE_LICENSE("GPL v2");
