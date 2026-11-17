#include <linux/string.h>
#include <bsp_version.h>
#include <bsp_print.h>
#include <securec.h>
#include "return_code.h"
#include "file_option.h"

#define MAX_READ_BUFF_SIZE 32
#define PHONE_STATE_NUM 4
#define ACORE_DIRECTORY "/data"
#define MODEM_STATE_NODE "/sys/devices/platform/modem_power/state"

enum st_core_state {
    // acore state
    ACORE_STATE_NOT_READY = 100,
    ACORE_STATE_READY,

    // mcore state
    MCORE_STATE_NOT_READY = 110,
    MCORE_STATE_READY,

    // ccore state
    CCORE_STATE_NOT_READY = 120,
    CCORE_STATE_READY,

    UNRECOGNIZED
};

static const char *const g_st_ccore_state_str[PHONE_STATE_NUM] = {
    "MODEM_STATE_READY",
    "MODEM_STATE_OFF",
    "MODEM_STATE_INIT_OK",
    "MODEM_STATE_INVALID",
};

extern int mdrv_sysboot_is_modem_ready(void);

int get_acore_state(void)
{
    // open dir in fs
    if (open_directory(ACORE_DIRECTORY) == ACORE_SUCCESS) {
        return ACORE_STATE_READY;
    }
    return ACORE_STATE_NOT_READY;
}

int get_mcore_state(void)
{
    if (get_acore_state() == ACORE_STATE_READY) {
        return MCORE_STATE_READY;
    }
    return MCORE_STATE_NOT_READY;
}

int get_ccore_state(void)
{
    int ret;
    const bsp_version_info_s* version_info = bsp_get_version_info();

    if (version_info == NULL) {
        bsp_err("get version info failed\n");
        return -ACORE_FAIL;
    }

    ret = mdrv_sysboot_is_modem_ready();
    if (ret == 0) {
        return CCORE_STATE_NOT_READY;
    }
    return CCORE_STATE_READY;
}
