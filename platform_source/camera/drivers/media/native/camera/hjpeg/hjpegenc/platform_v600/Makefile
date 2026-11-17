SOC_PLATFORM := $(strip $(subst ", , $(CONFIG_VENDOR_CHIP_PREFIX)))

ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wshadow
# if cs and es differs, split two different directories
ccflags-y += -I$(srctree)/platform_source/camera/drivers/media/native/camera
ccflags-y += -I$(srctree)/platform_source/camera/drivers/media/native/camera/hjpeg/hjpegenc
ccflags-y += -I$(srctree)/drivers/platform_drivers/ap/platform/common
ccflags-y += -I$(srctree)/drivers/platform_drivers/ap/platform/$(SOC_PLATFORM)

obj-y += platform_cvdr_config.o platform_jpegenc_config.o
