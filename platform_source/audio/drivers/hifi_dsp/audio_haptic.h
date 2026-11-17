#ifndef __AUDIO_HAPTIC_H__
#define __AUDIO_HAPTIC_H__

#include "audio_ddr_map.h"

#ifdef CONFIG_AUDIO_HAPTIC
#define get_haptic_share_buf_phyaddr() DSP_HAPTIC_DATA_BUF_ADDR
#define get_haptic_share_buf_size() DSP_HAPTIC_DATA_BUF_SIZE
unsigned char *get_haptic_share_buf_virtaddr(void);
#else
#define get_haptic_share_buf_phyaddr() 0
#define get_haptic_share_buf_size() 0
static inline unsigned char *get_haptic_share_buf_virtaddr(void)
{
    return NULL;
}

#endif

typedef void(*audio_haptic_switch_path_cb)(bool is_succ);
#ifdef CONFIG_AUDIO_HAPTIC_UEVENT
int audio_haptic_switch_path(bool is_path_open);
int audio_haptic_switch_path_cb_register(audio_haptic_switch_path_cb callback);
int audio_haptic_config_done(uintptr_t arg);
#else
static inline int audio_haptic_switch_path(bool is_path_open, audio_haptic_switch_path_cb callback)
{
    return 0;
}

static inline int audio_haptic_switch_path_cb_register(uintptr_t arg)
{
    return 0;
}

static inline int audio_haptic_config_done(uintptr_t arg)
{
    return 0;
}
#endif
#endif
