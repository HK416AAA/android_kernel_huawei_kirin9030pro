ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wformat=2 -Wshadow

ifeq ($(CONFIG_NET_VENDOR_HIXGEMAC_10CC),y)
obj-y += hi10cc/
else
obj-y += gth/
endif
