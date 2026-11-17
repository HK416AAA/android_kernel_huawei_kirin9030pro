/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 功能说明 : Hertz平台翻译适配源文件
 */
#ifdef _PRE_WLAN_FEATURE_CLAT
#include "hmac_clat.h"
#include "clat_balong.h"

/*
* 函 数 名 : hmac_clat_proc
* 功能描述 : hisi 驱动CLAT 功能处理函数
* 日 期 : 2024年5月7日
* 作 者 : liuzixi
* 修改内容 : 新生成函数
 */
int32_t hmac_clat_proc(oal_net_device_stru *ndev, oal_netbuf_stru *skb, char type)
{
    if (is_clat_transl_enable() == IS_CLAT_TRANSLATE) {
        clat_transl_result_t transl_ret;
        oal_netbuf_stru      *new_skb = NULL;
        if (type != IPV6_TO_IPV4 && type != IPV4_TO_IPV6) {
            return OAL_FAIL;
        }

        transl_ret = clat_transl_pkt(skb, type, 0, &(ndev->dev), &new_skb);
        switch (transl_ret) {
            case TRANSL_SUCCESS:
            case TRANSL_NO_NEED:
            case TRANSL_PARAM_ERR:
            case TRANSL_TYPE_UNMATCH:
                return OAL_SUCC;
            case TRANSL_EXCESS_MTU:
            case TRANSL_NOMEM:
            case TRANSL_PKT_ERR:
            case TRANSL_SILENTLY_DROP:
            default:
                return OAL_FAIL;
        }
    }
    return OAL_SUCC;
}
#endif
