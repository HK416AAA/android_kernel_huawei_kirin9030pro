# Makefile for the focaltech touchscreen drivers.

obj-$(CONFIG_HUAWEI_TOUCHPAD) += focal_hid_core.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) += focal_hid_upgrade.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) += focal_hid_esd.o

ifeq ($(TARGET_VERSION_MODE),factory)
    ccflags-$(CONFIG_HUAWEI_TOUCHPAD) += -DTOUCHPAD_FACTORY_ENABLE
    obj-$(CONFIG_HUAWEI_TOUCHPAD) += focal_hid_ex_func.o
    obj-$(CONFIG_HUAWEI_TOUCHPAD) += focal_hid_i2c.o
    obj-$(CONFIG_HUAWEI_TOUCHPAD) += focaltech_test/
endif