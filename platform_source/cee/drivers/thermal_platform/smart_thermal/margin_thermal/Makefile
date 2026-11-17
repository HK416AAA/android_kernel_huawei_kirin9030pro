ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wshadow -Wformat=2
ccflags-y += -I$(srctree)/drivers/thermal \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform/smart_thermal

obj-$(CONFIG_THERMAL_OFFLOADING)	+= thermal_offloading.o
obj-$(CONFIG_THERMAL_GOV_MARGIN_CTRL)	+= margin_thermal.o
obj-$(CONFIG_THERMAL_POWER_QUOTA)	+= power_quota.o
obj-$(CONFIG_THERMAL_POWER_QUOTA)	+= power_state.o
ifeq ($(CONFIG_THERMAL_POWER_QUOTA),y)
  obj-$(CONFIG_THERMAL_EMULATION)	+= margin_thermal_sysfs.o
endif
