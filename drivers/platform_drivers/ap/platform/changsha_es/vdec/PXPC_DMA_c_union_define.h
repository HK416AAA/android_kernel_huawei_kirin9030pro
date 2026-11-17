#ifndef __PXPC_DMA_C_UNION_DEFINE_H__
#define __PXPC_DMA_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int syscache_buf_saddr : 29 ;
        unsigned int reserved_0 : 3 ;
    } bits;
    unsigned int u32;
} U_SYS_CACHE_BUF_SADDR;
typedef union {
    struct {
        unsigned int syscache_buf_len : 13 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_SYS_CACHE_BUF_LEN;
typedef struct {
    volatile unsigned int reserved_0[3] ;
    volatile U_SYS_CACHE_BUF_SADDR SYS_CACHE_BUF_SADDR ;
    volatile U_SYS_CACHE_BUF_LEN SYS_CACHE_BUF_LEN ;
} S_PXPC_DMA_REGS_TYPE;
extern volatile S_PXPC_DMA_REGS_TYPE *gopPXPC_DMAAllReg;
int iSetSYS_CACHE_BUF_SADDRsyscache_buf_saddr(unsigned int usyscache_buf_saddr);
#endif
