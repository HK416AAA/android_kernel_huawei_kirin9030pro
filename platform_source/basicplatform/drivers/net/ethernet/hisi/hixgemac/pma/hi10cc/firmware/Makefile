ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wformat=2 -Wshadow

ifeq ($(CONFIG_NET_VENDOR_HIXGEMAC_10CC_VER1),y)
obj-y += hi10cc_fw_ver1.o
else ifeq ($(CONFIG_NET_VENDOR_HIXGEMAC_10CC_VER2),y)
obj-y += hi10cc_fw_ver2.o
endif
