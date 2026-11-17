 
 
#ifndef _AMAX_DPA_CLIENT_H
#define _AMAX_DPA_CLIENT_H

#ifdef CONFIG_HW_WIFI_AMAX

typedef struct {
    unsigned char throughput;
    unsigned char latency;
    unsigned char packetnumber;
} threshold_desc;

typedef struct {
    threshold_desc desc;
    unsigned int sendmode;
    int fn_main;
} amax_client_dfx;

typedef void (*sync_ioctl_func)(int cmd);
typedef void (*sync_mode_func)(unsigned int sendmode);
typedef void (*sync_thres_func)(unsigned char throughput, unsigned char latency, unsigned char packetnumber);
typedef void (*sync_main_fn_func)(int fn_main);

extern void dpa_amax_control_register(sync_ioctl_func func);
extern void dpa_send_mode_register(sync_mode_func func);
extern void dpa_set_threshold_register(sync_thres_func func);
extern void dpa_main_fn_register(sync_main_fn_func func);
#endif

void amax_dpa_client_init(void);
void amax_dpa_client_exit(void);

#endif