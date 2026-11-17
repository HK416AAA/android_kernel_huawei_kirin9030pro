#include <bsp_version.h>
#include <bsp_print.h>
#include <securec.h>
#include "return_code.h"
#include "file_option.h"

enum dss_id {
    DSS_0 = 0,
    DSS_1,
    DSS_2,
    DSS_3
};

extern void pm_wakeup_ccore(unsigned int dss_id, int flag);

int wakeup_ccore(unsigned int flag)
{
    const bsp_version_info_s* version_info = bsp_get_version_info();

    if (version_info == NULL) {
        bsp_err("get version info failed\n");
        return -ACORE_FAIL;
    }

    pm_wakeup_ccore(DSS_0, flag);           
    if (version_info->chip_type == CHIP_B510) {
        pm_wakeup_ccore(DSS_1, flag);
        pm_wakeup_ccore(DSS_2, flag);
        pm_wakeup_ccore(DSS_3, flag);
    }

    return ACORE_SUCCESS;
}
