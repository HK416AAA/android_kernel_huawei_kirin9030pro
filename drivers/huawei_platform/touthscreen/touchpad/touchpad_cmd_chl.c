/*
 * Huawei touchpad command channel
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/hid.h>
#include <linux/delay.h>
#include <securec.h>
#include "touchpad_func.h"
#include "touchpad_api.h"

#define TOUCHPAD_GET_LOG_REPORT_ID		0x18
#define TOUCHPAD_FUNC_STATE_REPORT_ID	0x08
#define TOUCHPAD_MCU_VER_REPORT_ID		0x17

#define TOUCHPAD_LOG_PKG_LEN			256

struct touchpad_log_data {
	uint16_t total_pkg;
	uint16_t current_pkg;
	uint8_t buf[TOUCHPAD_LOG_PKG_LEN];
};

struct touchpad_func_state {
	uint16_t len;
	uint8_t report_id;
	uint8_t func;
	uint8_t func_state;
};

struct touchpad_mcu_ver {
	uint16_t len;
	uint8_t report_id;
	uint8_t version[HW_FREETOUCH_FW_VERSION_LENTH];
};

#ifdef TOUCHPAD_FACTORY_ENABLE
#define TOUCHPAD_I2C_RDWR			_IOWR(0xED, 0x10, struct i2c_rdwr_ioctl_data)
#endif
#define TOUCHPAD_GET_LOG_PKG_NUM	_IOR(0xED, 0x11, uint16_t)
#define TOUCHPAD_GET_LOG_PKG		_IOWR(0xED, 0x12, struct touchpad_log_data)
#define TOUCHPAD_SET_FUNC_STATE		_IOW(0xED, 0x13, uint16_t)
#define TOUCHPAD_SET_TIME			_IOW(0xED, 0x14, uint64_t)
#define TOUCHPAD_GET_MCU_VER		_IOR(0xED, 0x15, uint8_t[HW_FREETOUCH_FW_VERSION_LENTH])
#define RDWR_MAX_MSGS				32
#define RDWR_MSG_MAX_LEN			8192

struct tp_cmd_chl_dev {
	int major;
	struct class *class;
	struct device *dev;
	struct i2c_client *client;
};

static struct tp_cmd_chl_dev *g_tp_cmd_chl_dev = NULL;

#ifdef TOUCHPAD_FACTORY_ENABLE
static TestFunc test_func = NULL;
void touchpad_register_test_func(TestFunc func)
{
	test_func = func;
}
#endif

static int tp_cmd_chl_open(struct inode *inode, struct file *filp)
{
	int ret;
	if ((inode == NULL) || (filp == NULL)) {
		pr_err("%s, invalid arguments\n", __func__);
		return -EINVAL;
	}

	ret = nonseekable_open(inode, filp);
	if (ret < 0) {
		pr_err("%s, nonseekable_open failed, %d\n", __func__, ret);
		return ret;
	}

	filp->private_data = (void *)g_tp_cmd_chl_dev;
	return ret;
}

static int tp_cmd_chl_release(struct inode *inode, struct file *filp)
{
	if ((inode == NULL) || (filp == NULL)) {
		pr_err("%s, invalid arguments\n", __func__);
		return -EINVAL;
	}

	filp->private_data = NULL;
	return 0;
}

#ifdef TOUCHPAD_FACTORY_ENABLE
static int tp_cmd_chl_ioctl_rdwr(struct i2c_client *client, struct i2c_msg *msgs, unsigned nmsgs)
{
	u8 __user **user_data_ptrs;
	int i;
	int j;
	int ret;

	if (!client || !msgs)
		return -EINVAL;

	user_data_ptrs = kmalloc_array(nmsgs, sizeof(u8 __user *), GFP_KERNEL);
	if (user_data_ptrs == NULL) {
		pr_err("%s, alloc user data failed\n", __func__);
		return -ENOMEM;
	}

	for (i = 0; i < nmsgs; i++) {
		if (msgs[i].len > RDWR_MSG_MAX_LEN) {
			pr_err("%s, msg data too long: %d\n", __func__, msgs[i].len);
			ret = -EINVAL;
			break;
		}
		msgs[i].addr = client->addr;
		user_data_ptrs[i] = (u8 __user *)msgs[i].buf;
		msgs[i].buf = memdup_user(user_data_ptrs[i], msgs[i].len);
		if (IS_ERR(msgs[i].buf)) {
			pr_err("%s, dump user data failed\n", __func__);
			ret = PTR_ERR(msgs[i].buf);
			break;
		}
		msgs[i].flags |= I2C_M_DMA_SAFE;
	}

	/* free memory alloced by kmalloc_array and memdup_user after failed */
	if (ret < 0) {
		for (j = 0; j < i; ++j)
			kfree(msgs[j].buf);
		kfree(user_data_ptrs);
		return ret;
	}

	ret = i2c_transfer(client->adapter, msgs, nmsgs);
	/* copy data to user and free memory */
	while (i-- > 0) {
		if (ret >= 0 && (msgs[i].flags & I2C_M_RD)) {
			if (copy_to_user(user_data_ptrs[i], msgs[i].buf, msgs[i].len)) {
				pr_err("%s, copy data to user failed\n", __func__);
				ret = -EFAULT;
			}
		}
		kfree(msgs[i].buf);
	}
	kfree(user_data_ptrs);
	return ret;
}
#endif

static int tp_cmd_chl_set_log_index(struct i2c_client *client, uint16_t total, uint16_t cur)
{
	int ret;
	uint8_t reply[64];
	struct touchpad_cmd_pkg pkg;
	const uint8_t hid_head[] = {0x05, 0x00, 0x3F, 0x03, 0x18, 0x06, 0x00};
	uint8_t send_buf[sizeof(hid_head) + sizeof(pkg)];

	pr_info("%s, enter! total: %d, cur: %d\n", __func__, total, cur);
	pkg.len = sizeof(pkg);
	pkg.report_id = TOUCHPAD_GET_LOG_REPORT_ID;
	pkg.cmd_id = 0xC8;
	pkg.cmd_dir = 0x2;
	pkg.total_pkg = total;
	pkg.current_pkg = cur;

	ret = memcpy_s(send_buf, sizeof(send_buf), hid_head, sizeof(hid_head));
	if (ret) {
		pr_err("%s, copy hid head failed, ret: %d\n", __func__, ret);
		return ret;
	}

	ret = memcpy_s(send_buf + sizeof(hid_head), sizeof(send_buf) - sizeof(hid_head), (uint8_t *)&pkg, sizeof(pkg));
	if (ret) {
		pr_err("%s, copy pkg failed, ret: %d\n", __func__, ret);
		return ret;
	}

	ret = i2c_master_send(client, send_buf, sizeof(send_buf));
	if (ret != sizeof(send_buf))
		return -EREMOTEIO;

	ret = i2c_master_recv(client, reply, sizeof(reply));
	if (ret != sizeof(reply))
		return -EREMOTEIO;

	pr_info("%s, reply: %*ph\n", __func__, sizeof(reply), reply);
	return 0;
}

static int tp_cmd_chl_get_log_data(struct i2c_client *client, struct touchpad_cmd_pkg *pkg)
{
	int ret;
	struct i2c_msg msgs[2];
	const int data_len = sizeof(struct touchpad_cmd_pkg);
	uint8_t hid_head[] = {0x05, 0x00, 0x3F, 0x02, 0x18, 0x06, 0x00};

	msgs[0].addr = client->addr;
	msgs[0].flags = client->flags;
	msgs[0].len = sizeof(hid_head);
	msgs[0].buf = hid_head;

	msgs[1].addr = client->addr;
	msgs[1].flags = client->flags | I2C_M_RD;
	msgs[1].len = data_len;
	msgs[1].buf = (uint8_t *)pkg;

	ret = i2c_transfer(client->adapter, msgs, 2); // 2: msg len
	if (ret != 2) // 2: recv 2 byte data
		return -EREMOTEIO;

	return 0;
}

static int tp_cmd_chl_get_log_total_pkg(struct i2c_client *client, unsigned long arg)
{
	int ret;
	struct touchpad_cmd_pkg pkg;
	uint16_t __user *argp = (uint16_t __user *)arg;
	if (!argp) {
		pr_err("%s, argp is NULL\n", __func__);
		return -EFAULT;
	}

	ret = tp_cmd_chl_set_log_index(client, 0, 0);
	if (ret) {
		pr_err("%s, set log idx failed, ret: %d\n", __func__, ret);
		return ret;
	}

	ret = tp_cmd_chl_get_log_data(client, &pkg);
	if (ret) {
		pr_err("%s, get log data failed, ret: %d\n", __func__, ret);
		return ret;
	}

	put_user(pkg.total_pkg, argp);
	return 0;
}

static int tp_cmd_chl_get_log_pkg(struct i2c_client *client, unsigned long arg)
{
	int ret;
	struct touchpad_cmd_pkg pkg;
	struct touchpad_log_data __user *user_log_data = (struct touchpad_log_data __user *)arg;
	struct touchpad_log_data log_data;

	if (!client || !user_log_data) {
		pr_err("%s, client or user_log_data is NULL\n", __func__);
		return -EFAULT;
	}

	if (copy_from_user(&log_data, user_log_data, sizeof(log_data))) {
		pr_err("%s, copy user data failed\n", __func__);
		return -EFAULT;
	}

	ret = tp_cmd_chl_set_log_index(client, log_data.total_pkg, log_data.current_pkg);
	if (ret) {
		pr_err("%s, set log idx failed, ret: %d\n", __func__, ret);
		return ret;
	}

	ret = tp_cmd_chl_get_log_data(client, &pkg);
	if (ret) {
		pr_err("%s, get log data failed, ret: %d\n", __func__, ret);
		return ret;
	}

	if (copy_to_user(user_log_data->buf, pkg.buf, sizeof(pkg.buf))) {
		pr_err("%s, copy data to user failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int tp_cmd_chl_set_func_state(struct i2c_client *client, unsigned long arg)
{
	int ret;
	uint8_t reply[64];
	uint16_t func_info;
	struct touchpad_func_state state;
	const uint8_t hid_head[] = {0x05, 0x00, 0x38, 0x03, 0x06, 0x00};
	uint8_t send_buf[sizeof(hid_head) + sizeof(state)];

	pr_info("%s, enter\n", __func__);
	uint16_t __user *argp = (uint16_t __user *)arg;
	if (!argp) {
		pr_err("%s, argp is NULL\n", __func__);
		return -EFAULT;
	}
	if (get_user(func_info, argp)) {
		pr_err("%s, get user data failed\n", __func__);
		return -EFAULT;
	}

	state.len = sizeof(state);
	state.report_id = TOUCHPAD_FUNC_STATE_REPORT_ID;
	state.func = (func_info >> 8) & 0xff; // 8: move 8 bit
	state.func_state = func_info & 0xff;

	ret = memcpy_s(send_buf, sizeof(send_buf), hid_head, sizeof(hid_head));
	if (ret) {
		pr_err("%s, copy hid head failed, ret: %d\n", __func__, ret);
		return ret;
	}

	ret = memcpy_s(send_buf + sizeof(hid_head), sizeof(send_buf) - sizeof(hid_head), (uint8_t *)&state, sizeof(state));
	if (ret) {
		pr_err("%s, copy state failed, ret: %d\n", __func__, ret);
		return ret;
	}

	pr_info("%s, func_info: 0x%x, func: 0x%x, func_state: 0x%x\n", __func__, func_info, state.func, state.func_state);

	ret = i2c_master_send(client, send_buf, sizeof(send_buf));
	if (ret != sizeof(send_buf))
		return -EREMOTEIO;

	msleep(1);

	ret = i2c_master_recv(client, reply, sizeof(reply));
	if (ret != sizeof(reply))
		return -EREMOTEIO;

	pr_info("%s, reply: %*ph\n", __func__, sizeof(reply), reply);
	return 0;
}

static int tp_cmd_chl_set_time(struct i2c_client *client, unsigned long arg)
{
	int ret;
	uint64_t time;

	pr_info("%s, enter\n", __func__);
	uint64_t __user *argp = (uint64_t __user *)arg;
	if (!argp) {
		pr_err("%s, argp is NULL\n", __func__);
		return -EFAULT;
	}
	if (get_user(time, argp)) {
		pr_err("%s, get user data failed\n", __func__);
		return -EFAULT;
	}

	pr_info("%s, time: %lld\n", __func__, time);

	return touchpad_sync_time(client, time);
}

static int tp_cmd_chl_get_mcu_ver(struct i2c_client *client, unsigned long arg)
{
	int ret;
	struct touchpad_mcu_ver ver;
	struct i2c_msg msgs[2];
	uint8_t hid_head[] = {0x05, 0x00, 0x3F, 0x02, 0x17, 0x06, 0x00};
	const int data_len = sizeof(struct touchpad_mcu_ver);

	uint8_t __user *argp = (uint8_t __user *)arg;
	if (!argp) {
		pr_err("%s, argp is NULL\n", __func__);
		return -EFAULT;
	}

	msgs[0].addr = client->addr;
	msgs[0].flags = client->flags;
	msgs[0].len = sizeof(hid_head);
	msgs[0].buf = hid_head;

	msgs[1].addr = client->addr;
	msgs[1].flags = client->flags | I2C_M_RD;
	msgs[1].len = data_len;
	msgs[1].buf = (uint8_t *)&ver;

	ret = i2c_transfer(client->adapter, msgs, 2); // 2: msg len
	if (ret != 2) // 2:　recv 2 byte data
		return -EREMOTEIO;

	if (copy_to_user(argp, ver.version, sizeof(ver.version))) {
		pr_err("%s, copy data to user failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static long tp_cmd_chl_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int ret;
	struct i2c_msg *msgs;
	struct i2c_rdwr_ioctl_data rdwr_data;
	if (!file)
		return -EINVAL;

	struct tp_cmd_chl_dev *tp_cmd_chl_dev = (struct tp_cmd_chl_dev *)file->private_data;
	if (!tp_cmd_chl_dev || !tp_cmd_chl_dev->client || !arg) {
		pr_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}

	pr_info("%s, cmd: 0x%x\n", __func__, cmd);
	switch (cmd) {
#ifdef TOUCHPAD_FACTORY_ENABLE
		case TOUCHPAD_I2C_RDWR:
			if (copy_from_user(&rdwr_data, (struct i2c_rdwr_ioctl_data __user *)arg, sizeof(rdwr_data))) {
				pr_err("%s, copy user data failed\n", __func__);
				return -EFAULT;
			}
			if (!rdwr_data.msgs || rdwr_data.nmsgs == 0 || rdwr_data.nmsgs > RDWR_MAX_MSGS) {
				pr_err("%s, invalid user param\n", __func__);
				return -EINVAL;
			}
			msgs = memdup_user(rdwr_data.msgs, rdwr_data.nmsgs * sizeof(struct i2c_msg));
			if (IS_ERR(msgs)) {
				pr_err("%s, dump user data failed\n", __func__);
				return PTR_ERR(msgs);
			}
			ret = tp_cmd_chl_ioctl_rdwr(tp_cmd_chl_dev->client, msgs, rdwr_data.nmsgs);
			kfree(msgs);
			break;
		case TOUCHPAD_FAC_TEST_IN_SOC:
			ret = -EINVAL;
			if (test_func)
				ret = test_func();
			break;
#endif
		case TOUCHPAD_GET_LOG_PKG_NUM:
			ret = tp_cmd_chl_get_log_total_pkg(tp_cmd_chl_dev->client, arg);
			break;
		case TOUCHPAD_GET_LOG_PKG:
			ret = tp_cmd_chl_get_log_pkg(tp_cmd_chl_dev->client, arg);
			break;
		case TOUCHPAD_SET_FUNC_STATE:
			ret = tp_cmd_chl_set_func_state(tp_cmd_chl_dev->client, arg);
			break;
		case TOUCHPAD_SET_TIME:
			ret = tp_cmd_chl_set_time(tp_cmd_chl_dev->client, arg);
			break;
		case TOUCHPAD_GET_MCU_VER:
			ret = tp_cmd_chl_get_mcu_ver(tp_cmd_chl_dev->client, arg);
			break;
		default:
			pr_err("%s, invalid cmd: 0x%x\n", __func__, cmd);
			ret = -ENOTTY;
			break;
	}

	return ret;
}

static struct file_operations tp_cmd_chl_fops = {
	.owner = THIS_MODULE,
	.open = tp_cmd_chl_open,
	.release = tp_cmd_chl_release,
	.unlocked_ioctl = tp_cmd_chl_ioctl,
};

static int touchpad_cmd_chl_probe(struct i2c_client *client)
{
	int major;
	int err;
	struct class *class;
	struct device *dev;

	if (client == NULL || g_tp_cmd_chl_dev != NULL)
		return -EINVAL;

	g_tp_cmd_chl_dev = kmalloc(sizeof(struct tp_cmd_chl_dev), GFP_KERNEL);
	if (g_tp_cmd_chl_dev == NULL)
		return -ENOMEM;

	major = register_chrdev(0, "tp_cmd_chl", &tp_cmd_chl_fops);
	class = class_create(THIS_MODULE, "tp_cmd_chl");
	if (IS_ERR(class)) {
		err = PTR_ERR(class);
		goto err_chrdev;
	}

	dev = device_create(class, NULL, MKDEV(major, 0), NULL, "tp_cmd_chl");
	if (IS_ERR(dev)) {
		err = PTR_ERR(dev);
		goto err_class;
	}
	g_tp_cmd_chl_dev->client = client;
	g_tp_cmd_chl_dev->class = class;
	g_tp_cmd_chl_dev->dev = dev;
	g_tp_cmd_chl_dev->major = major;

	return 0;

err_class:
	class_destroy(class);
err_chrdev:
	unregister_chrdev(major, "tp_cmd_chl");
	kfree(g_tp_cmd_chl_dev);
	g_tp_cmd_chl_dev = NULL;

	return err;
}

static void touchpad_cmd_chl_remove()
{
	if (g_tp_cmd_chl_dev) {
		device_destroy(g_tp_cmd_chl_dev->class, MKDEV(g_tp_cmd_chl_dev->major, 0));
		class_destroy(g_tp_cmd_chl_dev->class);
		unregister_chrdev(g_tp_cmd_chl_dev->major, "tp_cmd_chl");
		kfree(g_tp_cmd_chl_dev);
		g_tp_cmd_chl_dev = NULL;
	}
}

static struct touchpad_func tp_cmd_chl_func = {
	.name = "tp_cmd_chl",
	.type = TOUCHPAD_CMD_CHL,
	.probe = touchpad_cmd_chl_probe,
	.remove = touchpad_cmd_chl_remove,
};

static int __init touchpad_cmd_chl_init(void)
{
	return touchpad_register_func(&tp_cmd_chl_func);
}

static void __exit touchpad_cmd_chl_exit(void)
{
	touchpad_unregister_func(&tp_cmd_chl_func);
}

late_initcall(touchpad_cmd_chl_init);
module_exit(touchpad_cmd_chl_exit);

MODULE_AUTHOR("Huawei Technologies Co., Ltd");
MODULE_DESCRIPTION("touchpad module driver");
MODULE_LICENSE("GPL");