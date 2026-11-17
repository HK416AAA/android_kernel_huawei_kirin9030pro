ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wshadow -Wformat=2
ccflags-y += -I$(srctree)/drivers/thermal \
	     -I$(srctree)/drivers/regulator/ \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform \
	     -I$(srctree)/platform_source/cee/drivers/thermal_platform/active_cooling_thermal/

ifeq ($(CONFIG_THERMAL_GOV_AC_CTRL),y)
obj-y					+= thermal_policy/ac_level_throttle_policy.o
obj-y					+= main/fan_ctrl/fan_speed_pid_ctrl.o
obj-y					+= basic/thermal_get_temp.o
obj-y					+= interface/ac_thermal_sysfs.o
obj-y					+= main/fan_ctrl/ac_thermal.o
obj-y					+= main/fan_ctrl/fan_ctrl_dev.o
obj-y					+= main/fan_ctrl/gov_ac_ctrl.o
obj-y					+= interface/ac_thermal_ioctl.o
obj-y					+= basic/fan_nv.o
obj-y					+= basic/fan_dmd.o
obj-y					+= basic/fan_power.o
obj-y					+= main/fan_error/fan_error.o
obj-y					+= service/fan_production_test_case.o
obj-y					+= basic/fan_pwm_dev.o
obj-y					+= thermal_policy/soc_temp_thermal_policy.o
obj-y					+= service/ac_thermal_voting_center.o
obj-y					+= main/fan_error/fan_status_fsm.o
obj-y					+= main/fan_error/fan_context.o
obj-y					+= main/fan_error/ac_thermal_noise.o
endif