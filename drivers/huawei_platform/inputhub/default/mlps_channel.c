/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2024. All rights reserved.
 * Description: mlps channel source file
 * Author: jiangzimu <jiangzimu@huawei.com>
 * Create: 2022-02-16
 */

#include "mlps_channel.h"

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/timer.h>

#include "contexthub_boot.h"
#include "contexthub_ext_log.h"
#include "contexthub_recovery.h"
#include "contexthub_route.h"
#include "sensor_info.h"
#include <securec.h>
#include <platform_include/smart/linux/base/ap/protocol.h>

#include "teek_client_api.h"

#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>
#include <linux/skbuff.h>
#include <linux/net.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <linux/inet.h>
#include <linux/if_ether.h>
#include <linux/string.h>
#include <linux/pm_wakeup.h>
#include <net/ip6_route.h>
#include <net/dst.h>
#ifdef CONFIG_HEADER_FILE_REPLACE_EXTRACT
#include <iomcu_mem.h>
#else
#include <iomcu_ddr_map.h>
#endif
#ifdef CONFIG_DFA_MCQ_OHOS
#include <platform_include/basicplatform/linux/ufs/dfa_multicore_ops.h>
#endif
#ifdef CONFIG_CONTEXTHUB_MINIFS
#include <platform_include/smart/linux/base/ap/minifs/minifs.h>
#endif

#define MLPS_TA_UUID { 0x53933180, 0xc8b0, 0x4a83, \
	{ 0x88, 0xd7, 0x8c, 0x76, 0xd2, 0x11, 0x7d, 0x19 } }

typedef enum {
	MLPS_WORK_GNSS = 1,
	MLPS_WORK_TA,
	MLPS_WORK_WIFI,
	MLPS_WORK_WIFI_SEND,
} mlps_work_queue_type;


int32_t(*mlps_ops_conn_function[MAX_CONN_FUNCTION_NUM])(int32_t uart);

static struct workqueue_struct *g_mlps_wq = NULL;

struct mlps_work_t {
	struct work_struct worker;
	int work_type;
	int cmd;
	int service;
	int data_len;
	void *data;
};

struct mlps_cmd_map {
	int mlps_ioctl_app_cmd;
	int tag;
	enum obj_cmd cmd;
};

struct mlps_sucmd_map {
	mlps_app_type_t type;
	enum obj_sub_cmd subcmd;
};
static bool g_support_conn_operation = false;
static int g_gnss_status = MLPS_WAIT_GNSS_OPERATION;
static const uint8_t g_dev_name[] = "wlan0";
static int64_t g_mlps_ref_cnt;
static unsigned int g_mlps_app_bit_map = 0;
static unsigned int g_outside_app_bit_map = 0;
static bool g_privacy_mode = false;
static bool g_palace_mode = false;
static unsigned int g_privacy_timer_retry = 0;
static unsigned int g_get_ipv6_retry_cnt = 0;
static TEEC_Context g_mlps_context = {0};
static TEEC_Session g_mlps_session = {0};
static const u8 *g_mlps_package_name = "/dev/mlpskernel_ca";
static u32 g_uid = 0u;
struct timer_list privacy_gnss_timer;
struct timer_list get_ipv6_timer;
struct timer_list get_ipv4_timer;
static uint8_t g_get_ipaddr_cmd = 0;
static unsigned char push_ipv6_daddr[IPV6_ADDR_LEN];
static struct wakeup_source *mlps_wl;
static uint8_t g_push_gnss_status = ST_PUSH_DEFAULT;
static uint8_t g_push_link_status[2] = {0}; // 0  ipv4  1 ipv6
static push_proxy_start_req_t start_req = { 0 };
static spinlock_t link_hook_lock;
static push_wf_hook_v4_filter g_v4_f[PUSH_LINK_MAX - PUSH_LINK_1] = { 0 };
static push_wf_hook_v6_filter g_v6_f[PUSH_LINK_MAX - PUSH_LINK_1] = { 0 };
static push_version_t g_push_version = {
	.app_type           = APP_PUSHPROXY,
	.push_proxy_version = 0,
	.push_cloud_version = 0,
};
static softbus_version_t g_softbus_version = {
	.app_type           = APP_SOFTBUS,
	.softbus_version    = 0,
	.rsv                = 0
};
static app_version_t g_am_version = {
	.app_type           = APP_HMSCORE,
	.version1           = 0,
	.version2           = 0,
};
static app_version_t g_nearlink_version = {
	.app_type           = APP_NEARLINK,
	.version1           = 0,
	.version2           = 0,
};
static const struct mlps_cmd_map mlps_cmd_map_tab[] = {
	{ MLPS_IOCTL_MLPS_START, TAG_MLPS, CMD_CMN_OPEN_REQ },
	{ MLPS_IOCTL_MLPS_STOP, TAG_MLPS, CMD_CMN_CLOSE_REQ },
	{ MLPS_IOCTL_MLPS_ATTR_START, TAG_MLPS, CMD_CMN_CONFIG_REQ },
	{ MLPS_IOCTL_MLPS_ATTR_STOP, TAG_MLPS, CMD_CMN_CONFIG_REQ },
	{ MLPS_IOCTL_MLPS_INTERVAL_SET, TAG_MLPS, CMD_CMN_INTERVAL_REQ },
};
#ifdef CONFIG_MLPS_PL_FEATURE
static bool g_map_trajectory_recording_switch = false;
#endif
static int send_mlps_cmd_ext(void *data, ssize_t len,
	struct read_info *pkg_mcu, bool use_lock);
static ssize_t upload_mlps_data(char *data, ssize_t len);
static void mlps_work_handle(struct work_struct *work);

static unsigned int bit_check(unsigned int *map, unsigned int bit)
{
	return ((*map) & ((unsigned int)BIT_1 << ((bit) % MLPS_BIT_MAP_SIZE)));
}

static void bit_set(unsigned int *map, unsigned int bit)
{
	*map |= ((unsigned int)BIT_1 << ((bit) % MLPS_BIT_MAP_SIZE));
	return;
}

static void bit_clear(unsigned int *map, unsigned int bit)
{
	*map &= ~((unsigned int)BIT_1 << ((bit) % MLPS_BIT_MAP_SIZE));
	return;
}

int get_mlps_operate_gnss_status(void)
{
	return g_gnss_status;
}

static int mlps_ops_conn_function_echo(int uart)
{
	hwlog_info("%s enter\n", __func__);
	return MLPS_OPERATE_GNSS_SUCCESS;
}

static void mlps_ops_conn_function_init(void)
{
	int i;

	for (i = 0; i < MAX_CONN_FUNCTION_NUM; i++)
		mlps_ops_conn_function[i] = mlps_ops_conn_function_echo;
}

int mlps_ops_conn_function_register(unsigned int tag, connectivity_callback func)
{
	hwlog_info("%s enter\n", __func__);
	if (func == NULL  || tag >= MAX_CONN_FUNCTION_NUM) {
		hwlog_err("%s,register function is null or tag is error\n", __func__);
		return FAIL;
	}

	if (mlps_ops_conn_function[tag] != mlps_ops_conn_function_echo) {
		hwlog_err("CallbackExist:%u\n", tag);
		return FAIL;
	}

	mlps_ops_conn_function[tag] = func;
	hwlog_info("%s success\n", __func__);
	return SUCCESS;
}
EXPORT_SYMBOL(mlps_ops_conn_function_register);

static void mlps_errno_to_push_service(int event_id, int errno, int ext)
{
	mlps_push_err_t err_data = {
		.mlps_app_type = APP_PUSHPROXY,
		.app_len = sizeof(mlps_push_err_t) - DATA_LEN_4,
		.mlps_module_type = 0,
		.module_len = sizeof(mlps_push_err_t) - DATA_LEN_8,
		.config_type = MLPS_CMD_UPLOAD,
		.config_len = sizeof(mlps_push_err_t) - DATA_LEN_12,
		.cmd = PUSH_WARN_IND,
		.cmd_len = sizeof(mlps_push_err_t) - DATA_LEN_16,
		.warnmsgcnt = 1,
		.time = 0,
		.event = event_id,
		.reason = errno,
		.subreason = ext,
		.len = 0,
	};

	upload_mlps_data((char *)&err_data, sizeof(mlps_push_err_t));
	hwlog_info("%s event = %d, reason = %d, subreason = %d\n",
		__func__, err_data.event, err_data.reason, err_data.subreason);
}

static int mlps_privacy_open_ta_session(void)
{
	TEEC_Result result;
	TEEC_Operation op;
	TEEC_UUID uuid = MLPS_TA_UUID;
/* 1. initialize context */
	result = TEEK_InitializeContext(NULL, &g_mlps_context);
	if (result != TEEC_SUCCESS) {
		hwlog_err("%s teec initial failed", __func__);
		return FAIL;
	}
	hwlog_info("%s teec initial done", __func__);

/* 2. open session */
	u32 err_origin = 0;
	if (memset_s(&op, sizeof(op), 0, sizeof(op)) != EOK) {
		hwlog_err("%s memset_s failed", __func__);
		TEEK_FinalizeContext(&g_mlps_context);
		return FAIL;
	}

	// prepare operation parameters
	op.started = SESSION_START_DEFAULT;
	// params[2] is TEEC_MEMREF_TEMP_INPUT
	op.params[TEE_PARAM_2].tmpref.buffer = (void *)&g_uid;
	op.params[TEE_PARAM_2].tmpref.size = sizeof(g_uid);
	// params[3] is TEEC_MEMREF_TEMP_INPUT
	op.params[TEE_PARAM_3].tmpref.buffer = (void *)g_mlps_package_name;
	op.params[TEE_PARAM_3].tmpref.size = strlen(g_mlps_package_name) + 1;
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE,
		TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT);
	// Open a session to the TA
	result = TEEK_OpenSession(&g_mlps_context, &g_mlps_session, &uuid,
			TEEC_LOGIN_IDENTIFY, NULL, &op, &err_origin);
	if (result != TEEC_SUCCESS) {
		hwlog_err("%s open session=%d and err_origin is %u",
			__func__, result, err_origin);
		TEEK_FinalizeContext(&g_mlps_context);
		return FAIL;
	}

	return SUCCESS;
}

static void mlps_privacy_invoke_ta(void)
{
	TEEC_Result result;
	TEEC_Operation op_invoke;
	u32 err_origin = 0;
/* 3. set in buffer and out buffer */
	if (memset_s(&op_invoke, sizeof(op_invoke), 0, sizeof(op_invoke)) != EOK) {
		hwlog_err("%s memset_s failed", __func__);
		return;
	}
	op_invoke.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT,
		TEEC_VALUE_OUTPUT, TEEC_NONE, TEEC_NONE);
	op_invoke.started = SESSION_START_DEFAULT;
	op_invoke.params[TEE_PARAM_0].value.a = MLPS_NOTIFY_TA;
/* 4. invoke command to ta */
	result = TEEK_InvokeCommand(&g_mlps_session,
		NOTIFY_HAL_READY_CMD_ID, &op_invoke, &err_origin);
	if (result != TEEC_SUCCESS) {
		hwlog_err("%s TEEK_InvokeCommand failed res=0x%x orig=0x%x \n",
			__func__, result, err_origin);
		return;
	}
	hwlog_info("%s TEEK_InvokeCommand called successfully %d",
		__func__, op_invoke.params[TEE_PARAM_1].value.a);
}

static void mlps_privacy_op_ta(void)
{
	int ret = mlps_privacy_open_ta_session();
	if (ret == FAIL)
		return;

	mlps_privacy_invoke_ta();

	TEEK_CloseSession(&g_mlps_session);
	TEEK_FinalizeContext(&g_mlps_context);
}

static void mlps_privacy_notify_ta(void)
{
	struct mlps_work_t *ta_work = NULL;
	ta_work = kzalloc(sizeof(struct mlps_work_t), GFP_ATOMIC);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)ta_work)) {
		pr_err("[%s] alloc gnss_work failed.\n", __func__);
		return;
	}

	ta_work->work_type = MLPS_WORK_TA;
	ta_work->cmd = 0;
	ta_work->service = 0;
	ta_work->data_len = 0;
	ta_work->data = NULL;

	INIT_WORK(&ta_work->worker, mlps_work_handle);
	queue_work(g_mlps_wq, &ta_work->worker);
}

static void mlps_notify_pushproxy_open_gnss(unsigned short op_ret)
{
	char *data = (char *)kzalloc(DATA_LEN_16 + SUBCMD_LEN, GFP_KERNEL);
	if (data == NULL) {
		hwlog_err("%s data kzalloc fail\n", __func__);
		return;
	}

	pkt_mlps_sub_header_t *temp = (pkt_mlps_sub_header_t *)data;
	temp->subcmd = SUB_CMD_MLPS_CONFIG_REQ;
	pkt_mlps_detail_data_t *tmp = (pkt_mlps_detail_data_t *)temp->value;
	tmp->mlps_app_type = APP_PUSHPROXY;
	tmp->app_len = DATA_LEN_12;
	tmp->mlps_module_type = 0;
	tmp->module_len = DATA_LEN_8;
	tmp->mlps_cmd = MLPS_CMD_CONFIG;
	tmp->cmd_len = DATA_LEN_4;
	pkt_mlps_cmd_data_t *value = (pkt_mlps_cmd_data_t *)tmp->value;
	value->cmd = op_ret;
	value->cmd_len = 0;
	hwlog_info("%s send opt 0x%x\n", __func__, op_ret);
	int ret = send_mlps_cmd_ext(data, DATA_LEN_16, NULL, true);

	if (data != NULL) {
		kfree(data);
		data = NULL;
	}
}

static void mlps_notify_pushproxy_opt_gnss(unsigned int cmd)
{
	if (cmd == MLPS_SET_GNSS_ON) {
		g_push_gnss_status = ST_PUSH_OPEN_SUC;
		mlps_notify_pushproxy_open_gnss(PUHS_OPEN_GNSS_SUC);
	} else if (cmd == MLPS_SET_GNSS_CLOSE) {
		g_push_gnss_status = ST_PUSH_CLOSE;
	} else {
		hwlog_err("%s no support cmd\n", __func__);
	}
}

static void mlps_update_gnss_power_fail(void)
{
	unsigned short mlps_upload_data[DATA_LEN_4] = {GNSS_POWER_FAIL, MLPS_RECOVERY_LEN, 0, 0};
	upload_mlps_data((char *)mlps_upload_data, MLPS_RECOVERY_DATA_LEN);
}

static int mlps_operate_gnss(unsigned int cmd)
{
	if ((g_privacy_mode || g_palace_mode) && cmd == MLPS_SET_GNSS_ON) {
		hwlog_info("%s is in privacy or palace\n", __func__);
		return MLPS_OPERATE_GNSS_FAIL;
	}

	hwlog_info("%s enter\n", __func__);
	int ret = 0;
	int i = 0;
	for (i = 0; i < MAX_CONN_FUNCTION_NUM; i++)
		ret |= mlps_ops_conn_function[i](cmd);

	if (ret != 0) {
		hwlog_err("%s failed, ret is %d\n", __func__, ret);
		return MLPS_OPERATE_GNSS_FAIL;
	}

	hwlog_info("%s, cmd: %d success\n", __func__, cmd);
	return MLPS_OPERATE_GNSS_SUCCESS;
}

static bool mlps_check_bit_map(void)
{
	int i = 0;
	for (i = 0; i < MODULE_END; i++) {
		if (bit_check(&g_mlps_app_bit_map, i))
			return true;
	}

	return false;
}

static int mlps_open_gnss_power(unsigned int service)
{
	int ret = MLPS_OPERATE_GNSS_SUCCESS;
	hwlog_info("%s enter, service: %u, g_mlps_app_bit_map: %u\n",
		__func__, service, g_mlps_app_bit_map);
	if (bit_check(&g_mlps_app_bit_map, service)) {
		hwlog_warn("%s service %d has opened\n", __func__, service);
		if (service == PUSHPROXY_WIFI_HEARTBEAT_AGENT)
			mlps_notify_pushproxy_opt_gnss(MLPS_SET_GNSS_ON);
		return ret;
	}

	if (mlps_check_bit_map() == false) {
		ret = mlps_operate_gnss(MLPS_SET_GNSS_ON);
		hwlog_warn("%s service %d open success ret = %d\n", __func__, service, ret);
	}

	if (ret == MLPS_OPERATE_GNSS_FAIL) {
		mlps_update_gnss_power_fail();
		if (service == PUSHPROXY_WIFI_HEARTBEAT_AGENT)
			g_push_gnss_status = ST_PUSH_FAIL;
		return ret;
	}

	bit_set(&g_mlps_app_bit_map, service);
	if (service == PUSHPROXY_WIFI_HEARTBEAT_AGENT)
		mlps_notify_pushproxy_opt_gnss(MLPS_SET_GNSS_ON);

	return ret;
}

static int mlps_close_gnss_power(unsigned int service)
{
	int ret = MLPS_OPERATE_GNSS_SUCCESS;
	hwlog_info("%s enter, service: %u, g_mlps_app_bit_map: %u\n",
		__func__, service, g_mlps_app_bit_map);
	if (!bit_check(&g_mlps_app_bit_map, service)) {
		hwlog_warn("%s service %d has closed\n", __func__, service);
		if (service == PUSHPROXY_WIFI_HEARTBEAT_AGENT)
			mlps_notify_pushproxy_opt_gnss(MLPS_SET_GNSS_CLOSE);
		return ret;
	}

	bit_clear(&g_mlps_app_bit_map, service);

	if (mlps_check_bit_map() == false) {
		ret = mlps_operate_gnss(MLPS_SET_GNSS_CLOSE);
		hwlog_warn("%s close success\n", __func__);
	}

	if (service == PUSHPROXY_WIFI_HEARTBEAT_AGENT)
		mlps_notify_pushproxy_opt_gnss(MLPS_SET_GNSS_CLOSE);

	return ret;
}

static void mlps_gnss_handle(struct mlps_work_t *p)
{
	int ret = MLPS_OPERATE_GNSS_SUCCESS;
	if (p->cmd == MLPS_CMD_OPEN) {
		ret = mlps_open_gnss_power(p->service);
	} else if (p->cmd == MLPS_CMD_CLOSE) {
		ret = mlps_close_gnss_power(p->service);
	} else {
		ret = MLPS_NOT_SUPPORT_GNSS_OPERATION;
		hwlog_warn("%s unkonwn cmd %u\n", __func__, p->cmd);
	}
	if (ret == MLPS_OPERATE_GNSS_SUCCESS) {
		g_gnss_status = MLPS_OPERATE_GNSS_OPEN_SUCCESS;
		if (p->cmd == MLPS_CMD_CLOSE)
			g_gnss_status = MLPS_OPERATE_GNSS_CLOSE_SUCCESS;
	} else {
		g_gnss_status = ret;
	}
	return;
}

#ifdef CONFIG_MLPS_OPERATE_CONN
static int mlps_operate_gnss_handle(unsigned short cmd, unsigned int service)
{
	hwlog_info("%s, cmd: %u, service: %u\n", __func__, cmd, service);
	int ret = MLPS_OPERATE_GNSS_SUCCESS;
	g_gnss_status = MLPS_WAIT_GNSS_OPERATION;
	if (g_support_conn_operation  == false) {
		g_gnss_status = MLPS_NOT_SUPPORT_GNSS_OPERATION;
		ret = MLPS_NOT_SUPPORT_GNSS_OPERATION;
		return ret;
	}
	if (service >= MODULE_END) {
		g_gnss_status = MLPS_NOT_SUPPORT_GNSS_OPERATION;
		ret = MLPS_NOT_SUPPORT_GNSS_OPERATION;
		hwlog_warn("%s unkonwn service %u\n", __func__, service);
		return ret;
	}

	struct mlps_work_t *gnss_work = NULL;
	gnss_work = kzalloc(sizeof(struct mlps_work_t), GFP_ATOMIC);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)gnss_work)) {
		pr_err("[%s] alloc gnss_work failed.\n", __func__);
		g_gnss_status = MLPS_OPERATE_GNSS_FAIL;
		ret = MLPS_OPERATE_GNSS_FAIL;
		return ret;
	}
	gnss_work->cmd = cmd;
	gnss_work->service = service;
	gnss_work->work_type = MLPS_WORK_GNSS;
	gnss_work->data_len = 0;
	gnss_work->data = NULL;
	INIT_WORK(&gnss_work->worker, mlps_work_handle);
	queue_work(g_mlps_wq, &gnss_work->worker);
	return ret;
}
#else
static int mlps_operate_gnss_handle(unsigned short cmd, unsigned int service)
{
	if (cmd == MLPS_CMD_OPEN)
		g_gnss_status = MLPS_OPERATE_GNSS_OPEN_SUCCESS;
	else
		g_gnss_status = MLPS_OPERATE_GNSS_CLOSE_SUCCESS;

	if (cmd == MLPS_CMD_OPEN && service == PUSHPROXY_WIFI_HEARTBEAT_AGENT) {
		g_push_gnss_status = ST_PUSH_OPEN_SUC;
		mlps_notify_pushproxy_open_gnss(PUHS_OPEN_GNSS_SUC);
	} else if (cmd == MLPS_CMD_CLOSE && service == PUSHPROXY_WIFI_HEARTBEAT_AGENT) {
		g_push_gnss_status = ST_PUSH_CLOSE;
	}

	return MLPS_OPERATE_GNSS_SUCCESS;
}
#endif

static void outside_app_status_record(unsigned short cmd, unsigned int service)
{
	if (cmd == MLPS_CMD_OPEN) {
		bit_set(&g_outside_app_bit_map, service);
	} else if (cmd == MLPS_CMD_CLOSE){
		bit_clear(&g_outside_app_bit_map, service);
	}
}

int mlps_operate_gnss_power(unsigned short cmd, unsigned int service)
{
	hwlog_info("%s, cmd: %u, service: %u\n", __func__, cmd, service);
	if (service >= OUTSIDE_APP_START)
		outside_app_status_record(cmd, service);

	return mlps_operate_gnss_handle(cmd, service);
}

#ifdef CONFIG_MLPS_OPERATE_CONN
static int mlps_parse_softbus_module(pkt_mlps_detail_data_t *data)
{
	switch (data->mlps_module_type) {
	case HEARTBEAT_ALIVE:
		if (data->mlps_cmd == MLPS_CMD_OPEN) {
			hwlog_info("%s SOFTBUS_HEARTBEAT_ALIVE open\n", __func__);
			mlps_operate_gnss_handle(data->mlps_cmd, SOFTBUS_HEARTBEAT_ALIVE);
		} else if (data->mlps_cmd == MLPS_CMD_CLOSE) {
			mlps_operate_gnss_handle(data->mlps_cmd, SOFTBUS_HEARTBEAT_ALIVE);
			hwlog_info("%s SOFTBUS_HEARTBEAT_ALIVE close\n", __func__);
		}
		break;

	default:
		hwlog_warn("%s unkonwn mlps softbus %d\n", __func__, data->mlps_module_type);
		break;
	}

	return SUCCESS;
}
#endif

static int mlps_send_wifi_workq_data(pkt_wifi_detail_data_t *wf_data, int len)
{
	struct mlps_work_t  *wifi_work = NULL;
	wifi_work = kzalloc(sizeof(struct mlps_work_t), GFP_ATOMIC);
	if (wifi_work == NULL) {
		pr_err("[%s] alloc wifi_work failed.\n", __func__);
		return FAIL;
	}
	wifi_work->data = wf_data;
	wifi_work->data_len = len;
	wifi_work->work_type = MLPS_WORK_WIFI;
	wifi_work->cmd = 0;
	wifi_work->service = 0;
	INIT_WORK(&wifi_work->worker, mlps_work_handle);
	queue_work(g_mlps_wq, &wifi_work->worker);
	return SUCCESS;
}

static void mlps_process_ip_addr(unsigned char *addr, int len, int cmd)
{
	char *data = (char *)kzalloc(len + DATA_LEN_16 + SUBCMD_LEN, GFP_KERNEL);
	if (data == NULL) {
		hwlog_err("%s ip addr kzalloc fail!!!\n", __func__);
		return;
	}
	pkt_wifi_detail_data_t *wf_data = (pkt_wifi_detail_data_t *)data;
	(void)memset_s(data, (len + DATA_LEN_16 + SUBCMD_LEN),
		0, (len + DATA_LEN_16 + SUBCMD_LEN));
	if (memcpy_s(wf_data->value, len, addr, len) != EOK) {
		hwlog_err("%s memcpy_s fail\n", __func__);
		kfree(data);
		data = NULL;
		return;
	}
	wf_data->subcmd = SUB_CMD_MLPS_CONFIG_REQ;
	wf_data->mlps_app_type = APP_PUSHPROXY;
	wf_data->app_len = len + DATA_LEN_12;
	wf_data->mlps_module_type = 0;
	wf_data->module_len = len + DATA_LEN_8;
	wf_data->config_type = MLPS_CMD_CONFIG;
	wf_data->config_len = len + DATA_LEN_4;
	wf_data->cmd = cmd;
	wf_data->cmd_len = len;

	if (mlps_send_wifi_workq_data(wf_data, len + DATA_LEN_16) == FAIL) {
		kfree(data);
		data = NULL;
		hwlog_warn("%s send to sh fail\n", __func__);
		return;
	}
	hwlog_info("%s send to sh sucess\n", __func__);
	return;
}

static void mlps_get_ipv6_next_mac(struct net_device *dev)
{
	int err = 0;
	struct flowi6 fl6 = {
		.daddr = *(struct in6_addr *)push_ipv6_daddr,
		.flowi6_oif = 0,
	};

	struct dst_entry *dst = ip6_route_output(&init_net, NULL, &fl6);
	if (dst == NULL) {
		hwlog_err("%s dst_entry is NULL\n", __func__);
		return;
	}
	struct rt6_info *rt = container_of(dst, struct rt6_info, dst);
 	if (rt->dst.error) {
 		err = rt->dst.error;
 		ip6_rt_put(rt);
		hwlog_err("%s rt err = %d\n", __func__, err);
 		return;
 	}
 	if (rt == init_net.ipv6.ip6_null_entry) {
 		err = rt->dst.error;
 		ip6_rt_put(rt);
		hwlog_err("%s rt init err = %d\n", __func__, err);
 		return;
 	}
	unsigned char ipv6_gateway[IPV6_ADDR_LEN];
	if (memcpy_s(ipv6_gateway, IPV6_ADDR_LEN,
		&rt->rt6i_gateway, IPV6_ADDR_LEN) != EOK) {
		hwlog_err("%s memcpy ipv6_gateway fail\n", __func__);
		return;
	}

	struct neighbour *n = NULL;
	n = neigh_lookup(&nd_tbl, ipv6_gateway, dev);  // ipv6 table nd_tbl
	if (!n) {
		hwlog_err("%s neigh_lookup fail\n", __func__);
		return;
	}
	if (n->nud_state & NUD_VALID) {
		hwlog_info("%s find neigher\n", __func__);
		if (memcpy_s(start_req.next_hop_mac, MAC_ADDR_LEN,
			n->ha, MAC_ADDR_LEN) != EOK) {
			hwlog_err("%s memcpy v4_next_hop_mac fail\n", __func__);
		}
	}
	neigh_release(n);
}

static void mlps_get_current_ipv6_info(struct net_device *dev,
	struct inet6_ifaddr *ifp)
{
	if (ifp->scope != 0) {
		hwlog_info("%s ipv6 addr is not global\n", __func__);
	} else {
		if (memcpy_s(start_req.ipv6_addr, IPV6_ADDR_LEN,
			&ifp->addr.s6_addr, IPV6_ADDR_LEN) != EOK) {
			hwlog_err("%s memcpy v6_addr fail\n", __func__);
			return;
		}
		hwlog_info("%s ipv6 addr is global\n", __func__);
		if (g_get_ipaddr_cmd == PUSH_START_PROXY_REQ) {
			mlps_get_ipv6_next_mac(dev);
			mlps_process_ip_addr((char *)&start_req,
				sizeof(push_proxy_start_req_t), PUSH_START_PROXY_REQ);
			g_get_ipaddr_cmd = 0;
		} else if (g_get_ipaddr_cmd == PUSH_IPV6_ADDR) {
			mlps_process_ip_addr(start_req.ipv6_addr, IPV6_ADDR_LEN, PUSH_IPV6_ADDR);
			g_get_ipaddr_cmd = 0;
		} else {
			hwlog_warn("%s get_ipaddr_cmd is no support\n", __func__);
		}
	}
}

static void mlps_get_current_ipv6_addr(void)
{
	struct net_device *dev = NULL;

	dev = dev_get_by_name(&init_net, g_dev_name);
	if (dev == NULL) {
		hwlog_err("%s dev_get_by_name fail\n", __func__);
		goto err;
	}
	hwlog_info("%s find wlan0\n", __func__);

	struct inet6_dev *idev = in6_dev_get(dev);
	if (idev == NULL) {
		dev_put(dev);
		goto err;
	}

	if (g_get_ipaddr_cmd == PUSH_START_PROXY_REQ) {
		if (memcpy_s(start_req.mac, MAC_ADDR_LEN,
			dev->dev_addr, MAC_ADDR_LEN) != EOK) {
			hwlog_err("%s memcpy mac_addr fail\n", __func__);
			dev_put(dev);
			in6_dev_put(idev);
			mlps_errno_to_push_service(GET_IPV6_MAC_ERR, dev->state, dev->flags);
			goto err;
		}
	}

	struct inet6_ifaddr *ifp;
	rcu_read_lock();
	list_for_each_entry(ifp, &idev->addr_list, if_list) {
		mlps_get_current_ipv6_info(dev, ifp);
	}
	rcu_read_unlock();
	in6_dev_put(idev);
	dev_put(dev);

err:
	if (g_get_ipaddr_cmd == PUSH_START_PROXY_REQ) {
		mlps_process_ip_addr((char *)&start_req,
			sizeof(push_proxy_start_req_t), PUSH_START_PROXY_REQ);
		g_get_ipaddr_cmd = 0;
	}
}

static int mlps_process_ipv4_ifa(struct in_ifaddr *ifa,
	struct neighbour *n, struct net_device *dev)
{
	if (memcpy_s(start_req.ipv4_addr, IPV4_ADDR_LEN,
		&ifa->ifa_local, IPV4_ADDR_LEN) != EOK) {
		hwlog_err("%s memcpy v4_addr fail\n", __func__);
		return FAIL;
	}
	uint8_t ip_addr[IPV4_ADDR_LEN] = { 0 };
	if (memcpy_s(ip_addr, IPV4_ADDR_LEN,
		start_req.next_hop_ip, IPV4_ADDR_LEN) != EOK) {
		hwlog_err("%s memcpy v4_next_addr fail\n", __func__);
		return FAIL;
	}
	n = neigh_lookup(&arp_tbl, ip_addr, dev);  // ipv6 table nd_tbl
	if (!n) {
		hwlog_err("%s neigh_lookup fail\n", __func__);
		mlps_errno_to_push_service(GET_IPV4_GATEWAY_ERR, 0, 0);
		return FAIL;
	}
	if (n->nud_state & NUD_VALID) {
		hwlog_info("%s find neigher\n", __func__);
		if (memcpy_s(start_req.next_hop_mac, MAC_ADDR_LEN,
			n->ha, MAC_ADDR_LEN) != EOK) {
			hwlog_err("%s memcpy v4_next_hop_mac fail\n", __func__);
			mlps_errno_to_push_service(GET_IPV4_GATEWAY_ERR, 1, 0);
			return FAIL;
		}
	} else {
		mlps_errno_to_push_service(GET_IPV4_GATEWAY_ERR, 2, 0);
		return FAIL;
	}
	neigh_release(n);
	return SUCCESS;
}

static int mlps_get_ipv4_info(struct net_device *dev)
{
    if (!(dev->flags & IFF_UP))
		return FAIL;

	struct in_device *in_dev = in_dev_get(dev);
	if (in_dev == NULL)
		return FAIL;

	struct neighbour *n = NULL;
	struct in_ifaddr *ifa;
	int ret = 0;
	rcu_read_lock();
	in_dev_for_each_ifa_rcu(ifa, in_dev) {
		if (ifa->ifa_local == 0)
			continue;

		ret = mlps_process_ipv4_ifa(ifa, n, dev);
		if (ret == SUCCESS)
			break;
	}
	if (ifa == NULL) {
		mlps_errno_to_push_service(GET_IPV4_NO_IFA, dev->state, dev->flags);
	}

	rcu_read_unlock();
	in_dev_put(in_dev);
	return ret;
}

static int mlps_get_current_ipv4_addr(void)
{
	int ret = 0;
	struct net_device *dev = NULL;
	dev = dev_get_by_name(&init_net, g_dev_name);
	if (dev == NULL) {
		hwlog_err("%s dev_get_by_name fail\n", __func__);
		mlps_errno_to_push_service(NO_NETWORK_ADAPTER, 0, 0);
		return FAIL;
	}
	hwlog_info("%s find wlan0\n", __func__);

	if (memcpy_s(start_req.mac, MAC_ADDR_LEN,
		dev->dev_addr, MAC_ADDR_LEN) != EOK) {
		hwlog_err("%s memcpy mac_addr fail\n", __func__);
		mlps_errno_to_push_service(GET_IPV4_MAC_ERR, dev->state, dev->flags); // state flag
		dev_put(dev);
		return FAIL;
	}
	ret = mlps_get_ipv4_info(dev);
	dev_put(dev);
	if (ret == SUCCESS) {
		mlps_process_ip_addr((char *)&start_req,
			sizeof(push_proxy_start_req_t), PUSH_START_PROXY_REQ);
		g_get_ipaddr_cmd = PUSH_IPV6_ADDR;
	}
	return ret;
}

static void mlps_get_addr_info(void)
{
	int ret = 0;
	g_get_ipaddr_cmd = PUSH_START_PROXY_REQ;
	ret = mlps_get_current_ipv4_addr();
	if (ret < 0) {
		mod_timer(&get_ipv4_timer, jiffies + IPV4_RETRY_TIME * HZ);
	}

	mod_timer(&get_ipv6_timer, jiffies + IPV6_RETRY_TIME * HZ);
}

static void mlps_push_get_addr(push_proxy_start_req_t *addr)
{
	if (memcpy_s(&start_req, sizeof(push_proxy_start_req_t),
		addr, sizeof(push_proxy_start_req_t)) != EOK) {
		return;
	}

	mlps_get_addr_info();
}

static void mlps_get_ipv6_daddr(push_proxy_ip_info *info)
{
	for (int i = 0; i < DATA_LEN_4; i++) {
		if (info->addr_info[i].ipv6_flag == 1) {
			memcpy_s(push_ipv6_daddr, IPV6_ADDR_LEN, info->addr_info[i].ipv6_addr, IPV6_ADDR_LEN);
			break;
		}
	}
}

static int mlps_parse_pushproxy_module_cmd(pkt_mlps_cmd_data_t *data, unsigned int len)
{
	int ret = SUCCESS;

	switch (data->cmd) {
	case PUSH_START_PROXY_REQ:
		if ((len <= DATA_LEN_16) || (len != data->cmd_len + sizeof(short) * DATA_LEN_8) ||
			(data->cmd_len != sizeof(push_proxy_start_req_t))) {
			hwlog_warn("%s PUSH_START_PROXY_REQ check len fail len=%d\n", __func__, len);
			return FAIL;
		}
		if (g_push_gnss_status != ST_PUSH_OPEN_WAIT) {
			g_push_gnss_status = ST_PUSH_OPEN_WAIT;
			mlps_operate_gnss_handle(MLPS_CMD_OPEN, PUSHPROXY_WIFI_HEARTBEAT_AGENT);
		}
		mlps_push_get_addr((push_proxy_start_req_t *)data->value);
		ret = MLPS_BLOCK;
		break;

	case PUSH_PARAM_CNF:
		if ((len <= DATA_LEN_16) ||  (len != data->cmd_len + sizeof(short) * DATA_LEN_8) ||
			(data->cmd_len <= sizeof(push_proxy_ip_info))) {
			hwlog_warn("%s PUSH_PARAM_CNF check len fail len=%d\n", __func__, len);
			return FAIL;
		}
		mlps_get_ipv6_daddr((push_proxy_ip_info *)data->value);
		break;

	default:
		if (g_get_ipv6_retry_cnt == IPV6_RETRY_MAX &&
			g_get_ipaddr_cmd == PUSH_IPV6_ADDR) {
			mlps_get_current_ipv6_addr();
		}
		break;
	}

	return ret;
}

static int mlps_parse_pushproxy_module(pkt_mlps_detail_data_t *data, unsigned int len)
{
	return mlps_parse_pushproxy_module_cmd((pkt_mlps_cmd_data_t *)data->value, len);
}

#ifdef CONFIG_MLPS_PL_FEATURE
static int mlps_parse_map_module(pkt_mlps_detail_data_t *data)
{
	if (data->mlps_cmd == MLPS_CMD_OPEN) {
		g_map_trajectory_recording_switch = true;
		hwlog_info("%s mlps_parse_map_module open %d\n", __func__, g_map_trajectory_recording_switch);
	} else if (data->mlps_cmd == MLPS_CMD_CLOSE) {
		g_map_trajectory_recording_switch = false;
		hwlog_info("%s mlps_parse_map_module close %d\n", __func__, g_map_trajectory_recording_switch);
	}
	return SUCCESS;
}
#endif

static int mlps_parse_app(pkt_mlps_detail_data_t *data, unsigned int len)
{
	int ret = SUCCESS;

	switch (data->mlps_app_type) {
#ifdef CONFIG_MLPS_OPERATE_CONN
	case APP_SOFTBUS:
		ret = mlps_parse_softbus_module(data);
		break;
#endif

	case APP_PUSHPROXY:
		ret = mlps_parse_pushproxy_module(data, len);
		break;

#ifdef CONFIG_MLPS_PL_FEATURE
	case APP_MAP:
		ret = mlps_parse_map_module(data);
		break;
#endif

	default:
		hwlog_warn("%s unkonwn mlps app %d\n", __func__, data->mlps_app_type);
		break;
	}

	return ret;
}

static int mlps_check_tlv_len(pkt_mlps_detail_data_t *data, unsigned int len)
{
	if ((len != data->app_len + sizeof(short) * DATA_LEN_2) ||
		(len != data->module_len + sizeof(short) * DATA_LEN_4) ||
		(len != data->cmd_len + sizeof(short) * DATA_LEN_6)) {
		hwlog_warn("%s check fail, len=%d, app_len=%d, module_len=%d, cmd_len=%d\n",
			__func__, len, data->app_len, data->module_len, data->cmd_len);
		return FAIL;
	}
	return SUCCESS;
}

static int mlps_parse_data(pkt_mlps_detail_data_t *data, unsigned int len)
{
	if (data->mlps_app_type <= APP_START || data->mlps_app_type >= APP_MAX) {
		hwlog_err("%s: no support app : %d\n", __func__, data->mlps_app_type);
		return FAIL;
	}

	if (data->mlps_cmd < MLPS_CMD_OPEN || data->mlps_cmd >= MLPS_CMD_UPLOAD) {
		hwlog_err("%s: no support cmd : %d\n", __func__, data->mlps_cmd);
		return FAIL;
	}

	if (mlps_check_tlv_len(data, len) == FAIL) {
		return FAIL;
	}

	return mlps_parse_app(data, len);
}

static ssize_t upload_mlps_data(char *data, ssize_t len)
{
	return inputhub_route_write(ROUTE_MLPS_PORT, data, len);
}

static int send_mlps_cmd_internal(int tag, enum obj_cmd cmd,
	enum obj_sub_cmd subcmd, bool use_lock)
{
	interval_param_t interval_param;

	(void)memset_s(&interval_param, sizeof(interval_param), 0,
		sizeof(interval_param));
	if (cmd == CMD_CMN_OPEN_REQ) {
		if (really_do_enable_disable(&g_mlps_ref_cnt, true, 0)) {
			if (use_lock) {
				inputhub_sensor_enable(tag, true, HOST_DEFAULT);
				inputhub_sensor_setdelay(tag, &interval_param, HOST_DEFAULT);
			} else {
				inputhub_sensor_enable_nolock(tag, true, HOST_DEFAULT);
				inputhub_sensor_setdelay_nolock(tag,
					&interval_param, HOST_DEFAULT);
			}
		}
		hwlog_info("send_mlps_cmd open cmd:%d, mlps_ref_cnt= %x\n", cmd, g_mlps_ref_cnt);
	} else if (cmd == CMD_CMN_CLOSE_REQ) {
		if (really_do_enable_disable(&g_mlps_ref_cnt, false, 0)) {
			if (use_lock)
				inputhub_sensor_enable(tag, false, HOST_DEFAULT);
			else
				inputhub_sensor_enable_nolock(tag, false, HOST_DEFAULT);
		}
		hwlog_info("send_mlps_cmd close cmd:%d, mlps_ref_cnt= %x\n", cmd, g_mlps_ref_cnt);
	}
	return 0;
}

static int send_mlps_cmd(enum obj_cmd cmd, unsigned long arg, ssize_t len)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	int argvalue = 0;
	int i;
	int loop_num;

	loop_num = sizeof(mlps_cmd_map_tab) /
		sizeof(mlps_cmd_map_tab[0]);
	for (i = 0; i < loop_num; i++) {
		if (mlps_cmd_map_tab[i].mlps_ioctl_app_cmd == cmd)
			break;
	}

	if (i == loop_num) {
		hwlog_err("%s unknown cmd %d in mlps\n", __func__, cmd);
		return -EFAULT;
	}

	if (copy_from_user(&argvalue, argp, sizeof(argvalue)))
		hwlog_err("%s copy_from_user fail or arg is NULL\n", __func__);

	return send_mlps_cmd_internal(mlps_cmd_map_tab[i].tag,
		mlps_cmd_map_tab[i].cmd, argvalue, true);
}

static int send_mlps_cmd_ext(void *data, ssize_t len,
	struct read_info *pkg_mcu, bool use_lock)
{
	struct write_info pkg_ap;
	int ret = 0;

	if (!(data) || (len <= 0)) {
		hwlog_err("%s para failed\n", __func__);
		return -1;
	}

	if (memset_s(&pkg_ap, sizeof(pkg_ap), 0, sizeof(pkg_ap))) {
		hwlog_err("%s memset data failed\n", __func__);
		return -1;
	}

	pkg_ap.cmd = CMD_CMN_CONFIG_REQ;
	pkg_ap.tag = TAG_MLPS;
	pkg_ap.wr_buf = data;
	pkg_ap.wr_len = SUBCMD_LEN + len;

	ret = write_customize_cmd(&pkg_ap, NULL, use_lock);
	if (ret < 0) {
		hwlog_err("%s: err. write cmd\n", __func__);
		return -1;
	}
	return ret;
}

static void send_raw_sock_errno_to_mcu(int errno)
{
	// four data is type errno rsv rsv
	int ep[DATA_LEN_4] = { RAW_SOCK_SEND_ERR, errno, 0, 0 };
	char *data = (char *)kzalloc(DATA_LEN_16 + sizeof(ep) + SUBCMD_LEN, GFP_KERNEL);
	if (data == NULL) {
		hwlog_err("%s data kzalloc fail\n", __func__);
		return;
	}

	pkt_mlps_sub_header_t *temp = (pkt_mlps_sub_header_t *)data;
	temp->subcmd = SUB_CMD_MLPS_CONFIG_REQ;
	pkt_mlps_detail_data_t *tmp = (pkt_mlps_detail_data_t *)temp->value;
	tmp->mlps_app_type = APP_PUSHPROXY;
	tmp->app_len = DATA_LEN_12 + sizeof(ep);
	tmp->mlps_module_type = 0;
	tmp->module_len = DATA_LEN_8 + sizeof(ep);
	tmp->mlps_cmd = MLPS_CMD_CONFIG;
	tmp->cmd_len = DATA_LEN_4 + sizeof(ep);
	pkt_mlps_cmd_data_t *value = (pkt_mlps_cmd_data_t *)tmp->value;
	value->cmd = PUSH_MLPS_ERR;
	value->cmd_len = sizeof(ep);
	if (memcpy_s(value->value, DATA_LEN_16, ep, sizeof(ep)) != EOK) {
		hwlog_err("%s memcpy errno fail\n", __func__);
		return;
	}

	hwlog_info("%s send errno %d\n", __func__, errno);
	int ret = send_mlps_cmd_ext(data, DATA_LEN_16 + sizeof(ep), NULL, true);

	if (data != NULL) {
		kfree(data);
		data = NULL;
	}
}

static void mlps_ipv6_msg_update(struct msghdr *msg,
	push_wf_send_data_t *pg, struct sockaddr_in6 *s_addr)
{
	s_addr->sin6_port = 0;
	s_addr->sin6_family = AF_INET6;
	if (memcpy_s(&s_addr->sin6_addr, IPV6_ADDR_LEN, pg->addr, IPV6_ADDR_LEN) != EOK) {
		hwlog_err("%s v6 memcpy_s fail\n", __func__);
		return;
	}

	msg->msg_flags |= MSG_DONTWAIT;
	msg->msg_control = NULL;
	msg->msg_controllen = 0;
	msg->msg_name = (struct sockaddr *)s_addr;
	msg->msg_namelen = sizeof(struct sockaddr_in6);
}

static void mlps_ipv4_msg_update(struct msghdr *msg,
	push_wf_send_data_t *pg, struct sockaddr_in *s_addr)
{
	s_addr->sin_port = pg->port;
	s_addr->sin_family = AF_INET;
	if (memcpy_s(&s_addr->sin_addr, IPV4_ADDR_LEN, pg->addr, IPV4_ADDR_LEN) != EOK) {
		hwlog_err("%s v4 memcpy_s fail\n", __func__);
		return;
	}

	msg->msg_flags |= MSG_DONTWAIT;
	msg->msg_control = NULL;
	msg->msg_controllen = 0;
	msg->msg_name = (struct sockaddr *)s_addr;
	msg->msg_namelen = sizeof(struct sockaddr);
}

static void mlps_ip_raw_socket(push_wf_send_data_t *pg)
{
	struct socket *sock = NULL;
	int err;
	struct msghdr msg;
	struct kvec iov[1];
	struct sockaddr_in s_addr;
	struct sockaddr_in6 s_addr6;

	(void)memset_s(&msg, sizeof(msg), 0, sizeof(msg));
	(void)memset_s(&iov, sizeof(iov), 0, sizeof(iov));
	if (pg->addr_len == IPV4_ADDR_LEN) {
		mlps_ipv4_msg_update(&msg, pg, &s_addr);
		err = sock_create_kern(&init_net, AF_INET, SOCK_RAW, IPPROTO_TCP, &sock);
	} else if (pg->addr_len == IPV6_ADDR_LEN) {
		mlps_ipv6_msg_update(&msg, pg, &s_addr6);
		err = sock_create_kern(&init_net, AF_INET6, SOCK_RAW, IPPROTO_RAW, &sock);
	} else {
		hwlog_err("%s is not ipv4 or v6\n", __func__);
		return;
	}
	if (err < 0) {
		hwlog_err("%s create fail\n", __func__);
		mlps_errno_to_push_service(RAW_SOCK_CREATE_ERR, err, 0);
		return;
	}

	int on = 1;
	if (pg->addr_len == IPV4_ADDR_LEN) {
		err = sock->ops->setsockopt(sock, IPPROTO_IP, IP_HDRINCL, KERNEL_SOCKPTR(&on), sizeof(on));
	} else if (pg->addr_len == IPV6_ADDR_LEN) {
		err = sock->ops->setsockopt(sock, IPPROTO_IPV6, IPV6_HDRINCL, KERNEL_SOCKPTR(&on), sizeof(on));
	} else {
		hwlog_info("%s unknown set sock\n", __func__);
	}
	if (err < 0) {
		hwlog_err("%s kernel_setsockopt fail : %d\n", __func__, err);
		mlps_errno_to_push_service(RAW_SOCK_OP_ERR, err, 0);
		sock_release(sock);
		return;
	}

	iov[0].iov_base = pg->data;
	iov[0].iov_len  = pg->data_len;
	err = kernel_sendmsg(sock, &msg, iov, 1, pg->data_len);
	if (err != (signed)pg->data_len) {
		hwlog_err("%s kernel_sendmsg failed, ret=%d", __func__, err);
		sock_release(sock);
		mlps_errno_to_push_service(RAW_SOCK_SEND_ERR, err, 0);
		send_raw_sock_errno_to_mcu(err);
		return;
	}
	sock_release(sock);
}


static void mlps_wifi_send_handle(struct mlps_work_t *p)
{
	mlps_ip_raw_socket((push_wf_send_data_t *)p->data);

	if (p->data != NULL) {
		kfree(p->data);
		p->data = NULL;
	}
	return;
}

static void mlps_wifi_handle(struct mlps_work_t *p)
{
	int ret = send_mlps_cmd_ext(p->data, p->data_len, NULL, true);
	if (ret != 0)
		hwlog_err("%s send_mlps_cmd_ext work error\n", __func__);

	if (p->data != NULL) {
		kfree(p->data);
		p->data = NULL;
	}
	return;
}

static int mlps_match_ip_hook_data(struct sk_buff *skb, unsigned short link_id)
{
	struct ethhdr *eth_header = (struct ethhdr *)(skb_mac_header(skb));
	char *data = (char *)kzalloc(skb->len + MAC_HDR_LEN + DATA_LEN_16 + SUBCMD_LEN, GFP_ATOMIC);
	if (data == NULL) {
		hwlog_err("%s ip pg kzalloc fail!!!\n", __func__);
		return FAIL;
	}
	pkt_wifi_detail_data_t *wf_data = (pkt_wifi_detail_data_t *)data;
	(void)memset_s(data, (skb->len + MAC_HDR_LEN + DATA_LEN_16 + SUBCMD_LEN),
		0, (skb->len + MAC_HDR_LEN + DATA_LEN_16 + SUBCMD_LEN));
	if (memcpy_s(wf_data->value, MAC_HDR_LEN, eth_header, MAC_HDR_LEN) != EOK) {
		hwlog_err("%s memcpy_s fail\n", __func__);
		return FAIL;
	}
	int ret = skb_copy_bits(skb, 0, wf_data->value + MAC_HDR_LEN, skb->len);
	if (ret != 0) {
		hwlog_info("%s copy error!\n", __func__);
		mlps_errno_to_push_service(NETFILTER_HOOK_DATA_ERR, ret, 0);
		kfree(data);
		data = NULL;
		return FAIL;
	}
	wf_data->subcmd = SUB_CMD_MLPS_CONFIG_REQ;
	wf_data->mlps_app_type = APP_PUSHPROXY;
	wf_data->app_len = skb->len + MAC_HDR_LEN + DATA_LEN_12;
	wf_data->mlps_module_type = 0;
	wf_data->module_len = skb->len + MAC_HDR_LEN + DATA_LEN_8;
	wf_data->config_type = MLPS_CMD_CONFIG;
	wf_data->config_len = skb->len + MAC_HDR_LEN + DATA_LEN_4;
	wf_data->cmd = link_id;
	wf_data->cmd_len = skb->len + MAC_HDR_LEN;
	struct mlps_work_t  *wifi_work = NULL;
	wifi_work = kzalloc(sizeof(struct mlps_work_t), GFP_ATOMIC);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)wifi_work)) {
		pr_err("[%s] alloc wifi_work failed.\n", __func__);
		mlps_errno_to_push_service(NETFILTER_HOOK_DATA_ERR, 0, 0);
		kfree(data);
		data = NULL;
		return FAIL;
	}
	wifi_work->data = wf_data;
	wifi_work->data_len = skb->len + MAC_HDR_LEN + DATA_LEN_16;
	wifi_work->cmd = 0;
	wifi_work->service = 0;
	wifi_work->work_type = MLPS_WORK_WIFI;
	INIT_WORK(&wifi_work->worker, mlps_work_handle);
	queue_work(g_mlps_wq, &wifi_work->worker);
	return SUCCESS;
}

static int mlps_ipv6_hook_in_check_data(struct sk_buff *skb)
{
	struct ethhdr *eth_header;
	struct ipv6hdr *ip_header;
	struct tcphdr *tcp_header;

	eth_header = (struct ethhdr *)(skb_mac_header(skb));
	ip_header = (struct ipv6hdr *)(ipv6_hdr(skb));
	tcp_header = (struct tcphdr *)(tcp_hdr(skb));
	if (eth_header == NULL || ip_header == NULL || tcp_header == NULL) {
		return FAIL;
	}
	for (int i = 0; i < PUSH_LINK_MAX - PUSH_LINK_1; i++) {
		if (g_v6_f[i].flag != 1) {
			return FAIL;
		}
		if (g_v6_f[i].port == ntohs(tcp_header->dest)) {
			if (memcmp(&(ip_header->saddr), g_v6_f[i].addr, IPV6_ADDR_LEN) == 0) {
				hwlog_info("%s ipv6 filter match!!!\n", __func__);
				return mlps_match_ip_hook_data(skb, g_v6_f[i].link_id);
			}
		}
	}

	return FAIL;
}

static unsigned int mlps_ipv6_hook_in(void *priv_data, struct sk_buff *skb, const struct nf_hook_state *state)
{
	if (g_push_gnss_status != ST_PUSH_OPEN_SUC) {
		return NF_ACCEPT;
	}

	if (!skb || !skb->len || !state) {
		return NF_ACCEPT;
	}

	if (ipv6_hdr(skb)->nexthdr != IPPROTO_TCP) {
		return NF_ACCEPT;
	}

	spin_lock_bh(&link_hook_lock);
	if (mlps_ipv6_hook_in_check_data(skb) == FAIL) {
		spin_unlock_bh(&link_hook_lock);
		return NF_ACCEPT;
	}
	spin_unlock_bh(&link_hook_lock);

	return NF_DROP;
}

static int mlps_ipv4_hook_in_check_data(struct sk_buff *skb)
{
	struct ethhdr *eth_header;
	struct iphdr *ip_header;
	struct tcphdr *tcp_header;

	eth_header = (struct ethhdr *)(skb_mac_header(skb));
	ip_header = (struct iphdr *)(skb_network_header(skb));
	tcp_header = (struct tcphdr *)(skb_transport_header(skb));
	if (eth_header == NULL || ip_header == NULL || tcp_header == NULL) {
		return FAIL;
	}

	for (int i = 0; i < PUSH_LINK_MAX - PUSH_LINK_1; i++) {
		if (g_v4_f[i].flag != 1) {
			return FAIL;
		}
		if (g_v4_f[i].port == ntohs(tcp_header->dest)) {
			if (memcmp(&(ip_header->saddr), g_v4_f[i].addr, IPV4_ADDR_LEN) == 0) {
				hwlog_info("%s ipv4 filter match!!!\n", __func__);
				return mlps_match_ip_hook_data(skb, g_v4_f[i].link_id);
			}
		}
	}

	return FAIL;
}

static unsigned int mlps_ipv4_hook_in(void *priv_data, struct sk_buff *skb, const struct nf_hook_state *state)
{
	if (g_push_gnss_status != ST_PUSH_OPEN_SUC) {
		return NF_ACCEPT;
	}

	if (!skb || !skb->len || !state) {
		return NF_ACCEPT;
	}

	if (ip_hdr(skb)->protocol != IPPROTO_TCP) {
		return NF_ACCEPT;
	}

	spin_lock_bh(&link_hook_lock);
	if (mlps_ipv4_hook_in_check_data(skb) == FAIL) {
		spin_unlock_bh(&link_hook_lock);
		return NF_ACCEPT;
	}
	spin_unlock_bh(&link_hook_lock);

	return NF_DROP;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
static const struct nf_hook_ops mlps_hooks_ipv4[] = {
#else
static struct nf_hook_ops mlps_hooks_ipv4[] = {
#endif
	{
		.hook = mlps_ipv4_hook_in,
		.pf = PF_INET,
		.hooknum = NF_INET_LOCAL_IN,
		.priority = NF_IP_PRI_FILTER + 1,
	},
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
static const struct nf_hook_ops mlps_hooks_ipv6[] = {
#else
static struct nf_hook_ops mlps_hooks_ipv6[] = {
#endif
	{
		.hook = mlps_ipv6_hook_in,
		.pf = PF_INET6,
		.hooknum = NF_INET_LOCAL_IN,
		.priority = NF_IP_PRI_FILTER + 1,
	},
};

static void mlps_close_push_link_hooks(void)
{
	if (g_push_link_status[0] == 1) {
		hwlog_info("%s enter v4\n", __func__);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
		nf_unregister_net_hooks(&init_net, mlps_hooks_ipv4, ARRAY_SIZE(mlps_hooks_ipv4));
#else
		nf_unregister_hooks(mlps_hooks_ipv4, ARRAY_SIZE(mlps_hooks_ipv4));
#endif
		g_push_link_status[0] = 0;
	}
	if (g_push_link_status[1] == 1) {
		hwlog_info("%s enter v6\n", __func__);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
		nf_unregister_net_hooks(&init_net, mlps_hooks_ipv6, ARRAY_SIZE(mlps_hooks_ipv6));
#else
		nf_unregister_hooks(mlps_hooks_ipv6, ARRAY_SIZE(mlps_hooks_ipv6));
#endif
		g_push_link_status[1] = 0;
	}
}

static void mlps_start_push_link_v6_hooks(void)
{
	int ret = 0;
	if (g_push_link_status[1] == 0) {
		hwlog_info("%s enter\n", __func__);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
		ret = nf_register_net_hooks(&init_net, mlps_hooks_ipv6, ARRAY_SIZE(mlps_hooks_ipv6));
#else
		ret = nf_register_hooks(mlps_hooks_ipv6, ARRAY_SIZE(mlps_hooks_ipv6));
#endif
	}
	if (ret < 0) {
		hwlog_err("%s fail\n", __func__);
		mlps_errno_to_push_service(NETFILTER_V6_REGISTER_ERR, ret, 0);
		return;
	}
	g_push_link_status[1] = 1;
}

static void mlps_start_push_link_v4_hooks(void)
{
	int ret = 0;
	if (g_push_link_status[0] == 0) {
		hwlog_info("%s enter\n", __func__);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
		ret = nf_register_net_hooks(&init_net, mlps_hooks_ipv4, ARRAY_SIZE(mlps_hooks_ipv4));
#else
		ret = nf_register_hooks(mlps_hooks_ipv4, ARRAY_SIZE(mlps_hooks_ipv4));
#endif
	}
	if (ret < 0) {
		hwlog_err("%s fail\n", __func__);
		mlps_errno_to_push_service(NETFILTER_V4_REGISTER_ERR, ret, 0);
		return;
	}
	g_push_link_status[0] = 1;
}

static void mlps_push_close_ops(void)
{
	g_get_ipv6_retry_cnt = 0;
	mlps_close_push_link_hooks();
	mlps_operate_gnss_handle(MLPS_CMD_CLOSE, PUSHPROXY_WIFI_HEARTBEAT_AGENT);
	spin_lock_bh(&link_hook_lock);
	for (int i = 0; i < PUSH_LINK_MAX - PUSH_LINK_1; i++) {
		g_v4_f[i].flag = 0;
		g_v6_f[i].flag = 0;
	}
	spin_unlock_bh(&link_hook_lock);
}

static void mlps_push_send_raw(pkt_mlps_cmd_data_t *raw_data)
{
	if (raw_data->cmd_len > 0) {
		push_wf_send_data_t *pg = (push_wf_send_data_t *)raw_data->value;

		struct mlps_work_t *ws_work = NULL;
		ws_work = kzalloc(sizeof(struct mlps_work_t), GFP_ATOMIC);
		if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)ws_work)) {
			pr_err("[%s] alloc ws_work failed.\n", __func__);
			return;
		}
		push_wf_send_data_t *send_data = kzalloc(sizeof(push_wf_send_data_t) + pg->data_len, GFP_ATOMIC);
		if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)send_data)) {
			pr_err("[%s] alloc send_data failed.\n", __func__);
			return;
		}
		if (memcpy_s((unsigned char *)send_data, raw_data->cmd_len, raw_data->value, raw_data->cmd_len) != EOK) {
			hwlog_err("%s memcpy_s fail\n", __func__);
			return;
		}
		ws_work->work_type = MLPS_WORK_WIFI_SEND;
		ws_work->cmd = 0;
		ws_work->service = 0;
		ws_work->data_len = pg->data_len;
		ws_work->data = send_data;

		INIT_WORK(&ws_work->worker, mlps_work_handle);
		queue_work(g_mlps_wq, &ws_work->worker);
	}
}

static void mlps_push_update_v4_filter(uint8_t i, push_wf_hook_data_t *hook_filter)
{
	if (hook_filter->flag == 1) { // open
		hwlog_info("%s ipv4 flag 1\n", __func__);
		g_v4_f[i].port = hook_filter->port;
		if (memcpy_s(g_v4_f[i].addr, IPV4_ADDR_LEN, hook_filter->addr, IPV4_ADDR_LEN) != EOK) {
			hwlog_err("%s memcpy_s fail\n", __func__);
			return;
		}
		g_v4_f[i].flag = 1;
		g_v6_f[i].flag = 0;
	} else if (hook_filter->flag == 0) {
		hwlog_info("%s ipv4 flag 0\n", __func__);
		g_v4_f[i].flag = 0;
		g_v6_f[i].flag = 0;
	} else {
		hwlog_err("%s no suport push v4 hook flag %d\n", __func__, hook_filter->flag);
	}
}

static void mlps_push_update_v6_filter(uint8_t i, push_wf_hook_data_t *hook_filter)
{
	if (hook_filter->flag == 1) { // open
		hwlog_info("%s ipv6 flag 1\n", __func__);
		g_v6_f[i].port = hook_filter->port;
		if (memcpy_s(g_v6_f[i].addr, IPV6_ADDR_LEN, hook_filter->addr, IPV6_ADDR_LEN) != EOK) {
			hwlog_err("%s memcpy_s fail\n", __func__);
			return;
		}
		g_v4_f[i].flag = 0;
		g_v6_f[i].flag = 1;
	} else if (hook_filter->flag == 0) {
		hwlog_info("%s ipv6 flag 0\n", __func__);
		g_v4_f[i].flag = 0;
		g_v6_f[i].flag = 0;
	} else {
		hwlog_err("%s no suport push v6 hook flag %d\n", __func__, hook_filter->flag);
	}
}

static void mlps_push_update_filter(uint8_t i, pkt_mlps_cmd_data_t *temp)
{
	push_wf_hook_data_t *hook_filter = (push_wf_hook_data_t *)temp->value;

	spin_lock_bh(&link_hook_lock);
	if (temp->value[0] == IPV4_ADDR_LEN) {
		mlps_start_push_link_v4_hooks();
		hwlog_info("%s ipv4 enter in\n", __func__);
		mlps_push_update_v4_filter(i, hook_filter);
	} else if (temp->value[0] == IPV6_ADDR_LEN) {
		mlps_start_push_link_v6_hooks();
		hwlog_info("%s ipv6 enter in\n", __func__);
		mlps_push_update_v6_filter(i, hook_filter);
	}
	hwlog_err("%s push hook ip addr len = %d\n", __func__, temp->value[0]);
	spin_unlock_bh(&link_hook_lock);
}

#ifdef CONFIG_CONTEXTHUB_MINIFS
uint32_t tlv_net_to_host(uint32_t net_len, uint8_t size)
{
	if (size == sizeof(uint8_t)) {
		return net_len;
	} else if (size == sizeof(uint16_t)) {
		return NET_NTOHS(net_len);
	} else if (size == sizeof(uint32_t)) {
		return NET_NTOHL(net_len);
	}
	return 0;
}

static int parse_tlv_code(uint32_t target_id, uint32_t src_len, const uint8_t *src, struct push_tlv_info *out_info)
{
	if (src == NULL || src_len <= 0) {
		pr_err("parse_tlv_code data or out_data is NULL\n");
		return -1;
	}
	uint32_t src_index = 0;
	while (src_index < src_len) {
		uint32_t temp_src_index = src_index;
		uint8_t temp_wire_type = GET_TLV_WIRE_TYPE_VALUE(src[temp_src_index]);
		uint8_t temp_fildid1 = GET_TLV_FILED1_VALUE(src[temp_src_index]);
		uint32_t cur_fileid = temp_fildid1;
		uint32_t tlv_len = 0;
		if (temp_wire_type >= WIRE_TYPE_MAX) {
			pr_err("parse_tlv_code: wire_type[%d]\n", temp_wire_type);
			goto error_out_data;
		}
		if (temp_fildid1 == MAX_MESSAGE_TAG_T_FIELDID_VALUE) {
			temp_src_index++;
			if (temp_src_index >= src_len) {
				pr_err("push_copy_tlv: tlv copy_num INVALID!fildid++ cur[%d] - max[%d]\n", temp_src_index, src_len);
				goto error_out_data;
			}
			cur_fileid = src[temp_src_index] + temp_fildid1;
		}
		pr_info("parse_tlv_code: cur_fileid 0x%x\n", cur_fileid);

		temp_src_index++;
		if (temp_src_index >= src_len) {
			pr_err("push_copy_tlv: tlv copy_num INVALID!fildid-- cur[%d] - max[%d]\n", temp_src_index, src_len);
			goto error_out_data;
		}

		if (g_push_tlv_rule[temp_wire_type].len_v == 0) {
			for (uint8_t i = 0; i < g_push_tlv_rule[temp_wire_type].len_size; ++i) {
				tlv_len |= ((uint32_t)src[temp_src_index] << (8 * i));
				temp_src_index++;
				if (temp_src_index >= src_len) {
					pr_err("push_copy_tlv: tlv copy_num INVALID!tlv_len cur[%d] - max[%d]\n", temp_src_index, src_len);
					goto error_out_data;
				}
			}
			tlv_len = tlv_net_to_host(tlv_len, g_push_tlv_rule[temp_wire_type].len_size);
		} else {
			tlv_len = g_push_tlv_rule[temp_wire_type].len_v;
		}

		if (tlv_len > (src_len - temp_src_index) || (is_add_reversed(tlv_len, (temp_src_index - src_index)) == true)) {
			pr_err("push_copy_tlv: tlv_len out of range! tlv[%d] - max[%d]\n", tlv_len, src_len);
			goto error_out_data;
		}

		pr_info("parse_tlv_code: tlv_len 0x%x\n", tlv_len);
		pr_info("parse_tlv_code: temp_src_index 0x%x\n", temp_src_index);
		pr_info("parse_tlv_code: src_index 0x%x\n", src_index);

		if (target_id == cur_fileid) {
			out_info->write_type = temp_wire_type;
			out_info->file_id = cur_fileid;
			out_info->len = tlv_len + (temp_src_index - src_index);
			out_info->begin_addr = (void *)(&src[src_index]);
			out_info->len_v = tlv_len;
			out_info->value_addr = (void *)(&src[temp_src_index]);
			pr_info("parse_tlv_code: debug fileid [%u] parse success\n", target_id);
			return SUCCESS;
		}

		temp_src_index += tlv_len;
		src_index = temp_src_index;
	}
	pr_err("parse_tlv_code: id[%d] is wrong! \n", target_id);
	return -1;

error_out_data:
	pr_err("parse_tlv_code: tlv is INVALID \n");
	return -1;
}

int push_prase_file_info_list(uint32_t src_addr, uint32_t src_len)
{
	int ret;
	int i;

	uint8_t *src = (uint8_t *)ioremap_wc(src_addr, src_len);
	if (!src || src_len < 2) {
		return -EINVAL;
	}

	uint16_t count = *(uint16_t *)src;
	pr_info("file list count: %u\n", count);
	char **file_buffer = NULL;
	file_buffer = kmalloc_array(count, sizeof(char *), GFP_KERNEL);
	if (!file_buffer) {
		iounmap(src);
		return -ENOMEM;
	}

	(void)memset_s(file_buffer, count * sizeof(uint8_t *), 0, count * sizeof(uint8_t *));
	uint32_t src_offset = sizeof(count);
	uint32_t data_len = sizeof(uint16_t);

	for (i = 0; i < count && src_offset < src_len; i++) {
		struct push_tlv_info out_info = {0};
		ret = parse_tlv_code(HAP_PATH_TARGET_ID, src_len - src_offset, src + src_offset + data_len, &out_info);
		pr_info("data_len:%d out_info.len\n", *(uint16_t *)(src + src_offset), out_info.len);
		if (ret != SUCCESS || out_info.len == 0) {
			pr_err("Failed to parse info[%u]\n", i);
			iounmap(src);
			return -EINVAL;
		}

		file_buffer[i] = kzalloc(HAP_PATH_LEN_MAX, GFP_KERNEL);
		if (!file_buffer[i]) {
			pr_err("Failed to kzalloc buffer[%u]\n", i);
			iounmap(src);
			return -EINVAL;
		}

		if (memcpy_s(file_buffer[i], HAP_PATH_LEN_MAX, (uint8_t *)out_info.value_addr, out_info.len_v) != EOK) {
			pr_err("Failed to memcpy hap_path[%u]\n", i);
		}
		pr_info("hap_path[%u] value len:%u\n", i, out_info.len_v);
		pr_info("offset %d\n", *(uint16_t *)(src_offset + src));
		src_offset += *(uint16_t *)(src_offset + src) + data_len;
	}
	ret = init_all_file_map_info(file_buffer, (unsigned int)count);
	pr_info("%s init_file_map_info ret:%d\n", __func__, ret);

	for (i = 0; i < count; i++) {
		kfree(file_buffer[i]);
	}
	kfree(file_buffer);
	iounmap(src);
	return 0;
}

void push_delete_file_info_list(void)
{
	release_file_list_in_cma();
}
#endif

static int mlps_parse_push_up_module(pkt_mlps_detail_data_t *data)
{
	pkt_mlps_cmd_data_t *temp = (pkt_mlps_cmd_data_t *)data->value;
	int ret = NORMAL_PROCESS;
	hwlog_info("%s cmd 0x%x\n", __func__, temp->cmd);

	switch (temp->cmd) {
	case PUSH_STOP_CNF:
		g_push_gnss_status = ST_PUSH_DEFAULT;
		break;

	case PUSH_CLOSE_SUC:
		ret = SKIP_PROCESS;
		mlps_push_close_ops();
		break;

	case PUSH_SEND_RAW:
		ret = SKIP_PROCESS;
		mlps_push_send_raw(temp);
		break;

	case PUSH_LINK_1:
	case PUSH_LINK_2:
		if (temp->cmd_len > 0) {
			mlps_push_update_filter(temp->cmd - PUSH_LINK_1, temp);
		}
		ret = SKIP_PROCESS;
		break;

	default:
		hwlog_err("%s no suport push cmd = 0x%x\n", __func__, temp->cmd);
		break;
	}

	return ret;
}

#ifdef CONFIG_MLPS_PL_FEATURE
static int mlps_map_read_buffer(uint32_t num, uint8_t* map_mem_ptr,
	map_mem_manager_t* map_mem_manager_ptr, pkt_mlps_cmd_data_t *value,
	uint32_t num_max, uint32_t data_len)
{
	if (num >= num_max) {
		uint32_t map_index = num_max - map_mem_manager_ptr->index;
		if (memcpy_s(value->value, (num_max * data_len),
			&map_mem_ptr[map_mem_manager_ptr->index * data_len],
			(map_index * data_len)) != EOK) {
			hwlog_err("%s large memcpy half one fail\n", __func__);
			return FAIL;
		}
		if (memcpy_s(&value->value[map_index * data_len],
			(map_mem_manager_ptr->index * data_len),
			map_mem_ptr, (map_mem_manager_ptr->index * data_len))) {
			hwlog_err("%s large memcpy half two fail\n", __func__);
			return FAIL;
		}
	} else if (num == 0) {
		hwlog_info("%s no gnss data\n", __func__);
	} else {
		if (map_mem_manager_ptr->index < map_mem_manager_ptr->pos_num) {
			if (memcpy_s(value->value,
				(map_mem_manager_ptr->pos_num * data_len),
				&map_mem_ptr[(num_max + map_mem_manager_ptr->index - map_mem_manager_ptr->pos_num) * data_len],
				((map_mem_manager_ptr->pos_num - map_mem_manager_ptr->index) * data_len))) {
				hwlog_err("%s small memcpy half one fail\n", __func__);
				return FAIL;
			}

			if (memcpy_s(&value->value[(map_mem_manager_ptr->pos_num - map_mem_manager_ptr->index) * data_len],
				(map_mem_manager_ptr->pos_num * data_len),
				map_mem_ptr, map_mem_manager_ptr->index * data_len)) {
				hwlog_err("%s small memcpy half two fail\n", __func__);
				return FAIL;
			}
		} else {
			if (memcpy_s(value->value, (num * data_len),
				&map_mem_ptr[(map_mem_manager_ptr->index - map_mem_manager_ptr->pos_num) * data_len],
				(map_mem_manager_ptr->pos_num * data_len))) {
				hwlog_err("%s small memcpy fail\n", __func__);
				return FAIL;
			}
		}
	}
	return SUCCESS;
}

static void mlps_map_upload_mem_data(uint32_t num, uint8_t* map_gnss_ptr,
	map_mem_manager_t* map_mem_manager_ptr, uint32_t num_max, uint32_t pos_len, unsigned short cmd)
{
	uint32_t data_len = sizeof(pkt_mlps_detail_data_t) +
		sizeof(pkt_mlps_cmd_data_t) + (num * pos_len);
	pkt_mlps_detail_data_t *data = (pkt_mlps_detail_data_t *)vmalloc(data_len);
	if (data == NULL) {
		hwlog_err("mlps_map_upload_mem_data kzalloc fail cmd = %d\n", cmd);
		return;
	}

	data->mlps_app_type = APP_MAP;
	data->app_len = DATA_LEN_12 + (num * pos_len);
	data->mlps_module_type = 0;
	data->module_len = DATA_LEN_8 + (num * pos_len);
	data->mlps_cmd = MLPS_CMD_UPLOAD;
	data->cmd_len = DATA_LEN_4 + (num * pos_len);
	pkt_mlps_cmd_data_t *value = (pkt_mlps_cmd_data_t *)data->value;
	value->cmd = cmd;
	value->cmd_len = (num * pos_len);

	int ret = mlps_map_read_buffer(num, map_gnss_ptr, map_mem_manager_ptr, value, num_max, pos_len);
	if (ret == SUCCESS) {
		uint32_t upload_len = upload_mlps_data((char *)data, data_len);
		hwlog_info("%s upload_len is %d\n", __func__, upload_len);
	}
	vfree(data);
	data = NULL;
}

/*========================================================================
      SENSORHUB MAP OFFLOAD BUFFER (sh/ap)-rw non-cache
==========================================================================*/
/*    |-----Total 40K(40960)-----
      |-----18 bytes------------------|-----gps manager-------------|
      |-----34628(44 * 787) bytes-----|-----gps data----------------|
      |-----18 bytes------------------|-----climb manager-----------|
      |-----6296(8 * 787) bytes-------|-----climb data--------------|
*/
#define DDR_MAP_GPS_MANAGER               DDR_MAP_BUFFER_BASE_AP
#define DDR_MAP_MANAGER_SIZE              (0x12)
#define DDR_MAP_GPS_MANAGER_END           (DDR_MAP_GPS_MANAGER + DDR_MAP_MANAGER_SIZE)

#define DDR_MAP_GPS_DATA                  DDR_MAP_GPS_MANAGER_END
#define DDR_MAP_GPS_DATA_SIZE             (0x8744)
#define DDR_MAP_GPS_DATA_END              (DDR_MAP_GPS_DATA + DDR_MAP_GPS_DATA_SIZE)

#define DDR_MAP_CLIMB_MANAGER             DDR_MAP_GPS_DATA_END
#define DDR_MAP_MANAGER_SIZE              (0x12)
#define DDR_MAP_CLIMB_MANAGER_END         (DDR_MAP_CLIMB_MANAGER + DDR_MAP_MANAGER_SIZE)

#define DDR_MAP_CLIMB_DATA                DDR_MAP_CLIMB_MANAGER_END
#define DDR_MAP_CLIMB_DATA_SIZE           (0x1898)
#define DDR_MAP_CLIMB_DATA_END            (DDR_MAP_CLIMB_DATA + DDR_MAP_CLIMB_DATA_SIZE)

static void mlps_get_map_climb_data(void)
{
	uint8_t* map_climb_ptr = (uint8_t *)ioremap_wc(DDR_MAP_CLIMB_DATA, DDR_MAP_CLIMB_DATA_SIZE);
	if (map_climb_ptr == NULL) {
		hwlog_warn("mlps_get_map_climb_data map_climb_ptr is NULL\n");
		return;
	}
	map_mem_manager_t* map_mem_manager_ptr =
		(map_mem_manager_t *)ioremap_wc(DDR_MAP_CLIMB_MANAGER, DDR_MAP_MANAGER_SIZE);
	if (map_mem_manager_ptr == NULL) {
		hwlog_warn("mlps_get_map_climb_data map_mem_manager_ptr is NULL\n");
		iounmap(map_climb_ptr);
		return;
	}
	if (map_mem_manager_ptr->wr_fg != MAP_READ) {
		hwlog_warn("mlps_get_map_climb_data mem status is wrong\n");
		iounmap(map_climb_ptr);
		iounmap(map_mem_manager_ptr);
		return;
	}
	hwlog_info("%s pos_num is %d\n", __func__, map_mem_manager_ptr->pos_num);
	if (map_mem_manager_ptr->pos_num > MAP_CLIMB_DATA_MAX) {
		mlps_map_upload_mem_data(MAP_CLIMB_DATA_MAX, map_climb_ptr, map_mem_manager_ptr,
			MAP_CLIMB_DATA_MAX, MAP_CLIMB_DATA_LEN, MAP_CLIMB_DATA);
	} else {
		mlps_map_upload_mem_data(map_mem_manager_ptr->pos_num, map_climb_ptr, map_mem_manager_ptr,
			MAP_CLIMB_DATA_MAX, MAP_CLIMB_DATA_LEN, MAP_CLIMB_DATA);
	}

	map_mem_manager_ptr->report_pos = map_mem_manager_ptr->index;
	map_mem_manager_ptr->pos_num = 0;
	map_mem_manager_ptr->wr_fg = MAP_WRITE;
	iounmap(map_climb_ptr);
	iounmap(map_mem_manager_ptr);
}

static void mlps_get_map_gnss_data(void)
{
	uint8_t* map_gnss_ptr = (uint8_t *)ioremap_wc(DDR_MAP_GPS_DATA, DDR_MAP_GPS_DATA_SIZE);
	if (map_gnss_ptr == NULL) {
		hwlog_warn("mlps_get_map_gnss_data map_gnss_ptr is NULL\n");
		return;
	}
	map_mem_manager_t* map_mem_manager_ptr =
		(map_mem_manager_t *)ioremap_wc(DDR_MAP_GPS_MANAGER, DDR_MAP_MANAGER_SIZE);
	if (map_mem_manager_ptr == NULL) {
		hwlog_warn("mlps_get_map_gnss_data map_mem_manager_ptr is NULL\n");
		iounmap(map_gnss_ptr);
		return;
	}
	if (map_mem_manager_ptr->wr_fg != MAP_READ) {
		hwlog_warn("mlps_get_map_gnss_data mem status is wrong\n");
		iounmap(map_gnss_ptr);
		iounmap(map_mem_manager_ptr);
		return;
	}
	hwlog_info("%s pos_num is %d\n", __func__, map_mem_manager_ptr->pos_num);
	if (map_mem_manager_ptr->pos_num > MAP_GNSS_DATA_MAX) {
		mlps_map_upload_mem_data(MAP_GNSS_DATA_MAX, map_gnss_ptr, map_mem_manager_ptr,
			MAP_GNSS_DATA_MAX, MAP_GNSS_DATA_LEN, MAP_GNSS_INFO_REQ);
	} else {
		mlps_map_upload_mem_data(map_mem_manager_ptr->pos_num, map_gnss_ptr, map_mem_manager_ptr,
			MAP_GNSS_DATA_MAX, MAP_GNSS_DATA_LEN, MAP_GNSS_INFO_REQ);
	}

	map_mem_manager_ptr->report_pos = map_mem_manager_ptr->index;
	map_mem_manager_ptr->pos_num = 0;
	map_mem_manager_ptr->wr_fg = MAP_WRITE;
	iounmap(map_gnss_ptr);
	iounmap(map_mem_manager_ptr);
}

static int mlps_parse_map_up_module(pkt_mlps_detail_data_t *data)
{
	pkt_mlps_cmd_data_t *temp = (pkt_mlps_cmd_data_t *)data->value;
	int ret = NORMAL_PROCESS;
	hwlog_info("%s cmd 0x%x\n", __func__, temp->cmd);

	switch (temp->cmd) {
	case MAP_GNSS_INFO_REQ:
		mlps_get_map_climb_data();
		mlps_get_map_gnss_data();
		ret = SKIP_PROCESS;
		break;

	default:
		hwlog_err("%s no suport push cmd = 0x%x\n", __func__, temp->cmd);
		break;
	}

	return ret;
}
#endif

static int mlps_parse_upload_app(pkt_mlps_detail_data_t *data)
{
	int ret = NORMAL_PROCESS;

	switch (data->mlps_app_type) {
	case APP_PUSHPROXY:
		ret = mlps_parse_push_up_module(data);
		break;

#ifdef CONFIG_MLPS_PL_FEATURE
	case APP_MAP:
		ret = mlps_parse_map_up_module(data);
		break;
#endif

	default:
		break;
	}

	return ret;
}

static int process_mlps_data_from_mcu(const struct pkt_header *head)
{
	int ret = NORMAL_PROCESS;
	unsigned char *data = (unsigned char *)head + sizeof(struct pkt_header);
	ret = mlps_parse_upload_app((pkt_mlps_detail_data_t *)data);
	if (ret == NORMAL_PROCESS) {
		__pm_wakeup_event(mlps_wl, MLPS_WAKEUP_MSEC); // wait for mlps service read 50ms
		upload_mlps_data(data, head->length);
		hwlog_info("%s: upload mlps data\n", __func__);
	} else {
		hwlog_info("%s: no need upload mlps data\n", __func__);
	}
	return 0;
}

/* read /dev/mlpshub */
static ssize_t mlps_read(struct file *file, char __user *data, size_t count,
			loff_t *pos)
{
	return inputhub_route_read(ROUTE_MLPS_PORT, data, count);
}

static int check_mlps_privacy_mode(pkt_mlps_detail_data_t *data)
{
	int ret = 0;

	if (data->app_len != NORMAL_LEN || data->module_len != MLPS_RECOVERY_LEN)
		return ret;

	if (data->mlps_cmd == MLPS_CMD_OPEN) {
		hwlog_info("%s privacy mode in\n", __func__);
		g_privacy_mode = true;
		if (mlps_check_bit_map() == false) {
			hwlog_info("%s check bit map suc\n", __func__);
			mlps_privacy_notify_ta();
			return ret;
		}
		hwlog_info("%s check bit map fail : 0x%x\n", __func__, g_mlps_app_bit_map);
		for (int i = OUTSIDE_APP_START; i < MODULE_END; i++) {
			if (bit_check(&g_mlps_app_bit_map, i))
				(void)mlps_operate_gnss_power(MLPS_CMD_CLOSE, i);
		}
		g_privacy_timer_retry = 0;
		mod_timer(&privacy_gnss_timer, jiffies + 1 * HZ);
	} else if (data->mlps_cmd == MLPS_CMD_CLOSE) {
		hwlog_info("%s privacy mode out\n", __func__);
		g_privacy_timer_retry = 0;
		g_privacy_mode = false;
		for (int i = OUTSIDE_APP_START; i < MODULE_END; i++) {
			if (bit_check(&g_outside_app_bit_map, i))
				(void)mlps_operate_gnss_power(MLPS_CMD_OPEN, i);
		}
	}

	return ret;
}

static int check_mlps_palace_museum_mode(pkt_mlps_detail_data_t *data)
{
	int ret = 0;

	if (data->app_len != NORMAL_LEN)
		return ret;

	if (data->mlps_cmd == MLPS_CMD_OPEN) {
		hwlog_info("%s in\n", __func__);
		g_palace_mode = true;
		hwlog_info("%s check bit map : 0x%x\n", __func__, g_mlps_app_bit_map);
		for (int i = INSIDE_APP_START; i < MODULE_END; i++) {
			if (bit_check(&g_mlps_app_bit_map, i))
				(void)mlps_operate_gnss_power(MLPS_CMD_CLOSE, i);
		}
		unsigned short mlps_upload_data[DATA_LEN_4] = {APP_PALACE_MUSEUM, MLPS_RECOVERY_LEN, 0, 0};
		upload_mlps_data((char *)mlps_upload_data, MLPS_RECOVERY_DATA_LEN);
	} else if (data->mlps_cmd == MLPS_CMD_CLOSE) {
		hwlog_info("%s out\n", __func__);
		g_palace_mode = false;
		for (int i = OUTSIDE_APP_START; i < MODULE_END; i++) {
			if (bit_check(&g_outside_app_bit_map, i))
				(void)mlps_operate_gnss_power(MLPS_CMD_OPEN, i);
		}
	}

	return ret;
}

static int check_mlps_enter_s4_mode(pkt_mlps_detail_data_t *data)
{
	int ret = 0;

	if (data == NULL || data->app_len != NORMAL_LEN) {
		return ret;
	}

	if (data->mlps_cmd == MLPS_CMD_OPEN) {
		hwlog_info("%s in check bit map : 0x%x\n", __func__, g_mlps_app_bit_map);

		for (int i = INSIDE_APP_START; i < MODULE_END; i++) {
			if (bit_check(&g_mlps_app_bit_map, i)) {
				(void)mlps_operate_gnss_power(MLPS_CMD_CLOSE, i);
			}
		}
	}

	return ret;
}

static int check_mlps_data(pkt_mlps_detail_data_t *data)
{
	if (data == NULL) {
		return -1;
	}
	if (data->mlps_app_type < ENTER_S4 || data->mlps_app_type >= MLPS_SENSORHUB_RECOVERY) {
		hwlog_info("%s: app %d no need check\n", __func__, data->mlps_app_type);
		return -1;
	}

	if (data->mlps_cmd < MLPS_CMD_OPEN || data->mlps_cmd >= MLPS_CMD_UPLOAD) {
		hwlog_err("%s: cmd fail\n", __func__);
		return -1;
	}

	int ret = 0;
	switch (data->mlps_app_type) {
	case ENTER_S4:
		ret = check_mlps_enter_s4_mode(data);
		break;

	case APP_PALACE_MUSEUM:
		ret = check_mlps_palace_museum_mode(data);
		break;

	case APP_PRIVACY:
		ret = check_mlps_privacy_mode(data);
		break;

	default:
		hwlog_info("%s app %d no need check\n", __func__, data->mlps_app_type);
		break;
	}

	return ret;
}

/* write to /dev/motionhub, when need tansfer big data ,use this channel */
static ssize_t mlps_write(struct file *file, const char __user *user_data,
			 size_t len, loff_t *ppos)
{
	if (!(user_data) || (len < MIN_LEN) || (len > MAX_LEN)) {
		hwlog_err("%s para failed\n", __func__);
		return -EINVAL;
	}

	char *data = (char *)kzalloc(len + SUBCMD_LEN, GFP_KERNEL);
	if (data == NULL) {
		hwlog_err("%s user data kzalloc fail\n", __func__);
		return -ENOMEM;
	}

	pkt_mlps_sub_header_t *temp = (pkt_mlps_sub_header_t *)data;
	temp->subcmd = SUB_CMD_MLPS_CONFIG_REQ;
	if (copy_from_user(temp->value, user_data, len)) {
		hwlog_err("%s copy from user fail\n", __func__);
		if (data != NULL) {
			kfree(data);
		}
		return -EFAULT;
	}

	int ret = check_mlps_data((pkt_mlps_detail_data_t *)temp->value);
	if (ret != 0) {
		ret = mlps_parse_data((pkt_mlps_detail_data_t *)temp->value, len);
		if (ret == SUCCESS) {
			ret = send_mlps_cmd_ext(data, len, NULL, true);
			if (ret != 0)
				hwlog_err("mlps_write work error\n");
		}
	}
	if (data != NULL) {
		kfree(data);
		data = NULL;
	}
	if (ret < 0)
		return ret;

	return len;
}

static void privacy_or_palace_ops_gnss(void)
{
	for (int i = INSIDE_APP_START; i < MODULE_END; i++) {
		if (bit_check(&g_mlps_app_bit_map, i))
			(void)mlps_operate_gnss_power(MLPS_CMD_CLOSE, i);
	}
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
static void privacy_gnss_timeout(unsigned long data)
#else
static void privacy_gnss_timeout(struct timer_list *data)
#endif
{
	hwlog_info("%s enter in\n", __func__);
	if (g_privacy_mode == false)
		return;

	if (mlps_check_bit_map() == true) {
		if (g_privacy_timer_retry == 0) {
			g_privacy_timer_retry++;
			privacy_or_palace_ops_gnss();
			mod_timer(&privacy_gnss_timer, jiffies + 1 * HZ);
		} else {
			g_privacy_timer_retry = 0;
		}
		hwlog_info("%s mlps_check_bit_map fail 0x%x\n", __func__, g_mlps_app_bit_map);
		return;
	}

	g_privacy_timer_retry = 0;
	mlps_privacy_notify_ta();

	return;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
static void get_ipv4_timeout(unsigned long data)
#else
static void get_ipv4_timeout(struct timer_list *data)
#endif
{
	hwlog_info("%s is enter\n", __func__);
	if (g_push_gnss_status != ST_PUSH_OPEN_SUC) {
		hwlog_warn("%s g_push_gnss_status is not open\n", __func__);
		return;
	}

	int ret = mlps_get_current_ipv4_addr();
	if (ret != SUCCESS) {
		hwlog_warn("%s mlps_get_current_ipv4_addr fail\n", __func__);
	}
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
static void get_ipv6_timeout(unsigned long data)
#else
static void get_ipv6_timeout(struct timer_list *data)
#endif
{
	hwlog_info("%s is enter\n", __func__);

	if (g_push_gnss_status != ST_PUSH_OPEN_SUC) {
		hwlog_warn("%s g_push_gnss_status is not open\n", __func__);
		return;
	}

	mlps_get_current_ipv6_addr();
	if (g_get_ipv6_retry_cnt < IPV6_RETRY_MAX) {
		g_get_ipv6_retry_cnt++;
	}
	return;
}

static void mlps_work_handle(struct work_struct *work)
{
	struct mlps_work_t *p = container_of(work, struct mlps_work_t, worker);
	switch (p->work_type) {
		case MLPS_WORK_GNSS:
			mlps_gnss_handle(p);
			break;

		case MLPS_WORK_TA:
			mlps_privacy_op_ta();
			break;

		case MLPS_WORK_WIFI:
			mlps_wifi_handle(p);
			break;

		case MLPS_WORK_WIFI_SEND:
			mlps_wifi_send_handle(p);
			break;

		default:
			hwlog_warn("%s unknow type %d\n", __func__, p->work_type);
			break;
	}

	kfree(p);
}

static void notify_ap_mlps_recovery(void)
{
	g_push_gnss_status = ST_PUSH_CLOSE;
	char mlps_recovery_data[MLPS_RECOVERY_DATA_LEN] = {MLPS_RECOVERY_HIGH, MLPS_RECOVERY_LOW,
		MLPS_RECOVERY_LEN, 0, 0, 0, 0, 0};
	upload_mlps_data((char *)mlps_recovery_data, MLPS_RECOVERY_DATA_LEN);
}

static int mlps_ioc_get_app_version(void __user *argp)
{
	int rc = 0;
	app_version_t temp;

	if (copy_from_user(&temp, argp, sizeof(app_version_t)))
		hwlog_err("%s copy_from_user fail or arg is NULL\n", __func__);

	switch (temp.app_type) {
	case APP_SOFTBUS:
		if (copy_to_user(argp, &g_softbus_version, sizeof(softbus_version_t)))
			rc = -EFAULT;
		break;

	case APP_PUSHPROXY:
		if (copy_to_user(argp, &g_push_version, sizeof(push_version_t)))
			rc = -EFAULT;
		break;

	case APP_HMSCORE:
		if (copy_to_user(argp, &g_am_version, sizeof(app_version_t)))
			rc = -EFAULT;
		break;

	case APP_NEARLINK:
		if (copy_to_user(argp, &g_nearlink_version, sizeof(app_version_t)))
			rc = -EFAULT;
		break;

	default:
		rc = -EFAULT;
		break;
	}

	return rc;
}

static int mlps_ioc_get_ufs_version(void __user *argp)
{
	int rc = 0;
#ifdef CONFIG_DFA_MCQ_OHOS
	bool res = is_dfa_ftl_inf();
#else
	bool res = true;
#endif

	if (copy_to_user(argp, &res, sizeof(bool))) {
		hwlog_err("%s copy_to_user fail or arg is NULL\n", __func__);
		rc = -EFAULT;
	}

	return rc;
}
/*
 * Description: ioctl function to /dev/mlpshub, do open, do config/debug
 *              cmd to mlpshub
 * Return:      result of ioctrl command, 0 successed, -ENOTTY failed
 */
static long mlps_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;

	switch (cmd) {
	case MLPS_IOCTL_MLPS_START:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_MLPS_START\n", __func__);
		break;

	case MLPS_IOCTL_MLPS_STOP:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_MLPS_STOP\n", __func__);
		break;

	case MLPS_IOCTL_MLPS_ATTR_START:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_MLPS_ATTR_START\n", __func__);
		break;

	case MLPS_IOCTL_MLPS_ATTR_STOP:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_MLPS_ATTR_STOP\n", __func__);
		break;

	case MLPS_IOCTL_MLPS_INTERVAL_SET:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_MLPS_INTERVAL_SET\n", __func__);
		break;

	case MLPS_IOCTL_GET_APP_VERSION:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_GET_APP_VERSION\n", __func__);
		return mlps_ioc_get_app_version(argp);

	case MLPS_IOCTL_GET_UFS_VERSION:
		hwlog_info("mlps: %s  cmd: MLPS_IOCTL_GET_UFS_VERSION\n", __func__);
		return mlps_ioc_get_ufs_version(argp);

	default:
		hwlog_err("mlps: %s unknown cmd : %u\n", __func__, cmd);
		return -ENOTTY;
	}

	return send_mlps_cmd(cmd, arg, sizeof(arg));
}

/* open to /dev/mlpshub, do nothing now */
static int mlps_open(struct inode *inode, struct file *file)
{
	hwlog_info("mlps: enter %s\n", __func__);
	return 0;
}

/* release to /dev/mlpshub, do nothing now */
static int mlps_release(struct inode *inode, struct file *file)
{
	hwlog_info("mlps: %s ok\n", __func__);
	return 0;
}

#ifdef CONFIG_MLPS_PL_FEATURE
static void send_map_switch(void)
{
	if (g_map_trajectory_recording_switch == false) {
		hwlog_info("%s map switch is not open", __func__);
		return;
	}

	char *data = (char *)kzalloc(DATA_LEN_16 + SUBCMD_LEN, GFP_KERNEL);
	if (data == NULL) {
		hwlog_err("%s data kzalloc fail\n", __func__);
		return;
	}

	pkt_mlps_sub_header_t *temp = (pkt_mlps_sub_header_t *)data;
	temp->subcmd = SUB_CMD_MLPS_CONFIG_REQ;
	pkt_mlps_detail_data_t *tmp = (pkt_mlps_detail_data_t *)temp->value;
	tmp->mlps_app_type = APP_MAP;
	tmp->app_len = DATA_LEN_12;
	tmp->mlps_module_type = 0;
	tmp->module_len = DATA_LEN_8;
	tmp->mlps_cmd = MLPS_CMD_CONFIG;
	tmp->cmd_len = DATA_LEN_4;
	pkt_mlps_cmd_data_t *value = (pkt_mlps_cmd_data_t *)tmp->value;
	value->cmd = MAP_DUMP_ENABLE;
	value->cmd_len = 0;
	int ret = send_mlps_cmd_ext(data, DATA_LEN_16, NULL, false);
	if (ret == 0) {
		hwlog_info("%s send MAP_DUMP_ENABLE SUCCESS\n", __func__);
	} else {
		hwlog_warn("%s send MAP_DUMP_ENABLE FAIL\n", __func__);
	}

	if (data != NULL) {
		kfree(data);
		data = NULL;
	}
}
#endif

static void enable_mlps_when_recovery_iom3(void)
{
	g_mlps_ref_cnt = 0;

	send_mlps_cmd_internal(TAG_MLPS, CMD_CMN_OPEN_REQ,
		SUB_CMD_NULL_REQ, false);
#ifdef CONFIG_MLPS_PL_FEATURE
	send_map_switch();
#endif
}

static int mlps_recovery_notify(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	/* prevent access the emmc now: */
	hwlog_info("%s (%lu) +\n", __func__, foo);
	switch (foo) {
	case IOM3_RECOVERY_IDLE:
		notify_ap_mlps_recovery();
		break;
	case IOM3_RECOVERY_START:
	case IOM3_RECOVERY_MINISYS:
	case IOM3_RECOVERY_3RD_DOING:
	case IOM3_RECOVERY_FAILED:
		break;
	case IOM3_RECOVERY_DOING:
		save_step_count();
		enable_mlps_when_recovery_iom3();
		break;
	default:
		hwlog_err("%s -unknow state %ld\n", __func__, foo);
		break;
	}
	hwlog_info("%s -\n", __func__);
	return 0;
}

static struct notifier_block g_mlps_recovery_notify = {
	.notifier_call = mlps_recovery_notify,
	.priority = -1,
};

/* file_operations to mlps */
static const struct file_operations mlps_fops = {
	.owner = THIS_MODULE,
	.llseek = no_llseek,
	.read = mlps_read,
	.write = mlps_write,
	.unlocked_ioctl = mlps_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = mlps_ioctl,
#endif
	.open = mlps_open,
	.release = mlps_release,
};

/* miscdevice to motion */
static struct miscdevice mlpshub_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mlpshub",
	.fops = &mlps_fops,
};

static void mlps_read_dts_info(struct device_node *mlps_node)
{
	uint32_t temp = 0;
	if (of_property_read_u32(mlps_node, "push_proxy_version", &temp)) {
		hwlog_err("%s:read push_proxy_version fail\n", __func__);
	} else {
		g_push_version.push_proxy_version = (uint32_t)temp;
		hwlog_info("mlps: push_proxy_version : 0x%x\n", g_push_version.push_proxy_version);
	}
	if (of_property_read_u32(mlps_node, "push_cloud_version", &temp)) {
		hwlog_err("%s:read push_cloud_version fail\n", __func__);
	} else {
		g_push_version.push_cloud_version = (uint32_t)temp;
		hwlog_info("mlps: push_cloud_version : 0x%x\n", g_push_version.push_cloud_version);
	}
	if (of_property_read_u32(mlps_node, "softbus_version", &temp)) {
		hwlog_err("%s:read softbus_version fail\n", __func__);
	} else {
		g_softbus_version.softbus_version = (uint32_t)temp;
		hwlog_info("mlps: softbus_version : 0x%x\n", g_softbus_version.softbus_version);
	}
	if (of_property_read_u32(mlps_node, "softbus_rsv", &temp)) {
		hwlog_err("%s:read softbus_rsv fail\n", __func__);
	} else {
		g_softbus_version.rsv = (uint32_t)temp;
		hwlog_info("mlps: softbus_rsv : 0x%x\n", g_softbus_version.rsv);
	}
	if (of_property_read_u32(mlps_node, "am_version1", &temp)) {
		hwlog_err("%s:read am_version1 fail\n", __func__);
	} else {
		g_am_version.version1 = (uint32_t)temp;
		hwlog_info("mlps: am_version1 : 0x%x\n", g_am_version.version1);
	}
	if (of_property_read_u32(mlps_node, "am_version2", &temp)) {
		hwlog_err("%s:read am_version2 fail\n", __func__);
	} else {
		g_am_version.version2 = (uint32_t)temp;
		hwlog_info("mlps: am_version2 : 0x%x\n", g_am_version.version2);
	}
	if (of_property_read_u32(mlps_node, "nearlink_collabration_version1", &temp)) {
		hwlog_err("%s:read nearlink_version1 fail\n", __func__);
	} else {
		g_nearlink_version.version1 = (uint32_t)temp;
		hwlog_info("mlps: nearlink_version1 : 0x%x\n", g_nearlink_version.version1);
	}
	if (of_property_read_u32(mlps_node, "nearlink_collabration_version2", &temp)) {
		hwlog_err("%s:read nearlink_version2 fail\n", __func__);
	} else {
		g_nearlink_version.version2 = (uint32_t)temp;
	}
}

static int is_mlps_supported(void)
{
	int len = 0;
	struct device_node *mlps_node = NULL;
	const char *mlps_status = NULL;
	const char *mlps_operate_conn = NULL;
	static int ret = SUCCESS;

	mlps_node = of_find_compatible_node(NULL, NULL, MLPS_COMPATIBLE_NAME);
	if (!mlps_node) {
		hwlog_err("%s, can not find node mlps_status\n", __func__);
		return FAIL;
	}

	mlps_status = of_get_property(mlps_node, "status", &len);
	if (!mlps_status) {
		hwlog_err("%s, can't find property status\n", __func__);
		return FAIL;
	}

	if (strstr(mlps_status, "ok")) {
		hwlog_info("%s, mlps enabled!\n", __func__);
		ret = SUCCESS;
		if (of_property_read_string_index(mlps_node, "operate_conn", 0, &mlps_operate_conn) != 0)
			hwlog_err("%s, fail to read mlps operate_conn\n", __func__);
		if (strstr(mlps_operate_conn, "ok")) {
			g_support_conn_operation = true;
			hwlog_info("%s, mlps needs to operate conn!\n", __func__);
		}
		mlps_read_dts_info(mlps_node);
	} else {
		hwlog_err("%s, mlps disabled!\n", __func__);
		ret = FAIL;
	}
	return ret;
}

static int mlps_workqueue_create(void)
{
	g_mlps_wq  = create_singlethread_workqueue("mlps_workqueue");
	if (g_mlps_wq == NULL) {
		hwlog_err("create_mlps_wq_singlethread_workqueue fail\n");
		return -EFAULT;
	}

	spin_lock_init(&link_hook_lock);

	for (int i = 0; i < PUSH_LINK_MAX - PUSH_LINK_1; i++) {
		g_v4_f[i].link_id = PUSH_LINK_1 + i;
		g_v6_f[i].link_id = PUSH_LINK_1 + i;
	}

	return 0;
}
/*
* Description:	apply kernel buffer, register mlps_miscdev
* Return: 		result of function, 0 successed, else false
*/
static int __init mlpshub_init(void)
{
	int ret;

	if (is_sensorhub_disabled())
		return -1;

	ret = is_mlps_supported();
	if (ret != 0)
	{
		hwlog_info("%s, not support mlps!\n", __func__);
		return ret;
	}

	mlps_ops_conn_function_init();

	ret = mlps_workqueue_create();
	if (ret == -EFAULT) {
		hwlog_err("mlps: %s mlps_workqueue_create err=%d\n", __func__, ret);
		return ret;
	}

	ret = inputhub_route_open(ROUTE_MLPS_PORT);
	if (ret != 0) {
		hwlog_err("mlps: %s cannot open inputhub route err=%d\n",
			__func__, ret);
		return ret;
	}

	ret = misc_register(&mlpshub_miscdev);
	if (ret != 0) {
		hwlog_err("%s cannot register miscdev err=%d\n", __func__, ret);
		inputhub_route_close(ROUTE_MLPS_PORT);
		return ret;
	}
	register_mcu_event_notifier(TAG_MLPS, CMD_DATA_REQ, process_mlps_data_from_mcu);
	register_iom3_recovery_notifier(REC_USR_MLPS, &g_mlps_recovery_notify);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	setup_timer(&privacy_gnss_timer, privacy_gnss_timeout, 0);
	setup_timer(&get_ipv6_timer, get_ipv6_timeout, 0);
	setup_timer(&get_ipv4_timer, get_ipv4_timeout, 0);
#else
	timer_setup(&privacy_gnss_timer, privacy_gnss_timeout, 0);
	timer_setup(&get_ipv6_timer, get_ipv6_timeout, 0);
	timer_setup(&get_ipv4_timer, get_ipv4_timeout, 0);
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	mlps_wl = wakeup_source_register(NULL, "mlps_sensorhub");
#else
	mlps_wl = wakeup_source_register("mlps_sensorhub");
#endif

	hwlog_info("%s ok\n", __func__);
	return ret;
}

/* release kernel buffer, deregister mlpshub_ud_miscdev */
static void __exit mlpshub_exit(void)
{
	inputhub_route_close(ROUTE_MLPS_PORT);
	wakeup_source_unregister(mlps_wl);
	mlps_wl = NULL;
	misc_deregister(&mlpshub_miscdev);
	hwlog_info("exit %s\n", __func__);
}

late_initcall_sync(mlpshub_init);
module_exit(mlpshub_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("MLPSHub driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
