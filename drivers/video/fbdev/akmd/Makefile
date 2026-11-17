# If you want to compile into modular drive, will need to decide
# according to the following configuration to compile.
# If the CONFIG_UKMD_ENABLE is not defined, display module isn't compiled.

ifeq ($(CONFIG_AKMD_ENABLE),y)

obj-y += dacc_aae/
obj-y += aksm/
obj-y += cmdlist/
obj-y += commit/
obj-y += device/
obj-y += isr/
obj-y += power/
obj-y += res_mgr/
obj-y += init/

ifeq ($(CONFIG_MDFX_KMD),y)
obj-y += mntn/
endif

endif
