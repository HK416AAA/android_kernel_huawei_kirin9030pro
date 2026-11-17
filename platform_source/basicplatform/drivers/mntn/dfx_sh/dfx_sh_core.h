#ifndef __DFX_SH_CORE_H__
#define __DFX_SH_CORE_H__

void sh_wakeup_source_register(void);
void sh_wakeup_source_unregister(void);

int sh_thread_body(void *arg);

void sh_tbc_init(void);
void sh_del_timer(void);

#endif /* __DFX_SH_CHECK_H__ */
