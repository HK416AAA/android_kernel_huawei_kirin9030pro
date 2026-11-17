ifeq ($(CONFIG_ISP_LINX_CPU_SUPPORT), y)
obj-y += hisp_memory.o
else
obj-y += hisp_mempool.o
endif

ifdef CONFIG_HISP_MEMECC_SUPPORT
obj-$(CONFIG_ISP) += hisp_memecc.o
endif

obj-y += hisp_cma.o
