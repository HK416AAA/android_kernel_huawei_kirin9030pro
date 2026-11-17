
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/err.h>
#include <securec.h>
#include <hisp_internel.h>
#include "hisp_device_manager.h"
#include "hisp_clock_manager.h"
#include "hisp_memory_manager.h"
#include "hisp_rpmsg.h"
#include "hisp_hw_lock.h"
#if defined(ISP_LINX_CPU_SUPPORT)
#include "isp_clock_rate.h"
#endif

enum isp_power_state {
	ISP_POWER_DOWN = 0,
	ISP_POWER_UP,
	ISP_POWER_STATE_MAX
};

struct hisp_device_manager {
	int initialized;
	enum hisp_rproc_case_attr case_type;
	struct mutex ispdev_mutex;
	enum isp_power_state power_state[MAX_OP];
	unsigned int clk_vote_value[MAX_OP][ISP_CLK_MAX];
};

struct hisp_device_manager hisp_dev_manager = {0};

bool hisp_check_isp_power_sate(unsigned int master)
{
	struct hisp_device_manager *hisp_dev = &hisp_dev_manager;

	if (master >= MAX_OP) {
		return false;
	}

	return hisp_dev->power_state[master] == ISP_POWER_UP;
}

static int hisp_device_enable_check(enum hisp_op_master_e master, enum hisp_rproc_case_attr boot_type)
{
	if (((master != CAMERA_OP) && (master != CANN_OP)) ||
		((boot_type != SEC_CASE) && (boot_type != NONSEC_CASE)) ||
		((master == CANN_OP) && (boot_type == SEC_CASE))) {
		pr_err("input error:master %d boot_type %d\n", master, boot_type);
		return -EINVAL;
	}

	return 0;
}

static int hisp_device_sec_conflict_pre_process(void)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;

	if (hisp_dev_rproc_disable()) {
		pr_err("hisp power down failed\n");
		return -EINVAL;
	}

#ifdef ISP_BUF_PRIVATIZE
#if defined(ISP_LINX_CPU_SUPPORT)
	hisp_mem_list_clean(CANN_OP);
#else
	hisp_mem_list_clean();
#endif
#else
	hisp_dynamic_mem_pool_clean();
#endif
	dev_manager->power_state[CANN_OP] = ISP_POWER_DOWN;

	return 0;
}

static int hisp_check_and_set_share_power_state(enum hisp_op_master_e master)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	enum hisp_op_master_e another_master = CAMERA_OP;
	bool need_do_power_down = false;
	int ret = 0;

	if (master == CAMERA_OP) {
		another_master = CANN_OP;
	} else if (master == CANN_OP) {
		another_master = CAMERA_OP;
	} else {
		return -1;
	}

	ret = hisp_hw_lock_get();
	if (ret != 0) {
		pr_err("[%s] get hw lock failed\n", __func__);
		return ret;
	}

	pr_info("master %d pu %d pd %d another_master %d pu %d pd %d\n",
		master, hisp_share_get_power_up_master(master),
		hisp_share_check_power_down_master(master),
		another_master, hisp_share_get_power_up_master(another_master),
		hisp_share_check_power_down_master(another_master));

	if ((dev_manager->power_state[another_master] == ISP_POWER_UP) &&
		hisp_share_check_power_down_master(another_master)) {
		need_do_power_down = true;
	}

	hisp_share_set_power_up_master(master, ISP_POWER_UP);

	hisp_hw_lock_put();

	if (need_do_power_down) {
		hisp_rpmsg_register_callback(another_master, NULL);
		ret = hisp_dev_rproc_disable();
		if (ret != 0) {
			pr_err("isp power down failed\n");
		}
#if defined(ISP_LINX_CPU_SUPPORT)
		hisp_mem_list_clean(another_master);
#endif
		dev_manager->power_state[another_master] = ISP_POWER_DOWN;
		hisp_share_clear_power_state();
	}

	return 0;
}

int hisp_device_rproc_enable(enum hisp_op_master_e master, enum hisp_rproc_case_attr boot_type)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	int ret = 0;

	pr_info("[%s]+\n", __func__);
	pr_info("master %d boot_type %d\n", master, boot_type);

	if (hisp_device_enable_check(master, boot_type)) {
		pr_err("input error:master %d boot_type %d\n", master, boot_type);
		return -EINVAL;
	}

	mutex_lock(&dev_manager->ispdev_mutex);

	if (hisp_check_isp_power_sate(master)) {
		pr_err("isp is already running, master %d boot_type %d\n", master, boot_type);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return -EINVAL;
	}

	if ((dev_manager->power_state[CAMERA_OP] == ISP_POWER_UP) &&
		(dev_manager->case_type == SEC_CASE)) {
		pr_err("isp sec is running, master %d boot_type %d\n", master, boot_type);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return ISP_DEV_SEC_POWER_CONFLICT;
	}

	if ((master == CAMERA_OP) && (boot_type == SEC_CASE) &&
		(dev_manager->power_state[CANN_OP] == ISP_POWER_UP)) {
		pr_info("isp is running while camera sec power on\n");
		if (hisp_device_sec_conflict_pre_process()) {
			pr_err("hisp_device_sec_conflict_process failed\n");
			mutex_unlock(&dev_manager->ispdev_mutex);
			return -EINVAL;
		}
	}

	ret = hisp_check_and_set_share_power_state(master);
	if (ret != 0) {
		pr_err("check and set share power state failed\n");
		mutex_unlock(&dev_manager->ispdev_mutex);
		return ret;
	}

#if defined(ISP_LINX_CPU_SUPPORT)
	hisp_mem_clean_status(master);
#endif

	dev_manager->power_state[master] = ISP_POWER_UP;
	hisp_rpmsg_handshake_init();

	if ((boot_type == NONSEC_CASE) &&
		(master == CAMERA_OP) && (dev_manager->power_state[CANN_OP] == ISP_POWER_UP)) {
		pr_info("isp power concurrent, in master %d power state %d %d\n",
			master, dev_manager->power_state[CAMERA_OP], dev_manager->power_state[CANN_OP]);
		ret = hisp_rpmsg_device_switch2camera();
		if (ret != 0) {
			pr_err("hisp_rpmsg_device_switch2camera failed, master %d boot_type %d\n", master, boot_type);
			goto enable_err;
		}
		goto power_end;
	}

	if ((boot_type == NONSEC_CASE) &&
		(master == CANN_OP) && (dev_manager->power_state[CAMERA_OP] == ISP_POWER_UP)) {
		pr_info("isp power concurrent, in master %d power state %d %d\n",
			master, dev_manager->power_state[CAMERA_OP], dev_manager->power_state[CANN_OP]);
		goto power_end;
	}

	ret = hisp_dev_rproc_enable(boot_type);
	if (ret != 0) {
		pr_err("rpoc enable failed, master %d boot_type %d\n", master, boot_type);
		goto enable_err;
	}

	ret = hisp_rpmsg_wait_handshake();
	if (ret != 0) {
		pr_err("[%s]Failed:hisp_rpmsg_wait_handshake\n", __func__);
		goto enable_err;
	}

	dev_manager->case_type = boot_type;
	hisp_share_set_power_up_master(master, ISP_POWER_UP);

power_end:
	if (master == CAMERA_OP) {
		hisp_dev_update_camera_ffrt_uid(false);
	}
	hisp_share_init_power_down_state(master);
	mutex_unlock(&dev_manager->ispdev_mutex);

	pr_info("[%s]-\n", __func__);
	return 0;

enable_err:
	dev_manager->power_state[master] = ISP_POWER_DOWN;
	hisp_share_set_power_up_master(master, ISP_POWER_DOWN);
#if defined(ISP_LINX_CPU_SUPPORT)
	hisp_mem_list_clean(CANN_OP);
	hisp_mem_list_clean(CAMERA_OP);
#endif
	(void)hisp_dev_rproc_disable();
	mutex_unlock(&dev_manager->ispdev_mutex);

	return ret;
}

int hisp_device_rproc_disable(enum hisp_op_master_e master)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	int ret = 0;

	pr_info("[%s]+\n", __func__);

	if ((master != CAMERA_OP) && (master != CANN_OP)) {
		pr_err("input error:master %d\n", master);
		return -EINVAL;
	}

	mutex_lock(&dev_manager->ispdev_mutex);

	if (!hisp_check_isp_power_sate(master)) {
		pr_err("master %d has not enable isp\n", master);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return 0;
	}

	if (!hisp_share_check_power_down_master(master)) {
		pr_err("[%s] master %d is not power down in isp_fw, kernel force power down\n", __func__, master);
	} else if (((master == CAMERA_OP) && (dev_manager->power_state[CANN_OP] == ISP_POWER_UP)) ||
		((master == CANN_OP) && (dev_manager->power_state[CAMERA_OP] == ISP_POWER_UP))) {
		if (master == CAMERA_OP) {
			ret = hisp_rpmsg_device_switch2cann();
			if (ret != 0) {
				pr_err("hisp_rpmsg_device_switch2cann failed\n");
			}
		}
		pr_info("[%s] master %d request isp power down while other master request power up\n", __func__, master);
		goto power_down_end;
	}

	dev_manager->power_state[CAMERA_OP] = ISP_POWER_DOWN;
	dev_manager->power_state[CANN_OP] = ISP_POWER_DOWN;

	ret = hisp_dev_rproc_disable();
	if (ret != 0) {
		pr_err("isp power down failed\n");
	}

	hisp_share_clear_power_state();

#if defined(ISP_LINX_CPU_SUPPORT)
	hisp_mem_list_clean(CANN_OP);
	hisp_mem_list_clean(CAMERA_OP);
#endif

power_down_end:
#ifdef ISP_BUF_PRIVATIZE
#if defined(ISP_LINX_CPU_SUPPORT)
	hisp_mem_list_clean(master);
#else
	hisp_mem_list_clean();
#endif
#else
	hisp_dynamic_mem_pool_clean();
#endif

	hisp_rpmsg_register_callback(master, NULL);
	dev_manager->power_state[master] = ISP_POWER_DOWN;
	hisp_share_set_power_up_master(master, ISP_POWER_DOWN);
	mutex_unlock(&dev_manager->ispdev_mutex);

	pr_info("[%s]-\n", __func__);
	return ret;
}

int hisp_device_clk_level2rate(unsigned int type, unsigned int clk_level, unsigned int *rate)
{
#if defined(ISP_LINX_CPU_SUPPORT)
	if (rate == NULL) {
		pr_err("[%s]rate is NULL\n", __func__);
		return -1;
	}

	switch (type) {
		case ISP_CPU_CLK:
			if (clk_level >= ARRAY_SIZE(isp_cpu_clks)) {
				pr_err("[%s]clk_level %u error type %u\n", __func__, clk_level, type);
				return -1;
			}
			*rate = isp_cpu_clks[clk_level];
			break;
		case ISP_FUNC_CLK:
			if (clk_level >= ARRAY_SIZE(isp_func_clks)) {
				pr_err("[%s]clk_level %u error type %u\n", __func__, clk_level, type);
				return -1;
			}
			*rate = isp_func_clks[clk_level];
			break;
		case ISP_FUNC2_CLK:
			if (clk_level >= ARRAY_SIZE(isp_func2_clks)) {
				pr_err("[%s]clk_level %u error type %u\n", __func__, clk_level, type);
				return -1;
			}
			*rate = isp_func2_clks[clk_level];
			break;
		case ISP_FUNC3_CLK:
			if (clk_level >= ARRAY_SIZE(isp_func3_clks)) {
				pr_err("[%s]clk_level %u error type %u\n", __func__, clk_level, type);
				return -1;
			}
			*rate = isp_func3_clks[clk_level];
			break;
		default:
			pr_err("[%s]type %u error\n", __func__, type);
			return -1;
	}

	return 0;
#else
	(void)type;
	(void)clk_level;
	(void)rate;
	return -1;
#endif
}

int hisp_device_set_clk_rate(enum hisp_op_master_e master, unsigned int type, unsigned int rate)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	unsigned int set_rate = rate;
	int ret = 0;

	pr_info("[%s]+\n", __func__);

	mutex_lock(&dev_manager->ispdev_mutex);

	if (!hisp_check_isp_power_sate(master)) {
		pr_err("master %d has not enable isp\n", master);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return -EINVAL;
	}

	if (master == CAMERA_OP) {
		if (hisp_check_isp_power_sate(CANN_OP) && (dev_manager->clk_vote_value[CANN_OP][type] > rate)) {
			set_rate = dev_manager->clk_vote_value[CANN_OP][type];
		}
	} else {
		if (hisp_check_isp_power_sate(CAMERA_OP) && (dev_manager->clk_vote_value[CAMERA_OP][type] > rate)) {
			set_rate = dev_manager->clk_vote_value[CAMERA_OP][type];
		}
	}

	ret = hisp_clock_set_rate(type, set_rate);
	if (ret != 0) {
		pr_err("master %d type %u rate %u set clk failed\n", master, type, rate);
		goto clk_vote_err;
	}

	dev_manager->clk_vote_value[master][type] = rate;
clk_vote_err:
	mutex_unlock(&dev_manager->ispdev_mutex);

	pr_info("[%s]-\n", __func__);
	return ret;
}

#ifdef ISP_LINX_CPU_SUPPORT
int hisp_device_mem_map_addr
(
	enum hisp_op_master_e master,
	struct hisp_mem_type type,
	struct hisp_map_info_s *info,
	struct hisp_mem_info_s *mem
)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	int ret = 0;

	pr_info("[%s]+\n", __func__);

	mutex_lock(&dev_manager->ispdev_mutex);

	if (!hisp_check_isp_power_sate(master)) {
		pr_err("master %d has not enable isp\n", master);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return -EINVAL;
	}

	ret = hisp_driver_mem_map_addr(master, type, info, mem);
	if (ret != 0) {
		pr_err("master %d dst master 0x%x  type 0x%x mem map failed\n", master, type.master, type.mem_type);
	}

	mutex_unlock(&dev_manager->ispdev_mutex);

	pr_info("[%s]-\n", __func__);
	return ret;
}

int hisp_device_mem_unmap_addr
(
	enum hisp_op_master_e master,
	struct hisp_mem_type type,
	struct hisp_mem_info_s mem_info
)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	int ret = 0;

	pr_info("[%s]+\n", __func__);

	mutex_lock(&dev_manager->ispdev_mutex);

	if (!hisp_check_isp_power_sate(master)) {
		pr_err("master %d has not enable isp\n", master);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return -EINVAL;
	}

	ret = hisp_driver_mem_unmap_addr(master, type, mem_info);
	if (ret != 0) {
		pr_err("master %d dst master 0x%x  type 0x%x unmem map failed\n", master, type.master, type.mem_type);
	}

	mutex_unlock(&dev_manager->ispdev_mutex);

	pr_info("[%s]-\n", __func__);
	return ret;
}
#endif

int hisp_device_register_rpmsg_cb(enum hisp_op_master_e master, hisp_rpmsg_cb rpmsg_cb)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;

	mutex_lock(&dev_manager->ispdev_mutex);
	hisp_rpmsg_register_callback(master, rpmsg_cb);
	mutex_unlock(&dev_manager->ispdev_mutex);

	return 0;
}

int hisp_device_unregister_rpmsg_cb(enum hisp_op_master_e master)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;

	mutex_lock(&dev_manager->ispdev_mutex);
	hisp_rpmsg_register_callback(master, NULL);
	mutex_unlock(&dev_manager->ispdev_mutex);

	return 0;
}

int hisp_device_rpmsg_send(enum hisp_op_master_e master, void *data, int len)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	int ret = 0;

	mutex_lock(&dev_manager->ispdev_mutex);

	if (!hisp_check_isp_power_sate(master)) {
		pr_err("master %d has not enable isp\n", master);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return -EINVAL;
	}

	ret = hisp_rpmsg_send(master, data, len);
	mutex_unlock(&dev_manager->ispdev_mutex);

	return ret;
}

void hisp_device_update_ffrt_uid(enum hisp_op_master_e master, bool force)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;

	mutex_lock(&dev_manager->ispdev_mutex);

	if (!hisp_check_isp_power_sate(master)) {
		pr_err("master %d has not enable isp\n", master);
		mutex_unlock(&dev_manager->ispdev_mutex);
		return;
	}

	if (master == CAMERA_OP) {
		hisp_dev_update_camera_ffrt_uid(force);
	}

	mutex_unlock(&dev_manager->ispdev_mutex);
}

static __init int hisp_device_manager_init(void)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	unsigned int i = 0;
	int ret = 0;

	dev_manager->initialized = 0;
	dev_manager->case_type = NONSEC_CASE;
	mutex_init(&dev_manager->ispdev_mutex);

	ret = memset_s(dev_manager->clk_vote_value, sizeof(dev_manager->clk_vote_value),
		0, sizeof(dev_manager->clk_vote_value));
	if (ret != 0) {
		pr_err("[%s] memset_s err %d\n", __func__, ret);
		return -1;
	}

	for (i = 0; i < MAX_OP; i++) {
		dev_manager->power_state[i] = ISP_POWER_DOWN;
	}
	dev_manager->initialized = 1;

	return 0;
}

static void __exit hisp_device_manager_exit(void)
{
	struct hisp_device_manager *dev_manager = &hisp_dev_manager;
	unsigned int i = 0;

	dev_manager->initialized = 0;
	mutex_destroy(&dev_manager->ispdev_mutex);
	for (i = 0; i < MAX_OP; i++) {
		dev_manager->power_state[i] = ISP_POWER_DOWN;
	}
}

module_init(hisp_device_manager_init);
module_exit(hisp_device_manager_exit);
MODULE_LICENSE("GPL v2");

