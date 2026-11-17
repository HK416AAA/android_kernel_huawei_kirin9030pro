/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : dpe_wlan_user.c
 * 作    者 :
 * 创建日期 : 2024年11月15日
 */

/* 1 头文件包含 */
#include "dpe_wlan_user.h"
#include "dpe_dpa_intf.h"
#include "dpe_wlan_tid.h"
#include "dpe_wlan_resource.h"
#include "oam_ext_if.h"
#include "dpe_schedule.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "hmac_config.h"
#else
#include "dpe_wlan_debug.h"
#include "dpe_frw_if.h"
#endif
#include "dpe_sbuf.h"
#include "hmac_tx_ring_alloc.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DPE_WLAN_USER_C

dpe_wlan_user_atomic_var g_wlan_user_atomic_res[WLAN_USER_MAX_USER_LIMIT];
dpe_wlan_user_stru *g_dpe_wlan_lut_index_tbl[HAL_MAX_TX_BA_LUT_SIZE];
void dpe_wlan_lut_index_tbl_init(void)
{
    memset_s(g_dpe_wlan_lut_index_tbl, sizeof(dpe_wlan_user_stru *) * HAL_MAX_TX_BA_LUT_SIZE, 0,
        sizeof(dpe_wlan_user_stru *) * HAL_MAX_TX_BA_LUT_SIZE);
}

dpe_wlan_user_stru *dpe_wlan_get_user_by_lut_index(uint8_t lut_idx)
{
    dpe_wlan_user_stru *dpe_user = NULL;
    if (lut_idx >= HAL_MAX_TX_BA_LUT_SIZE) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_get_user_by_lut_index::dpe_user null, lut_idx=%d.}", lut_idx);
        return NULL;
    }
    dpe_user = (dpe_wlan_user_stru *)g_dpe_wlan_lut_index_tbl[lut_idx];
    return dpe_user;
}

OAL_STATIC void dpe_wlan_set_user_lut_index_tbl(dpe_wlan_user_stru *dpe_user, uint8_t lut_idx)
{
    if (lut_idx >= HAL_MAX_TX_BA_LUT_SIZE) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_set_user_lut_index_tbl::lut_idx[%d] is invalid!}", lut_idx);
        return;
    }
    g_dpe_wlan_lut_index_tbl[lut_idx] = dpe_user;
}
/*
 * 函 数 名  : dpe_wlan_user_get
 * 功能描述  : 获取对应DPE USER
 * 1.日    期  : 2024年11月18日
 *   修改内容  : 新生成函数
 */
dpe_wlan_user_stru *dpe_wlan_user_get(uint16_t us_idx)
{
    dpe_wlan_res_stru *wlan_res = dpe_wlan_res_addr_get();
    dpe_wlan_device_stru *dpe_device = dpe_wlan_device_get(0);
    dpe_wlan_user_stru *dpe_wlan_user;

    if (us_idx >= WLAN_USER_MAX_USER_LIMIT && dpe_device->en_al_trx_flag != OAL_TRUE) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_user_get::dpe_user null,user_idx=%d.}", us_idx);
        return NULL;
    }
    dpe_wlan_user = (dpe_wlan_user_stru *)(&wlan_res->dpe_wlan_user_res[us_idx]);
    if (dpe_wlan_user->uc_is_user_alloced == MAC_USER_FREED) {
        dpe_print_funcname();
        oam_warning_log1(0, 0, "{dpe_wlan_user_get::[E]user has been freed,user_idx=%d.}", us_idx);
        return NULL;
    }
    return dpe_wlan_user;
}

uint32_t mac_vap_user_exist(oal_dlist_head_stru *pst_new, oal_dlist_head_stru *pst_head)
{
    oal_dlist_head_stru      *pst_user_list_head = NULL;
    oal_dlist_head_stru      *pst_member_entry = NULL;

    oal_dlist_search_for_each_safe(pst_member_entry, pst_user_list_head, pst_head)
    {
        if (pst_new == pst_member_entry) {
            oam_error_log0(0, OAM_SF_DPA, "{mac_vap_user_exist:user doule add.}");
            return OAL_SUCC;
        }
    }

    return OAL_FAIL;
}
OAL_STATIC void dpe_wlan_add_assoc_user(dpe_wlan_user_stru *dpe_user)
{
    oal_uint lock_flag;
    dpe_wlan_vap_stru   *dpe_vap = NULL;
    oal_dlist_head_stru *dlist_head = NULL;
    dpe_vap = dpe_wlan_vap_get(dpe_user->uc_vap_id);
    if (dpe_vap == NULL) {
        return;
    }
    if (mac_vap_user_exist(&(dpe_user->st_user_dlist), &(dpe_vap->st_mac_user_list_head)) == OAL_SUCC) {
        oam_error_log1(dpe_user->uc_vap_id, OAM_SF_DPA,
                       "dpe_wlan_add_assoc_user:: user[%d] already exist", dpe_user->us_assoc_id);
        return;
    }
    dpe_user->us_user_hash_idx = mac_calculate_hash_value(dpe_user->auc_user_mac_addr);

    dpe_cache_user_lock_irq_save(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);

    dlist_head = &(dpe_vap->ast_user_hash[dpe_user->us_user_hash_idx]);

    /* 加入双向hash链表表头 */
    oal_dlist_add_head(&(dpe_user->st_user_hash_dlist), dlist_head);

    /* 加入双向链表表头 */
    dlist_head = &(dpe_vap->st_mac_user_list_head);
    oal_dlist_add_head(&(dpe_user->st_user_dlist), dlist_head);

    /* 更新cache user */
    oal_set_mac_addr(dpe_vap->auc_cache_user_mac_addr, dpe_user->auc_user_mac_addr);
    dpe_vap->us_cache_user_id = dpe_user->us_assoc_id;
    /* vap已关联 user个数++ */
    dpe_vap->us_user_nums++;
    dpe_cache_user_unlock_irq_restore(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);
}
OAL_STATIC void dpe_wlan_user_init(dpe_wlan_user_stru *dpe_user, uint16_t us_idx, uint8_t vap_id)
{
    uint8_t tid;

    memset_s(dpe_user, sizeof(dpe_wlan_user_stru), 0, sizeof(dpe_wlan_user_stru));
    dpe_user->us_assoc_id = us_idx;
    dpe_user->uc_vap_id = vap_id;
    dpe_user->uc_is_user_alloced = MAC_USER_ALLOCED;
    dpe_user->dev_rx_list_idx = us_idx;
    oal_spin_lock_init(dpe_get_user_dev_rx_list_lock(dpe_user->dev_rx_list_idx));
    for (tid = 0; tid < WLAN_TID_MAX_NUM; tid++) {
        oal_netbuf_list_head_init_nolock(&(dpe_user->device_rx_list[tid]));
    }
    dpe_user->atomic_val = &g_wlan_user_atomic_res[us_idx];
    oal_atomic_set(&dpe_user->atomic_val->netdev_tx_suspend, OAL_FALSE);
}
OAL_STATIC void dpe_wlan_user_port_valid_init(dpe_wlan_user_stru *dpe_user)
{
    /* 组播用户port默认打开,否则aput不加密场景会拦截组播帧 */
    dpe_user->en_port_valid = dpe_user->en_is_multi_user == OAL_TRUE ? OAL_TRUE : OAL_FALSE;
}

OAL_STATIC dpe_wlan_user_stru *dpe_wlan_user_alloc(uint16_t us_idx)
{
    dpe_wlan_res_stru *wlan_res = dpe_wlan_res_addr_get();
    dpe_wlan_device_stru *dpe_device = dpe_wlan_device_get(0);
    dpe_wlan_user_stru *dpe_wlan_user;

    if (us_idx >= WLAN_USER_MAX_USER_LIMIT && dpe_device->en_al_trx_flag != OAL_TRUE) {
        oam_error_log1(0, 0, "{dpe_wlan_user_get::dpe_user null,user_idx=%d.}", us_idx);
        return NULL;
    }
    dpe_wlan_user = (dpe_wlan_user_stru *)(&wlan_res->dpe_wlan_user_res[us_idx]);
    if (dpe_wlan_user->uc_is_user_alloced == MAC_USER_ALLOCED) {
        oam_warning_log1(0, 0, "{dpe_wlan_user_alloc::[E]user has been alloced,user_idx=%d.}", us_idx);
    }
    return dpe_wlan_user;
}

void dpe_wlan_user_add(uint8_t *add_user_data, uint8_t vap_id)
{
    dpe_wlan_user_stru *user = NULL;
    dmac_ctx_add_user_stru *add_user_payload = (dmac_ctx_add_user_stru *)add_user_data;

    if (add_user_payload == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_user_add::add_user_payload is NULL!}");
        return;
    }

    user = dpe_wlan_user_alloc(add_user_payload->us_user_idx);
    if (user == NULL) {
        return;
    }
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_resource_dump();
#endif
    dpe_wlan_user_init(user, add_user_payload->us_user_idx, vap_id);
    user->en_is_multi_user = OAL_FALSE;
    user->en_is_support_mcast_ampdu = OAL_FALSE;
    user->en_user_asoc_state = MAC_USER_STATE_BUTT;
    oal_set_mac_addr(user->auc_user_mac_addr, add_user_payload->auc_user_mac_addr);
    user->lut_index = add_user_payload->lut_index;
    user->ml_user_lut_idx = add_user_payload->mld_lut_idx;
    dpe_wlan_add_assoc_user(user);
#ifdef _PRE_WLAN_FEATURE_ML
    user->ml_user_id = add_user_payload->ml_user_id;
#endif
    dpe_wlan_user_port_valid_init(user);
    dpe_wlan_set_user_lut_index_tbl(user, user->lut_index);
    dpe_wlan_user_tid_init(add_user_payload->us_user_idx);
    oam_warning_log4(vap_id, OAM_SF_DPA, "{dpe_wlan_user_add::user[%d] mac:%02X:XX:XX:XX:%02X:%02X}",
        user->us_assoc_id, user->auc_user_mac_addr[MAC_ADDR_0],
        user->auc_user_mac_addr[MAC_ADDR_4], user->auc_user_mac_addr[MAC_ADDR_5]);
}

void dpe_wlan_multi_user_add(uint16_t us_idx, uint8_t vap_id, uint8_t multi_user_lut_idx,
    uint8_t multi_user_ml_lut_idx, uint8_t support_mcast_ampdu)
{
    dpe_wlan_user_stru *user = dpe_wlan_user_alloc(us_idx);
    if (user == NULL) {
        return;
    }

    dpe_wlan_user_init(user, us_idx, vap_id);
    user->en_is_multi_user = OAL_TRUE;
    user->en_is_support_mcast_ampdu = support_mcast_ampdu;
    user->lut_index = multi_user_lut_idx;
    user->ml_user_lut_idx = multi_user_ml_lut_idx;
#ifdef _PRE_WLAN_FEATURE_ML
    user->ml_user_id = 0xFF;
#endif
    user->en_user_asoc_state = MAC_USER_STATE_ASSOC;
    dpe_wlan_user_port_valid_init(user);
    /* 如果组播用户支持组播聚合，需要申请tid资源 */
    if (support_mcast_ampdu == OAL_TRUE) {
        dpe_wlan_user_tid_init(user->us_assoc_id);
        /* 默认组播用户的lut_index无效，仅组播聚合时有效 */
        dpe_wlan_set_user_lut_index_tbl(user, user->lut_index);
    }
    oam_warning_log4(vap_id, OAM_SF_DPA, "MCAST_AMPDU::dpe_wlan_multi_user_add user[%u] support[%u] lut[%u] ml lut[%u]",
        us_idx, support_mcast_ampdu, user->lut_index, user->ml_user_lut_idx);
}

uint32_t dpe_vap_hash_del_user(dpe_wlan_vap_stru *dpe_vap, dpe_wlan_user_stru *dpe_user)
{
    dpe_wlan_user_stru     *pst_user_temp       = NULL;
    oal_dlist_head_stru    *pst_hash_head       = NULL;
    oal_dlist_head_stru    *pst_entry           = NULL;
    oal_dlist_head_stru    *pst_dlist_tmp       = NULL;
    uint32_t              ret              = OAL_FAIL;

    pst_hash_head = &(dpe_vap->ast_user_hash[dpe_user->us_user_hash_idx]);

    oal_dlist_search_for_each_safe(pst_entry, pst_dlist_tmp, pst_hash_head) {
        pst_user_temp = (dpe_wlan_user_stru *)oal_dlist_get_entry(pst_entry, dpe_wlan_user_stru, st_user_hash_dlist);
        if (pst_user_temp == NULL) {
            oam_error_log1(dpe_vap->uc_vap_id, OAM_SF_DPA,
                           "{dpe_vap_hash_del_user::pst_user_temp null,us_user_idx is %d}", dpe_user->us_assoc_id);
            continue;
        }

        if (!oal_compare_mac_addr(dpe_user->auc_user_mac_addr, pst_user_temp->auc_user_mac_addr)) {
            oal_dlist_delete_entry(pst_entry);

            /* 从双向链表中拆掉 */
            oal_dlist_delete_entry(&(dpe_user->st_user_dlist));

            oal_dlist_delete_entry(&(dpe_user->st_user_hash_dlist));
            ret = OAL_SUCC;
            /* 初始化相应成员 */
            dpe_user->us_user_hash_idx = DPE_VAP_USER_HASH_MAX_VALUE;
            memset_s(dpe_user->auc_user_mac_addr, WLAN_MAC_ADDR_LEN, 0, WLAN_MAC_ADDR_LEN);
            if (dpe_vap->us_user_nums) {
                dpe_vap->us_user_nums--;
            }
        }
    }

    return ret;
}
uint32_t dpe_wlan_vap_del_user(dpe_wlan_user_stru *dpe_user)
{
    oal_uint lock_flag;
    dpe_wlan_vap_stru   *dpe_vap = NULL;
    uint32_t      ret;
    dpe_vap = dpe_wlan_vap_get(dpe_user->uc_vap_id);
    if (dpe_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    dpe_cache_user_lock_irq_save(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);

    /* 与cache user id对比 , 相等则清空cache user */
    if (dpe_user->us_assoc_id == dpe_vap->us_cache_user_id) {
        oal_set_mac_addr_zero(dpe_vap->auc_cache_user_mac_addr);
        /*  解决用户已删除，cache id和mac addr均为0，导致发送完成中断下半部依旧可以找到已删除的用户 */
        dpe_vap->us_cache_user_id = g_wlan_spec_cfg->invalid_user_id;
    }

    if (dpe_user->us_user_hash_idx >= DPE_VAP_USER_HASH_MAX_VALUE) {
        /* ADD USER命令丢失，或者重复删除User都可能进入此分支。 */
        dpe_cache_user_unlock_irq_restore(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);

        oam_error_log1(dpe_vap->uc_vap_id, OAM_SF_DPA, "{dpe_wlan_vap_del_user::hash idx invaild %u}",
                       dpe_user->us_user_hash_idx);
        return OAL_FAIL;
    }

    ret = dpe_vap_hash_del_user(dpe_vap, dpe_user);
    if (ret != OAL_SUCC) {
        oam_warning_log1(dpe_vap->uc_vap_id, OAM_SF_DPA,
                         "{dpe_wlan_vap_del_user::delete user failed,user idx is %d.}", dpe_user->us_assoc_id);
    }
    dpe_cache_user_unlock_irq_restore(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);
    return ret;
}
void dpe_wlan_user_list_free(dpe_wlan_user_stru *dpe_user)
{
    uint8_t tid;
    oal_uint irq_flags;
    oal_netbuf_head_stru *list_head = NULL;

    oal_spin_lock_irq_save(dpe_get_user_dev_rx_list_lock(dpe_user->dev_rx_list_idx), &irq_flags);
    for (tid = 0; tid < WLAN_TID_MAX_NUM; tid++) {
        list_head = &(dpe_user->device_rx_list[tid]);
        dpe_netbuf_free_list_all(list_head, oal_netbuf_list_len(list_head));
    }
    oal_spin_unlock_irq_restore(dpe_get_user_dev_rx_list_lock(dpe_user->dev_rx_list_idx), &irq_flags);
}
/*
HMAC通知DPE侧删除user
DPE USER去初始化接口，在迁移tid_res变量后，需要调用该接口进行处理，
并将其它直接调用dpe_user下变量去初始化的位置进行替换
 */
void dpe_wlan_user_del(uint8_t *del_user_data)
{
    dpe_wlan_user_stru *user = NULL;
    dmac_ctx_del_user_stru *del_user_payload = (dmac_ctx_del_user_stru *)del_user_data;

    if (del_user_payload == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_user_del::del_user_payload is NULL!}");
        return;
    }
    user = dpe_wlan_user_get(del_user_payload->us_user_idx);
    if (user == NULL) {
        return;
    }
    dpe_user_tx_ring_deinit(del_user_payload->us_user_idx);
    dpe_user_tid_res_deinit(del_user_payload->us_user_idx);
    dpe_wlan_set_user_lut_index_tbl(NULL, user->lut_index);
    dpe_wlan_vap_del_user(user);

    dpe_wlan_user_list_free(user);
    OAL_SPIN_LOCK_EXIT(dpe_get_user_dev_rx_list_lock(user->dev_rx_list_idx));

    user->us_assoc_id = del_user_payload->us_user_idx;
    user->en_is_multi_user = OAL_FALSE;
#ifdef _PRE_WLAN_FEATURE_ML
    user->ml_user_id = 0xFF;
#endif
    user->uc_is_user_alloced = MAC_USER_FREED;
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    dpe_resource_dump();
#endif
    oam_warning_log1(0, OAM_SF_DPA, "{dpe_wlan_user_del:free user[%d]}", del_user_payload->us_user_idx);
}

void dpe_wlan_del_multi_user(uint16_t user_idx, uint32_t support_mcast_ampdu)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL) {
        return;
    }
    if (support_mcast_ampdu == OAL_TRUE) {
        dpe_user_tx_ring_deinit(user_idx);
        dpe_user_tid_res_deinit(user_idx);
        dpe_wlan_set_user_lut_index_tbl(NULL, dpe_user->lut_index);
    }
    oam_warning_log4(0, OAM_SF_DPA, "MCAST_AMPDU::dpe_wlan_del_multi_user user[%u] support[%u] lut[%u] ml lut[%u]",
        user_idx, support_mcast_ampdu, dpe_user->lut_index, dpe_user->ml_user_lut_idx);

    dpe_wlan_user_list_free(dpe_user);
    OAL_SPIN_LOCK_EXIT(dpe_get_user_dev_rx_list_lock(dpe_user->dev_rx_list_idx));

    dpe_user->en_port_valid = OAL_FALSE;
    dpe_user->us_assoc_id = WLAN_USER_MAX_USER_LIMIT;
    dpe_user->uc_vap_id = WLAN_VAP_MAX_NUM_LIMIT;
    dpe_user->en_is_multi_user = OAL_FALSE;
    dpe_user->lut_index = HAL_MAX_TX_BA_LUT_SIZE;
    dpe_user->en_user_asoc_state = MAC_USER_STATE_BUTT;
    dpe_user->uc_is_user_alloced = MAC_USER_FREED;
}

void dpe_wlan_user_assoc_state_sync(uint16_t user_idx, mac_user_asoc_state_enum_uint8 user_asoc_state)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL) {
        return;
    }

    dpe_user->en_user_asoc_state = user_asoc_state;
}

void dpe_wlan_user_info_sync(uint8_t *param)
{
    dpe_wlan_user_stru *dpe_user = NULL;
    mac_h2d_usr_info_stru *mac_h2d_usr_info = NULL;

    if (param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_user_info_sync::param is NULL!}");
        return;
    }

    mac_h2d_usr_info = (mac_h2d_usr_info_stru *)param;
    dpe_user = dpe_wlan_user_get(mac_h2d_usr_info->us_user_idx);
    if (dpe_user == NULL) {
        return;
    }
    dpe_user->en_user_asoc_state = mac_h2d_usr_info->en_user_asoc_state;
}

void dpe_wlan_user_addr_sync(uint16_t user_idx, uint8_t *addr)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL) {
        return;
    }

    oal_set_mac_addr(dpe_user->auc_user_mac_addr, addr);
}

OAL_STATIC void dpe_ap_find_user_by_macaddr(dpe_wlan_vap_stru *dpe_vap, const unsigned char *sta_mac_addr,
    uint16_t *user_idx)
{
    oal_uint lock_flag;
    uint32_t user_hash_value;
    oal_dlist_head_stru *pst_entry = NULL;
    dpe_wlan_user_stru  *dpe_user = NULL;

    dpe_cache_user_lock_irq_save(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);

    /* 与cache user对比 , 相等则直接返回cache user id */
    if (!oal_compare_mac_addr(dpe_vap->auc_cache_user_mac_addr, sta_mac_addr)) {
        /* 用户删除后，user macaddr和cache user macaddr地址均为0，但实际上用户已经删除，此时user id无效 */
        *user_idx = dpe_vap->us_cache_user_id;
    } else {
        user_hash_value = mac_calculate_hash_value(sta_mac_addr);

        oal_dlist_search_for_each(pst_entry, &(dpe_vap->ast_user_hash[user_hash_value]))
        {
            dpe_user = (dpe_wlan_user_stru *)oal_dlist_get_entry(pst_entry, dpe_wlan_user_stru, st_user_hash_dlist);
            if (dpe_user == NULL) {
                oam_error_log0(dpe_vap->uc_vap_id, OAM_SF_DPA,
                               "{dpe_ap_find_user_by_macaddr::mac_user null.}");
                continue;
            }
            /* 相同的 */
            if (!oal_compare_mac_addr(dpe_user->auc_user_mac_addr, sta_mac_addr)) {
                *user_idx = dpe_user->us_assoc_id;
                /* 更新cache user */
                oal_set_mac_addr(dpe_vap->auc_cache_user_mac_addr, dpe_user->auc_user_mac_addr);
                dpe_vap->us_cache_user_id = dpe_user->us_assoc_id;
            }
        }
    }
    dpe_cache_user_unlock_irq_restore(dpe_get_vap_cache_user_lock(dpe_vap->cache_user_lock_idx), &lock_flag);
}
/*
 * 功能描述  : 根据mac地址 查找dpe user对象
 * 日    期  : 2024年02月14日
 */
uint32_t dpe_vap_find_user_by_macaddr(uint8_t vap_id, const unsigned char *sta_mac_addr,
    uint16_t *user_idx)
{
    dpe_wlan_user_stru  *dpe_user = NULL;
    dpe_wlan_vap_stru   *dpe_vap = NULL;

    if (oal_unlikely(oal_any_null_ptr2(sta_mac_addr, user_idx))) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_vap_find_user_by_macaddr::param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    dpe_vap = dpe_wlan_vap_get(vap_id);
    if (dpe_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    /*
     * 1.本函数*user_idx先初始化为无效值，防止调用者没有初始化，可能出现使用返回值异常;
     * 2.根据查找结果刷新*user_idx值，如果是有效，返回SUCC,无效MAC_INVALID_USER_ID返回FAIL;
     * 3.调用函数根据首先根据本函数返回值做处理，其次根据*user_idx进行其他需要的判断和操作
     */
    *user_idx = g_wlan_spec_cfg->invalid_user_id;

    if (dpe_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        dpe_user = (dpe_wlan_user_stru *)dpe_wlan_user_get(dpe_vap->us_assoc_vap_id);
        if (dpe_user == NULL) {
            return OAL_FAIL;
        }

        if (!oal_compare_mac_addr(dpe_user->auc_user_mac_addr, sta_mac_addr)) {
            *user_idx = dpe_vap->us_assoc_vap_id;
        }
    } else {
        dpe_ap_find_user_by_macaddr(dpe_vap, sta_mac_addr, user_idx);
    }

    /*
     * user id有效的话，返回SUCC给调用者处理，user id无效的话，
     * 返回user id为MAC_INVALID_USER_ID，并返回查找结果FAIL给调用者处理
     */
    if (*user_idx == g_wlan_spec_cfg->invalid_user_id) {
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_ML
void dpe_wlan_config_h2d_user_change_to_mld_mode(uint8_t *event_mem)
{
    dpe_wlan_user_stru *dpe_user;
    user_mld_mode_change_stru *add_mld_user_param;

    if (event_mem == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_config_h2d_user_change_to_mld_mode::event_mem is NULL!}");
        return;
    }

    add_mld_user_param = (user_mld_mode_change_stru *)event_mem;
    dpe_user = dpe_wlan_user_get(add_mld_user_param->user_idx);
    if (dpe_user == NULL) {
        return;
    }

    dpe_user->ml_user_id = add_mld_user_param->ml_user_id;
}
#endif  /* _PRE_WLAN_FEATURE_ML */

void dpe_user_set_port_sync(uint16_t user_idx, oal_bool_enum_uint8 en_port_valid)
{
    dpe_wlan_user_stru *dpe_user = dpe_wlan_user_get(user_idx);
    if (dpe_user == NULL) {
        return;
    }
    dpe_user->en_port_valid = en_port_valid;
}

/* 入参判空由调用者保证 */
uint8_t dpe_wlan_is_multi_user_not_support_ampdu(dpe_wlan_user_stru *dpe_user)
{
    dpe_wlan_vap_stru *dpe_vap = NULL;
    if (dpe_user->en_is_multi_user == OAL_FALSE) {
        return OAL_FALSE;
    }

    /* vap找不到，认为不支持组播聚合 */
    dpe_vap = dpe_wlan_vap_get(dpe_user->uc_vap_id);
    if (oal_unlikely(dpe_vap == NULL)) {
        return OAL_TRUE;
    }
    if (dpe_vap->bit_support_mcast_ampdu == OAL_FALSE) {
        return OAL_TRUE;
    }
    return OAL_FALSE;
}

/* 功能描述: 更新dpe_user上保存的密钥类型 */
void dpe_wlan_update_user_key_info(uint8_t *param)
{
    mac_user_key_sync_dpe_info *sync_key_info = NULL;
    dpe_wlan_user_stru *dpe_user = NULL;
    if (param == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{dpe_wlan_update_user_key_info:parm is NULL!}");
        return;
    }
    sync_key_info = (mac_user_key_sync_dpe_info *)param;
    dpe_user = dpe_wlan_user_get(sync_key_info->user_idx);
    if (dpe_user == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{dpe_wlan_update_user_key_info:faitl to get user[%d]!}",
            sync_key_info->user_idx);
        return;
    }
    dpe_user->cipher_type = sync_key_info->key_info.en_cipher_type;
}
