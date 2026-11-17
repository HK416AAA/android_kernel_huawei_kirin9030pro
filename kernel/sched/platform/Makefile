KERNEL_DIR := $(srctree)
EXTRA_CFLAGS += -I$(KERNEL_DIR)/kernel/sched
EXTRA_CFLAGS += -I$(KERNEL_DIR)/drivers/platform_drivers/ap/platform/common/

obj-y += hck_cpufreq_schedutil.o
obj-y += plat_sched.o
obj-$(CONFIG_SCHED_COLOC_GROUP) += walt_coloc_grp.o
obj-y += misc.o
obj-$(CONFIG_CPU_MICROARCH_PERF_CTRL) += cpu_microarch_perf_ctrl.o
obj-$(CONFIG_SCHED_PRIORITY_INVERSION_OPT) += priority_inversion.o
obj-$(CONFIG_FRAME_WINDOW) += frame_window.o
obj-$(CONFIG_THERMAL_INTELLIGENT_FREQ_CTRL) += thermal_intelligent_freq_ctrl.o
obj-$(CONFIG_SOC_DFX) += dfx.o
obj-$(CONFIG_SCHED_THERMAL_REPORT) += sched_thermal_report.o
obj-$(CONFIG_SCHED_CHIP_INFO) += sched_chip_info/
