/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: Contexthub 9030 driver.
 * Create: 2024-10-10
 */

#include <linux/init.h>
#include <linux/notifier.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/time.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/debugfs.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/io.h>
#include <linux/of.h>
#include "inputhub_api/inputhub_api.h"
#include "bbox_diaginfo_id_def.h"
#include <platform_include/basicplatform/linux/dfx_bbox_diaginfo.h>
#include <platform_include/basicplatform/linux/rdr_platform.h>
#include <platform_include/smart/linux/iomcu_status.h>
#include <platform_include/smart/linux/iomcu_ipc.h>
#include <securec.h>
#include <linux/arm-smccc.h>  /* just use in es */
#include "iodie_dev.h"
#include "iodie_drv.h"

#define NS_TO_US                          1000
#define NS_TO_MS                          1000000
#define IODIE_IPC_RETRY_TIMES             5
#define IODIE_IPC_RETRY_INTERVAL          200   // ms
#define IODIE_IPC_RETRY_THREHOLD          2000  // ms

#ifndef bit
#define bit(n)                            (1ul << ((uint32_t)(n)))
#endif
#define HIPHYIO_AXI_GROUP_NUM         4
#define HIPHYIO_AXI_GROUP_SIZE        32
#define axi_record_group(num)         ((num) / HIPHYIO_AXI_GROUP_SIZE)
#define axi_record_bit(num)           ((num) % HIPHYIO_AXI_GROUP_SIZE)
#define check_axi_record_bit(data, n) ((data)[(n) / HIPHYIO_AXI_GROUP_SIZE] & bit((n) % HIPHYIO_AXI_GROUP_SIZE))

struct iodie_error_info {
	enum iodie_err_status status;
	enum iodie_abrl_src src;
};

enum iodie_err_event {
	IODIE_ERR_EVT_OCCURED,
	IODIE_ERR_EVT_ACCESS_STOPPED,
	IODIE_ERR_EVT_END,
};

struct iodie_error_ext_msg {
	enum iodie_err_event evt;
	struct iodie_error_info info;
};

struct iodie_perf_stat{
	atomic64_t max_latency;
	enum iodie_commu_cmd cmd;
};

struct iodie_vote {
	uint8_t vote_count[IODIE_USER_END];
	uint32_t total;
};

#define IODIE_STATUS_PKT_LEN     8
#define IODIE_ST_INFO_DATA_MAX   10

struct iodie_status_pkt_msg {
	struct pkt_header hd;
	uint32_t sys_st;
	uint32_t err_st;
	uint32_t err_src;
	uint32_t data[IODIE_ST_INFO_DATA_MAX];
};

struct iodie_axi_record_pkt_msg {
	struct pkt_header hd;
	uint32_t user[HIPHYIO_AXI_GROUP_NUM];
};

struct iodie_gpio_wakeup_pkt_msg {
	struct pkt_header hd;
	uint32_t remain_gpio_irq;
};

struct iodie_evt_sync_info {
	enum iodie_err_event evt;
	enum iodie_abrl_src src;
	enum iodie_err_status err_st;
	struct work_struct worker;
};

struct iodie_info {
	spinlock_t lock;
	bool err_notify_flag;
	enum iodie_sys_status sys_st;
	enum iodie_runtime_status run_st;
	enum iodie_err_status err_st;
	struct iodie_vote low_vote;
	struct iodie_vote high_vote;
	struct iodie_vote pll_vote;
	struct iodie_perf_stat perf;
	iodie_user_func usr_func[IODIE_USER_END];
};

static struct hio_ap_user_time g_hio_ap_user_time = {0};

struct hiphyio_user_time {
    enum iodie_user user_name;
    uint64_t user_start_time;
    uint64_t user_end_time;
    uint64_t user_time;
};

static struct hiphyio_user_time g_hiphyio_user_time[] = {
    {IODIE_USER_AP_BT, 0, 0, 0},
    {IODIE_USER_AP_GNSS, 0, 0, 0},
    {IODIE_USER_AUDIO_UART, 0, 0, 0},
};

void update_user_start_time_data(enum iodie_user user)
{
    for (int i = 0; i < sizeof(g_hiphyio_user_time) / sizeof(g_hiphyio_user_time[0]); i++) {
        if (user == g_hiphyio_user_time[i].user_name) {
            g_hiphyio_user_time[i].user_start_time = get_jiffies_64();
            g_hiphyio_user_time[i].user_end_time = 0;
			return;
        }
    }
}

static void update_user_time_data(int num)
{
	u64 entry_jiffies;
	u64 exit_jiffies;
	u64 diff_usecs;

	g_hiphyio_user_time[num].user_end_time = get_jiffies_64();
	entry_jiffies = g_hiphyio_user_time[num].user_start_time;
	exit_jiffies = g_hiphyio_user_time[num].user_end_time;
	diff_usecs = jiffies64_to_nsecs(exit_jiffies - entry_jiffies) / NS_TO_US;
	g_hiphyio_user_time[num].user_time += (uint64_t)diff_usecs;
}

void update_user_end_time_data(enum iodie_user user)
{
    for (int i = 0; i < sizeof(g_hiphyio_user_time) / sizeof(g_hiphyio_user_time[0]); i++) {
        if (user == g_hiphyio_user_time[i].user_name) {
			update_user_time_data(i);
			return;
        }
    }
}

static void check_user_time(int num)
{
	if (g_hiphyio_user_time[num].user_start_time > g_hiphyio_user_time[num].user_end_time) {
		pr_info("%s: num %u, checkn", __func__, (uint32_t)num);
		update_user_time_data(num);
		g_hiphyio_user_time[num].user_start_time = g_hiphyio_user_time[num].user_end_time;
		g_hiphyio_user_time[num].user_end_time = 0;
	}
}

static void update_user_time(void)
{
    for (int i = 0; i < sizeof(g_hiphyio_user_time) / sizeof(g_hiphyio_user_time[0]); i++) {
		if (g_hiphyio_user_time[i].user_name == IODIE_USER_AP_BT) {
			check_user_time(i);
			g_hio_ap_user_time.bt_uart_time = g_hiphyio_user_time[i].user_time;
			g_hiphyio_user_time[i].user_time = 0;
		} else if (g_hiphyio_user_time[i].user_name == IODIE_USER_AP_GNSS) {
			check_user_time(i);
			g_hio_ap_user_time.gnss_uart_time = g_hiphyio_user_time[i].user_time;
			g_hiphyio_user_time[i].user_time = 0;
		} else if (g_hiphyio_user_time[i].user_name == IODIE_USER_AUDIO_UART) {
			check_user_time(i);
			g_hio_ap_user_time.audio_uart_time = g_hiphyio_user_time[i].user_time;
			g_hiphyio_user_time[i].user_time = 0;
		}
    }
}

struct hio_ap_user_time send_hiphyio_user_data_to_dubai(void)
{
	pr_info("%s: dubai start\n", __func__);
    update_user_time();
	pr_info("bt_uart_time %llu\n", g_hio_ap_user_time.bt_uart_time);
	pr_info("gnss_uart_time %llu\n", g_hio_ap_user_time.gnss_uart_time);
	pr_info("audio_uart_time %llu\n", g_hio_ap_user_time.audio_uart_time);
	return g_hio_ap_user_time;
}

void hiphyio_user_data_reset(void)
{
	g_hio_ap_user_time.bt_uart_time = 0;
	g_hio_ap_user_time.gnss_uart_time = 0;
	g_hio_ap_user_time.audio_uart_time = 0;
}

/* global variable */
static DEFINE_MUTEX(g_iodie_notify_lock);
static DEFINE_MUTEX(g_iodie_status_lock);
static DEFINE_MUTEX(g_iodie_recovery_lock);
static DEFINE_MUTEX(g_iodie_clk_lock);
static struct iodie_perf_stat g_iodie_perf;
static struct iodie_info g_iodie_info = {
	.err_notify_flag = true,
	.sys_st = IODIE_ST_PRE_INITED,
	.run_st = IODIE_RT_SUSPEND,
	.err_st = IODIE_ERR_NO,
	.low_vote = {{0}, 0},
	.high_vote = {{0}, 0},
	.pll_vote = {{0}, 0},
	.perf = {0, 0},
	.usr_func = {NULL},
};

#ifdef CONFIG_DFX_DEBUG_FS
int iodie_reg_op(struct iodie_reg_op *data)
{
	struct iodie_commu_data commu = {0};
	int ret;

	if (data == NULL) {
		pr_err("iodie_reg_op: data is null\n");
		return -EINVAL;
	}

	pr_info("%s: op[%x], slave_id[%x], reg_addr[%x], val[%x]\n", __func__, data->op, data->slave_id,
		data->reg_addr, data->val);

	commu.wr_buf = data;
	commu.wr_len = sizeof(struct iodie_reg_op);
	ret = iodie_drv_commu(IODIE_CMD_REG_OP, &commu);
	if (ret != EOK)
		return ret;

	if(commu.errno) {
		pr_err("%s: response err [%d]\n", __func__, commu.errno);
		return commu.errno;
	}

	if (commu.rd_len == sizeof(u32)) {
		data->val = *(u32 *)commu.rd_buf;
		pr_info("%s: read res 0x%x\n", __func__, data->val);
	}

	return EOK;
}

uint32_t iodie_reg_read(uint32_t reg)
{
	struct iodie_reg_op iodie_reg = {0};

	iodie_reg.op = 1;
	iodie_reg.slave_id = 0;
	iodie_reg.reg_addr = reg;

	iodie_reg_op(&iodie_reg);

	return iodie_reg.val;
}

void iodie_reg_write(uint32_t reg, uint32_t val)
{
	struct iodie_reg_op iodie_reg = {0};

	iodie_reg.op = 0;
	iodie_reg.slave_id = 0;
	iodie_reg.reg_addr = reg;
	iodie_reg.val = val;

	iodie_reg_op(&iodie_reg);
}
#endif

static void iodie_set_err_notify_flag(bool flag)
{
	mutex_lock(&g_iodie_notify_lock);
	g_iodie_info.err_notify_flag = flag;
	mutex_unlock(&g_iodie_notify_lock);
}

static bool iodie_get_err_notify_flag(void)
{
	bool flag;

	mutex_lock(&g_iodie_notify_lock);
	flag = g_iodie_info.err_notify_flag;
	mutex_unlock(&g_iodie_notify_lock);

	return flag;
}

static int iodie_err_event_sync(enum iodie_err_event evt, enum iodie_err_status st, enum iodie_abrl_src src)
{
	struct iodie_commu_data commu;
	struct iodie_error_ext_msg msg;
	enum iodie_sys_status sys_st;
	int ret;

	if ((evt >= IODIE_ERR_EVT_END) || (st >= IODIE_ERR_END) || (src >= IODIE_ARRL_END)) {
		pr_err("%s: invalid para\n", __func__);
		return -EINVAL;
	}

	pr_info("%s: evt %d, status %d, src %d\n", __func__, evt, st, src);

	sys_st = iodie_drv_get_sys_status();
	if ((sys_st == IODIE_ST_PRE_INITED) || (sys_st == IODIE_ST_NONE)) {
		pr_err("%s: iodie not ready, status %u\n", __func__, sys_st);
		return -EINVAL;
	}

	msg.evt = evt;
	msg.info.status = st;
	msg.info.src = src;
	commu.wr_buf = &msg;
	commu.wr_len = sizeof(struct iodie_error_ext_msg);
	ret = iodie_drv_commu(IODIE_CMD_IODIE_ERR, &commu);
	if (ret != EOK) {
		pr_err("%s: commu fail\n", __func__);
		return ret;
	}

	return EOK;
}

static void iodie_event_sync_handler(struct work_struct *work)
{
	struct iodie_evt_sync_info *info = container_of(work, struct iodie_evt_sync_info, worker);

	if (info == NULL)
		return;

	if (iodie_get_err_notify_flag()) {
		if (iodie_err_event_sync(info->evt, info->err_st, info->src) == EOK)
			iodie_set_err_notify_flag(false);
	} else {
		pr_err("%s: ignore err %u src %u\n", __func__, info->err_st, info->src);
	}

	kfree(info);
}

static void iodie_err_event_sync_delay(enum iodie_err_event evt, enum iodie_err_status st, enum iodie_abrl_src src)
{
	struct iodie_evt_sync_info *info = NULL;

	info = kzalloc(sizeof(struct iodie_evt_sync_info), GFP_ATOMIC);
	if (!info) {
		pr_err("[%s] alloc work failed.\n", __func__);
		return;
	}

	info->evt = evt;
	info->src = src;
	info->err_st = st;;
	INIT_WORK(&info->worker, iodie_event_sync_handler);
	queue_work(system_unbound_wq, &info->worker);
}

static int sh_clk_out_cfg(enum iodie_clk_out_op op)
{
	struct iodie_commu_data commu = {0};
	uint32_t data;
	int ret;

	if ((op != IODIE_CLK_OUT_CMD_OPEN) && (op != IODIE_CLK_OUT_CMD_CLOSE)) {
		pr_err("sh_clk_out_cfg: invalid para %u\n", op);
		return -EINVAL;
	}

	data = op;
	commu.wr_buf = (void *)&data;
	commu.wr_len = sizeof(uint32_t);
	ret = iodie_drv_commu(IODIE_CMD_CLK_OUT_CFG, &commu);
	if (ret != EOK)
		return ret;

	if (commu.errno) {
		pr_err("%s: response err [%d]\n", __func__, commu.errno);
		return commu.errno;
	}

	return ret;
}

static bool check_iodie_clk_lock(enum iodie_clk_out_op op)
{
	bool res = false;

	if ((op == IODIE_CLK_OUT_CMD_CLOSE) || (op == IODIE_CLK_CAM_REF_CLOSE))
		res = true;

	return res;
}

int iodie_drv_clk_out_sys(enum iodie_clk_out_op op, unsigned int freq)
{
	int ret;

	if (check_iodie_clk_lock(op))
		mutex_lock(&g_iodie_clk_lock);

	switch (op) {
	case IODIE_CLK_OUT_CMD_OPEN:
	case IODIE_CLK_OUT_CMD_CLOSE:
		ret = sh_clk_out_cfg(op);
		break;
	case IODIE_CLK_CAM_REF_OPEN:
	case IODIE_CLK_CAM_REF_CLOSE:
	case IODIE_CLK_CAM_REF_SEL:
		ret = iodie_dev_clk_cfg(op, freq);
		break;
	default:
		pr_err("%s:invalid para op %u\n", __func__, op);
		ret = -EINVAL;
	}

	if (check_iodie_clk_lock(op))
		mutex_unlock(&g_iodie_clk_lock);

	return ret;
}

static int io_die_ipc(const struct write_info *wr, struct read_info *rd)
{
	int ret;
	uint8_t times = 0;
	u64 entry_jiffies;
	u64 exit_jiffies;
	u64 diff_usecs;

	entry_jiffies = get_jiffies_64();
	ret = write_customize_cmd(wr, rd, true);
	while (ret < 0 && times < IODIE_IPC_RETRY_TIMES) {
		pr_err("%s: send err, times[%hhu] ret[%d]\n", __func__, times, ret);
		exit_jiffies = get_jiffies_64();
		diff_usecs = jiffies64_to_nsecs(exit_jiffies - entry_jiffies) / NS_TO_MS;
		if (diff_usecs > IODIE_IPC_RETRY_THREHOLD) {
			pr_err("%s: timeout, lantency[%llu]ms. \n", __func__, diff_usecs);
			break;
		}
		times++;
		msleep(IODIE_IPC_RETRY_INTERVAL);
		ret = write_customize_cmd(wr, rd, true);
	}

	return ret;
}

static int do_iodie_commu(enum iodie_commu_cmd cmd, struct iodie_commu_data *data)
{
	int ret;
	struct write_info winfo;
	struct read_info rinfo;

	(void)memset_s(&winfo, sizeof(struct write_info), 0, sizeof(struct write_info));
	(void)memset_s(&rinfo, sizeof(struct read_info), 0, sizeof(struct read_info));

	winfo.wr_len = data->wr_len;
	winfo.wr_buf = data->wr_buf;
	winfo.cmd = cmd;
	winfo.tag = TAG_IO_DIE;
	ret = io_die_ipc(&winfo, &rinfo);
	if (ret) {
		pr_err("%s: send err, ret is [%d]\n", __func__, ret);
		return ret;
	}

	data->rd_buf = rinfo.data;
	data->rd_len = rinfo.data_length;
	data->errno = rinfo.errno;

	return EOK;
}

/* send iodie msg to sensorhub, sync interface */
int iodie_drv_commu(enum iodie_commu_cmd cmd, struct iodie_commu_data *data)
{
	int ret;
	u64 entry_jiffies;
	u64 exit_jiffies;
	u64 diff_usecs;

	if (iodie_drv_get_sys_status() == IODIE_ST_NONE) {
		pr_info("%s: no io die. \n", __func__);
		return EOK;
	}

	entry_jiffies = get_jiffies_64();
	ret = do_iodie_commu(cmd, data);
	exit_jiffies = get_jiffies_64();
	diff_usecs = jiffies64_to_nsecs(exit_jiffies - entry_jiffies) / NS_TO_MS;
	if (unlikely(diff_usecs > (u64)atomic64_read(&g_iodie_perf.max_latency))) {
		atomic64_set(&g_iodie_perf.max_latency, (s64)diff_usecs);
		g_iodie_perf.cmd = cmd;
		pr_info("%s:max_latency, cmd[%d], lantency[%llu]ms\n", __func__, cmd, diff_usecs);
	}

	pr_info("%s: send complete, cmd[%d], lantency[%llu]ms.\n", __func__, cmd, diff_usecs);

	return ret;
}

static inline bool iodie_check_local_err(enum iodie_sys_status sys_st, enum iodie_err_status err_st)
{
	return ((sys_st == IODIE_ST_INITED) && ((err_st == IODIE_ERR_I2S) || (err_st == IODIE_ERR_SPI)));
}

static inline bool iodie_check_global_err(enum iodie_sys_status sys_st, enum iodie_err_status err_st)
{
	return ((sys_st == IODIE_ST_ERR) && ((err_st == IODIE_ERR_HIPHY) || (err_st == IODIE_ERR_IODIE)));
}

static inline bool iodie_check_sys_err(enum iodie_sys_status sys_st, enum iodie_err_status err_st)
{
	return ((sys_st == IODIE_ST_ERR) && (err_st == IODIE_ERR_SYS));
}

static void iodie_rdr_record(struct iodie_status_pkt_msg *msg)
{
	enum iodie_sys_status sys_st;
	enum iodie_err_status err_st;

	if (msg == NULL)
		return;

	sys_st = msg->sys_st;
	err_st = msg->err_st;
	if ((iodie_check_local_err(sys_st, err_st) || iodie_check_global_err(sys_st, err_st)) &&
		(msg->err_src != IODIE_ABRL_RETRY)) {
		/* record error msg to RDR and trigger sub system error */
		pr_err("%s: iodie subsys error, trigger subsys rdr\n", __func__);
		rdr_system_error(SENSORHUB_IODIE_MODID, sys_st, err_st);
	}

	if (iodie_check_sys_err(sys_st, err_st)) {
		/* record error msg to RDR and trigger system error */
		pr_err("%s: iodie fatal error, trigger sys rdr\n", __func__);
		rdr_system_error(SENSORHUB_IODIE_SYS_MODID, sys_st, err_st);
	}
}

static void iodie_status_lock_request(void)
{
	static bool inited;

	if (!inited) {
		spin_lock_init(&g_iodie_info.lock);
		pr_info("%s: inited\n", __func__);
		inited = true;
	}
}

/* ensure that parameters are valid before invocation */
static void iodie_set_status(enum iodie_sys_status sys_st, enum iodie_err_status err_st)
{
	unsigned long flags = 0;

	iodie_status_lock_request();
	spin_lock_irqsave(&g_iodie_info.lock, flags);
	if (iodie_check_local_err(sys_st, err_st) || iodie_check_global_err(sys_st, err_st)) {
		iodie_dev_set_hio_availble(false);
		intr_hub_irq_freeze();
	} else {
		iodie_dev_set_hio_availble(true);
		intr_hub_irq_recovery();
	}
	g_iodie_info.sys_st = sys_st;
	g_iodie_info.err_st = err_st;
	spin_unlock_irqrestore(&g_iodie_info.lock, flags);

	return;
}

enum iodie_sys_status iodie_drv_get_sys_status(void)
{
	enum iodie_sys_status st;
	unsigned long flags = 0;

	iodie_status_lock_request();
	spin_lock_irqsave(&g_iodie_info.lock, flags);
	st = g_iodie_info.sys_st;
	spin_unlock_irqrestore(&g_iodie_info.lock, flags);

	return st;
}

enum iodie_err_status iodie_drv_get_err_status(void)
{
	enum iodie_err_status st;
	unsigned long flags = 0;

	iodie_status_lock_request();
	spin_lock_irqsave(&g_iodie_info.lock, flags);
	st = g_iodie_info.err_st;
	spin_unlock_irqrestore(&g_iodie_info.lock, flags);

	return st;
}

static void iodie_vote_info_dump(void)
{
	uint32_t i;

	for (i = 0; i < IODIE_USER_END; i++)
		pr_err("iodie_vote: user %u high_vote %u, low_vote %u, pll_vote %u\n", i,
			g_iodie_info.high_vote.vote_count[i], g_iodie_info.low_vote.vote_count[i],
			g_iodie_info.pll_vote.vote_count[i]);

	pr_err("iodie_vote: total high_vote %u, low_vote %u, pll_vote %u\n",
		g_iodie_info.high_vote.total, g_iodie_info.low_vote.total, g_iodie_info.pll_vote.total);
}

int iodie_drv_normal_request(enum iodie_user user, enum iodie_runtime_status status)
{
	unsigned long flags = 0;
	int ret;

	if (user >= IODIE_USER_END)
		return -EINVAL;

	if (status == IODIE_RT_SUSPEND) {
		pr_info("%s: suspend status no need to vote\n", __func__);
		return EOK;
	}

	iodie_status_lock_request();
	spin_lock_irqsave(&g_iodie_info.lock, flags);
	if ((g_iodie_info.sys_st == IODIE_ST_ERR) || (g_iodie_info.sys_st == IODIE_ST_NONE)) {
		pr_err("%s: status error \n", __func__);
		spin_unlock_irqrestore(&g_iodie_info.lock, flags);
		return -EFAULT;
	}

	if (status == IODIE_RT_NORMAL_HIGH) {
		if (g_iodie_info.high_vote.vote_count[user] == 0xFF) {
			pr_err("%s: user %u upto max vote. \n", __func__, (uint32_t)user);
			spin_unlock_irqrestore(&g_iodie_info.lock, flags);
			return -EFAULT;
		}

		if (g_iodie_info.high_vote.total == 0) {
			ret = iodie_dev_hiphy_vote_kernel(status);
			if (ret != EOK) {
				spin_unlock_irqrestore(&g_iodie_info.lock, flags);
				iodie_err_event_sync_delay(IODIE_ERR_EVT_OCCURED, IODIE_ERR_HIPHY, IODIE_ABRL_HIPHYIO_SPEED);
				return ret;
			}
		}
		g_iodie_info.high_vote.vote_count[user]++;
		g_iodie_info.high_vote.total++;
	}

	if (status == IODIE_RT_NORMAL_LOW) {
		if (g_iodie_info.low_vote.vote_count[user] == 0xFF) {
			spin_unlock_irqrestore(&g_iodie_info.lock, flags);
			pr_err("%s: user %u upto max vote. \n", __func__, (uint32_t)user);
			return -EFAULT;
		}

		if (g_iodie_info.low_vote.total == 0 && g_iodie_info.high_vote.total == 0) {
			ret = iodie_dev_hiphy_vote_kernel(status);
			if (ret != EOK) {
				spin_unlock_irqrestore(&g_iodie_info.lock, flags);
				iodie_err_event_sync_delay(IODIE_ERR_EVT_OCCURED, IODIE_ERR_HIPHY, IODIE_ABRL_PERI);
				return ret;
			}
		}
		g_iodie_info.low_vote.vote_count[user]++;
		g_iodie_info.low_vote.total++;
	}
	spin_unlock_irqrestore(&g_iodie_info.lock, flags);

	update_user_start_time_data(user);

	pr_info("%s: user %u succ, new status %u\n", __func__, (uint32_t)user, iodie_dev_lp_status());

	return EOK;
}

int iodie_drv_normal_release(enum iodie_user user, enum iodie_runtime_status status)
{
	unsigned long flags = 0;

	if (user >= IODIE_USER_END)
		return -EINVAL;

	if (status == IODIE_RT_SUSPEND) {
		pr_info("%s: suspend status no need to vote\n", __func__);
		return EOK;
	}

	iodie_status_lock_request();
	spin_lock_irqsave(&g_iodie_info.lock, flags);
	if (status == IODIE_RT_NORMAL_HIGH) {
		if (g_iodie_info.high_vote.vote_count[user] == 0) {
			pr_err("%s: user %u no high vote. \n", __func__, (uint32_t)user);
			spin_unlock_irqrestore(&g_iodie_info.lock, flags);
			return -EFAULT;
		}
		if ((g_iodie_info.high_vote.total >= 1) && (g_iodie_info.high_vote.vote_count[user] >= 1)) {
			g_iodie_info.high_vote.vote_count[user]--;
			g_iodie_info.high_vote.total--;
		} else {
			iodie_vote_info_dump();
			pr_err("%s: high vote err. \n", __func__);
		}
	}

	if (status == IODIE_RT_NORMAL_LOW) {
		if (g_iodie_info.low_vote.vote_count[user] == 0) {
			pr_err("%s: user %u no low vote. \n", __func__, (uint32_t)user);
			spin_unlock_irqrestore(&g_iodie_info.lock, flags);
			return -EFAULT;
		}
		if ((g_iodie_info.low_vote.total >= 1) && (g_iodie_info.low_vote.vote_count[user] >= 1)) {
			g_iodie_info.low_vote.vote_count[user]--;
			g_iodie_info.low_vote.total--;
		} else {
			iodie_vote_info_dump();
			pr_err("%s: low vote err. \n", __func__);
		}
	}

	// There are only two situations where state transitions occur here, peri power-down and hiphyio 
	// switching to low speed, and any failures will not affect system run
	if (g_iodie_info.high_vote.total > 0) {
		iodie_dev_hiphy_vote_kernel(IODIE_RT_NORMAL_HIGH);
	} else if (g_iodie_info.low_vote.total > 0) {
		iodie_dev_hiphy_vote_kernel(IODIE_RT_NORMAL_LOW);
	} else {
		iodie_dev_hiphy_vote_kernel(IODIE_RT_SUSPEND);
	}

	spin_unlock_irqrestore(&g_iodie_info.lock, flags);

	update_user_end_time_data(user);

	pr_info("%s: user %u succ, new status %u\n", __func__, (uint32_t)user, iodie_dev_lp_status());

	return EOK;
}

int iodie_drv_fnpll_request(enum iodie_user user)
{
	enum iodie_sys_status sys_st;
	int ret;

	if (user >= IODIE_USER_END) {
		pr_err("%s: user %u invalid. \n", __func__, (uint32_t)user);
		return -EINVAL;
	}

	sys_st = iodie_drv_get_sys_status();
	if ((sys_st == IODIE_ST_ERR) || (sys_st == IODIE_ST_NONE)) {
		pr_err("%s: status error. \n", __func__);
		return -EFAULT;
	}

	mutex_lock(&g_iodie_status_lock);
	if (g_iodie_info.pll_vote.vote_count[user] == 0xFF) {
		pr_err("%s: user %u upto max vote. \n", __func__, (uint32_t)user);
		mutex_unlock(&g_iodie_status_lock);
		return -EFAULT;
	}

	if (g_iodie_info.pll_vote.total == 0) {
		ret = iodie_dev_fnpll_enable();
		if (ret != EOK) {
			mutex_unlock(&g_iodie_status_lock);
			pr_err("%s: user %u enable fail. \n", __func__, (uint32_t)user);
			iodie_err_event_sync_delay(IODIE_ERR_EVT_OCCURED, IODIE_ERR_HIPHY, IODIE_ARRL_FNPLL);
			return ret;
		}
	}
	g_iodie_info.pll_vote.vote_count[user]++;
	g_iodie_info.pll_vote.total++;
	mutex_unlock(&g_iodie_status_lock);

	pr_info("%s: user %u succ\n", __func__, (uint32_t)user);

	return EOK;
}

static void iodie_drv_fnpll_recovery(void)
{
	mutex_lock(&g_iodie_status_lock);
	if (g_iodie_info.pll_vote.total == 0)
		iodie_dev_fnpll_disable();
	mutex_unlock(&g_iodie_status_lock);
}

int iodie_drv_fnpll_release(enum iodie_user user)
{
	if (user >= IODIE_USER_END) {
		pr_err("%s: invalid user. \n", __func__);
		return -EINVAL;
	}

	mutex_lock(&g_iodie_status_lock);
	if (g_iodie_info.pll_vote.vote_count[user] == 0) {
		pr_err("%s: user %u no vote. \n", __func__, (uint32_t)user);
		mutex_unlock(&g_iodie_status_lock);
		return -EFAULT;
	}

	if ((g_iodie_info.pll_vote.total >= 1) && (g_iodie_info.pll_vote.vote_count[user] >= 1)) {
		g_iodie_info.pll_vote.vote_count[user]--;
		g_iodie_info.pll_vote.total--;
	} else {
		pr_err("%s: err vote. \n", __func__);
		iodie_vote_info_dump();
		mutex_unlock(&g_iodie_status_lock);
		return -EFAULT;
	}

	if ((g_iodie_info.pll_vote.total == 0) && (g_iodie_info.pll_vote.vote_count[user] == 0))
		iodie_dev_fnpll_disable();

	mutex_unlock(&g_iodie_status_lock);

	pr_info("%s: user %u succ\n", __func__, (uint32_t)user);

	return EOK;
}

int iodie_drv_notify_register(enum iodie_user user, iodie_user_func func)
{
	if (user >= IODIE_USER_END || func == NULL) {
		pr_err("%s: user %u, para invalid\n", __func__, user);
		return -EINVAL;
	}

	mutex_lock(&g_iodie_notify_lock);
	if (g_iodie_info.usr_func[user] != NULL)
		pr_err("%s: user %u, register again!\n", __func__, user);

	g_iodie_info.usr_func[user] = func;
	mutex_unlock(&g_iodie_notify_lock);

	pr_info("%s: user %u success\n", __func__, user);

	return EOK;
}

static void iodie_status_notify_user(struct iodie_status_pkt_msg *msg)
{
	int i;

	if (msg == NULL)
		return;

	mutex_lock(&g_iodie_notify_lock);
	for (i = 0; i < IODIE_USER_END; i++)
		if (g_iodie_info.usr_func[i] != NULL) {
			pr_info("%s: user %d ++\n", __func__, i);
			g_iodie_info.usr_func[i](msg->sys_st, msg->err_st);
			pr_info("%s: user %d --\n", __func__, i);
		}
	mutex_unlock(&g_iodie_notify_lock);

	if (iodie_check_local_err(msg->sys_st, msg->err_st) || iodie_check_global_err(msg->sys_st, msg->err_st))
		iodie_err_event_sync(IODIE_ERR_EVT_ACCESS_STOPPED, 0, 0);
}

static void iodie_status_recovery(struct iodie_status_pkt_msg *msg)
{
	if ((msg->sys_st == IODIE_ST_INITED) && (msg->err_st == IODIE_ERR_NO)) {
		iodie_drv_fnpll_recovery();
		iodie_set_err_notify_flag(true);
	}
}

static void iodie_dmd_record(struct iodie_status_pkt_msg *msg)
{
	enum iodie_sys_status sys_st;
	enum iodie_err_status err_st;

	if (msg == NULL)
		return;

	sys_st = msg->sys_st;
	err_st = msg->err_st;
	if (iodie_check_local_err(sys_st, err_st) || iodie_check_global_err(sys_st, err_st) ||
		iodie_check_sys_err(sys_st, err_st)) {
		pr_err("[%s] err_st %u src %u, info 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n", __func__,
			err_st, msg->err_src, msg->data[0], msg->data[1], msg->data[2], msg->data[3], msg->data[4],
			msg->data[5], msg->data[6], msg->data[7], msg->data[8], msg->data[9]);
		(void)bbox_diaginfo_record(IODIE_DMD_HW_FAULT, NULL,
			"err_st %u src %u, info 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x",
			err_st, msg->err_src, msg->data[0], msg->data[1], msg->data[2], msg->data[3], msg->data[4],
			msg->data[5], msg->data[6], msg->data[7], msg->data[8], msg->data[9]);
	}
}

static int iodie_status_notify_handler(const struct pkt_header *pkt)
{
	struct iodie_status_pkt_msg *msg = (struct iodie_status_pkt_msg *)pkt;

	if (pkt == NULL) {
		pr_err("%s: pkt is null\n", __func__);
		return -EINVAL;
	}

	pr_info("%s: recv tag:%x, cmd:%x, len:%x\n", __func__, pkt->tag, pkt->cmd, pkt->length);

	if (pkt->tag != TAG_IO_DIE || pkt->length < IODIE_STATUS_PKT_LEN) {
		pr_err("%s: pkt err\n", __func__);
		return -EINVAL;
	}

	if (msg->sys_st >= IODIE_ST_END || msg->err_st >= IODIE_ERR_END) {
		pr_err("%s: status invalid\n", __func__);
		return -EINVAL;
	}

	mutex_lock(&g_iodie_recovery_lock);
	pr_info("%s: iodie sys status %u, err status %u\n", __func__, msg->sys_st, msg->err_st);

	iodie_set_status(msg->sys_st, msg->err_st);
	iodie_status_recovery(msg);
	iodie_status_notify_user(msg);
	iodie_rdr_record(msg);
	iodie_dmd_record(msg);
	mutex_unlock(&g_iodie_recovery_lock);

	return EOK;
}

static void iodie_axi_record_notify(struct iodie_axi_record_pkt_msg *msg)
{
	int i;

	if (msg == NULL)
		return;

	mutex_lock(&g_iodie_notify_lock);
	for (i = 0; i < IODIE_USER_END; i++) {
		if (!check_axi_record_bit(msg->user, i))
			continue;

		if (g_iodie_info.usr_func[i] != NULL) {
			pr_info("%s: user %d ++\n", __func__, i);
			g_iodie_info.usr_func[i](IODIE_ST_ERR, IODIE_ERR_IODIE);
			pr_info("%s: user %d --\n", __func__, i);
		}
	}
	mutex_unlock(&g_iodie_notify_lock);
}

static void iodie_axi_record_dump(struct iodie_axi_record_pkt_msg *msg)
{
	uint32_t i;

	if (msg == NULL)
		return;

	for (i = 0; i < HIPHYIO_AXI_GROUP_NUM; i++)
		pr_info("%s: id %u axi_record 0x%x\n", __func__, i, msg->user[i]);
}

static void iodie_recovery_pre(void)
{
	(void)iodie_dev_hiphy_vote_boot(IODIE_RT_NORMAL_LOW);
	pr_info("%s: iodie sys_st %u rt_st %u\n", __func__, iodie_drv_get_sys_status(),
		iodie_dev_lp_status());
}

static void iodie_recovery_post(void)
{
	pr_info("%s: iodie sys_st %u rt_st %u\n", __func__, iodie_drv_get_sys_status(),
		iodie_dev_lp_status());
}

static int iodie_recovery_notifier(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	pr_info("%s %lu +\n", __func__, foo);
	switch (foo) {
	case IOM3_RECOVERY_IDLE:
		break;
	case IOM3_RECOVERY_START:
		iodie_recovery_pre();
		break;
	case IOM3_RECOVERY_MINISYS:
	case IOM3_RECOVERY_3RD_DOING:
	case IOM3_RECOVERY_FAILED:
		break;
	case IOM3_RECOVERY_DOING:
		iodie_recovery_post();
		break;
	default:
		pr_err("%s -unknow state %lu\n", __func__, foo);
		break;
	}
	pr_info("%s -\n", __func__);
	return 0;
}

static struct notifier_block iodie_recovery_notify = {
	.notifier_call = iodie_recovery_notifier,
	.priority = -1,
};

static int iodie_axi_record_notify_handler(const struct pkt_header *pkt)
{
	struct iodie_axi_record_pkt_msg *msg = (struct iodie_axi_record_pkt_msg *)pkt;

	if (pkt == NULL) {
		pr_err("%s: pkt is null\n", __func__);
		return -EINVAL;
	}

	pr_info("%s: recv tag:%x, cmd:%x, len:%x\n", __func__, pkt->tag, pkt->cmd, pkt->length);

	if ((pkt->tag != TAG_IO_DIE) || (pkt->length != (sizeof(uint32_t) * HIPHYIO_AXI_GROUP_NUM))) {
		pr_err("%s: pkt err\n", __func__);
		return -EINVAL;
	}

	iodie_axi_record_dump(msg);
	iodie_axi_record_notify(msg);

	return EOK;
}

static int iodie_weakup_irq_handler(const struct pkt_header *pkt)
{
	struct iodie_gpio_wakeup_pkt_msg *msg = (struct iodie_gpio_wakeup_pkt_msg *)pkt;

	if (pkt == NULL) {
		pr_err("%s: pkt is null\n", __func__);
		return -EINVAL;
	}

	if (pkt->tag == TAG_IO_DIE && (pkt->cmd < IODIE_CMD_GPIO_WAKEUP_START || pkt->cmd > IODIE_CMD_GPIO_WAKEUP_END))
		return EOK;

	pr_info("%s: recv tag:%x, cmd:%x, len:%x\n", __func__, pkt->tag, pkt->cmd, pkt->length);

	if (pkt->tag != TAG_IO_DIE || pkt->length != (sizeof(uint32_t))) {
		pr_err("%s: pkt err\n", __func__);
		return -EINVAL;
	}

	pr_info("%s: gpio wakeup source %u, remain irq info %x\n", __func__, pkt->cmd - IODIE_CMD_GPIO_WAKEUP_START,
			 msg->remain_gpio_irq);

	return EOK;
}

static int __init iodie_drv_init(void)
{
	int ret;

	ret = register_mcu_event_notifier(TAG_IO_DIE, IODIE_CMD_STATUS_NOTIFY, iodie_status_notify_handler);
	if (ret != 0) {
		pr_err( "register iodie status event failed =%d\n", ret);
		return ret;
	}

	ret = register_mcu_event_notifier(TAG_IO_DIE, IODIE_CMD_AXI_RECORD, iodie_axi_record_notify_handler);
	if (ret != 0) {
		pr_err( "register iodie axi record event failed =%d\n", ret);
		return ret;
	}

	ret = register_mcu_event_notifier(TAG_IO_DIE, CMD_ALL, iodie_weakup_irq_handler);
	if (ret != 0) {
		pr_err( "register iodie weakup irq event failed =%d\n", ret);
		return ret;
	}

	register_iom3_recovery_notifier(REC_USR_IODIE, &iodie_recovery_notify);
	pr_info("%s ok\n", __func__);

	return EOK;
}

static void __exit iodie_drv_exit(void)
{
	unregister_mcu_event_notifier(TAG_IO_DIE, IODIE_CMD_STATUS_NOTIFY, iodie_status_notify_handler);
	unregister_mcu_event_notifier(TAG_IO_DIE, IODIE_CMD_AXI_RECORD, iodie_axi_record_notify_handler);
	unregister_mcu_event_notifier(TAG_IO_DIE, CMD_ALL, iodie_weakup_irq_handler);
	pr_info("exit %s\n", __func__);
}

late_initcall_sync(iodie_drv_init);
module_exit(iodie_drv_exit);