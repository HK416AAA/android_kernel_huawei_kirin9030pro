/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2022-2023. All rights reserved.
 *
 * Description: MP12 gpio board-level implementation.
 * Author: platform drivers
 */

#include <linux/device.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include "oal_hcc_bus.h"
#include "plat_debug.h"
#include "plat_gpio.h"
#include "oal_ext_if.h"
#include "plat_pm.h"
#include "plat_exception_rst.h"
#include "chr_user.h"
#include "bfgx_core.h"
#include "plat_pm_wlan.h"
#include "plat_cust_mp12.h"
#include "plat_cust.h"

uint8_t g_mp12_gugong_stage = OAL_FALSE;
uint8_t g_mp12_enter_gugong_fac_status = OAL_FALSE;
uint8_t g_mp12_tas_ctrl = 0;
// 特性开关
typedef enum  {
    SW_OFF,
    SW_ON
} switch_t;

// 特性类型
typedef enum  {
    TYPE_SPDT,
    TYPE_PA,
    TYPE_RSMC,
    TYPE_CLK,
    TYPE_QUERY,
    TYPE_FAC,
    TYPE_W_POWER,
} feature_t;

struct gpio_gugong {
    char *dts_type;
    char *gpio_name;
    int32_t number;
    enum of_gpio_flags init_mode;
    int32_t inited;
};

uint8_t mp12_is_gugong_status(void)
{
    ps_print_info("gugong status is %d", g_mp12_gugong_stage);
    return g_mp12_gugong_stage;
}

STATIC int32_t gugong_rsmc_config(struct conn_gpio_userdata *data)
{
    plat_cust_data_mp12 *plat_cust = NULL;

    plat_cust = (plat_cust_data_mp12 *)get_plat_cust_addr();
    if (plat_cust == NULL) {
        ps_print_err("gugong get plat cust fail \n");
        return -OAL_FAIL;
    }

    if (data->sub_type == SW_OFF) {
        g_mp12_gugong_stage = OAL_FALSE;
    } else if (data->sub_type == SW_ON) {
        if ((board_subsys_is_shutdown(W_SYS) == OAL_TRUE) && (ps_core_single_subsys_active(BFGX_GNSS) == OAL_TRUE)) {
            g_mp12_gugong_stage = OAL_TRUE;
        } else {
            chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                                 CHR_PLT_DRV_EVENT_GUGONG, CHR_PLAT_DRV_ERROR_GUGONG_OPEN_CMD_FAIL);
            ps_print_err("wifi status[%u], bt status[%u] , don't allow enter gugong!\n",
                         (board_subsys_is_shutdown(W_SYS) == OAL_TRUE) ? OAL_FALSE : OAL_TRUE,
                         (ps_core_single_subsys_active(BFGX_GNSS) == OAL_TRUE) ? OAL_FALSE : OAL_TRUE);
            return -OAL_FAIL;
        }
    }
    plat_cust->cfg.enter_rsmc = (g_mp12_gugong_stage == OAL_FALSE) ? OAL_FALSE : OAL_TRUE;
    return OAL_SUCC;
}

STATIC void get_gugong_status_to_user(struct conn_gpio_userdata *data, uint8_t OAL_USER *userdata)
{
    ps_print_info("get gugong status %d\n", g_mp12_gugong_stage);
    data->sub_type = (g_mp12_gugong_stage == OAL_TRUE) ? OAL_TRUE : OAL_FALSE;
    if (copy_to_user(userdata, data, sizeof(struct conn_gpio_userdata))) {
        ps_print_err("copy_to_user is err!\n");
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_GUGONG, CHR_PLAT_DRV_ERROR_GUGONG_QUERY_STATUS_FAIL);
    }

    ps_core_show_bfgx_status();

    if (wlan_pm_is_poweron() == OAL_TRUE) {
        ps_print_info("wifi is open!");
    } else {
        ps_print_info("wifi is close!");
    }
}

STATIC void gugong_factory_config(uint32_t sub_type)
{
    plat_cust_data_mp12 *plat_cust = NULL;

    plat_cust = (plat_cust_data_mp12 *)get_plat_cust_addr();
    if (plat_cust == NULL) {
        ps_print_err("gugong get plat cust fail \n");
        return;
    }
    if (sub_type == SW_ON) {
        g_mp12_enter_gugong_fac_status = OAL_TRUE;
        plat_cust->cfg.gugong_fac_status = OAL_TRUE;
        ps_print_info("it is factory status\n");
    } else {
        g_mp12_enter_gugong_fac_status = OAL_FALSE;
        plat_cust->cfg.gugong_fac_status = OAL_FALSE;
        ps_print_info("it is not factory status\n");
    }
}

STATIC void gugong_status_reset(void)
{
    plat_cust_data_mp12 *plat_cust = NULL;

    plat_cust = (plat_cust_data_mp12 *)get_plat_cust_addr();
    if (plat_cust != NULL) {
        plat_cust->cfg.enter_rsmc = OAL_FALSE;
        plat_cust->cfg.gugong_fac_status = OAL_FALSE;
    }

    g_mp12_gugong_stage = OAL_FALSE;
    g_mp12_enter_gugong_fac_status = OAL_FALSE;
}

STATIC int32_t user_gpio_set(struct conn_gpio_userdata *data, uint8_t OAL_USER *userdata)
{
    struct pm_top* pm_top_data = pm_get_top();
    ps_print_info("gugong set gugong type main[%u] sub[%u]\n",
                  data->main_type, data->sub_type);

    if (data->main_type == TYPE_RSMC) {
        mutex_lock(&(pm_top_data->host_mutex));
        if (gugong_rsmc_config(data) != OAL_SUCC) {
            mutex_unlock(&(pm_top_data->host_mutex));
            return -OAL_FAIL;
        }
        mutex_unlock(&(pm_top_data->host_mutex));
    } else if (data->main_type == TYPE_QUERY) {
        get_gugong_status_to_user(data, userdata);
    } else if (data->main_type == TYPE_FAC) {
        gugong_factory_config(data->sub_type);
    }

    return OAL_SUCC;
}

STATIC int32_t mp12_gugong_check_subsys_power_on(uint32_t subsys)
{
    if (g_mp12_gugong_stage == OAL_TRUE) {
        // 产测模式, 在GNSS打开的情况下，重新开wifi
        if (g_mp12_enter_gugong_fac_status == OAL_TRUE && (ps_core_single_subsys_active(BFGX_GNSS) == OAL_TRUE) &&
            subsys == W_SYS) {
            ps_print_info("enter facotry mode\n");
            return OAL_SUCC;
        }

        ps_print_err("already into gugong, not support subsys[%u] power up\n", subsys);
        if (subsys == W_SYS) {
            chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                                 CHR_PLT_DRV_EVENT_GUGONG, CHR_PLAT_DRV_ERROR_GUGONG_WIFI_POWER_ON);
        }
        declare_dft_trace_key_info("gugong power exception", OAL_DFT_TRACE_EXCEP);
        plat_exception_handler(SUBSYS_BFGX, THREAD_GNSS, GUGONG_POWER_FAIL);
        return -OAL_FAIL;
    }

    if (g_mp12_enter_gugong_fac_status == OAL_TRUE) {
        ps_print_err("subsys[%u] open, but the status is gugong fac state!\n", subsys);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

int32_t mp12_gugong_subsys_power_on(uint32_t subsys)
{
    int32_t ret;

    ret = mp12_gugong_check_subsys_power_on(subsys);
    if (ret < 0) {
        gugong_status_reset();
    }

    return ret;
}

STATIC int32_t mp12_gugong_check_subsys_power_off(uint32_t subsys)
{
    ps_print_info("gugong stage %d, fac status %d\n", g_mp12_gugong_stage, g_mp12_enter_gugong_fac_status);

    if (g_mp12_gugong_stage == OAL_TRUE || g_mp12_enter_gugong_fac_status == OAL_TRUE) {
        ps_print_err("subsys[%u] should closed before gugong and gugong fac mode\n", subsys);
        declare_dft_trace_key_info("gugong power exception", OAL_DFT_TRACE_EXCEP);
        plat_exception_handler(SUBSYS_BFGX, THREAD_GNSS, GUGONG_POWER_FAIL);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

void mp12_gugong_subsys_power_off(uint32_t subsys)
{
    int32_t ret;

    ret = mp12_gugong_check_subsys_power_off(subsys);
    if (ret < 0) {
        gugong_status_reset();
    }
}

STATIC struct conn_gpio_node g_gpio_spec[] = {
    {
        .pin = {
            .name = PROC_NAME_GPIO_POWEN_ON,
            .is_key_gpio = OAL_TRUE,
            .type = CHIP_POWR,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS | MODE_PMU_IO,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_MPXX_POWEN_ON
                }
            },
        }
    },
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    {
        .pin = {
            .name = PROC_NAME_GPIO_WLAN_POWEN_ON,
            .is_key_gpio = OAL_TRUE,
            .type = W_POWER,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS | MODE_PMU_IO,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_WLAN_POWEN_ON_ENABLE
                }
            },
        }
    },
#endif
    {
        .pin = {
            .name = PROC_NAME_GPIO_BFGX_POWEN_ON,
            .is_key_gpio = OAL_TRUE,
            .type = BFGX_POWER,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS | MODE_PMU_IO,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_BFGX_POWEN_ON_ENABLE
                }
            },
        }
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_SSI_CLK,
            .is_key_gpio = OAL_FALSE,
            .type = SSI_CLK,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_MPXX_GPIO_SSI_CLK
                }
            },
        }
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_SSI_DATA,
            .is_key_gpio = OAL_FALSE,
            .type = SSI_DATA,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_MPXX_GPIO_SSI_DATA
                }
            },
        }
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_HOST_WAKEUP_WLAN,
            .is_key_gpio = OAL_TRUE,
            .type = HOST_WKUP_W,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_MPXX_WIFI,
                    .label_name = DTS_PROP_GPIO_HOST_WAKEUP_WLAN
                }
            },
        }
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_BFGX_WAKEUP_HOST,
            .is_key_gpio = OAL_TRUE,
            .type = BFGX_WKUP_HOST,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_IN
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_MPXX_BFGX,
                    .label_name = DTS_PROP_MPXX_GPIO_BFGX_WAKEUP_HOST
                }
            },
        },
        .irq = {
            .name = "bfgx_wake_host",
            .flags = IRQF_DISABLED | IRQF_TRIGGER_RISING | IRQF_NO_SUSPEND,
            .init_set_enable = OAL_FALSE
        },
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_WLAN_WAKEUP_HOST,
            .is_key_gpio = OAL_TRUE,
            .type = W_WKUP_HOST,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_IN
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_MPXX_WIFI,
                    .label_name = DTS_PROP_MPXX_GPIO_WLAN_WAKEUP_HOST
                }
            },
        },
        .irq = {
            .name = "wlan_wake_host",
            .flags = IRQF_DISABLED | IRQF_TRIGGER_RISING | IRQF_NO_SUSPEND,
            .init_set_enable = OAL_FALSE
        },
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_WLAN_FLOWCTRL,
            .is_key_gpio = OAL_FALSE,
            .type = SDIO_FLOW_CTRL,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_IN
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_MPXX_WIFI,
                    .label_name = DTS_PROP_GPIO_WLAN_FLOWCTRL,
                }
            },
        },
        .irq = {
            .name = "wifi_gpio_flowctrl_intr",
            .flags = IRQF_NO_SUSPEND | IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_DISABLED,
            .init_set_enable = OAL_FALSE,
        },
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_BFGX_IR_CTRL,
            .is_key_gpio = OAL_FALSE,
            .type = IR_CTRL,
            .init = {
                .req_sts = REQ_ONE,
                .flags = GPIOF_OUT_INIT_LOW
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_BFGX_IR_CTRL,
                }
            },
        }
    }
};

STATIC struct usr_gpio_ops g_usr_ops = {
    .user_set = user_gpio_set
};

STATIC struct conn_gpio_chip g_drv_gpio_chip = {
    .node = g_gpio_spec,
    .node_num = oal_array_size(g_gpio_spec),
    .usr_ops = &g_usr_ops
};

int32_t mp12_gpio_init(struct platform_device *pdev)
{
    int32_t ret;

    ret = conn_gpio_init(&g_drv_gpio_chip);
    if (ret < 0) {
        ps_print_err("mp12 gpio init fail\n");
        return ret;
    }
    return OAL_SUCC;
}

void mp12_gpio_remove(struct platform_device *pdev)
{
    conn_gpio_remove();
}
