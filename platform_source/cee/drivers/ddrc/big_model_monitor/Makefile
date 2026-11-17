ccflags-y += -I$(srctree)/platform_source/cee/drivers
ccflags-y += -I$(srctree)/platform_source/cee/drivers/ddrc/big_model_monitor/include

obj-y += src/bmm.o
obj-y += src/bmm_sys.o
obj-y += src/bmm_drv.o
obj-y += src/bmm_cfg.o
obj-y += src/bmm_event.o
obj-y += src/bmm_report.o
obj-y += src/bmm_notifier.o
obj-y += src/bmm_ddr_stat.o
obj-$(CONFIG_LIBLINUX) += src/bmm_mpam.o