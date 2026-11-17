// SPDX-License-Identifier: GPL-2.0+
/*
 * sc6605_ufcs.c
 *
 * sc6605 ufcs driver
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

#include "sc6605_ufcs.h"
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_log.h>

#define HWLOG_TAG sc6605_ufcs
HWLOG_REGIST();

static struct sc6605_ufcs_msg_head *g_sc6605_ufcs_msg_head = NULL;

static int sc6605_ufcs_field_write(struct sc6605_ufcs_device *di, enum sc6605_ufcs_fields field_id,
	uint8_t val)
{
	int ret;
	uint8_t reg_val = 0, tmp = 0;
	uint8_t mask = GENMASK(sc6605_ufcs_reg_fields[field_id].msb, sc6605_ufcs_reg_fields[field_id].lsb);

	ret = regmap_bulk_read(di->rmap, sc6605_ufcs_reg_fields[field_id].reg, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] read field %d fail: %d\n", __func__, field_id, ret);
		return ret;
	}

	tmp = reg_val & ~mask;
	val <<= sc6605_ufcs_reg_fields[field_id].lsb;
	tmp |= val  & mask;

	if (tmp != reg_val) {
		ret = regmap_bulk_write(di->rmap, sc6605_ufcs_reg_fields[field_id].reg, &tmp, REG_COUNT1);
		if (ret)
			hwlog_err("[%s] sc6605 ufcs write field %d fail: %d\n", __func__, field_id, ret);
	}

	return ret;
}

static int sc6605_ufcs_get_int_flag(struct sc6605_ufcs_device *di, uint32_t *flag)
{
	int ret;
	uint32_t reg_val = 0;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_UFCS_INT_FLAG1, (uint8_t *)&reg_val, REG_COUNT3);
	if (ret) {
		hwlog_err("[%s] get int flag failed\n", __func__);
		return ret;
	}

	hwlog_info("[%s] irqflag1:0x%x\n", __func__, reg_val);
	if ((reg_val & UFCS_INT_FLAG1_DATA) == UFCS_INT_FLAG1_DATA) {
		reg_val &= ~UFCS_INT_FLAG1_DATA;
		reg_val |= UFCS_INT_FLAG2_DATA;
	}

	*flag = reg_val;

	return 0;
}

static int sc6605_ufcs_detect_adapter_init(struct sc6605_ufcs_device *di)
{
	uint32_t flag = 0;
	uint8_t reg_val = 0;
	int ret;

	hwlog_info("[%s] enter\n", __func__);
	ret = regmap_bulk_read(di->rmap, SC6605_REG_DPDM_INT_MASK, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] read SC6605_REG_DPDM_INT_MASK failed\n", __func__);
		return ret;
	}

	reg_val &= ~UFCS_INIT_REG;
	ret = regmap_bulk_write(di->rmap, SC6605_REG_DPDM_INT_MASK, &reg_val, REG_COUNT1);
	if (ret) {
		hwlog_err("[%s] write SC6605_REG_DPDM_INT_MASK failed\n", __func__);
		return ret;
	}

	sc6605_ufcs_get_int_flag(di, &flag);
	ret = sc6605_ufcs_field_write(di, F_DPDM_EN, true);
	ret |= sc6605_ufcs_field_write(di, F_DM_DRIVE, DM_DRIVE_DATA);
	ret |= sc6605_ufcs_field_write(di, UFCS_EN, true);
	ret |= sc6605_ufcs_field_write(di, RX_CLEAR, true);
	/* set rx_handreset time is 2ms */
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_UFCS_OPTION2, &reg_val, REG_COUNT1);
	reg_val |= UFCS_OPTION2_DATA;
	ret |= regmap_bulk_write(di->rmap, SC6605_REG_UFCS_OPTION2, &reg_val, REG_COUNT1);
	/* disable check msg type */
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_UFCS_OPTION4, &reg_val, REG_COUNT1);
	reg_val &= ~SC6605_HK_RESET_MASK;
	ret |= regmap_bulk_write(di->rmap, SC6605_REG_UFCS_OPTION4, &reg_val, REG_COUNT1);
	if (ret)
		hwlog_err("[%s] ufcs_init failed\n", __func__);

	return ret;
}

static int sc6605_ufcs_deinit(struct sc6605_ufcs_device *di) 
{
	int ret;
	uint8_t reg_val = 0;

	ret = regmap_write(di->rmap, SC6605_REG_DPDM_NONSTD_STAT, false);
	ret |= regmap_write(di->rmap, SC6605_REG_DPDM_CTRL_2, false);
	ret |= regmap_write(di->rmap, SC6605_REG_DPDM_CTRL, false);
	ret |= regmap_write(di->rmap, SC6605_REG_UFCS_CTRL_1, 0);
	ret |= sc6605_ufcs_field_write(di, F_DPDM_EN, 0);
	ret |= regmap_bulk_read(di->rmap, SC6605_REG_DPDM_INT_MASK, &reg_val, REG_COUNT1);

	reg_val |= SC6605_UFCS_DPDM_INT;
	ret |= regmap_write(di->rmap, SC6605_REG_DPDM_INT_MASK, reg_val);
	if (ret)
		hwlog_err("[%s] ufcs_deinit failed\n", __func__);
	
	return ret;
}

static int sc6605_ufcs_init_msg_head(struct sc6605_ufcs_device *di)
{
	struct sc6605_ufcs_msg_head *head = NULL;

	mutex_lock(&di->ufcs_node_lock);
	head = kzalloc(sizeof(struct sc6605_ufcs_msg_head), GFP_KERNEL);
	if (!head) {
		mutex_unlock(&di->ufcs_node_lock);
		return -ENOMEM;
	}

	head->num = 0;
	head->next = NULL;
	g_sc6605_ufcs_msg_head = head;
	mutex_unlock(&di->ufcs_node_lock);
	
	return 0;
}

static struct sc6605_ufcs_msg_node *sc6605_ufcs_create_node(const u8 *data, int len)
{
	struct sc6605_ufcs_msg_node *node = NULL;

	hwlog_info("[%s] create node\n", __func__);

	node = kzalloc(sizeof(struct sc6605_ufcs_msg_node), GFP_KERNEL);
	if (!node) {
		hwlog_err("[%s] create node fail\n", __func__);
		return NULL;
	}

	node->len = len;
	(void)memcpy_s(node->data, SC6605_UFCS_RX_BUF_SIZE, &data[0], len);

	return node;
}

static void sc6605_ufcs_add_node(struct sc6605_ufcs_device *di, struct sc6605_ufcs_msg_node *node)
{
	struct sc6605_ufcs_msg_head *head = g_sc6605_ufcs_msg_head;
	struct sc6605_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head) {
		hwlog_err("[%s] msg head is null\n", __func__);
		mutex_unlock(&di->ufcs_node_lock);
		return;
	}

	hwlog_info("[%s] add msg\n", __func__);
	if (!head->next) {
		head->next = node;
		goto end;
	}

	check_node = head->next;
	while (check_node->next)
		check_node = check_node->next;
	check_node->next = node;

end:
	head->num++;
	hwlog_info("[%s] current msg num=%d\n", __func__, head->num);
	mutex_unlock(&di->ufcs_node_lock);
}

static void sc6605_ufcs_delete_node(struct sc6605_ufcs_device *di)
{
	struct sc6605_ufcs_msg_head *head = g_sc6605_ufcs_msg_head;
	struct sc6605_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !head->next) {
		hwlog_err("[%s] msg head or node is null\n", __func__);
		mutex_unlock(&di->ufcs_node_lock);
		return;
	}

	hwlog_info("[%s] delete msg\n", __func__);
	check_node = head->next;
	head->next = head->next->next;
	kfree(check_node);
	head->num--;
	hwlog_info("[%s] current msg num=%d\n", __func__, head->num);
	mutex_unlock(&di->ufcs_node_lock);
}

static void sc6605_ufcs_free_node_list(struct sc6605_ufcs_device *di, bool need_free_head)
{
	struct sc6605_ufcs_msg_head *head = g_sc6605_ufcs_msg_head;
	struct sc6605_ufcs_msg_node *free_node = NULL;
	struct sc6605_ufcs_msg_node *temp = NULL;

	if (!head) {
		hwlog_err("[%s] msg head is null\n", __func__);
		return;
	}

	mutex_lock(&di->ufcs_node_lock);
	hwlog_info("[%s] free msg\n", __func__);
	free_node = head->next;
	while (free_node) {
		temp = free_node->next;
		kfree(free_node);
		free_node = temp;
	}

	head->next = NULL;
	head->num = 0;

	if (need_free_head) {
		kfree(head);
		g_sc6605_ufcs_msg_head = NULL;
	}
	mutex_unlock(&di->ufcs_node_lock);
}

static void sc6605_ufcs_add_msg(struct sc6605_ufcs_device *di)
{
	u8 len = 0;
	int ret;
	u8 data[SC6605_UFCS_RX_BUF_SIZE]  = { 0 };
	struct sc6605_ufcs_msg_node *node = NULL;

	ret = regmap_bulk_read(di->rmap, SC6605_REG_RX_LENGTH, &len, REG_COUNT1);
	if (ret)
		return;

	if (!len || len > SC6605_UFCS_RX_BUF_SIZE) {
		hwlog_err("[%s] length is %d, invalid\n", __func__, len);
		return;
	}

	ret = regmap_bulk_read(di->rmap, SC6605_REG_RX_BUFFER0, data, len);
	if (ret) {
		hwlog_err("[%s] RX_BUFFER0 read failed or data is null\n", __func__);
		return;
	}

	node = sc6605_ufcs_create_node(data, len);
	if (!node) {
		hwlog_err("[%s] create_node failed\n", __func__);
		return;
	}

	sc6605_ufcs_add_node(di, node);

	hwlog_info("[%s] receive new msg, completion\n", __func__);
	complete(&di->sc6605_add_msg_completion);
}

static struct sc6605_ufcs_msg_node *sc6605_ufcs_get_msg(struct sc6605_ufcs_device *di)
{
	struct sc6605_ufcs_msg_head *head = g_sc6605_ufcs_msg_head;

	if (!head || !head->next) {
		hwlog_err("[%s] msg head or node is null\n", __func__);
		return NULL;
	}

	return head->next;
}

static int sc6605_ufcs_wait(struct sc6605_ufcs_device *di, u8 flag)
{
	u8 reg_val1 = 0;
	u8 reg_val2 = 0;
	u8 reg_val3 = 0;
	int i;

	for (i = 0; i < SC6605_UFCS_WAIT_RETRY_CYCLE; i++) {
		if (!di->plugged_state)
			break;

		power_usleep(DT_USLEEP_1MS);
		reg_val1 = di->ufcs_irq[0];
		reg_val2 = di->ufcs_irq[1];
		reg_val3 = di->ufcs_irq[2];
		hwlog_info("[%s] ufcs_isr1=0x%x, ufcs_isr2=0x%x ufcs_isr3=0x%x\n", __func__, reg_val1, reg_val2, reg_val3);

		/* isr1[4] must be 0 */
		if ((flag & HWUFCS_WAIT_CRC_ERROR) && (reg_val2 & UFCS_IRQ_CRC_ERROR)) {
			hwlog_err("[%s] crc error\n", __func__);
			break;
		}

		/* isr1[3] must be 1 */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) && (reg_val1 & UFCS_IRQ_MSG_TRANS_FAIL)) {
			hwlog_err("[%s] sent packet conflict with receive data\n", __func__);
			return SC6605_UFCS_RX_TX_CONFLICT_ERROR;
		}

		/* isr2[1] must be 0 */
		if ((flag & HWUFCS_ACK_RECEIVE_TIMEOUT) && (reg_val1 & UFCS_IRQ_MSG_TRANS_FAIL)) {
			hwlog_err("[%s] not receive ack after retry\n", __func__);
			break;
		}

		/* isr1[3] must be 1 */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) && !(reg_val1 & UFCS_IRQ_SENT_PACKET_COMPLETE)) {
			hwlog_err("[%s] sent packet not complete or fail\n", __func__);
			continue;
		}

		/* isr1[2] must be 1 */
		if ((flag & HWUFCS_WAIT_DATA_READY) && !(reg_val1 & UFCS_IRQ_DATA_READY)) {
			hwlog_err("[%s] receive data not ready\n", __func__);
			continue;
		}

		hwlog_info("[%s] wait succ\n", __func__);
		return 0;
	}

	hwlog_err("[%s] wait fail\n", __func__);
	return -EINVAL;
}

static int sc6605_ufcs_detect_adapter(void *dev_data)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret, i;
	u8 reg_val = 0;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_ufcs_detect_adapter_init(di);
	if (ret)
		return ret;

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	mutex_lock(&di->ufcs_detect_lock);
	(void)power_usleep(DT_USLEEP_20MS);

	ret = sc6605_ufcs_field_write(di, UFCS_HANDSHAKE, true);
	if (ret) {
		hwlog_err("[%s] write UFCS_HANDSHAKE failed\n", __func__);
		return ret;
	}

	/* waiting for handshake */
	for (i = 0; i < SC6605_UFCS_HANDSHARK_RETRY_CYCLE; i++) {
		if (!di->plugged_state)
			break;

		(void)power_usleep(DT_USLEEP_5MS);
		ret = regmap_bulk_read(di->rmap, SC6605_REG_UFCS_INT_FLAG1, &reg_val, REG_COUNT1);
		if (ret) {
			hwlog_err("[%s] read isr reg[%x] fail\n", __func__, SC6605_REG_UFCS_INT_FLAG1);
			continue;
		}

		reg_val |= di->ufcs_irq[0];
		hwlog_info("[%s] ufcs_isr1=0x%x\n", __func__, reg_val);
		if (reg_val & UFCS_IRQ_HANDSHAKE_FAIL) {
			i = SC6605_UFCS_HANDSHARK_RETRY_CYCLE;
			break;
		}

		if (reg_val & UFCS_IRQ_HANDSHAKE_SUCCESS)
			break;
	}

	mutex_unlock(&di->ufcs_detect_lock);

	if (i == SC6605_UFCS_HANDSHARK_RETRY_CYCLE) {
		hwlog_err("[%s] handshake fail\n", __func__);
		sc6605_ufcs_deinit(di);
		return HWUFCS_DETECT_FAIL;
	}

	hwlog_info("[%s] handshake succ\n", __func__);
	queue_delayed_work(di->msg_update_wq, &di->ufcs_msg_update_work, 0);
	return HWUFCS_DETECT_SUCC;
}

static int sc6605_ufcs_end_read_msg(void *dev_data)
{
	struct sc6605_ufcs_device *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	di->ufcs_msg_ready_flag = false;
	complete(&di->sc6605_ufcs_read_msg_completion);

	return 0;
}

static int sc6605_ufcs_clear_rx_buff(void *dev_data)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	sc6605_ufcs_free_node_list(di, false);
	reinit_completion(&di->sc6605_add_msg_completion);
	ret = sc6605_ufcs_end_read_msg(di);
	if (ret < 0)
		hwlog_err("[%s] clear_rx_buff failed\n", __func__);

	return ret;
}

static int sc6605_ufcs_write_msg(void *dev_data, uint8_t *data, uint8_t len, uint8_t flag)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret;

	if (!di || !data) {
		hwlog_err("[%s] di or data is null\n", __func__);
		return -ENODEV;
	}

	if (len > SC6605_UFCS_TX_BUF_WITHOUTHEAD_SIZE) {
		hwlog_err("[%s] invalid length=%u\n", __func__, len);
		return -EINVAL;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	ret = regmap_bulk_write(di->rmap, SC6605_REG_TX_LENGTH, &len, REG_COUNT1);
	ret |= regmap_bulk_write(di->rmap, SC6605_REG_TX_BUFFER0, data, len);
	ret |= sc6605_ufcs_field_write(di, SND_CMD, true);
	if (ret) {
		hwlog_err("[%s] write msg failed \n", __func__);
		return ret;
	}

	ret = sc6605_ufcs_wait(di, flag);
	if (ret < 0)
		hwlog_err("[%s] ufcs_wait failed\n", __func__);

	return ret;
}

static int sc6605_ufcs_wait_msg_ready(void *dev_data, uint8_t flag)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_ufcs_wait(di, flag);
	if (ret < 0)
		hwlog_err("[%s] ufcs_wait failed\n", __func__);

	return ret;
}

static int sc6605_ufcs_get_rx_len(void *dev_data, u8 *len)
{
	struct sc6605_ufcs_device *di = dev_data;

	if (!di || !len) {
		hwlog_err("[%s] di or len is null\n", __func__);
		*len = 0;
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		reinit_completion(&di->sc6605_ufcs_msg_update_completion);
		if (!wait_for_completion_timeout(&di->sc6605_ufcs_msg_update_completion,
			msecs_to_jiffies(SC6605_UFCS_WAIT_MSG_UPDATE_TIMEOUT))) {
			hwlog_err("[%s] wait for updating msg timeout\n", __func__);
			*len = 0;
			return -ENODEV;
		}
	}

	*len = di->ufcs_pending_msg_len;
	return 0;
}

static int sc6605_ufcs_read_msg(void *dev_data, uint8_t *data, uint8_t len)
{
	struct sc6605_ufcs_device *di = dev_data;

	if (!di || !data) {
		hwlog_err("[%s] di or data is null\n", __func__);
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		hwlog_err("[%s] msg is not ready\n", __func__);
		return -EINVAL;
	}

	if (len > SC6605_UFCS_RX_BUF_WITHOUTHEAD_SIZE) {
		hwlog_err("[%s] invalid length=%u\n", __func__, len);
		return -EINVAL;
	}

	if (memcpy_s(data, len, &di->ufcs_pending_msg[0], len) != EOK) {
		hwlog_err("[%s] memcpy_s failed\n", __func__);
		return -EINVAL;
	}

	if (g_sc6605_ufcs_msg_head->num != 0)
		di->ufcs_irq[0] = 0x10;
	else
		di->ufcs_irq[0] = 0;

	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;

	return 0;
}

static void sc6605_ufcs_pending_msg_update_work(struct work_struct *work)
{
	struct sc6605_ufcs_msg_node *msg;
	struct sc6605_ufcs_device *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct sc6605_ufcs_device, ufcs_msg_update_work.work);
	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return;
	}

	hwlog_info("[%s] start pending msg update work\n", __func__);
	/* init msg list */
	sc6605_ufcs_free_node_list(di, true);
	if (sc6605_ufcs_init_msg_head(di)) {
		hwlog_err("[%s] msg list init fail\n", __func__);
		return;
	}

	reinit_completion(&di->sc6605_add_msg_completion);
	reinit_completion(&di->sc6605_ufcs_read_msg_completion);

	while (1) {
		if (!wait_for_completion_timeout(&di->sc6605_add_msg_completion,
			msecs_to_jiffies(SC6605_UFCS_MSG_TIMEOUT))) {
			hwlog_err("[%s] wait for adding msg timeout\n", __func__);
			break;
		}
		reinit_completion(&di->sc6605_add_msg_completion);

		if (g_sc6605_ufcs_msg_head->num <= 0) {
			break;
		}

		msg = sc6605_ufcs_get_msg(di);
		if (!msg) {
			hwlog_err("[%s] msg is null\n", __func__);
			break;
		}

		di->ufcs_pending_msg_len = msg->len;
		(void)memcpy_s(di->ufcs_pending_msg, SC6605_UFCS_RX_BUF_SIZE, &msg->data[0], di->ufcs_pending_msg_len);
		di->ufcs_msg_ready_flag = true;
		sc6605_ufcs_delete_node(di);
		complete(&di->sc6605_ufcs_msg_update_completion);
		hwlog_info("[%s] pending msg updated\n", __func__);
		if (!di->ufcs_communicating_flag && di->ufcs_msg_ready_flag)
			/* need to change */
			power_event_bnc_notify(POWER_BNT_UFCS, POWER_NE_UFCS_REC_UNSOLICITED_DATA, NULL);

		if (!wait_for_completion_timeout(&di->sc6605_ufcs_read_msg_completion,
			msecs_to_jiffies(SC6605_UFCS_MSG_TIMEOUT))) {
			hwlog_err("[%s] wait for reading msg timeout\n", __func__);
			break;
		}
		reinit_completion(&di->sc6605_ufcs_read_msg_completion);
	}

	sc6605_ufcs_free_node_list(di, true);
}

static void sc6605_ufcs_cancel_msg_update_work(struct sc6605_ufcs_device *di)
{
	complete(&di->sc6605_add_msg_completion);
	complete(&di->sc6605_ufcs_read_msg_completion);
	cancel_delayed_work(&di->ufcs_msg_update_work);
}

static int sc6605_ufcs_soft_reset_master(void *dev_data)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	sc6605_ufcs_cancel_msg_update_work(di);
	ret = sc6605_ufcs_deinit(di);
	if (ret < 0)
		hwlog_err("[%s] ufcs_deinid failed\n", __func__);

	return ret;
}

static int sc6605_ufcs_set_communicating_flag(void *dev_data, bool flag)
{
	struct sc6605_ufcs_device *di = dev_data;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	if (di->ufcs_communicating_flag && flag) {
		hwlog_info("[%s] is communicating, wait\n", __func__);
		return -EINVAL;
	}

	di->ufcs_communicating_flag = flag;
	return 0;
}

static int sc6605_ufcs_config_baud_rate(void *dev_data, int baud_rate)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}
	hwlog_err("[%s]  set baudrate is %d\n", __func__, baud_rate);
	ret = sc6605_ufcs_field_write(di, UFCS_BAUDRATE, baud_rate);
	if (ret)
		hwlog_err("[%s] UFCS_BAUDRATE write failed\n", __func__);

	return ret;
}

static int sc6605_ufcs_hard_reset_cable(void *dev_data)
{
	struct sc6605_ufcs_device *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = sc6605_ufcs_field_write(di, CABLE_HARDRESET, true);
	if (ret)
		hwlog_err("[%s] CABLE_HARDRESET write failed\n", __func__);

	(void)power_usleep(DT_USLEEP_2MS);

	return ret;
}

static bool sc6605_ufcs_need_check_ack(void *dev_data)
{
	return false;
}

static irqreturn_t sc6605_ufcs_interrupt_handler(int irq, void *data)
{
	struct sc6605_ufcs_device *di = data;
	int ret;
	u8 ufcs_irq[3] = { 0 };

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return IRQ_NONE;
	}
	hwlog_info("[%s] \n", __func__);

	ret = regmap_bulk_read(di->rmap, SC6605_REG_UFCS_INT_FLAG1, ufcs_irq, ARRAY_SIZE(ufcs_irq));
	if (ret) {
		hwlog_err("[%s] SC6605_REG_UFCS_INT_FLAG1 read failed\n", __func__);
		return IRQ_NONE;
	}

	hwlog_info("[%s] ufcs_isr1=0x%x, ufcs_isr2=0x%x ufcs_isr3=0x%x\n", __func__, ufcs_irq[0], ufcs_irq[1], ufcs_irq[2]);

	if (ufcs_irq[0] & UFCS_IRQ_DATA_READY)
		sc6605_ufcs_add_msg(di);

	di->ufcs_irq[0] |= ufcs_irq[0];
	di->ufcs_irq[1] |= ufcs_irq[1];
	di->ufcs_irq[2] |= ufcs_irq[2];

	return IRQ_HANDLED;
}

static int sc6605_ufcs_request_irq(struct sc6605_ufcs_device *di)
{
	int ret;
	const char *irq_name = "UFCS";

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	ret = platform_get_irq_byname(to_platform_device(di->dev), irq_name);
	if (ret < 0) {
		hwlog_err("[%s] failed to get irq %s\n", __func__, irq_name);
		return ret;   
	} 

	di->irq = ret;
	hwlog_info("[%s] %s irq = %d\n", __func__, irq_name, ret);
	ret = devm_request_threaded_irq(di->dev, ret, NULL, sc6605_ufcs_interrupt_handler,
		IRQF_ONESHOT, dev_name(di->dev), di);
	if (ret < 0) {
		hwlog_err("[%s] failed to request irq %s\n", __func__, irq_name);
		return ret;
	}

	return 0;
}

static struct hwufcs_ops sc6605_hwufcs_ops = {
	.chip_name = "sc6605",
	.detect_adapter = sc6605_ufcs_detect_adapter,
	.write_msg = sc6605_ufcs_write_msg,
	.wait_msg_ready = sc6605_ufcs_wait_msg_ready,
	.read_msg = sc6605_ufcs_read_msg,
	.end_read_msg = sc6605_ufcs_end_read_msg,
	.clear_rx_buff = sc6605_ufcs_clear_rx_buff,
	.soft_reset_master = sc6605_ufcs_soft_reset_master,
	.get_rx_len = sc6605_ufcs_get_rx_len,
	.set_communicating_flag = sc6605_ufcs_set_communicating_flag,
	.config_baud_rate = sc6605_ufcs_config_baud_rate,
	.hard_reset_cable = sc6605_ufcs_hard_reset_cable,
	.need_check_ack = sc6605_ufcs_need_check_ack,
};

static int sc6605_ufcs_register(struct sc6605_ufcs_device *di)
{
	sc6605_hwufcs_ops.dev_data = (void *)di;
	return hwufcs_ops_register(&sc6605_hwufcs_ops);
}

static int sc6605_ufcs_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	struct sc6605_ufcs_device *di = (struct sc6605_ufcs_device *)container_of(nb,
		struct sc6605_ufcs_device, event_nb);

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return NOTIFY_OK;
	}

	switch (event) {
	case POWER_NE_USB_DISCONNECT:
		di->ufcs_irq[0] = 0;
		di->ufcs_irq[1] = 0;
		di->ufcs_irq[2] = 0;
		di->plugged_state = false;
		hwlog_info("[%s] reset ic\n", __func__);
		sc6605_ufcs_deinit(di);
		sc6605_ufcs_cancel_msg_update_work(di);
		break;
	case POWER_NE_USB_CONNECT:
		di->plugged_state = true;
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int sc6605_ufcs_init(struct sc6605_ufcs_device *di)
{
	int ret;

	di->msg_update_wq = create_singlethread_workqueue("ufcs_msg_update_wq");
	if (!di->msg_update_wq) {
		hwlog_err("create ufcs_msg_update_wq fail\n");
		return -ENOMEM;
	}
	INIT_DELAYED_WORK(&di->ufcs_msg_update_work, sc6605_ufcs_pending_msg_update_work);

	ret = sc6605_ufcs_request_irq(di);
	if (ret < 0) {
		hwlog_err("[%s] irq request failed\n", __func__);
		return ret;
	}

	di->event_nb.notifier_call = sc6605_ufcs_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->event_nb);
	if (ret) {
		hwlog_err("[%s] register connect notifier failed\n", __func__);
		return ret;
	}

	init_completion(&di->sc6605_add_msg_completion);
	init_completion(&di->sc6605_ufcs_read_msg_completion);
	init_completion(&di->sc6605_ufcs_msg_update_completion);

	mutex_init(&di->ufcs_node_lock);
	mutex_init(&di->ufcs_detect_lock);

	return 0;
}

static int sc6605_ufcs_probe(struct platform_device *pdev)
{
	struct device *dev = NULL;
	struct sc6605_ufcs_device *di = NULL;
	int ret;

	if (!pdev || !pdev->dev.of_node) {
		hwlog_err("[%s] pdev or of_node is null\n", __func__);
		return -ENODEV;
	}

	dev = &pdev->dev;
	di = devm_kzalloc(dev, sizeof(*di), GFP_KERNEL);
	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENOMEM;
	}

	di->rmap = dev_get_regmap(dev->parent, NULL);
	if (!di->rmap) {
		hwlog_err("[%s] failed to get regmap\n", __func__);
		return -ENODEV;
	}

	di->dev = dev;
	platform_set_drvdata(pdev, di);

	ret = sc6605_ufcs_init(di);
	if (ret) {
		hwlog_err("%s sc6605 ufcs init failed\n", __func__);
		goto sc6605_ufcs_fail_0;
	}

	ret = sc6605_ufcs_register(di);
	if (ret) {
		hwlog_err("[%s] hwufcs_ops_register fail", __func__);
		goto sc6605_ufcs_fail_1;
	}
	hwlog_info("[%s] probe success\n", __func__);
	return 0;

sc6605_ufcs_fail_1:
	power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
	mutex_destroy(&di->ufcs_node_lock);
	mutex_destroy(&di->ufcs_detect_lock);
sc6605_ufcs_fail_0:
	if (di->msg_update_wq)
		destroy_workqueue(di->msg_update_wq);

	hwlog_info("[%s] probe failed\n", __func__);
	return ret;
}

static int sc6605_ufcs_remove(struct platform_device *pdev)
{
	struct sc6605_ufcs_device *di = platform_get_drvdata(pdev);

	if (!di) {
		hwlog_err("[%s] di is null\n", __func__);
		return -ENODEV;
	}

	power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
	sc6605_ufcs_free_node_list(di, true);
	mutex_destroy(&di->ufcs_node_lock);
	mutex_destroy(&di->ufcs_detect_lock);

	return 0;
}

static const struct of_device_id sc6605_ufcs_of_match[] = {
	{
		.compatible = "huawei,sc6605_ufcs",
		.data = NULL,
	},
	{},
};

static struct platform_driver sc6605_ufcs_driver = {
	.driver = {
		.name = "sc6605_ufcs",
		.of_match_table = of_match_ptr(sc6605_ufcs_of_match),
	},
	.probe = sc6605_ufcs_probe,
	.remove = sc6605_ufcs_remove,
};

module_platform_driver(sc6605_ufcs_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("sc6605 ufcs module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
