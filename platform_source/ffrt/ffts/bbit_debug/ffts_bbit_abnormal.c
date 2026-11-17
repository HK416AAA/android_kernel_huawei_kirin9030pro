#include "ffts_bbit_abnormal.h"

#include <linux/debugfs.h>
#include <linux/uaccess.h>

#include "ffts_bbit_debug.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "ffts_interrupt.h"
#include "ffts_log.h"
#include "debug/ffts_dfx_debug.h"

ssize_t ffts_bbit_abnormal_read(struct file *filp, char __user *buf,
	size_t count, loff_t *ppos)
{
	struct user_msg msg = {0};
	uint32_t cnt = 0;
	unused(filp);
	unused(ppos);


	if (buf == NULL || count != sizeof(struct user_msg)) {
		ffts_drv_err("invalid pointer.\n");
		return -1;
	}
	
	if (copy_from_user(&msg, buf, sizeof(msg)) != 0) {
		ffts_drv_err("copy from user failed \n");
		return -1;
	}

	if (msg.interface_id >= INTERFACE_MAX || msg.len < sizeof(uint32_t)) {
		ffts_drv_err("invalid interface_id %d.\n", msg.interface_id);
		return -1;
	}

	if (msg.interface_id < INTERFACE_GET_COUNT_FFTS_DFX)
		cnt = ffts_get_abnormal_count(msg.interface_id);
	else if (msg.interface_id == INTERFACE_GET_COUNT_FFTS_DFX)
		cnt = ffts_get_dfx_count();
	else if (msg.interface_id == INTERFACE_GET_COUNT_FFTS_DEBUG_INFO_HWRTB)
		cnt = ffts_get_debug_info(HWRTB_CONNECT_STATE, 1);
	else if (msg.interface_id == INTERFACE_GET_COUNT_FFTS_DEBUG_INFO_SUBMIT)
		cnt = ffts_get_debug_info(SUBMIT_PROCESS_UNIT_STATE_0, 2);
	else if (msg.interface_id == INTERFACE_GET_COUNT_FFTS_DEBUG_INFO_TASK_DONE)
		cnt = ffts_get_debug_info(TASKDONE_PROCESS_UNIT_STATE_0, 0);
	
	if (copy_to_user(msg.buf, &cnt, sizeof(cnt)) != 0) {
		ffts_drv_err("copy to user buffer failed.\n");
		return -1;
	}

	return (ssize_t)count;
}

ssize_t ffts_bbit_abnormal_write(struct file *filp, const char __user *buf,
	size_t count, loff_t *ppos)
{
	return (ssize_t)count;
}