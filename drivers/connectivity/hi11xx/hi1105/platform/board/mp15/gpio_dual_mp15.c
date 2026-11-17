/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * Description: Dual MP15 gpio board-level implementation
 * Author: platform drivers
 */

#ifdef _PRE_DUAL_CHIP

#include <linux/of_gpio.h>
#include "plat_debug.h"
#include "oal_hcc_bus.h"
#include "oal_ext_if.h"
#include "gpio_dual_mp15.h"

/* CHIP2_POWER */
#define DTS_PROP_GPIO_MPXX_POWEN_ON_CHIP2               "hi110x,gpio_power_on_chip2"
#define PROC_NAME_GPIO_POWEN_ON_CHIP2                   "power_on_enable_chip2"
/* W_POWER_CHIP2 */
#define DTS_PROP_GPIO_WLAN_POWEN_ON_ENABLE_CHIP2        "hi110x,gpio_wlan_power_on_chip2"
#define PROC_NAME_GPIO_WLAN_POWEN_ON_CHIP2              "wlan_power_on_enable_chip2"
/* W_WKUP_HOST_CHIP2 */
#define DTS_PROP_MPXX_GPIO_WLAN_WAKEUP_HOST_CHIP2       "hi110x,gpio_wlan_wakeup_host_chip2"
#define PROC_NAME_GPIO_WLAN_WAKEUP_HOST_CHIP2           "wlan_wake_host_chip2"
/* HOST_WKUP_W_CHIP2 */
#define DTS_PROP_GPIO_HOST_WAKEUP_WLAN_CHIP2            "hi110x,gpio_host_wakeup_wlan_chip2"
#define PROC_NAME_GPIO_HOST_WAKEUP_WLAN_CHIP2           "host_wakeup_wlan_chip2"

STATIC struct conn_gpio_node g_gpio_spec[] = {
    {
        .pin = {
            .name = PROC_NAME_GPIO_POWEN_ON,
#ifndef _PRE_WLAN_EXPORT
            .is_key_gpio = OAL_TRUE,
#else
            .is_key_gpio = OAL_FALSE,
#endif
            .type = CHIP_POWR,
            .init = {
                .req_sts = REQ_ONE,
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
            },
        },
        .attr = {
            .mode = MODE_DTS,
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
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
            },
        },
        .attr = {
            .mode = MODE_DTS,
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
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_BFGX_POWEN_ON_ENABLE
                }
            },
        },
    },
#ifndef _PRE_WLAN_EXPORT
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
#endif
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    {
        .pin = {
            .name = PROC_NAME_GPIO_HOST_WAKEUP_WLAN,
            .is_key_gpio = OAL_FALSE,
            .type = HOST_WKUP_W,
            .init = {
                .req_sts = REQ_ONE,
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
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
#endif
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
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
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
#if (KERNEL_VERSION(3, 10, 44) <= LINUX_VERSION_CODE)
            .flags = IRQF_NO_SUSPEND | IRQF_TRIGGER_RISING | IRQF_DISABLED,
#else
            .flags = IRQF_DISABLED | IRQF_TRIGGER_RISING,
#endif
            .init_set_enable = OAL_FALSE
        },
    },
#endif
    {
        .pin = {
            .name = PROC_NAME_GPIO_POWEN_ON_CHIP2,
            .is_key_gpio = OAL_FALSE,
            .type = CHIP_POWR_CHIP2,
            .init = {
                .req_sts = REQ_ONE,
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_MPXX_POWEN_ON_CHIP2
                }
            },
        }
    },
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    {
        .pin = {
            .name = PROC_NAME_GPIO_WLAN_POWEN_ON_CHIP2,
            .is_key_gpio = OAL_FALSE,
            .type = W_POWER_CHIP2,
            .init = {
                .req_sts = REQ_ONE,
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
            },
        },
        .attr = {
            .mode = MODE_DTS,
            .u = {
                .dts = {
                    .compatibale = DTS_NODE_HISI_MPXX,
                    .label_name = DTS_PROP_GPIO_WLAN_POWEN_ON_ENABLE_CHIP2
                }
            },
        }
    },
#endif
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    {
        .pin = {
            .name = PROC_NAME_GPIO_WLAN_WAKEUP_HOST_CHIP2,
            .is_key_gpio = OAL_FALSE,
            .type = W_WKUP_HOST_CHIP2,
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
                    .label_name = DTS_PROP_MPXX_GPIO_WLAN_WAKEUP_HOST_CHIP2
                }
            },
        },
        .irq = {
            .name = "wlan_wake_host_chip2",
#if (KERNEL_VERSION(3, 10, 44) <= LINUX_VERSION_CODE)
            .flags = IRQF_NO_SUSPEND | IRQF_TRIGGER_RISING | IRQF_DISABLED,
#else
            .flags = IRQF_DISABLED | IRQF_TRIGGER_RISING,
#endif
            .init_set_enable = OAL_FALSE
        },
    },
    {
        .pin = {
            .name = PROC_NAME_GPIO_HOST_WAKEUP_WLAN_CHIP2,
            .is_key_gpio = OAL_FALSE,
            .type = HOST_WKUP_W_CHIP2,
            .init = {
                .req_sts = REQ_ONE,
#ifdef _PRE_HI375X_PCIE
                .flags = GPIOF_OUT_INIT_HIGH
#else
                .flags = GPIOF_OUT_INIT_LOW
#endif
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
#endif
};

STATIC struct conn_gpio_chip g_drv_gpio_chip = {
    .node = g_gpio_spec,
    .node_num = oal_array_size(g_gpio_spec),
};

int32_t dual_mp15_gpio_init(struct platform_device *pdev)
{
    int32_t ret;

    ret = conn_gpio_init(&g_drv_gpio_chip);
    if (ret < 0) {
        ps_print_err("mp15 gpio init fail\n");
        return ret;
    }

    return OAL_SUCC;
}

void dual_mp15_gpio_remove(struct platform_device *pdev)
{
    conn_gpio_remove();
}

enum gpio_type conn_get_gpio_type_by_id(int32_t dev_id, enum gpio_type type)
{
    enum gpio_type new_type = type;
    if (dev_id != HCC_EP_WIFI_DEV1 && dev_id != HCC_EP_WIFI_DEV) {
        return GPIO_TYPE_BUFF;
    }

    switch (type) {
        case CHIP_POWR:
            new_type = dev_id == HCC_EP_WIFI_DEV1 ? (enum gpio_type)CHIP_POWR_CHIP2 : CHIP_POWR;
            break;
        case W_POWER:
            new_type = dev_id == HCC_EP_WIFI_DEV1 ? (enum gpio_type)W_POWER_CHIP2 : W_POWER;
            break;
        case HOST_WKUP_W:
            new_type = dev_id == HCC_EP_WIFI_DEV1 ? (enum gpio_type)HOST_WKUP_W_CHIP2 : HOST_WKUP_W;
            break;
        default:
            break;
    }
    return new_type;
}
#endif