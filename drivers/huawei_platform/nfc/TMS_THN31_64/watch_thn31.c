/*
 * Copyright (C) 2010 Trusted Logic S.A.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/spinlock.h>
#include <linux/reboot.h>
#include <linux/clk.h>
#include <linux/pm_wakeup.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/mtd/hisi_nve_interface.h>
#include <linux/timex.h>
#include <linux/kthread.h>
#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#endif
#include "watch_thn31.h"
#include "securec.h"
#include <platform_include/basicplatform/linux/mfd/pmic_platform.h>
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <huawei_platform/devdetect/hw_dev_dec.h>
#endif
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/nfc/nfc_interface.h>
#include "../nfc_watch_commu/nfc_watch_commu.h"

#define HWLOG_TAG nfc
HWLOG_REGIST();

#define RSSI_MAX 65535

#define PMU_CLK_NFC_EN_REG 0x42
#define PMU_CLK_LDO_MASK_REG 0xBF
#define PMU_CLK_SQUARE_OUTPUT_REG 0x401
#define PMU_CLK_SQUARE_DRIVER_REG 0xA7

#define NFC_DMD_PROBE_TIMER (10 * HZ) /* delay to probe dmd */

#define MAX_CHIP_LENGTH 8 /* The supported NFC chip types are listed as follows: */
#define NFC_CHIP_THN31 "thn31"
#define NFC_CHIP_ST "st21nfc"
#define NFC_CHIP_ST54K "st54k"
#define NFC_CHIP_PN553 "pn553"
#define NFC_CHIP_PN80T "pn80t"
#define NFC_CHIP_SN110U "sn110u"
#define NFC_CHIP_SZ "nfc_sz"
#define NFC_CHIP_BJ "nfc_bj"

#define NCI_HEADER 3
#define T1_HEAD 0x5A
#define I2C_ELAPSE_TIMEOUT (1500 * 1000 * 1000L)
#define MAX_I2C_WAKEUP_TIME 3
#define NFC_SEMAPHORE_TIME_OUT ((HZ / 2000) * 2000) /* HZ=2s  timeout 2s */

/* reset to bootloader */
#define T1_HDR_LEN 3
#define T1_PAYLOAD_LEN_BYTE 2
#define T1_LRC_LEN 1
#define MAX_NCI_PAYLOAD_LEN (255)
#define MAX_NCI_BUFFER_SIZE (NCI_HEADER + MAX_NCI_PAYLOAD_LEN)
#define MAX_T1_PAYLOAD_LEN (255)
#define MAX_T1_BUFFER_SIZE (T1_HDR_LEN + MAX_T1_PAYLOAD_LEN + T1_LRC_LEN)
#define RESET_TO_BL_MS 70
#define NCI_LEN_INDEX 2

#define DTS_COMP_ESS_CA_NAME "hisilicon,ese_ca"

static size_t last_count = 0;

enum NFC_CHIPTYPE {
    NFCTYPE_INVALID = 0,
    NFCTYPE_ST21NFC = 1, // st54h or st21
    NFCTYPE_NXP     = 2, // pn80t
    NFCTYPE_SN110   = 3,
    NFCTYPE_ST54K   = 4,
    NFCTYPE_THN31   = 5,
    NFCTYPE_PN553   = 6,
    MAX_CHIP_TYPE
};

typedef struct {
    const char* type_str;
    int type_value;
} chip_type_mask;

static struct ese_config_data g_ese_config_data = {0};
/*lint -save -e528 -e529*/
static bool ven_felica_status;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static struct wakeup_source *wlock_read;
#else
static struct wakeup_source wlock_read;
#endif
static int firmware_update;
static int nfc_switch_state;
static int nfc_at_result;
long tms_nfc_get_rssi = 0;
static char g_nfc_nxp_config_name[MAX_CONFIG_NAME_SIZE];
static unsigned char g_nfc_nxp_config_clock_switch = 0;
static char g_nfc_brcm_conf_name[MAX_CONFIG_NAME_SIZE];
static char g_nfc_chip_type[MAX_NFC_CHIP_TYPE_SIZE];
static char g_nfc_fw_version[MAX_NFC_FW_VERSION_SIZE];
static unsigned int g_nfc_ext_gpio; /* use extented gpio, eg.codec */
static int g_nfc_svdd_sw; /* use for svdd switch */
static int g_nfc_on_type; /* nfc ven controlled by which type of gpio: gpio/hisi_pmic/regulator_bulk */
/* 0 -- hisi cpu(default); 1 -- hisi pmu */
static int g_nfc_clk_src = NFC_CLK_SRC_CPU;
static int g_nfcservice_lock;
/* 0 -- close nfcservice normally; 1 -- close nfcservice with enable CE */
static int g_nfc_close_type;
static int g_nfc_open_status = NFC_CLOSE_STATUS;
static int g_nfc_need_reset = NFC_NONEED_RESET;

static int g_nfc_single_channel;
static int g_nfc_spec_rf;
static int g_nfc_delaytime_set;
static int g_nfc_delaytime_node;
static int g_nfc_card_num;
static int g_nfc_ese_num;
static int g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_DISABLE;
static int g_nfc_ese_type = NFC_WITHOUT_ESE; /* record ese type wired to nfcc by dts */
static int g_nfc_activated_se_info; /* record activated se info when nfc enable process */
static int g_nfc_hal_dmd_no; /* record last hal dmd no */
static int g_nfc_sim2_omapi;
static t_pmu_reg_control nfc_on_hi6421v600 = {0x240, 0};
static t_pmu_reg_control nfc_on_hi6421v500 = {0x0C3, 4};
static t_pmu_reg_control nfc_on_hi6555v110 = {0x158, 0};
static t_pmu_reg_control nfc_on_hi6421v700 = {0x2E6, 0};
static t_pmu_reg_control nfc_on_hi6421v800 = {0x2E6, 0};
static t_pmu_reg_control nfc_on_hi6421v900 = {0x40C, 0};
static t_pmu_reg_control nfc_on_hi6555v300 = {0x22D, 0};
static t_pmu_reg_control nfc_on_hi6555v500 = {0x2E5, 0};
static bool g_is_gtboost = false;
static int g_chip_type = NFCTYPE_INVALID;
static bool g_is_uid = false;
static bool g_xbjt_uid = false;
static struct timer_list nfc_dmd_probe_timer;

/*lint -save -e* */
struct thn31_dev {
    wait_queue_head_t read_wq;
    struct mutex read_mutex;
    struct i2c_client *client;
    struct miscdevice thn31_device;
    struct pinctrl *pctrl;
    struct pinctrl_state *pins_idle;
    unsigned int firm_gpio;
    unsigned int irq_gpio;
    int sim_switch;
    int sim_status;
    int enable_status;
    bool irq_enabled;
    spinlock_t irq_enabled_lock;
    struct mutex irq_mutex_lock;
    unsigned int ven_gpio;
    struct regulator_bulk_data ven_felica;
    struct clk *nfc_clk;
    bool release_read;
    struct mutex ese_recover_mutex_lock;
    struct mutex ese_switch_mutex_lock;
    struct platform_device *pdev;

    int irq;

};
/*lint -restore*/
static struct thn31_dev *nfcdev;
static ktime_t g_pre_write_time;

struct semaphore nfc_read_data_sem;

#ifdef CONFIG_HUAWEI_DSM
static struct dsm_dev dsm_nfc = {
    .name = "dsm_nfc",
    .device_name = NULL,
    .ic_name = NULL,
    .module_name = NULL,
    .fops = NULL,
    .buff_size = 1024,
};

static struct dsm_client *nfc_dclient = NULL;

#endif

/*lint -save -e* */
void tms_realse_read(void)
{
    hwlog_info("tms_realse_read\n");
    wake_up(&nfcdev->read_wq);
}
EXPORT_SYMBOL(tms_realse_read);

static void nfc_is_recovery_mode(void)
{
    if (strstr(saved_command_line, "rescue_mode=true")) {
        hwlog_info("%s: enter rescure mode %d\n", __func__, nfc_at_result);
        nfc_at_result = RECOVERY_MODE;
        return;
    }
    hwlog_info("%s: else nfc_at_result = %d\n", __func__, nfc_at_result);
    nfc_at_result = NORMAL_MODE;
    return;
}

static int nfc_nv_opera(unsigned int opr, unsigned int idx, const char *name, unsigned int len, void *data)
{
    int err;
    int ret;
    struct hisi_nve_info_user user_info;
     hwlog_info("%s:enter.\n", __func__);

    memset_s(&user_info, sizeof(user_info), 0x00, sizeof(user_info));
    user_info.nv_operation = opr;
    user_info.nv_number = idx;
    user_info.valid_size = len;

    err = strncpy_s(user_info.nv_name, sizeof(user_info.nv_name),
        name, sizeof(user_info.nv_name));
    if (err != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    user_info.nv_name[sizeof(user_info.nv_name) - 1] = '\0';

    /* write data to nv */
    if (opr == NV_WRITE) {
        if (len > sizeof(user_info.nv_data))
            len = sizeof(user_info.nv_data);
        err = memcpy_s((char *)user_info.nv_data, len, (char *)data, len);
        if (err != EOK)
            hwlog_err("%s memcpy_s fail\n", __func__);
    }

    ret = hisi_nve_direct_access(&user_info);
    if (ret != 0) {
        hwlog_err("%s:nve_direct_access read error %d\n", __func__, ret);
        return -1;
    }
    err = memcpy_s((char *)data, len, (char *)user_info.nv_data, len);
    if (err != EOK)
        hwlog_err("%s memcpy_s fail\n", __func__);
    return 0;
}

static unsigned int clr_pmu_reg_bit(unsigned int ret, int bit_pos)
{
    ret = ret & (~(1<<(bit_pos)));
    return ret;
}

static unsigned int set_pmu_reg_bit(unsigned int ret, int bit_pos)
{
    ret = ret | (1<<(bit_pos));
    return ret;
}

/*lint -restore*/
/*lint -save -e* */
static int hisi_pmu_reg_operate_by_bit(int reg_addr, int bit_pos, int op)
{
    unsigned int ret = 0;
    if (reg_addr <= 0 || bit_pos < 0 || op < 0) {
        hwlog_err("%s: reg_addr[%x], bit_pos[%d], op[%d], error!\n", __func__, reg_addr, bit_pos, op);
        return -1;
    }
    ret = pmic_read_reg(reg_addr);
    if (op == CLR_BIT) {
        ret = clr_pmu_reg_bit(ret, bit_pos);
    } else {
        ret = set_pmu_reg_bit(ret, bit_pos);
    }
    pmic_write_reg(reg_addr, ret);
    hwlog_info("%s: reg: 0x%x, pos: %d, value: 0x%x\n", __func__, reg_addr, bit_pos, ret);
    return 0;
}

static int get_hisi_pmic_reg_status(int reg_addr, int bit_pos)
{
    unsigned int ret = 0;
    if (reg_addr <= 0 || bit_pos < 0 || bit_pos > 31) {
        hwlog_err("%s: reg_addr[%x], bit_pos[%d], error!\n", __func__, reg_addr, bit_pos);
        return -1;
    }
    ret = pmic_read_reg(reg_addr);

    ret = (ret >> bit_pos) & 0x01;

    hwlog_info("%s: reg: 0x%x, pos: %d, value: 0x%x\n", __func__, reg_addr, bit_pos, ret);
    return (int)ret;
}

static int hisi_pmic_on(void)
{
    int ret = -1;
    if (g_nfc_on_type == NFC_ON_BY_HI6421V600_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v600.addr, nfc_on_hi6421v600.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HISI_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v500.addr, nfc_on_hi6421v500.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6555V110_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v110.addr, nfc_on_hi6555v110.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6421V700_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v700.addr, nfc_on_hi6421v700.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6421V800_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v800.addr, nfc_on_hi6421v800.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6421V900_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v900.addr, nfc_on_hi6421v900.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6555V300_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v300.addr, nfc_on_hi6555v300.pos, SET_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6555V500_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v500.addr, nfc_on_hi6555v500.pos, SET_BIT);
    } else {
        hwlog_err("%s: bad g_nfc_on_type: %d\n", __func__, g_nfc_on_type);
    }
    return ret;
}

static int hisi_pmic_off(void)
{
    int ret = -1;
    if (g_nfc_on_type == NFC_ON_BY_HI6421V600_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v600.addr, nfc_on_hi6421v600.pos, CLR_BIT);
    }  else if (g_nfc_on_type == NFC_ON_BY_HISI_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v500.addr, nfc_on_hi6421v500.pos, CLR_BIT);
    }  else if (g_nfc_on_type == NFC_ON_BY_HI6555V110_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v110.addr, nfc_on_hi6555v110.pos, CLR_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6421V700_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v700.addr, nfc_on_hi6421v700.pos, CLR_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6421V800_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v800.addr, nfc_on_hi6421v800.pos, CLR_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6421V900_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v900.addr, nfc_on_hi6421v900.pos, CLR_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6555V300_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v300.addr, nfc_on_hi6555v300.pos, CLR_BIT);
    } else if (g_nfc_on_type == NFC_ON_BY_HI6555V500_PMIC) {
        ret = hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v500.addr, nfc_on_hi6555v500.pos, CLR_BIT);
    } else {
        hwlog_err("%s: bad g_nfc_on_type: %d\n", __func__, g_nfc_on_type);
    }
    return ret;
}

static void pmu0_svdd_sel_on(void)
{
    hwlog_info("%s: in g_nfc_svdd_sw: %d\n", __func__, g_nfc_svdd_sw);
    if (g_nfc_svdd_sw == NFC_SWP_SW_HI6421V600) {
        hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v600.addr, nfc_on_hi6421v600.pos, SET_BIT);
    } else if (g_nfc_svdd_sw == NFC_SWP_SW_HI6421V500) {
        hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v500.addr, nfc_on_hi6421v500.pos, SET_BIT);
    } else if (g_nfc_svdd_sw == NFC_SWP_SW_HI6555V110) {
        hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v110.addr, nfc_on_hi6555v110.pos, SET_BIT);
    } else {
        hwlog_info("%s: pmu gpio don't connect to switch\n", __func__);
    }
}

static void pmu0_svdd_sel_off(void)
{
    hwlog_info("%s: in g_nfc_svdd_sw: %d\n", __func__, g_nfc_svdd_sw);
    if (g_nfc_svdd_sw == NFC_SWP_SW_HI6421V600) {
        hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v600.addr, nfc_on_hi6421v600.pos, CLR_BIT);
    } else if (g_nfc_svdd_sw == NFC_SWP_SW_HI6421V500) {
        hisi_pmu_reg_operate_by_bit(nfc_on_hi6421v500.addr, nfc_on_hi6421v500.pos, CLR_BIT);
    } else if (g_nfc_svdd_sw == NFC_SWP_SW_HI6555V110) {
        hisi_pmu_reg_operate_by_bit(nfc_on_hi6555v110.addr, nfc_on_hi6555v110.pos, CLR_BIT);
    } else {
        hwlog_info("%s: pmu gpio don't connect to switch\n", __func__);
    }
}

static int get_pmu0_svdd_sel_status(void)
{
    int ret = -1;
    hwlog_info("%s: in g_nfc_svdd_sw: %d\n", __func__, g_nfc_svdd_sw);
    if (g_nfc_svdd_sw == NFC_SWP_SW_HI6421V600) {
        ret = get_hisi_pmic_reg_status(nfc_on_hi6421v600.addr, nfc_on_hi6421v600.pos);
    } else if (g_nfc_svdd_sw == NFC_SWP_SW_HI6421V500) {
        ret = get_hisi_pmic_reg_status(nfc_on_hi6421v500.addr, nfc_on_hi6421v500.pos);
    } else if (g_nfc_svdd_sw == NFC_SWP_SW_HI6555V110) {
        ret = get_hisi_pmic_reg_status(nfc_on_hi6555v110.addr, nfc_on_hi6555v110.pos);
    } else {
        hwlog_info("%s: pmu gpio don't connect to switch\n", __func__);
    }
    return ret;
}

static int nfc_get_dts_config_string(const char *node_name,
                const char *prop_name,
                char *out_string,
                int out_string_len)
{
    struct device_node *np = NULL;
    const char *out_value;
    int ret = -1;

    for_each_node_with_property(np, node_name) {
        ret = of_property_read_string(np, prop_name, (const char **)&out_value);
        if (ret != 0) {
            hwlog_err("%s: can not get prop values with prop_name: %s\n",
                            __func__, prop_name);
        } else {
            if (out_value == NULL) {
                hwlog_info("%s: error out_value = NULL\n", __func__);
                ret = -1;
            } else if (strlen(out_value) >= out_string_len) {
                hwlog_info("%s: error out_value len :%d >= out_string_len:%d\n",
                    __func__, (int)strlen(out_value), (int)out_string_len);
                ret = -1;
            } else {
                errno_t rc = strcpy_s(out_string, out_string_len, out_value);
                if (rc != EOK)
                    hwlog_err("%s: strncpy_s fail\n", __func__);
                hwlog_info("%s: =%s\n", __func__, out_string);
            }
        }
    }
    return ret;
}

static int nfc_get_dts_config_u32(const char *node_name, const char *prop_name, u32 *pvalue)
{
    struct device_node *np = NULL;
    int ret = -1;

    for_each_node_with_property(np, node_name) {
        ret = of_property_read_u32(np, prop_name, pvalue);
        if (ret != 0) {
            hwlog_err("%s: can not get prop values with prop_name: %s\n", __func__, prop_name);
        } else {
            hwlog_info("%s: %s=%d\n", __func__, prop_name, *pvalue);
        }
    }
    return ret;
}
/*lint -restore*/
/*
 * g_nfc_ext_gpio bit 0: 1 -- dload use extented gpio, 0 -- dload use soc gpio
 * g_nfc_ext_gpio bit 1: 1 -- irq use extented gpio, 0 -- irq use soc gpio
 */
 /*lint -save -e* */
static void get_ext_gpio_type(void)
{
    int ret = -1;

    ret = nfc_get_dts_config_u32("nfc_ext_gpio", "nfc_ext_gpio", &g_nfc_ext_gpio);
    if (ret != 0) {
        g_nfc_ext_gpio = 0;
        hwlog_err("%s: can't check_ext_gpio\n", __func__);
    }
    hwlog_info("%s: g_nfc_ext_gpio:%d\n", __func__, g_nfc_ext_gpio);
    return;
}

static void nfc_gpio_set_value(unsigned int gpio, int val)
{
    if (g_nfc_ext_gpio & DLOAD_EXTENTED_GPIO_MASK) {
        hwlog_info("%s: gpio_set_value_cansleep\n", __func__);
        gpio_set_value_cansleep(gpio, val);
    } else {
        hwlog_info("%s: gpio_set_value\n", __func__);
        gpio_set_value(gpio, val);
    }
}
/*lint -restore*/
static int nfc_gpio_get_value(unsigned int gpio)
{
    int ret = -1;

    if (g_nfc_ext_gpio & IRQ_EXTENTED_GPIO_MASK) {
        ret = gpio_get_value_cansleep(gpio);
    } else {
        ret = gpio_get_value(gpio);
    }
    return ret;
}
/*lint -save -e* */
static void get_wake_lock_timeout(void)
{
    char wake_lock_str[MAX_WAKE_LOCK_TIMEOUT_SIZE] = {0};
    int ret = -1;

    memset_s(wake_lock_str, sizeof(wake_lock_str), 0x00, MAX_WAKE_LOCK_TIMEOUT_SIZE);
    ret = nfc_get_dts_config_string("wake_lock_timeout", "wake_lock_timeout",
    wake_lock_str, sizeof(wake_lock_str));
    if (ret != 0) {
        memset_s(wake_lock_str, sizeof(wake_lock_str), 0x00, MAX_WAKE_LOCK_TIMEOUT_SIZE);
        g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_DISABLE;
        hwlog_err("%s: can't find wake_lock_timeout\n", __func__);
        return;
    } else {
        if (!strncasecmp(wake_lock_str, "ok", strlen("ok"))) {
            g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_ENALBE;
        } else {
            g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_DISABLE;
        }
    }
    hwlog_info("%s: g_wake_lock_timeout:%d\n", __func__, g_wake_lock_timeout);
    return;
}

static void get_nfc_on_type(void)
{
    char nfc_on_str[MAX_DETECT_SE_SIZE] = {0};
    int ret = -1;

    memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_SE_SIZE);
    ret = nfc_get_dts_config_string("nfc_on_type", "nfc_on_type",
    nfc_on_str, sizeof(nfc_on_str));
    if (ret != 0) {
        memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_SE_SIZE);
        g_nfc_on_type = NFC_ON_BY_REGULATOR_BULK;
        hwlog_err("%s: can't check_ext_gpio\n", __func__);
        return;
    } else {
        if (!strncasecmp(nfc_on_str, "gpio", strlen("gpio"))) {
            g_nfc_on_type = NFC_ON_BY_GPIO;
        } else if (!strncasecmp(nfc_on_str, "hisi_pmic", strlen("hisi_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HISI_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6421v600_pmic", strlen("hi6421v600_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6421V600_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6421v700_pmic", strlen("hi6421v700_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6421V700_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6421v800_pmic", strlen("hi6421v800_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6421V800_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6421v900_pmic", strlen("hi6421v900_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6421V900_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6555v300_pmic", strlen("hi6555v300_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6555V300_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6555v500_pmic", strlen("hi6555v500_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6555V500_PMIC;
        } else if (!strncasecmp(nfc_on_str, "hi6555v110_pmic", strlen("hi6555v110_pmic"))) {
            g_nfc_on_type = NFC_ON_BY_HI6555V110_PMIC;
        } else if (!strncasecmp(nfc_on_str, "regulator_bulk", strlen("regulator_bulk"))) {
            g_nfc_on_type = NFC_ON_BY_REGULATOR_BULK;
        } else {
            g_nfc_on_type = NFC_ON_BY_GPIO;
        }
    }
    hwlog_info("%s: g_nfc_on_type:%d\n", __func__, g_nfc_on_type);
    return;
}
static void get_nfc_chip_type(void)
{
    char nfc_on_str[MAX_DETECT_SE_SIZE] = {0};
    int ret, cnt;
    chip_type_mask chip_type[MAX_CHIP_LENGTH] = {
        {NFC_CHIP_ST, NFCTYPE_ST21NFC},
        {NFC_CHIP_THN31, NFCTYPE_THN31},
        {NFC_CHIP_ST54K, NFCTYPE_ST54K},
        {NFC_CHIP_PN553, NFCTYPE_PN553},
        {NFC_CHIP_PN80T, NFCTYPE_NXP},
        {NFC_CHIP_SN110U, NFCTYPE_SN110},
        {NFC_CHIP_SZ, NFCTYPE_SN110},
        {NFC_CHIP_BJ, NFCTYPE_THN31},
    };

    memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_SE_SIZE);
    ret = nfc_get_dts_config_string("nfc_chip_type", "nfc_chip_type",
                    nfc_on_str, sizeof(nfc_on_str));
    if (ret != 0) {
        memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_SE_SIZE);
        hwlog_err("%s: can't find nfc_chip_type node\n", __func__);
        return;
    }
    for (cnt = 0; cnt < MAX_CHIP_LENGTH; cnt++) {
        if (chip_type[cnt].type_str == NULL) {
            continue;
        }
        if (!strncasecmp(nfc_on_str, chip_type[cnt].type_str, MAX_DETECT_SE_SIZE)) {
            g_chip_type = chip_type[cnt].type_value;
            break;
        }
    }
    hwlog_info("%s: nfc_chip_type:%d\n", __func__, g_chip_type);
    return;
}
static void get_nfc_wired_ese_type(void)
{
    char nfc_on_str[MAX_DETECT_SE_SIZE] = {0};
    int ret = -1;

    memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_SE_SIZE);
    ret = nfc_get_dts_config_string("nfc_ese_type", "nfc_ese_type",
    nfc_on_str, sizeof(nfc_on_str));
    if (ret != 0) {
        memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_SE_SIZE);
        g_nfc_ese_type = NFC_WITHOUT_ESE;
        hwlog_err("%s: can't find nfc_ese_type node\n", __func__);
        return;
    } else {
        if (!strncasecmp(nfc_on_str, "hisee", strlen("hisee"))) {
            g_nfc_ese_type = NFC_ESE_HISEE;
        } else if (!strncasecmp(nfc_on_str, "p61", strlen("p61"))) {
            g_nfc_ese_type = NFC_ESE_P61;
        } else {
            g_nfc_ese_type = NFC_WITHOUT_ESE;
        }
    }
    hwlog_info("%s: g_nfc_ese_type:%d\n", __func__, g_nfc_ese_type);
    return;
}

static void get_nfc_gt_boost(void)
{
    char nfc_on_str[MAX_DETECT_GT_SIZE] = {0};
    int boost_ret = -1;
    int ret;

    memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_GT_SIZE);
    ret = nfc_get_dts_config_string("nfc_gt_boost", "nfc_gt_boost",
        nfc_on_str, sizeof(nfc_on_str));
    if (ret != 0) {
        memset_s(nfc_on_str, sizeof(nfc_on_str), 0x00, MAX_DETECT_GT_SIZE);
        hwlog_info("%s: gt boost not supported on this board, ret = %d\n",
            __func__, ret);
        return;
    } else {
        hwlog_info("%s: enabling 5v, and setting g_is_gtboost = true\n",
            __func__);
        g_is_gtboost = true;
        boost_ret  = boost_5v_enable(BOOST_5V_ENABLE, BOOST_CTRL_NFC);
        if (boost_ret)
            hwlog_err("%s: boost_5v enable failed\n", __func__);
        else
            hwlog_info("%s: boost_5v enable succeeded\n", __func__);

        /* delay 10ms for volt stability */
        usleep_range(9500, 10500);
    }
    return;
}

static void get_nfc_svdd_sw(void)
{
    char nfc_svdd_sw_str[MAX_DETECT_SE_SIZE] = {0};
    int ret = -1;

    memset_s(nfc_svdd_sw_str, sizeof(nfc_svdd_sw_str), 0x00, MAX_DETECT_SE_SIZE);
    ret = nfc_get_dts_config_string("nfc_svdd_sw", "nfc_svdd_sw",
        nfc_svdd_sw_str, sizeof(nfc_svdd_sw_str));
    if (ret != 0) {
        memset_s(nfc_svdd_sw_str, sizeof(nfc_svdd_sw_str), 0x00, MAX_DETECT_SE_SIZE);
        g_nfc_svdd_sw = NFC_SWP_WITHOUT_SW;
        hwlog_err("%s: can't get_nfc_svdd_sw\n", __func__);
    } else {
        if (!strncasecmp(nfc_svdd_sw_str, "hi6421v600_pmic", strlen("hi6421v600_pmic"))) {
            g_nfc_svdd_sw = NFC_SWP_SW_HI6421V600;
        } else if (!strncasecmp(nfc_svdd_sw_str, "hi6421v500_pmic", strlen("hi6421v500_pmic"))) {
            g_nfc_svdd_sw = NFC_SWP_SW_HI6421V500;
        } else if (!strncasecmp(nfc_svdd_sw_str, "hi6555v110_pmic", strlen("hi6555v110_pmic"))) {
            g_nfc_svdd_sw = NFC_SWP_SW_HI6555V110;
        } else {
            g_nfc_svdd_sw = NFC_SWP_WITHOUT_SW;
        }
    }
    hwlog_info("%s: g_nfc_svdd_sw:%d\n", __func__, g_nfc_svdd_sw);
    return;
}

static void get_nfc_pmu_clock_switch(void)
{
    int ret;
    int clock_switch = 0;
    const int noah_pmu_switch = 1;

    ret = nfc_get_dts_config_u32("nfc_pmu_clock_switch", "nfc_pmu_clock_switch", &clock_switch);
    if (ret != 0) {
        g_nfc_nxp_config_clock_switch = 0;
        hwlog_info("%s: has no nfc PMU clock switch config!\n", __func__);
    } else if (clock_switch == noah_pmu_switch) {
        // for Noah pmu switch
        g_nfc_nxp_config_clock_switch = 1;
        // Configuring Square Wave Output
        pmic_write_reg(PMU_CLK_SQUARE_OUTPUT_REG, 0);
        pmic_write_reg(PMU_CLK_SQUARE_DRIVER_REG, 1);
        hwlog_info("%s: Set PMU clock to square wave!\n", __func__);
    }
    return;
}

/*lint -restore*/
/*lint -save -e* */
void tms_set_nfc_nxp_config_name(void)
{
    int ret = -1;

    memset_s(g_nfc_nxp_config_name, sizeof(g_nfc_nxp_config_name), 0x00, MAX_CONFIG_NAME_SIZE);
    ret = nfc_get_dts_config_string("nfc_nxp_name", "nfc_nxp_name",
                    g_nfc_nxp_config_name, sizeof(g_nfc_nxp_config_name));
    if (ret != 0) {
        memset_s(g_nfc_nxp_config_name, sizeof(g_nfc_nxp_config_name), 0x00, MAX_CONFIG_NAME_SIZE);
        hwlog_err("%s: can't get nfc nxp config name\n", __func__);
        return;
    }
    hwlog_info("%s: nfc nxp config name:%s\n", __func__, g_nfc_nxp_config_name);
    return;
}

static int get_nfc_chip_gpio_ven(void)
{
    int nfc_chip_gpio_ven = -1;
    if (nfc_get_dts_config_u32("nfc_chip_gpio_ven", "nfc_chip_gpio_ven", &nfc_chip_gpio_ven) != 0) {
        hwlog_err("%s: has no chip gpio ven!\n", __func__);
        return -1;
    }
    hwlog_info("%s: nfc_chip_gpio_ven: %d\n", __func__, nfc_chip_gpio_ven);
    return nfc_chip_gpio_ven;
}

void tms_set_nfc_brcm_config_name(void)
{
    int ret = -1;

    memset_s(g_nfc_brcm_conf_name, sizeof(g_nfc_brcm_conf_name), 0x00, MAX_CONFIG_NAME_SIZE);
    ret = nfc_get_dts_config_string("nfc_brcm_conf_name", "nfc_brcm_conf_name",
                    g_nfc_brcm_conf_name, sizeof(g_nfc_brcm_conf_name));
    if (ret != 0) {
        memset_s(g_nfc_brcm_conf_name, sizeof(g_nfc_brcm_conf_name), 0x00, MAX_CONFIG_NAME_SIZE);
        hwlog_err("%s: can't get nfc brcm config name\n", __func__);
        return;
    }
    hwlog_info("%s: nfc brcm config name:%s\n", __func__, g_nfc_brcm_conf_name);
    return;
}

void tms_set_nfc_single_channel(void)
{
    int ret = -1;
    char single_channel_dts_str[MAX_CONFIG_NAME_SIZE] = {0};

    memset_s(single_channel_dts_str, sizeof(single_channel_dts_str), 0x00, MAX_CONFIG_NAME_SIZE);
    ret = nfc_get_dts_config_string("nfc_single_channel", "nfc_single_channel",
        single_channel_dts_str, sizeof(single_channel_dts_str));
    if (ret != 0) {
        memset_s(single_channel_dts_str, sizeof(single_channel_dts_str), 0x00, MAX_CONFIG_NAME_SIZE);
        hwlog_err("%s: can't get nfc single channel dts config\n", __func__);
        g_nfc_single_channel = 0;
        return;
    }
    if (!strcasecmp(single_channel_dts_str, "true"))
        g_nfc_single_channel = 1;
    hwlog_info("%s: nfc single channel:%d\n", __func__, g_nfc_single_channel);
    return;
}

void tms_set_nfc_spec_rf(void)
{
    int ret;
    char spec_rf_dts_str[MAX_CONFIG_NAME_SIZE] = {0};

    memset_s(spec_rf_dts_str, sizeof(spec_rf_dts_str), 0x00, MAX_CONFIG_NAME_SIZE);
    ret = nfc_get_dts_config_string("nfc_spec_rf", "nfc_spec_rf",
        spec_rf_dts_str, sizeof(spec_rf_dts_str));
    if (ret != 0) {
        memset_s(spec_rf_dts_str, sizeof(spec_rf_dts_str), 0x00, MAX_CONFIG_NAME_SIZE);
        hwlog_err("%s: can't get nfc spec rf dts config\n", __func__);
        g_nfc_spec_rf = 0;    // special rf config flag 0:normal
        return;
    }
    if (!strcasecmp(spec_rf_dts_str, "true"))
        g_nfc_spec_rf = 1;    // special rf config flag 1:special

    hwlog_info("%s: nfc spec rf:%d\n", __func__, g_nfc_spec_rf);
    return;
}

void tms_get_nfc_delaytime_set(void)
{
    int ret;
    char delaytime_set_dts_str[MAX_CONFIG_NAME_SIZE];

    memset_s(delaytime_set_dts_str, sizeof(delaytime_set_dts_str), 0x00, MAX_CONFIG_NAME_SIZE);
    ret = nfc_get_dts_config_string("nfc_delaytime_set", "nfc_delaytime_set",
        delaytime_set_dts_str, sizeof(delaytime_set_dts_str));
    if (ret != 0) {
        memset_s(delaytime_set_dts_str, sizeof(delaytime_set_dts_str), 0x00, MAX_CONFIG_NAME_SIZE);
        hwlog_err("%s: can't get nfc delaytime set dts config\n", __func__);
        g_nfc_delaytime_set = 0;
        return;
    }
    if (!strcasecmp(delaytime_set_dts_str, "true"))
        g_nfc_delaytime_set = 1;

    hwlog_info("%s: nfc delaytime set:%d\n", __func__, g_nfc_delaytime_set);
    return;
}

void tms_get_nfc_delaytime_node(void)
{
    int ret;

    ret = nfc_get_dts_config_u32("nfc_delaytime_node", "nfc_delaytime_node", &g_nfc_delaytime_node);
    if (ret != 0) {
        g_nfc_delaytime_node = 0;
        hwlog_err("%s: can't get nfc delaytime set dts config!\n", __func__);
    }
    hwlog_info("%s: nfc delaytime node:%d\n", __func__, g_nfc_delaytime_node);

    return;
}

void tms_set_nfc_chip_type_name(void)
{
    int ret = -1;

    memset_s(g_nfc_chip_type, sizeof(g_nfc_chip_type), 0x00, MAX_NFC_CHIP_TYPE_SIZE);
    ret = nfc_get_dts_config_string("nfc_chip_type", "nfc_chip_type",
        g_nfc_chip_type, sizeof(g_nfc_chip_type));
    if (ret != 0) {
        memset_s(g_nfc_chip_type, sizeof(g_nfc_chip_type), 0x00, MAX_NFC_CHIP_TYPE_SIZE);
        hwlog_err("%s: can't get nfc nfc_chip_type, default pn547\n", __func__);
        ret = strcpy_s(g_nfc_chip_type, strlen("pn547") + 1, "pn547");
        if (ret != EOK)
            hwlog_err("strcpy_s err %x\n", ret);
    }

    hwlog_info("%s: nfc chip type name:%s\n", __func__, g_nfc_chip_type);

    return;
}

void tms_set_nfc_card_num(void)
{
    int ret = -1;

    ret = nfc_get_dts_config_u32("nfc_card_num", "nfc_card_num", &g_nfc_card_num);
    if (ret != 0) {
        g_nfc_card_num = 1;
        hwlog_err("%s: can't get nfc card num config!\n", __func__);
    }
    return;
}

void tms_set_nfc_ese_num(void)
{
    int ret = -1;

    ret = nfc_get_dts_config_u32("nfc_ese_num", "nfc_ese_num", &g_nfc_ese_num);
    if (ret != 0) {
        g_nfc_ese_num = 1;
        hwlog_err("%s: can't get nfc ese num config!\n", __func__);
    }

    return;
}

void tms_set_nfc_sim2_omapi(void)
{
    int ret = -1;
    char nfc_sim2_omapi_dts_str[MAX_CONFIG_NAME_SIZE] = {0};
    ret = nfc_get_dts_config_string("nfc_sim2_omapi", "nfc_sim2_omapi",
            nfc_sim2_omapi_dts_str, sizeof(nfc_sim2_omapi_dts_str));
    if (ret != 0) {
        g_nfc_sim2_omapi = 0;
        hwlog_err("%s: can't get nfc sim2 omapi config!\n", __func__);
        return;
    }
    if (!strcasecmp(nfc_sim2_omapi_dts_str, "true"))
        g_nfc_sim2_omapi = 1;
    hwlog_info("%s: nfc sim2 omapi:%d\n", __func__, g_nfc_sim2_omapi);
}

static int thn31_bulk_enable(struct  thn31_dev *pdev)
{
    int ret = 0;

    switch (g_nfc_on_type) {
    case NFC_ON_BY_GPIO:
        hwlog_info("%s: Nfc on by GPIO !\n", __func__);
        gpio_set_value(pdev->ven_gpio, 1);
        break;

    case NFC_ON_BY_REGULATOR_BULK:
        hwlog_info("%s: Nfc on by REGULATOR !\n", __func__);
        if (false == ven_felica_status) {
            ret = regulator_bulk_enable(1, &(pdev->ven_felica));
            if (ret < 0) {
                hwlog_err("%s: regulator_enable failed, ret:%d\n", __func__, ret);
            } else {
                ven_felica_status = true;
            }
        } else {
            hwlog_err("%s: ven already enable\n", __func__);
        }
        break;

    case NFC_ON_BY_HISI_PMIC:
    case NFC_ON_BY_HI6421V600_PMIC:
    case NFC_ON_BY_HI6555V110_PMIC:
    case NFC_ON_BY_HI6421V700_PMIC:
    case NFC_ON_BY_HI6421V800_PMIC:
    case NFC_ON_BY_HI6421V900_PMIC:
    case NFC_ON_BY_HI6555V300_PMIC:
    case NFC_ON_BY_HI6555V500_PMIC:
        hwlog_info("%s: Nfc on by HISI PMIC !\n", __func__);
        hisi_pmic_on();
        break;

    default:
        hwlog_err("%s: Unknown nfc on type !\n", __func__);
        break;
    }

    return ret;
}

static int thn31_bulk_disable(struct  thn31_dev *pdev)
{
    int ret = 0;

    if (pdev == NULL) {
        hwlog_err("%s: pdev is null !\n", __func__);
        return -1;
    }

    switch (g_nfc_on_type) {
    case NFC_ON_BY_GPIO:
        hwlog_info("%s: Nfc off by GPIO !\n", __func__);
        gpio_set_value(pdev->ven_gpio, 0);
        break;

    case NFC_ON_BY_REGULATOR_BULK:
        hwlog_info("%s: Nfc off by REGULATOR !\n", __func__);
        if (true == ven_felica_status) {
            ret = regulator_bulk_disable(1, &(pdev->ven_felica));
            if (ret < 0) {
                hwlog_err("%s: regulator_disable failed, ret:%d\n", __func__, ret);
            } else {
                ven_felica_status = false;
            }
        } else {
            hwlog_err("%s: ven already disable\n", __func__);
        }
        break;

    case NFC_ON_BY_HISI_PMIC:
    case NFC_ON_BY_HI6421V600_PMIC:
    case NFC_ON_BY_HI6555V110_PMIC:
    case NFC_ON_BY_HI6421V700_PMIC:
    case NFC_ON_BY_HI6421V800_PMIC:
    case NFC_ON_BY_HI6421V900_PMIC:
    case NFC_ON_BY_HI6555V300_PMIC:
    case NFC_ON_BY_HI6555V500_PMIC:
        hwlog_info("%s: Nfc off by HISI PMIC !\n", __func__);
        hisi_pmic_off();
        break;

    default:
        hwlog_err("%s: Unknown nfc off type !\n", __func__);
        break;
    }

    return ret;
}

// hide bank card number
uint16_t tms_nfc_check_number(const char *string, uint16_t len)
{
    uint16_t i;
    if (string == NULL)
        return 0;
    for (i = 0; i < len; i++) {
        if (string[i] > '9' || string[i] < '0') // '9' & '0' means char must between 1-9
            return 0;
    }
    return 1; // 1 means success
}
// end

static int hex_2_byte(char hex_ch)
{
    if (hex_ch >= '0' && hex_ch <= '9')
        return hex_ch - '0';

    if (hex_ch >= 'a' && hex_ch <= 'f')
        return hex_ch - 'a' + 10;

    if (hex_ch >= 'A' && hex_ch <= 'F')
        return hex_ch - 'A' + 10;

    return -1;
}
// hide XBJT the UID
static void hide_xbjt_uid(char *tmp_str, int offset, int count)
{
    char tag;
    int len;
    int tmp_offset = offset;
    int length = count;
    hwlog_info("%s : enter\n", __func__);

    if (tmp_str == NULL)
        return;

    while (length > 0) {
        tag = tmp_str[tmp_offset++];
        len = hex_2_byte(tmp_str[tmp_offset++]);
        if (len <= 0) {
            hwlog_err("%s: Data length is = %d\n", __func__, len);
            return;
        }
        if (tag == '\0') {
            hwlog_err("%s Data End\n", __func__);
            return;
        }

        switch (tag) {
        case TAG_UID:
            if (len == FOUR_BYTE_UID || len == SEVEN_BYTE_UID || len == TEN_BYTE_UID) {
                tmp_str[tmp_offset + UID_CHAR_OFFSET_5] = 'X';
                tmp_str[tmp_offset + UID_CHAR_OFFSET_6] = 'X';
                tmp_str[tmp_offset + UID_CHAR_OFFSET_7] = 'X';
                tmp_str[tmp_offset + UID_CHAR_OFFSET_8] = 'X';
            } else {
                hwlog_err("%s Not UID\n", __func__);
            }
            break;
        default:
            break;
        }
        tmp_offset += len * BYTE_CHAR_LEN;
        length -= (len + 1) * BYTE_CHAR_LEN;
    }
}

int tms_set_fwupdate_on_info(char info)
{
    char hex_para[TEL_HUAWEI_NV_NFCCAL_LEGTH] = {0};
    /* read nfc configure value from nvm */
    int ret;
    ret = nfc_nv_opera(NV_READ, TEL_HUAWEI_NV_NFCCAL_NUMBER,
               TEL_HUAWEI_NV_NFCCAL_NAME,
               TEL_HUAWEI_NV_NFCCAL_LEGTH, hex_para);
    hwlog_info("%s: enter!\n", __func__);
    if (ret < 0) {
        hwlog_err("%s: get nv error ret: %d!\n", __func__, ret);
        return -1;
    }
    /* write nfc configure value to nvm */
    hex_para[FWUPDATE_ON_OFFSET] = info;
    ret = nfc_nv_opera(NV_WRITE, TEL_HUAWEI_NV_NFCCAL_NUMBER, TEL_HUAWEI_NV_NFCCAL_NAME, TEL_HUAWEI_NV_NFCCAL_LEGTH, hex_para);
    if (ret < 0) {
        hwlog_err("%s: set nv error ret: %d!\n", __func__, ret);
        return -1;
    }
    return 0;
}

int tms_get_fwupdate_on_info(char *info)
{
    char hex_para[TEL_HUAWEI_NV_NFCCAL_LEGTH] = {0};
    /* read nfc configure value from nvm */
    int ret;
    ret = nfc_nv_opera(NV_READ, TEL_HUAWEI_NV_NFCCAL_NUMBER, TEL_HUAWEI_NV_NFCCAL_NAME, TEL_HUAWEI_NV_NFCCAL_LEGTH, hex_para);
    hwlog_info("%s: enter!\n", __func__);
    if (ret < 0) {
        hwlog_err("%s: get nv error ret: %d!\n", __func__, ret);
        return -1;
    }
    *info = hex_para[FWUPDATE_ON_OFFSET];
    hwlog_info("%s: info = %d.\n", __func__, (int)*info);
    return 0;
}

static ssize_t nfc_fwupdate_on_show(struct device *dev, struct device_attribute *attr, char *buf)
{
        char fwupdate_flag = 0;
        (void)tms_get_fwupdate_on_info(&fwupdate_flag);
        hwlog_info("%s: read fwupdate_on, returned =%d\n", __func__,  (unsigned char)fwupdate_flag);

        return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
            "%d\n", fwupdate_flag));
}

static ssize_t nfc_fwupdate_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    if ((buf != NULL) && (buf[0] >= CHAR_0) && (buf[0] <= CHAR_9)) {
        firmware_update = buf[0] - CHAR_0;;
        hwlog_info("%s:firmware update success: %d\n", __func__, firmware_update);
    }

    return (ssize_t)count;
}

static ssize_t nfc_fwupdate_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, sizeof(firmware_update) + 1, sizeof(firmware_update),
        "%d", firmware_update));
}

static ssize_t nfc_switch_state_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    if ((buf!=NULL) && (buf[0]>=CHAR_0) && (buf[0]<=CHAR_9))
        nfc_switch_state = buf[0] - CHAR_0; /* file storage str */
    return (ssize_t)count;
}

static ssize_t nfc_switch_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, sizeof(nfc_switch_state) + 1, sizeof(nfc_switch_state),
        "%d", nfc_switch_state));
}

static ssize_t nfc_at_result_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    if ((buf!=NULL) && (buf[0]>=CHAR_0) && (buf[0]<=CHAR_9))
        nfc_at_result = buf[0] - CHAR_0; /* file storage str */
    return (ssize_t)count;
}

static ssize_t nfc_at_result_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, sizeof(nfc_at_result) + 1, sizeof(nfc_at_result),
        "%d", nfc_at_result));
}

static ssize_t nfc_get_rssi_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int i = 0;
    int flag = 1;
    tms_nfc_get_rssi = 0;
    if (buf!=NULL) {
        if (buf[0] == '-') {
            flag = -1;
            i++;
        }
        while (buf[i] != '\0') {
            if ((buf[i] >= CHAR_0) && (buf[i] <= CHAR_9) && (tms_nfc_get_rssi <= RSSI_MAX))
                tms_nfc_get_rssi = (long)(tms_nfc_get_rssi * 10) + (buf[i] - CHAR_0); /* file storage str */
            i++;
        }
        tms_nfc_get_rssi = flag * tms_nfc_get_rssi;
    }
    return (ssize_t)count;
}

static ssize_t nfc_get_rssi_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    hwlog_info("%s:%s,%ld\n", __func__, buf, tms_nfc_get_rssi);
    return (ssize_t)(snprintf_s(buf, MAX_SIZE + 1, MAX_SIZE, "%ld", tms_nfc_get_rssi));
}


static ssize_t nxp_config_name_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    return (ssize_t)count;
}

static ssize_t nxp_config_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, strlen(g_nfc_nxp_config_name) + 1, strlen(g_nfc_nxp_config_name),
        "%s", g_nfc_nxp_config_name));
}

static ssize_t nfc_brcm_conf_name_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    return (ssize_t)count;
}
static ssize_t nfc_brcm_conf_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, strlen(g_nfc_brcm_conf_name) + 1, strlen(g_nfc_brcm_conf_name),
        "%s", g_nfc_brcm_conf_name));
}

static ssize_t nfc_sim_switch_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    int val = 0;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        hwlog_err("%s: nfc_bj_dev == NULL!\n", __func__);
        return 0;
    }
    if (sscanf_s(buf, "%1d", &val) == 1) {
        if (val >= 1 && val <= 3) {
            thn31_dev->sim_switch = val;
        } else {
            return -EINVAL;
        }
    } else {
        return -EINVAL;
    }
    return (ssize_t)count;
}

static ssize_t nfc_sim_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        hwlog_err("%s: nfc_bj_dev == NULL!\n", __func__);
        return 0;
    }
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d\n", thn31_dev->sim_switch));
}
static ssize_t rd_nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int status = -1;
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        hwlog_err("%s:    nfc_bj_dev == NULL!\n", __func__);
        return status;
    }
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d\n", thn31_dev->sim_status));
}
static ssize_t nfc_enable_status_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    int val = 0;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        hwlog_err("%s: nfc_bj_dev == NULL!\n", __func__);
        return 0;
    }
    if (sscanf_s(buf, "%1d", &val) == 1) {
        if (val == ENABLE_START) {
            thn31_dev->enable_status = ENABLE_START;
        } else if (val == ENABLE_END) {
            thn31_dev->enable_status = ENABLE_END;
        } else {
            return -EINVAL;
        }
    } else {
        return -EINVAL;
    }
    return (ssize_t)count;
}
static ssize_t nfc_enable_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        hwlog_err("%s: nfc_bj_dev == NULL!\n", __func__);
        return 0;
    }
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
    "%d\n", thn31_dev->enable_status));
}
static ssize_t nfc_card_num_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d\n", g_nfc_card_num));
}

static ssize_t nfc_ese_num_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d\n", g_nfc_ese_num));
}

static ssize_t nfc_delaytime_node_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d\n", g_nfc_delaytime_node));
}

static ssize_t nfc_fw_version_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret = -1;

    memset_s(g_nfc_fw_version, sizeof(g_nfc_fw_version), 0x00, MAX_NFC_FW_VERSION_SIZE);
    ret = nfc_get_dts_config_string("nfc_fw_version", "nfc_fw_version",
        g_nfc_fw_version, sizeof(g_nfc_fw_version));
    if (ret != 0) {
        memset_s(g_nfc_fw_version, sizeof(g_nfc_fw_version), 0x00, MAX_NFC_FW_VERSION_SIZE);
        hwlog_err("%s: can't get nfc g_nfc_fw_version, default FW 8.1.24\n", __func__);
        ret = strcpy_s(g_nfc_fw_version, strlen("FW 8.1.24") + 1, "FW 8.1.24");
        if (ret != EOK)
            hwlog_err("strcpy_s err %x\n", ret);
    }
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%s", g_nfc_fw_version));
}
static ssize_t nfc_chip_type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, strlen(g_nfc_chip_type) + 1, strlen(g_nfc_chip_type),
        "%s", g_nfc_chip_type));
}

static ssize_t nfc_chip_type_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_nfc_chip_type, sizeof(g_nfc_chip_type),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}


static ssize_t nfcservice_lock_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfcservice_lock));
}

static ssize_t nfcservice_lock_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    int val = 0;

    if (sscanf_s(buf, "%1d", &val) == 1) {
        g_nfcservice_lock = val;
    } else {
        hwlog_err("%s: set g_nfcservice_lock error\n", __func__);
        g_nfcservice_lock = 0;
    }
    hwlog_info("%s: g_nfcservice_lock:%d\n", __func__, g_nfcservice_lock);
    return (ssize_t)count;
}

static ssize_t nfc_svdd_sw_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    int val = 0;

    if (sscanf_s(buf, "%1d", &val) == 1) {
        switch (val) {
        case NFC_SVDD_SW_OFF:
            pmu0_svdd_sel_off();
            break;
        case NFC_SVDD_SW_ON:
            pmu0_svdd_sel_on();
            break;
        default:
            hwlog_err("%s: svdd switch error, val:%d[0:pulldown, 1:pullup]\n", __func__, val);
            break;
        }
    } else {
        hwlog_err("%s: val len error\n", __func__);
        return (ssize_t)count;
    }
    hwlog_info("%s: nfc svdd switch to %d\n", __func__, val);
    return (ssize_t)count;
}

static ssize_t nfc_svdd_sw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int sw_status = 0;

    sw_status = get_pmu0_svdd_sel_status();
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", sw_status));
}

static ssize_t nfc_close_type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_close_type));
}

static ssize_t nfc_close_type_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    int val = 0;
    if (sscanf_s(buf, "%1d", &val) == 1) {
        g_nfc_close_type = val;
    } else {
        hwlog_err("%s: set g_nfc_close_type error\n", __func__);
        g_nfc_close_type = 0;
    }
    hwlog_info("%s: g_nfc_close_type:%d\n", __func__, g_nfc_close_type);
    return (ssize_t)count;
}

static ssize_t nfc_open_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_open_status));
}

static ssize_t nfc_open_status_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    int val = 0;
    if (sscanf_s(buf, "%1d", &val) == 1) {
        g_nfc_open_status = val;
    } else {
        hwlog_err("%s: set g_nfc_open_status error\n", __func__);
        g_nfc_open_status = NFC_CLOSE_STATUS;
    }
    hwlog_info("%s: g_nfc_open_status:%d\n", __func__, g_nfc_open_status);
    return (ssize_t)count;
}

static ssize_t nfc_need_reset_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_need_reset));
}

static ssize_t nfc_need_reset_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    int val = 0;
    if (sscanf_s(buf, "%1d", &val) == 1) {
        g_nfc_need_reset = val;
    } else {
        hwlog_err("%s: set g_nfc_need_reset error\n", __func__);
        g_nfc_need_reset = NFC_NONEED_RESET;
    }
    hwlog_info("%s: g_nfc_need_reset:%d\n", __func__, g_nfc_need_reset);
    return (ssize_t)count;
}

static ssize_t nfc_single_channel_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_single_channel));
}

static ssize_t nfc_spec_rf_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_spec_rf));
}

static ssize_t nfc_delaytime_set_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_delaytime_set));
}

static ssize_t nfc_sim2_omapi_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_sim2_omapi));
}

static ssize_t nfc_wired_ese_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_ese_type));
}

static ssize_t nfc_wired_ese_info_store(struct device *dev, struct device_attribute *attr,
        const char *buf, size_t count)
{
    int val = 0;
    if (sscanf_s(buf, "%1d", &val) == 1) {
        g_nfc_ese_type = val;
    } else {
        hwlog_err("%s: set g_nfc_ese_type  error\n", __func__);
    }
    hwlog_info("%s: g_nfc_ese_type:%d\n", __func__, g_nfc_ese_type);
    return (ssize_t)count;
}
static ssize_t nfc_activated_se_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_activated_se_info));
}

static ssize_t nfc_activated_se_info_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    int val = 0;
    if (sscanf_s(buf, "%1d", &val) == 1) {
        g_nfc_activated_se_info = val;
    } else {
        hwlog_err("%s: set g_nfc_activated_se_info error\n", __func__);
        g_nfc_activated_se_info = 0;
    }
    hwlog_info("%s: g_nfc_activated_se_info:%d\n", __func__, g_nfc_activated_se_info);
    return (ssize_t)count;
}

static ssize_t nfc_hal_dmd_info_store(struct device *dev, struct device_attribute *attr,
             const char *buf, size_t count)
{
    long val = 0;
    char dmd_info_from_hal[64] = {'\0'};
    /* The length of DMD error number is 9. */
    if (sscanf_s(buf, "%9ld", &val) == 1) {
        if (val < NFC_DMD_NUMBER_MIN || val > NFC_DMD_NUMBER_MAX)
            return (ssize_t)count;
        g_nfc_hal_dmd_no = val;
        /* The max length of content for current dmd description set as 63.
           Example for DMD Buf: '923002014 CoreReset:600006A000D1A72000'.
           A space as a separator is between dmd error no and description. */
        if (sscanf_s(buf, "%*s%63s", dmd_info_from_hal) == 1)
            tms_nfc_record_dmd_info(val, dmd_info_from_hal);
    } else {
        hwlog_err("%s: get dmd number error\n", __func__);
    }
    return (ssize_t)count;
}

/* lint -e516 -e515 -e717 -e960 -e712 -e747 */
int tms_nfc_record_dmd_info(long dmd_no, const char *dmd_info)
{
/* lint -e529 -esym(529,*) */
#ifdef CONFIG_HUAWEI_DSM
    if (dmd_no < NFC_DMD_NUMBER_MIN || dmd_no > NFC_DMD_NUMBER_MAX
        || dmd_info == NULL || NULL == nfc_dclient) {
        hwlog_info("%s: para error: %ld\n", __func__, dmd_no); /*lint !e960*/
        return -1;
    }

    hwlog_info("%s: dmd no: %ld - %s", __func__, dmd_no, dmd_info); /*lint !e960*/
    if (!dsm_client_ocuppy(nfc_dclient)) {
        dsm_client_record(nfc_dclient, "DMD info:%s", dmd_info);
        dsm_client_notify(nfc_dclient, dmd_no);
    }
#endif
    return 0;
}
/* lint +e516 +e515 +e717 +e960 +e712 +e747 */
/* lint -e529 +esym(529,*) */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static void nfc_record_dmd_probe_timerhandler(struct timer_list *data)
#else
static void nfc_record_dmd_probe_timerhandler(unsigned long data)
#endif
{
    del_timer(&nfc_dmd_probe_timer);
    if (get_nfc_dmd_probe_flag() == 0) {
        if (g_chip_type == NFCTYPE_THN31)
            tms_nfc_record_dmd_info(NFC_DMD_I2C_READ_ERROR_NO, "THN31-Error-in-Probe-Error:nfc_sz");
        else
            tms_nfc_record_dmd_info(NFC_DMD_I2C_READ_ERROR_NO, "THN31-Error-in-Probe-Error:nfc_dg");
    }
}

static ssize_t nfc_hal_dmd_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%d", g_nfc_hal_dmd_no));
}

static ssize_t nfc_calibration_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    char cali_info[TEL_HUAWEI_NV_NFCCAL_LEGTH] = {0};
    char cali_str[MAX_BUFFER_SIZE] = {0};
    int err;
    int ret = -1;
    int i = 0;
    int cal_len = 0;
    ret = nfc_nv_opera(NV_READ, TEL_HUAWEI_NV_NFCCAL_NUMBER, TEL_HUAWEI_NV_NFCCAL_NAME, TEL_HUAWEI_NV_NFCCAL_LEGTH, cali_info);
    if (ret < 0) {
        hwlog_err("%s: get nv error ret: %d!\n", __func__, ret);
        return -1;
    }
    cal_len = cali_info[0];
    if (cal_len >= TEL_HUAWEI_NV_NFCCAL_LEGTH) {
        cal_len = TEL_HUAWEI_NV_NFCCAL_LEGTH - 1;
        hwlog_info("%s: nfc cal info len %d!\n", __func__, cali_info[0]);
    }
    for (i = 0; i < cal_len + 1; i++) {
        err = snprintf_s(&cali_str[i * 2], sizeof(cali_info[i]) * 2 + 1, sizeof(cali_info[i]) * 2 + 1, "%02X", cali_info[i]);
        if (err < 0)
            hwlog_err("%s: snprintf_s is failed\n", __func__);
    }
    hwlog_info("%s: nfc cal info: [%s]!\n", __func__, cali_str);
    return (ssize_t)(snprintf_s(buf, MAX_BUFFER_SIZE, MAX_BUFFER_SIZE-1, "%s", cali_str));
}

static ssize_t nfc_clk_src_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE-1,
        "%d", g_nfc_clk_src));
}

static ssize_t nxp_config_clock_switch_store(struct device *dev, struct device_attribute *attr,
    const char *buf, size_t count)
{
    unsigned int value;
    unsigned int value_set;
    if (g_nfc_nxp_config_clock_switch == 0) // 0 means clock switch not config
        return (ssize_t)count;
    if ((buf != NULL) && (buf[0] == '1')) {
        pmic_write_reg(PMU_CLK_NFC_EN_REG, 1); // 1 - clock enable
        value = pmic_read_reg(PMU_CLK_LDO_MASK_REG);
        value_set = value | 0x2; // Masking the ldo_buf switch by enable reg bit 1
        pmic_write_reg(PMU_CLK_LDO_MASK_REG, value_set);
        hwlog_info("%s: PMU clock write open ok, and config ldo mask from %d to %d\n", __func__, value, value_set);
    } else if ((buf != NULL) && (buf[0] == '0')) {
        pmic_write_reg(PMU_CLK_NFC_EN_REG, 0); // 0 - clock disable
        value = pmic_read_reg(PMU_CLK_LDO_MASK_REG);
        value_set = value & 0xfd; // not mask the ldo_buf switch by disable reg bit 1
        pmic_write_reg(PMU_CLK_LDO_MASK_REG, value_set);
        hwlog_info("%s: PMU clock write close ok, and config ldo mask from %d to %d\n", __func__, value, value_set);
    } else {
        hwlog_info("%s: param input error\n", __func__);
    }

    return (ssize_t)count;
}

static ssize_t nxp_config_clock_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%s\n", g_nfc_nxp_config_clock_switch));
}

static int ese_ca_get_dt_val(struct device_node *pnode)
{
    if (of_property_read_u32(pnode, "nfc_ese_num_dts", &(g_ese_config_data.nfc_ese_num_dts))) {
        hwlog_err("get nfc_ese_num_dts from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "spi_bus", &(g_ese_config_data.spi_bus))) {
        hwlog_err("get spi_bus from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "gpio_spi_cs", &(g_ese_config_data.gpio_spi_cs))) {
        hwlog_err("get gpio_spi_cs from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "gpio_ese_irq", &(g_ese_config_data.gpio_ese_irq))) {
        hwlog_err("get gpio_ese_irq from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "gpio_ese_reset", &(g_ese_config_data.gpio_ese_reset))) {
        hwlog_err("get gpio_ese_reset from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "svdd_pwr_req_need", &(g_ese_config_data.svdd_pwr_req_need))) {
        hwlog_err("get svdd_pwr_req_need from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "gpio_svdd_pwr_req", &(g_ese_config_data.gpio_svdd_pwr_req))) {
        hwlog_err("get gpio_svdd_pwr_req from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "spi_switch_need", &(g_ese_config_data.spi_switch_need))) {
        hwlog_err("get spi_switch_need from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_u32(pnode, "gpio_spi_switch", &(g_ese_config_data.gpio_spi_switch))) {
        hwlog_err("get gpio_spi_switch from dts failed\n");
        return -ENODEV;
    }
    return 0;
}

static int ese_ca_parse_dt(void)
{
    char *ese_config_status = NULL;
    struct device_node *tmp_pnode;
    int ret;
    tmp_pnode = of_find_compatible_node(NULL, NULL, DTS_COMP_ESS_CA_NAME);
    if (tmp_pnode == NULL) {
        hwlog_err("get ese_config hisilicon,ese_ca from dts failed\n");
        return -ENODEV;
    }
    if (of_property_read_string(tmp_pnode, "status",
        (const char **)&ese_config_status) >= 0) {
        hwlog_err("ese_config_status=%s\n", ese_config_status);
        if (strncmp(ese_config_status, "ok", 2)) {
            hwlog_err("get ese_config status from dts failed\n");
            return -ENODEV;
        }
    }

    ret = ese_ca_get_dt_val(tmp_pnode);
    return ret;
}

static ssize_t nfc_ese_num_dts_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.nfc_ese_num_dts));
}

static ssize_t spi_bus_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.spi_bus));
}

static ssize_t gpio_spi_cs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.gpio_spi_cs));
}

static ssize_t gpio_ese_irq_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.gpio_ese_irq));
}

static ssize_t gpio_ese_irq_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_ese_config_data.gpio_ese_irq, sizeof(g_ese_config_data.gpio_ese_irq),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}

static ssize_t gpio_ese_reset_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.gpio_ese_reset));
}

static ssize_t gpio_ese_reset_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_ese_config_data.gpio_ese_reset, sizeof(g_ese_config_data.gpio_ese_reset),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}

static ssize_t svdd_pwr_req_need_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.svdd_pwr_req_need));
}

static ssize_t svdd_pwr_req_need_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_ese_config_data.svdd_pwr_req_need, sizeof(g_ese_config_data.svdd_pwr_req_need),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}

static ssize_t gpio_svdd_pwr_req_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.gpio_svdd_pwr_req));
}

static ssize_t gpio_svdd_pwr_req_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_ese_config_data.gpio_svdd_pwr_req, sizeof(g_ese_config_data.gpio_svdd_pwr_req),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}

static ssize_t spi_switch_need_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.spi_switch_need));
}

static ssize_t spi_switch_need_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_ese_config_data.spi_switch_need, sizeof(g_ese_config_data.spi_switch_need),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}

static ssize_t gpio_spi_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
        "%u", g_ese_config_data.gpio_spi_switch));
}

static ssize_t gpio_spi_switch_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
    int ret;

    hwlog_err("%s: %s count=%lu\n", __func__, buf, count);
    ret = strncpy_s(g_ese_config_data.gpio_spi_switch, sizeof(g_ese_config_data.gpio_spi_switch),
        buf, MAX_NFC_CHIP_TYPE_SIZE - 1);
    if (ret != 0)
        hwlog_err("%s: strncpy_s fail\n", __func__);
    return (ssize_t)count;
}

static struct device_attribute thn31_attr[] = {

    __ATTR(nfc_fwupdate, 0664, nfc_fwupdate_show, nfc_fwupdate_store),
    __ATTR(nxp_config_name, 0664, nxp_config_name_show, nxp_config_name_store),
    __ATTR(nfc_brcm_conf_name, 0664, nfc_brcm_conf_name_show, nfc_brcm_conf_name_store),
    __ATTR(nfc_sim_switch, 0664, nfc_sim_switch_show, nfc_sim_switch_store),
    __ATTR(rd_nfc_sim_status, 0444, rd_nfc_sim_status_show, NULL),
    __ATTR(nfc_enable_status, 0664, nfc_enable_status_show, nfc_enable_status_store),
    __ATTR(nfc_card_num, 0444, nfc_card_num_show, NULL),
    __ATTR(nfc_ese_num, 0444, nfc_ese_num_show, NULL),
    __ATTR(nfc_chip_type, 0664, nfc_chip_type_show, nfc_chip_type_store),
    __ATTR(nfc_fw_version, 0444, nfc_fw_version_show, NULL),
    __ATTR(nfcservice_lock, 0664, nfcservice_lock_show, nfcservice_lock_store),
    __ATTR(nfc_svdd_sw, 0664, nfc_svdd_sw_show, nfc_svdd_sw_store),
    __ATTR(nfc_close_type, 0664, nfc_close_type_show, nfc_close_type_store),
    __ATTR(nfc_single_channel, 0444, nfc_single_channel_show, NULL),
    __ATTR(nfc_delaytime_set, 0444, nfc_delaytime_set_show, NULL),
    __ATTR(nfc_delaytime_node, 0444, nfc_delaytime_node_show, NULL),
    __ATTR(nfc_sim2_omapi, 0444, nfc_sim2_omapi_show, NULL),
    __ATTR(nfc_wired_ese_type, 0664, nfc_wired_ese_info_show, nfc_wired_ese_info_store),
    __ATTR(nfc_activated_se_info, 0664, nfc_activated_se_info_show, nfc_activated_se_info_store),
    __ATTR(nfc_hal_dmd, 0664, nfc_hal_dmd_info_show, nfc_hal_dmd_info_store),
    __ATTR(nfc_calibration, 0444, nfc_calibration_show, NULL),
    __ATTR(nfc_clk_src, 0444, nfc_clk_src_show, NULL),
    __ATTR(nfc_switch_state, 0664, nfc_switch_state_show, nfc_switch_state_store),
    __ATTR(nfc_at_result, 0664, nfc_at_result_show, nfc_at_result_store),
    __ATTR(nfc_get_rssi, 0664, nfc_get_rssi_show, nfc_get_rssi_store),
    __ATTR(nfc_spec_rf, 0444, nfc_spec_rf_show, NULL),
    __ATTR(nfc_fwupdate_on, 0444, nfc_fwupdate_on_show, NULL),
    __ATTR(nxp_config_clock_switch, 0664, nxp_config_clock_switch_show, nxp_config_clock_switch_store),
    __ATTR(nfc_ese_num_dts, 0664, nfc_ese_num_dts_show, NULL),
    __ATTR(spi_bus, 0664, spi_bus_show, NULL),
    __ATTR(gpio_spi_cs, 0664, gpio_spi_cs_show, NULL),
    __ATTR(gpio_ese_irq, 0664, gpio_ese_irq_show, gpio_ese_irq_store),
    __ATTR(gpio_ese_reset, 0664, gpio_ese_reset_show, gpio_ese_reset_store),
    __ATTR(svdd_pwr_req_need, 0664, svdd_pwr_req_need_show, svdd_pwr_req_need_store),
    __ATTR(gpio_svdd_pwr_req, 0664, gpio_svdd_pwr_req_show, gpio_svdd_pwr_req_store),
    __ATTR(spi_switch_need, 0664, spi_switch_need_show, spi_switch_need_store),
    __ATTR(gpio_spi_switch, 0664, gpio_spi_switch_show, gpio_spi_switch_store),
    __ATTR(nfc_open_status, 0664, nfc_open_status_show, nfc_open_status_store),
    __ATTR(nfc_need_reset, 0664, nfc_need_reset_show, nfc_need_reset_store),
};
/* lint -restore */
/* lint -save -e* */
static int create_sysfs_interfaces(struct device *dev)
{
    int i;
    for (i = 0; i < ARRAY_SIZE(thn31_attr); i++) {
        if (device_create_file(dev, thn31_attr + i)) {
            goto error;
        }
    }

    return 0;
error:
    for (; i >= 0; i--)
        device_remove_file(dev, thn31_attr + i);

    hwlog_err("%s:nfc_bj unable to create sysfs interface.\n", __func__);
    return -1;
}

static int remove_sysfs_interfaces(struct device *dev)
{
    int i;
    for (i = 0; i < ARRAY_SIZE(thn31_attr); i++)
        device_remove_file(dev, thn31_attr + i);

    return 0;
}

static struct of_device_id thn31_i2c_dt_ids[] = {
    {.compatible = "hisilicon,thn31_nfc" },
    {}
};

static void watch_thn31_disable_irq(struct thn31_dev *thn31_dev)
{
    unsigned long flags;

    spin_lock_irqsave(&thn31_dev->irq_enabled_lock, flags);
    if (thn31_dev->irq_enabled) {
        disable_irq_nosync(thn31_dev->irq);
        thn31_dev->irq_enabled = false;
    }
    spin_unlock_irqrestore(&thn31_dev->irq_enabled_lock, flags);
}

static void watch_thn31_disable_irq_for_ext_gpio(struct thn31_dev *thn31_dev)
{
    mutex_lock(&thn31_dev->irq_mutex_lock);
    if (thn31_dev->irq_enabled) {
        disable_irq_nosync(thn31_dev->irq);
        thn31_dev->irq_enabled = false;
    }
    mutex_unlock(&thn31_dev->irq_mutex_lock);
}

static int watch_thn31_get_resource(struct thn31_dev *pdev, struct platform_device *dev)
{
    pdev->irq_gpio = (unsigned int)of_get_named_gpio(dev->dev.of_node, "thn31,irq", 0);
    hwlog_info("irq_gpio:%u\n", pdev->irq_gpio);
    if (!gpio_is_valid(pdev->firm_gpio)) {
        hwlog_err("failed to get firm!\n");
        return -ENODEV;
    }
    return 0;
}

static irqreturn_t watch_thn31_dev_irq_handler(int irq, void *dev_id)
{
    struct thn31_dev *thn31_dev = dev_id;
    if (g_nfc_ext_gpio & IRQ_EXTENTED_GPIO_MASK) {
        watch_thn31_disable_irq_for_ext_gpio(thn31_dev);
    } else {
        watch_thn31_disable_irq(thn31_dev);
    }

    /* set a wakelock to avoid entering into suspend */
    if (WAKE_LOCK_TIMEOUT_ENALBE == g_wake_lock_timeout) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
        __pm_wakeup_event(wlock_read, jiffies_to_msecs(5 * HZ));
#else
        __pm_wakeup_event(&wlock_read, jiffies_to_msecs(5 * HZ));
#endif
    } else {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
        __pm_wakeup_event(wlock_read, jiffies_to_msecs(1 * HZ));
#else
        __pm_wakeup_event(&wlock_read, jiffies_to_msecs(1 * HZ));
#endif
    }
    /* Wake up waiting readers */
    wake_up(&thn31_dev->read_wq);

    return IRQ_HANDLED;
}

static ssize_t watch_thn31_dev_read(struct file *filp, char __user *buf,
        size_t count, loff_t *offset)
{
    struct thn31_dev *thn31_dev = filp->private_data;
    char tmp[MAX_BUFFER_SIZE] = {0};
    char *tmpStr = NULL;
    int err = -1;
    int ret;
    int i;
    int retry;
    bool is_success = false;
    uint16_t buffer_count;
    uint16_t tmp_length;
    // 2 means ascii length of char, 1 means '\0'
    uint16_t tmp_size = sizeof(tmp) * 2 + 1;
    errno_t err_ret;
    /* #ifdef TMS_NFC */
    bool need2byte = false;
    /* #endif */
    unsigned long flag;
    if (count > MAX_BUFFER_SIZE) {
        count = MAX_BUFFER_SIZE;
    }
    hwlog_info("%s-> enter count = %d\n", __func__, count);
    mutex_lock(&thn31_dev->read_mutex);

    if (!nfc_gpio_get_value(thn31_dev->irq_gpio)) {
        if (filp->f_flags & O_NONBLOCK) {
            ret = -EAGAIN;
            goto fail;
        }
        if (g_nfc_ext_gpio & IRQ_EXTENTED_GPIO_MASK) {
            watch_thn31_disable_irq_for_ext_gpio(thn31_dev);
        } else {
            watch_thn31_disable_irq(thn31_dev);
        }

        thn31_dev->irq_enabled = true;
        enable_irq(thn31_dev->irq);
        ret = wait_event_interruptible(thn31_dev->read_wq,
        !thn31_dev->irq_enabled);
        hwlog_info("%s: common ireq received\n", __func__);
        if (ret) {
            hwlog_err("%s : ret %d goto fail\n", __func__, ret);
            goto fail;
        }
        /*
        * NFC service wanted to close the driver so,
        * release the calling reader thread asap.
        *
        * This can happen in case of nfc node close call from
        * eSE HAL in that case the NFC HAL reader thread
        * will again call read system call
        */
        if (thn31_dev->release_read) {
            hwlog_err("%s: releasing read\n", __func__);
            mutex_unlock(&thn31_dev->read_mutex);
            return 0;
        }
    }

    tmpStr = (char *)kzalloc(sizeof(tmp) * 2 + 1, GFP_KERNEL);
    if (!tmpStr) {
        hwlog_info("%s:Cannot allocate memory for read tmpStr.\n", __func__);
        ret = -ENOMEM;
        goto fail;
    }

    /* Read data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        /* #ifdef TMS_NFC */
        hwlog_info("%s:second read 1 count = %d last_count %d.\n", __func__, count, last_count);
        if (last_count == 3 && count == 1) {
            hwlog_info("%s: need2byte \n", __func__);
            need2byte = true;
            count = 2;
        }
        hwlog_info("%s:second read 2 count = %d last_count %d.\n", __func__, count, last_count);
        /* #endif */

        clear_receive_data();
        char *sendData = (char *)kzalloc(count, GFP_KERNEL);
        (void*)memset_s(sendData, count, 0x00, count);
        ret = nfc_commu_send_msg(sendData, count, NFC_COMMUX_READ);
        kfree(sendData);
        if (ret != 0) {
            hwlog_err("%s : nfc_commu_send_msg fail, retry = %d, ret = %d\n", __func__, retry, ret);
            msleep(20);
            continue;
        }
        /* wait 2 HZ timeout for resume */
        ret = down_timeout(&nfc_read_data_sem, 2 * HZ);
        if (ret == -ETIME) {
            pr_err("%s nfc_commu_data_semaphore sema timeout",
                __func__);
        }
        unsigned char* data = get_receive_data();
        ret = get_receive_data_len();
        if (memcpy_s(tmp, MAX_BUFFER_SIZE, data, ret) != EOK) {
            hwlog_err("%s: memcpy_s data err\n", __func__);
            goto fail;
        }

        if (need2byte) {
            count = 1;
            --ret;
        }
        /* #endif */
        for (i = 0; i < count; i++) {
            err = snprintf_s(&tmpStr[i * 2], sizeof(tmp[i]) * 2 + 1, sizeof(tmp[i]) * 2 + 1, "%02X", tmp[i]);
            if (err < 0)
                hwlog_err("%s: snprintf_s is failed\n", __func__);
        }
        // 00 means Type A 0A means max UID len
        if ((count > MIN_NCI_CMD_LEN_WITH_DOOR_NUM) &&
            (tmp[NFC_A_PASSIVE] == 0x00) &&
            (tmp[NFCID_LEN] >= DOORCARD_MIN_LEN) &&
            (tmp[NFCID_LEN] <= 0x0A) && g_is_uid) {
                err_ret = memcpy_s(tmpStr + DOORCARD_OVERRIDE_LEN,
                    tmp_size - DOORCARD_OVERRIDE_LEN,
                    "XXXXXXXXXXXXXXXXXXXX",
                    tmp[NFCID_LEN] * BYTE_CHAR_LEN);
                if (err_ret != EOK)
                    pr_err("%s: memcpy_s fail,%d\n",
                        __func__, err_ret);
        }
        if ((count > MIN_NCI_CMD_LEN_WITH_DOOR_NUM) &&
            (tmp[NCI_CMD_HEAD_OFFSET] == 0x10) && g_is_uid) {
            err_ret = memcpy_s(tmpStr + MIFARE_DATA_UID_OFFSET,
                tmp_size - MIFARE_DATA_UID_OFFSET,
                "XXXXXXXX",
                BANKCARD_NUM_OVERRIDE_LEN);
            if (err_ret != EOK)
                pr_err("%s: memcpy_s fail,%d\n",
                __func__, err_ret);
        }
        // hide bank card number,'6'&'2' means card number head
        buffer_count = count * 2 + 1; // 2 means ascii length of char, 1 means '\0'
        tmp_length = sizeof(tmp) * 2 + 1; // 2 means ascii length of char, 1 means '\0'
        if (buffer_count > MIN_NCI_CMD_LEN_WITH_BANKCARD_NUM) {
            for (i = NCI_CMD_HEAD_OFFSET; i < buffer_count - BANKCARD_NUM_LEN; i += BANKCARD_NUM_HEAD_LEN) {
                if ((*(tmpStr + i) == '6') && (*(tmpStr + i + 1) == '2') &&
                    ((i + BANKCARD_NUM_OVERRIDE_OFFSET) < tmp_length) &&
                    tms_nfc_check_number(tmpStr + i + BANKCARD_NUM_HEAD_LEN, BANKCARD_NUM_VALUE_LEN)) {
                    err_ret = memcpy_s(tmpStr + i + BANKCARD_NUM_OVERRIDE_OFFSET, BANKCARD_NUM_OVERRIDE_LEN,
                        "XXXXXXXX", BANKCARD_NUM_OVERRIDE_LEN);
                    if (err_ret != EOK) {
                        hwlog_err("%s memcpy_s xxx fail\n", __func__);
                    }
                }
            }
        }
        // end
        if (g_xbjt_uid) {
            g_xbjt_uid = false;
            hide_xbjt_uid(tmpStr, 0, (int)buffer_count);
        }
        /* hide cplc
         * 4 is start pos of 9F7F and length of 9F7F
         * 18 is length of cplc and 2 is trans byte "9F" into two char
         * 13 is length of print info and \0
         */
        if ((2 * count > 18) && (strncmp(tmpStr + 4, "9F7F", 4) == 0))
            snprintf_s(tmpStr, sizeof("xxxx9F7Fxxxx") + 1, sizeof("xxxx9F7Fxxxx") + 1, "%s", "xxxx9F7Fxxxx");
        hwlog_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);

        if (ret == (int)count) {
            is_success = true;
            break;
        } else {
            hwlog_info("%s : read data try =%d returned %d\n", __func__, retry, ret);
            msleep(1);
            continue;
        }
    }
    // '6F41' is a proprietary maintenance log for XBJT
    if (count == NCI_HEADER && (strncmp(tmpStr, "6F41", 4) == 0)) {
        g_xbjt_uid = true;
    }

    // 0&1 means '6105' or '000012' mifare, 2 means nci length
    if (((count >= FIRST_LINE_NCI_LEN) && (tmp[0] == 0x61) &&
        (tmp[1] == 0x05) && (tmp[2] >= 0x0A)) ||
        ((tmp[0] == 0x00) && (tmp[1] == 0x00) && (tmp[2] == 0x12))) {
        g_is_uid = true;
    } else {
        g_is_uid = false;
    }
    kfree(tmpStr);
    tmpStr = NULL;
    mutex_unlock(&thn31_dev->read_mutex);
    if (false == is_success) {
        hwlog_err("%s : i2c_master_recv returned %d\n", __func__, ret);
        ret = -EIO;
    }

    if (ret < 0) {
        hwlog_err("%s: i2c_master_recv returned %d\n", __func__, ret);
        return ret;
    }
    if (ret > (int)count) {
        hwlog_err("%s: received too many bytes from i2c (%d)\n",
            __func__, ret);
        return -EIO;
    }
    g_pre_write_time = ktime_get_boottime();
    if (copy_to_user(buf, tmp, ret)) {
        hwlog_err("%s : failed to copy to user space\n", __func__);
        return -EFAULT;
    }
    last_count = count;
    return (size_t)ret;

fail:
    mutex_unlock(&thn31_dev->read_mutex);
    return (ssize_t)ret;
}

static ssize_t watch_thn31_dev_write(struct file *filp, const char __user *buf,
        size_t count, loff_t *offset)
{
    struct thn31_dev  *thn31_dev;
    char data[MAX_BUFFER_SIZE] = {0};
    char *data_buf = NULL;
    char *tmpStr = NULL;
    int err;
    int ret;
    int retry;
    int i;
    bool is_success = false;
    char *pDataAlloc = NULL;
    char wakeup_cmd[1] = {0};
    int wakeup_len = 1;
    int retry_count = 0;
    ktime_t elapse_time = 0;
    ktime_t write_time;

    thn31_dev = filp->private_data;
    /* thn31 download max size is 4096 */
    if (count > MAX_BUFFER_SIZE) {
        if (count > MAX_DL_BUFFER_SIZE) {
            hwlog_err("%s :nfc Max count = %d\n", __func__, count);
            count = MAX_DL_BUFFER_SIZE;
        }
        pDataAlloc = (char *)kzalloc(count, GFP_KERNEL);
        if (NULL == pDataAlloc) {
            hwlog_err("%s:nfc memory kzalloc failed\n", __func__);
            return -ENOMEM;
        }
        data_buf = pDataAlloc;
    } else {
        data_buf = data;
    }

    if (copy_from_user(data_buf, buf, count)) {
        hwlog_err("%s :nfc failed to copy from user space\n", __func__);
        if (NULL != pDataAlloc) {
            kfree(pDataAlloc);
            pDataAlloc = NULL;
        }
        return -EFAULT;
    }

    if (data_buf[0] != T1_HEAD) {
        hwlog_err("%s : nfc data_buf %d\n", __func__, data_buf[0]);
        write_time = ktime_get_boottime();
        elapse_time = write_time - g_pre_write_time;
        // make sure elapse_time is not overflow
        if (elapse_time < 0) {
            elapse_time = I2C_ELAPSE_TIMEOUT;
        }
        g_pre_write_time = write_time;

        if (elapse_time >= I2C_ELAPSE_TIMEOUT) {
            while (++retry_count < MAX_I2C_WAKEUP_TIME) {
                ret = nfc_commu_send_msg(wakeup_cmd, wakeup_len, NFC_COMMUX_WRITE);
                if (ret == 0) {
                    break;
                }
            }
            if (ret < 0)
                hwlog_err("%s: nfc failed to write wakeup_cmd : %d, retry for : %d times\n", __func__, ret, retry_count);
        }
    }

    tmpStr = (char *)kzalloc(count * 2 + 1, GFP_KERNEL);
    if (!tmpStr) {
        hwlog_info("%s:Cannot allocate memory for write tmpStr.\n", __func__);
        if (NULL != pDataAlloc) {
            kfree(pDataAlloc);
            pDataAlloc = NULL;
        }
        return -ENOMEM;
    }

    /* Write data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        ret = nfc_commu_send_msg(data_buf, count, NFC_COMMUX_WRITE);
        if (ret == 0) {
            ret = count;
        }
        for (i = 0; i < count; i++) {
            err = snprintf_s(&tmpStr[i * 2], sizeof(data_buf[i]) * 2 + 1, sizeof(data_buf[i]) * 2 + 1, "%02X", data_buf[i]);
            if (err < 0)
                hwlog_err("%s: nfc snprintf_s is failed\n", __func__);
        }

        hwlog_info("%s :nfc retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);
        if (ret == (int)count) {
            is_success = true;
            break;
        } else {
            if (retry > 0)
                hwlog_info("%s : nfc send data try =%d returned %d\n", __func__, retry, ret);
            msleep(1);
            continue;
        }
    }

    kfree(tmpStr);
    tmpStr = NULL;
    if (false == is_success) {
        hwlog_err("%s : nfc i2c_master_send returned %d\n", __func__, ret);
        ret = -EIO;
    }

    if (NULL != pDataAlloc) {
        kfree(pDataAlloc);
        pDataAlloc = NULL;
    }

    return (ssize_t)ret;
}

static ssize_t watch_thn31_i2c_write(struct  thn31_dev *pdev, const char *buf, int count)
{
    int err;
    int ret;
    int retry;
    bool is_success = false;
    char *tmpStr = NULL;
    int i;

    tmpStr = (char *)kzalloc(255*2, GFP_KERNEL);
    if (!tmpStr) {
        hwlog_info("%s:Cannot allocate memory for write tmpStr.\n", __func__);
        return -ENOMEM;
    }

    /* Write data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        ret = nfc_commu_send_msg(buf, count, NFC_COMMUX_WRITE);
        if (ret == 0) {
            ret = count;
        }
        for (i = 0; i < count; i++) {
            err = snprintf_s(&tmpStr[i * 2], sizeof(buf[i]) * 2 + 1, sizeof(buf[i]) * 2 + 1, "%02X", buf[i]);
            if (err < 0) {
                hwlog_err("%s: snprintf_s is failed\n", __func__);
            }
        }

        hwlog_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);

        if (ret == (int)count) {
            is_success = true;
            break;
        } else {
            if (retry > 0) {
                hwlog_info("%s : send data try =%d returned %d\n", __func__, retry, ret);
            }
            msleep(1);
            continue;
        }
    }
    kfree(tmpStr);
    tmpStr = NULL;
    if (false == is_success) {
        hwlog_err("%s : i2c_master_send returned %d\n", __func__, ret);
        ret = -EIO;
    }
    return (size_t)ret;
}

static ssize_t watch_thn31_i2c_read(struct  thn31_dev *pdev, char *buf, int count)
{
    int err;
    int ret;
    int retry;
    bool is_success = false;
    char *tmpStr = NULL;
    int i;
    /* #ifdef TMS_NFC */
    bool need2byte = false;
    /* #endif */
    mutex_lock(&pdev->read_mutex);
    if (!nfc_gpio_get_value(pdev->irq_gpio)) {
        if (g_nfc_ext_gpio & IRQ_EXTENTED_GPIO_MASK) {
            watch_thn31_disable_irq_for_ext_gpio(pdev);
        } else {
            watch_thn31_disable_irq(pdev);
        }

        pdev->irq_enabled = true;
        enable_irq(pdev->irq);
        ret = wait_event_interruptible_timeout(pdev->read_wq,
        !pdev->irq_enabled, msecs_to_jiffies(1000));
        hwlog_info("%s: common ireq received\n", __func__);
        if (ret <= 0) {
            ret  = -1;
            hwlog_err("%s : wait_event_interruptible_timeout error!\n", __func__);
            goto fail;
        }
        /*
        * NFC service wanted to close the driver so,
        * release the calling reader thread asap.
        *
        * This can happen in case of nfc node close call from
        * eSE HAL in that case the NFC HAL reader thread
        * will again call read system call
        */
        if (pdev->release_read) {
            hwlog_info("%s: releasing read\n", __func__);
            mutex_unlock(&pdev->read_mutex);
            return 0;
        }
    }

    tmpStr = (char *)kzalloc(255*2 + 1, GFP_KERNEL);
    if (!tmpStr) {
        hwlog_info("%s:Cannot allocate memory for write tmpStr.\n", __func__);
        mutex_unlock(&pdev->read_mutex);
        return -ENOMEM;
    }

    /* Read data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        /* #ifdef TMS_NFC */
        if (count == 1) {
            hwlog_info("%s: need2byte \n", __func__);
            need2byte = true;
            count = 2;    // read 2 bytes
        }
        /* #endif */

        clear_receive_data();
        char *sendData = (char *)kzalloc(count, GFP_KERNEL);
        (void*)memset_s(sendData, count, 0x00, count);
        ret = nfc_commu_send_msg(sendData, count, NFC_COMMUX_READ);
        kfree(sendData);
        if (ret != 0) {
            hwlog_err("%s : nfc_commu_send_msg fail, retry = %d, ret = %d\n", __func__, retry, ret);
            msleep(20);
            continue;
        }
        /* wait 2 HZ timeout for resume */
        ret = down_timeout(&nfc_read_data_sem, 2 * HZ);
        if (ret == -ETIME) {
            pr_err("%s: nfc_commu_data_semaphore sema timeout\n", __func__);
        }
        unsigned char* data = get_receive_data();
        ret = get_receive_data_len();
        if (memcpy_s(buf, MAX_BUFFER_SIZE, data, ret) != EOK) {
            hwlog_err("%s: memcpy_s data err", __func__);
            goto fail;
        }
        /* #ifdef TMS_NFC */
        if (need2byte) {
            count = 1;
            --ret;
        }
        /* #endif */
        for (i = 0; i < count; i++) {
            err = snprintf_s(&tmpStr[i * 2], sizeof(buf[i]) * 2 + 1, sizeof(buf[i]) * 2 + 1, "%02X", buf[i]);
            if (err < 0) {
                hwlog_err("%s: snprintf_s is failed\n", __func__);
            }
        }
        hwlog_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);
        g_pre_write_time = ktime_get_boottime();
        if (ret == (int)count) {
            is_success = true;
            break;
        } else {
            hwlog_err("%s : read data try =%d returned %d\n", __func__, retry, ret);
            msleep(1);
            continue;
        }
    }
    kfree(tmpStr);
    tmpStr = NULL;
    mutex_unlock(&pdev->read_mutex);
    if (false == is_success) {
        hwlog_err("%s : i2c_master_recv returned %d\n", __func__, ret);
        ret = -EIO;
    }
    return (size_t)ret;
fail:
    mutex_unlock(&pdev->read_mutex);
    return (size_t)ret;
}

static void thn31_ese_open(struct  thn31_dev *pdev)
{
    hwlog_err("%s : thn31_ese_open enter.", __func__);
    char buffer[ESE_SWITCH_NCI_LEN] = {0x22, 0x03, 0x02, 0xC0, 0x01};
    mutex_lock(&pdev->ese_switch_mutex_lock);
    int ret = nfc_commu_send_msg(buffer, ESE_SWITCH_NCI_LEN, NFC_COMMUX_WRITE);
    if (ret != 0) {
        hwlog_err("%s : nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
    }
    mutex_unlock(&pdev->ese_switch_mutex_lock);
}

static void thn31_ese_close(struct thn31_dev *pdev)
{
    hwlog_err("%s : thn31_ese_close enter.", __func__);
    char buffer[ESE_SWITCH_NCI_LEN] = {0x22, 0x03, 0x02, 0xC0, 0x00};
    mutex_lock(&pdev->ese_switch_mutex_lock);
    int ret = nfc_commu_send_msg(buffer, ESE_SWITCH_NCI_LEN, NFC_COMMUX_WRITE);
    if (ret != 0) {
        hwlog_err("%s : nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
    }
    mutex_unlock(&pdev->ese_switch_mutex_lock);
}

static int watch_thn31_dev_open(struct inode *inode, struct file *filp)
{
    struct thn31_dev *thn31_dev = container_of(filp->private_data,
                        struct thn31_dev, thn31_device);

    filp->private_data = thn31_dev;

    hwlog_info("%s : %d,%d\n", __func__, imajor(inode), iminor(inode));

    return 0;
}

static int watch_thn31_enable_nfc(struct thn31_dev *pdev)
{
    int ret = 0;
    char value = 0;
    /* enable chip */
    value = 1;
    ret = nfc_commu_send_msg(&value, 1, MODE_VEN_VALUE_SET_MSG);
    if (ret != 0) {
        hwlog_err("%s :  set ven:1 nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
        return ret;
    }
    msleep(20);

    value = 0;
    ret = nfc_commu_send_msg(&value, 1, MODE_VEN_VALUE_SET_MSG);
    if (ret != 0) {
        hwlog_err("%s : set ven:0 nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
        return ret;
    }
    msleep(20);

    value = 1;
    ret = nfc_commu_send_msg(&value, 1, MODE_VEN_VALUE_SET_MSG);
    if (ret != 0) {
        hwlog_err("%s : set ven:1-1 nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
        return ret;
    } 
    msleep(20);

    return ret;
}

static void watch_thn31_cleanup_and_hard_reset(struct thn31_dev *pdev)
{
    int ret;
    char value = 0;
    ret = nfc_commu_send_msg(&value, 1, MODE_DL_VALUE_SET_MSG);
    if (ret != 0) {
        hwlog_err("%s : set dwl:0 nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
        return;
    }
    msleep(10);

    ret = watch_thn31_enable_nfc(pdev);
    if (ret != NFC_OK) {
        hwlog_err("%s: hard reset nfc failed, ret:%d\n", __func__, ret);
    }
}

static int watch_thn31_soft_reset_to_bl_cmd(struct thn31_dev *pdev)
{
    int ret;
    const uint8_t soft_reset_cmd[] = {0x20, 0x00, 0x01, 0x80};
    const uint8_t soft_reset_rsp_prefix[] = {0x40, 0x00, 0x01};
    uint8_t recv_buf[MAX_NCI_BUFFER_SIZE] = {0};
    uint8_t payload_len;

    ret = watch_thn31_i2c_write(pdev, soft_reset_cmd, sizeof(soft_reset_cmd));
    if (ret < 0) {
        hwlog_err("Soft reset to bl: send cmd failed\n");
        return ret;
    }
    ret = watch_thn31_i2c_read(pdev, recv_buf, NCI_HEADER);
    if (ret < 0) {
        hwlog_err("Soft reset to bl: recv rsp header failed\n");
        return ret;
    }
    if (memcmp(recv_buf, soft_reset_rsp_prefix, sizeof(soft_reset_rsp_prefix)) != 0) {
        hwlog_err("Soft reset to bl: rsp prefix not match\n");
        return -EIO;
    }
    payload_len = recv_buf[NCI_LEN_INDEX];
    if (payload_len != 1) {
        hwlog_err("Soft reset to bl: rsp payload len is not 1\n");
        return -EIO;
    }
    ret = watch_thn31_i2c_read(pdev, recv_buf + NCI_HEADER, payload_len + 1);
    if (ret < 0) {
        hwlog_err("Soft reset to bl: recv rsp payload failed\n");
        return ret;
    }

    if (recv_buf[3] != 0x00) { // 400001 00
        hwlog_err("Soft reset to bl: rsp payload not match\n");
        return -EIO;
    }
    return 0;
}

static int watch_thn31_handle_fw_mode_response(const uint8_t *recv_buf)
{
    const uint8_t fw_rsp_prefix_dl[] = {0xA5, 0xC4};

    if (memcmp(recv_buf, fw_rsp_prefix_dl, sizeof(fw_rsp_prefix_dl)) == 0) {
        hwlog_info("Chip in FW mode, retrying...");
        return 1; // Retry
    }

    return -1;
}

static int watch_thn31_send_bl_reset_and_read_rsp(struct thn31_dev *pdev, uint8_t *bl_recv_buf)
{
    int ret;
    size_t bl_payload_len;
    const uint8_t bl_reset_cmd[] = {0x5A, 0xC4, 0x00, 0x9E};
    const uint8_t bl_rsp_prefix[] = {0xA5, 0xE4};

    ret = watch_thn31_i2c_write(pdev, bl_reset_cmd, sizeof(bl_reset_cmd));
    if (ret < 0) {
        hwlog_err("send bl cmd failed\n");
        return ret;
    }
    ret = watch_thn31_i2c_read(pdev, bl_recv_buf, T1_HDR_LEN);
    if (ret < 0) {
        hwlog_err("recv bl rsp header failed\n");
        return ret;
    }
    bl_payload_len = bl_recv_buf[T1_PAYLOAD_LEN_BYTE];
    if (bl_payload_len > MAX_T1_PAYLOAD_LEN) {
        hwlog_err("bl rsp payload len error\n");
        return -EINVAL;
    }
    ret = watch_thn31_i2c_read(pdev, bl_recv_buf + T1_HDR_LEN, bl_payload_len + T1_LRC_LEN);
    if (ret < 0) {
        hwlog_err("recv bl payload failed\n");
        return ret;
    }
    if (memcmp(bl_recv_buf, bl_rsp_prefix, sizeof(bl_rsp_prefix)) == 0) {
        return 0; /* Success */
    }
    return 1; /* Valid response, but not the expected one */
}

static int watch_thn31_soft_reset_to_bl(struct thn31_dev *pdev, unsigned int delay_ms)
{
    int i, ret = 0;
    int max_retries = 3;
    uint8_t bl_recv_buf[MAX_T1_BUFFER_SIZE] = {0};
    char value = 1;

    ret = nfc_commu_send_msg(&value, 1, MODE_DL_VALUE_SET_MSG);
    if (ret != 0) {
        hwlog_err("%s : set dwl:0 nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
        return ret;
    }
    msleep(10);

    for (i = 0; i < max_retries; i++) {
        ret = watch_thn31_soft_reset_to_bl_cmd(pdev);
        if (ret < 0)
            goto cleanup_and_reset;

        msleep(delay_ms);

        ret = watch_thn31_send_bl_reset_and_read_rsp(pdev, bl_recv_buf);
        if (ret == 0) {
            hwlog_info("Soft reset to bl successful\n");
            return 0;
        }
        if (ret < 0)
            goto cleanup_and_reset;

        ret = watch_thn31_handle_fw_mode_response(bl_recv_buf);
        if (ret > 0) { // Retry
            continue;
        }

        hwlog_err("Soft reset to bl: Unexpected BL response\n");
        goto cleanup_and_reset;
    }

cleanup_and_reset:
    watch_thn31_cleanup_and_hard_reset(pdev);
    return -1;
}

static int watch_thn31_hard_reset_to_bl(struct thn31_dev *pdev, unsigned int delay_ms)
{
    int i, ret = 0;
    int max_retries = 3;
    uint8_t bl_recv_buf[MAX_T1_BUFFER_SIZE] = {0};
    char value = 1;

    ret = nfc_commu_send_msg(&value, 1, MODE_DL_VALUE_SET_MSG);
    if (ret != 0) {
        hwlog_err("%s : set dwl:0 nfc_commu_send_msg fail, ret = %d\n", __func__, ret);
        return ret;
    }
    msleep(10); // 10 for sleep 10ms

    for (i = 0; i < max_retries; i++) {
        ret = watch_thn31_enable_nfc(pdev);
        if (ret < 0) {
            hwlog_err("Hard reset ven failed, retry\n");
            continue;
        }

        if (delay_ms > 20) {
            msleep(delay_ms - 20); // thn31_enable_nfc sleep 20ms, need delay_ms - 20
        } else {
            msleep(delay_ms);
        }

        ret = watch_thn31_send_bl_reset_and_read_rsp(pdev, bl_recv_buf);
        if (ret == 0) {
            hwlog_info("Hard reset to bl successful\n");
            return 0;
        }

        hwlog_info("Hard reset to bl: Retrying procedure (attempt %d/%d)...\n", i + 1, max_retries);
        continue;
    }

cleanup_and_reset:
    watch_thn31_cleanup_and_hard_reset(pdev);
    return -1;
}

static int watch_thn31_reset_to_bl(struct thn31_dev *pdev, unsigned long arg)
{
    int ret = 0;
    unsigned long delay_ms;
    unsigned long command;
    bool is_soft_reset;

    command = arg & 0xFFFF; // 0xFFFF for get command from lower 16 bits
    delay_ms = (arg >> 16) & 0xFFFF; // right shift 16 bits to get high bits

    if (delay_ms == 0 || delay_ms > 100) { // 100 for overflow 100ms
        hwlog_info("reset to bl: delay_ms=%u, defaulting to 70ms\n", delay_ms);
        delay_ms = RESET_TO_BL_MS;
    }
    is_soft_reset = (command == MODE_THN31_NFC_DLD_SOFT_RESET);

    hwlog_info("reset to bl: command=%u, delay_ms=%u\n", command, delay_ms);

    if (is_soft_reset) {
        ret = watch_thn31_soft_reset_to_bl(pdev, delay_ms);
    } else {
        ret = watch_thn31_hard_reset_to_bl(pdev, delay_ms);
    }

    return ret;
}

static long watch_thn31_dev_ioctl(struct file *filp,
                unsigned int cmd, unsigned long arg)
{
    hwlog_info("[%s,%d]:nfc thn31_dev_ioctl !\n", __func__, __LINE__);
    struct thn31_dev *thn31_dev = filp->private_data;
    char value = 0;
    int ret = 0;
    unsigned long command;
    switch (cmd) {
    case THN31_SET_PWR:
		command = arg & 0xFFFF; // 0xFFFF for get command from lower 16 bits
		hwlog_info("%s: arg = %lu, command = %lu\n", __func__, arg, command);
        if (command == MODE_THN31_VEN_HIGH) {
            value = 1;
            nfc_commu_send_msg(&value, 1, MODE_VEN_VALUE_SET_MSG);
        } else if (command == MODE_THN31_VEN_LOW) {
            nfc_commu_send_msg(&value, 1, MODE_VEN_VALUE_SET_MSG);
        } else if (command == MODE_THN31_FW_DWND_HIGH) {
            value = 1;
            nfc_commu_send_msg(&value, 1, MODE_DL_VALUE_SET_MSG);
        } else if (command == MODE_THN31_FW_DWND_LOW) {
            nfc_commu_send_msg(&value, 1, MODE_DL_VALUE_SET_MSG);
        } else if (command == MODE_THN31_NFC_DLD_FLUSH) {
            /*
            * release blocked user thread waiting for pending read
            */
            if (!mutex_trylock(&thn31_dev->read_mutex)) {
                thn31_dev->release_read = true;
                watch_thn31_disable_irq(thn31_dev);
                wake_up(&thn31_dev->read_wq);
                pr_err("%s: waiting for release of blocked read\n", __func__);
                mutex_lock(&thn31_dev->read_mutex);
                thn31_dev->release_read = false;
            } else {
                pr_err("%s: read thread already released\n", __func__);
            }
            mutex_unlock(&thn31_dev->read_mutex);
        } else if (command == MODE_THN31_NFC_DLD_SOFT_RESET || command == MODE_THN31_NFC_DLD_HARD_RESET) {
            ret = watch_thn31_reset_to_bl(thn31_dev, arg);
            return ret;           
        }
        else {
            hwlog_err("%s bad arg %lu\n", __func__, arg);
            return -EINVAL;
        }
        break;
    case THN31_OPEN_ESE:
		thn31_ese_open(thn31_dev);
		return 0;
    case THN31_CLOSE_ESE:
		thn31_ese_close(thn31_dev);
		return 0;
    default:
        hwlog_err("%s bad ioctl %u\n", __func__, cmd);
        return -EINVAL;
    }

    return 0;
}

static const struct file_operations watch_thn31_dev_fops = {
    .owner = THIS_MODULE,
    .llseek = no_llseek,
    .read = watch_thn31_dev_read,
    .write = watch_thn31_dev_write,
    .open = watch_thn31_dev_open,
    .unlocked_ioctl = watch_thn31_dev_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = watch_thn31_dev_ioctl,
#endif
};

void watch_thn31_free_irq(void)
{
    free_irq(nfcdev->irq, nfcdev);
}

void watch_thn31_reconfig_irq(void)
{
    int ret;
    nfcdev->irq_enabled = true;
    ret = request_irq(nfcdev->irq, watch_thn31_dev_irq_handler,
                 IRQF_TRIGGER_HIGH | IRQF_NO_SUSPEND, nfcdev->pdev->name, nfcdev);
    if (ret) {
        hwlog_err("[%s,%d]:soc gpio request_irq nfcdev->irq=%d failed,ret=%d\n", __func__, __LINE__, nfcdev->irq, ret);
        gpio_free(nfcdev->irq_gpio);
        free_irq(nfcdev->irq, nfcdev);
        nfcdev->irq_enabled = true;
        request_irq(nfcdev->irq, watch_thn31_dev_irq_handler,
                 IRQF_TRIGGER_HIGH | IRQF_NO_SUSPEND, nfcdev->pdev->name, nfcdev);
    }
    hwlog_info("[%s] success\n", __func__);
}

/* lint -restore */
/* lint -save -e* */
static int watch_thn31_probe(struct platform_device *pdev)
{

    int ret;
    struct thn31_dev *thn31_dev = NULL;
    hwlog_info("[%s,%d]:watch nfc probe start !\n", __func__, __LINE__);
    if (!of_match_device(thn31_i2c_dt_ids, &pdev->dev)) {
        hwlog_err("[%s,%d]: nfc_bj NFC match fail !\n", __func__, __LINE__);
        return -ENODEV;
    }
    register_watch_mcu_nfc_callback();

    get_ext_gpio_type();
    get_nfc_on_type();
    get_nfc_svdd_sw();
    get_wake_lock_timeout();
    get_nfc_wired_ese_type();
    ret = ese_ca_parse_dt();
    hwlog_info("[%s]:ese_ca_parse_dt ret =%d\n", __func__, ret);
    ret = create_sysfs_interfaces(&pdev->dev);
    if (ret < 0) {
        hwlog_err("[%s,%d]:Failed to create_sysfs_interfaces\n", __func__, __LINE__);
        return -ENODEV;
    }
    ret = sysfs_create_link(NULL, &pdev->dev.kobj, "nfc");
    if (ret < 0) {
        hwlog_err("[%s,%d]:Failed to sysfs_create_link\n", __func__, __LINE__);
        return -ENODEV;
    }
    thn31_dev = kzalloc(sizeof(*thn31_dev), GFP_KERNEL);
    if (thn31_dev == NULL) {
        hwlog_err("[%s,%d]:failed to allocate memory for module data\n", __func__, __LINE__);
        ret = -ENOMEM;
        goto err_exit;
    }

    /* get clk ,gpio,supply resource from dts */
    hwlog_info("%s:watch_thn31_get_resource start !\n", __func__);
    ret = watch_thn31_get_resource(thn31_dev, pdev);
    if (ret < 0) {
        hwlog_err("[%s,%d]: nfc_bj probe get resource failed ret:%d\n", __func__, __LINE__, ret);
        goto err_thn31_get_resource;
    }

    thn31_dev->pdev = kzalloc(sizeof(*pdev), GFP_KERNEL);
    if (thn31_dev == NULL) {
        hwlog_err("[%s,%d]:failed to allocate memory for thn31_dev->pdev\n", __func__, __LINE__);
        ret = -ENOMEM;
        goto err_exit;
    }
    ret = memcpy_s((char *)thn31_dev->pdev, sizeof(*pdev), (char *)pdev, sizeof(*pdev));
    if (ret != EOK) {
        hwlog_err("%s memcpy_s pdev fail\n", __func__);
    }
    nfcdev = thn31_dev;
    thn31_dev->release_read = false;
    get_nfc_gt_boost();
    get_nfc_chip_type();

    /* init mutex and queues */
    init_waitqueue_head(&thn31_dev->read_wq);
    mutex_init(&thn31_dev->read_mutex);
    spin_lock_init(&thn31_dev->irq_enabled_lock);

    mutex_init(&thn31_dev->irq_mutex_lock);
    mutex_init(&thn31_dev->ese_recover_mutex_lock);
    mutex_init(&thn31_dev->ese_switch_mutex_lock);

    /* Initialize wakelock */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
    wlock_read = wakeup_source_register(&pdev->dev, "nfc_read");
#else
    wakeup_source_init(&wlock_read, "nfc_read");
#endif
    /* register thn31 char device */
    thn31_dev->thn31_device.minor = MISC_DYNAMIC_MINOR;
    thn31_dev->thn31_device.name = "nfc_dg";
    thn31_dev->thn31_device.fops = &watch_thn31_dev_fops;
    ret = misc_register(&thn31_dev->thn31_device);
    if (ret) {
        hwlog_err("[%s,%d]: misc_register failed\n", __func__, __LINE__);
        goto err_misc_register;
    }
    /* request irq.  the irq is set whenever the chip has data available
      * for reading.  it is cleared when all data has been read.
    */
    thn31_dev->irq_enabled = true;
    ret = gpio_request(thn31_dev->irq_gpio, NULL);
    if (ret < 0) {
        hwlog_err("[%s,%d]: gpio_request failed, ret:%d.\n", __func__, __LINE__,
            thn31_dev->irq_gpio);
        goto err_misc_register;
    }
    ret = gpio_direction_input(thn31_dev->irq_gpio);
    if (ret < 0) {
        hwlog_err("[%s,%d]: Fail set gpio as input, irq_gpio:%d.\n", __func__, __LINE__,
            thn31_dev->irq_gpio);
        goto err_request_irq_failed;
    }
    if (g_nfc_ext_gpio & IRQ_EXTENTED_GPIO_MASK) {
        hwlog_info("%s:request_threaded_irq start !\n", __func__);
        thn31_dev->irq = gpio_to_irq(thn31_dev->irq_gpio);
        ret = request_threaded_irq(thn31_dev->irq, NULL,
                watch_thn31_dev_irq_handler,
                IRQF_TRIGGER_HIGH | IRQF_NO_SUSPEND, pdev->name, thn31_dev);
        if (ret < 0) {
            hwlog_err("[%s,%d]:ext gpio request_irq thn31_dev->irq=%d failed,ret=%d\n", __func__, __LINE__, thn31_dev->irq, ret);
            goto err_request_irq_failed;
        }
        hwlog_err("[%s,%d]:request_irq thn31_dev->irq=%d success,ret=%d\n", __func__, __LINE__, thn31_dev->irq, ret);
        watch_thn31_disable_irq_for_ext_gpio(thn31_dev);
    } else {
        thn31_dev->irq = gpio_to_irq(thn31_dev->irq_gpio);
        hwlog_info("%s:request_irq start !\n", __func__);
        ret = request_irq(thn31_dev->irq, watch_thn31_dev_irq_handler,
                IRQF_TRIGGER_HIGH | IRQF_NO_SUSPEND, pdev->name, thn31_dev);
        if (ret) {
            hwlog_err("[%s,%d]:soc gpio request_irq thn31_dev->irq=%d failed,ret=%d\n", __func__, __LINE__, thn31_dev->irq, ret);
            goto err_request_irq_failed;
        }
        watch_thn31_disable_irq(thn31_dev);
    }

    tms_set_nfc_nxp_config_name();
    tms_set_nfc_brcm_config_name();
    tms_set_nfc_chip_type_name();
    tms_set_nfc_single_channel();
    tms_set_nfc_spec_rf();
    tms_get_nfc_delaytime_set();
    tms_get_nfc_delaytime_node();
    tms_set_nfc_card_num();
    tms_set_nfc_ese_num();
    tms_set_nfc_sim2_omapi();
    get_nfc_pmu_clock_switch();
    nfc_is_recovery_mode();

    /* set probe flag: nxp success */
    set_nfc_dmd_probe_flag(NFC_PN547_PROBE_SUCCESS);
    hwlog_info("[%s,%d]: probe end !\n", __func__, __LINE__);
    return 0;
err_request_irq_failed:
    gpio_free(thn31_dev->irq_gpio);
err_misc_register:
    misc_deregister(&thn31_dev->thn31_device);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
    wakeup_source_unregister(wlock_read);
    wlock_read = NULL;
#else
    wakeup_source_trash(&wlock_read);
#endif
    mutex_destroy(&thn31_dev->read_mutex);
err_thn31_get_resource:
    kfree(thn31_dev);
err_exit:
    hwlog_err("[%s,%d]: err_nfc_bj_get_resource sysfs_remove_link \n", __func__, __LINE__);
    sysfs_remove_link(NULL, "nfc");
    remove_sysfs_interfaces(&pdev->dev);
    /* set probe flag: nxp failed */
    set_nfc_dmd_probe_flag(NFC_PN547_PROBE_FAIL);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
    timer_setup(&nfc_dmd_probe_timer, nfc_record_dmd_probe_timerhandler, 0);
#else
    setup_timer(&nfc_dmd_probe_timer, nfc_record_dmd_probe_timerhandler, 0);
#endif
    nfc_dmd_probe_timer.expires = jiffies + NFC_DMD_PROBE_TIMER;
    add_timer(&nfc_dmd_probe_timer);

    return ret;
}


static int watch_thn31_remove(struct platform_device *pdev)
{
    struct thn31_dev *thn31_dev = NULL;
    int ret = 0;

    hwlog_info("[%s]: %s removed !\n", __func__, g_nfc_chip_type);
    thn31_dev = dev_get_drvdata(&pdev->dev);
    if (thn31_dev == NULL) {
        hwlog_err("%s:    nfc_bj_dev == NULL!\n", __func__);
        goto out;
    }
    free_irq(thn31_dev->irq, thn31_dev);
    misc_deregister(&thn31_dev->thn31_device);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
    wakeup_source_unregister(wlock_read);
    wlock_read = NULL;
#else
    wakeup_source_trash(&wlock_read);
#endif
    mutex_destroy(&thn31_dev->read_mutex);

    remove_sysfs_interfaces(&pdev->dev);
    if (thn31_dev->nfc_clk) {
        clk_put(thn31_dev->nfc_clk);
        thn31_dev->nfc_clk = NULL;
        ret = pinctrl_select_state(thn31_dev->pctrl, thn31_dev->pins_idle);
        if (ret < 0)
            hwlog_err("%s: unapply new state!\n", __func__);
    }
    kfree(thn31_dev);
    if (g_is_gtboost) {
        ret = boost_5v_enable(BOOST_5V_DISABLE, BOOST_CTRL_NFC);
        if (ret)
            hwlog_err("%s: boost_5v disable failed\n", __func__);
        else
            hwlog_info("%s: boost_5v disable succeeded\n", __func__);
    }
    del_timer(&nfc_dmd_probe_timer);
out:
    return 0;
}

struct semaphore *get_nfc_read_data_sem(void)
{
    return &nfc_read_data_sem;
}

static struct of_device_id thn31_platform_dt_ids[] = {
    {.compatible = "hisilicon,thn31_nfc" },
    {}
};

MODULE_DEVICE_TABLE(of, thn31_platform_dt_ids);

static struct platform_driver watch_thn31_driver = {
    .probe = watch_thn31_probe,
    .remove = watch_thn31_remove,
    .driver = {
        .owner = THIS_MODULE,
        .name = "thn31",
        .of_match_table = of_match_ptr(thn31_platform_dt_ids),
    },
};

static int __init thn31nfc_dev_init(void)
{
    printk("%s: init nfc commu semaphore!\n", __func__);
    sema_init(&nfc_read_data_sem, 0);

    printk("%s: Loading thn31nfc driver\n", __func__);
    return platform_driver_register(&watch_thn31_driver);
}

static void __exit thn31nfc_dev_exit(void)
{
    platform_driver_unregister(&watch_thn31_driver);
}

module_init(thn31nfc_dev_init);
module_exit(thn31nfc_dev_exit);
