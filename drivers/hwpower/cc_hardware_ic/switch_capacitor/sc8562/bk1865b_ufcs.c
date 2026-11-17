// SPDX-License-Identifier: GPL-2.0
/*
 * bk1865b_ufcs.c
 *
 * bk1865b ufcs driver
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

#include "bk1865b_ufcs.h"
#include "sc8562_i2c.h"
#include <linux/mutex.h>
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>
#define HWLOG_TAG bk1865b_ufcs
HWLOG_REGIST();

static struct bk1865b_ufcs_msg_head *g_bk1865b_ufcs_msg_head;

int bk1865b_ufcs_init_msg_head(struct sc8562_device_info *di)
{
	struct bk1865b_ufcs_msg_head *head = NULL;

	if (!di || g_bk1865b_ufcs_msg_head)
		return 0;

	mutex_lock(&di->ufcs_node_lock);
	head = kzalloc(sizeof(struct bk1865b_ufcs_msg_head), GFP_KERNEL);
	if (!head) {
		mutex_unlock(&di->ufcs_node_lock);
		return -ENOMEM;
	}

	head->num = 0;
	head->next = NULL;
	g_bk1865b_ufcs_msg_head = head;
	mutex_unlock(&di->ufcs_node_lock);
	return 0;
}

static struct bk1865b_ufcs_msg_node *bk1865b_ufcs_create_node(const u8 *data, int len)
{
	struct bk1865b_ufcs_msg_node *node = NULL;

	hwlog_info("create node\n");
	if (!data) {
		hwlog_err("data is null\n");
		return NULL;
	}

	node = kzalloc(sizeof(struct bk1865b_ufcs_msg_node), GFP_KERNEL);
	if (!node) {
		hwlog_err("create node fail\n");
		return NULL;
	}

	node->len = len;
	(void)memcpy_s(node->data, BK1865B_UFCS_RX_BUF_SIZE, &data[0], len);
	return node;
}

static int bk1865b_ufcs_add_node(struct sc8562_device_info *di, struct bk1865b_ufcs_msg_node *node)
{
	struct bk1865b_ufcs_msg_head *head = g_bk1865b_ufcs_msg_head;
	struct bk1865b_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !node) {
		hwlog_err("%s msg head or node is null\n", __func__);
		mutex_unlock(&di->ufcs_node_lock);
		return -ENODEV;
	}

	hwlog_info("add msg\n");
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
	hwlog_info("current msg num=%d\n", head->num);
	mutex_unlock(&di->ufcs_node_lock);
	return 0;
}

static void bk1865b_ufcs_delete_node(struct sc8562_device_info *di)
{
	struct bk1865b_ufcs_msg_head *head = g_bk1865b_ufcs_msg_head;
	struct bk1865b_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !head->next) {
		hwlog_err("%s msg head or node is null\n", __func__);
 		mutex_unlock(&di->ufcs_node_lock);
		return;
	}

	hwlog_info("delete msg\n");
	check_node = head->next;
	head->next = head->next->next;
	kfree(check_node);
	head->num--;
	hwlog_info("current msg num=%d\n", head->num);
	mutex_unlock(&di->ufcs_node_lock);
}

void bk1865b_ufcs_free_node_list(struct sc8562_device_info *di, bool need_free_head)
{
	struct bk1865b_ufcs_msg_head *head = g_bk1865b_ufcs_msg_head;
	struct bk1865b_ufcs_msg_node *free_node = NULL;
	struct bk1865b_ufcs_msg_node *temp = NULL;

	if (!di || !head) {
		hwlog_err("di or msg head is null\n");
		return;
	}

	mutex_lock(&di->ufcs_node_lock);
	hwlog_info("free msg\n");
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
		g_bk1865b_ufcs_msg_head = NULL;
	}
	mutex_unlock(&di->ufcs_node_lock);
}

void bk1865b_ufcs_add_msg(struct sc8562_device_info *di)
{
	u8 len = 0;
	int ret;
	u8 data[BK1865B_UFCS_RX_BUF_SIZE] = { 0 };
	struct bk1865b_ufcs_msg_node *node = NULL;

	if (!di)
		return;

	ret = sc8562_read_byte(di, BK1865B_REG_UFCS_RX_LEN, &len);
	if (ret)
		return;

	if (!len || len > BK1865B_UFCS_RX_BUF_SIZE) {
		hwlog_err("length is %d, invalid\n", len);
		return;
	}

	ret = sc8562_read_block(di, BK1865B_REG_UFCS_RX_BUF, data, len);
	if (ret)
		return;

	node = bk1865b_ufcs_create_node(data, len);
	if (!node)
		return;

	if (bk1865b_ufcs_add_node(di, node)) {
		hwlog_err("kfree node\n");
		kfree(node);
		node = NULL;
		return;
	}

	hwlog_info("receive new msg, completion\n");
	complete(&di->bk1865b_add_msg_completion);
}

static struct bk1865b_ufcs_msg_node *bk1865b_ufcs_get_msg(struct sc8562_device_info *di)
{
	struct bk1865b_ufcs_msg_head *head = g_bk1865b_ufcs_msg_head;

	if (!head || !head->next) {
		hwlog_err("msg head or node is null\n");
		return NULL;
	}

	return head->next;
}

static int bk1865b_ufcs_wait(struct sc8562_device_info *di, u8 flag)
{
	u8 reg_val1;
	u8 reg_val2;
	u8 reg_val3;
	int i;

	for (i = 0; i < BK1865B_UFCS_WAIT_RETRY_CYCLE; i++) {
		if (!di->plugged_state)
			break;
		power_usleep(DT_USLEEP_2MS);
		reg_val1 = di->ufcs_irq[0];
		reg_val2 = di->ufcs_irq[1];
		reg_val3 = di->ufcs_irq[2];
		hwlog_info("ufcs_isr1=0x%x, ufcs_isr2=0x%x ufcs_isr3=0x%x\n", reg_val1, reg_val2, reg_val3);

		/* isr2[1] must be 1 */
		if ((flag & HWUFCS_WAIT_CRC_ERROR) &&
			(reg_val2 & UFCS_IRQ_CRC_ERROR)) {
			hwlog_err("crc error\n");
			break;
		}

		/* isr1[0] must be 1 */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) &&
			(reg_val1 & UFCS_IRQ_ACK_RECEIVE_TIMEOUT)) {
			hwlog_err("sent packet conflict with receive data\n");
			return BK1865B_UFCS_RX_TX_CONFLICT_ERROR;
		}

		/* isr1[5] must be 0 */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) &&
			!(reg_val1 & UFCS_IRQ_SENT_PACKET_COMPLETE)) {
			hwlog_err("sent packet not complete or fail\n");
			continue;
		}

		/* isr1[1] must be 1 */
		if ((flag & HWUFCS_ACK_RECEIVE_TIMEOUT) &&
			(reg_val1 & UFCS_IRQ_MSG_TRANS_FAIL)) {
			hwlog_err("not receive ack after retry\n");
			break;
		}

		/* isr1[4] must be 0 */
		if ((flag & HWUFCS_WAIT_DATA_READY) &&
			!(reg_val1 & UFCS_IRQ_DATA_READY)) {
			hwlog_err("receive data not ready\n");
			continue;
		}

		hwlog_info("wait succ\n");
		return 0;
	}

	hwlog_err("wait fail\n");
	return -EINVAL;
}

static void bk1865b_ufcs_handshake_preparation(struct sc8562_device_info *di)
{
	/* dpdm en */
	sc8562_write_mask(di, BK1865B_REG_DPDM_CTRL2, BK1865B_UFCS_DPDM_EN_MASK,
		BK1865B_UFCS_DPDM_EN_SHIFT, 1);
	/* set dpdm volt 3.3v */
	sc8562_write_mask(di, BK1865B_REG_SCP_CTRL, BK1865B_UFCS_DPDM_3P3_EN_MASK,
		BK1865B_UFCS_DPDM_3P3_EN_SHIFT, 1);
	/* ufcs en */
	sc8562_write_mask(di, BK1865B_REG_UFCS_CTRL1, BK1865B_UFCS_EN_MASK,
		BK1865B_UFCS_EN_SHIFT, 1);
	/* 2ms for t_reset_source */
	sc8562_write_mask(di, BK1865B_REG_UFCS_OPTION2, BK1865B_UFCS_RX_HARDRESET_TH_MASK,
		BK1865B_UFCS_RX_HARDRESET_TH_SHIFT, BK1865B_UFCS_RX_HARDRESET_TH_VAL);
	/* enable check msg length*/
	sc8562_write_mask(di, BK1865B_REG_UFCS_UFCS_OPTION4,
		BK1865B_UFCS_CHECK_MSG_LENGTH_MASK, BK1865B_UFCS_CHECK_MSG_LENGTH_SHIFT, 1);
	/* enter idle after rx length done */
	sc8562_write_mask(di, BK1865B_REG_UFCS_UFCS_OPTION4,
		BK1865B_UFCS_DIS_LENGTH_END_DLY_MASK, BK1865B_UFCS_DIS_LENGTH_END_DLY_SHIFT, 1);
	/* handshake en */
	sc8562_write_mask(di, BK1865B_REG_UFCS_CTRL1, BK1865B_UFCS_HANDSHAKE_EN_MASK,
		BK1865B_UFCS_HANDSHAKE_EN_SHIFT, 1);
}

static int bk1865b_ufcs_get_isr1(struct sc8562_device_info *di, u8 *reg_val)
{
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	(void)power_usleep(DT_USLEEP_5MS);

	ret = sc8562_read_byte(di, BK1865B_REG_UFCS_INT_FLAG1, reg_val);
	if (ret) {
		hwlog_err("read isr reg[%x] fail\n", BK1865B_REG_UFCS_INT_FLAG1);
		return ret;
	}

	*reg_val |= di->ufcs_irq[0];
	hwlog_info("ufcs_isr1=0x%x\n", *reg_val);
	return 0;
}

static int bk1865b_ufcs_detect_adapter(void *dev_data)
{
	struct sc8562_device_info *di = dev_data;
	int ret, i;
	u8 reg_val = 0;
	bool err;

	if (!di) {
		hwlog_err("di is null\n");
		return HWUFCS_DETECT_OTHER;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	mutex_lock(&di->ufcs_detect_lock);
	bk1865b_ufcs_handshake_preparation(di);
	(void)power_usleep(DT_USLEEP_20MS);
	/* waiting for handshake */
	for (i = 0; i < BK1865B_UFCS_HANDSHARK_RETRY_CYCLE; i++) {
		if (!di->plugged_state) {
			mutex_unlock(&di->ufcs_detect_lock);
			return HWUFCS_DETECT_OTHER;
		}
		ret = bk1865b_ufcs_get_isr1(di, &reg_val);
		if (ret)
			continue;

		if (reg_val & UFCS_IRQ_HANDSHAKE_FAIL) {
			i = BK1865B_UFCS_HANDSHARK_RETRY_CYCLE;
			break;
		}

		if (reg_val & UFCS_IRQ_HANDSHAKE_SUCCESS)
			break;
	}

	mutex_unlock(&di->ufcs_detect_lock);

	if (i == BK1865B_UFCS_HANDSHARK_RETRY_CYCLE) {
		hwlog_err("handshake fail\n");
		return HWUFCS_DETECT_FAIL;
	}

	err = queue_delayed_work(di->msg_update_wq, &di->ufcs_msg_update_work, 0);
	if (!err) {
		hwlog_err("%s queue_delayed_work failed\n", __func__);
		return HWUFCS_DETECT_OTHER;
	}
	hwlog_info("handshake succ\n");
	return HWUFCS_DETECT_SUCC;
}

static int bk1865b_ufcs_end_read_msg(void *dev_data)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}
	di->ufcs_msg_ready_flag = false;
	complete(&di->bk1865b_ufcs_read_msg_completion);
	return 0;
}

static int bk1865b_ufcs_clear_rx_buff(void *dev_data)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	bk1865b_ufcs_free_node_list(di, false);
	reinit_completion(&di->bk1865b_add_msg_completion);
	return bk1865b_ufcs_end_read_msg(di);
}

int bk1865b_ufcs_write_msg(void *dev_data, uint8_t *data, uint8_t len, uint8_t flag)
{
	struct sc8562_device_info *di = dev_data;
	int ret, i;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (len > BK1865B_UFCS_TX_BUF_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	for (i = 0; i < BK1865B_UFCS_TX_CONFLICT_RETRY_TIMES; i++) {
		di->ufcs_irq[0] = 0;
		di->ufcs_irq[1] = 0;
		di->ufcs_irq[2] = 0;
		ret = sc8562_write_byte(di, BK1865B_REG_UFCS_TX_LEN, len);
		ret |= sc8562_write_block(di, BK1865B_REG_UFCS_TX_BUF, data, len);
		if (ret) {
			hwlog_err("write msg fail\n");
			break;
		}
		ret = sc8562_write_mask(di, BK1865B_REG_UFCS_CTRL1, BK1865B_UFCS_SND_CMD_MASK,
			BK1865B_UFCS_SND_CMD_SHIFT, 1);
		if (ret) {
			hwlog_err("write send cmd failed\n");
			break;
		}

		ret = bk1865b_ufcs_wait(di, flag);
		if (ret == BK1865B_UFCS_RX_TX_CONFLICT_ERROR) {
			hwlog_err("send data conflict with receive data, retry %d times\n", i + 1);
			bk1865b_ufcs_clear_rx_buff(di);
			continue;
		}
		break;
	}

    return ret;
}

static int bk1865b_ufcs_wait_msg_ready(void *dev_data, uint8_t flag)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	return bk1865b_ufcs_wait(di, flag);
}

static int bk1865b_ufcs_get_rx_len(void *dev_data, u8 *len)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		*len = 0;
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		reinit_completion(&di->bk1865b_ufcs_msg_update_completion);
		if (!wait_for_completion_timeout(&di->bk1865b_ufcs_msg_update_completion,
			msecs_to_jiffies(BK1865B_UFCS_WAIT_MSG_UPDATE_TIMEOUT))) {
			hwlog_err("wait for updating msg timeout\n");
			*len = 0;
			return -ENODEV;
		}
	}

	*len = di->ufcs_pending_msg_len;
	return 0;
}

static int bk1865b_ufcs_read_msg(void *dev_data, uint8_t *data, uint8_t len)
{
	struct sc8562_device_info *di = dev_data;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		hwlog_err("msg is not ready\n");
		return -EINVAL;
	}

	if (len > BK1865B_UFCS_RX_BUF_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	if (memcpy_s(data, len, &di->ufcs_pending_msg[0], len) != EOK) {
		hwlog_err("memcpy_s failed\n");
		return -EINVAL;
	}
	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	return 0;
}

void bk1865b_ufcs_pending_msg_update_work(struct work_struct *work)
{
	struct bk1865b_ufcs_msg_node *msg;
	struct sc8562_device_info *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct sc8562_device_info, ufcs_msg_update_work.work);
	if (!di || !di->client)
		return;

	hwlog_info("start pending msg update work\n");
	/* init msg list */
	bk1865b_ufcs_free_node_list(di, true);
	if (bk1865b_ufcs_init_msg_head(di)) {
		hwlog_err("msg list init fail\n");
		return;
	}

	reinit_completion(&di->bk1865b_add_msg_completion);
	reinit_completion(&di->bk1865b_ufcs_read_msg_completion);

	while (1) {
		if (g_bk1865b_ufcs_msg_head->num <= 0) {
			if (!wait_for_completion_timeout(&di->bk1865b_add_msg_completion, msecs_to_jiffies(BK1865B_UFCS_MSG_TIMEOUT))) {
				hwlog_err("wait for adding msg timeout\n");
				break;
			}
			reinit_completion(&di->bk1865b_add_msg_completion);
		}

		msg = bk1865b_ufcs_get_msg(di);
		if (!msg) {
			hwlog_err("msg is null\n");
			break;
		}

		di->ufcs_pending_msg_len = msg->len;
		if (!di->ufcs_pending_msg_len || di->ufcs_pending_msg_len > BK1865B_UFCS_RX_BUF_SIZE) {
			hwlog_err("length is %d, invalid\n", di->ufcs_pending_msg_len);
			break;
		}
		(void)memcpy_s(di->ufcs_pending_msg, BK1865B_UFCS_RX_BUF_SIZE, &msg->data[0], di->ufcs_pending_msg_len);
		di->ufcs_msg_ready_flag = true;
		bk1865b_ufcs_delete_node(di);
		complete(&di->bk1865b_ufcs_msg_update_completion);

		hwlog_info("pending msg updated\n");

		if (!di->ufcs_communicating_flag && di->ufcs_msg_ready_flag)
			power_event_bnc_notify(POWER_BNT_UFCS, POWER_NE_UFCS_REC_UNSOLICITED_DATA, NULL);

		if (!wait_for_completion_timeout(&di->bk1865b_ufcs_read_msg_completion, msecs_to_jiffies(BK1865B_UFCS_MSG_TIMEOUT))) {
			hwlog_err("wait for reading msg timeout\n");
			break;
		}
		reinit_completion(&di->bk1865b_ufcs_read_msg_completion);
	}

	bk1865b_ufcs_free_node_list(di, true);
}

void bk1865b_ufcs_cancel_msg_update_work(struct sc8562_device_info *di)
{
	if (!di)
		return;

	complete(&di->bk1865b_add_msg_completion);
	complete(&di->bk1865b_ufcs_read_msg_completion);
	cancel_delayed_work(&di->ufcs_msg_update_work);
}

static int bk1865b_ufcs_soft_reset_master(void *dev_data)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	bk1865b_ufcs_cancel_msg_update_work(di);
	sc8562_write_mask(di, BK1865B_REG_DPDM_CTRL2, BK1865B_UFCS_DPDM_EN_MASK,
		BK1865B_UFCS_DPDM_EN_SHIFT, 0);
	return sc8562_write_mask(di, BK1865B_REG_UFCS_CTRL1, BK1865B_UFCS_EN_MASK,
		BK1865B_UFCS_EN_SHIFT, 0);
}

static int bk1865b_ufcs_set_communicating_flag(void *dev_data, bool flag)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	if (di->ufcs_communicating_flag && flag) {
		hwlog_info("is communicating, wait\n");
		return -EINVAL;
	}

	di->ufcs_communicating_flag = flag;
	return 0;
}

static int bk1865b_ufcs_config_baud_rate(void *dev_data, int baud_rate)
{
	struct sc8562_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}
	hwlog_info("set baudrate is %d\n", baud_rate);
	return sc8562_write_mask(di, BK1865B_REG_UFCS_CTRL1, BK1865B_UFCS_BAUD_RATE_MASK,
		BK1865B_UFCS_BAUD_RATE_SHIFT, baud_rate);
}

static int bk1865b_ufcs_hard_reset_cable(void *dev_data)
{
	struct sc8562_device_info *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}
	return sc8562_write_mask(di, BK1865B_REG_UFCS_CTRL1, BK1865B_UFCS_CABLE_HARDRESET_MASK,
		BK1865B_UFCS_CABLE_HARDRESET_SHIFT, 1);
}

static bool bk1865b_ufcs_need_check_ack(void *dev_data)
{
	return false;
}

static struct hwufcs_ops bk1865b_hwufcs_ops = {
	.chip_name = "bk1865b",
	.detect_adapter = bk1865b_ufcs_detect_adapter,
	.write_msg = bk1865b_ufcs_write_msg,
	.wait_msg_ready = bk1865b_ufcs_wait_msg_ready,
	.read_msg = bk1865b_ufcs_read_msg,
	.end_read_msg = bk1865b_ufcs_end_read_msg,
	.clear_rx_buff = bk1865b_ufcs_clear_rx_buff,
	.soft_reset_master = bk1865b_ufcs_soft_reset_master,
	.get_rx_len = bk1865b_ufcs_get_rx_len,
	.set_communicating_flag = bk1865b_ufcs_set_communicating_flag,
	.config_baud_rate = bk1865b_ufcs_config_baud_rate,
	.hard_reset_cable = bk1865b_ufcs_hard_reset_cable,
	.need_check_ack = bk1865b_ufcs_need_check_ack,
};

int bk1865b_ufcs_ops_register(struct sc8562_device_info *di)
{
	if (di->dts_ufcs_support && (di->device_id == SWITCHCAP_BK1865)) {
		bk1865b_hwufcs_ops.dev_data = (void *)di;
		return hwufcs_ops_register(&bk1865b_hwufcs_ops);
	}

	return 0;
}
