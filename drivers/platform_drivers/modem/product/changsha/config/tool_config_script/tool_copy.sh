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

    src_path=$root_dir/$BUILD_OUT/device_soc_hisi/modem_vendor
    dst_config_path=$root_dir/$BUILD_OUT/packages/phone/modem_vendor/config
    src_tool_logcfg_path=$src_path/tool_logcfg
    src_tool_chrcfg_path=$src_path/tool_chrcfg
    dst_tool_logcfg_path=$dst_config_path/tool_logcfg
    dst_tool_chrcfg_path=$dst_config_path/tool_chrcfg
    echo src_tool_logcfg_path=$src_tool_logcfg_path
    echo src_tool_chrcfg_path=$src_tool_chrcfg_path
    echo dst_tool_logcfg_path=$dst_tool_logcfg_path
    echo dst_tool_chrcfg_path=$dst_tool_chrcfg_path

    mkdir -p $dst_tool_logcfg_path
    mkdir -p $dst_tool_chrcfg_path

    cp -r $src_tool_logcfg_path/log_default.cfg $dst_tool_logcfg_path/log_default.cfg
    cp -r $src_tool_logcfg_path/log_mid.cfg $dst_tool_logcfg_path/log_mid.cfg
    cp -r $src_tool_logcfg_path/log_mini.cfg $dst_tool_logcfg_path/log_mini.cfg
    cp -r $src_tool_chrcfg_path/chr_msg.db $dst_tool_chrcfg_path/chr_msg.db
    cp -r $src_tool_chrcfg_path/chr_msg_group.xml $dst_tool_chrcfg_path/chr_msg_group.xml
}

main $@
