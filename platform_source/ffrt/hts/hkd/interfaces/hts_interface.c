#include "hts_interface.h"
#include <linux/mutex.h>
#include "linux/types.h"
#include "hts_common_resource.h"
#include "hts_kernel_log.h"
#include "hts_resmem.h"
#include "hpd_interface.h"
#include "hts_common.h"
#include "uniform_id.h"
#include "hts_graph_manager.h"
#include "hts_graph_resource.h"
#include "hts_profiling.h"

int hts_block_dev(uint32_t dev_id)
{
	int ret;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");

	cond_return_error(hpd->hts_except_block_by_ip == NULL, -EINVAL, "hts except dev is invalid\n");
	hts_drv_warn("hts_block_dev soc_ip:%u\n", dev_id);
	ret = hpd->hts_except_block_by_ip((soc_ip)dev_id);
	return ret;
}
EXPORT_SYMBOL(hts_block_dev);

int hts_block_event(uint16_t event)
{
	int ret;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");

	cond_return_error( hpd->hts_except_block_by_event == NULL, -EINVAL, "hts except event is invalid\n");
	hts_drv_warn("hts_block_event event:%u\n", event);
	ret = hpd->hts_except_block_by_event(event);
	return ret;
}

int ffts_outbuff_block_event(uint16_t event)
{
	int ret;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");

	cond_return_error( hpd->hts_ffts_outbuff_except_block_by_event == NULL, -EINVAL, "hts except event is invalid\n");
	hts_drv_warn("hts_block_event event:%u\n", event);
	ret = hpd->hts_ffts_outbuff_except_block_by_event(event);
	return ret;
}

int hts_block_proc(struct dev_pid_info info)
{
	int ret;
	uint16_t uid;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");

	uid = ffrt_get_uniform_id_with_reserve(info.pid);
	if (uid == FFRT_INVALID_UNIFORM_ID) {
		hts_drv_err("ffrt get uid error uid = %u.r\n", uid);
		return -EINVAL;
	}
	cond_return_error(hpd->hts_except_block_by_proc == NULL, -EINVAL, "hts except block by proc is invalid\n");
	hts_drv_warn("hts_block_proc pid:%d, soc_ip:%u\n", info.pid, info.dev_id);
	ret = hpd->hts_except_block_by_proc((soc_ip)info.dev_id, uid);
	return ret;
}
EXPORT_SYMBOL(hts_block_proc);

#ifdef HTS_DEBUG_EN
int ip_get_hts_uid_event_test(uint8_t dev_id, int32_t pid)
{
	struct dev_event_info info = {0};
	uint16_t i;
	int ret = -1;

	info.dev_id = dev_id;
	info.uid = ffrt_get_uniform_id_with_reserve(pid);
	ret = ip_get_hts_uid_event(&info);
	for(i = 0; i < info.event_count; i++) {
		hts_drv_err("eventid=%hu\n", info.events[i]);
	}
	return ret;
}
EXPORT_SYMBOL(ip_get_hts_uid_event_test);

int hts_event_outbuff_enable_test(uint16_t start_event_id, uint16_t end_event_id)
{
	uint16_t event_id[100] = {0};
	uint16_t i = 0;
	uint16_t num = 0;
	int ret = -1;

	for(i = start_event_id; i <= end_event_id; i++) {
		event_id[num++] = i;
		hts_drv_err("eventid=%hu\n", i);
	}
	ret = hts_event_outbuff_enable(event_id, num);
	return ret;
}
EXPORT_SYMBOL(hts_event_outbuff_enable_test);

int hts_event_outbuff_disable_test(uint16_t start_event_id, uint16_t end_event_id)
{
	uint16_t event_id[100] = {0};
	uint16_t num = 0;
	uint16_t i;
	int ret = -1;

	for(i = start_event_id; i <= end_event_id; i++) {
		event_id[num++] = i;
		hts_drv_err("eventid=%hu\n", i);
	}
	ret = hts_event_outbuff_disable(event_id, num);
	return ret;
}
EXPORT_SYMBOL(hts_event_outbuff_disable_test);
#endif

int ip_get_hts_uid_event(struct dev_event_info *info)
{
	int ret;
	struct hpd_registry *hpd = NULL;

	cond_return_error(info == NULL, -1, "dev_event_info is NULL\n");
	hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_get_ip_event_by_uid == NULL, -1, "hts get ip event is invalid\n");
	ret = hpd->hts_get_ip_event_by_uid(info->uid, info->dev_id, info->events,
		HTS_INTERFACE_MAX_EVENT_BUFF, &info->event_count);
	return ret;
}
EXPORT_SYMBOL(ip_get_hts_uid_event);

int hts_event_outbuff_enable(uint16_t *event_id, uint16_t event_num)
{
	uint16_t i;
	struct hts_dev_ctx *dev_ctx = NULL;
	struct hpd_registry *hpd = NULL;

	hts_drv_info("hts_event_outbuff_enable start\n");
	cond_return_error(event_id == NULL, -EINVAL, " event_id is null\n");
	cond_return_error(event_num > HTS_INTERFACE_MAX_EVENT_BUFF || event_num == 0, -EINVAL, " event_num over\n");
	dev_ctx = hts_get_dev_ctx();
	hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_store_event == NULL, -EINVAL, "hts_store_event invalid\n");
	mutex_lock(&dev_ctx->mtx);
	for (i = 0; i < event_num; i++) {
		(void)hpd->hts_store_event(event_id[i]);
		hts_drv_warn("store event_id:%u \n", event_id[i]);
	}
	mutex_unlock(&dev_ctx->mtx);
	hts_drv_info("hts_event_outbuff_enable end\n");
	return 0;
}
EXPORT_SYMBOL(hts_event_outbuff_enable);

int hts_event_outbuff_disable(uint16_t *event_id, uint16_t event_num)
{
	uint16_t i;
	struct hpd_registry *hpd = NULL;
	struct hts_dev_ctx *dev_ctx = NULL;

	hts_drv_info("hts_event_outbuff_disable start\n");
	cond_return_error(event_id == NULL, -EINVAL, " event_id is null\n");
	cond_return_error(event_num > HTS_INTERFACE_MAX_EVENT_BUFF || event_num == 0, -EINVAL, " event_num over\n");
	dev_ctx = hts_get_dev_ctx();
	hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_unstore_event == NULL, -EINVAL, "hts_unstore_event invalid\n");
	mutex_lock(&dev_ctx->mtx);
	for (i = 0; i < event_num; i++) {
		(void)hpd->hts_unstore_event(event_id[i]);
		hts_drv_warn("unstore event_id:%u \n", event_id[i]);
	}
	mutex_unlock(&dev_ctx->mtx);
	hts_drv_info("hts_event_outbuff_disable end\n");
	return 0;
}
EXPORT_SYMBOL(hts_event_outbuff_disable);

int hts_event_outbuff_enable_by_dev(uint32_t dev_id)
{
	uint32_t i;
	hts_check_table table = {0};
	struct hpd_registry *hpd = NULL;
	struct hts_dev_ctx *dev_ctx = NULL;

	hts_drv_info("hts_event_outbuff_enable_by_dev start\n");
	cond_return_error(dev_id == SOC_HTS || dev_id >= SOC_IPMAX, -EINVAL, " dev_id is invalid \n");
	dev_ctx = hts_get_dev_ctx();
	hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_store_event == NULL, -EINVAL, "hts_store_event invalid\n");
	mutex_lock(&dev_ctx->mtx);

	if (check_hts_use_gpu_gragh(dev_id) != 0) {
		mutex_unlock(&dev_ctx->mtx);
		return 0;
	}

	for (i = 1; i <= HTS_MAX_EVENT_NUM; i++) {
		hts_get_auth_table(i, &table);
		if(table.data.valid == 1 && (table.data.src_id == dev_id || table.data.dst_id == dev_id)) {
			(void)hpd->hts_store_event((uint16_t)i);
			hts_drv_warn("dev(%u) store event_id:%u \n", dev_id, i);
		}
	}
	mutex_unlock(&dev_ctx->mtx);
	hts_drv_info("hts_event_outbuff_enable_by_dev end\n");
	return 0;
}
EXPORT_SYMBOL(hts_event_outbuff_enable_by_dev);

int hts_event_outbuff_disable_by_dev(uint32_t dev_id)
{
	hts_check_table table = {0};
	struct hts_dev_ctx *dev_ctx = NULL;
	struct hpd_registry *hpd = NULL;
	uint32_t i;

	hts_drv_info("hts_event_outbuff_disable_by_dev start\n");
	cond_return_error(dev_id == SOC_HTS || dev_id >= SOC_IPMAX, -EINVAL, " dev_id is invalid \n");
	dev_ctx = hts_get_dev_ctx();
	hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_unstore_event == NULL, -EINVAL, "hts_unstore_event invalid\n");
	mutex_lock(&dev_ctx->mtx);

	if (check_hts_use_gpu_gragh(dev_id) != 0) {
		mutex_unlock(&dev_ctx->mtx);
		return 0;
	}

	for (i = 1; i <= HTS_MAX_EVENT_NUM; i++) {
		hts_get_auth_table(i, &table);
		if(table.data.valid == 1 && (table.data.src_id == dev_id || table.data.dst_id == dev_id)) {
			(void)hpd->hts_unstore_event((uint16_t)i);
			hts_drv_warn("dev(%u) unstore event_id:%u \n", dev_id, i);
		}
	}
	mutex_unlock(&dev_ctx->mtx);
	hts_drv_info("hts_event_outbuff_disable_by_dev end\n");
	return 0;
}
EXPORT_SYMBOL(hts_event_outbuff_disable_by_dev);

int hts_connect(uint32_t dev_id)
{
	struct hts_dev_ctx *dev_ctx = NULL;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");

	cond_return_error(dev_id == SOC_HTS || dev_id >= SOC_IPMAX, -EINVAL, " dev_id is invalid \n");
	dev_ctx = hts_get_dev_ctx();
	if (atomic_read(&dev_ctx->dev_power_status[dev_id]) != 0) {
		hts_drv_warn("dev id = %u, already connect\n", dev_id);
		return 0;
	}
	atomic_set(&dev_ctx->dev_power_status[dev_id], 1);
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_unlock_event_by_ip == NULL, -EINVAL, "hts_unlock_event_by_ip invalid\n");
	return hpd->hts_unlock_event_by_ip((soc_ip)dev_id);
}
EXPORT_SYMBOL(hts_connect);

int hts_disconnect(uint32_t dev_id)
{
	struct hts_dev_ctx *dev_ctx = NULL;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");

	cond_return_error(dev_id == SOC_HTS || dev_id >= SOC_IPMAX, -EINVAL, " dev_id is invalid \n");
	dev_ctx = hts_get_dev_ctx();
	if (atomic_read(&dev_ctx->dev_power_status[dev_id]) == 0) {
		hts_drv_warn("dev id = %u, already disconnect\n", dev_id);
		return 0;
	}
	atomic_set(&dev_ctx->dev_power_status[dev_id], 0);
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd->hts_lock_event_by_ip == NULL, -EINVAL, "hts_lock_event_by_ip invalid\n");
	return hpd->hts_lock_event_by_ip((soc_ip)dev_id);
}
EXPORT_SYMBOL(hts_disconnect);

int hts_notify_event_exception(struct dev_pid_info info)
{
	int ret;
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");

	cond_return_error(hpd->hts_notify_event_exception == NULL, -EINVAL, "hts notify except is invalid\n");
	hts_drv_warn("dev_id:%u, pid:%d\n", info.dev_id, info.pid);
	ret = hpd->hts_notify_event_exception((soc_ip)info.dev_id, info.pid);
	return ret;
}
EXPORT_SYMBOL(hts_notify_event_exception);