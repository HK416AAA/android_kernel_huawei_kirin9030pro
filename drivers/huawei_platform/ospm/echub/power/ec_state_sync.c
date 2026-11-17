/*
 * ec_state_sync.c
 *
 * ec_state_sync driver for suspend/resume
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/syscore_ops.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/fs.h>
#ifdef CONFIG_POWERKEY_SPMI
#include <platform_include/basicplatform/linux/powerkey_event.h>
#endif
#ifdef CONFIG_DKMD_DKSM
#include <platform_include/display/dkmd/dkmd_notify.h>
#endif
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#include <securec.h>
#include "ec_state_sync.h"
#include "echub_i2c.h"
#include "ospm_printf.h"

#define GPIO_OUT_HIGH           (1)
#define GPIO_OUT_LOW            (0)

#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
#define MAX_SLEEP_COUNT         (100)
#endif

#define EC_POST_CODE_CMD        0x02B2

#define PM_STATE_SUSPEND_MEM 	(0x1)
#define PM_STATE_SUSPEND_DISK 	(0x2)

#define EC_I2C_TIMESTAMP_CMD    0x02BB
#define WAKERTC_DELAY_TIME      (5000)
#define TIMESTAMP_LEN           4
#define MAX_RETRY_CNT           3
#define SHIFT_OFFSET_1_BYTE 	8
#define SHIFT_OFFSET_2_BYTE 	16
#define SHIFT_OFFSET_3_BYTE 	24
#define MS_SECOND_TO_TENMIN     600000
#ifdef CONFIG_HISYSEVENT
#define SEC_TO_MILLISEC 1000
#define MILLISEC_TO_NANOSEC (1000 * 1000)

struct awake_s3_info {
	u64 start_time;
	u64 end_time;
};

static struct awake_s3_info g_awake_s3_info = {
	.start_time = 0,
	.end_time = 0
};
#endif

struct ec_state_sync_info {
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	int gpio_sync;
	int gpio_s0_power_on;
	int gpio_s0_power_on_delay_ms;
	bool pcie_ssd_time_config_support;
	unsigned int pcie_ssd_rc_idx;
	unsigned int pcie_ssd_reset_gpio;
	unsigned int t_ref2perst[0x2];
	unsigned int t_perst2access[0x2];
	unsigned int pcie_ssd_poweron2perst_delay_ms;
	struct delayed_work rtc_timestamp_work;
};

static bool g_s3_wakeup_flag = false;
static int g_echub_pm_suspend_state = 0x0;
static struct ec_state_sync_info *g_ec_state_sync_di;
int g_gpio_soc_ec_int = 0;
int g_gpio_num;
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
int g_sleep_count = 0;
int get_sleep_count(void)
{
	return g_sleep_count;
}
EXPORT_SYMBOL(get_sleep_count);
#endif

#ifdef CONFIG_HISYSEVENT
static void get_current_time_ms(u64 *millisec)
{
	struct timespec64 ts;
	ktime_get_ts64(&ts);
	*millisec = (u64)(ts.tv_sec * SEC_TO_MILLISEC) + (u64)(ts.tv_nsec / MILLISEC_TO_NANOSEC);
}

static void hiview_hisysevent_s3_wakeup_event(const char *name, const char *key, const u64 timestamp)
{
	struct hiview_hisysevent *event = NULL;
	int ret = 0;
	int write_len = 0;

	event = hisysevent_create("KERNEL_WAKEUP", name, BEHAVIOR);
	if (event == NULL) {
		echub_err("failed to create event %s\n", name);
		return;
	}
	ret = hisysevent_put_integer(event, key, timestamp);
	if (ret != 0) {
		echub_err("failed to put key %s to event, ret=%d\n", key, ret);
		goto hisysevent_end;
	}
	write_len = hisysevent_write(event);
	if (write_len < 0) {
		echub_err("failed to write to event, key %s, ret=%d\n", key, ret);
	}

hisysevent_end:
	hisysevent_destroy(&event);
}

static void hiview_hisysevent_wakeuptime_event(u8 waketype)
{
	u8 recvtime[NUM_4] = {0};
	int eccmd = 0x0249; // 0x0249 02: get ec resumetime to report
	u8 senddata = 2; // data 02
	u64 wakeuptime;
	struct hiview_hisysevent *event = NULL;
	int ret;
	int write_len;

    if (waketype == AWAKE_TYPE_S3) {
		wakeuptime = g_awake_s3_info.end_time - g_awake_s3_info.start_time;
	} else {
		if (g_ec_state_sync_di == NULL || g_ec_state_sync_di->echub_dev == NULL) {
			echub_err("%s echub_dev is NULL\n", __func__);
			return;
		}

		ret = g_ec_state_sync_di->echub_dev->transfer_func(g_ec_state_sync_di->echub_dev,
			eccmd, &senddata, 1, recvtime, NUM_4);
		if (ret != 0) {
			echub_err("%s, get resume time failed: %d\n", __func__, ret);
			return;
		}
		wakeuptime = recvtime[0] + (recvtime[1] << NUM_8) + (recvtime[NUM_2] << NUM_16) + (recvtime[NUM_3] << NUM_24);
	}
	echub_info("wakeup time = %llu\n", wakeuptime);

	event = hisysevent_create("POWER", "SYSTEM_AWAKE_TIME", STATISTIC);
	if (event == NULL) {
		echub_err("failed to create event\n");
		return;
	}
	ret = hisysevent_put_integer(event, "AWAKE_TYPE", waketype);
	if (ret != 0) {
		echub_err("failed to put waketype to event, ret=%d\n", ret);
		goto hisysevent_end;
	}
	ret = hisysevent_put_integer(event, "AWAKE_TIME", wakeuptime);
	if (ret != 0) {
		echub_err("failed to put wakeuptime to event, ret=%d\n", ret);
		goto hisysevent_end;
	}
	write_len = hisysevent_write(event);
	if (write_len < 0) {
		echub_err("failed to write event, write_len=%d\n", write_len);
	}
 
hisysevent_end:
	hisysevent_destroy(&event);
}
#endif

#ifdef CONFIG_DKMD_DKSM
static int tcon_logo_notifier_call(struct notifier_block *nb,
	unsigned long action, void *data)
{
	int ret;
	u8 write_buf[] = {0x7A}; // post code
#ifdef CONFIG_HISYSEVENT
	if (g_awake_s3_info.start_time != 0 && action == DKMD_EVENT_BLANK) {
		get_current_time_ms(&g_awake_s3_info.end_time);
		echub_info("[%s]awake_s3 end time: %llu\n", __func__, g_awake_s3_info.end_time);
		if (g_awake_s3_info.end_time > g_awake_s3_info.start_time) {
			hiview_hisysevent_wakeuptime_event(AWAKE_TYPE_S3);
			hiview_hisysevent_s3_wakeup_event("LID_WAKEUP_START", "KERNEL_START_TIME", g_awake_s3_info.start_time);
			hiview_hisysevent_s3_wakeup_event("LID_WAKEUP_END", "KERNEL_END_TIME", g_awake_s3_info.end_time);
		}
		g_awake_s3_info.start_time = 0;
	}
#endif

	if (action != DKMD_EVENT_CLOSE_TCON_LOGO)
		return NOTIFY_OK;

	ret = g_ec_state_sync_di->echub_dev->transfer_func(g_ec_state_sync_di->echub_dev,
		EC_POST_CODE_CMD, write_buf, 1, NULL, 0);
	if (ret) {
		echub_err("failed to send logo end post code\n");
		return NOTIFY_OK;
	}
	echub_info("logo end, notify EC\n");
	return NOTIFY_OK;
}

static struct notifier_block tcon_logo_notifier_block = {
	.notifier_call = tcon_logo_notifier_call,
};
#endif

#ifdef CONFIG_POWERKEY_SPMI
static int powerkey_notifier_call(
	struct notifier_block *powerkey_nb, unsigned long event,
	void *data)
{
#ifdef CONFIG_HISYSEVENT
	if (event == PRESS_KEY_DOWN && g_awake_s3_info.start_time != 0) {
		get_current_time_ms(&g_awake_s3_info.start_time);
		echub_info("[%s]awake_s3 start time: %llu\n", __func__, g_awake_s3_info.start_time);
	}
#endif
	return 0;
}

static struct notifier_block powerkey_notifier_block = {
	.notifier_call = powerkey_notifier_call,
	.priority = 0,
};
#endif

#define ECHUB_SR_MIN_DELAY_MS 10
static unsigned long g_echub_suspend_time;
static unsigned long g_echub_pcie_ssd_power_on_time;
static unsigned long gettimeofday_ms(void)
{
	return dfx_getcurtime() / NSEC_PER_MSEC;
}

/**********************************************************
*  Function:       echub_gpio_init
*  Discription:    module probe
*  Parameters:     gpio_num
*  return value:   0-sucess or others-fail
**********************************************************/
static void echub_gpio_init(int gpio_num)
{
	gpio_request(gpio_num, "echub_suspend");
	gpio_direction_output(gpio_num, GPIO_OUT_HIGH);
}

static void echub_gpio_soc_ec_int_init(int gpio_num)
{
	gpio_request(gpio_num, "gpio_soc_ec_int");
	gpio_direction_output(gpio_num, GPIO_OUT_HIGH);
}

static void echub_gpio_s0_power_on_init(int gpio_num)
{
	gpio_request(gpio_num, "s0_power_on");
	gpio_direction_output(gpio_num, GPIO_OUT_HIGH);
}

static void echub_pcie_ssd_parse_time_config(struct device_node *np)
{
	int ret;
	unsigned size = 0x2;

	g_ec_state_sync_di->pcie_ssd_time_config_support = 0x0;
	if (of_property_read_bool(np, "pcie_ssd_time_config_support")) {
		g_ec_state_sync_di->pcie_ssd_time_config_support = 0x1;
		ret = of_property_read_u32_array(np, "t_ref2perst", g_ec_state_sync_di->t_ref2perst, size);
		if (ret != 0) {
			g_ec_state_sync_di->t_ref2perst[0] = 0x0;
			g_ec_state_sync_di->t_ref2perst[1] = 0x0;
			echub_info("get t_ref2perst failed, set default");
		}

		ret = of_property_read_u32_array(np, "t_perst2access", g_ec_state_sync_di->t_perst2access, size);
		if (ret != 0) {
			g_ec_state_sync_di->t_perst2access[0] = 0x0;
			g_ec_state_sync_di->t_perst2access[1] = 0x0;
			echub_info("get t_perst2access failed, set default");
		}

		ret = of_property_read_u32(np, "pcie_ssd_rc_idx", &g_ec_state_sync_di->pcie_ssd_rc_idx);
		if (ret)
			echub_info("get pcie_ssd_rc_idx failed\n");

		ret = of_property_read_u32(np, "pcie_ssd_reset_gpio", &g_ec_state_sync_di->pcie_ssd_reset_gpio);
		if (ret)
			echub_info("get pcie_ssd_reset_gpio failed\n");

		ret = of_property_read_u32(np, "pcie_ssd_poweron2perst_delay_ms",
			&g_ec_state_sync_di->pcie_ssd_poweron2perst_delay_ms);
		if (ret)
			echub_info("get pcie_ssd_poweron2perst_delay_ms failed\n");
	}
	return;
}


/**********************************************************
*  Function:       echub_syscore_suspend
*  Discription:    module suspend
*  Parameters:     void
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_syscore_suspend(void)
{
#ifdef CONFIG_HISYSEVENT
	g_awake_s3_info.start_time = 0;
#endif
	echub_info("%s, pm_suspend_state = 0x%x\n", __func__, g_echub_pm_suspend_state);
	g_echub_suspend_time = gettimeofday_ms();
#ifdef CONFIG_ARMPC_ECHUB_LID_TEST
	g_sleep_count++;
	if (g_sleep_count > MAX_SLEEP_COUNT)
		g_sleep_count = 0;
#endif
	gpio_set_value(g_gpio_soc_ec_int, GPIO_OUT_LOW);
	cancel_delayed_work_sync(&g_ec_state_sync_di->rtc_timestamp_work);
	if (g_echub_pm_suspend_state == PM_STATE_SUSPEND_MEM) {
		#ifdef CONFIG_SYS_PM_ULSR
			if (!is_ulsr())
				gpio_set_value(g_gpio_num, GPIO_OUT_LOW);
		#else
			gpio_set_value(g_gpio_num, GPIO_OUT_LOW);
		#endif
		if (g_ec_state_sync_di->gpio_s0_power_on > 0)
			gpio_set_value(g_ec_state_sync_di->gpio_s0_power_on, GPIO_OUT_LOW);
	}
	return 0;
}

/**********************************************************
*  Function:       echub_syscore_resume
*  Discription:    module resume
*  Parameters:     void
*  return value:   0-sucess or others-fail
**********************************************************/
static void echub_syscore_resume(void)
{
	unsigned long resume_time, delta_ms;
#ifdef CONFIG_HISYSEVENT
    bool awake_s3 = (g_echub_pm_suspend_state == PM_STATE_SUSPEND_MEM);
#ifdef CONFIG_SYS_PM_ULSR
    awake_s3 &= (!is_ulsr());
#endif
	if (awake_s3) {
		get_current_time_ms(&g_awake_s3_info.start_time);
		echub_info("[%s]awake_s3 start time: %llu\n", __func__, g_awake_s3_info.start_time);
	}
#endif

	gpio_set_value(g_gpio_soc_ec_int, GPIO_OUT_HIGH);
	queue_delayed_work(system_power_efficient_wq, &g_ec_state_sync_di->rtc_timestamp_work,
		msecs_to_jiffies(MS_SECOND_TO_TENMIN));
	echub_info("%s, pm_suspend_state = 0x%x\n", __func__, g_echub_pm_suspend_state);
	/* ec limit: resume time - suspend time need > ECHUB_SR_MIN_DELAY_MS */
	resume_time = gettimeofday_ms();
	delta_ms = resume_time > g_echub_suspend_time ?
		   resume_time - g_echub_suspend_time : 0;
	if (delta_ms < ECHUB_SR_MIN_DELAY_MS)
		mdelay(ECHUB_SR_MIN_DELAY_MS - delta_ms);
	gpio_set_value(g_gpio_num, GPIO_OUT_HIGH);

	if (g_ec_state_sync_di->gpio_s0_power_on > 0 && g_echub_pm_suspend_state == PM_STATE_SUSPEND_MEM) {
		if (delta_ms == 0) {
			mdelay(g_ec_state_sync_di->gpio_s0_power_on_delay_ms);
		} else if (delta_ms < g_ec_state_sync_di->gpio_s0_power_on_delay_ms) {
			mdelay(g_ec_state_sync_di->gpio_s0_power_on_delay_ms - delta_ms);
		}

		gpio_set_value(g_ec_state_sync_di->gpio_s0_power_on, GPIO_OUT_HIGH);
		g_echub_pcie_ssd_power_on_time = gettimeofday_ms();
		echub_info("%s suspend_time = %lld, resume_time = %lld\n", __func__, g_echub_suspend_time, resume_time);
	}

#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		echub_info("state sync ulsr enable send ec rtc timestamp\n");
		schedule_delayed_work(&g_ec_state_sync_di->rtc_timestamp_work, msecs_to_jiffies(WAKERTC_DELAY_TIME));
	}
#endif
}

static struct syscore_ops echub_syscore_ops = {
	.suspend = echub_syscore_suspend,
	.resume  = echub_syscore_resume,
};

#ifdef CONFIG_SYS_PM_ULSR
static int ec_state_sync_pm_prepare(struct device *dev)
{
	int ret;
	u8 write_buf[] = {0xF5};

	if (!is_ulsr()) {
		return 0;
	}
	echub_info("%s\n", __func__);
	for (int i = 0; i < MAX_RETRY_CNT; i++) {
		ret = g_ec_state_sync_di->echub_dev->transfer_func(g_ec_state_sync_di->echub_dev,
			EC_POST_CODE_CMD, write_buf, 1, NULL, 0);
		if (!ret) {
			return 0;
		}
		echub_err("failed to send ULSR prepare post code 0xF5\n");
		mdelay(5); // delay 5ms retry
	}
	return -EINVAL;
}

static void ec_state_sync_pm_complete(struct device *dev)
{
	int ret;
	u8 write_buf[] = {0xF6};

	if (!is_ulsr()) {
		return;
	}
	echub_info("%s\n", __func__);
	for (int i = 0; i < MAX_RETRY_CNT; i++) {
	    ret = g_ec_state_sync_di->echub_dev->transfer_func(g_ec_state_sync_di->echub_dev,
		    EC_POST_CODE_CMD, write_buf, 1, NULL, 0);
	    if (!ret) {
		    return;
	    }
	    echub_err("failed to send ULSR complete post code 0xF6\n");
	    mdelay(5); // delay 5ms retry
	}
}
#endif

#ifdef CONFIG_PM
static int ec_state_sync_pm_suspend(struct device *dev)
{
	g_echub_pm_suspend_state = PM_STATE_SUSPEND_MEM;
	g_s3_wakeup_flag = false;
	return 0;
}

static int ec_state_sync_pm_freeze(struct device *dev)
{
	g_echub_pm_suspend_state = PM_STATE_SUSPEND_DISK;
	return 0;
}
#endif

#ifdef CONFIG_HISYSEVENT
static int ec_state_sync_pm_restore(struct device *dev)
{
	hiview_hisysevent_wakeuptime_event(AWAKE_TYPE_S4);
	return 0;
}

static int ec_state_sync_pm_resume(struct device *dev)
{
	g_s3_wakeup_flag = true;
#ifdef CONFIG_SYS_PM_ULSR
	if (is_ulsr()) {
		hiview_hisysevent_wakeuptime_event(AWAKE_TYPE_ULSR);
		g_s3_wakeup_flag = false;
	}
#endif
	return 0;
}
#endif

static const struct dev_pm_ops ec_state_sync_pm_ops = {
#ifdef CONFIG_PM
    .suspend = ec_state_sync_pm_suspend,
    .freeze = ec_state_sync_pm_freeze,
#endif
#ifdef CONFIG_SYS_PM_ULSR
    .prepare = ec_state_sync_pm_prepare,
    .complete = ec_state_sync_pm_complete,
#endif
#ifdef CONFIG_HISYSEVENT
	.restore = ec_state_sync_pm_restore,
	.resume = ec_state_sync_pm_resume,
#endif
};

/**********************************************************
*  Function:       ec_state_parse_dts
*  Discription:    parse the module dts config value
*  Parameters:     np:device_node
*                  di:ec_state_sync_info
*  return value:   0-sucess or others-fail
**********************************************************/
static int ec_state_parse_dts(struct device_node *np, struct ec_state_sync_info *di)
{
	int ret;

	ret = of_property_read_u32(np, "gpio_sync", (u32 *)&di->gpio_sync);
	if (ret) {
		echub_err("get gpio_sync failed\n");
		return -EINVAL;
	}
	g_gpio_num = di->gpio_sync;
	echub_info("gpio_sync = %d\n", di->gpio_sync);

	ret = of_property_read_u32(np, "gpio_soc_ec_int", (u32 *)&g_gpio_soc_ec_int);
	if (ret)
		echub_info("get gpio_soc_ec_int failed\n");

	ret = of_property_read_u32(np, "gpio_s0_power_on", (u32 *)&di->gpio_s0_power_on);
	if (ret)
		echub_info("get s0_power_on failed\n");

	ret = of_property_read_u32(np, "gpio_s0_power_on_delay_ms", (u32 *)&di->gpio_s0_power_on_delay_ms);
	if (ret)
		echub_info("get gpio_s0_power_on_delay_ms failed\n");

	return 0;
}

#ifdef CONFIG_HIPCIE_OCT
static int pcie_ssd_device_power_on(void *data)
{
	int ret;
	unsigned long current_time, delta_ms;

	echub_info("%s ++", __func__);
	if (g_echub_pm_suspend_state == PM_STATE_SUSPEND_MEM) {
		if (g_ec_state_sync_di->gpio_s0_power_on > 0) {
			current_time = gettimeofday_ms();
			delta_ms = current_time > g_echub_pcie_ssd_power_on_time ? current_time - g_echub_pcie_ssd_power_on_time : 0;
			echub_info("%s pcie_ssd_power_on_time = %lld, current_time = %lld \n",
				__func__, g_echub_pcie_ssd_power_on_time, current_time);
			if (delta_ms > 0 && delta_ms < g_ec_state_sync_di->pcie_ssd_poweron2perst_delay_ms)
				mdelay(g_ec_state_sync_di->pcie_ssd_poweron2perst_delay_ms - delta_ms);
		}
	}

	usleep_range(g_ec_state_sync_di->t_ref2perst[0], g_ec_state_sync_di->t_ref2perst[1]);
	ret = gpio_direction_output(g_ec_state_sync_di->pcie_ssd_reset_gpio, GPIO_OUT_HIGH);
	usleep_range(g_ec_state_sync_di->t_perst2access[0], g_ec_state_sync_di->t_perst2access[1]);
	return ret;
}

static int pcie_ssd_device_power_off(void *data)
{
	return gpio_direction_output(g_ec_state_sync_di->pcie_ssd_reset_gpio, GPIO_OUT_LOW);
}
#endif

static void echub_set_ec_timestamp_work(struct work_struct *work)
{
	int ret;
	int i;
	struct timespec64 now;
	unsigned char time_stamp[TIMESTAMP_LEN] = {0};

	if (work == NULL) {
		echub_err("[%s:%dL] work is NULL\n", __func__, __LINE__);
		return;
	}

	ktime_get_real_ts64(&now);

	if (now.tv_sec > INT_MAX) {
		echub_err("tv_sec > INT_MAX, tv_sec = %lld\n", now.tv_sec);
		return;
	}
	queue_delayed_work(system_power_efficient_wq, &g_ec_state_sync_di->rtc_timestamp_work,
		msecs_to_jiffies(MS_SECOND_TO_TENMIN));
	for (i = 0; i < MAX_RETRY_CNT; i++) {
		time_stamp[0] = now.tv_sec & 0xFF; // BYTE 0
		time_stamp[1] = (now.tv_sec >> SHIFT_OFFSET_1_BYTE) & 0xFF; // BYTE 1
		time_stamp[2] = (now.tv_sec >> SHIFT_OFFSET_2_BYTE) & 0xFF; // BYTE 2
		time_stamp[3] = (now.tv_sec >> SHIFT_OFFSET_3_BYTE) & 0xFF; // BYTE 3
		ret = g_ec_state_sync_di->echub_dev->transfer_func(g_ec_state_sync_di->echub_dev, EC_I2C_TIMESTAMP_CMD,
			time_stamp, TIMESTAMP_LEN, NULL, 0x0);
		if (!ret)
			return;
		echub_err("i2c write 0x%x fail, retry %d/3\n", EC_I2C_TIMESTAMP_CMD, i + 1);
	}
}

static void state_sync_probe_config(struct device_node *np, struct ec_state_sync_info *di)
{
	echub_pcie_ssd_parse_time_config(np);
	echub_gpio_init(di->gpio_sync);
	echub_gpio_soc_ec_int_init(g_gpio_soc_ec_int);
	echub_gpio_s0_power_on_init(di->gpio_s0_power_on);
	register_syscore_ops(&echub_syscore_ops);
	INIT_DELAYED_WORK(&di->rtc_timestamp_work, echub_set_ec_timestamp_work);
	queue_delayed_work(system_power_efficient_wq, &di->rtc_timestamp_work,
		msecs_to_jiffies(MS_SECOND_TO_TENMIN));
#ifdef CONFIG_DKMD_DKSM
	dkmd_register_client(&tcon_logo_notifier_block);
#endif
#ifdef CONFIG_POWERKEY_SPMI
    powerkey_register_notifier(&powerkey_notifier_block);
#endif
}

static ssize_t s3_wakeup_flag_show(struct device *dev,
                              struct device_attribute *attr, char *buf)
{
	return sprintf_s(buf, PAGE_SIZE, "%d", g_s3_wakeup_flag);
}

static ssize_t s3_wakeup_flag_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count)
{
	u8 wb = 0;
	if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("%s incorrect format\n", __func__);
		return -1;
    }
	g_s3_wakeup_flag = wb;
	return count;
}

static DEVICE_ATTR(s3_wakeup, 0660, s3_wakeup_flag_show, s3_wakeup_flag_store);
static const struct attribute *s3_wakeup_attrs[] = {
    &dev_attr_s3_wakeup.attr,
    NULL
};

/**********************************************************
*  Function:       ec_state_sync_probe
*  Discription:    module probe
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int ec_state_sync_probe(struct platform_device *pdev)
{
	struct ec_state_sync_info *di;
	int ret = 0;
	struct device_node *np = NULL;
	struct echub_i2c_dev *echub_dev = NULL;

	if (!pdev || !pdev->dev.parent || !pdev->dev.of_node) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (di == NULL)
		return -ENOMEM;

	di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
	np = di->dev->of_node;
	platform_set_drvdata(pdev, di);

	g_ec_state_sync_di = di;
	if (sysfs_create_files(&di->dev->kobj, s3_wakeup_attrs))
		echub_err("create S3 wakeup node failed\n");

	ret = ec_state_parse_dts(np, di);
	if (ret < 0) {
		echub_err("ec_state_sync_info get data from dts fail!\n");
		goto err_state;
	}
	state_sync_probe_config(np, di);
#ifdef CONFIG_HIPCIE_OCT
	if (g_ec_state_sync_di->pcie_ssd_time_config_support) {
		ret = pcie_notify_pwr_register(g_ec_state_sync_di->pcie_ssd_rc_idx, 0,
			pcie_ssd_device_power_on, pcie_ssd_device_power_off, NULL);
		if (ret != 0)
			echub_info("%s pcie_kport_power_notifiy_register fail!\n", __func__);
	}
#endif
	echub_info("%s ok!\n", __func__);
	return 0;
err_state:
	platform_set_drvdata(pdev, NULL);
	kfree(di);
	di = NULL;
	return ret;
}

/**********************************************************
*  Function:       ec_state_sync_remove
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int ec_state_sync_remove(struct platform_device *pdev)
{
	struct ec_state_sync_info *di = NULL;

	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	di = platform_get_drvdata(pdev);
	if (di == NULL) {
		echub_err("[%s]di is NULL!\n", __func__);
		return -ENODEV;
	}
#ifdef CONFIG_DKMD_DKSM
	dkmd_unregister_client(&tcon_logo_notifier_block);
#endif
	cancel_delayed_work_sync(&g_ec_state_sync_di->rtc_timestamp_work);
	platform_set_drvdata(pdev, NULL);
	kfree(di);
	di = NULL;

	return 0;
}

static struct of_device_id ec_state_sync_match_table[] = {
	{
		.compatible = "huawei,ec_state_sync",
		.data = NULL,
	},
	{
	},
};
static struct platform_driver ec_state_sync_driver = {
	.probe        = ec_state_sync_probe,
	.remove       = ec_state_sync_remove,
	.driver       = {
		.name           = "huawei,ec_state_sync",
		.owner          = THIS_MODULE,
		.pm = &ec_state_sync_pm_ops,
		.of_match_table = of_match_ptr(ec_state_sync_match_table),
	},
};

/**********************************************************
*  Function:       ec_state_sync_init
*  Discription:    module initialization
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
int __init ec_state_sync_init(void)
{
	echub_info("%s\n", __func__);
	return platform_driver_register(&ec_state_sync_driver);
}

/**********************************************************
*  Function:       ec_state_sync_exit
*  Discription:    module exit
*  Parameters:     NULL
*  return value:   NULL
**********************************************************/
void __exit ec_state_sync_exit(void)
{
	platform_driver_unregister(&ec_state_sync_driver);
}

module_init(ec_state_sync_init);
module_exit(ec_state_sync_exit);

MODULE_AUTHOR("ARMPC");
MODULE_DESCRIPTION("ec state sync module driver");
MODULE_LICENSE("GPL");
