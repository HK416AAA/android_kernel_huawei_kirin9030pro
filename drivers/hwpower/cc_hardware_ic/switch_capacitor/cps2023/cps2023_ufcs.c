// SPDX-License-Identifier: GPL-2.0
/*
 * cps2023_ufcs.c
 *
 * cps2023 ufcs driver
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

#include "cps2023_ufcs.h"
#include "cps2023_i2c.h"
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs.h>

#define HWLOG_TAG cps2023_ufcs
HWLOG_REGIST();

struct cps2023_ufcs_msg_head *g_cps2023_ufcs_msg_head;

int cps2023_ufcs_init_msg_head(struct cps2023_device_info *di)
{
	struct cps2023_ufcs_msg_head *head = NULL;

	if (!di || g_cps2023_ufcs_msg_head)
		return 0;

	mutex_lock(&di->ufcs_node_lock);
	head = kzalloc(sizeof(struct cps2023_ufcs_msg_head), GFP_KERNEL);
	if (!head) {
		mutex_unlock(&di->ufcs_node_lock);
		return -ENOMEM;
	}

	head->num = 0;
	head->next = NULL;
	g_cps2023_ufcs_msg_head = head;
	mutex_unlock(&di->ufcs_node_lock);
	return 0;
}

static struct cps2023_ufcs_msg_node *cps2023_ufcs_create_node(const u8 *data, int len)
{
	struct cps2023_ufcs_msg_node *node = NULL;

	hwlog_info("create node\n");
	if (!data) {
		hwlog_err("data is null\n");
		return NULL;
	}

	node = kzalloc(sizeof(struct cps2023_ufcs_msg_node), GFP_KERNEL);
	if (!node) {
		hwlog_err("create node fail\n");
		return NULL;
	}

	node->len = len;
	(void)memcpy_s(node->data, CPS2023_UFCS_RX_BUF_SIZE, &data[0], len);
	return node;
}

static void cps2023_ufcs_add_node(struct cps2023_device_info *di,
	struct cps2023_ufcs_msg_node *node)
{
	struct cps2023_ufcs_msg_head *head = g_cps2023_ufcs_msg_head;
	struct cps2023_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !node) {
		hwlog_err("msg head or node is null\n");
		mutex_unlock(&di->ufcs_node_lock);
		return;
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
}

static void cps2023_ufcs_delete_node(struct cps2023_device_info *di)
{
	struct cps2023_ufcs_msg_head *head = g_cps2023_ufcs_msg_head;
	struct cps2023_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !head->next) {
		hwlog_err("msg head or node is null\n");
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

void cps2023_ufcs_free_node_list(struct cps2023_device_info *di, bool need_free_head)
{
	struct cps2023_ufcs_msg_head *head = g_cps2023_ufcs_msg_head;
	struct cps2023_ufcs_msg_node *free_node = NULL;
	struct cps2023_ufcs_msg_node *temp = NULL;

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
		g_cps2023_ufcs_msg_head = NULL;
	}
	mutex_unlock(&di->ufcs_node_lock);
}

void cps2023_ufcs_add_msg(struct cps2023_device_info *di)
{
	u8 len = 0;
	int ret;
	u8 data[CPS2023_UFCS_RX_BUF_SIZE];
	struct cps2023_ufcs_msg_node *node = NULL;

	if (!di)
		return;

	ret = cps2023_read_byte(di, CPS2023_UFCS_RX_LENGTH_REG, &len);
	if (ret)
		return;

	if (!len || len > CPS2023_UFCS_RX_BUF_SIZE) {
		hwlog_err("length is %d, invalid\n", len);
		return;
	}

	ret = cps2023_read_block(di, CPS2023_UFCS_RX_BUFFER_REG, data, len);
	if (ret)
		return;

	node = cps2023_ufcs_create_node(data, len);
	if (!node)
		return;

	cps2023_ufcs_add_node(di, node);

	hwlog_info("receive new msg, completion\n");
	complete(&di->cps2023_add_msg_completion);
}

static struct cps2023_ufcs_msg_node *cps2023_ufcs_get_msg(struct cps2023_device_info *di)
{
	struct cps2023_ufcs_msg_head *head = g_cps2023_ufcs_msg_head;

	if (!head || !head->next) {
		hwlog_err("msg head or node is null\n");
		return NULL;
	}

	return head->next;
}

static int cps2023_ufcs_wait(struct cps2023_device_info *di, u8 flag)
{
	u8 reg_val1;
	u8 reg_val2;
	u8 reg_val3;
	int i;

	for (i = 0; i < CPS2023_UFCS_WAIT_RETRY_CYCLE; i++) {
		if (!di->plugged_state)
			break;
		power_usleep(DT_USLEEP_1MS);
		reg_val1 = di->ufcs_irq[0];
		reg_val2 = di->ufcs_irq[1];
		reg_val3 = di->ufcs_irq[2];
		hwlog_info("ufcs_isr1=0x%x, ufcs_isr2=0x%x, ufcs_isr3=0x%x\n", reg_val1, reg_val2, reg_val3);

		/* isr1[4] must be 0 */
		if ((flag & HWUFCS_WAIT_CRC_ERROR) &&
			(reg_val1 & CPS2023_UFCS_ISR1_CRC_ERROR_MASK)) {
			hwlog_err("crc error\n");
			break;
		}

		/* isr2[1] must be 0 */
		if ((flag & HWUFCS_ACK_RECEIVE_TIMEOUT) &&
			(reg_val2 & CPS2023_UFCS_ISR2_MSG_TRANS_FAIL_MASK)) {
			hwlog_err("not receive ack after retry\n");
			break;
		}

		/* isr3[0] must be 1 */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) &&
			!(reg_val3 & CPS2023_UFCS_ISR3_TX_PASS_INT_MASK)) {
			hwlog_err("sent packet not complete or fail\n");
			continue;
		}

		/* isr2[2] must be 1 */
		if ((flag & HWUFCS_WAIT_DATA_READY) &&
			(reg_val2 & CPS2023_UFCS_ISR2_RX_BUF_OVERFLOW_MASK)) {
			hwlog_err("rx buffer overflow\n");
			return CPS2023_UFCS_RX_BUFFER_OVERFLOW_ERROR;
		}

		/* isr1[2] must be 1 */
		if ((flag & HWUFCS_WAIT_DATA_READY) &&
			(!(reg_val1 & CPS2023_UFCS_ISR1_DATA_READY_MASK) &&
			!(reg_val2 & CPS2023_UFCS_ISR2_RX_BUF_BUSY_MASK))) {
			hwlog_err("receive data not ready\n");
			continue;
		}

		hwlog_info("wait succ\n");
		return 0;
	}

	hwlog_err("wait fail\n");
	return -EINVAL;
}

static void cps2023_ufcs_handshake_preparation(struct cps2023_device_info *di)
{
	/* disable scp */
	cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_EN_PROTOCOL_MASK,
		CPS2023_UFCS_CTL1_EN_PROTOCOL_SHIFT, 0);

	/* enable ufcs */
	cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_EN_PROTOCOL_MASK,
		CPS2023_UFCS_CTL1_EN_PROTOCOL_SHIFT, CPS2023_UFCS_ENABLE);

	/* enable handshake */
	cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_EN_HANDSHAKE_MASK,
		CPS2023_UFCS_CTL1_EN_HANDSHAKE_SHIFT, CPS2023_ENABLE_HANDSHAKE);

	/* hard reset to SW reset */
	cps2023_write_mask(di, CPS2023_UFCS_CTL3_REG, CPS2023_UFCS_CTL3_HARD_RST_SEL_CFG_MASK,
		CPS2023_UFCS_CTL3_HARD_RST_SEL_CFG_SHIFT, CPS2023_UFCS_CTL3_RST_SEL_SOFTRESET);	

	/* mask ufcs interrupt */
	cps2023_write_byte(di, CPS2023_UFCS_MASK1_REG, CPS2023_UFCS_MASK1_MASK_INTERRUPT);
	cps2023_write_byte(di, CPS2023_UFCS_MASK2_REG, CPS2023_UFCS_MASK2_MASK_INTERRUPT);
	cps2023_write_byte(di, CPS2023_UFCS_MASK3_REG, CPS2023_UFCS_MASK3_MASK_INTERRUPT);
}

static int cps2023_ufcs_get_isr1(struct cps2023_device_info *di, u8 *reg_val)
{
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	(void)power_usleep(DT_USLEEP_5MS);

	ret = cps2023_read_byte(di, CPS2023_UFCS_ISR1_REG, reg_val);
	if (ret) {
		hwlog_err("read isr reg[%x] fail\n", CPS2023_UFCS_ISR1_REG);
		return ret;
	}

	*reg_val |= di->ufcs_irq[0];
	hwlog_info("ufcs_isr1=0x%x\n", *reg_val);
	return 0;
}

static int cps2023_ufcs_detect_adapter(void *dev_data)
{
	struct cps2023_device_info *di = dev_data;
	u8 reg_val = 0;
	int ret, i;
	bool err;

	if (!di) {
		hwlog_err("di is null\n");
		return HWUFCS_DETECT_OTHER;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	mutex_lock(&di->ufcs_detect_lock);

	cps2023_ufcs_handshake_preparation(di);

	(void)power_usleep(DT_USLEEP_20MS);
	/* waiting for handshake */
	for (i = 0; i < CPS2023_UFCS_HANDSHARK_RETRY_CYCLE; i++) {
		if (!di->plugged_state) {
			mutex_unlock(&di->ufcs_detect_lock);
			return HWUFCS_DETECT_OTHER;
		}

		ret = cps2023_ufcs_get_isr1(di, &reg_val);
		if (ret)
			continue;

		if (reg_val & CPS2023_UFCS_ISR1_HANDSHAKE_FAIL_MASK) {
			i = CPS2023_UFCS_HANDSHARK_RETRY_CYCLE;
			break;
		}

		if (reg_val & CPS2023_UFCS_ISR1_HANDSHAKE_SUCC_MASK)
			break;
	}

	(void)cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_SEND_MASK, CPS2023_UFCS_CTL1_SEND_SHIFT, 0);
	(void)cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_EN_HANDSHAKE_MASK,
		CPS2023_UFCS_CTL1_EN_HANDSHAKE_SHIFT, CPS2023_DISABLE_HANDSHAKE);
	mutex_unlock(&di->ufcs_detect_lock);

	if (i == CPS2023_UFCS_HANDSHARK_RETRY_CYCLE) {
		hwlog_err("handshake fail\n");
		return HWUFCS_DETECT_FAIL;
	}

	(void)cps2023_write_mask(di, CPS2023_UFCS_CTL2_REG, CPS2023_UFCS_CTL2_DEV_ADDR_ID_MASK,
		CPS2023_UFCS_CTL2_DEV_ADDR_ID_SHIFT, CPS2023_UFCS_CTL2_SOURCE_ADDR);
	(void)cps2023_write_mask(di, CPS2023_UFCS_CTL4_REG, CPS2023_UFCS_CTL4_CLR_BUF_MASK,
		CPS2023_UFCS_CTL4_CLR_BUF_SHIFT, 1);
	hwlog_info("handshake succ\n");
	err = queue_delayed_work(di->msg_update_wq, &di->ufcs_msg_update_work, 0);
	if (!err) {
		hwlog_err("%s queue_delayed_work failed\n", __func__);
		return HWUFCS_DETECT_OTHER;
	}
	return HWUFCS_DETECT_SUCC;
}

static int cps2023_ufcs_end_read_msg(void *dev_data)
{
	struct cps2023_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}
	di->ufcs_msg_ready_flag = false;
	complete(&di->cps2023_ufcs_read_msg_completion);
	return 0;
}

static int cps2023_ufcs_clear_rx_buff(void *dev_data)
{
	struct cps2023_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;

	(void)cps2023_write_mask(di, CPS2023_UFCS_CTL4_REG, CPS2023_UFCS_CTL4_CLR_BUF_MASK,
		CPS2023_UFCS_CTL4_CLR_BUF_SHIFT, 1);

	cps2023_ufcs_free_node_list(di, false);
	reinit_completion(&di->cps2023_add_msg_completion);
	return cps2023_ufcs_end_read_msg(di);
}

static int cps2023_ufcs_write_msg(void *dev_data, u8 *data, u8 len, u8 flag)
{
	struct cps2023_device_info *di = dev_data;
	int ret, i;
	u8 rd_len = 0;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (len > CPS2023_UFCS_RX_BUF_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	for (i = 0; i < CPS2023_UFCS_TX_CONFLICT_RETRY_TIMES; i++) {
		di->ufcs_irq[0] = 0;
		di->ufcs_irq[1] = 0;
		di->ufcs_irq[2] = 0;

		ret = cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_SEND_MASK,
			CPS2023_UFCS_CTL1_SEND_SHIFT, 0);

		ret |= cps2023_write_byte(di, CPS2023_UFCS_TX_LENGTH_REG, len);
		ret |= cps2023_read_byte(di, CPS2023_UFCS_TX_LENGTH_REG, &rd_len);
		if (rd_len != len)
			ret |= cps2023_write_byte(di, CPS2023_UFCS_TX_LENGTH_REG, len);
		if (len <= CPS2023_UFCS_TX_LENGTH28)
			ret |= cps2023_write_block(di, CPS2023_UFCS_TX_BUFFER_REG, data, len);
		else {
			ret |= cps2023_write_block(di, CPS2023_UFCS_TX_BUFFER_REG, data, CPS2023_UFCS_TX_LENGTH28);
			ret |= cps2023_write_block(di, CPS2023_UFCS_TX_BUFFER28_REG, data + CPS2023_UFCS_TX_LENGTH28,
				len - CPS2023_UFCS_TX_LENGTH28);
		}
		if (ret) {
			hwlog_err("write msg fail\n");
			continue;
		}

		ret = cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_SEND_MASK,
			CPS2023_UFCS_CTL1_SEND_SHIFT, 1);
		if (ret) {
			hwlog_err("write send cmd failed\n");
			continue;
		}

		ret = cps2023_ufcs_wait(di, flag);
		if (ret == CPS2023_UFCS_RX_BUFFER_OVERFLOW_ERROR) {
			cps2023_ufcs_clear_rx_buff(di);
			continue;
		}
		break;
	}

	return ret;
}

static int cps2023_ufcs_wait_msg_ready(void *dev_data, u8 flag)
{
	struct cps2023_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	return cps2023_ufcs_wait(di, flag);
}

static int cps2023_ufcs_get_rx_len(void *dev_data, u8 *len)
{
	struct cps2023_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		*len = 0;
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		reinit_completion(&di->cps2023_ufcs_msg_update_completion);
		if (!wait_for_completion_timeout(&di->cps2023_ufcs_msg_update_completion,
			msecs_to_jiffies(CPS2023_UFCS_WAIT_MSG_UPDATE_TIMEOUT))) {
			hwlog_err("wait for updating msg timeout\n");
			*len = 0;
			return -ETIMEDOUT;
		}
	}

	*len = di->ufcs_pending_msg_len;
	return 0;
}

static int cps2023_ufcs_read_msg(void *dev_data, u8 *data, u8 len)
{
	int ret;
	struct cps2023_device_info *di = dev_data;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		hwlog_err("msg is not ready\n");
		return -EINVAL;
	}

	if (len > CPS2023_UFCS_RX_BUF_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	ret = memcpy_s(data, len, di->ufcs_pending_msg, len);
	if (ret != EOK) {
		hwlog_err("memcpy_s failed\n");
		return -EINVAL;
	}
	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	return 0;
}

void cps2023_ufcs_pending_msg_update_work(struct work_struct *work)
{
	struct cps2023_ufcs_msg_node *msg;
	struct cps2023_device_info *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct cps2023_device_info, ufcs_msg_update_work.work);
	if (!di || !di->client)
		return;

	hwlog_info("start pending msg update work\n");
	/* init msg list */
	cps2023_ufcs_free_node_list(di, true);
	if (cps2023_ufcs_init_msg_head(di)) {
		hwlog_err("msg list init fail\n");
		return;
	}

	reinit_completion(&di->cps2023_add_msg_completion);
	reinit_completion(&di->cps2023_ufcs_read_msg_completion);

	while (1) {
		if (g_cps2023_ufcs_msg_head->num <= 0) {
			if (!wait_for_completion_timeout(&di->cps2023_add_msg_completion, msecs_to_jiffies(CPS2023_UFCS_MSG_TIMEOUT))) {
				hwlog_err("wait for adding msg timeout\n");
				break;
			}
			reinit_completion(&di->cps2023_add_msg_completion);
		}

		msg = cps2023_ufcs_get_msg(di);
		if (!msg) {
			hwlog_err("msg is null\n");
			break;
		}

		di->ufcs_pending_msg_len = msg->len;
		if (!di->ufcs_pending_msg_len || di->ufcs_pending_msg_len > CPS2023_UFCS_RX_BUF_SIZE) {
			hwlog_err("length is %d, invalid\n", di->ufcs_pending_msg_len);
			break;
		}
		(void)memcpy_s(di->ufcs_pending_msg, CPS2023_UFCS_RX_BUF_SIZE, &msg->data[0], di->ufcs_pending_msg_len);
		di->ufcs_msg_ready_flag = true;
		cps2023_ufcs_delete_node(di);
		complete(&di->cps2023_ufcs_msg_update_completion);

		hwlog_info("pending msg updated\n");

		if (!di->ufcs_communicating_flag && di->ufcs_msg_ready_flag)
			power_event_bnc_notify(POWER_BNT_UFCS, POWER_NE_UFCS_REC_UNSOLICITED_DATA, NULL);

		if (!wait_for_completion_timeout(&di->cps2023_ufcs_read_msg_completion, msecs_to_jiffies(CPS2023_UFCS_MSG_TIMEOUT))) {
			hwlog_err("wait for reading msg timeout\n");
			break;
		}
		reinit_completion(&di->cps2023_ufcs_read_msg_completion);
	}

	cps2023_ufcs_free_node_list(di, true);
}

void cps2023_ufcs_cancel_msg_update_work(struct cps2023_device_info *di)
{
	if (!di)
		return;

	complete(&di->cps2023_add_msg_completion);
	complete(&di->cps2023_ufcs_read_msg_completion);
	cancel_delayed_work(&di->ufcs_msg_update_work);
}

static int cps2023_ufcs_soft_reset_master(void *dev_data)
{
	struct cps2023_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	di->ufcs_irq[2] = 0;
	cps2023_ufcs_cancel_msg_update_work(di);
	return cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_EN_PROTOCOL_MASK,
		CPS2023_UFCS_CTL1_EN_PROTOCOL_SHIFT, 0);
}

static int cps2023_ufcs_set_communicating_flag(void *dev_data, bool flag)
{
	struct cps2023_device_info *di = dev_data;

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

static int cps2023_ufcs_config_baud_rate(void *dev_data, int baud_rate)
{
	struct cps2023_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	return cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_BAUD_RATE_MASK,
		CPS2023_UFCS_CTL1_BAUD_RATE_SHIFT, (u8)baud_rate);
}

static int cps2023_ufcs_hard_reset_cable(void *dev_data)
{
	struct cps2023_device_info *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	ret = cps2023_write_mask(di, CPS2023_UFCS_CTL1_REG, CPS2023_UFCS_CTL1_CABLE_HARDRESET_MASK,
		CPS2023_UFCS_CTL1_CABLE_HARDRESET_SHIFT, 1);
	power_usleep(DT_USLEEP_2MS);

	return ret;
}

static bool cps2023_ufcs_need_check_ack(void *dev_data)
{
	return false;
}

static struct hwufcs_ops cps2023_hwufcs_ops = {
	.chip_name = "cps2023",
	.detect_adapter = cps2023_ufcs_detect_adapter,
	.write_msg = cps2023_ufcs_write_msg,
	.wait_msg_ready = cps2023_ufcs_wait_msg_ready,
	.read_msg = cps2023_ufcs_read_msg,
	.end_read_msg = cps2023_ufcs_end_read_msg,
	.clear_rx_buff = cps2023_ufcs_clear_rx_buff,
	.soft_reset_master = cps2023_ufcs_soft_reset_master,
	.get_rx_len = cps2023_ufcs_get_rx_len,
	.set_communicating_flag = cps2023_ufcs_set_communicating_flag,
	.config_baud_rate = cps2023_ufcs_config_baud_rate,
	.hard_reset_cable = cps2023_ufcs_hard_reset_cable,
	.need_check_ack = cps2023_ufcs_need_check_ack,
};

int cps2023_ufcs_ops_register(struct cps2023_device_info *di)
{
	if (di->dts_ufcs_support) {
		cps2023_hwufcs_ops.dev_data = (void *)di;
		return hwufcs_ops_register(&cps2023_hwufcs_ops);
	}

	return 0;
}
