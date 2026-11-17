/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef COMMON_MSG_H
#define COMMON_MSG_H
#include "stack_types.h"
#include "stack_mem.h"
#include "if_ether.h"
#include "dmm_spinlock.h"
#include "stack_comm_sem.h"
#include "spl_common_opt.h"
#include "ip_addr.h"
#include "sys_msg.h"
#include "proto_conn_stats.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_MSG_NETBUFF_SIZE 64
#define MAX_MSG_CMSGHDR_SIZE (((MAX_MSG_SIZE - sizeof(msg_param)) - sizeof(cmsg_param)))
#define MSG_BUF_SIZE ((MAX_MSG_SIZE - sizeof(msg_param) - DATA_MSG_PRE))
#define MSG_SIZE(m) (sizeof(msg_param) + (m))

#define MSG_ASYN_POST 0U
#define MSG_SYN_POST 1U
#define MSG_SYN_POST_DIRECT 2U
#define MSG_ASYN_POST_DIRECT 3U
#define IFNAMSIZ 16
#define MAX_FRAGS 64

#ifndef IP_ADDR_LEN
#define IP_ADDR_LEN 16
#endif

#define COST_TIME_STAT_UPLOAD 1
#define COST_TIME_STAT_DOWNLOAD 2

#define D2A_EVT_CLOSE               0
#define D2A_EVT_NOT_ACCEPT_CLOSE    1
#define D2A_EVT_SK_CLOSED           2
#define D2A_EVT_RCV_FIN             3
#define D2A_EVT_RCV_RST             4
#define D2A_EVT_FALLBACK            5
#define D2A_EVT_DIAG_ABORT          6
#define D2A_EVT_ECALL_FALLBACK      7
#define D2A_EVT_SHUTDOWN            8

#define D2A_EVT_A2D_MSG_FAIL    100
#define D2A_EVT_A2D_TIMEOUT     101
#define D2A_EVT_SK_INIT_FAIL    102
#define D2A_EVT_SK_NUM_FULL     103
#define D2A_EVT_ADD_FILTER_FAIL 104
#define D2A_EVT_PRE_OPT_UNSUPP  105
#define D2A_EVT_FAIL_MAX        199

#define D2A_EVT_DPA_RESET       200
#define D2A_EVT_TCP_FLAG_UNSUPP 201
#define D2A_EVT_OPT_UNSUPP      202
#define D2A_EVT_PMTU_REDUCED    203
#define D2A_EVT_REQ_RTO         204
#define D2A_EVT_TCP_TX_TC_FAIL  205
#define D2A_EVT_TCP_RX_TC_FAIL  206
#define D2A_EVT_API_UNSUPP      207
#define D2A_EVT_TX_DRA_LIMIT    208
#define D2A_EVT_CPU_OVERLOAD    209
#define D2A_EVT_HEAD_OVERLONG   210
#define D2A_EVT_NOROUTE         211
/* d2a due to external error below */
#define D2A_EVT_NIF_NO_DL_PKT   300
#define D2A_EVT_CONN_NO_DL_PKT  301
#define D2A_EVT_REVERT_MAX      399

enum api_msg_type {
    SBR_SPL_CREATE = 0,
    SBR_SPL_CLOSE,
    SBR_SPL_RECVED,
    SBR_SPL_BIND,
    SBR_SPL_CONNECT,
    SBR_SPL_LISTEN,
    SBR_SPL_SHUTDOWN,
    SBR_SPL_SETSOCKOPT,
    SBR_SPL_GETSOCKOPT,
    SBR_SPL_SEND,
    NETIF_PACKET_INPUT,
    NETIF_SYNC_FLAGS,
    NETIF_SYNC_ADDR,
    NETIF_SYNC_IP6ADDR,
    DPA_SYNC_ARP,
    MIGRATE_A2D,
    MIGRATE_A2D_BACKLOG,
    SBR_SYNC_ACCEPT_INFO,
    MIGRATE_D2A,
    ROUTE_TICK_UPDATE,
    SBR_ROUTE_TICK_RSP,
    SBR_SPL_GETADDRINFO,
};

enum acpu_msg_type {
    DPA_COMMON_RESP = 0,
    DPA_PKT_ARRIVED,
    DPA_TX_ENQ,
    DPA_GLOBAL_TX_ENQ,
    STACK_ERR_REPORT,
    STACK_TCP_STATE_CHANGE,
    STACK_ARP_QUERY,
    MIGRATE_A2D_RESP,
    STACK_ND_QUERY,
    MIGRATE_D2A_RESP,
    MIGRATE_D2A_IOV_SND,
    MIGRATE_D2A_IOV_RCV,
    DPA_PKT_REDIRECT,
    CONN_STATS_REPORT,
    STACK_ROUTE_QUERY,
    MIGRATE_D2A_REQ,
};

#pragma pack (4)
typedef struct {
    u16 type;
    u16 op_type; /* MSG_SYN_POST or MSG_ASYN_POST */
    s32 fd;
    s32 err;
    u32 euid;        /* use it in reuseport */
    u64 op_completed;
    u64 msg_from; /* use it to free msg */
    u64 msg_self;
    u32 buffer_len;
    u32 msg_post_ts;
    u8  is_dmi_msg;
    u64 mhandle;
} msg_param;

typedef struct msg_t {
    char msg_pre[DATA_MSG_PRE];
    msg_param param;
    u64 buffer[MSG_BUF_SIZE / sizeof(u64)];
} data_com_msg;

typedef struct {
    /* for UDP recvfrom */
    s8 connect_buff[MAX_MSG_NETBUFF_SIZE];

    /* for msghdr->msgcontrol */
    s32 msg_flag;
    u32 msg_controllen; /* ancillary data buffer len */
    s8 msg_control[0];        /* ancillary data */
} cmsg_param;

typedef struct msg_send_iov_t {
    u64 base_addr;
    u16 data_len;
    u16 data_off : 15,
        head_frag : 1;
} msg_iov;

/* API_DO_SEND */
typedef struct msg_send_buf_t {
    union {
        msg_iov iov[MAX_FRAGS];
        struct sbuf *sbuff;
    };
    // Do not move the position of remote_ip, local_ip and nexthop, because they memset together
    ip_addr_t remote_ip;
    ip_addr_t local_ip;
    ip_addr_t nexthop;
    u16 len;
    u16 remote_port;
    u8 iov_segs;
    u8 tcp_push : 1, is_sbuf : 1;
    u16 inet_id;    /* udp use only */
    s32 ifidx;
    u16 conn_tx_cost;
    u16 global_tx_cost;
    u32 post_msg_timestamp;
    u32 socket_timestamp;
} msg_send_buf;

#define TCP_MAX_HDR_LEN 60
typedef struct msg_backlog_buf_t {
    msg_iov iov[MAX_FRAGS];
    u8 tcp_head[TCP_MAX_HDR_LEN];
    u16 tcp_head_len;
    u8 iov_segs;
    u8 ipv6 : 1,
       last : 1,
       has_iov : 1;
    s32 ifidx;
    u32 header_offset;
} msg_backlog_buf;

/* SBR_SPL_BIND and SBR_SPL_UNBIND */
typedef struct {
    s32 family;
    ip_addr_t local_ip;
    u16 local_port;
    u8 update;
} msg_bind;

/* SBR_SPL_SHUTDOWN */
typedef struct {
    u8 shut;
    u8 reserv[3];
} msg_shutdown;

/* SBR_SPL_CONNECT */
typedef struct {
    ip_addr_t local_ip;
    ip_addr_t remote_ip;
    u16 local_port;
    u16 remote_port;
    u8 is_nonblock;
    u8 ipv6;
    s32 ifidx;
    s8 update;
} msg_connect;

/* SBR_SPL_CLOSE */
typedef struct {
    s64 time_started;
    u8 need_rst;
    u8 shut;
} msg_delete_connect;

/* SBR_SPL_LISTEN */
typedef struct {
    u32 backlog;
} msg_listen;

/* SBR_SPL_RECVED */
typedef struct {
    u32 count;
} msg_recv_buf;

typedef struct {
    char name[IFNAMSIZ];
    u32 event;
    u32 flags;
} msg_sync_netif_flags;

typedef struct {
    u64 event;
    s32 ifindex;
    struct spl_sockaddr_in addr;
    struct spl_sockaddr_in mask;
} msg_sync_netif_addr;

typedef struct {
    u64 event;
    s32 ifindex;
    spl_ip6_addr_t addr;
    u32 mask_len;
} msg_sync_netif_ip6addr;

typedef struct {
    s32 ifindex;
    ip_addr_t addr;
    u8 nud_state;
    struct eth_addr ha;
} msg_sync_arp;

typedef struct {
    s32 accept_fd;
} msg_sync_accept_info;

struct ns_tcp_info {
    u8    tcpinf_state;
    u8    tcpinf_ca_state;
    u8    tcpinf_retransmits;
    u8    tcpinf_probes;
    u8    tcpinf_backoff;
    u8    tcpinf_options;
    u8    tcpinf_snd_wscale : 4, tcpinf_rcv_wscale : 4;
    u8    tcpinf_delivery_rate_app_limited : 1, tcpinf_fastopen_client_fail : 2;

    u32    tcpinf_rto;
    u32    tcpinf_ato;
    u32    tcpinf_snd_mss;
    u32    tcpinf_rcv_mss;

    u32    tcpinf_unacked;
    u32    tcpinf_sacked;
    u32    tcpinf_lost;
    u32    tcpinf_retrans;
    u32    tcpinf_fackets;

    /* Times. */
    u32   tcpinf_last_data_sent;
    u32   tcpinf_last_ack_sent;     /* Not remembered, sorry. */
    u32   tcpinf_last_data_recv;
    u32   tcpinf_last_ack_recv;

    /* Metrics. */
    u32   tcpinf_pmtu;
    u32   tcpinf_rcv_ssthresh;
    u32   tcpinf_rtt;
    u32   tcpinf_rttvar;
    u32   tcpinf_snd_ssthresh;
    u32   tcpinf_snd_cwnd;
    u32   tcpinf_advmss;
    u32   tcpinf_reordering;

    u32   tcpinf_rcv_rtt;
    u32   tcpinf_rcv_space;

    u32   tcpinf_total_retrans;

    u64   tcpinf_pacing_rate;
    u64   tcpinf_max_pacing_rate;
    u64   tcpinf_bytes_acked;
    u32   tcpinf_segs_out;
    u32   tcpinf_segs_in;

    u32   tcpinf_notsent_bytes;
    u32   tcpinf_min_rtt;
    u32   tcpinf_data_segs_out;

    u64   tcpinf_delivery_rate;

    u64   tcpinf_busy_time;
    u64   tcpinf_rwnd_limited;
    u64   tcpinf_sndbuf_limited;

    u32   tcpinf_delivered;
    u32   tcpinf_delivered_ce;

    u64   tcpinf_bytes_sent;
    u64   tcpinf_bytes_retrans;
    u32   tcpinf_dsack_dups;
    u32   tcpinf_reord_seen;
    u32   tcpinf_rcv_ooopack;

    u32   tcpinf_snd_wnd;
};

/* SBR_SPL_GETSOCKOPT and SBR_SPL_SETSOCKOPT */
typedef struct {
    s32 level;
    s32 optname;
    union {
        s32 int_optval;
        struct spl_in_addr inaddr_optval;
        struct spl_linger linger_t;
        struct timeval timeval_optval;
        char ca_name[TCP_CA_NAME_MAX];
        char if_name[IFNAMSIZ];
        struct ns_tcp_info opt_tcpinf;
    } optval;

    u32 optlen;
} msg_setgetsockopt;

struct netbuf {
    ip_addr_t addr;
    u16 port;
};

typedef struct {
    u64 sync_m;
} msg_common_resp;

typedef struct {
    u8 enabled; // Whether the timestamp is valid, prevent callbacks configured in the middle of the process
    u8 resv[3];
    u32 if_timestamp; // first stat when recv, need use timestamp.
    u16 netif_cost_time;
    u16 ip_cost_time;
    u16 trans_cost_time;
    u16 msg_cost_time; // cost time in A2D/D2A
    u32 sock_timestamp; // first stat when send, need use timestamp.
} cost_time_stats;

typedef struct {
    s32 ifidx;
    s8 net_hdr_offset;
    s8 trans_hdr_offset;
    u8 iov_segs;
    u8 is_ipv6 : 1,
       resv : 7;

    cost_time_stats stats;
    u32 arrived_timestamp;
    msg_iov iov[0];
} msg_pkt_arrived;

typedef struct {
    u8 num;
    u8 reserv[3];
    msg_pkt_arrived pkt_array[0];
} msg_pkt_arrived_array;

typedef struct {
    u32 enq_num;
} msg_tx_enq;

typedef struct {
    s32 fd;
    u16 remote_port;
    u16 local_port;
    ip_addr_t remote_ip;
    ip_addr_t local_ip;
    u32 tx_sbuf_num;
    u16 tcp_optlen;
    u16 mss;
} msg_conn_accept;

typedef struct {
    u64 sync_m;
    u8 is_wakeup;
    u32 event;
    s32 errnum;
    u16 tcp_optlen;
    u16 mss;
    u16 remote_port;
    u16 local_port;
    ip_addr_t remote_ip;
    ip_addr_t local_ip;
    u8 update;
} msg_connect_resp;

typedef struct {
    u8 tcp_state;
    s32 errnum;
} msg_err_report;

typedef struct {
    u8 tcp_state;
    u8 reserv[3];
} msg_tcp_state_change;

typedef struct {
    u64 sk_id;
    s32 bind_netif_id;
    u32 sk_mark;
    s32 send_bufsize;
    ip_addr_t sip;
    ip_addr_t rip;
    u8 so_debug : 1,
        so_reuse_addr : 1,
        so_keepalive : 1,
        so_dontroute : 1,
        so_broadcast : 1,
        so_urginline : 1,
        so_reuse_port : 1;

    u8 tos;
    u8 ttl;
    u8 mc_ttl;
    u8 is_tcp : 1,
        ipv6 : 1,
        ipv6_only : 1,
        is_auto_fl : 1,
        pmtudisc : 3;

    u16 inet_id;
    u16 sport;
    u16 dport;
    u32 uid;
    u32 flowlabel;  /* network order */
    u32 tx_hash;
    u32 fl_stateless_flag;
} msg_common_migrate;

typedef struct {
    msg_common_migrate comm;

    ip_addr_t nexthop;
    u8 shutdown : 2,
       nagle_off : 1,
       tstamp : 1,
       sack : 1,
       wscale : 1,
       tcp_quick_ack : 1,
       thin_lto : 1;
    u32 rcv_nxt;
    u32 rcv_wnd;

    u16 peer_mss;
    u16 effmss;
    u16 user_defined_mss;
    /* Sender side RTT estimation */
    struct {
        u32 sa, sv;
    } snd_rtt_est;

    u32 snd_cwnd;
    u32 snd_ssthresh;

    u32 snd_nxt; /* next new SeqNo to send */
    u32 snd_wnd; /* sender window */

    u32 keep_intvl; /* seconds */
    u32 keep_cnt;
    u32 keep_idle; /* idle time in seconds before KEEPALIVE is sent */

    s32 linger2; /* seconds */
    u8 ws_shift_cnt_w;
    u8 ws_shift_cnt_r;

    u8 recv_buf_flag;
    int ifidx;
    s32 rcv_bufsize;
    u32 ts_recent;
    u32 ts_now;
} msg_tcp_migrate_a2d;

typedef struct {
    msg_common_migrate comm;
} msg_udp_migrate_a2d;

typedef struct {
    u64 migrate_id;
    u32 tx_sbuf_num;
} msg_migrate_a2d_resp; /* both tcp and udp */

typedef struct {
    s32 netif_id;
    struct eth_addr hwsrc;
    spl_ip4_addr_t ipsrc;
    spl_ip4_addr_t ipdst;
} msg_arp_notify;

typedef struct {
    s32 netif_id;
    spl_ip6_addr_t ipsrc;
    spl_ip6_addr_t ipdst;
} msg_nd_notify;

typedef struct {
    ip_addr_t dst_addr;
    ip_addr_t src_addr;
    u16 remote_port;
} msg_route_notify;

typedef struct {
    s32 netif_id;
    ip_addr_t nexthop;
} msg_route_rsp;

#define MAX_NUM_SACK 4
struct sack_block {
    u32 start_seq;
    u32 end_seq;
};

struct rtt_minmax_sample {
    u32 t;
    u32 v;
};

struct rtt_minmax {
    struct rtt_minmax_sample s[3];
};

typedef struct {
    u32 type;
    u32 cnt;
    u32 pkts;
    u32 bytes;
} conn_stat_tv;

typedef struct {
    s32 err;
    u32 rcv_nxt;
    u32 rcv_wnd;
    u32 rcv_buf;

    struct {
        u32 sa, sv;
    } snd_rtt_est;
    struct rtt_minmax rtt_min; /* min rtt ms */

    u32 snd_cwnd;
    u32 snd_ssthresh;
    u32 persist_cnt; /* Persist timer counter */
    u8 keep_cnt_sent; /* KEEPALIVE counter */
    u8 tcp_state; /* TCP state */
    u16 inet_id;
    u32 tx_hash;

    u32 snd_buf;
    u32 snd_nxt; /* next new SeqNo to send */
    u32 snd_sml; /* The last byte of the most recently transmitted small packet */
    u32 snd_wnd; /* sender window */
    u32 rcv_wup; /* ackno that last window update acked */
    u32 quick_ack;
    u32 snd_una;

    /* Seq and Ack numbers of last window update */
    u32 snd_wl1;
    u32 ts_recent;
    u32 ts_now;

    struct sack_block sack_seq[MAX_NUM_SACK]; /* in host bytes order */
    struct sack_block recv_sack[MAX_NUM_SACK];
    u16 retransmits;
} msg_tcp_migrate_d2a_resp;

typedef struct {
    ip_addr_t sip;
    ip_addr_t rip;
    u8 is_ipv6 : 1,
        is_udp : 1;
    u16 sport;
    u16 dport;
    u64 sk_id;
    u16 stats_num;
    conn_stat_tv stats[0];
} msg_dpa_conn_stats_report;

enum {
    IOV_TYPE_UNSENT = 0,
    IOV_TYPE_UNACK = 1,
    IOV_TYPE_RCV = 2,
    IOV_TYPE_RCV_OFO = 3,
};

typedef struct iov_desc {
    u32 start_seq; /* tcp seq */
    u32 send_time; /* the time(us) since last send */
    u8 type : 3, /* IOV_TYPE_* */
       push : 1, /* tcp header flag push */
       fin : 1, /* tcp header flag fin */
       retrans : 1,
       sacked : 1,
       is_ipv6 : 1;
    s8 net_hdr_offset;
    s8 trans_hdr_offset;
} iov_desc_t;

#define D2A_SND_IOV_MAX 32

typedef struct {
    msg_iov iov[D2A_SND_IOV_MAX];
    iov_desc_t desc[D2A_SND_IOV_MAX];
    u8 iov_segs;
} msg_tcp_d2a_iov_snd;

typedef struct {
    msg_iov iov[MAX_FRAGS];
    iov_desc_t desc;
    u8 iov_segs;
} msg_tcp_d2a_iov_rcv;

typedef struct {
    msg_iov iov[MAX_FRAGS];
    s32 ifindex;
    s8 net_hdr_offset;
    s8 trans_hdr_offset;
    u8 is_ipv6 : 1,
       is_tcp : 1,
       head_repair : 1,
       resv : 5;
    u8 iov_segs;
    u16 net_len; /* valid when head_repair is set */
    u8 tcp_flags; /* valid when head_repair is set */
} msg_pkt_redirect;

typedef struct {
    s32 req_code;
} msg_migrate_d2a_req;

#pragma pack ()

static inline void msg_iov_free(msg_iov *iov)
{
    stack_maa_free(iov->base_addr, iov->head_frag ? MAA_FLAG_PAGE : 0);
}

static inline void msg_iovs_free(msg_iov *iov, u32 segs)
{
    u32 i;
    for (i = 0; i < segs; i++) {
        msg_iov_free(&iov[i]);
    }
}

#ifdef __cplusplus
}
#endif

#endif
