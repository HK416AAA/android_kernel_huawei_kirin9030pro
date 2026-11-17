# install bin_files for eng&user version
install(
    FILES
        ${GBB_ROOT_DIR}/out/target/product/${GBB_PRODUCT_NAME}/modem_vendor/bin/hmi_service
    DESTINATION ${GBB_OUTPUT_LIB_DIR}/ps_user/bin/
)

# install lib64_files for eng&user version
install(
    FILES
        ${GBB_ROOT_DIR}/out/target/product/${GBB_PRODUCT_NAME}/modem_vendor/lib64/libhmi_driver.so
        ${GBB_ROOT_DIR}/out/target/product/${GBB_PRODUCT_NAME}/modem_vendor/lib64/libhmi_logcat.so
        ${GBB_ROOT_DIR}/out/target/product/${GBB_PRODUCT_NAME}/modem_vendor/lib64/libhmi_chr.so
        ${GBB_ROOT_DIR}/out/target/product/${GBB_PRODUCT_NAME}/modem_vendor/lib64/librtt.so
    DESTINATION ${GBB_OUTPUT_LIB_DIR}/ps_user/lib64/
)
