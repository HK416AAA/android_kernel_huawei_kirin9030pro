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
#include <linux/jiffies.h>
#include <linux/io.h>
#include <linux/of.h>
#include <securec.h>
#include <linux/arm_ffa.h>
#include <platform_include/see/ffa/ffa_msg_id.h>
#include <platform_include/see/ffa/ffa_plat_drv.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_def.h>
#include <platform_include/cee/linux/lpcpu_idle_sleep.h>
#include <doze.h>
#include "iodie_dev.h"

#define HIPHYIO_INT_STATUS            0x8
#define HIPHYIO_VOTE_REG_ADDR         0x3000
#define HIPHYIO_LP_STATUS_ADDR        0x3010
#define HIPHYIO_FNPLL_VOTE            0x3018
#define HIPHYIO_FNPLL_STATUS          0x3014
#define HIPHYIO_FNPLL_SOFT_EN         0x660
#define HIPHYIO_FNPLL_STATUS_MASK     0x1 
#define HIPHYIO_FNPLL_VOTE_EN         0x10001
#define HIPHYIO_FNPLL_VOTE_DIS        0x10000

#define HIPHYIO_VOTE_REG_STEP         0x4
#define HIPHYIO_LP_STATUS_MASK        0x3
#define HIPHYIO_VOTE_GROUP_MASK       0x30000
#define hiphyio_vote_group_offset(n)  (((n) % 8) * 2)
#define hiphyio_vote_group_addr(n)    (((n) / 8) * 0x4)

#define HIPHYIO_VOTE_GROUP_KERNEL     8
#define HIPHYIO_VOTE_GROUP_BOOT       9
#define HIPHYIO_VOTE_GROUP_MAX        32
#define HIPHYIO_VOTE_WAIT_TIMES       100
#define HIPHYIO_VOTE_WAIT_STEP        10    // us

#define AO_CRG_CTRL_SD_ADDR           0xC68
#define PERI_CFG_DMAC_CTRL0_ADDR      0xC18
#define PERI_CFG_DMAC_CTRL1_ADDR      0xC1C

enum iodie_drv_ops { // sec config x1 define
	HIPHYIO_SEC_CFG_FNPLL,
	HIPHYIO_SEC_CFG_CLK,
};

enum hiphyio_sec_cfg_fnpll_ops { // sec config HIPHYIO_SEC_CFG_FNPLL, x2 define
	HIPHYIO_DRV_FNPLL_CLOSE,
	HIPHYIO_DRV_FNPLL_OPEN,
};

enum hiphyio_sec_cfg_clk_ops { // sec config HIPHYIO_SEC_CFG_CLK, x2 define
	HIPHYIO_DRV_CAM_CLK0_OPEN,
	HIPHYIO_DRV_CAM_CLK0_23M,
	HIPHYIO_DRV_CAM_CLK0_19M,
	HIPHYIO_DRV_CAM_CLK0_CLOSE,
};

#define FREQ_19M2               19200
#define FREQ_23M33              23330

#ifndef array_size
#define array_size(array) (sizeof(array) / sizeof((array)[0]))
#endif

struct iodie_hiphyio_info {
	bool inited;
	bool hio_avail;
	void __iomem *host_addr;
	void __iomem *slv_addr;
};

struct iodie_addr_map {
	enum iodie_module module;
	uint32_t start_addr;
	uint32_t end_addr;
};

struct iodie_clk_cfg {
	enum iodie_module module;
	uint32_t addr;
	uint32_t val;
};

static struct iodie_hiphyio_info g_iodie_info;
static struct iodie_addr_map g_iodie_addr_map[IODIE_IP_END] = {
	{IODIE_IP_AO_SEC_REGION, 0x00000000, 0x00001FFF},
	{IODIE_IP_AO_CFG, 0x00002000, 0x00002FFF},
	{IODIE_IP_AO_CRG, 0x00004000, 0x00004FFF},
	{IODIE_IP_EFUSE, 0x00006000, 0x00006FFF},
	{IODIE_IP_HIPHYIO, 0x00008000, 0x0000BFFF},
	{IODIE_IP_I2C0, 0x0000C000, 0x0000CFFF},
	{IODIE_IP_I2C1, 0x0000D000, 0x0000DFFF},
	{IODIE_IP_I2C3, 0x0000E000, 0x0000EFFF},
	{IODIE_IP_I2C5, 0x0000F000, 0x0000FFFF},
	{IODIE_IP_I3C1, 0x00010000, 0x00010FFF},
	{IODIE_IP_USIM0, 0x00014000, 0x00014FFF},
	{IODIE_IP_USIM1, 0x00015000, 0x00015FFF},
	{IODIE_IP_ADC, 0x00016000, 0x00016FFF},
	{IODIE_IP_GPIO0, 0x0001A000, 0x0001AFFF},
	{IODIE_IP_GPIO1, 0x0001B000, 0x0001BFFF},
	{IODIE_IP_GPIO2, 0x0001C000, 0x0001CFFF},
	{IODIE_IP_GPIO3, 0x0001D000, 0x0001DFFF},
	{IODIE_IP_GPIO4, 0x0001E000, 0x0001EFFF},
	{IODIE_IP_IOC, 0x0001F000, 0x0001FFFF},
	{IODIE_IP_AO_QIC_DFX, 0x00020000, 0x0002FFFF},
	{IODIE_IP_RAM, 0x00031000, 0x00050FFF},
	{IODIE_IP_PERI_SEC_REGION, 0x00052000, 0x00052FFF},
	{IODIE_IP_DSPI, 0x00053000, 0x00054FFF},
	{IODIE_IP_DMA0, 0x00055000, 0x00055FFF},
	{IODIE_IP_PERI_CRG, 0x00056000, 0x00057FFF},
	{IODIE_IP_PERI_CFG, 0x00058000, 0x00058FFF},
	{IODIE_IP_I3C0, 0x00059000, 0x00059FFF},
	{IODIE_IP_I3C2, 0x0005B000, 0x0005BFFF},
	{IODIE_IP_I2C2, 0x0005D000, 0x0005DFFF},
	{IODIE_IP_I2C4, 0x0005E000, 0x0005EFFF},
	{IODIE_IP_ISP_I2C0, 0x0005F000, 0x0005FFFF},
	{IODIE_IP_ISP_I2C1, 0x00060000, 0x00060FFF},
	{IODIE_IP_UART0, 0x00065000, 0x00065FFF},
	{IODIE_IP_UART1, 0x00066000, 0x00066FFF},
	{IODIE_IP_UART2, 0x00067000, 0x00067FFF},
	{IODIE_IP_SPMI, 0x00068000, 0x0006BFFF},
	{IODIE_IP_UART_AUDIO, 0x0006C000, 0x0006CFFF},
	{IODIE_IP_ONEWIRE0, 0x0006D000, 0x0006DFFF},
	{IODIE_IP_ONEWIRE1, 0x0006E000, 0x0006EFFF},
	{IODIE_IP_PERI_QIC_DFX, 0x00070000, 0x0007FFFF},
};

static struct iodie_clk_cfg g_iodie_clk[IODIE_IP_END] = {
	{IODIE_IP_ADC, 0xC00, BIT(24)},

	{IODIE_IP_DSPI, 0xC00, BIT(1) | BIT(2)},
	{IODIE_IP_I3C0, 0xC00, BIT(17)},
	{IODIE_IP_I3C2, 0xC00, BIT(18)},
	{IODIE_IP_I2C2, 0xC00, BIT(15)},
	{IODIE_IP_I2C4, 0xC00, BIT(16)},
	{IODIE_IP_UART0, 0xC00, BIT(3)},
	{IODIE_IP_UART1, 0xC00, BIT(4)},
	{IODIE_IP_UART2, 0xC00, BIT(5)},
	{IODIE_IP_SPMI, 0xC00, BIT(6)},
	{IODIE_IP_ONEWIRE0, 0xC00, BIT(7) | BIT(9)},
	{IODIE_IP_ONEWIRE1, 0xC00, BIT(8) | BIT(10)},
};

int iodie_dev_check(void)
{
	if (!g_iodie_info.inited)
		pr_err("%s: no inited\n", __func__);

	if (!g_iodie_info.hio_avail)
		pr_err("%s: hiphyio not avail\n", __func__);

	return g_iodie_info.inited & g_iodie_info.hio_avail;
}

void iodie_dev_set_hio_availble(bool val)
{
	g_iodie_info.hio_avail = val;
	pr_err("%s:set avail to %d\n", __func__, val);
}

void iodie_dev_writel(unsigned int module, unsigned int addr, unsigned int val)
{
	if (!iodie_dev_check())
		return;

	if (g_iodie_info.slv_addr == NULL) {
		pr_err("%s:iodie slave is null!\n", __func__);
		return;
	}

	if (module >= IODIE_IP_END) {
		pr_err("%s:module %u is invalid!\n", __func__, module);
		return;
	}

	if (addr > (g_iodie_addr_map[module].end_addr - g_iodie_addr_map[module].start_addr)) {
		pr_err("%s:addr 0x%x is invalid!\n", __func__, addr);
		return;
	}

	writel(val, g_iodie_addr_map[module].start_addr + g_iodie_info.slv_addr + addr);
}

unsigned int iodie_dev_readl(unsigned int module, unsigned int addr)
{
	if (!iodie_dev_check())
		return 0;
 
	if (g_iodie_info.slv_addr == NULL) {
		pr_err("%s:iodie slv addr is null!\n", __func__);
		return 0;
	}

	if (module >= IODIE_IP_END) {
		pr_err("%s:module %u is invalid!\n", __func__, module);
		return 0;
	}

	if (addr > (g_iodie_addr_map[module].end_addr - g_iodie_addr_map[module].start_addr)) {
		pr_err("%s:addr 0x%x is invalid!\n", __func__, addr);
		return 0;
	}

	return readl(g_iodie_addr_map[module].start_addr + g_iodie_info.slv_addr + addr);
}

static void hiphyio_vote(enum iodie_runtime_status status, unsigned int group)
{
	uint32_t val;
	uint32_t offset;
	uint32_t addr;

	if ((status > IODIE_RT_NORMAL_HIGH) || (status == IODIE_RT_RESERVED)) {
		pr_err("%s:vote status %u invalid!\n", __func__, status);
		return;
	}

	if (group >= HIPHYIO_VOTE_GROUP_MAX) {
		pr_err("%s:vote group %u invalid!\n", __func__, group);
		return;
	}

	offset = hiphyio_vote_group_offset(group);
	addr = hiphyio_vote_group_addr(group);
	val = (status << offset) | (HIPHYIO_VOTE_GROUP_MASK << offset);
	writel(val, addr + g_iodie_info.host_addr + HIPHYIO_VOTE_REG_ADDR);
}

inline unsigned int iodie_dev_lp_status(void)
{
	if (!iodie_dev_check())
		return IODIE_RT_ERROR;

	return readl(g_iodie_info.host_addr + HIPHYIO_LP_STATUS_ADDR) & HIPHYIO_LP_STATUS_MASK;
}

static void iodie_hiphy_vote_info(void)
{
	if (!iodie_dev_check())
		return;

	pr_err("%s: 0x%x 0x%x 0x%x 0x%x\n", __func__, readl(g_iodie_info.host_addr + HIPHYIO_VOTE_REG_ADDR), 
		readl(g_iodie_info.host_addr + HIPHYIO_VOTE_REG_ADDR + HIPHYIO_VOTE_REG_STEP * 1),
		readl(g_iodie_info.host_addr + HIPHYIO_VOTE_REG_ADDR + HIPHYIO_VOTE_REG_STEP * 2),
		readl(g_iodie_info.host_addr + HIPHYIO_VOTE_REG_ADDR + HIPHYIO_VOTE_REG_STEP * 3));
}

void iodie_dev_hiphy_dump(void)
{
	pr_err("%s: need to check\n", __func__);
}

static int iodie_dev_hiphy_vote(unsigned int status, unsigned int group)
{
	uint32_t times = HIPHYIO_VOTE_WAIT_TIMES;
	uint32_t val;

	pr_info("%s: status %u, group %u\n", __func__, status, group);

	if (!iodie_dev_check())
		return -EFAULT;

	hiphyio_vote(status, group);
	while(times > 0) {
		udelay(HIPHYIO_VOTE_WAIT_STEP);
		val = iodie_dev_lp_status();
		if (val == status)
			break;
		if ((val > status) && (val != IODIE_RT_RESERVED))
			break;
		times--;
	}

	if (times == 0) {
		pr_err("%s: fail, exp 0x%x, real 0x%x\n", __func__, status, val);
		iodie_hiphy_vote_info();
		iodie_dev_hiphy_dump();
		return -EFAULT;
	}

	return EOK;
}

int iodie_dev_hiphy_vote_kernel(unsigned int status)
{
	if (status == IODIE_RT_SUSPEND)
		vote_enable_doze(DOZE_CLIENT_HIPHYIO);
	else
		vote_disable_doze(DOZE_CLIENT_HIPHYIO);

	return iodie_dev_hiphy_vote(status, HIPHYIO_VOTE_GROUP_KERNEL);
}

int iodie_dev_hiphy_vote_boot(unsigned int status)
{
	return iodie_dev_hiphy_vote(status, HIPHYIO_VOTE_GROUP_BOOT);
}

/* sec read and write */
static int iodie_hiphyio_sec_config(uint32_t x1, uint32_t x2)
{
	int ret;
	struct ffa_send_direct_data args = {0};

	args.data0 = IODIE_HIPHYIO_DRV_FID;
	args.data1 = x1;
	args.data2 = x2;

	ret = ffa_platdrv_send_msg(&args);
	if (ret != 0) {
		pr_err("%s:ffa_platdrv_send_msg fail! ret:%d\n", __func__, ret);
		return ret;
	}

	return args.data1;
}

int iodie_dev_clk_cfg(unsigned int op, unsigned int freq)
{
	uint32_t cmd;

	if ((freq == FREQ_19M2) && (op == IODIE_CLK_CAM_REF_SEL)) {
		cmd = HIPHYIO_DRV_CAM_CLK0_19M;
	} else if ((freq == FREQ_23M33) && (op == IODIE_CLK_CAM_REF_SEL)) {
		cmd = HIPHYIO_DRV_CAM_CLK0_23M;
	} else if (op == IODIE_CLK_CAM_REF_CLOSE) {
		cmd = HIPHYIO_DRV_CAM_CLK0_CLOSE;
	} else if (op == IODIE_CLK_CAM_REF_OPEN) {
		cmd = HIPHYIO_DRV_CAM_CLK0_OPEN;
	} else {
		pr_err("%s:invalid para freq %u op %u\n", __func__, freq, op);
		return  -EINVAL;
	}

	return iodie_hiphyio_sec_config(HIPHYIO_SEC_CFG_CLK, cmd);
}

int iodie_dev_fnpll_enable(void)
{
	uint32_t val;
	uint32_t times = HIPHYIO_VOTE_WAIT_STEP;
	uint32_t locked_times = 0;

	if (!iodie_dev_check())
		return -EFAULT;

	lpcpu_idle_sleep_vote(ID_IODIE, 1);
	iodie_dev_writel(IODIE_IP_HIPHYIO, HIPHYIO_FNPLL_VOTE, HIPHYIO_FNPLL_VOTE_EN);
	
	udelay(80);
	while (times > 0) {
		val = iodie_dev_readl(IODIE_IP_HIPHYIO, HIPHYIO_FNPLL_STATUS);
		if (val & HIPHYIO_FNPLL_STATUS_MASK)
			locked_times++;

		// stable after 3 locked times
		if (locked_times == 3)
			break;

		udelay(HIPHYIO_VOTE_WAIT_STEP);
		times--;
	}

	if (times == 0) {
		pr_err("%s: fail\n", __func__);
		lpcpu_idle_sleep_vote(ID_IODIE, 0);
		return -EFAULT;
	}

	pr_info("%s: success\n", __func__);

	return EOK;
}

void iodie_dev_fnpll_disable(void)
{
	lpcpu_idle_sleep_vote(ID_IODIE, 0);

	if (!iodie_dev_check())
		return;

	iodie_dev_writel(IODIE_IP_HIPHYIO, HIPHYIO_FNPLL_VOTE, HIPHYIO_FNPLL_VOTE_DIS);

	pr_info("%s: success\n", __func__);
}

void iodie_dev_clk_en(unsigned int module)
{
	uint32_t i;
	uint32_t m_id;

	if (!iodie_dev_check())
		return;

	if (module <= IODIE_IP_AO_QIC_DFX) {
		m_id = IODIE_IP_AO_CRG;
		pr_info("%s: ao module\n", __func__);
	} else {
		m_id = IODIE_IP_PERI_CRG;
		pr_info("%s: peri module\n", __func__);
	}

	for (i = 0; i < array_size(g_iodie_clk); i++) {
		if (g_iodie_clk[i].module == module) {
			iodie_dev_writel(m_id, g_iodie_clk[i].addr, g_iodie_clk[i].val);
			pr_info("%s: module %u clk en val:0x%x status:0x%x\n", __func__, module, g_iodie_clk[i].val,
				iodie_dev_readl(m_id, g_iodie_clk[i].addr + 0x8));
		}
	}

	if (module == IODIE_IP_DMA0) {
		iodie_dev_writel(IODIE_IP_PERI_CRG, PERI_CFG_DMAC_CTRL0_ADDR, 0x3);
		iodie_dev_writel(IODIE_IP_PERI_CRG, PERI_CFG_DMAC_CTRL1_ADDR, 0x3);
		pr_info("%s: peri module dma enable finish\n", __func__);
	}
}

void iodie_dev_clk_dis(unsigned int module)
{
	uint32_t i;
	uint32_t m_id;

	if (!iodie_dev_check())
		return;

	if (module <= IODIE_IP_AO_QIC_DFX) {
		m_id = IODIE_IP_AO_CRG;
		pr_info("%s: ao module\n", __func__);
	} else {
		m_id = IODIE_IP_PERI_CRG;
		pr_info("%s: peri module\n", __func__);
	}

	for (i = 0; i < array_size(g_iodie_clk); i++) {
		if (g_iodie_clk[i].module == module) {
			iodie_dev_writel(m_id, g_iodie_clk[i].addr + 0x4, g_iodie_clk[i].val);
			pr_info("%s: module %u val:0x%x status:0x%x\n", __func__, module, g_iodie_clk[i].val,
				iodie_dev_readl(m_id, g_iodie_clk[i].addr + 0x8));
		}
	}
}

int get_iodie_dts_status(void)
{
	int len = 0;
	struct device_node *node = NULL;
	const char *status = NULL;

	node = of_find_compatible_node(NULL, NULL, "hisilicon,io-die");
	if (node != NULL) {
		status = of_get_property(node, "status", &len);
		if (status == NULL) {
			pr_err("[%s]of_get_property status err\n", __func__);
			return -EINVAL;
		}
		
		pr_info("[%s] status %s\n", __func__, status);
		if (strstr(status, "ok"))
			return EOK;
	}

	return -EINVAL;
}

static int get_hiphyio_dts_info(void)
{
	struct device_node *node = NULL;
	uint32_t reg_addr;
	uint32_t reg_size;
	int ret;

	node = of_find_compatible_node(NULL, NULL, "hisilicon,io-die");
	if (node == NULL) {
		pr_err("can not find hisilicon,io-die node !\n");
		return -EFAULT;
	}

	ret = of_property_read_u32_index(node, "host_reg", 0, &reg_addr);
	if (ret) {
		pr_err("%s failed to get host reg addr! ret=%d\n", __func__, ret);
		return -EFAULT;
	}

	ret = of_property_read_u32_index(node, "host_reg", 1, &reg_size);
	if (ret) {
		pr_err("%s failed to get host reg size! ret=%d\n", __func__, ret);
		return -EFAULT;
	}

	g_iodie_info.host_addr = ioremap(reg_addr, reg_size);
	if (g_iodie_info.host_addr == NULL){
		pr_err("%s host reg addr is null\n", __func__);
		return -EFAULT;
	}

	ret = of_property_read_u32_index(node, "slv_reg", 0, &reg_addr);
	if (ret) {
		pr_err("%s failed to get slv reg addr! ret=%d\n", __func__, ret);
		goto error;
	}

	ret = of_property_read_u32_index(node, "slv_reg", 1, &reg_size);
	if (ret) {
		pr_err("%s failed to get slv reg size! ret=%d\n", __func__, ret);
		goto error;
	}

	g_iodie_info.slv_addr = ioremap(reg_addr, reg_size);
	if (g_iodie_info.slv_addr  == NULL){
		pr_err("%s slv reg addr is null\n", __func__);
		goto error;
	}

	return EOK;

error:
	iounmap(g_iodie_info.host_addr);
	return -EFAULT;
}

static int __init iodie_dev_init(void)
{
	int ret;

	if (get_iodie_dts_status() != EOK) {
		pr_err("%s: iodie node is not enable\n", __func__);
		return -1;
	}

	ret = get_hiphyio_dts_info();
	if (ret != EOK) {
		pr_err("%s get hiphyio dts info failed, ret %d\n", __func__, ret);
		return -1;
	}

	g_iodie_info.inited = true;
	g_iodie_info.hio_avail = true;

	pr_info("%s ok\n", __func__);

	return EOK;
}

static void __exit iodie_dev_exit(void)
{
	if (g_iodie_info.inited == 0)
		return;

	g_iodie_info.inited = 0;

	iounmap(g_iodie_info.host_addr);
	iounmap(g_iodie_info.slv_addr);

	pr_info("exit %s\n", __func__);
}

arch_initcall_sync(iodie_dev_init);
module_exit(iodie_dev_exit);