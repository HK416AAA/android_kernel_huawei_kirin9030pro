
#ifndef DPA_CHR_WEB_STAT_H
#define DPA_CHR_WEB_STAT_H

#include "bsp_dpa_chr.h"
#ifdef CONFIG_CHR_NETLINK_MODULE
#include <hwnet/chr/wbc_hw_hook.h>
#endif
#include "dpa_chr_info.h"

#ifdef CONFIG_CHR_NETLINK_MODULE
struct http_return* get_dpa_chr_web_info(void);
struct statics_by_rat* get_dpa_chr_web_info_by_rat(void);
int dpa_web_chr_init(void);
void dpa_chr_rtt_dmi_client_init(void);
#else
#include <linux/in6.h>
static inline int dpa_web_chr_init(void)
{
    return 0;
}
void set_stream_list(void)
{
}
int get_data_reg_tech(void)
{
    return 0;
}
#endif
void upload_web_info(void);
#endif  // DPA_CHR_WEB_STAT_H