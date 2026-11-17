/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: for hiphyio spi master.
 *
 */

#include <linux/err.h>
#include <linux/module.h>
#include <linux/clk.h>
#include <linux/device.h>
#include <linux/ioport.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/spi/spi.h>
#include <linux/hwspinlock.h>
#include <securec.h>
#include <linux/of_address.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/amba/bus.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/of_gpio.h>
#include <linux/pm_runtime.h>
#include <linux/scatterlist.h>
#ifdef CONFIG_HIPHYIO_SPI_FFA_SUPPORT
#include <platform_include/see/ffa/ffa_plat_drv.h>
#include <platform_include/see/ffa/ffa_msg_id.h>
#endif

#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
#include "hiphyio_spi.h"
#include "doze.h"

static int hiphyio_spi_runtime_suspend(struct device *dev);
static int hiphyio_spi_runtime_resume(struct device *dev);

static unsigned int g_hiphyio_state = 0;

static void hiphyio_state_cb(enum iodie_sys_status sys_st, enum iodie_err_status err_st)
{
	if (((sys_st == IODIE_ST_INITED) && (err_st == IODIE_ERR_SPI)) || ((sys_st == IODIE_ST_ERR) && (err_st == IODIE_ERR_HIPHY) || (err_st == IODIE_ERR_IODIE))) {
		g_hiphyio_state = 1;
		pr_err("iodie sys has err st %u, err st %u\n", (uint32_t)sys_st, (uint32_t)err_st);
	} else {
		g_hiphyio_state = 0;
	}
}

static void hiphyio_spi_cs0_set(struct hiphyio_spi_controller
	*spi_control, u32 command)
{
	if (command) {
		writel((BIT(spi_control->cs0_bit)) << 16 | (BIT(spi_control->cs0_bit)),
			spi_control->cs_reg_base + spi_control->cs0_offset);
	} else {
		writel((BIT(spi_control->cs0_bit)) << 16, spi_control->cs_reg_base + spi_control->cs0_offset);
	}
}

static void hiphyio_spi_cs2_set(struct hiphyio_spi_controller
	*spi_control, u32 command)
{
	if (command) {
		writel((BIT(spi_control->cs2_bit)) << 16 | (BIT(spi_control->cs2_bit)),
			spi_control->cs_reg_base + spi_control->cs2_offset);
	} else {
		writel((BIT(spi_control->cs2_bit)) << 16, spi_control->cs_reg_base + spi_control->cs2_offset);
	}
}

static void null_cs_control(u32 command)
{
	pr_debug("hiphyio_spi: dummy chip select control, CS=0x%x\n", command);
}

static void hiphyio_spi_cs_control(struct hiphyio_spi_controller
			*spi_control, u32 command)
{
	hiphyio_spi_cs0_set(spi_control, command);
}

static int hiphyio_spi_setup(struct hiphyio_spi_controller *spi_control)
{
	int ret = 0;
	u32 rate;
	struct chip_data *chip = spi_control->cur_chip;

	if (spi_control->hiphyio_spi_cr == chip->cr)
		return ret;

	spi_control->hiphyio_spi_cr = chip->cr;
	rate = clk_get_rate(spi_control->clk);
#ifdef CONFIG_HIPHYIO_SPI_FFA_SUPPORT
	struct ffa_send_direct_data args = {0};

	args.data0 = IODIE_HIPHYIO_SPI_FID;
	args.data1 = HIPHYIO_SPI_SETUP;
	args.data2 = spi_control->phybase;
	args.data3 = rate;
	args.data4 = chip->cr;
	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0)
		dev_err(&spi_control->pdev->dev, "%s failed to send_msg, ret:%d!\n", __func__, ret);
#endif
	return ret;
}

static void hiphyio_spi_pin_select(struct hiphyio_spi_controller *spi_control,
	u32 command)
{
#ifdef CONFIG_HIPHYIO_SPI_FFA_SUPPORT
	int ret;
	struct ffa_send_direct_data args = {0};

	args.data0 = IODIE_HIPHYIO_SPI_FID;
	args.data1 = HIPHYIO_SPI_PIN_SELECT;
	args.data2 = spi_control->phybase;
	args.data3 = command;
	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0)
		dev_err(&spi_control->pdev->dev, "%s failed, ret:%d!\n", __func__, ret);
#else
	UNUSED(spi_control);
#endif
}

static void giveback(struct hiphyio_spi_controller *spi_control)
{
	struct spi_transfer *last_transfer;

	spi_control->next_msg_cs_active = false;
	last_transfer = list_last_entry(&spi_control->cur_msg->transfers,
					struct spi_transfer, transfer_list);

	/* Delay if requested before any change in chip select */
	if (last_transfer->delay_usecs)
		udelay(last_transfer->delay_usecs);

	if (!last_transfer->cs_change) {
		struct spi_message *next_msg;
		next_msg = spi_get_next_queued_message(spi_control->master);
		if (next_msg && next_msg->spi != spi_control->cur_msg->spi)
			next_msg = NULL;
		if (!next_msg || spi_control->cur_msg->state == MSG_STATE_ERROR)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);
		else
			spi_control->next_msg_cs_active = true;
	}

	spi_control->cur_msg = NULL;
	spi_control->cur_transfer = NULL;
	spi_control->cur_chip = NULL;

	writel((readl(HIPHYIO_ENR(spi_control->virtbase)) &
		(~HIPHYIO_ENR_MASK_EN)), HIPHYIO_ENR(spi_control->virtbase));

	spi_finalize_current_message(spi_control->master);
}

static int flush(struct hiphyio_spi_controller *spi_control)
{
	unsigned long limit = loops_per_jiffy << 1;

	dev_dbg(&spi_control->pdev->dev, "%s\n", __func__);
	do {
		while (readl(HIPHYIO_SR(spi_control->virtbase)) & HIPHYIO_SR_MASK_RNE)
			readl(HIPHYIO_DOUT(spi_control->virtbase));
	} while ((readl(HIPHYIO_SR(spi_control->virtbase)) & HIPHYIO_SR_MASK_BSY)
			&& limit--);

	spi_control->exp_fifo_level = 0;

	return limit;
}

static void restore_state(struct hiphyio_spi_controller *spi_control)
{
	struct chip_data *chip = spi_control->cur_chip;

	writel(chip->csr, HIPHYIO_CSCR(spi_control->virtbase));
	writel(chip->cr, HIPHYIO_COMMONCR(spi_control->virtbase));
	writel(chip->enr, HIPHYIO_ENR(spi_control->virtbase));

	writel(DEFAULT_HIPHYIO_REG_FIFOCR_V600, HIPHYIO_FIFOCR(spi_control->virtbase));
	writel(DISABLE_ALL_INTERRUPTS_V600, HIPHYIO_IMC(spi_control->virtbase));
	writel(CLEAR_ALL_INTERRUPTS_V600, HIPHYIO_ICR(spi_control->virtbase));
}

static void load_hiphyio_default_config(struct hiphyio_spi_controller *spi_control)
{
	writel(DEFAULT_HIPHYIO_REG_CSCR, HIPHYIO_CSCR(spi_control->virtbase));
	writel(DEFAULT_HIPHYIO_REG_COMMONCR, HIPHYIO_COMMONCR(spi_control->virtbase));
	writel(DEFAULT_HIPHYIO_REG_ENR, HIPHYIO_ENR(spi_control->virtbase));
	writel(DISABLE_ALL_INTERRUPTS_V600, HIPHYIO_IMC(spi_control->virtbase));
	writel(CLEAR_ALL_INTERRUPTS_V600, HIPHYIO_ICR(spi_control->virtbase));
}

static void hiphyio_spi_read_rx(struct hiphyio_spi_controller *spi_control)
{
	while ((readl(HIPHYIO_SR(spi_control->virtbase)) & HIPHYIO_SR_MASK_RNE)
	       && (spi_control->rx < spi_control->rx_end)) {
		switch (spi_control->read) {
		case READING_NULL:
			readl(HIPHYIO_DOUT(spi_control->virtbase));
			break;
		case READING_U8:
			*(u8 *) (spi_control->rx) =
				readl(HIPHYIO_DOUT(spi_control->virtbase)) & 0xFFU;
			break;
		case READING_U16:
			*(u16 *) (spi_control->rx) =
				(u16) readl(HIPHYIO_DOUT(spi_control->virtbase));
			break;
		case READING_U32:
			*(u32 *) (spi_control->rx) =
				readl(HIPHYIO_DOUT(spi_control->virtbase));
			break;
		}
		spi_control->rx += (spi_control->cur_chip->n_bytes);
		spi_control->exp_fifo_level--;
	}
}

static void hiphyio_spi_write_tx(struct hiphyio_spi_controller *spi_control)
{
	while ((spi_control->exp_fifo_level < FIFO_DEPTH)
	       && (spi_control->tx < spi_control->tx_end)) {
		switch (spi_control->write) {
		case WRITING_NULL:
			writel(0x0, HIPHYIO_DIN(spi_control->virtbase));
			break;
		case WRITING_U8:
			writel(*(u8 *) (spi_control->tx),
				HIPHYIO_DIN(spi_control->virtbase));
			break;
		case WRITING_U16:
			writel((*(u16 *) (spi_control->tx)),
				HIPHYIO_DIN(spi_control->virtbase));
			break;
		case WRITING_U32:
			writel(*(u32 *) (spi_control->tx),
				HIPHYIO_DIN(spi_control->virtbase));
			break;
		}
		spi_control->tx += (spi_control->cur_chip->n_bytes);
		spi_control->exp_fifo_level++;
		hiphyio_spi_read_rx(spi_control);
	}
}

static void readwriter(struct hiphyio_spi_controller *spi_control)
{
	dev_dbg(&spi_control->pdev->dev,
		"%s, rx: %pK, rxend: %pK, tx: %pK, txend: %pK\n",
		__func__, spi_control->rx, spi_control->rx_end,
		spi_control->tx, spi_control->tx_end);

	/* Read as much as you can */
	hiphyio_spi_read_rx(spi_control);
	/* Write as much as possible up to the RX FIFO size */
	hiphyio_spi_write_tx(spi_control);
}

static void *next_transfer(struct hiphyio_spi_controller *spi_control)
{
	struct spi_message *msg = spi_control->cur_msg;
	struct spi_transfer *trans = spi_control->cur_transfer;

	/* Move to next transfer */
	if (trans->transfer_list.next != &msg->transfers) {
		spi_control->cur_transfer =
		    list_entry(trans->transfer_list.next,
			       struct spi_transfer, transfer_list);
		return MSG_STATE_RUNNING;
	}
	return MSG_STATE_DONE;
}

static void unmap_free_dma_scatter(struct hiphyio_spi_controller *spi_control)
{
	/* Unmap and free the SG tables */
	dma_unmap_sg(spi_control->dma_tx_channel->device->dev,
		spi_control->sgt_tx.sgl,
		spi_control->sgt_tx.nents, DMA_TO_DEVICE);
	dma_unmap_sg(spi_control->dma_rx_channel->device->dev,
		spi_control->sgt_rx.sgl,
		spi_control->sgt_rx.nents, DMA_FROM_DEVICE);
	sg_free_table(&spi_control->sgt_rx);
	sg_free_table(&spi_control->sgt_tx);
}

static void spi_iodie_pre_cfg(struct hiphyio_spi_controller *spi_ctrl,
	u32 *irq_msk_st, u32 *comm_cr)
{
	/* disable SPI */
	writel((readl(HIPHYIO_ENR(spi_ctrl->virtbase)) &
		(~HIPHYIO_ENR_MASK_EN)), HIPHYIO_ENR(spi_ctrl->virtbase));

	*irq_msk_st = readl(HIPHYIO_IMC(spi_ctrl->virtbase));
	*comm_cr = readl(HIPHYIO_COMMONCR(spi_ctrl->virtbase));

	writel(DISABLE_ALL_INTERRUPTS_V600, HIPHYIO_IMC(spi_ctrl->virtbase));

	writel((readl(HIPHYIO_COMMONCR(spi_ctrl->virtbase)) & (~(BIT(26) | BIT(27)))),
			HIPHYIO_COMMONCR(spi_ctrl->virtbase));

	/* enbale SPI */
	writel((readl(HIPHYIO_ENR(spi_ctrl->virtbase)) |
		HIPHYIO_ENR_MASK_EN), HIPHYIO_ENR(spi_ctrl->virtbase));
}

static void spi_iodie_post_cfg(struct hiphyio_spi_controller *spi_ctrl,
	u32 irq_msk_st, u32 comm_cr)
{
	/* disable SPI */
	writel((readl(HIPHYIO_ENR(spi_ctrl->virtbase)) &
		(~HIPHYIO_ENR_MASK_EN)), HIPHYIO_ENR(spi_ctrl->virtbase));

	writel(irq_msk_st, HIPHYIO_IMC(spi_ctrl->virtbase));
	writel(comm_cr, HIPHYIO_COMMONCR(spi_ctrl->virtbase));

	/* enbale SPI */
	writel((readl(HIPHYIO_ENR(spi_ctrl->virtbase)) |
		HIPHYIO_ENR_MASK_EN), HIPHYIO_ENR(spi_ctrl->virtbase));
}

static void spi_proc_iodie(struct hiphyio_spi_controller *spi_ctrl)
{
	u32 irq_msk_st;
	u32 comm_cr;
	int ret;
	struct spi_transfer *xfer = spi_ctrl->cur_transfer;
	u8 temp_rx[DUMMY_MAX] = {0};
	u8 temp_tx[DUMMY_MAX] = {0};
	unsigned long time, timeout;

	if (!xfer->rx_buf)
		return;

	if (readl(HIPHYIO_COMMONCR(spi_ctrl->virtbase)) & HIPHYIO_COMMONCR_LOOPBACK)
		return;

	spi_ctrl->tx = (void*)temp_tx;
	spi_ctrl->tx_end = spi_ctrl->tx + spi_ctrl->iodie_dummy;
	spi_ctrl->write = WRITING_NULL;

	spi_ctrl->rx = (void*)temp_rx;
	spi_ctrl->rx_end = spi_ctrl->rx + spi_ctrl->iodie_dummy;

	spi_iodie_pre_cfg(spi_ctrl, &irq_msk_st, &comm_cr);

	hiphyio_spi_cs2_set(spi_ctrl, HIPHYIO_CHIP_SELECT);

	udelay(10);
	timeout = jiffies + msecs_to_jiffies(SPI_POLLING_TIMEOUT);
	while (spi_ctrl->tx < spi_ctrl->tx_end || spi_ctrl->rx < spi_ctrl->rx_end) {
		time = jiffies;
		readwriter(spi_ctrl);
		if (time_after(time, timeout)) {
			dev_err(&spi_ctrl->pdev->dev,"%s: timeout!\n", __func__);
			break;
		}
	}

	hiphyio_spi_cs2_set(spi_ctrl, HIPHYIO_CHIP_DESELECT);

	/* buf len > dummy */
	if (xfer->len > spi_ctrl->iodie_dummy) {
		ret = memmove_s(xfer->rx_buf, xfer->len - spi_ctrl->iodie_dummy,
			xfer->rx_buf + spi_ctrl->iodie_dummy, xfer->len - spi_ctrl->iodie_dummy);
		if (ret != EOK)
			dev_err(&spi_ctrl->pdev->dev, "%s: memmove_s failed, ret is %d\n", __func__, ret);
		ret = memcpy_s(xfer->rx_buf + xfer->len - spi_ctrl->iodie_dummy, spi_ctrl->iodie_dummy,
			temp_rx, spi_ctrl->iodie_dummy);
		if (ret != EOK)
			dev_err(&spi_ctrl->pdev->dev, "%s: memcpy_s failed, ret is %d\n", __func__, ret);
	} else {
		ret = memcpy_s(xfer->rx_buf, xfer->len, temp_rx + spi_ctrl->iodie_dummy - xfer->len,
			xfer->len);
		if (ret != EOK)
			dev_err(&spi_ctrl->pdev->dev, "%s: memcpy_s failed, ret is %d\n", __func__, ret);
	}

	spi_iodie_post_cfg(spi_ctrl, irq_msk_st, comm_cr);
}

static void dma_callback(void *data)
{
	struct hiphyio_spi_controller *spi_control = data;
	struct spi_message *msg = spi_control->cur_msg;

	spin_lock(&spi_control->lock);
	if (!msg || !msg->context) {
		dev_err(&spi_control->pdev->dev, "msg is invalid\n");
		spin_unlock(&spi_control->lock);
		return;
	}
	if (!spi_control->sgt_rx.sgl) {
		dev_err(&spi_control->pdev->dev, "sgt_rx.sgl invalid\n");
		spin_unlock(&spi_control->lock);
		return;
	}

	unmap_free_dma_scatter(spi_control);

	/* Update total bytes transferred */
	msg->actual_length += spi_control->cur_transfer->len;

	spi_proc_iodie(spi_control);

	if (spi_control->cur_transfer->cs_change)
		hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

	/* Move to next transfer */
	msg->state = next_transfer(spi_control);
	if (msg->state != MSG_STATE_DONE && spi_control->cur_transfer->cs_change)
		hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

	tasklet_schedule(&spi_control->pump_transfers);
	spin_unlock(&spi_control->lock);
}

static void setup_dma_scatter(struct hiphyio_spi_controller *spi_control,
	void *buffer, unsigned int length, struct sg_table *sgtab)
{
	struct scatterlist *sg = NULL;
	unsigned int bytesleft = length;
	void *bufp = buffer;
	int mapbytes;
	u32 i = 0;

	if (buffer) {
		for_each_sg(sgtab->sgl, sg, sgtab->nents, i) {
			if (bytesleft < (PAGE_SIZE - offset_in_page(bufp)))
				mapbytes = bytesleft;
			else
				mapbytes = PAGE_SIZE - offset_in_page(bufp);
			sg_set_page(sg, virt_to_page(bufp),
				    mapbytes, offset_in_page(bufp));
			bufp += mapbytes;
			bytesleft -= mapbytes;
		}
	} else {
		for_each_sg(sgtab->sgl, sg, sgtab->nents, i) {
			if (bytesleft < PAGE_SIZE)
				mapbytes = bytesleft;
			else
				mapbytes = PAGE_SIZE;
			sg_set_page(sg, virt_to_page(spi_control->dummypage),
				    mapbytes, 0);
			bytesleft -= mapbytes;
		}
	}
	BUG_ON(bytesleft);
}

static void config_dma_fifo_level(struct hiphyio_spi_controller *spi_control,
	struct dma_slave_config *rx_conf, struct dma_slave_config *tx_conf)
{
	switch (spi_control->rx_lev_trig) {
	case HIPHYIO_RX_1_OR_MORE_ELEM:
		rx_conf->src_maxburst = MAX_BURST_1;
		break;
	case HIPHYIO_RX_4_OR_MORE_ELEM:
		rx_conf->src_maxburst = MAX_BURST_4;
		break;
	case HIPHYIO_RX_8_OR_MORE_ELEM:
		rx_conf->src_maxburst = MAX_BURST_8;
		break;
	case HIPHYIO_RX_16_OR_MORE_ELEM:
		rx_conf->src_maxburst = MAX_BURST_16;
		break;
	case HIPHYIO_RX_32_OR_MORE_ELEM:
		rx_conf->src_maxburst = MAX_BURST_32;
		break;
	default:
		rx_conf->src_maxburst = FIFO_DEPTH >> 1;
		break;
	}

	switch (spi_control->tx_lev_trig) {
	case HIPHYIO_TX_1_OR_MORE_EMPTY_LOC:
		tx_conf->dst_maxburst = MAX_BURST_1;
		break;
	case HIPHYIO_TX_4_OR_MORE_EMPTY_LOC:
		tx_conf->dst_maxburst = MAX_BURST_4;
		break;
	case HIPHYIO_TX_8_OR_MORE_EMPTY_LOC:
		tx_conf->dst_maxburst = MAX_BURST_8;
		break;
	case HIPHYIO_TX_16_OR_MORE_EMPTY_LOC:
		tx_conf->dst_maxburst = MAX_BURST_16;
		break;
	case HIPHYIO_TX_32_OR_MORE_EMPTY_LOC:
		tx_conf->dst_maxburst = MAX_BURST_32;
		break;
	default:
		tx_conf->dst_maxburst = FIFO_DEPTH >> 1;
		break;
	}
}

static void config_dma_bus_width(struct hiphyio_spi_controller *spi_control,
	struct dma_slave_config *rx_conf, struct dma_slave_config *tx_conf)
{
	switch (spi_control->read) {
	case READING_NULL:
		/* Use the same as for writing */
		rx_conf->src_addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
		break;
	case READING_U8:
		rx_conf->src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
		break;
	case READING_U16:
		rx_conf->src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
		break;
	case READING_U32:
		rx_conf->src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
		break;
	}

	switch (spi_control->write) {
	case WRITING_NULL:
		/* Use the same as for reading */
		tx_conf->dst_addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
		break;
	case WRITING_U8:
		tx_conf->dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
		break;
	case WRITING_U16:
		tx_conf->dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
		break;
	case WRITING_U32:
		tx_conf->dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
		break;
	}

	/* SPI pecularity: we need to read and write the same width */
	if (rx_conf->src_addr_width == DMA_SLAVE_BUSWIDTH_UNDEFINED)
		rx_conf->src_addr_width = tx_conf->dst_addr_width;
	if (tx_conf->dst_addr_width == DMA_SLAVE_BUSWIDTH_UNDEFINED)
		tx_conf->dst_addr_width = rx_conf->src_addr_width;
	BUG_ON(rx_conf->src_addr_width != tx_conf->dst_addr_width);
}

static int spi_dma_sgl_config(struct hiphyio_spi_controller *spi_control,
	int *rx_sglen, int *tx_sglen)
{
	int ret;
	unsigned int pages, txpages, rxpages;
	struct dma_chan *rxchan = spi_control->dma_rx_channel;
	struct dma_chan *txchan = spi_control->dma_tx_channel;

	/* Create sglists for the transfers */
	pages = DIV_ROUND_UP(spi_control->cur_transfer->len, PAGE_SIZE);

	rxpages = pages;
	txpages = pages;
	spi_control->transfer_len = spi_control->cur_transfer->len;
	if (spi_control->cur_transfer->len >
		(pages * PAGE_SIZE -
			offset_in_page(
			(unsigned long)(uintptr_t)spi_control->rx)))
		rxpages++;

	if (spi_control->cur_transfer->len >
		(pages * PAGE_SIZE -
			offset_in_page(
			(unsigned long)(uintptr_t)spi_control->tx)))
		txpages++;

	ret = sg_alloc_table(&spi_control->sgt_rx, rxpages, GFP_ATOMIC);
	if (ret)
		goto err_alloc_rx_sg;

	ret = sg_alloc_table(&spi_control->sgt_tx, txpages, GFP_ATOMIC);
	if (ret)
		goto err_alloc_tx_sg;

	/* Fill in the scatterlists for the RX+TX buffers */
	setup_dma_scatter(spi_control, spi_control->rx,
		spi_control->cur_transfer->len, &spi_control->sgt_rx);
	setup_dma_scatter(spi_control, spi_control->tx,
		spi_control->cur_transfer->len, &spi_control->sgt_tx);

	/* Map DMA buffers */
	*rx_sglen = dma_map_sg(rxchan->device->dev, spi_control->sgt_rx.sgl,
		spi_control->sgt_rx.nents, DMA_FROM_DEVICE);
	if (!(*rx_sglen))
		goto err_rx_sgmap;

	*tx_sglen = dma_map_sg(txchan->device->dev, spi_control->sgt_tx.sgl,
		spi_control->sgt_tx.nents, DMA_TO_DEVICE);
	if (!(*tx_sglen))
		goto err_tx_sgmap;

	return ret;

err_tx_sgmap:
	dma_unmap_sg(rxchan->device->dev, spi_control->sgt_rx.sgl,
		spi_control->sgt_rx.nents, DMA_FROM_DEVICE);
err_rx_sgmap:
	sg_free_table(&spi_control->sgt_tx);
err_alloc_tx_sg:
	sg_free_table(&spi_control->sgt_rx);
err_alloc_rx_sg:
	return -ENOMEM;
}

/*
 * configure_dma - configures the channels for the next transfer
 * @hiphyio_spi: HIPHYIO driver's private data structure
 */
static int configure_dma(struct hiphyio_spi_controller *spi_control)
{
	struct dma_slave_config rx_conf = {
		.src_addr = HIPHYIO_DOUT(spi_control->phybase),
		.direction = DMA_DEV_TO_MEM,
		.device_fc = false,
	};
	struct dma_slave_config tx_conf = {
		.dst_addr = HIPHYIO_DIN(spi_control->phybase),
		.direction = DMA_MEM_TO_DEV,
		.device_fc = false,
	};

	int ret;
	int rx_sglen, tx_sglen;
	struct dma_chan *rxchan = spi_control->dma_rx_channel;
	struct dma_chan *txchan = spi_control->dma_tx_channel;
	struct dma_async_tx_descriptor *rxdesc = NULL;
	struct dma_async_tx_descriptor *txdesc = NULL;

	/* Check that the channels are available */
	if (!rxchan || !txchan)
		return -ENODEV;

	config_dma_fifo_level(spi_control, &rx_conf, &tx_conf);
	config_dma_bus_width(spi_control, &rx_conf, &tx_conf);

	dmaengine_slave_config(rxchan, &rx_conf);
	dmaengine_slave_config(txchan, &tx_conf);

	ret = spi_dma_sgl_config(spi_control, &rx_sglen, &tx_sglen);
	if (ret)
		return -ENOMEM;

	/* Send both scatterlists */
	rxdesc = dmaengine_prep_slave_sg(rxchan,
		spi_control->sgt_rx.sgl,
		rx_sglen,
		DMA_DEV_TO_MEM,
		DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!rxdesc)
		goto err_rxdesc;

	txdesc = dmaengine_prep_slave_sg(txchan,
		spi_control->sgt_tx.sgl,
		tx_sglen,
		DMA_MEM_TO_DEV,
		DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!txdesc)
		goto err_txdesc;

	/* Put the callback on the RX transfer only, that should finish last */
	rxdesc->callback = dma_callback;
	rxdesc->callback_param = spi_control;
	/* Submit and fire RX and TX with TX last so we're ready to read! */
	dmaengine_submit(rxdesc);
	dmaengine_submit(txdesc);
	dma_async_issue_pending(rxchan);
	dma_async_issue_pending(txchan);
	spi_control->dma_running = true;

	return 0;

err_txdesc:
	dmaengine_terminate_all(txchan);
err_rxdesc:
	dmaengine_terminate_all(rxchan);
	dma_unmap_sg(txchan->device->dev, spi_control->sgt_tx.sgl,
			spi_control->sgt_tx.nents, DMA_TO_DEVICE);
	return -ENOMEM;
}

static int hiphyio_spi_dma_probe(struct hiphyio_spi_controller *spi_control)
{
	dma_cap_mask_t mask;

	dma_cap_zero(mask);
	dma_cap_set(DMA_SLAVE, mask);

	spi_control->dma_rx_channel = dma_request_channel(mask,
		spi_control->pdata->dma_filter,
		spi_control->pdata->dma_rx_param);
	if (!spi_control->dma_rx_channel) {
		dev_dbg(&spi_control->pdev->dev, "no RX DMA channel!\n");
		goto err_no_rxchan;
	}

	spi_control->dma_tx_channel = dma_request_channel(mask,
						spi_control->pdata->dma_filter,
						spi_control->pdata->dma_tx_param);
	if (!spi_control->dma_tx_channel) {
		dev_dbg(&spi_control->pdev->dev, "no TX DMA channel!\n");
		goto err_no_txchan;
	}

	spi_control->dummypage = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!spi_control->dummypage)
		goto err_no_dummypage;

	dev_info(&spi_control->pdev->dev, "setup for DMA on RX %s, TX %s\n",
		 dma_chan_name(spi_control->dma_rx_channel),
		 dma_chan_name(spi_control->dma_tx_channel));

	return 0;

err_no_dummypage:
	dma_release_channel(spi_control->dma_tx_channel);
err_no_txchan:
	dma_release_channel(spi_control->dma_rx_channel);
	spi_control->dma_rx_channel = NULL;
err_no_rxchan:
	dev_err(&spi_control->pdev->dev,
		"Failed to work in dma mode, work without dma!\n");
	return -ENODEV;
}

static int hiphyio_spi_dma_autoprobe(struct hiphyio_spi_controller *spi_control)
{
	struct device *dev = &spi_control->pdev->dev;
	struct dma_chan *chan;
	int err;

	chan = dma_request_chan(dev, "rx");
	if (IS_ERR(chan)) {
		err = PTR_ERR(chan);
		goto err_no_rxchan;
	}

	dev_err(dev, "spi DMA channel RX %s\n",
		dma_chan_name(chan));

	spi_control->dma_rx_channel = chan;

	chan = dma_request_chan(dev, "tx");
	if (IS_ERR(chan)) {
		err = PTR_ERR(chan);
		goto err_no_txchan;
	}
	dev_err(dev, "spi DMA channel TX %s\n",
		dma_chan_name(chan));

	spi_control->dma_tx_channel = chan;

	spi_control->dummypage = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (!spi_control->dummypage) {
		err = -ENOMEM;
		goto err_no_dummypage;
	}

	return 0;

err_no_dummypage:
	dma_release_channel(spi_control->dma_tx_channel);
	spi_control->dma_tx_channel = NULL;
err_no_txchan:
	dma_release_channel(spi_control->dma_rx_channel);
	spi_control->dma_rx_channel = NULL;
err_no_rxchan:
	return err;
}

static void terminate_dma(struct hiphyio_spi_controller *spi_control)
{
	struct dma_chan *rxchan = spi_control->dma_rx_channel;
	struct dma_chan *txchan = spi_control->dma_tx_channel;

	dmaengine_terminate_all(rxchan);
	dmaengine_terminate_all(txchan);
	unmap_free_dma_scatter(spi_control);
	spi_control->dma_running = false;
}

static void hiphyio_spi_dma_remove(struct hiphyio_spi_controller *spi_control)
{
	if (spi_control->dma_running)
		terminate_dma(spi_control);
	if (spi_control->dma_tx_channel)
		dma_release_channel(spi_control->dma_tx_channel);
	if (spi_control->dma_rx_channel)
		dma_release_channel(spi_control->dma_rx_channel);
	kfree(spi_control->dummypage);
	spi_control->dummypage = NULL;
}

static void hiphyio_spi_fifo_overrun(struct hiphyio_spi_controller *spi_control)
{
	struct spi_message *msg = spi_control->cur_msg;

	if (readl(HIPHYIO_SR(spi_control->virtbase)) & HIPHYIO_SR_MASK_RFF)
		dev_err(&spi_control->pdev->dev,
			"RXFIFO is full\n");
	if (spi_control->cur_chip->enable_dma) {
		dmaengine_terminate_all(spi_control->dma_rx_channel);
		dmaengine_terminate_all(spi_control->dma_tx_channel);
	}

	writel(DISABLE_ALL_INTERRUPTS_V600, HIPHYIO_IMC(spi_control->virtbase));
	writel(CLEAR_ALL_INTERRUPTS_V600, HIPHYIO_ICR(spi_control->virtbase));
	writel((readl(HIPHYIO_ENR(spi_control->virtbase)) &
		(~HIPHYIO_ENR_MASK_EN)), HIPHYIO_ENR(spi_control->virtbase));
	msg->state = MSG_STATE_ERROR;

	tasklet_schedule(&spi_control->pump_transfers);
}

static void hiphyio_proc_exclusive_dma_irq(struct hiphyio_spi_controller *spi_control, u32 irq_status)
{
	struct spi_transfer *xfer = spi_control->cur_transfer;
	struct spi_message *msg = spi_control->cur_msg;

	/* clear irq */
	writel(irq_status, INTR_SPI_DMA_CLR(spi_control->virtbase));
	/* mask  all irq */
	writel(EXCLUSIVE_DMA_ALL_INT, INTR_SPI_DMA_MASK(spi_control->virtbase));
	/* stop dma */
	writel(0, HIPHYIO_DMA_CTRL(spi_control->virtbase));

	__dma_unmap_area(xfer->rx_buf, xfer->len, DMA_FROM_DEVICE);
	__dma_unmap_area(xfer->tx_buf, xfer->len, DMA_TO_DEVICE);
	if (irq_status & INT_DMA_COMPLETE) {
		msg->actual_length += spi_control->cur_transfer->len;
		spi_proc_iodie(spi_control);

		if (spi_control->cur_transfer->cs_change)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

		/* Move to next transfer */
		msg->state = next_transfer(spi_control);
		if (msg->state != MSG_STATE_DONE && spi_control->cur_transfer->cs_change)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

		tasklet_schedule(&spi_control->pump_transfers);
	} else {
		if (spi_control->cur_transfer->cs_change)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

		msg->state = MSG_STATE_ERROR;
		tasklet_schedule(&spi_control->pump_transfers);
		pr_err("spi transfer error irq 0x%x\n", irq_status);
	}
}

static irqreturn_t hiphyio_spi_interrupt_handler(int irq, void *dev_id)
{
	struct hiphyio_spi_controller *spi_control = dev_id;
	struct spi_message *msg = spi_control->cur_msg;
	u16 irq_status = 0;

	if (unlikely(!msg)) {
		dev_err(&spi_control->pdev->dev,
			"bad message state in interrupt handler");
		/* Never fail */
		return IRQ_HANDLED;
	}
	irq_status = readl(INTR_SPI_DMA_RAW(spi_control->virtbase));
	if (irq_status) {
		complete(&spi_control->dma_complete);
		hiphyio_proc_exclusive_dma_irq(spi_control, irq_status);
		return IRQ_HANDLED;
	}

	/* Read the Interrupt Status Register */
	irq_status = readl(HIPHYIO_MIS(spi_control->virtbase));
	if (unlikely(!irq_status))
		return IRQ_NONE;

	if (unlikely(irq_status & HIPHYIO_MIS_MASK_RORMIS)) {
		dev_err(&spi_control->pdev->dev, "FIFO overrun\n");
		hiphyio_spi_fifo_overrun(spi_control);
		return IRQ_HANDLED;
	}

	readwriter(spi_control);

	if (spi_control->tx == spi_control->tx_end)
		/* Disable Transmit interrupt, enable receive interrupt */
		writel((readl(HIPHYIO_IMC(spi_control->virtbase)) &
		       ~HIPHYIO_IMC_MASK_RXIM) | HIPHYIO_IMC_MASK_TXIM,
		       HIPHYIO_IMC(spi_control->virtbase));

	if (spi_control->rx >= spi_control->rx_end) {
		writel(DISABLE_ALL_INTERRUPTS_V600, HIPHYIO_IMC(spi_control->virtbase));
		writel(CLEAR_ALL_INTERRUPTS_V600, HIPHYIO_ICR(spi_control->virtbase));

		if (unlikely(spi_control->rx > spi_control->rx_end))
			dev_warn(&spi_control->pdev->dev, "read %u surplus "
				 "bytes (did you request an odd "
				 "number of bytes on a 16bit bus?)\n",
				 (u32) (spi_control->rx - spi_control->rx_end));

		/* Update total bytes transferred */
		msg->actual_length += spi_control->cur_transfer->len;

		spi_proc_iodie(spi_control);

		if (spi_control->cur_transfer->cs_change)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

		/* Move to next transfer */
		msg->state = next_transfer(spi_control);

		tasklet_schedule(&spi_control->pump_transfers);
		return IRQ_HANDLED;
	}

	return IRQ_HANDLED;
}

static int set_up_next_transfer(struct hiphyio_spi_controller *spi_control,
				struct spi_transfer *transfer)
{
	int residue;

	/* Sanity check the message for this bus width */
	residue = spi_control->cur_transfer->len %
		spi_control->cur_chip->n_bytes;
	if (unlikely(residue != 0)) {
		dev_err(&spi_control->pdev->dev,
			"message of %u bytes to transmit but the current "
			"chip bus has a data width of %u bytes!\n",
			spi_control->cur_transfer->len,
			spi_control->cur_chip->n_bytes);
		dev_err(&spi_control->pdev->dev, "skipping this message\n");
		return -EIO;
	}

	spi_control->tx = (void *)transfer->tx_buf;
	spi_control->tx_end = spi_control->tx +
		spi_control->cur_transfer->len;
	spi_control->rx = (void *)transfer->rx_buf;
	spi_control->rx_end = spi_control->rx +
		spi_control->cur_transfer->len;

	spi_control->write =
		spi_control->tx ? spi_control->cur_chip->write : WRITING_NULL;
	spi_control->read = spi_control->rx ?
		spi_control->cur_chip->read : READING_NULL;
	return 0;
}

static void hiphyio_spi_config_dma_addr(struct hiphyio_spi_controller *spi_control,
		struct spi_transfer *xfer)
{
	writel((u32)(xfer->tx_dma & SPI_32BITS_MASK), HIPHYIO_SDMA_ADDR_L_R(spi_control->virtbase));
	writel((u32)(xfer->tx_dma >> 32), HIPHYIO_SDMA_ADDR_H_R(spi_control->virtbase));

	writel((u32)(xfer->rx_dma & SPI_32BITS_MASK), HIPHYIO_SDMA_ADDR_L_W(spi_control->virtbase));
	writel((u32)(xfer->rx_dma >> 32), HIPHYIO_SDMA_ADDR_H_W(spi_control->virtbase));
}

static void config_exclusive_dma(struct spi_master *master)
{
	struct hiphyio_spi_controller *spi_control = spi_master_get_devdata(master);
	struct spi_transfer *xfer = NULL;

	xfer = spi_control->cur_transfer;

	/* mask  all irq */
	writel(EXCLUSIVE_DMA_ALL_INT, INTR_SPI_DMA_MASK(spi_control->virtbase));

	/* enable sdma */
	writel(DMA_ENBALE_APB | spi_control->cur_transfer->len, HIPHYIO_DMA_CTRL(spi_control->virtbase));

	xfer->rx_dma = virt_to_phys(xfer->rx_buf);
	__dma_map_area(xfer->rx_buf, xfer->len, DMA_FROM_DEVICE);

	xfer->tx_dma = virt_to_phys(xfer->tx_buf);
	__dma_map_area(xfer->tx_buf, xfer->len, DMA_TO_DEVICE);

	hiphyio_spi_config_dma_addr(spi_control, xfer);

	/* enable all irq */
	writel(0, INTR_SPI_DMA_MASK(spi_control->virtbase));

	writel((readl(HIPHYIO_ENR(spi_control->virtbase)) | HIPHYIO_ENR_MASK_EN), HIPHYIO_ENR(spi_control->virtbase));

	writel(DMA_CMD_START, HIPHYIO_DMA_CMD_START(spi_control->virtbase));
}

static void pump_transfers(unsigned long data)
{
	struct hiphyio_spi_controller *spi_control =
		(struct hiphyio_spi_controller *) (uintptr_t)data;
	struct spi_message *message = NULL;
	struct spi_transfer *transfer = NULL;
	struct spi_transfer *previous = NULL;

	/* Get current state information */
	message = spi_control->cur_msg;
	transfer = spi_control->cur_transfer;

	if (!message || !transfer) {
		dev_err(&spi_control->pdev->dev, "msg or transfer invalid\n");
		return;
	}

	/* Handle for abort */
	if (message->state == MSG_STATE_ERROR) {
		message->status = -EIO;
		giveback(spi_control);
		return;
	}

	/* Handle end of message */
	if (message->state == MSG_STATE_DONE) {
		message->status = 0;
		flush(spi_control);
		giveback(spi_control);
		return;
	}

	/* Delay if requested at end of transfer before CS change */
	if (message->state == MSG_STATE_RUNNING) {
		previous = list_entry(transfer->transfer_list.prev,
					struct spi_transfer,
					transfer_list);
		if (previous->delay_usecs)
			udelay(previous->delay_usecs);

		/* Reselect chip select only if cs_change was requested */
		if (previous->cs_change)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_SELECT);
	} else {
		message->state = MSG_STATE_RUNNING;
	}

	if (set_up_next_transfer(spi_control, transfer)) {
		message->state = MSG_STATE_ERROR;
		message->status = -EIO;
		giveback(spi_control);
		return;
	}
	/* Flush the FIFOs and let's go! */
	flush(spi_control);
	if (spi_control->cur_chip->xfer_type == EXCLUSIVE_DMA_TRANSFER) {
		config_exclusive_dma(spi_control->master);
		return;
	}

	if (spi_control->cur_chip->enable_dma) {
		if (configure_dma(spi_control)) {
			dev_dbg(&spi_control->pdev->dev,
				"configuration of DMA failed, fall back to interrupt mode\n");
			goto err_config_dma;
		}
		return;
	}

err_config_dma:
	/* enable all interrupts except RX */
	writel(ENABLE_ALL_INTERRUPTS | HIPHYIO_IMC_MASK_RXIM,
		HIPHYIO_IMC(spi_control->virtbase));
}

static void do_interrupt_dma_transfer(struct hiphyio_spi_controller *spi_control)
{
	u32 irqflags = (u32)(ENABLE_ALL_INTERRUPTS | HIPHYIO_IMC_MASK_RXIM);
	/* Enable target chip, if not already active */
	if (!spi_control->next_msg_cs_active)
		hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_SELECT);

	if (set_up_next_transfer(spi_control, spi_control->cur_transfer)) {
		/* Error path */
		spi_control->cur_msg->state = MSG_STATE_ERROR;
		spi_control->cur_msg->status = -EIO;
		giveback(spi_control);
		return;
	}
	/* If we're using DMA, set up DMA here */
	if (spi_control->cur_chip->enable_dma) {
		/* Configure DMA transfer */
		if (configure_dma(spi_control)) {
			dev_dbg(&spi_control->pdev->dev,
				"configuration of DMA failed, fall back to interrupt mode\n");
			goto err_config_dma;
		}
		/* Disable interrupts in DMA mode, IRQ from DMA controller */
		irqflags = DISABLE_ALL_INTERRUPTS_V600 & ~HIPHYIO_IMC_MASK_RORIM;
	}
err_config_dma:
	/* Enable HIPHYIO, turn on interrupts */
	writel(irqflags, HIPHYIO_IMC(spi_control->virtbase));
	writel((readl(HIPHYIO_ENR(spi_control->virtbase)) | HIPHYIO_ENR_MASK_EN),
			HIPHYIO_ENR(spi_control->virtbase));
}

static void do_polling_transfer(struct hiphyio_spi_controller *spi_control)
{
	struct spi_message *message = NULL;
	struct spi_transfer *transfer = NULL;
	struct spi_transfer *previous = NULL;
	struct chip_data *chip = NULL;
	unsigned long time, timeout;
	unsigned long flags = 0;

	if (spi_control->sync_locked)
		spin_lock_irqsave(&spi_control->sync_spinlock, flags);

	chip = spi_control->cur_chip;
	message = spi_control->cur_msg;

	while (message->state != MSG_STATE_DONE) {
		/* Handle for abort */
		if (message->state == MSG_STATE_ERROR)
			break;
		transfer = spi_control->cur_transfer;

		/* Delay if requested at end of transfer */
		if (message->state == MSG_STATE_RUNNING) {
			previous =
				list_entry(transfer->transfer_list.prev,
					struct spi_transfer, transfer_list);
			if (previous->delay_usecs)
				udelay(previous->delay_usecs);
			if (previous->cs_change)
				hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_SELECT);
		} else {
			message->state = MSG_STATE_RUNNING;
			if (!spi_control->next_msg_cs_active)
				hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_SELECT);
		}

		/* Configuration Changing Per Transfer */
		if (set_up_next_transfer(spi_control, transfer)) {
			/* Error path */
			message->state = MSG_STATE_ERROR;
			break;
		}

		flush(spi_control);
		writel((readl(HIPHYIO_ENR(spi_control->virtbase)) |
				HIPHYIO_ENR_MASK_EN),
				HIPHYIO_ENR(spi_control->virtbase));

		dev_dbg(&spi_control->pdev->dev, "polling transfer ongoing ...\n");

		timeout = jiffies + msecs_to_jiffies(SPI_POLLING_TIMEOUT);
		while (spi_control->tx < spi_control->tx_end ||
			spi_control->rx < spi_control->rx_end) {
			time = jiffies;
			readwriter(spi_control);
			if (time_after(time, timeout)) {
				dev_err(&spi_control->pdev->dev,
				"%s: timeout!\n", __func__);
				message->state = MSG_STATE_ERROR;
				goto out;
			}
			if (!spi_control->sync_locked)
				cpu_relax();
		}

		/* Update total byte transferred */
		message->actual_length += spi_control->cur_transfer->len;

		spi_proc_iodie(spi_control);

		if (spi_control->cur_transfer->cs_change)
			hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_DESELECT);

		/* Move to next transfer */
		message->state = next_transfer(spi_control);
	}
out:
	/* Handle end of message */
	if (message->state == MSG_STATE_DONE) {
		message->status = 0;
		flush(spi_control);
	} else {
		message->status = -EIO;
	}

	giveback(spi_control);

	if (spi_control->sync_locked)
		spin_unlock_irqrestore(&spi_control->sync_spinlock, flags);
}

static void do_exclusive_dma_transfer(struct spi_master *master)
{
	struct hiphyio_spi_controller *spi_control = spi_master_get_devdata(master);
	int ret;

	reinit_completion(&spi_control->dma_complete);

	if (!spi_control->next_msg_cs_active)
		hiphyio_spi_cs_control(spi_control, HIPHYIO_CHIP_SELECT);

	if (set_up_next_transfer(spi_control, spi_control->cur_transfer)) {
		/* Error path */
		spi_control->cur_msg->state = MSG_STATE_ERROR;
		spi_control->cur_msg->status = -EIO;
		giveback(spi_control);
		return;
	}
	config_exclusive_dma(master);

	ret = wait_for_completion_timeout(&spi_control->dma_complete,
		WAIT_FOR_COMPLETION);
	if (ret == 0) {
		dev_err(&spi_control->pdev->dev,
			"exclusive_dma timeout, cur_transfer len %u, irq stat 0x%x, trans stat 0x%x\n",
			spi_control->cur_transfer->len,
			readl(INTR_SPI_DMA(spi_control->virtbase)),
			readl(SPI_DMA_TRANS_STAT(spi_control->virtbase)));
	};
}

static int hiphyio_spi_transfer_one_message(struct spi_master *master,
					struct spi_message *msg)
{
	struct hiphyio_spi_controller *spi_control = spi_master_get_devdata(master);

	/* Initial message state */
	spi_control->cur_msg = msg;
	msg->state = MSG_STATE_START;

	spi_control->cur_transfer = list_entry(msg->transfers.next,
					 struct spi_transfer, transfer_list);

	/* Setup the SPI using the per chip configuration */
	spi_control->cur_chip = spi_get_ctldata(msg->spi);

	if (g_hiphyio_state != 0) {
		msg->status = -EIO;
		dev_err(&spi_control->pdev->dev, "iodie stat err fail\n");
		return -EIO;
	}

	if (hiphyio_spi_setup(spi_control) != 0)
		dev_err(&spi_control->pdev->dev, "iodie spi setup fail\n");

	if (msg->spi->chip_select <
		spi_control->pdata->num_chipselect)
		spi_control->cur_cs =
			spi_control->chipselects[msg->spi->chip_select];
	else
		dev_err(&spi_control->pdev->dev, "%s: Bad chip_select:%d\n",
			__func__, msg->spi->chip_select);

	restore_state(spi_control);
	flush(spi_control);

	if (spi_control->cur_chip->xfer_type == POLLING_TRANSFER)
		do_polling_transfer(spi_control);
	else if (spi_control->cur_chip->xfer_type == EXCLUSIVE_DMA_TRANSFER)
		do_exclusive_dma_transfer(master);
	else
		do_interrupt_dma_transfer(spi_control);

	return 0;
}

static int hiphyio_spi_prepare_transfer_hardware(struct spi_master *master)
{
	int ret;
	struct hiphyio_spi_controller *spi_control = spi_master_get_devdata(master);

	if (spi_control->spi_hwspin_lock) {
		ret = hwspin_lock_timeout_in_atomic(spi_control->spi_hwspin_lock,
		GET_HARDWARE_TIMEOUT);
		if (ret) {
			dev_err(&spi_control->pdev->dev,
				"Get hardware_mutex complete timeout\n");
			return -ETIME;
		}
	}

	if (spi_control->spi_sleep_use_doze)
		vote_disable_doze(spi_control->doze_id);
	ret = hiphyio_spi_runtime_resume(master->dev.parent);
	return ret;
}

static int hiphyio_spi_unprepare_transfer_hardware(struct spi_master *master)
{
	struct hiphyio_spi_controller *spi_control = spi_master_get_devdata(master);

	writel((readl(HIPHYIO_ENR(spi_control->virtbase)) &
		(~HIPHYIO_ENR_MASK_EN)), HIPHYIO_ENR(spi_control->virtbase));

	hiphyio_spi_runtime_suspend(master->dev.parent);
	if (spi_control->spi_hwspin_lock)
		hwspin_unlock_in_atomic(spi_control->spi_hwspin_lock);

	if (spi_control->spi_sleep_use_doze)
		vote_enable_doze(spi_control->doze_id);
	return 0;
}

static int verify_controller_parameters(struct hiphyio_spi_controller *spi_control,
	struct hiphyio_spi_config_chip const *chip_info)
{
	if ((chip_info->com_mode != INTERRUPT_TRANSFER)
		&& (chip_info->com_mode != DMA_TRANSFER)
		&& (chip_info->com_mode != POLLING_TRANSFER)
		&& (chip_info->com_mode != EXCLUSIVE_DMA_TRANSFER)) {
		dev_err(&spi_control->pdev->dev,
			"Communication mode is configured incorrectly\n");
		return -EINVAL;
	}

	return 0;
}

static inline u32 spi_rate(u32 rate, u16 cpsdvsr, u16 scr)
{
	return rate / (cpsdvsr * (1 + scr));
}

static int spi_freq_check(struct hiphyio_spi_controller *spi_control,
	u32 freq, u32 rate)
{
	int ret = 0;
	u32 max_tclk, min_tclk;

	/* cpsdvscr = 2 & scr 0 */
	max_tclk = spi_rate(rate, CLK_CPSDVR_MIN, CLK_SCR_MIN);
	/* cpsdvsr = 254 & scr = 255 */
	min_tclk = spi_rate(rate, CLK_CPSDVR_MAX, CLK_SCR_MAX);

	if (freq > max_tclk) {
		dev_warn(&spi_control->pdev->dev,
			"Max speed that can be programmed is %d Hz, you requested %d\n",
			max_tclk, freq);
		freq = max_tclk;
	}
	if (freq < min_tclk) {
		dev_err(&spi_control->pdev->dev,
			"Requested frequency: %d Hz is less than minimum possible %d Hz\n",
			freq, min_tclk);
		ret = -EINVAL;
	}

	return ret;
}

static int calculate_effective_freq(struct hiphyio_spi_controller *spi_control,
	u32 freq, struct hiphyio_spi_clock_params *clk_freq)
{
	/* Lets calculate the frequency parameters */
	u16 cpsdvsr = CLK_CPSDVR_MIN;
	u16 scr = CLK_SCR_MIN;
	u32 rate;
	u32 tmp = 0;
	u32 best_freq = 0;
	u32 best_cpsdvsr = 0;
	u32 best_scr = 0;

	rate = clk_get_rate(spi_control->clk);
	if (spi_freq_check(spi_control, freq, rate))
		return -EINVAL;

	while ((cpsdvsr <= CLK_CPSDVR_MAX) && (tmp != freq)) {
		while (scr <= CLK_SCR_MAX) {
			tmp = spi_rate(rate, cpsdvsr, scr);
			if (tmp > (u32)freq) {
				/* we need lower freq */
				scr++;
				continue;
			}

			if (tmp > best_freq) {
				best_freq = tmp;
				best_cpsdvsr = cpsdvsr;
				best_scr = scr;
			}
			break;
		}
		cpsdvsr += 2;
		scr = CLK_SCR_MIN;
	}

	WARN(!best_freq,
		"hiphyio_spi: Matching cpsdvsr and scr not found for %d Hz rate\n",
		freq);

	clk_freq->cpsdvsr = (u8) (best_cpsdvsr & 0xFF);
	clk_freq->scr = (u8) (best_scr & 0xFF);
	dev_dbg(&spi_control->pdev->dev,
		"HIPHYIO Target Frequency is: %u, Effective Frequency is %u\n",
		freq, best_freq);
	dev_dbg(&spi_control->pdev->dev, "HIPHYIO cpsdvsr = %d, scr = %d\n",
		clk_freq->cpsdvsr, clk_freq->scr);

	return 0;
}

static struct hiphyio_spi_config_chip hiphyio_spi_default_chip_info = {
	.com_mode = POLLING_TRANSFER,
	.rx_lev_trig = HIPHYIO_RX_1_OR_MORE_ELEM,
	.tx_lev_trig = HIPHYIO_TX_1_OR_MORE_EMPTY_LOC,
	.cs_control = null_cs_control,
};

static int hiphyio_spi_bits_word_check(struct spi_device *spi,
			struct chip_data *chip)
{
	int status = 0;
	unsigned int bits = spi->bits_per_word;

	/* Check bits per word with vendor specific range */
	if (bits <= 3) {
		status = E_SPI_PARAMS;
		dev_err(&spi->dev, "illegal data size for this controller!\n");
		return status;
	} else if (bits <= 8) {
		chip->n_bytes = 1;
		chip->read = READING_U8;
		chip->write = WRITING_U8;
	} else if (bits <= 16) {
		chip->n_bytes = 2;
		chip->read = READING_U16;
		chip->write = WRITING_U16;
	} else {
		chip->n_bytes = 4;
		chip->read = READING_U32;
		chip->write = WRITING_U32;
	}
	return status;
}

static void hiphyio_spi_chipdata_init(struct hiphyio_spi_config_chip *chip_info,
	struct hiphyio_spi_controller *spi_control, struct spi_device *spi,
	struct chip_data *chip, struct hiphyio_spi_clock_params clk_freq)
{
	u32 tmp;

	chip->csr = 0;
	chip->cr = 0;
	chip->enr = 0;

	if ((chip_info->com_mode == DMA_TRANSFER)
		&& ((spi_control->pdata)->enable_dma)) {
		chip->enable_dma = true;
		dev_dbg(&spi->dev, "DMA mode set in controller state\n");
		HIPHYIO_WRITE_BITS(chip->cr, HIPHYIO_DMA_ENABLED,
			HIPHYIO_COMMONCR_MASK_TXDMAE, BIT_TXDMAE);
		HIPHYIO_WRITE_BITS(chip->cr, HIPHYIO_DMA_ENABLED,
			HIPHYIO_COMMONCR_MASK_RXDMAE, BIT_RXDMAE);
	} else {
		chip->enable_dma = false;
		dev_dbg(&spi->dev, "DMA mode NOT set in controller state\n");
		HIPHYIO_WRITE_BITS(chip->cr, HIPHYIO_DMA_DISABLED,
			HIPHYIO_COMMONCR_MASK_TXDMAE, BIT_TXDMAE);
		HIPHYIO_WRITE_BITS(chip->cr, HIPHYIO_DMA_DISABLED,
			HIPHYIO_COMMONCR_MASK_RXDMAE, BIT_RXDMAE);
	}

	/* Effective data bit width */
	HIPHYIO_WRITE_BITS(chip->cr, (u32)spi->bits_per_word - 1,
		HIPHYIO_COMMONCR_MASK_FRAMESIZE, BIT_FRAME);

	/* Stuff that is common for all versions */
	if (spi->mode & SPI_CPOL)
		tmp = HIPHYIO_CLK_POL_IDLE_HIGH;
	else
		tmp = HIPHYIO_CLK_POL_IDLE_LOW;
	HIPHYIO_WRITE_BITS(chip->cr, (u32)tmp,
		HIPHYIO_COMMONCR_MASK_CPOL, BIT_CPOL);

	if (spi->mode & SPI_CPHA)
		tmp = HIPHYIO_CLK_SECOND_EDGE;
	else
		tmp = HIPHYIO_CLK_FIRST_EDGE;
	HIPHYIO_WRITE_BITS(chip->cr, (u32)tmp, HIPHYIO_COMMONCR_MASK_CPHA, BIT_CPHA);

	HIPHYIO_WRITE_BITS(chip->cr, (u32)clk_freq.scr, HIPHYIO_COMMONCR_MASK_DRPO,
		BIT_DRPO);

	HIPHYIO_WRITE_BITS(chip->cr, (u32)clk_freq.cpsdvsr, HIPHYIO_COMMONCR_MASK_DRPR,
		BIT_DRPR);

	/* Loopback config */
	if (spi->mode & SPI_LOOP)
		tmp = LOOPBACK_ENABLED;
	else
		tmp = LOOPBACK_DISABLED;
	HIPHYIO_WRITE_BITS(chip->cr, (u32)tmp, HIPHYIO_COMMONCR_LOOPBACK, 1);
	HIPHYIO_WRITE_BITS(chip->enr, HIPHYIO_DISABLED, HIPHYIO_ENR_MASK_EN, 0);
}

static int hiphyio_spi_controller_setup(struct spi_device *spi)
{
	struct hiphyio_spi_config_chip *hiphyspi_info = NULL;
	struct hiphyio_spi_config_chip chip_info_form_dt;
	struct chip_data *chip = NULL;
	struct hiphyio_spi_clock_params clk_freq = {.cpsdvsr = 0, .scr = 0};
	errno_t ret;
	int status = 0;
	struct device_node *np = spi->dev.of_node;
	struct hiphyio_spi_controller *spi_control =
		spi_master_get_devdata(spi->master);

	if (!spi->max_speed_hz)
		return -EINVAL;

	chip = spi_get_ctldata(spi);
	if (chip == NULL) {
		chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
		if (!chip)
			return -ENOMEM;
	}

	hiphyspi_info = spi->controller_data;

	if (hiphyspi_info == NULL) {
		if (np) {
			chip_info_form_dt = hiphyio_spi_default_chip_info;
			of_property_read_u32(np, "pl022,com-mode",
				&chip_info_form_dt.com_mode);
			of_property_read_u32(np, "pl022,rx-level-trig",
				&chip_info_form_dt.rx_lev_trig);
			of_property_read_u32(np, "pl022,tx-level-trig",
				&chip_info_form_dt.tx_lev_trig);
			hiphyspi_info = &chip_info_form_dt;
		} else {
			hiphyspi_info = &hiphyio_spi_default_chip_info;
			/* spi_board_info.controller_data not is supplied */
			dev_dbg(&spi->dev,
				"using default controller_data settings\n");
		}
	}

	if ((hiphyspi_info->clk_freq.cpsdvsr == 0)
		&& (hiphyspi_info->clk_freq.scr == 0)) {
		status = calculate_effective_freq(spi_control,
						spi->max_speed_hz,
						&clk_freq);
		if (status < 0)
			goto err_config_params;
	} else {
		ret = memcpy_s(&clk_freq, sizeof(clk_freq),
				&hiphyspi_info->clk_freq, sizeof(clk_freq));
		if (ret != EOK) {
			status = -EINVAL;
			dev_err(&spi->dev, "%s memcpy_s failed\n", __func__);
			goto err_config_params;
		}
		if ((clk_freq.cpsdvsr % 2) != 0)
			clk_freq.cpsdvsr =
				clk_freq.cpsdvsr - 1;
	}
	if ((clk_freq.cpsdvsr < CLK_CPSDVR_MIN)
		|| (clk_freq.cpsdvsr > CLK_CPSDVR_MAX)) {
		status = -EINVAL;
		dev_err(&spi->dev,
			"cpsdvsr is configured incorrectly\n");
		goto err_config_params;
	}

	status = verify_controller_parameters(spi_control, hiphyspi_info);
	if (status) {
		dev_err(&spi->dev, "controller data is incorrect");
		goto err_config_params;
	}

	spi_control->rx_lev_trig = hiphyspi_info->rx_lev_trig;
	spi_control->tx_lev_trig = hiphyspi_info->tx_lev_trig;

	/* Now set controller state based on controller data */
	chip->xfer_type = hiphyspi_info->com_mode;
	if (!hiphyspi_info->cs_control) {
		chip->cs_control = null_cs_control;
		if (!gpio_is_valid(spi_control->chipselects[spi->chip_select]))
			dev_warn(&spi->dev,
				 "invalid chip select\n");
	} else {
		chip->cs_control = hiphyspi_info->cs_control;
	}
	/* Check bits per word with vendor specific range */
	if (hiphyio_spi_bits_word_check(spi, chip))
		goto err_config_params;
	/* Now Initialize all register settings required for this chip */
	hiphyio_spi_chipdata_init(hiphyspi_info, spi_control, spi, chip, clk_freq);
	/* Save controller_state */
	spi_set_ctldata(spi, chip);
	return status;
err_config_params:
	spi_set_ctldata(spi, NULL);
	kfree(chip);
	return status;
}

static void hiphyio_spi_cleanup(struct spi_device *spi)
{
	struct chip_data *chip = spi_get_ctldata(spi);

	spi_set_ctldata(spi, NULL);
	kfree(chip);
}

static struct hiphyio_spi_platform_data *
hiphyio_spi_platform_data_dt_get(struct device *dev)
{
	struct device_node *np = dev->of_node;
	struct hiphyio_spi_platform_data *pd = NULL;
	u32 tmp = 0xFFFFFFFF;

	if (!np) {
		dev_err(dev, "no dt node defined\n");
		return NULL;
	}

	pd = devm_kzalloc(dev, sizeof(struct hiphyio_spi_platform_data), GFP_KERNEL);
	if (!pd)
		return NULL;

	if (of_property_read_u32(np, "bus-id", &tmp))
		dev_err(dev, "no bus-id defined\n");
	pd->bus_id = tmp;
	dev_info(dev,
		 "spi driver, bus id: 0x%08x\n", pd->bus_id);

	if (of_property_read_u32(np, "enable-dma", &tmp)) {
		dev_info(dev, "no enable-dma defined\n");
		pd->enable_dma = 1;
	} else {
		pd->enable_dma = tmp;
		dev_info(dev, "enable-dma %d\n", pd->enable_dma);
	}

	of_property_read_u32(np, "num-cs", &tmp);
	pd->num_chipselect = tmp;

	return pd;
}

static void platform_release_regions(struct platform_device *dev)
{
	u32 size;

	size = resource_size(dev->resource);
	release_mem_region(dev->resource->start, size);
}

static int hiphyio_spi_parse_hiphy_cfg(struct platform_device *pdev,
	struct hiphyio_spi_controller *spi_ctrl)
{
	int ret;
	struct device_node *np = pdev->dev.of_node;
	u32 data[SPI_CS_REG_CNT] = {0};

	ret = of_property_read_u32_array(np, "cs-reg-base",
		&data[0], ARRAY_SIZE(data));
	if (ret) {
		dev_err(&pdev->dev, "doesn't have reset-reg-base property!\n");
		goto err;
	} else {
		spi_ctrl->cs_reg_base = devm_ioremap(&pdev->dev, data[1], data[3]);
		dev_info(&pdev->dev, "spi cs reg addr is: %x\n", data[1]);
	}

	if (of_property_read_u32_array(np, "cs0-info",&data[0], CS_INFO_CNT)) {
		dev_err(&pdev->dev, "can not get cs0 info\n");
		goto err;
	}
	spi_ctrl->cs0_offset = data[0];
	spi_ctrl->cs0_bit =  data[1];

	if (of_property_read_u32_array(np, "cs2-info",&data[0], CS_INFO_CNT)) {
		dev_err(&pdev->dev, "can not get cs2 info\n");
		goto err;
	}
	spi_ctrl->cs2_offset = data[0];
	spi_ctrl->cs2_bit =  data[1];

	of_property_read_u32(np, "iodie-dummy-bytes", &spi_ctrl->iodie_dummy);
	if (spi_ctrl->iodie_dummy == 0 || spi_ctrl->iodie_dummy >= DUMMY_MAX) {
		dev_err(&pdev->dev, "can not dummy byte\n");
		goto err;
	}

	dev_info(&pdev->dev, "dummy_bytes %d, cs0_offset 0x%x cs0_bit %d,\
		cs2_offset 0x%x, cs2_bit %d\n",
		spi_ctrl->iodie_dummy,
		spi_ctrl->cs0_offset, spi_ctrl->cs0_bit,
		spi_ctrl->cs2_offset, spi_ctrl->cs2_bit);

	return 0;
err:
	return -1;
}

static void hiphyio_spi_get_doze_id(struct platform_device *pdev,
	struct hiphyio_spi_controller *spi_control)
{
	if (of_property_read_u32(pdev->dev.of_node, "use-doze-to-sleep",
		&spi_control->spi_sleep_use_doze))
		spi_control->spi_sleep_use_doze = 0;

	if (spi_control->spi_sleep_use_doze) {
		if (of_property_read_u32(pdev->dev.of_node, "doze-id",
			&spi_control->doze_id)) {
			pr_err("%s: spi doze id get err\n", __func__);
			spi_control->spi_sleep_use_doze = 0;
		}
	}
}

static int hiphyio_spi_cfg_from_dt(struct platform_device *pdev,
			struct hiphyio_spi_controller *spi_control,
			struct hiphyio_spi_platform_data *platform_data,
			u64 *clk_rate)
{
	int status = 0;
	struct device_node *np = pdev->dev.of_node;

	status = of_property_read_u64(np, "clock-rate", clk_rate);
	if (status)
		dev_info(&pdev->dev, "[%s] node %s doesn't have clock-rate property!\n",
			__func__, np->name);

	if (of_property_read_u32(np, "hardware-mutex",
		&spi_control->hardware_mutex))
		spi_control->spi_hwspin_lock = NULL;
	if (spi_control->hardware_mutex) {
		if (spi_control->hardware_mutex == HARDWARE_LOCK_DEFAULT) {
			/* if hardware-mutex config to 1 in dts,
			 * then hardware lock is default value 27
			 */
			spi_control->spi_hwspin_lock =
				hwspin_lock_request_specific(
					ENUM_SPI_HWSPIN_LOCK);
		} else {
			/* if hardware-mutex is not 0 or 1 int dts,
			 * then hardware lock is config value in dts
			 */
			spi_control->spi_hwspin_lock =
				hwspin_lock_request_specific(
					spi_control->hardware_mutex);
		}

		if (!spi_control->spi_hwspin_lock) {
			dev_err(&pdev->dev, "spi_hwspin_lock request error\n");
			return E_HWSPI_LOCK;
		}
	}

	platform_data->rt = of_property_read_bool(np, "spi,rt");
	dev_info(&pdev->dev, "spi,rt : %d\n", platform_data->rt);

	if (of_property_read_u32(np, "sync-spinlock",
		&spi_control->sync_locked))
		spi_control->sync_locked = 0;
	if (spi_control->sync_locked)
		spin_lock_init(&spi_control->sync_spinlock);
	spin_lock_init(&spi_control->lock);

	if (hiphyio_spi_parse_hiphy_cfg(pdev, spi_control))
		return E_HWSPI_LOCK;
	hiphyio_spi_get_doze_id(pdev, spi_control);

	return 0;
}

static void hiphyio_spi_master_cfg(struct hiphyio_spi_platform_data *platform_data,
	struct spi_master *master, struct device *dev)
{
	master->bus_num = platform_data->bus_id;
	master->num_chipselect = platform_data->num_chipselect;
	master->cleanup = hiphyio_spi_cleanup;
	master->setup = hiphyio_spi_controller_setup;
	master->prepare_transfer_hardware =
		hiphyio_spi_prepare_transfer_hardware;
	master->transfer_one_message =
		hiphyio_spi_transfer_one_message;
	master->unprepare_transfer_hardware =
		hiphyio_spi_unprepare_transfer_hardware;
	master->dev.of_node = dev->of_node;
	master->auto_runtime_pm = false;
	/*
	 * Supports mode 0-3, loopback, and active low CS.
	 */
	master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LOOP;
	master->rt = platform_data->rt;
	dev_dbg(dev, "BUSNO: %d\n", master->bus_num);
}

static int hiphyio_spi_clk_cfg(struct platform_device *pdev,
	struct hiphyio_spi_controller *spi_control, u64 clk_rate)
{
	int ret = 0;
	int status = 0;

	spi_control->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(spi_control->clk)) {
		status = PTR_ERR(spi_control->clk);
		dev_err(&pdev->dev, "could not retrieve HIPHYIO/SPI bus clock %d\n", status);
		ret = E_SPI_NO_CLK;
		return ret;
	}
	status = clk_prepare_enable(spi_control->clk);
	if (status) {
		dev_err(&pdev->dev, "could not enable HIPHYIO/SPI bus clock\n");
		ret = E_SPI_NO_CLK_EN;
		return ret;
	}

	if (clk_rate > 0) {
		status = clk_set_rate(spi_control->clk, clk_rate);
		if (status) {
			dev_err(&pdev->dev,
				"could not set HIPHYIO/SPI rate status[0x%x]\n",
				status);
			ret = E_SPI_CLK_SET_RATE;
			return ret;
		}
		clk_rate =  clk_get_rate(spi_control->clk);
		dev_info(&pdev->dev, "clk_rate:%lld\n", clk_rate);
	}

	return ret;
}

static int hiphyio_spi_probe_paramter_check(struct platform_device *pdev,
	struct hiphyio_spi_platform_data **platform_data)
{
	*platform_data = hiphyio_spi_platform_data_dt_get(&pdev->dev);

	if (!*platform_data) {
		dev_err(&pdev->dev, "probe: no platform data defined\n");
		return -ENODEV;
	}

	if (!(*platform_data)->num_chipselect) {
			dev_err(&pdev->dev, "probe: no chip select defined\n");
			return -ENODEV;
	}

	return 0;
}

static int hiphyio_spi_probe_trans_cfg(struct platform_device *pdev,
			struct hiphyio_spi_platform_data *platform_data,
			struct hiphyio_spi_controller *spi_control)
{
	int status = 0;

	init_completion(&spi_control->dma_complete);
	/* Initialize transfer pump */
	tasklet_init(&spi_control->pump_transfers, pump_transfers,
		(uintptr_t)spi_control);

	/* Disable HIPHYIO */
	writel((readl(HIPHYIO_ENR(spi_control->virtbase)) & (~HIPHYIO_ENR_MASK_EN)),
			HIPHYIO_ENR(spi_control->virtbase));
	load_hiphyio_default_config(spi_control);

	status = devm_request_irq(&pdev->dev, spi_control->irq,
			hiphyio_spi_interrupt_handler,
			0, pdev->name, spi_control);
	if (status < 0) {
		dev_err(&pdev->dev, "probe - cannot get IRQ (%d)\n", status);
		return status;
	}

	if (platform_data->enable_dma == 0) {
		dev_err(&pdev->dev, "no need dma\n");
		return status;
	}
	/* Get DMA channels, try autoconfiguration first */
	status = hiphyio_spi_dma_autoprobe(spi_control);
	if (status == -EPROBE_DEFER) {
		dev_dbg(&pdev->dev, "deferring probe to get DMA channel\n");
		return status;
	}

	/* If that failed, use channels from platform_data */
	if (status == 0) {
		platform_data->enable_dma = 1;
	} else if (platform_data->enable_dma) {
		status = hiphyio_spi_dma_probe(spi_control);
		if (status != 0)
			platform_data->enable_dma = 0;
	}

	return status;
}
static int hiphyio_spi_master_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct hiphyio_spi_platform_data *platform_data =
			dev_get_platdata(&pdev->dev);
	struct spi_master *master = NULL;
	struct resource *iores = NULL;
	struct hiphyio_spi_controller *spi_control = NULL;
	int status = 0;
	u64 clk_rate = 0;

	status = hiphyio_spi_probe_paramter_check(pdev, &platform_data);
	if (status)
		return -ENODEV;

	/* Allocate master with space for data */
	master = spi_alloc_master(dev, sizeof(struct hiphyio_spi_controller));
	if (master == NULL) {
		dev_err(&pdev->dev, "probe - cannot alloc SPI master\n");
		return -ENOMEM;
	}

	spi_control = spi_master_get_devdata(master);
	spi_control->master = master;
	spi_control->pdata = platform_data;
	spi_control->pdev = pdev;
	spi_control->irq = platform_get_irq(pdev, 0);
	spi_control->chipselects = devm_kzalloc(dev,
					platform_data->num_chipselect * sizeof(int),
					GFP_KERNEL);
	if (!spi_control->chipselects) {
		status = -ENOMEM;
		goto err_no_mem;
	}

	status = hiphyio_spi_cfg_from_dt(pdev, spi_control, platform_data,
		&clk_rate);
	if (status)
		goto hwspin_lock_err0;

	g_hiphyio_state = 0;
	status = iodie_notify_register(IODIE_USER_AP_SPI, hiphyio_state_cb);
	if (status != 0)
		dev_err(dev, "hiphyio notify_register failed\n");

	hiphyio_spi_master_cfg(platform_data, master, dev);

	iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (iores == NULL) {
		dev_err(dev, "get the resource failed\n");
		goto hwspin_lock_err0;
	}

	spi_control->phybase = iores->start;
	spi_control->virtbase = devm_ioremap_resource(dev, iores);

	if (spi_control->virtbase == NULL) {
		status = -ENOMEM;
		goto err_no_ioremap;
	}

	status = hiphyio_spi_clk_cfg(pdev, spi_control, clk_rate);
	if (status) {
		switch (status) {
		case E_SPI_NO_CLK:
			goto err_no_clk;
		case E_SPI_NO_CLK_EN:
			goto err_no_clk_en;
		case E_SPI_CLK_SET_RATE:
			goto err_clk_set_rate;
		default:
			break;
		}
	}
	status = hiphyio_spi_probe_trans_cfg(pdev, platform_data, spi_control);
	if (status)
		goto err_no_irq;

	/* Register with the SPI framework */
	platform_set_drvdata(pdev, spi_control);
	status = devm_spi_register_master(&pdev->dev, master);
	if (status != 0) {
		dev_err(&pdev->dev,
			"probe - problem registering spi master\n");
		goto err_spi_register;
	}
	dev_err(dev, "probe succeeded\n");

	clk_disable_unprepare(spi_control->clk);
	if (spi_control->spi_sleep_use_doze)
		vote_enable_doze(spi_control->doze_id);

	return 0;

err_spi_register:
	if (platform_data->enable_dma)
		hiphyio_spi_dma_remove(spi_control);
err_clk_set_rate:
err_no_irq:
	clk_disable_unprepare(spi_control->clk);
err_no_clk_en:
err_no_clk:
err_no_ioremap:
	if (spi_control->cs_reg_base != NULL) {
		iounmap(spi_control->cs_reg_base);
		spi_control->cs_reg_base = NULL;
	}
	platform_release_regions(pdev);
hwspin_lock_err0:
err_no_mem:
	spi_master_put(master);
	return status;
}

static int hiphyio_spi_master_remove(struct platform_device *pdev)
{
	struct hiphyio_spi_controller *spi_control = platform_get_drvdata(pdev);

	if (!spi_control)
		return 0;

	pm_runtime_get_noresume(&pdev->dev);

	load_hiphyio_default_config(spi_control);
	if (spi_control->pdata->enable_dma)
		hiphyio_spi_dma_remove(spi_control);

	if (spi_control->cs_reg_base != NULL) {
		iounmap(spi_control->cs_reg_base);
		spi_control->cs_reg_base = NULL;
	}
	clk_disable_unprepare(spi_control->clk);
	platform_release_regions(pdev);
	tasklet_disable(&spi_control->pump_transfers);
	spi_unregister_master(spi_control->master);
	platform_set_drvdata(pdev, NULL);

	return 0;
}
#ifdef CONFIG_OF
static const struct of_device_id hiphyio_spi_master_of_match[] = {
	{
		.compatible = "hiphyio-spi-master",
	},
	{},
};
MODULE_DEVICE_TABLE(of, hiphyio_spi_master_of_match);
#endif

#ifdef CONFIG_PM_SLEEP
static int hiphyio_spi_suspend(struct device *dev)
{
	struct hiphyio_spi_controller *spi_control = dev_get_drvdata(dev);
	int ret = 0;

	dev_err(dev, "%s: +\n", __func__);
	ret = spi_master_suspend(spi_control->master);
	if (ret) {
		dev_err(dev, "cannot suspend master\n");
		return ret;
	}

	dev_err(dev, "%s: -\n", __func__);
	return 0;
}

static int hiphyio_spi_resume(struct device *dev)
{
	struct hiphyio_spi_controller *spi_control = dev_get_drvdata(dev);
	int ret;

	dev_err(dev, "%s: +\n", __func__);
	/* Start the queue running */
	ret = spi_master_resume(spi_control->master);
	if (ret)
		dev_err(dev, "problem starting queue (%d)\n", ret);

	dev_err(dev, "%s: -\n", __func__);

	return ret;
}
#endif

#ifdef CONFIG_PM
static int hiphyio_spi_runtime_suspend(struct device *dev)
{
	struct hiphyio_spi_controller *spi_control = dev_get_drvdata(dev);

	clk_disable_unprepare(spi_control->clk);
	hiphyio_spi_pin_select(spi_control, HIPHYIO_SPI_PIN_IDLE);

	return 0;
}

static int hiphyio_spi_runtime_resume(struct device *dev)
{
	struct hiphyio_spi_controller *spi_control = dev_get_drvdata(dev);

	hiphyio_spi_pin_select(spi_control, HIPHYIO_SPI_PIN_NORMAL);
	clk_prepare_enable(spi_control->clk);

	return 0;
}
#endif

static const struct dev_pm_ops hiphyio_spi_master_dev_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(hiphyio_spi_suspend, hiphyio_spi_resume)
};

static struct platform_driver hiphyio_spi_master_driver = {
	.driver = {
		.name = "hiphyio_spi_master",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hiphyio_spi_master_of_match),
		.pm	= &hiphyio_spi_master_dev_pm_ops,
	},
	.probe		= hiphyio_spi_master_probe,
	.remove		= hiphyio_spi_master_remove,
};

static int __init hiphyio_spi_init(void)
{
	return platform_driver_register(&hiphyio_spi_master_driver);
}

static void __exit hiphyio_spi_exit(void)
{
	platform_driver_unregister(&hiphyio_spi_master_driver);
}

subsys_initcall_sync(hiphyio_spi_init);
module_exit(hiphyio_spi_exit);

MODULE_DESCRIPTION("hiphyio_spi controller driver");
MODULE_ALIAS("platform:hiphyio_spi_master");
MODULE_LICENSE("GPL v2");

