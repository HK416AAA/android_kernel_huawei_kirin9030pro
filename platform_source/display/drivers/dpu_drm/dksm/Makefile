obj-$(CONFIG_DPU_DKSM) += hisi_dpu_dksm.o


hisi_dpu_dksm-objs := \
	dksm_debug.o \
	isr/dkmd_isr.o \
	peri/dkmd_peri.o

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm \
	-I$(srctree)/include/ \


clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f

	