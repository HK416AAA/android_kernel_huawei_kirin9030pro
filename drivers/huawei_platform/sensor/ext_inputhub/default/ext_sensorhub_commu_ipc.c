/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * ext_sensorhub_commu_ipc.c
 *
 * code for ipc communication with sensorhub core
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#include "ext_sensorhub_commu.h"

#include <linux/syscore_ops.h>
#include <linux/syscalls.h>
#include <linux/delay.h>
#include <uapi/linux/sched/types.h>
#include <linux/pm_wakeup.h>
#include <linux/suspend.h>
#include <linux/spinlock.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <linux/preempt.h>

#include <platform_include/smart/linux/base/ap/protocol.h>
#include <platform_include/smart/linux/iomcu_ipc.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/log/hwlog_kernel.h>

#include "securec.h"
#include "ext_sensorhub_frame.h"

#define SID_OFFSET 5
#define CID_OFFSET 6
#define COMMU_MSG_MIN_LEN 9
#define COMMU_IPC_SCHED_PRIORITY 15
#define QUEUE_WORK_RETRY_COUNT 3
#define HWLOG_TAG ext_sensorhub_commu_ipc
HWLOG_REGIST();

struct ext_sensorhub_commu_work {
	struct kthread_work worker;
	unsigned int trans_cnt;
	unsigned int transid;
	unsigned int recvsid;
};

struct ext_sensorhub_commu_list {
	struct list_head list;
	unsigned int transid;
	unsigned int read_cnt;
	unsigned char *buffer;
};

/* enum coumm driver */
static struct commu_data *commu_data_tbl[COMMU_DRIVER_COUNT];
static struct ext_sensorhub_commu_list commu_recv_list_head;
static struct ext_sensorhub_commu_work commu_recv_work_head;
static struct workqueue_struct *ext_ipc_notifier_wq;
static DEFINE_SPINLOCK(ext_ipc_spin_lock);
static bool ext_mcu_first_ready = true;

static int commu_read_check(struct commu_data *commu_data)
{
	enum commu_driver driver = commu_data->driver;

	if (!commu_data->initialed) {
		pr_err("%s driver:%d commu data not init\n", __func__, driver);
		return -EINVAL;
	}

	return 0;
}

ssize_t commu_write(struct commu_data *commu_data, unsigned char *buf, size_t len)
{
	int ret;
	struct write_info winfo;

	if ((!commu_data) || (len == 0) || (!buf))
		return -EINVAL;

	mutex_lock(&commu_data->commu_op_lock);

	if (!commu_data->resumed) {
		pr_err("%s driver:%d is not resumed", __func__);
		mutex_unlock(&commu_data->commu_op_lock);
		return -EACCES;
	}

	ret = memset_s(&winfo, sizeof(winfo), 0, sizeof(winfo));
	if (ret != EOK) {
		hwlog_err("commu write memset_s winfo err\n");
		mutex_unlock(&commu_data->commu_op_lock);
		return -EINVAL;
	}

	winfo.tag = TAG_WEAR_COMMU;
	winfo.cmd = CMD_CMN_IPCSHM_REQ;
	winfo.wr_buf = buf;
	winfo.wr_len = len;

	ret = write_customize_cmd(&winfo, NULL, false);
	if (ret < 0) {
		hwlog_err("commu write error, ret is %d!\r\n", ret);
		mutex_unlock(&commu_data->commu_op_lock);
		return ret;
	}
	mutex_unlock(&commu_data->commu_op_lock);

	return 0;
}

void commu_suspend(enum commu_driver driver)
{
	pr_info("%s: suspend +\n", __func__);
	if (commu_data_tbl[driver] == NULL) {
		pr_err("%s commu_data_tbl[%d] is null", __func__, driver);
		return;
	}
	commu_data_tbl[driver]->resumed = false;
	if (down_interruptible(&commu_data_tbl[driver]->sr_wake_sema))
		pr_err("%s down sr wake sema error", __func__);
	notify_commu_wakeup(false, driver);
	pr_info("%s: suspend -\n", __func__);
}

void commu_resume(enum commu_driver driver)
{
	pr_info("%s: resume +\n", __func__);
	if (commu_data_tbl[driver] == NULL) {
		pr_err("%s commu_data_tbl[%d] is null", __func__, driver);
		return;
	}
	notify_commu_wakeup(true, driver);
	commu_data_tbl[driver]->resumed = true;
	up(&commu_data_tbl[driver]->sr_wake_sema);
	pr_info("%s: resume -\n", __func__);
}

static int commu_handle_response(const struct pkt_header *head, enum commu_driver driver)
{
	int ret = -EFAULT;

	unsigned char *data = (unsigned char *)head + sizeof(struct pkt_header);

	if ((data[0] & 0xF0) == TRANSACTION_ID_APP_IS_DST)
		return encode_send_raw_data(TRANSACTION_ID_RAW_DATA, RAW_DATA_SEREVICE_ID,
				RAW_DATA_COMMAND_ID, data, head->length);

	ret = decode_frame_resp(data, head->length, driver);
	if (ret < 0)
		hwlog_err("%s driver:%d decode resp error: %d", __func__, driver, ret);

	return ret;
}

static int mcu_sys_ready_callback(const struct pkt_header *head)
{
	struct commu_data *commu_data = get_commu_data(IPC_DRIVER);

	if (((pkt_sys_statuschange_req_t *) head)->status == ST_MINSYSREADY) {
		if (ext_mcu_first_ready == false) {
			pr_err("%s mcu is rebooting, clear init flag", __func__);
		} else {
			pr_err("%s mcu is first ready", __func__);
			ext_mcu_first_ready = false;
		}
		notify_mcu_reboot(commu_data->driver);
	}

	return 0;
}

static int commu_transaction_switch(unsigned char *buf, int bufsz)
{
	int ret = -EFAULT;

	if(bufsz <= 0)
		return ret;

	if ((buf[0] & 0xF0) == TRANSACTION_ID_APP_IS_DST) {
		ret = encode_send_raw_data(TRANSACTION_ID_RAW_DATA, RAW_DATA_SEREVICE_ID,
				RAW_DATA_COMMAND_ID, buf, bufsz);
	} else {
		ret = decode_frame_resp(buf, bufsz, IPC_DRIVER);
	}
	if (ret < 0)
		hwlog_err("%s decode resp error: %d", __func__, ret);

    return ret;
}

static void commu_read_worker(struct kthread_work *work)
{
	int ret = -EFAULT;
	unsigned long flags = 0;
	struct commu_data *commu_data = get_commu_data(IPC_DRIVER);
	struct ext_sensorhub_commu_work *work_node = container_of(work,
		struct ext_sensorhub_commu_work, worker);
	struct ext_sensorhub_commu_list *buff_node = NULL;

	if (!work_node) {
		hwlog_err("[%s] work_node is null\n", __func__);
		goto err;
	}
	if (!commu_data || commu_read_check(commu_data) != 0) {
		hwlog_err("[%s] commu_data is null\n", __func__);
		goto err;
	}
	if (list_empty(&commu_recv_list_head.list)) {
		hwlog_err("[%s] commu ipc list is null\n", __func__);
		goto err;
	}

	mutex_lock(&commu_data->commu_op_lock);
	__pm_stay_awake(commu_data->wake_lock);

	spin_lock_irqsave(&ext_ipc_spin_lock, flags);
	buff_node = list_first_entry(&commu_recv_list_head.list,
					struct ext_sensorhub_commu_list, list);
	list_del(&buff_node->list);
	if (commu_recv_work_head.recvsid != buff_node->transid) {
		hwlog_info("%s recvsid 0x%x, wtid:%d, ltid:%d, trans_cnt:%d", __func__,
			commu_recv_work_head.recvsid, work_node->transid, buff_node->transid,
			commu_recv_work_head.trans_cnt);
		commu_recv_work_head.recvsid = buff_node->transid;
	}
	commu_recv_work_head.trans_cnt--;
	commu_recv_work_head.recvsid++;
	spin_unlock_irqrestore(&ext_ipc_spin_lock, flags);

	if (ext_sensorhub_data_print_get()) {
		hwlog_info("%s Tid=0x%x, buff_node_len=0x%x, transid=%d, trans_cnt=%d", __func__,
			buff_node->buffer[0], buff_node->read_cnt, buff_node->transid, commu_recv_work_head.trans_cnt);
	}
	ret = commu_transaction_switch(buff_node->buffer, buff_node->read_cnt);
	mutex_unlock(&commu_data->commu_op_lock);
	__pm_relax(commu_data->wake_lock);

err:
	if (buff_node) {
		kfree(buff_node->buffer);
		kfree(buff_node);
	}
	kfree(work_node);
}

static void commu_queue_work(struct kthread_worker *worker, struct kthread_work *work)
{
	int i;
	bool ret;

	if (!worker || !work)
		return;

	for (i = 0; i < QUEUE_WORK_RETRY_COUNT; ++i) {
		ret = kthread_queue_work(worker, work);
		if (ret)
			break;
		else
			pr_err("[%s] fail to queue work, retry: %d\n", __func__, i);
	}
}

static void process_data_in_irq(const struct pkt_header *head)
{
	unsigned long flags = 0;
	struct commu_data *commu_data = get_commu_data(IPC_DRIVER);
	struct ext_sensorhub_commu_list *buff_node = 0;
	struct ext_sensorhub_commu_work *work_node = 0;
	unsigned char *data = (unsigned char *)head + sizeof(struct pkt_header);

	if (!head || head->length < COMMU_MSG_MIN_LEN) {
		pr_err("[%s] head or work handler len is NULL\n", __func__);
		return;
	}

	hwlog_info("%s: tag:%x, cmd:%x, sid:%x, cid:%x, len:0x%x, transid:%d, trans_cnt:%d\n",
		__func__, head->tag, head->cmd, data[SID_OFFSET], data[CID_OFFSET], head->length,
		commu_recv_work_head.transid, commu_recv_work_head.trans_cnt);

	work_node = kmalloc(sizeof(*work_node), GFP_ATOMIC);
	if (!work_node)
		return;
	buff_node = kmalloc(sizeof(*buff_node), GFP_ATOMIC);
	if (!buff_node) {
		kfree(work_node);
		hwlog_err("%s cannot alloc buff_node", __func__);
		return;
	}

	work_node->transid = commu_recv_work_head.transid;
	buff_node->transid = commu_recv_list_head.transid;
	buff_node->read_cnt = head->length;
	buff_node->buffer = kmalloc(buff_node->read_cnt + 1, GFP_ATOMIC);
	if (!buff_node->buffer) {
		kfree(buff_node);
		kfree(work_node);
		hwlog_err("%s cannot alloc buff_node->buffer", __func__);
		return;
	}
	if (memcpy_s(buff_node->buffer, buff_node->read_cnt,
			data, buff_node->read_cnt) != EOK) {
		kfree(buff_node->buffer);
		kfree(buff_node);
		kfree(work_node);
		return;
	}

	spin_lock_irqsave(&ext_ipc_spin_lock, flags);
	commu_recv_list_head.transid++;
	commu_recv_work_head.transid++;
	commu_recv_work_head.trans_cnt++;
	INIT_LIST_HEAD(&buff_node->list);
	list_add_tail(&buff_node->list, &commu_recv_list_head.list);
	spin_unlock_irqrestore(&ext_ipc_spin_lock, flags);

	kthread_init_work(&work_node->worker, commu_read_worker);
	commu_queue_work(&commu_data->read_kworker, &work_node->worker);
}

int process_data_from_mcu(const struct pkt_header *head)
{
	int ret;
	struct commu_data *commu_data;

	if (!head || head->length == 0) {
		pr_err("[%s] head or work handler len is NULL\n", __func__);
		return -EINVAL;
	}

	commu_data = get_commu_data(IPC_DRIVER);
	if (commu_read_check(commu_data) != 0)
		return -EINVAL;

	if (in_interrupt()) {
		process_data_in_irq(head);
		return 0;
	}

	mutex_lock(&commu_data->commu_op_lock);
	__pm_stay_awake(commu_data->wake_lock);

	hwlog_info("%s: tag:%x, cmd:%x, len:%x\n", __func__,
			head->tag, head->cmd, head->length);

	ret = commu_handle_response(head, commu_data->driver);
	if (ret < 0)
		hwlog_info("handle commu response err no is %d\n", ret);

	mutex_unlock(&commu_data->commu_op_lock);
	__pm_relax(commu_data->wake_lock);

	return 0;
}

static void read_work_init_task(struct commu_data *commu_data)
{
	int ret;
	struct sched_param param = { .sched_priority = COMMU_IPC_SCHED_PRIORITY };

	if (!commu_data) {
		pr_err("%s: commu_data is null, abort init worker", __func__);
		return;
	}

	memset_s(&commu_recv_list_head, sizeof(commu_recv_list_head), 0, sizeof(commu_recv_list_head));
	memset_s(&commu_recv_work_head, sizeof(commu_recv_work_head), 0, sizeof(commu_recv_work_head));
	INIT_LIST_HEAD(&commu_recv_list_head.list);
	spin_lock_init(&ext_ipc_spin_lock);

	kthread_init_worker(&commu_data->read_kworker);
	commu_data->read_kworker_task = kthread_run(
		kthread_worker_fn, &commu_data->read_kworker,
		"%s %d", "read_worker",
		commu_data->driver);
	if (IS_ERR(commu_data->read_kworker_task)) {
		pr_err("%s: failed to create read work task", __func__);
		return;
	}

	ret = sched_setscheduler(commu_data->read_kworker_task,
				 SCHED_FIFO, &param);
	pr_info("%s get init sched_setscheduler ret:%d", __func__, ret);
}

static bool check_resume_irq(struct commu_data *commu_data)
{
	return false;
}

static void record_commu_wakeup(void)
{
	int i;

	for (i = 0; i < COMMU_DRIVER_COUNT; ++i) {
		if (commu_data_tbl[i] && check_resume_irq(commu_data_tbl[i])) {
			pr_info("will record for dubai");
			notify_commu_wakeup(true, i);
			return;
		}
	}
}

static int record_commu_suspend(void)
{
	return 0;
}

static struct syscore_ops dubai_pm_syscore_ops = {
	.resume = record_commu_wakeup,
	.suspend = record_commu_suspend,
};

int commu_init(struct device *dev, struct commu_data *commu_data)
{
	int ret;

	sema_init(&commu_data->sr_wake_sema, 1);
	commu_data->initialed = true;
	commu_data->commu_direct_mode = 0;
	commu_data->resumed = true;
	pr_info("%s begin", __func__);
	mutex_init(&commu_data->commu_op_lock);
	read_work_init_task(commu_data);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	commu_data->wake_lock = wakeup_source_register(NULL, "mcu_commu");
	commu_data->user_wake_lock = wakeup_source_register(NULL, "mcu_user_commu");
	commu_data->at_wake_lock = wakeup_source_register(NULL, "mcu_user_commu_at");
#else
	commu_data->wake_lock = wakeup_source_register("mcu_commu");
	commu_data->user_wake_lock = wakeup_source_register("mcu_user_commu");
	commu_data->at_wake_lock = wakeup_source_register("mcu_user_commu_at");
#endif

	ret = register_mcu_event_notifier(TAG_WEAR_COMMU, CMD_ALL, process_data_from_mcu);
	if (ret < 0)
		hwlog_err("%sregister mcu data callback fail\n", __func__);

	ret = register_mcu_event_notifier(TAG_SYS, CMD_SYS_STATUSCHANGE_REQ, mcu_sys_ready_callback);
	if (ret < 0)
		hwlog_err("%sregister mcu system satatus callback fail\n", __func__);

	return ret;
}

void commu_exit(struct commu_data *commu_data)
{
	int ret = 0;

	ret += unregister_mcu_event_notifier(TAG_WEAR_COMMU, CMD_ALL, process_data_from_mcu);
	ret += unregister_mcu_event_notifier(TAG_SYS, CMD_SYS_STATUSCHANGE_REQ, mcu_sys_ready_callback);
	if (ret)
		hwlog_err("%s commu exit unregister error\n", __func__);
	wakeup_source_unregister(commu_data->user_wake_lock);
	wakeup_source_unregister(commu_data->wake_lock);
	wakeup_source_unregister(commu_data->at_wake_lock);
}

/* for global init */
void ext_sensorhub_commu_init(void)
{
	int i;

	/* init NULL */
	for (i = 0; i < COMMU_DRIVER_COUNT; ++i)
		commu_data_tbl[i] = NULL;

	register_syscore_ops(&dubai_pm_syscore_ops);
}

/* for global exit */
void ext_sensorhub_commu_exit(void)
{
	unregister_syscore_ops(&dubai_pm_syscore_ops);
}

static void commu_data_ipc_init(struct commu_data *commu_data)
{
	if (!commu_data)
		return;

	commu_data->commu_ops.op_commu_init = NULL;
	commu_data->commu_ops.op_commu_exit = NULL;
	commu_data->commu_ops.op_read_count = NULL;
	commu_data->commu_ops.op_commu_read = NULL;
	commu_data->commu_ops.op_write_count = NULL;
	commu_data->commu_ops.op_commu_write = NULL;
	commu_data->commu_ops.op_commu_rx_irq = NULL;
	commu_data->commu_ops.op_commu_wake_irq = NULL;
	commu_data->commu_ops.op_read_ready = NULL;
	commu_data->commu_ops.op_write_ready = NULL;
	commu_data->driver = IPC_DRIVER;
	commu_data->active_handshake = 1;
}

static bool init_commu_data(enum commu_driver driver)
{
	struct commu_data *commu_data = NULL;

	if (commu_data_tbl[driver])
		return true;

	commu_data = kmalloc(sizeof(*commu_data), GFP_KERNEL);
	if (!commu_data)
		return false;

	commu_data_ipc_init(commu_data);

	commu_data_tbl[driver] = commu_data;
	return true;
}

static void init_commu_driver(void)
{
	static int once;

	if (once)
		return;
	once = 1;

	if (!init_commu_data(IPC_DRIVER))
		once = 0;
}

struct commu_data *get_commu_data(enum commu_driver driver)
{
	init_commu_driver();

	return commu_data_tbl[driver];
}
