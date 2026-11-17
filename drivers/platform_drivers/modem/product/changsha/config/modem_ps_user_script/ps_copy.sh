#!/bin/bash
# Copyright Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
set -e

this_dir=$(dirname $(readlink -f ${BASH_SOURCE}))
root_dir=$(readlink -f ${this_dir}/../../../../../../../)

function main()
{
    while [[ "$#" -gt 0 ]]
    do
        local tmp_args="$1"
        echo $tmp_args
        local $tmp_args
        shift
    done

    src_path=$root_dir/$BUILD_OUT/device_soc_hisi/modem_vendor
    if [ "$LIBS_BUILD" != "true" ]; then
        dst_bin_path=$root_dir/$BUILD_OUT/packages/phone/modem_vendor/bin
        dst_lib64_path=$root_dir/${BUILD_OUT}/packages/phone/modem_vendor/lib64
        dst_config_path=$root_dir/$BUILD_OUT/packages/phone/modem_vendor/config
    else
        dst_bin_path=$root_dir/output/${PRODUCT_NAME}/${CHIP_TYPE}_${BUILD_VARIANT}/ps_user_ohos/bin
        dst_lib64_path=$root_dir/output/${PRODUCT_NAME}/${CHIP_TYPE}_${BUILD_VARIANT}/ps_user_ohos/lib64
        dst_config_path=$root_dir/output/${PRODUCT_NAME}/${CHIP_TYPE}_${BUILD_VARIANT}/ps_user_ohos/config
    fi

    echo src_path=$src_path
    echo dst_bin_path=$dst_bin_path
    echo dst_lib64_path=$dst_lib64_path

    mkdir -p $dst_bin_path
    mkdir -p $dst_lib64_path

    if [ "$LIBS_BUILD" != "true" ]; then
        # ril modules
        if [ "$MODEM_VERSION_MODE" != "plat_llt" ]; then
            cp $src_path/libhuaweicust.z.so $dst_lib64_path
            cp $src_path/libvendor-ril.z.so $dst_lib64_path
            cp $src_path/libcommril.z.so $dst_lib64_path
            cp $src_path/libril_msgtransfer.z.so $dst_lib64_path
            cp $src_path/libio_event.z.so $dst_lib64_path
        fi

        # hmi modules
        if [ "$BUILD_VARIANT" != "user" ]; then
            cp $src_path/himodemapr $dst_bin_path
            cp $src_path/libhmi_analysis.z.so $dst_lib64_path
        fi
        cp $src_path/libhmi_driver.z.so $dst_lib64_path
        cp $src_path/libhmi_driver_core.z.so $dst_lib64_path
        cp $src_path/libhmi_logcat.z.so $dst_lib64_path
        cp $src_path/libhmi_chr.z.so $dst_lib64_path
        cp $src_path/libhmi_qoe.z.so $dst_lib64_path
    else
        if [ "$BUILD_VARIANT" != "user" ]; then
            cp $src_path/himodemapr $dst_bin_path
            cp $src_path/libhmi_analysis.z.so $dst_lib64_path
        fi
        cp $src_path/libhmi_driver_core.z.so $dst_lib64_path
        cp $src_path/libhmi_logcat.z.so $dst_lib64_path
        cp $src_path/libhmi_chr.z.so $dst_lib64_path
        cp $src_path/libhmi_qoe.z.so $dst_lib64_path
    fi
}

main $@