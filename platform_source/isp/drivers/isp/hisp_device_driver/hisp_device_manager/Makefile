obj-y += hisp_device.o \
         hisp_device_manager.o \
         hisp_nsec.o \
         hisp_remoteproc.o \
         hisp_sec.o

obj-$(CONFIG_HISP_DPM) += hisp_dpm.o

ifdef CONFIG_HISP_SMARTISP_ENABLE
obj-$(CONFIG_ISP) += hisp_smartisp.o
endif
