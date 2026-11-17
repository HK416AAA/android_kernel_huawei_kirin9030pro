#ifndef _HISP_DRIVER_CAN_INTERFACE_H
#define _HISP_DRIVER_CAN_INTERFACE_H

#include <platform_include/isp/linux/hisp_mempool.h>
#include "hisp_rpmsg.h"

int hisp_power_up_cann(hisp_rpmsg_cb rpmsg_cb);
int hisp_power_down_cann(void);

int hisp_set_clk_rate_cann(unsigned int type, unsigned int clk_level);

#ifdef ISP_LINX_CPU_SUPPORT
int hisp_mem_map_addr_cann(struct hisp_mem_type type, struct hisp_map_info_s *info, struct hisp_mem_info_s *mem);
int hisp_mem_unmap_addr_cann(struct hisp_mem_type type, struct hisp_mem_info_s mem_info);
#endif

int hisp_rpmsg_send_cann(void *data, int len);

#endif /* _HISP_DRIVER_CAN_INTERFACE_H */

