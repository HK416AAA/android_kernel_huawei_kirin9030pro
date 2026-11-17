-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk

subdir-ccflags-y := -Wall -Werror
ifeq ($(strip $(CFG_CONFIG_SPPM)),YES)
drv-y           += sppm_chan_mgr_it.o
drv-y           += sppm_chan_mgr.o
drv-y           += sppm_device.o
drv-y           += sppm_reg_base.o
else
drv-y           += sppm_chan_mgr_stub.o
endif