

/* ---- includes ---- */
#include <linux/rtc.h>
#include <linux/vmalloc.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/namei.h>
#include <linux/security.h>
#include <linux/fs.h>
#include <crypto/hash.h>
#include <crypto/sha.h>
#include <linux/syscalls.h>
#include <linux/mutex.h>

#include <hwbootfail/core/boot_detector.h>
#include <hwbootfail/core/boot_recovery.h>
#include <hwbootfail/chipsets/common/bootfail_common.h>
#include <hwbootfail/chipsets/common/bootfail_chipsets.h>

#include <linux/blackbox.h>
#include <linux/blackbox_common.h>
#include <linux/blackbox_storage.h>
#include <securec.h>
#include <trace/hooks/liblinux.h>
#include <mntn_public_interface.h>
#include "bootfail_parsing.h"

#ifndef BF_SIZE_2K
#define BF_SIZE_2K (BF_SIZE_1K * 2)
#endif
#define RECORDS_COUNT 40
#define SHUT_FAIL_ERRNO (-1)
#define MAX_LOG_COUNT 10
#define DEFAULT_START_YEAR 1900
#define SLEEP_TIME 100


#define RECORDS_INFO_TITLE_FMT "================time:0x%lx================"
#define RECORDS_INFO_METHOD_STR_FMT "rcvMethod%s:%s"
#define RECORDS_INFO_RESULT_STR_FMT "rcvResult%s:%s"
#define RECORDS_INFO_METHOD_FMT "rcvMethod%s:%d"
#define RECORDS_INFO_RESULT_FMT "rcvResult%s:%d"
#define RECORDS_INFO_SELF_HEAL_CCHAIN_FMT "selfHealChain%s:%s"

static char g_recovery_info_log_path[BF_SIZE_128] = {0};

static const int recovery_success = 1;

static char invalid_boot_stage[] = "INVALID STAGE";
static char invalid_errno[] = "INVALID_ERRNO";

static char shut_fail[] = "SHUTDOWN FAIL";


// bootfail log path userd
unsigned int g_write_index = 0;
struct mutex mtx_lock;

static int sha256_check(char *data, unsigned int len, char hash[SHA256_DIGEST_SIZE])
{
	int ret = 0;
	struct crypto_shash *tfm;
	size_t desc_size;
	struct shash_desc *desc;

	tfm = crypto_alloc_shash("sha256", 0, 0);
	if (IS_ERR(tfm)) {
		ret = PTR_ERR(tfm);
		goto out;
	}

	desc_size = crypto_shash_descsize(tfm) + sizeof(struct shash_desc);
	desc = kzalloc(desc_size, GFP_KERNEL);
	if (!desc) {
		ret = -ENOMEM;
		goto out_free_tfm;
	}
	desc->tfm = tfm;

	ret = crypto_shash_init(desc);
	if (ret < 0)
		goto out_free_desc;

	ret = crypto_shash_update(desc, data, len);
	if (ret)
		goto out_free_desc;

	ret = crypto_shash_final(desc, hash);

out_free_desc:
	kfree(desc);
out_free_tfm:
	crypto_free_shash(tfm);
out:
	return ret;
}

static bool check_values(struct bootfail_meta_log *bf_meta_log)
{
	if (bf_meta_log == NULL) {
		print_err("check_values: bf_meta_log is NULL!\n");
		return false;
    }

	if ((bf_meta_log->log_max_count < 0) || (bf_meta_log->log_max_count > MAX_LOG_COUNT)) {
		print_err("check_values: log_max_count is invalid!\n");
        return false;
    }

	if ((bf_meta_log->log_count < 0) || (bf_meta_log->log_count > bf_meta_log->log_max_count)) {
    	print_err("check_values: log_count is invalid!\n");
    	return false;
	}

	if (bf_meta_log->write_idx < 0 || bf_meta_log->write_idx >= bf_meta_log->log_max_count) {
		print_err("check_values: write_index is invalid!\n");
		return false;
	}
	return true;
}

bool get_meta_log(struct bootfail_meta_log *bf_meta_log)
{
	int ret = 0;
	char hash[SHA256_DIGEST_SIZE];
	memset_s(bf_meta_log, sizeof(struct bootfail_meta_log), 0, sizeof(struct bootfail_meta_log));
	memset_s(hash, SHA256_DIGEST_SIZE, 0, SHA256_DIGEST_SIZE);

	ret = read_part(get_bfi_dev_path(), sizeof(union bfi_part_header) + sizeof(struct bootfail_proc_param),
				(char *)bf_meta_log, sizeof(struct bootfail_meta_log));
	if (ret != 0) {
		print_err("read rrecord part failed!\n");
		return false;
	}

	ret = sha256_check((char *)bf_meta_log + sizeof(bf_meta_log->sha256),
					   sizeof(struct bootfail_meta_log) - sizeof(bf_meta_log->sha256),
					   hash);
	if (ret != 0) {
		print_err("sha256_check failed!\n");
		return false;
	}

	if (memcmp(hash, bf_meta_log->sha256, SHA256_DIGEST_SIZE) != 0) {
		print_err("sha256 failed!\n");
		return false;
	}

	return check_values(bf_meta_log);
}

static int read_content(char *content, unsigned int start, unsigned int size)
{
	int ret;

	ret = read_part(get_bfi_dev_path(), start, (char *)content, size);
	if (ret != 0) {
		print_err("read log from record partition failed!");
		return -1;
	}
	return 0;
}

static bool write_content(char *content, unsigned int start, unsigned int size)
{
	int ret = write_part(get_bfi_dev_path(), start, (char *)content, size);
	if (ret != 0) {
		print_err("write log to record partition failed!");
		return false;
	}
	return true;
}

static void clear_bfi_misc(void) {
	union bfi_part_header header;
	memset_s(&header, sizeof(union bfi_part_header), 0, sizeof(union bfi_part_header));
	bool ret = write_content((char *)&header, 0, sizeof(union bfi_part_header));
	if (!ret) {
		print_err("clear bfi misc msg header failed");
		(void)write_content((char *)&header, 0, sizeof(union bfi_part_header));
	}
}

static void clear_recovery_info(struct bootfail_meta_log *bf_meta_log)
{
	int record_bak_addr = bf_meta_log->rrecord_offset + RECORDS_COUNT * sizeof(struct rrecord) +
		sizeof(struct rrecord_header);
	struct rrecord_header rheader;
	memset_s(&rheader, sizeof(struct rrecord_header), 0, sizeof(struct rrecord_header));

	struct rrecord *records = (struct rrecord *)vmalloc(sizeof(struct rrecord) * RECORDS_COUNT);
	if (records == NULL) {
		print_err("failed to alloc size for rrecord, exit\n");
		return;
	}

	memset_s(records, sizeof(struct rrecord) * RECORDS_COUNT, 0, sizeof(struct rrecord) * RECORDS_COUNT);

	bool ret = write_content((char *)(&rheader), bf_meta_log->rrecord_offset, sizeof(struct rrecord_header));
	if (!ret) {
		print_err("clear rrecord header failed");
		write_content((char *)(&rheader), bf_meta_log->rrecord_offset, sizeof(rheader.sha256));
	}

	ret = write_content((char *)records, bf_meta_log->rrecord_offset + sizeof(struct rrecord_header),
		sizeof(struct rrecord) * RECORDS_COUNT);
	if (!ret)
		print_err("clear rrecord  failed ");

	ret = write_content((char *)(&rheader), record_bak_addr, sizeof(struct rrecord_header));
	if (!ret) {
		print_err("clear rrecord bak header failed");
		write_content((char *)(&rheader), record_bak_addr, sizeof(rheader.sha256));
	}

	ret = write_content((char *)records, record_bak_addr + sizeof(struct rrecord_header),
		sizeof(struct rrecord) * RECORDS_COUNT);
	if (!ret)
		print_err("clear rrecord bak failed ");

	vfree(records);
	records = NULL;
}

static void clean_bootfail_info(void)
{
	struct bootfail_meta_log bf_meta_log;
	memset_s(&bf_meta_log, sizeof(struct bootfail_meta_log), 0, sizeof(struct bootfail_meta_log));
	bool ret = get_meta_log(&bf_meta_log);
	if (ret) {
		clear_recovery_info(&bf_meta_log);
	}

	memset_s((char *)&bf_meta_log, sizeof(struct bootfail_meta_log), 0, sizeof(struct bootfail_meta_log));
	write_content((char *)(&bf_meta_log), sizeof(union bfi_part_header) +
				sizeof(struct bootfail_proc_param), sizeof(struct bootfail_meta_log));
}

static void convert_stageno_to_str(char *stage, int stage_no)
{
	unsigned int index = 0;
	for (index; index < ARRAY_SIZE(stage_map); index++) {
		if (stage_map[index].stage == stage_no) {
			errno_t ret = strncpy_s(stage, BF_SIZE_128 - 1, stage_map[index].stage_dec, strlen(stage_map[index].stage_dec));
			if (ret != EOK)
				print_err("stage_map[index].stage_dec strncpy_s failed\n");
			return;
		}
	}
}

static void convert_errno_to_str(char *errnum, int errno)
{
	int ret = 0;
	unsigned int index = 0;

	if (errno == SHUT_FAIL_ERRNO) {
		ret = strncpy_s(errnum, BF_SIZE_128 - 1, shut_fail, strlen(shut_fail));
		if (ret < 0)
			print_err("convert_errno_to_str copy shutfail failed!\n");
		return;
	}
	for (index; index < ARRAY_SIZE(error_no_map); index++) {
		if (error_no_map[index].error == errno) {
			ret = strncpy_s(errnum, BF_SIZE_128 - 1, error_no_map[index].err_dec, strlen(error_no_map[index].err_dec));
				if (ret < 0)
					print_err("convert_errno_to_str copy bootfail failed!\n");
			return;
		}
	}
}

static const char *convert_rcv_method_to_str(int method)
{
	unsigned int index = 0;
	for (index; index < ARRAY_SIZE(g_method_no_map); index++) {
		if (g_method_no_map[index].method == method) {
			return g_method_no_map[index].method_dec;
		}
	}

	print_err("convert_rcv_method_to_str failed, method = %d.!\n", method);
	return "";
}

static void convert_orig_data(char *stage, char *errnum, int ori_stage, int ori_errno)
{
	int ret = 0;
	convert_stageno_to_str(stage, ori_stage);
	if (strlen(stage) == 0) {
		print_err("convert_orig_data: convert stage failed!\n");
		ret = strncpy_s(stage, BF_SIZE_128 - 1, invalid_boot_stage, strlen(invalid_boot_stage));
		if (ret)
			print_err("convert_orig_data copy boot stage failed!\n");
	}

	convert_errno_to_str(errnum, ori_errno);
	if (strlen(errnum) == 0) {
		print_err("convert_orig_data: convert errno failed!\n");
		ret = strncpy_s(errnum, BF_SIZE_128 - 1, invalid_errno, strlen(invalid_errno));
		if (ret)
			print_err("convert_orig_data copy errno failed!\n");
	}
}

static void send_bbox_notify(struct error_info *info, char *stage, char *errnum)
{
	errno_t ret;
	ret = strncpy_s(info->event, EVENT_MAX_LEN - 1, EVENT_BOOTFAIL, strlen(EVENT_BOOTFAIL));
	if (ret != EOK)
		print_err("info->event strncpy_s failed\n");

	ret = strncpy_s(info->module, MODULE_MAX_LEN - 1, MODULE_BOOTFAIL, strlen(MODULE_BOOTFAIL));
	if (ret != EOK)
		print_err("info->module strncpy_s failed\n");

	ret = strncpy_s(info->category, CATEGORY_MAX_LEN - 1, CATEGORY_SYSTEM_BOOTFAIL, strlen(CATEGORY_SYSTEM_BOOTFAIL));
	if (ret != EOK)
		print_err("info->category strncpy_s failed\n");

	ret = strncpy_s(info->log_path, ROOT_LOG_PATH_LEN - 1, CONFIG_BLACKBOX_LOG_ROOT_PATH,
				strlen(CONFIG_BLACKBOX_LOG_ROOT_PATH));
	if (ret != EOK)
		print_err("info->log_path strncpy_s failed\n");

	ret = strncpy_s((char *)info->top_category, CATEGORY_MAX_LEN - 1, stage, strlen(stage));
	if (ret != EOK)
		print_err("info->top_category strncpy_s failed\n");

	ret = strncpy_s((char *)info->error_desc, ERROR_DESC_MAX_LEN - 1, errnum, strlen(errnum));
	if (ret != EOK)
		print_err("info->error_desc strncpy_s failed\n");

	bbox_notify_error(EVENT_BOOTFAIL, MODULE_BOOTFAIL, (char *)info, false);
}

static void append_log_path(struct bootfail_log_header *bf_bootfail_info, char *logs, int space)
{
	int ret = 0;
	char *buf = logs;
	size_t i = 0;

	for (i; i < (sizeof(bf_bootfail_info->log_path) / sizeof(bf_bootfail_info->log_path[0])); i++) {
		if (strlen(bf_bootfail_info->log_path[i]) <= 0)
			continue;

		ret = snprintf_s(buf, space, strlen(bf_bootfail_info->log_path[i]), "%s\n", bf_bootfail_info->log_path[i]);
		if (ret > 0) {
			space -= ret;
			buf += ret;
		} else {
			print_err("%d append string failed", __LINE__);
		}
	}
}

static void save_boofail_info(char *bf_content, struct bootfail_log_header *bf_bootfail_info, struct error_info *info,
							char *errno, char *stage)
{
	struct rtc_time real_time;
	int len;

	int logPaths = sizeof(bf_bootfail_info->log_path) / sizeof(bf_bootfail_info->log_path[0]);
	int space = sizeof(bf_bootfail_info->log_path) + logPaths;

	char *logs = vmalloc(space);
	if (logs != NULL) {
		int ret = memset_s(logs, space, 0, space);
		if (ret == 0) {
			append_log_path(bf_bootfail_info, logs, space);
		} else {
			print_err("memset log path buffer failed!\n");
			vfree(logs);
			logs = NULL;
		}
	}

	rtc_time64_to_tm(bf_bootfail_info->binfo.rtc_time, &real_time);
	convert_orig_data(stage, errno, bf_bootfail_info->binfo.stage, bf_bootfail_info->binfo.bootfail_errno);

	len = snprintf_s(info->error_time, TIMESTAMP_MAX_LEN, TIMESTAMP_MAX_LEN - 1,
			"%04d%02d%02d%02d%02d%02d-%08d", real_time.tm_year + DEFAULT_START_YEAR, real_time.tm_mon + 1, real_time.tm_mday,
			real_time.tm_hour, real_time.tm_min, real_time.tm_sec, bf_bootfail_info->binfo.bootup_time);
	if (len <= 0) {
		print_err("%d append error_time failed", __LINE__);
		goto end;
	}

	len = snprintf_s((char *)bf_content, BF_SIZE_1K, BF_SIZE_1K - 1,
				"                   Generated by HiviewDFX@HarmonyOS               \n"
				"==========================Parsed data=============================\n"
				"Time of Error Occoured: %d/%02d/%02d-%02d:%02d:%02d\nBoot Stage when Error Occoured: %s\n"
				"Fault Reason: %s\nBoot Up Time: %d seconds\nDMD Error No: %d\nIs Root: %s\n"
				"Space Left On Device: %uMB\nInodes Left On Device: %u\nError Description: %s\n"
				"\n=======================Original data=============================\n"
				"Error No: 0x%x\nBoot Stage: 0x%x\nException Type: %d\nSub Exception Type: %d\n"
				"Suggest Recovery Method: %d\nException Stage: %d\nVersion: %s\nLogPath:%s\n",
				real_time.tm_year + 1900, real_time.tm_mon + 1, real_time.tm_mday, real_time.tm_hour,
				real_time.tm_min, real_time.tm_sec, stage, errno, bf_bootfail_info->binfo.bootup_time,
				bf_bootfail_info->binfo.dmd_errno, bf_bootfail_info->binfo.is_rooted == 0 ? "False" : "True",
				bf_bootfail_info->space_left, bf_bootfail_info->inodes_left, bf_bootfail_info->detail_info,
				bf_bootfail_info->binfo.bootfail_errno, bf_bootfail_info->binfo.stage,
				bf_bootfail_info->binfo.exception_type, bf_bootfail_info->binfo.sub_exception_type,
				bf_bootfail_info->binfo.suggest_recovery_method, bf_bootfail_info->binfo.exception_stage,
				bf_bootfail_info->version, logs == NULL ? "No additional log detected" : logs);
	if (len <= 0)
		print_err("%d append bootfail_info failed", __LINE__);

end:
	if (logs != NULL) {
		vfree(logs);
		logs = NULL;
	}
}

static int write_file(const char *log_path, char *content, unsigned int size, bool append)
{
	int ret;
	struct file *fp = NULL;
	mm_segment_t fs;

	if (append) {
		fp = filp_open(log_path, O_CREAT | O_RDWR | O_APPEND, 0664);
	} else {
		fp = filp_open(log_path, O_CREAT | O_RDWR, 0664);
	}
	if (IS_ERR_OR_NULL(fp)) {
        int err = PTR_ERR(fp);
		print_err("BootDetector bbox_dump filp_open failed!, errno is %d\n", err);
		return -1;
	}

	fs = get_fs();
	set_fs(KERNEL_DS);

	ret = vfs_write(fp, content, size, &fp->f_pos);
	if (ret < 0)
		print_err("BootDetector bbox_dump write is error res %d!\n", ret);

	set_fs(fs);
	filp_close(fp, NULL);

	print_info("write file logpath is %s, ret is  %d \n", log_path, ret);
	return ret;
}

static int save_log(const char *path, char *content, unsigned int start, unsigned int size)
{
	int ret = 0;
	ret = read_content(content, start, size);
	if (ret != 0) {
		print_err("read content failed !\n");
		return ret;
	}
	ret = write_file(path, content, size, false);
	if (ret < 0) {
		print_err("save_log: write file failed!\n");
		return ret;
	}
	return ret;
}

static bool get_file_dir(struct error_info *info, char *bf_info_path, char *bl_log_path, char *kernel_log_path)
{
	const char *bf_info = "bootfail_info";
	const char *last_kmsg = "last_kmsg";
	const char *bl_log = "bl_log";
	const char *recovery_info = "recovery_info";
	char log_dir[BF_SIZE_128];

	memset_s(log_dir, BF_SIZE_128, 0, BF_SIZE_128);
	memset_s(bf_info_path, BF_SIZE_128, 0, BF_SIZE_128);
	memset_s(bl_log_path, BF_SIZE_128, 0, BF_SIZE_128);
	memset_s(kernel_log_path, BF_SIZE_128, 0, BF_SIZE_128);
	memset_s(g_recovery_info_log_path, BF_SIZE_128, 0, BF_SIZE_128);

	int len = snprintf_s(log_dir, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s", CONFIG_BLACKBOX_LOG_ROOT_PATH, info->error_time);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return false;
	}

	create_log_dir(log_dir);
	mutex_lock(&mtx_lock);
	len = snprintf_s(bf_info_path, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s_%u", log_dir, bf_info, g_write_index);
	if (len <= 0) {
		print_err("%d append bf_info_path failed", __LINE__);
		mutex_unlock(&mtx_lock);
		return false;
	}

	len = snprintf_s(bl_log_path, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s_%u", log_dir, bl_log, g_write_index);
	if (len <= 0) {
		print_err("%d append bl_log_path failed", __LINE__);
		mutex_unlock(&mtx_lock);
		return false;
	}

	len = snprintf_s(kernel_log_path, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s_%u", log_dir, last_kmsg, g_write_index);
	if (len <= 0) {
		print_err("%d append kernel_log_path failed", __LINE__);
		mutex_unlock(&mtx_lock);
		return false;
	}

	len = snprintf_s(g_recovery_info_log_path, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s_%u",
		log_dir, recovery_info, g_write_index);
	if (len <= 0) {
		print_err("%d append recovery_info_log_path failed", __LINE__);
		mutex_unlock(&mtx_lock);
		return false;
	}

	g_write_index++;
	mutex_unlock(&mtx_lock);

	return true;
}

static const char* find_file_name(const char *log_path)
{
	int i = strlen(log_path) - 1;
	for (i; i >= 0; --i) {
		if (log_path[i] == '/') {
			if (i == (strlen(log_path) - 1)) {
				return NULL;
			} else {
				return log_path + i + 1; // add 1 to ignore '/'
			}
		}
	}
	return log_path;
}
 
static void save_prefabricated_files(struct error_info *info, struct bootfail_log_header *pparam)
{
	char log_dir[BF_SIZE_128] = {0};
	char *log_file = NULL;
	int i = 0;
	int len = snprintf_s(log_dir, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s", CONFIG_BLACKBOX_LOG_ROOT_PATH, info->error_time);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return;
	}

	print_info("save_prefabricated_files: log_dir! %s\n", log_dir);
	for (i; i < sizeof(pparam->log_path) / sizeof(pparam->log_path[0]); i++) {
		if (strlen(pparam->log_path[i]) <= 0)
			break;
 
		const char* name = find_file_name(pparam->log_path[i]);
		if (name == NULL) {
			continue;
		}

		log_file = vmalloc(BF_SIZE_256);
		if(log_file == NULL) {
			print_err("vmalloc save_prefabricated_files buffer failed!\n");
			return;
		}
		memset_s(log_file, BF_SIZE_256, 0, BF_SIZE_256);

		len = snprintf_s(log_file, BF_SIZE_256, BF_SIZE_256 - 1, "%s/%s", log_dir, name);
		if (len <= 0) {
			print_err("%d append string failed", __LINE__);
			vfree(log_file);
			return;
		}
		print_info("save_prefabricated_files: %s to %s \n", pparam->log_path[i], log_file);
#ifdef CONFIG_LIBLINUX
		long error = ksys_symlink(pparam->log_path[i], log_file);
		if (error != 0)
			print_err("log_symlink error:%d\n", error);
#endif
	}
	vfree(log_file);
}

#ifdef CONFIG_BOOT_DETECTOR_SINGLE_FRAME
static void save_snapshot(struct error_info *info, unsigned int snapshot_addr, unsigned int snapshot_size)
{
	int len = 0;
    int ret = 0;
	char *content = NULL;
	char timestamp[BF_SIZE_64] = {0};

	char *log_path = vmalloc(BF_SIZE_256);
	if(log_path == NULL) {
		print_err("vmalloc save_snapshot log_path buffer failed!\n");
		return;
	}

	get_timestamp(timestamp, BF_SIZE_64);
	len = snprintf_s(log_path, BF_SIZE_256, BF_SIZE_256 - 1, "%s/%s/hm_klog_%s.gz",
		CONFIG_BLACKBOX_LOG_ROOT_PATH, info->error_time, timestamp);
	if (len <= 0) {
		print_err("append log dir failed!");
        vfree(log_path);
		return;
	}

	content = vzalloc(snapshot_size);
	if (content == NULL) {
		print_err("vmalloc snapshot content buffer failed!\n");
        vfree(log_path);
		return;
	}

	ret = save_log(log_path, content, snapshot_addr, snapshot_size);
	if (ret < 0) {
		print_err("make snapshot failed!\n");
	} else {
		print_err("make snapshot succeed!, ret is %d \n", content);
	}

	vfree(content);
    vfree(log_path);
}
#endif

static void process_snapshot(struct error_info *info, struct bootfail_meta_log *bf_meta_log,
		unsigned int index, struct bootfail_log_header *bf_log_header)
{
#ifdef CONFIG_BOOT_DETECTOR_SINGLE_FRAME
	unsigned int snapshot_addr = 0;
	unsigned int snapshot_size = 0;
	bool res = get_snapshot_info(bf_meta_log, index, bf_log_header, &snapshot_addr, &snapshot_size);
	if (res) {
		save_snapshot(info, snapshot_addr, snapshot_size);
	} else {
		print_err("not find snapshot idx %u\n", index);
	}
#endif
    return;
}

static void get_log_size(struct bootfail_log_content *log_content,
		struct bootfail_meta_log *bf_meta_log, unsigned int index)
{
	if (index < 0 || index >= bf_meta_log->log_max_count) {
		print_err("get_log_size log_max_count index, index = %u\n", index);
		return;
	}

	log_content->bl_log_size = bf_meta_log->logs_info[index].bl_log.size > SUB_RESERVED_FASTBOOT_LOG_PYHMEM_SIZE ?
			SUB_RESERVED_FASTBOOT_LOG_PYHMEM_SIZE : bf_meta_log->logs_info[index].bl_log.size;
	log_content->kernel_log_size = bf_meta_log->logs_info[index].kernel_log.size > LAST_KMSG_SIZE ?
			LAST_KMSG_SIZE : bf_meta_log->logs_info[index].kernel_log.size;
	log_content->bf_info_start = bf_meta_log->logs_info[index].bl_log.start - BF_SIZE_1K;
}

static void save_log_to_file(struct error_info *info, struct bootfail_meta_log *bf_meta_log, unsigned int index,
							char *errno, char *stage)
{
	struct bootfail_log_header bf_log_header;

	char bf_info_path[BF_SIZE_128] = {0};
	char bl_log_path[BF_SIZE_128] = {0};
	char kernel_log_path[BF_SIZE_128] = {0};

	struct bootfail_log_content *log_content = (struct bootfail_log_content *)vmalloc(sizeof(struct bootfail_log_content));
	if (log_content == NULL) {
		print_err("bbox_dump: vmalloc memory for bootfail logContent failed!\n");
		return;
	}

	memset_s(&bf_log_header, sizeof(bf_log_header), 0, sizeof(bf_log_header));
	memset_s(log_content, sizeof(struct bootfail_log_content), 0, sizeof(struct bootfail_log_content));

	get_log_size(log_content, bf_meta_log, index);

	if (log_content->bf_info_start < (sizeof(struct bfi_misc_msg) +
		sizeof(struct bootfail_meta_log) + sizeof(struct bootfail_proc_param))) {
		print_err("bootfail info start is invalid!\n");
        goto exit;
	}

	int ret = read_content((char *)&bf_log_header, log_content->bf_info_start, BF_SIZE_1K);
	if (ret != 0) {
		print_err("save_to_log_file read_content bootfail_info failed !\n");
		goto exit;
	}
	bf_log_header.detail_info[sizeof(bf_log_header.detail_info) - 1] = '\0';

	save_boofail_info(log_content->bf_info_content, &bf_log_header, info, errno, stage);

	bf_log_header.binfo.recovery_result = recovery_success;
	write_content((char *)&bf_log_header, log_content->bf_info_start, BF_SIZE_1K);

	if (!(get_file_dir(info, bf_info_path, bl_log_path, kernel_log_path)))
        goto exit;

	ret = write_file(bf_info_path, log_content->bf_info_content, BF_SIZE_1K, false);
	if (ret < 0)
		print_err("save_to_log_file: write bootfail info file failed!\n");

	ret = save_log(bl_log_path, log_content->bl_log_content, bf_meta_log->logs_info[index].bl_log.start,
				log_content->bl_log_size);
	if (ret < 0)
		print_err("save_to_log_file: bl_log failed ! ret == %d\n", ret);

	ret = save_log(kernel_log_path, log_content->kernel_log_content, bf_meta_log->logs_info[index].kernel_log.start,
				log_content->kernel_log_size);
	if (ret < 0) 
		print_err("save_to_log_file: kernel_log failed ! ret == %d\n", ret);

    process_snapshot(info, bf_meta_log, index, &bf_log_header);

	save_prefabricated_files(info, &bf_log_header);
exit:
	vfree(log_content);
	log_content = NULL;
}

static bool check_recovery_info_values(struct recovery_info *recovery_log)
{
	if (recovery_log == NULL) {
		print_err("check_values: recovery_log is NULL!\n");
		return false;
	}

	if ((recovery_log->hdr.record_count < 0) || (recovery_log->hdr.record_count > RECORDS_COUNT)) {
		print_err("check_values: hdr record_count is invalid!\n");
		return false;
	}

	if ((recovery_log->hdr.count_before_succ < 0) ||
		(recovery_log->hdr.count_before_succ > recovery_log->hdr.record_count)) {
		print_err("check_values: hdr count_before_succ is invalid!\n");
		return false;
	}

	if ((recovery_log->hdr.write_idx < 0) ||
		(recovery_log->hdr.write_idx >= recovery_log->hdr.record_count)) {
		print_err("check_values: hdr write_index is invalid!\n");
		return false;
	}

	return true;
}

static bool check_recovery_info_data(const unsigned char *hash, int hash_len, unsigned char *data, int data_len)
{
	int ret;
	char *hash_string = vmalloc(SHA256_DIGEST_SIZE);
	if(hash_string == NULL) {
		print_err("vmalloc recovery_info hash_string buffer failed!\n");
		return false;
	}

	memset_s(hash_string, SHA256_DIGEST_SIZE, 0, SHA256_DIGEST_SIZE);

	ret = sha256_check(data, data_len, hash_string);
	if (ret != 0) {
		print_err("check_recovery_info_data sha256_check failed!\n");
		vfree(hash_string);
		return false;
	}

	if (memcmp(hash_string, hash, hash_len) != 0) {
		print_err("check_recovery_info_data sha256 failed!\n");
		vfree(hash_string);
		return false;
	}

	vfree(hash_string);
	return true;
}

static bool get_recovery_info_log(struct recovery_info *recovery_log, unsigned int rrecord_offset)
{
	int recovery_info_len;
	bool check;
	errno_t sec;

	int ret = read_part(get_bfi_dev_path(), rrecord_offset, (char *)recovery_log, sizeof(struct recovery_info));
	if (ret != 0) {
		print_err("read rrecord part failed!\n");
		return false;
	}
	print_info("read rrecord part success, rrecord_offset = 0x%x!\n", rrecord_offset);

	recovery_info_len = RECORDS_COUNT * sizeof(struct rrecord) + sizeof(struct rrecord_header);
	check = check_recovery_info_data(recovery_log->hdr.sha256, sizeof(recovery_log->hdr.sha256),
		(char *)&recovery_log->hdr + sizeof(recovery_log->hdr.sha256),
		recovery_info_len - sizeof(recovery_log->hdr.sha256));
	if (check) {
		return check_recovery_info_values(recovery_log);
	}
	print_err("get_recovery_info_log check recovery info failed!\n");

	check = check_recovery_info_data(recovery_log->backup_hdr.sha256, sizeof(recovery_log->backup_hdr.sha256),
		(char *)&recovery_log->backup_hdr + sizeof(recovery_log->backup_hdr.sha256),
		recovery_info_len - sizeof(recovery_log->backup_hdr.sha256));
	if (!check) {
		print_err("get_recovery_info_log check recovery backup info failed!\n");
		return false;
	}

	sec = memcpy_s((char *)recovery_log, recovery_info_len, (char *)&recovery_log->backup_hdr, recovery_info_len);
	if (sec != EOK) {
		print_err("get_recovery_info_log copy recovery backup info failed!\n");
		return false;
	}

	return check_recovery_info_values(recovery_log);
}

static void get_recovery_info_to_content(struct recovery_info_log_content *content,
										 struct rrecord *record_info, unsigned int index,
										 char *all_heal_chain, bool with_index)
{
	char index_str[BF_SIZE_32] = {0};
	char heal_chain[BF_SIZE_32] = {0};

	int len = snprintf_s(index_str, sizeof(index_str), sizeof(index_str) - 1, "_%d", index + 1);
	if (len <= 0) {
		print_err("get recovery info index snprintf error.\n");
	}

	// time
	len = snprintf_s(content->time, sizeof(content->time), sizeof(content->time) - 1,
		RECORDS_INFO_TITLE_FMT, record_info->rtc_time);
	if (len <= 0) {
		print_err("get recovery info time snprintf error.\n");
	}

	// rcvMethod description
	len = snprintf_s(content->method_str, sizeof(content->method_str), sizeof(content->method_str) - 1,
		RECORDS_INFO_METHOD_STR_FMT, with_index ? index_str : "", convert_rcv_method_to_str(record_info->real_method));
	if (len <= 0) {
		print_err("get recovery info rcvMethod description snprintf error.\n");
	}

	// rcvResult description
	len = snprintf_s(content->result_str, sizeof(content->result_str), sizeof(content->result_str) - 1,
		RECORDS_INFO_RESULT_STR_FMT, with_index ? index_str : "",
		(record_info->result == RECOVERY_SUCCESS) ? "success" : "fail");
	if (len <= 0) {
		print_err("get recovery info rcvResult description snprintf error.\n");
	}

	// rcvMethod
	len = snprintf_s(content->method, sizeof(content->method), sizeof(content->method) - 1,
		RECORDS_INFO_METHOD_FMT, with_index ? index_str : "", record_info->real_method);
	if (len <= 0) {
		print_err("get recovery info rcvMethod snprintf error.\n");
	}

	// rcvResult
	len = snprintf_s(content->result, sizeof(content->result), sizeof(content->result) - 1, RECORDS_INFO_RESULT_FMT,
		with_index ? index_str : "", (record_info->result == RECOVERY_SUCCESS) ? 1 : 0);
	if (len <= 0) {
		print_err("get recovery info rcvResult snprintf error.\n");
	}

	// selfHealChain
	len = snprintf_s(heal_chain, sizeof(heal_chain), sizeof(heal_chain) - 1,
		"%s%d", index == 0 ? "" : ", ", record_info->real_method);
	if (len <= 0) {
		print_err("get recovery info HealChain snprintf error.\n");
	}
	if (strncat_s(all_heal_chain, BF_SIZE_512, heal_chain, sizeof(heal_chain)) != EOK) {
		print_err("get recovery info all_heal_chain strncat error.\n");
	}
	len = snprintf_s(content->heal_chain, sizeof(content->heal_chain), sizeof(content->heal_chain) - 1,
		RECORDS_INFO_SELF_HEAL_CCHAIN_FMT, with_index ? index_str : "", all_heal_chain);
	if (len <= 0) {
		print_err("get recovery info selfHealChain snprintf error.\n");
	}
}

static int write_recovery_info_to_file(struct rrecord *record_info, unsigned int index,
									   char *all_heal_chain, bool with_index)
{
	struct recovery_info_log_content recovery_content;
	char *content;
	int len;

	memset_s(&recovery_content, sizeof(recovery_content), 0, sizeof(recovery_content));
	get_recovery_info_to_content(&recovery_content, record_info, index, all_heal_chain, with_index);

	content = vmalloc(BF_SIZE_2K);
	if (content == NULL) {
		print_err("vmalloc recovery_info content buffer failed!\n");
		return -1;
	}
	memset_s(content, BF_SIZE_2K, 0, BF_SIZE_2K);

	len = snprintf_s(content, BF_SIZE_2K, BF_SIZE_2K - 1, "%s\n%s\n%s\n\n%s\n%s\n%s\n\n",
		recovery_content.time, recovery_content.method_str, recovery_content.result_str,
		recovery_content.method, recovery_content.result, recovery_content.heal_chain);
	if (len <= 0) {
		print_err("write_recovery_info_to_file snprintf error!\n");
		vfree(content);
		return -1;
	}

	write_file(g_recovery_info_log_path, content, len, index != 0);
	vfree(content);
	return 0;
}

static void save_recovery_info_to_file(struct recovery_info *recovery_log, int bf_index, int bf_count)
{
	char all_heal_chain[BF_SIZE_512] = {0};
	unsigned int recovery_info_cnt;
	unsigned int count;
	int write_count;
	int log_count;
	int start_idx;
	int ret;

	recovery_info_cnt = recovery_log->hdr.count_before_succ;
	if (recovery_info_cnt == 0) {
		print_err("save recovery info failed, not find recovery_info!\n");
		return;
	}

	write_count = recovery_info_cnt < bf_index ? recovery_info_cnt : bf_index;
	log_count = recovery_info_cnt < bf_count ? recovery_info_cnt : bf_count;
	start_idx = (recovery_log->hdr.write_idx + recovery_log->hdr.record_count - log_count) %
		recovery_log->hdr.record_count;

	for (count = 0; count < write_count; ++count) {
		ret = write_recovery_info_to_file(&recovery_log->rrecord[(start_idx + count) % recovery_log->hdr.record_count],
			count, all_heal_chain, count != (write_count - 1));
		if (ret != 0) {
			print_err("save recovery info failed, write file failed! count = %u, start_idx = %d.\n", count, start_idx);
		}
	}
}

static void update_records(struct recovery_info *recovery_log)
{
	int index = (recovery_log->hdr.write_idx + (recovery_log->hdr.record_count - 1)) % recovery_log->hdr.record_count;
	recovery_log->rrecord[index].result = RECOVERY_SUCCESS;
}

static void update_recovery_info(struct recovery_info *recovery_log, unsigned int rrecord_offset)
{
	unsigned int recovery_info_len;
	int ret;

	recovery_log->hdr.is_download_succ = 0;
	recovery_log->hdr.count_before_succ = 0;

	recovery_info_len = RECORDS_COUNT * sizeof(struct rrecord) + sizeof(struct rrecord_header);
	ret = sha256_check((char *)&recovery_log->hdr + sizeof(recovery_log->hdr.sha256),
		recovery_info_len - sizeof(recovery_log->hdr.sha256), (char *)&recovery_log->hdr.sha256);
	if (ret != 0) {
		print_err("update_records Calculate sha256 failed!\n");
		return;
	}

	write_content((char *)recovery_log, rrecord_offset, recovery_info_len);
	write_content((char *)recovery_log, rrecord_offset + recovery_info_len, recovery_info_len);
}

int parse_bootfail(void)
{
	struct bootfail_meta_log bf_meta_log;
	struct recovery_info *recovery_log;
	bool load_recovery_log;
	unsigned int i = 0;

	memset_s(&bf_meta_log, sizeof(struct bootfail_meta_log), 0, sizeof(struct bootfail_meta_log));
	bool ret = get_meta_log(&bf_meta_log);
	if (!ret) {
		print_err("parse_bootfail, get_meta_log faild!\n");
		return -1;
	}
	unsigned int log_count = bf_meta_log.log_count;
	if (log_count == 0) {
		print_err("parse_bootfail, not find bootfail!\n");
		return -1;
	}

	recovery_log = (struct recovery_info *)vmalloc(sizeof(struct recovery_info));
	if (recovery_log == NULL) {
		print_err("parse_bootfail malloc recovery_log buffer failed!\n");
		return -1;
	}
	memset_s(recovery_log, sizeof(struct recovery_info), 0, sizeof(struct recovery_info));

	load_recovery_log = get_recovery_info_log(recovery_log, bf_meta_log.rrecord_offset);
	if (!load_recovery_log) {
		print_err("parse_bootfail, get_recovery_info_log faild!\n");
	} else {
		update_records(recovery_log);
	}
	print_err("parse_bootfail!\n");

	struct error_info info;
	char stage[BF_SIZE_128] = {0};
	char errnum[BF_SIZE_128] = {0};
	
	for (i = 0; i < log_count; ++i) {
		memset_s(&info, sizeof(struct error_info), 0, sizeof(struct error_info));
		memset_s(stage, BF_SIZE_128, 0, BF_SIZE_128);
		memset_s(errnum, BF_SIZE_128, 0, BF_SIZE_128);
		unsigned int index = bf_meta_log.log_max_count ? (bf_meta_log.log_max_count -
							(bf_meta_log.log_count - bf_meta_log.write_idx) + i) % bf_meta_log.log_max_count : 0;
		save_log_to_file(&info, &bf_meta_log, index, errnum, stage);
		if (load_recovery_log)
			save_recovery_info_to_file(recovery_log, i + 1, log_count);

		msleep(SLEEP_TIME);
		send_bbox_notify((struct error_info *)&info, stage, errnum);
	}
	if (load_recovery_log)
		update_recovery_info(recovery_log, bf_meta_log.rrecord_offset);

	vfree(recovery_log);
	return 0;
}

#ifdef CONFIG_SHUT_DETECTOR
static void rtc_time_transfer(char *time, unsigned long long timestamp, struct error_info *info)
{
	struct rtc_time real_time;
	const int format_number = 1;

	rtc_time64_to_tm(timestamp, &real_time);
	int len = snprintf_s(time, TIMESTAMP_MAX_LEN, TIMESTAMP_MAX_LEN - 1, "%04d%02d%02d%02d%02d%02d-%08d",
		real_time.tm_year + 1900, real_time.tm_mon + 1, real_time.tm_mday,
		real_time.tm_hour, real_time.tm_min, real_time.tm_sec, format_number);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return;
	}

	len = snprintf_s(info->error_time, TIMESTAMP_MAX_LEN, TIMESTAMP_MAX_LEN - 1, "%s", time);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return;
	}
}

static void get_shutfail_log_path(char *bf_info_path, char *klog_path, char *time)
{
	char log_dir[BF_SIZE_128] = {0};
	const char *bf_info = "bootfail_info";
	const char *last_kmsg = "last_kmsg";
	static const unsigned int format_number = 0;

	int len = snprintf_s(log_dir, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s", CONFIG_BLACKBOX_LOG_ROOT_PATH, time);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return;
	}

	create_log_dir(log_dir);
	len = snprintf_s(bf_info_path, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s_%u", log_dir, bf_info, format_number);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return;
	}

	len = snprintf_s(klog_path, BF_SIZE_128, BF_SIZE_128 - 1, "%s/%s_%u", log_dir, last_kmsg, format_number);
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return;
	}
}

static void clear_shutfail_info()
{
	struct shutfail_log_header sf_log_header;
	memset_s(&sf_log_header, sizeof(struct shutfail_log_header), 0, sizeof(struct shutfail_log_header));
	int ret = write_part(get_sfi_dev_path(), get_sfi_dev_offset(), (const char *)&sf_log_header,
						sizeof(struct shutfail_log_header));
	if (ret != 0)
		print_err("clear_shutfail_info, clear shutfail log header failed!\n");
}

static int get_shut_header(struct shutfail_log_header *sf_log_header)
{
	memset_s((char *)sf_log_header, sizeof(struct shutfail_log_header), 0, sizeof(struct shutfail_log_header));

	int ret = read_part(get_sfi_dev_path(), get_sfi_dev_offset(),
		(char *)sf_log_header, sizeof(struct shutfail_log_header));
	if (ret != 0) {
		print_err("read log from bootfail_info partition failed!\n");
		return -1;
	}

	if (sf_log_header->kernel_log_size <= 0) {
		print_err("invalid shutfail kernel log size!\n");
		return -1;
	}
	return 0;
}

static int save_shutfail_info(struct shutfail_log_header *sf_log_header, struct shutfail_info *sinfo,
			char *bf_info_content, char *bf_info_path)
{
	int len = snprintf_s(bf_info_content, BF_SIZE_256, BF_SIZE_256 - 1, "error desc:%s\nSHUT_FAIL_TIME: %s\n"
			"SHUT_FAIL_STAGENO: %d\nSHUT_FAIL_STAGE:%s\n", (char *)(sinfo->errnum), (char *)(sinfo->time),
			sf_log_header->sinfo.stage, (char *)(sinfo->stage));
	if (len <= 0) {
		print_err("%d append string failed", __LINE__);
		return -1;
	}

	int ret = write_file(bf_info_path, bf_info_content, len, false);
	if (ret < 0) {
		print_err("parse_shutfail: write bootfail info file failed!\n");
        return -1;
    }

    return 0;
}

static int save_shutfail_kmsg(struct shutfail_log_header *sf_log_header, char *klog_path)
{
    int kmsg_size = min(BF_SIZE_512K, sf_log_header->kernel_log_size);

    char *klog = vmalloc(kmsg_size);
	if (klog == NULL) {
		print_err("malloc shutfail klog buffer failed!\n");
		return -1;
	}

	int ret = read_part(get_sfi_dev_path(), get_sfi_dev_offset() + sizeof(struct shutfail_log_header),
					klog, kmsg_size);
	if (ret != 0) {
		print_err("read part to get shutfail log failed!\n");
		vfree(klog);
		return -1;
	}

	ret = write_file(klog_path, klog, kmsg_size, false);
	if (ret < 0) {
		print_err("parse_shutfail: write klog file failed!\n");
		vfree(klog);
        return -1;
    }

    vfree(klog);
    return 0;
}


static int save_logs(struct shutfail_log_header *sf_log_header, struct shutfail_info *sinfo)
{
	char bf_info_content[BF_SIZE_256] = {0};
    char bf_info_path[BF_SIZE_128] = {0};
	char klog_path[BF_SIZE_128] = {0};

    get_shutfail_log_path(bf_info_path, klog_path, (char *)sinfo->time);

    int ret = save_shutfail_info(sf_log_header, sinfo, bf_info_content, bf_info_path);
    if (ret != 0) {
        print_err("shutfail save shutfail info failed!\n");
        return -1;
    }

    ret = save_shutfail_kmsg(sf_log_header, klog_path);
    if (ret != 0) {
        print_err("shutfail save shutfail kmsg failed!\n");
        return -1;
    }

    return 0;
}

int parse_shutfail()
{
	struct shutfail_log_header *sf_log_header = (struct shutfail_log_header *)vmalloc(sizeof(struct shutfail_log_header));
	if (sf_log_header == NULL) {
		print_err("vmalloc sf_log_header failed!\n");
		return -1;
	}

	memset_s((char *)sf_log_header, sizeof(struct shutfail_log_header), 0, sizeof(struct shutfail_log_header));

	int ret = get_shut_header(sf_log_header);
	if (ret != 0) {
		print_err("parse_shutfail get_shut_header failed");
		vfree(sf_log_header);
		return -1;
	}

	struct error_info *info = (struct error_info *)vmalloc(sizeof(struct error_info));
	if (info == NULL) {
		print_err("vmalloc info failed!\n");
        vfree(sf_log_header);
		return -1;
	}
 
	struct shutfail_info *sinfo = (struct shutfail_info *)vmalloc(sizeof(struct shutfail_info));
	if (sinfo == NULL) {
		print_err("vmalloc sinfo failed!\n");
        vfree(sf_log_header);
		vfree(info);
		return -1;
	}

    memset_s((char *)info, sizeof(struct error_info), 0, sizeof(struct error_info));
    memset_s((char *)sinfo, sizeof(struct shutfail_info), 0, sizeof(struct shutfail_info));

	rtc_time_transfer((char *)sinfo->time, sf_log_header->sinfo.rtc_time, info);
    convert_orig_data((char *)(sinfo->stage), (char *)(sinfo->errnum), sf_log_header->sinfo.stage, SHUT_FAIL_ERRNO);

    ret = save_logs(sf_log_header, sinfo);
    if (ret != 0) {
        print_err("save log failed!\n");
    }

    send_bbox_notify((struct error_info *)&info, (char *)(sinfo->stage), (char *)(sinfo->errnum));

	vfree(sinfo);
	vfree(info);
	vfree(sf_log_header);
    return 0;
}
#endif

void clear_info(void)
{
	clear_bfi_misc();
	clean_bootfail_info();
#ifdef CONFIG_SHUT_DETECTOR
	clear_shutfail_info();
#endif
}

int boot_completed()
{
	int ret = 0;
#ifdef CONFIG_SHUT_DETECTOR
	enum shut_stage last_shut_stage = SHUT_STAGE_INVALID;

	(void)get_shut_stage(&last_shut_stage);
	if ((last_shut_stage != SHUT_STAGE_INVALID) && (last_shut_stage != SHUT_STAGE_SUCC)) {
		print_info("start to parse shutfail!\n");
		ret = parse_shutfail();
		if (ret < 0)
			print_err("parse shutfail failed!\n");
	}
#endif
	ret = parse_bootfail();
	if (ret < 0)
		print_err("parse bootfail failed!\n");

	return 0;
}
