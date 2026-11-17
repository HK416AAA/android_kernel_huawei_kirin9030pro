/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: implement the platform interface for boot fail
 * Author: qidechun
 * Create: 2019-03-05
 */

/* ----includes ---- */
#include <linux/printk.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/stacktrace.h>
#include <mntn_public_interface.h>
#include <hwbootfail/chipsets/bootfail_hisi.h>
#include <hwbootfail/core/boot_detector.h>
#include <hwbootfail/chipsets/common/bootfail_common.h>
#include <hwbootfail/chipsets/common/bootfail_chipsets.h>
#include <hwbootfail/chipsets/common/adapter_common.h>
#include <platform_include/basicplatform/linux/mfd/pmic_mntn.h>
#include <securec.h>
#include "adapter_hisi.h"
#include "ocp_hisi.h"
#ifdef CONFIG_CPU_FAULT_HWDEGRADE_CDC
#include <platform_include/basicplatform/linux/rdr_ap_hook.h>
#include <linux/vmalloc.h>
#endif
#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
#include <asm/stacktrace.h>
#include <linux/mutex.h>
#endif

/* ----local macroes ---- */
#define BFI_PART_SIZE (0x7E0000) /* 8MB -128 KB */
#define NS_PER_SEC 1000000000
#define BOOT_SUCC_TIME (90) /* unit: second */
#define SHORT_TIMER_TIMEOUT_VALUE (1000 * 60 * 10)
#define LONG_TIMER_TIMEOUT_VALUE (1000 * 60 * 30)
#define ACTION_TIMER_TIMEOUT_VALUE (1000 * 60 * 30)
#define UFS_TYPE_OFFSET 0x10
#define UFS_FAULT_SIMULATION_SIZE (0x20)
#ifdef CONFIG_SHUT_DETECTOR
#define SFI_PART_SIZE (0x80200) /* 512KB + 512B */
#define SHUT_TIMER_TIMEOUT_VALUE (1000 * 60)
#endif

#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
#define MAX_BACKTRACE_COUNT 5
#endif
/* ---- local prototypes ---- */
/* ---- local static variables ---- */
static bool is_poweroff_charge;
static uintptr_t panic_tag_addr;
#ifdef CONFIG_CPU_FAULT_HWDEGRADE_CDC
static uintptr_t panic_info_addr;
#endif

#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
static uintptr_t panic_stack_addr;
static bool usb_panic = false;
static const int STACK_LEN = 1024;
static const long long int MAGIC_NUM = 0x86868886;
static const int KEY_MAXLEN = 30;
static const char NO_USB_KEYWORD[] = "NO_USB_KEYWORD";
static const char POWERKEY_REBOOT_FLAG[] = "HM_POWERKEY_REBOOT";
static const int USB_STACK_KEY_COUNT = 10;
static const int USB_PANIC_BLOCK_TIME = -1;
struct usb_info {
	long long int magic;
	char key[KEY_MAXLEN];
	int blocked_time;
	unsigned long long rtc;
};
static const long long int USB_HUNGTASK_INFO_SIZE = sizeof(struct usb_info) + sizeof(char);
static const char usb_keyword[USB_STACK_KEY_COUNT][KEY_MAXLEN] = {
	"exfat",
	"fat_",
	"vfat_",
	"usb_",
	"sdcardfs_",
	"otghub_ioctl",
	"sd_",
	"scsi_",
	"blkdev",
	"blk_"
};
/* ---- local function definitions --- */
static void init_usb_phymem(const void *phys_mem_addr, const unsigned long len)
{
	for (unsigned long i = 0; i < len; i++) {
		writeb(0, (char*)(phys_mem_addr + i));
	}
}

static void get_hungtask_panic_stacktrace(struct task_struct *tsk, char *stack, int stack_len)
{
	unsigned int len = 0;
	struct stackframe frame;
	unsigned long last_pc = 0;
	unsigned long count = 0;
	start_backtrace(&frame, thread_saved_fp(tsk), thread_saved_pc(tsk));
	do {
		len = strlen(stack);
		if (len >= stack_len) {
			print_err("stack_len: %d, overflow\n", (int)len);
			stack[stack_len - 1] = '\0';
			break;
		}
 
		if (frame.pc == last_pc) {
			count++;
			if (count >= MAX_BACKTRACE_COUNT) {
				print_err("%s(backtrace infinite loop:fp %p pc %p)\n",
					__func__, (void *)frame.fp, (void *)frame.pc);
				break;
			}
		} else {
			last_pc = frame.pc;
			count = 0;
		}
		scnprintf(stack + len, stack_len - len, "%pS\n", (void *)(uintptr_t)frame.pc);
	} while (!unwind_frame(tsk, &frame));
	stack[min(strlen(stack), stack_len - 1)] = '\0';
}

static int find_usb_keyword(const char *stack, char *key, int len)
{
	int num_keyword = ARRAY_SIZE(usb_keyword);
	while (*stack) {
        while (*stack && *stack == '\n') {
			stack++;
		}
		if (*stack == NULL) {
			break;
		}
		for (int i = 0; i < num_keyword; i++) {
			if (strncmp(stack, usb_keyword[i], strlen(usb_keyword[i])) == 0) {
				return strncpy_s(key, len, usb_keyword[i], strlen(usb_keyword[i]));
			}
		}
        while (*stack && *stack != '\n') {
			stack++;
		}
    }
	return strncpy_s(key, len, NO_USB_KEYWORD, strlen(NO_USB_KEYWORD));
}

static unsigned long long get_ktime_sec()
{
	struct timespec64 cur_time;
	ktime_get_real_ts64(&cur_time);
	return (unsigned long long)cur_time.tv_sec;
}

static void update_usb_panic_info(char *pbuf, const int buf_size, const char *key, const int hungtask_time)
{	
	struct usb_info info = {.magic = MAGIC_NUM, .blocked_time = hungtask_time, .rtc = get_ktime_sec()};
	memcpy_s(info.key, KEY_MAXLEN, key, strlen(key));
	char *buf = (char *)&info;
	int len = min(buf_size - 1, sizeof(struct usb_info));
	for (int i = 0; i < len; ++i) {
		writeb(buf[i], pbuf + i);
	}
	print_info("update_usb_panic_info success: info key:%s, blocked_time:%d, rtc:%lld\n",
				info.key, info.blocked_time, info.rtc);
}

static void get_stack_from_phymem(const void *phys_mem_addr, const unsigned long data_len, char *info)
{
	char *psrc = (char *)phys_mem_addr;
	for (int i = 0; i < data_len - 1; i++) {
		info[i] = readb(psrc);
		psrc++;
	}
	info[data_len - 1] = '\0';
}

static void process_usb_hungtask(const struct usb_hungtask_tsk_s hungtask_tsk)
{
	if (hungtask_tsk.tsk == NULL || hungtask_tsk.magic != MAGIC_NUM) {	
		print_err("Hungtask_tsk is null or magic is error\n");
		return ;
	}
	char stack[STACK_LEN] = {0};
	get_hungtask_panic_stacktrace(hungtask_tsk.tsk, stack, STACK_LEN);
	char key[KEY_MAXLEN] = {0};
	if (find_usb_keyword(stack, key, KEY_MAXLEN) != 0) {
		print_err("Failed to search for keywords in USB hungtask stack\n");
		return ;
	}
	update_usb_panic_info((char*)panic_stack_addr, USB_HUNGTASK_INFO_SIZE, key, hungtask_tsk.hungtask_time);
}

static void proccess_usb_panic(const void *phys_mem_addr)
{
	if (!usb_panic) {
		print_err("not usb panic\n");
		return;
	}

	char stack[STACK_LEN] = {0};
	get_stack_from_phymem(phys_mem_addr, STACK_LEN, stack);

	char key[KEY_MAXLEN] = {0};
	if (find_usb_keyword(stack, key, KEY_MAXLEN) != 0) {
		print_err("Failed to search for keywords in USB panic stack\n");
		return;
	}
	update_usb_panic_info((char*)(panic_stack_addr) + USB_HUNGTASK_INFO_SIZE,
						SUB_RESERVED_USB_PANIC_INFO_PHYMEM_SIZE - USB_HUNGTASK_INFO_SIZE, key, USB_PANIC_BLOCK_TIME);
}

void save_powerkey_flag(void)
{
	print_err("Save the powerkey reboot flag to rrecord for USB isolation solution");
	(void)write_part(BFI_DEV_PATH, POWERKEY_INFO_OFFSET, POWERKEY_REBOOT_FLAG, 
					min(sizeof(POWERKEY_REBOOT_FLAG), POWERKEY_INFO_SIZE));
}

int read_usb_fault_info(char* buf)
{
	if (buf == NULL) {
		print_err("Error: Buffer is NULL\n");
		return -1;
	}
	int ret = read_part(get_bfi_dev_path(), USB_FUALT_INFO_OFFSET, buf, USB_FUALT_INFO_SIZE);
	if (ret != 0) {
		print_err("Failed to read USB fault info from rrecord\n");
	}
	return ret;
}

int write_usb_fault_info(char* buf)
{
	if (buf == NULL) {
		print_err("Error: Buffer is NULL\n");
		return -1;
	}
	int ret = write_part(get_bfi_dev_path(), USB_FUALT_INFO_OFFSET, buf, USB_FUALT_INFO_SIZE);
	if (ret != 0) {
		print_err("Failed to write USB fault info to rrecord\n");
	}
	return ret;
}

void process_usb_isolation_info(void)
{
	panic_stack_addr = (uintptr_t)ioremap((phys_addr_t)SUB_RESERVED_USB_PANIC_INFO_PHYMEM_BASE,
		SUB_RESERVED_USB_PANIC_INFO_PHYMEM_SIZE);
	if (panic_stack_addr != 0) {
		init_usb_phymem(panic_stack_addr, SUB_RESERVED_USB_PANIC_INFO_PHYMEM_SIZE);
		register_usb_hungtask_tsk(process_usb_hungtask);
	}
}
#endif

unsigned int get_bootup_time(void)
{
	unsigned long long ts;

#ifdef CONFIG_DFX_TIME
	ts = dfx_getcurtime(); /* ns */
#else
	ts = sched_clock();
#endif

	return (unsigned int)(ts / (NS_PER_SEC));
}

static int __init early_parse_power_off_charge_cmdline(char *p)
{
	if (p != NULL) {
		is_poweroff_charge = (strncmp(p, "charger",
			strlen("charger")) == 0) ? true : false;
	}

	return 0;
}
early_param("ohos.boot.mode", early_parse_power_off_charge_cmdline);

void set_valid_long_press_flag(void)
{
	union bfi_part_header hdr;
	enum boot_stage bootstage;

	memset(&hdr, 0, sizeof(hdr));
	if (is_erecovery_mode()) {
		print_info("save long press log in erecovery mode!\n");
		/*lint -e666*/
		strncpy(hdr.misc_msg.command, ERECOVERY_LONG_PRESS_TAG,
			min(strlen(ERECOVERY_LONG_PRESS_TAG),
			sizeof(hdr.misc_msg.command) - 1));
		/*lint +e666*/
	} else {
		if (check_recovery_mode()) {
			print_info("recovery mode!\n");
			return;
		}

		if (is_poweroff_charge) {
			print_info("charger mode!\n");
			return;
		}

		get_boot_stage(&bootstage);
		if (!((get_bootup_time() > BOOT_SUCC_TIME) &&
			(bootstage < BOOT_SUCC_STAGE))) {
			print_info("mistakenly press!\n");
			return;
		}
		print_info("save long press log in normal mode!\n");
		/*lint -e666*/
		strncpy(hdr.misc_msg.command, NORMAL_LONG_PRESS_TAG,
			min(strlen(NORMAL_LONG_PRESS_TAG),
			sizeof(hdr.misc_msg.command) - 1));
		/*lint +e666*/
	}
	(void)write_part(BFI_DEV_PATH, 0, (const char *)&hdr, sizeof(hdr));
#ifdef CONFIG_BOOT_DETECTOR_SINGLE_FRAME
	char log_path[BF_SIZE_256] = {0};
	struct bootfail_proc_param pparam = {0};
	pparam.binfo.bootfail_errno = KERNEL_SYSTEM_FREEZE;
	pparam.binfo.stage = bootstage;
	pparam.desc_errno = 1; //1: LONG_PRESS
	bootfail_callback(FAULT_SAVE_LOG, log_path, BF_SIZE_256, &pparam);
	int ret = strncpy_s(hdr.misc_msg.log_path, sizeof(hdr.misc_msg.log_path) - 1, log_path, strlen(log_path));
	if (ret != 0)
		print_err("strncpy_s error ret: %d\n", ret);
	(void)write_part(BFI_DEV_PATH, 0, (const char *)&hdr, sizeof(hdr));
#endif
}

unsigned int get_long_timer_timeout_value(void)
{
	return LONG_TIMER_TIMEOUT_VALUE;
}

unsigned int get_short_timer_timeout_value(void)
{
	return SHORT_TIMER_TIMEOUT_VALUE;
}

unsigned int get_action_timer_timeout_value(void)
{
	return ACTION_TIMER_TIMEOUT_VALUE;
}

static void dump_stacktrace(char *pbuf, size_t buf_size)
{
	int i;
	size_t stack_len = 0;
	size_t com_len = 0;
	unsigned long entries[20]; /* max backword entries*/
	char tmp_buf[384]; /* max size of tmp_buf */
	char com_buf[40]; /* max size of com_buf */
	bool find_panic = false;
	unsigned int nr_entries;

	if (pbuf == NULL || buf_size == 0)
		return;

	for (i = 0; i < (int)buf_size; i++)
		writeb(0, pbuf + i);
	memset(tmp_buf, 0, sizeof(tmp_buf));
	memset(com_buf, 0, sizeof(com_buf));
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	nr_entries = stack_trace_save(entries, ARRAY_SIZE(entries), 0);
#else
	struct stack_trace trace;
	trace.nr_entries = 0;
	trace.max_entries = (unsigned int)ARRAY_SIZE(entries);
	trace.entries = entries;
	trace.skip = 0;
	save_stack_trace(&trace);
	nr_entries = (int)trace.nr_entries;
#endif
	scnprintf(com_buf, sizeof(com_buf), "Comm:%s,CPU:%d\n",
		current->comm, raw_smp_processor_id());
	for (i = 0; i < nr_entries; i++) {
		stack_len = strlen(tmp_buf);
		if (stack_len >= sizeof(tmp_buf)) {
			print_err("stack_len: %d, overflow\n", (int)stack_len);
			tmp_buf[sizeof(tmp_buf) - 1] = '\0';
			break;
		}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		scnprintf(tmp_buf + stack_len, sizeof(tmp_buf) - stack_len,
			"%pS\n", (void *)(uintptr_t)entries[i]);
#else
		scnprintf(tmp_buf + stack_len, sizeof(tmp_buf) - stack_len,
			"%pS\n", (void *)(uintptr_t)trace.entries[i]);
#endif
		if (!find_panic) {
			if (strncmp(tmp_buf, "panic", strlen("panic")) == 0) {
				find_panic = true;
#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
				usb_panic = true;
#endif
			}
			else
				memset(tmp_buf, 0, sizeof(tmp_buf));
		}
	}

	com_len = min(buf_size - 1, strlen(com_buf)); //lint !e666
	for (i = 0; i < (int)com_len; i++)
		writeb(com_buf[i], pbuf + i);
	if (com_len >= buf_size - 1)
		return;
	stack_len = min(buf_size - com_len - 1, strlen(tmp_buf)); //lint !e666
	for (i = 0; i < (int)stack_len; i++)
		writeb(tmp_buf[i], pbuf + com_len + i);
}

static int process_panic_event(struct notifier_block *self,
	unsigned long val,
	void *data)
{
	if (check_recovery_mode() && panic_tag_addr != 0) {
		print_err("panic in recovery mode!\n");
		writel(is_erecovery_mode() ? PANIC_IN_ERECOVERY : PANIC_IN_RECOVERY,
			(char *)panic_tag_addr);
	} else if (panic_tag_addr != 0) {
		print_err("dump stack trace for panic @ %p!\n",
			(void *)panic_tag_addr);
		dump_stacktrace((char *)panic_tag_addr, BF_SIZE_1K);
		print_err("stack trace:\n%s\n", (char *)panic_tag_addr);
#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
		proccess_usb_panic(panic_tag_addr);
#endif
	}

	return NOTIFY_DONE;
}

char *get_bfi_dev_path(void)
{
	return BFI_DEV_PATH;
}

size_t get_bfi_part_size(void)
{
	return (size_t)BFI_PART_SIZE;
}

#ifdef CONFIG_SHUT_DETECTOR
unsigned int get_shut_timer_timeout_value(void)
{
	return SHUT_TIMER_TIMEOUT_VALUE;
}

char *get_sfi_dev_path(void)
{
	return SFI_DEV_PATH;
}

size_t get_sfi_part_size(void)
{
	return (size_t)SFI_PART_SIZE;
}

unsigned int get_sfi_dev_offset(void)
{
	return SFI_DEV_OFFSET;
}
#endif

static struct notifier_block panic_event_nb = {
	.notifier_call	= process_panic_event,
	.priority	= INT_MAX,
};

#ifdef CONFIG_BOOT_DETECTOR_DBG
long simulate_storge_rdonly(unsigned long arg)
{
	int ufs_type;
	char *paddr = NULL;
	unsigned int *value = NULL;

	if (copy_from_user(&ufs_type, (int *)(uintptr_t)arg,
		sizeof(int)) != 0) {
		print_err("Failed to copy flag from user!\n");
		return -EFAULT;
	}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	paddr = ioremap(SUB_RESERVED_UNUSED_PHYMEM_BASE,
		UFS_FAULT_SIMULATION_SIZE);
#else
	paddr = ioremap_nocache(SUB_RESERVED_UNUSED_PHYMEM_BASE,
		UFS_FAULT_SIMULATION_SIZE);
#endif
	if (paddr != NULL) {
		value = (unsigned int *)paddr;
		writel(0x0, value++);
		writel(0x0, value++);
		writel(0x0, value++);
		writel(ufs_type, (paddr + UFS_TYPE_OFFSET));
		iounmap(paddr);
		print_err("simulate storge rdonly successfully!\n");
	}

	return 0;
}
#else
long simulate_storge_rdonly(unsigned long arg)
{
	return -EFAULT;
}
#endif

#ifdef CONFIG_CPU_FAULT_HWDEGRADE_CDC
static void soc_panic_info_save(struct dfx_exc_info_s  rec)
{
	size_t len = 0;
	char *buf = (char *)&rec;
#ifdef CONFIG_M536_DDRFAULT_TOLERANCE
	len = min(SUB_RESERVED_DDRFAULT_PHYMEM_SIZE, sizeof(struct dfx_exc_info_s));
#else
	len = min(SUB_RESERVED_SOC_PANIC_INFO_PHYMEM_SIZE, sizeof(struct dfx_exc_info_s));
#endif
	for (int i = 0; i < (int)len; ++i)
		writeb(buf[i], panic_info_addr+i);
}

long read_soc_panic_info(char* buf)
{
	long ret = 0;
	ret = read_part(get_bfi_dev_path(), SOC_PANIC_INFO_OFFSET, buf, SOC_PANIC_INFO_SIZE);
	if (ret != 0) {
		print_err("read rrecord fail\n");
		return ret;
	}
	return ret;
}

long write_soc_panic_info(char* buf)
{
	long ret = 0;
	ret = write_part(get_bfi_dev_path(), SOC_PANIC_INFO_OFFSET, buf, SOC_PANIC_INFO_SIZE);
	if (ret != 0) {
		print_err("write rrecord fail\n");
		return ret;
	}
	return ret;
}
#endif

static void panic_register(void)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	panic_tag_addr = (uintptr_t)ioremap((phys_addr_t)SUB_RESERVED_UNUSED_PHYMEM_BASE, BF_SIZE_1K);
#ifdef CONFIG_CPU_FAULT_HWDEGRADE_CDC
#ifdef CONFIG_M536_DDRFAULT_TOLERANCE
	panic_info_addr = (uintptr_t)ioremap((phys_addr_t)SUB_RESERVED_DDRFAULT_PHYMEM_BASE,
	    SUB_RESERVED_DDRFAULT_PHYMEM_SIZE);
#else
	panic_info_addr = (uintptr_t)ioremap((phys_addr_t)SUB_RESERVED_SOC_PANIC_INFO_PHYMEM_BASE,
		SUB_RESERVED_SOC_PANIC_INFO_PHYMEM_SIZE);
#endif
#endif
#else
	/*lint -e446*/
	panic_tag_addr = (uintptr_t)ioremap_nocache((phys_addr_t)SUB_RESERVED_UNUSED_PHYMEM_BASE, BF_SIZE_1K);
#endif
#ifdef CONFIG_USB_FAULT_ISOLATION_CDC
	process_usb_isolation_info();
#endif
	if (panic_tag_addr != 0) {
		print_err("Register panic notifier in bootfail!\n");
		atomic_notifier_chain_register(&panic_notifier_list, &panic_event_nb);
	}
#ifdef CONFIG_CPU_FAULT_HWDEGRADE_CDC
	if (panic_info_addr != 0)
		register_dfx_exc_info(soc_panic_info_save);
#endif
}

int __init bootfail_init(void)
{
	int ret;
	enum bootfail_errorcode errcode;
	struct ocp_init_param ocp_param;
	struct common_init_params init_param;
	struct adapter adp;

	panic_register();
	memset(&init_param, 0, sizeof(init_param));
	if (bootfail_common_init(&init_param) != 0) {
		print_err("int bootfail common failed!\n");
		return -1;
	}
	memset(&adp, 0, sizeof(adp));
	if (hisi_adapter_init(&adp) != 0) {
		print_err("int adapter failed!\n");
		return -1;
	}

	errcode = boot_detector_init(&adp);
	if (errcode != BF_OK) {
		print_err("init boot detector failed [ret: %d]\n", errcode);
		return -1;
	}

	errcode = set_boot_stage(KERNEL_STAGE); // set kernel stage
	print_err("set KERNEL_STAGE [%d]\n", errcode);

	memset(&ocp_param, 0, sizeof(ocp_param)); // process OCP for HISI
	ret = ocp_init(&ocp_param);
	if (ret != 0)
		print_err("device_ocp_init failed!\n");

	return 0;
}

module_init(bootfail_init);
MODULE_LICENSE("GPL");
