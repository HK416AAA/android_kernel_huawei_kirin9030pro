ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wformat=2 -Wshadow -I$(srctree)/platform_source/basicplatform/drivers/net/ethernet/hisi/hixgemac
ccflags-$(CONFIG_NET_VENDOR_HIXGEMAC_10CC_VER1) += -DCONFIG_10CC_VER1

obj-y += hixgemac_pma_10cc.o

obj-$(CONFIG_DFX_DEBUG_FS) += dfx/
obj-y += firmware/
