/*
 * I3C-V200 Master Dma driver.
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

#ifdef CONFIG_DMA_ENGINE
void i3c_v200_dma_probe_initcall(struct i3c_v200_master *master)
{
	struct dma_chan *chan = NULL;
	dma_cap_mask_t mask;
	struct dma_slave_config tx_conf = {};
	struct dma_slave_config rx_conf = {};

	if (!master)
		return;

	/* DMA is the sole user of the platform data right now */
	tx_conf.dst_addr = master->mapbase + I3C_V200_TX_DATA_PORT;
	tx_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	tx_conf.direction = DMA_MEM_TO_DEV;
	tx_conf.dst_maxburst = 1;

	rx_conf.src_addr = master->mapbase + I3C_V200_RX_DATA_PORT;
	rx_conf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
	rx_conf.direction = DMA_DEV_TO_MEM;
	rx_conf.src_maxburst = 1;

	/* Try to acquire a generic DMA engine slave TX channel */
	dma_cap_zero(mask);
	dma_cap_set(DMA_SLAVE, mask);

	chan = dma_request_slave_channel(&master->controller.dev, "tx");
	if (!chan) {
		dev_err(&master->controller.dev, "no TX DMA channel!\n");
		return;
	}

	dmaengine_slave_config(chan, &tx_conf);
	master->dmatx.chan = chan;

	dev_info(&master->controller.dev, "DMA channel TX %s-%d\n",
		dma_chan_name(master->dmatx.chan),
		master->dmatx.chan->chan_id);

	chan = dma_request_slave_channel(&master->controller.dev, "rx");
	if (!chan) {
		dev_err(&master->controller.dev, "no RX DMA channel!\n");
		return;
	}

	dmaengine_slave_config(chan, &rx_conf);
	master->dmarx.chan = chan;

	dev_info(&master->controller.dev, "DMA channel RX %s-%d\n",
		dma_chan_name(master->dmarx.chan),
		master->dmarx.chan->chan_id);
}

void i3c_v200_dma_remove(struct i3c_v200_master *master)
{
	if (!master)
		return;

	/* remove the initcall if it has not yet executed */
	if (master->dmatx.chan)
		dma_release_channel(master->dmatx.chan);
	if (master->dmarx.chan)
		dma_release_channel(master->dmarx.chan);
}

/*
 * The current DMA TX buffer has been sent.
 * Try to queue up another DMA buffer.
 */
static void i3c_v200_dma_tx_callback(void *data)
{
	struct i3c_v200_master *master = data;
	struct i3c_v200_xfer *xfer =  NULL;

	xfer = master->xferqueue.cur;
	if (!xfer) {
		dev_err(&master->controller.dev, "%s:xfer is null\n", __func__);
		return;
	}

	master->using_tx_dma = false;
	if (!(master->using_tx_dma) && !(master->using_rx_dma))
		complete(&xfer->comp);
}

static int i3c_v200_dma_tx_refill(struct i3c_v200_master *master)
{
	struct i3c_v200_dma_data *dmatx = NULL;
	struct dma_chan *chan = NULL;
	struct dma_device *dma_dev = NULL;
	struct dma_async_tx_descriptor *desc = NULL;

	dmatx = &master->dmatx;
	chan = dmatx->chan;
	if (!chan) {
		dev_err(&master->controller.dev, "chan is NULL!\n");
		return -EIO;
	}

	dma_dev = chan->device;

	/* Map only 1 entry */
	if (dma_map_sg(dma_dev->dev, &dmatx->sg, 1, DMA_TO_DEVICE) != 1) {
		dev_err(&master->controller.dev, "unable to map TX DMA\n");
		return -EBUSY;
	}

	/* only 1 mapped entry */
	desc = dmaengine_prep_slave_sg(chan, &dmatx->sg, 1, DMA_MEM_TO_DEV,
		DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!desc) {
		dma_unmap_sg(dma_dev->dev, &dmatx->sg, 1, DMA_TO_DEVICE);
		dev_err(&master->controller.dev, "TX DMA busy\n");
		return -EBUSY;
	}

	/* Some data to go along to the callback */
	desc->callback = i3c_v200_dma_tx_callback;
	desc->callback_param = master;

	desc->tx_submit(desc);

	/* Fire the DMA transaction */
	dma_dev->device_issue_pending(chan);

	return 0;
}

static void i3c_v200_dma_rx_callback(void *data)
{
	struct i3c_v200_master *master = data;
	struct i3c_v200_xfer *xfer = NULL;
	struct i3c_v200_dma_data *dmarx = NULL;
	u32 rx_valid;
	u32 rd_idx = 0;
	u32 len, i;
	u8 *buf = NULL;

	xfer = master->xferqueue.cur;
	if (!xfer) {
		dev_err(&master->controller.dev,
			"%s:xfer is null\n", __func__);
		return;
	}

	dmarx = &master->dmarx;
	if (!dmarx) {
		dev_err(&master->controller.dev,
			"%s:dmarx is null\n", __func__);
		return;
	}

	rx_valid = dmarx->sg.length;

	/* Sync in buffer , only 1 mapped entry */
	dma_sync_sg_for_cpu(&master->controller.dev,
		&dmarx->sg, 1, DMA_FROM_DEVICE);

	for (i = 0; i < xfer->ncmds; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		if (!cmd->rx_len)
			continue;

		len = cmd->rx_len;
		buf = cmd->rx_buf;

		for (; len > 0 && rx_valid > 0; len--, rx_valid--)
			*buf++ = dmarx->buf[rd_idx++];
	}

	master->using_rx_dma = false;
	if (!(master->using_tx_dma) && !(master->using_rx_dma))
		complete(&xfer->comp);
}

static int i3c_v200_dma_rx_trigger_dma(struct i3c_v200_master *master)
{
	struct i3c_v200_dma_data *dmarx = NULL;
	struct dma_chan *rxchan = NULL;
	struct dma_device *dma_dev = NULL;
	struct dma_async_tx_descriptor *desc = NULL;

	dmarx = &master->dmarx;
	rxchan = dmarx->chan;
	if (!rxchan) {
		dev_err(&master->controller.dev, "rxchan is NULL!\n");
		return -EIO;
	}

	dma_dev = rxchan->device;

	/* Map only 1 entry */
	if (dma_map_sg(dma_dev->dev, &dmarx->sg, 1, DMA_FROM_DEVICE) != 1) {
		dev_err(&master->controller.dev, "unable to map TX DMA\n");
		return -EBUSY;
	}

	/* Only 1 mapped entry */
	desc = dmaengine_prep_slave_sg(rxchan, &dmarx->sg, 1,
		DMA_DEV_TO_MEM,
		DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!desc) {
		dma_unmap_sg(dma_dev->dev, &dmarx->sg, 1, DMA_FROM_DEVICE);
		dev_err(&master->controller.dev, "RX DMA busy\n");
		return -EBUSY;
	}

	/* Some data to go along to the callback */
	desc->callback = i3c_v200_dma_rx_callback;
	desc->callback_param = master;

	/* All errors should happen at prepare time */
	dmaengine_submit(desc);

	/* Fire the DMA transaction */
	dma_async_issue_pending(rxchan);

	return 0;
}

static int i3c_v200_dma_sg_init(struct i3c_v200_master *master,
	struct i3c_v200_dma_data *dma_data, unsigned long length)
{
	dma_data->buf = devm_kzalloc(&master->controller.dev, length, GFP_KERNEL);
	if (!dma_data->buf)
		return -ENOMEM;

	sg_init_one(&dma_data->sg, dma_data->buf, length);

	return 0;
}

static void i3c_v200_dma_clear(struct i3c_v200_master *master)
{
	if (master->dmatx.buf) {
		dmaengine_terminate_all(master->dmatx.chan);
		dma_unmap_sg(master->dmatx.chan->device->dev,
			&master->dmatx.sg, 1, DMA_TO_DEVICE);
		devm_kfree(&master->controller.dev, master->dmatx.buf);
		master->dmatx.buf = NULL;
		master->using_tx_dma = false;
	}

	if (master->dmarx.buf) {
		dmaengine_terminate_all(master->dmarx.chan);
		dma_unmap_sg(master->dmarx.chan->device->dev,
			&master->dmarx.sg, 1, DMA_FROM_DEVICE);
		devm_kfree(&master->controller.dev, master->dmarx.buf);
		master->dmarx.buf = NULL;
		master->using_rx_dma = false;
	}
}

static void i3c_v200_gen_dmatx_buf(u8 *dma_txbuf,
	struct i3c_v200_cmd *cmd)
{
	u32 i;

	for (i = 0; i < cmd->tx_len; i++)
		*dma_txbuf++ = *(u8 *)cmd->tx_buf++;
}

static int i3c_v200_xfer_dma_check_ctrl(struct i3c_v200_master *master)
{
	if (!master->dmatx.chan || !master->dmarx.chan)
		return -EPERM;

	return 0;
}

static void i3c_v200_dma_prepare_tx(struct i3c_v200_master *master,
	struct i3c_v200_cmd *cmd)
{
	int ret;

	ret = i3c_v200_xfer_dma_check_ctrl(master);
	if (ret) {
		dev_dbg(&master->controller.dev, "%s check i2c master device fail\n",
			__func__);
		return;
	}

	ret = i3c_v200_dma_sg_init(master, &master->dmatx, cmd->tx_len);
	if (ret < 0) {
		dev_err(&master->controller.dev, "Dma sg init failed. ret=%d\n", ret);
		return;
	}
	master->using_tx_dma = true;
	i3c_v200_gen_dmatx_buf(master->dmatx.buf, cmd);

	ret = i3c_v200_dma_tx_refill(master);
	if (ret < 0) {
		dev_err(&master->controller.dev, "Dma tx failed\n");
		return;
	}
}

static void i3c_v200_dma_prepare_rx(struct i3c_v200_master *master,
	struct i3c_v200_cmd *cmd)
{
	int ret;

	ret = i3c_v200_xfer_dma_check_ctrl(master);
	if (ret) {
		dev_err(&master->controller.dev, "%s check i2c master device fail\n",
			__func__);
		return;
	}

	ret = i3c_v200_dma_sg_init(master, &master->dmarx, cmd->rx_len);
	if (ret < 0) {
		dev_err(&master->controller.dev, "Dma sg init failed. ret=%d\n", ret);
		return;
	}

	master->using_rx_dma = true;

	ret = i3c_v200_dma_rx_trigger_dma(master);
	if (ret < 0) {
		dev_err(&master->controller.dev, "Dma rx failed\n");
		return;
	}
}

void i3c_v200_dma_start_xfer(struct i3c_v200_master *master)
{
	struct i3c_v200_xfer *xfer = master->xferqueue.cur;
	unsigned int i;

	if (!xfer)
		return;

	for (i = 0; i < xfer->ncmds; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		writel(cmd->cmd_hi, master->regs + I3C_V200_TRANSFER_CMD2);
		writel(cmd->cmd_lo, master->regs + I3C_V200_TRANSFER_CMD1);

		if ((cmd->tx_buf) && (cmd->tx_len))
			i3c_v200_dma_prepare_tx(master, cmd);

		if ((cmd->rx_buf) && (cmd->rx_len))
			i3c_v200_dma_prepare_rx(master, cmd);
	}
}

static int i3c_v200_dma_trans_state(struct i3c_v200_master *master)
{
	int state;
	int ret = 0;
	unsigned int resp;
	struct i3c_v200_xfer *xfer = master->xferqueue.cur;

	resp = readl(master->regs + I3C_V200_RESP_STATE);
	state = i3c_v200_resp_error(resp);

	switch (state) {
	case I3C_V200_RESP_NO_ERROR:
		break;
	case I3C_V200_RESP_BROADCAST_ERROR:
		ret = -I3C_V200_RESP_BROADCAST_ERROR;
		break;
	case I3C_V200_RESP_SLAVE_NACK:
		ret = -I3C_V200_RESP_SLAVE_NACK;
		break;
	case I3C_V200_RESP_I2C_WRITE_NACK:
		ret = -I3C_V200_RESP_I2C_WRITE_NACK;
		break;
	case I3C_V200_RESP_ENTDAA_NACK:
		ret = -I3C_V200_RESP_ENTDAA_NACK;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	xfer = list_first_entry_or_null(&master->xferqueue.list,
		struct i3c_v200_xfer, node);
	if (xfer)
		list_del_init(&xfer->node);

	master->xferqueue.cur = xfer;

	kfree(xfer);

	return ret;
}

int i3c_v200_i2c_dma_transfer(struct i3c_v200_master *master,
	const struct i2c_msg *i2c_xfers, int xfer_num,
	struct i3c_v200_i2c_dev_data *data)
{
	u32 i;
	struct i3c_v200_xfer *xfer = NULL;
	int ret = 0;

	if ((!i2c_xfers) || (!xfer_num))
		return -EINVAL;

	xfer = i3c_v200_alloc_xfer(master, xfer_num);
	if (!xfer)
		return -ENOMEM;

	/* mask intr */
	writel(0x0, master->regs + I3C_V200_INT_MASK);

	for (i = 0; i < xfer_num; i++) {
		struct i3c_v200_cmd *cmd = &xfer->cmds[i];

		cmd->cmd_hi = i3c_v200_data_len(i2c_xfers[i].len) |
			I3C_V200_TRANS_ARG | I3C_V200_DMA_EN;

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
		dev_err(&master->controller.dev, "%s timeout,resp stat 0x%x,trans stat 0x%x\n",
			__func__, readl(master->regs + I3C_V200_RESP_STATE),
			readl(master->regs + I3C_V200_TRANS_STATE));
		ret = -ETIMEDOUT;
		i3c_reset_controller(master);
		i3c_v200_master_dequeue_xfer(master, xfer);
		goto dma_trans_timeout;
	}

	ret = i3c_v200_dma_trans_state(master);

dma_trans_timeout:
	i3c_v200_dma_clear(master);

	return ret;
}
#else
void i3c_v200_dma_start_xfer(struct i3c_v200_master *master)
{
}

void i3c_v200_dma_probe_initcall(struct i3c_v200_master *master)
{
}

void i3c_v200_dma_remove(struct i3c_v200_master *master)
{
}

int i3c_v200_i2c_dma_transfer(struct i3c_v200_master *master,
	const struct i2c_msg *i2c_xfers, int xfer_num,
	struct i3c_v200_i2c_dev_data *data)
{
	return -EIO;
}
#endif

