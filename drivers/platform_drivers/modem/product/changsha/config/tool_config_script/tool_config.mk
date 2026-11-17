TOOL_CONFIG_PACKAGES :=
TOOL_CONFIG_PACKAGES_ENG :=

# logcfg
TOOL_CONFIG_PACKAGES += log_default.cfg log_mid.cfg log_mini.cfg

# chrcfg
TOOL_CONFIG_PACKAGES += chr_ct_msg.db msg_adapter.xml

ifeq ($(TARGET_BUILD_VARIANT),eng)
TOOL_CONFIG_PACKAGES += $(TOOL_CONFIG_PACKAGES_ENG)
endif