PS_USER_PACKAGES :=
PS_USER_PACKAGES_ENG :=

$(info "modem_version_mode is $(modem_version_mode)")
ifneq ($(modem_version_mode),plat_llt)
# ril
PS_USER_PACKAGES += \
    libaril_msgtransfer-udp \
    libvendor-ril-udp \
    libcommril-udp \
    libio_event-udp
endif

# hmi_service
PS_USER_PACKAGES += hmi_service

# rtt_service
PS_USER_PACKAGES += rtt_service

ifeq ($(TARGET_BUILD_VARIANT),eng)
PS_USER_PACKAGES += $(PS_USER_PACKAGES_ENG)
endif

include vendor/hisi/modem/product/$(OBB_PRODUCT_NAME)/config/modem_ps_user_script/modem_ps_user_private.mk
PS_USER_PACKAGES += $(PS_USER_PRIVATE_PACKAGES)
