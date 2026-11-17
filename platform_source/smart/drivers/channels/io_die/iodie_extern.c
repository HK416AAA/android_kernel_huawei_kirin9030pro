/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 * Description: iodie exter driver.
 * Create: 2025-07-07
 */

#include <linux/types.h>
#include <linux/export.h>
#include <platform_include/smart/linux/base/ap/protocol.h>
#include <platform_include/smart/drivers/io_die/iodie_extern.h>
#include <platform_include/smart/linux/iomcu_ipc.h>

#ifdef CONFIG_POWER_DUBAI
#include <huawei_platform/power/dubai/dubai_wakeup_stats.h>
#endif

#ifdef CONFIG_CONTEXTHUB_IO_DIE_HIPHYIO
#include "hiphyio/iodie_drv.h"
#endif

#ifdef CONFIG_IPC_V5
#define IPC_DATA_LEN                  8
#define GET_IPC_TAG(data)             ((data) & 0xff)
#define GET_IPC_CMD(data)             (((data) & 0xff00) >> 8)
#endif

void notify_dubai_iodie_wakeup(const unsigned int *data, unsigned int len)
{
#if defined(CONFIG_CONTEXTHUB_IO_DIE_HIPHYIO) &&  defined(CONFIG_POWER_DUBAI) && defined(CONFIG_IPC_V5)
	unsigned int gpio_num = 0;
	const char *source = "iodie_gpio";

	if (data == NULL || len < IPC_DATA_LEN) {
		pr_err("invalid data\n");
		return;
	}

	if (GET_IPC_TAG(data[1]) != TAG_IO_DIE || GET_IPC_CMD(data[1]) < IODIE_CMD_GPIO_WAKEUP_START ||
		GET_IPC_CMD(data[1]) > IODIE_CMD_GPIO_WAKEUP_END)
		return;

	gpio_num = GET_IPC_CMD(data[1]) - IODIE_CMD_GPIO_WAKEUP_START;

	pr_info("iodie wakeup gpio_num %u\n", gpio_num);
	dubai_log_irq_wakeup(DUBAI_IRQ_WAKEUP_TYPE_AP, source, gpio_num);
#else
	return;
#endif
}
EXPORT_SYMBOL(notify_dubai_iodie_wakeup);