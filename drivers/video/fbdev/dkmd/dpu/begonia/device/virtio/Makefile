ifeq ($(CONFIG_DMABUF_MM),y)
ccflags-y += -I$(srctree)/drivers/dma-buf/heaps
ccflags-y += -I$(srctree)/platform_source/basicplatform/drivers/dma-buf/heaps
endif

obj-y			+= virtio.o
virtio-objs := \
	virtio_fb.o \
	virtio_iommu.o

EXTRA_CFLAGS += \
	-I$(srctree)/drivers/staging/android/ion/ \
	-I$(srctree)/include/platform_include/display/dkmd/ \
	-I$(srctree)/include/platform_include/display/linux/ \
	-I$(srctree)/drivers/video/fbdev/dkmd/dksm \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm
