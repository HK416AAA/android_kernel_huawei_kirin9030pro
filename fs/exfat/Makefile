# SPDX-License-Identifier: GPL-2.0-or-later
#
# Makefile for the linux exFAT filesystem support.
#
obj-$(CONFIG_EXFAT_FS) += exfat.o

exfat-y	:= inode.o namei.o dir.o super.o fatent.o cache.o nls.o misc.o \
	   file.o balloc.o

ifeq ($(CONFIG_PRODUCT_CDC), y)
exfat-y += sysfs.o
else ifeq ($(CONFIG_PRODUCT_CDC_ACE), y)
exfat-y += sysfs.o
endif
