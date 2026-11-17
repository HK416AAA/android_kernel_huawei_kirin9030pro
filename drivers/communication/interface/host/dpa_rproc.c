/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <linux/remoteproc.h>
#include <securec.h>
#include "nve_ap_kernel_interface.h"
#include "dpa_version.h"
#include "dpa_rproc.h"
#include "dpa_sms.h"

static struct dpa_rproc_ops *g_dpa_rproc_ops;

int bsp_dpa_register(struct dpa_rproc_ops *rproc_ops)
{
    if (rproc_ops == NULL) {
        return -1;
    }

    g_dpa_rproc_ops = rproc_ops;

    return 0;
}
EXPORT_SYMBOL(bsp_dpa_register);

int dpa_get_status_ops(void)
{
    if (g_dpa_rproc_ops == NULL) {
        dpa_err("Not Register dpa rproc API!\n");
        return -ENOSYS;
    }

    if (g_dpa_rproc_ops->dpa_get_status == NULL) {
        dpa_err("Not Support dpa_get_status API!\n");
        return -ENOSYS;
    }

    if (g_dpa_rproc_ops->dpa_get_status() == RPROC_OFFLINE) {
         dpa_err("DPA OFFLINE,Not Support!\n");
         return -1;
    }

    return 0;
}
EXPORT_SYMBOL(dpa_get_status_ops);

struct dpa_wakeup_source *dpa_wakeup_source_register_ops(const char *name)
{
    if (g_dpa_rproc_ops == NULL) {
        dpa_err("Not Register dpa rproc API!\n");
        return NULL;
    }

    if (g_dpa_rproc_ops->dpa_wakeup_source_register == NULL) {
        dpa_err("Not Support dpa_get_status API!\n");
        return NULL;
    }

    return g_dpa_rproc_ops->dpa_wakeup_source_register(name);
}
EXPORT_SYMBOL(dpa_wakeup_source_register_ops);

int dpa_wakeup_source_unregister_ops(struct dpa_wakeup_source *ws)
{
    if (g_dpa_rproc_ops == NULL) {
        dpa_err("Not Register dpa rproc API!\n");
        return -ENOSYS;
    }

    if (g_dpa_rproc_ops->dpa_wakeup_source_unregister == NULL) {
        dpa_err("Not Support dpa_wakeup_source_unregister API!\n");
        return -ENOSYS;
    }

    return g_dpa_rproc_ops->dpa_wakeup_source_unregister(ws);
}
EXPORT_SYMBOL(dpa_wakeup_source_unregister_ops);

int dpa_pm_stay_awake_ops(struct dpa_wakeup_source *ws)
{
    if (g_dpa_rproc_ops == NULL) {
        dpa_err("Not Register dpa rproc API!\n");
        return -ENOSYS;
    }

    if (g_dpa_rproc_ops->dpa_pm_stay_awake == NULL) {
        dpa_err("Not Support dpa_pm_stay_awake API!\n");
        return -ENOSYS;
    }

    return g_dpa_rproc_ops->dpa_pm_stay_awake(ws);
}
EXPORT_SYMBOL(dpa_pm_stay_awake_ops);

int dpa_pm_stay_awake_with_autosuspend_ops(struct dpa_wakeup_source *ws, unsigned int msec)
{
    if (g_dpa_rproc_ops == NULL) {
        dpa_err("Not Register dpa rproc API!\n");
        return -ENOSYS;
    }

    if (g_dpa_rproc_ops->dpa_pm_stay_awake_with_autosuspend == NULL) {
        dpa_err("Not Support dpa_pm_stay_awake_with_autosuspend API!\n");
        return -ENOSYS;
    }

    return g_dpa_rproc_ops->dpa_pm_stay_awake_with_autosuspend(ws, msec);
}
EXPORT_SYMBOL(dpa_pm_stay_awake_with_autosuspend_ops);

int dpa_pm_relax_ops(struct dpa_wakeup_source *ws)
{
    if (g_dpa_rproc_ops == NULL) {
        dpa_err("Not Register dpa rproc API!\n");
        return -ENOSYS;
    }

    if (g_dpa_rproc_ops->dpa_pm_relax == NULL) {
        dpa_err("Not Support dpa_pm_relax API!\n");
        return -ENOSYS;
    }

    return g_dpa_rproc_ops->dpa_pm_relax(ws);
}
EXPORT_SYMBOL(dpa_pm_relax_ops);

#define DPA_NVE_NAME "DPA"
#define DPA_NVE_NUM 581
#define DPA_NVE_MAX_SIZE NVE_NV_DATA_SIZE 
#define DPA_WRIYE_NV NV_WRITE
#define DPA_READ_NV NV_READ

static int dpa_read_nve(void *data, uint32_t len)
{
    int ret;
    struct opt_nve_info_user nve_info = {
        .nv_operation = DPA_READ_NV,
        .nv_number = DPA_NVE_NUM,
        .nv_name = DPA_NVE_NAME,
        .valid_size = DPA_NVE_MAX_SIZE,
    };

    if ((data == NULL) || (len > DPA_NVE_MAX_SIZE)){
        dpa_err("para check fail!\n");
    }

    ret = nve_direct_access_interface(&nve_info);
    if (ret != 0) {
        dpa_err("dpa nve read fail!\n");
        return -1;
    }

    ret = memcpy_s(data, len, nve_info.nv_data, len);
    if (ret != EOK) {
        dpa_err("memcpy fail,err %d!\n",ret);
        return -1;
    }

    dpa_err("dpa nve read success!\n");
    return 0;
}

static int dpa_write_nve(void *data, uint32_t len)
{
    int ret;
    struct opt_nve_info_user nve_info = {
        .nv_operation = DPA_WRIYE_NV,
        .nv_number = DPA_NVE_NUM,
        .nv_name = DPA_NVE_NAME,
        .valid_size = DPA_NVE_MAX_SIZE,
    };

    if (data == NULL) {
        dpa_err("para check fail!\n");
    }

    ret = memcpy_s(nve_info.nv_data, DPA_NVE_MAX_SIZE, data, len);
    if(ret != EOK) {
        dpa_err("memcpy fail,err nun %d!\n",ret);
        return -1;
    }

    ret = nve_direct_access_interface(&nve_info);
    if (ret != 0) {
        dpa_err("dpa nve write fail!\n");
        return -1;
    }

    dpa_err("dpa nve write success!\n");
    return 0;
}

bool dpa_wan_path_switch_acpu(void)
{
    int ret;
    struct dpa_nve dpa_nve = {0};

    ret = dpa_read_nve((void *)&dpa_nve, sizeof(dpa_nve));
    if (ret != 0) {
        dpa_err("read nve read fail, default set data path to acpu!\n");
        return true;
    }

    if (!dpa_nve.modem_boot) {
        dpa_err("WAN set data path to acpu!\n");
        return true;
    }

    dpa_err("WAN set data path to dpa!\n");
    return false;
}
EXPORT_SYMBOL(dpa_wan_path_switch_acpu);

static boot_mode g_wlan_boot_mode = RUN_MODE_DPA;
static int __init early_parse_bootmode_cmdline(char *p)
{
    if (p == NULL) {
        dpa_err("arg is null.\n");
        return -EINVAL;
    }

    if (!strcmp(p, "1")) {
        g_wlan_boot_mode = RUN_MODE_ACPU;
    } 

    dpa_err("run mode is %s, g_wlan_boot_mode = %d\n", p, g_wlan_boot_mode);
    return 0;
}

early_param("enter_recovery", early_parse_bootmode_cmdline);

static bool wlan_path_switch_acpu(void)
{
    int ret;
    struct dpa_nve dpa_nve = {0};

    ret = dpa_read_nve((void *)&dpa_nve, sizeof(dpa_nve));
    if (ret != 0) {
        dpa_err("read nve read fail, default set data path to acpu!\n");
        return true;
    }

    if (!dpa_nve.wifi_boot) {
        dpa_err("WLAN set data path to acpu!\n");
        return true;
    }

    dpa_err("WLAN set data path to dpa!\n");
    return false;
}

bool dpa_wlan_path_switch_acpu(void)
{
    int ret;

    /* step1: dpa not support*/
    ret = dpa_get_status_ops();
    if (ret != 0 ) {
        return true;
    }

    /* step2: recover mode */
    if (g_wlan_boot_mode == RUN_MODE_ACPU) {
        dpa_err("recover mode,WLAN set data path to acpu!\n");
        return true;
    }

    /* step 3:  */
    return wlan_path_switch_acpu();
}
EXPORT_SYMBOL(dpa_wlan_path_switch_acpu);

static void dpa_default_path_switch(enum dpa_sms_nic nic, uint32_t value)
{
    int ret;
    struct dpa_nve nve;

    ret = dpa_read_nve((void *)&nve, sizeof(nve));
    if (ret != 0) {
        dpa_err("read nve read fail, switch dpa path fail!\n");
        return;
    }

    switch (nic) {
        case DPA_SMS_NIC_WAN:
            nve.modem_boot = value;
            ret = dpa_write_nve((void *)&nve, sizeof(nve));
            break;
        case DPA_SMS_NIC_WLAN:
            nve.wifi_boot = value;
            ret = dpa_write_nve((void *)&nve, sizeof(nve));
            break;
        default:
            nve.modem_boot = value;
            nve.wifi_boot = value;
            ret = dpa_write_nve((void *)&nve, sizeof(nve));
            break;
    }

    if (ret != 0) {
        dpa_err("write nve read fail, switch dpa path fail!\n");
    }

    return;
}

void dpa_wan_default_path_switch(uint32_t value)
{
    dpa_default_path_switch(DPA_SMS_NIC_WAN, value);
    return;
}
EXPORT_SYMBOL(dpa_wan_default_path_switch);

void dpa_wlan_default_path_switch(uint32_t value)
{
    dpa_default_path_switch(DPA_SMS_NIC_WLAN, value);
    return;
}
EXPORT_SYMBOL(dpa_wlan_default_path_switch);