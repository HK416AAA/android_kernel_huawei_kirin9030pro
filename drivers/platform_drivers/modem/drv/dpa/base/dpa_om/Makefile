-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/modem/drv/dpa/base/dpa_om
ifeq ($(strip $(CFG_CONFIG_DPA_OM)),YES)
obj-y                   := om_msg.o dump.o

ifeq ($(strip $(CFG_CONFIG_MODEM_CORESIGHT)),YES)
obj-y += ocd.o
else
obj-y += ocd_stub.o
endif

ifeq ($(CFG_CONFIG_DPA_WDT), YES)
obj-y += watchdog_dpa.o
endif

else
obj-y                   := om_stub.o
endif