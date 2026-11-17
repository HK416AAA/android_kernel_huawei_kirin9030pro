/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 * Description: Phy driver.
 * Author: gemingjia@h-partners.com
 * Create: 2025-04-24
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/netdevice.h>
#include <linux/phy.h>
#include <linux/of.h>
#include <linux/clk.h>
#include <linux/ioctl.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/of_device.h>
#include <linux/compat.h>
#include <linux/device.h>
#include <linux/sysfs.h>
#include <linux/of_net.h>
#include <net/rtnetlink.h>
#include <sound/jack.h>
#include <securec.h>
#include "phy_driver.h"
#ifdef CONFIG_OSPM_ETH_POWER_MGMT
#include "eth_power_mgmt.h"
#endif
#ifdef FACTORY_MODE
static int phy_loopback_atcmd_release(struct inode *inode, struct file *filp);
static int phy_loopback_atcmd_open(struct inode *inode, struct file *filp);
static long phy_loopback_atcmd_ioctl(struct file *file, unsigned int command, unsigned long arg);
#ifdef CONFIG_COMPAT
static long phy_loopback_atcmd_ioctl_compat(struct file *file, unsigned int command, unsigned long arg);
#endif
static int phy_loopback_atcmd_do_ioctl(unsigned int cmd,	void __user *arg, int compat_mode);

static struct mdio_device_id __maybe_unused phy_driver_tbl[] = {
	{ PHY_ID, PHY_ID_MASK },
	{ }
};

static const struct file_operations phy_loopback_atcmd_fops = {
	.owner          = THIS_MODULE,
	.open           = phy_loopback_atcmd_open,
	.release        = phy_loopback_atcmd_release,
	.unlocked_ioctl = phy_loopback_atcmd_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl   = phy_loopback_atcmd_ioctl_compat,
#endif
};

static struct miscdevice phy_loopback_atcmd_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name  = "phy_loopback_atcmd",
    .fops  = &phy_loopback_atcmd_fops,
};

static atomic_t dev_speed_value = ATOMIC_INIT(0);
#endif

static int phy_hw_strap_polling(struct phy_device *phydev);
static bool g_phy_init_only_once = false;
static struct phy_device *phy_devices[MAX_PHY_ADDR];
static DEFINE_MUTEX(net_control_mutex);
static DEFINE_MUTEX(phy_array_lock);
static bool g_phy_power_status = true;
static bool g_phy_interrupt_switch = false;

static ssize_t phy_show_dev_info(struct device *dev,
                struct device_attribute *attr, char *buf)
{
    int len = 0;
	struct phy_device *phydev = NULL;
	phy_check_null_and_return((!dev || !attr || !buf), -EINVAL, "error");

    phydev = to_phy_device(dev);

    len += scnprintf(buf + len, PAGE_SIZE - len,
                     "%s,", phydev->drv ? phydev->drv->name : "NULL");
	phy_check_negative_and_return(len, len, "format error:");
    if (len >= PAGE_SIZE) {
        pr_err("[HW_PHY] [%s:%d] buffer truncated (len=%d)\n", __func__, __LINE__, len);
        return -ENOBUFS;
    }

    len += scnprintf(buf + len, PAGE_SIZE - len,
                     "%04x,YT,1000", phydev->drv ? phydev->drv->phy_id : PHY_ID_DEFAULT);
	phy_check_negative_and_return(len, len, "format error:");
    if (len >= PAGE_SIZE) {
        pr_err("[HW_PHY] [%s:%d] buffer truncated (len=%d)\n", __func__, __LINE__, len);
        return -ENOBUFS;
    }

	pr_info("[HW_PHY] phy dev info node add\n");
    return len;
}

#ifdef FACTORY_MODE
static ssize_t phy_show_dev_speed(struct device *dev,
                struct device_attribute *attr, char *buf)
{
	phy_check_null_and_return((!dev || !attr || !buf), -EINVAL, "error");
    int value = atomic_read(&dev_speed_value);
	int len = scnprintf(buf, PAGE_SIZE, "%d\n", value);
	phy_check_negative_and_return(len, len, "format error:");
    if (len >= PAGE_SIZE) {
        pr_err("[HW_PHY] [%s:%d] buffer truncated (len=%d)\n", __func__, __LINE__, len);
        return -ENOBUFS;
    }
	pr_info("[HW_PHY] phy dev speed node add\n");
    return len;
}

static void update_dev_speed_value(int new_value)
{
    atomic_set(&dev_speed_value, new_value);
}

static struct device_attribute my_attr_dev_speed =
    __ATTR(dev_speed, 0444, phy_show_dev_speed, NULL);
#endif

static struct device_attribute my_attr_dev_info = 
    __ATTR(dev_info, 0444, phy_show_dev_info, NULL);

static int phy_store_phydev(struct phy_device *phydev)
{
	phy_check_null_and_return(!phydev, -EINVAL, "error");
    int addr = phydev->mdio.addr;
	pr_info("[HW_PHY] [%s:%d] addr = %d\n", __func__, __LINE__, addr);

    if (addr < 0 || addr >= MAX_PHY_ADDR) {
		pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
        return -EINVAL;
	}

    mutex_lock(&phy_array_lock);
    phy_devices[addr] = phydev;
    mutex_unlock(&phy_array_lock);
    return EOK;
}

struct phy_device *phy_get_phydev_by_addr(int addr)
{
    struct phy_device *phydev = NULL;
	pr_info("[HW_PHY] [%s:%d] addr = %d\n", __func__, __LINE__, addr);

    if (addr < 0 || addr >= MAX_PHY_ADDR) {
		pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
        return NULL;
	}

    mutex_lock(&phy_array_lock);
    phydev = phy_devices[addr];
    mutex_unlock(&phy_array_lock);

    return phydev;
}

static int phy_write_ext(struct phy_device *phydev, u32 regnum, u16 val)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_write(phydev, REG_DEBUG_ADDR_OFFSET, regnum);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_write(phydev, REG_DEBUG_DATA, val);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int phy_judge_power_switch(struct phy_device *phydev)
{
	int ret = 0;
	int flag = 0;
	struct net_device *ndev = NULL;
    struct device *parent_dev = NULL;
    struct platform_device *pdev = NULL;
	struct device_node *eth_node = NULL;
	pr_info("[HW_PHY] [%s:%d] enter\n", __func__, __LINE__);

	phy_check_null_and_return(!phydev, -EINVAL, "error");

    ndev = phydev->attached_dev;
	phy_check_null_and_return(!ndev, -EINVAL, "error");

    parent_dev = ndev->dev.parent;
	phy_check_null_and_return(!parent_dev, -EINVAL, "error");

    pdev = to_platform_device(parent_dev);
	phy_check_null_and_return(!pdev, -EINVAL, "error");

    eth_node = pdev->dev.of_node;
	phy_check_null_and_return(!eth_node, -EINVAL, "error");

	ret = of_property_read_u32(eth_node, "power_switch", &flag);
	phy_check_negative_and_return(ret, ret, "error:");

	pr_info("[HW_PHY] [%s:%d] power_switch = %d\n", __func__, __LINE__, flag);

	if (flag) {
		phydev->power_switch = true;
	} else {
		phydev->power_switch = false;
	}

	return ret;
}

static int phy_switch_reg_space(struct phy_device *phydev, int space)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

#ifdef FACTORY_MODE
	update_dev_speed_value(phydev->speed);
#endif

	if (space == PHY_REG_SPACE_UTP) {
		ret = phy_write_ext(phydev, PHY_REG_MODE, PHY_REG_SPACE_UTP);
	} else {
		ret = phy_write_ext(phydev, PHY_REG_MODE, PHY_REG_SPACE_FIBER);
	}
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int phy_check_dev_info_status(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	if (!g_phy_init_only_once) {
		g_phy_init_only_once = true;
		ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
		phy_check_negative_and_return(ret, ret, "error:");
		ret = device_create_file(&phydev->mdio.dev, &my_attr_dev_info);
		phy_check_negative_and_return(ret, ret, "error:");
		ret = phy_judge_power_switch(phydev);
		phy_check_negative_and_return(ret, ret, "error:");
#ifdef FACTORY_MODE
		ret = device_create_file(&phydev->mdio.dev, &my_attr_dev_speed);
		phy_check_negative_and_return(ret, ret, "error:");
#endif
	}

	return ret;
}

static int check_phydev_state(struct phy_device *phydev)
{
	int max_wait_cycle = PHY_INTERRUPT_WAIT_CYCLE;
	phy_check_null_and_return(!phydev, -EINVAL, "error");
	
	do {
		if (phydev->state != PHY_HALTED) {
			break;
		}
		mdelay(PHY_INTERRUPT_WAIT_TIME);
	} while (max_wait_cycle--);

	if (phydev->state == PHY_HALTED) {
		return -ENODEV;;
	}

	return 0;
}

static int phy_sds_power_down(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");
	pr_info("[HW_PHY] [%s:%d] sds power down\n", __func__, __LINE__);

	phy_check_null_and_return(phydev->power_switch_resume, 0, "system is going to sleep");
	ret = check_phydev_state(phydev);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_write_ext(phydev, PHY_REG_MODE, PHY_REG_SPACE_FIBER);
	phy_check_negative_and_return(ret, ret, "error:");
	phy_check_null_and_return(phydev->power_switch_resume, 0, "system is going to sleep");
	ret = check_phydev_state(phydev);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_read(phydev, PHY_EXTERNAL_LOOPBACK_MII_REG);
	phy_check_negative_and_return(ret, ret, "error:");

	pr_info("[HW_PHY] [%s:%d] sds power down reg = 0x%04x\n", __func__, __LINE__, ret);
	ret |= PHY_LINK_FAILED_INTR_MASK;
	phy_check_null_and_return(phydev->power_switch_resume, 0, "system is going to sleep");
	ret = check_phydev_state(phydev);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_write(phydev, PHY_EXTERNAL_LOOPBACK_MII_REG, ret);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int phy_read_ext(struct phy_device *phydev, u32 regnum)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_write(phydev, REG_DEBUG_ADDR_OFFSET, regnum);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_read(phydev, REG_DEBUG_DATA);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static void phy_power_switch_invert(void)
{
	g_phy_power_status = !g_phy_power_status;
	pr_info("[HW_PHY] [%s:%d] g_phy_power_status : %d\n", __func__, __LINE__, g_phy_power_status);
}

static int phy_power_switch(void)
{
    int ret = 0;
    unsigned int new_flags = 0;
	struct net_device *eth0_dev = NULL;

    rtnl_lock();

    eth0_dev = dev_get_by_name(&init_net, "eth0");
    if (!eth0_dev) {
		pr_err("[HW_PHY] [%s:%d] eth0_dev not initialized\n", __func__, __LINE__);
        ret = -ENODEV;
        goto unlock;
    }

	if (g_phy_power_status) {
		new_flags = eth0_dev->flags & ~IFF_UP;
    	pr_info("[HW_PHY] eth0 down\n");
	} else {
		new_flags = eth0_dev->flags | IFF_UP;
    	pr_info("[HW_PHY] eth0 up\n");
	}
    ret = dev_change_flags(eth0_dev, new_flags, NULL);
    if (ret) {
		pr_err("[HW_PHY] [%s:%d] dev_change_flags failed: %d\n", __func__, __LINE__, ret);
		goto unlock;
    }
	dev_put(eth0_dev);
	phy_power_switch_invert();
    pr_info("[HW_PHY] successfully\n");

unlock:
    rtnl_unlock();
    return ret;
}

static int phy_power_up(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_power_switch();
	phy_check_negative_and_return(ret, ret, "error:");

	phy_check_null_and_return(phydev->power_switch_resume, 0, "system is going to sleep");
	ret = check_phydev_state(phydev);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_read(phydev, PHY_UTP_INTR_STATUS_REG);
	phy_check_negative_and_return(ret, ret, "error:");
	pr_info("[HW_PHY] [%s:%d] node status : 0x%04x\n", __func__, __LINE__, ret);

	ret &= PHY_LINK_SUCCEED_INTR_MASK;
	if (!ret) {
		pr_err("[HW_PHY] [%s:%d] power up is jitter\n", __func__, __LINE__);
    	schedule_delayed_work(&phydev->power_switch_delay_work, msecs_to_jiffies(0));
	}
	g_phy_interrupt_switch = false;
    atomic_set(&phydev->work_executing, 0);

	return ret;
}

static int phy_power_down(struct phy_device *phydev)
{
	int ret = 0;
	int link_up_int_flag = 0;
	int link_down_int_flag = 0;
	bool is_power_down = false;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	if (!g_phy_interrupt_switch) {
		is_power_down = true;
	}

	phy_check_null_and_return(phydev->power_switch_resume, 0, "system is going to sleep");
	ret = check_phydev_state(phydev);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_read(phydev, PHY_UTP_INTR_STATUS_REG);
	phy_check_negative_and_return(ret, ret, "error:");
	pr_info("[HW_PHY] [%s:%d] node status : 0x%04x\n", __func__, __LINE__, ret);
	link_down_int_flag = (ret >> PHY_INT_FAIL_OFFSET) & PHY_GET_MASK_VALUE;
	link_up_int_flag = (ret >> PHY_INT_SUCC_OFFSET) & PHY_GET_MASK_VALUE;
	if (link_up_int_flag) {
		pr_info("[HW_PHY] [%s:%d] link_up_int_flag\n", __func__, __LINE__);
		is_power_down = false;
	} else if (link_down_int_flag) {
		pr_info("[HW_PHY] [%s:%d] link_down_int_flag\n", __func__, __LINE__);
		is_power_down = true;
	}
	
	if (!is_power_down) {
		pr_err("[HW_PHY] [%s:%d] power down is jitter\n", __func__, __LINE__);
		g_phy_interrupt_switch = false;
		atomic_set(&phydev->work_executing, 0);
		return 0;
	}
	g_phy_interrupt_switch = false;
	atomic_set(&phydev->work_executing, 0);

	ret = phy_sds_power_down(phydev);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = check_phydev_state(phydev);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_power_switch();
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static void phy_power_switch_delay_work(struct work_struct *work)
{
    struct phy_device *phydev = container_of(work, struct phy_device, power_switch_delay_work.work);
	int ret = 0;
    mutex_lock(&net_control_mutex);
    atomic_set(&phydev->work_executing, 1);

	if (!phydev) {
		pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
		goto switch_end;
	}
	pr_info("[HW_PHY] [%s:%d] delay work enter\n", __func__, __LINE__);

	if (g_phy_power_status) {
		ret = phy_power_down(phydev);
		if (ret < 0) {
			pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
			goto switch_end;
		}
	} else {
		ret = phy_power_up(phydev);
		if (ret < 0) {
			pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
			goto switch_end;
		}
	}

switch_end:
    mutex_unlock(&net_control_mutex);
	pr_info("[HW_PHY] [%s:%d] delay work end\n", __func__, __LINE__);
}

bool get_work_executing_status(struct phy_device *phydev)
{
    return atomic_read(&phydev->work_executing);
}

static int hw_phy_node_switch(void)
{
	pr_info("[HW_PHY] [%s:%d] switch delay work start\n", __func__, __LINE__);
    struct phy_device *phydev = phy_get_phydev_by_addr(PHY_ETHERNET_REG);
	int ret = 0;

	phy_check_null_and_return(!phydev, -EINVAL, "error");
	phy_check_null_and_return(!phydev->power_switch, 0, "power switch not support");
	phy_check_null_and_return(phydev->power_switch_resume, 0, "system is going to sleep");

	if (!get_work_executing_status(phydev)) {
		g_phy_interrupt_switch = true;
		ret = cancel_delayed_work(&phydev->power_switch_delay_work);
		if (ret)
			pr_info("[HW_PHY] [%s:%d] cancel work success\n", __func__, __LINE__);
    	schedule_delayed_work(&phydev->power_switch_delay_work, msecs_to_jiffies(0));
	} else {
		pr_info("[HW_PHY] [%s:%d] delay_work is working\n", __func__, __LINE__);
	}

	return 0;
}

static int phy_interconnect_reg_init(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_write(phydev, PHY_INTERCONNECT_REG_ONE, PHY_INTERCONNECT_REG_ONE_INDEX);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_write(phydev, PHY_INTERCONNECT_REG_TWO, PHY_INTERCONNECT_REG_TWO_INDEX);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int hw_phy_module_init(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

#ifdef FACTORY_MODE
    atomic_set(&dev_speed_value, 0);
#endif
	INIT_DELAYED_WORK(&(phydev->power_switch_delay_work), phy_power_switch_delay_work);
    atomic_set(&phydev->work_executing, 0);

    ret = phy_store_phydev(phydev);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_check_dev_info_status(phydev);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_interconnect_reg_init(phydev);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_write(phydev, PHY_UTP_INTR_REG, PHY_NODE_SWITCH);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_read_ext(phydev, PHY_CONFIG_CONTROL1);
	phy_check_negative_and_return(ret, ret, "error:");
	ret &= ~(PHY_REG_FLAG_CLEAR_MASK);
	ret = phy_write_ext(phydev, PHY_CONFIG_CONTROL1, ret);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int phy_soft_reset_mii(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_read(phydev, MII_BMCR);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_write(phydev, MII_BMCR, ret | BMCR_RESET);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int phy_soft_reset_srds(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = BMCR_FULLDPLX | BMCR_SPEED1000;
	ret = phy_write(phydev, MII_BMCR, ret | BMCR_RESET);
	phy_check_negative_and_return(ret, ret, "error:");

	return ret;
}

static int hw_phy_soft_reset(struct phy_device *phydev)
{
	int ret = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_soft_reset_mii(phydev);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_FIBER);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_soft_reset_srds(phydev);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, ret, "error:");

	return 0;
}

static int phy_hw_strap_polling(struct phy_device *phydev)
{
	int val = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	val = phy_read_ext(phydev, PHY_STRAP_POLL) & PHY_STRAP_POLL_ADDR;
	phy_check_negative_and_return(val, val, "error:");

	if (val == PHY_VAL_FIBER) {
		return PHY_MODE_FIBER;
	} else if (val == PHY_VAL_POLL) {
		return PHY_MODE_POLL;
	} else {
		return PHY_MODE_UTP;
	}
}

static int hw_phy_config_init(struct phy_device *phydev)
{
	int ret = 0;
	int hw_strap_mode = 0;
	struct ethtool_wolinfo wol;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	hw_strap_mode = phy_read_ext(phydev, PHY_STRAP_POLL) & PHY_STRAP_POLL_ADDR;
	if (hw_strap_mode < 0) {
		pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
		return hw_strap_mode;
	}
	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, ret, "error:");

	ret = hw_phy_module_init(phydev);
	if (ret < 0)
		return ret;

	pr_info("[HW_PHY] phy mdio index: %d, strap mode = %d, polling mode = %d\n",
		phydev->mdio.addr, hw_strap_mode, phy_hw_strap_polling(phydev));

	if (phydev->power_switch) {
#ifdef CONFIG_OSPM_ETH_POWER_MGMT
		pr_info("[HW_PHY] [%s:%d] ospm eth power success\n", __func__, __LINE__);
		eth_phy_device_init(phydev);
#endif
		if (!g_phy_interrupt_switch) {
			pr_info("[HW_PHY] [%s:%d] phy init without interrupt\n", __func__, __LINE__);
			schedule_delayed_work(&phydev->power_switch_delay_work, msecs_to_jiffies(0));
		}
	}

	return ret;
}

static int phy_adjust_status(struct phy_device *phydev, int val, int is_utp)
{
	int speed_mode = 0;
	int duplex = 0;
	int speed = SPEED_UNKNOWN;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	if (is_utp)
		duplex = (val & PHY_DUPLEX) >> PHY_DUPLEX_BIT;
	else
		duplex = 1;
	speed_mode = (val & PHY_SPEED_MODE) >> PHY_SPEED_MODE_BIT;
	switch (speed_mode) {
	case PHY_ADJUST_STATUS_TEN:
		if (is_utp)
			speed = SPEED_10;
		break;
	case PHY_ADJUST_STATUS_HUNDRED:
		speed = SPEED_100;
		break;
	case PHY_ADJUST_STATUS_THOUSAND:
		speed = SPEED_1000;
		break;
	default:
		speed = SPEED_UNKNOWN;
		break;
	}

	phydev->speed = speed;
	phydev->duplex = duplex;

	return 0;
}

static int hw_phy_aneg_done(struct phy_device *phydev)
{
	int ret = 0;
	int link_fiber = 0;
	int link_utp = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_FIBER);
	phy_check_negative_and_return(ret, ret, "error:");
	ret = phy_read(phydev, PHY_REG_SPEC_STATUS);
	phy_check_negative_and_return(ret, ret, "error:");
	link_fiber = !!(ret & (BIT(PHY_LINK_STATUS_BIT)));

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, ret, "error:");
	if (!link_fiber)
		link_utp = !!(phy_read(phydev, PHY_REG_SPEC_STATUS) & (BIT(PHY_LINK_STATUS_BIT)));

	pr_info("phy mdio index: %d, link_fiber: %d, link_utp: %d\n",
		phydev->mdio.addr, link_fiber, link_utp);
	return !!(link_fiber | link_utp);
}

static int hw_phy_read_status(struct phy_device *phydev)
{
	int ret = 0;
	volatile int val = 0;
	volatile int link = 0;
	volatile int link1 = 0;
	int link_utp = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, ret, "error:");
	val = phy_read(phydev, PHY_REG_SPEC_STATUS);
	phy_check_negative_and_return(val, val, "error:");
	link = val & (BIT(PHY_LINK_STATUS_BIT));

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_FIBER);
	phy_check_negative_and_return(ret, ret, "error:");
	val = phy_read(phydev, PHY_REG_SPEC_STATUS);
	phy_check_negative_and_return(val, val, "error:");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, ret, "error:");

	link1 = val & (BIT(PHY_LINK_STATUS_BIT));
	if (link && link1) {
		link_utp = 1;
		phy_adjust_status(phydev, val, 1);
	} else {
		link_utp = 0;
	}

	if (link_utp) {
		if (phydev->link == 0)
			pr_info("[HW_PHY] phy mdio index: %d, link up, media: %s, mii reg 0x11 = 0x%x\n",
			phydev->mdio.addr, (link_utp ? "UTP" : "Fiber"), (unsigned int)val);
		phydev->link = 1;
	} else {
		if (phydev->link == 1)
			pr_info("[HW_PHY] phy mdio index: %d, link down\n", phydev->mdio.addr);
		phydev->link = 0;
	}

	return 0;
}

static int hw_phy_loopback(struct phy_device *phydev, int speed)
{
	int ret = 0;
	u16 val = 0;
	phy_check_null_and_return(!phydev, -EINVAL, "error");
 
    phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	val = phy_read_ext(phydev, PHY_EXTERNAL_LOOPBACK_SLEEP_CLOSE);
	phy_check_negative_and_return(val, val, "error:");
	val = val & (~PHY_EXLOOPBACK_CLOSE_SLEEP);
	ret = phy_write_ext(phydev, PHY_EXTERNAL_LOOPBACK_SLEEP_CLOSE, val);
	phy_check_negative_and_return(ret, ret, "error:");
	
	val = phy_read_ext(phydev, PHY_EXTERNAL_LOOPBACK_UTP_REG);
	phy_check_negative_and_return(val, val, "error:");
	val = val | PHY_EXLOOPBACK_SOFT_RESET;
	ret = phy_write_ext(phydev, PHY_EXTERNAL_LOOPBACK_UTP_REG, val);
	phy_check_negative_and_return(ret, ret, "error:");

	if (speed == PHY_EXTERNAL_LOOPBACK_MONDE_TEN) {
		ret = phy_write(phydev, PHY_EXTERNAL_LOOPBACK_MII_REG, PHY_EXTERNAL_LOOPBACK_TEN);
	} else if (speed == PHY_EXTERNAL_LOOPBACK_MONDE_HUNDRED) {
		ret = phy_write(phydev, PHY_EXTERNAL_LOOPBACK_MII_REG, PHY_EXTERNAL_LOOPBACK_HUNDRED);
	} else if (speed == PHY_EXTERNAL_LOOPBACK_MONDE_THOUSAND) {
		ret = phy_write(phydev, PHY_EXTERNAL_LOOPBACK_MII_REG, PHY_EXTERNAL_LOOPBACK_THOUSAND);
	}
	phy_check_negative_and_return(ret, ret, "error:");
 
	return ret;
}

static bool phy_is_link(struct phy_device *phydev)
{
	int ret = 0;
	int val = 0;
	bool link_utp = false;
	bool link_sds = false;
	phy_check_null_and_return(!phydev, false, "error");

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_UTP);
	phy_check_negative_and_return(ret, false, "error:");

	val = phy_read(phydev, PHY_REG_SPEC_STATUS);
	pr_info("PHY_is_link utp ling reg val = 0x%x\n", val);
	phy_check_negative_and_return(val, false, "error:");
	link_utp = !!(val & (BIT(PHY_LINK_STATUS_BIT)));

	ret = phy_switch_reg_space(phydev, PHY_REG_SPACE_FIBER);
	phy_check_negative_and_return(ret, false, "error:");

	val = phy_read(phydev, PHY_REG_SPEC_STATUS);
	pr_info("PHY_is_link sds ling reg val = 0x%x\n", val);
	phy_check_negative_and_return(val, false, "error:");

	link_sds = !!(val & (BIT(PHY_LINK_STATUS_BIT)));

	return (link_utp && link_sds);
}

static int phy_external_loopback(int speed)
{
	int try_times = PHY_EXTERNAL_LOOPBACK_MAX_TRY_TIME;
	int ret = 0;
    struct phy_device *phydev = phy_get_phydev_by_addr(PHY_ETHERNET_REG);
	
	phy_check_null_and_return(!phydev, -EINVAL, "error");

	ret = phy_loopback(phydev, speed);
	phy_check_negative_and_return(ret, ret, "error:");

	while (try_times--) {
		if (phy_is_link(phydev))
			break;
		msleep(PHY_EXTERNAL_LOOPBACK_WAIT_TIME);
	}

	if (try_times <= 0) {
		pr_err("slt: set phy loopback timeout!\n");
		return -ETIMEDOUT;
	}

	return ret;
}

static int hw_phy_resume(struct phy_device *phydev)
{
	pr_info("[HW_PHY] [%s:%d] enter\n", __func__, __LINE__);
	phy_check_null_and_return(!phydev, -EINVAL, "error");
	if (phydev->power_switch_resume) {
		pr_info("[HW_PHY] [%s:%d] resume start g_phy_power_status = %d\n", __func__, __LINE__, g_phy_power_status);
		if (!g_phy_power_status) {
			schedule_delayed_work(&phydev->power_switch_delay_work, msecs_to_jiffies(0));
		}
	}
	return 0;
}

static struct phy_driver hw_phy_drvs[] = {
	{
		.phy_id         = PHY_ID,
		.name           = "Phy Ethernet",
		.phy_id_mask    = PHY_ID_MASK,
		.features       = PHY_GBIT_FEATURES,
		.flags          = PHY_POLL,
		.soft_reset     = hw_phy_soft_reset,
		.aneg_done      = hw_phy_aneg_done,
		.config_init    = hw_phy_config_init,
		.read_status    = hw_phy_read_status,
		.node_switch    = hw_phy_node_switch,
		.resume 		= hw_phy_resume,
	},
};

module_phy_driver(hw_phy_drvs);

#ifdef FACTORY_MODE
static int phy_loopback_atcmd_open(struct inode *inode, struct file *filp)
{
	int ret = 0;
	pr_info("[HW_PHY] [%s:%d] phy_loopback_atcmd_open +\n", __func__, __LINE__);
	phy_check_null_and_return(!inode, -EINVAL, "error");
	phy_check_null_and_return(!filp, -EINVAL, "error");

	ret = nonseekable_open(inode, filp);
	phy_check_negative_and_return(ret, ret, "error:");

    filp->private_data = NULL;
	pr_info("[HW_PHY] [%s:%d] phy_loopback_atcmd_open -\n", __func__, __LINE__);
	return ret;
}

static int phy_loopback_atcmd_release(struct inode *inode, struct file *filp)
{
	phy_check_null_and_return(!inode, -EINVAL, "error");
	phy_check_null_and_return(!filp, -EINVAL, "error");

	filp->private_data = NULL;
	return 0;
}

static long phy_loopback_atcmd_ioctl(struct file *file, unsigned int command,
	unsigned long arg)
{
	return phy_loopback_atcmd_do_ioctl(command, (void __user *)(uintptr_t)arg, 0);
}

static int phy_loopback_atcmd_set_speaker_direction(void __user *arg)
{
	EXTERNAL_LOOPBACK_SPEED speed_dir = 0;
	phy_check_null_and_return(!arg, -EINVAL, "error");
	phy_check_null_and_return(!access_ok(arg, sizeof(EXTERNAL_LOOPBACK_SPEED)),
							 -EINVAL, "error");
	int ret = copy_from_user(&speed_dir, arg, sizeof(EXTERNAL_LOOPBACK_SPEED));
	if (ret != 0) {
		pr_err("[HW_PHY] [%s:%d] error\n", __func__, __LINE__);
		return ret;
	}

	if (speed_dir == SP_TEN) {
		ret = phy_external_loopback(PHY_EXTERNAL_LOOPBACK_MONDE_TEN);
	} else if (speed_dir == SP_HUNDRED) {
		ret = phy_external_loopback(PHY_EXTERNAL_LOOPBACK_MONDE_HUNDRED);
	} else if (speed_dir == SP_THOUSAND) {
		ret = phy_external_loopback(PHY_EXTERNAL_LOOPBACK_MONDE_THOUSAND);
	}
	phy_check_negative_and_return(ret, ret, "error:");
	return 0;
}
#ifdef CONFIG_COMPAT
static long phy_loopback_atcmd_ioctl_compat(struct file *file,
	unsigned int command, unsigned long arg)
{
	if (command == GET_EXTERNAL_LOOPBACK_SPEED_DIR_COMP) {
		command = GET_EXTERNAL_LOOPBACK_SPEED_DIR;
	}

	return phy_loopback_atcmd_do_ioctl(command, compat_ptr((unsigned int)arg), 1);
}
#else
#define phy_loopback_atcmd_ioctl_compat NULL
#endif

static int phy_loopback_atcmd_do_ioctl(unsigned int cmd,
	void __user *arg, int compat_mode)
{
	int ret = 0;

	if (cmd == GET_EXTERNAL_LOOPBACK_SPEED_DIR) {
		ret = phy_loopback_atcmd_set_speaker_direction(arg);
	}

	return ret;
}

int __init phy_hw_gpio_key_driver_init(void)
{
	int ret = 0;
	pr_info("[HW_PHY] [%s:%d]+\n", __func__, __LINE__);

	ret = misc_register(&phy_loopback_atcmd_miscdev);
	phy_check_negative_and_return(ret, ret, "error:");
	pr_info("[HW_PHY] [%s:%d]-\n", __func__, __LINE__);
	return ret;
}

void __exit phy_hw_gpio_key_driver_exit(void)
{
	pr_info("[HW_PHY] [%s:%d]\n", __func__, __LINE__);
	misc_deregister(&phy_loopback_atcmd_miscdev);
}

module_init(phy_hw_gpio_key_driver_init);
module_exit(phy_hw_gpio_key_driver_exit);

MODULE_DEVICE_TABLE(mdio, phy_driver_tbl);
MODULE_ALIAS("phy gpio key button module");
MODULE_DESCRIPTION("phy gpio key button driver");
MODULE_LICENSE("GPL");
#endif
