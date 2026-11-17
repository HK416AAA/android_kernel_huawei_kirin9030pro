// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_protocol_ufcs_base.c
 *
 * reverse ufcs protocol base function
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

#include "reverse_protocol_ufcs_base.h"
#include "reverse_protocol_ufcs_interface.h"
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG rvs_ufcs_protocol
HWLOG_REGIST();

static struct mutex g_msg_number_lock;
static u8 g_msg_number;

static const char * const g_hwufcs_ctl_msg_table[HWUFCS_CTL_MSG_END] = {
	[HWUFCS_CTL_MSG_PING] = "ping",
	[HWUFCS_CTL_MSG_ACK] = "ack",
	[HWUFCS_CTL_MSG_NCK] = "nck",
	[HWUFCS_CTL_MSG_ACCEPT] = "accept",
	[HWUFCS_CTL_MSG_SOFT_RESET] = "soft_reset",
	[HWUFCS_CTL_MSG_POWER_READY] = "power_ready",
	[HWUFCS_CTL_MSG_GET_OUTPUT_CAPABILITIES] = "get_output_capabilities",
	[HWUFCS_CTL_MSG_GET_SOURCE_INFO] = "get_source_info",
	[HWUFCS_CTL_MSG_GET_SINK_INFO] = "get_sink_info",
	[HWUFCS_CTL_MSG_GET_CABLE_INFO] = "get_cable_info",
	[HWUFCS_CTL_MSG_GET_DEVICE_INFO] = "get_device_info",
	[HWUFCS_CTL_MSG_GET_ERROR_INFO] = "get_error_info",
	[HWUFCS_CTL_MSG_DETECT_CABLE_INFO] = "detect_cable_info",
	[HWUFCS_CTL_MSG_START_CABLE_DETECT] = "start_cable_detect",
	[HWUFCS_CTL_MSG_END_CABLE_DETECT] = "end_cable_detect",
	[HWUFCS_CTL_MSG_EXIT_HWUFCS_MODE] = "exit_ufcs_mode",
};

static const char * const g_hwufcs_data_msg_table[HWUFCS_DATA_MSG_END] = {
	[HWUFCS_DATA_MSG_OUTPUT_CAPABILITIES] = "output_capabilities",
	[HWUFCS_DATA_MSG_REQUEST] = "request",
	[HWUFCS_DATA_MSG_SOURCE_INFO] = "source_info",
	[HWUFCS_DATA_MSG_SINK_INFO] = "sink_info",
	[HWUFCS_DATA_MSG_CABLE_INFO] = "cable_info",
	[HWUFCS_DATA_MSG_DEVICE_INFO] = "device_info",
	[HWUFCS_DATA_MSG_ERROR_INFO] = "error_info",
	[HWUFCS_DATA_MSG_CONFIG_WATCHDOG] = "config_watchdog",
	[HWUFCS_DATA_MSG_REFUSE] = "refuse",
	[HWUFCS_DATA_MSG_VERIFY_REQUEST] = "verify_request",
	[HWUFCS_DATA_MSG_VERIFY_RESPONSE] = "verify_response",
	[HWUFCS_DATA_MSG_POWER_CHANGE] = "power_change",
	[HWUFCS_DATA_MSG_TEST_REQUEST] = "test_request",
};

static const char *rvs_ufcs_get_ctl_msg_name(unsigned int msg)
{
	if ((msg >= HWUFCS_CTL_MSG_BEGIN) && (msg < HWUFCS_CTL_MSG_END))
		return g_hwufcs_ctl_msg_table[msg];

	return "illegal ctl_msg";
}

static const char *rvs_ufcs_get_data_msg_name(unsigned int msg)
{
	if ((msg >= HWUFCS_DATA_MSG_BEGIN) && (msg < HWUFCS_DATA_MSG_END))
		return g_hwufcs_data_msg_table[msg];

	return "illegal data_msg";
}

void rvs_ufcs_init_msg_number_lock(void)
{
	mutex_init(&g_msg_number_lock);
}

void rvs_ufcs_destroy_msg_number_lock(void)
{
	mutex_destroy(&g_msg_number_lock);
}

static u8 rvs_ufcs_get_msg_number(void)
{
	u8 msg_number;

	mutex_lock(&g_msg_number_lock);
	msg_number = g_msg_number;
	mutex_unlock(&g_msg_number_lock);
	return msg_number;
}

static void rvs_ufcs_set_msg_number(u8 msg_number)
{
	hwlog_info("old_msg_number=%u new_msg_number=%u\n",
		g_msg_number, msg_number);
	mutex_lock(&g_msg_number_lock);
	g_msg_number = (msg_number % HWUFCS_MSG_MAX_COUNTER);
	mutex_unlock(&g_msg_number_lock);
}

int rvs_ufcs_request_communication(bool flag)
{
	int ret = 0;
	int i;

	for (i = 0; i < HWUFCS_REQUEST_COMMUNICATION_RETRY; i++) {
		ret = rvs_ufcs_set_communicating_flag(flag);
		if (!ret)
			break;

		power_usleep(DT_USLEEP_10MS);
	}

	hwlog_info("request communication finish, ret=%d\n", ret);
	return ret;
}

static void rvs_ufcs_packet_head(struct hwufcs_package_data *pkt, u8 *buf)
{
	u16 data = 0;

	/* packet tx header data */
	data |= ((pkt->msg_type & HWUFCS_HDR_MASK_MSG_TYPE) <<
		HWUFCS_HDR_SHIFT_MSG_TYPE);
	data |= ((pkt->prot_version & HWUFCS_HDR_MASK_PROT_VERSION) <<
		HWUFCS_HDR_SHIFT_PROT_VERSION);
	data |= ((pkt->msg_number & HWUFCS_HDR_MASK_MSG_NUMBER) <<
		HWUFCS_HDR_SHIFT_MSG_NUMBER);
	data |= ((pkt->dev_address & HWUFCS_HDR_MASK_DEV_ADDRESS) <<
		HWUFCS_HDR_SHIFT_DEV_ADDRESS);

	/* fill tx header data */
	buf[HWUFCS_HDR_HEADER_H_OFFSET] = (data >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;
	buf[HWUFCS_HDR_HEADER_L_OFFSET] = (data >> 0) & POWER_MASK_BYTE;
}

static void rvs_ufcs_packet_ctrl_and_data_msg(struct hwufcs_package_data *pkt, u8 *buf)
{
	hwlog_info("type=%u ver=%u num=%u addr=%u cmd=0x%x len=%u\n",
		pkt->msg_type, pkt->prot_version, pkt->msg_number,
		pkt->dev_address, pkt->cmd, pkt->len);

	/* fill tx body data */
	buf[HWUFCS_CTRL_DATA_MSG_CMD_OFFSET] = pkt->cmd;
	buf[HWUFCS_CTRL_DATA_MSG_LEN_OFFSET] = pkt->len;
	if (pkt->len)
		(void)memcpy_s(&buf[HWUFCS_CTRL_DATA_MSG_DATA_OFFSET],
			HWUFCS_MSG_MAX_BUFFER_SIZE - HWUFCS_CTRL_DATA_MSG_DATA_OFFSET,
			pkt->data, pkt->len);
}

static void rvs_ufcs_packet_vendor_define_msg(struct hwufcs_package_data *pkt, u8 *buf)
{
	hwlog_info("type=%u ver=%u num=%u addr=%u vendor_id=0x%x len=%u\n",
		pkt->msg_type, pkt->prot_version, pkt->msg_number,
		pkt->dev_address, pkt->vender_id, pkt->len);

	/* fill tx body data */
	buf[HWUFCS_VD_MSG_VER_ID_H_OFFSET] = pkt->vender_id >> POWER_BITS_PER_BYTE;
	buf[HWUFCS_VD_MSG_VER_ID_L_OFFSET] = pkt->vender_id & POWER_MASK_BYTE;
	buf[HWUFCS_VD_MSG_MSG_LEN_OFFSET] = pkt->len;
	if (pkt->len)
		(void)memcpy_s(&buf[HWUFCS_VD_MSG_DATA_OFFSET],
			HWUFCS_MSG_MAX_BUFFER_SIZE - HWUFCS_VD_MSG_DATA_OFFSET, pkt->data, pkt->len);
}

static int rvs_ufcs_packet_tx_data(struct hwufcs_package_data *pkt, int pkt_len,
	u8 *buf, int buf_len)
{
	if (pkt_len > buf_len) {
		hwlog_err("length err, pkt_len=%d, buf_len=%d\n", pkt_len, buf_len);
		return -EINVAL;
	}

	rvs_ufcs_packet_head(pkt, buf);
	switch (pkt->msg_type) {
	case HWUFCS_MSG_TYPE_CONTROL:
	case HWUFCS_MSG_TYPE_DATA:
		rvs_ufcs_packet_ctrl_and_data_msg(pkt, buf);
		break;
	case HWUFCS_MSG_TYPE_VENDOR_DEFINED:
		rvs_ufcs_packet_vendor_define_msg(pkt, buf);
		break;
	default:
		hwlog_info("invalid msg_type=%d\n", pkt->msg_type);
		break;
	}

	return 0;
}

static void rvs_ufcs_unpacket_rx_header(struct hwufcs_package_data *pkt, u8 *buf)
{
	u16 data;

	/* unpacket rx header data */
	data = (buf[HWUFCS_HDR_HEADER_H_OFFSET] << POWER_BITS_PER_BYTE) |
		buf[HWUFCS_HDR_HEADER_L_OFFSET];
	pkt->msg_type = (data >> HWUFCS_HDR_SHIFT_MSG_TYPE) &
		HWUFCS_HDR_MASK_MSG_TYPE;
	pkt->prot_version = (data >> HWUFCS_HDR_SHIFT_PROT_VERSION) &
		HWUFCS_HDR_MASK_PROT_VERSION;
	pkt->msg_number = (data >> HWUFCS_HDR_SHIFT_MSG_NUMBER) &
		HWUFCS_HDR_MASK_MSG_NUMBER;
	pkt->dev_address = (data >> HWUFCS_HDR_SHIFT_DEV_ADDRESS) &
		HWUFCS_HDR_MASK_DEV_ADDRESS;
}

static void rvs_ufcs_unpacket_ctrl_and_data_msg(struct hwufcs_package_data *pkt, u8 *buf)
{
	/* get rx body data */
	pkt->cmd = buf[HWUFCS_CTRL_DATA_MSG_CMD_OFFSET];
	pkt->len = buf[HWUFCS_CTRL_DATA_MSG_LEN_OFFSET];
	if (pkt->len && (pkt->len <= HWUFCS_CTRL_DATA_MSG_MAX_BUF_SIZE))
		(void)memcpy_s(pkt->data, HWUFCS_MSG_MAX_BUFFER_SIZE,
			&buf[HWUFCS_CTRL_DATA_MSG_DATA_OFFSET], pkt->len);

	hwlog_info("type=%u ver=%u num=%u addr=%u cmd=0x%x len=%u\n",
		pkt->msg_type, pkt->prot_version, pkt->msg_number,
		pkt->dev_address, pkt->cmd, pkt->len);
}

static void rvs_ufcs_unpacket_vendor_define_msg(struct hwufcs_package_data *pkt, u8 *buf)
{
	u16 data;

	/* get rx body data */
	pkt->vender_id = (buf[HWUFCS_VD_MSG_VER_ID_H_OFFSET] << POWER_BITS_PER_BYTE) |
		buf[HWUFCS_VD_MSG_VER_ID_L_OFFSET];
	pkt->len = buf[HWUFCS_VD_MSG_MSG_LEN_OFFSET] - HWUFCS_VDR_HEADER_LEN;
	data = (buf[HWUFCS_VD_MSG_CMD_H_OFFSET] << POWER_BITS_PER_BYTE) |
		buf[HWUFCS_VD_MSG_CMD_L_OFFSET];
	pkt->cmd = (data >> HWUFCS_VDR_SHIFT_MSG_CMD) &
		HWUFCS_VDR_MASK_MSG_CMD;
	pkt->vdm_type = (data >> HWUFCS_VDR_SHIFT_MSG_CMD_TYPE) &
		HWUFCS_VDR_MASK_MSG_CMD_TYPE;
	if (pkt->len && (pkt->len <= HWUFCS_VD_MSG_MAX_BUF_SIZE))
		(void)memcpy_s(pkt->data, HWUFCS_MSG_MAX_BUFFER_SIZE,
			&buf[HWUFCS_VD_MSG_DATA_OFFSET + HWUFCS_VDR_HEADER_LEN], pkt->len);

	hwlog_info("type=%u ver=%u num=%u addr=%u vendor_id=0x%x vdm_type=0x%x cmd=0x%x len=%u\n",
		pkt->msg_type, pkt->prot_version, pkt->msg_number,
		pkt->dev_address, pkt->vender_id, pkt->vdm_type, pkt->cmd, pkt->len);
}

static int rvs_ufcs_unpacket_rx_data(struct hwufcs_package_data *pkt, u8 *buf, int buf_len)
{
	if (buf_len > sizeof(struct hwufcs_package_data)) {
		hwlog_err("length err, buf_len=%d\n", buf_len);
		return -EPERM;
	}

	rvs_ufcs_unpacket_rx_header(pkt, buf);
	switch (pkt->msg_type) {
	case HWUFCS_MSG_TYPE_CONTROL:
	case HWUFCS_MSG_TYPE_DATA:
		rvs_ufcs_unpacket_ctrl_and_data_msg(pkt, buf);
		break;
	case HWUFCS_MSG_TYPE_VENDOR_DEFINED:
		rvs_ufcs_unpacket_vendor_define_msg(pkt, buf);
		break;
	default:
		hwlog_info("invalid msg_type=%d\n", pkt->msg_type);
		break;
	}

	return 0;
}

static int rvs_ufcs_check_refuse_reason(u8 reason)
{
	int ret = HWUFCS_ERR_REFUSED_DATA;

	switch (reason) {
	case HWUFCS_REFUSE_REASON_NOT_IDENTIFY:
	case HWUFCS_REFUSE_REASON_NOT_SUPPORT:
		hwlog_info("refuse reason is not identify or unsupport\n");
		ret = HWUFCS_ERR_REFUSED_SUPPORT_DATA;
		break;
	default:
		break;
	}
	return ret;
}

static int rvs_ufcs_receive_refuse_data_msg(struct hwufcs_package_data *pkt)
{
	u32 data = 0;
	u32 tmp_data;
	u8 len = sizeof(u32);
	struct hwufcs_refuse_data p = {0};
	int ret;

	if (len != pkt->len) {
		hwlog_err("refuse length=%u,%u invalid\n", len, pkt->len);
		return HWUFCS_ERR_ILLEGAL_DATA;
	}

	ret = memcpy_s((u8 *)&data, sizeof(data), pkt->data, pkt->len);
	if (ret)
		return HWUFCS_ERR_REFUSED_DATA;

	tmp_data = cpu_to_be32(data);
	/* reason */
	p.reason = (tmp_data >> HWUFCS_REFUSE_SHIFT_REASON) &
		HWUFCS_REFUSE_MASK_REASON;
	/* command number */
	p.cmd_number = (tmp_data >> HWUFCS_REFUSE_SHIFT_CMD_NUMBER) &
		HWUFCS_REFUSE_MASK_CMD_NUMBER;
	/* message type */
	p.msg_type = (tmp_data >> HWUFCS_REFUSE_SHIFT_MSG_TYPE) &
		HWUFCS_REFUSE_MASK_MSG_TYPE;
	/* message number */
	p.msg_number = (tmp_data >> HWUFCS_REFUSE_SHIFT_MSG_NUMBER) &
		HWUFCS_REFUSE_MASK_MSG_NUMBER;

	hwlog_info("refuse=%lx %x %x %x %x\n", tmp_data,
		p.reason, p.cmd_number, p.msg_type, p.msg_number);
	return rvs_ufcs_check_refuse_reason(p.reason);
}

static int rvs_ufcs_handle_recevice_exception_msg(struct hwufcs_package_data *pkt)
{
	int ret = 0;

	hwlog_info("type=%d,cmd=0x%x\n", pkt->msg_type, pkt->cmd);
	if (pkt->msg_type != HWUFCS_MSG_TYPE_DATA)
		return HWUFCS_ERR_UNEXPECT_DATA;

	if (pkt->cmd == HWUFCS_DATA_MSG_REFUSE)
		ret = rvs_ufcs_receive_refuse_data_msg(pkt);

	return ret ? ret : HWUFCS_ERR_UNEXPECT_DATA;
}

static int rvs_ufcs_send_control_cmd(u8 prot_version, u8 msg_number, u8 cmd, u8 addr)
{
	struct hwufcs_package_data pkt = { 0 };
	u8 buf[HWUFCS_MSG_MAX_BUFFER_SIZE] = { 0 };
	u8 flag = HWUFCS_WAIT_SEND_PACKET_COMPLETE | HWUFCS_ACK_RECEIVE_TIMEOUT;
	int len = HWUFCS_HDR_HEADER_LEN + HWUFCS_MSG_CMD_LEN;
	int ret;

	pkt.msg_type = HWUFCS_MSG_TYPE_CONTROL;
	pkt.prot_version = prot_version;
	pkt.msg_number = msg_number;
	pkt.dev_address = addr;
	pkt.cmd = cmd;
	pkt.len = 0;

	hwlog_info("send ctrl msg=%s\n", rvs_ufcs_get_ctl_msg_name(pkt.cmd));
	ret = rvs_ufcs_packet_tx_data(&pkt, len, buf, HWUFCS_MSG_MAX_BUFFER_SIZE);
	if (ret) {
		hwlog_err("packet control msg msg_number=%u cmd=%u fail\n",
			msg_number, cmd);
		return -EPERM;
	}

	ret = rvs_ufcs_write_msg(buf, len, flag);
	if (ret) {
		hwlog_err("send control msg msg_number=%u cmd=%u fail\n",
			msg_number, cmd);
		return -EPERM;
	}

	return 0;
}

static int rvs_ufcs_send_data_cmd(u8 msg_number, u8 cmd, u8 *data, u8 len)
{
	struct hwufcs_package_data pkt = { 0 };
	u8 buf[HWUFCS_MSG_MAX_BUFFER_SIZE] = { 0 };
	u8 flag = HWUFCS_WAIT_SEND_PACKET_COMPLETE | HWUFCS_ACK_RECEIVE_TIMEOUT;
	int ret;
	int len_all = HWUFCS_HDR_HEADER_LEN + HWUFCS_MSG_CMD_LEN +
		HWUFCS_MSG_LENGTH_LEN + len;

	if (len > HWUFCS_CTRL_DATA_MSG_MAX_BUF_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	pkt.msg_type = HWUFCS_MSG_TYPE_DATA;
	pkt.prot_version = HWUFCS_MSG_PROT_VERSION;
	pkt.msg_number = msg_number;
	pkt.dev_address = HWUFCS_DEV_ADDRESS_SINK;
	pkt.cmd = cmd;
	pkt.len = len;
	ret = memcpy_s(pkt.data, HWUFCS_MSG_MAX_BUFFER_SIZE, data, len);
	if (ret) {
		hwlog_err("%s memcpy_s failed\n", __func__);
		return -EINVAL;
	}

	hwlog_info("send data msg=%s\n", rvs_ufcs_get_data_msg_name(pkt.cmd));
	ret = rvs_ufcs_packet_tx_data(&pkt, len_all, buf, HWUFCS_MSG_MAX_BUFFER_SIZE);
	if (ret) {
		hwlog_err("packet data msg msg_number=%u cmd=%u fail\n",
			msg_number, cmd);
		return -EPERM;
	}

	ret = rvs_ufcs_write_msg(buf, len_all, flag);
	if (ret) {
		hwlog_err("send data msg msg_number=%u cmd=%u fail\n",
			msg_number, cmd);
		return -EPERM;
	}

	return 0;
}

static int rvs_ufcs_send_vdm_control_cmd(u8 prot_version, u8 msg_number, u8 *data, u8 len, u8 addr)
{
	struct hwufcs_package_data pkt = { 0 };
	u8 buf[HWUFCS_MSG_MAX_BUFFER_SIZE] = { 0 };
	u8 flag = HWUFCS_WAIT_SEND_PACKET_COMPLETE | HWUFCS_ACK_RECEIVE_TIMEOUT;
	int ret;
	int len_all = HWUFCS_HDR_HEADER_LEN + HWUFCS_MSG_VER_ID_LEN +
		HWUFCS_MSG_LENGTH_LEN + len;

	if (len > HWUFCS_VD_MSG_MAX_BUF_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	pkt.msg_type = HWUFCS_MSG_TYPE_VENDOR_DEFINED;
	pkt.prot_version = prot_version;
	pkt.msg_number = msg_number;
	pkt.dev_address = HWUFCS_DEV_ADDRESS_SINK;
	pkt.vender_id = HWUFCS_MSG_VERSION_ID;
	pkt.len = len;
	ret = memcpy_s(pkt.data, HWUFCS_MSG_MAX_BUFFER_SIZE, data, len);
	if (ret) {
		hwlog_err("%s memcpy_s failed\n", __func__);
		return -EINVAL;
	}

	ret = rvs_ufcs_packet_tx_data(&pkt, len_all, buf, HWUFCS_MSG_MAX_BUFFER_SIZE);
	if (ret) {
		hwlog_err("packet vendor defined msg msg_number=%u fail\n",
			msg_number);
		return -EPERM;
	}

	ret = rvs_ufcs_write_msg(buf, len_all, flag);
	if (ret) {
		hwlog_err("send vendor defined msg msg_number=%u fail\n",
			msg_number);
		return -EPERM;
	}

	return 0;
}

static int rvs_ufcs_check_vdm_msg_legality(u16 vendor_id, u8 vdm_type, u8 cmd)
{
	if (vendor_id != HWUFCS_MSG_VERSION_ID)
		return HWUFCS_ERR_UNSUPPORT_DATA;

	switch (vdm_type) {
	case HWUFCS_VDM_TYPE_CONTROL:
		if ((cmd >= HWUFCS_VDM_CTL_MSG_END) || (cmd < HWUFCS_VDM_CTL_MSG_BEGIN))
			return HWUFCS_ERR_UNSUPPORT_DATA;
		break;
	case HWUFCS_VDM_TYPE_DATA:
		if ((cmd >= HWUFCS_VDM_DATA_MSG_END) || (cmd < HWUFCS_VDM_DATA_MSG_BEGIN))
			return HWUFCS_ERR_UNSUPPORT_DATA;
		break;
	default:
		return HWUFCS_ERR_UNSUPPORT_DATA;
	}
	return 0;
}

static int rvs_ufcs_check_msg_legality(u8 type, u16 vendor_id, u8 vdm_type, u8 cmd)
{
	if ((type >= HWUFCS_MSG_TYPE_END) || (type < HWUFCS_MSG_TYPE_BEGIN))
		return HWUFCS_ERR_UNSUPPORT_DATA;

	switch (type) {
	case HWUFCS_MSG_TYPE_CONTROL:
		if ((cmd >= HWUFCS_CTL_MSG_END) || (cmd < HWUFCS_CTL_MSG_BEGIN))
			return HWUFCS_ERR_UNSUPPORT_DATA;
		break;
	case HWUFCS_MSG_TYPE_DATA:
		if ((cmd >= HWUFCS_DATA_MSG_END) || (cmd < HWUFCS_DATA_MSG_BEGIN))
			return HWUFCS_ERR_UNSUPPORT_DATA;
		break;
	case HWUFCS_MSG_TYPE_VENDOR_DEFINED:
		return rvs_ufcs_check_vdm_msg_legality(vendor_id, vdm_type, cmd);
	default:
		return HWUFCS_ERR_UNSUPPORT_DATA;
	}

	return 0;
}

int rvs_ufcs_receive_msg(struct hwufcs_package_data *pkt, bool need_wait_msg)
{
	u8 buf[HWUFCS_MSG_MAX_BUFFER_SIZE] = { 0 };
	u8 flag = HWUFCS_WAIT_CRC_ERROR | HWUFCS_WAIT_DATA_READY;
	u8 buf_len = 0;
	int ret;

	/* wait msg from rx */
	if (need_wait_msg && rvs_ufcs_wait_msg_ready(flag)) {
		hwlog_err("wait for msg time out\n");
		return HWUFCS_ERR_TIMEOUT;
	}

	ret = rvs_ufcs_get_rx_length(&buf_len);
	if (ret || !buf_len || (buf_len > HWUFCS_MSG_MAX_BUFFER_SIZE)) {
		hwlog_err("get data length err, len=%d,ret=%d\n", buf_len, ret);
		return HWUFCS_ERR_ILLEGAL_DATA;
	}

	hwlog_info("rx msg len=%d\n", buf_len);
	/* receive msg header from rx */
	ret = rvs_ufcs_read_msg(buf, buf_len);
	if (ret)
		return HWUFCS_ERR_ILLEGAL_DATA;

	ret = rvs_ufcs_end_read_msg();
	if (ret)
		return HWUFCS_ERR_UNKNOWN;

	ret = rvs_ufcs_unpacket_rx_data(pkt, buf, buf_len);
	if (ret)
		return HWUFCS_ERR_UNKNOWN;

	ret = rvs_ufcs_check_msg_legality(pkt->msg_type, pkt->vender_id, pkt->vdm_type, pkt->cmd);
	if (ret) {
		hwlog_err("receive_msg msg_type=%u vender_id=%u vdm_type=%u msg_cmd=%u illegal\n",
			pkt->msg_type, pkt->vender_id, pkt->vdm_type, pkt->cmd);
		return ret;
	}

	return 0;
}

int rvs_ufcs_receive_control_msg(u8 cmd, bool check_msg_num)
{
	int ret;
	struct hwufcs_package_data pkt = { 0 };
	u8 msg_number = rvs_ufcs_get_msg_number();

	if ((cmd == HWUFCS_CTL_MSG_ACK) && !rvs_ufcs_need_check_ack())
		return 0;

	ret = rvs_ufcs_receive_msg(&pkt, true);
	if (ret) {
		hwlog_err("receive msg err\n");
		return ret;
	}

	/* check control msg header */
	if (check_msg_num && (pkt.msg_number != msg_number)) {
		hwlog_err("msg_number=%u,%u invalid\n",
			pkt.msg_number, msg_number);
		return HWUFCS_ERR_UNKNOWN;
	}

	if ((pkt.msg_type != HWUFCS_MSG_TYPE_CONTROL) || (pkt.cmd != cmd)) {
		hwlog_err("receive_control_msg msg_type=%u cmd=%u unexpect\n", pkt.msg_type, pkt.cmd);
		return rvs_ufcs_handle_recevice_exception_msg(&pkt);
	}

	return 0;
}

static int rvs_ufcs_check_receive_data_msg(struct hwufcs_package_data *pkt, u8 expect_cmd)
{
	if ((pkt->msg_type != HWUFCS_MSG_TYPE_DATA) || (pkt->cmd != expect_cmd)) {
		hwlog_err("receive_data_msg msg_type=%u cmd=%u unexpect\n", pkt->msg_type, pkt->cmd);
		return rvs_ufcs_handle_recevice_exception_msg(pkt);
	}
	return 0;
}

static int rvs_ufcs_check_receive_vdm_data_msg(struct hwufcs_package_data *pkt, u8 expect_cmd)
{
	if ((pkt->vdm_type != HWUFCS_VDM_TYPE_DATA) || (pkt->cmd != expect_cmd)) {
		hwlog_err("receive_data_msg msg_type=%u cmd=%u unexpect\n", pkt->vdm_type, pkt->cmd);
		return rvs_ufcs_handle_recevice_exception_msg(pkt);
	}
	return 0;
}

int rvs_ufcs_send_control_msg(u8 cmd, bool ack)
{
	u8 msg_number = rvs_ufcs_get_msg_number();
	int ret;

	/* send control cmd to tx */
	ret = rvs_ufcs_send_control_cmd(HWUFCS_MSG_PROT_VERSION, msg_number, cmd, HWUFCS_DEV_ADDRESS_SINK);
	if (ret)
		return HWUFCS_ERR_UNKNOWN;

	if (!ack)
		goto end;

	/* wait ack from rx */
	ret = rvs_ufcs_receive_control_msg(HWUFCS_CTL_MSG_ACK, true);
	if (ret) {
		hwlog_err("wait for ack err,ret=%d\n", ret);
		return ret;
	}

end:
	rvs_ufcs_set_msg_number(++msg_number);
	return 0;
}

static int rvs_ufcs_send_data_msg(u8 cmd, u8 *data, u8 len, bool ack)
{
	u8 msg_number = rvs_ufcs_get_msg_number();
	int ret;

	/* send data cmd to tx */
	ret = rvs_ufcs_send_data_cmd(msg_number, cmd, data, len);
	if (ret)
		return HWUFCS_ERR_UNKNOWN;

	if (!ack)
		goto end;

	/* wait ack from rx */
	ret = rvs_ufcs_receive_control_msg(HWUFCS_CTL_MSG_ACK, true);
	if (ret) {
		hwlog_err("wait for ack err,ret=%d\n", ret);
		return ret;
	}

end:
	rvs_ufcs_set_msg_number(++msg_number);
	return 0;
}

int rvs_ufcs_send_vdm_control_msg(u8 cmd, bool ack)
{
	u8 msg_number = rvs_ufcs_get_msg_number();
	u16 data = 0;
	u16 tmp_data;
	int ret;

	data |= (u16)(cmd & HWUFCS_VDR_MASK_MSG_CMD) << HWUFCS_VDR_SHIFT_MSG_CMD;
	data |= (u16)(HWUFCS_VDM_TYPE_CONTROL & HWUFCS_VDR_MASK_MSG_CMD_TYPE) << HWUFCS_VDR_SHIFT_MSG_CMD_TYPE;
	tmp_data = be16_to_cpu(data);

	/* send control cmd to tx */
	ret = rvs_ufcs_send_vdm_control_cmd(HWUFCS_MSG_PROT_VERSION, msg_number, (u8 *)&tmp_data,
		HWUFCS_VDR_HEADER_LEN, HWUFCS_DEV_ADDRESS_SINK);
	if (ret)
		return HWUFCS_ERR_UNKNOWN;

	if (!ack)
		goto end;

	/* wait ack from rx */
	ret = rvs_ufcs_receive_control_msg(HWUFCS_CTL_MSG_ACK, true);
	if (ret) {
		hwlog_err("wait for ack err,ret=%d\n", ret);
		return ret;
	}

end:
	rvs_ufcs_set_msg_number(++msg_number);
	return 0;
}

/* data message from source to sink: 0x01 output_capabilities */
int rvs_ufcs_send_output_capabilities_data_msg(struct hwufcs_capabilities_data *p)
{
	u64 data = 0;
	u64 tmp_data;
	u8 len = sizeof(u64);

	data |= ((u64)((p->min_curr / HWUFCS_CAP_UNIT_CURR) &
		HWUFCS_CAP_MASK_MIN_CURR) << HWUFCS_CAP_SHIFT_MIN_CURR);
	data |= ((u64)((p->max_curr / HWUFCS_CAP_UNIT_CURR) &
		HWUFCS_CAP_MASK_MAX_CURR) << HWUFCS_CAP_SHIFT_MAX_CURR);
	data |= ((u64)((p->min_volt / HWUFCS_CAP_UNIT_VOLT) &
		HWUFCS_CAP_MASK_MIN_VOLT) << HWUFCS_CAP_SHIFT_MIN_VOLT);
	data |= ((u64)((p->max_volt / HWUFCS_CAP_UNIT_VOLT) &
		HWUFCS_CAP_MASK_MAX_VOLT) << HWUFCS_CAP_SHIFT_MAX_VOLT);
	data |= ((u64)((p->volt_step / HWUFCS_CAP_UNIT_VOLT - 1) &
		HWUFCS_CAP_MASK_VOLT_STEP) << HWUFCS_CAP_SHIFT_VOLT_STEP);
	data |= ((u64)((p->curr_step / HWUFCS_CAP_UNIT_CURR - 1) &
		HWUFCS_CAP_MASK_CURR_STEP) << HWUFCS_CAP_SHIFT_CURR_STEP);
	data |= ((u64)(p->output_mode & HWUFCS_CAP_MASK_OUTPUT_MODE) <<
		HWUFCS_CAP_SHIFT_OUTPUT_MODE);
	tmp_data = be64_to_cpu(data);

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_OUTPUT_CAPABILITIES,
		(u8 *)&tmp_data, len, true);
}

/* data message from source to sink: 0x03 source_information */
int rvs_ufcs_send_source_information_data_msg(struct hwufcs_source_info_data *p)
{
	u64 data = 0;
	u64 tmp_data;
	u8 len = sizeof(u64);

	data |= ((u64)((p->output_curr / HWUFCS_SOURCE_INFO_UNIT_CURR) &
		HWUFCS_SOURCE_INFO_MASK_OUTPUT_CURR) << HWUFCS_SOURCE_INFO_SHIFT_OUTPUT_CURR);
	data |= ((u64)((p->output_volt / HWUFCS_SOURCE_INFO_UNIT_VOLT) &
		HWUFCS_SOURCE_INFO_MASK_OUTPUT_VOLT) << HWUFCS_SOURCE_INFO_SHIFT_OUTPUT_VOLT);
	data |= ((u64)((p->port_temp + HWUFCS_SOURCE_INFO_TEMP_BASE) &
		HWUFCS_SOURCE_INFO_MASK_PORT_TEMP) << HWUFCS_SOURCE_INFO_SHIFT_PORT_TEMP);
	data |= ((u64)((p->dev_temp + HWUFCS_SOURCE_INFO_TEMP_BASE) &
		HWUFCS_SOURCE_INFO_MASK_DEV_TEMP) << HWUFCS_SOURCE_INFO_SHIFT_DEV_TEMP);
	tmp_data = be64_to_cpu(data);

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_SOURCE_INFO,
		(u8 *)&tmp_data, len, true);
}

/* data message from sink to source: 0x06 device_information */
int rvs_ufcs_send_device_information_data_msg(struct hwufcs_dev_info_data *p)
{
	u64 data = 0;
	u64 tmp_data;
	u8 len = sizeof(u64);

	data |= ((u64)(p->sw_ver & HWUFCS_DEV_INFO_MASK_SW_VER) <<
		HWUFCS_DEV_INFO_SHIFT_SW_VER);
	data |= ((u64)(p->hw_ver & HWUFCS_DEV_INFO_MASK_HW_VER) <<
		HWUFCS_DEV_INFO_SHIFT_HW_VER);
	data |= ((u64)(p->reserved_1 & HWUFCS_DEV_INFO_MASK_RESERVED_1) <<
		HWUFCS_DEV_INFO_SHIFT_RESERVED_1);
	data |= ((u64)(p->reserved_2 & HWUFCS_DEV_INFO_MASK_RESERVED_2) <<
		HWUFCS_DEV_INFO_SHIFT_RESERVED_2);
	tmp_data = be64_to_cpu(data);

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_DEVICE_INFO,
		(u8 *)&tmp_data, len, true);
}

/* data message from sink to source: 0x07 error_information */
int rvs_ufcs_send_error_information_data_msg(struct hwufcs_error_info_data *p)
{
	u32 data = 0;
	u32 tmp_data;
	u8 len = sizeof(u32);

	data |= ((u32)(p->output_ovp & HWUFCS_ERROR_INFO_MASK_OUTPUT_OVP) <<
		HWUFCS_ERROR_INFO_SHIFT_OUTPUT_OVP);
	data |= ((u32)(p->output_uvp & HWUFCS_ERROR_INFO_MASK_OUTPUT_UVP) <<
		HWUFCS_ERROR_INFO_SHIFT_OUTPUT_UVP);
	data |= ((u32)(p->output_ocp & HWUFCS_ERROR_INFO_MASK_OUTPUT_OCP) <<
		HWUFCS_ERROR_INFO_SHIFT_OUTPUT_OCP);
	data |= ((u32)(p->output_scp & HWUFCS_ERROR_INFO_MASK_OUTPUT_SCP) <<
		HWUFCS_ERROR_INFO_SHIFT_OUTPUT_SCP);
	data |= ((u32)(p->usb_otp & HWUFCS_ERROR_INFO_MASK_USB_OTP) <<
		HWUFCS_ERROR_INFO_SHIFT_USB_OTP);
	data |= ((u32)(p->device_otp & HWUFCS_ERROR_INFO_MASK_DEVICE_OTP) <<
		HWUFCS_ERROR_INFO_SHIFT_DEVICE_OTP);
	data |= ((u32)(p->cc_ovp & HWUFCS_ERROR_INFO_MASK_CC_OVP) <<
		HWUFCS_ERROR_INFO_SHIFT_CC_OVP);
	data |= ((u32)(p->dminus_ovp & HWUFCS_ERROR_INFO_MASK_DMINUS_OVP) <<
		HWUFCS_ERROR_INFO_SHIFT_DMINUS_OVP);
	data |= ((u32)(p->dplus_ovp & HWUFCS_ERROR_INFO_MASK_DPLUS_OVP) <<
		HWUFCS_ERROR_INFO_SHIFT_DPLUS_OVP);
	data |= ((u32)(p->input_ovp & HWUFCS_ERROR_INFO_MASK_INPUT_OVP) <<
		HWUFCS_ERROR_INFO_SHIFT_INPUT_OVP);
	data |= ((u32)(p->input_uvp & HWUFCS_ERROR_INFO_MASK_INPUT_UVP) <<
		HWUFCS_ERROR_INFO_SHIFT_INPUT_UVP);
	data |= ((u32)(p->over_leakage & HWUFCS_ERROR_INFO_MASK_OVER_LEAKAGE) <<
		HWUFCS_ERROR_INFO_SHIFT_OVER_LEAKAGE);
	data |= ((u32)(p->input_drop & HWUFCS_ERROR_INFO_MASK_INPUT_DROP) <<
		HWUFCS_ERROR_INFO_SHIFT_INPUT_DROP);
	data |= ((u32)(p->crc_error & HWUFCS_ERROR_INFO_MASK_CRC_ERROR) <<
		HWUFCS_ERROR_INFO_SHIFT_CRC_ERROR);
	data |= ((u32)(p->wtg_overflow & HWUFCS_ERROR_INFO_MASK_WTG_OVERFLOW) <<
		HWUFCS_ERROR_INFO_SHIFT_WTG_OVERFLOW);
	tmp_data = be32_to_cpu(data);

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_ERROR_INFO,
		(u8 *)&tmp_data, len, true);
}

/* data message from sink to source: 0x09 refuse */
int rvs_ufcs_send_refuse_data_msg(u8 reason, struct hwufcs_package_data *pkt)
{
	u32 data = 0;
	u32 tmp_data;
	u8 len = sizeof(u32);

	data |= ((u32)(reason & HWUFCS_REFUSE_MASK_REASON) <<
		HWUFCS_REFUSE_SHIFT_REASON);
	data |= ((u32)(pkt->cmd & HWUFCS_REFUSE_MASK_CMD_NUMBER) <<
		HWUFCS_REFUSE_SHIFT_CMD_NUMBER);
	data |= ((u32)(pkt->msg_type & HWUFCS_REFUSE_MASK_MSG_TYPE) <<
		HWUFCS_REFUSE_SHIFT_MSG_TYPE);
	data |= ((u32)(pkt->msg_number & HWUFCS_REFUSE_MASK_MSG_NUMBER) <<
		HWUFCS_REFUSE_SHIFT_MSG_NUMBER);
	tmp_data = be32_to_cpu(data);

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_REFUSE,
		(u8 *)&tmp_data, len, true);
}

/* data message from sink to source: 0x0b verify_response */
int rvs_ufcs_send_verify_response_data_msg(struct hwufcs_verify_response_data *p)
{
	u8 len = sizeof(struct hwufcs_verify_response_data);

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_VERIFY_RESPONSE,
		(u8 *)p, len, true);
}

/* data message from source to sink: 0x0C power_change */
int rvs_ufcs_send_power_change_data_msg(struct hwufcs_power_change_data *p)
{
	u8 data[HWUFCS_POWER_CHANGE_DATA_SIZE] = { 0 };

	data[2] = (p->max_curr / HWUFCS_POWER_CHANGE_UNIT_CURR) & POWER_MASK_BYTE;
	data[1] = (p->max_curr / HWUFCS_POWER_CHANGE_UNIT_CURR) >> POWER_BITS_PER_BYTE;
	data[0] = p->output_mode << POWER_DWORD_LEN;

	return rvs_ufcs_send_data_msg(HWUFCS_DATA_MSG_POWER_CHANGE,
		data, HWUFCS_POWER_CHANGE_DATA_SIZE, true);
}

void rvs_ufcs_handle_communication_result(int ret, struct hwufcs_package_data *pkt)
{
	if (ret == HWUFCS_ERR_ILLEGAL_DATA)
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_IDENTIFY, pkt);
	if (ret == HWUFCS_ERR_UNSUPPORT_DATA)
		rvs_ufcs_send_refuse_data_msg(HWUFCS_REFUSE_REASON_NOT_SUPPORT, pkt);
}

/* data message from source to sink: 0x06 device_information */
int rvs_ufcs_receive_dev_info_data_msg(struct hwufcs_dev_info_data *p)
{
	u64 data = 0;
	u64 tmp_data;
	u8 len = sizeof(u64);
	int ret;
	struct hwufcs_package_data pkt = { 0 };

	ret = rvs_ufcs_receive_msg(&pkt, true);
	if (ret) {
		hwlog_err("receive msg err\n");
		goto end;
	}

	/* check data msg */
	ret = rvs_ufcs_check_receive_data_msg(&pkt, HWUFCS_DATA_MSG_DEVICE_INFO);
	if (ret)
		goto end;

	if (pkt.len != len) {
		hwlog_err("receive_data_msg length=%u,%u invalid\n", pkt.len, len);
		ret =  HWUFCS_ERR_ILLEGAL_DATA;
		goto end;
	}

	ret = memcpy_s(&data, sizeof(data), pkt.data, pkt.len);
	if (ret) {
		hwlog_err("%s memcpy_s failed\n", __func__);
		goto end;
	}

	tmp_data = cpu_to_be64(data);
	/* software version */
	p->sw_ver = (tmp_data >> HWUFCS_DEV_INFO_SHIFT_SW_VER) &
		HWUFCS_DEV_INFO_MASK_SW_VER;
	/* hardware version */
	p->hw_ver = (tmp_data >> HWUFCS_DEV_INFO_SHIFT_HW_VER) &
		HWUFCS_DEV_INFO_MASK_HW_VER;
	/* reserved 1 */
	p->reserved_1 = (tmp_data >> HWUFCS_DEV_INFO_SHIFT_RESERVED_1) &
		HWUFCS_DEV_INFO_MASK_RESERVED_1;
	/* reserved 2 */
	p->reserved_2 = (tmp_data >> HWUFCS_DEV_INFO_SHIFT_RESERVED_2) &
		HWUFCS_DEV_INFO_MASK_RESERVED_2;

	hwlog_info("dev_info=%lx %x %x %x %x\n", tmp_data,
		p->sw_ver, p->hw_ver, p->reserved_1, p->reserved_2);
end:
	rvs_ufcs_handle_communication_result(ret, &pkt);
	return ret;
}
