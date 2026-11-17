

#ifndef UL1M_FLPM_OM_DEF_H
#define UL1M_FLPM_OM_DEF_H

/* 1 其他头文件包含 */
#include "fess_shared.h"
#include "uphy_basedef_data.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push, 4)

/* 2 宏定义 */
/* 低功耗trace记录条数，根据实际需求进行调整 */
#define UL1M_FLPM_OM_TRACE_LPC_LEN     64

/* RFIC最大个数 */
#define UL1M_FLPM_MAX_RFIC_NUM          2

/* 3 枚举定义 */

/* 4 STRUCT定义 */
/* 结构说明:低功耗trace的维测状态信息具体内容 */
typedef struct {
    uint16_t fileId;
    uint16_t lineNo;
    uint32_t data;                   /* 记录的具体的log数据 */
} UL1M_FLPM_OmTraceLpcBuf;

/* 结构说明:低功耗trace的维测状态信息 */
typedef struct {
    uint32_t              currntPos; /* 当前buf的位置 */
    uint32_t              totalCnt;  /* 总的记录条数 */
    UL1M_FLPM_OmTraceLpcBuf buffer[UL1M_FLPM_OM_TRACE_LPC_LEN];
} UL1M_FLPM_OmTraceLpc;

/* 结构说明: 低功耗消息上报信息 */
typedef struct {
    uint8_t             rficId;
    uint8_t             resv0;
    uint16_t            resv1;
    uint32_t            timeStampIn32k;
} UL1M_FLPM_OmCommInfo;

/* 结构说明: 低功耗消息上报信息 */
typedef struct {
    uint8_t             rficId;
    uint8_t             resv0;
    uint16_t            resv1;
    uint32_t            timeStampIn32k;
    uint32_t            deepVoteInfo[UL1M_FLPM_MAX_RFIC_NUM][FESS_MODEM_ID_BUTT];
} UL1M_FLPM_OmVoteInfo;

/* 结构说明: HIDS下发消息配置 */
typedef struct {
    UPHY_ValidUint32   enableFlag;
} UL1M_FLPM_OmReq;

/* 结构说明: RFRESET检测异常时上报信息 */
typedef struct {
    uint32_t excpId;         /* 异常原因 */
    uint32_t detectExcpTime; /* 首次检测到异常的时间, 对应收到excp_ind, 单位32K时钟个数 */
} UL1M_FLPM_OmExceptionInd;

/* 结构说明: RFRESET开始处理异常时上报信息 */
typedef struct {
    uint16_t rficInd;
    uint8_t  fessRunStatus; /* 指示是否低功耗稳态, 0 -- 非稳态, 1 -- 稳态 */
    uint8_t  resetStatus;   /* RFRESET状态, 0 -- 初始态, 1 -- reseting, 2 -- reset finish */
    uint32_t procStartTime; /* RFRESET启动时间, 对应收到RCM的rf_reset_req, 单位32K时钟个数 */
} UL1M_FLPM_OmRfResetReq;

/* 结构说明: RFRESET结束处理异常时上报信息 */
typedef struct {
    uint8_t  fessRunStatus; /* 指示是否低功耗稳态, 0 -- 非稳态, 1 -- 稳态 */
    uint8_t  resetStatus;   /* RFRESET状态, 0 -- 初始态, 1 -- reseting, 2 -- reset finish */
    uint16_t reserved;      /* 保留位 */
    uint16_t resetCounter;  /* 在子系统自恢复正常前, 连续进行的RFRESET次数 */
    uint16_t resetTimeOut;  /* RFRESET是否等待超时 */
    uint32_t procEndTime;   /* RFRESET完成时间, 对应收到RFM的rf_reset_cnf, 单位32K时钟个数 */
    uint32_t procUseTime;   /* RFRESET耗时, 单位32K时钟个数 */
} UL1M_FLPM_OmRfResetCnf;

/* 5 UNION定义 */

/* 6 消息头定义 */

/* 7 消息定义 */

/* 8 OTHERS定义 */

/* 9 全局变量声明 */

/* 10 函数声明 */

#pragma pack(pop)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

