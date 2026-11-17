
-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk
ifeq ($(strip $(BSP_CONFIG_PHONE_TYPE)), YES)
obj-y                   += avs_core.o
obj-y                   += avs_base.o
obj-y                   += avs_cfg.o
obj-$(CONFIG_AVS_PERCHIP_UPDATE)     += avs_perchip.o
obj-$(CONFIG_AVS_COLL_TEST)          += avs_collection.o
endif