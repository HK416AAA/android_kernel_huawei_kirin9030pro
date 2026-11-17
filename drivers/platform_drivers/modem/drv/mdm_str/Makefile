
-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk

subdir-ccflags-y := -Wall -Werror
ifeq ($(strip $(CFG_CONFIG_MDM_STR)),YES)
obj-y       += mdm_str.o
else
obj-y       += mdm_str_stub.o
endif