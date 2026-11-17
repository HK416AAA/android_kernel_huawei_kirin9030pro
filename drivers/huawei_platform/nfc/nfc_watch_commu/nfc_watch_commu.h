
#ifndef _NFC_WATCH_COMMU_H
#define _NFC_WATCH_COMMU_H

#include "securec.h"

/* watch serviceid commandid */
#define NFC_WATCH_COMMUX_SVR     0x01
#define NFC_WATCH_DATA_CMD       0x8A
#define NFC_WATCH_IRQ_CMD        0xA1
#define ELECTRICITY_COMMUX_SVR   0x1B
#define ELECTRICITY_DATA_CMD     0xFA
#define NFC_ELECTRICITY_DATA_LEN 20
#define NFC_SID_CID_COUNT        1      /* watch serviceid commandid */

#define NFC_COMMON_OK            1
#define NFC_COMMON_NOK           -1

typedef enum {
    NFC_COMMUX_READ = 0x0,
    NFC_COMMUX_WRITE,
    MODE_VEN_VALUE_SET_MSG,
    NFC_VEN_INIT,
    MODE_DL_VALUE_SET_MSG,
    NFC_AP_IRQ_FREE_REQ,
    NFC_AP_IRQ_RECONFIG_REQ,
} NFC_COMMUX_CONTROLS;

#pragma pack(4)
typedef struct {
    uint16_t msgtype;
    uint16_t buff_len;
    uint8_t buff[0];
} nfc_commu_msg;
#pragma pack()

#pragma pack(4)
typedef struct {
    int16_t maximum_current;
    int16_t abnormal_time;
} nfc_electric_msg;
#pragma pack()

void register_watch_mcu_nfc_callback(void);
uint16_t get_receive_data_len(void);
unsigned char* get_receive_data(void);
void clear_receive_data(void);
int nfc_commu_send_msg(const char *buf, int len, uint16_t msg);
void nfc_electric_dubai(unsigned char *data);
#endif
