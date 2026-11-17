/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: Contexthub 9030 driver.
 * Create: 2024-10-10
 */

#include <linux/init.h>
#include <linux/notifier.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/time.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/debugfs.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/of_irq.h>
#include <linux/string.h>
#include <linux/interrupt.h>
#include <securec.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
#include "iodie_dev.h"

#define intr_hub_l2_intr_maskset_addr(base, n)        ((base) + (n) * 0x10 + 0x4)
#define intr_hub_l2_intr_maskclr_addr(base, n)        ((base) + (n) * 0x10 + 0x8)
#define intr_hub_l2_intr_status_addr(base, n)         ((base) + (n) * 0x10 + 0xC)

#define INTR_HUB_L2_MAX_BIT                           32
#define INTR_HUB_L2_MAX_ID                            3

struct intr_hub_group {
	int irqnum;
	int id;
	void *data[INTR_HUB_L2_MAX_BIT];
	iodie_intr_hub_func func[INTR_HUB_L2_MAX_BIT];
};

struct iodie_intr_hub_info {
	bool inited;
	void __iomem *addr;
	struct intr_hub_group hub[INTR_HUB_L2_MAX_ID];
};

/* support 3 groups of L2 interrupts */
static struct iodie_intr_hub_info g_intr_info;

static void iodie_intr_hub_en_by_bit(uint32_t l2_id, uint32_t l2_bit)
{
	writel(BIT(l2_bit), intr_hub_l2_intr_maskset_addr(g_intr_info.addr, l2_id));
	pr_info("%s: l2_id %u, mask 0x%x\n", __func__, l2_id,
		readl(intr_hub_l2_intr_maskset_addr(g_intr_info.addr, l2_id)));
}

static void iodie_intr_hub_dis_by_bit(uint32_t l2_id, uint32_t l2_bit)
{
	writel(BIT(l2_bit), intr_hub_l2_intr_maskclr_addr(g_intr_info.addr, l2_id));
	pr_info("%s: l2_id %u, mask 0x%x\n", __func__, l2_id,
		readl(intr_hub_l2_intr_maskclr_addr(g_intr_info.addr, l2_id)));
}

static void iodie_intr_hub_dis(uint32_t l2_id)
{
	writel(0xFFFFFFFF, intr_hub_l2_intr_maskclr_addr(g_intr_info.addr, l2_id));
	pr_info("%s: l2_id %u, mask 0x%x\n", __func__, l2_id,
		readl(intr_hub_l2_intr_maskclr_addr(g_intr_info.addr, l2_id)));
}

void intr_hub_irq_freeze(void)
{
	uint32_t l2_id;

	for (l2_id = INTR_HUB_L2_ID_START; l2_id < INTR_HUB_L2_ID_END; l2_id++) {
		iodie_intr_hub_dis(l2_id);
	}
}

void intr_hub_irq_recovery(void)
{
	uint32_t l2_id;
	uint32_t l2_bit;

	for (l2_id = INTR_HUB_L2_ID_START; l2_id < INTR_HUB_L2_ID_END; l2_id++) {
		for (l2_bit = 0; l2_bit < INTR_HUB_L2_MAX_BIT; l2_bit++) {
			if (g_intr_info.hub[l2_id - INTR_HUB_L2_ID_START].func[l2_bit] != NULL) {
				iodie_intr_hub_en_by_bit(l2_id, l2_bit);
			}
		}
	}
}

int iodie_intr_hub_irq_register(unsigned int l2_id, unsigned int l2_bit, iodie_intr_hub_func handler, void *arg)
{
	enum iodie_sys_status st;
	uint32_t idx;

	pr_info("%s: L2 id %u, bit %u\n", __func__, l2_id, l2_bit);

	st = get_iodie_status();
	if ((st != IODIE_ST_PRE_INITED) && (st != IODIE_ST_INITED)) {
		pr_err("%s: iodie status err\n", __func__);
		return -EINVAL;
	}

	if (g_intr_info.inited == 0) {
		pr_err("%s: no inited\n", __func__);
		return -EINVAL;
	}

	if (l2_id < INTR_HUB_L2_ID_START || l2_id > INTR_HUB_L2_ID_END) {
		pr_err("%s:invalid para, l2_id %u\n", __func__, l2_id);
		return -EINVAL;
	}

	if (l2_bit >= INTR_HUB_L2_MAX_BIT) {
		pr_err("%s:invalid para, l2_bit %u\n", __func__, l2_bit);
		return -EINVAL;
	}

	if (handler == NULL) {
		pr_err("%s:handler is null\n", __func__);
		return -EINVAL;
	}

	idx = l2_id - INTR_HUB_L2_ID_START;
	if (g_intr_info.hub[idx].func[l2_bit] != NULL)
		pr_err("%s: register again, L2 id %u, bit %u\n", __func__, l2_id, l2_bit);

	g_intr_info.hub[idx].func[l2_bit] = handler;
	g_intr_info.hub[idx].data[l2_bit] = arg;
	iodie_intr_hub_en_by_bit(l2_id, l2_bit);

	return EOK;
}

int iodie_intr_hub_irq_unregister(unsigned int l2_id, unsigned int l2_bit)
{
    enum iodie_sys_status st;
	uint32_t idx;

	pr_info("%s: L2 id %u, bit %u\n", __func__, l2_id, l2_bit);

	st = get_iodie_status();
	if ((st != IODIE_ST_PRE_INITED) && (st != IODIE_ST_INITED)) {
		pr_err("%s: iodie status err\n", __func__);
		return -EINVAL;
	}

	if (g_intr_info.inited == 0) {
		pr_err("%s: no inited\n", __func__);
		return -EINVAL;
	}

	if (l2_id < INTR_HUB_L2_ID_START || l2_id > INTR_HUB_L2_ID_END) {
		pr_err("%s:invalid para, l2_id %u\n", __func__, l2_id);
		return -EINVAL;
	}

	if (l2_bit >= INTR_HUB_L2_MAX_BIT) {
		pr_err("%s:invalid para, l2_bit %u\n", __func__, l2_bit);
		return -EINVAL;
	}

	iodie_intr_hub_dis_by_bit(l2_id, l2_bit);
	idx = l2_id - INTR_HUB_L2_ID_START;
	g_intr_info.hub[idx].func[l2_bit] = NULL;
	g_intr_info.hub[idx].data[l2_bit] = NULL;

	return EOK;
}

static int get_l2_id_by_irq(int irq)
{
	int i;

	for (i = 0; i < INTR_HUB_L2_MAX_ID; i++) {
		if (g_intr_info.hub[i].irqnum == irq)
			return g_intr_info.hub[i].id;
	}

	return -EFAULT;
}

static irqreturn_t iodie_intr_hub_handler(int irq, void *data)
{
	int idx;
	int l2_id;
	uint32_t i;
	uint32_t val;

	if (g_intr_info.inited == 0) {
		pr_err("[%s] irq %d, intr hub not inited\n", __func__, irq);
		return IRQ_HANDLED;
	}

	l2_id = get_l2_id_by_irq(irq);
	if ((l2_id < INTR_HUB_L2_ID_START) || (l2_id >= INTR_HUB_L2_ID_END)) {
		pr_err("[%s] invalid irq %d.\n", __func__, irq);
		return IRQ_HANDLED;
	}

	/* Reverse lookup interrupt source */
	val = readl(intr_hub_l2_intr_status_addr(g_intr_info.addr, l2_id));
	pr_info("%s: recv irq %d, l2_id %d, status 0x%x.\n", __func__, irq, l2_id, val);

	idx = l2_id - INTR_HUB_L2_ID_START;
	for (i = 0; i < INTR_HUB_L2_MAX_BIT; i++) {
		if ((BIT(i) & val) == 0)
			continue;

		if (g_intr_info.hub[idx].func[i] != NULL) {
			pr_info("[%s] exec id %u.\n", __func__, i);
			g_intr_info.hub[idx].func[i](g_intr_info.hub[idx].data[i]);
		} else{
			pr_err("[%s] id %u func is null.\n", __func__, i);
		}
	}

	return IRQ_HANDLED;
}

static int get_intr_hub_dts_info(void)
{
	struct device_node *node = NULL;
	uint32_t reg_addr;
	uint32_t reg_size;
	int ret;
	int i;

	node = of_find_compatible_node(NULL, NULL, "hisilicon,io-die");
	if (node == NULL) {
		pr_err("can not find hisilicon,io-die node !\n");
		return -EFAULT;
	}

	for (i = 0; i < INTR_HUB_L2_MAX_ID; i++) {
		g_intr_info.hub[i].irqnum = of_irq_get(node, i);
		g_intr_info.hub[i].id = INTR_HUB_L2_ID_START + i;
		pr_err("%s: parse id %d, irq %d node !\n", __func__, g_intr_info.hub[i].id, g_intr_info.hub[i].irqnum);
		if (g_intr_info.hub[i].irqnum < 0) {
			pr_err("%s get irq num failed, irqnum %d\n", __func__, g_intr_info.hub[i].irqnum);
			return -EFAULT;
		}
	}

	ret = of_property_read_u32_index(node, "intr_reg", 0, &reg_addr);
	if (ret) {
		pr_err("%s failed to get reg addr! ret=%d\n", __func__, ret);
		return -EFAULT;
	}

	ret = of_property_read_u32_index(node, "intr_reg", 1, &reg_size);
	if (ret) {
		pr_err("%s failed to get reg size! ret=%d\n", __func__, ret);
		return -EFAULT;
	}

	g_intr_info.addr = ioremap(reg_addr, reg_size);
	if (g_intr_info.addr == NULL){
		pr_err("%s intr hub addr is null\n", __func__);
		return -EFAULT;
	}

	return EOK;
}

static int intr_hub_request_irq(void)
{
	int ret;
	uint32_t i, j;

	for (i = 0; i < INTR_HUB_L2_MAX_ID; i++) {
		iodie_intr_hub_dis(g_intr_info.hub[i].id);
		ret = request_irq(g_intr_info.hub[i].irqnum, iodie_intr_hub_handler, IRQF_NO_SUSPEND | IRQF_TRIGGER_HIGH,
			"iodie_intr_hub", NULL);
		if (ret != 0) {
			pr_err("%s: failed, irqnum %d\n", __func__, g_intr_info.hub[i].irqnum);
			goto error;
		}
		pr_err("%s: request irq %d finish\n", __func__, g_intr_info.hub[i].irqnum);
	}

	return EOK;

error:
	for (j = 0; j < i; j++)
		free_irq(g_intr_info.hub[j].irqnum, NULL);

	return -EFAULT;
}

static int __init iodie_intr_hub_init(void)
{
	int ret;

	if (get_iodie_dts_status() != EOK) {
		pr_err("%s: iodie node is not enable\n", __func__);
		return -1;
	}

	ret = get_intr_hub_dts_info();
	if (ret != EOK) {
		pr_err("%s get int parse dts info failed, ret %d\n", __func__, ret);
		return -1;
	}

	ret = intr_hub_request_irq();
	if (ret != EOK) {
		pr_err("%s request irq fail, ret %d\n", __func__, ret);
		return -1;
	}

	g_intr_info.inited = 1;

	pr_info("%s success\n", __func__);
	return 0;
}

static void __exit iodie_intr_hub_exit(void)
{
	int i;

	if (g_intr_info.inited == 0)
		return;

	for (i = 0; i < INTR_HUB_L2_MAX_ID; i++) {
		free_irq(g_intr_info.hub[i].irqnum, NULL);
	}

	iounmap(g_intr_info.addr);

	g_intr_info.inited = 0;
	pr_info("exit %s\n", __func__);
}

arch_initcall_sync(iodie_intr_hub_init);
module_exit(iodie_intr_hub_exit);
