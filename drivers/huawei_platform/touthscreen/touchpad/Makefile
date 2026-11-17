#
# Makefile for kernel touchpad driver.
#

obj-$(CONFIG_HUAWEI_TOUCHPAD) += touchpad_core.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) += touchpad_fw_update.o touchpad_api.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) += touchpad_tp_ic_update.o btl_firmware_update.o goodix_firmware_update.o touchpad_cmd_chl.o

ifeq ($(TARGET_VERSION_MODE),factory)
	ccflags-$(CONFIG_HUAWEI_TOUCHPAD) += -DTOUCHPAD_FACTORY_ENABLE
endif

obj-$(CONFIG_HUAWEI_TOUCHPAD) += touchpad_thirdparty.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) += ft3438/
obj-$(CONFIG_HUAWEI_TOUCHPAD) += gt786x/
