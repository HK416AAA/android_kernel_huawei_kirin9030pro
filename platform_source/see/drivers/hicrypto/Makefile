# CONFIG_CRYPTO_HICRYPTO
ifeq ($(CONFIG_CRYPTO_HICRYPTO), y)
obj-$(CONFIG_CRYPTO_HICRYPTO) += hicrypto.o
LP_SOC_CHIP_NAME := $(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_PREFIX)))
ifneq ($(LP_SOC_CHIP_NAME), " ")
subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/chip/$(LP_SOC_CHIP_NAME)
hicrypto_chip-$(CONFIG_CRYPTO_HICRYPTO) += chip/$(LP_SOC_CHIP_NAME)/hicrypto_dev_chip.o
endif

hicrypto-$(CONFIG_CRYPTO_HICRYPTO) := hicrypto_driver.o $(hicrypto_chip-y) hicrypto_dev.o hicrypto_common.o

ifeq ($(CONFIG_KERNEL_MODE_NEON), y)
	hicrypto-$(CONFIG_CRYPTO_HICRYPTO) += hicrypto_neon.o
CFLAGS_REMOVE_hicrypto_neon.o += -mgeneral-regs-only
CFLAGS_hicrypto_neon.o += -ffreestanding
CFLAGS_hicrypto_neon.o += -isystem $(shell $(CC) -print-file-name=include)
endif

hicrypto-$(CONFIG_CRYPTO_HICRYPTO_SHA) += hicrypto_hash.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_CIPHER) += hicrypto_cipher.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_AEAD) += hicrypto_aead_reg.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_AEAD) += hicrypto_dev_aead.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_MAC) += hicrypto_mac.o

hicrypto-$(CONFIG_CRYPTO_HICRYPTO_DEBUG) += hicrypto_dft.o

hicrypto-$(CONFIG_CRYPTO_HICRYPTO_LDK_OEMINFO_TEST) += hicrypto_ldk_ioctl.o

subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/ap/platform/common/lowpm
subdir-ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow

endif # CONFIG_CRYPTO_HICRYPTO

ifeq ($(CONFIG_CRYPTO_HICRYPTO_V2), y)
obj-$(CONFIG_CRYPTO_HICRYPTO_V2) += hicrypto.o
LP_SOC_CHIP_NAME := $(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_PREFIX)))
ifneq ($(LP_SOC_CHIP_NAME), " ")
	subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include/chip/$(LP_SOC_CHIP_NAME)
	hicrypto_chip-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/drv/hicrypto_dev_chip.o
endif

ifeq ($(CONFIG_KERNEL_MODE_NEON), y)
	hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += hicrypto_neon.o
CFLAGS_REMOVE_hicrypto_neon.o += -mgeneral-regs-only
CFLAGS_hicrypto_neon.o += -ffreestanding
CFLAGS_hicrypto_neon.o += -isystem $(shell $(CC) -print-file-name=include)
endif

hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) := src/hicrypto_driver.o $(hicrypto_chip-y) src/hicrypto_common.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/hicrypto_eng_ctrl.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/hicrypto_register.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/hicrypto_utils.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/custom_oeminfo/hicrypto_alg_nve_mac.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/custom_oeminfo/hicrypto_alg_oeminfo_mac.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/hicrypto_alg_hd_api.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/hicrypto_alg_hd_hash.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/hicrypto_alg_hd_km.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/hicrypto_alg_hd_mac.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/alg/hicrypto_alg_hd_cipher.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/drv/hicrypto_dev_config.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/drv/hicrypto_dev_hash.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/drv/hicrypto_dev_km.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/drv/hicrypto_dev_symm.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/inner_api/hicrypto_inner_hash.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/inner_api/hicrypto_inner_mac.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/inner_api/hicrypto_inner_standard.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/ioctl/hicrypto_ioctl.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/ioctl/hicrypto_ioctl_nve_mac.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2) += src/ioctl/hicrypto_ioctl_oem_mac.o

hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) += src/ioctl/hicrypto_ioctl_cipher.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) += src/ioctl/hicrypto_ioctl_hash.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) += src/ioctl/hicrypto_ioctl_dft.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) += src/inner_api/hicrypto_inner_cipher.o
hicrypto-$(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) += src/hicrypto_dft.o

subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include
subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include/ioctl
subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include/inner_api
subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include/drv
subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include/alg
subdir-ccflags-y += -I$(srctree)/platform_source/see/drivers/hicrypto/include/alg/custom_oeminfo
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/ap/platform/common/lowpm
subdir-ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow

endif # CONFIG_CRYPTO_HICRYPTO_V2
