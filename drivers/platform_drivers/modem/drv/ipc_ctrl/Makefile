-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk
ifeq ($(strip $(CFG_CONFIG_MODULE_IPC_CTRL)), YES)
obj-y += ipc_ctrl.o
obj-y += ipc_ctrl_test.o
obj-y += ipc_ctrl_dump.o
endif

subdir-ccflags-y := -Werror
