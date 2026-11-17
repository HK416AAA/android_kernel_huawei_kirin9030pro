obj-y += hisp_ca.o \
         hisp_smc.o

ifdef CONFIG_HISP_FFA_SUPPORT
obj-$(CONFIG_ISP) += hisp_ffa.o
endif

ifdef CONFIG_HISP_LOAD_SECISPIMAGE
obj-$(CONFIG_ISP) += hisp_load_image_ca.o
endif
