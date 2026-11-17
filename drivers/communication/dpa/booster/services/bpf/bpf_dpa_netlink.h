

#ifndef _BPF_DPA_NETLINK_H
#define _BPF_DPA_NETLINK_H

#include <linux/netlink.h>

#define BPF_NETLINK_INIT 1
#define BPF_NETLINK_EXIT 0

/*
 * enum - netlink DPA report message
 * @NETLINK_BPF_REG: send from user space to register the PID for netlink kernel socket
 * @NETLINK_BPF_TO_USR_MSG: send from kernel to apk
 * @NETLINK_BPF_TO_KER_MSG: send from user space with opcode and should be transfered to D-core
 */

typedef enum {
    NETLINK_BPF_WRITE_CONNLOSSSTATMAP,
    NETLINK_BPF_READ_CONNLOSSSTATMAP,
    NETLINK_BPF_DELETE_CONNLOSSSTATMAP,
    NETLINK_BPF_CLEAR_CONNLOSSSTATMAP,
    NETLINK_BPF_WRITE_CONNLOSSMAP,
    NETLINK_BPF_READ_CONNLOSSMAP,
    NETLINK_BPF_CLEAR_CONNLOSSMAP,
    NETLINK_BPF_DELETE_CONNLOSSMAP,
    NETLINK_BPF_WRITE_CONNSTATMAP,
    NETLINK_BPF_READ_CONNSTATMAP,
    NETLINK_BPF_CLEAR_CONNSTATMAP,
    NETLINK_BPF_DELETE_CONNSTATMAP,
    NETLINK_BPF_OPCODE_MAX,
} bpf_op_code;

#pragma pack(4)
typedef struct conn_loss_stat_value {
    u64 totalbytes;
    u64 lossbytes;
    u64 rcvbytes;
} conn_loss_stat_value;
#pragma pack()

typedef u32 conn_addr_stat_switch_val;

struct bpf_packet_msg {
    conn_loss_stat_value conn_loss_stat_val;
    conn_addr_stat_switch_val conn_addr_stat_switch_val;
};

typedef struct conn_loss_stat_key {
    u32 saddr;
    u32 daddr;
    u16 sport;
    u16 dport;
} conn_loss_stat_key;

typedef struct conn_addr_stat_switch_key {
    u32 saddr;
    u32 daddr;
} conn_addr_stat_switch_key;

#pragma pack(4)
struct bpf_msg_2_knl {
    struct nlmsghdr hdr;
    bpf_op_code bpf_code;
    union {
        conn_loss_stat_key conn_lost_stat_key;
        conn_addr_stat_switch_key conn_addr_stat_key;
    };
    union {
        conn_loss_stat_value conn_loss_stat_val;
        conn_addr_stat_switch_val conn_addr_stat_val;
    };
};
#pragma pack()

int send_resp_msg(bpf_op_code opcode, struct bpf_packet_msg *msg);
int bpf_dpa_netlink_module_init(void);

#endif /* _BPF_DPA_NETLINK_H */
