#
# Makefile for the dts drivers.
#
# this mk is for phone (without ko) and mbb

-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk

subdir-ccflags-y+= -I$(srctree)/drivers/platform_drivers/modem/drv/dt/

ifeq ($(strip $(CFG_CONFIG_KERNEL_DTS_DECOUPLED)),YES)
# for phone(enable dt decouple)
subdir-ccflags-y+= -I$(srctree)/drivers/platform_drivers/modem/drv/dt/fdt/
obj-y           += device_tree_fdt.o
obj-y           += device_tree_load_acore_dtb.o

obj-y           += fdt/fdt.o
obj-y           += fdt/fdt_ro.o
obj-y           += fdt/fdt_overlay.o
obj-y           += fdt/fdt_rw.o
obj-y           += fdt/fdt_strerror.o
obj-y           += fdt/fdt_wip.o
else
# for mbb and phone(disable dt decouple)
obj-y           += device_tree_native.o
endif

# for mbb and phone(not care dt decouple)
obj-y   += device_tree_load_untils.o
obj-y   += device_tree_load_ccore_dt.o
obj-y   += device_tree_driver.o