/*
 * echub_log.c
 *
 * echub log interface
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/i2c.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/syscalls.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#include <securec.h>
#include "ospm_printf.h"
#include "echub_i2c.h"
#include "echub_log.h"
#include "hmi/hmi.h"

struct echub_ec_log_info {
	int monitoring_interval;
	struct echub_i2c_dev *echub_dev;
	struct device *dev;
	struct delayed_work echub_ec_log_work;
};
struct echub_ec_log_info *g_ec_log_dev;

typedef struct {
	char *name;
	int (*get_log)(struct seq_file *m, void *v);
} ec_log_t;

static int g_eclog_cmd_type = 0;
static struct notifier_block g_hmi_event_nb;
static int g_record_kbd_cnt = 0;

static int query_echub_log(struct i2c_client *client, u8 *buf, int size, int index)
{
	u8 write_buf[4] = {0}; /* echub log query cmd, 4 byte */
	u16 query_addr = ECLOG_DUMP_START_ADDR + index * ECLOG_DUMP_SIZE;

	if (!buf || size != ECLOG_DUMP_SIZE) {
		echub_err("%s, query echub log failed\n", __func__);
		return -EFAULT;
	}

	write_buf[0] = upper_byte(ECLOG_DUMP_CMD);
	write_buf[1] = lower_byte(ECLOG_DUMP_CMD);
	write_buf[2] = upper_byte(query_addr); // buffer[2]
	write_buf[3] = lower_byte(query_addr); // buffer[3]

	struct i2c_msg msgs[] = {
		{
			.addr = client->addr,
			.buf = write_buf,
			.len = sizeof(write_buf),
			.flags = 0,
		}, {
			.addr = client->addr,
			.buf = buf,
			.len = size,
			.flags = I2C_M_RD,
		}
	};

	if (i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs)) != ARRAY_SIZE(msgs)) {
		echub_err("%s, transfer data failed\n", __func__);
		return -EIO;
	}
	return 0;
}

static int get_log_dump_times(u8 log_type)
{
	switch (log_type) {
	case ECLOG_LOG_TYPE_TRACE:
	case ECLOG_LOG_TYPE_FLASH:
		return ECLOG_DUMP_TIMES + 1;
	case ECLOG_LOG_TYPE_CRITICAL:
		return EC_CRITICAL_DUMP_TIMES + 1;
	case ECLOG_LOG_TYPE_FP:
		return EC_FP_LOG_DUMP_TIMES + 1;
	case ECLOG_LOG_TYPE_PD:
		return 1;
	case ECLOG_LOG_TYPE_SHUTDOWN:
		return EC_SHUTDOWN_DUMP_TIMES + 1;
	case ECLOG_LOG_TYPE_KBD:
		return EC_KBD_DUMP_TIMES + 1;
	default:
		break;
	}
	return 0;
}

static int get_ec_log_info(struct seq_file *m, u8 log_type)
{
	u8 log_buf[ECLOG_DUMP_SIZE] = {0};
	char *buffer = NULL;
	size_t size;
	int ret;
	int cmd = ECLOG_QUERY_CMD;
	int dump_size = ECLOG_QUERY_DATA_SIZE;
	int dump_times;
	u8 write_buf[2] = {log_type, 0};
	struct echub_i2c_dev *echub_dev = (struct echub_i2c_dev *)m->private;

	if (!echub_dev || !echub_dev->transfer_func) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}

	size = seq_get_buf(m, &buffer);
	if (size < ECLOG_OUTPUT_SIZE) {
		seq_commit(m, -1);
		return 0;
	}

	dump_times = get_log_dump_times(log_type);
	if (log_type == ECLOG_LOG_TYPE_SHUTDOWN) {
		cmd = ECLOG_QUERY_SHUTDOWN_CODE;
		dump_size = ECLOG_SHUTDOWN_DATA_SIZE;
	}

	for (int i = 0; i < dump_times; i++) {
		write_buf[1] = i;
		ret = echub_dev->transfer_func(echub_dev, cmd, write_buf, 2, log_buf, ECLOG_QUERY_DATA_SIZE); // 2 byte slen
		if (ret) {
			echub_err("%s, query_echub_log failed: %d\n", __func__, ret);
			break;
		}
		seq_hex_dump(m, "", DUMP_PREFIX_NONE, ECLOG_ONE_LINE_BYTES, 1, log_buf, dump_size, 0);
	}
	return ret;
}

static int echub_get_trace_log(struct seq_file *m, void *v)
{
	struct echub_i2c_dev *echub_dev = NULL;
	u8 log_buf[ECLOG_DUMP_SIZE] = {0};
	char *buffer = NULL;
	size_t size;
	int ret;

	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	echub_dev = (struct echub_i2c_dev *)m->private;
	if (!echub_dev || !echub_dev->client) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}

	size = seq_get_buf(m, &buffer);
	if (size < ECLOG_OUTPUT_SIZE) {
		seq_commit(m, -1);
		return 0;
	}

	if (g_eclog_cmd_type) {
		for (int i = 0; i < ECLOG_DUMP_TIMES; i++) {
			ret = query_echub_log(echub_dev->client, log_buf, ECLOG_DUMP_SIZE, i);
			if (ret) {
				echub_err("%s, query_echub_log failed: %d\n", __func__, ret);
				break;
			}
			seq_hex_dump(m, "", DUMP_PREFIX_NONE, ECLOG_ONE_LINE_BYTES * 2, 1, log_buf, ECLOG_DUMP_SIZE, 0);
		}
	} else {
		ret = get_ec_log_info(m, ECLOG_LOG_TYPE_TRACE);
	}

	return ret;
}

static int get_ec_trace_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_TRACE);
	if (ret) {
		echub_err("%s, query ec trace log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_flash_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_FLASH);
	if (ret) {
		echub_err("%s, query ecflash log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_kbd_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_KBD);
	if (ret) {
		echub_err("%s, query ec kbd log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_critical_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_CRITICAL);
	if (ret) {
		echub_err("%s, query ec critical log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_fp_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_FP);
	if (ret) {
		echub_err("%s, query ec fp log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_pd_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_PD);
	if (ret) {
		echub_err("%s, query ec pd log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_shutdowncause_log(struct seq_file *m, void *v)
{
	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	int ret = get_ec_log_info(m, ECLOG_LOG_TYPE_SHUTDOWN);
	if (ret) {
		echub_err("%s, query ec shutdown cause log failed: %d\n", __func__, ret);
	}

	return ret;
}

static int get_ec_version(struct seq_file *m, void *v)
{
	u8 main_version_buf[EC_VERSION_SIZE + 1] = {0};
	u8 sub_version_buf[EC_VERSION_SIZE + 1] = {0};
	char *buffer = NULL;
	size_t size;
	int ret;
	struct echub_i2c_dev *echub_dev = NULL;

	if (!m) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}
	echub_dev = (struct echub_i2c_dev *)m->private;
	if (!echub_dev || !echub_dev->transfer_func) {
		echub_err("%s, invalid value\n", __func__);
		return -EINVAL;
	}

	size = seq_get_buf(m, &buffer);
	if (size < EC_VERSION_OUTPUT_SIZE) {
		seq_commit(m, -1);
		return 0;
	}

	ret = echub_dev->transfer_func(echub_dev, EC_MAIN_VERSION_CMD, NULL, 0, main_version_buf, EC_VERSION_SIZE);
	msleep(10); // delay 10ms
	ret |= echub_dev->transfer_func(echub_dev, EC_SUB_VERSION_CMD, NULL, 0, sub_version_buf, EC_VERSION_SIZE);
	if (ret) {
		echub_err("%s, get ec version failed: %d\n", __func__, ret);
	}
	seq_printf(m, "v%s-%s\n", main_version_buf, sub_version_buf);
	return ret;
}

static const ec_log_t ec_log_tab[] = {
	{"ec_trace_log", get_ec_trace_log},
	{"ec_critical_log", get_ec_critical_log},
	{"ec_flash_log", get_ec_flash_log},
	{"ec_shutdowncause_log", get_ec_shutdowncause_log},
	{"ec_fp_log", get_ec_fp_log},
	{"ec_pd_log", get_ec_pd_log},
	{"ec_version", get_ec_version},
	{"ec_kbd_log", get_ec_kbd_log},
};

static int get_ec_errcode(struct echub_i2c_dev *echub_dev)
{
	int ret;
	u8 errcode[EC_ERRORCODE_SIZE] = {0};
	int errcodecmd = 0x0249; // 0x0249: get ec shutdowncase to report
	u8 senddata = 1;

	// caller must esure echub_dev valid
	ret = echub_dev->transfer_func(echub_dev, errcodecmd, &senddata, 1, errcode, EC_ERRORCODE_SIZE);
	if (ret != 0) {
		echub_err("%s, get_ec_errcode 0249 failed: %d\n", __func__, ret);
		return 0xFF; // cmd error, 0xFF do not report
	}

	return errcode[0];
}

static int save_eclog(const u8 *log_buf, int log_len, const char *file_name)
{
	int ret;
	char ec_log_path[PATH_MAX_LEN] = {0};
	struct file *fp = NULL;

	if (log_buf == NULL || file_name == NULL)
		return -EINVAL;

	if (ksys_access(EC_LOG_ROOT_DIR, 0) < 0) {
		echub_err("%s: mkdir %s\n", __func__, EC_LOG_ROOT_DIR);
		ret = ksys_mkdir(EC_LOG_ROOT_DIR, 770); // 770: DIR_LIMIT(S_IRWXU | S_IRWXG)
		if (ret != 0) {
			echub_err("%s: mkdir %s fail  with ret %d\n", __func__, EC_LOG_ROOT_DIR, ret);
			return -EINVAL;
		}
	}
	scnprintf(ec_log_path, sizeof(ec_log_path) - 1, "%s%s", EC_LOG_ROOT_DIR, file_name);
	fp = filp_open(ec_log_path, O_CREAT | O_RDWR | O_TRUNC, 0644); // 0644: S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
	if (IS_ERR(fp)) {
		echub_err("%s: filp_open %s fail. fp=0x%pK\n", __func__, ec_log_path, fp);
		return -EINVAL;
	}
	vfs_llseek(fp, 0L, SEEK_END);
	echub_err("%s: write log to file %s: ", __func__, ec_log_path);
	ret = vfs_write(fp, (char *)log_buf, log_len, &(fp->f_pos));
	if (ret != log_len) {
		echub_err(" fail with ret %d\n", ret);
		filp_close(fp, NULL);
		return -EINVAL;
	}

	echub_err(" SUCC\n", ret);
	filp_close(fp, NULL);
	return 0;
}

static int proc_save_eclog(struct echub_i2c_dev *echub_dev, u8 log_type, const char *file_name)
{
	int ret;
	u8 *log_buf = NULL;
	int log_buf_size;
	int cmd = ECLOG_QUERY_CMD;
	int dump_size = ECLOG_QUERY_DATA_SIZE;
	int dump_times;
	u8 write_buf[NUM_2] = {log_type, 0};
	u8 temp_buf[ECLOG_DUMP_SIZE] = {0};

	if (!echub_dev || !file_name)
		return  -EINVAL;

	dump_times = get_log_dump_times(log_type);
	if (log_type == ECLOG_LOG_TYPE_SHUTDOWN) {
		cmd = ECLOG_QUERY_SHUTDOWN_CODE;
		dump_size = ECLOG_SHUTDOWN_DATA_SIZE;
	}

	log_buf_size = dump_size * dump_times;
	log_buf = kzalloc(log_buf_size, GFP_KERNEL);
	if (!log_buf) {
		echub_err(" kzalloc ec log buf error\n");
		return -ENOMEM;
	}

	for (int i = 0; i < dump_times; i++) {
		write_buf[1] = i;
		echub_err("transfer ec log index: %d\n", i);
		ret = echub_dev->transfer_func(echub_dev, cmd, write_buf, 2, temp_buf, ECLOG_QUERY_DATA_SIZE); // 2 byte slen
		if (ret != 0) {
			echub_err("transfer ec log failed: %d\n", ret);
			break;
		}

		ret = memcpy_s(log_buf + dump_size * i, log_buf_size - dump_size * i, temp_buf, dump_size);
		if (ret != EOK) {
			echub_err("memcpy_s failed, index %d\n", i);
			break;
		}
	}

	ret = save_eclog(log_buf, log_buf_size, file_name);

	kfree(log_buf);
	return ret;
}

#ifdef CONFIG_HISYSEVENT
static void eclog_report_by_errcode(int errorcode, const char *logname)
{
    struct hiview_hisysevent *event = NULL;
    int ret;

	if (!logname)
		return;

	echub_err("report errorcode 0x%x for %s: ", errorcode, logname);
    event = hisysevent_create("EC_FIRMWARE", logname, FAULT);
    if (!event) {
        echub_err("failed to create event");
        return;
    }
    ret = hisysevent_put_integer(event, "SHUTDOWNCASE", errorcode);
    if (ret != 0) {
        echub_err("failed to put integer to event, ret=%d", ret);
        goto hisysevent_end;
    }
    ret = hisysevent_write(event);
	if (ret != 0)
        echub_err("failed to write event");

hisysevent_end:
    hisysevent_destroy(&event);
}

static void eclog_report(int errorcode)
{
	for (int i = 0; i < ARRAY_SIZE(g_eclog_event); i++) {
		if (errorcode == g_eclog_event[i].errcode) {
			eclog_report_by_errcode(errorcode, g_eclog_event[i].eventname);
			return;
		}
	}
}
#endif

static void eclog_for_bigdata(struct echub_i2c_dev *echub_dev)
{
	int errcode;
	int ret;

	if (!echub_dev || !echub_dev->transfer_func) {
		echub_err("%s, invalid value\n", __func__);
		return;
	}

	errcode = get_ec_errcode(echub_dev);
	echub_err("%s, error code 0x%x\n", __func__, errcode);
	if (errcode == 0xFF) // 0xFF: no error report
		return;

	for (int i = 0; i < ARRAY_SIZE(g_eclog_file); i++) {
		ret = proc_save_eclog(echub_dev, g_eclog_file[i].log_type, g_eclog_file[i].log_filename);
		if (ret != 0)
			echub_err("%s, save %s fail, \n", __func__, g_eclog_file[i].log_filename);
	}
#ifdef CONFIG_HISYSEVENT
	eclog_report(errcode);
#endif
}

struct echub_ec_log_info *create_ec_log_info(struct platform_device *pdev, struct echub_i2c_dev *echub_dev)
{
	struct echub_ec_log_info *di = NULL;

	if (!pdev || !echub_dev)
		return NULL;

	di = devm_kzalloc(&pdev->dev, sizeof(struct echub_ec_log_info), GFP_KERNEL);
	if (!di)
		return NULL;

	di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
	return di;
}

static void echub_eclog_work(struct work_struct *work)
{
	struct echub_ec_log_info *di = NULL;
	if (!work) {
		echub_err("[%s:%dL] work is NULL\n", __func__, __LINE__);
		return;
	}
	di = container_of(work, struct echub_ec_log_info, echub_ec_log_work.work);
	if (!di || !di->echub_dev) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}

	eclog_for_bigdata(di->echub_dev);
}

static void echub_log_work_init(void)
{
	struct echub_ec_log_info *di = g_ec_log_dev;
	if (di == NULL) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return;
	}

	INIT_DELAYED_WORK(&di->echub_ec_log_work, echub_eclog_work);
	queue_delayed_work(system_power_efficient_wq, &di->echub_ec_log_work, msecs_to_jiffies(10000)); // 10000ms
}

static void echub_log_probe_init(struct platform_device *pdev, struct echub_ec_log_info *di)
{
	echub_log_work_init();
}

static int echub_log_probe(struct platform_device *pdev)
{
	int ret;
	struct echub_i2c_dev *echub_dev;
	struct proc_dir_entry *echub_dir = NULL;
	struct echub_ec_log_info *di = NULL;
	umode_t mode = 440; // 0440: S_IRUSR | S_IRGRP

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node)
		return -ENODEV;

	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (!echub_dev) {
		echub_err("echub_dev is NULL\n");
		return -ENODEV;
	}

	ret = of_property_read_u32(pdev->dev.of_node, "eclog_cmd_type", &g_eclog_cmd_type);
	if (ret < 0)
		g_eclog_cmd_type = 0;

	if (!proc_create_single_data("echub_log", mode, NULL, echub_get_trace_log, echub_dev)) {
		echub_err("create echub log proc node failed\n");
		return -ENOMEM;
	}

	echub_dir = proc_mkdir("echub", NULL);
	if (echub_dir == NULL) {
		echub_err("create echub proc node failed\n");
		return -ENOMEM;
	}

	for (int i = 0; i < sizeof(ec_log_tab) / sizeof(ec_log_t); i++) {
		if (!proc_create_single_data(ec_log_tab[i].name, mode, echub_dir, ec_log_tab[i].get_log, echub_dev)) {
			echub_err("create ec log proc node failed, index = %d\n", i);
		}
	}

	di = create_ec_log_info(pdev, echub_dev);
	if (!di)
		return -ENOMEM;
	g_ec_log_dev = di;
	echub_log_probe_init(pdev, di);

	return 0;
}

static const struct of_device_id of_echub_log_match_tbl[] = {
	{ .compatible = "huawei,echub-log" },
	{},
};

static struct platform_driver echub_log_driver = {
	.driver = {
		.name = "echub-log",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(of_echub_log_match_tbl),
	},
	.probe = echub_log_probe,
};

static void getkbdlog_qevent_callback(int cnt)
{
	u8 *log_buf = NULL;
	int cmd = ECLOG_QUERY_CMD;
	int dump_size = ECLOG_QUERY_DATA_SIZE;
	int dump_times = EC_KBD_DUMP_TIMES + 1;
	char file_name[EC_KBD_FILENAME_LEN] = {0};
	u8 write_buf[NUM_2] =  {ECLOG_LOG_TYPE_KBD, 0};
	u8 temp_buf[ECLOG_DUMP_SIZE] = {0};
	int ret;
	struct echub_ec_log_info *di = g_ec_log_dev;
	if (di == NULL) {
		echub_err("[%s: %dL] di is NULL\n", __func__, __LINE__);
		return;
	}
	struct echub_i2c_dev *echub_dev = di->echub_dev;
	if (!echub_dev || !echub_dev->transfer_func) {
        echub_err("[%s: %dL] echub_dev is NULL\n", __func__, __LINE__);
        return;
	}

	log_buf = (u8 *)kzalloc(ECLOG_KEYBOARD_SIZE, GFP_KERNEL);
	if (!log_buf) {
        echub_err("kzalloc ec log buf error\n");
        return;
	}
	(void)snprintf_s(file_name, EC_KBD_FILENAME_LEN, EC_KBD_FILENAME_LEN - 1, "kbdlog%d", cnt);
	for (int i = 0; i < dump_times; i++) {
		write_buf[1] = i;
		mdelay(10); // delay 10ms
		ret = echub_dev->transfer_func(echub_dev, cmd, write_buf, 2, temp_buf, ECLOG_QUERY_DATA_SIZE); // 2 byte slen
		if (ret != 0) {
			echub_err("transfer ec kbd log failed: %d\n", ret);
			break;
		}
		if (i == dump_times - 1) {
			ret = memcpy_s(log_buf + dump_size * i, ECLOG_KEYBOARD_SIZE - dump_size * i, temp_buf, 
				ECLOG_KEYBOARD_SIZE - dump_size * i);
        } else {
			ret = memcpy_s(log_buf + dump_size * i, ECLOG_KEYBOARD_SIZE - dump_size * i, temp_buf, dump_size);
		}
		if (ret != 0) {
            echub_err("memcpy_s failed: %d\n", ret);
            break;
		}
	}
	(void)save_eclog(log_buf, ECLOG_KEYBOARD_SIZE, file_name);
	kfree(log_buf);
	return;
}

static int echub_get_kbclog_event_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	if (event == GET_KEYBOARD_LOG) {
		g_record_kbd_cnt %= EC_KBD_FILE_MAX_SIZE;
		getkbdlog_qevent_callback(g_record_kbd_cnt);
		g_record_kbd_cnt++;
	}
	return NOTIFY_OK;
}

static int __init echub_log_init(void)
{
	g_hmi_event_nb.notifier_call = echub_get_kbclog_event_notifier_call;
	int ret = hmi_event_bnc_register(HMI_KEYBOARD_EVENT, &g_hmi_event_nb);
	if (ret != 0) {
		echub_err("[%s]failed to init register keyboard log event ret = %d\n", __func__, ret);
		return ret;
	}
	return platform_driver_register(&echub_log_driver);
}

static void __exit echub_log_exit(void)
{
	platform_driver_unregister(&echub_log_driver);
}

module_init(echub_log_init);
module_exit(echub_log_exit);

MODULE_DESCRIPTION("echub log driver");
MODULE_LICENSE("GPL");
