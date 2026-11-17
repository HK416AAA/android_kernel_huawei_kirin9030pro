#
# RPMB Makefile
#
ifeq ($(CONFIG_LIBLINUX),y)
ifeq ($(CONFIG_DFA_MCQ),y)
CFLAGS_vendor_rpmb.o += -I$(srctree)/drivers/scsi/ufs/
endif
endif
obj-$(CONFIG_VENDOR_RPMB)			+= vendor_rpmb.o
obj-$(CONFIG_RPMB_MMC)		+= rpmb_mmc.o
obj-$(CONFIG_RPMB_UFS)		+= rpmb_ufs.o
CFLAGS_rpmb_ufs.o += -I$(srctree)/drivers/scsi/ufs/

ifeq ($(CONFIG_LIBLINUX),y)
obj-$(CONFIG_RPMB_UFS) += rpmb_ufs_ldk.o
CFLAGS_rpmb_ufs_ldk.o += -I$(srctree)/platform_source/basicplatform/drivers/rpmb/ \
                     -I$(srctree)/platform_source/basicplatform/block/ \
					 -I$(srctree)/drivers/scsi/ufs/ \
					 -I$(srctree)/include/platform_include/basicplatform/linux/ \
					 -I$(srctree)/include/platform_include/basicplatform/linux/ufs/
endif

obj-$(CONFIG_RPMB_NORFLASH) += rpmb_norflash.o

obj-$(CONFIG_RPMB_STORAGE_INTERFACE)		+= rpmb_fs.o

obj-$(CONFIG_RPMB_DEBUG_FS)		+= rpmb_debugfs.o

obj-$(CONFIG_UFS_RPMB_SUPPORT_FROM_TEEOS_IN_KERNEL) += rpmb_ufs_teeos.o
