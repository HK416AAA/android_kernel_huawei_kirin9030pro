/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Registers related to media storage after DSS triggers underflow
 * Create: 2025-06-04
 */

#include <linux/device.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/of_address.h>
#include <linux/io.h>
#include <securec.h>
#include <mdfx_mntn.h>

#define FILENAME_LEN 256

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)    (sizeof(array) / sizeof((array)[0]))
#endif

static struct regulator *g_media1_subsys = NULL;
static void __iomem *g_reg_base[BASE_ADDR_MAX];

static int dump_regs_to_buffer(char *buf, size_t buf_size)
{
    int offset = 0;
	int len = 0;
	int i;
    u32 reg_val;
	void __iomem *base_addr;

	for (i = 0; i < ARRAY_SIZE(regs_info); i++) {
        if (regs_info[i].crg_type >= BASE_ADDR_MAX) {
            pr_err("%s: Invalid crg_type %d for register %s\n", 
                  __func__, regs_info[i].crg_type, regs_info[i].name);
            return -EINVAL;
        }

        base_addr = g_reg_base[regs_info[i].crg_type];
        if (!base_addr) {
            pr_err("%s : crg %d is not mapped\n", __func__, regs_info[i].crg_type);
            return -EINVAL;
        }

        reg_val = readl(base_addr + regs_info[i].reg);

        len = snprintf_s(buf + offset, buf_size - offset, buf_size - offset - 1,
                             "%s: 0x%x\n", regs_info[i].name, reg_val);
        if (len < 0 || (offset + len) >= buf_size) {
            pr_err("%s : Buffer overflow at reg\n", __func__);
            return -EINVAL;
        }
        offset += len;
    }

    return offset;
}

int media_regs_dump(void)
{
	char *module_name = "regulator";
	char filename[FILENAME_LEN] = "regulator_mntn";
	char *postfix = "_log_mdfx_record.txt";
	int ret = 0;
	char log_buf[LOG_BUF_SIZE] = {0};
    int buf_len = 0;

	if (!g_media1_subsys) {
        pr_err("%s: media1_subsys is NULL\n", __func__);
        return -ENODEV;
    }

    ret = regulator_enable(g_media1_subsys);
	if (ret) {
        pr_err("%s regulator enable failed\n", __func__);
        return ret;
	}

    ret = mdfx_get_file_name(module_name, filename, postfix, FILENAME_LEN);
	if (ret) {
        (void)regulator_disable(g_media1_subsys);
		pr_err("%s : mdfx_get_file_name ret is %d, filename is %s\n", __func__, ret, filename);
        return ret;
	}
 
	buf_len = dump_regs_to_buffer(log_buf, LOG_BUF_SIZE);
    if (buf_len <= 0) {
        (void)regulator_disable(g_media1_subsys);
        pr_err("%s : Failed to dump regulators\n", __func__);
        return -ENODEV;
    }

	ret = mdfx_file_save(filename, log_buf, buf_len);
	if (ret) {
        (void)regulator_disable(g_media1_subsys);
        pr_err("%s : Failed to save regulator info to %s\n", __func__, filename);
        return ret;
	}

    (void)regulator_disable(g_media1_subsys);

	return 0;
}

static void addr_iounmap(void)
{
    int i;

    for (i = 0; i < BASE_ADDR_MAX; i++) {
        if (g_reg_base[i] != NULL) {
            iounmap(g_reg_base[i]);
            g_reg_base[i] = NULL;
        }
    }
}

static void regs_base_init(void)
{
    int i;

    for (i = 0; i < BASE_ADDR_MAX; i++)
        g_reg_base[i] = NULL;
}

static int regulator_mdfx_probe(struct platform_device *pdev)
{
    struct device_node *np = pdev->dev.of_node;
    int ret, i;
	u32 base_addr_num;

    regs_base_init();

    ret = of_property_read_u32(np, "mdfx-mntn-baseaddr-num", &base_addr_num);
    if (ret) {
        pr_err("%s Failed to get base address number\n", __func__);
        return ret;
    }

	if (base_addr_num != BASE_ADDR_MAX) { 
		pr_err("%s Exceed max CRG count (%u/%d)\n", __func__, base_addr_num, BASE_ADDR_MAX);
		return -EINVAL;
	}

     for (i = 0; i < base_addr_num; i++) {
        g_reg_base[i] = of_iomap(np, i);
        if (IS_ERR_OR_NULL(g_reg_base[i])) {
            addr_iounmap();
            pr_err("%s Failed to ioremap %d\n", __func__, i);
            return -EINVAL;
        }
    }

    g_media1_subsys = devm_regulator_get(&pdev->dev, "mdfx-mntn");
	if (IS_ERR_OR_NULL(g_media1_subsys)) {
        g_media1_subsys = NULL;
        addr_iounmap();
        pr_err("%s can't get mdfx mntn regulator\n", __func__);
        return -EINVAL;
	}

    pr_info("regulator mdfx probe setup!\n");
    return 0;
}

static int regulator_mdfx_remove(struct platform_device *pdev)
{
    (void)pdev;
    addr_iounmap();

    return 0;
}

static const struct of_device_id regulator_mdfx_of_match[] = {
    { .compatible = "hisilicon,regulator-mdfx-mntn", },
    { },
};
MODULE_DEVICE_TABLE(of, regulator_mdfx_of_match);

static struct platform_driver regulator_mdfx_driver = {
    .probe      = regulator_mdfx_probe,
    .remove     = regulator_mdfx_remove,
    .driver     = {
        .name   = "regulator-mdfx-mntn",
        .of_match_table = regulator_mdfx_of_match,
    },
};
module_platform_driver(regulator_mdfx_driver);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Regulator mdfx mntn driver");
