/* SPDX-License-Identifier: GPL-2.0
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2024. All rights reserved.
 *
 * data_transfer.c
 *
 * source file for data transfer steps
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
#include "data_transfer.h"
#include "ext_sensorhub_channel.h"
#include "inner_event.h"

#include "securec.h"
#include <linux/slab.h>
#include <linux/types.h>
#include <huawei_platform/log/hw_log.h>

#define ACK_PACKAGE_COUNT 8

#define HWLOG_TAG file_trans
HWLOG_REGIST();

static bool mark_offset_mismatch(struct transfer_file *pfile, u32 offset)
{
	if (pfile->c_offset == offset)
		return false;

	hwlog_warn("%s receive:%d offset not match:%d", __func__, offset, pfile->c_offset);
	return true;
}

static int wait_data_ack(struct transfer_worker *worker, struct transfer_file *file, int read_count)
{
	int ret;
	int rfd = worker->record->rfd;
	struct work_event *work_event = NULL;
	struct transfer_data_ack *data_ack_event = NULL;
	u32 aim_flag = FILE_TRANS_DATA_PCK | FILE_TRANS_ACK;

	/*
	 * need wait ack, the flag set when send transfer data
	 * 1. every ACK_PACKAGE_COUNT packages
	 * 2. the last package
	 */
	if (read_count % ACK_PACKAGE_COUNT != 0 && file->state != END)
		return 0;

	hwlog_info("%s rfd:%08x wait data ack", __func__, rfd);
	/* 1. try to wait for data ack event */
	ret = wait_event_interruptible_timeout(worker->event_wait, !list_empty(&worker->list),
					       msecs_to_jiffies(WAIT_REMOTE_TIMEOUT));
	if (ret <= 0) {
		hwlog_err("%s rfd:%08x wait data err", __func__, rfd);
		return -ETIME;
	}
	/* 2. event list is not empty and get from event list */
	mutex_lock(&worker->list_lock);
	work_event = list_first_entry(&worker->list, struct work_event, list);
	if (work_event)
		list_del(&work_event->list);
	mutex_unlock(&worker->list_lock);
	/* 3. check event is valid */
	if (!work_event || !work_event->data ||
	    work_event->data_len < sizeof(struct transfer_data_ack)) {
		ret = -EINVAL;
		goto out;
	}
	/* 4. check is a data ack package by transfer flag(need to check data error flag) */
	data_ack_event = (struct transfer_data_ack *)(work_event->data);
	if ((data_ack_event->transfer_flag & aim_flag) != aim_flag) {
		ret = -EINVAL;
		goto out;
	}
	ret = 0;
out:
	if (work_event) {
		kfree(work_event->data);
		kfree(work_event);
	}
	return ret;
}

#ifdef CONFIG_EXT_INPUTHUB_FILETRANSFER_SHAREMEM
static int transfer_data_form_sharermem(struct transfer_worker *worker,
	unsigned char *transfer_buff, int transfer_len, int *read_count)
{
	int ret = 0;
	int rfd = worker->record->rfd;
	struct transfer_file *read_file = worker->file;
	struct transfer_data *trans_data = worker->trans_data;

	if (!read_file || !trans_data || !transfer_buff || !read_count)
		return -EINVAL;
	hwlog_info("%s send len %d, offset:%d, des offset:%d, read count:%d", __func__,
		transfer_len, read_file->c_offset, read_file->dst_offset, *read_count);

	while (transfer_len) {
		if (transfer_len > PACKAGE_READ_LEN)
			trans_data->data_len = PACKAGE_READ_LEN;
		else
			trans_data->data_len = transfer_len;
		*read_count += 1;
		transfer_len -= trans_data->data_len;
		read_file->c_offset += trans_data->data_len;
		trans_data->offset = read_file->dst_offset;
		read_file->dst_offset += trans_data->data_len;
		ret = memcpy_s(trans_data->data, PACKAGE_READ_LEN, transfer_buff, trans_data->data_len);
		if (ret != EOK)
			return -EFAULT;
		hwlog_debug("%s send info cnt %d, offset %d, len %d, left len %d", __func__,
			*read_count, trans_data->offset, trans_data->data_len, transfer_len);

		if (read_file->c_offset >= (read_file->offset + read_file->len)) {
			hwlog_info("%s file is end, now offset:%u, file len:%u", __func__,
				read_file->c_offset, read_file->len);
			read_file->state = END;
		}
		transfer_buff += trans_data->data_len;
		trans_data->transfer_flag = FILE_TRANS_DATA_PCK;
		if ((*read_count % ACK_PACKAGE_COUNT == 0) || (read_file->state == END))
			trans_data->transfer_flag |= FILE_TRANS_NEED_ACK;
		/* send transfer data to remote */
		ret = send_transfer_requeset(worker->transfer_type, trans_data, sizeof(*trans_data));
		if (ret < 0) {
			hwlog_info("%s rfd:%08x send file data:%d", __func__, rfd, ret);
			return ret;
		}
		/* wait if need ack */
		ret = wait_data_ack(worker, read_file, *read_count);
		if (ret < 0)
			return ret;
	}

	return 0;
}

int transfer_file_data(struct transfer_worker *worker)
{
	int ret = 0;
	int read_count = 0;
	int rfd = worker->record->rfd;
	struct work_event *work_event = NULL;
	struct transfer_data *data_event = NULL;
	struct transfer_file *read_file = worker->file;
	struct transfer_data *trans_data = worker->trans_data;
	unsigned char *share_mem = get_read_map_mem(&ret);

	if (!read_file || !trans_data || !share_mem)
		return -EINVAL;

	/* transfer to the end */
	while (read_file->state != END) {
		/* try to get event data */
		transfer_inner_event_status(worker, TRANS_STATUS_DATA_SEND);
		ret = wait_event_interruptible_timeout(worker->event_wait,
						       !list_empty(&worker->list),
						       msecs_to_jiffies(WAIT_REMOTE_TIMEOUT));
		if (ret <= 0) {
			hwlog_err("%s rfd:%08x wait file data err:%d", __func__, rfd, ret);
			ret = -ETIME;
			break;
		}

		/* get commu event data */
		mutex_lock(&worker->list_lock);
		work_event = list_first_entry(&worker->list, struct work_event, list);
		if (work_event)
			list_del(&work_event->list);
		mutex_unlock(&worker->list_lock);
		data_event = (struct transfer_data *)(work_event->data);
		if (mark_offset_mismatch(read_file, data_event->offset))
			break;

		/* transfer sharermem data */
		ret = transfer_data_form_sharermem(worker, share_mem,
			data_event->data_len, &read_count);
		if (ret < 0)
			break;
		kfree(data_event);
	}
	/* release file resource */
	kfree(trans_data->data);
	trans_data->data = NULL;
	kfree(trans_data);
	worker->trans_data = NULL;
	release_transfer_file(read_file);
	worker->file = NULL;

	return ret;
}
#else
int transfer_file_data(struct transfer_worker *worker)
{
	int ret = 0;
	int read_count = 0;
	int rfd = worker->record->rfd;
	struct transfer_file *read_file = worker->file;
	struct transfer_data *trans_data = worker->trans_data;

	if (!read_file || !trans_data) {
		hwlog_info("%s rfd:%08x invalid file to read", __func__, rfd);
		return -EINVAL;
	}
	/* transfer to the end */
	while (read_file->state != END) {
		ret = read_file->data_process(read_file, trans_data->data, PACKAGE_READ_LEN);
		if (ret <= 0) {
			hwlog_err("%s rfd:%08x process file data error:%d", __func__, rfd, ret);
			ret = -EFAULT;
			break;
		}

		read_count++;
		trans_data->transfer_flag = FILE_TRANS_DATA_PCK;
		/*
		 * set need ack flag to avoid overflow, need wait ack later
		 * 1. every ACK_PACKAGE_COUNT packages
		 * 2. the last package
		 */
		if (read_count % ACK_PACKAGE_COUNT == 0 || read_file->state == END)
			trans_data->transfer_flag |= FILE_TRANS_NEED_ACK;
		trans_data->data_len = ret;
		trans_data->offset = read_file->dst_offset - trans_data->data_len;
		/* send transfer data to remote */
		ret = send_transfer_requeset(worker->transfer_type,
					     trans_data, sizeof(*trans_data));
		if (ret < 0) {
			hwlog_info("%s rfd:%08x send file data:%d", __func__, rfd, ret);
			break;
		}
		/* wait if need ack */
		ret = wait_data_ack(worker, read_file, read_count);
		if (ret < 0)
			break;
	}
	/* release file resource */
	kfree(trans_data->data);
	trans_data->data = NULL;
	kfree(trans_data);
	worker->trans_data = NULL;

	release_transfer_file(read_file);
	worker->file = NULL;

	return ret;
}
#endif

static int send_data_ack(enum transfer_type type,
			 struct work_event *work_event, struct transfer_data *data_event)
{
	int ret;
	struct transfer_data_ack data_ack;

	/* check transfer flag */
	if ((data_event->transfer_flag & FILE_TRANS_NEED_ACK) == 0) {
		ret = 0;
		goto end;
	}

	data_ack.rfd = data_event->rfd;
	data_ack.offset = data_event->offset;
	data_ack.data_len = data_event->data_len;
	data_ack.transfer_flag = FILE_TRANS_DATA_PCK | FILE_TRANS_ACK;

	ret = send_transfer_requeset(type, &data_ack, sizeof(data_ack));
	if (ret < 0)
		hwlog_err("%s send ack err:%d", __func__, ret);
end:
	kfree(data_event->data);
	data_event->data = NULL;
	kfree(work_event->data);
	work_event->data = NULL;
	kfree(work_event);
	return ret;
}

#ifdef CONFIG_EXT_INPUTHUB_FILETRANSFER_SHAREMEM
static int receive_data_to_sharemem(struct transfer_worker *worker,
	struct transfer_data *event, unsigned char *data_buff, int *write_count)
{
	int ret;
	static int data_offset;
	unsigned int transfer_maxcnt = 0;
	struct transfer_file *write_file = worker->file;
	unsigned char *share_mem = get_write_map_mem(&ret);

	transfer_maxcnt = ret / (PACKAGE_READ_LEN * ACK_PACKAGE_COUNT) * ACK_PACKAGE_COUNT;
	if (!write_file || !share_mem || !event || !data_buff || !write_count)
		return -EFAULT;

	/* check transfer flag is data ack (need check error flag) */
	if ((event->transfer_flag & FILE_TRANS_DATA_PCK) != FILE_TRANS_DATA_PCK)
		return -EPERM;
	/* receive data from remote (need check aim data offset) */
	if (mark_offset_mismatch(write_file, event->offset))
		return -EPERM;
	if (*write_count % transfer_maxcnt == 0)
		data_offset = 0;
	hwlog_debug("%s recv cnt %d, offset %d, len:%d, data_offset %d", __func__,
		*write_count, event->offset, event->data_len, data_offset);

	/* recv the data packet. */
	ret = memcpy_s(data_buff + data_offset, event->data_len, event->data, event->data_len);
	if (ret != EOK)
		return ret;
	write_file->c_offset += event->data_len;
	data_offset += event->data_len;
	*write_count += 1;

	/* Notify the Commux to recv the data packet. */
	if (write_file->c_offset >= (write_file->offset + write_file->len)) {
		hwlog_info("%s file is end, now offset:%u, file len:%u", __func__,
			write_file->c_offset, write_file->len);
		write_file->state = END;
	}
	if ((*write_count % transfer_maxcnt == 0) || (write_file->state == END)) {
		hwlog_info("%s write info offset:%u, write len:%u, cnt:%d", __func__,
				write_file->c_offset - data_offset, data_offset, *write_count);
		ret = memcpy_s(share_mem, data_offset, data_buff, data_offset);
		if (ret != EOK)
			return -EFAULT;
		worker->record->trans_info->file.src_offset = write_file->c_offset - data_offset;
		worker->record->trans_info->file.data_len = data_offset;
		transfer_inner_event_status(worker, TRANS_STATUS_DATA_RECV);
	}

	return 0;
}

int receive_transfer_data(struct transfer_worker *worker)
{
	int ret;
	int rfd = worker->record->rfd;
	unsigned int write_count = 0;
	struct work_event *work_event = NULL;
	struct transfer_data *data_event = NULL;
	struct transfer_file *write_file = worker->file;
	unsigned char *share_mem = get_write_map_mem(&ret);
	unsigned char *recv_buff = get_share_map_mem(&ret);

	if (!write_file || !share_mem || !recv_buff)
		return -EFAULT;

	/* receive to the aim length */
	while (write_file->state != END) {
		/* 1. try to get event data */
		ret = wait_event_interruptible_timeout(worker->event_wait,
			!list_empty(&worker->list), msecs_to_jiffies(WAIT_REMOTE_TIMEOUT));
		if (ret <= 0) {
			hwlog_err("%s rfd:%08x wait file data err:%d", __func__, rfd, ret);
			ret = -ETIME;
			break;
		}
		mutex_lock(&worker->list_lock);
		work_event = list_first_entry(&worker->list, struct work_event, list);
		if (work_event)
			list_del(&work_event->list);
		mutex_unlock(&worker->list_lock);
		/* 2. check data valid */
		if (!work_event || !work_event->data ||
		    work_event->data_len < sizeof(struct transfer_data))
			break;
		data_event = (struct transfer_data *)(work_event->data);
		/* 3. recv data to save share mem */
		ret = receive_data_to_sharemem(worker, data_event, recv_buff, &write_count);
		if (ret < 0)
			break;
		/* 4. send data ack if transfer flag mark */
		ret = send_data_ack(worker->transfer_type, work_event, data_event);
		work_event = NULL;
		data_event = NULL;
		if (ret < 0)
			break;
	}
	/* 4. release file resource */
	if (data_event)
		kfree(data_event->data);
	if (work_event) {
		kfree(work_event->data);
		work_event->data = NULL;
	}
	kfree(work_event);
	release_transfer_file(write_file);
	worker->file = NULL;

	return ret;
}
#else
int receive_transfer_data(struct transfer_worker *worker)
{
	int ret;
	int rfd = worker->record->rfd;
	struct work_event *work_event = NULL;
	struct transfer_data *data_event = NULL;
	struct transfer_file *write_file = worker->file;

	if (!write_file)
		return -EFAULT;

	/* receive to the aim length */
	while (write_file->state != END) {
		/* 1. try to get event data */
		ret = wait_event_interruptible_timeout(worker->event_wait,
						       !list_empty(&worker->list),
						       msecs_to_jiffies(WAIT_REMOTE_TIMEOUT));
		if (ret <= 0) {
			hwlog_err("%s rfd:%08x wait file data err:%d", __func__, rfd, ret);
			return -ETIME;
		}
		mutex_lock(&worker->list_lock);
		work_event = list_first_entry(&worker->list, struct work_event, list);
		if (work_event)
			list_del(&work_event->list);
		mutex_unlock(&worker->list_lock);
		/* 2. check data valid */
		ret = -EINVAL;
		if (!work_event || !work_event->data ||
		    work_event->data_len < sizeof(struct transfer_data))
			break;

		/* 3. check transfer flag is data ack (need check error flag) */
		data_event = (struct transfer_data *)(work_event->data);
		if ((data_event->transfer_flag & FILE_TRANS_DATA_PCK) != FILE_TRANS_DATA_PCK)
			break;

		/* 4. receive data from remote (need check aim data offset) */
		if (mark_offset_mismatch(write_file, data_event->offset))
			break;
		if (write_file->data_process(write_file, data_event->data,
			data_event->data_len) <= 0)
			break;
		/* 5. send data ack if transfer flag mark */
		ret = send_data_ack(worker->transfer_type, work_event, data_event);
		work_event = NULL;
		data_event = NULL;
		if (ret < 0)
			break;
	}
	/* 6. release file resource */
	if (data_event)
		kfree(data_event->data);
	if (work_event) {
		kfree(work_event->data);
		work_event->data = NULL;
	}
	kfree(work_event);
	release_transfer_file(write_file);
	worker->file = NULL;

	return ret;
}
#endif
