#ifndef ADRV_STUB_H
#define ADRV_STUB_H

static inline bool dpa_uid_match_stub(uid_t kuid)
{
    return false;
}
extern void sock_offload_func_register(void *func);

#endif
