# Makefile for the goodix touchpad drivers.
 
obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  goodix_i2c_rw.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  goodix_ts_log.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  gt786x_fwupdate.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  gt786x_hw_ops.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  hm_os_sys.o
obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  goodix_driver.o

ifeq ($(TARGET_VERSION_MODE),factory)
    ccflags-$(CONFIG_HUAWEI_TOUCHPAD) += -DTOUCHPAD_FACTORY_ENABLE
    obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  gt786x_inspect.o
    obj-$(CONFIG_HUAWEI_TOUCHPAD) +=  gt786x_save_csv.o
endif