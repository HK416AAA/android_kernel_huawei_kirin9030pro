/*
 * Driver for Hi9030 UART serial ports
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 *
 * This is a generic driver for Hi9030 UART serial ports. They
 * have a lot of 16550-like features, but are not register compatible.
 * Note that although they do have CTS, DCD and DSR inputs, they do
 * not have an RI input, nor do they have DTR or RTS outputs. If
 * required, these have to be supplied via some other means (eg, GPIO)
 * and hooked into this driver.
 */
#include "uart_v500_hi9030.h"

static void hi9030_uart_start_tx_pio(struct hi9030_uart_port *uap);
static int hi9030_uart_dma_tx_refill(struct hi9030_uart_port *uap);
static void hi9030_uart_dma_rx_callback(void *data);
static bool hi9030_uart_tx_chars(struct hi9030_uart_port *uap, bool from_irq);
struct hi9030_uart_port *hi9030_uart_ports_ne[MAX_UART_IDX];

struct hi9030_uart_port *get_hi9030_uart_ports_uap(int index)
{
	if ((index >= MAX_UART_IDX) || (index < 0))
		return NULL;

	return hi9030_uart_ports_ne[index];
}

unsigned int hi9030_uart_reg_offset(const struct hi9030_uart_port *uap,
	unsigned int reg)
{
	return uap->reg_offset[reg];
}

unsigned int hi9030_uart_read(const struct hi9030_uart_port *uap, unsigned int reg)
{
	unsigned int addr = 0;

	if (uap->uart_num == 0)
		return 0;
	addr = hi9030_uart_reg_offset(uap, reg);
	return iodie_readl(uap->uart_num, addr);
}

void hi9030_uart_write(unsigned int val, const struct hi9030_uart_port *uap, unsigned int reg)
{
	unsigned int addr = 0;

	if (uap->uart_num == 0)
		return;
	addr = hi9030_uart_reg_offset(uap, reg);
	iodie_writel(uap->uart_num, addr, val);
}

static void hi9030_uart_chip_reset_endisable(struct hi9030_uart_port *dev, unsigned int enable)
{
	unsigned int ret;
	int timeout = UART_RESET_WAIT_TIME;

	if (dev->reset_val) {
		if (enable) {
			iodie_writel(IODIE_IP_PERI_CRG, dev->reset_enable, BIT(dev->reset_bit));
			do {
				ret = iodie_readl(IODIE_IP_PERI_CRG, dev->reset_status);
				ret &= BIT(dev->reset_bit);
				udelay(1);
			} while (!ret && timeout--);
		} else {
			iodie_writel(IODIE_IP_PERI_CRG, dev->reset_disable, BIT(dev->reset_bit));
			do {
				ret = iodie_readl(IODIE_IP_PERI_CRG, dev->reset_status);
				ret &= BIT(dev->reset_bit);
				udelay(1);
			} while (ret && timeout--);
		}
	}
}

static int hi9030_uart_reset_func_init(struct platform_device *dev,
	struct hi9030_uart_port *uap)
{
	int ret;
	unsigned int data[UAP_REG_CFG_NUM] = {0};
	unsigned int flag_reset_enable = 0;

	/* read reset function */
	ret = of_property_read_u32(dev->dev.of_node, "reset-enable-flag",
		&flag_reset_enable);
	if (ret) {
		uap->reset_val = false;
		dev_info(&dev->dev, "get reset-enable-flag fail\n");
	} else {
		if (flag_reset_enable) {
			/* get uart reset control regester */
			ret = of_property_read_u32_array(dev->dev.of_node,
				"reset-controller-reg", &data[0],
				ARRAY_SIZE(data));
			if (ret) {
				uap->reset_val = false;
				dev_info(&dev->dev,
					"get reset-controller-reg fail\n");
			} else {
				uap->reset_enable = data[0];
				uap->reset_disable = data[1];
				uap->reset_status = data[2];
				uap->reset_bit = data[3];
				uap->reset_val = true;
			}
		} else {
			uap->reset_val = false;
		}
	}

	return ret;
}

static int hi9030_uart_find_free_port(void)
{
	int i;
	struct hi9030_uart_port *uart_ports = NULL;

	for (i = 0; i < MAX_UART_IDX; i++) {
		uart_ports = get_hi9030_uart_ports_uap(i);
		if (uart_ports == NULL)
			return i;
	}
	return -EBUSY;
}
static int hi9030_uart_probe_dt_alias(int index, struct device *dev)
{
	struct device_node *np = NULL;
	static bool seen_dev_alias;
	static bool seen_dev_no_alias;
	int val = index;

	if (!IS_ENABLED(CONFIG_OF))
		return val;

	np = dev->of_node;
	if (!np)
		return val;

	val = of_alias_get_id(np, "serial");
	if (val < 0) {
		seen_dev_no_alias = true;
		val = index;
	} else {
		seen_dev_alias = true;
		if (val >= MAX_UART_IDX || get_hi9030_uart_ports_uap(val) != NULL) {
			dev_warn(dev,
				"requested serial port %d not available\n",
				val);
			val = index;
		}
	}

	if (seen_dev_alias && seen_dev_no_alias)
		dev_warn(dev, "aliased and non-aliased serial devices found in "
			"device tree. Serial port may be unpredictable\n");

	return val;
}

static void hi9030_uart_pm(struct uart_port *port, unsigned int state,
	unsigned int oldstate)
{
	struct hi9030_uart_port *uap = (struct hi9030_uart_port *)port;
	int retval;

	(void)oldstate;

	retval = iodie_normal_request(uap->uart_user, IODIE_RT_NORMAL_LOW);
	if (retval) {
		dev_info(port->dev, "ttyIOD%d iodie_normal_request failed\n", port->line);
		return;
	}
	retval = iodie_fnpll_request(uap->uart_user);
	if (retval) {
		dev_info(port->dev, "ttyIOD%d iodie_fnpll_request failed\n", port->line);
		return;
	}

	switch (state) {
	case UART_PM_STATE_ON:
		if (uap->uart_num == IODIE_IP_UART1) {
			iodie_writel(IODIE_IP_PERI_CRG, PERI_CRG_BUS_CLK_SEL, IODIE_UART1_CLK_SEL);
		} else if (uap->uart_num == IODIE_IP_UART2) {
			iodie_writel(IODIE_IP_PERI_CRG, PERI_CRG_BUS_CLK_SEL, IODIE_UART2_CLK_SEL);
		} else {
			dev_err(uap->port.dev, "%s: iodie clk enable failed\n", __func__);
		}
		iodie_clk_en(uap->uart_num);
		break;
	case UART_PM_STATE_OFF:
		iodie_clk_dis(uap->uart_num);
		break;
	default:
		dev_err(uap->port.dev, "%s: pm state fail state=%u\n",
			__func__, state);
		break;
	}

	iodie_fnpll_release(uap->uart_user);
	iodie_normal_release(uap->uart_user, IODIE_RT_NORMAL_LOW);
}

#ifdef CONFIG_PM_SLEEP
static int hi9030_uart_suspend(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct hi9030_uart_port *uap = platform_get_drvdata(pdev);
	int ret;

	if (!uap) {
		pr_err("%s:uap is NULL\n", __func__);
		return -EINVAL;
	}

	dev_info(uap->port.dev, "%s: +\n", __func__);
	ret = uart_suspend_port(&g_hi9030_uart_v500, &uap->port);
	dev_info(uap->port.dev, "%s: -\n", __func__);

	return ret;
}

static int hi9030_uart_resume(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct hi9030_uart_port *uap = platform_get_drvdata(pdev);
	int ret;

	if (!uap) {
		pr_err("%s:uap is NULL\n", __func__);
		return -EINVAL;
	}

	dev_info(uap->port.dev, "%s: +\n", __func__);
	ret = uart_resume_port(&g_hi9030_uart_v500, &uap->port);
	dev_info(uap->port.dev, "%s: -\n", __func__);

	return ret;
}
#endif

static int uart_v500_pinctrl(struct platform_device *dev,
	struct hi9030_uart_port *uap)
{
	int ret = 0;

	uap->pinctrl = devm_pinctrl_get(&dev->dev);
	if (IS_ERR(uap->pinctrl)) {
		ret = PTR_ERR(uap->pinctrl);
		return ret;
	}

	uap->pinctrls_default = pinctrl_lookup_state(uap->pinctrl,
		PINCTRL_STATE_DEFAULT);
	if (IS_ERR(uap->pinctrls_default))
		dev_err(&dev->dev, "could not get default pinstate\n");

	uap->pinctrls_idle = pinctrl_lookup_state(uap->pinctrl,
		PINCTRL_STATE_IDLE);
	if (IS_ERR(uap->pinctrls_idle))
		dev_err(&dev->dev, "could not get sleep pinstate\n");

	return ret;
}

static void hi9030_uart_disable_msk(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);

	uap->int_msk |= UART_V500_INT_CTSM | UART_V500_INT_RIM | UART_V500_INT_DCDM | UART_V500_INT_DSRM;
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
}

static void hi9030_uart_fifo_err_check(struct hi9030_uart_port *uap,
	unsigned int *ch, unsigned int *flag)
{
	if (*ch & UART_V500_DR_BE) {
		*ch &= ~(UART_V500_DR_FE | UART_V500_DR_PE);
		uap->port.icount.brk++;
		if (uart_handle_break(&uap->port))
			return;
	} else if (*ch & UART_V500_DR_PE) {
		uap->port.icount.parity++;
	} else if (*ch & UART_V500_DR_FE) {
		uap->port.icount.frame++;
	}

	if (*ch & UART_V500_DR_OE)
		uap->port.icount.overrun++;

	*ch &= uap->port.read_status_mask;

	if (*ch & UART_V500_DR_BE)
		*flag = TTY_BREAK;
	else if (*ch & UART_V500_DR_PE)
		*flag = TTY_PARITY;
	else if (*ch & UART_V500_DR_FE)
		*flag = TTY_FRAME;
}
/*
 * Reads up to 256 characters from the FIFO or until it's empty and
 * inserts them into the TTY layer. Returns the number of characters
 * read from the FIFO.
 */
static int hi9030_uart_fifo_to_tty(struct hi9030_uart_port *uap)
{
	unsigned int status;
	unsigned int ch, flag;
	unsigned int max_count = FIFO_MAX_COUNT;
	int fifotaken = 0;

	while (max_count--) {
		status = hi9030_uart_read(uap, REG_UART_STAT);
		if (status & UART_V500_STAT_RXFE)
			break;

		/* Take chars from the FIFO and update status */
		ch = hi9030_uart_read(uap, REG_UART_RX_FIFO);
		flag = TTY_NORMAL;
		uap->port.icount.rx++;
		fifotaken++;

		if (unlikely(ch & UART_V500_DR_ERROR))
			hi9030_uart_fifo_err_check(uap, &ch, &flag);

		if (uart_handle_sysrq_char(&uap->port, ch & UART_TX_WORDS))
			continue;

		uart_insert_char(&uap->port, ch, UART_V500_DR_OE, ch, flag);
	}

	return fifotaken;
}
#ifdef CONFIG_DMA_ENGINE
#define UART_DMA_BUFFER_SIZE PAGE_SIZE

static void hi9030_uart_dma_tx_init(struct hi9030_uart_port *uap,
	struct device *dev, struct hi9030_uart_dma_data *plat)
{
	struct dma_chan *request_chan = NULL;
	dma_cap_mask_t mask;
	struct dma_slave_config tx_conf = {
		.dst_addr = uap->port.mapbase + hi9030_uart_reg_offset(uap,
			REG_UART_TX_FIFO),
		.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE,
		.direction = DMA_MEM_TO_DEV,
		.dst_maxburst = (uap->fifosize >> 2),
		.device_fc = false,
	};

	request_chan = dma_request_chan(dev, "tx");
	if (IS_ERR(request_chan)) {
		if (PTR_ERR(request_chan) == -EPROBE_DEFER) {
			uap->is_dma_probed = false;
			return;
		}
		/* check platform data */
		if (!plat || !plat->dma_filter) {
			dev_info(uap->port.dev, "No DMA platform data\n");
			return;
		}
		/* Try to acquire a generic DMA engine slave TX channel */
		dma_cap_zero(mask);
		dma_cap_set(DMA_SLAVE, mask);

		request_chan = dma_request_channel(mask, plat->dma_filter,
			plat->dma_tx_param);
		if (!request_chan) {
			dev_err(uap->port.dev, "No Tx DMA channel!\n");
			return;
		}
	}

	dmaengine_slave_config(request_chan, &tx_conf);
	uap->dmatx.chan = request_chan;
	dev_info(uap->port.dev, "DMA channel Tx %s\n",
		dma_chan_name(uap->dmatx.chan));
}

static void hi9030_uart_dma_rx_init(struct hi9030_uart_port *uap,
	struct device *dev, struct hi9030_uart_dma_data *plat)
{
	struct dma_chan *request_chan = NULL;
	struct dma_slave_caps caps;
	dma_cap_mask_t mask;
	struct dma_slave_config rx_conf = {
		.src_addr = uap->port.mapbase +
			hi9030_uart_reg_offset(uap, REG_UART_RX_FIFO),
		.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE,
		.direction = DMA_DEV_TO_MEM,
		.src_maxburst = (uap->fifosize >> 3) - 1,
		.device_fc = false,
	};

	request_chan = dma_request_slave_channel(dev, "rx");
	if (!request_chan && plat && plat->dma_rx_param) {
		request_chan = dma_request_channel(mask, plat->dma_filter,
			plat->dma_rx_param);
		if (!request_chan) {
			dev_err(uap->port.dev, "No Rx DMA channel!\n");
			return;
		}
	}

	if (request_chan) {
		/*
		 * Some DMA controllers provide information on their
		 * capabilities. If the controller does, check for suitable
		 * residue processing otherwise assime all is well.
		 */
		if (dma_get_slave_caps(request_chan, &caps) == 0) {
			if (caps.residue_granularity ==
				DMA_RESIDUE_GRANULARITY_DESCRIPTOR) {
				dma_release_channel(request_chan);
				dev_info(uap->port.dev,
					"no residue process disable rx dma\n");
				return;
			}
		}
		dmaengine_slave_config(request_chan, &rx_conf);
		uap->dmarx.chan = request_chan;

		dev_info(uap->port.dev, "DMA channel Rx %s\n",
			 dma_chan_name(uap->dmarx.chan));
	}
}

static void hi9030_uart_dma_probe(struct hi9030_uart_port *uap)
{
	/* DMA is the sole user of the platform data right now */
	struct hi9030_uart_dma_data *plat = dev_get_platdata(uap->port.dev);
	struct device *dev = uap->port.dev;

	uap->is_dma_probed = true;
	hi9030_uart_dma_tx_init(uap, dev, plat);
	hi9030_uart_dma_rx_init(uap, dev, plat);
}

static void hi9030_uart_dma_remove(struct hi9030_uart_port *uap)
{
	if (uap->dmatx.chan)
		dma_release_channel(uap->dmatx.chan);
	if (uap->dmarx.chan)
		dma_release_channel(uap->dmarx.chan);
}

/*
 * The current DMA TX buffer has been sent.
 * Try to queue up another DMA buffer.
 */
static void hi9030_uart_dma_tx_callback(void *data)
{
	struct hi9030_uart_port *uap = data;
	unsigned long flags;
	unsigned int dma_conctrl;

	spin_lock_irqsave(&uap->port.lock, flags);

	dma_conctrl = uap->dma_conctrl;
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_TX_DMA_DIS, uap, REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;

	if (!(dma_conctrl & UART_V500_TX_DMA_EN) ||
		uart_tx_stopped(&uap->port) ||
		uart_circ_empty(&uap->port.state->xmit)) {
		uap->dmatx.queued = false;
		spin_unlock_irqrestore(&uap->port.lock, flags);
		return;
	}

	if (hi9030_uart_dma_tx_refill(uap) <= 0)
		hi9030_uart_start_tx_pio(uap);

	spin_unlock_irqrestore(&uap->port.lock, flags);
}

static void hi9030_uart_dma_tx_xmit_fill(struct hi9030_uart_port *uap,
	unsigned int *count, struct circ_buf *xmit,
	struct hi9030_dmatx_data *dma_tx)
{
	size_t first = UART_XMIT_SIZE - xmit->tail;
	size_t second;

	/* Else proceed to copy the TX chars to the DMA buffer and fire DMA */
	if (*count > UART_DMA_BUFFER_SIZE)
		*count = UART_DMA_BUFFER_SIZE;

	if (xmit->tail < xmit->head) {
		memcpy_toio(dma_tx->buffer, (&xmit->buf[xmit->tail]), *count);
	} else {
		if (first > *count)
			first = *count;
		second = *count - first;
		memcpy_toio(dma_tx->buffer, (&xmit->buf[xmit->tail]), first);
		if (second) {
			memcpy_toio(dma_tx->buffer + first, (&xmit->buf[0]), second);
		}
	}

	dma_tx->length = *count;
}

/*
 * Try to refill the TX DMA buffer.
 * Locking: called with port lock held and IRQs disabled.
 * Returns:
 *   1 if we queued up a TX DMA buffer.
 *   0 if we didn't want to handle this by DMA
 *  <0 on error
 */
static int hi9030_uart_dma_tx_refill(struct hi9030_uart_port *uap)
{
	struct hi9030_dmatx_data *dma_tx = &uap->dmatx;
	struct dma_chan *tx_chan = dma_tx->chan;
	struct dma_device *dma_dev = tx_chan->device;
	struct dma_async_tx_descriptor *dma_desc = NULL;
	struct circ_buf *tx_xmit = &uap->port.state->xmit;
	unsigned int count;

	/*
	 * Try to avoid the overhead involved in using DMA if the transaction
	 * fits in the first half of the FIFO, by using the standard interrupt
	 * handling. This ensures that we issue a uart_write_wakeup() at the
	 * appropriate time.
	 */
	count = uart_circ_chars_pending(tx_xmit);
	if (count < (uap->fifosize >> 1)) {
		uap->dmatx.queued = false;
		return 0;
	}

	hi9030_uart_dma_tx_xmit_fill(uap, &count, tx_xmit, dma_tx);

	/* 1: Number of entries in table */
	dma_desc = dmaengine_prep_slave_sg(tx_chan, NULL, dma_tx->length,
		DMA_MEM_TO_DEV, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	if (!dma_desc) {
		uap->dmatx.queued = false;
		/*
		 * If DMA can not be used right now, we complete this
		 * transaction via IRQ and let the TTY layer retry.
		 */
		dev_err(uap->port.dev, "TX DMA busy\n");
		return -EBUSY;
	}

	/* Some data to go along to the callback */
	dma_desc->callback = hi9030_uart_dma_tx_callback;
	dma_desc->callback_param = uap;
	/* All errors should happen at prepare time */
	dmaengine_submit(dma_desc);
	/* Fire the DMA transaction */
	dma_dev->device_issue_pending(tx_chan);

	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_TX_DMA_EN, uap, REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
	uap->dmatx.queued = true;

	tx_xmit->tail = (tx_xmit->tail + count) & (UART_XMIT_SIZE - 1);
	uap->port.icount.tx += count;
	if (uart_circ_chars_pending(tx_xmit) < WAKEUP_CHARS)
		uart_write_wakeup(&uap->port);

	return 1;
}

static bool hi9030_uart_dma_tx_irq(struct hi9030_uart_port *uap)
{
	if (!uap->using_9030_tx_dma)
		return false;

	if (uap->dmatx.queued) {
		hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
		hi9030_uart_write(UART_V500_TX_DMA_EN, uap, REG_UART_CONFIG);
		uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
		uap->dma_conctrl &= uap->uart_cfg_mask;
		uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
		uap->int_msk |= UART_V500_INT_TXM;
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
		return true;
	}

	/*
	 * We don't have a TX buffer queued, so try to queue one.
	 * If we successfully queued a buffer, mask the TX IRQ.
	 */
	if (hi9030_uart_dma_tx_refill(uap) > 0) {
		uap->int_msk |= UART_V500_INT_TXM;
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
		return true;
	}
	return false;
}

/*
 * Stop the DMA transmit (eg, due to received XOFF).
 * Locking: called with port lock held and IRQs disabled.
 */
static void hi9030_uart_dma_tx_stop(struct hi9030_uart_port *uap)
{
	if (uap->dmatx.queued) {
		hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
		hi9030_uart_write(UART_V500_TX_DMA_DIS, uap, REG_UART_CONFIG);
		uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
		uap->dma_conctrl &= uap->uart_cfg_mask;
		uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
	}
}

static bool hi9030_uart_dma_tx_start(struct hi9030_uart_port *uap)
{
	if (!uap->using_9030_tx_dma)
		return false;

	if (!uap->port.x_char) {
		bool retval = true;

		if (!uap->dmatx.queued) {
			if (hi9030_uart_dma_tx_refill(uap) > 0) {
				uap->int_msk |= UART_V500_INT_TXM;
				hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
			} else {
				retval = false;
			}
		} else if (!(uap->dma_conctrl & UART_V500_TX_DMA_EN)) {
			hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
			hi9030_uart_write(UART_V500_TX_DMA_EN, uap, 
				REG_UART_CONFIG);
			uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
			uap->dma_conctrl &= uap->uart_cfg_mask;
			uap->dma_conctrl |= uap->dma_conctrl <<
				UART_CONFIG_BIT_MASK;
		}
		return retval;
	}
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_TX_DMA_DIS, uap, REG_UART_CONFIG);

	if (hi9030_uart_read(uap, REG_UART_STAT) & UART_V500_STAT_TXFF)
		return false;

	hi9030_uart_write(uap->port.x_char, uap, REG_UART_TX_FIFO);
	uap->port.icount.tx++;
	uap->port.x_char = 0;

	/* Success - restore the DMA state */
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);

	return true;
}

/*
 * Flush the transmit buffer.
 * Locking: called with port lock held and IRQs disabled.
 */
static void hi9030_uart_dma_flush_buffer(struct uart_port *port)
__releases(&uap->port.lock)
__acquires(&uap->port.lock)
{
	struct hi9030_uart_port *uap = container_of(port,
		struct hi9030_uart_port, port);

	if (!uap->using_9030_tx_dma)
		return;

	dmaengine_terminate_async(uap->dmatx.chan);

	if (uap->dmatx.queued) {
		uap->dmatx.queued = false;
		hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
		hi9030_uart_write(UART_V500_TX_DMA_DIS, uap, REG_UART_CONFIG);
		uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
		uap->dma_conctrl &= uap->uart_cfg_mask;
		uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
	}
}

static int hi9030_uart_dma_rx_trigger_dma(struct hi9030_uart_port *uap)
{
	struct dma_chan *rx_chan = uap->dmarx.chan;
	struct hi9030_dmarx_data *dma_rx = &uap->dmarx;
	struct dma_async_tx_descriptor *dma_desc = NULL;
	struct hi9030_uart_rx_sgbuf *rx_sg = uap->rx_sg;

	if (!rx_chan)
		return -EIO;

	rx_sg->buf = uap->dmarx.use_buf_b ? uap->dmarx.buffer_b :
		uap->dmarx.buffer_a;
	dma_rx->length = UART_DMA_BUFFER_SIZE;
	rx_sg->use_buf_b = uap->dmarx.use_buf_b;
	/* 1: Number of entries in table */
	dma_desc = dmaengine_prep_slave_sg(rx_chan, &rx_sg->sg, dma_rx->length,
		DMA_DEV_TO_MEM, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
	/*
	 * If the DMA engine is busy and can not prepare a
	 * channel, no big deal, the driver will fall back
	 * to interrupt mode as a result of this error code.
	 */
	if (!dma_desc) {
		uap->dmarx.running = false;
		dmaengine_terminate_all(rx_chan);
		return -EBUSY;
	}

	/* Some data to go along to the callback */
	dma_desc->callback = hi9030_uart_dma_rx_callback;
	dma_desc->callback_param = uap;
	dma_rx->dma_cookie = dmaengine_submit(dma_desc);
	dma_async_issue_pending(rx_chan);

	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_RX_DMA_EN, uap, REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
	uap->dmarx.running = true;
	uap->int_msk |= UART_V500_INT_RXM;
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	return 0;
}

/*
 * This is called when either the DMA job is complete, or
 * the FIFO timeout interrupt occurred. This must be called
 * with the port spinlock uap->port.lock held.
 */
static void hi9030_uart_dma_rx_chars(struct hi9030_uart_port *uap,
	unsigned int pending, bool use_buf_b, bool readfifo)
{
	struct tty_port *port = &uap->port.state->port;
	char *sgbuf = use_buf_b ? uap->dmarx.buffer_b : uap->dmarx.buffer_a;
	unsigned int dma_count = 0;
	unsigned int int_clr;
	unsigned int fifotaken = 0;

	/* Pick the remain data from the DMA */
	if (pending) {
		dma_count = iodie_tty_insert_flip_string(port, sgbuf, pending);
		uap->port.icount.rx += dma_count;
		if (dma_count < pending)
			dev_dbg(uap->port.dev,
				 "can't insert all characters (TTY is full)\n");
	}

	if (dma_count == pending && readfifo) {
		/* Clear any error flags */
		int_clr = (UART_V500_INT_OES | UART_V500_INT_BES |
			UART_V500_INT_PES | UART_V500_INT_FES);
		hi9030_uart_write(int_clr, uap, REG_UART_INT_CLR);

		fifotaken = hi9030_uart_fifo_to_tty(uap);
	}

	spin_unlock(&uap->port.lock);
	dev_dbg(uap->port.dev,
		 "Took %u chars from DMA buffer and %u chars from the FIFO\n",
		 dma_count, fifotaken);
	tty_flip_buffer_push(port);
	spin_lock(&uap->port.lock);
}

static void hi9030_uart_dma_rx_irq(struct hi9030_uart_port *uap)
{
	struct hi9030_dmarx_data *dmarx = &uap->dmarx;
	struct dma_chan *rxchan = dmarx->chan;
	size_t pending;
	struct dma_tx_state state;
	enum dma_status dmastat;

	/* Disable RX DMA - incoming data will wait in the FIFO */
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_RX_DMA_DIS, uap, REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;

	/*
	 * Pause the transfer so we can trust the current counter,
	 * do this before we pause the uart block, else we may
	 * overflow the FIFO.
	 */
	if (dmaengine_pause(rxchan))
		dev_err(uap->port.dev, "unable to pause DMA transfer\n");
	dmastat = rxchan->device->device_tx_status(rxchan,
		dmarx->dma_cookie, &state);
	if (dmastat != DMA_PAUSED)
		dev_err(uap->port.dev, "not pause DMA transfer dmastat = %d\n",
			dmastat);

	if (dmastat == DMA_COMPLETE || state.residue == 0) {
		uap->port.icount.buf_overrun++;
		uap->int_msk |= UART_V500_INT_RTM;
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
		return;
	}

	uap->dmarx.running = false;

	pending = dmarx->length - state.residue;
	BUG_ON(pending > UART_DMA_BUFFER_SIZE);
	/* Then we terminate the transfer - we now know our residue */
	dmaengine_terminate_all(rxchan);

	/*
	 * This will take the chars we have so far and insert
	 * into the framework.
	 */
	hi9030_uart_dma_rx_chars(uap, pending, dmarx->use_buf_b, true);

	/* Switch buffer & re-trigger DMA job */
	dmarx->use_buf_b = !dmarx->use_buf_b;
	if (hi9030_uart_dma_rx_trigger_dma(uap)) {
		dev_err(uap->port.dev, "could not retrigger RX DMA job "
			"fall back to interrupt mode\n");
		uap->int_msk &= (~UART_V500_INT_RXM);
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	}
}

static void hi9030_uart_dma_rx_callback(void *data)
{
	struct hi9030_uart_port *uap = data;
	struct hi9030_dmarx_data *dmarx = &uap->dmarx;
	struct dma_chan *rxchan = dmarx->chan;
	bool lastbuf = dmarx->use_buf_b;
	size_t rx_pending;
	struct dma_tx_state state;
	int val;

	spin_lock_irq(&uap->port.lock);
	if (uap->uart_rx_dma_disabled) {
		spin_unlock_irq(&uap->port.lock);
		return;
	}
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_RX_DMA_DIS, uap, REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;

	/*
	 * Rx data can be taken by the UART interrupts during
	 * the DMA irq handler. So we check the residue here.
	 */
	rxchan->device->device_tx_status(rxchan, dmarx->dma_cookie, &state);
	rx_pending = dmarx->length - state.residue;
	BUG_ON(rx_pending > UART_DMA_BUFFER_SIZE);
	/* Then we terminate the transfer - we now know our residue */
	dmaengine_terminate_all(rxchan);

	uap->dmarx.running = false;
	dmarx->use_buf_b = !lastbuf;
	val = hi9030_uart_dma_rx_trigger_dma(uap);

	hi9030_uart_dma_rx_chars(uap, rx_pending, lastbuf, false);
	spin_unlock_irq(&uap->port.lock);

	if (val) {
		dev_dbg(uap->port.dev, "can not retrigger RX DMA job "
			"fall back to interrupt mode\n");
		uap->int_msk &= ~(UART_V500_INT_RXM | UART_V500_INT_RTM);
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	} else {
		uap->int_msk |= UART_V500_INT_RXM;
		uap->int_msk &= (~UART_V500_INT_RTM);
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	}
}

/*
 * Stop accepting received characters, when we're shutting down or
 * suspending this port.
 * Locking: called with port lock held and IRQs disabled.
 */
static void hi9030_uart_dma_rx_stop(struct hi9030_uart_port *uap)
{
	/* Just disable the DMA enable */
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write(UART_V500_RX_DMA_DIS, uap, REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
}

static void hi9030_uart_dma_startup(struct hi9030_uart_port *uap)
{
	unsigned int addr;

	if ((uap->enable_dma) && (!uap->is_dma_probed))
		hi9030_uart_dma_probe(uap);

	/* release dma reset */
	iodie_writel(IODIE_IP_PERI_CRG, IODIE_DMA_RST_OFFSET, IODIE_DMA_RST_DIS);
	/* DMA clk enable */
	iodie_clk_en(IODIE_IP_DMA0);
	iodie_writel(IODIE_IP_DMA0, IODIE_DMA_INT_TC1_MASK, IODIE_DMA_MASK_VAL);
	iodie_writel(IODIE_IP_DMA0, IODIE_DMA_INT_ERR1_MASK, IODIE_DMA_MASK_VAL);
	iodie_writel(IODIE_IP_DMA0, IODIE_DMA_INT_ERR2_MASK, IODIE_DMA_MASK_VAL);
	/* DMA mem exit shutdown */
	iodie_writel(IODIE_IP_AO_CRG, DMA_MEM_SHUTDOWN_OFFSET, DMA_MEM_SHUTDOWN_VAL);

	if (!uap->dmatx.chan)
		return;

	if (uap->uart_num == IODIE_IP_UART1) {
		addr = IODIE_UART1_TX_BUFFER;
	} else if (uap->uart_num == IODIE_IP_UART2) {
		addr = IODIE_UART2_TX_BUFFER;
	} else {
		uap->using_9030_tx_dma = false;
		uap->using_9030_rx_dma = false;
		return;
	}

	uap->dmatx.buffer = (char *)ioremap(addr, IODIE_UART_BUFFER_SIZE);
	memset_io(uap->dmatx.buffer, 0, IODIE_UART_BUFFER_SIZE);
	if (!uap->dmatx.buffer) {
		dev_err(uap->port.dev, "no memory for DMA TX buffer\n");
		uap->port.fifosize = uap->fifosize;
		return;
	}

	/* The DMA buffer is now the FIFO the tty subsystem can use */
	uap->port.fifosize = UART_DMA_BUFFER_SIZE;
	uap->using_9030_tx_dma = true;

	if (!uap->dmarx.chan)
		goto skip_rx;

	/* Allocate and map DMA RX buffers */
	if (!uap->rx_global_sg_buf_alloced) {
		if (uap->uart_num == IODIE_IP_UART1) {
			uap->dmarx.buffer_a = (char *)ioremap(IODIE_UART1_RX_BUFFER_A, IODIE_UART_BUFFER_SIZE);
			memset_io(uap->dmarx.buffer_a, 0, IODIE_UART_BUFFER_SIZE);
			uap->dmarx.buffer_b = (char *)ioremap(IODIE_UART1_RX_BUFFER_B, IODIE_UART_BUFFER_SIZE);
			memset_io(uap->dmarx.buffer_b, 0, IODIE_UART_BUFFER_SIZE);
		} else if (uap->uart_num == IODIE_IP_UART2) {
			uap->dmarx.buffer_a = (char *)ioremap(IODIE_UART2_RX_BUFFER_A, IODIE_UART_BUFFER_SIZE);
			memset_io(uap->dmarx.buffer_a, 0, IODIE_UART_BUFFER_SIZE);
			uap->dmarx.buffer_b = (char *)ioremap(IODIE_UART2_RX_BUFFER_B, IODIE_UART_BUFFER_SIZE);
			memset_io(uap->dmarx.buffer_b, 0, IODIE_UART_BUFFER_SIZE);
		}
		if (uap->rx_use_global_sg_buf)
			uap->rx_global_sg_buf_alloced = true;
	}

	uap->using_9030_rx_dma = true;
	uap->uart_rx_dma_disabled = false;

skip_rx:
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	if (uap->using_9030_rx_dma) {
		if (hi9030_uart_dma_rx_trigger_dma(uap))
			dev_dbg(uap->port.dev, "could not trigger initial "
				"RX DMA job, fall back to interrupt mode\n");
	}
}

static void hi9030_uart_dma_shutdown(struct hi9030_uart_port *uap)
{
	unsigned int uart_cfg;
	unsigned int count = 0;

	if (!(uap->using_9030_tx_dma || uap->using_9030_rx_dma))
		return;

	hi9030_uart_write(UART_V500_CFG_CTS_DIS, uap, REG_UART_CONFIG);
	uart_cfg = hi9030_uart_read(uap, REG_UART_CONFIG);
	uart_cfg &= uap->uart_cfg_mask;
	uart_cfg |= uart_cfg << UART_CONFIG_BIT_MASK;

	/* Disable RX and TX DMA */
	while ((hi9030_uart_read(uap, REG_UART_STAT) & uap->vendor->stat_busy) &&
		(count < TXFF_TIMEOUT)) {
		cpu_relax();
		udelay(1);
		count++;
	}
	if (count == TXFF_TIMEOUT)
		dev_err(uap->port.dev, "Tx busy timeout, uart stat 0x%x\n",
			hi9030_uart_read(uap, REG_UART_STAT));

	spin_lock_irq(&uap->port.lock);
	uap->dma_conctrl |= uart_cfg;
	hi9030_uart_write(uap->dma_conctrl, uap, REG_UART_CONFIG);
	hi9030_uart_write((UART_V500_TX_DMA_DIS | UART_V500_RX_DMA_DIS), uap,
		REG_UART_CONFIG);
	uap->dma_conctrl = hi9030_uart_read(uap, REG_UART_CONFIG);
	uap->dma_conctrl &= uap->uart_cfg_mask;
	uap->dma_conctrl |= uap->dma_conctrl << UART_CONFIG_BIT_MASK;
	uap->uart_rx_dma_disabled = true;
	spin_unlock_irq(&uap->port.lock);

	if (uap->using_9030_tx_dma) {
		/* this should already be done by hi9030_uart_dma_flush_buffer */
		dmaengine_terminate_all(uap->dmatx.chan);
		if (uap->dmatx.queued) {
			uap->dmatx.queued = false;
		}
		iounmap(uap->dmatx.buffer);
		uap->using_9030_tx_dma = false;
	}

	if (uap->using_9030_rx_dma) {
		dmaengine_terminate_all(uap->dmarx.chan);
		/* Clean up the RX DMA */
		if (!uap->rx_global_sg_buf_alloced) {
			iounmap(uap->dmarx.buffer_a);
			iounmap(uap->dmarx.buffer_b);
		}
		uap->using_9030_rx_dma = false;
	}
}

static inline bool hi9030_uart_dma_rx_available(struct hi9030_uart_port *uap)
{
	return uap->using_9030_rx_dma;
}

static inline bool hi9030_uart_dma_rx_running(struct hi9030_uart_port *uap)
{
	return uap->using_9030_rx_dma && uap->dmarx.running;
}

#else
/* Blank functions if the DMA engine is not available */
static inline void hi9030_uart_dma_probe(struct hi9030_uart_port *uap)
{
}

static inline void hi9030_uart_dma_remove(struct hi9030_uart_port *uap)
{
}

static inline void hi9030_uart_dma_startup(struct hi9030_uart_port *uap)
{
}

static inline void hi9030_uart_dma_shutdown(struct hi9030_uart_port *uap)
{
}

static inline bool hi9030_uart_dma_tx_irq(struct hi9030_uart_port *uap)
{
	return false;
}

static inline void hi9030_uart_dma_tx_stop(struct hi9030_uart_port *uap)
{
}

static bool hi9030_uart_dma_tx_start(struct hi9030_uart_port *uap)
{
	return false;
}

static inline void hi9030_uart_dma_rx_irq(struct hi9030_uart_port *uap)
{
}

static inline void hi9030_uart_dma_rx_stop(struct hi9030_uart_port *uap)
{
}

static inline int hi9030_uart_dma_rx_trigger_dma(struct hi9030_uart_port *uap)
{
	return -EIO;
}

static inline bool hi9030_uart_dma_rx_available(struct hi9030_uart_port *uap)
{
	return false;
}

static inline bool hi9030_uart_dma_rx_running(struct hi9030_uart_port *uap)
{
	return false;
}

static inline void hi9030_uart_dma_flush_buffer(struct hi9030_uart_port *uap)
{
	return;
}
#endif

static void hi9030_uart_stop_tx(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);

	uap->int_msk |= UART_V500_INT_TXM;
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	hi9030_uart_dma_tx_stop(uap);
}

static void hi9030_uart_start_tx_pio(struct hi9030_uart_port *uap)
{
	if (hi9030_uart_tx_chars(uap, false)) {
		uap->int_msk &= (~UART_V500_INT_TXM);
		hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	}
}

static void hi9030_uart_start_tx(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);

	if (!hi9030_uart_dma_tx_start(uap))
		hi9030_uart_start_tx_pio(uap);
}

static void hi9030_uart_stop_rx(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);

	uap->int_msk |= UART_V500_INT_MASK;
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);

	hi9030_uart_dma_rx_stop(uap);
}

static void hi9030_uart_enable_msk(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);

	uap->int_msk &= ~(UART_V500_INT_CTSM | UART_V500_INT_RIM | UART_V500_INT_DCDM | UART_V500_INT_DSRM);
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
}

static void hi9030_uart_rx_chars(struct hi9030_uart_port *uap)
__releases(&uap->port.lock)
__acquires(&uap->port.lock)
{
	hi9030_uart_fifo_to_tty(uap);

	spin_unlock(&uap->port.lock);
	tty_flip_buffer_push(&uap->port.state->port);
	if (hi9030_uart_dma_rx_available(uap)) {
		if (hi9030_uart_dma_rx_trigger_dma(uap)) {
			dev_dbg(uap->port.dev, "could not trigger RX DMA job "
				"fall back to interrupt mode again\n");
			uap->int_msk &= ~(UART_V500_INT_RXM |
				UART_V500_INT_RTM);
			hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
		} else {
			uap->int_msk |= UART_V500_INT_RXM;
			uap->int_msk &= (~UART_V500_INT_RTM);
			hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
		}
	}
	spin_lock(&uap->port.lock);
}

static void hi9030_uart_flow_ctrl_status(struct hi9030_uart_port *uap)
{
	unsigned int status, delta;

	status = hi9030_uart_read(uap, REG_UART_STAT) & UART_V500_STAT_CTS;

	delta = status ^ uap->old_status;
	uap->old_status = status;

	if (!delta)
		return;

	if (delta & uap->vendor->stat_cts)
		uart_handle_cts_change(&uap->port, status &
			uap->vendor->stat_cts);

	wake_up_interruptible(&uap->port.state->port.delta_msr_wait);
}

static bool hi9030_uart_tx_char(struct hi9030_uart_port *uap,
	unsigned char c, bool from_irq)
{
	if (unlikely(!from_irq) && (hi9030_uart_read(uap, REG_UART_STAT) &
		UART_V500_STAT_TXFF))
		return false; /* unable to transmit character */

	hi9030_uart_write(c, uap, REG_UART_TX_FIFO);
	uap->port.icount.tx++;

	return true;
}

/* Returns true if tx interrupts have to be (kept) enabled */
static bool hi9030_uart_tx_chars(struct hi9030_uart_port *uap, bool from_irq)
{
	struct circ_buf *xmit = &uap->port.state->xmit;
	int count = uap->fifosize >> 1;

	if (uap->port.x_char) {
		if (!hi9030_uart_tx_char(uap, uap->port.x_char, from_irq))
			return true;
		uap->port.x_char = 0;
		--count;
	}
	if (uart_circ_empty(xmit) || uart_tx_stopped(&uap->port)) {
		hi9030_uart_stop_tx(&uap->port);
		return false;
	}
	/* If we are using DMA mode, try to send some characters */
	if (hi9030_uart_dma_tx_irq(uap))
		return true;

	do {
		if (likely(from_irq) && count-- == 0)
			break;

		if (!hi9030_uart_tx_char(uap, xmit->buf[xmit->tail], from_irq))
			break;

		xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
	} while (!uart_circ_empty(xmit));

	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(&uap->port);

	if (uart_circ_empty(xmit)) {
		hi9030_uart_stop_tx(&uap->port);
		return false;
	}
	return true;
}

static void hi9030_uart_rx_irq_handler(struct hi9030_uart_port *uap)
{
	if (hi9030_uart_dma_rx_running(uap))
		hi9030_uart_dma_rx_irq(uap);
	else
		hi9030_uart_rx_chars(uap);
}

static irqreturn_t hi9030_uart_int_handler(int irq, void *dev_id)
{
	struct hi9030_uart_port *uap = dev_id;
	unsigned long flags;
	unsigned int status;
	int handled = 0;
	unsigned int int_clr;

	spin_lock_irqsave(&uap->port.lock, flags);
	status = hi9030_uart_read(uap, REG_UART_INT_STAT);
	if (status) {
		int_clr = status;
		int_clr &= ~(UART_V500_INT_TXS | UART_V500_INT_RTS |
			UART_V500_INT_RXS);
		hi9030_uart_write(int_clr, uap, REG_UART_INT_CLR);

		if (status & UART_V500_INT_RTS) {
			uap->timeout_irq_cnt++;
			if (uap->timeout_irq_cnt == TIMEOUT_IRQ_MAX_CNT) {
				uap->timeout_irq_cnt = 0;
				hi9030_uart_rx_irq_handler(uap);
			}
		}
		if (status & UART_V500_INT_RXS)
				hi9030_uart_rx_irq_handler(uap);

		if (status & (UART_V500_INT_CTSS | UART_V500_INT_RIS | UART_V500_INT_DCDS | UART_V500_INT_DSRS))
			hi9030_uart_flow_ctrl_status(uap);

		if (status & UART_V500_INT_TXS)
			hi9030_uart_tx_chars(uap, true);

		handled = 1;
	}
	spin_unlock_irqrestore(&uap->port.lock, flags);

	return IRQ_RETVAL(handled);
}

static unsigned int hi9030_uart_tx_empty(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);
	unsigned int status = hi9030_uart_read(uap, REG_UART_STAT);

	return (status & UART_V500_STAT_TXFE) ? 1 : 0;
}

static unsigned int hi9030_uart_get_mctrl(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);
	unsigned int result = 0;
	unsigned int status;

	status = hi9030_uart_read(uap, REG_UART_STAT);
	if (status & uap->vendor->stat_cts)
		result |= TIOCM_CTS;

	return result;
}

static void hi9030_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);
	unsigned int uart_cfg;

	if (mctrl & TIOCM_LOOP) {
		uart_cfg = UART_V500_CFG_LOOP_EN;
		uap->uart_cfg_mask = DEFULT_CONFIG_MASK | UART_LOOP_EN;
	} else {
		uart_cfg = UART_V500_CFG_LOOP_DIS;
		uap->uart_cfg_mask = DEFULT_CONFIG_MASK;
	}

	hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);

	if (uap->auto_rts) {
		/* We need to disable auto-RTS if we want to turn RTS off */
		if (mctrl & TIOCM_RTS)
			uart_cfg = UART_V500_CFG_RTS_EN;
		else
			uart_cfg = UART_V500_CFG_RTS_DIS;

		hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);
	}
}

static void hi9030_uart_break_ctl(struct uart_port *port, int break_state)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);
	unsigned long flags;
	unsigned int brk_cfg;

	spin_lock_irqsave(&uap->port.lock, flags);
	if (break_state == -1)
		brk_cfg = UART_V500_CFG_BRK_EN;
	else
		brk_cfg = UART_V500_CFG_BRK_DIS;
	hi9030_uart_write(brk_cfg, uap, REG_UART_CONFIG);
	spin_unlock_irqrestore(&uap->port.lock, flags);
}

static int hi9030_uart_hwinit(struct uart_port *port)
{
	struct hi9030_uart_port *uap = container_of(port,
		struct hi9030_uart_port, port);
	int retval;

	/* Optionaly enable pins to be muxed in and configured */
	pinctrl_pm_select_default_state(port->dev);
	if (uap->uart_num == IODIE_IP_UART1) {
		iodie_writel(IODIE_IP_PERI_CRG, PERI_CRG_BUS_CLK_SEL, IODIE_UART1_CLK_SEL);
	} else if (uap->uart_num == IODIE_IP_UART2) {
		iodie_writel(IODIE_IP_PERI_CRG, PERI_CRG_BUS_CLK_SEL, IODIE_UART2_CLK_SEL);
	} else {
		dev_err(port->dev, "%s: iodie clk enable failed\n", __func__);
	}
	iodie_clk_en(uap->uart_num);
	/* Clear pending error and receive interrupts */
	hi9030_uart_write(UART_V500_INT_STAUS, uap, REG_UART_INT_CLR);
	/*
	 * Save interrupts enable mask, and enable RX interrupts in case if
	 * the interrupt is used for NMI entry.
	 */
	uap->int_msk = hi9030_uart_read(uap, REG_UART_INT_MSK);
	hi9030_uart_write(~(UART_V500_INT_RXM | UART_V500_INT_RTM) &
		UART_V500_MSK_INT_ALL, uap, REG_UART_INT_MSK);

	/* Optionaly enable pins to be muxed in and configured */
	if (!IS_ERR(uap->pinctrls_default)) {
		retval = pinctrl_select_state(uap->pinctrl,
			uap->pinctrls_default);
		if (retval) {
			dev_err(port->dev, "could not set default pins\n");
			return retval;
		}
	}
	return 0;
}

static int hi9030_uart_allocate_irq(struct hi9030_uart_port *uap)
{
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);

	return request_irq(uap->port.irq, hi9030_uart_int_handler, 0,
		"hi9030_uart_v500", uap);
}

static void hi9030_uart_enable_interrupts(struct hi9030_uart_port *uap)
{
	unsigned int i;

	spin_lock_irq(&uap->port.lock);
	/* Clear out any spuriously appearing RX interrupts */
	hi9030_uart_write(UART_V500_INT_RTS | UART_V500_INT_RXS, uap,
		REG_UART_INT_CLR);

	for (i = 0; i < uap->fifosize * 2; ++i) {
		if (hi9030_uart_read(uap, REG_UART_STAT) & UART_V500_STAT_RXFE)
			break;

		hi9030_uart_read(uap, REG_UART_RX_FIFO);
	}

	uap->int_msk = (~UART_V500_INT_RTM);
	hi9030_uart_write(uap->int_msk, uap, REG_UART_INT_MSK);
	spin_unlock_irq(&uap->port.lock);
}

static int hi9030_uart_startup(struct uart_port *port)
{
	struct hi9030_uart_port *uap = container_of(port,
		struct hi9030_uart_port, port);
	unsigned int uart_cfg;
	int retval;

	retval = iodie_normal_request(uap->uart_user, IODIE_RT_NORMAL_LOW);
	if (retval) {
		dev_info(port->dev, "ttyIOD%d iodie_normal_request failed\n", port->line);
		return retval;
	}
	dev_info(port->dev, "%s: ttyIOD%d\n", __func__, port->line);

	hi9030_uart_chip_reset_endisable(uap, 1);
	hi9030_uart_chip_reset_endisable(uap, 0);

	retval = iodie_fnpll_request(uap->uart_user);
	if (retval) {
		dev_info(port->dev, "ttyIOD%d iodie_fnpll_request failed\n", port->line);
		return retval;
	}
	retval = hi9030_uart_hwinit(port);
	if (retval)
		goto clk_dis;
	retval = hi9030_uart_allocate_irq(uap);
	if (retval)
		goto clk_dis;

	if (cpu_online(A53_CLUSTER0_CPU1)) {
		retval = irq_set_affinity(uap->port.irq, cpumask_of(A53_CLUSTER0_CPU1));
		if (retval)
			pr_err("bind uart%d interrupt to cpu1 failed\n", port->line);
		else
			pr_err("bind uart%d interrupt to cpu1 sucess\n", port->line);
	}
	hi9030_uart_write(uap->vendor->fifo_cfg, uap, REG_UART_FIFO_CFG);

	spin_lock_irq(&uap->port.lock);

	uap->uart_cfg_mask = DEFULT_CONFIG_MASK;
	uart_cfg = uap->old_config;
	uart_cfg &= uap->uart_cfg_mask;
	uart_cfg |= UART_V500_CFG_UART_EN | UART_V500_CFG_RX_EN |
		UART_V500_CFG_TX_EN | UART_V500_CFG_FIFO_EN;
	hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);

	hi9030_uart_flow_ctrl_status(uap);

	spin_unlock_irq(&uap->port.lock);
	/* Startup DMA */
	hi9030_uart_dma_startup(uap);
	uap->timeout_irq_cnt = 0;
	hi9030_uart_enable_interrupts(uap);

	return 0;

clk_dis:
	iodie_clk_dis(uap->uart_num);
	iodie_fnpll_release(uap->uart_user);
	iodie_normal_release(uap->uart_user, IODIE_RT_NORMAL_LOW);
	return retval;
}

/*
 * disable the port. It should not disable RTS and DTR.
 * Also RTS and DTR state should be preserved to restore
 * it during startup().
 */
static void hi9030_uart_disable_uart(struct hi9030_uart_port *uap)
{
	unsigned int uart_cfg;

	uap->auto_rts = false;
	spin_lock_irq(&uap->port.lock);
	uart_cfg = hi9030_uart_read(uap, REG_UART_CONFIG);
	uart_cfg &= uap->uart_cfg_mask;
	uart_cfg |= (uart_cfg << UART_CONFIG_BIT_MASK);	
	uap->old_config = uart_cfg;
	uart_cfg = (UART_V500_CFG_TX_EN | UART_V500_CFG_UART_EN | UART_V500_CFG_FIFO_EN);
	hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);
	spin_unlock_irq(&uap->port.lock);

	/*
	 * disable break condition
	 */
	hi9030_uart_write(UART_V500_CFG_BRK_DIS, uap, REG_UART_CONFIG);
}

static void hi9030_uart_disable_interrupts(struct hi9030_uart_port *uap)
{
	spin_lock_irq(&uap->port.lock);
	/* mask all interrupts and clear all pending ones */
	hi9030_uart_write(UART_V500_MSK_INT_ALL, uap, REG_UART_INT_MSK);
	hi9030_uart_write(UART_V500_CLR_INT_ALL, uap, REG_UART_INT_CLR);
	spin_unlock_irq(&uap->port.lock);
}

static void hi9030_uart_shutdown(struct uart_port *port)
{
	struct hi9030_uart_port *uap =
		container_of(port, struct hi9030_uart_port, port);
	int retval;

	dev_info(port->dev, "%s: ttyIOD%d\n", __func__, port->line);
	disable_irq(uap->port.irq);

	hi9030_uart_disable_interrupts(uap);

	hi9030_uart_dma_shutdown(uap);

	uap->uart_cfg_mask = DEFULT_CONFIG_MASK;
	free_irq(uap->port.irq, uap);
	hi9030_uart_disable_uart(uap);
	/*
	 * Shut down the clock producer
	 */
	iodie_clk_dis(uap->uart_num);
	/* Optionally let pins go into sleep states */
	if (!IS_ERR(uap->pinctrls_idle)) {
		retval = pinctrl_select_state(uap->pinctrl, uap->pinctrls_idle);
		if (retval)
			dev_err(port->dev, "can't set pins to sleep state\n");
	}
	iodie_fnpll_release(uap->uart_user);
	iodie_normal_release(uap->uart_user, IODIE_RT_NORMAL_LOW);
}

static void hi9030_uart_setup_status_masks(struct uart_port *port,
	struct ktermios *termios)
{
	port->read_status_mask = UART_V500_DR_OE | 255;
	if (termios->c_iflag & INPCK)
		port->read_status_mask |= UART_V500_DR_FE | UART_V500_DR_PE;
	if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
		port->read_status_mask |= UART_V500_DR_BE;

	/*
	 * Characters to ignore
	 */
	port->ignore_status_mask = 0;
	if (termios->c_iflag & IGNPAR)
		port->ignore_status_mask |= UART_V500_DR_FE | UART_V500_DR_PE;
	if (termios->c_iflag & IGNBRK) {
		port->ignore_status_mask |= UART_V500_DR_BE;
		/*
		 * If we're ignoring parity and break indicators,
		 * ignore overruns too (for real raw support).
		 */
		if (termios->c_iflag & IGNPAR)
			port->ignore_status_mask |= UART_V500_DR_OE;
	}
}

static void hi9030_uart_set_frame(struct hi9030_uart_port *uap,
	struct ktermios *termios)
{
	unsigned int frame_cfg;

	switch (termios->c_cflag & CSIZE) {
	case CS5:
		frame_cfg = UART_V500_FRAME_LEN_5;
		break;
	case CS6:
		frame_cfg = UART_V500_FRAME_LEN_6;
		break;
	case CS7:
		frame_cfg = UART_V500_FRAME_LEN_7;
		break;
	default: /* CS8 */
		frame_cfg = UART_V500_FRAME_LEN_8;
		break;
	}
	if (termios->c_cflag & CSTOPB)
		frame_cfg |= UART_V500_FRAME_STOP;
	if (termios->c_cflag & PARENB) {
		if (!(termios->c_cflag & PARODD))
			frame_cfg |= UART_V500_FRAME_POS;
		if (termios->c_cflag & CMSPAR)
			frame_cfg &= (~UART_V500_FRAME_NPS);
	}
	hi9030_uart_write(frame_cfg, uap, REG_UART_FRAME);
}

static void hi9030_uart_set_uart_cfg(struct hi9030_uart_port *uap,
	struct ktermios *termios)
{
	unsigned int uart_cfg;

	/* store the uart cfg old status */
	uart_cfg = hi9030_uart_read(uap, REG_UART_CONFIG);
	uart_cfg &= uap->uart_cfg_mask;
	uart_cfg |= (uart_cfg << UART_CONFIG_BIT_MASK);
	/* first, disable everything */
	hi9030_uart_write(UART_V500_CFG_DIS_ALL, uap, REG_UART_CONFIG);

	if (uap->fifosize > 1)
		uart_cfg |= (UART_V500_CFG_RX_EN | UART_V500_CFG_TX_EN |
			UART_V500_CFG_UART_EN | UART_V500_CFG_FIFO_EN);

	if (termios->c_cflag & CRTSCTS) {
		uart_cfg |= UART_V500_CFG_RTS_EN | UART_V500_CFG_CTS_EN;
		hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);
		uap->auto_rts = true;
	} else {
		hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);
		uart_cfg = (UART_V500_CFG_CTS_DIS | UART_V500_CFG_RTS_DIS);
		hi9030_uart_write(uart_cfg, uap, REG_UART_CONFIG);
		uap->auto_rts = false;
	}
}

static void hi9030_uart_set_termios(struct uart_port *port,
	struct ktermios *termios, struct ktermios *old)
{
	struct hi9030_uart_port *uap = container_of(port,
		struct hi9030_uart_port, port);
	unsigned long flags;
	unsigned int baud, quot, quotn;
	unsigned int count = 0;

	baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk / 16);
	if (!baud) {
		dev_err(port->dev, "%s error baud!\n", __func__);
		return;
	}

	if (baud > port->uartclk / 16)
		quot = DIV_ROUND_CLOSEST(port->uartclk * 8, baud);
	else
		quot = DIV_ROUND_CLOSEST(port->uartclk * 4, baud);

	hi9030_uart_set_frame(uap, termios);

	spin_lock_irqsave(&port->lock, flags);

	uart_update_timeout(port, termios->c_cflag, baud);

	hi9030_uart_setup_status_masks(port, termios);

	if (UART_ENABLE_MS(port, termios->c_cflag))
		hi9030_uart_enable_msk(port);
	else
		hi9030_uart_disable_msk(port);

	hi9030_uart_set_uart_cfg(uap, termios);

	while ((hi9030_uart_read(uap, REG_UART_STAT) & uap->vendor->stat_busy) &&
		(count < TXFF_TIMEOUT)) {
		udelay(1);
		count++;
		barrier();
	}

	/* Set baud rate */
	quotn = quot;
	quot = (quot & UART_BAUD_FRAC_MASK) << UART_CONFIG_BIT_MASK;
	quotn = (quotn >> 6) & UART_BAUD_INT_MASK;
	quot |= quotn;

	hi9030_uart_write(quot, uap, REG_UART_BAUD);
	spin_unlock_irqrestore(&port->lock, flags);
}

static const char *hi9030_uart_type(struct uart_port *port)
{
	struct hi9030_uart_port *uap = container_of(port,
		struct hi9030_uart_port, port);

	return uap->port.type == PORT_HI9030_UART_V500 ? uap->uart_type : NULL;
}

/*
 * Release the memory region(s) being used by 'port'
 */
static void hi9030_uart_release_port(struct uart_port *port)
{
	release_mem_region(port->mapbase, SZ_4K);
}

/*
 * Request the memory region(s) being used by 'port'
 */
static int hi9030_uart_request_port(struct uart_port *port)
{
	return request_mem_region(port->mapbase, SZ_4K, "hi9030_uart_v500")
		!= NULL ? 0 : -EBUSY;
}

/*
 * Configure auto configure the port.
 */
static void hi9030_uart_config_port(struct uart_port *port, int flags)
{
	if ((unsigned int)flags & UART_CONFIG_TYPE) {
		port->type = PORT_HI9030_UART_V500;
		hi9030_uart_request_port(port);
	}
}

/*
 * verify the new serial_struct (for TIOCSSERIAL).
 */
static int hi9030_uart_verify_port(struct uart_port *port,
	struct serial_struct *serial)
{
	int val = 0;

	if (serial->type != PORT_UNKNOWN && serial->type != PORT_HI9030_UART_V500)
		val = -EINVAL;
	if (serial->irq < 0 || serial->irq >= nr_irqs)
		val = -EINVAL;
	if (serial->baud_base < 9600)
		val = -EINVAL;

	return val;
}

static const struct uart_ops hi9030_uart_pops = {
	.tx_empty	= hi9030_uart_tx_empty,
	.set_mctrl	= hi9030_uart_set_mctrl,
	.get_mctrl	= hi9030_uart_get_mctrl,
	.stop_tx	= hi9030_uart_stop_tx,
	.start_tx	= hi9030_uart_start_tx,
	.stop_rx	= hi9030_uart_stop_rx,
	.enable_ms	= hi9030_uart_enable_msk,
	.break_ctl	= hi9030_uart_break_ctl,
	.startup	= hi9030_uart_startup,
	.shutdown	= hi9030_uart_shutdown,
	.flush_buffer	= hi9030_uart_dma_flush_buffer,
	.set_termios	= hi9030_uart_set_termios,
	.type		= hi9030_uart_type,
	.release_port	= hi9030_uart_release_port,
	.request_port	= hi9030_uart_request_port,
	.config_port	= hi9030_uart_config_port,
	.verify_port	= hi9030_uart_verify_port,
	.pm		= hi9030_uart_pm,
};

static void hi9030_uart_unregister_port(struct hi9030_uart_port *uap)
{
	unsigned int i;
	bool busy = false;

	for (i = 0; i < ARRAY_SIZE(hi9030_uart_ports_ne); i++) {
		if (hi9030_uart_ports_ne[i] == uap)
			hi9030_uart_ports_ne[i] = NULL;
		else if (hi9030_uart_ports_ne[i])
			busy = true;
	}

	hi9030_uart_dma_remove(uap);
	if (!busy)
		uart_unregister_driver(&g_hi9030_uart_v500);
}

static int hi9030_uart_setup_port(struct device *dev, struct hi9030_uart_port *uap,
	struct resource *mmiobase, int index)
{
	int ret;
	unsigned long long uart_clock_rate = 0;
	struct platform_device *pdev = container_of(dev,
		struct platform_device, dev);

	index = hi9030_uart_probe_dt_alias(index, dev);
	ret = uart_v500_pinctrl(pdev, uap);
	if (ret) {
		dev_err(&pdev->dev, "%s get pinctrl failed!\n", __func__);
		return ret;
	}
	uap->old_config = 0;
	uap->port.dev = dev;
	uap->port.mapbase = mmiobase->start;
	uap->port.fifosize = uap->fifosize;
	uap->port.flags = UPF_BOOT_AUTOCONF;
	uap->port.line = index;
	hi9030_uart_ports_ne[index] = uap;

	ret = hi9030_uart_reset_func_init(pdev, uap);
	if (ret)
		dev_err(&pdev->dev, "%s not enable reset func!\n", __func__);

	ret = of_property_read_u64(pdev->dev.of_node, "clock-rate", &uart_clock_rate);
	if (!ret && (uart_clock_rate > 0)) {
		dev_info(&pdev->dev, "reset clock rate[%Ld]!\n", uart_clock_rate);
	} else {
		dev_info(&pdev->dev, "iodie UART%d haven't clock-rate cfg\n", index);
	}
	uap->port.uartclk = uart_clock_rate;

	return 0;
}

static int hi9030_uart_register_port(struct hi9030_uart_port *uap)
{
	int ret;
	int retval;

	retval = iodie_normal_request(uap->uart_user, IODIE_RT_NORMAL_LOW);
	if (retval) {
		dev_info(uap->port.dev, "ttyIOD%d iodie_normal_request failed\n", uap->port.line);
		return retval;
	}
	retval = iodie_fnpll_request(uap->uart_user);
	if (retval) {
		dev_info(uap->port.dev, "ttyIOD%d iodie_fnpll_request failed\n", uap->port.line);
		return retval;
	}
	iodie_clk_en(uap->uart_num);

	hi9030_uart_chip_reset_endisable(uap, 0);

	ret = uart_add_one_port(&g_hi9030_uart_v500, &uap->port);
	if (ret) {
		hi9030_uart_unregister_port(uap);
	}

	iodie_clk_dis(uap->uart_num);
	iodie_fnpll_release(uap->uart_user);
	iodie_normal_release(uap->uart_user, IODIE_RT_NORMAL_LOW);

	return ret;
}

static int hi9030_uart_v500_probe(struct platform_device *pdev)
{
	struct hi9030_uart_port *uap = NULL;
	struct vendor_data *vendor = &g_vendor_hi9030_uart;
	int port_num, ret;
	struct resource *resource = NULL;

	pr_err("%s: enter\n", __func__);
	port_num = hi9030_uart_find_free_port();
	if (port_num < 0)
		return port_num;

	uap = devm_kzalloc(&pdev->dev, sizeof(struct hi9030_uart_port), GFP_KERNEL);
	if (!uap)
		return -ENOMEM;

	uap->rx_sg = devm_kzalloc(&pdev->dev, sizeof(struct hi9030_uart_rx_sgbuf), GFP_KERNEL);
	if (!uap->rx_sg)
		return -ENOMEM;

	if (of_property_read_u32(pdev->dev.of_node, "hi9030-uart-module", &uap->uart_num)) {
		pr_err("%s: get hi9030-uart-module failed\n", __func__);
		uap->uart_num = 0;
	}
	if (of_property_read_u32(pdev->dev.of_node, "uart-iodie-user", &uap->uart_user)) {
		pr_err("%s: get uart-iodie-user failed\n", __func__);
		uap->uart_user = 0;
	}
	if (of_property_read_u32(pdev->dev.of_node, "enable-dma", &uap->enable_dma)) {
		pr_err("%s: get enable-dma failed\n", __func__);
		uap->enable_dma = 0;
	}
	uap->rx_global_sg_buf_alloced = false;
	if (of_property_read_u32(pdev->dev.of_node, "rx-use-global-sg-buf",
		&uap->rx_use_global_sg_buf))
		uap->rx_use_global_sg_buf = 0;

	uap->reg_offset = vendor->reg_offset;
	uap->vendor = vendor;
	uap->fifosize = FIFO_SIZE_UART_V500;
	uap->port.iotype = vendor->access_32b ? UPIO_MEM32 : UPIO_MEM;
	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		pr_err("%s: get irq failed %d\n", __func__, ret);
		return ret;
	}
	uap->port.irq = ret;
	uap->port.ops = &hi9030_uart_pops;

	ret = snprintf_s(uap->uart_type, sizeof(uap->uart_type),
		sizeof("hi9030_uart"), "%s", "hi9030_uart");
	if (ret < 0) {
		pr_err("%s: snprintf_s fail %d\n", __func__, ret);
		return ret;
	}

	resource = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ret = hi9030_uart_setup_port(&pdev->dev, uap, resource, port_num);
	if (ret)
		return ret;

	platform_set_drvdata(pdev, uap);

	return hi9030_uart_register_port(uap);
}

static int hi9030_uart_v500_remove(struct platform_device *pdev)
{
	struct hi9030_uart_port *uap = platform_get_drvdata(pdev);

	devm_pinctrl_put(uap->pinctrl);

	uart_remove_one_port(&g_hi9030_uart_v500, &uap->port);
	hi9030_uart_unregister_port(uap);
	return 0;
}

#if defined(CONFIG_OF)
static const struct of_device_id hi9030_uart_ids[] = {
	{ .compatible = "hisilicon,hi9030_uart" },
	{ },
};
#endif

static SIMPLE_DEV_PM_OPS(hi9030_uart_dev_pm_ops,
	hi9030_uart_suspend, hi9030_uart_resume);

static struct platform_driver hi9030_uart_platform_driver = {
	.probe = hi9030_uart_v500_probe,
	.remove = hi9030_uart_v500_remove,
	.driver = {
		.name = "hi9030_uart_v500",
		.pm = &hi9030_uart_dev_pm_ops,
		.of_match_table = of_match_ptr(hi9030_uart_ids),
	},
};

static int __init hi9030_uart_v500_init(void)
{
	int ret;

	printk(KERN_ERR "Serial: Hi9030 UART V500 driver\n");
	ret = uart_register_driver(&g_hi9030_uart_v500);
	if (ret) {
		printk(KERN_ERR "hi9030 uart_register_driver fail\n");
		return ret;
	}
	ret = platform_driver_register(&hi9030_uart_platform_driver);
	if (ret) {
		printk(KERN_ERR "hi9030 uart platform_driver_register fail\n");
		uart_unregister_driver(&g_hi9030_uart_v500);
	}

	return ret;
}

static void __exit hi9030_uart_v500_exit(void)
{
	platform_driver_unregister(&hi9030_uart_platform_driver);
	uart_unregister_driver(&g_hi9030_uart_v500);
}

subsys_initcall_sync(hi9030_uart_v500_init);
module_exit(hi9030_uart_v500_exit);

MODULE_DESCRIPTION("hi9030 UART V500 port driver");
MODULE_LICENSE("GPL");
