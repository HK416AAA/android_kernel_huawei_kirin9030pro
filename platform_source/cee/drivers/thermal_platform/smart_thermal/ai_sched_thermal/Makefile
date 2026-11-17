ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wshadow -Wformat=2
ccflags-y += -I$(srctree)/drivers/thermal \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform/smart_thermal

obj-y			+= ai_sched_thermal.o
obj-y			+= ai_sched_thermal_cpufreq_cdev.o
obj-y			+= ai_sched_thermal_devfreq_cdev.o
obj-y			+= ai_sched_thermal_state.o
obj-y			+= ai_sched_thermal_sysfs.o
obj-y			+= ai_sched_thermal_ctrl.o
