/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Audio Resource Control Mutex
 * Author: Shengzexuan Shengzexuan@huawei.com
 * Create: 2025-05-13
 */

#include "audio_resource_mutex.h"
#include <soc_sctrl_interface.h>
#include <linux/of_address.h>
#include "asp_codec_resource_control.h"

#define AUDIO_RESOURCE_HARWARE_LOCK_ID           78
#define AP_USE_BIT                               BIT(14)
#define AP_USE_BIT_VOTE                          BIT(14) | BIT(30)
#define AP_USE_BIT_RELEASE                       BIT(30)
#define SENSORHUB_USE_BIT                        BIT(15)
#define SENSORHUB_USE_BIT_VOTE                   BIT(15) | BIT(31)
#define SENSORHUB_USE_BIT_RELEASE                BIT(31)
#define SCTRL_ADDR_SIZE                          0X1000
#define GET_HWLOCK_TIMEOUT                       100

static struct hwspinlock *audio_resource_hwlock;
static DECLARE_WAIT_QUEUE_HEAD(audio_resource_hwlock_waitq);
static uint32_t g_sensorhub_use_release_signal = 0;
static struct mutex audio_resource_hwlock_mutex;
static uint32_t g_audiodsp_ready = true;
static uint8_t g_audio_user = 0;

static void __iomem *get_sysctrl_base(void)
{
	struct device_node *np = NULL;
	void __iomem *sysctrl_base = NULL;

	np = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
	if (np == NULL) {
		hwlog_err("can not find sysctrl node!\n");
		return NULL;
	}

	sysctrl_base = of_iomap(np, 0);
	if (sysctrl_base == NULL) {
		hwlog_err("get sysctrl_base error!\n");
		return NULL;
	}
	return sysctrl_base;
}

static int audio_resource_hwspin_trylock(void)
{
	int ret;
	ret = hwspin_trylock_in_atomic(audio_resource_hwlock);
	if (ret) {
		return -1;
	}
	return ret;
}

void audio_resource_hwspin_unlock(void)
{
	hwspin_unlock_in_atomic(audio_resource_hwlock);
}

static int process_arm_data_from_mcu(const struct pkt_header *head)
{
	pkt_arm_mcu_data *mcu_data = (pkt_arm_mcu_data *)head;
	if (mcu_data->value == RELEASE_CONTROL_NOTIFY) {
		g_sensorhub_use_release_signal = mcu_data->value;
		hwlog_info("%s: get data from mcu succ, value:%d\n", __func__, g_sensorhub_use_release_signal);
	} else if (mcu_data->value == SEND_SMARTPA_PARAM_NOTIFY) {
		hwlog_info("%s: get data from mcu succ, notify smartpa send param done!\n", __func__);
	} else {
		hwlog_err("%s: invalid value from mcu\n", __func__);
	}
	return 0;
}

static int send_get_hwlock_cmd(unsigned int subcmd)
{
	struct write_info pkg_ap = { 0 };
	pkt_parameter_req_t cpkt;
	struct pkt_header *hd = (struct pkt_header *)&cpkt;
	int ret;

	ret = memset_s(&cpkt, sizeof(cpkt), 0, sizeof(cpkt));
	if (ret != EOK) {
		hwlog_err("%s memset_s cpkt err\n", __func__);
		return -ENOTTY;
	}

	pkg_ap.tag = TAG_NOTIFICATION;
	pkg_ap.cmd = CMD_CMN_CONFIG_REQ;
	cpkt.subcmd = subcmd;
	pkg_ap.wr_buf = &hd[1];
	pkg_ap.wr_len = SUBCMD_LEN;

	ret = write_customize_cmd(&pkg_ap, NULL, true);
	if (ret != 0) {
		hwlog_err("%s failed ret = %d\n", __func__, ret);
		return -ENOTTY;
	}
	return 0;
}

void notify_sensorhub_stop(unsigned int subcmd)
{
	send_get_hwlock_cmd(subcmd);
	mutex_lock(&audio_resource_hwlock_mutex);
	unsigned long remain_wait_time = 0;
	remain_wait_time = wait_event_timeout(audio_resource_hwlock_waitq,
						g_sensorhub_use_release_signal != 0, msecs_to_jiffies(GET_HWLOCK_TIMEOUT));
	g_sensorhub_use_release_signal = 0;
	mutex_unlock(&audio_resource_hwlock_mutex);
	if (remain_wait_time <= 0) {
		hwlog_err("wait for sensorhub stop timeout type:\n", __func__);
		if (subcmd == SUB_CMD_STOP_NOTIFICATION_FORCE) {
			iom3_need_recovery(SENSORHUB_USER_MODID, SH_FAULT_USER_DUMP);
			hwlog_err("%s reset mcu done\n", __func__);
		}
		return;
	}
	hwlog_info("sensorhub_use_release succ\n");
}

int audio_resource_control_request(enum audio_resource_control_type usr_type)
{
	hwlog_info("%s usr_type:0x%x\n", __func__, usr_type);
	if (g_audiodsp_ready == false) {
		hwlog_err("audiodsp not ready, can't get control!\n");
		return -1;
	}

	if (g_audio_user != 0) {
		hwlog_info("pre user:0x%x\n", g_audio_user);
		g_audio_user |= BIT(usr_type);
		hwlog_info("%s ap already hold control, current user:0x%x\n", __func__, g_audio_user);
		return 0;
	}

	if (audio_resource_hwspin_trylock()) {
		hwlog_err("%s get lock fail!\n", __func__);
		return -1;
	}

	void __iomem *vir_base_addr = get_sysctrl_base();
	if (!vir_base_addr) {
		hwlog_err("%s: vir_base_addr is NULL\n", __func__);
		audio_resource_hwspin_unlock();
		return -1;
	}
	uint32_t val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	val = val & SENSORHUB_USE_BIT;
	hwlog_info("%s sensorhub use val:0x%x\n", __func__, val);
	if (val == 0) {
		hwlog_info("%s sensorhub not use\n", __func__);
		writel(AP_USE_BIT_VOTE, SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		hwlog_info("%s write ap use bit val:0x%x\n", __func__, val);
		iounmap(vir_base_addr);
		audio_resource_hwspin_unlock();
		g_audio_user |= BIT(usr_type);
		hwlog_info("%s succ, current user:0x%x\n", __func__, g_audio_user);
		return 0;
	} else {
		hwlog_info("%s sensorhub using, try force stop\n", __func__);
		notify_sensorhub_stop(SUB_CMD_STOP_NOTIFICATION_FORCE);
		writel(AP_USE_BIT_VOTE, SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		hwlog_info("%s write ap use bit val:0x%x\n", __func__, val);
		iounmap(vir_base_addr);
		audio_resource_hwspin_unlock();
		g_audio_user |= BIT(usr_type);
		hwlog_info("%s succ, current user:0x%x\n", __func__, g_audio_user);
		return 0;
	}
}

int audio_resource_control_release(enum audio_resource_control_type usr_type)
{
	hwlog_info("%s pre user:0x%x\n", __func__, g_audio_user);
	g_audio_user &= ~BIT(usr_type);
	hwlog_info("%s current user:0x%x\n", __func__, g_audio_user);
	if (g_audio_user != 0) {
		hwlog_info("%s ap has other user\n", __func__);
		return 0;
	}
	if (audio_resource_hwspin_trylock()) {
		hwlog_err("%s get lock fail!\n", __func__);
		return -1;
	}
	void __iomem *vir_base_addr = get_sysctrl_base();
	if (!vir_base_addr) {
		hwlog_err("%s: vir_base_addr is NULL\n", __func__);
		audio_resource_hwspin_unlock();
		return -1;
	}
	uint32_t val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	hwlog_info("%s read val:0x%x\n", __func__, val);
	writel(AP_USE_BIT_RELEASE, SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	hwlog_info("%s write ap use bit val:0x%x\n", __func__, val);
	iounmap(vir_base_addr);
	audio_resource_hwspin_unlock();
	return 0;
}

int audiodsp_reset_notify(enum dsp_reset_event event)
{
	if (event == DSP_RESET_EVENT_SUSPEND) {
		hwlog_info("%s dsp start reset\n", __func__);
		g_audiodsp_ready = false;
		if (audio_resource_hwspin_trylock()) {
			hwlog_err("%s get lock fail!\n", __func__);
			return -1;
		}
		void __iomem *vir_base_addr = get_sysctrl_base();
		if (!vir_base_addr) {
			hwlog_err("%s: vir_base_addr is NULL\n", __func__);
			audio_resource_hwspin_unlock();
			return -1;
		}
		uint32_t val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		hwlog_info("%s read val:0x%x\n", __func__, val);
		writel(AP_USE_BIT_RELEASE, SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		notify_sensorhub_stop(SUB_CMD_RELEASE_NOTIFICATION);
		val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
		hwlog_info("%s read after sensorhub release val:0x%x\n", __func__, val);
		iounmap(vir_base_addr);
		audio_resource_hwspin_unlock();
	} else if (event == DSP_RESET_EVENT_RESUME) {
		g_audiodsp_ready = true;
		hwlog_info("%s dsp reset ready\n", __func__);
	}

	return 0;
}

static void sensorhub_reset_notify(void)
{
	if (audio_resource_hwspin_trylock()) {
		hwlog_err("%s get lock fail!\n", __func__);
		return;
	}
	void __iomem *vir_base_addr = get_sysctrl_base();
	if (!vir_base_addr) {
		hwlog_err("%s: vir_base_addr is NULL\n", __func__);
		audio_resource_hwspin_unlock();
		return;
	}
	uint32_t val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	hwlog_info("[szx]%s val:0x%x\n", __func__, val);
	uint32_t val_shb = val & SENSORHUB_USE_BIT;
	writel(SENSORHUB_USE_BIT_RELEASE, SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	val = readl(SOC_SCTRL_SCBAKDATA3_MSK_ADDR(vir_base_addr));
	hwlog_info("[szx]%s crash clean shb bit val:0x%x\n", __func__, val);
	iounmap(vir_base_addr);
	audio_resource_hwspin_unlock();
	if (val_shb != 0)
		sensorhub_reset_notify_codec();
}

static int audio_resource_recovery_notifier(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	/* prevent access the emmc now: */
	hwlog_info("%s %lu enter\n", __func__, foo);
	switch (foo) {
	case IOM3_RECOVERY_IDLE:
		break;
	case IOM3_RECOVERY_START:
	case IOM3_RECOVERY_MINISYS:
	case IOM3_RECOVERY_3RD_DOING:
	case IOM3_RECOVERY_FAILED:
		break;
	case IOM3_RECOVERY_DOING:
		sensorhub_reset_notify();
		break;
	#ifdef CONFIG_BOX_RECOVERY
	case IOM3_RECOVERY_BOXREADY:
		hwlog_info("%s box ready\n", __func__);
	#endif
	default:
		hwlog_err("%s -unknow state %ld\n", __func__, foo);
		break;
	}
	hwlog_info("%s out\n", __func__);
	return 0;
}

static struct notifier_block recovery_notify = {
	.notifier_call = audio_resource_recovery_notifier,
	.priority = -1,
};

static int audio_resource_hwlock_init(void)
{
	audio_resource_hwlock = hwspin_lock_request_specific(AUDIO_RESOURCE_HARWARE_LOCK_ID);
	if (audio_resource_hwlock == NULL) {
		hwlog_err("unable to get audio_resource_hwlock\n");
		return -1;
	}
	hwlog_info("get audio_resource_hwlock succ!\n");
	init_waitqueue_head(&audio_resource_hwlock_waitq);
	hwlog_info("init audio_resource_hwlock_waitq_head succ!\n");
	mutex_init(&audio_resource_hwlock_mutex);
	hwlog_info("init audio_resource_hwlock_mutex succ!\n");
	register_mcu_event_notifier(TAG_NOTIFICATION, CMD_DATA_REQ, process_arm_data_from_mcu);
	hwlog_info("process_arm_data_from_mcu regist ok\n", __func__);
	register_iom3_recovery_notifier(REC_USR_AOD, &recovery_notify);
	return 0;
}

late_initcall_sync(audio_resource_hwlock_init);