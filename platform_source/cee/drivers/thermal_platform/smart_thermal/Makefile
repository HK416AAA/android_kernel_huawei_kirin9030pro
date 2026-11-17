ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wshadow -Wformat=2
ccflags-y += -I$(srctree)/drivers/thermal \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform/smart_thermal

obj-$(CONFIG_SMART_THERMAL)		+= smart_thermal.o
obj-$(CONFIG_SMART_THERMAL_SYSFS)	+= smart_thermal_sysfs.o
obj-$(CONFIG_SMART_THERMAL_IOCTL)	+= smart_thermal_ctrl.o
obj-$(CONFIG_SMART_THERMAL_IOCTL)	+= thermal_event_ctrl.o
obj-$(CONFIG_THERMAL_AI_SCHED)		+= ai_sched_thermal/
obj-y					+= margin_thermal/
