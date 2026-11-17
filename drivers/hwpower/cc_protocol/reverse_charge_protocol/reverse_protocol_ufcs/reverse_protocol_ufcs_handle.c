// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_protocol_ufcs_handle.c
 *
 * reverse ufcs protocol irq event handle
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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

#include "reverse_protocol_ufcs_handle.h"
#include "reverse_protocol_ufcs_base.h"
#include "reverse_protocol_ufcs_interface.h"
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_temp.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_scp_auth.h>

#define HWLOG_TAG rvs_ufcs_protocol_handle
HWLOG_REGIST();

static struct hwufcs_source_info_data g_source_info;
static struct hwufcs_capabilities_data g_capabilities_data = {300, 4000, 5500, 11000, 20, 40, 1};
static struct hwufcs_request_data g_recvd_request_data;
static bool g_rvs_ufcs_encrypt_result;

void rvs_ufcs_handle_clear_request_data(void)
{
	g_recvd_request_data.output_curr = 0;
	g_recvd_request_data.output_volt = 0;
}

int rvs_ufcs_handle_set_source_info(int volt, int curr)
{
	g_source_info.output_curr = curr;
	g_source_info.output_volt = volt;
	return 0;
}

int rvs_ufcs_handle_get_request_curr(int *curr)
{
	if (!curr)
		return -EPERM;

	*curr = g_recvd_request_data.output_curr;
	return 0;
}

int rvs_ufcs_handle_get_request_volt(int *volt)
{
	if (!volt)
		return -EPERM;

	*volt = g_recvd_request_data.output_volt;
	return 0;
}

int rvs_ufcs_handle_set_power_curve(int max_curr, int max_volt)
{
	g_capabilities_data.max_curr = max_curr;
	g_capabilities_data.max_volt = max_volt + RVS_UFCS_MAX_VOLT_OFFSET;
	return 0;
}

static void rvs_ufcs_handle_ping(struct hwufcs_package_data *pkt)
{
	hwlog_info("handle ping msg\n");
}

static void rvs_ufcs_handle_soft_reset(struct hwufcs_package_data *pkt)
{
	hwlog_info("handle soft_reset msg\n");
}

static void rvs_ufcs_handle_get_output_capabilities(struct hwufcs_package_data *pkt)
{
	int ret;

	hwlog_info("handle get_output_capabilities msg\n");

	ret = rvs_ufcs_send_output_capabilities_data_msg(&g_capabilities_data);
	if (ret)
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
}

static void rvs_ufcs_handle_get_source_info(struct hwufcs_package_data *pkt)
{
	int ret;

	hwlog_info("handle get_source_info msg\n");
	g_source_info.dev_temp = power_temp_get_average_value(POWER_TEMP_RCHG) / POWER_MC_PER_C;
	g_source_info.port_temp = power_temp_get_average_value(POWER_TEMP_USB_PORT) / POWER_MC_PER_C;
	ret = rvs_ufcs_send_source_information_data_msg(&g_source_info);
	if (ret)
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
}

static void rvs_ufcs_handle_get_device_info(struct hwufcs_package_data *pkt)
{
	int ret;
	struct hwufcs_dev_info_data data = { 0 };

	hwlog_info("handle get_device_info msg\n");
	ret = rvs_ufcs_send_device_information_data_msg(&data);
	if (ret)
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
}

static void rvs_ufcs_handle_get_error_info(struct hwufcs_package_data *pkt)
{
	int ret;
	struct hwufcs_error_info_data data = { 0 };

	/* Used for test authentication, no error by default */
	hwlog_info("handle get_error_info msg\n");
	ret = rvs_ufcs_send_error_information_data_msg(&data);
	if (ret)
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
}

static void rvs_ufcs_handle_detect_cable_info(struct hwufcs_package_data *pkt)
{
	hwlog_info("handle detect_cable_info msg\n");
	(void)rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
}

static void rvs_ufcs_handle_start_cable_detect(struct hwufcs_package_data *pkt)
{
	hwlog_info("handle start_cable_detect msg\n");
	(void)rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
}

static void rvs_ufcs_handle_end_cable_detect(struct hwufcs_package_data *pkt)
{
	hwlog_info("handle end_cable_detect msg\n");
	(void)rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
}

static void rvs_ufcs_handle_exit_ufcs_mode(struct hwufcs_package_data *pkt)
{
	hwlog_info("handle exit_ufcs_mode msg\n");
	(void)rvs_ufcs_enable_rprot(false);
}

static void rvs_ufcs_handle_error_info(struct hwufcs_package_data *pkt)
{
	int len = 4; /* 4: error info data size */

	hwlog_info("handle error_info msg\n");
	if (pkt->len != len) {
		hwlog_err("receive_data_msg length=%u,%u invalid\n",
			pkt->len, len);
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_IDENTIFY, pkt);
		return;
	}

	hwlog_info("error_info msg=%u %u %u %u\n", pkt->data[0], pkt->data[1],
		pkt->data[2], pkt->data[3]);
}

static bool rvs_ufcs_check_request_data_legality(struct hwufcs_request_data *p)
{
	if ((p->output_volt <= g_capabilities_data.max_volt) &&
		(p->output_volt >= g_capabilities_data.min_volt) &&
		(p->output_curr <= g_capabilities_data.max_curr) &&
		(p->output_curr >= g_capabilities_data.min_curr))
		return true;

	return false;
}

/* data message from sink to source: 0x02 request */
static int rvs_ufcs_parse_request_data(struct hwufcs_request_data *p,
	struct hwufcs_package_data *pkt)
{
	u8 len = sizeof(u64);
	u64 data = 0;
	u64 tmp_data;
	int ret;

	if (pkt->len != len) {
		hwlog_err("receive_data_msg length=%u,%u invalid\n", pkt->len, len);
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
		return -EPERM;
	}

	ret = memcpy_s(&data, sizeof(data), pkt->data, pkt->len);
	if (ret) {
		hwlog_err("%s memcpy_s failed\n", __func__);
		return -ENOMEM;
	}

	tmp_data = cpu_to_be64(data);
	p->output_curr = (tmp_data >> HWUFCS_REQ_SHIFT_OUTPUT_CURR) &
		HWUFCS_REQ_MASK_OUTPUT_CURR;
	p->output_curr *= HWUFCS_REQ_UNIT_OUTPUT_CURR;
	p->output_volt = (tmp_data >> HWUFCS_REQ_SHIFT_OUTPUT_VOLT) &
		HWUFCS_REQ_MASK_OUTPUT_VOLT;
	p->output_volt *= HWUFCS_REQ_UNIT_OUTPUT_VOLT;
	p->output_mode = (tmp_data >> HWUFCS_REQ_SHIFT_OUTPUT_MODE) &
		HWUFCS_REQ_MASK_OUTPUT_MODE;
	hwlog_info("request data:output_curr=%dmA, output_volt=%dmV\n",
		p->output_curr, p->output_volt);
	return 0;
}

static void rvs_ufcs_handle_request(struct hwufcs_package_data *pkt)
{
	static struct hwufcs_request_data data;
	int ret;

	hwlog_info("handle request msg\n");

	ret = rvs_ufcs_parse_request_data(&data, pkt);
	if (ret)
		return;

	if (!rvs_ufcs_check_request_data_legality(&data)) {
		hwlog_info("request data exceeds output capabilities\n");
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
		return;
	}

	g_recvd_request_data = data;
	ret = rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_ACCEPT, true);
	if (ret) {
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
		return;
	}

	power_msleep(DT_MSLEEP_30MS, 0, NULL);
	ret = rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_POWER_READY, true);
	if (ret)
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
}

static void rvs_ufcs_handle_config_watchdog(struct hwufcs_package_data *pkt)
{
	u16 time;
	u8 len = sizeof(u16);
	u16 data = 0;
	u16 tmp_data;
	int ret;

	if (pkt->len != len) {
		hwlog_err("receive_data_msg length=%u,%u invalid\n", pkt->len, len);
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
		return;
	}
	hwlog_info("handle config watchdog msg\n");

	ret = memcpy_s((u8 *)&data, sizeof(data), pkt->data, pkt->len);
	if (ret)
		hwlog_err("%s memcpy_s failed\n", __func__);

	tmp_data = cpu_to_be16(data);
	time = (tmp_data >> HWUFCS_WTG_SHIFT_TIME) &
		HWUFCS_WTG_MASK_TIME;

	rvs_ufcs_config_watchdog(time);
	ret = rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_ACCEPT, true);
	if (ret)
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
}

static int rvs_ufcs_parse_verify_request_data(struct hwufcs_verify_request_data *p,
	struct hwufcs_package_data *pkt)
{
	u8 len = sizeof(struct hwufcs_verify_request_data);
	int ret;

	if (pkt->len != len) {
		hwlog_err("receive_data_msg length=%u,%u invalid\n", pkt->len, len);
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
		return -EPERM;
	}

	ret = memcpy_s((u8 *)p, len, pkt->data, pkt->len);
	if (ret)
		hwlog_err("%s memcpy_s failed\n", __func__);
	return ret;
}

int rvs_ufcs_auth_process(void)
{
	int ret;

	ret = rscp_auth_wait_completion();
	g_rvs_ufcs_encrypt_result = (ret == 0);
	hwlog_info("auth process end, ret=[%d]\n", g_rvs_ufcs_encrypt_result);

	return ret;
}

static int rvs_ufcs_prepare_random_data(struct hwufcs_verify_data *p)
{
	u8 *rscp_random = rscp_auth_get_hash_data_header();
	u8 rscp_random_len = rscp_auth_get_hash_data_size();
	int ret, i;

	if (!rscp_random || rscp_random_len != RSCP_AUTH_RANDOM_LEN)
		return -EINVAL;

	rscp_auth_clean_hash_data();

	ret = memcpy_s(rscp_random, rscp_random_len, p->req_data.random, HWUFCS_RANDOM_SIZE);
	if (ret)
		return ret;

	for (i = 0; i < HWUFCS_RANDOM_SIZE; i++)
		get_random_bytes(&rscp_random[HWUFCS_RANDOM_SIZE + i], sizeof(unsigned char));

	rscp_random[rscp_random_len - 1] = p->req_data.encrypt_index;

	ret = memcpy_s(p->rsp_data.random, HWUFCS_RANDOM_SIZE,
		&rscp_random[HWUFCS_RANDOM_SIZE], HWUFCS_RANDOM_SIZE);

	return ret;
}

static void rvs_ufcs_handle_verify_request(struct hwufcs_package_data *pkt)
{
	struct hwufcs_verify_data verify_data;
	struct hwufcs_dev_info_data dev_info;
	u8 *rscp_encrypt_value = NULL;
	int ret;

	hwlog_info("handle verify_request msg\n");

	ret = rvs_ufcs_parse_verify_request_data(&verify_data.req_data, pkt);
	if (ret)
		return;

	g_rvs_ufcs_encrypt_result = false;
	/* step 1: parse sink random num and generate source random num */
	ret = rvs_ufcs_prepare_random_data(&verify_data);
	if (ret) {
		hwlog_err("prepare random data fail\n");
		goto fail_encrypt;
	}

	/* step 2: notify bms service to calculate encrypt data */
	power_event_bnc_notify(POWER_BNT_REVERSE_SC, POWER_NE_BMS_REVERSE_AUTH_START, NULL);

	/* step 3: send accept msg */
	power_msleep(DT_MSLEEP_10MS, 0, NULL);
	ret = rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_ACCEPT, true);
	if (ret) {
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
		goto fail_encrypt;
	}

	/* step 4: send get devive info msg */
	power_msleep(DT_MSLEEP_20MS, 0, NULL);
	ret = rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_GET_DEVICE_INFO, true);
	if (ret) {
		rvs_ufcs_send_control_msg(HWUFCS_CTL_MSG_SOFT_RESET, true);
		goto fail_encrypt;
	}

	/* step 5: wait for devive info msg */
	ret = rvs_ufcs_receive_dev_info_data_msg(&dev_info);
	if (ret)
		goto fail_encrypt;

	power_msleep(DT_MSLEEP_10MS, 0, NULL);

	/* step 6: get encrypted value */
	if (!g_rvs_ufcs_encrypt_result) {
		hwlog_err("calculate encrypt data fail\n");
		goto fail_encrypt;
	}

	rscp_encrypt_value = rscp_auth_get_encrypted_value_header();
	if (!rscp_encrypt_value)
		goto fail_encrypt;

	ret = memcpy_s(verify_data.rsp_data.encrypt, HWUFCS_ENCRYPT_SIZE,
		rscp_encrypt_value, HWUFCS_ENCRYPT_SIZE);
	if (ret)
		goto fail_encrypt;

	/* step 7: send verify response msg */
	rvs_ufcs_send_verify_response_data_msg(&verify_data.rsp_data);

fail_encrypt:
	rscp_auth_clean_hash_data();
}

static void rvs_ufcs_handle_ctrl_msg(struct hwufcs_package_data *pkt)
{
	if (!pkt) {
		hwlog_err("msg is null\n");
		return;
	}

	switch (pkt->cmd) {
	case HWUFCS_CTL_MSG_PING:
		rvs_ufcs_handle_ping(pkt);
		break;
	case HWUFCS_CTL_MSG_SOFT_RESET:
		rvs_ufcs_handle_soft_reset(pkt);
		break;
	case HWUFCS_CTL_MSG_GET_OUTPUT_CAPABILITIES:
		rvs_ufcs_handle_get_output_capabilities(pkt);
		break;
	case HWUFCS_CTL_MSG_GET_SOURCE_INFO:
		rvs_ufcs_handle_get_source_info(pkt);
		break;
	case HWUFCS_CTL_MSG_GET_DEVICE_INFO:
		rvs_ufcs_handle_get_device_info(pkt);
		break;
	case HWUFCS_CTL_MSG_GET_ERROR_INFO:
		rvs_ufcs_handle_get_error_info(pkt);
		break;
	case HWUFCS_CTL_MSG_DETECT_CABLE_INFO:
		rvs_ufcs_handle_detect_cable_info(pkt);
		break;
	case HWUFCS_CTL_MSG_START_CABLE_DETECT:
		rvs_ufcs_handle_start_cable_detect(pkt);
		break;
	case HWUFCS_CTL_MSG_END_CABLE_DETECT:
		rvs_ufcs_handle_end_cable_detect(pkt);
		break;
	case HWUFCS_CTL_MSG_EXIT_HWUFCS_MODE:
		rvs_ufcs_handle_exit_ufcs_mode(pkt);
		break;
	default:
		hwlog_err("ctrl cmd invalid\n");
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
		break;
	}
}

static void rvs_ufcs_handle_data_msg(struct hwufcs_package_data *pkt)
{
	if (!pkt) {
		hwlog_err("msg is null\n");
		return;
	}

	switch (pkt->cmd) {
	case HWUFCS_DATA_MSG_REQUEST:
		rvs_ufcs_handle_request(pkt);
		break;
	case HWUFCS_DATA_MSG_ERROR_INFO:
		rvs_ufcs_handle_error_info(pkt);
		break;
	case HWUFCS_DATA_MSG_CONFIG_WATCHDOG:
		rvs_ufcs_handle_config_watchdog(pkt);
		break;
	case HWUFCS_DATA_MSG_VERIFY_REQUEST:
		rvs_ufcs_handle_verify_request(pkt);
		break;
	case HWUFCS_DATA_MSG_REFUSE:
		break;
	default:
		hwlog_err("data cmd invalid\n");
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
		break;
	}
}

void rvs_ufcs_handle_msg(void)
{
	struct hwufcs_package_data pkt = { 0 };
	int ret;

	ret = rvs_ufcs_request_communication(true);
	if (ret)
		return;

	ret = rvs_ufcs_receive_msg(&pkt, false);
	if (ret) {
		hwlog_err("receive msg err\n");
		rvs_ufcs_handle_communication_result(ret, &pkt);
		goto end;
	}

	switch (pkt.msg_type) {
	case HWUFCS_MSG_TYPE_CONTROL:
		rvs_ufcs_handle_ctrl_msg(&pkt);
		break;
	case HWUFCS_MSG_TYPE_DATA:
		rvs_ufcs_handle_data_msg(&pkt);
		break;
	default:
		hwlog_err("msg type invalid\n");
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, &pkt);
		break;
	}

end:
	rvs_ufcs_request_communication(false);
}
