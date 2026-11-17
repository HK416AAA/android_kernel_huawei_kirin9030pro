PS_USER_PRIVATE_PACKAGES :=
PS_USER_PRIVATE_PACKAGES_ENG :=

# libhmi_logcat
ifeq ($(MODEMLOGCAT_FEATURE),ON)
PS_USER_PRIVATE_PACKAGES += libhmi_logcat
else ifeq ($(CFG_MODEM_PS_USER_LIBS),true)
PS_USER_PRIVATE_PACKAGES += libhmi_logcat
endif

# libhmi_chr
ifeq ($(MODEMCHR_FEATURE),ON)
PS_USER_PRIVATE_PACKAGES += libhmi_chr
else ifeq ($(CFG_MODEM_PS_USER_LIBS),true)
PS_USER_PRIVATE_PACKAGES += libhmi_chr
endif

# hmi_service
PS_USER_PRIVATE_PACKAGES += hmi_service

# libhmi_driver
PS_USER_PRIVATE_PACKAGES += libhmi_driver

# librtt
PS_USER_PRIVATE_PACKAGES += librtt

ifeq ($(TARGET_BUILD_VARIANT),eng)
PS_USER_PRIVATE_PACKAGES += $(PS_USER_PRIVATE_PACKAGES_ENG)
endif