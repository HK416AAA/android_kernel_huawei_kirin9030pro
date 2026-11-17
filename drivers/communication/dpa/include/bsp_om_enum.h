/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

#ifndef __BSP_OM_ENUM_H__
#define __BSP_OM_ENUM_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief DPA HOST各组件复位modid, 用于system_error接口，若需新增modid, 请在此处添加,host和fw需保持一致
 */
typedef enum {
    DRV_ERRNO_START = 0x0,
    DRV_ERRNO_AP_DETECT_DPA_QIC = 0xb,
    DRV_ERRNO_OTHER_CORE = 0xe,
    // 从0x1000开始添加, 0x1000之前保留
    DRV_ERRNO_DUMP_PROCESSOR_EXC = 0x1000,
    DRV_ERRNO_WDT = 0x1001,
    DRV_ERRNO_DPA_QIC = 0x1002,
    DRV_ERRNO_MDMPERI_QIC = 0x1003,
    DRV_ERRNO_RST_FAIL = 0x1004,
    DRV_ERRNO_DPA_RESET = 0x1005,
    DRV_ERRNO_MDMPERI_PDLOCK = 0x1006,
    DRV_ERRNO_DPM = 0x1007,                       /* dpm error */
    DRV_ERRNO_PM_SR = 0x1008,                     /* pm error */
    DRV_ERRNO_SMS_GRO = 0x1009,
    DRV_ERRNO_DMI = 0x100a,
    DRV_ERRNO_DPA_PDLOCK = 0x100b,
    DRV_ERRNO_DRA = 0x100c,
    DRV_ERRNO_DRA_MEM = 0x100d,
    DRV_ERRNO_DPA_FREQ = 0x100e,
    DRV_ERRNO_DPA_RESET_TEST_NORMALRST = 0x0000fffd, /* 0xfffd */
    DRV_ERRNO_DPA_RESET_TEST = 0x0000fffe, /* 0xfffe */
    DRV_ERRNO_BUTT = 0x0000ffff,
    /**< 其他组件的modid在此处分段添加 */
    WLAN_ERRNO_START = 0x10000,
    WLAN_ERRNO_DMI_EXCEP = 0x10001,
    WLAN_ERRNO_BUTT = 0x1ffff,
    NSTACK_ERRNO_START = 0x20000,
    NSTACK_ERRNO_STACK = 0x20001,
    NSTACK_ERRNO_BUTT = 0x2ffff,
    BOOSTER_ERRNO_START = 0x30000,
    BOOSTER_ERRNO_BUTT = 0x3ffff,
} om_errno_enum;

/**
 * @brief 申请, 查询维测内存使用的field_id
*
 * @attention
 * <ul><li> field id定义只允许添加，不允许删除，枚举定义删除之后，id值需要保留，新添加id需要跳过删除id </li></ul>
 * <ul><li> 添加DPA FW新的field，放到OM_DPAFW_FIELD_END之前 </li></ul>
 */
typedef enum {
    /**< dpa host ids, host中申请的维测内存，需要在此添加field_id */
    OM_DPAHOST_FIELD_BEGIN = 0x10000000,
    OM_DPAHOST_DPA_RESET_FW = (0x10000001),
    OM_DPAHOST_SYS_RESET = (0x10000002),
    OM_DPAHOST_DPA_RESET = (0x10000003),
    OM_DPAHOST_DPA_QIC = (0x10000004),
    OM_DPAHOST_DPA_PDLOCK = (0x10000005),
    OM_DPAHOST_DRA = (0x10000006),
    OM_DPAHOST_FIELD_DPA_FIPC = (0x10000007),
    OM_DPAHOST_SYSCACHE = (0x10000008),
    OM_DPAHOST_DWS = (0x10000009),
    OM_DPAHOST_BOOT_DUMP = (0x1000000a),
    OM_DPAHOST_RPM = (0x1000000b),
    OM_DPAHOST_DMI = (0x1000000c),
    OM_DPAHOST_DPA_RFILE = (0x1000000d),
    OM_DPAHOST_IPC_CTRL = (0x1000000e),
    OM_DPAHOST_FIELD_DPA_IPCMSG = (0x1000000f),
    OM_DPAHOST_SECBOOT = (0x10000010),

    /**< 10100000-101fffff modid划分给WLAN业务 */
    OM_DPAHOST_WLAN_FIELD_BEGIN = 0x10100000,
    OM_DPAHOST_WLAN_FIELD_END = 0x101fffff,

    /**< 10fff000-10ffffff modid划分给OM业务 */
    OM_DPAHOST_BASE_INFO = 0x10fff000,
    OM_DPAHOST_KO_DUMP = 0x10fff001,
    OM_DPAHOST_USER_DATA = 0x10fff002,
    OM_DPAHOST_APR = 0x10fff003,
    OM_DPAHOST_THREAD_REGS = 0x10fff004,
    OM_DPAHOST_DSS_REGS = 0x10fff005,
    OM_DPAHOST_MPSS_REGS = 0x10fff006,
    OM_DPAHOST_FIELD_DMESG = (0x10fff007),
    OM_DPAHOST_FIELD_RECORD = (0x10fff008),
    OM_DPAHOST_FIELD_LTRACE0 = (0x10fff009),
    OM_DPAHOST_FIELD_LTRACEX = (0x10fff018),
    OM_DPAHOST_FIELD_END = 0x10ffffff,

    /**< DPA FW FIELD IDs, 需要与FW中定义的ID保持一致，按需添加 */
    OM_DPAFW_FIELD_BEGIN = 0x11000000,
    OM_DPAFW_IPC_CTRL = (0x11000001),
    OM_DPAFW_NMI = (0x11000002),
    OM_DPAFW_SYS_RESET = (0x11000003),
    /**< 11fff000-11ffffff modid划分给OM业务 */
    OM_DPAFW_BASE_INFO = 0x11fff000,
    OM_DPAFW_CPUINFO_START = 0x11fff001, // 最大规格16thread预留field
    OM_DPAFW_CPUINFO_END = 0x11fff010,
    OM_DPA_TASK_SWITCH_START = 0x11fff011,
    OM_DPA_TASK_SWITCH_END = 0x11fff020,
    OM_DPAFW_TASK_TCB = 0x11fff021,
    OM_DPAFW_REBOOTCONTEX = 0x11fff022,
    OM_DPAFW_DUMP_DEBUG = 0x11fff023,
    OM_DPAFW_USER_DATA = 0x11fff024,
    OM_DPAFW_EXCINFO = 0x11fff025,
    OM_DPAFW_DMESG = 0x11fff026,
    OM_DPAFW_RECORD = 0x11fff027,
    OM_DPAFW_RTOSCK = 0x11fff028,
    OM_DPAFW_SYSSTACK = 0x11fff029,
    OM_DPAFW_WDT = 0x11fff02a,
    OM_DPAFW_LTRACE0 = (0x11fff02b),
    OM_DPAFW_LTRACEX = (0x11fff040),
    OM_DPAFW_DPA_QIC = (0x11000042),
    OM_DPAFW_DPA_PDLOCK = (0x11000043),
    OM_DPAFW_FIELD_END = 0x11ffffff,
    // teeos field
    OM_DPA_TEEOS_FIELD_BEGIN = 0x12000000,
    OM_DPA_TEEOS_FIELD_END = 0x12ffffff,
    // lpmcu field
    OM_DPA_LPMCU_FIELD_BEGIN = 0x13000000,
    OM_DPA_LPMCU_FIELD_END = 0x13ffffff,
} om_filed_id_enum;

#ifdef __cplusplus
}
#endif

#endif /* __BSP_OM_ENUM_H__ */
