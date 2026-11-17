/*
* Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "wifi_audio_ptp_ext.h"

static int get_delay_event_id(const struct ptp_dev *dev,
	unsigned char data)
{
	int id;
	if (dev == NULL) {
		wifi_audio_log_err("dev is NULL Pointer");
		return PTP_EVENT_ID_MAX;
	}
	switch (data) {
	case DELAY_REQ: {
		if (dev->role == PTP_MASTER)
			id = PTP_RECEIVE_DELAY_REQUEST;
		else
			id = PTP_EVENT_ID_MAX;
		break;
	}
	case DELAY_RESP: {
		if (dev->role == PTP_SLAVE)
			id = PTP_RECEIVE_DELAY_RESPONSE;
		else
			id = PTP_EVENT_ID_MAX;
		break;
	}
	case SYNC_DONE: {
		if (dev->role == PTP_MASTER)
			id = PTP_RECEIVE_SYNC_DONE;
		else
			id = PTP_EVENT_ID_MAX;
		break;
	}
	default:
		id = PTP_EVENT_ID_MAX;
		break;
	}
	return id;
}

int get_ptp_event_data_id(const struct ptp_dev *dev,
	unsigned char data)
{
	int id;
	if (dev == NULL) {
		wifi_audio_log_err("dev is NULL Pointer");
		return PTP_EVENT_ID_MAX;
	}
	switch (data) {
	case SYNC_REQ: {
		if (dev->role == PTP_MASTER)
			id = PTP_SEND_SYNC_REQUEST;
		else if (dev->role == PTP_SLAVE)
			id = PTP_RECEIVE_SYNC_REQUEST;
		else
			id = PTP_EVENT_ID_MAX;
		break;
	}
	case DELAY_REQ:
	case DELAY_RESP:
	case SYNC_DONE: {
		id = get_delay_event_id(dev, data);
		break;
	}
	case RESTART_TIME_SYNC: {
		if (dev->role == PTP_SLAVE)
			id = PTP_RECEIVE_RESTART_TIME_SYNC;
		else
			id = PTP_EVENT_ID_MAX;
		break;
	}
	case STOP_TIME_SYNC: {
		if ((dev->role == PTP_SLAVE) || (dev->role == PTP_MASTER))
			id = PTP_RECEIVE_STOP_TIME_SYNC;
		else
			id = PTP_EVENT_ID_MAX;
		break;
	}
	default:
		id = PTP_EVENT_ID_MAX;
		break;
	}
	return id;
}