/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: lpp channel source file
 * Author: shengzexuan <shengzexuan@huawei.com>
 * Create: 2024-08-14
 */
#include "lpp_channel.h"

#include <linux/err.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/spinlock.h>
#include <linux/wait.h>

#include "contexthub_boot.h"
#include "contexthub_ext_log.h"
#include "contexthub_recovery.h"
#include "contexthub_route.h"
#include "sensor_info.h"
#include <securec.h>
#include <platform_include/smart/linux/base/ap/protocol.h>

#ifdef CONFIG_DMABUF_MM
#include <linux/dmabuf/mm_dma_heap.h>
#endif
#include <linux/iommu/mm_iommu.h>

#include <dkmd_dmabuf.h>

#ifdef CONFIG_HEADER_FILE_REPLACE_EXTRACT
#include <iomcu_mem.h>
#else
#include <iomcu_ddr_map.h>
#endif

#define LPPHBIO                       0xB1
#define LPP_IOCTL_CREATE_INSTANCE    _IOW(LPPHBIO, 0x01, short)
#define LPP_IOCTL_SET_VIDEO_ID       _IOW(LPPHBIO, 0x02, short)
#define LPP_IOCTL_START_RENDER       _IOW(LPPHBIO, 0x03, short)
#define LPP_IOCTL_RENDER_NEXT        _IOW(LPPHBIO, 0x04, short)
#define LPP_IOCTL_PAUSE              _IOW(LPPHBIO, 0x05, short)
#define LPP_IOCTL_RESUME             _IOW(LPPHBIO, 0x06, short)
#define LPP_IOCTL_FLUSH              _IOW(LPPHBIO, 0x07, short)
#define LPP_IOCTL_STOP               _IOW(LPPHBIO, 0x08, short)
#define LPP_IOCTL_RESET              _IOW(LPPHBIO, 0x09, short)
#define LPP_IOCTL_SET_FD             _IOW(LPPHBIO, 0x0A, short)
#define LPP_IOCTL_GET_PARAM          _IOW(LPPHBIO, 0x0B, short)
#define LPP_IOCTL_SET_PARAM          _IOW(LPPHBIO, 0x0C, short)
#define LPP_IOCTL_SET_TARGET_FRAME   _IOW(LPPHBIO, 0x0D, short)
#define LPP_IOCTL_SET_SPEED          _IOW(LPPHBIO, 0x0E, short)
#define LPP_IOCTL_UPDATE_ANCHOR      _IOW(LPPHBIO, 0x0F, short)
#define LPP_IOCTL_BIND_OUTBUFFER     _IOW(LPPHBIO, 0x10, short)
#define LPP_IOCTL_UNBIND_OUTBUFFER   _IOW(LPPHBIO, 0x11, short)
#define LPP_IOCTL_SET_TUNNELID       _IOW(LPPHBIO, 0x12, short)
#define LPP_IOCTL_RELEASE            _IOW(LPPHBIO, 0x13, short)
#define LPP_IOCTL_GET_LATESET_PTS    _IOW(LPPHBIO, 0x14, short)

#define LPP_WAKEUP_MSEC         (50)
#define FLUSH_TIMEOUT           (200)
#define NO_NEED_UPLOAD          (-1)

static atomic_t g_instance_num = ATOMIC_INIT(0);
static lpp_instance_info g_instance_info[MAX_LPP_INSTANCE_NUM];
static enum lpp_state g_instance_state[MAX_LPP_INSTANCE_NUM];
static DECLARE_WAIT_QUEUE_HEAD(sensorhub_flush_back_waitq);
static struct mutex g_lpp_ioctl_lock[MAX_LPP_INSTANCE_NUM];
static uint32_t g_sensorhub_flush_back_signal = 0;

static struct wakeup_source *lpp_wl;
typedef struct {
	spinlock_t lock;
	struct list_head head;
} lpp_output_buffer_list;

static lpp_output_buffer_list g_lpp_total_output_buffer;

static const lpp_ioctl_cmd_map lpp_ioctl_cmd_map_tab[] = {
	{ LPP_IOCTL_CREATE_INSTANCE, SUB_CMD_LPP_CREATE_INSTANCE },
	{ LPP_IOCTL_SET_VIDEO_ID, SUB_CMD_LPP_SET_VIDEO_ID },
	{ LPP_IOCTL_START_RENDER, SUB_CMD_LPP_START_RENDER },
	{ LPP_IOCTL_RENDER_NEXT, SUB_CMD_LPP_RENDER_NEXT },
	{ LPP_IOCTL_PAUSE, SUB_CMD_LPP_PAUSE },
	{ LPP_IOCTL_RESUME, SUB_CMD_LPP_RESUME },
	{ LPP_IOCTL_FLUSH, SUB_CMD_LPP_FLUSH },
	{ LPP_IOCTL_STOP, SUB_CMD_LPP_STOP },
	{ LPP_IOCTL_RESET, SUB_CMD_LPP_RESET },
	{ LPP_IOCTL_SET_FD, SUB_CMD_LPP_SET_FD },
	{ LPP_IOCTL_GET_PARAM, SUB_CMD_LPP_GET_PARAM },
	{ LPP_IOCTL_SET_PARAM, SUB_CMD_LPP_SET_PARAM },
	{ LPP_IOCTL_SET_TARGET_FRAME, SUB_CMD_LPP_SET_TARGET_FRAME },
	{ LPP_IOCTL_SET_SPEED, SUB_CMD_LPP_SET_SPEED },
	{ LPP_IOCTL_UPDATE_ANCHOR, SUB_CMD_LPP_UPDATE_ANCHOR },
	{ LPP_IOCTL_BIND_OUTBUFFER, SUB_CMD_LPP_BIND_OUTBUFFER },
	{ LPP_IOCTL_UNBIND_OUTBUFFER, SUB_CMD_LPP_UNBIND_OUTBUFFER },
	{ LPP_IOCTL_SET_TUNNELID, SUB_CMD_LPP_SET_TUNNELID },
	{ LPP_IOCTL_RELEASE, SUB_CMD_LPP_RELEASE },
	{ LPP_IOCTL_GET_LATESET_PTS, SUB_CMD_LPP_GET_LATEST_PTS },
};

static const lpp_state_cmd_map lpp_state_control_tab[] = {
	{ LPP_IDLE, SUB_CMD_LPP_CREATE_INSTANCE },
	{ LPP_IDLE, SUB_CMD_LPP_GET_LATEST_PTS },

	{ LPP_INITIALIZED, SUB_CMD_LPP_SET_VIDEO_ID },
	{ LPP_INITIALIZED, SUB_CMD_LPP_SET_FD },
	{ LPP_INITIALIZED, SUB_CMD_LPP_BIND_OUTBUFFER },
	{ LPP_INITIALIZED, SUB_CMD_LPP_SET_TUNNELID },
	{ LPP_INITIALIZED, SUB_CMD_LPP_RELEASE },
	{ LPP_INITIALIZED, SUB_CMD_LPP_GET_LATEST_PTS },

	{ LPP_PREPARED, SUB_CMD_LPP_START_RENDER },
	{ LPP_PREPARED, SUB_CMD_LPP_RESET },
	{ LPP_PREPARED, SUB_CMD_LPP_RELEASE },
	{ LPP_PREPARED, SUB_CMD_LPP_UNBIND_OUTBUFFER },
	{ LPP_PREPARED, SUB_CMD_LPP_RENDER_NEXT },
	{ LPP_PREPARED, SUB_CMD_LPP_GET_PARAM },
	{ LPP_PREPARED, SUB_CMD_LPP_SET_PARAM },
	{ LPP_PREPARED, SUB_CMD_LPP_GET_LATEST_PTS },

	{ LPP_PLAYING, SUB_CMD_LPP_PAUSE },
	{ LPP_PLAYING, SUB_CMD_LPP_STOP },
	{ LPP_PLAYING, SUB_CMD_LPP_SET_SPEED },
	{ LPP_PLAYING, SUB_CMD_LPP_SET_TARGET_FRAME },
	{ LPP_PLAYING, SUB_CMD_LPP_UPDATE_ANCHOR },
	{ LPP_PLAYING, SUB_CMD_LPP_UNBIND_OUTBUFFER },
	{ LPP_PLAYING, SUB_CMD_LPP_BIND_OUTBUFFER },
	{ LPP_PLAYING, SUB_CMD_LPP_SET_TUNNELID },
	{ LPP_PLAYING, SUB_CMD_LPP_RESET },
	{ LPP_PLAYING, SUB_CMD_LPP_RELEASE },
	{ LPP_PLAYING, SUB_CMD_LPP_GET_PARAM },
	{ LPP_PLAYING, SUB_CMD_LPP_SET_PARAM },
	{ LPP_PLAYING, SUB_CMD_LPP_GET_LATEST_PTS },

	{ LPP_PAUSED, SUB_CMD_LPP_START_RENDER },
	{ LPP_PAUSED, SUB_CMD_LPP_RESUME },
	{ LPP_PAUSED, SUB_CMD_LPP_STOP },
	{ LPP_PAUSED, SUB_CMD_LPP_SET_SPEED },
	{ LPP_PAUSED, SUB_CMD_LPP_SET_TARGET_FRAME },
	{ LPP_PAUSED, SUB_CMD_LPP_UNBIND_OUTBUFFER },
	{ LPP_PAUSED, SUB_CMD_LPP_BIND_OUTBUFFER },
	{ LPP_PAUSED, SUB_CMD_LPP_RENDER_NEXT },
	{ LPP_PAUSED, SUB_CMD_LPP_RESET },
	{ LPP_PAUSED, SUB_CMD_LPP_RELEASE },
	{ LPP_PAUSED, SUB_CMD_LPP_GET_PARAM },
	{ LPP_PAUSED, SUB_CMD_LPP_SET_PARAM },
	{ LPP_PAUSED, SUB_CMD_LPP_FLUSH },
	{ LPP_PAUSED, SUB_CMD_LPP_GET_LATEST_PTS },

	{ LPP_STOPPED, SUB_CMD_LPP_RESET },
	{ LPP_STOPPED, SUB_CMD_LPP_RELEASE },
	{ LPP_STOPPED, SUB_CMD_LPP_GET_PARAM },
	{ LPP_STOPPED, SUB_CMD_LPP_SET_PARAM },
	{ LPP_STOPPED, SUB_CMD_LPP_GET_LATEST_PTS },
};

static int send_lpp_cmd(const void *argp, size_t input_len, enum obj_sub_cmd subcmd, uint32_t instance_num)
{
	struct write_info pkg_ap;
	struct read_info pkg_mcu;
	pkt_parameter_req_lpp_t cpkt;
	struct pkt_header *hd = (struct pkt_header *)&cpkt;
	int ret;

	hwlog_info("%s len = %d\n", __func__, input_len);
	if (input_len > sizeof(cpkt.para) - sizeof(int32_t)) {
		hwlog_err("%s input_len too long\n", __func__);
		return -EFAULT;
	}

	(void)memset_s(&pkg_ap, sizeof(pkg_ap), 0, sizeof(pkg_ap));
	(void)memset_s(&pkg_mcu, sizeof(pkg_mcu), 0, sizeof(pkg_mcu));
	(void)memset_s(&cpkt, sizeof(cpkt), 0, sizeof(cpkt));

	pkg_ap.tag = TAG_LPP;
	pkg_ap.cmd = CMD_CMN_CONFIG_REQ;
	cpkt.subcmd = subcmd;
	pkg_ap.wr_buf = &hd[1];
	pkg_ap.wr_len = SUBCMD_LEN + input_len + sizeof(int32_t);

	ret = memcpy_s(cpkt.para, sizeof(cpkt.para), &g_instance_info[instance_num].instance_id, sizeof(int32_t));
	if (ret) {
		hwlog_err("%s memcpy_s instance_num fail ret:%d\n", __func__, ret);
		return -EFAULT;
	}

	if (input_len > 0) {
		ret = memcpy_s((char *)cpkt.para + sizeof(int32_t), sizeof(cpkt.para) - sizeof(int32_t), argp, input_len);
		if (ret) {
			hwlog_err("%s memcpy_s argp fail ret:%d\n", __func__, ret);
			return -EFAULT;
		}
	}

	ret = write_customize_cmd(&pkg_ap, &pkg_mcu, true);
	if (ret != 0) {
		hwlog_err("%s failed ret = %d\n", __func__, ret);
		return -ENOTTY;
	}

	if (pkg_mcu.errno != 0) {
		hwlog_err("%s subcmd:0x%x fail, errno = 0x%x\n",
			__func__, subcmd, pkg_mcu.errno);
		return pkg_mcu.errno;
	}

	if (subcmd == SUB_CMD_LPP_GET_LATEST_PTS) {
		g_instance_info[instance_num].current_pts = *(uint64_t *)pkg_mcu.data;
		hwlog_info("%s get latest pts:0x%x\n", __func__, g_instance_info[instance_num].current_pts);
	}
	hwlog_info("%s subcmd:0x%x is success\n", __func__, subcmd);

	return 0;
}

static ssize_t upload_lpp_data(char *data, ssize_t len)
{
	return inputhub_route_write(ROUTE_LPP_PORT, data, len);
}

static void lpp_upload_state(enum lpp_upload_event_type event, uint32_t instance_num, int32_t err_code)
{
	static lpp_upload_pkg upload_pkg;
	if (instance_num >= MAX_LPP_INSTANCE_NUM) {
		upload_pkg.instance_id = instance_num;
	} else {
		upload_pkg.instance_id = g_instance_info[instance_num].instance_id;
	}
	upload_pkg.event_type = event;
	upload_pkg.error_code = err_code;
	__pm_wakeup_event(lpp_wl, LPP_WAKEUP_MSEC);
	upload_lpp_data((char *)&upload_pkg, sizeof(upload_pkg));
	hwlog_info("%s event:%d instance:%d err_code:0x%x\n", __func__, event, upload_pkg.instance_id, err_code);
}

static int state_machine_control(enum obj_sub_cmd cmd, uint32_t instance_num)
{
	for (int i = 0; i < ARRAY_SIZE(lpp_state_control_tab); i++) {
		if (lpp_state_control_tab[i].state == g_instance_state[instance_num] &&
			lpp_state_control_tab[i].cmd == cmd) {
			hwlog_info("State %d → Executing cmd 0x%x\n", g_instance_state[instance_num], cmd);
			return 0;
		}
	}
	if (cmd == SUB_CMD_LPP_UPDATE_ANCHOR) {
		hwlog_info("update anchor with error state, pass\n");
		return -1;
	}
	hwlog_err("%s cmd not match lpp state! state: %d cmd: 0x%x\n", __func__, g_instance_state[instance_num], cmd);
	lpp_upload_state(ON_ERROR_EVENT, instance_num, LPPDRV_STATE_MACH_ERR);
	return -1;
}

static int state_machine_change(enum obj_sub_cmd cmd, uint32_t instance_num)
{
	hwlog_info("%s lpp current state:%d\n", __func__, g_instance_state[instance_num]);
	switch (cmd) {
	case SUB_CMD_LPP_CREATE_INSTANCE:
		g_instance_state[instance_num] = LPP_INITIALIZED;
		break;
	case SUB_CMD_LPP_UNBIND_OUTBUFFER:
		if (g_instance_state[instance_num] == LPP_PREPARED)
			g_instance_state[instance_num] = LPP_INITIALIZED;
		break;
	case SUB_CMD_LPP_SET_VIDEO_ID:
	case SUB_CMD_LPP_BIND_OUTBUFFER:
	case SUB_CMD_LPP_SET_TUNNELID:
		if (g_instance_state[instance_num] == LPP_INITIALIZED
			&& g_instance_info[instance_num].channel_id != 0
			&& g_instance_info[instance_num].tunnel_id != 0
			&& g_instance_info[instance_num].output_buffer_to_sensorhub.buf_count != 0)
			g_instance_state[instance_num] = LPP_PREPARED;
		break;
	case SUB_CMD_LPP_START_RENDER:
	case SUB_CMD_LPP_RESUME:
		g_instance_state[instance_num] = LPP_PLAYING;
		break;
	case SUB_CMD_LPP_PAUSE:
		g_instance_state[instance_num] = LPP_PAUSED;
		break;
	case SUB_CMD_LPP_STOP:
		g_instance_state[instance_num] = LPP_STOPPED;
		break;
	case SUB_CMD_LPP_RESET:
		g_instance_state[instance_num] = LPP_INITIALIZED;
		break;
	case SUB_CMD_LPP_RELEASE:
		g_instance_state[instance_num] = LPP_IDLE;
		break;
	default:
		hwlog_info("%s lpp state no need change, cmd:0x%x\n", __func__, cmd);
		return 0;
	}

	hwlog_info("%s lpp state change to %d succ, cmd:0x%x\n", __func__, g_instance_state[instance_num], cmd);
	return 0;
}

static void lpp_create_instance(void *argp, uint32_t instance_num)
{
	atomic_inc(&g_instance_num);
	g_instance_info[instance_num].instance_id = *(int32_t *)argp;
	hwlog_info("%s succ! instance_id: 0x%x g_instance_num: %d\n", __func__,
				g_instance_info[instance_num].instance_id, atomic_read(&g_instance_num));
}

static void lpp_release_instance(uint32_t instance_num)
{
	if (atomic_read(&g_instance_num) > 0)
		atomic_dec(&g_instance_num);
	if (g_instance_info[instance_num].rs_buf_info.buf != NULL)
		dma_buf_put(g_instance_info[instance_num].rs_buf_info.buf);
	(void)memset_s(&g_instance_info[instance_num], sizeof(lpp_instance_info), 0, sizeof(lpp_instance_info));
	hwlog_info("%s succ! instance_num: %d g_instance_num: %d\n", __func__, instance_num, atomic_read(&g_instance_num));
}

static int output_buffer_list_add(uint32_t fd, uint32_t sequence_id, uint64_t iova_addr)
{
	int ret = 0;
	unsigned long flags = 0;
	struct dma_buf *buf = NULL;
	lpp_output_buffer_node *buffer_node = NULL, *n = NULL;

	spin_lock_irqsave(&g_lpp_total_output_buffer.lock, flags);
	list_for_each_entry_safe(buffer_node, n, &g_lpp_total_output_buffer.head, entry) {
		if (fd == buffer_node->lpp_dma_buf_fd.fd && sequence_id == buffer_node->lpp_dma_buf_fd.sequence_id && 
			iova_addr == buffer_node->lpp_dma_buf_fd.iova_addr) {
			hwlog_warn("fd:%d seqid:%d has already registed in!\n", fd, sequence_id);
			return -1;
		}
	}

	buffer_node = kzalloc(sizeof(lpp_output_buffer_node), GFP_KERNEL);
	if (!buffer_node)
		return -1;
	buffer_node->lpp_dma_buf_fd.fd = fd;
	buf = dma_buf_get(fd);
	if (IS_ERR_OR_NULL(buf)) {
		hwlog_err("%s: get dmabuf fail!\n", __func__);
		kfree(buffer_node);
		spin_unlock_irqrestore(&g_lpp_total_output_buffer.lock, flags);
		return -1;
	}
	buffer_node->lpp_dma_buf_fd.buf = buf;
	buffer_node->lpp_dma_buf_fd.sequence_id = sequence_id;
	buffer_node->lpp_dma_buf_fd.iova_addr = iova_addr;
	list_add(&buffer_node->entry, &g_lpp_total_output_buffer.head);
	spin_unlock_irqrestore(&g_lpp_total_output_buffer.lock, flags);
	hwlog_info("%s succ! fd:%d sequence_id:%d iova_addr:0x%x!\n", __func__, fd, sequence_id, iova_addr);

	return ret;
}

static int output_buffer_list_del(uint32_t fd, uint32_t sequence_id, uint64_t iova_addr)
{
	int ret = -1;
	unsigned long flags = 0;
	lpp_output_buffer_node *buffer_node = NULL, *n = NULL;

	spin_lock_irqsave(&g_lpp_total_output_buffer.lock, flags);
	list_for_each_entry_safe(buffer_node, n, &g_lpp_total_output_buffer.head, entry) {
		if (fd == buffer_node->lpp_dma_buf_fd.fd && sequence_id == buffer_node->lpp_dma_buf_fd.sequence_id && 
			iova_addr == buffer_node->lpp_dma_buf_fd.iova_addr) {
			hwlog_info("fd:%d sequence_id:%d iova_addr:0x%x found in output_buffer_list!\n", fd, sequence_id, iova_addr);
			dma_buf_put(buffer_node->lpp_dma_buf_fd.buf);
			list_del(&buffer_node->entry);
			kfree(buffer_node);
			buffer_node = NULL;
			ret = 0;
			break;
		}
	}
	spin_unlock_irqrestore(&g_lpp_total_output_buffer.lock, flags);

	return ret;
}

static void lpp_bind_vdec_output(void *argp, uint32_t instance_num, uint32_t package_len_hdi)
{
	uint64_t iova_addr;
	lpp_vdec_output_buffer_hal *output_buffer = NULL;

	if (package_len_hdi < offset(hdi_ioctl_package, data)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	uint32_t hdi_pkg_data_len = package_len_hdi - offset(hdi_ioctl_package, data);
	output_buffer = kzalloc(sizeof(lpp_vdec_output_buffer_hal), GFP_KERNEL);
	if (output_buffer == NULL) {
		hwlog_err("%s kzalloc failed\n", __func__);
		return;
	}
	if (memcpy_s(output_buffer, sizeof(lpp_vdec_output_buffer_hal), argp, hdi_pkg_data_len)) {
		hwlog_err("%s copy vdec_output fail!\n", __func__);
		goto do_free;
	}
	g_instance_info[instance_num].output_buffer_to_sensorhub.buf_count = output_buffer->buf_count;
	hwlog_info("%s output_buffer buf_count %d\n", __func__, output_buffer->buf_count);
	vdec_yuv_buffer_hal_t *yuv_buffer_hal = output_buffer->yuv_buffer_list;
	vdec_yuv_buffer_t *yuv_buffer = g_instance_info[instance_num].output_buffer_to_sensorhub.yuv_buffer_list;
	for (int i = 0; i < min(output_buffer->buf_count, MAX_VDEC_OUTPUT_BUFF_NUM); i++) {
		if (dpu_dev_map_dmabuf_by_sharefd(yuv_buffer_hal->fd, 0, &iova_addr) != 0) {
			hwlog_err("%s gr_dev_map_dmabuf_by_sharefd_intf fail! num:%d\n", __func__, i);
			goto do_free;
		}
		yuv_buffer->fd = yuv_buffer_hal->fd;
		yuv_buffer->sequence_id = yuv_buffer_hal->sequence_id;
		yuv_buffer->buffer_id = yuv_buffer_hal->buffer_id;
		yuv_buffer->iova_addr = iova_addr;
		if (output_buffer_list_add(yuv_buffer_hal->fd, yuv_buffer_hal->sequence_id, iova_addr))
			goto do_free;
		hwlog_info("%s output_buffer fd %d, num: %d\n", __func__, yuv_buffer->fd, i);
		hwlog_info("%s output_buffer sequence_id %d, num: %d\n", __func__, yuv_buffer->sequence_id, i);
		hwlog_info("%s output_buffer buffer_id %d, num: %d\n", __func__, yuv_buffer->buffer_id, i);
		hwlog_info("%s output_buffer iova_addr 0x%x, num: %d\n", __func__, yuv_buffer->iova_addr, i);
		yuv_buffer_hal++;
		yuv_buffer++;
	}
	hwlog_info("%s succ!\n", __func__);

do_free:
	kfree(output_buffer);
	output_buffer = NULL;
	return;
}

static void lpp_set_channel_id(void* argp, uint32_t instance_num, uint32_t package_len_hdi)
{
	if (package_len_hdi < offset(hdi_ioctl_package, data) + sizeof(int32_t)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	g_instance_info[instance_num].channel_id = *(int32_t *)argp;
	hwlog_info("%s succ! channel_id: %d\n", __func__, g_instance_info[instance_num].channel_id);
}

static void lpp_set_speed(void *argp, uint32_t instance_num, uint32_t package_len_hdi)
{
	if (package_len_hdi < offset(hdi_ioctl_package, data) + sizeof(uint32_t)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	g_instance_info[instance_num].playback_speed = *(uint32_t *)argp;
	hwlog_info("%s succ! speed: %u\n", __func__, g_instance_info[instance_num].playback_speed);
}

static void lpp_set_tunnel_id(void *argp, uint32_t instance_num, uint32_t package_len_hdi)
{
	if (package_len_hdi < offset(hdi_ioctl_package, data) + sizeof(uint64_t)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	g_instance_info[instance_num].tunnel_id = *(uint64_t *)argp;
	hwlog_info("%s succ! tunnel_id: 0x%llx\n", __func__, g_instance_info[instance_num].tunnel_id);
}

static void lpp_copy_time_anchor(void *argp, lpp_time_anchor *time_anchor, uint32_t package_len_hdi)
{
	if (package_len_hdi < offset(hdi_ioctl_package, data) + sizeof(lpp_time_anchor)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	if (memcpy_s(time_anchor, sizeof(lpp_time_anchor), argp, sizeof(lpp_time_anchor))) {
		hwlog_err("%s copy time_anchor fail!\n", __func__);
		return;
	}
	hwlog_info("%s succ! pts: %lu, clk: %lu\n", __func__, time_anchor->anchor_pts, time_anchor->anchor_clk);
}

static void lpp_copy_seek_target_info(void *argp, lpp_seek_target_info *seek_target_info, uint32_t package_len_hdi)
{
	if (package_len_hdi < offset(hdi_ioctl_package, data) + sizeof(lpp_seek_target_info)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	if (memcpy_s(seek_target_info, sizeof(lpp_seek_target_info), argp, sizeof(lpp_seek_target_info))) {
		hwlog_err("%s copy seek_target_info fail!\n", __func__);
		return;
	}
	hwlog_info("%s succ! pts: %lu, timeout: %u\n", __func__, seek_target_info->target_pts, seek_target_info->timeout_ms);
}

static void lpp_get_latest_pts(const void __user *argp, uint32_t instance_num, uint32_t package_len_hdi)
{
	if (package_len_hdi < offset(hdi_ioctl_package, data) + sizeof(int64_t)) {
		hwlog_err("%s package_len_hdi:%u invalid\n", __func__, package_len_hdi);
		return;
	}
	hdi_ioctl_package *package = (hdi_ioctl_package *)argp;
	if (copy_to_user(package->data, &g_instance_info[instance_num].current_pts, sizeof(int64_t))) {
		hwlog_err("%s copy_to_user fail or arg is NULL\n", __func__);
	}
}

static int lpp_wait_flush_back(void)
{
	unsigned long remain_wait_time = 0;
	remain_wait_time = wait_event_timeout(sensorhub_flush_back_waitq,
				g_sensorhub_flush_back_signal != 0, msecs_to_jiffies(FLUSH_TIMEOUT));
	g_sensorhub_flush_back_signal = 0;
	if (remain_wait_time <= 0) {
		hwlog_err("wait for sensorhub_flush_back timeout\n");
		return LPPDRV_FLUSH_TIMEOUT;
	}

	return 0;
}

static uint32_t get_instance_num(const void __user *argp, hdi_ioctl_package *package, unsigned int cmd)
{
	int32_t instance_id_hdi;

	if (copy_from_user(package, argp, sizeof(uint64_t))) {
		hwlog_err("%s copy from user fail!\n", __func__);
		return MAX_LPP_INSTANCE_NUM;
	}
	instance_id_hdi = package->instance_id;
	hwlog_info("%s instance_id_hdi:0x%x\n", __func__, instance_id_hdi);
	for (uint32_t i = 0; i < MAX_LPP_INSTANCE_NUM; i++) {
		hwlog_info("%s g_instance_info[%d].instance_id:0x%x\n", __func__, i, g_instance_info[i].instance_id);
		if (g_instance_info[i].instance_id == instance_id_hdi ||
			(cmd == LPP_IOCTL_CREATE_INSTANCE && g_instance_info[i].instance_id == 0))
			return i;
	}
	hwlog_err("%s instance_num is over limit!\n", __func__);
	lpp_upload_state(ON_ERROR_EVENT, instance_id_hdi, LPPDRV_INSTANCE_EXCEED_LIMIT);
	return MAX_LPP_INSTANCE_NUM;
}

static int execute_lpp_ioctl_cmd(unsigned int cmd, const void __user *argp)
{
	int i;
	int ret = 0;
	int loop_count = ARRAY_SIZE(lpp_ioctl_cmd_map_tab);

	for (i = 0 ; i < loop_count; i++) {
		if (lpp_ioctl_cmd_map_tab[i].lpp_ioctl_app_cmd == cmd)
			break;
	}
	if (i == loop_count) {
		hwlog_err("%s unknown cmd %u\n", __func__, cmd);
		return -EINVAL;
	}

	hdi_ioctl_package package_hdi = {0};

	uint32_t instance_num = get_instance_num(argp, &package_hdi, cmd);
	if (instance_num >= MAX_LPP_INSTANCE_NUM) {
		hwlog_err("%s instance_id invalid\n", __func__);
		return -EINVAL;
	}
	hwlog_info("%s instance_num:%d\n", __func__, instance_num);

	if (package_hdi.package_len < offset(hdi_ioctl_package, data) || package_hdi.package_len > MAX_PKG_HDI_LEN) {
		hwlog_err("%s hdi ioctl package len invalid! len:0x%x\n", __func__, package_hdi.package_len);
		return -EINVAL;
	}
	uint32_t package_len_hdi = package_hdi.package_len;
	hwlog_info("%s package_len_hdi:0x%x\n", __func__, package_len_hdi);
	hdi_ioctl_package *package = kzalloc(package_len_hdi, GFP_KERNEL);
	if (package == NULL) {
		hwlog_err("%s: kzalloc hdi_ioctl_package fail!\n", __func__);
		return -ENOMEM;
	}
	if (copy_from_user(package, argp, package_len_hdi)) {
		hwlog_err("%s copy from user fail!\n", __func__);
		kfree(package);
		return -EFAULT;
	}
	hwlog_info("%s instance_id:0x%x, package_len:%u\n", __func__, package->instance_id, package->package_len);
	mutex_lock(&g_lpp_ioctl_lock[instance_num]);
	ret = state_machine_control(lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
	if (ret) {
		if (lpp_ioctl_cmd_map_tab[i].cmd == SUB_CMD_LPP_UPDATE_ANCHOR) {
			ret = 0;
			goto out;
		} else {
			goto out;
		}
	}

	switch (lpp_ioctl_cmd_map_tab[i].cmd) {
	case SUB_CMD_LPP_CREATE_INSTANCE:
		lpp_create_instance((void *)package, instance_num);
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num].instance_id,
							sizeof(int32_t), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_RESUME:
	case SUB_CMD_LPP_START_RENDER:
	case SUB_CMD_LPP_STOP:
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num],
							sizeof(lpp_instance_info), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_BIND_OUTBUFFER:
		lpp_bind_vdec_output((void *)package->data, instance_num, package_len_hdi);
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num].output_buffer_to_sensorhub,
							sizeof(lpp_vdec_output_buffer_to_sensorhub), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_SET_VIDEO_ID:
		lpp_set_channel_id((void *)package->data, instance_num, package_len_hdi);
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num].channel_id,
							sizeof(int32_t), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_SET_SPEED:
		lpp_set_speed((void *)package->data, instance_num, package_len_hdi);
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num].playback_speed,
							sizeof(uint32_t), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_SET_FD:
		ret = send_lpp_cmd((void *)&instance_num, sizeof(int32_t), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_SET_TUNNELID:
		lpp_set_tunnel_id((void *)package->data, instance_num, package_len_hdi);
		if (g_instance_state[instance_num] == LPP_PLAYING)
			ret = send_lpp_cmd((void *)&g_instance_info[instance_num].tunnel_id,
								sizeof(uint64_t), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_UPDATE_ANCHOR:
		{
			lpp_time_anchor time_anchor;
			lpp_copy_time_anchor((void *)package->data, &time_anchor, package_len_hdi);
			ret = send_lpp_cmd((void *)&time_anchor, sizeof(lpp_time_anchor),
								lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
			break;
		}
	case SUB_CMD_LPP_SET_TARGET_FRAME:
		{
			lpp_seek_target_info seek_target_info;
			lpp_copy_seek_target_info((void *)package->data, &seek_target_info, package_len_hdi);
			ret = send_lpp_cmd((void *)&seek_target_info, sizeof(lpp_seek_target_info),
								lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
			break;
		}
	case SUB_CMD_LPP_RESET:
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num].channel_id,
							sizeof(int32_t), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_RELEASE:
		ret = send_lpp_cmd((void *)&g_instance_info[instance_num],
							sizeof(lpp_instance_info), lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		lpp_release_instance(instance_num);
		if (atomic_read(&g_instance_num) == 0)
			lpp_upload_state(ON_RELEASE, instance_num, 0);
		break;
	case SUB_CMD_LPP_FLUSH:
		ret = send_lpp_cmd(NULL, 0, lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		if (ret)
			break;
		ret = lpp_wait_flush_back();
		break;
	case SUB_CMD_LPP_GET_LATEST_PTS:
		ret = send_lpp_cmd(NULL, 0, lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		lpp_get_latest_pts(argp, instance_num, package_len_hdi);
		break;
	case SUB_CMD_LPP_UNBIND_OUTBUFFER:
	case SUB_CMD_LPP_RENDER_NEXT:
	case SUB_CMD_LPP_PAUSE:
		ret = send_lpp_cmd(NULL, 0, lpp_ioctl_cmd_map_tab[i].cmd, instance_num);
		break;
	case SUB_CMD_LPP_GET_PARAM:
	case SUB_CMD_LPP_SET_PARAM:
		break;
	default:
		hwlog_err("%s unknown sub_cmd : %u\n", __func__, cmd);
		ret = -EINVAL;
		goto out;
	}
	state_machine_change(lpp_ioctl_cmd_map_tab[i].cmd, instance_num);

out:
	kfree(package);
	package = NULL;
	mutex_unlock(&g_lpp_ioctl_lock[instance_num]);
	return ret;
}

/*
 * Description:    read /dev/lpphub, do nothing now
 * Return:         length of read data
 */
static ssize_t lpp_read(struct file *file, char __user *data, size_t count,
			loff_t *pos)
{
	hwlog_info("lpp: enter %s\n", __func__);
	return inputhub_route_read(ROUTE_LPP_PORT, data, count);
}

/*
 * Description:    write to /dev/lpphub, do nothing now
 * Return:         length of write data
 */
static ssize_t lpp_write(struct file *file, const char __user *data,
	size_t len, loff_t *ppos)
{
	hwlog_info("lpp: enter %s\n", __func__);
	return len;
}

/*
 * Description: ioctl function to /dev/lpphub, do open, do config/debug
 *              cmd to lpp
 * Return:      result of ioctrl command, 0 successed, -ENOTTY failed
 */
static long lpp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;

	switch (cmd) {
	case LPP_IOCTL_CREATE_INSTANCE:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_INIT\n", __func__);
		break;

	case LPP_IOCTL_SET_VIDEO_ID:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_SET_VIDEO_ID\n", __func__);
		break;

	case LPP_IOCTL_START_RENDER:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_START_RENDER\n", __func__);
		break;

	case LPP_IOCTL_RENDER_NEXT:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_RENDER_NEXT\n", __func__);
		break;

	case LPP_IOCTL_PAUSE:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_PAUSE\n", __func__);
		break;

	case LPP_IOCTL_RESUME:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_RESUME\n", __func__);
		break;

	case LPP_IOCTL_FLUSH:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_FLUSH\n", __func__);
		break;

	case LPP_IOCTL_STOP:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_STOP\n", __func__);
		break;

	case LPP_IOCTL_RESET:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_RESET\n", __func__);
		break;

	case LPP_IOCTL_SET_FD:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_SET_FD\n", __func__);
		break;

	case LPP_IOCTL_GET_PARAM:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_GET_PARAM\n", __func__);
		break;

	case LPP_IOCTL_SET_PARAM:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_SET_PARAM\n", __func__);
		break;

	case LPP_IOCTL_SET_TARGET_FRAME:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_SET_TARGET_FRAME\n", __func__);
		break;

	case LPP_IOCTL_SET_SPEED:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_SET_SPEED\n", __func__);
		break;

	case LPP_IOCTL_UPDATE_ANCHOR:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_UPDATE_ANCHOR\n", __func__);
		break;

	case LPP_IOCTL_BIND_OUTBUFFER:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_BIND_OUTBUFFER\n", __func__);
		break;

	case LPP_IOCTL_UNBIND_OUTBUFFER:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_UNBIND_OUTBUFFER\n", __func__);
		break;

	case LPP_IOCTL_SET_TUNNELID:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_SET_TUNNELID\n", __func__);
		break;

	case LPP_IOCTL_RELEASE:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_RELEASE\n", __func__);
		break;

	case LPP_IOCTL_GET_LATESET_PTS:
		hwlog_info("lpp: %s  cmd: LPP_IOCTL_GET_LATESET_PTS\n", __func__);
		break;

	default:
		hwlog_err("lpp: %s unknown cmd : %u\n", __func__, cmd);
		return -EINVAL;
	}

	return execute_lpp_ioctl_cmd(cmd, arg);
}

static int lpp_err_clean(bool is_sensorhub_crash)
{
	int ret = 0;
	unsigned long flags = 0;
	lpp_output_buffer_node *buffer_node = NULL, *n = NULL;

	spin_lock_irqsave(&g_lpp_total_output_buffer.lock, flags);
	list_for_each_entry_safe(buffer_node, n, &g_lpp_total_output_buffer.head, entry) {
		list_del(&buffer_node->entry);
		kfree(buffer_node);
		buffer_node = NULL;
	}
	spin_unlock_irqrestore(&g_lpp_total_output_buffer.lock, flags);

	for (int i = 0; i < MAX_LPP_INSTANCE_NUM; i++) {
		if (g_instance_info[i].instance_id != 0) {
			if (!is_sensorhub_crash) {
				ret = send_lpp_cmd((void *)&g_instance_info[i].channel_id,
								sizeof(int32_t), SUB_CMD_LPP_RELEASE, i);
			} else {
				lpp_upload_state(ON_ERROR_EVENT, i, LPPDRV_SHB_CRASH);
			}
			lpp_release_instance(i);
			g_instance_state[i] = LPP_IDLE;
		}
	}
	atomic_set(&g_instance_num, 0);

	return ret;
}

/* open to /dev/lpphub, do nothing now */
static int lpp_open(struct inode *inode, struct file *file)
{
	hwlog_info("lpp: enter %s\n", __func__);
	return 0;
}

/* release to /dev/lpphub, do nothing now */
static int lpp_release(struct inode *inode, struct file *file)
{
	hwlog_info("lpp: enter %s\n", __func__);
	lpp_err_clean(false);
	return 0;
}

static unsigned long set_rs_addr_by_tunnleid(unsigned long offset, unsigned long size)
{
	uint32_t input_id = (uint32_t)offset;
	int i;
	for (i = 0; i < MAX_LPP_INSTANCE_NUM; i++) {
		uint32_t surface_id = (uint32_t)g_instance_info[i].tunnel_id;
		if (input_id == surface_id)
			break;
	}
	if (i == MAX_LPP_INSTANCE_NUM) {
		hwlog_err("%s surface id can not match!\n", __func__);
		return 0;
	}
	return DDR_LPP_RS_RB_BASE_AP + i * size;
}

static int lpp_mmap(struct file *file, struct vm_area_struct *vma)
{
	hwlog_info("lpp: enter %s\n", __func__);
	int ret;

	if (file == NULL || vma == NULL) {
		hwlog_err("%s param is error\n", __func__);
		return -EINVAL;
	}

	unsigned long size;
	unsigned long page = 0;

	if (file == NULL) {
		hwlog_err("lpp_mmap file is null\n");
		return -EINVAL;
	}

	if (vma->vm_start == 0) {
		hwlog_err("[%s]:line[%d] Failed : vm_start.0x%lx\n", __func__, __LINE__, vma->vm_start);
		return -EINVAL;
	}

	hwlog_info("[%s]:line[%d] vma->vm_pgoff 0x%lx\n", __func__, __LINE__, vma->vm_pgoff);
	size = DDR_LPP_RS_RB_SIZE / MAX_LPP_INSTANCE_NUM;
	page = set_rs_addr_by_tunnleid(vma->vm_pgoff, size);
	if (page == 0) {
		hwlog_err("invalid tunnelid\n");
		return -EINVAL;
	}
	hwlog_info("[%s]:line[%d] enter, page:0x%x vm_start.0x%lx, size.0x%lx, vm_end.0x%lx\n",
	       __func__, __LINE__, page, vma->vm_start, size, vma->vm_end);

	vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
	ret = remap_pfn_range(vma, vma->vm_start, (page >> PAGE_SHIFT), size, vma->vm_page_prot);
	if (ret != 0) {
		hwlog_err("[%s]:line[%d] remap_pfn_range failed, ret.%d\n", __func__, __LINE__, ret);
		return -EINVAL;
	}

	return ret;
}

static int lpp_recovery_notify(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	/* prevent access the emmc now: */
	hwlog_info("%s (%lu) +\n", __func__, foo);
	switch (foo) {
	case IOM3_RECOVERY_IDLE:
		break;
	case IOM3_RECOVERY_START:
		lpp_err_clean(true);
	case IOM3_RECOVERY_MINISYS:
	case IOM3_RECOVERY_3RD_DOING:
	case IOM3_RECOVERY_FAILED:
		break;
	case IOM3_RECOVERY_DOING:
		break;
	default:
		hwlog_err("%s -unknow state %ld\n", __func__, foo);
		break;
	}
	hwlog_info("%s -\n", __func__);
	return 0;
}

static struct notifier_block g_lpp_recovery_notify = {
	.notifier_call = lpp_recovery_notify,
	.priority = -1,
};

/* file_operations to lpp */
static const struct file_operations lpp_fops = {
	.owner = THIS_MODULE,
	.llseek = no_llseek,
	.read = lpp_read,
	.write = lpp_write,
	.unlocked_ioctl = lpp_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = lpp_ioctl,
#endif
	.open = lpp_open,
	.release = lpp_release,
	.mmap = lpp_mmap,
};

static struct miscdevice lpp_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "lpphub",
	.fops = &lpp_fops,
};

static int lpp_record_data_from_mcu(pkt_lpp_mcu_data_t *data, lpp_upload_pkg *upload_pkg)
{
	lpp_mcu_data_head *mcu_data = &data->head;
	lpp_upload_pkg *mcu_pkg = (lpp_upload_pkg *)data->value;

	if (memcpy_s(upload_pkg, sizeof(lpp_upload_pkg),
				mcu_pkg, sizeof(lpp_upload_pkg))) {
		hwlog_err("%s memcpy_s fail!\n", __func__);
	}
	hwlog_info("%s upload_pkg instance_id %d\n", __func__, upload_pkg->instance_id);
	hwlog_info("%s upload_pkg event_type %d\n", __func__, upload_pkg->event_type);
	hwlog_info("%s upload_pkg error_code 0x%x\n", __func__, upload_pkg->error_code);
	hwlog_info("%s upload_pkg err_msg %s\n", __func__, upload_pkg->err_msg);
	hwlog_info("%s upload_pkg target_pts %d\n", __func__, upload_pkg->target_pts);
	hwlog_info("%s upload_pkg is_timeout %d\n", __func__, upload_pkg->is_timeout);
	hwlog_info("%s upload_pkg info_code %d\n", __func__, upload_pkg->info_code);
	hwlog_info("%s upload_pkg info_msg %s\n", __func__, upload_pkg->info_msg);
	hwlog_info("%s succ!\n", __func__);
	return 0;
}

static int lpp_release_output_buffer(pkt_lpp_mcu_data_t *data)
{
	int ret = 0;

	lpp_mcu_data_head *mcu_data = &data->head;
	lpp_upload_pkg *mcu_pkg = (lpp_upload_pkg *)data->value;

	ret = output_buffer_list_del((uint32_t)mcu_pkg->info_code,
								(uint32_t)mcu_pkg->error_code, (uint64_t)mcu_pkg->target_pts);
	if(ret)
		hwlog_err("%s fail, fd:%d not found!\n", __func__, (uint32_t)mcu_pkg->info_code);
	else
		hwlog_info("%s succ!\n", __func__);

	return NO_NEED_UPLOAD;
}

static int lpp_flush_back_report(void)
{
	g_sensorhub_flush_back_signal = 1;

	return NO_NEED_UPLOAD;
}

static int lpp_parse_display_upload(pkt_lpp_mcu_data_t *data, lpp_upload_pkg *upload_pkg)
{
	pkt_lpp_mcu_data_t *temp = (pkt_lpp_mcu_data_t *)data;
	int ret = 0;
	hwlog_info("%s cmd 0x%x\n", __func__, temp->head.lpp_cmd);

	switch (temp->head.lpp_cmd) {
	case LPP_CMD_UPLOAD:
		ret = lpp_record_data_from_mcu(data, upload_pkg);
		break;
	case LPP_CMD_RELEASE_BUFF:
		ret = lpp_release_output_buffer(data);
		break;
	case LPP_CMD_FLUSH_DONE:
		ret = lpp_flush_back_report();
		break;

	default:
		hwlog_err("%s no suport lpp cmd = 0x%x\n", __func__, temp->head.lpp_cmd);
		break;
	}

	return ret;
}

static int lpp_parse_upload_app(pkt_lpp_mcu_data_t *data, lpp_upload_pkg *upload_pkg)
{
	int ret = 0;

	switch (data->head.lpp_app_type) {
	case APP_DISPLAY:
		ret = lpp_parse_display_upload(data, upload_pkg);
		break;

	default:
		hwlog_err("%s no suport app = 0x%x\n", __func__, data->head.lpp_app_type);
		break;
	}

	return ret;
}

static int process_lpp_data_from_mcu(const struct pkt_header *head)
{
	hwlog_info("%s: get data from mcu\n", __func__);
	int ret = 0;
	if (head == NULL) {
		hwlog_err("%s: NULL ptr!\n", __func__);
		return -1;
	}
	unsigned char *data = (unsigned char *)head + sizeof(struct pkt_header);
	lpp_upload_pkg *upload_pkg = kzalloc(sizeof(lpp_upload_pkg), GFP_KERNEL);
	if (upload_pkg == NULL) {
		hwlog_err("%s: kzalloc upload_pkg fail!\n", __func__);
		return -1;
	}
	ret = lpp_parse_upload_app((pkt_lpp_mcu_data_t *)data, upload_pkg);
	if (ret == 0) {
		hwlog_info("%s upload_pkg event_type %d\n", __func__, upload_pkg->event_type);
		__pm_wakeup_event(lpp_wl, LPP_WAKEUP_MSEC);
		upload_lpp_data((char *)upload_pkg, sizeof(lpp_upload_pkg));
		hwlog_info("%s: upload lpp data\n", __func__);
	} else {
		hwlog_info("%s: no need upload lpp data\n", __func__);
	}
	kfree(upload_pkg);
	upload_pkg = NULL;
	hwlog_info("%s: get data from mcu success\n", __func__);
	return 0;
}

/*
* Description:	apply kernel buffer, register lpp_miscdev
* Return: 		result of function, 0 successed, else false
*/
static int __init lpp_init(void)
{
	int ret;

	if (is_sensorhub_disabled())
		return -1;

	ret = inputhub_route_open(ROUTE_LPP_PORT);
	if (ret != 0) {
		hwlog_err("lpp: %s cannot open inputhub route err=%d\n",
			__func__, ret);
		return ret;
	}

	ret = misc_register(&lpp_miscdev);
	if (ret != 0) {
		hwlog_err("%s cannot register miscdev err=%d\n", __func__, ret);
		inputhub_route_close(ROUTE_LPP_PORT);
		return ret;
	}
	register_mcu_event_notifier(TAG_LPP, CMD_DATA_REQ, process_lpp_data_from_mcu);
	register_iom3_recovery_notifier(REC_USR_LPP, &g_lpp_recovery_notify);

	lpp_wl = wakeup_source_register(NULL, "lpp_sensorhub");
	INIT_LIST_HEAD(&g_lpp_total_output_buffer.head);
	spin_lock_init(&g_lpp_total_output_buffer.lock);
	init_waitqueue_head(&sensorhub_flush_back_waitq);
	for (int i = 0; i < MAX_LPP_INSTANCE_NUM; i++) {
		mutex_init(&g_lpp_ioctl_lock[i]);
	}
	hwlog_info("%s ok\n", __func__);

	return ret;
}

/* release kernel buffer, deregister lpp_miscdev */
static void __exit lpp_exit(void)
{
	inputhub_route_close(ROUTE_LPP_PORT);
	wakeup_source_unregister(lpp_wl);
	lpp_wl = NULL;
	misc_deregister(&lpp_miscdev);
	hwlog_info("exit %s\n", __func__);
}

late_initcall_sync(lpp_init);
module_exit(lpp_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Lpp driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");