/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : wal_linux_vap_proc.c 文件 proc 文件系统 E5 产品使用
 * 作    者 : wifi3
 * 创建日期 : 2024年5月18日
 */
#ifdef _PRE_WLAN_VAP_PROC
#include "wal_linux_vap_proc.h"
#include "wal_linux_vendor.h"
#include "wal_linux_cfgvendor.h"
#include "hmac_invoke_dpe.h"

#define KBPS_100            (100)
#define QUERY_STA_INFO_TIME (5 * OAL_TIME_HZ)
#define CHANNLE_LIST_LENGTH (256)

static void wal_show_sta_info(struct seq_file *file, mac_user_stru *mac_user, hmac_user_stru *hmac_user)
{
    mac_vap_stru        *mac_vap  = NULL;
    int8_t              *protocol2string[] = {"11a", "11b", "error", "11bg", "11g", "11n", "11ac",
                                              "11nonly", "11aconly", "11ng", "11ax", "error", "error",
                                              "11be"};
    uint32_t            curr_time;
    hmac_vap_stru       *hmac_vap = NULL;
    dpe_wlan_user_stat_stru *user_stats = NULL;

    if (file == NULL || mac_user == NULL || hmac_user == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "wal_show_sta_info: para is null.");
        return;
    }
    curr_time = (uint32_t)oal_time_get_stamp_ms();
    mac_vap = (mac_vap_stru *)(file->private);
    if (mac_vap == NULL) {
        return;
    }
    user_stats = hmac_wlan_user_stat_get(hmac_user->st_user_base_info.us_assoc_id);
    if (user_stats == NULL) {
        return;
    }
    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_ANY, "wal_show_sta_info: hmac vap is null. vap id:%d",
            mac_vap->uc_vap_id);
        return;
    }

    seq_printf(file, "aid: %hu\n"
        "    MAC ADDR: %02X:**:**:**:%02X:%02X\n"
        "    status: %hhu\n" "    BW: %d\n" "    NSS: %d\n" "    RSSI: %d\n"
        "    phy type: %s\n" "    TX rate: %ukbps\n" "    RX rate: %ukbps\n"
        "    RX rate_min: %ukbps\n" "    RX rate_max: %ukbps\n"
        "    user online time: %us\n" "    TX packets succ: %u\n"
        "    TX packets fail: %u\n" "    RX packets succ: %u\n"
        "    RX packets fail: %u\n" "    TX power: %ddBm\n"
        "    TX bytes: %llu\n" "    RX bytes: %llu\n" "    TX retries: %u\n",
        mac_user->us_assoc_id,
        mac_user->auc_user_mac_addr[0], mac_user->auc_user_mac_addr[4], mac_user->auc_user_mac_addr[5], // 地址目录0 4 5
        mac_user->en_user_asoc_state, wal_bw_en_to_number(mac_user->en_avail_bandwidth),
        (mac_user->en_avail_num_spatial_stream+1), hmac_user->c_rssi,
        protocol2string[mac_user->en_avail_protocol_mode], hmac_user->tx_rate,
        hmac_user->rx_rate, hmac_user->rx_rate_min,
        hmac_user->rx_rate_max, (uint32_t)oal_delta_count32(hmac_user->first_add_time, curr_time) / MS_TO_S,
        user_stats->tx_packets, hmac_vap->station_info.tx_failed,
        user_stats->rx_packets, hmac_vap->station_info.rx_dropped_misc,
        mac_vap->uc_tx_power, user_stats->tx_bytes,
        user_stats->rx_bytes, hmac_vap->station_info.tx_retries);
    seq_printf(file, "sta diag info:\n" "    tx_bandwidth: %d\n" "    rx_bandwidth: %d\n"
        "    tx_rate: %d (100kps)\n" "    rx_rate: %d (100kps)\n",
        wal_bw_en_to_number(mac_user->en_cur_bandwidth), wal_bw_en_to_number(mac_user->en_cur_bandwidth),
        hmac_user->tx_rate / KBPS_100, hmac_user->rx_rate / KBPS_100);
    return;
}

static int32_t wal_vap_get_channel_list(oal_net_device_stru *net_dev, mac_vap_stru *mac_vap_info,
    void *buff, uint32_t size)
{
    int idx = 0;
    int32_t ret = OAL_FAIL;
    int32_t offset = 0;
    int32_t channel_list_arry[VENDOR_CHANNEL_LIST_ALL + 1] = { 0 };
    uint32_t num_channels = 0;
    uint32_t channel_number = 0; // 数字 信道 1,2，……13,36……149

    if (net_dev == NULL || mac_vap_info == NULL || buff == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_vap_get_channel_list::para is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (mac_vap_info->st_channel.en_band == WLAN_BAND_2G) {
        ret = wal_cfgvendor_get_current_channel_list(net_dev, WIFI_BAND_24_GHZ, channel_list_arry, &num_channels);
    } else if (mac_vap_info->st_channel.en_band == WLAN_BAND_5G) {
        ret = wal_cfgvendor_get_current_channel_list(net_dev, WIFI_BAND_5_GHZ_WITH_DFS,
            channel_list_arry, &num_channels);
    }
    if (ret != OAL_SUCC) {
        return OAL_FAIL;
    }
    offset = 0;
    ret = snprintf_s((int8_t *)(buff + offset), size - offset, size - offset - 1,
        "%lu ", num_channels);
    if (ret < 0) {
        oam_error_log0(0, OAM_SF_ANY, "wal_vap_get_channel_list mem buff overrun.");
        return -OAL_ENOMEM;
    }
    offset += ret;
    for (idx = 0; idx < num_channels; idx++) {
        channel_number = oal_ieee80211_frequency_to_channel(channel_list_arry[idx]);
        if (size < offset + 1) {
            oam_error_log0(0, OAM_SF_ANY, "wal_vap_get_channel_list mem buff overrun.");
            return -OAL_ENOMEM;
        }
        ret = snprintf_s((int8_t *)(buff + offset), size - offset, size - offset - 1,
            "%lu ", channel_number);
        if (ret < 0) {
            oam_error_log0(0, OAM_SF_ANY, "wal_vap_get_channel_list mem buff overrun.");
            return -OAL_ENOMEM;
        }
        offset += ret;
    }
    return OAL_SUCC;
}

static int32_t wal_sta_info_seq_show(struct seq_file *file, void *v)
{
    mac_vap_stru        *mac_vap  = (mac_vap_stru *)(file->private);
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *entry_temp = NULL;
    mac_user_stru       *mac_user = NULL;
    hmac_user_stru      *hmac_user = NULL;
    uint16_t            idx = 1; // 目录索引 1

    if (mac_vap == NULL) {
        return OAL_FAIL;
    }
    seq_printf(file, "Total user nums: %hu\n", mac_vap->us_user_nums);
    seq_printf(file, "-- STA info table --\n");

    oal_dlist_search_for_each_safe(entry, entry_temp, &(mac_vap->st_mac_user_list_head))
    {
        mac_user = oal_dlist_get_entry(entry, mac_user_stru, st_user_dlist);
        if (entry_temp == NULL) {
            break;
        }
        if (mac_user == NULL) {
            continue;
        }
        hmac_user = mac_res_get_hmac_user(mac_user->us_assoc_id);
        if (hmac_user == NULL) {
            continue;
        }

        seq_printf(file, "%2hu: ", idx);
        wal_vendor_get_user_info_ext(mac_vap, mac_user->auc_user_mac_addr);
        wal_show_sta_info(file, mac_user, hmac_user);
        idx++;
    }

    return OAL_SUCC;
}

static int32_t wal_vap_info_seq_show(struct seq_file *file, void *v)
{
    uint32_t ret;
    mac_vap_stru *mac_vap_info = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    mac_regdomain_info_stru *rd_info = NULL;
    int8_t *channel_list = NULL;
    dpe_wlan_vap_stat_stru *vap_stats = NULL;
    mac_vap_stru *mac_vap  = (mac_vap_stru *)(file->private);

    if (mac_vap == NULL) {
        return -OAL_EINVAL;
    }
    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    vap_stats = hmac_wlan_vap_stat_get(mac_vap->uc_vap_id);
    if (hmac_vap == NULL || vap_stats == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "wal_vap_info_seq_show::vap is null");
        return -OAL_EINVAL;
    }
    wal_vendor_query_vap_info_ext(mac_vap);
    mac_vap_info = &(hmac_vap->st_vap_base_info);
    mac_get_regdomain_info(&rd_info);
    if (rd_info == NULL) {
        return -OAL_EINVAL;
    }
    channel_list = (int8_t *)oal_memalloc(CHANNLE_LIST_LENGTH);
    if (channel_list == NULL) {
        return -OAL_ENOMEM;
    }
    memset_s(channel_list, CHANNLE_LIST_LENGTH, 0, CHANNLE_LIST_LENGTH);

    wal_vap_get_channel_list(hmac_vap->pst_net_device, mac_vap_info, channel_list, CHANNLE_LIST_LENGTH);

    seq_printf(file, "vap stats:\n" "  TX packets: %u\n" "  TX bytes: %llu\n" "  TX packets fail: %u\n"
        "  RX packets: %u\n" "  RX bytes: %llu\n" "  RX packets drop: %u\n",
        vap_stats->tx_packets, vap_stats->tx_bytes, vap_stats->tx_failed, vap_stats->rx_packets,
        vap_stats->rx_bytes, vap_stats->rx_dropped_misc);

    seq_printf(file, "vap diag info:\n"
        "  BSSID: %02X:xx:xx:xx:%02X:%02X\n" "  band:%s\n" "  bandwidth: %hhu\n"
#ifdef CONFIG_HW_GET_EXT_SIG
        "  channel_usage: %hu\n"
#endif
        "  channel number: %hhu\n" "  country code: %s\n" "  channel_list: %s\n"
        "  wmm_switch: %d\n" "  sta_cnt: %u\n" "  free_power: %d\n",
        mac_vap_info->auc_bssid[0], mac_vap_info->auc_bssid[4], mac_vap_info->auc_bssid[5], // ssid目录0 4 5
        (mac_vap_info->st_channel.en_band == WLAN_BAND_2G ? "2G" : "5G"),
        wal_get_vap_band_width(mac_vap_info->st_channel.en_bandwidth),
#ifdef CONFIG_HW_GET_EXT_SIG
        hmac_vap->station_info.chload,
#endif
        mac_vap_info->st_channel.uc_chan_number, rd_info->ac_country, channel_list,
        mac_vap_info->en_vap_wmm, mac_vap_info->us_user_nums, hmac_vap->s_free_power);
    oal_free(channel_list);
    return OAL_SUCC;
}

static int32_t wal_sta_info_proc_open(struct inode *inode, struct file *file)
{
    int32_t               ret;
    struct proc_dir_entry *pde = PDE(inode);
    if (pde == NULL) {
        return OAL_FAIL;
    }
    ret = single_open(file, wal_sta_info_seq_show, pde->data);
    return ret;
}

static int32_t wal_vap_info_proc_open(struct inode *inode, struct file *file)
{
    int32_t               ret;
    struct proc_dir_entry *pde = PDE(inode);
    if (pde == NULL) {
        return OAL_FAIL;
    }
    ret = single_open(file, wal_vap_info_seq_show, pde->data);
    return ret;
}

static ssize_t wal_sta_info_proc_write(struct file *file, const char __user *buffer, size_t len, loff_t *off)
{
    char mode;
    if (len < 1) {
        return -EINVAL;
    }

    if (copy_from_user(&mode, buffer, sizeof(mode))) {
        return -EFAULT;
    }

    return len;
}

static ssize_t wal_vap_info_proc_write(struct file *file, const char __user *buffer, size_t len, loff_t *off)
{
    char mode;
    if (len < 1) {
        return -EINVAL;
    }

    if (copy_from_user(&mode, buffer, sizeof(mode))) {
        return -EFAULT;
    }

    return len;
}

/*****************************************************************************
    gst_sta_info_proc_fops: 定义sta info proc fops
*****************************************************************************/
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops gst_sta_info_proc_fops = {
    .proc_open = wal_sta_info_proc_open,
    .proc_read = seq_read,
    .proc_write = wal_sta_info_proc_write,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};
#else
static OAL_CONST struct file_operations gst_sta_info_proc_fops = {
    .owner      = THIS_MODULE,
    .open       = wal_sta_info_proc_open,
    .read       = seq_read,
    .write      = wal_sta_info_proc_write,
    .llseek     = seq_lseek,
    .release    = single_release,
};
#endif

/*****************************************************************************
    gst_vap_info_proc_fops: 定义vap info proc fops
*****************************************************************************/
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops gst_vap_info_proc_fops = {
    .proc_open = wal_vap_info_proc_open,
    .proc_read = seq_read,
    .proc_write = wal_vap_info_proc_write,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};
#else
static OAL_CONST struct file_operations gst_vap_info_proc_fops = {
    .owner      = THIS_MODULE,
    .open       = wal_vap_info_proc_open,
    .read       = seq_read,
    .write      = wal_vap_info_proc_write,
    .llseek     = seq_lseek,
    .release    = single_release,
};
#endif

void wal_add_vap_proc_file(oal_net_device_stru *net_dev)
{
    mac_vap_stru                        *mac_vap = NULL;
    hmac_vap_stru                       *hmac_vap = NULL;
    oal_proc_dir_entry_stru             *proc_dir = NULL;
    oal_proc_dir_entry_stru             *proc_vap_info = NULL;
    oal_proc_dir_entry_stru             *proc_sta_info = NULL;

    if (net_dev == NULL) {
        return;
    }

    mac_vap = (mac_vap_stru *)oal_net_dev_priv(net_dev);
    if (mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{mac_vap wal_add_vap_proc_file is NULL}");
        return;
    }

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "wal_add_vap_proc_file: hmac_vap is null ptr!");
        return;
    }

    proc_dir = proc_mkdir(net_dev->name, NULL);
    if (proc_dir == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "wal_add_vap_proc_file: proc_mkdir return null");
        return;
    }
    /* 416为文件权限:110-6 100-4 000-0 */
    proc_vap_info = proc_create("ap_info", 416, proc_dir, &gst_vap_info_proc_fops);
    if (proc_vap_info == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "wal_add_vap_proc_file: proc_create return null");
        oal_remove_proc_entry(net_dev->name, NULL);
        return;
    }
    /* 416为文件权限:110-6 100-4 000-0 */
    proc_sta_info = proc_create("sta_info", 416, proc_dir, &gst_sta_info_proc_fops);
    if (proc_sta_info == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "wal_add_vap_proc_file: proc_create return null");
        oal_remove_proc_entry("ap_info", proc_dir);
        oal_remove_proc_entry(net_dev->name, NULL);
        return;
    }

    proc_vap_info->data       = mac_vap;
    proc_sta_info->data       = mac_vap;
    hmac_vap->proc_dir        = proc_dir;
}

void wal_del_vap_proc_file(oal_net_device_stru *net_dev)
{
    mac_vap_stru   *mac_vap = NULL;
    hmac_vap_stru  *hmac_vap = NULL;

    mac_vap = oal_net_dev_priv(net_dev);
    if (mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "wal_del_vap_proc_file: mac_vap is null ptr.");
        return;
    }

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log1(0, OAM_SF_ANY, "wal_del_vap_proc_file: hmac_vap is null ptr. mac vap id:%d", mac_vap->uc_vap_id);
        return;
    }

    if (hmac_vap->proc_dir != NULL) {
        oal_remove_proc_entry("sta_info", hmac_vap->proc_dir);
        oal_remove_proc_entry("ap_info", hmac_vap->proc_dir);
        oal_remove_proc_entry((const int8_t *)hmac_vap->auc_name, NULL);
        hmac_vap->proc_dir = NULL;
    }
}

OAL_STATIC int32_t wal_vendor_find_sta_mac(mac_vap_stru *mac_vap, dmac_query_station_info_request_event *query_sta_info)
{
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *entry_temp = NULL;
    mac_user_stru *mac_user = NULL;
    hmac_user_stru *hmac_user = NULL;
    int32_t find_sta_mac = 0;

    if (mac_vap == NULL || query_sta_info == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_vendor_query_sta_count::return null!}");
        return OAL_FALSE;
    }

    oal_dlist_search_for_each_safe(entry, entry_temp, &(mac_vap->st_mac_user_list_head))
    {
        mac_user = oal_dlist_get_entry(entry, mac_user_stru, st_user_dlist);
        if (entry_temp == NULL) {
            break;
        }
        if (mac_user == NULL) {
            continue;
        }
        hmac_user = mac_res_get_hmac_user(mac_user->us_assoc_id);
        if (hmac_user == NULL) {
            continue;
        }
        /* 只要找到1个sta 就退出 */
        find_sta_mac = OAL_TRUE;
        oal_set_mac_addr(query_sta_info->auc_query_sta_addr, (uint8_t *)(mac_user->auc_user_mac_addr));
        break;
    }
    return find_sta_mac;
}


int32_t wal_vendor_query_vap_info_ext(mac_vap_stru *mac_vap)
{
    dmac_query_station_info_request_event *query_station_info = NULL;
    wal_msg_write_stru write_msg = {0};
    int32_t ret;
    int64_t leftime;
    hmac_vap_stru *hmac_vap = NULL;

    if (mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_vendor_query_vap_info_ext::return null!}");
        return -OAL_EINVAL;
    }

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_ANY, "wal_vendor_query_vap_info_ext: hmac vap is null. vap id:%d",
            mac_vap->uc_vap_id);
        return -OAL_EINVAL;
    }
    query_station_info = (dmac_query_station_info_request_event *)write_msg.auc_value;
    query_station_info->query_event = OAL_QUERY_STATION_INFO_EVENT;
    hmac_vap->station_info_query_completed_flag = OAL_FALSE;

    if (wal_vendor_find_sta_mac(mac_vap, query_station_info) != OAL_TRUE) {
#ifdef CONFIG_HW_GET_EXT_SIG
        hmac_vap->station_info.chload = 0;
#endif
        hmac_vap->s_free_power = 0;
        return OAL_SUCC;
    }

    wal_write_msg_hdr_init(&write_msg, WLAN_CFGID_QUERY_STATION_STATS, sizeof(dmac_query_station_info_request_event));
    if (hmac_vap->pst_net_device == NULL) {
        oam_error_log0(0, 0, "{wal_vendor_query_vap_info_ext::hmac_vap->pst_net_device == NULL!}");
        return -OAL_EFAIL;
    }

    ret = wal_send_cfg_event(hmac_vap->pst_net_device, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH +
        sizeof(dmac_query_station_info_request_event), (uint8_t *)&write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log1(0, 0, "{wal_vendor_query_vap_info_ext::wal_send_cfg_event return err code %d!}", ret);
        return -OAL_EFAIL;
    }
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
        (hmac_vap->station_info_query_completed_flag == OAL_TRUE), QUERY_STA_INFO_TIME);
    if (leftime <= 0) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_vendor_query_vap_info_ext::query info wait for 5 s timeout!}");
        return OAL_FAIL;
    } else {
        return OAL_SUCC;
    }
}

int32_t wal_vendor_get_user_info_ext(mac_vap_stru *mac_vap, uint8_t *mac_addr)
{
    dmac_query_station_info_request_event *query_station_info = NULL;
    wal_msg_write_stru write_msg = {0};
    int32_t ret;
    int64_t leftime;
    hmac_vap_stru *hmac_vap = NULL;

    if (mac_vap == NULL || mac_addr == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_vendor_get_user_info_ext::return null!}");
        return -OAL_EINVAL;
    }

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_ANY, "wal_vendor_get_user_info_ext: hmac vap is null. vap id:%d",
            mac_vap->uc_vap_id);
        return -OAL_EINVAL;
    }

    query_station_info = (dmac_query_station_info_request_event *)write_msg.auc_value;
    query_station_info->query_event = OAL_QUERY_STATION_INFO_EVENT;
    oal_set_mac_addr(query_station_info->auc_query_sta_addr, (uint8_t *)mac_addr);
    hmac_vap->station_info_query_completed_flag = OAL_FALSE;

    wal_write_msg_hdr_init(&write_msg, WLAN_CFGID_QUERY_STATION_STATS, sizeof(dmac_query_station_info_request_event));
    if (hmac_vap->pst_net_device == NULL) {
        oam_error_log0(0, 0, "{wal_vendor_get_user_info_ext::hmac_vap->pst_net_device == NULL!}");
        return -OAL_EFAIL;
    }

    ret = wal_send_cfg_event(hmac_vap->pst_net_device, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH +
        sizeof(dmac_query_station_info_request_event), (uint8_t *)&write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log1(0, 0, "{wal_vendor_get_user_info_ext::wal_send_cfg_event return err code %d!}", ret);
        return -OAL_EFAIL;
    }
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
        (hmac_vap->station_info_query_completed_flag == OAL_TRUE), QUERY_STA_INFO_TIME);
    if (leftime <= 0) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_vendor_get_user_info_ext::query info wait for 5 s timeout!}");
        return OAL_FAIL;
    } else {
        return OAL_SUCC;
    }
}

#endif
