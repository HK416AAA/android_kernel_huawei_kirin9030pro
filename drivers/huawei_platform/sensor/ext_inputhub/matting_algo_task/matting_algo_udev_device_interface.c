/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * All rights reserved.
 * Description: Creating File Nodes and Interfaces in udev
 * Author: yangxiaopeng@huawei.com
 * Create: 2024-9-9
 */
#include "matting_algo_udev_device_interface.h"
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/device.h>
#include <huawei_platform/log/hw_log.h>
#include "image_compositing_algo.h"
#include "securec.h"
#include "matting_algo_task.h"
#include "als_matting_algo_info.h"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG matting_algo_task
HWLOG_REGIST();

#ifndef MATTING_ALGO_MAX_BUF_LENGTH
#define MATTING_ALGO_MAX_BUF_LENGTH (512)
#endif

#ifndef MATTING_ALGO_BUF_LENGTH_TWO_BYTES
#define MATTING_ALGO_BUF_LENGTH_TWO_BYTES (2)
#endif

// matting_algo_als_param: Sensor Hal -> Matting Algo
static const struct file_operations matting_algo_als_param_ops = {
	.owner = THIS_MODULE,
	.read = matting_algo_als_param_read,
	.write = matting_algo_als_param_write,
};

static struct miscdevice matting_algo_als_param_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "matting_algo_als_param",
	.fops = &matting_algo_als_param_ops,
};

// matting_algo_lux_value: Matting Algo -> Sensor Hal
static const struct file_operations matting_algo_lux_value_ops = {
	.owner = THIS_MODULE,
	.read = matting_algo_lux_value_read,
	.write = matting_algo_lux_value_write,
};

static struct miscdevice matting_algo_lux_value_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "matting_algo_lux_value",
	.fops = &matting_algo_lux_value_ops,
};

// log_check_control: Kernel <-> user
static const struct file_operations matting_algo_log_check_control_ops = {
	.owner = THIS_MODULE,
	.read = matting_algo_log_check_control_read,
	.write = matting_algo_log_check_control_write,
};

static struct miscdevice matting_algo_log_check_control_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "matting_algo_log_check_control",
	.fops = &matting_algo_log_check_control_ops,
};

// crop_check_control: Kernel <-> user
static const struct file_operations matting_algo_crop_check_control_ops = {
	.owner = THIS_MODULE,
	.read = matting_algo_crop_check_control_read,
	.write = matting_algo_crop_check_control_write,
};

static struct miscdevice matting_algo_crop_check_control_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "matting_algo_crop_check_control",
	.fops = &matting_algo_crop_check_control_ops,
};

void matting_algo_udev_device_init(void)
{
    if (misc_register(&matting_algo_als_param_miscdev) != 0) {
        hwlog_err("[%s] cannot register miscdev matting_algo_als_param\n", __func__);
		return;
	}

	if (misc_register(&matting_algo_lux_value_miscdev) != 0) {
        hwlog_err("[%s] cannot register miscdev matting_algo_lux_value\n", __func__);
		return;
	}

	if (misc_register(&matting_algo_log_check_control_miscdev) != 0) {
        hwlog_err("[%s] cannot register miscdev log_check_control\n", __func__);
		return;
	}

	if (misc_register(&matting_algo_crop_check_control_miscdev) != 0) {
        hwlog_err("[%s] cannot register miscdev crop_check_control\n", __func__);
		return;
	}
}

ssize_t matting_algo_als_param_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
	char char_str[MATTING_ALGO_MAX_BUF_LENGTH] = {0};
	uint32_t len = 0;
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
    int32_t ret =  EC_SUCCESS;

	if (!buf) {
		hwlog_err("[%s] buf is NULL\n", __func__);
		return EC_FAILURE;
	}

	ret = snprintf_s(char_str, sizeof(char_str), sizeof(char_str) - 1,
		"alsLux: %d, alsChannel: %d %d %d %d %d, alsAgain: %d %d %d %d %d, alsAtime: %d",
		kernel_user_param_ptr->als_data_st.als_lux,
		kernel_user_param_ptr->als_data_st.als_channel[INDEX_ZERO],
		kernel_user_param_ptr->als_data_st.als_channel[INDEX_ONE],
		kernel_user_param_ptr->als_data_st.als_channel[INDEX_TWO],
		kernel_user_param_ptr->als_data_st.als_channel[INDEX_THREE],
		kernel_user_param_ptr->als_data_st.als_channel[INDEX_FOUR],
		kernel_user_param_ptr->als_data_st.als_again[INDEX_ZERO],
		kernel_user_param_ptr->als_data_st.als_again[INDEX_ONE],
		kernel_user_param_ptr->als_data_st.als_again[INDEX_TWO],
		kernel_user_param_ptr->als_data_st.als_again[INDEX_THREE],
		kernel_user_param_ptr->als_data_st.als_again[INDEX_FOUR],
		kernel_user_param_ptr->als_data_st.als_atime);

	if (ret < 0) {
		hwlog_err("[%s] format error, ret=%d\n", __func__, ret);
		return EC_FAILURE;
	}

	len = strlen(char_str);
	ret = copy_to_user(buf, char_str, len);
	if (ret != 0) {
		hwlog_err("[%s] copy to user buffer failed\n", __func__);
		return ret;
	}

	return count;
}

ssize_t matting_algo_als_param_write(struct file *file, const char __user *data, size_t len, loff_t *ppos)
{
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
	int32_t ret = EC_SUCCESS;
    char buf[MATTING_ALGO_MAX_BUF_LENGTH] = {0};

	if (len != sizeof(struct sensor_hub_als_data_st)) {
		hwlog_err("[%s] len=%d, but expectations size=%d\n", __func__, len, sizeof(struct sensor_hub_als_data_st));
		return EC_FAILURE;
	}

	if (copy_from_user(buf, data, len)) {
        hwlog_err("[%s] copy_from_user error.\n", __func__);
		return EC_FAILURE;
    }

	kernel_user_param_ptr->als_data_st = *(struct sensor_hub_als_data_st *)buf;

	up(matting_algo_get_semaphore_als_report());

	return EC_SUCCESS;
}

void matting_algo_set_lux_value(uint32_t lux_value)
{
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();

	mutex_lock(&matting_algo_get_lock_st()->matting_algo_lux_value_lock);
	kernel_user_param_ptr->lux_value = lux_value;
	mutex_unlock(&matting_algo_get_lock_st()->matting_algo_lux_value_lock);
}

ssize_t matting_algo_lux_value_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
	char char_str[MATTING_ALGO_MAX_BUF_LENGTH] = {0};
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
    int32_t ret =  EC_SUCCESS;
    uint32_t len = 0;

	if (!buf) {
		hwlog_err("[%s] buf is NULL\n", __func__);
		return EC_FAILURE;
	}

	ret = snprintf_s(char_str, sizeof(char_str), sizeof(char_str) - 1, "%u",
		kernel_user_param_ptr->lux_value);
	if (ret < 0) {
		hwlog_err("[%s] format error, ret=%d\n", __func__, ret);
		return EC_FAILURE;
	}

	len = strlen(char_str);
	ret = copy_to_user(buf, char_str, len);
	if (ret != 0) {
		hwlog_err("[%s] copy to user buffer failed\n", __func__);
		return ret;
	}

	// after read, change matting_algo_lux_value to invalid
	matting_algo_set_lux_value(UINT_MAX);

	return count;
}

ssize_t matting_algo_lux_value_write(struct file *file, const char __user *data, size_t len, loff_t *ppos)
{
	int32_t ret = EC_SUCCESS;
    char buf[MATTING_ALGO_MAX_BUF_LENGTH] = {0};
	uint32_t lux_value;

	if (len >= MATTING_ALGO_MAX_BUF_LENGTH) {
		hwlog_err("[%s] buf overflow!\n", __func__);
		return EC_FAILURE;
	}

	if (copy_from_user(buf, data, len)) {
        hwlog_err("[%s] copy_from_user error.\n", __func__);
		return EC_FAILURE;
    }

	ret = sscanf_s(buf, "%u", &lux_value);
	if (ret != MATTING_ALGO_PARAM_ONE) {
		hwlog_err("[%s] sscanf return invalid:%d\n", __func__, ret);
		return EC_FAILURE;
	}

	matting_algo_set_lux_value(lux_value);

	return ret;
}

ssize_t matting_algo_log_check_control_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
	char char_str[MATTING_ALGO_MAX_BUF_LENGTH] = {0};
	uint32_t len = 0;
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
    int32_t ret =  EC_SUCCESS;

	if (!buf) {
		hwlog_err("[%s] buf is NULL\n", __func__);
		return EC_FAILURE;
	}

	ret = snprintf_s(char_str, sizeof(char_str), sizeof(char_str) - 1, "%s",
		kernel_user_param_ptr->log_check_control == 0 ? "0: disable" : "1: enable");
	if (ret < 0) {
		hwlog_err("[%s] format error, ret=%d\n", __func__, ret);
		return EC_FAILURE;
	}

	len = strlen(char_str);
	ret = copy_to_user(buf, char_str, len);
	if (ret != 0) {
		hwlog_err("[%s] copy to user buffer failed\n", __func__);
		return ret;
	}

	return count;
}

ssize_t matting_algo_log_check_control_write(struct file *file, const char __user *data, size_t len, loff_t *ppos)
{
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
	int32_t ret = EC_SUCCESS;
    char buf[MATTING_ALGO_BUF_LENGTH_TWO_BYTES] = {0};
	uint32_t log_check_control = 0;

	if (len >= MATTING_ALGO_BUF_LENGTH_TWO_BYTES) {
		hwlog_err("[%s] buf overflow!\n", __func__);
		return EC_FAILURE;
	}

	if (copy_from_user(buf, data, len)) {
        hwlog_err("[%s] copy_from_user error.\n", __func__);
		return EC_FAILURE;
    }

	ret = sscanf_s(buf, "%u", &log_check_control);
	if (ret != MATTING_ALGO_PARAM_ONE) {
		hwlog_err("[%s] sscanf return invalid:%d\n", __func__, ret);
		return EC_FAILURE;
	}

	kernel_user_param_ptr->log_check_control = log_check_control == MATTING_ALGO_PARAM_CHECK_CONTROL_DISABLE ? \
		MATTING_ALGO_PARAM_CHECK_CONTROL_DISABLE : MATTING_ALGO_PARAM_CHECK_CONTROL_ENABLE;

	return EC_SUCCESS;
}

ssize_t matting_algo_crop_check_control_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
	char char_str[MATTING_ALGO_MAX_BUF_LENGTH] = {0};
	uint32_t len = 0;
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
    int32_t ret =  EC_SUCCESS;

	if (!buf) {
		hwlog_err("[%s] buf is NULL\n", __func__);
		return EC_FAILURE;
	}

	ret = snprintf_s(char_str, sizeof(char_str), sizeof(char_str) - 1, "%s",
		kernel_user_param_ptr->crop_check_control == 0 ? "0: disable" : "1: enable");
	if (ret < 0) {
		hwlog_err("[%s] format error, ret=%d\n", __func__, ret);
		return EC_FAILURE;
	}

	len = strlen(char_str);
	ret = copy_to_user(buf, char_str, len);
	if (ret != 0) {
		hwlog_err("[%s] copy to user buffer failed\n", __func__);
		return ret;
	}

	return count;
}

ssize_t matting_algo_crop_check_control_write(struct file *file, const char __user *data, size_t len, loff_t *ppos)
{
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct matting_algo_kernel_user_param_st *kernel_user_param_ptr = matting_algo_get_kernel_user_param();
	int32_t ret = EC_SUCCESS;
    char buf[MATTING_ALGO_BUF_LENGTH_TWO_BYTES] = {0};
	uint32_t crop_check_control = 0;

	if (len >= MATTING_ALGO_BUF_LENGTH_TWO_BYTES) {
		hwlog_err("[%s] buf overflow!\n", __func__);
		return EC_FAILURE;
	}

	if (copy_from_user(buf, data, len)) {
        hwlog_err("[%s] copy_from_user error.\n", __func__);
		return EC_FAILURE;
    }

	ret = sscanf_s(buf, "%u", &crop_check_control);
	if (ret != MATTING_ALGO_PARAM_ONE) {
		hwlog_err("[%s] sscanf return invalid:%d\n", __func__, ret);
		return EC_FAILURE;
	}

	kernel_user_param_ptr->crop_check_control = crop_check_control == MATTING_ALGO_PARAM_CHECK_CONTROL_DISABLE ? \
		MATTING_ALGO_PARAM_CHECK_CONTROL_DISABLE : MATTING_ALGO_PARAM_CHECK_CONTROL_ENABLE;

	return EC_SUCCESS;
}
