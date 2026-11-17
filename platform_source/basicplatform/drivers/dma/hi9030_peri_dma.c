/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Iodie DesignWare DMA adapter driver.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 */
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_dma.h>
#include <linux/pm.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/version.h>
#include <platform_include/basicplatform/linux/pr_log.h>
#include "virt-dma.h"
#include <linux/dmaengine.h>
#include <securec.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
 
#define PR_LOG_TAG "hi9030-dma64"
#define DRIVER_NAME "hi9030-dma"
#define DMA_ALIGN               3
#define DMA_REG_CFG_NUM         4
#define DMA_MAX_SIZE            0x1ffc
#define DMA_RESET_WAIT_TIME     10

#define IODIE_INT_STAT          0x00
#define IODIE_INT_TC1           0x04
#define IODIE_INT_ERR1          0x0c
#define IODIE_INT_ERR2          0x10
#define IODIE_INT_TC1_MASK      0x18
#define IODIE_INT_ERR1_MASK     0x20
#define IODIE_INT_ERR2_MASK     0x24
#define IODIE_INT_TC1_RAW       0x600
#define IODIE_INT_TC2_RAW       0x608
#define IODIE_INT_ERR1_RAW      0x610
#define IODIE_INT_ERR2_RAW      0x618
#define IODIE_IODIE_CH_STAT     0x690
#define IODIE_DMA_CTRL          0x698
#define CH_CUR_CNT              0x404
#define CH_LLI_H                0x804
#define CH_LLI_L                0x800
#define CH_CNT                  0x81C
#define CH_SRC_L                0x820
#define CH_SRC_H                0x824
#define CH_DST_L                0x828
#define CH_DST_H                0x82C
#define IODIE_CX_CONFIG         0x830
#define AXI_CONFIG              0x834
 
#define CCFG_SRCINCR (0x1UL << 31)
#define CCFG_DSTINCR (0x1UL << 30)
#define CX_LLI_CHAN_EN 0x2
#define IODIE_DMA_CCFG_EN 0x1
#define CCFG_MEM2PER (0x1 << 2)
#define GET_LOW_32BIT(a) ((u32)((u64)(a) & 0xffffffff))
#define GET_HIGH_32BIT(a) ((u32)((u64)(a) >> 32))
#define U32_TO_U64(u32h, u32l) ((u64)(u32l) | ((u64)(u32h) << 32))
 
#define DMA_CH_CFG_PERI 4
#define DMA_CH_CFG_DW   12
#define DMA_CH_CFG_SW   16
#define DMA_CH_CFG_DL   20
#define DMA_CH_CFG_SL   24
#define DMA_2BITS_MASK  0x3
 
#define DMA_MAX_BURST 16
#define DMA_WAIT_PHY_STATUS_TIMEOUT 2000
 
#define DMA_SLAVE_BUS_WIDTH_VAL_1BYTE 0
#define DMA_SLAVE_BUS_WIDTH_VAL_2BYTE 1
#define DMA_SLAVE_BUS_WIDTH_VAL_4BYTE 2
#define DMA_SLAVE_BUS_WIDTH_VAL_8BYTE 8

#define CURRENT_COUNT_OFFSET   0x20
#define DMA_CHAN_OFFSET        0x40

#define UART1_TX_ADDR          0xfdf66400
#define UART2_TX_ADDR          0xfdf67400
#define UART1_RX_ADDR          0xfdf66800
#define UART2_RX_ADDR          0xfdf67800
#define UART1_TX_BUFF_ADDR     0xfdf31000
#define UART2_TX_BUFF_ADDR     0xfdf35000
#define UART1_RX_BUFF_A_ADDR   0xfdf32000
#define UART2_RX_BUFF_A_ADDR   0xfdf36000
#define UART1_RX_BUFF_B_ADDR   0xfdf33000
#define UART2_RX_BUFF_B_ADDR   0xfdf37000

struct hi9030_dma_desc_hw {
	u64 lli;
	u32 reserved1[5];
	u32 count;
	u64 saddr;
	u64 daddr;
	u32 config;
	u32 reserved2[3];
} __aligned(64);
 
struct hi9030_dma_desc_sw {
	struct virt_dma_desc vd;
	dma_addr_t desc_hw_lli;
	size_t desc_num;
	size_t size;
	struct hi9030_dma_desc_hw desc_hw[0];
};
 
struct hi9030_dma_phy;
struct hi9030_dma_chan {
	u32 ccfg;
	struct virt_dma_chan vc;
	struct hi9030_dma_phy *phy;
	struct list_head node;
	enum dma_transfer_direction dir;
	dma_addr_t dev_addr;
	enum dma_status status;
};
 
struct hi9030_dma_phy {
	u32 idx;
	u32 offset;
	struct hi9030_dma_chan *vchan;
	struct hi9030_dma_desc_sw *ds_run;
	struct hi9030_dma_desc_sw *ds_done;
};

 struct hi9030_dma_rx_sgbuf {
	struct scatterlist sg;
	char *buf;
	bool use_buf_b;
};

struct hi9030_dma_dev {
	struct dma_device slave;
	struct tasklet_struct task;
	spinlock_t lock;
	struct list_head chan_pending;
	struct hi9030_dma_phy *phy;
	struct hi9030_dma_chan *chans;
	u32 dma_channels;
	u32 dma_requests;
	u32 hi9030_dma_module;
	u32 dma_used_chans;
	u32 reset_reg;
	u32 reset_val;
	int dma_irq;
	bool dma_irq_flag;
};

static void hi9030_peri_dma_config(struct hi9030_dma_dev *d);

#define to_hi9030_dma_dev(dmadev) container_of(dmadev, struct hi9030_dma_dev, slave)
 
static struct hi9030_dma_chan *to_hi9030_dma_chan(struct dma_chan *chan)
{
	return container_of(chan, struct hi9030_dma_chan, vc.chan);
}
 
static void hi9030_dma_pause(struct hi9030_dma_phy *phy,
	struct hi9030_dma_dev *d, bool on)
{
	u32 val;
	int timeout;
 
	if (on) {
		val = iodie_readl(d->hi9030_dma_module, phy->offset + IODIE_CX_CONFIG);
		val |= IODIE_DMA_CCFG_EN;
		iodie_writel(d->hi9030_dma_module, phy->offset + IODIE_CX_CONFIG, val);
		*(int *)(phy->vchan->vc.chan.private) = 1;
	} else {
		val = iodie_readl(d->hi9030_dma_module, phy->offset + IODIE_CX_CONFIG);
		val &= ~IODIE_DMA_CCFG_EN;
		iodie_writel(d->hi9030_dma_module, phy->offset + IODIE_CX_CONFIG, val);
		*(int *)(phy->vchan->vc.chan.private) = 0;
		/* Wait for channel inactive */
		for (timeout = DMA_WAIT_PHY_STATUS_TIMEOUT;
			timeout > 0; timeout--) {
			if (!(BIT(phy->idx) & (u64)iodie_readl(d->hi9030_dma_module, IODIE_IODIE_CH_STAT)))
				break;
			iodie_writel(d->hi9030_dma_module, phy->offset + IODIE_CX_CONFIG, val);
			/* delay 1us */
			udelay(1);
		}
 
		if (!timeout)
			pr_err("channel%u timeout wait for pause\n", phy->idx);
	}
}
 
static void hi9030_dma_terminate_chan(struct hi9030_dma_phy *phy,
	struct hi9030_dma_dev *d)
{
	u32 val;
 
	hi9030_dma_pause(phy, d, false);
 
	/* phy->idx must be 0~15 */
	val = (u32)0x1 << phy->idx;
	iodie_writel(d->hi9030_dma_module, IODIE_INT_TC1_RAW, val);
	iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR1_RAW, val);
	iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR2_RAW, val);
}
 
static void hi9030_dma_set_desc(struct hi9030_dma_dev *d,
	struct hi9030_dma_phy *phy, struct hi9030_dma_desc_hw *hw)
{
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_LLI_H, GET_HIGH_32BIT(hw->lli));
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_LLI_L, GET_LOW_32BIT(hw->lli));
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_CNT, hw->count);
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_SRC_H, GET_HIGH_32BIT(hw->saddr));
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_SRC_L, GET_LOW_32BIT(hw->saddr));
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_DST_H, GET_HIGH_32BIT(hw->daddr));
	iodie_writel(d->hi9030_dma_module, phy->offset + CH_DST_L, GET_LOW_32BIT(hw->daddr));
	iodie_writel(d->hi9030_dma_module, phy->offset + IODIE_CX_CONFIG, hw->config);
}
 
static u32 hi9030_dma_get_curr_cnt(struct hi9030_dma_dev *d,
	struct hi9030_dma_phy *phy)
{
	u32 cnt;
 
	cnt = iodie_readl(d->hi9030_dma_module, CH_CUR_CNT + phy->idx *
		CURRENT_COUNT_OFFSET);
	cnt &= 0xffff; /* current count mask bits */
 
	return cnt;
}
 
static u64 hi9030_dma_get_curr_lli(struct hi9030_dma_dev *d,
	struct hi9030_dma_phy *phy)
{
	return U32_TO_U64(iodie_readl(d->hi9030_dma_module, phy->offset + CH_LLI_H),
		iodie_readl(d->hi9030_dma_module, phy->offset + CH_LLI_L));
}
 
static u32 hi9030_dma_get_chan_stat(struct hi9030_dma_dev *d)
{
	return iodie_readl(d->hi9030_dma_module, IODIE_IODIE_CH_STAT);
}
 
static void hi9030_dma_enable_dma(struct hi9030_dma_dev *d, bool on)
{
	if (on) {
		/* unmask irq */
		iodie_writel(d->hi9030_dma_module, IODIE_INT_TC1_MASK, d->dma_used_chans);
		iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR1_MASK, d->dma_used_chans);
		iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR2_MASK, d->dma_used_chans);
	} else {
		/* mask irq */
		iodie_writel(d->hi9030_dma_module, IODIE_INT_TC1_MASK, 0x0);
		iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR1_MASK, 0x0);
		iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR2_MASK, 0x0);
	}
}
 
static void hi9030_dma_tc1_int_prehdl(struct hi9030_dma_dev *d,
	u32 *tc1_irq, u32 i, u32 stats)
{
	struct hi9030_dma_chan *c = NULL;
	struct hi9030_dma_phy *p = NULL;
	unsigned long flag;
 
	spin_lock_irqsave(&d->lock, flag);
	p = &d->phy[i];
	c = p->vchan;
	if (c) {
		spin_lock(&c->vc.lock);
		if (p->ds_run)
			vchan_cookie_complete(&p->ds_run->vd);
		p->ds_done = p->ds_run;
		spin_unlock(&c->vc.lock);
	} else {
		dev_err(d->slave.dev, "%s: phy[%u] stats[0x%x]\n", __func__,
			p->idx, stats);
	}
 
	*tc1_irq = (*tc1_irq) | (u32)BIT(i);
	spin_unlock_irqrestore(&d->lock, flag);
}
 
static void hi9030_dma_err_int_prehdl(struct hi9030_dma_dev *d, u32 i)
{
	struct hi9030_dma_chan *c = NULL;
	struct hi9030_dma_phy *p = NULL;

	spin_lock(&d->lock);
	p = &d->phy[i];
	c = p->vchan;
	if (c)
		c->status = DMA_ERROR;
	spin_unlock(&d->lock);
}
 
static irqreturn_t hi9030_peri_dma_int_handler(int irq, void *dev_id)
{
	struct hi9030_dma_dev *d = (struct hi9030_dma_dev *)dev_id;
	u32 stat = iodie_readl(d->hi9030_dma_module, IODIE_INT_STAT);
	u32 tc1 = iodie_readl(d->hi9030_dma_module, IODIE_INT_TC1);
	u32 err1 = iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR1);
	u32 err2 = iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR2);
	u32 i;
	u32 tc1_irq = 0;
	u32 err1_irq = 0;
	u32 err2_irq = 0;
	u32 stats = stat;
 
	if (d->dma_irq_flag == 0) {
		iodie_writel(d->hi9030_dma_module, IODIE_INT_TC1_RAW, tc1);
		iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR1_RAW, err1);
		iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR2_RAW, err2);
		dev_info(d->slave.dev, "clear abnormal dma irq\n");
		return IRQ_HANDLED;
	}
 
	while (stat) {
		i = (u32)__ffs((unsigned long)stat);
		stat &= (stat - 1);
 
		if (i >= d->dma_channels)
			continue;
 
		if (likely(tc1 & BIT(i)))
			hi9030_dma_tc1_int_prehdl(d, &tc1_irq, i, stats);
 
		if (unlikely((err1 & BIT(i)) || (err2 & BIT(i)))) {
			hi9030_dma_err_int_prehdl(d, i);
 
			if (err1 & BIT(i))
				err1_irq |= (u32)BIT(i);
 
			if (err2 & BIT(i))
				err2_irq |= (u32)BIT(i);
 
			dev_warn(d->slave.dev,
				"DMA ERR phy:%u st:0x%x err1:0x%x err2:0x%x\n",
				d->phy[i].idx, stats, err1, err2);
		}
	}
 
	iodie_writel(d->hi9030_dma_module, IODIE_INT_TC1_RAW, tc1_irq);
	iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR1_RAW, err1_irq);
	iodie_writel(d->hi9030_dma_module, IODIE_INT_ERR2_RAW, err2_irq);
 
	if (tc1_irq || err1_irq || err2_irq) {
		spin_lock(&d->lock);
		hi9030_peri_dma_config(d);
		spin_unlock(&d->lock);
		return IRQ_HANDLED;
	}
 
	return IRQ_NONE;
}
 
static int hi9030_dma_start_txd(struct hi9030_dma_chan *chan)
{
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->vc.chan.device);
	struct virt_dma_desc *vd = vchan_next_desc(&chan->vc);
 
	if (!chan->phy) {
		dev_dbg(d->slave.dev, "%s: dma chan phy is NULL\n", __func__);
		return -ENODEV;
	}
 
	if (BIT(chan->phy->idx) & hi9030_dma_get_chan_stat(d)) {
		dev_err(d->slave.dev, "%s: chan[%d] phy[%u] stat[0x%x]\n",
			__func__, chan->vc.chan.chan_id, chan->phy->idx,
			hi9030_dma_get_chan_stat(d));
		return -EBUSY;
	}
 
	if (vd) {
		struct hi9030_dma_desc_sw *ds =
			container_of(vd, struct hi9030_dma_desc_sw, vd);

		list_del(&ds->vd.node);
		chan->phy->ds_run = ds;
		chan->phy->ds_done = NULL;

		hi9030_dma_set_desc(d, chan->phy, &ds->desc_hw[0]);
		if (chan->ccfg & IODIE_DMA_CCFG_EN)
			*(int *)(chan->vc.chan.private) = 1;
		else
			*(int *)(chan->vc.chan.private) = 0;
 
		return 0;
	}
 	chan->phy->ds_done = NULL;
	chan->phy->ds_run = NULL;
 
	return -EAGAIN;
}
 
static void hi9030_dma_chk_running_dma(struct hi9030_dma_chan *c,
	struct hi9030_dma_dev *d)
{
	struct hi9030_dma_phy *p = NULL;
	int ret;
 
	if (!c) {
		dev_err(d->slave.dev, "%s:c is NULL\n", __func__);
		return;
	}
 
	p = c->phy;
	if (p && p->ds_done) {
		ret = hi9030_dma_start_txd(c);
		if (ret == -EAGAIN) {
			/* No current txd associated with this channel */
			dev_dbg(d->slave.dev, "pchan %u: free\n", p->idx);
			/* Mark this channel free */
			c->phy = NULL;
			p->vchan = NULL;
		} else if (ret) {
			return;
		}
	} else if (p && c->status == DMA_ERROR) {
		hi9030_dma_terminate_chan(p, d);
		c->phy = NULL;
		p->vchan = NULL;
		p->ds_run = p->ds_done = NULL;
		c->status = DMA_IN_PROGRESS;
	}
}
 
static void hi9030_peri_dma_config(struct hi9030_dma_dev *d)
{
	struct hi9030_dma_phy *p = NULL;
	struct hi9030_dma_chan *c = NULL;
	struct hi9030_dma_chan *cn = NULL;
	unsigned int pch;
 
	/* check new dma request of running channel in vc->desc_issued */
	list_for_each_entry_safe(c, cn, &d->slave.channels,
		vc.chan.device_node) {
		hi9030_dma_chk_running_dma(c, d);
	}
 
	/* check new channel request in d->chan_pending */
	for (pch = 0; pch < d->dma_channels; pch++) {
		p = &d->phy[pch];
 
		if (!p->vchan && !list_empty(&d->chan_pending)) {
			c = list_first_entry(
				&d->chan_pending, struct hi9030_dma_chan, node);
			/* remove from d->chan_pending */
			list_del_init(&c->node);
			/* Mark this channel allocated */
			p->vchan = c;
			c->phy = p;
			hi9030_dma_start_txd(c);
			dev_dbg(d->slave.dev, "pchan %u: alloc vchan %pK\n",
				pch, &c->vc);
		}
	}
}
 
static int hi9030_dma_alloc_chan_resources(struct dma_chan *chan)
{
	(void)chan;
	return 0;
}
 
static void hi9030_dma_free_chan_resources(struct dma_chan *chan)
{
	struct hi9030_dma_chan *c = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	unsigned long flag;
 
	spin_lock_irqsave(&d->lock, flag);
	list_del_init(&c->node);
	spin_unlock_irqrestore(&d->lock, flag);
 
	vchan_free_chan_resources(&c->vc);
	c->ccfg = 0;
}
 
static enum dma_status hi9030_dma_tx_status(struct dma_chan *chan,
	dma_cookie_t cookie, struct dma_tx_state *state)
{
	struct hi9030_dma_chan *c = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	struct hi9030_dma_phy *phy = NULL;
	struct virt_dma_desc *vd = NULL;
	unsigned long flags;
	enum dma_status retval;
	size_t bytes = 0;
 
	retval = dma_cookie_status(&c->vc.chan, cookie, state);
	if (retval == DMA_COMPLETE)
		return retval;
 
	spin_lock_irqsave(&c->vc.lock, flags);
	phy = c->phy;
	retval = c->status;
 
	vd = vchan_find_desc(&c->vc, cookie);
	if (vd) {
		bytes = container_of(vd, struct hi9030_dma_desc_sw, vd)->size;
	} else if ((!phy) || (!phy->ds_run)) {
		bytes = 0;
	} else {
		struct hi9030_dma_desc_sw *ds = phy->ds_run;
		u64 clli, index;
 
		bytes = hi9030_dma_get_curr_cnt(d, phy);
		clli = hi9030_dma_get_curr_lli(d, phy);
		index = (clli - ds->desc_hw_lli) / sizeof(struct hi9030_dma_desc_hw);
		for (; index < ds->desc_num; index++) {
			bytes += ds->desc_hw[index].count;
			/* end of lli */
			if (!ds->desc_hw[index].lli)
				break;
		}
	}
	spin_unlock_irqrestore(&c->vc.lock, flags);
	dma_set_residue(state, (u32)bytes);
 
	return retval;
}
 
static void hi9030_dma_issue_pending(struct dma_chan *chan)
{
	struct hi9030_dma_chan *c = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	unsigned long flag;
 
	spin_lock_irqsave(&d->lock, flag);
	spin_lock(&c->vc.lock);
	/* add request to vc->desc_issued */
	if (vchan_issue_pending(&c->vc)) {
		if (!c->phy)
			if (list_empty(&c->node)) {
				/* if new channel, add chan_pending */
				list_add_tail(&c->node, &d->chan_pending);
				/* check in tasklet */
				hi9030_peri_dma_config(d);
				dev_dbg(d->slave.dev, "vchan %pK: issued\n",
					&c->vc);
			}
	} else {
		dev_dbg(d->slave.dev, "vchan %pK: nothing to issue\n", &c->vc);
	}
 
	spin_unlock(&c->vc.lock);
	spin_unlock_irqrestore(&d->lock, flag);
}
 
static void hi9030_dma_fill_desc(struct hi9030_dma_desc_sw *ds, dma_addr_t dst,
	dma_addr_t src, size_t len, u32 num, u32 ccfg)
{
	if ((num + 1) < ds->desc_num)
		ds->desc_hw[num].lli = ds->desc_hw_lli +
			(u64)(num + 1) * sizeof(struct hi9030_dma_desc_hw);
 
	ds->desc_hw[num].lli |= CX_LLI_CHAN_EN;
	ds->desc_hw[num].count = (u32)len;
	ds->desc_hw[num].saddr = src;
	ds->desc_hw[num].daddr = dst;
	ds->desc_hw[num].config = ccfg;
}

/* 9030dma burst * width < 128bit */
static struct dma_async_tx_descriptor *hi9030_dma_prep_m2m(
	struct dma_chan *chan, dma_addr_t dst, dma_addr_t src, size_t len,
	unsigned long flags)
{
	(void)chan;
	(void)dst;
	(void)src;
	(void)len;
	(void)flags;
	/* 9030 dma not support M2M */
	return NULL;
}

static void hi9030_dma_get_dst_and_src(
	const struct hi9030_dma_chan *c, enum dma_transfer_direction dir,
	struct scatterlist *sgl, dma_addr_t *dst, dma_addr_t *src)
{
	unsigned int addr = 0;
	struct hi9030_dma_rx_sgbuf *sgbuf = NULL;

	if (sgl)
		sgbuf = container_of(sgl, struct hi9030_dma_rx_sgbuf, sg);

	if (dir == DMA_MEM_TO_DEV) {
		if (c->dev_addr == UART1_TX_ADDR) {
			addr = UART1_TX_BUFF_ADDR;
		} else if (c->dev_addr == UART2_TX_ADDR) {
			addr = UART2_TX_BUFF_ADDR;
		}
		*src = addr;
		*dst = c->dev_addr;
	} else if (dir == DMA_DEV_TO_MEM) {
		if (sgbuf == NULL)
			return;

		if (c->dev_addr == UART1_RX_ADDR) {
			if (sgbuf->use_buf_b)
				addr = UART1_RX_BUFF_B_ADDR;
			else
				addr = UART1_RX_BUFF_A_ADDR;
		} else if (c->dev_addr == UART2_RX_ADDR) {
			if (sgbuf->use_buf_b)
				addr = UART2_RX_BUFF_B_ADDR;
			else
				addr = UART2_RX_BUFF_A_ADDR;
		}
		*src = c->dev_addr;
		*dst = addr;
	}
}
 
static struct dma_async_tx_descriptor *hi9030_dma_prep_slave_sg(
	struct dma_chan *chan, struct scatterlist *sgl, unsigned int length,
	enum dma_transfer_direction dir, unsigned long flags, void *context)
{
	struct hi9030_dma_chan *c = to_hi9030_dma_chan(chan);
	struct hi9030_dma_desc_sw *ds = NULL;
	dma_addr_t src = 0;
	dma_addr_t dst = 0;
 
	(void)context;
 
	ds = kzalloc(sizeof(*ds) + sizeof(ds->desc_hw[0]),
		GFP_ATOMIC | GFP_DMA);
	if (!ds)
		return NULL;
 
	ds->desc_hw_lli = __virt_to_phys((uintptr_t)&ds->desc_hw[0]);
	ds->desc_num = 1;

	hi9030_dma_get_dst_and_src(c, dir, sgl, &dst, &src);
	hi9030_dma_fill_desc(ds, dst, src, length, 0, c->ccfg);
 
	ds->desc_hw[0].lli = 0; /* end of link */
#if defined(CONFIG_PERI_DMA_NO_CCI)
	dma_sync_single_for_device(chan->device->dev, ds->desc_hw_lli,
		sizeof(ds->desc_hw[0]), DMA_TO_DEVICE);
#endif
	ds->size = length;
	return vchan_tx_prep(&c->vc, &ds->vd, flags);
}
 
static u32 peri_dma_convert_width(enum dma_slave_buswidth width)
{
	u32 val = 0;
 
	switch (width) {
	case DMA_SLAVE_BUSWIDTH_1_BYTE:
		val = DMA_SLAVE_BUS_WIDTH_VAL_1BYTE;
		break;
	case DMA_SLAVE_BUSWIDTH_2_BYTES:
		val = DMA_SLAVE_BUS_WIDTH_VAL_2BYTE;
		break;
	case DMA_SLAVE_BUSWIDTH_4_BYTES:
		val = DMA_SLAVE_BUS_WIDTH_VAL_4BYTE;
		break;
	case DMA_SLAVE_BUSWIDTH_8_BYTES:
		val = DMA_SLAVE_BUS_WIDTH_VAL_8BYTE;
		break;
	default:
		break;
	}
 
	return val;
}
 
static int hi9030_dma_config(struct dma_chan *chan,
	struct dma_slave_config *cfg)
{
	struct hi9030_dma_chan *ch = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	u32 maxburst = 0;
	u32 value;
	enum dma_slave_buswidth width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
 
	if (!cfg) {
		dev_warn(d->slave.dev, "config is NULL\n");
		return -EINVAL;
	}
 
	ch->dir = cfg->direction;
	if (ch->dir == DMA_DEV_TO_MEM) {
		ch->ccfg = CCFG_DSTINCR;
		ch->dev_addr = cfg->src_addr;
		maxburst = cfg->src_maxburst;
		width = cfg->src_addr_width;
	} else if (ch->dir == DMA_MEM_TO_DEV) {
		ch->ccfg = CCFG_SRCINCR;
		ch->dev_addr = cfg->dst_addr;
		maxburst = cfg->dst_maxburst;
		width = cfg->dst_addr_width;
	} else if (ch->dir == DMA_MEM_TO_MEM) {
		ch->ccfg = CCFG_SRCINCR | CCFG_DSTINCR;
	}
 
	value = peri_dma_convert_width(width);
	ch->ccfg |= (value << DMA_CH_CFG_DW) | (value << DMA_CH_CFG_SW);
 
	if (!maxburst || (maxburst > DMA_MAX_BURST))
		value = DMA_MAX_BURST;
	else
		value = maxburst - 1;
 
	ch->ccfg |= (value << DMA_CH_CFG_DL) | (value << DMA_CH_CFG_SL);
	ch->ccfg |= CCFG_MEM2PER | IODIE_DMA_CCFG_EN;
 
	/* specific request line */
	ch->ccfg |= (u32)ch->vc.chan.chan_id << DMA_CH_CFG_PERI;
	return 0;
}
 
static int hi9030_peri_dma_pause(struct dma_chan *chan)
{
	struct hi9030_dma_chan *ch = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	unsigned long flags;
	struct hi9030_dma_phy *phy = NULL;
 
	dev_dbg(d->slave.dev, "vchan %pK: pause\n", &ch->vc);
	if (ch->status == DMA_IN_PROGRESS) {
		ch->status = DMA_PAUSED;
		spin_lock_irqsave(&d->lock, flags);
		phy = ch->phy;
		if (phy) {
			spin_unlock_irqrestore(&d->lock, flags);
			hi9030_dma_pause(phy, d, false);
		} else {
			list_del_init(&ch->node);
			spin_unlock_irqrestore(&d->lock, flags);
		}
	}
 
	return 0;
}
 
static int hi9030_peri_dma_resume(struct dma_chan *chan)
{
	struct hi9030_dma_chan *ch = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	unsigned long flag;
	struct hi9030_dma_phy *phy = NULL;
 
	dev_dbg(d->slave.dev, "vchan %pK: resume\n", &ch->vc);
	spin_lock_irqsave(&ch->vc.lock, flag);
	phy = ch->phy;
	if (ch->status == DMA_PAUSED) {
		ch->status = DMA_IN_PROGRESS;
		if (phy) {
			hi9030_dma_pause(phy, d, true);
		} else if (!list_empty(&ch->vc.desc_issued)) {
			spin_lock(&d->lock);
			list_add_tail(&ch->node, &d->chan_pending);
			spin_unlock(&d->lock);
		}
	}
	spin_unlock_irqrestore(&ch->vc.lock, flag);
 
	return 0;
}
 
static int hi9030_dma_terminate_all(struct dma_chan *chan)
{
	struct hi9030_dma_chan *c = to_hi9030_dma_chan(chan);
	struct hi9030_dma_dev *d = to_hi9030_dma_dev(chan->device);
	unsigned long flag;
	struct hi9030_dma_phy *phy = NULL;
	LIST_HEAD(head);
 
	dev_dbg(d->slave.dev, "vchan %pK: terminate all\n", &c->vc);
	/* Prevent this channel being scheduled */
	spin_lock_irqsave(&d->lock, flag);
	list_del_init(&c->node);

	/* Clear the tx descriptor lists */
	spin_lock(&c->vc.lock);
	phy = c->phy;
	vchan_get_all_descriptors(&c->vc, &head);
	if (phy && phy->ds_run && !phy->ds_done)
		list_add_tail(&phy->ds_run->vd.node, &head);
 
	if (phy) {
		/* vchan is assigned to a pchan - stop the channel */
		hi9030_dma_terminate_chan(phy, d);
		c->phy = NULL;
		phy->vchan = NULL;
		phy->ds_run = phy->ds_done = NULL;
	}
	spin_unlock(&c->vc.lock);
	spin_unlock_irqrestore(&d->lock, flag);
	vchan_dma_desc_free_list(&c->vc, &head);
 
	return 0;
}
 
static int check_dma_chan(struct dma_chan *chan)
{
	if (!chan) {
		pr_err("%s: dma_chan *chan is NULL!\n", __func__);
		return -EINVAL;
	}
 
	pr_err("%s: chan[0x%pK] id[%d] cookie[%d-%d]!\n", __func__, chan,
		chan->chan_id, chan->cookie, chan->completed_cookie);
 
	if (!chan->device) {
		pr_err("show_dma_reg: chan->device * is NULL!\n");
		return -EINVAL;
	}
 
	return 0;
}

static int check_hi9030_dma_dev(struct hi9030_dma_dev *d)
{
	if (!d) {
		pr_err("hi9030_dma_dev *d is NULL!\n");
		return -EINVAL;
	}
	if (!d->slave.dev) {
		pr_err("d->slave.dev is NULL!\n");
		return -EINVAL;
	}

	return 0;
}

static int check_hi9030_dma_chan(struct hi9030_dma_dev *dev, struct hi9030_dma_chan *c)
{
	if (!(c->phy)) {
		dev_err(dev->slave.dev, "d->phy is NULL!\n");
		return -EINVAL;
	}
	return 0;
}

static void show_hi9030_dma_dev_base_reg(struct hi9030_dma_dev *d)
{
	dev_info(d->slave.dev, "IODIE_INT_STAT = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_STAT));
	dev_info(d->slave.dev, "IODIE_INT_TC1  = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_TC1));
	dev_info(d->slave.dev, "IODIE_INT_ERR1 = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR1));
	dev_info(d->slave.dev, "IODIE_INT_ERR2 = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR2));

	dev_info(d->slave.dev, "IODIE_INT_TC1_MASK  = 0x%x\n", iodie_readl(d->hi9030_dma_module,IODIE_INT_TC1_MASK));
	dev_info(d->slave.dev, "IODIE_INT_ERR1_MASK = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR1_MASK));
	dev_info(d->slave.dev, "IODIE_INT_ERR2_MASK = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR2_MASK));

	dev_info(d->slave.dev, "IODIE_INT_TC1_RAW  = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_TC1_RAW));
	dev_info(d->slave.dev, "IODIE_INT_TC2_RAW  = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_TC2_RAW));
	dev_info(d->slave.dev, "IODIE_INT_ERR1_RAW = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR1_RAW));
	dev_info(d->slave.dev, "IODIE_INT_ERR2_RAW = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_INT_ERR2_RAW));

	dev_info(d->slave.dev, "IODIE_IODIE_CH_STAT  = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_IODIE_CH_STAT));
	dev_info(d->slave.dev, "IODIE_DMA_CTRL = 0x%x\n", iodie_readl(d->hi9030_dma_module, IODIE_DMA_CTRL));
}

static void hi9030_show_dma64_reg(struct dma_chan *chan)
{
	struct hi9030_dma_chan *c = NULL;
	struct hi9030_dma_dev *d = NULL;
	struct hi9030_dma_phy *p = NULL;
	u32 i;

	if (check_dma_chan(chan))
		return;

	d = to_hi9030_dma_dev(chan->device);
	if (check_hi9030_dma_dev(d))
		return;
	c = to_hi9030_dma_chan(chan);
	if (check_hi9030_dma_chan(d, c))
		return;

	p = c->phy;
	dev_info(d->slave.dev,
		"%s:chan[%pK] ccfg[0x%x] dir[%d] dev_addr[0x%llx] status[%d]\n",
		__func__, c, c->ccfg, c->dir, c->dev_addr, c->status);
	dev_info(d->slave.dev,
		"%s: phy idx[0x%x] ds_run[%pK] ds_done[%pK]\n", __func__,
		p->idx, p->ds_run, p->ds_done);

	for (i = 0; i < d->dma_channels; i++) {
		p = &d->phy[i];
		dev_info(d->slave.dev, "idx[%2d]:IODIE_CX_CONFIG:[0x%32x], CX_AXI_CONF:[0x%32x]",
			i, iodie_readl(d->hi9030_dma_module, p->offset + IODIE_CX_CONFIG),
			iodie_readl(d->hi9030_dma_module, p->offset + AXI_CONFIG));
		dev_info(d->slave.dev, "SRC_H:[0x%32x], SRC_L:[0x%32x], DST_H:[0x%32x]",
			iodie_readl(d->hi9030_dma_module, p->offset + CH_SRC_H), iodie_readl(d->hi9030_dma_module, p->offset + CH_SRC_L),
			iodie_readl(d->hi9030_dma_module, p->offset + CH_DST_H));
		dev_info(d->slave.dev,
			"DST_L:[0x%32x], CNT0:[0x%32x], CH_CUR_CNT0:[0x%32x]\n",
			iodie_readl(d->hi9030_dma_module, p->offset + CH_DST_L), iodie_readl(d->hi9030_dma_module, p->offset + CH_CNT),
			iodie_readl(d->hi9030_dma_module, p->offset + CH_CUR_CNT - i * CURRENT_COUNT_OFFSET));
	}

	show_hi9030_dma_dev_base_reg(d);
}

static void hi9030_dma_free_desc(struct virt_dma_desc *vd)
{
	struct hi9030_dma_desc_sw *ds =
		container_of(vd, struct hi9030_dma_desc_sw, vd);
#if defined(CONFIG_PERI_DMA_NO_CCI)
	dma_sync_single_for_cpu(vd->tx.chan->device->dev, ds->desc_hw_lli,
		ds->desc_num * sizeof(ds->desc_hw[0]), DMA_FROM_DEVICE);
#endif
	kfree(ds);
}
 
static const struct of_device_id hi9030_pdma64_dt_ids[] = {
	{
		.compatible = "hisilicon,hi9030-peri-dma64",
	},
	{}
};
MODULE_DEVICE_TABLE(of, hi9030_pdma64_dt_ids);
 
static struct dma_chan *hi9030_of_dma_simple_xlate(
	struct of_phandle_args *dma_spec, struct of_dma *ofdma)
{
	struct hi9030_dma_dev *d = ofdma->of_dma_data;
	unsigned int request = dma_spec->args[0];
 
	if (request > d->dma_requests)
		return NULL;
 
	return dma_get_slave_channel(&(d->chans[request].vc.chan));
}
 
static void hi9030_dma_set_slave_cfg(struct dma_device *slave,
	struct platform_device *op, struct hi9030_dma_dev *d)
{
	INIT_LIST_HEAD(&slave->channels);
	dma_cap_set(DMA_SLAVE, slave->cap_mask);
	dma_cap_set(DMA_MEMCPY, slave->cap_mask);
	dma_cap_set(DMA_PRIVATE, slave->cap_mask);
	slave->dev = &op->dev;
	slave->device_alloc_chan_resources = hi9030_dma_alloc_chan_resources;
	slave->device_free_chan_resources = hi9030_dma_free_chan_resources;
	slave->device_tx_status = hi9030_dma_tx_status;
	slave->device_prep_dma_memcpy = hi9030_dma_prep_m2m;
	slave->device_prep_slave_sg = hi9030_dma_prep_slave_sg;
	slave->device_issue_pending = hi9030_dma_issue_pending;
	slave->device_config = hi9030_dma_config;
	slave->device_pause = hi9030_peri_dma_pause;
	slave->device_resume = hi9030_peri_dma_resume;
	slave->device_terminate_all = hi9030_dma_terminate_all;
	slave->copy_align = DMA_ALIGN;
	slave->chancnt = d->dma_requests;
}
 
static int hi9030_dma_read_dev_dt_cfg(struct platform_device *op,
	struct hi9030_dma_dev *d)
{
	int ret = 0;
	const struct of_device_id *of_id = NULL;
 
	of_id = of_match_device(hi9030_pdma64_dt_ids, &op->dev);
	if (of_id)
		ret = of_property_read_u32(
			(&op->dev)->of_node, "dma-channels", &d->dma_channels);
 
	if (ret) {
		dev_err(&op->dev, "%s doesn't have dma-channels property!\n",
			__func__);
		return ret;
	}
 
	ret = of_property_read_u32((&op->dev)->of_node, "dma-requests",
		&d->dma_requests);
	if (ret) {
		dev_err(&op->dev, "%s doesn't have dma-request property!\n",
			__func__);
		return ret;
	}
 
	ret = of_property_read_u32((&op->dev)->of_node, "hi9030-dma-module",
		&d->hi9030_dma_module);
	if (ret) {
		dev_info(&op->dev, "%s doesn't have hi9030-dma-module property!\n",
			__func__);
		return ret;
	}
 
	ret = of_property_read_u32((&op->dev)->of_node, "dma-used-chans",
		&d->dma_used_chans);
	if (ret) {
		dev_info(&op->dev, "%s doesn't have dma-used-chans property!\n",
			__func__);
		return ret;
	}
 
	ret = of_property_read_u32((&op->dev)->of_node, "dma-reset-reg",
				&d->reset_reg);
	if (ret) {
		dev_info(&op->dev, "%s doesn't have dma-reset-reg property!\n",
			__func__);
		return ret;
	}
 
	ret = of_property_read_u32((&op->dev)->of_node, "dma-reset-val",
				&d->reset_val);
	if (ret) {
		dev_info(&op->dev, "%s doesn't have dma-reset-val property!\n",
			__func__);
		return ret;
	}
 
	return ret;
}
 
static int hi9030_dma_new_dev(struct hi9030_dma_dev **dev,
	struct platform_device *opd)
{
	int ret;
	struct hi9030_dma_dev *d = NULL;
	struct resource *ioreq = NULL;
 
	ioreq = platform_get_resource(opd, IORESOURCE_MEM, 0);
	if (!ioreq)
		return -EINVAL;
 
	d = devm_kzalloc(&opd->dev, sizeof(*d), GFP_KERNEL);
	if (!d)
		return -ENOMEM;
 
	ret = hi9030_dma_read_dev_dt_cfg(opd, d);
	if (ret) {
		dev_err(&opd->dev, "dma read dev cfg failed. ret=[%d]\n", ret);
		devm_kfree(&opd->dev, d);
		return ret;
	}
 
	dev_info(&opd->dev, "dma_channels:0x%x dma_requests:0x%x",
		d->dma_channels, d->dma_requests);
	dev_info(&opd->dev, "dma_used_chans:0x%x\n", d->dma_used_chans);
	*dev = d;
 
	return ret;
}
 
static int peri_dma_init_virtual_channel(
	struct hi9030_dma_dev *d, struct platform_device *op)
{
	u32 i;
 
	d->chans = devm_kzalloc(&op->dev,
		d->dma_requests * sizeof(struct hi9030_dma_chan), GFP_KERNEL);
	if (!d->chans)
		return -ENOMEM;
 
	for (i = 0; i < d->dma_requests; i++) {
		struct hi9030_dma_chan *c = &d->chans[i];
		c->status = DMA_IN_PROGRESS;
		INIT_LIST_HEAD(&c->node);
		c->vc.desc_free = hi9030_dma_free_desc;
		vchan_init(&c->vc, &d->slave);
		c->vc.chan.private = kmalloc(sizeof(int), GFP_KERNEL);
		if (!c->vc.chan.private) {
			dev_err(&op->dev, "chan %d kmalloc failed\n", i);
			return -ENOMEM;
		} else {
			*(int *)(c->vc.chan.private) = 0;
		}
	}
 
	return 0;
}
 
static int hi9030_dma_init_phy(struct platform_device *op, struct hi9030_dma_dev *d)
{
	u32 i;
 
	d->phy = devm_kzalloc(&op->dev,
		d->dma_channels * sizeof(struct hi9030_dma_phy), GFP_KERNEL);
	if (!d->phy)
		return -ENOMEM;
 
	for (i = 0; i < d->dma_channels; i++) {
		struct hi9030_dma_phy *p = &d->phy[i];
 
		p->idx = i;
		p->offset = i * DMA_CHAN_OFFSET;
	}
 
	return 0;
}
 
static int hi9030_dma_prepare_irq(struct platform_device *op,
	struct hi9030_dma_dev *d)
{
	int ret;
 
	d->dma_irq = platform_get_irq(op, 0);
	if (d->dma_irq < 0) {
		dev_err(&op->dev, "platform get irq failed. irq=%d\n",
			d->dma_irq);
		return -ENXIO;
	}
 
	ret = devm_request_irq(
		&op->dev, (u32)d->dma_irq, hi9030_peri_dma_int_handler, 0,
			DRIVER_NAME, d);
	if (ret) {
		dev_err(&op->dev, "request irq failed irq=%d\n", d->dma_irq);
		return ret;
	}
 
	return 0;
}
 
static void hi9030_dma_dis_reset(struct hi9030_dma_dev *d)
{
	/* release dma reset */
	iodie_writel(IODIE_IP_PERI_CRG, d->reset_reg, d->reset_val);
}
 
static int hi9030_dma_probe(struct platform_device *op)
{
	struct hi9030_dma_dev *d = NULL;
 
	if (hi9030_dma_new_dev(&d, op) || !d) {
		dev_err(&op->dev, "new dma dev failed\n");
		return -ENOMEM;
	}
 
	op->dev.dma_mask = &(op->dev.coherent_dma_mask);
	op->dev.coherent_dma_mask = DMA_BIT_MASK(64); /* 64bit */
	d->dma_irq_flag = 0;
 
	hi9030_dma_dis_reset(d);
 
	if (hi9030_dma_prepare_irq(op, d)) {
		dev_err(&op->dev, "prepare irq failed\n");
		return -1;
	}
 
	/* init phy channel */
	if (hi9030_dma_init_phy(op, d)) {
		dev_err(&op->dev, "init phy channel failed\n");
		return -1;
	}
 
	op->dev.coherent_dma_mask = DMA_BIT_MASK(64); /* 64bit */
	op->dev.dma_mask = &op->dev.coherent_dma_mask;
	hi9030_dma_set_slave_cfg(&d->slave, op, d);
 
	/* init virtual channel */
	if (peri_dma_init_virtual_channel(d, op)) {
		dev_err(&op->dev, "init virtual channel failed\n");
		return -1;
	}
	iodie_clk_en(d->hi9030_dma_module);
	hi9030_dma_enable_dma(d, true);
	if (dma_async_device_register(&d->slave)) {
		dev_err(&op->dev, "async device register failed\n");
		return -1;
	}
 
	if (of_dma_controller_register(
		(&op->dev)->of_node, hi9030_of_dma_simple_xlate, d)) {
		dev_err(&op->dev, "dma device register failed\n");
		dma_async_device_unregister(&d->slave);
		return -1;
	}
 
	spin_lock_init(&d->lock);
	INIT_LIST_HEAD(&d->chan_pending);
	platform_set_drvdata(op, d);
	d->dma_irq_flag = 1;
 
	dev_info(&op->dev, "initialized hi9030 dma64 probe ok!\n");
 
	return 0;
}
 
static int hi9030_dma_remove(struct platform_device *op)
{
	struct hi9030_dma_chan *c = NULL;
	struct hi9030_dma_chan *cn = NULL;
	struct hi9030_dma_dev *d = platform_get_drvdata(op);
 
	if (!d) {
		pr_err("%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}
 
	dma_async_device_unregister(&d->slave);
	of_dma_controller_free((&op->dev)->of_node);
 
	/* Clear virtual channel resource */
	list_for_each_entry_safe(c, cn, &d->slave.channels,
		vc.chan.device_node) {
		if (c->vc.chan.private)
			kfree(c->vc.chan.private);
		list_del(&c->vc.chan.device_node);
		tasklet_kill(&c->vc.task);
	}
	tasklet_kill(&d->task);
	iodie_clk_dis(d->hi9030_dma_module);
 
	return 0;
}
 
#if defined(CONFIG_PM_SLEEP)
static int hi9030_dma_pltfm_suspend(struct device *dev)
{
	struct hi9030_dma_dev *d = dev_get_drvdata(dev);
 
	if (!d) {
		pr_err("%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}
 
	dev_info(d->slave.dev, "%s: suspend +\n", __func__);
	dev_info(d->slave.dev, "%s: suspend -\n", __func__);
	return 0;
}
 
static int hi9030_dma_pltfm_resume(struct device *dev)
{
	struct hi9030_dma_dev *d = dev_get_drvdata(dev);
 
	if (!d) {
		pr_err("%s: get drvdata failed\n", __func__);
		return -EINVAL;
	}
	dev_info(d->slave.dev, "%s: resume +\n", __func__);
 
	dev_info(d->slave.dev, "%s: resume -\n", __func__);
	return 0;
}
 
#endif /* CONFIG_PM_SLEEP */
 
const struct dev_pm_ops hi9030_dma_pm_ops = {
	SET_LATE_SYSTEM_SLEEP_PM_OPS(hi9030_dma_pltfm_suspend,
		hi9030_dma_pltfm_resume)
};
 
static struct platform_driver hi9030_pdma64_driver = {
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.pm = &hi9030_dma_pm_ops,
		.of_match_table = hi9030_pdma64_dt_ids,
	},
	.probe = hi9030_dma_probe,
	.remove = hi9030_dma_remove,
};
 
static int __init dmac_module_init(void)
{
	int retval;
 
	retval = platform_driver_register(&hi9030_pdma64_driver);
	if (retval) {
		pr_err("hi9030 dma platform driver register failed\n");
		return retval;
	}
 
	return retval;
}
 
static void __exit dmac_module_exit(void)
{
	platform_driver_unregister(&hi9030_pdma64_driver);
}
 
subsys_initcall_sync(dmac_module_init);
MODULE_DESCRIPTION("hi9030 peri 64bit DMA Driver");
MODULE_LICENSE("GPL v2");