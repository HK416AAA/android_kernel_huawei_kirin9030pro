#ifndef __IPC_AO_C_UNION_DEFINE_H__
#define __IPC_AO_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int source : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_SOURCE;
typedef union {
    struct {
        unsigned int dset : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_DSET;
typedef union {
    struct {
        unsigned int dclear : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_DCLEAR;
typedef union {
    struct {
        unsigned int dstatus : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_DSTATUS;
typedef union {
    struct {
        unsigned int autoAnswer : 1;
        unsigned int autoLink : 1;
        unsigned int reserved0 : 2;
        unsigned int stateStatus : 4;
        unsigned int reserved1 : 24;
    } bits;
    unsigned int u32;
} U_MBX_MODE;
typedef union {
    struct {
        unsigned int intMask : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_IMASK;
typedef union {
    struct {
        unsigned int intClear : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_ICLR;
typedef union {
    struct {
        unsigned int send : 2;
        unsigned int reserved : 30;
    } bits;
    unsigned int u32;
} U_MBX_SEND;
typedef union {
    struct {
        unsigned int data0 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA0;
typedef union {
    struct {
        unsigned int data1 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA1;
typedef union {
    struct {
        unsigned int data2 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA2;
typedef union {
    struct {
        unsigned int data3 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA3;
typedef union {
    struct {
        unsigned int data4 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA4;
typedef union {
    struct {
        unsigned int data5 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA5;
typedef union {
    struct {
        unsigned int data6 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA6;
typedef union {
    struct {
        unsigned int data7 : 32;
    } bits;
    unsigned int u32;
} U_MBX_DATA7;
typedef union {
    struct {
        unsigned int intMaskStatus : 3;
        unsigned int reserved : 29;
    } bits;
    unsigned int u32;
} U_CPU_IMST;
typedef union {
    struct {
        unsigned int intRawStatus : 3;
        unsigned int reserved : 29;
    } bits;
    unsigned int u32;
} U_CPU_IRST;
typedef union {
    struct {
        unsigned int mbxActiveStatus : 3;
        unsigned int reserved : 29;
    } bits;
    unsigned int u32;
} U_IPC_MBX_ACTIVE;
typedef union {
    struct {
        unsigned int ipcLock : 32;
    } bits;
    unsigned int u32;
} U_IPC_LOCK;
typedef struct {
    U_MBX_SOURCE MBX_SOURCE;
    U_MBX_DSET MBX_DSET;
    U_MBX_DCLEAR MBX_DCLEAR;
    U_MBX_DSTATUS MBX_DSTATUS;
    U_MBX_MODE MBX_MODE;
    U_MBX_IMASK MBX_IMASK;
    U_MBX_ICLR MBX_ICLR;
    U_MBX_SEND MBX_SEND;
    U_MBX_DATA0 MBX_DATA0;
    U_MBX_DATA1 MBX_DATA1;
    U_MBX_DATA2 MBX_DATA2;
    U_MBX_DATA3 MBX_DATA3;
    U_MBX_DATA4 MBX_DATA4;
    U_MBX_DATA5 MBX_DATA5;
    U_MBX_DATA6 MBX_DATA6;
    U_MBX_DATA7 MBX_DATA7;
} U_IPC_MBX_REGS;
typedef struct {
    U_CPU_IMST CPU_IMST;
    U_CPU_IRST CPU_IRST;
} U_IRQ_STATUS_REGS;
typedef struct {
    U_IPC_MBX_REGS IPC_MBX_REGS[17];
    unsigned int reserved0[240];
    U_IRQ_STATUS_REGS IRQ_STATUS_REGS[8];
    unsigned int reserved1[48];
    U_IPC_MBX_ACTIVE IPC_MBX_ACTIVE;
    unsigned int reserved2[63];
    U_IPC_LOCK IPC_LOCK;
} S_IPC_AO_REGS_TYPE;
#endif
