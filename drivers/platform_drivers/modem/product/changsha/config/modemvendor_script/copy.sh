#!/bin/bash
# Copyright Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
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

    bin_path=$root_dir/$PRODUCT_OUT/packages/phone/modem_vendor/bin
    lib64_path=$root_dir/$PRODUCT_OUT/packages/phone/modem_vendor/lib64
    init_path=$root_dir/$PRODUCT_OUT/packages/phone/modem_vendor/init
    fstab_path=$root_dir/$PRODUCT_OUT/packages/phone/modem_vendor/fstab
    config_path=$root_dir/$PRODUCT_OUT/packages/phone/modem_vendor/config

    mkdir -p $bin_path
    mkdir -p $lib64_path
    mkdir -p $init_path
    mkdir -p $fstab_path
    mkdir -p $config_path

    cp $root_dir/vendor/hisi/modem/app/etc/phone_modem/$OBB_PRODUCT_NAME/fstab_files/fstab.modem.ohos $fstab_path
    cp $root_dir/vendor/hisi/modem/app/etc/phone_modem/$OBB_PRODUCT_NAME/rc_files/init.modem.cfg $init_path
    cp $root_dir/vendor/hisi/modem/app/etc/phone_modem/$OBB_PRODUCT_NAME/rc_files/init.chip.charger.modem.cfg $init_path
    cp $root_dir/vendor/hisi/modem/app/etc/phone_modem/$OBB_PRODUCT_NAME/rc_files/init.modem_rnic.cfg $init_path
    cp $root_dir/vendor/hisi/modem/app/etc/phone_modem/$OBB_PRODUCT_NAME/rc_files/init.modem_ril.cfg $init_path
    cp $root_dir/vendor/hisi/modem/app/etc/phone_modem/$OBB_PRODUCT_NAME/rc_files/init.modem_ims.cfg $init_path
    cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/rfile_user_phone $bin_path
    cp $root_dir/vendor/hisi/modem/ps/ap/user/platform/hmi_service/config/cliem.cfg $config_path
    cp $root_dir/vendor/hisi/modem/ps/ap/user/platform/hmi_service/config/klist.bin $config_path
    cp $root_dir/vendor/hisi/modem/ps/ap/user/platform/hmi_service/config/qoe_scene_alg_model.bin $config_path
    cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/libims_dc_interface_service_1.0.z.so $lib64_path

    if [ "$BUILD_VARIANT" != "user" ]; then
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/mdmlogdeflatsvr $bin_path
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/heating_proxy $bin_path
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/libmodem_aging.z.so $lib64_path
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/libmodem_aging_server.z.so $lib64_path
        cp $root_dir/vendor/hisi/modem/product/$OBB_PRODUCT_NAME/config/aging_case/case_config.xml $config_path
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/modem_aging_test $bin_path
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/st_test $bin_path
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/ktfrun $bin_path || :
    elif [ "$modem_build_with_log" == "true" ]; then
        echo modem_build_with_log=$modem_build_with_log
        cp $root_dir/$PRODUCT_OUT/device_soc_hisi/modem_vendor/mdmlogdeflatsvr $bin_path
    fi
}

main $@
