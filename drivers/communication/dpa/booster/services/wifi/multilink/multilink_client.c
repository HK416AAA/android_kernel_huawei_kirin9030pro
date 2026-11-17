

#ifdef CONFIG_HW_WIFI_AMAX

#include <linux/printk.h>
#include "booster_dmi_client.h"
#include "booster_features.h"
#include "multilink_client.h"
 
#define SEND_MODE_LEN 4
#define DEFAULT_LEN 1
char default_data[DEFAULT_LEN] = {0x01};
amax_client_dfx dfx = {0};

// start/stop feature
void sync_amax_ioctl_cmd(int cmd)
{
    if (cmd == MULTILINK_START || cmd == MULTILINK_STOP) {
        booster_dpa_request_async(DPA_AMAX_FEATURE, cmd, default_data, DEFAULT_LEN);
    }
    printk(KERN_INFO "[dpa_amax] sync_amax_ioctl_cmd: %d \n", cmd);
}

// add sync_amax_send_mode() in amax_multilink_main.c set_send_mode_param
void sync_amax_send_mode(unsigned int sendmode)
{
    dfx.sendmode = sendmode;
    booster_dpa_request_async(DPA_AMAX_FEATURE, SYNC_SEND_MODE, (unsigned char *)(&dfx.sendmode), sizeof(unsigned int));
    printk(KERN_INFO "[dpa_amax] sync_amax_send_mode: %d \n", sendmode);
}

// set_threshold
void sync_threshold(unsigned char throughput, unsigned char latency, unsigned char packetnumber)
{
    dfx.desc.throughput = throughput;
    dfx.desc.latency = latency;
    dfx.desc.packetnumber = packetnumber;
    booster_dpa_request_async(DPA_AMAX_FEATURE, SYNC_THRESHOLD, (unsigned char *)(&dfx.desc), sizeof(threshold_desc));
    printk(KERN_INFO "[dpa_amax] sync_threshold \n");
}

// hook in amax_get_main_dev_fn
void sync_main_fn(int fn_main)
{
    dfx.fn_main = fn_main;
    booster_dpa_request_async(DPA_AMAX_FEATURE, SYNC_MAIN_FN, (unsigned char *)(&dfx.fn_main), sizeof(int));
    printk(KERN_INFO "[dpa_amax] sync_main_fn: %d \n", fn_main);
}

void amax_dpa_client_init(void)
{
    dpa_amax_control_register(sync_amax_ioctl_cmd);
    dpa_send_mode_register(sync_amax_send_mode);
    dpa_set_threshold_register(sync_threshold);
    dpa_main_fn_register(sync_main_fn);
    printk(KERN_INFO "[dpa_amax] multilink client init \n");
}

#else

#include <linux/printk.h>
void amax_dpa_client_init(void)
{
    printk(KERN_INFO "[dpa_amax] not define CONFIG_HW_WIFI_AMAX, not initial. \n");
}

#endif

void amax_dpa_client_exit(void)
{
    printk(KERN_INFO "[dpa_amax] multilink client exit \n");
}