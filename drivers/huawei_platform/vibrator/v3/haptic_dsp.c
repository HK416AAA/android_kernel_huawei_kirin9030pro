/*
 * haptic_dsp.c
 *
 * common logic for haptic DSP
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/mman.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/vmalloc.h>
#include <linux/suspend.h>
#include <linux/types.h>
#include <linux/platform_device.h>
#include <linux/mtd/nve_ap_kernel_interface.h>
#include <linux/err.h>
#include <securec.h>
#include <linux/completion.h>
#include <linux/jiffies.h>
#include <huawei_platform/log/hw_log.h>

#include "dsp_misc.h"
#include "audio_common_msg_id.h"
#include "audio_haptic.h"
#include "drv_mailbox_cfg.h"
#include "drv_mailbox_msg.h"
#include "haptic_dsp.h"
#include "ap_dsp_haptic_msg.h"
#include "pa_haptic.h"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG ap_haptic_dsp
HWLOG_REGIST();

#define FILE_PATH "/data/test2"

#define INVALID_PARA_CHECK(ret) do { \
	if ((ret) != 0) { \
		hwlog_err("%s: %d err\n", __func__, __LINE__); \
		return -EINVAL; \
	} \
} while (0)

#define IS_DSP_F0_VALID(f0_param) (((f0_param) >= HAPTIC_F0_LOW_THRE) && ((f0_param) <= HAPTIC_F0_HIGH_THRE))

static struct dsp_haptic_t *dsp_haptic_pub;
static int haptic_recv_msg_proc(void *msg);
static int haptic_get_calib_f0(struct dsp_haptic_t *dsp_haptic);
#ifdef CONFIG_AUDIO_HAPTIC_UEVENT
static DECLARE_COMPLETION(haptic_codec_done);
static bool haptic_codec_result = false;
#endif

struct dsp_haptic_t *get_dsp_haptic(void)
{
	return dsp_haptic_pub;
}

static int _mail_buff_init(struct recv_request **recv, unsigned int mail_len,
	struct mb_queue *mail_handle)
{
	unsigned int ret;

	*recv = kmalloc(sizeof(struct recv_request), GFP_ATOMIC);
	if (!(*recv)) {
		hwlog_err("recv kmalloc failed\n");
		return -ENOMEM;
	}
	(void)memset_s(*recv, sizeof(**recv), 0, sizeof(**recv));

	(*recv)->rev_msg.mail_buff_len = mail_len;
	(*recv)->rev_msg.mail_buff = kmalloc(mail_len, GFP_ATOMIC);
	if (!(*recv)->rev_msg.mail_buff) {
		hwlog_err("mail buff kmalloc failed\n");
		return -ENOMEM;
	}
	(void)memset_s((*recv)->rev_msg.mail_buff, mail_len, 0, mail_len);

	/* copy remain content to buff */
	ret = mailbox_read_msg_data(mail_handle, (char *)((*recv)->rev_msg.mail_buff),
		(unsigned int *)(&(*recv)->rev_msg.mail_buff_len));
	if ((ret != 0) || ((*recv)->rev_msg.mail_buff_len == 0)) {
		hwlog_err("empty point or data length error ret:%u, mail size: %u\n",
			ret, (*recv)->rev_msg.mail_buff_len);
		return -EINVAL;
	}

	return 0;
}

static void _mail_buff_deinit(struct recv_request **recv)
{
	if (*recv) {
		if ((*recv)->rev_msg.mail_buff) {
			kfree((*recv)->rev_msg.mail_buff);
			(*recv)->rev_msg.mail_buff = NULL;
		}

		kfree(*recv);
		*recv = NULL;
	}
}

static void haptic_recv_msg_handle_mail(const void *usr_para, struct mb_queue *mail_handle, uint32_t mail_len)
{
	int ret;
	struct recv_request *recv = NULL;
	void *recmsg = NULL;

	hwlog_info("%s\n", __func__);
	if (!mail_handle) {
		hwlog_err("mail handle is null\n");
		return;
	}

	if (mail_len >= MAIL_LEN_MAX || mail_len < sizeof(unsigned short)) {
		hwlog_err("mail len is invalid: %u, max: 512, min: 2\n", mail_len);
		return;
	}

	ret = _mail_buff_init(&recv, mail_len, mail_handle);
	if (ret != 0)
		goto kfree;

	recmsg = (void *)recv->rev_msg.mail_buff;

	if (haptic_recv_msg_proc(recmsg) != 0) {
		hwlog_err("haptic test msg proc failed\n");
		goto kfree;
	}
kfree:
	_mail_buff_deinit(&recv);
}

static void haptic_set_update_request_ram_status(struct dsp_haptic_t *dsp_haptic, bool status)
{
	if (!dsp_haptic->shared_prv_data) {
		hwlog_err("%s virt_map is invalid", __func__);
		return;
	}

	dsp_haptic->shared_prv_data->need_update_ram = status;
}

static void haptic_set_play_done_status(struct dsp_haptic_t *dsp_haptic, bool status)
{
	if (!dsp_haptic->shared_prv_data) {
		hwlog_err("%s virt_map is invalid", __func__);
		return;
	}

	dsp_haptic->shared_prv_data->stream_play_done = status;
}

static void haptic_recv_start_cnf_msg(struct haptic_start_cnf_msg *start_cnf, struct dsp_haptic_t *dsp_haptic)
{
	hwlog_info("%s ret = %d", __func__, start_cnf->ret);
	dsp_haptic->start_play_succ = !!start_cnf->ret;
}

static void haptic_recv_play_done_msg(struct haptic_play_done_to_ap_msg *play_done_msg,
	struct dsp_haptic_t *dsp_haptic)
{
	uint32_t pa_idx = 0;
	uint32_t dsp_f0 = 0;

	hwlog_info("%s new_re0 = %u, new_re1 = %u new_f0[0] = %u, new_f0[1] = %u", __func__, play_done_msg->new_re[0],
		play_done_msg->new_re[1], play_done_msg->new_f0[0], play_done_msg->new_f0[1]);
	for (pa_idx = 0; pa_idx < MAX_HAPTIC_NUM; pa_idx++) {
		if (dsp_haptic->pa_haptic[pa_idx]) {
			dsp_haptic->pa_haptic[pa_idx]->new_re = play_done_msg->new_re[pa_idx];
			dsp_f0 = play_done_msg->new_f0[pa_idx] / FLOAT_TO_FIX; // check f0 valid
			if (IS_DSP_F0_VALID(dsp_f0))
				dsp_haptic->pa_haptic[pa_idx]->haptic_f0_val = play_done_msg->new_f0[pa_idx];
		}
	}

	haptic_set_play_done_status(dsp_haptic, true);
	haptic_set_update_request_ram_status(dsp_haptic, true);
	// set power off, HAL will exec this schedule
}

static int haptic_f0_valid_calc(int haptic_f0_val)
{
	int ret = 0;
	int f0 = haptic_f0_val / HAPTIC_Q_BASE;

	if (f0 <= HAPTIC_F0_HIGH_THRE && f0 >= HAPTIC_F0_LOW_THRE) {
		hwlog_info("%s haptic_f0_val is valid", __func__);
	} else {
		hwlog_err("%s haptic_f0_val is invalid, out of range", __func__);
		ret = -EINVAL;
	}
	return ret;
}

static void haptic_recv_f0_test_done_msg(struct haptic_f0_start_cnf_msg_t *msg,
	struct dsp_haptic_t *dsp_haptic)
{
	uint32_t pa_idx = 0;
	uint32_t calib_f0 = 0;

	hwlog_info("%s haptic_f0_val = %d, %d", __func__, msg->haptic_f0_val[0], msg->haptic_f0_val[1]);
	for (pa_idx = 0; pa_idx < MAX_HAPTIC_NUM; pa_idx++) {
		if (!dsp_haptic->pa_haptic[pa_idx])
			continue;
		hwlog_info("%s pa-%u exist, f0 valid check\n", __func__, pa_idx);
		dsp_haptic->pa_haptic[pa_idx]->cali_rst = haptic_f0_valid_calc(msg->haptic_f0_val[pa_idx]);
		if (msg->haptic_f0_val[pa_idx] > 0) {
			calib_f0 = msg->haptic_f0_val[pa_idx] * FLOAT_TO_FIX / HAPTIC_Q_BASE + dsp_haptic->f0_compensation;
			if (IS_DSP_F0_VALID(calib_f0 / FLOAT_TO_FIX)) {
				dsp_haptic->pa_haptic[pa_idx]->charge_calib_f0 = calib_f0;
				dsp_haptic->pa_haptic[pa_idx]->haptic_f0_val = calib_f0;  // update next get_vb_f0 result
			}
		}
	}
	haptic_set_play_done_status(dsp_haptic, true);
}

static void haptic_recv_dfx_report_msg(haptic_bigdata *msg, struct dsp_haptic_t *dsp_haptic)
{
	int ret;
	ret = memcpy_s(&dsp_haptic->haptic_bigdata_work.bigdata, sizeof(haptic_bigdata), msg, sizeof(haptic_bigdata));
	if (ret != 0) {
		hwlog_err("%s memcpy_s err", __func__);
		return;
	};
	schedule_work(&dsp_haptic->haptic_bigdata_work.bigdata_work);
}

static int haptic_recv_msg_proc(void *msg)
{
	uint16_t msg_id = 0;

	if (!msg || !dsp_haptic_pub) {
		hwlog_err("%s err ptr", __func__);
		return -EINVAL;
	}
	msg_id = *((unsigned short *)msg);
	switch(msg_id) {
	case ID_DSP_AP_AUDIO_HAPTIC_START_CNF_CMD:
		haptic_recv_start_cnf_msg((struct haptic_start_cnf_msg *)msg, dsp_haptic_pub);
		break;
	case ID_DSP_AP_AUDIO_HAPTIC_REQ_DATA_CMD:
		hwlog_info("request update ram data");
		haptic_set_update_request_ram_status(dsp_haptic_pub, true);
		break;
	case ID_DSP_AP_AUDIO_HAPTIC_PLAY_DONE_CMD:
		haptic_recv_play_done_msg((struct haptic_play_done_to_ap_msg *)msg, dsp_haptic_pub);
		break;
	case ID_DSP_AP_AUDIO_HAPTIC_START_F0_CNF_CMD:
		haptic_recv_f0_test_done_msg((struct haptic_f0_start_cnf_msg_t *)msg, dsp_haptic_pub);
		break;
	case ID_AUDIO_HAPTIC_DFX_REPORT_CMD:
		haptic_recv_dfx_report_msg((haptic_bigdata *)msg, dsp_haptic_pub);
		break;
	default:
		hwlog_err("haptic recv msg id: 0x%x error\n", msg_id);
		return -1;
	}

	return 0;
}

static int dsp_haptic_ctrl_open(struct inode *inode, struct file *filp)
{
	if (!filp)
		return 0;

	if (!try_module_get(THIS_MODULE))
		return -ENODEV;

	filp->private_data = dsp_haptic_pub;

	return 0;
}

static int dsp_haptic_ctrl_release(struct inode *inode, struct file *file)
{
	if ((inode == NULL) || (file == NULL)) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	file->private_data = NULL;
	return 0;
}

static ssize_t dsp_haptic_ctrl_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
	return len;
}

static ssize_t dsp_haptic_ctrl_read(struct file *filp, char *buff, size_t len, loff_t *offset)
{
	return len;
}

#ifdef DUMP_HAPTIC_RAM_DATA
static void dump_data(uint32_t len)
{
    struct file *file;
    mm_segment_t old_fs;
    loff_t pos;
    int ret;

	hwlog_info("%s write Len = %u", __func__, len);
	if (dsp_haptic_pub->virt_map == NULL) {
		hwlog_info("%s virt map fail", __func__);
		return;
	}
    // open file
    old_fs = get_fs();
    set_fs(KERNEL_DS);
    file = filp_open(FILE_PATH, O_WRONLY | O_APPEND, 0);
    if (IS_ERR(file)) {
        hwlog_err("%s open fail, reason = %d", __func__, PTR_ERR(file));
        set_fs(old_fs);
        return;
    }

    pos = file->f_pos;
    // write data
    ret = kernel_write(file, dsp_haptic_pub->virt_map, len, &pos);
    if (ret < 0) {
		hwlog_err("%s write fail", __func__);
        filp_close(file, NULL);
        set_fs(old_fs);
        return;
    }

    // close file
    filp_close(file, NULL);
    set_fs(old_fs);
}
#endif

static int haptic_send_open_msg_to_dsp(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int ret = 0;
	struct haptic_start_msg_t start_msg;
	uint32_t haptic0_calib_f0 = haptic_get_calib_f0(dsp_haptic);

	haptic_set_update_request_ram_status(dsp_haptic, false);
	(void)memset_s(&start_msg, sizeof(start_msg), 0, sizeof(start_msg));
	if (copy_from_user(&start_msg, argp, sizeof(start_msg))) {
		hwlog_info("%s, recv hal start cmd fail", __func__);
		return -EFAULT;
	}
	start_msg.calib_haptic0_f0 = haptic0_calib_f0;
	start_msg.msg_id = ID_AP_DSP_AUDIO_HAPTIC_START_CMD;
	start_msg.default_re0 = dsp_haptic->haptic_re0;
	if (dsp_haptic->pa_haptic[0])
		start_msg.vendor_id = vendor_id_convert_to_dsp(dsp_haptic->pa_haptic[0]->vendor_id);
#ifdef DUMP_HAPTIC_RAM_DATA
	dump_data(start_msg.data_len);
#endif
	ret = dsp_send_msg(MAILBOX_MAILCODE_ACPU_TO_HIFI_HAPTIC, &start_msg, sizeof(start_msg));
	if (ret) {
		hwlog_err("%s send start msg fail, ret = %d\n", __func__, ret);
		return ret;
	}
	hwlog_info("%s, send start msg success, data len = %u, vendor_id = %u", __func__,
		start_msg.data_len, start_msg.vendor_id);
	return 0;
}

static int haptic_set_pa_power_state(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int ret;
	uint32_t pa_idx;
	uint32_t on_status = 0;

	if (copy_from_user(&on_status, argp, sizeof(uint32_t))) {
		hwlog_info("%s, recv power state fail", __func__);
		return -EFAULT;
	}
	hwlog_info("%s = %u\n", __func__, on_status);
	for (pa_idx = 0; pa_idx < MAX_HAPTIC_NUM; pa_idx++) {
		if (!dsp_haptic->pa_haptic[pa_idx])
			continue;
		ret = haptic_pa_power_on(dsp_haptic->pa_haptic[pa_idx], !!on_status);
		if (ret < 0) {
			hwlog_err("%s, pa_haptic[%u] power fail", __func__, pa_idx);
			return ret;
		}
	}

	return 0;
}

static int haptic_play_stop(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int ret = 0;
	struct haptic_stop_msg_t stop_msg;
	// 1, send stop msg to dsp
	// 2, set play_done to true
	// 3, wait for 3s for pa power off
	if (!argp)
		return -EINVAL;
	hwlog_info("%s", __func__);
	(void)memset_s(&stop_msg, sizeof(stop_msg), 0, sizeof(stop_msg));
	if (copy_from_user(&stop_msg, argp, sizeof(stop_msg))) {
		hwlog_err("%s copy data fail", __func__);
		return -EFAULT;
	}
	stop_msg.msg_id = ID_AP_DSP_AUDIO_HAPTIC_STOP_CMD;
	ret = dsp_send_msg(MAILBOX_MAILCODE_ACPU_TO_HIFI_HAPTIC, &stop_msg, sizeof(stop_msg));
	if (ret) {
		hwlog_err("%s send msg fail, ret = %d\n", __func__, ret);
		return ret;
	}
	haptic_set_update_request_ram_status(dsp_haptic, true);
	return 0;
}

static int haptic_send_updata_ram_msg_to_dsp(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int ret = 0;
	struct haptic_update_sh_buf_msg_t update_msg;

	if (!argp)
		return -EINVAL;
#ifdef DUMP_HAPTIC_RAM_DATA
	haptic_pa_dump_data(dsp_haptic->pa_haptic[0]);
#endif
	haptic_set_update_request_ram_status(dsp_haptic, false);
	(void)memset_s(&update_msg, sizeof(update_msg), 0, sizeof(update_msg));
	if (copy_from_user(&update_msg, argp, sizeof(update_msg)))
		return -EFAULT;
	update_msg.msg_id = ID_AP_DSP_AUDIO_HAPTIC_UPDATE_SHARE_BUF_CMD;
	hwlog_info("%s send update msg, data_len = %u\n", __func__, update_msg.data_len);
#ifdef DUMP_HAPTIC_RAM_DATA
	dump_data(update_msg.data_len);
#endif
	ret = dsp_send_msg(MAILBOX_MAILCODE_ACPU_TO_HIFI_HAPTIC, &update_msg, sizeof(update_msg));
	if (ret) {
		hwlog_err("%s send msg fail, ret = %d\n", __func__, ret);
		return ret;
	}
	return 0;
}

static int haptic_get_check_f0(uint32_t f0)
{
	int tmp = 1710;

	if ((f0 >= (HAPTIC_F0_LOW_THRE * FLOAT_TO_FIX)) && (f0 <= (HAPTIC_F0_HIGH_THRE * FLOAT_TO_FIX))) {
		tmp = f0;
	} else if (f0 > (HAPTIC_F0_HIGH_THRE * FLOAT_TO_FIX)) {
		tmp = HAPTIC_F0_HIGH_THRE * FLOAT_TO_FIX;
		hwlog_err("%s f0 = %u is invalid, out of range", __func__, f0);
		pa_haptic_dmd_work(DSM_VIBRATOR_F0_ERROR);
	} else if ((f0 > 0) && (f0 < (HAPTIC_F0_LOW_THRE * FLOAT_TO_FIX))) {
		tmp = HAPTIC_F0_LOW_THRE * FLOAT_TO_FIX;
		hwlog_err("%s f0 = %u is invalid, out of range", __func__, f0);
		pa_haptic_dmd_work(DSM_VIBRATOR_F0_ERROR);
	}
	return tmp;
}

static int haptic_get_calib_f0(struct dsp_haptic_t *dsp_haptic)
{
	int tmp;

	if (!dsp_haptic || !dsp_haptic->pa_haptic[0])
		return -EINVAL;

	tmp = haptic_get_check_f0(dsp_haptic->haptic_uefi_f0);
	if (dsp_haptic->pa_haptic[0]->charge_calib_f0 != 0)
		tmp = haptic_get_check_f0(dsp_haptic->pa_haptic[0]->charge_calib_f0);

	return tmp;
}

static int haptic_get_vb_f0(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int tmp;
	int dsp_f0;

	if (!argp || !dsp_haptic || !dsp_haptic->pa_haptic[0])
		return -EINVAL;

	tmp = haptic_get_calib_f0(dsp_haptic);

	dsp_f0 = dsp_haptic->pa_haptic[0]->haptic_f0_val / FLOAT_TO_FIX; // check dsp f0 (162, 178)
	if (IS_DSP_F0_VALID(dsp_f0))
		tmp = dsp_haptic->pa_haptic[0]->haptic_f0_val;

	hwlog_info("%s update f0 = %d dsp f0 = %d charge_f0 = %u\n", __func__,
		tmp, dsp_haptic->pa_haptic[0]->haptic_f0_val, dsp_haptic->pa_haptic[0]->charge_calib_f0);

	if (copy_to_user(argp, &tmp, sizeof(int)))
		return -EFAULT;
	return 0;
}

static int haptic_pa_get_hw_info(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	if (!argp || !dsp_haptic->pa_haptic[0]) {
		hwlog_err("%s para err", __func__);
		return -EINVAL;
	}
	hwlog_info("%s get vendor_id = %u", __func__, dsp_haptic->pa_haptic[0]->vendor_id);
	if (copy_to_user(argp, &dsp_haptic->pa_haptic[0]->vendor_id, sizeof(uint32_t)))
		return -EFAULT;
	return 0;
}

static int haptic_pa_send_f0_test_cmd(struct dsp_haptic_t *dsp_haptic)
{
	int ret = 0;
	struct haptic_f0_start_msg f0_cali_msg;

	if (!dsp_haptic->pa_haptic[0]) {
		hwlog_err("%s pa_haptic is null\n", __func__);
		return -EFAULT;
	}
	haptic_pa_set_bst_cfg(dsp_haptic->pa_haptic[0], true);
	haptic_set_play_done_status(dsp_haptic, false);
	(void)memset_s(&f0_cali_msg, sizeof(f0_cali_msg), 0, sizeof(f0_cali_msg));
	f0_cali_msg.msg_id = ID_AP_DSP_AUDIO_HAPTIC_START_F0_CMD;
	f0_cali_msg.vendor_id = vendor_id_convert_to_dsp(dsp_haptic->pa_haptic[0]->vendor_id);
	f0_cali_msg.default_re[0] = dsp_haptic->haptic_re0;
	hwlog_info("%s vendor_id = %u, default_re = %u", __func__, f0_cali_msg.vendor_id, f0_cali_msg.default_re[0]);
	ret = dsp_send_msg(MAILBOX_MAILCODE_ACPU_TO_HIFI_HAPTIC, &f0_cali_msg, sizeof(f0_cali_msg));
	if (ret)
		hwlog_err("%s send msg fail, ret = %d\n", __func__, ret);
	if (dsp_haptic->pa_haptic[0])
		dsp_haptic->pa_haptic[0]->cali_rst = -1;
	return ret;
}

static int haptic_pa_set_paras_config(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int ret = 0;
	struct haptic_set_params_msg set_msg_cmd;

	(void)memset_s(&set_msg_cmd, sizeof(set_msg_cmd), 0, sizeof(set_msg_cmd));
	if (copy_from_user(&set_msg_cmd, argp, sizeof(set_msg_cmd)))
		return -EFAULT;

	return ret;
}

static int haptic_get_f0_test_rst(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	struct haptic_cali_rst_t cali_info;

	(void)memset_s(&cali_info, sizeof(cali_info), 0, sizeof(cali_info));
	if (!dsp_haptic->pa_haptic[0]) {
		hwlog_err("%s pa_haptic is null\n", __func__);
		return -EFAULT;
	}

	hwlog_info("%s f0 = %d, cali_rst = %d\n", __func__, dsp_haptic->pa_haptic[0]->haptic_f0_val,
		dsp_haptic->pa_haptic[0]->cali_rst);
	cali_info.cal_rst = dsp_haptic->pa_haptic[0]->cali_rst;
	cali_info.cali_val = dsp_haptic->pa_haptic[0]->haptic_f0_val;
	if (copy_to_user(argp, (void *)&cali_info, sizeof(cali_info)) != 0) {
		hwlog_err("%s,support copy_to_user err\n", __func__);
		return -EFAULT;
	}
	return 0;
}

static int haptic_read_data_from_nv(uint32_t data_size, uint32_t *nv_data)
{
	int ret;
	struct opt_nve_info_user user_info;
 
	ret = memset_s(&user_info, sizeof(user_info), 0, sizeof(user_info));
	INVALID_PARA_CHECK(ret);
 
	if (data_size != sizeof(uint32_t)) {
		hwlog_err("%s: memset fail\n", __func__);
		return -1;
	}
	user_info.nv_operation = NV_READ_TAG;
	user_info.nv_number = HAPTIC_CALI_DATA_NV_NUM;
	user_info.valid_size = data_size;
 
	ret = strncpy_s(user_info.nv_name, sizeof(user_info.nv_name),
		HAPTIC_CALI_DATA_NAME, strlen(HAPTIC_CALI_DATA_NAME));
	INVALID_PARA_CHECK(ret);
 
	ret = nve_direct_access_interface(&user_info);
	INVALID_PARA_CHECK(ret);
 
	ret = memcpy_s(nv_data, data_size, user_info.nv_data, data_size);
	INVALID_PARA_CHECK(ret);
 
	hwlog_info("%s: succ\n", __func__);
	return 0;
}

static uint32_t haptic_get_r0_data(struct pa_paptic_t *pa_haptic)
{
	uint32_t r0 = 0;
	int ret = 0;
 
	if (!pa_haptic) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}
	ret = haptic_read_data_from_nv(sizeof(uint32_t), &r0);
	if (ret != 0) {
		hwlog_err("%s do not get r0 from nv, set default val", __func__);
		r0 = HAPTIC_R0_DEFAULT;
	}

	if (pa_haptic->r_scale != 0)
		r0 = r0 * R_Q15 / pa_haptic->r_scale;
	else
		r0 = HAPTIC_DEFAULT_R0;
	hwlog_info("%s get r0 val = %u", __func__, r0);
	
	return r0;
}

static int dsp_haptic_set_stream_mode(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int ret = 0;

	// pa and codec already opened by hal schedule
	if (!argp)
		return -EINVAL;

	// set play done to false
	haptic_set_play_done_status(dsp_haptic, false);
	// send start stream msg to dsp
	ret = haptic_send_open_msg_to_dsp(argp, dsp_haptic);
	return ret;
}

static int haptic_set_pa_configs(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	return pa_haptic_get_dev_cfgs(argp, dsp_haptic->pa_haptic[0]);
}

#ifdef CONFIG_AUDIO_HAPTIC_UEVENT
static void haptic_codec_callback(bool cb_status)
{
    haptic_codec_result = cb_status;
    complete(&haptic_codec_done);
}

static int haptic_set_codec_ctrl(void __user *argp, struct dsp_haptic_t *dsp_haptic)
{
	int powerState;
	int ret;
	unsigned long timeout;

	if (copy_from_user(&powerState, argp, sizeof(uint32_t))) {
		hwlog_info("%s, recv power state fail", __func__);
		return -EFAULT;
	}
	hwlog_info("%s powerState = %d", __func__, powerState);

	reinit_completion(&haptic_codec_done);

	ret = audio_haptic_switch_path(powerState ? true : false);
	if (ret < 0) {
		hwlog_info("haptic: codec path switch failed, ret=%d\n", ret);
		return ret;
	}
	timeout = wait_for_completion_timeout(&haptic_codec_done, msecs_to_jiffies(30));
	if (timeout == 0) {
		hwlog_err("%s: wait codec ready timeout", __func__);
		return -ETIMEDOUT;
	}

	return haptic_codec_result ? 0 : -EIO;
}
#endif

static long dsp_haptic_ctrl_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct dsp_haptic_t *dsp_haptic = NULL;
	void __user *argp = (void __user *)(uintptr_t)arg;
	int ret = 0;

	hwlog_info("%s cmd = 0x%x", __func__, cmd);
	if (!filp || !filp->private_data) {
		hwlog_err("%s info is null", __func__);
		return -EFAULT;
	}

	dsp_haptic = (struct dsp_haptic_t *)filp->private_data;
	switch (cmd) {
	case HAPTIC_DSP_STREAM_MODE: // send start cmd to dsp, then play wave data
		ret = dsp_haptic_set_stream_mode(argp, dsp_haptic);
		break;
	case HAPTIC_PA_POWER_ON: // send pa power on
		ret = haptic_set_pa_power_state(argp, dsp_haptic);
		break;
	case HAPTIC_DSP_GET_F0: // get haptic f0 value
		ret = haptic_get_vb_f0(argp, dsp_haptic);
		break;
	case HAPTIC_DSP_STOP_MODE: // send stop play cmd to dsp
		ret = haptic_play_stop(argp, dsp_haptic);
		break;
	case HAPTIC_DSP_UPDATE_RAM: // send update wave data cmd to dsp
		ret = haptic_send_updata_ram_msg_to_dsp(argp, dsp_haptic);
		break;
	case HAPTIC_DSP_GET_HWINFO: // send pa paras cmd to dsp
		ret = haptic_pa_get_hw_info(argp, dsp_haptic);
		break;
	case HAPTIC_DSP_F0_TEST: // send f0 test cmd to dsp, only single
		ret = haptic_pa_send_f0_test_cmd(dsp_haptic);
		break;
	case HAPTIC_DSP_F0_GET_TEST_RST: // get f0 test result, only single
		ret = haptic_get_f0_test_rst(argp, dsp_haptic);
		break;
	case HAPTIC_DSP_PA_CONFIGS:
		ret = haptic_set_pa_configs(argp, dsp_haptic);
		break;
#ifdef CONFIG_AUDIO_HAPTIC_UEVENT
	case HAPTIC_CODEC_CTRL:
		ret = haptic_set_codec_ctrl(argp, dsp_haptic);
		break;
#endif
	default:
		break;
	}
	return ret;
}

static int dsp_haptic_ctrl_mmap(struct file *filp, struct vm_area_struct *vma)
{
	unsigned long phys = 0;
	struct dsp_haptic_t *dsp_haptic = NULL;
	int ret = 0;
	uint32_t map_size = 0;

	hwlog_info("%s enter", __func__);
	if (!filp || !vma || !filp->private_data)
		return -EPERM;
	dsp_haptic = (struct dsp_haptic_t *)filp->private_data;

	vma->vm_page_prot = pgprot_writecombine(PAGE_SHARED);
	phys = get_haptic_share_buf_phyaddr();
	map_size = get_haptic_share_buf_size();
	if ((vma->vm_end - vma->vm_start) != map_size) {
		hwlog_err("%s mmap size error", __func__);
		return -ENOMEM;
	}
	dsp_haptic->virt_map = get_haptic_share_buf_virtaddr();
	if (!dsp_haptic->virt_map) {
		hwlog_err("%s get virt buffer failed", __func__);
		return -ENOMEM;
	}
	dsp_haptic->shared_prv_data =
		(struct haptic_shared_prv_data_t *)(dsp_haptic->virt_map + HAPTIC_SHARED_PRIVATE_DATA_START);
	ret = remap_pfn_range(vma, vma->vm_start, (phys >> PAGE_SHIFT), (vma->vm_end - vma->vm_start), vma->vm_page_prot);
	if (ret) {
		hwlog_err("Error mmap failed");
		return ret;
	}
	hwlog_info("%s succ, mmap size = %u", __func__, map_size);
	dsp_haptic->haptic_re0 = haptic_get_r0_data(dsp_haptic->pa_haptic[0]);
	return ret;
}

static const struct file_operations dsp_haptic_ctrl_fops = {
	.owner          = THIS_MODULE,
	.open           = dsp_haptic_ctrl_open,
	.release        = dsp_haptic_ctrl_release,
	.read           = dsp_haptic_ctrl_read,
	.write          = dsp_haptic_ctrl_write,
	.unlocked_ioctl = dsp_haptic_ctrl_ioctl,
	.mmap           = dsp_haptic_ctrl_mmap,
};

static struct miscdevice dsp_haptic_ctrl_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name  = "haptics",
	.fops  = &dsp_haptic_ctrl_fops,
};

static void dsp_haptic_parse_dts_para(struct platform_device *pdev, struct dsp_haptic_t *dsp_haptic_data)
{
	int ret;
	uint32_t f0_compensation = 0;
	uint32_t uefi_f0 = 0;
	struct device_node *node = pdev->dev.of_node;

	if (!node) {
		hwlog_err("%s get node fail", __func__);
		return;
	}
	ret = of_property_read_u32(pdev->dev.of_node, "uefi_f0", &uefi_f0);
	if (ret != 0)
		hwlog_info("uefi_f0 is not found");
	ret = of_property_read_u32(pdev->dev.of_node, "f0_compensation", &dsp_haptic_data->f0_compensation);
	if (ret != 0) {
		dsp_haptic_data->f0_compensation = 0;
		hwlog_info("uefi_f0 is not need compensate");
	}
	
	if (uefi_f0 != 0)
		dsp_haptic_data->haptic_uefi_f0 = uefi_f0 + dsp_haptic_data->f0_compensation;
	else
		dsp_haptic_data->haptic_uefi_f0 = uefi_f0;
	hwlog_info("%s: f0 from uefi = %u\n", __func__, dsp_haptic_data->haptic_uefi_f0);
}

static int dsp_haptic_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct dsp_haptic_t *dsp_haptic_data = NULL;

	hwlog_info("%s", __func__);
	if (pdev == NULL) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	dsp_haptic_data = kzalloc(sizeof(struct dsp_haptic_t), GFP_KERNEL);
	if (dsp_haptic_data == NULL)
		return -ENOMEM;

	platform_set_drvdata(pdev, dsp_haptic_data);
	dsp_haptic_parse_dts_para(pdev, dsp_haptic_data);
	INIT_WORK(&dsp_haptic_data->haptic_bigdata_work.bigdata_work, haptic_bigdata_report);

	/* register devices for haptic misc */
	ret = misc_register(&dsp_haptic_ctrl_miscdev);
	if (ret != 0) {
		goto free_dsp_haptic_data;
	}
	ret = mailbox_reg_msg_cb(MAILBOX_MAILCODE_HIFI_TO_ACPU_HAPTIC, haptic_recv_msg_handle_mail, NULL);
	if (ret != 0) {
		hwlog_err("%s: register miscdev failed, %d\n", __func__, ret);
		goto unregister_miscdev;
	}

	dsp_haptic_pub = dsp_haptic_data;
	return 0;

unregister_miscdev:
	misc_deregister(&dsp_haptic_ctrl_miscdev);
 
free_dsp_haptic_data:
	kfree(dsp_haptic_data);
	return ret;
}

/* register devices for haptic pa dev*/
static const struct dev_pm_ops haptic_i2c_pm_ops = {
	.suspend = haptic_i2c_suspend,
	.resume = haptic_i2c_resume,
};

static const struct i2c_device_id haptic_i2c_id[] = {
	{ "haptic_i2c", 0 },
	{},
};
MODULE_DEVICE_TABLE(i2c, haptic_i2c_id);

static const struct of_device_id haptic_i2c_match[] = {
	{ .compatible = "huawei,haptic_i2c", },
	{},
};
MODULE_DEVICE_TABLE(of, haptic_i2c_match);

static struct i2c_driver haptic_i2c_driver = {
	.driver = {
		.name = "haptic_i2c",
		.owner = THIS_MODULE,
		.pm = &haptic_i2c_pm_ops,
		.of_match_table = of_match_ptr(haptic_i2c_match),
	},
	.probe = haptic_i2c_probe,
	.remove = haptic_i2c_remove,
	.shutdown = haptic_i2c_shutdown,
	.id_table = haptic_i2c_id,
};
/* register devices for haptic pa dev*/

/* register devices for haptic misc*/
static int dsp_haptic_remove(struct platform_device *pdev)
{
	hwlog_info("%s", __func__);
	return 0;
}

static void dsp_haptic_shutdown(struct platform_device *pdev)
{
	hwlog_info("%s", __func__);
}

static const struct of_device_id dsp_haptic_match[] = {
	{ .compatible = "huawei,dsp_haptic", },
	{},
};
MODULE_DEVICE_TABLE(of, dsp_haptic_match);

static struct platform_driver dsp_haptic_misc = {
	.driver = {
		.name           = "dsp_haptic",
		.owner          = THIS_MODULE,
		.of_match_table = of_match_ptr(dsp_haptic_match),
	},
	.probe    = dsp_haptic_probe,
	.remove   = dsp_haptic_remove,
	.shutdown = dsp_haptic_shutdown,
};

static int __init dsp_haptic_init(void)
{
	int ret = 0;

	hwlog_info("%s", __func__);
	ret = platform_driver_register(&dsp_haptic_misc);
	if (ret != 0) {
		hwlog_err("%s: platform_driver_register failed, %d\n", __func__, ret);
		return ret;
	}
	ret = i2c_add_driver(&haptic_i2c_driver);
#ifdef CONFIG_AUDIO_HAPTIC_UEVENT
	audio_haptic_switch_path_cb_register(haptic_codec_callback);
#endif
	return 0;
}
module_init(dsp_haptic_init);

static void __exit dsp_haptic_exit(void)
{
}
module_exit(dsp_haptic_exit);

MODULE_DESCRIPTION("DSP Haptic Driver");
MODULE_LICENSE("GPL v2");
