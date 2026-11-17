/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/mutex.h>
#include <linux/atomic.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/miscdevice.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/time.h>
#include <linux/of_gpio.h>
#include <linux/kobject.h>
#include <linux/kthread.h>
#include <linux/types.h>
#include <linux/err.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_device.h>
#include <linux/regulator/consumer.h>
#include <linux/pm_wakeup.h>
#include <securec.h>
#include <platform_include/camera/native/laser_cfg.h>

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <huawei_platform/devdetect/hw_dev_dec.h>
#endif

#include "vi5302.h"
#include "vi5302_platform.h"
#include "vi5302_firmware.h"
#include "vi5302_api.h"

#define VI5302_IOCTL_PERIOD _IOW('p', 0x01, uint32_t)
#define VI5302_IOCTL_XTALK_CALIB _IOR('p', 0x02, struct vi5302_xtalk_calib_data)
#define VI5302_IOCTL_XTALK_CONFIG _IOW('p', 0x03, struct vi5302_xtalk_calib_data)
#define VI5302_IOCTL_OFFSET_CALIB _IOR('p', 0x04, struct vi5302_offset_calib_data)
#define VI5302_IOCTL_OFFSET_CONFIG _IOW('p', 0x05, int16_t)
#define VI5302_IOCTL_POWER_ON _IO('p', 0x06)
#define VI5302_IOCTL_CHIP_INIT _IO('p', 0x07)
#define VI5302_IOCTL_START _IO('p', 0x08)
#define VI5302_IOCTL_STOP _IO('p', 0x09)
#define VI5302_IOCTL_MZ_DATA _IOR('p', 0x0a, struct vi5302_measurement_data)
#define VI5302_IOCTL_POWER_OFF _IO('p', 0x0b)

#define VI5302_LOAD_CURRENT 18000
#define VI5302_DRV_NAME "vi5302"
static int xtalk_mark;
static int offset_mark;

struct vi5302_api_fn_t {
	int32_t (*power_on)(vi5302_dev dev);
	int32_t (*power_off)(vi5302_dev dev);
	void (*chip_register_init)(vi5302_dev dev);
	void (*set_fps)(vi5302_dev dev, uint32_t period);
	int32_t (*single_measure)(vi5302_dev dev);
	int32_t (*start_continuous_measure)(vi5302_dev dev);
	int32_t (*stop_continuous_measure)(vi5302_dev dev);
	int32_t (*get_measure_data)(vi5302_dev dev);
	int32_t (*get_interrupt_state)(vi5302_dev dev, uint8_t *stat);
	int32_t (*chip_init)(vi5302_dev dev);
	int32_t (*start_xtalk_calibration)(vi5302_dev dev);
	int32_t (*start_offset_calibration)(vi5302_dev dev, uint32_t param);
	int32_t (*get_xtalk_parameter)(vi5302_dev dev);
	int32_t (*config_xtalk_parameter)(vi5302_dev dev);
};
static struct vi5302_api_fn_t vi5302_api_func_tbl = {
	.power_on = vi5302_chip_poweron,
	.power_off = vi5302_chip_poweroff,
	.set_fps = vi5302_set_fps,
	.single_measure = vi5302_single_measure,
	.start_continuous_measure = vi5302_start_continuous_measure,
	.stop_continuous_measure = vi5302_stop_continuous_measure,
	.get_measure_data = vi5302_get_measure_data,
	.get_interrupt_state = vi5302_get_interrupt_state,
	.chip_init = vi5302_chip_init,
	.start_xtalk_calibration = vi5302_start_xtalk_calibration,
	.start_offset_calibration = vi5302_start_offset_calibration,
	.get_xtalk_parameter = vi5302_get_xtalk_parameter,
	.config_xtalk_parameter = vi5302_config_xtalk_parameter,
};
struct vi5302_api_fn_t *vi5302_func_tbl;

static void vi5302_setupAPIFunctions(void)
{
	vi5302_func_tbl->power_on = vi5302_chip_poweron;
	vi5302_func_tbl->power_off = vi5302_chip_poweroff;
	vi5302_func_tbl->set_fps = vi5302_set_fps;
	vi5302_func_tbl->single_measure = vi5302_single_measure;
	vi5302_func_tbl->start_continuous_measure = vi5302_start_continuous_measure;
	vi5302_func_tbl->stop_continuous_measure = vi5302_stop_continuous_measure;
	vi5302_func_tbl->get_measure_data = vi5302_get_measure_data;
	vi5302_func_tbl->chip_init = vi5302_chip_init;
	vi5302_func_tbl->start_xtalk_calibration = vi5302_start_xtalk_calibration;
	vi5302_func_tbl->start_offset_calibration = vi5302_start_offset_calibration;
	vi5302_func_tbl->get_xtalk_parameter = vi5302_get_xtalk_parameter;
	vi5302_func_tbl->config_xtalk_parameter = vi5302_config_xtalk_parameter;
}

static void vi5302_enable_irq(struct vi5302_data *data)
{
	if (!data)
		return;

	if (data->intr_state == VI5302_INTR_DISABLED) {
		vi5302_infomsg();
		data->intr_state = VI5302_INTR_ENABLED;
		enable_irq(data->irq);
	}
}

static void vi5302_disable_irq(struct vi5302_data *data)
{
	if (!data)
		return;

	if (data->intr_state == VI5302_INTR_ENABLED) {
		vi5302_infomsg();
		data->intr_state = VI5302_INTR_DISABLED;
		disable_irq(data->irq);
	}
}

#ifdef CONFIG_SYSFS
static ssize_t vi5302_chip_enable_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL)
		return scnprintf(buf, PAGE_SIZE, "%u\n", data->chip_enable);

	return -EINVAL;
}

static ssize_t vi5302_chip_enable_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	vi5302_error status = VI5302_ERROR_NONE;
	unsigned int val = 0;

	if (data != NULL) {
		if (sscanf(buf, "%u\n", &val) != 1)
			return -1;
		if (val != 0 && val != 1) {
			vi5302_errmsg("enable store unvalid value = %u\n", val);
			return count;
		}
		if (val == 1) {
			if (data->chip_enable == 0) {
				data->chip_enable = 1;
				vi5302_enable_irq(data);
				status = vi5302_func_tbl->power_on(data);
				ktime_get_real_ts64(&data->start_ts);
			} else {
				vi5302_errmsg("already enabled!!\n");
			}
		} else {
			if (data->chip_enable == 1) {
				data->chip_enable = 0;
				vi5302_disable_irq(data);
				data->fwdl_status = 0;
				status = vi5302_func_tbl->power_off(data);
			} else {
				vi5302_errmsg("already disabled!!\n");
			}
		}
		return status ? -1 : count;
	}
	vi5302_errmsg("data is NULL\n");
	return -EPERM; 
}

static DEVICE_ATTR(chip_enable, 0664, vi5302_chip_enable_show, vi5302_chip_enable_store);

/* for debug */
static ssize_t vi5302_enable_debug_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL)
		return snprintf(buf, PAGE_SIZE, "%u\n", data->enable_debug);

	return -EINVAL;
}

static ssize_t vi5302_enable_debug_store(struct device *dev,
					struct device_attribute *attr, const
					char *buf, size_t count)
{
	unsigned int on = 0;
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL) {
		if (sscanf(buf, "%u\n", &on) != 1) {
			return -1;
		}
		if ((on != 0) && (on != 1)) {
			vi5302_errmsg("set debug = %d\n", on);
			return count;
		}
		data->enable_debug = on;
		vi5302_infomsg("enable_debug: %u\n", data->enable_debug);
		return count;
	}

	return -EINVAL;
}

static DEVICE_ATTR(enable_debug, 0664, vi5302_enable_debug_show, vi5302_enable_debug_store);

static ssize_t vi5302_chip_init_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct vi5302_data *data = NULL;
	vi5302_error status = VI5302_ERROR_NONE;
	unsigned int val = 0;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL) {
		if (sscanf(buf, "%u\n", &val) != 1)
			return -1;
		
		if (val) {
			status = vi5302_func_tbl->chip_init(data);
			data->fwdl_status = 1;
		} else {
			return -EINVAL;
		}
		return status ? -1 : count;
	}

	return -EPERM;
}

static DEVICE_ATTR(chip_init, 0664, NULL, vi5302_chip_init_store);

static ssize_t vi5302_period_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL)
		return scnprintf(buf, PAGE_SIZE, "%u\n", data->fps);

	return -EINVAL;
}

static ssize_t vi5302_period_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	uint32_t val = 0;
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL) {
		if (sscanf(buf, "%u\n", &val) != 1)
			return -EINVAL;

		data->fps = val;
		vi5302_func_tbl->set_fps(data, data->fps);
		return count;
	}

	return -EPERM;
}

static DEVICE_ATTR(period, 0664, vi5302_period_show, vi5302_period_store);

static ssize_t vi5302_capture_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	vi5302_error status = VI5302_ERROR_NONE;
	unsigned int val = 0;
	struct vi5302_data *data = NULL;
	if (!dev || !attr || !buf) {
		vi5302_errmsg("input NULL\n");
		return -EINVAL;
	}

	data = dev_get_drvdata(dev);
	if (data != NULL) {
		if (sscanf(buf, "%u\n", &val) != 1)
			return -1;
		if (val != 0 && val != 1) {
			vi5302_errmsg("capture store unvalid value = %u\n", val);
			return count;
		}
		if (val == 1) {
			vi5302_enable_irq(data);
			status = vi5302_func_tbl->start_continuous_measure(data);
		} else {
			vi5302_disable_irq(data);
			status = vi5302_func_tbl->stop_continuous_measure(data);
		}
		return status ? -1 : count;
	}

	return -EPERM; 
}

static DEVICE_ATTR(capture, 0220, NULL, vi5302_capture_store);

static ssize_t vi5302_xtalk_calib_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct vi5302_data *data = dev_get_drvdata(dev);

	if (data != NULL)
		return scnprintf(buf, PAGE_SIZE, "%d.%u\n", data->xtalk_data.xtalk_cal, data->xtalk_data.xtalk_peak);

	return -EPERM;
}

static ssize_t vi5302_xtalk_calib_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct vi5302_data *data = dev_get_drvdata(dev);
	vi5302_error status = VI5302_ERROR_NONE;
	unsigned int val = 0;

	if (NULL != data) {
		mutex_lock(&data->work_mutex);
		if (sscanf(buf, "%u\n", &val) != 1) {
			mutex_unlock(&data->work_mutex);
			return -1;
		}
		if (val != 1) {
			vi5302_errmsg("xtalk calibration store unvalid value=%u\n", val);
			mutex_unlock(&data->work_mutex);
			return count;
		}
		xtalk_mark = 1;
		vi5302_enable_irq(data);
		status = vi5302_func_tbl->start_xtalk_calibration(data);
		mdelay(600);
		vi5302_disable_irq(data);
		xtalk_mark = 0;
		mutex_unlock(&data->work_mutex);
		return status ? -1 : count;
	}

	return -EPERM; 
}

static DEVICE_ATTR(xtalk_calib, 0664, vi5302_xtalk_calib_show, vi5302_xtalk_calib_store);

static ssize_t vi5302_offset_calib_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct vi5302_data *data = dev_get_drvdata(dev);

	if (data != NULL)
		return scnprintf(buf, PAGE_SIZE, "%d\n", data->offset_data.offset_cal);

	return -EPERM;
}

static ssize_t vi5302_offset_calib_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct vi5302_data *data = dev_get_drvdata(dev);
	vi5302_error status = VI5302_ERROR_NONE;
	unsigned int val = 0;
	uint32_t param = 0;

	if (NULL != data) {
		mutex_lock(&data->work_mutex);
		if (sscanf(buf, "%u\n", &val) != 1) {
			mutex_unlock(&data->work_mutex);
			return -1;
		}
		if (val !=1) {
			vi5302_errmsg("offset calibration store unvalid value=%u\n", val);
			mutex_unlock(&data->work_mutex);
			return count;
		}
		offset_mark = 1;
		status = vi5302_func_tbl->start_offset_calibration(data, param);
		offset_mark = 0;
		mutex_unlock(&data->work_mutex);
		return status ? -1 : count;
	}

	return -EPERM; 
}

static DEVICE_ATTR(offset_calib, 0664, vi5302_offset_calib_show, vi5302_offset_calib_store);

static ssize_t vi5302_xtalk_config_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct vi5302_data *data = dev_get_drvdata(dev);
	vi5302_error status = VI5302_ERROR_NONE;
	int cal = 0, peak = 0;

	if (NULL != data) {
		mutex_lock(&data->work_mutex);
		if (sscanf(buf, "%d %d\n", &cal, &peak) != 2) {
			mutex_unlock(&data->work_mutex);
			return -1;
		}
		data->xtalk_config.xtalk_cal = cal;
		data->xtalk_config.xtalk_peak = peak;
		status = vi5302_func_tbl->config_xtalk_parameter(data);
		mutex_unlock(&data->work_mutex);
		return status ? -1 : count;
	}

	return -EPERM; 
}

static DEVICE_ATTR(xtalk_config, 0220, NULL, vi5302_xtalk_config_store);

static ssize_t vi5302_offset_config_store(struct device *dev,
				struct device_attribute *attr, const char *buf, size_t count)
{
	struct vi5302_data *data = dev_get_drvdata(dev);
	int val = 0;

	if (NULL != data) {
		mutex_lock(&data->work_mutex);
		if (sscanf(buf, "%d\n", &val) != 1) {
			mutex_unlock(&data->work_mutex);
			return -1;
		}
		data->offset_config = (int16_t)val;
		mutex_unlock(&data->work_mutex);
		return count;
	}

	return -EPERM; 
}

static DEVICE_ATTR(offset_config, 0220, NULL, vi5302_offset_config_store);

static int vi5302_get_calibration_data(struct vi5302_data *data, hwlaser_calibration_data_t *cal_data)
{
	int rc = 0;
	mutex_lock(&data->work_mutex);

	rc = memcpy_s(&(cal_data->u.dataL2.VI5300_XTALK_Calib_Data), sizeof(struct vi5302_xtalk_calib_data), &(data->xtalk_data), sizeof(struct vi5302_xtalk_calib_data));
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		return -EFAULT;
	}

	rc = memcpy_s(&(cal_data->u.dataL2.VI5300_OFFSET_Calib_Data), sizeof(struct vi5302_offset_calib_data), &(data->offset_data), sizeof(struct vi5302_offset_calib_data));
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		return -EFAULT;
	}

	vi5302_infomsg("kernel xtalk_cal(%d), kernel xtalk_peak(%u)",
		data->xtalk_data.xtalk_cal, data->xtalk_data.xtalk_peak);
	vi5302_infomsg("hal xtalk_cal(%d), hal xtalk_peak(%u), hal xtalk_tof(%d)",
		cal_data->u.dataL2.VI5300_XTALK_Calib_Data.xtalk_cal, cal_data->u.dataL2.VI5300_XTALK_Calib_Data.xtalk_peak,
		cal_data->u.dataL2.VI5300_XTALK_Calib_Data.xtalk_tof);
	vi5302_infomsg("kernel offset_cal(%d)", data->offset_data.offset_cal);
	vi5302_infomsg("hal offset_cal(%d)", cal_data->u.dataL2.VI5300_OFFSET_Calib_Data.offset_cal);

	mutex_unlock(&data->work_mutex);
	return rc;
}

static ssize_t vi5302_xtalk_data_read(struct file *filp,
	struct kobject *kobj, struct bin_attribute *attr,
	char *buf, loff_t off, size_t count)
{
	struct device *dev = container_of(kobj, struct device, kobj);
	struct vi5302_data *data = dev_get_drvdata(dev);
	void *src = (void *) &(data->xtalk_data);
	int rc = 0;

	mutex_lock(&data->work_mutex);
	if (!data->chip_enable) {
		vi5302_errmsg("can't set calib data while disable sensor\n");
		mutex_unlock(&data->work_mutex);
		return -EBUSY;
	}

	if (count > sizeof(struct vi5302_xtalk_calib_data))
		count = sizeof(struct vi5302_xtalk_calib_data);

	rc = memcpy_s(buf, sizeof(struct vi5302_xtalk_calib_data), src, count);
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		vi5302_errmsg("memcpy_s fail %d", rc);
		return rc;
	}
	data->xtalk_config = data->xtalk_data;
	rc = vi5302_func_tbl->config_xtalk_parameter(data);
	if (rc) {
		vi5302_errmsg("config xtalk calibration data fail %d", rc);
		mutex_unlock(&data->work_mutex);
		return rc;
	}
	mutex_unlock(&data->work_mutex);

	return count;
}

static ssize_t vi5302_xtalk_data_write(struct file *filp,
	struct kobject *kobj, struct bin_attribute *attr,
	char *buf, loff_t off, size_t count)
{
	struct device *dev = container_of(kobj, struct device, kobj);
	struct vi5302_data *data = dev_get_drvdata(dev);
	struct vi5302_xtalk_calib_data *xtalk_data = 
				(struct vi5302_xtalk_calib_data *)buf;
	int rc = 0;

	mutex_lock(&data->work_mutex);

	if (!data->chip_enable) {
		rc = -EBUSY;
		vi5302_errmsg("can't set calib data while disable sensor\n");
		goto error;
	}

	if (count != sizeof(struct vi5302_xtalk_calib_data))
		goto invalid;

	if (data->enable_debug)
		vi5302_errmsg("xtalk config: %d, xtalk_peak: %d\n", xtalk_data->xtalk_cal, xtalk_data->xtalk_peak);

	data->xtalk_config = *xtalk_data;
	rc = vi5302_func_tbl->config_xtalk_parameter(data);
	if (rc) {
		vi5302_errmsg("config xtalk calibration data fail %d", rc);
		goto error;
	}
	mutex_unlock(&data->work_mutex);

	return count;

invalid:
	vi5302_errmsg("invalid syntax");
	rc = -EINVAL;
	goto error;

error:
	mutex_unlock(&data->work_mutex);

	return rc;
}

static ssize_t vi5302_offset_data_read(struct file *filp,
	struct kobject *kobj, struct bin_attribute *attr,
	char *buf, loff_t off, size_t count)
{
	struct device *dev = container_of(kobj, struct device, kobj);
	struct vi5302_data *data = dev_get_drvdata(dev);
	void *src = (void *) &(data->offset_data);

	mutex_lock(&data->work_mutex);
	if (!data->chip_enable) {
		vi5302_errmsg("can't set calib data while disable sensor\n");
		mutex_unlock(&data->work_mutex);
		return -EBUSY;
	}

	if (count > sizeof(struct vi5302_offset_calib_data))
		count = sizeof(struct vi5302_offset_calib_data);

	int rc = memcpy_s(buf, sizeof(struct vi5302_offset_calib_data), src, count);
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		vi5302_errmsg("memcpy_s fail %d", rc);
		return -EBUSY;
	}
	data->offset_config = data->offset_data.offset_cal;
	mutex_unlock(&data->work_mutex);

	return count;
}

static ssize_t vi5302_offset_data_write(struct file *filp,
	struct kobject *kobj, struct bin_attribute *attr,
	char *buf, loff_t off, size_t count)
{
	struct device *dev = container_of(kobj, struct device, kobj);
	struct vi5302_data *data = dev_get_drvdata(dev);
	struct vi5302_offset_calib_data *offset_data = 
				(struct vi5302_offset_calib_data *)buf;
	int rc = 0;

	mutex_lock(&data->work_mutex);
	if (!data->chip_enable) {
		rc = -EBUSY;
		vi5302_errmsg("can't set calib data while disable sensor\n");
		goto error;
	}

	if (count != sizeof(struct vi5302_offset_calib_data))
		goto invalid;

	if (data->enable_debug)
		vi5302_errmsg("offset config: %d\n", offset_data->offset_cal);

	data->offset_config = offset_data->offset_cal;
	mutex_unlock(&data->work_mutex);
	return count;

invalid:
	vi5302_errmsg("invalid syntax");
	rc = -EINVAL;
	goto error;

error:
	mutex_unlock(&data->work_mutex);
	return rc;
}

static struct attribute *vi5302_attributes[] = {
	&dev_attr_chip_enable.attr,
	&dev_attr_enable_debug.attr,
	&dev_attr_chip_init.attr,
	&dev_attr_period.attr,
	&dev_attr_capture.attr,
	&dev_attr_xtalk_calib.attr,
	&dev_attr_offset_calib.attr,
	&dev_attr_xtalk_config.attr,
	&dev_attr_offset_config.attr,
	NULL,
};

static const struct attribute_group vi5302_attr_group = {
	.name = NULL,
	.attrs = vi5302_attributes,
};
#endif /* CONFIG_SYSFS */

extern void laser_notify_data_event(hw_laser_ctrl_t *ctrl, struct laser_event_t *laser_event);

static void vi5302_notify_data_event(struct vi5302_data *data)
{
	struct laser_event_t laser_event = { 0 };

	if (!data || !(data->ctrl)) {
		vi5302_errmsg("notify data event failed\n");
		return;
	}

	laser_event.kind = FIRST_VALID_DATA;
	laser_notify_data_event(data->ctrl, &laser_event);
}

static irqreturn_t vi5302_irq_handler(int vec, void *info)
{
	struct vi5302_data *data = (struct vi5302_data *)info;
	vi5302_error status = VI5302_ERROR_NONE;

	vi5302_infomsg("enter vi5302_irq_handler:\n");
	if (!data || !data->fwdl_status)
		return IRQ_HANDLED;

	if (data->irq == vec) {
		if (xtalk_mark) {
			status = vi5302_func_tbl->get_xtalk_parameter(data);
			if (status != VI5302_ERROR_NONE)
				vi5302_errmsg("%d : status = %d\n" , __LINE__, status);
		}

		if (!xtalk_mark && !offset_mark) {
			status = vi5302_func_tbl->get_measure_data(data);
			if (status != VI5302_ERROR_NONE) {
				vi5302_errmsg("%d : status = %d\n" , __LINE__, status);
				return IRQ_HANDLED;
			}
			if (data->is_first_valid_data) {
				vi5302_notify_data_event(data);
				data->is_first_valid_data = false;
			}
		}
	}
	return IRQ_HANDLED;
}

static int vi5302_setup_regulator(struct device_node *np, struct vi5302_data *data)
{
	uint32_t rc = 0;
	uint32_t rgltr_min_volt[1];
	uint32_t rgltr_max_volt[1];
	uint32_t rgltr_load_current[1];
	struct regulator *vreg = NULL;

	vreg = devm_regulator_get(data->dev, "lvdd");
	if (IS_ERR(vreg)) {
		vi5302_errmsg("get regulator fail");
		goto regulator_err;
	}
	rc = of_property_read_u32_array(np, "regulator-min-microvolt", rgltr_min_volt, 1);
	if (rc != EOK) {
		vi5302_errmsg("regulator_read_voltage fail");
		goto regulator_err;
	}
	rc = of_property_read_u32_array(np, "regulator-max-microvolt", rgltr_max_volt, 1);
	if (rc != EOK) {
		vi5302_errmsg("regulator_read_voltage fail");
		goto regulator_err;
	}
	rc = regulator_set_voltage(vreg, rgltr_min_volt[0], rgltr_max_volt[0]);
	if (rc != EOK) {
		vi5302_errmsg("regulator_set_voltage fail");
		goto regulator_err;
	}
	vi5302_infomsg("Minimum volatage value = %u, Maximum volatage value = %u", rgltr_min_volt[0], rgltr_max_volt[0]);

	rc = of_property_read_u32_array(np, "rgltr-load-current", rgltr_load_current, 1);
	if (rc != EOK)
		rgltr_load_current[0] = VI5302_LOAD_CURRENT;
	vi5302_infomsg("Load curent value = %u", rgltr_load_current[0]);
	rc = regulator_set_load(vreg, rgltr_load_current[0]);
	if (rc != EOK) {
		vi5302_errmsg("regulator_set_load fail");
		goto regulator_err;
	}
	rc = regulator_enable(vreg);
	if (rc != EOK) {
		vi5302_errmsg("regulator_enable fail");
		goto regulator_err;
	}
	data->lvdd = vreg;
	return 0;

regulator_err:
	vi5302_errmsg("regulator_err");
	return 1;
}

static int vi5302_release_regulator(struct vi5302_data *data)
{
	if (data->lvdd == NULL) {
		vi5302_errmsg("release regulator fail");
		return 1;
	}
	regulator_disable(data->lvdd);
	return 0;
}

static int vi5302_parse_dt(struct device_node *np, struct vi5302_data *data)
{
	enum of_gpio_flags flags;
	data->lvdd = NULL;

	if (!data || !np)
		return -EINVAL;

	data->irq_gpio = of_get_named_gpio_flags(np, "vi5300,irq-gpio", 0, &flags);
	if (data->irq_gpio < 0) {
		vi5302_errmsg("get irq gpio: %d error\n", data->irq_gpio);
		return -ENODEV;
	}
	vi5302_infomsg("INT GPIO %d\n", data->irq_gpio);

	data->xshut_gpio = of_get_named_gpio_flags(np, "vi5300,xshut-gpio", 0, &flags);
	if (data->xshut_gpio < 0) {
		vi5302_errmsg("get xshut gpio: %d error\n", data->xshut_gpio);
		return -ENODEV;
	}
	vi5302_infomsg("XSHUT GPIO %d\n", data->xshut_gpio);

	if (vi5302_setup_regulator(np, data))
		vi5302_errmsg("vi5302 Setup Regulator Failed\n");
	return 0;
}

static int vi5302_status(struct vi5302_data* data, hwlaser_status_t *laser_status)
{
	int rc = -EINVAL;
	if (!data || !laser_status)
		return rc;

	laser_status->status = VI5302_ERROR_NONE;

	return VI5302_ERROR_NONE;
}

static int vi5302_set_calibration_data(struct vi5302_data *data, hwlaser_calibration_data_t *cal_data)
{
	int rc = 0;
	mutex_lock(&data->work_mutex);

	rc = memcpy_s(&(data->xtalk_config.xtalk_cal), sizeof(int8_t), &(cal_data->u.dataL2.VI5300_XTALK_Calib_Data.xtalk_cal), sizeof(int8_t));
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		return -EFAULT;
	}
	rc = memcpy_s(&(data->xtalk_config.xtalk_peak), sizeof(uint16_t), &(cal_data->u.dataL2.VI5300_XTALK_Calib_Data.xtalk_peak), sizeof(uint16_t));
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		return -EFAULT;
	}
	rc = vi5302_func_tbl->config_xtalk_parameter(data);
	if (rc != VI5302_ERROR_NONE)
		vi5302_infomsg("kernel xtalk_config failed(%d)", rc);

	rc = memcpy_s(&(data->offset_config), sizeof(int16_t), &(cal_data->u.dataL2.VI5300_OFFSET_Calib_Data.offset_cal), sizeof(int16_t));
	vi5302_infomsg("hal offset_config(%d)", cal_data->u.dataL2.VI5300_OFFSET_Calib_Data.offset_cal);
	vi5302_infomsg("kernel offset_config(%d)", data->offset_config);
	if (rc != EOK) {
		mutex_unlock(&data->work_mutex);
		return -EFAULT;
	}

	mutex_unlock(&data->work_mutex);
	return rc;
}

static int vi5302_laser_get_set_cal_data(struct vi5302_data* data,
	hwlaser_calibration_data_t *cal_data)
{
	int rc = 0;

	if (cal_data->is_read) {
		vi5302_dbgmsg("vi5302 hal get calibration data\n");
		rc = vi5302_get_calibration_data(data, cal_data);
		if (rc != EOK) {
			vi5302_errmsg("%d, hal get xtalk, offset fail\n", __LINE__);
			return -EFAULT;
		}
	} else {
		vi5302_dbgmsg("vi5302 hal set calibration data to kernel\n");
		rc = vi5302_set_calibration_data(data, cal_data);
		if (rc != EOK) {
			vi5302_errmsg("%d, kernel get xtalk_config, offset_config fail\n", __LINE__);
			return -EFAULT;
		}
	}

	return rc;
}

static int vi5302_perform_cal(struct vi5302_data* data, hwlaser_ioctl_perform_calibration_t* cal)
{
	int rc = 0;

	mutex_lock(&data->work_mutex);
	switch (cal->calibration_type) {
	case HWLASER_CALIBRATION_CROSSTALK:
		vi5302_enable_irq(data);
		xtalk_mark = 1;
		rc = vi5302_func_tbl->start_xtalk_calibration(data);
		if (rc != VI5302_ERROR_NONE)
			vi5302_errmsg("vi5302 perform XTALK calibration fail");
		msleep(800);
		xtalk_mark = 0;
		vi5302_disable_irq(data);
		break;
	case HWLASER_CALIBRATION_OFFSET:
		offset_mark = 1;
		vi5302_disable_irq(data);
		rc = vi5302_func_tbl->start_offset_calibration(data, cal->param1);
		if (rc != VI5302_ERROR_NONE)
			vi5302_errmsg("vi5302 perform OFFSET calibration fail");
		offset_mark = 0;
		break;
	default:
		vi5302_errmsg("vi5302 not support this calibration_type %d",
			cal->calibration_type);
	}
	mutex_unlock(&data->work_mutex);

	return rc;
}

long vi5302_ioctl(void *hw_data, unsigned int cmd, void *p)
{
	long rc = 0;
	struct vi5302_data *data = (struct vi5302_data*)hw_data;
	hwlaser_calibration_data_t *cal_data = NULL;
	hwlaser_ioctl_perform_calibration_t* cal_perform = NULL;
	hwlaser_status_t* status = NULL;
	hwlaser_info_t *pinfo = NULL;
	hwlaser_RangingData_t *pRangingData = NULL;
	hwlaser_ioctl_freq_param_t * pFreqpara = NULL;
	uint32_t fps = 0;

	if (!data)
		return -EFAULT; 

	switch (cmd) {
		case HWLASER_IOCTL_POWERON:
			vi5302_infomsg("HWLASER_IOCTL_POWERON\n");
			mutex_lock(&data->work_mutex);
			rc = vi5302_func_tbl->power_on(data);
			if (rc != VI5302_ERROR_NONE) {
				vi5302_errmsg("%d, CHIP POWER ON FAILED\n", __LINE__);
				mutex_unlock(&data->work_mutex);
				return -EIO;
			}
			ktime_get_real_ts64(&data->start_ts);
			mutex_unlock(&data->work_mutex);
			break;
		case HWLASER_IOCTL_INIT:
			vi5302_infomsg("HWLASER_IOCTL_INIT\n");
			mutex_lock(&data->work_mutex);
			rc = vi5302_func_tbl->chip_init(data);
			if (rc != VI5302_ERROR_NONE) {
				vi5302_errmsg("%d, CHIP INIT FAILED\n", __LINE__);
				mutex_unlock(&data->work_mutex);
				return -EIO;
			}
			data->fwdl_status = 1;
			mutex_unlock(&data->work_mutex);
			break;
		case HWLASER_IOCTL_GET_INFO:
			vi5302_infomsg("HWLASER_IOCTL_GET_INFO\n");
			mutex_lock(&data->work_mutex);
			pinfo = (hwlaser_info_t *)p;
			if (strncpy_s(pinfo->name, HWLASER_NAME_SIZE - 1 ,"vi5302", HWLASER_NAME_SIZE - 1))
				vi5302_errmsg("strncpy_s failed %d", __LINE__);
			if (strncpy_s(pinfo->product_name, HWLASER_NAME_SIZE - 1 ,"LASER", HWLASER_NAME_SIZE - 1))
				vi5302_errmsg("strncpy_s failed %d", __LINE__);
			pinfo->version = HWLASER_VI_I0_VERSION;
			pinfo->ap_pos = HWLASER_POS_AP;
			mutex_unlock(&data->work_mutex);
			break;
		case HWLASER_IOCTL_MATCHID:
			vi5302_infomsg("HWLASER_IOCTL_MATCHID");
			mutex_lock(&data->work_mutex);
			status = (hwlaser_status_t*) p;
			rc = vi5302_status(data, p);
			mutex_unlock(&data->work_mutex);
			break;
		case HWLASER_IOCTL_START:
			vi5302_infomsg("HWLASER_IOCTL_START\n");
			mutex_lock(&data->work_mutex);
			if (!(data->wake_lock->active)) {
				__pm_wakeup_event(data->wake_lock, START_WAKE_LOCK_TIMEOUT);
				vi5302_infomsg("%s laser start, wake lock", __func__);
			}
			vi5302_enable_irq(data);
			data->is_first_valid_data = true;
			rc = vi5302_func_tbl->start_continuous_measure(data);
			if (rc != VI5302_ERROR_NONE) {
				vi5302_errmsg("%d, CHIP START RANGE FAILED\n", __LINE__);
				mutex_unlock(&data->work_mutex);
				return -EIO;
			}
			mutex_unlock(&data->work_mutex);
			break;
		case HWLASER_IOCTL_MZ_DATA:
			vi5302_infomsg("HWLASER_IOCTL_GET_DATA\n");
			mutex_lock(&data->work_mutex);
			pRangingData = (hwlaser_RangingData_t *)p;
			if (memcpy_s(&(pRangingData->v_data), sizeof(struct VI5300_Measurement_Data), &(data->range_data), sizeof(struct VI5300_Measurement_Data)) != EOK) {
				vi5302_errmsg("memcpy failed %d", __LINE__);
				mutex_unlock(&data->work_mutex);
				return -EFAULT;
			}
			mutex_unlock(&data->work_mutex);
			vi5302_infomsg("milimeter(%d),status(%u)",
				pRangingData->v_data.milimeter,
				pRangingData->v_data.status);
			vi5302_infomsg("milimeter(%d), status(%u)",
				data->range_data.milimeter,
				data->range_data.status);
			break;
		case HWLASER_IOCTL_STOP:
			vi5302_infomsg("HWLASER_IOCTL_STOP\n");
			mutex_lock(&data->work_mutex);
			vi5302_disable_irq(data);
			rc = vi5302_func_tbl->stop_continuous_measure(data);
			if (rc != VI5302_ERROR_NONE) {
				vi5302_errmsg("%d, CHIP STOP RANGE FAILED\n", __LINE__);
				mutex_unlock(&data->work_mutex);
				return -EIO;
			}
			mutex_unlock(&data->work_mutex);
			if (data->wake_lock->active) {
				__pm_relax(data->wake_lock);
				vi5302_infomsg("%s laser stop, wake unlock", __func__);
			}
			break;
		case HWLASER_IOCTL_POWEROFF:
			vi5302_infomsg("HWLASER_IOCTL_POWEROFF\n");
			mutex_lock(&data->work_mutex);
			data->fwdl_status = 0;
			rc = vi5302_func_tbl->power_off(data);
			if (rc != VI5302_ERROR_NONE) {
				vi5302_errmsg("%d, CHIP POWER OFF FAILED\n", __LINE__);
				mutex_unlock(&data->work_mutex);
				return -EIO;
			}
			mutex_unlock(&data->work_mutex);
			break;
		case HWLASER_IOCTL_SET_FREQ:
			vi5302_infomsg("HWLASER_IOCTL_SET_FREQ");
			mutex_lock(&data->work_mutex);
			pFreqpara = (hwlaser_ioctl_freq_param_t *)p;
			fps = pFreqpara->freq;
			vi5302_infomsg("freq set to: %u", fps);
			if (fps > MAX_FPS) {
				vi5302_errmsg("%d, max fps = %d\n", __LINE__, MAX_FPS);
				mutex_unlock(&data->work_mutex);
				return -EFAULT;
			}
			data->fps = fps;
			if (data->enable_debug)
				vi5302_errmsg("fps setting: %d\n", data->fps);
			vi5302_func_tbl->set_fps(data, data->fps);
			mutex_unlock(&data->work_mutex);
			break;
		/* fac HDDC calib: xtalk & offeset */
		case HWLASER_IOCTL_PERFORM_CALIBRATION:
			vi5302_infomsg("HWLASER_IOCTL_PERFORM_CALIBRATION\n");
			cal_perform = (hwlaser_ioctl_perform_calibration_t*) p;
			rc = vi5302_perform_cal(data, cal_perform);
			break;
		/* calib data xtalk & offset save and set */
		case HWLASER_IOCTL_CALIBRATION_DATA:
			vi5302_infomsg("HWLASER_IOCTL_CALIBRATION_DATA\n");
			cal_data = (hwlaser_calibration_data_t *)p;
			rc = vi5302_laser_get_set_cal_data(data, cal_data);
			break;
		default:
			vi5302_infomsg("cmd not support: %u", cmd);
			rc = -EFAULT;
	}

	return rc;
}

static int vi5302_setup(struct vi5302_data *data)
{
	int rc = 0;
	int irq = 0;
	uint8_t buf = 0;
	uint8_t chipid[3] = {0};
	uint32_t chipversion = 0;

	if (!data)
		return -EINVAL;

	if (!gpio_is_valid(data->irq_gpio) || !gpio_is_valid(data->xshut_gpio))
		return -ENODEV;

	rc = gpio_request(data->xshut_gpio, "vi5302 xshut gpio");
	if (rc < 0) {
		vi5302_errmsg("gpio_request xshut_gpio failed.%d\n", rc);
		return rc;
	}
	rc = gpio_request(data->irq_gpio, "vi5302 irq gpio");
	if (rc < 0) {
		vi5302_errmsg("gpio_request irq_gpio failed.%d\n", rc);
		return rc;
	}
	gpio_direction_input(data->irq_gpio);
	irq = gpio_to_irq(data->irq_gpio);
	if (irq < 0) {
		vi5302_errmsg("fail to map GPIO: %d to INT: %d\n", data->irq_gpio, irq);
		rc = -EINVAL;
		goto exit_free_gpio;
	} else {
		vi5302_dbgmsg("request irq: %d\n", irq);
		rc = request_threaded_irq(irq,  NULL, vi5302_irq_handler, 
			IRQF_TRIGGER_FALLING | IRQF_ONESHOT, "vi5302_interrupt", (void *)data);
		if (rc != EOK) {
			vi5302_errmsg("%s(%d), Could not allocate VI5302_INT ! result:%d\n",__FUNCTION__, __LINE__, rc);
			goto exit_free_irq;
		}
	}
	data->irq = irq;
	data->intr_state = VI5302_INTR_DISABLED;
	disable_irq(data->irq);
	data->fwdl_status = 0;
	vi5302_func_tbl = &vi5302_api_func_tbl;
	vi5302_setupAPIFunctions();
	vi5302_func_tbl->power_on(data);
	vi5302_read_multibytes(data, REG_CHIPID_BASE, chipid, 3);
	chipversion = (chipid[1] << 16) + (chipid[0] << 8) + chipid[2];

	vi5302_read_byte(data, REG_DEV_ADDR, &buf);
	vi5302_func_tbl->power_off(data);
	if (buf != VI5302_CHIP_ADDR) {
		vi5302_errmsg("VI5302 I2C Transfer Failed, ChipVersion = 0x%x, ChipAddr = 0x%x\n", chipversion, buf);
		rc = -EFAULT;
		goto exit_free_irq;
	}
	vi5302_infomsg("VI5302 I2C Transfer Successfully, ChipVersion = 0x%x, ChipAddr = 0x%x\n", chipversion, buf);
	data->fps = 30;
	data->xtalk_config.xtalk_cal = 0;
	data->xtalk_config.xtalk_peak = 100;
	data->offset_config = 0;
	data->range_data.status = 255;
	data->is_first_valid_data = true;
	data->vi5302_attr_group = &vi5302_attr_group;

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
	set_hw_dev_flag(DEV_I2C_LASER);
#endif
	return 0;

exit_free_irq:
	free_irq(irq, data);
exit_free_gpio:
	gpio_free(data->xshut_gpio);
	gpio_free(data->irq_gpio);
	return rc;
}

static int vi5302_classdev_register(struct vi5302_data *vi5302_data)
{
	int rc = 0;
	struct device *pdevice = NULL;
	vi5302_data->dev_class = class_create(THIS_MODULE, "laser");
	if (!(vi5302_data->dev_class))
		return PTR_ERR(vi5302_data->dev_class);
	pdevice = device_create(vi5302_data->dev_class, vi5302_data->dev, 0, NULL, "vi5302");
	if (!pdevice) {
		vi5302_errmsg("device_create error\n");
		class_destroy(vi5302_data->dev_class);
		vi5302_data->dev_class = NULL;
		rc = -EFAULT;
	}
	return rc;
}

int vi5302_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct vi5302_data *vi5302_data = NULL;
	struct device *dev = &client->dev;
	struct device_node *node = NULL;
	hw_laser_ctrl_t *ctrl = NULL;
	int ret = 0;

	vi5302_data = devm_kzalloc(&client->dev, sizeof(*vi5302_data), GFP_KERNEL);
	if (!vi5302_data) {
		vi5302_errmsg("devm_kzalloc error\n");
		return -ENOMEM;
	}
	if (!dev->of_node) {
		devm_kfree(&client->dev, vi5302_data);
		vi5302_data = NULL;
		return -EINVAL;
	}
	/* setup device data */
	vi5302_data->dev_name = dev_name(&client->dev);
	vi5302_data->client = client;
	vi5302_data->dev = dev;
	ctrl = (hw_laser_ctrl_t *)id->driver_data;
	vi5302_data->ctrl = ctrl;
	ctrl->data = (void *)vi5302_data;
	node = dev->of_node;
	mutex_init(&vi5302_data->work_mutex);
	ret = vi5302_parse_dt(node, vi5302_data);
	if (ret) {
		vi5302_errmsg("VI5302 Parse DT Failed\n");
		goto exit_error;
	}
	ret = vi5302_setup(vi5302_data);
	if (ret) {
		vi5302_errmsg("VI5302 Setup Failed\n");
		goto exit_error;
	}
	ret = vi5302_classdev_register(vi5302_data);
	if (ret)
		vi5302_errmsg("clasdev register fail\n");
	ret = sysfs_create_group(&vi5302_data->dev->kobj, vi5302_data->vi5302_attr_group);
	if (ret)
		vi5302_errmsg("sysfs register fail\n");
	vi5302_data->wake_lock = wakeup_source_register(&vi5302_data->client->dev, "laser_attach_wakelock");
	if (!vi5302_data->wake_lock) {
		vi5302_errmsg("%s: wakeup source register failed", __func__);
		goto exit_error;
	}
	dev_set_drvdata(&client->dev, vi5302_data);

	return 0;

exit_error:
	mutex_destroy(&vi5302_data->work_mutex);
	vi5302_release_regulator(vi5302_data);
	dev_set_drvdata(&client->dev, NULL);
	devm_kfree(&client->dev, vi5302_data);
	vi5302_data = NULL;
	return ret;
}

int vi5302_remove(struct i2c_client *client)
{
	struct vi5302_data *data = i2c_get_clientdata(client);
	if (data->xshut_gpio) {
		gpio_direction_output(data->xshut_gpio, 0);
		gpio_free(data->xshut_gpio);
	}
	if (data->irq_gpio) {
		free_irq(data->irq, data);
		gpio_free(data->irq_gpio);
	}
	wakeup_source_unregister(data->wake_lock);
	mutex_destroy(&data->work_mutex);
	dev_set_drvdata(&client->dev, NULL);
	kfree(data);
	data = NULL;
	return 0;
}

