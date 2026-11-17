MODEM_APP_PACKAGES := rfile_user_phone
MODEM_APP_PACKAGES_ENG :=

# heating_proxy
MODEM_APP_PACKAGES_ENG += \
    heating_proxy

# modem_aging
MODEM_APP_PACKAGES_ENG += \
    libmodem_aging \
    libmodem_aging_server
MODEM_APP_PACKAGES_ENG += \
    modem_aging_test

MODEM_APP_PACKAGES_ENG += \
	st_test

ifeq ($(TARGET_BUILD_VARIANT),eng)
MODEM_APP_PACKAGES += $(MODEM_APP_PACKAGES_ENG)
endif

include vendor/hisi/modem/product/$(OBB_PRODUCT_NAME)/config/modem_ps_user_script/modem_ps_user.mk
MODEM_APP_PACKAGES += $(PS_USER_PACKAGES)

include vendor/hisi/modem/product/$(OBB_PRODUCT_NAME)/config/tool_config_script/tool_config.mk
MODEM_APP_PACKAGES += $(TOOL_CONFIG_PACKAGES)

define copy_file_func
	-cp -f $(1) $(2)
endef

MODEMVENDOR_COPY_FILES := $(PRODUCT_OUT)/modem_vendor/copy_files
$(MODEMVENDOR_COPY_FILES):
	@echo do [$@]
	cd $(PRODUCT_OUT) && mkdir -p modem_vendor/init modem_vendor/fstab
	$(call copy_file_func,vendor/hisi/modem/app/etc/phone_modem/$(TARGET_BOARD_PLATFORM)/rc_files/init.modem.rc,$(PRODUCT_OUT)/modem_vendor/init/init.modem.rc)
	$(call copy_file_func,vendor/hisi/modem/app/etc/phone_modem/$(TARGET_BOARD_PLATFORM)/rc_files/init.chip.charger.modem.rc,$(PRODUCT_OUT)/modem_vendor/init/init.chip.charger.modem.rc)
	$(call copy_file_func,vendor/hisi/modem/app/etc/phone_modem/$(TARGET_BOARD_PLATFORM)/fstab_files/fstab.modem,$(PRODUCT_OUT)/modem_vendor/fstab/fstab.modem)
	@echo do [$@]
	cd $(PRODUCT_OUT) && mkdir -p modem_vendor/config
	$(call copy_file_func,vendor/hisi/modem/ps/ap/user/platform/hmi_service/config/cliem.cfg,$(PRODUCT_OUT)/modem_vendor/config/cliem.cfg)
	$(call copy_file_func,vendor/hisi/modem/ps/ap/user/platform/hmi_service/config/klist.bin,$(PRODUCT_OUT)/modem_vendor/config/klist.bin)
	$(call copy_file_func,vendor/hisi/modem/ps/ap/user/platform/hmi_service/init_cfg/hmi_service.rc,$(PRODUCT_OUT)/modem_vendor/init/hmi_service.rc)
	$(call copy_file_func,vendor/hisi/modem/ps/ap/user/platform/rtt_channel/rtt_android/rtt_service.rc,$(PRODUCT_OUT)/modem_vendor/init/rtt_service.rc)
ifeq ($(TARGET_BUILD_VARIANT),eng)
	$(call copy_file_func,vendor/hisi/modem/product/$(TARGET_BOARD_PLATFORM)/config/aging_case/case_config.xml,$(PRODUCT_OUT)/modem_vendor/config/case_config.xml)
endif
