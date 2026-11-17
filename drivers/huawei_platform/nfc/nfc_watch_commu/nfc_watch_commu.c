
#include "nfc_watch_commu.h"
#include "stdbool.h"
#include <linux/printk.h>
#include <linux/delay.h>
#include "linux/slab.h"
#include "../TMS_THN31_64/watch_thn31.h"
#ifdef CONFIG_EXT_INPUTHUB
#include "ext_sensorhub_api.h"
#endif
#include <dfx/hiview_hisysevent.h>

#define RECV_DATA_MAX_LEN 512

unsigned char receive_data[RECV_DATA_MAX_LEN] = {0};
uint16_t receive_data_len = 0;

static struct sid_cid g_nfc_read_mcu_cid[] = {
    { NFC_WATCH_COMMUX_SVR, NFC_WATCH_DATA_CMD },
    { ELECTRICITY_COMMUX_SVR, ELECTRICITY_DATA_CMD }
};

static struct subscribe_cmds g_nfc_read_mcu_cmds = {
    g_nfc_read_mcu_cid, sizeof(g_nfc_read_mcu_cid) / sizeof(g_nfc_read_mcu_cid[0])
};

unsigned char* get_receive_data(void)
{
    return receive_data;
}

uint16_t get_receive_data_len(void)
{
    return receive_data_len;
}

void clear_receive_data(void)
{
    receive_data_len = 0;
    if (memset_s(receive_data, RECV_DATA_MAX_LEN ,0x00, RECV_DATA_MAX_LEN) != EOK) {
        pr_err("%s:memset_s err\n", __func__);
    }
    return;
}

int nfc_commu_send_msg(const char *buf, int len, uint16_t msg)
{
    int ret = NFC_COMMON_NOK;
    nfc_commu_msg *reqmsg = (nfc_commu_msg *)kzalloc(sizeof(nfc_commu_msg) + len, GFP_KERNEL);
    if (reqmsg == NULL) {
        pr_info("%s: reqmsg alloc fail\n", __func__);
        return ret;
    }
    (void*)memset_s(reqmsg, sizeof(nfc_commu_msg) + len, 0x00, sizeof(nfc_commu_msg) + len);

    reqmsg->msgtype = msg;
    reqmsg->buff_len = len;
    if (len > 0 && buf != NULL) {
        if(memcpy_s(reqmsg->buff, len ,buf, len) != EOK) {
            pr_err("%s:reqmsg buff memcpy_s err\n", __func__);
            goto err;
        }
    }

    struct command command_info = {0};
    command_info.service_id = NFC_WATCH_COMMUX_SVR;
    command_info.command_id = NFC_WATCH_DATA_CMD;
    command_info.send_buffer = (unsigned char *)reqmsg;
    command_info.send_buffer_len = sizeof(nfc_commu_msg) + reqmsg->buff_len;

    pr_info("%s command_info:msgtype->%d, buffer_len->%d\n", __func__, reqmsg->msgtype, reqmsg->buff_len);
    ret = send_command(NFC_CHANNEL, &command_info, false, NULL);
    if (ret < 0) {
        pr_err("%s:commux send %d err ret = %d\n", __func__, msg, ret);
    }
err:
    kfree(reqmsg);
    return ret;
}

static int watch_nfc_recv_mcu_cb(unsigned char service_id, unsigned char command_id, unsigned char *data, int data_len)
{
    if ((data == NULL) || (data_len < sizeof(nfc_commu_msg))) {
        pr_err("%s:data is NULL or data_len is illegal!\n", __func__);
        return NFC_COMMON_NOK;
    }

    if (service_id == NFC_WATCH_COMMUX_SVR && command_id == NFC_WATCH_DATA_CMD) {
        nfc_commu_msg *msgdata = (nfc_commu_msg *)data;
        if (msgdata->msgtype == NFC_COMMUX_READ) {
            receive_data_len = msgdata->buff_len;
            int cpy_len = RECV_DATA_MAX_LEN < receive_data_len ? RECV_DATA_MAX_LEN : receive_data_len;
            if (memcpy_s(receive_data, RECV_DATA_MAX_LEN, msgdata->buff, cpy_len) != EOK) {
                pr_err("%s:msgdata buff cpy fail!\n", __func__);
                return NFC_COMMON_NOK;
            }
            pr_info("%s:up nfc_read_data_sem\n", __func__);
            up(get_nfc_read_data_sem());
        } else if (msgdata->msgtype == NFC_AP_IRQ_FREE_REQ) {
            pr_info("%s:watch_thn31_free_irq\n", __func__);
            watch_thn31_free_irq();
        } else if (msgdata->msgtype == NFC_AP_IRQ_RECONFIG_REQ) {
            pr_info("%s:watch_thn31_reconfig_irq\n", __func__);
            watch_thn31_reconfig_irq();
        } else {
            pr_err("%s:unknown msgtype id %d!\n", __func__, msgdata->msgtype);
            return NFC_COMMON_NOK;
        }
    } else if (service_id == ELECTRICITY_COMMUX_SVR && command_id == ELECTRICITY_DATA_CMD) {
        pr_err("%s:nfc_electric_dubai enter!\n", __func__);
        nfc_electric_dubai(data);
    } else {
        pr_err("%s:unknown service_id:%d command_id:%d!\n", __func__, service_id, command_id);
        return NFC_COMMON_NOK;
    }

    return NFC_COMMON_OK;
}

void register_watch_mcu_nfc_callback(void)
{
    pr_info("%s: enter",__func__);
    register_data_callback(NFC_CHANNEL, &g_nfc_read_mcu_cmds, watch_nfc_recv_mcu_cb);
}

void nfc_electric_dubai(unsigned char *data)
{
    int ret = 0;
    nfc_electric_msg *msgdata = (nfc_electric_msg *)data;

    char *nfc_electric_data = (char *)kzalloc(NFC_ELECTRICITY_DATA_LEN, GFP_KERNEL);
    if (nfc_electric_data == NULL) {
        pr_err("%s allocate failed\n",  __func__);
        return;
    }
    (void*)memset_s(nfc_electric_data, NFC_ELECTRICITY_DATA_LEN, 0x00, NFC_ELECTRICITY_DATA_LEN);

    ret = snprintf_s(nfc_electric_data, NFC_ELECTRICITY_DATA_LEN, NFC_ELECTRICITY_DATA_LEN - 1,
        "%dmA,%dms", msgdata->maximum_current, msgdata->abnormal_time);
    if (ret < 0) {
        kfree(nfc_electric_data);
        pr_err("%s snprintf_s err, ret:%d\n",  __func__, ret);
        return;
    }

    struct hiview_hisysevent *nfc_electric_event = NULL;
    nfc_electric_event = hisysevent_create("WATCH_POWERTHER", "WATCH_MODULE_BATTERY_STATE", BEHAVIOR);

    hisysevent_put_string(nfc_electric_event, "MODULE", "WatchBatteryHighMCU");
    hisysevent_put_integer(nfc_electric_event, "STATE", -1);
    hisysevent_put_integer(nfc_electric_event, "LEVEL", -1);
    hisysevent_put_string(nfc_electric_event, "CONTENT", nfc_electric_data);

    hisysevent_write(nfc_electric_event);

    hisysevent_destroy(&nfc_electric_event);
    kfree(nfc_electric_data);
}
