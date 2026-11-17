
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/netdevice.h>
#include <linux/netfilter_ipv4.h>
#include <linux/time.h>
#include <linux/kernel.h>
#include <linux/ctype.h>
#include <linux/spinlock.h>
#include <linux/netlink.h>
#include <linux/kthread.h>
#include <linux/jiffies.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/semaphore.h>
#include <linux/version.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/ipv6.h>
#include <uapi/linux/netlink.h>
#include <securec.h>
#include <net/sock.h>
#include <net/inet_sock.h>
#include <net/ipv6.h>
#ifdef CONFIG_HW_BOOSTER
#include <hwnet/booster/hw_booster_common.h>
#endif
#ifdef CONFIG_CHR_NETLINK_MODULE
#include <hwnet/chr/wbc_hw_hook.h>
#include <hwnet/chr/chr_netlink.h>
#endif
#include <huawei_platform/log/hw_log.h>
#include "dpa_chr_web_stat.h"
#include "dpa_chr_netlink.h"
#include "booster_features.h"
#include "booster_dmi_client.h"

#ifdef CONFIG_CHR_NETLINK_MODULE
static bool g_dpa_web_deley_flag[IF_MAX_NUM];
static struct http_return g_dpa_rtn_stat[IF_MAX_NUM];
static struct http_return g_dpa_rtn_abn[IF_MAX_NUM];
static struct http_stream g_dpa_http_para_in;
static struct http_stream g_dpa_http_para_out;
static struct semaphore g_dpa_web_stat_sync_sema;
static spinlock_t g_dpa_web_stat_lock;
static spinlock_t g_dpa_web_para_in_lock;
static spinlock_t g_dpa_web_para_out_lock;
static unsigned long g_dpa_abn_stamp_web_fail;
static unsigned long g_dpa_abn_stamp_web_delay;
static unsigned long g_dpa_abn_stamp_web_no_ack;
static unsigned long g_dpa_abn_stamp_list_web_fail[WEB_FAIL_MAX];
static unsigned long g_dpa_abn_stamp_list_web_delay[WEB_DELAY_MAX];
static unsigned long g_dpa_abn_stamp_list_web_no_ack[WEB_NO_ACK_MAX];
static int g_dpa_abn_stamp_web_delay_num;
static int g_dpa_abn_stamp_web_fail_num;
static int g_dpa_abn_stamp_web_no_ack_num;
static int g_dpa_abn_stamp_list_web_fail_idx;
static int g_dpa_abn_stamp_list_web_delay_idx;
static int g_dpa_abn_stamp_list_web_no_ack_idx;
static struct timer_list g_dpa_web_stat_timer;
static char g_get_str[] = { 'G', 'E', 'T', 0, 0 };
static char g_http_str[] = { 'H', 'T', 'T', 'P', 0 };
static char g_post_str[] = { 'P', 'O', 'S', 'T', 0 };
static struct task_struct *g_dpa_web_stat_task;
static struct statics_by_rat g_statics_byrat[RAT_TYPE];
static int g_dpa_rat;

#define HTTP_ACK_FROM_START 9
#define HTTP_RESPONSE_NORMAL '2'
#define HTTP_RESPONSE_REDIRECT '3'
#define HTTP_RESPONSE_CLIENT_ERROR '4'
#define HTTP_RESPONSE_SERVER_ERROR '5'
#define RIL_RADIO_TECHNOLOGY_LTE 13
#define RIL_RADIO_TECHNOLOGY_LTE_CA 19
#define RIL_RADIO_TECHNOLOGY_NR 20
#define RADIO_TECHNOLOGY_LTE_EN_DC 25
#define CHR_DATA_REG_TYPE_LTE 0
#define CHR_DATA_REG_TYPE_ENDC 1
#define CHR_DATA_REG_TYPE_NR 2
#define HASH_MAX 256
#define HASH_MAX_16_BIT 65535
#define HASH_MAX_24_BIT 16777216
#define IPV6_ADD_P1 0
#define IPV6_ADD_P2 1
#define IPV6_ADD_P3 2
#define IPV6_ADD_P4 3

uid_t dpa_get_uid_from_sock(struct sock *sk)
{
 	if (sk == NULL)
 		return 0;
 	return sk->sk_uid.val;
}

u8 dpa_http_response_type(const char *pstr)
{
 	u8 type;
 	type = UN_KNOW;
 	if (pstr[HTTP_ACK_FROM_START] == HTTP_RESPONSE_NORMAL ||
 		pstr[HTTP_ACK_FROM_START] == HTTP_RESPONSE_REDIRECT)
 		type = WEB_SUCC;
 
 	if (pstr[HTTP_ACK_FROM_START] == HTTP_RESPONSE_CLIENT_ERROR ||
 		pstr[HTTP_ACK_FROM_START] == HTTP_RESPONSE_SERVER_ERROR)
 		type = WEB_FAIL;
 	return type;
}
 
bool dpa_is_valid_data_reg_tech(void)
{
    int reg = get_data_reg_tech();
 	switch (reg) {
    case 0:
 	case RIL_RADIO_TECHNOLOGY_LTE:
 	case RIL_RADIO_TECHNOLOGY_LTE_CA:
 	case RADIO_TECHNOLOGY_LTE_EN_DC:
 	case RIL_RADIO_TECHNOLOGY_NR:
 		return true;
 	default:
 	    return false;
 	}
}

u32 dpa_get_data_reg_type_chr_enum(int reg_type)
{
 	switch (reg_type) {
 	case RIL_RADIO_TECHNOLOGY_LTE:
 	case RIL_RADIO_TECHNOLOGY_LTE_CA:
 		return CHR_DATA_REG_TYPE_LTE;
 	case RADIO_TECHNOLOGY_LTE_EN_DC:
 		return CHR_DATA_REG_TYPE_ENDC;
 	case RIL_RADIO_TECHNOLOGY_NR:
 		return CHR_DATA_REG_TYPE_NR;
 	default:
 		break;
 	}
 	return CHR_DATA_REG_TYPE_LTE;
}

u8 hash3(u32 dst, u32 src, u32 port)
{
 	u32 hash;
 	hash = dst + src + port;
 	hash = hash + hash / HASH_MAX + hash / HASH_MAX_16_BIT +
 		hash / HASH_MAX_24_BIT;
 	hash = hash % HASH_MAX;
 	return (u8) hash;
}

u8 hash3_v6(struct in6_addr dst, struct in6_addr src, u32 port)
{
 	u32 hash;
 	hash = dst.s6_addr32[IPV6_ADD_P1] + dst.s6_addr32[IPV6_ADD_P2] +
 		dst.s6_addr32[IPV6_ADD_P3] + dst.s6_addr32[IPV6_ADD_P4] +
 		src.s6_addr32[IPV6_ADD_P1] + src.s6_addr32[IPV6_ADD_P2] +
 		src.s6_addr32[IPV6_ADD_P3] + src.s6_addr32[IPV6_ADD_P4] + port;
 	hash = hash + hash / HASH_MAX + hash / HASH_MAX_16_BIT +
 		hash / HASH_MAX_24_BIT;
 	hash = hash % HASH_MAX;
 	return (u8) hash;
}

u8 dpa_get_hash_cnt(struct http_stream http_para)
{
 	u8 hash_cnt;
 	if (http_para.proto == IPV6_NETWORK)
 		hash_cnt = hash3_v6(http_para.dst_v6_addr,
 			http_para.src_v6_addr, http_para.tcp_port);
 	else
 		hash_cnt = hash3(http_para.dst_addr,
 			http_para.src_addr, http_para.tcp_port);
 	return hash_cnt;
}

bool dpa_ipv6_address_equal(struct in6_addr src, struct in6_addr dst)
{
 	if (src.s6_addr32[IPV6_ADD_P1] == dst.s6_addr32[IPV6_ADD_P1] &&
 		src.s6_addr32[IPV6_ADD_P2] == dst.s6_addr32[IPV6_ADD_P2] &&
 		src.s6_addr32[IPV6_ADD_P3] == dst.s6_addr32[IPV6_ADD_P3] &&
 		src.s6_addr32[IPV6_ADD_P4] == dst.s6_addr32[IPV6_ADD_P4])
 		return true;
 	else
 		return false;
}

bool dpa_stream_list_http_para_equal(struct http_stream http_para,
 	struct http_stream stream_list, bool is_http_para_in)
{
 	u8 proto;
 	if (is_http_para_in)
 		proto = stream_list.proto;
 	else
 		proto = http_para.proto;
 	if (((proto != IPV6_NETWORK &&
 		stream_list.src_addr == http_para.src_addr &&
 		stream_list.dst_addr == http_para.dst_addr) ||
 		(proto == IPV6_NETWORK &&
 		dpa_ipv6_address_equal(stream_list.src_v6_addr,
 			http_para.src_v6_addr) &&
 		dpa_ipv6_address_equal(stream_list.dst_v6_addr,
 			http_para.dst_v6_addr))) &&
 		stream_list.tcp_port == http_para.tcp_port &&
 		stream_list.interface == http_para.interface)
 		return true;
 	else
 		return false;
}

void dpa_set_http_para_in(bool is_ipv6_pkt, struct ipv6hdr *ip6h, struct iphdr *iph, struct tcphdr *tcph)
{
    if ((is_ipv6_pkt && ip6h == NULL) || (!is_ipv6_pkt && iph == NULL) || tcph == NULL) {
        return;
    }
    g_dpa_http_para_in.tcp_port = tcph->dest;
    if (is_ipv6_pkt) {
        g_dpa_http_para_in.proto = IPV6_NETWORK;
        g_dpa_http_para_in.src_v6_addr = ip6h->daddr;
        g_dpa_http_para_in.dst_v6_addr = ip6h->saddr;
    } else {
        g_dpa_http_para_in.proto = IPV4_NETWORK;
        g_dpa_http_para_in.src_addr = iph->daddr;
        g_dpa_http_para_in.dst_addr = iph->saddr;
    }
    g_dpa_http_para_in.time_stamp = jiffies;
    g_dpa_http_para_in.is_valid = IS_USE;
}

bool dpa_is_http_para_out(u32 dlen, const char *p_http_str)
{
    if (p_http_str == NULL)
        return false;
    if (dlen > WEB_DS_NET_LEN &&
        (strncmp(p_http_str, g_get_str, GET_STR_LEN) == 0 || strncmp(p_http_str, g_post_str, POST_STR_LEN) == 0)) {
        return true;
    }
    return false;
}

bool dpa_is_ipv6_packet(struct sock *sk)
{
    return ((sk->sk_family == AF_INET6 && !((u32)ipv6_addr_type(&sk->sk_v6_rcv_saddr) & IPV6_ADDR_MAPPED)) ? true :
                                                                                                             false);
}

u8 *get_payload_addr(const struct sk_buff *skb, u32 *parse_len)
{
	u8 *payload = NULL;
	if (skb == NULL || parse_len == NULL)
		return payload;
    payload = skb->data;
    *parse_len = skb_headlen(skb);
	return payload;
}

int dpa_is_http_response(char *p_http_str, u32 dlen, struct tcphdr *tcph)
{
    if (dlen > HTTP_RSP_LEN && strncmp(p_http_str, g_http_str, HTTP_STR_LEN) == 0 &&
        dpa_http_response_type(p_http_str) != UN_KNOW && g_dpa_http_para_in.is_valid == IS_UNUSE) {
        return 1;
    }
    return 0;
}

bool dpa_is_stream_list_unuse(u8 hash_cnt)
{
    if (get_stream_list(hash_cnt)->is_valid == IS_UNUSE ||
        (get_stream_list(hash_cnt)->type != HTTP_GET && get_stream_list(hash_cnt)->type != HTTP_SYN)) {
        return true;
    } else {
        return false;
    }
}

u32 dpa_get_http_stream_iface(struct sk_buff *skb, bool is_http_para_in)
{
    if (skb->dev == NULL) {
        return -1;
    }
    if (strncmp(skb->dev->name, WEB_DS_NET, WEB_DS_NET_LEN)) {
        if (is_http_para_in) {
            g_dpa_http_para_in.interface = WLAN_INTERFACE;
        } else {
            g_dpa_http_para_out.interface = WLAN_INTERFACE;
        }
    } else {
        if (!dpa_is_valid_data_reg_tech()) {
            return -1;
        }
        if (is_http_para_in) {
            g_dpa_http_para_in.interface = RMNET_INTERFACE;
        } else {
            g_dpa_http_para_out.interface = RMNET_INTERFACE;
        }
    }
    return 0;
}

unsigned long dpa_abn_stamp_list_web_delay_update(unsigned long time_stamp)
{
    g_dpa_abn_stamp_list_web_delay[g_dpa_abn_stamp_list_web_delay_idx] = time_stamp;
    g_dpa_abn_stamp_list_web_delay_idx = (g_dpa_abn_stamp_list_web_delay_idx + 1) % WEB_DELAY_MAX;
    return g_dpa_abn_stamp_list_web_delay[g_dpa_abn_stamp_list_web_delay_idx];
}

unsigned long dpa_abn_stamp_list_web_fail_update(unsigned long time_stamp)
{
    g_dpa_abn_stamp_list_web_fail[g_dpa_abn_stamp_list_web_fail_idx] = time_stamp;
    g_dpa_abn_stamp_list_web_fail_idx = (g_dpa_abn_stamp_list_web_fail_idx + 1) % WEB_FAIL_MAX;
    return g_dpa_abn_stamp_list_web_fail[g_dpa_abn_stamp_list_web_fail_idx];
}

unsigned long dpa_abn_stamp_list_web_no_ack_update(unsigned long time_stamp)
{
    g_dpa_abn_stamp_list_web_no_ack[g_dpa_abn_stamp_list_web_no_ack_idx] = time_stamp;
    g_dpa_abn_stamp_list_web_no_ack_idx = (g_dpa_abn_stamp_list_web_no_ack_idx + 1) % WEB_NO_ACK_MAX;
    return g_dpa_abn_stamp_list_web_no_ack[g_dpa_abn_stamp_list_web_no_ack_idx];
}

bool dpa_is_port_need(struct tcphdr *tcph, bool flag)
{
    int port = 0;
    if (flag) {
        port = htons(tcph->source);
    } else {
        port = htons(tcph->dest);
    }
    switch (port) {
        case HTTP_PORT:
        case HTTPS_PORT:
        case SQUIDHTTP_PORT:
        case HTTP2_PORT:
        case ICECAP_PORT:
        case TOMCAT_PORT:
        case HTTP3_PORT:
            return true;
        default:
            return false;
    }
}

u32 http_response_code(const char *pstr)
{
    u32 code = 0;
    int idx;
    char ch;
    if (pstr == NULL) {
        return 0;
    }
    for (idx = 0; idx < CODE_LEN; idx++) {
        ch = pstr[(int)(HTTP_ACK_FROM_START + idx)];
        if (ch >= '0' && ch <= '9')
            /* multiply 10 to add ch */
            code = code * 10 + (ch - '0');
        else
            return 0;
    }
    return code;
}

u32 dpa_get_web_delay(u8 hash_cnt)
{
    u32 web_delay;
    if (g_dpa_http_para_in.time_stamp >= get_stream_list(hash_cnt)->time_stamp)
        web_delay = (g_dpa_http_para_in.time_stamp - get_stream_list(hash_cnt)->time_stamp) * MULTIPLE;
    else
        web_delay = (MAX_JIFFIES - get_stream_list(hash_cnt)->time_stamp + g_dpa_http_para_in.time_stamp) * MULTIPLE;
    return web_delay;
}

void dpa_save_rtn_web_delay(u32 web_delay, u8 interface_type)
{
    if (g_dpa_web_deley_flag[interface_type]) {
        g_dpa_rtn_stat[interface_type].highest_web_delay = web_delay;
        g_dpa_rtn_stat[interface_type].lowest_web_delay = web_delay;
        g_dpa_rtn_stat[interface_type].last_web_delay = web_delay;
        g_dpa_web_deley_flag[interface_type] = false;
    }
    if (web_delay > g_dpa_rtn_stat[interface_type].highest_web_delay)
        g_dpa_rtn_stat[interface_type].highest_web_delay = web_delay;
    if (web_delay < g_dpa_rtn_stat[interface_type].lowest_web_delay)
        g_dpa_rtn_stat[interface_type].lowest_web_delay = web_delay;
    g_dpa_rtn_stat[interface_type].last_web_delay = web_delay;
    if (web_delay > DELAY_THRESHOLD_L1 && web_delay <= DELAY_THRESHOLD_L2)
        g_dpa_rtn_stat[interface_type].delay_num_l1++;
    else if (web_delay > DELAY_THRESHOLD_L2 && web_delay <= DELAY_THRESHOLD_L3)
        g_dpa_rtn_stat[interface_type].delay_num_l2++;
    else if (web_delay > DELAY_THRESHOLD_L3 && web_delay <= DELAY_THRESHOLD_L4)
        g_dpa_rtn_stat[interface_type].delay_num_l3++;
    else if (web_delay > DELAY_THRESHOLD_L4 && web_delay <= DELAY_THRESHOLD_L5)
        g_dpa_rtn_stat[interface_type].delay_num_l4++;
    else if (web_delay > DELAY_THRESHOLD_L5 && web_delay <= DELAY_THRESHOLD_L6)
        g_dpa_rtn_stat[interface_type].delay_num_l5++;
    else if (web_delay > DELAY_THRESHOLD_L6)
        g_dpa_rtn_stat[interface_type].delay_num_l6++;
}

void dpa_save_app_web_delay(u32 uid, int web_delay, u8 if_type)
{
    struct report_app_stat *app_stat = NULL;
    int index = find_uid(uid, get_report_app_uid(), CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        return;
    } else {
        app_stat = &g_dpa_rtn_stat[if_type].report_app_stat_list[index];
        app_stat->total_num++;
        app_stat->succ_num++;
        app_stat->web_delay += web_delay;
        if (web_delay > DELAY_THRESHOLD_L1 && web_delay <= DELAY_THRESHOLD_L2)
            app_stat->delay_num_l1++;
        else if (web_delay > DELAY_THRESHOLD_L2 && web_delay <= DELAY_THRESHOLD_L3)
            app_stat->delay_num_l2++;
        else if (web_delay > DELAY_THRESHOLD_L3 && web_delay <= DELAY_THRESHOLD_L4)
            app_stat->delay_num_l3++;
        else if (web_delay > DELAY_THRESHOLD_L4 && web_delay <= DELAY_THRESHOLD_L5)
            app_stat->delay_num_l4++;
        else if (web_delay > DELAY_THRESHOLD_L5 && web_delay <= DELAY_THRESHOLD_L6)
            app_stat->delay_num_l5++;
        else if (web_delay > DELAY_THRESHOLD_L6)
            app_stat->delay_num_l6++;
    }
}

void dpa_web_stat_succ_report(u8 if_type, u8 hash_cnt, u32 web_delay)
{
    int net_type;
    unsigned long abn_stamp;
    if (web_delay < WEB_DELAY_THRESHOLD) {
        return;
    }
    g_dpa_abn_stamp_web_delay_num++;
    abn_stamp = dpa_abn_stamp_list_web_delay_update(jiffies);
    if (time_after(jiffies, g_dpa_abn_stamp_web_delay) && time_before(jiffies, abn_stamp + WEB_DELAY_REPORT_TIME)) {
        net_type = if_type % IPV6_INTERFACE;
        if (if_type < IPV6_INTERFACE) {
            g_dpa_rtn_abn[net_type].report_type = WEB_DELAY;
            g_dpa_rtn_abn[net_type].server_addr = get_stream_list(hash_cnt)->dst_addr;
        } else {
            g_dpa_rtn_abn[net_type].report_type = WEB_DELAY_V6;
            g_dpa_rtn_abn[net_type].server_v6_addr = get_stream_list(hash_cnt)->dst_v6_addr;
        }
        g_dpa_rtn_abn[net_type].data_reg_tech = dpa_get_data_reg_type_chr_enum(get_data_reg_tech());
        g_dpa_rtn_abn[net_type].web_delay = web_delay;
        g_dpa_rtn_abn[net_type].uid = get_stream_list(hash_cnt)->uid;
        g_dpa_rtn_abn[net_type].total_num = g_dpa_abn_stamp_web_delay_num;
        g_dpa_rtn_abn[net_type].dpa_flag = true;
        g_dpa_abn_stamp_web_delay_num = 0;
        spin_unlock_bh(&g_dpa_web_para_in_lock);
        spin_unlock_bh(&g_dpa_web_stat_lock);
        chr_notify_event(CHR_WEB_STAT_EVENT, get_user_space_pid(), 0, g_dpa_rtn_abn);
        pr_info("dpa chr: web delay report s:%x-d:%x>:%d\n", get_stream_list(hash_cnt)->src_addr & IPV4ADDR_MASK,
                get_stream_list(hash_cnt)->dst_addr & IPV4ADDR_MASK, get_stream_list(hash_cnt)->tcp_port);
        spin_lock_bh(&g_dpa_web_stat_lock);
        memset_s(&g_dpa_rtn_abn, sizeof(g_dpa_rtn_abn), 0, sizeof(g_dpa_rtn_abn));
        spin_lock_bh(&g_dpa_web_para_in_lock);
        g_dpa_abn_stamp_web_delay = jiffies + FORBID_TIME;
    }
}

void save_dpa_app_web_fail(u32 uid, u8 if_type)
{
    int index = find_uid(uid, get_report_app_uid(), CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        return;
    } else {
        g_dpa_rtn_stat[if_type].report_app_stat_list[index].total_num++;
        g_dpa_rtn_stat[if_type].report_app_stat_list[index].fail_num++;
    }
}

void dpa_web_stat_fail_report(u8 if_type, u8 hash_cnt)
{
    int net_type;
    unsigned long abn_stamp;
    g_dpa_abn_stamp_web_fail_num++;
    abn_stamp = dpa_abn_stamp_list_web_fail_update(jiffies);
    if (time_after(jiffies, g_dpa_abn_stamp_web_fail) && time_before(jiffies, abn_stamp + WEB_FAIL_REPORT_TIME)) {
        net_type = if_type % IPV6_INTERFACE;
        if (if_type < IPV6_INTERFACE) {
            g_dpa_rtn_abn[net_type].report_type = WEB_FAIL;
            g_dpa_rtn_abn[net_type].server_addr = get_stream_list(hash_cnt)->dst_addr;
        } else {
            g_dpa_rtn_abn[net_type].report_type = WEB_FAIL_V6;
            g_dpa_rtn_abn[net_type].server_v6_addr = get_stream_list(hash_cnt)->dst_v6_addr;
        }
        g_dpa_rtn_abn[net_type].data_reg_tech = dpa_get_data_reg_type_chr_enum(get_data_reg_tech());
        g_dpa_rtn_abn[net_type].uid = get_stream_list(hash_cnt)->uid;
        g_dpa_rtn_abn[net_type].http_resp = g_dpa_http_para_in.resp_code;
        g_dpa_rtn_abn[net_type].total_num = g_dpa_abn_stamp_web_fail_num;
        g_dpa_rtn_abn[net_type].dpa_flag = true;
        g_dpa_abn_stamp_web_fail_num = 0;
        spin_unlock_bh(&g_dpa_web_para_in_lock);
        spin_unlock_bh(&g_dpa_web_stat_lock);
        chr_notify_event(CHR_WEB_STAT_EVENT, get_user_space_pid(), 0, g_dpa_rtn_abn);
        pr_info("dpa chr: web fail report s:%x-d:%x>:%d\n", get_stream_list(hash_cnt)->src_addr & IPV4ADDR_MASK,
                get_stream_list(hash_cnt)->dst_addr & IPV4ADDR_MASK, get_stream_list(hash_cnt)->tcp_port);
        spin_lock_bh(&g_dpa_web_stat_lock);
        memset_s(&g_dpa_rtn_abn, sizeof(g_dpa_rtn_abn), 0, sizeof(g_dpa_rtn_abn));
        spin_lock_bh(&g_dpa_web_para_in_lock);
        g_dpa_abn_stamp_web_fail = jiffies + FORBID_TIME;
    }
}

void dpa_web_stat_report(u8 interface_type, u8 hash_cnt)
{
    u32 web_delay;
    switch (g_dpa_http_para_in.type) {
        case WEB_SUCC:
            g_dpa_rtn_stat[interface_type].total_num++;
            g_dpa_rtn_stat[interface_type].succ_num++;
            web_delay = dpa_get_web_delay(hash_cnt);
            g_dpa_rtn_stat[interface_type].web_delay += web_delay;
            if (interface_type % IPV6_INTERFACE == 0) {
                g_dpa_rat = dpa_get_data_reg_type_chr_enum(get_data_reg_tech());
                g_statics_byrat[g_dpa_rat].total_num++;
                g_statics_byrat[g_dpa_rat].succ_num++;
                g_statics_byrat[g_dpa_rat].web_delay += web_delay;
            }
            dpa_save_rtn_web_delay(web_delay, interface_type);
            dpa_save_app_web_delay(get_stream_list(hash_cnt)->uid, web_delay, interface_type);
            dpa_web_stat_succ_report(interface_type, hash_cnt, web_delay);
            set_stream_list(hash_cnt);
            break;
        case WEB_FAIL:
            g_dpa_rtn_stat[interface_type].total_num++;
            g_dpa_rtn_stat[interface_type].fail_num++;
            g_dpa_rat = dpa_get_data_reg_type_chr_enum(get_data_reg_tech());
            if (interface_type % IPV6_INTERFACE == 0) {
                g_statics_byrat[g_dpa_rat].total_num++;
                g_statics_byrat[g_dpa_rat].fail_num++;
            }
            save_dpa_app_web_fail(get_stream_list(hash_cnt)->uid, interface_type);
            pr_info("dpa chr: web fail report uid:%d-port:%u\n", get_stream_list(hash_cnt)->uid,
                    htons(get_stream_list(hash_cnt)->tcp_port));
            dpa_web_stat_fail_report(interface_type, hash_cnt);
            set_stream_list(hash_cnt);
            break;
        default:
            set_stream_list(hash_cnt);
            break;
    }
}

void dpa_in_proc(void)
{
    u8 hash_cnt;
    u8 nwk_type;
    u8 if_type;
    spin_lock_bh(&g_dpa_web_para_in_lock);
    if (g_dpa_http_para_in.is_valid == IS_UNUSE) {
        spin_unlock_bh(&g_dpa_web_para_in_lock);
        return;
    }
    hash_cnt = dpa_get_hash_cnt(g_dpa_http_para_in);
    if (dpa_is_stream_list_unuse(hash_cnt)) {
        g_dpa_http_para_in.is_valid = IS_UNUSE;
        spin_unlock_bh(&g_dpa_web_para_in_lock);
        return;
    }
    nwk_type = g_dpa_http_para_in.proto;
    if_type = g_dpa_http_para_in.interface + nwk_type * IPV6_INTERFACE;
    if (dpa_stream_list_http_para_equal(g_dpa_http_para_in, *get_stream_list(hash_cnt), true))
        dpa_web_stat_report(if_type, hash_cnt);
    g_dpa_http_para_in.is_valid = IS_UNUSE;
    spin_unlock_bh(&g_dpa_web_para_in_lock);
}

u32 is_tcp_protocol(struct sk_buff *skb, struct ipv6hdr **ip6h, struct iphdr **iph, struct tcphdr **tcph)
{
    if (dpa_is_ipv6_packet(skb->sk)) {
        *ip6h = ipv6_hdr(skb);
        if (*ip6h == NULL || (*ip6h)->nexthdr != IPPROTO_TCP)
            return -1;
    } else {
        *iph = ip_hdr(skb);
        if (*iph == NULL || (*iph)->protocol != IPPROTO_TCP)
            return -1;
    }
    *tcph = tcp_hdr(skb);
    if (*tcph == NULL || skb->data == NULL || (*tcph)->doff == 0)
        return -1;
    return 0;
}

void dpa_hook_local_in(struct sk_buff *skb)
{
    u32 dlen;
    bool up_req = false;
    struct iphdr *iph = NULL;
    struct tcphdr *tcph = NULL;
    struct ipv6hdr *ip6h = NULL;
    if (skb == NULL || skb->sk == NULL) {
        return;
    }
    if  (is_tcp_protocol(skb, &ip6h, &iph, &tcph) == -1) {
        return;
    }
    if (dpa_get_http_stream_iface(skb, true) == -1 || !dpa_is_port_need(tcph, true) ||
        !spin_trylock_bh(&g_dpa_web_para_in_lock)) {
        return;
    }
    bool is_ipv6_pkt = dpa_is_ipv6_packet(skb->sk);
    /* Determine whether the received packet is an HTTP response */
	char *p_http_str = (char *)get_payload_addr(skb, &dlen);
    if (p_http_str == NULL) {
        spin_unlock_bh(&g_dpa_web_para_in_lock);
        return;
    }
    int is_response = dpa_is_http_response(p_http_str, dlen, tcph);
    if (is_response == 1) {
        dpa_set_http_para_in(is_ipv6_pkt, ip6h, iph, tcph);
        g_dpa_http_para_in.type = dpa_http_response_type(p_http_str);
        g_dpa_http_para_in.resp_code = http_response_code(p_http_str);
        up_req = true;
    }
    spin_unlock_bh(&g_dpa_web_para_in_lock);
    if (up_req) {
        up(&g_dpa_web_stat_sync_sema);
    }
}

bool dpa_out_is_port_need(struct sk_buff *skb)
{
    int port = htons(skb->sk->sk_dport);
    switch (port) {
        case HTTP_PORT:
        case HTTPS_PORT:
        case SQUIDHTTP_PORT:
        case HTTP2_PORT:
        case ICECAP_PORT:
        case TOMCAT_PORT:
        case HTTP3_PORT:
            return true;
        default:
            return false;
    }
}

void dpa_hook_local_out(struct sk_buff *skb)
{
    bool up_req = false;
    if (skb == NULL || skb->sk == NULL || skb->sk->sk_protocol != IPPROTO_TCP) {
        return;
    }
    if (dpa_get_http_stream_iface(skb, false) == -1 || !dpa_out_is_port_need(skb) ||
        !spin_trylock_bh(&g_dpa_web_para_out_lock)) {
        return;
    }
    bool is_ipv6_pkt = dpa_is_ipv6_packet(skb->sk);
    if (g_dpa_http_para_out.is_valid == IS_UNUSE) {
        bool is_http_out = false;
        u32 dlen;
        char *p_http_str = (char *)get_payload_addr(skb, &dlen);
        if (dlen == 0 || p_http_str == NULL) {
            spin_unlock_bh(&g_dpa_web_para_out_lock);
            return;
        }
        is_http_out = dpa_is_http_para_out(dlen, p_http_str);
        if (is_http_out) {
            g_dpa_http_para_out.tcp_port = inet_sk(skb->sk)->inet_sport;
            if (is_ipv6_pkt) {
                g_dpa_http_para_out.proto = IPV6_NETWORK;
                g_dpa_http_para_out.src_v6_addr = skb->sk->sk_v6_rcv_saddr;
                g_dpa_http_para_out.dst_v6_addr = skb->sk->sk_v6_daddr;
            } else {
                g_dpa_http_para_out.proto = IPV4_NETWORK;
                g_dpa_http_para_out.src_addr = skb->sk->sk_rcv_saddr;
                g_dpa_http_para_out.dst_addr = skb->sk->sk_daddr;
            }
            g_dpa_http_para_out.time_stamp = jiffies;
            g_dpa_http_para_out.is_valid = IS_USE;
            g_dpa_http_para_out.type = HTTP_GET;
            up_req = true;
        }
    }
    spin_unlock_bh(&g_dpa_web_para_out_lock);
    if (up_req) {
        up(&g_dpa_web_stat_sync_sema);
    }
}

void dpa_get_http_get_delay(u8 hash_cnt, u8 if_type)
{
    u32 http_get_delay = 0;
    if (get_stream_list(hash_cnt)->ack_time_stamp != 0) {
        if (g_dpa_http_para_out.time_stamp >= get_stream_list(hash_cnt)->ack_time_stamp)
            http_get_delay = (g_dpa_http_para_out.time_stamp - get_stream_list(hash_cnt)->ack_time_stamp) * MULTIPLE;
        else
            http_get_delay =
                (MAX_JIFFIES - get_stream_list(hash_cnt)->ack_time_stamp + g_dpa_http_para_out.time_stamp) * MULTIPLE;
    }
    g_dpa_rtn_stat[if_type].http_get_delay += http_get_delay;
    g_dpa_rtn_stat[if_type].http_send_get_num++;
    g_dpa_rat = dpa_get_data_reg_type_chr_enum(get_data_reg_tech());
    if (if_type % IPV6_INTERFACE == 0) {
        g_statics_byrat[g_dpa_rat].http_get_delay += http_get_delay;
        g_statics_byrat[g_dpa_rat].http_get_num++;
    }
}

void dpa_http_para_out_http_get(u8 cnt)
{
    u8 nwk_type;
    u8 if_type;
    nwk_type = g_dpa_http_para_out.proto;
    if_type = g_dpa_http_para_out.interface + nwk_type * IPV6_INTERFACE;
    if (dpa_stream_list_http_para_equal(g_dpa_http_para_out, *get_stream_list(cnt), false)) {
        get_stream_list(cnt)->get_time_stamp = g_dpa_http_para_out.time_stamp;
        if (get_stream_list(cnt)->interface == g_dpa_http_para_out.interface)
            dpa_get_http_get_delay(cnt, if_type);
        get_stream_list(cnt)->type = HTTP_GET;
    }
}

void dpa_out_proc(void)
{
    u8 hash_cnt;
    spin_lock_bh(&g_dpa_web_para_out_lock);
    if (g_dpa_http_para_out.is_valid != IS_USE) {
        spin_unlock_bh(&g_dpa_web_para_out_lock);
        return;
    }
    hash_cnt = dpa_get_hash_cnt(g_dpa_http_para_out);
    if (get_stream_list(hash_cnt)->is_valid == IS_UNUSE) {
		if (get_stream_list(hash_cnt)->type == HTTP_GET && g_dpa_http_para_out.type == HTTP_GET) {
			get_stream_list(hash_cnt)->time_stamp = g_dpa_http_para_out.time_stamp;
		}
		if (g_dpa_http_para_out.type == HTTP_SYN)
			memcpy_s(get_stream_list(hash_cnt), sizeof(g_dpa_http_para_out), &g_dpa_http_para_out,
				sizeof(g_dpa_http_para_out));
	} else if (get_stream_list(hash_cnt)->type == HTTP_SYN &&
		g_dpa_http_para_out.type == HTTP_GET) {
		dpa_http_para_out_http_get(hash_cnt);
	} else if (get_stream_list(hash_cnt)->type == HTTP_GET && 
		g_dpa_http_para_out.type == HTTP_GET && g_dpa_http_para_out.is_valid == IS_USE) {
		get_stream_list(hash_cnt)->time_stamp = g_dpa_http_para_out.time_stamp;
	}
    g_dpa_http_para_out.is_valid = IS_UNUSE;
    spin_unlock_bh(&g_dpa_web_para_out_lock);
}

static int dpa_chr_web_thread(void *data)
{
    while (1) {
        if (kthread_should_stop()) {
            break;
        }
        down(&g_dpa_web_stat_sync_sema);
        spin_lock_bh(&g_dpa_web_stat_lock);
        dpa_in_proc();
        dpa_out_proc();
        spin_unlock_bh(&g_dpa_web_stat_lock);
    }
    return 0;
}

void dpa_variable_initialization(void)
{
    memset_s(&g_dpa_rtn_stat, sizeof(g_dpa_rtn_stat), 0, sizeof(g_dpa_rtn_stat));
    memset_s(&g_dpa_rtn_abn, sizeof(g_dpa_rtn_abn), 0, sizeof(g_dpa_rtn_abn));
    memset_s(&g_dpa_http_para_in, sizeof(g_dpa_http_para_in), 0, sizeof(g_dpa_http_para_in));
    memset_s(&g_dpa_http_para_out, sizeof(g_dpa_http_para_out), 0, sizeof(g_dpa_http_para_out));
    memset_s(&g_statics_byrat, sizeof(g_statics_byrat), 0, sizeof(g_statics_byrat));
}

void dpa_spin_lock_initialization(void)
{
    spin_lock_init(&g_dpa_web_stat_lock);
    spin_lock_init(&g_dpa_web_para_in_lock);
    spin_lock_init(&g_dpa_web_para_out_lock);
    sema_init(&g_dpa_web_stat_sync_sema, 0);
}

static void dpa_web_delay_flag_reset(void)
{
    int flag_index;
    for (flag_index = 0; flag_index < IF_MAX_NUM; flag_index++) {
        g_dpa_web_deley_flag[flag_index] = true;
    }
}

void dpa_timestamp_initialization(void)
{
    g_dpa_abn_stamp_web_fail = jiffies;
    g_dpa_abn_stamp_web_delay = jiffies;
    g_dpa_abn_stamp_web_no_ack = jiffies;
}

int dpa_kmalloc_abn_stamp_list(void)
{
    g_dpa_abn_stamp_list_web_fail_idx = 0;
    g_dpa_abn_stamp_list_web_delay_idx = 0;
    g_dpa_abn_stamp_list_web_no_ack_idx = 0;
    g_dpa_abn_stamp_web_delay_num = 0;
    g_dpa_abn_stamp_web_fail_num = 0;
    g_dpa_abn_stamp_web_no_ack_num = 0;
    return 0;
}

void dpa_web_stat_no_ack_report(u8 interface_type, u8 hash_cnt)
{
 	int net_type;
 	unsigned long abn_stamp;
 
 	g_dpa_abn_stamp_web_no_ack_num++;
 	abn_stamp = dpa_abn_stamp_list_web_no_ack_update(jiffies);
 	if (time_after(jiffies, g_dpa_abn_stamp_web_no_ack) &&
 		time_before(jiffies, abn_stamp + WEB_NO_ACK_REPORT_TIME)) {
 		net_type = interface_type % IPV6_INTERFACE;
 		if (interface_type < IPV6_INTERFACE) {
 			g_dpa_rtn_abn[net_type].report_type = WEB_NO_ACK;
 			g_dpa_rtn_abn[net_type].server_addr = get_stream_list(hash_cnt)->dst_addr;
 		} else {
 			g_dpa_rtn_abn[net_type].report_type = WEB_NO_ACK_V6;
 			g_dpa_rtn_abn[net_type].server_v6_addr = get_stream_list(hash_cnt)->dst_v6_addr;
 		}
 		g_dpa_rtn_abn[net_type].uid = get_stream_list(hash_cnt)->uid;
 		g_dpa_rtn_abn[net_type].data_reg_tech = dpa_get_data_reg_type_chr_enum(get_data_reg_tech());
 		g_dpa_rtn_abn[net_type].total_num = g_dpa_abn_stamp_web_no_ack_num;
 		g_dpa_abn_stamp_web_no_ack_num = 0;
 		g_dpa_rtn_abn[net_type].http_resp = 0xffffffff;
        g_dpa_rtn_abn[net_type].dpa_flag = true;
 		spin_unlock_bh(&g_dpa_web_stat_lock);
        chr_notify_event(CHR_WEB_STAT_EVENT, get_user_space_pid(), 0, g_dpa_rtn_abn);
 		pr_info("dpa chr: web no ack report s:%x-d:%x>:%x\n", get_stream_list(hash_cnt)->src_addr & IPV4ADDR_MASK,
 			get_stream_list(hash_cnt)->dst_addr & IPV4ADDR_MASK, get_stream_list(hash_cnt)->tcp_port);
 		spin_lock_bh(&g_dpa_web_stat_lock);
 		memset_s(&g_dpa_rtn_abn, sizeof(g_dpa_rtn_abn), 0, sizeof(g_dpa_rtn_abn));
 		g_dpa_abn_stamp_web_no_ack = jiffies + FORBID_TIME;
 	}
}

void save_dpa_app_web_no_ack(u32 uid, u8 if_type)
{
    int index = find_uid(uid, get_report_app_uid(), CHR_MAX_REPORT_APP_COUNT);
    if (index == -1) {
        return;
    } else {
        g_dpa_rtn_stat[if_type].report_app_stat_list[index].total_num++;
        g_dpa_rtn_stat[if_type].report_app_stat_list[index].no_ack_num++;
    }
}

static void dpa_web_stat_timer(struct timer_list *data)
{
    u32 hash_cnt;
    int hash_num = 0;
    u8 interface_type;

    spin_lock_bh(&g_dpa_web_stat_lock);
    for (hash_cnt = 0; hash_cnt < HASH_MAX; hash_cnt++) {
        if (get_stream_list(hash_cnt)->is_valid != IS_USE)
            continue;

        /* interface type 2 and 3 are reserved for ipv6 stats */
        interface_type = get_stream_list(hash_cnt)->interface +
            get_stream_list(hash_cnt)->proto * IPV6_INTERFACE;

        /* web no ack report */
        if (get_stream_list(hash_cnt)->type == HTTP_GET && get_stream_list(hash_cnt)->tcp_for_dpa &&
            time_after(jiffies, get_stream_list(hash_cnt)->get_time_stamp + EXPIRE_TIME)) {
            g_dpa_rtn_stat[interface_type].total_num++;
 		    g_dpa_rtn_stat[interface_type].no_ack_num++;
 		    save_dpa_app_web_no_ack(get_stream_list(hash_cnt)->uid, interface_type);
 		    dpa_web_stat_no_ack_report(interface_type, hash_cnt);
 		    pr_info("chr: web no ack report uid:%d-port:%u\n", get_stream_list(hash_cnt)->uid, 
                    htons(get_stream_list(hash_cnt)->tcp_port));
 		    set_stream_list(hash_cnt);
        }
        hash_num++;
    }
    spin_unlock_bh(&g_dpa_web_stat_lock);
    mod_timer(&g_dpa_web_stat_timer, jiffies + CHECK_TIME);
}

void timer_initialization(void)
{
    timer_setup(&g_dpa_web_stat_timer, dpa_web_stat_timer, 0);
    g_dpa_web_stat_timer.expires = jiffies + CHECK_TIME;
    add_timer(&g_dpa_web_stat_timer);
}

int dpa_web_chr_init(void)
{
    int ret;
    /* Variable initialization */
    dpa_variable_initialization();
    /* spin lock initialization */
    dpa_spin_lock_initialization();
    /* flag initialization */
    dpa_web_delay_flag_reset();
    /* Timestamp initialization */
    dpa_timestamp_initialization();
    /* kmalloc abn stamp list */
    ret = dpa_kmalloc_abn_stamp_list();
    if (ret == -1) {
        return -1;
    }
    /* Create a thread */
    g_dpa_web_stat_task = kthread_run(dpa_chr_web_thread, NULL, "dpa_chr_web_thread");
    /* Timer initialization */
 	timer_initialization();
    return 0;
}

struct http_return* get_dpa_chr_web_info(void)
{
    return g_dpa_rtn_stat;
}

struct statics_by_rat* get_dpa_chr_web_info_by_rat(void)
{
    return g_statics_byrat;
}

void upload_web_info(void)
{
    struct http_return* rtn_stat = get_dpa_chr_web_info();
    struct statics_by_rat* rat_stat = get_dpa_chr_web_info_by_rat();
    if (rtn_stat == NULL || rat_stat == NULL) {
        return;
    }
    struct dpa_chr_report *chr_report = NULL;
    chr_report = &g_dpa_chr_report;
    int ifnum, rat, app;

    struct dpa_web_info *web_info = NULL;
    web_info = &chr_report->web_info;
    for (ifnum = 0; ifnum < IF_MAX_NUM; ifnum++) {
        web_info->total_web_num[ifnum] += rtn_stat[ifnum].total_num;
        web_info->total_websucc_num[ifnum] += rtn_stat[ifnum].succ_num;
        web_info->total_webfail_num[ifnum] += rtn_stat[ifnum].fail_num;
        web_info->total_webnoack_num[ifnum] += rtn_stat[ifnum].no_ack_num;
        web_info->tcp_rtt[ifnum] += rtn_stat[ifnum].tcp_rtt;
        web_info->web_delay[ifnum] += rtn_stat[ifnum].web_delay;
        web_info->http_get_delay[ifnum] += rtn_stat[ifnum].http_get_delay;
        web_info->http_get_num[ifnum] += rtn_stat[ifnum].http_send_get_num;
    }

    struct statics_by_rat *rat_info = NULL;
    for (rat = 0; rat < RAT_TYPE; rat++) {
        rat_info = &chr_report->report_dpa_web_byrat[rat];
        rat_info->web_delay += rat_stat[rat].web_delay;
        rat_info->succ_num += rat_stat[rat].succ_num;
        rat_info->fail_num += rat_stat[rat].fail_num;
        rat_info->noack_num += rat_stat[rat].noack_num;
        rat_info->total_num += rat_stat[rat].total_num;
        rat_info->http_get_delay += rat_stat[rat].http_get_delay;
        rat_info->http_get_num += rat_stat[rat].http_get_num;
    }

    struct dpa_app_info *app_info = NULL;
    for (app = 0; app < DPA_CHR_MAX_REPORT_APP_COUNT; app++) {
        app_info = &chr_report->report_dpa_app_list[app];
        for (ifnum = 0; ifnum < IF_MAX_NUM; ifnum++) {
            app_info->app_web_info.total_web_num[ifnum] += rtn_stat[ifnum].report_app_stat_list[app].total_num;
            app_info->app_web_info.total_websucc_num[ifnum] += rtn_stat[ifnum].report_app_stat_list[app].succ_num;
            app_info->app_web_info.total_webfail_num[ifnum] += rtn_stat[ifnum].report_app_stat_list[app].fail_num;
            app_info->app_web_info.total_webnoack_num[ifnum] += rtn_stat[ifnum].report_app_stat_list[app].no_ack_num;
            app_info->app_web_info.tcp_rtt[ifnum] += rtn_stat[ifnum].report_app_stat_list[app].tcp_rtt;
            app_info->app_web_info.web_delay[ifnum] += rtn_stat[ifnum].report_app_stat_list[app].web_delay;
        }
    }
    memset_s(rtn_stat, sizeof(struct http_return) * IF_MAX_NUM, 0, sizeof(struct http_return) * IF_MAX_NUM);
    memset_s(rat_stat, sizeof(struct statics_by_rat) * RAT_TYPE, 0, sizeof(struct statics_by_rat) * RAT_TYPE);
}

static void chr_rtt_response_handler(unsigned short cmd, unsigned char *data, unsigned int len)
{
    struct dpa_chr_rtt *rtt_large = NULL;
    rtt_large = (struct dpa_chr_rtt *)kmalloc(IF_MAX_NUM * (sizeof(struct dpa_chr_rtt)), GFP_KERNEL);
    if (rtt_large == NULL) {
        pr_err("rtt_large malloc fail\n");
        return;
    }
    int ret = memcpy_s(rtt_large, IF_MAX_NUM * (sizeof(struct dpa_chr_rtt)), data, len);
    if (ret != EOK) {
        pr_err("chr_rtt_response_handler memcpy_s failed!");
        kfree(rtt_large);
        return;
    }
    int net_type;
    struct http_return *dpa_rtt_large = NULL;
    dpa_rtt_large = (struct http_return *)kmalloc(IF_MAX_NUM * (sizeof(struct http_return)), GFP_KERNEL);
    if (dpa_rtt_large == NULL) {
        pr_err("dpa_rtt_large malloc fail");
        kfree(rtt_large);
        return;
    }
    for (net_type = 0; net_type < RNT_SIZE; net_type++) {
        dpa_rtt_large[net_type].report_type = rtt_large[net_type].report_type;
        dpa_rtt_large[net_type].tcp_rtt = rtt_large[net_type].tcp_rtt;
        dpa_rtt_large[net_type].uid = rtt_large[net_type].uid;
        dpa_rtt_large[net_type].total_num = rtt_large[net_type].total_num;
        dpa_rtt_large[net_type].data_reg_tech = rtt_large[net_type].data_reg_tech;
        dpa_rtt_large[net_type].dpa_flag = true;
    }
    chr_notify_event(CHR_WEB_STAT_EVENT, get_user_space_pid(), 0, dpa_rtt_large);
    kfree(rtt_large);
    kfree(dpa_rtt_large);
}

void dpa_chr_rtt_dmi_client_init(void)
{
    register_handle_response_func(DPA_CHR_RTT_LARGE, chr_rtt_response_handler);
}

#else /* CONFIG_DPA_CHR_WEB */
void upload_web_info(void)
{
    return;
}

inline void dpa_hook_local_in(struct sk_buff *skb)
{
    return;
}

inline void dpa_hook_local_out(struct sk_buff *skb)
{
    return;
}
#endif /* CONFIG_DPA_CHR_WEB */
