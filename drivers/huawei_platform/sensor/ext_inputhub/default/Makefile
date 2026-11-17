ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/default/bus_driver/
ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/default/commu_handle/
ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/default/inner_cmd/
ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/default/common_cmd_handle/

ifeq ($(product_type),glasses)
ccflags-y += -DCONFIG_PRODUCT_GLASSES
endif

#ext sensorhub Driver
obj-$(CONFIG_EXT_INPUTHUB) += ext_sensorhub_channel.o
obj-$(CONFIG_EXT_INPUTHUB) += ext_sensorhub_api.o
obj-$(CONFIG_EXT_INPUTHUB) += ext_sensorhub_route.o
obj-$(CONFIG_EXT_INPUTHUB) += ext_sensorhub_frame.o
obj-$(CONFIG_EXT_INPUTHUB) += crc16.o
obj-$(CONFIG_EXT_INPUTHUB_IPC_COMMU) += ext_sensorhub_commu_ipc.o
obj-$(CONFIG_EXT_INPUTHUB_COMMU) += ext_sensorhub_commu.o
obj-$(CONFIG_EXT_INPUTHUB) += ext_sensorhub_debug.o
obj-$(CONFIG_EXT_INPUTHUB) += bus_driver/
obj-$(CONFIG_EXT_INPUTHUB) += commu_handle/
obj-$(CONFIG_EXT_INPUTHUB) += inner_cmd/
obj-$(CONFIG_EXT_INPUTHUB) += common_cmd_handle/

ifneq ($(CONFIG_EXT_INPUTHUB_QCOM), y)
obj-$(CONFIG_EXT_INPUTHUB) += ext_motion_channel.o
endif