# install libs_file_list
install(
    FILES
        ${GBB_MODEM_DIR}/product/${GBB_PRODUCT_NAME}/config/modem_ps_user_script/libs_file_list.yaml
    DESTINATION ${GBB_OUTPUT_LIB_DIR}/ps_user_ohos/
)

string(FIND "${GBB_CUST_NAME}" "user" type_index)
if (${type_index} STREQUAL -1)

# install bin_files for eng version
install(
    FILES
        ${GBB_OUTPUT_DIR}/ps_user_ohos/bin/himodemapr
    DESTINATION ${GBB_OUTPUT_LIB_DIR}/ps_user_ohos/bin/
)

# install lib64_files for eng version
install(
    FILES
        ${GBB_OUTPUT_DIR}/ps_user_ohos/lib64/libhmi_analysis.z.so
    DESTINATION ${GBB_OUTPUT_LIB_DIR}/ps_user_ohos/lib64/
)

endif()

# install bin_files for eng&user version

# install lib64_files for eng&user version
install(
    FILES
        ${GBB_OUTPUT_DIR}/ps_user_ohos/lib64/libhmi_driver_core.z.so
        ${GBB_OUTPUT_DIR}/ps_user_ohos/lib64/libhmi_logcat.z.so
        ${GBB_OUTPUT_DIR}/ps_user_ohos/lib64/libhmi_chr.z.so
        ${GBB_OUTPUT_DIR}/ps_user_ohos/lib64/libhmi_qoe.z.so
    DESTINATION ${GBB_OUTPUT_LIB_DIR}/ps_user_ohos/lib64/
)
