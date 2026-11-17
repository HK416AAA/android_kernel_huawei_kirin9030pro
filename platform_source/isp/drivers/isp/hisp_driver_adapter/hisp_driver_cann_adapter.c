
#include <linux/err.h>
#include "hisp_driver_interface_cann.h"
#include "hisp_device_manager.h"

int hisp_power_up_cann(hisp_rpmsg_cb rpmsg_cb)
{
	hisp_device_register_rpmsg_cb(CANN_OP, rpmsg_cb);

	return hisp_device_rproc_enable(CANN_OP, NONSEC_CASE);
}

int hisp_power_down_cann(void)
{
	hisp_device_unregister_rpmsg_cb(CANN_OP);
	return hisp_device_rproc_disable(CANN_OP);
}

int hisp_set_clk_rate_cann(unsigned int type, unsigned int clk_level)
{
	unsigned int rate = 0;
	int ret = 0;

	pr_info("[%s] type %u clk_level %u\n", __func__, type, clk_level);

	ret = hisp_device_clk_level2rate(type, clk_level, &rate);
	if (ret != 0) {
		pr_err("clk level %u to rate failed\n", clk_level);
		return ret;
	}

	pr_info("[%s] type %u rate %u\n", __func__, type, rate);

	return hisp_device_set_clk_rate(CANN_OP, type, rate);
}

#ifdef ISP_LINX_CPU_SUPPORT
int hisp_mem_map_addr_cann(struct hisp_mem_type type, struct hisp_map_info_s *info, struct hisp_mem_info_s *mem)
{
	return hisp_device_mem_map_addr(CANN_OP, type, info, mem);
}

int hisp_mem_unmap_addr_cann(struct hisp_mem_type type, struct hisp_mem_info_s mem_info)
{
	return hisp_device_mem_unmap_addr(CANN_OP, type, mem_info);
}
#endif

int hisp_rpmsg_send_cann(void *data, int len)
{
	return hisp_device_rpmsg_send(CANN_OP, data, len);
}

