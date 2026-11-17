
#ifndef HISP_RPMSG_H
#define HISP_RPMSG_H

#include <linux/rpmsg.h>
#include "hisp_device_manager.h"

#define RPMSG_CAMERA_START 0x1000
#define RPMSG_CAMERA_END   0x3FFF
#define RPMSG_CANN_START   0x4000
#define RPMSG_CANN_END     0x41FF

#define MSG_MASK_KERNL        0xf000
#define MSG_MASK_KERNL_TO_ISP 0xf400
#define MSG_MASK_ISP_TO_KERNL 0xf800
#define MSG_MASK_ID           0xf0000000

void hisp_rpmsg_set_ept(struct rpmsg_endpoint *ept);
void hisp_rpmsg_receive(enum hisp_op_master_e master, void *data, int len);
int hisp_rpmsg_send(enum hisp_op_master_e master, void *data, int len);
int hisp_rpmsg_wait_handshake(void);
void hisp_rpmsg_handshake_init(void);
void hisp_rpmsg_handshake_complete(void);
void hisp_rpmsg_register_callback(unsigned int master, hisp_rpmsg_cb callback);
int hisp_rpmsg_device_switch2camera(void);
int hisp_rpmsg_device_switch2cann(void);
#ifdef DEBUG_HISP
unsigned int hisp_rpmsg_debug_isp_power_on(void);
#endif

#endif /* HISP_RPMSG_H */

