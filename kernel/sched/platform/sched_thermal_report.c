/*
 * sched_thermal report.c
 *
 * sched thermal report
 *
 * Copyright (c) 2025-2026 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include "sched.h"
#include <securec.h>
#include <linux/compat.h>
#include <linux/module.h>
#include <linux/device.h>
#include <net/genetlink.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#include <linux/thermal.h>
#include <linux/of.h>
#include <linux/ktime.h>
#ifdef CONFIG_LIBLINUX
#include <liblinux/pal.h>
#endif
#ifdef CONFIG_THERMAL_POWER_QUOTA
#include <platform_include/cee/linux/lpm_thermal.h>
#endif
#ifdef CONFIG_SCHED_CHIP_INFO
#include <platform_include/cee/linux/sched_chip_info.h>
#endif
#include <platform_include/cee/linux/dpm_manage.h>

struct sched_thermal {
	struct miscdevice dev;
	struct list_head port_list;
	struct mutex lock;

	int shell_temp;
	int report_shell_temp;
	unsigned int update_threshold;
	struct pm_qos_request dpm_req;
};

static struct sched_thermal *g_sched_thermal_dev;
static ktime_t g_thermal_update_last_time;

struct port_t {
	struct list_head node;
	unsigned int portid;
};

enum sched_thermal_ioctl_cmd {
	SCHED_THERMAL_CMD_SET_PORTID = 1,
	SCHED_THERMAL_CMD_GET_SHELLTEMP,
};

enum {
	GENL_ATTR_UNSPEC,
	GENL_ATTR_EVENT,
	GENL_ATTR_MAX,
};

#define GENL_NAME                   "SCHED_THERMAL"
#define GENL_VERSION                 0x01
#define GENL_ATTR_MAX                (GENL_ATTR_MAX - 1)

#define THERMAL_UPDATE_CYCLE_MS 1000

#define SHELL_THERMAL_CMD 50
#define PTR_LEVEL_CMD    51
#define PTR_LEVEL_UPDATE_MIN_INTERVAL 100

static struct genl_family genl_family = {
	.name       = GENL_NAME,
	.version    = GENL_VERSION,
	.maxattr    = GENL_ATTR_MAX,
};

static int genlink_check(struct port_t *port, uint32_t data_len)
{
	if (port->portid == 0) {
		pr_err("%s no portid error\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static void send_status_to_uplayer(struct port_t *port, int *inputdata,
				   unsigned int data_len, unsigned char cmd_type)
{
	struct sk_buff *skb;
	struct nlmsghdr *nlh = NULL;
	void *msg_header;
	char *data;
	int result;

	result = genlink_check(port, data_len);
	if (result != 0) {
		pr_err("%s genlink_check fail=%d\n", __func__, result);
		return;
	}

	skb = genlmsg_new((size_t)data_len, GFP_ATOMIC);
	if (skb == NULL)
		return;

	/* add the genetlink message header */
	msg_header = genlmsg_put(skb, 0, 0, &genl_family, 0, cmd_type);
	if (msg_header == NULL) {
		nlmsg_free(skb);
		return;
	}

	/* fill the data */
	data = nla_reserve_nohdr(skb, (int)data_len);
	if (data == NULL) {
		nlmsg_free(skb);
		return;
	}

	result = memcpy_s(data, (size_t)data_len, inputdata, (size_t)data_len);
	if (result != EOK) {
		nlmsg_free(skb);
		pr_err("%s memset_s fail[%d]\n", __func__, result);
		return;
	}

	/* if aligned, just set real data_len */
	nlh = (struct nlmsghdr *)((unsigned char *)msg_header - GENL_HDRLEN - NLMSG_HDRLEN);
	nlh->nlmsg_len = data_len + GENL_HDRLEN + (unsigned int)NLMSG_HDRLEN;

	/* send unicast genetlink message */
	result = genlmsg_unicast(&init_net, skb, port->portid);
	if (result != 0)
		pr_err("%s Failed to send netlink. event:%d", __func__, result);
}

static int handle_report_data(unsigned char cmd, unsigned int *data, uint32_t data_len)
{
	struct port_t *port = NULL;
	struct list_head *pos = NULL;

	if (data == NULL || data_len == 0) {
		pr_err("%s status param is NULL\n", __func__);
		return -EINVAL;
	}
	mutex_lock(&g_sched_thermal_dev->lock);
	list_for_each(pos, &g_sched_thermal_dev->port_list) {
		port = container_of(pos, struct port_t, node);
		send_status_to_uplayer(port, data, data_len, cmd);
	}
	mutex_unlock(&g_sched_thermal_dev->lock);
	return 0;
}

static void sched_thermal_update(int shell_temp)
{
	int last_shell_temp = g_sched_thermal_dev->report_shell_temp;
	unsigned int threshold = g_sched_thermal_dev->update_threshold;

	g_sched_thermal_dev->shell_temp = shell_temp;
	if (abs(shell_temp - last_shell_temp) > threshold) {
		g_sched_thermal_dev->report_shell_temp = shell_temp;
		handle_report_data(SHELL_THERMAL_CMD, &shell_temp, sizeof(int));
	}
}

static void sched_ptr_level_update(ktime_t now)
{
#ifdef CONFIG_HISI_PTR_FEATURE
	static int last_level = 0;
	static ktime_t last_update = 0;
	ktime_t delta;
	int level;
	int ret;

	ret = liblinux_pal_get_ptr_level(&level, sizeof(int));
	if (ret != 0) {
		pr_err("%s: get ptr level failed\n", __func__);
		return;
	}
	if (level == last_level) {
		return;
	}
	delta = ktime_sub(now, last_update);
	if (ktime_to_ms(delta) < PTR_LEVEL_UPDATE_MIN_INTERVAL) {
		return;
	}
	last_update = now;
	last_level = level;
	handle_report_data(PTR_LEVEL_CMD, &level, sizeof(int));
#else
	(void)now;
#endif
}

static int sched_get_shell_temp(int *shell_temp)
{
	int temp;
	struct thermal_zone_device *shell_tz = NULL;

	shell_tz = thermal_zone_get_zone_by_name("shell_frame");
	if (IS_ERR(shell_tz)) {
		pr_err("get shell zone error\n");
		return -EPERM;
	}
	if (thermal_zone_get_temp(shell_tz, &temp) != 0) {
		pr_err("get shell temp error\n");
		return -EPERM;
	}

	*shell_temp = temp;

	return 0;
}

static void sched_thermal_shell_temp_update(ktime_t now)
{
	int shell_temp = 0;
	ktime_t delta = ktime_sub(now, g_thermal_update_last_time);
	s64 delta_ms = ktime_to_ms(delta);
	if (delta_ms >= THERMAL_UPDATE_CYCLE_MS) {
		if (!sched_get_shell_temp(&shell_temp)) {
			sched_thermal_update(shell_temp);
		}
		g_thermal_update_last_time = now;
	}
}

#ifdef CONFIG_SCHED_CHIP_INFO
static void power_chip_vote_dpm_state(void)
{
	int ret;

	if (get_soc_is_bottom_power())
		ret = dpm_pwr_state_add_request(&g_sched_thermal_dev->dpm_req, DPM_POWER_ON);
	else
		ret = dpm_pwr_state_add_request(&g_sched_thermal_dev->dpm_req, DPM_POWER_OFF);

	if (ret)
		pr_err("%s: power chip vote dpm failed,ret=%d\n", __func__, ret);
}
#else
static void power_chip_vote_dpm_state(void) {}
#endif

static struct delayed_work g_sched_thermal_work;
static void sched_thermal_work(struct work_struct *work)
{
	ktime_t now = ktime_get();

	sched_thermal_shell_temp_update(now);
#ifdef CONFIG_THERMAL_POWER_QUOTA
	margin_thermal_update_dpm_state();
#endif
	sched_ptr_level_update(now);
	mod_delayed_work(system_freezable_power_efficient_wq,
			 &g_sched_thermal_work,
			 msecs_to_jiffies(100));
}

static void sched_thermal_work_init(void)
{
	INIT_DEFERRABLE_WORK(&g_sched_thermal_work, sched_thermal_work);

	mod_delayed_work(system_freezable_power_efficient_wq,
			 &g_sched_thermal_work,
			 msecs_to_jiffies(0));
}

static void sched_thermal_work_exit(void)
{
	cancel_delayed_work(&g_sched_thermal_work);
}

static int ioctl_set_sched_thermal_portid(struct port_t *port, unsigned long arg)
{
	unsigned int data = 0;

	if (!access_ok((void __user *)((uintptr_t)arg), sizeof(unsigned int))) {
		pr_err("%s: invalid user pointer\n", __func__);
		return -EFAULT;
	}
	if (copy_from_user(&data, (void *)((uintptr_t)arg), sizeof(unsigned int))) {
		pr_err("%s copy_from_user error\n", __func__);
		return -EFAULT;
	}
	port->portid = data;
	return 0;
}

static int ioctl_get_now_shell_temp(unsigned long arg)
{
	int shell_temp = g_sched_thermal_dev->shell_temp;

	if (copy_to_user((void *)((uintptr_t)arg), &shell_temp, sizeof(int))) {
		pr_err("%s copy_to_user error\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static long sched_thermal_ioctl(struct file *file, unsigned int cmd,
		unsigned long arg)
{
	long ret = 0;
	struct port_t *port = NULL;

	if (!file) {
		pr_err("sched thermal ioctl file is null\n");
		return -EINVAL;
	}

	port = (struct port_t *)file->private_data;
	if (!port) {
		pr_err("sched thermal ioctl param error\n");
		return -EINVAL;
	}

	switch (cmd) {
	case SCHED_THERMAL_CMD_SET_PORTID:
		ret = ioctl_set_sched_thermal_portid(port, arg);
		break;
	case SCHED_THERMAL_CMD_GET_SHELLTEMP:
		ret = ioctl_get_now_shell_temp(arg);
		break;
	default:
		pr_err("sched thermal cmd:0x%x invalid\n", cmd);
		ret = -EINVAL;
		break;
	}

	return ret;
}

static int sched_thermal_open(struct inode *inode, struct file *file)
{
	struct port_t *port = NULL;
	int ret = 0;

	if (!file) {
		pr_err("sched thermal open file is null\n");
		return -EACCES;
	}

	mutex_lock(&g_sched_thermal_dev->lock);
	port = kzalloc(sizeof(struct port_t), GFP_KERNEL);
	if (!port) {
		pr_err("sched thermal open no mem\n");
		ret = -EINVAL;
		goto unlock;
	}
	list_add_tail(&port->node, &g_sched_thermal_dev->port_list);
	file->private_data = port;

unlock:
	mutex_unlock(&g_sched_thermal_dev->lock);
	return ret;
}

static int sched_thermal_release(struct inode *inode, struct file *file)
{
	struct port_t *port = file->private_data;

	if (!port)
		return -EINVAL;

	file->private_data = NULL;
	mutex_lock(&g_sched_thermal_dev->lock);
	list_del(&port->node);
	mutex_unlock(&g_sched_thermal_dev->lock);
	kfree(port);

	return 0;
}

#ifdef CONFIG_COMPAT
static long sched_thermal_compact_ioctl(struct file *file, unsigned int cmd,
		unsigned long arg)
{
	return sched_thermal_ioctl(file, cmd, (unsigned long)(compat_ptr(arg)));
}
#endif

static const struct file_operations sched_thermal_fops = {
	.owner = THIS_MODULE,
	.open = sched_thermal_open,
#ifdef CONFIG_COMPAT
	.compat_ioctl = sched_thermal_compact_ioctl,
#endif
	.unlocked_ioctl = sched_thermal_ioctl,
	.release = sched_thermal_release,
};

static struct miscdevice sched_thermal_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "sched_thermal_report",
	.fops = &sched_thermal_fops,
};

static int __init sched_thermal_report_init(void)
{
	struct sched_thermal *sched_thermal = NULL;
	int ret;

	sched_thermal = kzalloc(sizeof(struct sched_thermal), GFP_KERNEL);
	if (!sched_thermal) {
		pr_err("failed to alloc sched thermal device mem\n");
		return -ENOMEM;
	}

	sched_thermal->dev = sched_thermal_dev;
	sched_thermal->update_threshold = 1000;
	mutex_init(&sched_thermal->lock);
	INIT_LIST_HEAD(&sched_thermal->port_list);
	g_sched_thermal_dev = sched_thermal;

	ret = misc_register(&sched_thermal->dev);
	if (ret) {
		g_sched_thermal_dev = NULL;
		kfree(sched_thermal);
		pr_err("failed to register misc device\n");
		return ret;
	}

	power_chip_vote_dpm_state();
	sched_thermal_work_init();

	return 0;
}

static void __exit sched_thermal_report_exit(void)
{
	struct sched_thermal *sched_thermal = g_sched_thermal_dev;

	sched_thermal_work_exit();
	misc_deregister(&sched_thermal->dev);
	g_sched_thermal_dev = NULL;
	kfree(sched_thermal);
}

module_init(sched_thermal_report_init);
module_exit(sched_thermal_report_exit);
