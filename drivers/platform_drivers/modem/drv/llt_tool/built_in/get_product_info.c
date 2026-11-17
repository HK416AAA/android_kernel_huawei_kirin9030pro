#include <linux/fs.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <bsp_version.h>
#include <bsp_print.h>
#include <osl_malloc.h>
#include <securec.h>
#include "return_code.h"

#define VERSION_INFO_SIZE 512

char *st_get_product_info(void)
{
    char *info = (char *)osl_malloc(VERSION_INFO_SIZE);
    const bsp_version_info_s *version_info = bsp_get_version_info();
    int fmt_length;
    const char *pattern = "{\
    \"product_id\": %u, \"product_id_udp_masked\": %u, \"product_id_with_board_id\": %u,\
    \"base_board_id\": %u, \"udp_flag\": %u, \"chip_version\": %u,\
    \"version_magic\": %hu, \"chip_type\": %hu, \"plat_type\": %u,\
    \"plat_info\": %u, \"cses_type\": %u, \"board_type\": %u,\
    \"product_type\": %u, \"chip_level\": %u\
}";

    if (info == NULL) {
        bsp_err("malloc failed\n");
        return NULL;
    }

    if (version_info == NULL) {
        bsp_err("get version info failed\n");
        return NULL;
    }

    memset(info, 0, VERSION_INFO_SIZE);

    fmt_length = sprintf_s(info, VERSION_INFO_SIZE, pattern,
                           version_info->product_id, version_info->product_id_udp_masked,
                           version_info->product_id_with_board_id,
                           version_info->base_board_id, version_info->udp_flag, version_info->chip_version,
                           version_info->version_magic, version_info->chip_type, version_info->plat_type,
                           version_info->plat_info, version_info->cses_type, version_info->board_type,
                           version_info->product_type, version_info->chip_level);
    if (fmt_length == VERSION_INFO_SIZE || fmt_length <= 0) {
        bsp_err("format version info failed\n");
        return NULL;
    }

    return info;
}
