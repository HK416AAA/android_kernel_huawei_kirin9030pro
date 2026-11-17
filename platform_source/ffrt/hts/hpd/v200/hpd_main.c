#include <linux/module.h>

#include "hts_kernel_log.h"
#include "hpd_interface.h"
#include "hpd_rule.h"
#include "hpd_profiling.h"
#include "hts_arch_exception.h"
#include "hts_resmem.h"
#include "hts_profiling.h"
#include "hts_event.h"
#include "hts_cfg.h"
#include "hpd_intr.h"
#include "hpd_event.h"

struct hpd_registry g_hpd_v200_registry = {
	.version = HPD_REGISTRY_V200,
	.hts_chip_version = 0,
	.hts_set_rule = hts_set_rule,
	.hts_destroy_rule = hts_destroy_rule,
	.hts_except_block_by_event = hts_except_block_by_event,
	.hts_ffts_outbuff_except_block_by_event = hts_ffts_outbuff_except_block_by_event,
	.hts_except_block_by_proc = hts_except_block_by_proc,
	.hts_store_event = hts_store_event,
	.hts_unstore_event = hts_unstore_event,
	.hts_except_block_by_ip = hts_except_block_by_ip,
	.hts_resource_clear = hts_resource_clear,
	.hts_dump_info = hts_dump_info,
	.hts_get_resmem_info = hts_plat_get_resmem_info,
	.hts_get_ip_event_by_uid = hts_get_ip_event_by_uid,
	.hts_lock_event_by_ip = hts_lock_event_by_ip,
	.hts_unlock_event_by_ip = hts_unlock_event_by_ip,
	.hts_dbg_en_open_cfg = hts_dbg_en_open_cfg,
	.hts_obuf_overflow_profiling = hts_obuf_overflow_profiling,
	.hts_irq_init = hts_irq_init,
	.hts_event_alloc = hts_event_alloc,
	.hts_get_alloc_type_by_eventid = hts_get_alloc_type_by_eventid,
	.hts_set_dev_ctx_events = hts_set_dev_ctx_events,
	.hts_notify_event_exception = hts_plat_notify_event_exception,
	.hts_check_hts_use_gpu_gragh = hts_plat_check_hts_use_gpu_gragh,
	.hts_set_dynamic_graph_info = hts_plat_set_dynamic_graph_info,
	.hts_reset_dynamic_graph_info = hts_plat_reset_dynamic_graph_info,
};

static int __init hpd_init(void)
{
	int ret = hkd_register_plat_driver(&g_hpd_v200_registry);
	if (ret != 0)
		hts_drv_err("hkd register faild %d", ret);
	return ret;
}
module_init(hpd_init);

static void __exit hpd_exit(void)
{
	hkd_unregister_plat_driver();
}
module_exit(hpd_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("HTS Platform Driver(HPD)");
MODULE_VERSION("V1.0");
