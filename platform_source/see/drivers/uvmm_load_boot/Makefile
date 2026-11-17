ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver
ccflags-$(CONFIG_UVMM_LOAD_BOOT) += -I$(srctree)/platform_source/see/drivers/uvmm_load_boot/include

obj-$(CONFIG_UVMM_LOAD_BOOT) += src/sec_auth.o
obj-$(CONFIG_UVMM_LOAD_BOOT) += src/ioctl/sec_auth_main.o
obj-$(CONFIG_UVMM_LOAD_BOOT) += src/ioctl/sec_auth_ioctl.o

ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow
