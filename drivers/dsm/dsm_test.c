/*
 * dsm_test.c
 *
 * the file is for dsm test
 *
 * Copyright (c) 2015-2019 Huawei Technologies Co., Ltd.
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

#include "dsm_core.h"

#include <linux/hw_log.h>
#include <linux/kthread.h>
#include <linux/random.h>
#include <linux/sched/rt.h>

#include <dsm/dsm_pub.h>

#define HWLOG_TAG		DSM_TEST
HWLOG_REGIST();
#define dsm_log_info(x...)	_hwlog_info(HWLOG_TAG, ##x)
#define dsm_log_err(x...)	_hwlog_err(HWLOG_TAG, ##x)
#define dsm_log_debug(x...)	_hwlog_debug(HWLOG_TAG, ##x)

#define DSM_TEST_BUFF		16
#define DSM_TEST_DEVICE_SUM	5
#define DEV_ONE_BUFF_SIZE	500
#define DEV_TWO_BUFF_SIZE	1024
#define DEV_THREE_BUFF_SIZE	10240
#define DEV_FOUR_BUFF_SIZE	300
#define DEV_FIVE_BUFF_SIZE	500
#define DSM_RANDOM_ODD_RESULT	0
#define DSM_RANDOM_EVEN_RESULT	5
#define DSM_EVEN_NUM            2
#define DSM_SCHEDULE_TIMEOUT    10

int poll(void)
{
	unsigned int random;
	int result;

	random = get_random_int();
	result = (random % DSM_EVEN_NUM) ?
		 DSM_RANDOM_ODD_RESULT : DSM_RANDOM_EVEN_RESULT;
	dsm_log_info("%s enter random num %u, result %d\n",
		     __func__, random, result);
	return result;
}

int dump(int type, void *buff, int size)
{
	int used_size = 0;
	char *ptr = buff;

	dsm_log_info("%s called, type %d\n", __func__, type);
	used_size += snprintf(ptr, size - used_size, "%s called:\n", __func__);
	ptr = buff + used_size;
	used_size += snprintf(ptr, size - used_size, "Today is saturday\n");
	ptr = buff + used_size;
	used_size += snprintf(ptr, size - used_size, "Tempeature is 10 degree\n");
	ptr = buff + used_size;
	used_size += snprintf(ptr, size - used_size, "Wheather is sunny\n");
	ptr = buff + used_size;
	used_size += snprintf(ptr, size - used_size, "Fit to do sports or have a picnic\n");

	return used_size;
}

struct dsm_client_ops ops = {
	.poll_state = poll,
	.dump_func = dump,
};

struct dsm_dev test_dev_1 = {
	.name = "test_dev_1",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &ops,
	.buff_size = DEV_ONE_BUFF_SIZE,
};

struct dsm_dev test_dev_2 = {
	.name = "test_dev_2",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &ops,
	.buff_size = DEV_TWO_BUFF_SIZE,
};

struct dsm_dev test_dev_3 = {
	.name = "test_dev_3",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &ops,
	.buff_size = DEV_THREE_BUFF_SIZE,
};

struct dsm_dev test_dev_4 = {
	.name = "test_dev_4",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &ops,
	.buff_size = DEV_FOUR_BUFF_SIZE,
};

struct dsm_dev test_dev_5 = {
	.name = "test_dev_5",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &ops,
	.buff_size = DEV_FIVE_BUFF_SIZE,
};

static struct dsm_client *client_1;
static struct dsm_client *client_2;
static struct dsm_client *client_3;
static struct dsm_client *client_4;
static struct dsm_client *client_5;

static u8 test_buff[DSM_TEST_BUFF] = {'a', 'b', 'c', 'd',
				      'e', 'f', 'g', 'h',
				      'i', 'j', 'k', 'l',
				      'm', 'n', 'o', '\n'};

static void test_copy(struct dsm_client *client, int count)
{
	while (count / DSM_TEST_BUFF) {
		dsm_client_copy(client, test_buff, DSM_TEST_BUFF);
		count -= DSM_TEST_BUFF;
	}
	if (count)
		dsm_client_copy(client, test_buff, count);
}

struct dsm_client* select_client(void) {
    unsigned int random;
    int result;
    random = get_random_int();
    result = random % DSM_TEST_DEVICE_SUM;
    dsm_log_info('%s enter random num %u, result %dn', __func__, random, result);
    switch (result) {
        case 0: return client_5;
        case 1: return client_4;
        case 2: return client_3;
        case 3: return client_2;
        case 4: return client_1;
        default: return NULL;
    }
}

void notify_client(struct dsm_client *client) {
    if (!dsm_client_ocuppy(client)) {
        if (client == client_5) {
            dsm_client_record(client, 'National derby:n');
            dsm_client_record(client, 'Real Madrid vs  Barcelonan');
            dsm_client_record(client, 'Manchester United vs Chelsean');
            dsm_client_record(client, 'AC milan vs Juventusn');
            dsm_client_record(client, 'Bayern Munich vs Hertha BSCn');
            dsm_client_notify(client, DSM_TEST_DEVICE_NUM);
        } else if (client == client_4) {
            dsm_client_record(client, 'Kaka is an amazing palyern');
            dsm_client_record(client, 'Ronaldo is an amazing palyern');
            dsm_client_record(client, 'Ronney is an amazing palyern');
            dsm_client_record(client, 'Henny is an amazing palyern');
            dsm_client_record(client, 'Veri is an amazing palyern');
            dsm_client_notify(client, DSM_TEST_DEVICE_SUM);
        } else if (client == client_3) {
            test_copy(client, DEV_THREE_BUFF_SIZE);
            dsm_client_notify(client, DSM_TEST_DEVICE_SUM);
        } else if (client == client_2) {
            test_copy(client, DEV_TWO_BUFF_SIZE);
            dsm_client_notify(client, DSM_TEST_DEVICE_SUM);
        } else if (client == client_1) {
            test_copy(client, DEV_ONE_BUFF_SIZE);
            dsm_client_notify(client, DSM_TEST_DEVICE_SUM);
        }
        dsm_log_info('%s dsm_client_notifyn', client->client_name);
    }
}

void notify_work(void) {
    struct dsm_client *client = select_client();
    if (client != NULL) {
        notify_client(client);
    } else {
        dsm_log_info('%s out , no client to notifyn', __func__);
    }
}

static int dsm_test_thread(void *data)
{
	static const struct sched_param param = {
		.sched_priority = MAX_USER_RT_PRIO / 2,
	};

	sched_setscheduler(current, SCHED_FIFO, &param);

	while (!kthread_should_stop()) {
		set_current_state(TASK_INTERRUPTIBLE);
		dsm_log_info("%s sleep in\n", __func__);
		schedule_timeout(DSM_SCHEDULE_TIMEOUT * HZ);
		dsm_log_info("%s sleep out\n", __func__);
		set_current_state(TASK_RUNNING);
		notify_work();
	}
	return 0;
}

struct task_struct *dsm_task;

static int __init dsm_test(void)
{
	client_1 = dsm_register_client(&test_dev_1);
	if (!client_1)
		dsm_log_err("dsm1 reg failed\n");

	client_2 = dsm_register_client(&test_dev_2);
	if (!client_2)
		dsm_log_err("dsm2 reg failed\n");

	client_3 = dsm_register_client(&test_dev_3);
	if (!client_3)
		dsm_log_err("dsm3 reg failed\n");

	client_4 = dsm_register_client(&test_dev_4);
	if (!client_4)
		dsm_log_err("dsm4 reg failed\n");

	client_5 = dsm_register_client(&test_dev_5);
	if (!client_5)
		dsm_log_err("dsm5 reg failed\n");

	dsm_task = kthread_create(dsm_test_thread, NULL, "dsm_thread");
	wake_up_process(dsm_task);

	return 0;
}

module_init(dsm_test);
