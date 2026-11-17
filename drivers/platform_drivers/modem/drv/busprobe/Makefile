
-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk

subdir-ccflags-y := -Werror

ifeq ($(strip $(CFG_CONFIG_AP_QIC)), YES)
obj-y           += qic_dump_register.o
endif