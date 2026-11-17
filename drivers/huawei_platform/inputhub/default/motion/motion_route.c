/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: motion route source file
 * Author: linjianpeng <linjianpeng1@huawei.com>
 * Create: 2020-05-25
 */

#include "motion_route.h"

#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/types.h>

#include <huawei_platform/inputhub/motionhub.h>

// Active cooling for qingyun
#ifdef CONFIG_THERMAL_GOV_AC_CTRL
#include <platform_include/cee/linux/active_thermal.h>
#endif
#ifdef CONFIG_HUAWEI_DSM
#include <log/hiview_hievent.h>
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
#include <dfx/hiview_hisysevent.h>
#endif
#include <securec.h>
#include "contexthub_recovery.h"
#include "contexthub_route.h"
#include "contexthub_pm.h"

#include "motion_channel.h"

#define SENSOR_FALL_IMONITOR_ID 936005010
#define MOTION_SF_PARA_LEN 16
#define MOTION_TYPE 0
#define MOTION_STATUS 2
#define SHAKE_RES_LENGTH 3
#define ACC_X_SHAKE_RESULT    0x1
#define ACC_Y_SHAKE_RESULT    0x4
#define ACC_Z_SHAKE_RESULT    0x8
#define SHAKE_RESULT_MAX      100

static bool g_wireless_case_status = false;

static int motion_rcv_sf_info(unsigned long value)
{
	int ret;
	uint8_t app_config[MOTION_SF_PARA_LEN] = { 0 };

	app_config[0] = MOTION_TYPE_BACK_TAP;
	app_config[1] = SUB_CMD_MOTION_RCV_STATUS_REQ;
	app_config[2] = (uint8_t)value;

	if ((get_iom3_state() == IOM3_ST_RECOVERY) ||
		(get_iomcu_power_state() == ST_SLEEP))
		ret = send_app_config_cmd(TAG_MOTION, app_config, false);
	else
		ret = send_app_config_cmd(TAG_MOTION, app_config, true);

	if (ret) {
		hwlog_err("send motion %d cfg data to mcu fail,ret=%d\n",
			(int)app_config[0], ret);
		return RET_FAIL;
	}
	hwlog_info("write motion success. sf_rcv_info:%d\n", (int)app_config[2]);
	return RET_SUCC;
}
int send_motion_type_switch(unsigned long type, unsigned long cmd)
{
	int ret;
	uint8_t app_config[MOTION_SF_PARA_LEN] = { 0 };

	app_config[0] = (uint8_t)type;
	app_config[1] = (uint8_t)cmd;

	if ((get_iom3_state() == IOM3_ST_RECOVERY) ||
		(get_iomcu_power_state() == ST_SLEEP))
		ret = send_app_config_cmd(TAG_MOTION, app_config, false);
	else
		ret = send_app_config_cmd(TAG_MOTION, app_config, true);

	if (ret) {
		hwlog_err("send motion %d cfg data to mcu fail,ret=%d\n",
			(int)app_config[0], ret);
		return RET_FAIL;
	}
	hwlog_info("write motion success. motion_ctrl_type:%d %d\n", (int)app_config[0], (int)app_config[1]);
	return RET_SUCC;
}
void motion_speaker_status_change(unsigned long value)
{
	int ret;

	ret = motion_rcv_sf_info(value);
	if (ret)
		hwlog_info("motion_speaker_status_change fail. %d\n", ret);
}

void motion_finger_status_change(unsigned long value)
{
	int ret;

	ret = motion_rcv_sf_info(value);
	if (ret)
		hwlog_info("motion_finger_status_change fail. %d\n", ret);
}

#ifdef CONFIG_HUAWEI_DSM
static void motion_fall_down_report(const struct motion_fall_down_data *info)
{
	int ret;
	unsigned int ret_u = 0;
	struct hiview_hievent *hi_event = NULL;

	if (!info) {
		hwlog_err("%s info NULL\n", __func__);
		return;
	}

	hi_event = hiview_hievent_create(SENSOR_FALL_IMONITOR_ID);
	if (!hi_event) {
		hwlog_err("%s create hievent fail\n", __func__);
		return;
	}

	ret_u |= (unsigned int)hiview_hievent_put_integral(hi_event,
		"fall_status", info->fall_status);
	ret_u |= (unsigned int)hiview_hievent_put_integral(hi_event,
		"impact_force", info->impact_force);
	ret_u |= (unsigned int)hiview_hievent_put_integral(hi_event,
		"fall_height", info->fall_height);
	ret_u |= (unsigned int)hiview_hievent_put_integral(hi_event,
		"still_time", info->still_time);
	ret_u |= (unsigned int)hiview_hievent_put_integral(hi_event,
		"confidence", info->confidence);
	ret_u |= (unsigned int)hiview_hievent_put_integral(hi_event,
		"suspected_cnt", info->suspected_cnt);
	if (ret_u != 0)
		hwlog_err("%s put integral fail ret_put=%d\n", __func__,
			(int)ret_u);

	ret = hiview_hievent_report(hi_event);
	if (ret < 0)
		hwlog_err("%s report fail ret=%d\n", __func__, ret);

	hiview_hievent_destroy(hi_event);

	hwlog_info("%s fall_status=%d impact_force=%d fall_height=%d still_time=%d confidence=%d suspected_cnt=%d\n",
		__func__, info->fall_status, info->impact_force,
		info->fall_height, info->still_time,
		info->confidence, info->suspected_cnt);
}
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
static void motion_fall_down_report_ohos(const struct motion_fall_down_data *info)
{
	int ret;
	struct hiview_hisysevent *event = NULL;

	if (!info) {
		hwlog_err("%s info NULL\n", __func__);
		return;
	}

	event = hisysevent_create("SENSOR_DRV", "SENSOR_FALL_INFO", FAULT);
	if (!event) {
		hwlog_err("[sensorALG] %s hisysevent_create failed\n", __func__);
		return;
	}
	ret = hisysevent_put_integer(event, "FALL_STATUS", (long long)info->fall_status);
	ret = hisysevent_put_integer(event, "STILL_TIME", (long long)info->still_time);
	ret = hisysevent_put_integer(event, "IMPACT_FORCE", (long long)info->impact_force);
	ret = hisysevent_put_integer(event, "FALL_HEIGHT", (long long)info->fall_height);
	ret = hisysevent_put_integer(event, "CONFIDENCE", (long long)info->confidence);
	ret = hisysevent_put_integer(event, "SUSPECTED_CNT", (long long)info->suspected_cnt);
	ret = hisysevent_write(event);
hisysevent_end:
	hisysevent_destroy(&event);
	hwlog_info("[sensorALG][motion_fall_down_report_ohos]fall down big data finish in ohos");
}
#endif

#define MOTION_SHAKE_PATH                   "/sys/bus/platform/drivers/huawei,camcfgdev/get_motion_data"
int write_buf_to_node(void *buf, u32 len)
{
	if (!buf) {
		hwlog_err("%s buf NULL\n", __func__);
		return -1;
	}
	int ret = 0;
	int flags;
	struct file *fp = NULL;
	mm_segment_t old_fs;
	char shake_temp_file[PATH_MAXLEN] = MOTION_SHAKE_PATH;

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	flags = O_CREAT | O_RDWR | O_TRUNC;
	fp = filp_open(shake_temp_file, flags, FILE_LIMIT);
	if (IS_ERR(fp)) {
		hwlog_err("%s():open file %s err, err=%d\n", __func__, shake_temp_file, PTR_ERR(fp));
		ret = -1;
		goto file_err;
	}

	ret = vfs_write(fp, buf, len, &(fp->f_pos));
	if (ret != len) {
		hwlog_err("%s:write file %s exception with ret %d\n",
			__func__, shake_temp_file, ret);
		ret = -1;
	}
	filp_close(fp, NULL);
file_err:
	set_fs(old_fs);
	return ret;
}

// Active cooling for qingyun
#ifdef CONFIG_THERMAL_GOV_AC_CTRL
#define MOTIONHUB_TYPE_SHAKE_AND_FLIP 45
#define FAN_DROP_EVENT 2
#define GYRO_X_DETECT 1
#define GYRO_Y_DETECT 2
#define GYRO_Z_DETECT 3

#define ACC_X_DETECT    4
#define ACC_Y_DETECT    5
#define ACC_Z_DETECT    6

static void motion_status_upload_to_fan(int8_t motion_type, int8_t motion_status)
{
	if (motion_type == MOTION_TYPE_FALL && motion_status == FAN_DROP_EVENT) {
		set_fan_context_type(FAN_CONTEXT_FALL);
		hwlog_info("%s : fall msg upload\n", __func__);
	}

	if (motion_type == MOTIONHUB_TYPE_SHAKE_AND_FLIP && motion_status > 0) {
		int res = motion_status;
		if ((((res >> ACC_X_DETECT) & 1) == 1) ||
			(((res >> ACC_Y_DETECT) & 1) == 1) ||
			(((res >> ACC_Z_DETECT) & 1) == 1))
			set_fan_context_type(FAN_CONTEXT_SHAKE);

		if ((((res >> GYRO_X_DETECT) & 1) == 1) ||
			(((res >> GYRO_Y_DETECT) & 1) == 1) ||
			(((res >> GYRO_Z_DETECT) & 1) == 1))
			set_fan_context_type(FAN_CONTEXT_FLIP);
		hwlog_info("%s : flip msg upload, data = %d\n", __func__, motion_status);
	}
}
#endif

static void motion_shake_upload_to_camera(int8_t motion_type, int8_t motion_status)
{
	char shake_res[SHAKE_RES_LENGTH];
	int shake_result = motion_status;
	hwlog_info("%s : shake msg upload to camera motion_status = %d\n", __func__, shake_result);
	if (shake_result < SHAKE_RESULT_MAX &&
		((shake_result & ACC_X_SHAKE_RESULT) == ACC_X_SHAKE_RESULT ||
		(shake_result & ACC_Y_SHAKE_RESULT) == ACC_Y_SHAKE_RESULT ||
		(shake_result & ACC_Z_SHAKE_RESULT) == ACC_Z_SHAKE_RESULT)) {
		hwlog_info("%s : shake msg upload to camera success\n", __func__);
		sprintf_s(shake_res, sizeof(shake_res), "%d", shake_result);
		write_buf_to_node(shake_res, strlen(shake_res) + 1);
	}
}

// bit0 is for camera X axis shake
// bit1 is for framework shake (x axis slight shake)
// bit2 is for camera Y axis shake
// bit3 is for camera Z axis shake
int inputhub_process_motion_report(const struct pkt_header *head)
{
	if (!head) {
		hwlog_err("%s: head NULL\n", __func__);
		return -1;
	}
	if (head->length + sizeof(struct pkt_header) != sizeof(pkt_motion_receive_data_t)) {
		hwlog_err("%s : motion msg len is err, len = %d\n", __func__, head->length);
		return -1;
	}

	pkt_motion_receive_data_t *motion_buf = (pkt_motion_receive_data_t *)head;
	int8_t motion_type = motion_buf->mt.motion_type;
	uint8_t motion_result = motion_buf->mt.motion_result;
	int8_t motion_status = motion_buf->mt.motion_status;

	char *motion_data = (char *)head + sizeof(pkt_common_data_t);
	int shake_state = get_shake_state_signs();
	int camera_flag = (shake_state >> 1) & 1;
	int framework_flag = shake_state & 1;

#ifdef CONFIG_THERMAL_GOV_AC_CTRL
	motion_status_upload_to_fan(motion_type, motion_status);
#endif

	if (motion_type == MOTIONHUB_TYPE_SHAKE && camera_flag) {
		motion_shake_upload_to_camera(motion_type, motion_status);
	}

	if (motion_type == MOTIONHUB_TYPE_SHAKE &&
		(framework_flag == false || (((motion_status >> 1) & 0x1) != 1))) {
		hwlog_info("%s : shake msg no upload to framework motion_status = %d\n", __func__, motion_status);
		return 0;
	}

	if ((motion_type == MOTIONHUB_TYPE_TAKE_OFF) || (motion_type == MOTIONHUB_TYPE_PICKUP) ||
		(motion_type == MOTION_TYPE_REMOVE) || (motion_type == MOTIONHUB_TYPE_MISTOUCH_GUARD_IN_CALL)) {
		inputhub_route_pm_wakeup_event(jiffies_to_msecs(HZ));
		hwlog_err("%s weaklock HZ motiontype=%d\n", __func__, motion_type);
	}

	if ((int)motion_type == MOTIONHUB_TYPE_COVER)
		g_wireless_case_status = ((int)motion_result == COVER_ON) ? true : false;

	hwlog_info("%s : motiontype = %d motion_result = %d motion_status = %d\n",
		__func__, motion_type, motion_result, motion_status);

	return inputhub_route_write(ROUTE_MOTION_PORT, motion_data,
		head->length - (sizeof(pkt_common_data_t) - sizeof(struct pkt_header)));
}

bool is_motion_data_report(const struct pkt_header *head)
{
	/* all sensors report data with command CMD_PRIVATE */
	return (head->tag == TAG_MOTION) && (head->cmd == CMD_DATA_REQ);
}

bool inputhub_get_wireless_case_status(void)
{
	return g_wireless_case_status;
}

void process_step_counter_report(const struct pkt_header *head)
{
	uint16_t cnt;

	inputhub_route_pm_wakeup_event(jiffies_to_msecs(HZ));

	cnt = ((struct pkt_step_counter_motion_req *)head)->data_hd.cnt;
	if (cnt == 1) {
		struct pkt_motion_data *mt = NULL;

		hwlog_info("Kernel get pedometer motion\n");
		mt = &(((struct pkt_step_counter_motion_req *)head)->mt);
#ifdef CONFIG_HUAWEI_DSM
		if (mt->motion_type == MOTION_TYPE_FALL_DOWN)
			motion_fall_down_report(
		 		(const struct motion_fall_down_data *)mt->data);
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
		if (mt->motion_type == MOTION_TYPE_FALL_DOWN)
			motion_fall_down_report_ohos(
				(const struct motion_fall_down_data *)mt->data);
#endif
		return;
	}

	if (cnt == 0)
		hwlog_info("Kernel get pedometer event\n");
	else
		hwlog_info("Kernel get pedometer event cnt=%u\n", cnt);

	step_counter_data_process((pkt_step_counter_data_req_t *)head);
	report_sensor_event(head->tag,
		(int *)(&((pkt_step_counter_data_req_t *) head)->step_count),
		head->length);
}

