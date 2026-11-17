
#ifndef _HISP_DEVICE_MANAGER_H
#define _HISP_DEVICE_MANAGER_H

#include <platform_include/isp/linux/hisp_remoteproc.h>
#include <platform_include/isp/linux/hisp_mempool.h>

enum hisp_op_master_e {
	CAMERA_OP = 0,
	CANN_OP   = 1,
	MAX_OP
};

typedef int (*hisp_rpmsg_cb)(void *data, unsigned int len);

int hisp_device_rproc_enable(enum hisp_op_master_e master, enum hisp_rproc_case_attr boot_type);
int hisp_device_rproc_disable(enum hisp_op_master_e master);

int hisp_device_clk_level2rate(unsigned int type, unsigned int clk_level, unsigned int *rate);
int hisp_device_set_clk_rate(enum hisp_op_master_e master, unsigned int type, unsigned int rate);

#ifdef ISP_LINX_CPU_SUPPORT
int hisp_device_mem_map_addr(enum hisp_op_master_e master, struct hisp_mem_type type,
	struct hisp_map_info_s *info, struct hisp_mem_info_s *mem);
int hisp_device_mem_unmap_addr(enum hisp_op_master_e master, struct hisp_mem_type type, struct hisp_mem_info_s mem_info);
#endif

int hisp_device_register_rpmsg_cb(enum hisp_op_master_e master, hisp_rpmsg_cb rpmsg_cb);
int hisp_device_unregister_rpmsg_cb(enum hisp_op_master_e master);
int hisp_device_rpmsg_send(enum hisp_op_master_e master, void *data, int len);

void hisp_device_update_ffrt_uid(enum hisp_op_master_e master, bool force);

void hisp_share_set_power_up_master(unsigned int master, unsigned int state);
unsigned int hisp_share_get_power_up_master(unsigned int master);
unsigned int hisp_share_check_power_down_master(unsigned int master);
void hisp_share_init_power_down_state(unsigned int master);
void hisp_share_clear_power_state(void);

int hisp_dev_set_boot_mode(enum hisp_rproc_case_attr type);
int hisp_dev_rproc_enable(enum hisp_rproc_case_attr boot_type);
int hisp_dev_rproc_disable(void);

void hisp_dev_update_camera_ffrt_uid(bool force);

#endif /* _HISP_DEVICE_MANAGER_H */

