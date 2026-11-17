

#include <securec.h>
#include <platform_include/basicplatform/linux/hw_cmdline_parse.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/pm_wakeup.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/types.h>
#include <linux/printk.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif

#include "signal_hub_dfx.h"

#define TIME_BUFFER_SIZE 24
#define STATE_BUFFER_SIZE (MAX_TUNER_NUM * 4)
#define TOTAL_TYPE MAX_TUNER_NUM * (2 + MAX_CFG_STATE_NUM + MAX_SYSTEM_STATE_NUM)
#define ABNORMAL_TOTAL_TYPE 4
#define SIGNALHUB_REAL_TIME_POLICY 3

static signalhub_statistic_data g_signalhub_statistic;
static signalhub_abnormal_data g_signalhub_abnormal;
static signalhub_kernel_record_data g_record_data[MAX_NC_SYSTEM] = {0};

static int array_to_string(const uint32_t array[MAX_TUNER_NUM], char *buffer, int buffer_size)
{
	int ret;
	ret = snprintf_s(buffer, buffer_size, buffer_size, "%u,%u", array[0], array[1]);
	if (ret > buffer_size) {
		hwlog_err("signalhub_dfx %s: snprintf_s failed: %d\n", __func__, ret);
		return -EFAULT;
	}
	return 0;
}

static int matric_to_string(const uint32_t *array, int cols, char *buffer, int buffer_size)
{
    if (!array || !buffer || cols <= 0) {
        hwlog_err("signalhub_dfx %s: Invalid input parameters\n", __func__);
        return -EFAULT;
    }
    
    int ret = 0;
    int current_pos = 0;
    ret = snprintf_s(buffer, buffer_size, buffer_size, "%u", array[0]);
    if (ret < 0 || ret >= buffer_size) {
        hwlog_err("signalhub_dfx %s Output buffer overflow\n", __func__);
        return ret;
    }
    current_pos += ret;

    for (int i = 1; i < cols; i++) {
        ret = snprintf_s(buffer + current_pos, buffer_size - current_pos, buffer_size - current_pos, ",%u", array[i]);
        if (ret < 0 || (current_pos + ret) >= buffer_size) {
            hwlog_err("signalhub_dfx %s Output buffer overflow\n", __func__);
            return ret;
        }
        current_pos += ret;
    }

    return 0;
}

#ifdef CONFIG_HISYSEVENT
static int hisysevent_put_to_event(struct hiview_hisysevent *event)
{
    hisysevent_put_integer(event, "WIFI_SCAN", (long long)(g_signalhub_statistic.fir_data.wifi_time.wifi_scan_time));
    hisysevent_put_integer(event, "WIFI_CONN", (long long)(g_signalhub_statistic.fir_data.wifi_time.wifi_sta_time));
    hisysevent_put_integer(event, "WIFI_CONN_ACTIVE",
        (long long)(g_signalhub_statistic.fir_data.wifi_time.wifi_active_time));
    hisysevent_put_integer(event, "WIFI_CONN_BEACON",
        (long long)(g_signalhub_statistic.fir_data.wifi_time.wifi_beacon_time));
    hisysevent_put_integer(event, "BSLE_C0_ACTIVE",
        (long long)(g_signalhub_statistic.fir_data.bsle_time.bsle_c0_active_use_time));
    hisysevent_put_integer(event, "BSLE_C0_NACTIVE",
        (long long)(g_signalhub_statistic.fir_data.bsle_time.bsle_c0_active_off_time));
    hisysevent_put_integer(event, "BSLE_C1_ACTIVE",
        (long long)(g_signalhub_statistic.fir_data.bsle_time.bsle_c1_active_use_time));
    hisysevent_put_integer(event, "BSLE_C1_NACTIVE",
        (long long)(g_signalhub_statistic.fir_data.bsle_time.bsle_c1_active_off_time));

	// 分配足够大的内存
	char *fix_policy = kzalloc(TIME_BUFFER_SIZE * TOTAL_TYPE, GFP_KERNEL);
	if (fix_policy == NULL) {
		hwlog_err("signalhub %s: fix_policy allocate failed\n",  __func__);
		return -EFAULT;
	}

	char *real_policy = fix_policy + TIME_BUFFER_SIZE * MAX_TUNER_NUM;
	char *tuner0_cfg_time = real_policy + TIME_BUFFER_SIZE * MAX_TUNER_NUM;
	char *tuner1_cfg_time = tuner0_cfg_time + TIME_BUFFER_SIZE * MAX_CFG_STATE_NUM;
	char *tuner0_state_time = tuner1_cfg_time + TIME_BUFFER_SIZE * MAX_CFG_STATE_NUM;
	char *tuner1_state_time = tuner0_cfg_time + TIME_BUFFER_SIZE * MAX_SYSTEM_STATE_NUM;

    array_to_string(g_signalhub_statistic.fir_data.fix_policy_time, fix_policy, TIME_BUFFER_SIZE * MAX_TUNER_NUM);
    array_to_string(g_signalhub_statistic.fir_data.real_policy_time, real_policy, TIME_BUFFER_SIZE * MAX_TUNER_NUM);
    matric_to_string((const uint32_t *)g_signalhub_statistic.cfg_state_time[0], MAX_CFG_STATE_NUM,
        tuner0_cfg_time, TIME_BUFFER_SIZE * MAX_CFG_STATE_NUM);
    matric_to_string((const uint32_t *)g_signalhub_statistic.cfg_state_time[1], MAX_CFG_STATE_NUM,
        tuner1_cfg_time, TIME_BUFFER_SIZE * MAX_CFG_STATE_NUM);
    matric_to_string((const uint32_t *)g_signalhub_statistic.fir_data.system_state_time[0], MAX_SYSTEM_STATE_NUM,
        tuner0_state_time, TIME_BUFFER_SIZE * MAX_SYSTEM_STATE_NUM);
    matric_to_string((const uint32_t *)g_signalhub_statistic.fir_data.system_state_time[1], MAX_SYSTEM_STATE_NUM,
        tuner1_state_time, TIME_BUFFER_SIZE * MAX_SYSTEM_STATE_NUM);

    hisysevent_put_string(event, "FIX_POLICY", fix_policy);
    hisysevent_put_string(event, "REAL_POLICY", real_policy);
    hisysevent_put_string(event, "TUNER_ANT0_CFG_TIME", tuner0_cfg_time);
    hisysevent_put_string(event, "TUNER_ANT1_CFG_TIME", tuner1_cfg_time);
    hisysevent_put_string(event, "TUNER_ANT0_STATE_TIME", tuner0_state_time);
    hisysevent_put_string(event, "TUNER_ANT1_STATE_TIME", tuner1_state_time);

    kfree(fix_policy);
    return 0;
}
#endif

static void process_signalhub_statistic_data(void *data, uint32_t data_len)
{
	if (data == NULL) {
		hwlog_err("signalhub_dfx %s: data error\n", __func__);
		return;
	}

	signalhub_statistic_data *signalhub_data = (signalhub_statistic_data *)data;
	if (data_len != sizeof(g_signalhub_statistic)) {
		hwlog_err("signalhub_dfx %s: data_len invalid, data_len = %u\n", __func__, data_len);
		return;
	}

	int ret;
#ifdef CONFIG_HISYSEVENT
	struct hiview_hisysevent *event = NULL;
	ret = memcpy_s(&g_signalhub_statistic, sizeof(signalhub_statistic_data), signalhub_data, data_len);
	if (ret != EOK) {
		hwlog_err("signalhub_dfx %s: memcpy signalhub_data fail!\n", __func__);
		return;
	}

	event = hisysevent_create("CHR", "SIGNALHUB_KEY_INFO_EVENT", STATISTIC);
	if (!event) {
		hwlog_err("signalhub_dfx %s: hisysevent_create failed!\n", __func__);
		return;
	}

	ret = hisysevent_put_to_event(event);
    if (ret != 0) {
        hwlog_err("signalhub_dfx %s: hisysevent put to event failed\n", __func__);
        return;
    }

	hisysevent_write(event);
	hisysevent_destroy(&event);
	hwlog_info("signalhub_dfx %s: signalhub statistic report to hiview finish\n", __func__);
#else
    hwlog_info("signalhub_dfx %s: CONFIG_HISYSEVENT not enabled, skip report\n", __func__);
#endif
}

static void process_signalhub_abnormal_data(void *data, uint32_t data_len)
{
    if (data == NULL) {
        hwlog_err("signalhub %s: invalid data pointer\n", __func__);
        return;
    }
    
    signalhub_abnormal_data *signalhub_data = (signalhub_abnormal_data *)data;
    if (data_len != sizeof(g_signalhub_abnormal)) {
        hwlog_err("signalhub_dfx %s: data_len invalid, data_len = %u\n", __func__, data_len);
        return;
    }

#ifdef CONFIG_HISYSEVENT
    struct hiview_hisysevent *event = NULL;
    if (memcpy_s(&g_signalhub_abnormal, sizeof(g_signalhub_abnormal), signalhub_data, data_len) != EOK) {
        hwlog_err("signalhub_dfx %s: memcpy signalhub_data fail!\n", __func__);
        return;
    }
    
    event = hisysevent_create("CHR", "SIGNALHUB_ABNORMAL_INFO", FAULT);
    if (!event) {
        hwlog_err("signalhub_dfx %s: hisysevent_create failed!\n", __func__);
        return;
    }

    hisysevent_put_integer(event, "TRIGGER_TYPE", (long long)g_signalhub_abnormal.trigger_type);
    hisysevent_put_integer(event, "WIFI2P4G_STATUS", (long long)g_signalhub_abnormal.wifi_2P4G_status);
    hisysevent_put_integer(event, "WIFI5G_STATUS", (long long)g_signalhub_abnormal.wifi_5G_status);
    hisysevent_put_integer(event, "BSLE2P4G_STATUS", (long long)g_signalhub_abnormal.bsle_2P4G_status);
    hisysevent_put_integer(event, "BSLE5G_STATUS", (long long)g_signalhub_abnormal.bsle_5G_status);
    
    // put_string
    char *policy = kzalloc(STATE_BUFFER_SIZE * ABNORMAL_TOTAL_TYPE, GFP_KERNEL);
    if (policy == NULL) {
        hwlog_err("signalhub %s: policy allocate failed\n",  __func__);
        return;
    }
    char *mask = policy + STATE_BUFFER_SIZE;
    char *sys_state = mask + STATE_BUFFER_SIZE;
    char *cfg_index = sys_state + STATE_BUFFER_SIZE;
    array_to_string((const uint32_t *)g_signalhub_abnormal.policy, policy, STATE_BUFFER_SIZE);
    array_to_string((const uint32_t *)g_signalhub_abnormal.mask, mask, STATE_BUFFER_SIZE);
    array_to_string((const uint32_t *)g_signalhub_abnormal.sys_state, sys_state, STATE_BUFFER_SIZE);
    array_to_string((const uint32_t *)g_signalhub_abnormal.cfg_index, cfg_index, STATE_BUFFER_SIZE);
    hisysevent_put_string(event, "POLICY", policy);
    hisysevent_put_string(event, "MASK", mask);
    hisysevent_put_string(event, "SYS_STATE", sys_state);
    hisysevent_put_string(event, "CFG_INDEX", cfg_index);
    hwlog_info("%s: policy:%s, mask:%s, cfg_index:%s\n", __func__, policy, mask, cfg_index);
    kfree(policy);

    hisysevent_write(event);
    hisysevent_destroy(&event);
#else
    hwlog_info("signalhub_dfx %s: CONFIG_HISYSEVENT not enabled, skip report\n", __func__);
#endif
}

void process_signalhub_dfx_msg(signalhub_comm_report_data *data)
{
    if (data == NULL) {
        hwlog_err("signalhub %s: invalid data pointer\n", __func__);
        return;
    }
    signalhub_dfx_report_data *dfx_data = (signalhub_dfx_report_data *)(data->report_data);
    switch (dfx_data->subcmd) {
        case SIGNALUHB_DFX_STATISTIC_CMD:
            hwlog_info("signalhub %s: dfx statistic msg report\n", __func__);
            signalhub_statistic_data *statis_data = (signalhub_statistic_data *)(dfx_data->data);
            process_signalhub_statistic_data(statis_data, sizeof(signalhub_statistic_data));
            break;
        case SIGNALHUB_DFX_ABNORMAL_CMD:
            hwlog_info("signalhub %s: dfx abnormal msg report\n", __func__);
            signalhub_abnormal_data *abnormal_data = (signalhub_abnormal_data *)(dfx_data->data);
            process_signalhub_abnormal_data(abnormal_data, sizeof(signalhub_abnormal_data));
            break;
        default:
            break;
    }
}

int process_query_report_msg(signalhub_comm_report_data *data)
{
    if (data == NULL) {
        hwlog_err("signalhub %s: invalid data pointer\n", __func__);
        return -EINVAL;
    }
    int ret;
    uint16_t trigger_type;
    signalhub_report_query_data *query_data = (signalhub_report_query_data *)(data->report_data);
    if (query_data == NULL) {
        hwlog_err("signalhub %s: invalid query_data pointer\n", __func__);
        return -EINVAL;
    }

    trigger_type = query_data->trigger_type;
    if (trigger_type >= MAX_NC_SYSTEM) {
        hwlog_err("signalhub %s invalid trigger type:%d\n", __func__, trigger_type);
        return -EFAULT;
    }

    struct mutex* lock = get_signalhub_mutex();
    if (lock == NULL) {
        hwlog_err("signalhub %s: get_mutex returned NULL\n", __func__);
        return -EINVAL;
    }

    mutex_lock(lock);
    ret = memcpy_s(&g_record_data[trigger_type].data, sizeof(signalhub_report_query_data),
        query_data, sizeof(signalhub_report_query_data));
    if (ret != 0) {
        hwlog_err("signalhub %s query_data memcpy failed\n", __func__);
        mutex_unlock(lock);
        return -EFAULT;
    }
    g_record_data[trigger_type].valid_flag = 1;
    mutex_unlock(lock);

    return ret;
}

int signal_hub_send_abnormal_emergency(void __user *argp, bool is_open)
{
    if (!argp) {
        hwlog_err("signalhub %s: argp NULL Pointer!\n", __func__);
        return -EINVAL;
    }

    int ret = 0;
    sighub_send_msg_data *msg;
    
    int total_size = sizeof(sighub_send_msg_data) + sizeof(abnormal_state_unit) + sizeof(signalhub_state_unit);

    if (is_open == false) {
        abnormal_state_unit abnormal_return_unit;
        abnormal_return_unit.subcmd = 0xFF;
        hwlog_warn("signalhub %s signalhub is not supported\n", __func__);
        if (copy_to_user(argp, &abnormal_return_unit, sizeof(abnormal_state_unit))) {
            hwlog_warn("signalhub %s: copy_to_user failed!\n", __func__);
            return -EFAULT;
        }
        return -EINVAL;
    }

    // 为abnormal_state_unit的data成员分配空间,准备加载bsle_state_unit
    msg = (sighub_send_msg_data *)kmalloc(total_size, GFP_KERNEL);
    if (!msg) {
        hwlog_err("Failed to allocate buffer\n");
        return -EINVAL;
    }
    ret = memset_s(msg, total_size, 0, total_size);
    if (ret != EOK) {
        hwlog_err("%s memset_s failed, ret = %d\n", __func__, ret);
        kfree(msg);
        return ret;
    }

    if (copy_from_user((unsigned char *)msg->data, (unsigned char *)argp,
        sizeof(abnormal_state_unit) + sizeof(signalhub_state_unit))) {
            hwlog_warn("signalhub %s: copy_from_user failed!\n", __func__);
            kfree(msg);
            return -EFAULT;
        }

    abnormal_state_unit *abnormal_unit = (abnormal_state_unit *)msg->data;
    msg->size = sizeof(abnormal_state_unit) + sizeof(signalhub_state_unit);
    msg->cmd = SIGNAL_HUB_ABNORMAL_CMD;

    hwlog_info("signalhub %s: cmd:%u, subcmd:%u\n", __func__, msg->cmd, abnormal_unit->subcmd);
    ret = signal_hub_send_to_sensorhub(CMD_CMN_CONFIG_REQ, msg, total_size);

    kfree(msg);
    return ret;
}

int signal_hub_send_query(void __user *argp, bool is_open)
{
    if (!argp) {
        hwlog_err("signalhub %s: argp NULL Pointer!\n", __func__);
        return -EINVAL;
    }

    int ret = 0;
    sighub_send_msg_data *msg;

    if (is_open == false) {
        int trigger_type = 0xFF;
        hwlog_warn("%s signalhub is not supported\n", __func__);
        if (copy_to_user(argp, &trigger_type, sizeof(signalhub_trigger_type))) {
            hwlog_warn("signalhub%s: copy_to_user failed!\n", __func__);
            return -EFAULT;
        }
        return -EINVAL;
    }

    msg = (sighub_send_msg_data *)kmalloc(sizeof(sighub_send_msg_data) + sizeof(signalhub_trigger_type), GFP_KERNEL);
    if (!msg) {
        hwlog_err("Failed to allocate buffer\n");
        return -EINVAL;
    }
    ret = memset_s(msg, sizeof(sighub_send_msg_data) + sizeof(signalhub_trigger_type),
        0, sizeof(sighub_send_msg_data) + sizeof(signalhub_trigger_type));
    if (ret != EOK) {
        hwlog_err("%s memset_s failed, ret = %d\n", __func__, ret);
        kfree(msg);
        return ret;
    }

    if (copy_from_user((unsigned char *)msg->data, (unsigned char *)argp, sizeof(signalhub_trigger_type))) {
        hwlog_warn("signalhub %s: copy_from_user failed!\n", __func__);
        kfree(msg);
        return -EFAULT;
    }

    msg->size = sizeof(signalhub_trigger_type);
    msg->cmd = SIGNAL_HUB_QUERY_INFO_CMD;

    hwlog_info("signalhub %s: size:%u, cmd:%u\n", __func__, msg->size, msg->cmd);
    ret = signal_hub_send_to_sensorhub(CMD_CMN_CONFIG_REQ, msg,
        sizeof(sighub_send_msg_data) + sizeof(signalhub_trigger_type));
    return ret;
}

int signal_hub_get_state_info(void __user *argp)
{
    int ret;
    uint16_t trigger_type;
    signalhub_report_query_data report_data;
    
    if (!argp) {
        hwlog_err("signalhub %s: argp NULL Pointer!\n", __func__);
        return -EINVAL;
    }
    memset_s(&report_data, sizeof(signalhub_report_query_data), 0, sizeof(signalhub_report_query_data));

    if (copy_from_user(&report_data, argp, sizeof(signalhub_report_query_data))) {
        hwlog_warn("signalhub %s: copy_from_user failed!\n", __func__);
        return -EFAULT;
    }

    trigger_type = report_data.trigger_type;
    if (trigger_type >= MAX_NC_SYSTEM) {
        hwlog_err("signalhub %s invalid trigger type:%d\n", __func__, trigger_type);
        return -EFAULT;
    }
    hwlog_info("signalhub %s: trigger_type is %u\n", __func__, trigger_type);

    struct mutex* lock = get_signalhub_mutex();
    if (lock == NULL) {
        hwlog_err("signalhub %s: get_mutex returned NULL\n", __func__);
        return -EINVAL;
    }

    mutex_lock(lock);
    if (g_record_data[trigger_type].valid_flag == 0) {
        hwlog_err("signalhub %s: data is invalid!\n", __func__);
        mutex_unlock(lock);
        return -EINVAL;
    }
    ret = memcpy_s(&report_data, sizeof(signalhub_report_query_data), &g_record_data[trigger_type].data,
        sizeof(signalhub_report_query_data));
    if (ret != 0) {
        hwlog_err("signalhub %s report_data memcpy failed\n", __func__);
        mutex_unlock(lock);
        return -EFAULT;
    }

    if (copy_to_user(argp, &report_data, sizeof(signalhub_report_query_data))) {
        hwlog_warn("signalhub %s: copy_to_user failed!\n", __func__);
        mutex_unlock(lock);
        return -EFAULT;
    }
    hwlog_info("signalhub %s kernel_policy:%d, abnormal_type:%d\n", __func__,
        report_data.policy, report_data.abnormal_type);

    g_record_data[trigger_type].valid_flag = 0;
    mutex_unlock(lock);
    return ret;
}

uint32_t signalhub_recv_addr_info(unsigned int offset_addr)
{
    if (offset_addr > SOC_ADDR_OFFSET_SIZE) {
        hwlog_err("%s: offset_addr over SOC_ADDR_OFFSET_SIZE\n", __func__);
        return SOC_ADDR_OFFSET_SIZE;
    }

    void __iomem *base_vir_addr = NULL;
    void __iomem *target_vir_addr = NULL;
    signalhub_reg_recv_info recv_info;
    base_vir_addr = ioremap(SOC_ACPU_MIPI_BASE_ADDR, SOC_ADDR_OFFSET_SIZE);
    if (!base_vir_addr) {
        hwlog_err("%s: vir_addr is NULL\n", __func__);
        return SOC_ADDR_OFFSET_SIZE;
    }

    target_vir_addr = base_vir_addr + offset_addr;
    recv_info.value = readl(target_vir_addr);
    if (recv_info.reg.check_value != CHECK_VALUE) {
        hwlog_err("%s: invalid check_value\n", __func__);
        iounmap(base_vir_addr);
        return SOC_ADDR_OFFSET_SIZE;
    }

    iounmap(base_vir_addr);
    return recv_info.value;
}

void signalhub_send_addr_info(unsigned int offset_addr)
{
    if (offset_addr > SOC_ADDR_OFFSET_SIZE) {
        hwlog_err("%s: offset_addr over SOC_ADDR_OFFSET_SIZE\n", __func__);
        return;
    }

    void __iomem *base_vir_addr = NULL;
    void __iomem *target_vir_addr = NULL;
    base_vir_addr = ioremap(SOC_ACPU_MIPI_BASE_ADDR, SOC_ADDR_OFFSET_SIZE);
    if (!base_vir_addr) {
        hwlog_err("%s: vir_addr is NULL\n", __func__);
        return;
    }
    target_vir_addr = base_vir_addr + offset_addr;

    signalhub_reg_send_info send_info;
    send_info.reg.tuner0_policy = SIGNALHUB_REAL_TIME_POLICY;
    send_info.reg.sys1_tuner0_mask = 1;
    send_info.reg.sys2_tuner0_mask = 1;
    send_info.reg.sys1_tuner0_status = 1;
    send_info.reg.sys2_tuner0_status = 1;

    send_info.reg.tuner1_policy = SIGNALHUB_REAL_TIME_POLICY;
    send_info.reg.sys1_tuner1_mask = 1;
    send_info.reg.sys2_tuner1_mask = 1;
    send_info.reg.sys1_tuner1_status = 1;
    send_info.reg.sys2_tuner1_status = 1;
    send_info.reg.check_value = CHECK_VALUE;

    writel(send_info.value, target_vir_addr);
    iounmap(base_vir_addr);
}