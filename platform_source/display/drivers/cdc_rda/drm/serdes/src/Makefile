obj-$(CONFIG_DPU_PANEL) += hisi_dpu_serdes.o

hisi_dpu_serdes-objs := \
	drv_mcu.o \
	ti981_dsi1.o \
	ti981_common.o \
	i2c_common.o

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/serdes/include