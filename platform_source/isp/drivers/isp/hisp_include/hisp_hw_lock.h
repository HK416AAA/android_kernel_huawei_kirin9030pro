#ifndef HISP_HW_LOCK_H
#define HISP_HW_LOCK_H

#ifdef CONFIG_ISP_MEM_LIFECYCLE
int hisp_hw_lock_init(void);
void hisp_hw_lock_exit(void);
int hisp_hw_lock_get(void);
void hisp_hw_lock_put(void);
#else
static inline int hisp_hw_lock_init(void) {return 0;}
static inline void hisp_hw_lock_exit(void) {return;}
static inline int hisp_hw_lock_get(void) {return 0;}
static inline void hisp_hw_lock_put(void) {return;}
#endif

#endif /* HISP_HW_LOCK_H */
