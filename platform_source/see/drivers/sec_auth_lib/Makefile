ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver
ccflags-$(CONFIG_SEC_AUTH_LIB) += -I$(srctree)/platform_source/see/drivers/sec_auth_lib/include

obj-$(CONFIG_SEC_AUTH_LIB)	+= src/sec_auth.o

ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow
