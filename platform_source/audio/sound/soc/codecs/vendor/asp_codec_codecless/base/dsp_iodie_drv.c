/*
 * dsp_iodie_drv.c -- codec driver
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 *
 * Description: Initialization registration and exception callback
 * Create: 2025-02-19
 *
 */
#include <linux/printk.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <securec.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_def.h>
#include <platform_include/smart/drivers/io_die/iodie_hiphyio_hal.h>
 
#include "dsp_iodie_drv.h"
#include "dsp_misc.h"
#include "drv_mailbox_cfg.h"
#include "drv_mailbox_msg.h"
#include "audio_common_msg_id.h"
#include "audio_ddr_map.h"
#include "dsp_om.h"
#include "platform_base_addr_info.h"
#include "audio_common_msg.h"
#include "dsp_msg.h"

static int send_sync_iodie_err_msg_to_dsp(uint32_t msg_id, enum iodie_to_dsp_status err)
{
    struct dsp_iodie_stop_msg msg = {0};
    struct dsp_iodie_stop_msg_ack msg_ack = {0};

    msg.msg_id = msg_id;
    msg.err_type = err;
    if (sync_cmd_from_kernel((void *)&msg, sizeof(msg), (void *)&msg_ack, sizeof(msg_ack)) != 0) {
		pr_err("iodie audio send err msg to dsp fail\n");
        return -1;
    }

    if (msg_ack.msg_id != ID_AP_DSP_IODIE_STOP_TRANSTER_ACK) {
		pr_err("iodie audio msg_id: %hx msg from dsp error\n", msg_ack.msg_id);
		return -1;
	}

    return 0;
}

static int32_t iodie_msg_send(uint32_t msg_id)
{
    struct dsp_iodie_write_output_msg msg = {0};
    msg.msg_id = msg_id;
    return mailbox_send_msg(MAILBOX_MAILCODE_ACPU_TO_HIFI_MISC, &msg, sizeof(msg));
}

static enum iodie_to_dsp_status iodie_status_remap(enum iodie_sys_status sys_status,
    enum iodie_err_status interface_status)
{
    switch (sys_status) {
    case IODIE_ST_INITED:
        if (interface_status == IODIE_ERR_I2S)
            return IODIE_STATUS_ERR_I2S;
        else
            return IODIE_STATUS_INITED;
        break;
    case IODIE_ST_ERR:
        if (interface_status == IODIE_ERR_HIPHY)
            return IODIE_STATUS_ERR_HIPHY;
        else if (interface_status == IODIE_ERR_IODIE)
            return IODIE_STATUS_ERR_IODIE;
        else
            return IODIE_STATUS_ERR;
        break;
    default:
        break;
    }
    return IODIE_STATUS_INITED;
}

static int32_t iodie_write_shamem_to_dsp(enum iodie_to_dsp_status iodie_status)
{
    unsigned char *hifi_vir_addr;

    hifi_vir_addr = get_dsp_viradr();
    if (!hifi_vir_addr) {
		pr_err("iodie audio ABLOG_KEY:read nv,hifi vir addr is null\n");
        return -1;
	}
    writel(iodie_status, hifi_vir_addr + (DRV_AP_IODIE_SHAMEM_ADDR - DSP_UNSEC_BASE_ADDR));

    return 0;
}

static int32_t update_dsp_iodie_status(enum iodie_to_dsp_status dsp_status, uint32_t msg_id)
{
    int32_t ret_msg = 0;
    int32_t ret_shamem = 0;

    pr_info("iodie audio update dsp iodie msg_id: %hx\n", msg_id);

    if (msg_id == ID_AP_DSP_IODIE_RESUME_TRANSMISSION ) {
        ret_msg = iodie_msg_send(ID_AP_DSP_IODIE_RESUME_TRANSMISSION);
        pr_info("iodie audio ap success resume msg\n");
    } else {
        ret_msg = send_sync_iodie_err_msg_to_dsp(msg_id, dsp_status);
    }
    if (ret_msg != 0) {
        pr_err("iodie audio send msg to dsp fail msg_id: %hx\n", msg_id);
        return ret_msg;
    }

    ret_shamem = iodie_write_shamem_to_dsp(dsp_status);
    if (ret_shamem != 0) {
        pr_err("iodie audio write share memory fail\n");
        return ret_shamem;
    }

    return 0;
}

void iodie_use_callback(enum iodie_sys_status iodie_status, enum iodie_err_status err)
{
    /* used to determine whether there is repeated transmission */
    static enum iodie_sys_status pre_sys_status = IODIE_ST_PRE_INITED;
    static enum iodie_err_status pre_err_status = IODIE_ERR_SYS;
    static enum iodie_to_dsp_status pre_dsp_status = IODIE_STATUS_ERR_END;
    static enum iodie_to_dsp_status to_dsp_status = IODIE_STATUS_INITED;

    if (pre_sys_status == iodie_status && pre_err_status == err) {
        pr_err("iodie audio iodie status is same %d %d\n", iodie_status, err);
        return;
    }

    to_dsp_status = iodie_status_remap(iodie_status, err);
    if (to_dsp_status == pre_dsp_status) {
        pr_err("iodie audio dsp status is same %d\n", to_dsp_status);
        pre_sys_status = iodie_status;
        pre_err_status = err;
        return;
    }

    switch (iodie_status) {
    case IODIE_ST_INITED:
        if (err == IODIE_ERR_I2S) {
            if (update_dsp_iodie_status(to_dsp_status, ID_AP_DSP_IODIE_STOP_TRANSTER) != 0)
                pr_err("iodie audio send stop transfer i2s fail\n");
        } else if (err == IODIE_ERR_NO) {
            if (update_dsp_iodie_status(to_dsp_status, ID_AP_DSP_IODIE_RESUME_TRANSMISSION) != 0)
                pr_err("iodie audio send resume i2s fail\n");
        }
        break;
    case IODIE_ST_ERR:
        if (err == IODIE_ERR_HIPHY || err == IODIE_ERR_IODIE) {
            if (update_dsp_iodie_status(to_dsp_status, ID_AP_DSP_IODIE_STOP_TRANSTER) != 0)
                pr_err("iodie audio send stop i2s transfer fail\n");
        }
        break;
    default:
        pr_err("iodie audio unknown iodie status\n");
        break;
    }

    pre_sys_status = iodie_status;
    pre_err_status = err;
    pre_dsp_status = to_dsp_status;
}

int32_t iodie_drv_init(void)
{
    int32_t ret = 0;

    ret = iodie_notify_register(IODIE_USER_AP_AUDIO, iodie_use_callback);
    if (ret != 0) {
            pr_err("%s:iodie audio register fail\n", __func__);
            return -1;
    }

    ret = iodie_write_shamem_to_dsp(iodie_status_remap(get_iodie_status(), IODIE_ERR_NO));
    if (ret != 0) {
        pr_err("iodie audio write share memory fail\n");
        return -1;
    }

    pr_info("iodie audio dsp iodie drv init success\n");
    return 0;
}

