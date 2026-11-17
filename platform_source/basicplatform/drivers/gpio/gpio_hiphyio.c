/*
* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
* Description: provide hiphyio gpio access function interfaces.
* Create: 2024-12-5
*
* This software is licensed under the terms of the GNU General Public
* License version 2, as published by the Free Software Foundation, and
* may be copied, distributed, and modified under those terms.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>
#include <linux/bitops.h>
#include <linux/gpio.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/pinctrl/consumer.h>
#include <linux/workqueue.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/gpio/driver.h>
#include <gpiolib.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_def.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>

#define HW_SW_SEL 4
#define HW_SW_SEL_MASK 20
#define GPIO_PER_REG 16
#define SET_MASK 0x00010001
#define HIGH_LEVEL_ENABLE 0x00080008
#define LOW_LEVEL_ENABLE  0x00080000
#define RISING_EDGE_ENABLE  0x00060002
#define FALLING_EDGE_ENABLE  0x00060000
#define BOTH_EDGE_ENABLE  0x00060006
#define LEVEL_TRIGGER_ENABLE 0x00010001
#define EDGE_TRIGGER_ENABLE 0x00010000

#define intr_ctrl_bit(x) (0x08 + 0x04 * (x))
#define config_mask(x) (0x1 << (x))
#define data_offset(x) (((x) > 15) ? 0x0 : 0x04)
#define mask_offset(x) (((x) > 15) ? (x) : (x) + 16)

#define GPIO_NUM_32 32
#define GPIO_PREE_IRQ 21
#define PERI_GPIO_BASE 384
#define GPIO_MASK_0 0x088
#define GPIO_INTR_CLEAR 0x0A8
#define GPIO_STATUS_0 0x0B0
#define SOURCE_DATA 0x0DC
#define IRQ_MASK 0xFFFFFFFF
#define CLEAR_TRQ_TYPE 0xFFFFFFF0
#define IODIE_STATUS_MASK 0x80000000
#define IODIE_STATUS_OFFSET 0x46c
#define GPIO_406 406

struct hipyio {
	int base;
	struct gpio_chip gc;
	struct platform_device *pdev;
	uint32_t irqarray;
	struct irq_domain *domain;
};

static uint32_t hipyio_readl(struct hipyio *chip, uint32_t offset)
{
	return iodie_readl(chip->base, offset);
}

static void hipyio_writel(struct hipyio *chip, uint32_t v, uint32_t offset)
{
	iodie_writel(chip->base, offset, v);
}

static int hipyio_get_direction(struct gpio_chip *gc, uint32_t offset)
{
	struct hipyio *hipyio = gpiochip_get_data(gc);
	return !(hipyio_readl(hipyio, intr_ctrl_bit(offset)) & BIT(HW_SW_SEL));
}

static int hipyio_direction_input(struct gpio_chip *gc, uint32_t offset)
{
	struct hipyio *hipyio = gpiochip_get_data(gc);
	uint32_t gpiodir = 0;

	if (offset >= gc->ngpio)
		return -EINVAL;

	gpiodir |= BIT(HW_SW_SEL_MASK);
	hipyio_writel(hipyio, gpiodir, (intr_ctrl_bit(offset)));

	return 0;
}

static int hipyio_direction_output(struct gpio_chip *gc, uint32_t offset,
		int value)
{
	struct hipyio *hipyio = gpiochip_get_data(gc);
	uint32_t gpiodir = 0;
	uint32_t gpioval = 0;

	if (offset >= gc->ngpio)
		return -EINVAL;

	gpioval |= BIT(mask_offset(offset));
	gpioval |= (!!value << (offset % GPIO_PER_REG));
	hipyio_writel(hipyio, gpioval, (data_offset(offset)));
	gpiodir |= (SET_MASK << HW_SW_SEL);
	hipyio_writel(hipyio, gpiodir, (intr_ctrl_bit(offset)));

	return 0;
}

static int hipyio_get_value(struct gpio_chip *gc, uint32_t offset)
{
	struct hipyio *hipyio = gpiochip_get_data(gc);
	return (config_mask(offset) & (hipyio_readl(hipyio, SOURCE_DATA))) >> offset;
}

static void hipyio_set_value(struct gpio_chip *gc, uint32_t offset,
		int value)
{
	uint32_t gpioval = 0;
	struct hipyio *hipyio = gpiochip_get_data(gc);

	gpioval |= BIT(mask_offset(offset));
	gpioval |= (!!value << (offset % GPIO_PER_REG));
	hipyio_writel(hipyio, gpioval, (data_offset(offset)));
}

static int hipyio_gpio_to_irq(struct gpio_chip *gc, unsigned int offset)
{
	uint32_t virq;
	struct hipyio *hipyio = gpiochip_get_data(gc);

	virq = irq_create_mapping(hipyio->domain, offset);
	if (!virq) {
		pr_err("%s: Failed mapping hwirq\n", __func__);
		return -1;
	}

	return virq;
}

static int hipyio_irq_type(struct irq_data *d, unsigned trigger)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hipyio *hipyio = gpiochip_get_data(gc);
	irq_hw_number_t offset = irqd_to_hwirq(d);
	uint32_t intr_ctrl;

	if (offset >= GPIO_NUM_32)
		return -EINVAL;

	if ((trigger & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) &&
		(trigger & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING))) {
		pr_err("%s:trigger type error\n", __func__);
		return -EINVAL;
	}

	intr_ctrl = hipyio_readl(hipyio, intr_ctrl_bit(offset));
	intr_ctrl &= CLEAR_TRQ_TYPE;

	if (trigger & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
		bool polarity = trigger & IRQ_TYPE_LEVEL_HIGH;
		intr_ctrl |= LEVEL_TRIGGER_ENABLE;
		if (polarity)
			intr_ctrl |= HIGH_LEVEL_ENABLE;
		else
			intr_ctrl |= LOW_LEVEL_ENABLE;
		irq_set_handler_locked(d, handle_level_irq);
	} else if ((trigger & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
		intr_ctrl |= EDGE_TRIGGER_ENABLE;
		intr_ctrl |= BOTH_EDGE_ENABLE;
		irq_set_handler_locked(d, handle_edge_irq);
	} else if ((trigger & IRQ_TYPE_EDGE_RISING) ||
		(trigger & IRQ_TYPE_EDGE_FALLING)) {
		bool rising = trigger & IRQ_TYPE_EDGE_RISING;
		intr_ctrl |= EDGE_TRIGGER_ENABLE;
		if (rising)
			intr_ctrl |= RISING_EDGE_ENABLE;
		else
			intr_ctrl |= FALLING_EDGE_ENABLE;
		irq_set_handler_locked(d, handle_edge_irq);
	} else {
		irq_set_handler_locked(d, handle_bad_irq);
	}

	hipyio_writel(hipyio, intr_ctrl, (intr_ctrl_bit(offset)));
	return 0;
}

static void hipyio_irq_unmask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hipyio *hipyio = gpiochip_get_data(gc);
	uint32_t mask = BIT(irqd_to_hwirq(d) % GPIO_NUM_32);
	uint32_t gpioim;

	gpioim = hipyio_readl(hipyio, GPIO_MASK_0) & ~mask;
	hipyio_writel(hipyio, gpioim, GPIO_MASK_0);
}

static void hipyio_irq_mask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hipyio *hipyio = gpiochip_get_data(gc);
	uint32_t offset = irqd_to_hwirq(d) % GPIO_NUM_32;
	uint32_t mask = BIT(offset);
	uint32_t gpioim;

	if ((gc->base + offset) == GPIO_406) {
		pr_err("%s: gpio 406 is mask!\n", __func__);
		dump_stack();
	}

	gpioim = hipyio_readl(hipyio, GPIO_MASK_0) | mask;
	hipyio_writel(hipyio, gpioim, GPIO_MASK_0);
}

static void hipyio_irq_ack(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hipyio *hipyio = gpiochip_get_data(gc);
	uint32_t mask = BIT(irqd_to_hwirq(d) % GPIO_NUM_32);

	hipyio_writel(hipyio, mask, GPIO_INTR_CLEAR);
}

static struct irq_chip hipyio_irqchip = {
	.name = "hipyio-gpio",
	.irq_ack = hipyio_irq_ack,
	.irq_mask = hipyio_irq_mask,
	.irq_unmask = hipyio_irq_unmask,
	.irq_disable = hipyio_irq_mask,
	.irq_enable = hipyio_irq_unmask,
	.irq_set_type = hipyio_irq_type,
};

static void hipyio_irq_handler(void *irq_array)
{
	unsigned long pending;
	irq_hw_number_t offset;
	uint32_t gpio, gpio_group;
	struct gpio_desc *desc;
	struct gpio_chip *gc;
	struct hipyio *hipyio;

	if (irq_array == NULL)
		return;

	gpio_group = *(int *)irq_array;
	gpio = gpio_group * GPIO_NUM_32 + PERI_GPIO_BASE;
	desc = gpio_to_desc(gpio);
	gc = desc->gdev->chip;
	hipyio = gpiochip_get_data(gc);

	pending = hipyio_readl(hipyio, GPIO_STATUS_0);
	if (pending) {
		for_each_set_bit(offset, &pending, GPIO_NUM_32)
			generic_handle_irq(irq_find_mapping(hipyio->domain, offset));
	}
}

static int hipyio_irq_map(struct irq_domain *d, uint32_t virq, irq_hw_number_t hw)
{
	int ret;
	struct gpio_chip *chip = d->host_data;

	irq_set_chip_data(virq, chip);
	irq_set_chip_and_handler(virq, &hipyio_irqchip, handle_simple_irq);
	ret = irq_set_irq_type(virq, IRQ_TYPE_NONE);
	if (ret) {
		pr_err("%s: set irq type failed\n", __func__);
		return ret;
	}

	return 0;
}

static const struct irq_domain_ops hipyio_domain_ops = {
	.map	= hipyio_irq_map,
	.xlate	= irq_domain_xlate_twocell,
};

static int hipyio_setup_gpio(struct device_node *np, struct hipyio *hipyio, struct device *dev)
{
	int ret;

	hipyio->gc.request = gpiochip_generic_request;
	hipyio->gc.free = gpiochip_generic_free;
	hipyio->gc.get_direction = hipyio_get_direction;
	hipyio->gc.direction_input = hipyio_direction_input;
	hipyio->gc.direction_output = hipyio_direction_output;
	hipyio->gc.get = hipyio_get_value;
	hipyio->gc.set = hipyio_set_value;
	hipyio->gc.to_irq = hipyio_gpio_to_irq;
	hipyio->gc.label = dev_name(dev);
	hipyio->gc.parent = dev;
	hipyio->gc.owner = THIS_MODULE;
	hipyio->gc.ngpio = GPIO_NUM_32;

	ret = of_property_read_u32(np, "base,offset", (u32 *)(&(hipyio->gc.base)));
	if (ret) {
		pr_err("%s no base,offset set\n", __func__);
		return ret;
	}

	return 0;
}

static int hipyio_setup_irq(struct device_node *np, struct hipyio *hipyio)
{
	int ret = 0;
	struct irq_domain *domain = NULL;

	domain = irq_domain_add_simple(np, hipyio->gc.ngpio, 0, &hipyio_domain_ops, &hipyio->gc);
	if (!domain) {
		pr_err("%s: failed irq domain add simple!\n", __func__);
		return -ENODEV;
	}

	hipyio->domain = domain;
	ret = iodie_intr_hub_irq_register(INTR_HUB_L2_ID_7, hipyio->irqarray,
			(iodie_intr_hub_func)hipyio_irq_handler, (void *)&(hipyio->irqarray));
	if (ret) {
		pr_err("%s: register gpio irq fail!\n", __func__);
		return -ENODEV;
	}

	return 0;
}

static int get_hipyio_device_tree_data(struct device_node *np, struct hipyio *hipyio)
{
	int ret;

	ret = of_property_read_u32(np, "base", &(hipyio->base));
	if (ret) {
		pr_err("%s: register base not specified\n", __func__);
		return -ENOMEM;
	}

	ret = of_property_read_u32(np, "hipyio-irq-array", &(hipyio->irqarray));
	if (ret) {
		pr_err("%s: no hipyio-irq-array property set\n", __func__);
		return ret;
	}

	return 0;
}

static int hipyio_get_iodie_status(void)
{
	void __iomem *virAddr = NULL;
	struct device_node *np = NULL;
	int status;

	np = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
	if (np == NULL)
		pr_err("[%s] node doesn't have sysctrl node!\n", __func__);
	else
		virAddr = of_iomap(np, 0);

	if (virAddr == NULL)
		return 0;

	status = readl(virAddr + IODIE_STATUS_OFFSET);
	iounmap(virAddr);
	return status & IODIE_STATUS_MASK;
}

static int hipyio_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct hipyio *hipyio = NULL;
	struct device_node *np = NULL;
	int ret;

	if (hipyio_get_iodie_status() == 0) {
		pr_err("%s: iodie status is error, non probe\n", __func__);
		return 0;
	}

	np = pdev->dev.of_node;
	if (!np)
		return -EINVAL;

	hipyio = devm_kzalloc(dev, sizeof(*hipyio), GFP_KERNEL);
	if (!hipyio)
		return -ENOMEM;

	ret = get_hipyio_device_tree_data(np, hipyio);
	if (ret) {
		pr_err("%s: Error get hipyio dts\n", __func__);
		return ret;
	}

	ret = hipyio_setup_gpio(np, hipyio, dev);
	if (ret) {
		pr_err("%s: Error setup hipyio gpio %d\n", __func__, ret);
		return ret;
	}

	ret = gpiochip_add_data(&hipyio->gc, hipyio);
	if (ret) {
		pr_err("%s: gpio 9030 add data failed, fail err_no is %d!\n", __func__, ret);
		return ret;
	}

	hipyio_writel(hipyio, IRQ_MASK, GPIO_INTR_CLEAR);
	hipyio_writel(hipyio, IRQ_MASK, GPIO_MASK_0);

	ret = hipyio_setup_irq(np, hipyio);
	if (ret) {
		pr_err("%s: hipyio setup irq failed, err_no is %d!\n", __func__, ret);
		return ret;
	}

	platform_set_drvdata(pdev, hipyio);
	pr_err("%s: Hi9030 GPIO chip @0x%x registered\n", __func__, hipyio->base);
	return 0;
}

static const struct of_device_id hiphyio_gpio_of_match[] = {
	{
		.compatible = "hisilicon,hiphyio-gpio",
		.data = NULL
	},
	{},
};
MODULE_DEVICE_TABLE(of, hiphyio_gpio_of_match);

static struct platform_driver hiphyio_gpio_driver = {
	.probe = hipyio_probe,
	.driver = {
		.name = "hiphyio-gpio",
		.owner = THIS_MODULE,
		.of_match_table = hiphyio_gpio_of_match,
	},
};

static int __init hipyio_gpio_init(void)
{
	return platform_driver_register(&hiphyio_gpio_driver);
}

static void __exit hipyio_gpio_exit(void)
{
	platform_driver_unregister(&hiphyio_gpio_driver);
}

subsys_initcall_sync(hipyio_gpio_init);
module_exit(hipyio_gpio_exit);

MODULE_DESCRIPTION("hipyio GPIO driver");
MODULE_LICENSE("GPL");
