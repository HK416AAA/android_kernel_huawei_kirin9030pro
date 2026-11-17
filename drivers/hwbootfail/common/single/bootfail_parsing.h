

#ifndef BOOTFAIL_PARSING_H
#define BOOTFAIL_PARSING_H

#include <hwbootfail/core/boot_recovery.h>
#include <hwbootfail/chipsets/common/bootfail_common.h>

struct bootfail_log_content {
	unsigned int bl_log_size;
	unsigned int kernel_log_size;
	unsigned int bf_info_start;
	char bf_info_content[BF_SIZE_1K];
	char bl_log_content[SUB_RESERVED_FASTBOOT_LOG_PYHMEM_SIZE];
	char kernel_log_content[LAST_KMSG_SIZE];
};

struct method_map {
	int method;
	const char *method_dec;
};

struct recovery_info_log_content {
	char time[BF_SIZE_128];
	char method_str[BF_SIZE_128];
	char result_str[BF_SIZE_64];
	char method[BF_SIZE_64];
	char result[BF_SIZE_64];
	char heal_chain[BF_SIZE_512];
};

static char error_name_bl1_core_dev_fault[] = "BL1 core device fault";
static char error_name_bl1_non_core_dev_fault[] = "BL1 non core device fault";
static char error_name_bl1_img_fault[] = "BL1 image damaged or verification failed";
static char error_name_bl1_system_crash[] = "BL1 crash";
static char error_name_bl1_system_freeze[] = "BL1 freeze";
static char error_name_bl1_bad_env[] = "BL1 bad working env";
static char error_name_bl2_core_dev_fault[] = "BL2 core device fault";
static char error_name_bl2_non_core_dev_fault[] = "BL2 non core device fault";
static char error_name_bl2_img_fault[] = "BL2 image damaged or verification failed";
static char error_name_bl2_system_crash[] = "BL2 crash";
static char error_name_bl2_system_freeze[] = "BL2 freeze";
static char error_name_bl2_bad_env[] = "BL2 bad working env";
static char error_name_kernel_core_dev_fault[] = "Kernel core device fault";
static char error_name_kernel_non_core_dev_fault[] = "Kernel non core device fault";
static char error_name_kernel_img_fault[] = "Kernel image damaged or verification failed";
static char error_name_kernel_subsys_fault[] = "Kernel susystem fault";
static char error_name_kernel_system_crash[] = "Kernel crash";
static char error_name_kernel_system_freeze[] = "Kernel freeze";
static char error_name_kernel_bad_env[] = "Kernel bad working env";
static char error_name_native_core_dev_fault[] = "Native core device fault";
static char error_name_native_non_core_dev_fault[] = "Native non core device fault";
static char error_name_native_service_crash[] = "Native critical service crash";
static char error_name_native_service_freeze[] = "Native critical service freeze";
static char error_name_native_data_part_mount_fail[] = "Native /data mount failed";
static char error_name_native_data_fsck_fail[] = "Native data fsck failed";
static char error_name_native_data_part_mount_ro[] = "Native /data mounted RO";
static char error_name_native_data_damaged[] = "Native critical data damaged";
static char error_name_native_data_mount_fail[] = "Native critical part mount failed";
static char error_name_native_subsys_fault[] = "Native subsystem fault";
static char error_name_native_system_crash[] = "Native crash";
static char error_name_native_system_freeze[] = "Native freeze";
static char error_name_native_bad_env[] = "Native bad working env";
static char error_name_framework_core_dev_fault[] = "Framework core device fault";
static char error_name_framework_non_core_dev_fault[] = "Framework non core device fault";
static char error_name_framework_service_crash[] = "Framework critical service crash";
static char error_name_framework_service_freeze[] = "Framework critical service freeze";
static char error_name_framework_data_damaged[] = "Framework critical data damaged";
static char error_name_framework_subsys_fault[] = "Framework subsystem fault";
static char error_name_framework_system_crash[] = "Framework crash";
static char error_name_framework_system_freeze[] = "Framework freeze";
static char error_name_framework_bad_env[] = "Framework bad working env";
static char error_name_hardware_core_dev_fault[] = "Hardware core dev fault";
static char error_name_hardware_storage_fault[] = "Hardware storage fault";
static char error_name_hardware_non_core_dev_fault[] = "Hardware non core dev fault";

// method description
static const char g_method_bl1_do_nothing[] = "BL1 do nothing";
static const char g_method_bl1_reboot[] = "BL1 reboot";
static const char g_method_bl1_factory_rest[] = "BL1 factory reset";
static const char g_method_bl1_safe_mode[] = "BL1 safe mode";
static const char g_method_bl1_bopd[] = "BL1 normal BoPD";
static const char g_method_bl1_degrade_bopd[] = "BL1 hardware degrade BoPD";
static const char g_method_bl1_ufs_rdonly_bopd[] = "BL1 storage read only BoPD";
static const char g_method_bl1_ufs_rdonly_hw_deg_bopd[] = "BL1 storage read only and hardware degrade BoPD";
static const char g_method_bl1_download[] = "BL1 download lastest version";
static const char g_method_bl1_prevention[] = "BL1 prevention";
static const char g_method_bl2_do_nothing[] = "BL2 do nothing";
static const char g_method_bl2_reboot[] = "BL2 reboot";
static const char g_method_bl2_factory_rest[] = "BL2 factory reset";
static const char g_method_bl2_safe_mode[] = "BL2 safe mode";
static const char g_method_bl2_bopd[] = "BL2 normal BoPD";
static const char g_method_bl2_degrade_bopd[] = "BL2 hardware degrade BoPD";
static const char g_method_bl2_ufs_rdonly_bopd[] = "BL2 storage read only BoPD";
static const char g_method_bl2_ufs_rdonly_degrade_bopd[] = "BL2 storage read only and hardware degrade BoPD";
static const char g_method_bl2_download[] = "BL2 download lastest version";
static const char g_method_bl2_prevention[] = "BL2 prevention";
static const char g_method_kernel_do_nothing[] = "Kernel do nothing";
static const char g_method_kernel_reboot[] = "Kernel reboot";
static const char g_method_kernel_factory_rest[] = "Kernel factory reset";
static const char g_method_kernel_safe_mode[] = "Kernel safe mode";
static const char g_method_kernel_bopd[] = "Kernel normal BoPD";
static const char g_method_kernel_degrade_bopd[] = "Kernel hardware degrade BoPD";
static const char g_method_kernel_ufs_rdonly_bopd[] = "Kernel storage read only BoPD";
static const char g_method_kernel_ufs_rdonly_degrade_bopd[] = "Kernel storage read only and hardware degrade BoPD";
static const char g_method_kernel_bopd_after_download[] = "Kernel normal BoPD after download";
static const char g_method_kernel_degrade_bopd_after_download[] = "Kernel hardware degrade BoPD after download";
static const char g_method_kernel_download[] = "Kernel download lastest version";
static const char g_method_kernel_prevention[] = "Kernel prevention";
static const char g_method_native_do_nothing[] = "Native do nothing";
static const char g_method_native_reboot[] = "Native reboot";
static const char g_method_native_factory_rest[] = "Native factory reset";
static const char g_method_native_safe_mode[] = "Native safe mode";
static const char g_method_native_bopd[] = "Native normal BoPD";
static const char g_method_native_degrade_bopd[] = "Native hardware degrade BoPD";
static const char g_method_native_ufs_rdonly_bopd[] = "Native storage read only BoPD";
static const char g_method_native_ufs_rdonly_degrade_bopd[] = "Native storage read only and hardware degrade BoPD";
static const char g_method_native_bopd_after_download[] = "Native normal BoPD after download";
static const char g_method_native_degrade_bopd_after_download[] = "Native hardware degrade BoPD after download";
static const char g_method_native_download[] = "Native download lastest version";
static const char g_method_native_prevention[] = "Native prevention";
static const char g_method_framework_do_nothing[] = "Framework do nothing";
static const char g_method_framework_reboot[] = "Framework reboot";
static const char g_method_framework_factory_rest[] = "Framework factory reset";
static const char g_method_framework_safe_mode[] = "Framework safe mode";
static const char g_method_framework_bopd[] = "Framework normal BoPD";
static const char g_method_framework_degrade_bopd[] = "Framework hardware degrade BoPD";
static const char g_method_framework_ufs_rdonly_bopd[] = "Framework storage read only BoPD";
static const char g_method_framework_ufs_rdonly_degrade_bopd[] =
	"Framework storage read only and hardware degrade BoPD";
static const char g_method_framework_bopd_after_download[] = "Framework normal BoPD after download";
static const char g_method_framework_degrade_bopd_after_download[] = "Framework hardware degrade BoPD after download";
static const char g_method_framework_download[] = "Framework download lastest version";
static const char g_method_framework_prevention[] = "Framework prevention";
static const char g_method_unknown[] = "Unknown recovery method";

static boot_stage_map_st stage_map[] = {
	{BL1_STAGE, "BL1_STAGE"},
	{BL2_STAGE, "BL2_STAGE"},
	{KERNEL_STAGE, "KERNEL_STAGE"},
	{NATIVE_STAGE, "NATIVE_STAGE"},
	{FRAMEWORK_STAGE, "FRAMEWORK_STAGE"},
	{BOOT_SUCC_STAGE, "BOOT_SUCC_STAGE"},
#ifdef CONFIG_SHUT_DETECTOR
	{SHUT_STAGE_FRAMEWORK_START, "SHUT_STAGE_FRAMEWORK_START"},
	{SHUT_STAGE_FRAMEWORK_FINISH, "SHUT_STAGE_FRAMEWORK_FINISH"},
	{SHUT_STAGE_NATIVE_START, "SHUT_STAGE_NATIVE_START"},
	{SHUT_STAGE_NATIVE_FINISH, "SHUT_STAGE_NATIVE_FINISH"},
	{SHUT_STAGE_KERNEL, "SHUT_STAGE_KERNEL"},
#endif
};

error_no_map_st error_no_map[] = {
	{BL1_CORE_DEV_FAULT, error_name_bl1_core_dev_fault},
	{BL1_NON_CORE_DEV_FAULT, error_name_bl1_non_core_dev_fault},
	{BL1_IMG_FAULT, error_name_bl1_img_fault},
	{BL1_SYSTEM_CRASH, error_name_bl1_system_crash},
	{BL1_SYSTEM_FREEZE, error_name_bl1_system_freeze},
	{BL1_BAD_ENV, error_name_bl1_bad_env},
	{BL2_CORE_DEV_FAULT, error_name_bl2_core_dev_fault},
	{BL2_NON_CORE_DEV_FAULT, error_name_bl2_non_core_dev_fault},
	{BL2_IMG_FAULT, error_name_bl2_img_fault},
	{BL2_SYSTEM_CRASH, error_name_bl2_system_crash},
	{BL2_SYSTEM_FREEZE, error_name_bl2_system_freeze},
	{BL2_BAD_ENV, error_name_bl2_bad_env},
	{KERNEL_CORE_DEV_FAULT, error_name_kernel_core_dev_fault},
	{KERNEL_NON_CORE_DEV_FAULT, error_name_kernel_non_core_dev_fault},
	{KERNEL_IMG_FAULT, error_name_kernel_img_fault},
	{KERNEL_SUBSYS_FAULT, error_name_kernel_subsys_fault},
	{KERNEL_SYSTEM_CRASH, error_name_kernel_system_crash},
	{KERNEL_SYSTEM_FREEZE, error_name_kernel_system_freeze},
	{KERNEL_BAD_ENV, error_name_kernel_bad_env},
	{NATIVE_CORE_DEV_FAULT, error_name_native_core_dev_fault},
	{NATIVE_NON_CORE_DEV_FAULT, error_name_native_non_core_dev_fault},
	{NATIVE_SERVICE_CRASH, error_name_native_service_crash},
	{NATIVE_SERVICE_FREEZE, error_name_native_service_freeze},
	{NATIVE_DATA_PART_MOUNT_FAIL, error_name_native_data_part_mount_fail},
	{NATIVE_DATA_PART_MOUNT_RO, error_name_native_data_part_mount_ro},
	{NATIVE_DATA_DAMAGED, error_name_native_data_damaged},
	{NATIVE_PART_MOUNT_FAIL, error_name_native_data_mount_fail},
	{NATIVE_SUBSYS_FAULT, error_name_native_subsys_fault},
	{NATIVE_SYSTEM_CRASH, error_name_native_system_crash},
	{NATIVE_SYSTEM_FREEZE, error_name_native_system_freeze},
	{NATIVE_BAD_ENV, error_name_native_bad_env},
	{NATIVE_DATA_FSCK_FAIL, error_name_native_data_fsck_fail},
	{FRAMEWORK_CORE_DEV_FAULT, error_name_framework_core_dev_fault},
	{FRAMEWORK_NON_CORE_DEV_FAULT, error_name_framework_non_core_dev_fault},
	{FRAMEWORK_SERVICE_CRASH, error_name_framework_service_crash},
	{FRAMEWORK_SERVICE_FREEZE, error_name_framework_service_freeze},
	{FRAMEWORK_DATA_DAMAGED, error_name_framework_data_damaged},
	{FRAMEWORK_SUBSYS_FAULT, error_name_framework_subsys_fault},
	{FRAMEWORK_SYSTEM_CRASH, error_name_framework_system_crash},
	{FRAMEWORK_SYSTEM_FREEZE, error_name_framework_system_freeze},
	{FRAMEWORK_BAD_ENV, error_name_framework_bad_env},
	{HARDWARE_CORE_DEV_FAULT, error_name_hardware_core_dev_fault},
	{HARDWARE_STORAGE_FAULT, error_name_hardware_storage_fault},
	{HARDWARE_NON_CORE_DEV_FAULT, error_name_hardware_non_core_dev_fault},
};

static struct method_map g_method_no_map[]  = {
	{BL1_DO_NOTHING, g_method_bl1_do_nothing},
	{BL1_REBOOT, g_method_bl1_reboot},
	{BL1_FACTORY_REST, g_method_bl1_factory_rest},
	{BL1_SAFE_MODE, g_method_bl1_safe_mode},
	{BL1_BOPD, g_method_bl1_bopd},
	{BL1_DEGRADE_BOPD, g_method_bl1_degrade_bopd},
	{BL1_UFS_RDONLY_BOPD, g_method_bl1_ufs_rdonly_bopd},
	{BL1_UFS_RDONLY_HW_DEG_BOPD, g_method_bl1_ufs_rdonly_hw_deg_bopd},
	{BL1_DOWNLOAD, g_method_bl1_download},
	{BL1_PREVENTION, g_method_bl1_prevention},
	{BL2_DO_NOTHING, g_method_bl2_do_nothing},
	{BL2_REBOOT, g_method_bl2_reboot},
	{BL2_FACTORY_REST, g_method_bl2_factory_rest},
	{BL2_SAFE_MODE, g_method_bl2_safe_mode},
	{BL2_BOPD, g_method_bl2_bopd},
	{BL2_DEGRADE_BOPD, g_method_bl2_degrade_bopd},
	{BL2_UFS_RDONLY_BOPD, g_method_bl2_ufs_rdonly_bopd},
	{BL2_UFS_RDONLY_DEGRADE_BOPD, g_method_bl2_ufs_rdonly_degrade_bopd},
	{BL2_DOWNLOAD, g_method_bl2_download},
	{BL2_PREVENTION, g_method_bl2_prevention},
	{KERNEL_DO_NOTHING, g_method_kernel_do_nothing},
	{KERNEL_REBOOT, g_method_kernel_reboot},
	{KERNEL_FACTORY_REST, g_method_kernel_factory_rest},
	{KERNEL_SAFE_MODE, g_method_kernel_safe_mode},
	{KERNEL_BOPD, g_method_kernel_bopd},
	{KERNEL_DEGRADE_BOPD, g_method_kernel_degrade_bopd},
	{KERNEL_UFS_RDONLY_BOPD, g_method_kernel_ufs_rdonly_bopd},
	{KERNEL_UFS_RDONLY_DEGRADE_BOPD, g_method_kernel_ufs_rdonly_degrade_bopd},
	{KERNEL_BOPD_AFTER_DOWNLOAD, g_method_kernel_bopd_after_download},
	{KERNEL_DEGRADE_BOPD_AFTER_DOWNLOAD, g_method_kernel_degrade_bopd_after_download},
	{KERNEL_DOWNLOAD, g_method_kernel_download},
	{KERNEL_PREVENTION, g_method_kernel_prevention},
	{NATIVE_DO_NOTHING, g_method_native_do_nothing},
	{NATIVE_REBOOT, g_method_native_reboot},
	{NATIVE_FACTORY_REST, g_method_native_factory_rest},
	{NATIVE_SAFE_MODE, g_method_native_safe_mode},
	{NATIVE_BOPD, g_method_native_bopd},
	{NATIVE_DEGRADE_BOPD, g_method_native_degrade_bopd},
	{NATIVE_UFS_RDONLY_BOPD, g_method_native_ufs_rdonly_bopd},
	{NATIVE_UFS_RDONLY_DEGRADE_BOPD, g_method_native_ufs_rdonly_degrade_bopd},
	{NATIVE_BOPD_AFTER_DOWNLOAD, g_method_native_bopd_after_download},
	{NATIVE_DEGRADE_BOPD_AFTER_DOWNLOAD, g_method_native_degrade_bopd_after_download},
	{NATIVE_DOWNLOAD, g_method_native_download},
	{NATIVE_PREVENTION, g_method_native_prevention},
	{FRAMEWORK_DO_NOTHING, g_method_framework_do_nothing},
	{FRAMEWORK_REBOOT, g_method_framework_reboot},
	{FRAMEWORK_FACTORY_REST, g_method_framework_factory_rest},
	{FRAMEWORK_SAFE_MODE, g_method_framework_safe_mode},
	{FRAMEWORK_BOPD, g_method_framework_bopd},
	{FRAMEWORK_DEGRADE_BOPD, g_method_framework_degrade_bopd},
	{FRAMEWORK_UFS_RDONLY_BOPD, g_method_framework_ufs_rdonly_bopd},
	{FRAMEWORK_UFS_RDONLY_DEGRADE_BOPD, g_method_framework_ufs_rdonly_degrade_bopd},
	{FRAMEWORK_BOPD_AFTER_DOWNLOAD, g_method_framework_bopd_after_download},
	{FRAMEWORK_DEGRADE_BOPD_AFTER_DOWNLOAD, g_method_framework_degrade_bopd_after_download},
	{FRAMEWORK_DOWNLOAD, g_method_framework_download},
	{FRAMEWORK_PREVENTION, g_method_framework_prevention},
	{RECOVERY_METHOD_UNKNOWN, g_method_unknown},
};

#endif