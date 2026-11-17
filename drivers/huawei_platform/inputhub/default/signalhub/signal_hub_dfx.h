

#ifndef __SIGNAL_HUB_DFX_H__
#define __SIGNAL_HUB_DFX_H__
#include "contexthub_route.h"
#include "signal_hub_channel.h"

/* Check Value */
#define CHECK_VALUE                         0x5A5A

/* Size: 4K, End at: 0xFDB3BFFF */
#define SOC_ADDR_OFFSET_SIZE            (0x1000)
#define SOC_ACPU_MIPI_BASE_ADDR         (0xFDB3B000)
#define SIGNALHUB_WRITE_ADDR_OFFSET     (0x300UL)
#define SIGNALHUB_READ_ADDR_OFFSET      (0x304UL)
#define SIGANLHUB_ADDR_INVALID_VALUE    (0xffff)

#define MAX_TUNER_NUM 2
#define MAX_SYSTEM_STATE_NUM 27
#define MAX_CFG_STATE_NUM 9
#define MAX_NC_SYSTEM 2

typedef struct {
    uint32_t wifi_scan_time;
    uint32_t wifi_sta_time;
    uint32_t wifi_active_time;
    uint32_t wifi_beacon_time;
} signalhub_wifi_time;

typedef struct {
    uint32_t bsle_c0_active_use_time;
    uint32_t bsle_c0_active_off_time;
    uint32_t bsle_c1_active_use_time;
    uint32_t bsle_c1_active_off_time;
} signalhub_bsle_time;

typedef struct {
    uint32_t fix_policy_time[MAX_TUNER_NUM];
    uint32_t real_policy_time[MAX_TUNER_NUM];
    uint32_t system_state_time[MAX_TUNER_NUM][MAX_SYSTEM_STATE_NUM];
    signalhub_bsle_time bsle_time;
    signalhub_wifi_time wifi_time;
} signalhub_fir_statistic_data;

typedef struct {
    signalhub_fir_statistic_data fir_data;
    uint32_t cfg_state_time[MAX_TUNER_NUM][MAX_CFG_STATE_NUM];
} signalhub_statistic_data;

typedef enum {
    SIGNALHUB_WIFI_TRIGGER = 0x0,
    SIGNALHUB_BSLE_TRIGGER,
} signalhub_trigger_type;

typedef struct {
    uint16_t subcmd;  // 0:wifi 1:bsle
    uint16_t size;
    uint8_t data[0];
} abnormal_state_unit;
 
typedef union {
    struct wifi_state_unit{
        uint16_t wifi_mode; // 0:2.4G  1:5G
        uint16_t vap_mode; // uint16, 每个bit有不同值
        uint32_t rsv;
    } wifi_unit;
    struct bsle_state_unit{
        uint32_t bsle_mode;
        uint32_t rsv;
    } bsle_unit;
} signalhub_state_unit;

typedef struct {
    uint16_t trigger_type; // 0:WIFI; 1:BSLE
    uint8_t policy[MAX_TUNER_NUM];
    uint8_t mask[MAX_TUNER_NUM];
    uint8_t sys_state[MAX_TUNER_NUM];
    uint8_t wifi_2P4G_status; // 0:不使用 1：使用
    uint8_t wifi_5G_status;
    uint8_t bsle_2P4G_status;
    uint8_t bsle_5G_status;
    uint8_t cfg_index[MAX_TUNER_NUM];
    uint16_t rsv;
} signalhub_abnormal_data;

typedef struct {
    uint32_t subcmd;
    uint32_t size;
    uint8_t data[0];
} signalhub_dfx_report_data;

typedef enum {
    SIGNALUHB_DFX_STATISTIC_CMD = 0x0,
    SIGNALHUB_DFX_ABNORMAL_CMD = 0x1,
    SIGNALHUB_DFX_CMD_BUTT,
} signalhub_dfx_msg_cmd;

// 访问时持锁
typedef struct {
    uint32_t valid_flag; // 0:无效，1:有效
    signalhub_report_query_data data;
} signalhub_kernel_record_data;

typedef union {
    uint32_t value;
    struct {
        uint32_t tuner0_policy        : 4;

        uint32_t sys1_tuner0_mask     : 1;
        uint32_t sys2_tuner0_mask     : 1;
        uint32_t sys1_tuner0_status   : 1;
        uint32_t sys2_tuner0_status   : 1;

        uint32_t tuner1_policy        : 4;
        uint32_t sys1_tuner1_mask     : 1;
        uint32_t sys2_tuner1_mask     : 1;
        uint32_t sys1_tuner1_status   : 1;
        uint32_t sys2_tuner1_status   : 1;

        uint32_t check_value          : 16;
    } reg;
} signalhub_reg_send_info;

typedef union {
    uint32_t value;
    struct {
        uint32_t modem_flag           : 1;    /* 0:modem transient  1:modem steady */
        uint32_t mipi_ctrl_right      : 1;    /* 0:signalhub  1:modem */
    
        uint32_t rsv                  : 14;
        uint32_t check_value          : 16;   /* Check Value is 5A5A */
    } reg;
} signalhub_reg_recv_info;

uint32_t signalhub_recv_addr_info(unsigned int offset_addr);
void signalhub_send_addr_info(unsigned int offset_addr);
void process_signalhub_dfx_msg(signalhub_comm_report_data *data);
int process_query_report_msg(signalhub_comm_report_data *data);
int signal_hub_send_abnormal_emergency(void __user *argp, bool is_open);
int signal_hub_send_query(void __user *argp, bool is_open);
int signal_hub_get_state_info(void __user *argp);

#endif