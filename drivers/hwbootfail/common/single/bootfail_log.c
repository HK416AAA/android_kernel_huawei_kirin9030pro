

#include <linux/vmalloc.h>
#include <linux/blackbox_common.h>
#include <linux/blackbox_storage.h>

#include <linux/rtc.h>
#include <linux/ctype.h>
#include <linux/errno.h>
#include <linux/zlib.h>
#include <linux/kernel.h>
#include <linux/namei.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <crypto/hash.h>
#include <crypto/sha.h>

#include <hwbootfail/chipsets/common/bootfail_common.h>
#include <hwbootfail/chipsets/common/bootfail_timer.h>
#include <hwbootfail/chipsets/common/bootfail_chipsets.h>
#include <hwbootfail/core/boot_detector.h>
#include <linux/blackbox.h>
#include <linux/blackbox_common.h>
#include <linux/blackbox_storage.h>
#include <securec.h>

#define SECONDS_PER_MINUTE 60
#define SHA256_SIZE 32
#define LOG_MAX_COUNT 50
#define DEV_PATH_SIZE 128
#define BF_SIZE_16 16
#define BF_SIZE_1M (BF_SIZE_1K * BF_SIZE_1K)
#define KMSG_BUFF (BF_SIZE_1M * 20)
#define LOG_OFFSET 0x300
#define TIMEOUT_VALUE (1000 * 60 * 1)
#define FILE_PERMISSIONS 0664

struct save_logs_to_mem {
	unsigned int kmsg_idx;
	char kmsg[KMSG_BUFF];
} __packed;

struct save_logs_param {
	unsigned long long rtc_time;
	unsigned int bootup_time;
	unsigned int stage;
	struct save_logs_to_mem mem_param;
} __packed;

struct save_logs_param* g_log_param = NULL;
static DEFINE_SEMAPHORE(g_log_param_sem);

static void save_kmsg_to_mem(struct save_logs_to_mem* logs_to_mem, int count)
{
	char* pbuf = NULL;
	unsigned int buf_size = 0;
	print_info("bootfail save_kmsg_to_mem called!\n");
	if (logs_to_mem == NULL) {
		print_err("bootfail logs_to_mem == NULL!\n");
		return;
	}

	if (logs_to_mem->kmsg_idx >= sizeof(logs_to_mem->kmsg)) {
		print_err("bootfail kmsg_idx >= kmsg!\n");
		return;
	}

	if (count == 0) {
		buf_size = BF_SIZE_1M * 5; // 5M
	} else {
		buf_size = BF_SIZE_512K;
	}

	if (logs_to_mem->kmsg_idx + buf_size > sizeof(logs_to_mem->kmsg)) {
		buf_size = sizeof(logs_to_mem->kmsg) - logs_to_mem->kmsg_idx;
	}

	if (buf_size <= 1) { // 1 means end symbol
		print_err("bootfail bufsize is too small\n");
		return;
	}

	print_info("bootfail buf_size is %u!\n", buf_size);
	pbuf = (char*)vzalloc(buf_size);
	if (pbuf == NULL) {
		print_err("bootfail pbuf vzalloc failed!\n");
		return;
	}

	get_kernel_log(pbuf, buf_size);
	if (buf_size <= 1) { // 1 means end symbol
		print_err("bootfail bufsize is too small\n");
		vfree(pbuf);
		return;
	}

	pbuf[buf_size - 1] = '\n';
	int ret = memcpy_s(&logs_to_mem->kmsg[logs_to_mem->kmsg_idx],
		sizeof(logs_to_mem->kmsg) - logs_to_mem->kmsg_idx, pbuf, buf_size);
	if (ret != 0) {
		print_err("pbuf -> kmsg memcpy_s failed %d!\n", ret);
	}
	logs_to_mem->kmsg_idx += buf_size;
	vfree(pbuf);
	print_info("bootfail logs_to_mem->kmsg_idx %u!\n", logs_to_mem->kmsg_idx);
}

static int deflate_compress(const char *src, size_t slen, char **dst, unsigned int *dlen)
{
	int error;
	struct z_stream_s strm;
	void *stgbuf, *dstbuf;
	size_t stglen = deflateBound(slen);

	memset_s((void *)&strm, sizeof(strm), 0, sizeof(strm));
 
	if (stglen < slen)
		return -EFBIG;
 
	strm.workspace = vzalloc(zlib_deflate_workspacesize(MAX_WBITS,
							     MAX_MEM_LEVEL));
	if (!strm.workspace)
		return -ENOMEM;
 
	error = zlib_deflateInit(&strm, Z_DEFAULT_COMPRESSION);
	if (error != Z_OK) {
		error = -ENOMEM;
		goto fail_deflate_init;
	}
 
	stgbuf = vzalloc(stglen);
	if (!stgbuf) {
		error = -ENOMEM;
		goto fail_deflate_init;
	}
 
	strm.next_in = src;
	strm.avail_in = slen;
	strm.next_out = stgbuf;
	strm.avail_out = stglen;
 
	error = zlib_deflate(&strm, Z_FINISH);
	if (error != Z_STREAM_END) {
		error = -EINVAL;
		goto fail_deflate;
	}
	error = 0;
 
	dstbuf = vzalloc(strm.total_out);
	if (dstbuf) {
		int ret = memcpy_s(dstbuf, strm.total_out, stgbuf, min(stglen, strm.total_out));
		if (ret != 0) {
			print_err("dstbuf memcpy_s failed %d!\n", ret);
		}
	}
	*dst = dstbuf;
	*dlen = strm.total_out;

	zlib_deflateEnd(&strm);
fail_deflate:
	vfree(stgbuf);
fail_deflate_init:
	vfree(strm.workspace);
	return error;
}

static bool create_log_path(char log_path_tmp[BF_SIZE_128])
{
	print_info("bootfail create_log_path!\n");
	char timestamp[BF_SIZE_64] = {0};
	const char save_log_path[] = "/log/reliability/boot_fail/log";

	if (create_log_dir(save_log_path) != 0)
		return false;

	get_timestamp(timestamp, BF_SIZE_64);
	int ret = scnprintf(log_path_tmp, BF_SIZE_128 - 1,
		"%s/%s", save_log_path, timestamp);
	if (ret < 0 || ret >= BF_SIZE_128 - 1) {
		return false;
	}
	if (create_log_dir(log_path_tmp) == 0) {
		return true;
	}

	return false;
}

static int write_file(const char *log_path, char *content, unsigned int size)
{
	int ret;
	struct file *fp = NULL;
 
	fp = filp_open(log_path, O_CREAT | O_RDWR, FILE_PERMISSIONS);
	if (IS_ERR_OR_NULL(fp)) {
		print_err("BootDetector bbox_dump filp_open failed!\n");
		return -1;
	}
 
	ret = vfs_write(fp, content, size, &fp->f_pos);
	if (ret < 0)
		print_err("BootDetector bbox_dump write is error res %d!\n", ret);
 
	filp_close(fp, NULL);
	return ret;
}

static bool save_kmsg_to_log(char* log_path, char *log_file)
{
	print_info("bootfail save_kmsg_to_log!\n");
	if (g_log_param == NULL) {
		print_info("bootfail g_log_param == NULL!\n");
		return false;
	}
 
	struct save_logs_to_mem* mem_param = &(g_log_param->mem_param);
	if (mem_param == NULL) {
		print_info("bootfail mem_param == NULL!\n");
		return false;
	}
 
	char* dst = NULL;
	unsigned int dlen = 0;
	int error = deflate_compress(mem_param->kmsg, mem_param->kmsg_idx, &dst, &dlen);
	if (error) {
		print_err("bootfail deflate_compress error: %d!\n", error);
		return false;
	}
	if (dst == NULL) {
		print_err("bootfail deflate_compress dst = NULL!\n");
		return false;
	}

	char timestamp[BF_SIZE_64] = {0};
	get_timestamp(timestamp, BF_SIZE_64);
	int ret = scnprintf(log_file, BF_SIZE_256 - 1,
		"%s/log_%s.gz", log_path, timestamp);
	if (ret < 0 || ret >= BF_SIZE_256 - 1) {
		return false;
	}
	write_file(log_file, dst, dlen);
	vfree(dst);
	return true;
}

static int log_init(void)
{
	enum boot_stage stage = INVALID_STAGE;
	print_info("bootfail log_init!\n");
	down(&g_log_param_sem);
	if (g_log_param != NULL) {
		up(&g_log_param_sem);
		return 0;
	}
	g_log_param = vzalloc(sizeof(struct save_logs_param));
	if (g_log_param == NULL) {
		print_err("bootfail g_log_param vzalloc failed!\n");
		up(&g_log_param_sem);
		return -ENOMEM;
	}

	g_log_param->rtc_time = get_sys_rtc_time();
	g_log_param->bootup_time = get_bootup_time();
	int error_code = get_boot_stage(&stage);
	if (error_code != BF_OK) {
		print_err("bootfail get_boot_stage ret: %d!\n", error_code);
		stage = INVALID_STAGE;
	}
	g_log_param->stage = stage;
	print_info("bootfail log_init: rtc_time:%llu, bootup_time:%u, stage:%d!\n",
		g_log_param->rtc_time, g_log_param->bootup_time, g_log_param->stage);
	up(&g_log_param_sem);
	return 0;
}

void bootfail_callback(unsigned int state, char* ret_path, int len, struct bootfail_proc_param* param)
{
	static int count = 0;
	int ret = 0;
	print_info("bootfail callback!\n");

	char* log_temp_path = boot_detector_wake_up(state, count, TIMEOUT_VALUE, param);
	print_info("bootfail log_temp_path %s!\n", log_temp_path);
	if (strlen(log_temp_path) <= 0 && log_init() != 0) {
		return;
	}

	if (state == TIMING_SAVE_LOG) {
	    count++;
		print_info("bootfail state == TIMING_SAVE_LOG!\n");
		if (strlen(log_temp_path) <= 0) {
			down(&g_log_param_sem);
			if (g_log_param != NULL) {
				save_kmsg_to_mem(&g_log_param->mem_param, count);
			}
			up(&g_log_param_sem);
		}
	} else if (state == FAULT_SAVE_LOG) {
		char log_path[BF_SIZE_128] = {0};
		char log_file[BF_SIZE_256] = {0};
		print_info("bootfail state == FAULT_SAVE_LOG!\n");
		down(&g_log_param_sem);
		if ((g_log_param != NULL) && (g_log_param->mem_param.kmsg_idx > 0) && create_log_path(log_path)) {
			save_kmsg_to_log(log_path, log_file);
		}
		up(&g_log_param_sem);
		char* log_navite_path = boot_detector_wait_completed(30000); // 30s
		print_info("kmsg_log file is :%s!\n", log_file);
		print_info("navite_log path:%s!\n", log_navite_path);
		if (strlen(log_navite_path) > 0) {
			ret = scnprintf(ret_path, len - 1, "%s", log_navite_path);
		} else if (strlen(log_file) > 0) {
			ret = scnprintf(ret_path, len - 1, "%s", log_file);
		}

		if (ret >= len) {
			print_err("invalid path len, over buffer length, exit!\n");
			memset_s((void *)ret_path, len, 0, len);
			return;
		}
	}
}

void bootfail_logs_destructor(void)
{
	print_info("bootfail_logs_destructor!\n");
	down(&g_log_param_sem);
	if (g_log_param != NULL) {
		vfree(g_log_param);
		g_log_param = NULL;
	}
	up(&g_log_param_sem);
}

#ifdef CONFIG_BOOT_DETECTOR_SINGLE_FRAME
static bool save_snapshot(char *file_path, unsigned int snapshot_addr, unsigned int snapshot_size)
{
	bool res = true;
	int ret = -1;
	char file_dir[BF_SIZE_64];
	char timestamp[BF_SIZE_64] = {0};
	char* content = NULL;

	if (file_path == NULL) {
		print_err("file_path failed\n");
		return false;
	}

	memset_s(file_dir, sizeof(file_dir), 0, sizeof(file_dir));
	ret = sprintf_s(file_dir, BF_SIZE_64 - 1, "/log/reliability/boot_fail/log");
	if (ret < 0) {
		print_err("file_dir failed\n");
		return false;
	}
	create_log_dir(file_dir);
	
	get_timestamp(timestamp, BF_SIZE_64);
	ret = sprintf_s(file_path, BF_SIZE_256 - 1, "%s/hm_klog_%s.gz", file_dir, timestamp);
	if (ret < 0) {
		print_err("file_path failed\n");
		return false;
	}
 
	content = vzalloc(snapshot_size);
	if (!content) {
		print_err("vzalloc snapshot failed\n");
		return false;
	}
	ret = read_part(get_bfi_dev_path(), snapshot_addr, content, snapshot_size);
	if (ret != 0) {
		print_err("read_part, snapshot_addr:0x%x faild!\n", snapshot_addr);
		res = false;
		goto exit;
	}
	ret = write_file(file_path, content, snapshot_size);
	if (ret < 0) {
		print_err("write_file file_path %s faild!\n", file_path);
		res = false;
	}
exit:
	vfree(content);
	return res;
}
 
void update_log_header(struct bootfail_log_header* hdr, unsigned int hdr_addr,
	unsigned int snapshot_max_count, const char* file_path)
{
	int ret = -1;
	unsigned int i = 0;
	unsigned int log_path_size;

	if (hdr == NULL || file_path == NULL) {
    	print_err("invalid parameter: hdr or file_path is NULL\n");
    	return;
    }

	log_path_size = sizeof(hdr->log_path) / sizeof(hdr->log_path[0]);

	for(; i < log_path_size; ++i) {
		if (strlen(hdr->log_path[i]) == 0) {
			break;
		}
	}
	if (i >= log_path_size) {
		print_err("log_path is full\n");
		return;
	}
 
	ret = sprintf_s(hdr->log_path[i], sizeof(hdr->log_path[i]) - 1, "%s", file_path);
	if (ret < 0) {
		print_err("file_dir failed\n");
		return;
	}
	hdr->snapshot_store_index = snapshot_max_count;
	ret = write_part(get_bfi_dev_path(), hdr_addr,
		(const char *)hdr, sizeof(struct bootfail_log_header));
	if (ret < 0) {
		print_err("write_part, bootfail_log_header faild!\n");
	}
}
 
bool transfer_snapshot(void)
{
	print_err("transfer_snapshot\n");
	struct bootfail_meta_log pinfo;
	memset_s(&pinfo, sizeof(pinfo), 0, sizeof(pinfo));
	if (!get_meta_log(&pinfo)) {
		print_err("get_meta_log faild!\n");
		return false;
	}
 
	if (pinfo.log_count == 0) {
		print_err("not bootfail info data\n");
		return false;
	}
 
	unsigned int idx = (pinfo.write_idx == 0) ? pinfo.log_max_count - 1 : pinfo.write_idx - 1;
	unsigned int hdr_addr = pinfo.logs_info[idx].bl_log.start - sizeof(struct bootfail_log_header);
	print_err("transfer_snapshot hdr_addr 0x%x\n", hdr_addr);
	print_err("transfer_snapshot idx %u\n", idx);
	struct bootfail_log_header hdr;
	memset_s(&hdr, sizeof(hdr), 0, sizeof(hdr));
	int ret = read_part(get_bfi_dev_path(), hdr_addr,
		(char *)&hdr, sizeof(struct bootfail_log_header));
	if (ret != 0) {
		print_err("read_part, bootfail_log_header faild!\n");
		return false;
	}
 
	unsigned int snapshot_addr = 0;
	unsigned int snapshot_size = 0;
	bool res = get_snapshot_info(&pinfo, idx, &hdr, &snapshot_addr, &snapshot_size);
	if (!res) {
		print_err("get snapshot failed\n");
		return false;
	}
 
	print_err("transfer_snapshot snapshot_addr %u, snapshot_size %u\n", snapshot_addr, snapshot_size);
	char file_path[BF_SIZE_256];
	memset_s(file_path, BF_SIZE_256, 0, BF_SIZE_256);
	res = save_snapshot(file_path, snapshot_addr, snapshot_size);
	if (!res) {
		print_err("save snapshot failed\n");
		return false;
	}
	print_err("file_path %s\n", file_path);
	update_log_header(&hdr, hdr_addr, pinfo.snapshot_max_count, file_path);
	return true;
}
 
static int check_mount_point(const char* dev_path)
{
    struct path path;
    int ret;

    if (dev_path == NULL) {
        print_err("dev_path is failed!\n");
        return -EINVAL;
    }

    ret = kern_path(dev_path, LOOKUP_FOLLOW, &path);
    if (ret) {
        print_err("Failed to get path.\n");
        return ret;
    }
 
    if (path.mnt && path.mnt->mnt_root == path.dentry) {
        print_err("Path %s is a mount point.\n", dev_path);
    } else {
        print_err("Path %s is not a mount point.\n", dev_path);
    }
 
    path_put(&path);
    return 0;
}
 
static int save_error_log(void *pparam)
{
	print_err("save_error_log start\n");
	msleep(4000);
	while(check_mount_point("/log") == 0) {
		print_err("msleep(1000)\n");
		msleep(1000);
	}
	transfer_snapshot();
	print_err("save_error_log end\n");
	return 0;
}
 
int bootfail_log_init(void)
{
	struct task_struct *tsk = kthread_run(save_error_log, NULL, "save_bootfail_log");
	if (IS_ERR(tsk)) {
		print_err("kthread_run failed!\n");
		return -ESRCH;
	}
	return 0;
}
#endif