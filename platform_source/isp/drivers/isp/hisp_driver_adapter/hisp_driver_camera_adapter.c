
#include <platform_include/isp/linux/hisp_remoteproc.h>
#include "hisp_device_manager.h"

enum hisp_rproc_case_attr camera_boot_type = NONSEC_CASE;

int hisp_set_boot_mode(enum hisp_rproc_case_attr type)
{
	camera_boot_type = type;
	return 0;
}

int hisp_rproc_enable(void)
{
	return hisp_device_rproc_enable(CAMERA_OP, camera_boot_type);
}

int hisp_rproc_disable(void)
{
	return hisp_device_rproc_disable(CAMERA_OP);
}

int hisp_set_clk_rate(unsigned int type, unsigned int rate)
{
	return hisp_device_set_clk_rate(CAMERA_OP, type, rate);
}

#if defined(ISP_LINX_CPU_SUPPORT)
int hisp_mem_map_addr(struct hisp_mem_type type, struct hisp_map_info_s *info, struct hisp_mem_info_s *mem)
{
	return hisp_device_mem_map_addr(CAMERA_OP, type, info, mem);
}

int hisp_mem_unmap_addr(struct hisp_mem_type type, struct hisp_mem_info_s mem_info)
{
	return hisp_device_mem_unmap_addr(CAMERA_OP, type, mem_info);
}
#endif

void hisp_update_camera_ffrt_uid(bool force)
{
	return hisp_device_update_ffrt_uid(CAMERA_OP, force);
}

