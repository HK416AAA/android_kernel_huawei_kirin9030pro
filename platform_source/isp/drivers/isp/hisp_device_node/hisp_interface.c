/*
 * hisi isp device node driver
 *
 * Copyright (c) 2025- hisi ISP Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/completion.h>
#include <linux/miscdevice.h>
#include <linux/delay.h>
#include <hisp_interface.h>
#include <platform_include/isp/linux/hisp_remoteproc.h>
#include <platform_include/isp/linux/hisp_mempool.h>
#include <securec.h>
#include "hisp_internel.h"
#include "hisp_driver_interface_cann.h"
#ifndef DEBUG_HISP
#include <linux/types.h>
#endif

struct hisp_device_s {
	atomic_t open_cnt;
	struct mutex hisp_mutex;
	struct isp_msg_content *isp2user_msgs;
	unsigned int msg_read_idx;
	unsigned int msg_write_idx;
	struct completion rpmsg_queue_comp;
	struct mutex msg_queue_mutex;
	isp_dev_state isp_dev_fsm;
#ifndef DEBUG_HISP
	pid_t process_tgid[MAX_HISP_CANN];
#endif
} hisp_dev;

static bool hisp_intf_rpmsg_queue_is_full(void)
{
	struct hisp_device_s *dev = &hisp_dev;

	if (((dev->msg_write_idx > dev->msg_read_idx) &&
		(dev->msg_write_idx - dev->msg_read_idx == HISP_RPMSG_MAX_NUM)) ||
		((dev->msg_write_idx < dev->msg_read_idx) &&
		(dev->msg_read_idx - dev->msg_write_idx == 1))) {
		return true;
	}

	return false;
}

static bool hisp_intf_rpmsg_queue_is_empty(void)
{
	struct hisp_device_s *dev = &hisp_dev;

	if (dev->msg_write_idx == dev->msg_read_idx) {
		return true;
	}

	return false;
}

static unsigned int hisp_intf_rpmsg_queue_get_next_index(unsigned int index)
{
	unsigned int new_index = index;

	new_index++;

	if (new_index == HISP_RPMSG_MAX_NUM + 1) {
		new_index = 0;
	}

	return new_index;
}

int hisp_intf_rpmsg_cb(void *data, unsigned int len)
{
	struct hisp_device_s *dev = &hisp_dev;
	int ret = 0;

	mutex_lock(&dev->msg_queue_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_err("[%s]: isp device is not power up\n", __func__);
		goto ERR_RET;
	}

	if (dev->isp2user_msgs == NULL) {
		pr_err("[%s]:msg queue not initialized\n", __func__);
		goto ERR_RET;
	}

	if (hisp_intf_rpmsg_queue_is_full()) {
		pr_err("[%s]:msg queue is full\n", __func__);
		goto ERR_RET;
	}

	ret = memcpy_s(&dev->isp2user_msgs[dev->msg_write_idx], sizeof(struct isp_msg_content), data, len);
	if (ret != 0) {
		pr_err("[%s]:memcpy_s msg failed\n", __func__);
		goto ERR_RET;
	}

	pr_info("api_name 0x%x message_id 0x%x\n",
		dev->isp2user_msgs[dev->msg_write_idx].info.api_name, dev->isp2user_msgs[dev->msg_write_idx].info.message_id);

	dev->msg_write_idx = hisp_intf_rpmsg_queue_get_next_index(dev->msg_write_idx);

	complete(&dev->rpmsg_queue_comp);

	mutex_unlock(&dev->msg_queue_mutex);

	return 0;

ERR_RET:
	mutex_unlock(&dev->msg_queue_mutex);
	return -1;
}

static int hisp_intf_power_up(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	hisp_pu_info_t pu_info = {0};
	unsigned long ret1;

	pr_info("[%s] +\n", __func__);

	ret1 = copy_from_user(&pu_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(pu_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_OPEN) {
		pr_err("[%s] Failed : isp device state %d error\n", __func__, dev->isp_dev_fsm);
		pu_info.result = -1;
		goto ERR_RET;
	}

	mutex_lock(&dev->msg_queue_mutex);

	reinit_completion(&dev->rpmsg_queue_comp);
	dev->msg_read_idx = 0;
	dev->msg_write_idx = 0;
	dev->isp2user_msgs =
		(struct isp_msg_content *)vzalloc(sizeof(struct isp_msg_content) * (HISP_RPMSG_MAX_NUM + 1));
	if (dev->isp2user_msgs == NULL) {
		pr_err("[%s] Failed : kzalloc fail\n", __func__);
		pu_info.result = -1;
		mutex_unlock(&dev->msg_queue_mutex);
		goto ERR_RET;
	}

	mutex_unlock(&dev->msg_queue_mutex);

	pu_info.result = hisp_power_up_cann(hisp_intf_rpmsg_cb);
	if (pu_info.result != 0) {
		pr_err("[%s] Failed : hisp_rproc_enable. ret 0x%x\n", __func__, pu_info.result);
		mutex_lock(&dev->msg_queue_mutex);
		vfree(dev->isp2user_msgs);
		dev->isp2user_msgs = NULL;
		mutex_unlock(&dev->msg_queue_mutex);
		goto ERR_RET;
	}

	dev->isp_dev_fsm = ISP_DEV_POWER_UP;

ERR_RET:
	mutex_unlock(&dev->hisp_mutex);

	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&pu_info, sizeof(pu_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	pr_info("[%s] -\n", __func__);

	return pu_info.result;
}

static int hisp_intf_power_down(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	hisp_pd_info_t pd_info = {0};
	unsigned long ret1;

	pr_info("[%s] +\n", __func__);

	ret1 = copy_from_user(&pd_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(pd_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_err("[%s] Failed : isp device state %d error\n", __func__, dev->isp_dev_fsm);
		pd_info.result = -1;
		goto ERR_RET;
	}

	mutex_lock(&dev->msg_queue_mutex);
	vfree(dev->isp2user_msgs);
	dev->isp2user_msgs = NULL;
	mutex_unlock(&dev->msg_queue_mutex);

	pd_info.result = hisp_power_down_cann();
	if (pd_info.result != 0) {
		pr_err("[%s] Failed : hisp_rproc_disable. ret 0x%x\n", __func__, pd_info.result);
	}

	dev->isp_dev_fsm = ISP_DEV_OPEN;

ERR_RET:
	mutex_unlock(&dev->hisp_mutex);

	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&pd_info, sizeof(pd_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	pr_info("[%s] -\n", __func__);

	return pd_info.result;
}

static int hisp_intf_set_clk_rate(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	hisp_set_clk_t clk_info = {0};
	unsigned long ret1;

	pr_info("[%s] +\n", __func__);

	ret1 = copy_from_user(&clk_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(clk_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_err("[%s] Failed : isp device state %d error\n", __func__, dev->isp_dev_fsm);
		clk_info.result = -1;
		goto ERR_RET;
	}

	clk_info.result = hisp_set_clk_rate_cann(clk_info.type, clk_info.clk_level);
	if (clk_info.result != 0) {
		pr_err("[%s] Failed : hisp_set_clk_rate. ret 0x%x\n", __func__, clk_info.result);
	}

ERR_RET:
	mutex_unlock(&dev->hisp_mutex);

	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&clk_info, sizeof(clk_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	pr_info("[%s] -\n", __func__);

	return clk_info.result;
}

static int hisp_intf_mem_map(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	hisp_mem_map_t mem_map_info = {0};
	struct hisp_mem_type mem_type = {0};
	struct hisp_map_info_s map_info = {0};
	struct hisp_mem_info_s mem_info = {0};
	unsigned long ret1;

	ret1 = copy_from_user(&mem_map_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(mem_map_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	mem_type.master = mem_map_info.master_type;
	mem_type.mem_type = mem_map_info.mem_type;

	map_info.fd = mem_map_info.fd;
	map_info.size = mem_map_info.size;
	map_info.prot = mem_map_info.prot;

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_err("[%s] Failed : isp device state %d error\n", __func__, dev->isp_dev_fsm);
		mem_map_info.result = -1;
		goto ERR_RET;
	}

	if (!hisp_check_isp_power_sate(CANN_OP)) {
		pr_info("[%s]:sec isp conflict\n", __func__);
		mem_map_info.result = ISP_DEV_SEC_POWER_CONFLICT;
		goto ERR_RET;
	}

	mem_map_info.result = hisp_mem_map_addr_cann(mem_type, &map_info, &mem_info);
	if (mem_map_info.result != 0) {
		pr_err("[%s] Failed : hisp_mem_map_addr. ret 0x%x\n", __func__, mem_map_info.result);
	}

ERR_RET:
	mutex_unlock(&dev->hisp_mutex);

	mem_map_info.isp_core_iova = mem_info.isp_core_iova;
	mem_map_info.mapped_addr = mem_info.cpu_addr;
	mem_map_info.mapped_size = mem_info.cpu_size;
	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&mem_map_info, sizeof(mem_map_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	return mem_map_info.result;
}

static int hisp_intf_mem_unmap(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	hisp_mem_unmap_t unmap_info = {0};
	struct hisp_mem_type mem_type = {0};
	struct hisp_mem_info_s mem_info = {0};
	unsigned long ret1;

	ret1 = copy_from_user(&unmap_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(unmap_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	mem_type.master = unmap_info.master_type;
	mem_type.mem_type = unmap_info.mem_type;

	mem_info.cpu_addr = unmap_info.unmap_addr;
	mem_info.cpu_size = unmap_info.unmap_size;
	mem_info.isp_core_iova = unmap_info.isp_core_iova;

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_err("[%s] Failed : isp device state %d error\n", __func__, dev->isp_dev_fsm);
		unmap_info.result = -1;
		goto ERR_RET;
	}

	if (!hisp_check_isp_power_sate(CANN_OP)) {
		pr_info("[%s]:sec isp conflict\n", __func__);
		unmap_info.result = ISP_DEV_SEC_POWER_CONFLICT;
		goto ERR_RET;
	}

	unmap_info.result = hisp_mem_unmap_addr_cann(mem_type, mem_info);
	if (unmap_info.result != 0) {
		pr_err("[%s] Failed : hisp_mem_unmap_addr. ret 0x%x\n", __func__, unmap_info.result);
	}

ERR_RET:
	mutex_unlock(&dev->hisp_mutex);

	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&unmap_info, sizeof(unmap_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	return unmap_info.result;
}

static int hisp_intf_rpmsg_send(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	isp_msg_t msg_info = {0};
	struct isp_msg_content msg_data = {};
	unsigned long ret1;

	ret1 = copy_from_user(&msg_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(msg_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	if ((msg_info.size > sizeof(struct isp_msg_content)) || (msg_info.size <= sizeof(struct hisp_msg_info))) {
		pr_err("[%s] Failed : msg size error %u\n", __func__, msg_info.size);
		return -EFAULT;
	}

	ret1 = copy_from_user(&msg_data, (void __user *)msg_info.data, msg_info.size);
	if (ret1 != 0) {
		pr_err("%s: copy msg from user fail, len:%u",
			__func__, msg_info.size);
		return -EFAULT;
	}

	pr_debug("[%s] api_name 0x%x message_id 0x%x\n", __func__, msg_data.info.api_name, msg_data.info.message_id);

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_err("[%s] Failed : isp device state %d error\n", __func__, dev->isp_dev_fsm);
		msg_info.result = -1;
		goto ERR_RET;
	}

	if (!hisp_check_isp_power_sate(CANN_OP)) {
		pr_info("[%s]:sec isp conflict\n", __func__);
		msg_info.result = ISP_DEV_SEC_POWER_CONFLICT;
		goto ERR_RET;
	}

	msg_info.result = hisp_rpmsg_send_cann((void *)&msg_data, msg_info.size);
	if (msg_info.result != 0) {
		pr_err("[%s] Failed : hisp_rpmsg_send. ret 0x%x\n", __func__, msg_info.result);
	}

ERR_RET:
	mutex_unlock(&dev->hisp_mutex);

	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&msg_info, sizeof(msg_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	return msg_info.result;
}

static int hisp_intf_rpmsg_receive(unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;
	unsigned int timeout = 1;
	unsigned int wait_time = 0;
	int ret = 0;
	isp_msg_t msg_info = {0};
	unsigned long ret1;

	ret1 = copy_from_user(&msg_info, (void __user *)(uintptr_t)args, (unsigned long)sizeof(msg_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_from_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	if ((msg_info.data == NULL) || (msg_info.size < sizeof(struct isp_msg_content))) {
		pr_err("[%s] Failed : msg_info.data is NULL %d or size %u error\n",
			__func__, (msg_info.data == NULL), msg_info.size);
		return -EFAULT;
	}

	msg_info.result = -1;

	while (hisp_intf_rpmsg_queue_is_empty()) {
		ret = (int)wait_for_completion_timeout(&dev->rpmsg_queue_comp,
			msecs_to_jiffies(timeout));
		if ((ret != 0) && (dev->msg_read_idx != dev->msg_write_idx)) {
			break;
		}

		if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
			pr_info("[%s]:isp power down\n", __func__);
			goto ERR_OUT;
		}

		wait_time++;
		if (wait_time >= ISP_RPMSG_RECV_TIMEOUT_TIME) {
			pr_info("[%s]:recv rpmsg timeout\n", __func__);
			msg_info.result = ISP_DEV_TIMEOUT;
			goto ERR_OUT;
		}
	}

	mutex_lock(&dev->hisp_mutex);

	if (dev->isp_dev_fsm != ISP_DEV_POWER_UP) {
		pr_info("[%s]:isp power down\n", __func__);
		goto ERR_UNLOCK1;
	}

	if (!hisp_check_isp_power_sate(CANN_OP)) {
		pr_info("[%s]:sec isp conflict\n", __func__);
		msg_info.result = ISP_DEV_SEC_POWER_CONFLICT;
		goto ERR_UNLOCK1;
	}

	mutex_lock(&dev->msg_queue_mutex);
	if (hisp_intf_rpmsg_queue_is_empty()) {
		pr_info("[%s]:rpmsg queue is empty\n", __func__);
		goto ERR_UNLOCK2;
	}

	ret1 = copy_to_user((void __user *)(uintptr_t)msg_info.data,
		(const void *)&dev->isp2user_msgs[dev->msg_read_idx], sizeof(struct isp_msg_content));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		goto ERR_UNLOCK2;
	}

	msg_info.result = 0;

	dev->msg_read_idx = hisp_intf_rpmsg_queue_get_next_index(dev->msg_read_idx);

ERR_UNLOCK2:
	mutex_unlock(&dev->msg_queue_mutex);

ERR_UNLOCK1:
	mutex_unlock(&dev->hisp_mutex);

ERR_OUT:
	ret1 = copy_to_user((void __user *)(uintptr_t)args, (const void *)&msg_info, sizeof(msg_info));
	if (ret1 != 0) {
		pr_err("[%s] Failed : copy_to_user. ret 0x%llx\n", __func__, ret1);
		return -EFAULT;
	}

	return msg_info.result;
}

#ifndef DEBUG_HISP
static bool hisp_is_valid_cann(pid_t pid)
{
	int i;
	struct hisp_device_s *dev = &hisp_dev;
	for (i = 0; i < MAX_HISP_CANN; ++i) {
		if (dev->process_tgid[i] == pid) {
			return true;
        }
	}
	pr_info("%s: invalid process: tgid=%d\n", __func__, pid);
	return false;
}

static int hisp_allocate_cann_id(pid_t pid)
{
	struct hisp_device_s *dev = &hisp_dev;
    int cid;
    int ret = -EBUSY;

    for (cid = 0; cid < MAX_HISP_CANN; ++cid) {
        if (dev->process_tgid[cid] == pid) {
            ret = 0;
			return ret;
        }
	}

    for (cid = 0; cid < MAX_HISP_CANN; ++cid) {
        if (dev->process_tgid[cid] == 0) {
            dev->process_tgid[cid] = pid;
            ret = 0;
			return ret;
        }
	}
	return ret;
}
#endif

static int hisp_open(struct inode *inode, struct file *filp)
{
	struct hisp_device_s *dev = &hisp_dev;

	(void)inode;
	(void)filp;

	pr_info("[%s] +\n", __func__);

	if (dev->isp_dev_fsm != ISP_DEV_INITIAL) {
		pr_err("[%s] Failed : hisp device not ready\n", __func__);
		return -ENXIO;
	}

	mutex_lock(&dev->hisp_mutex);

#ifndef DEBUG_HISP
	if (current->tgid == 0) {
		pr_err("%s: Failed: invalid parameter\n", __func__);
		mutex_unlock(&dev->hisp_mutex);
        return -EINVAL;
	}

	int ret = hisp_allocate_cann_id(current->tgid);
	if(ret != 0) {
		pr_err("%s: Failed: invalid process tgid: %d\n", __func__, current->tgid);
		mutex_unlock(&dev->hisp_mutex);
		return -EINVAL;
	}
	pr_info("%s: valid process tgid=%d\n", __func__, current->tgid);
#endif

	if (atomic_read(&dev->open_cnt) != 0) {
		pr_err("%s: Failed: has been opened\n", __func__);
		mutex_unlock(&dev->hisp_mutex);
		return -EBUSY;
	}

	atomic_inc(&dev->open_cnt);

	dev->isp_dev_fsm = ISP_DEV_OPEN;

	mutex_unlock(&dev->hisp_mutex);

	pr_info("[%s] -\n", __func__);

	return 0;
}

static int hisp_release(struct inode *inode, struct file *filp)
{
	struct hisp_device_s *dev = &hisp_dev;

	(void)inode;
	(void)filp;

	pr_info("[%s] +\n", __func__);

	if ((dev->isp_dev_fsm != ISP_DEV_OPEN) &&
		(dev->isp_dev_fsm != ISP_DEV_POWER_UP)) {
		pr_err("[%s] Failed : hisp device not ready\n", __func__);
		return -ENXIO;
	}

	mutex_lock(&dev->hisp_mutex);

	if (atomic_read(&dev->open_cnt) <= 0) {
		pr_err("%s: Failed: hisp device has been closed\n", __func__);
		mutex_unlock(&dev->hisp_mutex);
		return -EBUSY;
	}

	if (dev->isp2user_msgs != NULL) {
		mutex_lock(&dev->msg_queue_mutex);
		vfree(dev->isp2user_msgs);
		dev->isp2user_msgs = NULL;
		mutex_unlock(&dev->msg_queue_mutex);
	}

	if (dev->isp_dev_fsm == ISP_DEV_POWER_UP) {
		(void)hisp_power_down_cann();
	}

	dev->isp_dev_fsm = ISP_DEV_INITIAL;

	atomic_dec(&dev->open_cnt);
#ifndef DEBUG_HISP
    for (int i = 0; i < MAX_HISP_CANN; ++i) {
        dev->process_tgid[i] = 0;
    }
#endif

	mutex_unlock(&dev->hisp_mutex);

	pr_info("[%s] -\n", __func__);

	return 0;
}

static int hisp_ioctl_check(unsigned int cmd, unsigned long args)
{
	struct hisp_device_s *dev = &hisp_dev;

	if ((dev->isp_dev_fsm != ISP_DEV_OPEN) &&
		(dev->isp_dev_fsm != ISP_DEV_POWER_UP)) {
		pr_err("[%s] Failed : hisp device not ready\n", __func__);
		return -ENXIO;
	}

	if (args == 0) {
		pr_err("[%s] cmd[0x%x] args NULL", __func__, cmd);
		return -EFAULT;
	}
#ifndef DEBUG_HISP
	if (current->tgid == 0) {
		pr_err("%s: Failed: invalid tgid \n", __func__);
        return -EINVAL;
	}
	bool ret = hisp_is_valid_cann(current->tgid);
    if (!ret) {
        pr_err("%s: invalid process: tgid=%d\n", __func__, current->tgid);
		return -EINVAL;
	}
#endif
	return 0;
}

static long hisp_ioctl(struct file *filp, unsigned int cmd,
		unsigned long args)
{
	int ret;

	(void)filp;

	pr_info("[%s] cmd.0x%x +\n", __func__, cmd);

	ret = hisp_ioctl_check(cmd, args);
	if (ret < 0) {
		pr_err("[%s] failed: hisp_ioctl_check.%d", __func__, ret);
		return ret;
	}

	switch (cmd) {
	case HISP_IOCTL_POWER_UP:
		ret = hisp_intf_power_up(args);
		break;
	case HISP_IOCTL_POWER_DOWN:
		ret = hisp_intf_power_down(args);;
		break;
	case HISP_IOCTL_SET_CLK_RATE:
		ret = hisp_intf_set_clk_rate(args);
		break;
	case HISP_IOCTL_MEM_MAP:
		ret = hisp_intf_mem_map(args);
		break;
	case HISP_IOCTL_MEM_UNMAP:
		ret = hisp_intf_mem_unmap(args);
		break;
	case HISP_IOCTL_RPMSG_SEND:
		ret = hisp_intf_rpmsg_send(args);
		break;
	case HISP_IOCTL_RPMSG_RECV:
		ret = hisp_intf_rpmsg_receive(args);
		break;
	default:
		pr_err("[%s] don't support cmd 0x%X.\n", __func__, cmd);
		ret = -EFAULT;
		break;
	};

	pr_info("[%s] -\n", __func__);

	return ret;
}

static const struct file_operations hisp_ops = {
	.open           = hisp_open,
	.release        = hisp_release,
	.unlocked_ioctl = hisp_ioctl,
	.owner          = THIS_MODULE,
};

static struct miscdevice hisp_miscdev = {
	.minor  = 255,
	.name   = "hisp",
	.fops   = &hisp_ops,
	.mode   = 0440,
};

static int __init hisp_init(void)
{
	struct hisp_device_s *dev = &hisp_dev;
	int ret = 0;

	pr_info("[%s] +\n", __func__);

	dev->isp2user_msgs = NULL;
	dev->msg_read_idx = 0;
	dev->msg_write_idx = 0;

	mutex_init(&dev->hisp_mutex);
	mutex_init(&dev->msg_queue_mutex);
	init_completion(&dev->rpmsg_queue_comp);

	ret = misc_register(&hisp_miscdev);
	if (ret != 0) {
		pr_err("[%s] Failed : misc_register.%d\n", __func__, ret);
		return ret;
	}

	dev->isp_dev_fsm = ISP_DEV_INITIAL;

	pr_info("[%s] -\n", __func__);

	return 0;
}

static void __exit hisp_exit(void)
{
	struct hisp_device_s *dev = &hisp_dev;

	pr_info("[%s] +\n", __func__);
	dev->isp_dev_fsm = ISP_DEV_UNINITIAL;
	misc_deregister(&hisp_miscdev);
	mutex_destroy(&dev->hisp_mutex);
	mutex_destroy(&dev->msg_queue_mutex);
	pr_info("[%s] -\n", __func__);
}

module_init(hisp_init);
module_exit(hisp_exit);

MODULE_DESCRIPTION("HISI ISP device node");
MODULE_LICENSE("GPL v2");
