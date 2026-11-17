/*
 * 版权所有 (c) 华为技术有限公司 2019-2019
 * 功能描述 : LTEV WMC OM接口文件
 * 作     者 : miqiushi
 * 生成日期 : 2019年10月24日
 * 修改历史 :
 * 1. 2019年10月24日, miqiushi, 创建文件
 */

/*
 * 1 其他头文件包含
 */
#ifndef __D2D_WMC_OM_DEF_H__
#define __D2D_WMC_OM_DEF_H__

#include  "neun_basedef_struct.h"
#include  "d2d_basedef_struct.h"
#include  "uphy_basedef_func.h"
#include "d2d_agc_om_def.h"
#include "d2d_afc_om_def.h"
#include  "d2d_tru_om_def.h"
#include  "d2d_fec_om_def.h"
#include  "neun_wmc_om_def.h"
#include "d2d_comm_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(push, 4)

/*
 * 2 宏定义
 */
#define D2D_MAX_MODEM_NUM                  1
#define D2D_WMC_MAX_CARRIER_NUM            1                                      /* 支持的最大载波数 */
#define D2D_WMC_EVT_TAB_MAX                (12 + 6)                               /* WMC表格中有效请求个数，表格新增请求时要同步增加 */
#define D2D_WMC_PROCESS_BUTT               (NEUN_LTEV_PROCESS_END - NEUN_LTEV_DAEMON_PROCESS)                                    /* ltev 过程最大数量定义 */
#define D2D_WMC_RECORD_ERR_MAX             30                                     /* 记录错误的buffer大小 */
#define D2D_WMC_EVT_REQ_BUF_MAX            6                                      /* 1次符号中断允许调用发送WMC 事件请求的最大次数 */
#define D2D_WMC_EVT_REQ_CTRL_BUF_MAX       (D2D_WMC_EVT_REQ_BUF_MAX * 2)     /* 请求控制buffer的最大空间，考虑强制删除场景重新设置请求控制的情况 */
#define D2D_WMC_INTRA_PROC_MAX             3                                      /* 同频过程同时激活个数 */
#define D2D_WMC_INTER_PROC_MAX             0                                      /* 异频过程个数 */
#define D2D_WMC_ALIVE_PROCESS_MAX          D2D_WMC_INTRA_PROC_MAX            /* Process给出的有效Process(非删除)的最大个数7,再加上2个预留的 */
#define D2D_WMC_INVALID_PROC_ID            0xff


/*
 * 3 枚举定义
 */
/*
 * 枚举说明: wmc上报错误类型枚举
 */

enum D2D_WMC_OmMsg {
    D2D_WMC_TRACE_RPT_B_INFO = D2DPHY_OM_L1MSG_ID(D2DPHY_MODULE_ID_WMC, 0x01),
    D2D_WMC_TRACE_RPT_B_CTRL_INFO,
    D2D_WMC_TRACE_RPT_C_INFO,
    D2D_WMC_TRACE_RPT_PROC_INFO,
    D2D_WMC_TRACE_RPT_ERROR_INFO,
    D2D_WMC_TRACE_RPT_FASTB_INFO,
    D2D_WMC_TRACE_RPT_B_DATA_INFO,
};
typedef uint32_t D2D_WMC_OmMsgUint32;


enum D2D_WMC_ErrorType {
    D2D_WMC_NO_ERROR               = 1,
    D2D_WMC_EVTREQ_INPUT_ERR_IDX,     /* 02 */
    D2D_WMC_EVTREQ_INPUT_ERR_BUFMAX,  /* 03 */
    D2D_WMC_EVTREQ_INPUT_ERR_TYPE,    /* 04 */
    D2D_WMC_EVTREQ_INPUT_ERR_TIME,    /* 05 */
    D2D_WMC_EVTREQ_INPUT_ERR_CCMAX,   /* 06 */
    D2D_WMC_EVTREQ_INPUT_ERR_PROCID,  /* 07 */
    D2D_WMC_SCHE_INPUT_ERR_BUFMAX,    /* 08 */
    D2D_WMC_INIT_INPUT_ERR_IDX,       /* 09 */
    D2D_WMC_SCANREQ_PARA_ERR_IDX,     /* 10 */
    D2D_WMC_ONEPROC_CONFLICT,         /* 11 */
    D2D_WMC_ONEPROC_HOLD_CONFLICT,    /* 12 */
    D2D_WMC_ONEPROC_REL_CONFLICT,     /* 13 */
    D2D_WMC_ONEPROC_SAME_REQ_CONFLICT, /* 14 */
    D2D_WMC_ONEPROC_DIFF_REQ_CONFLICT, /* 15 */
    D2D_WMC_ALLPROC_CONFLICT,         /* 16 */
    D2D_WMC_SENDACTION_BUFMAX,        /* 17 */
    D2D_WMC_SENDCAACTION_BUFMAX,      /* 18 */
    D2D_WMC_SENDMODE_BUFMAX,          /* 19 */
    D2D_WMC_ALIVE_PROC_NUM_OVERFLOW1, /* 20 */
    D2D_WMC_ALIVE_PROC_NUM_OVERFLOW2, /* 21 */
    D2D_WMC_ALIVE_PROC_NOT_EXIST,     /* 22 */
    D2D_WMC_FEC_HOLCUR_INPUT_ERR,     /* 23 */
    D2D_WMC_FAST_EVTREQ_INPUT_ERR_IDX, /* 24 */
    D2D_WMC_MBX_NOT_SEND_FOR_DL_POWER_DOWN, /* 25 */
    D2D_WMC_NO_CC_SOURCE,
    D2D_WMC_ERROR_TYPE_BUTT
};
typedef UPHY_UINT08 D2D_WMC_ErrorTypeUint08;

/*
 * 枚举说明: 子帧数据类型
 */
enum D2D_WMC_DataType {
    D2D_WMC_DATA_NULL              = 0,
    D2D_WMC_DATA_INTRA_VALID,              /* 同频有效 */
    D2D_WMC_DATA_TYPE_BUTT
};
typedef UPHY_UINT08 D2D_WMC_DataTypeUint08;

/*
 * 枚举说明: Event和workmode 表索引
 */
enum D2D_WMC_ComModule {
    D2D_WMC_AGC_TAB_IDX                = 0,
    D2D_WMC_AFC_TAB_IDX,
    D2D_WMC_TRU_TAB_IDX,
    D2D_WMC_FEC_TAB_IDX,
    D2D_WMC_REQ_TYPE_IDX,
    D2D_WMC_SUPPORT_COM_MODULE_MAX_BUTT = D2D_WMC_REQ_TYPE_IDX     /* WMC 目前支持的最大公共模块个数 */
};
typedef UPHY_UINT08 D2D_WMC_ComModuleUint08;

/*
 * 枚举说明: wmc模块各模块工作模式状态
 */
enum D2D_WMC_ModeType {
    D2D_WMC_NULL_MODE               = 0,
    D2D_WMC_REQ_MODE,
    D2D_WMC_CUR_MODE,
    D2D_WMC_MODE_UPDATE_TYPE_BUTT
};
typedef UPHY_UINT08 D2D_WMC_ModeTypeUint08;

/*
 * 枚举说明: B接口中发送的请求的类型
 */
enum D2D_WMC_EvtReqSort {
    D2D_WMC_NULL_REQ                   = 0,
    D2D_WMC_MODE_REQ,
    D2D_WMC_MODE_REL_REQ,
    D2D_WMC_MODE_UNHOLD_REQ,
    D2D_WMC_MODE_HOLD_REQ,
    D2D_WMC_ACT_REQ,
    D2D_WMC_EVT_REQ_TYPE_BUTT
};
typedef UPHY_UINT08 D2D_WMC_EvtReqSortUint08;

/*
 * 6 STRUCT定义
 */
/*
 * 结构说明: WMC给LL1C公共模块的INTERFACE C接口的结构体定义
 */
typedef struct {
    UPHY_UINT08                             agcWorkModeReq;   /* 当前Mode/Action Req */
    UPHY_UINT08                             fecWorkModeReq;   /* 当前Mode/Action Req */
    UPHY_UINT08                             truWorkModeReq;   /* 当前Mode/Action Req */
    UPHY_UINT08                             afcWorkModeReq;   /* 当前Mode/Action Req */
} D2D_WMC_CModeInfo;

/*
 * 结构说明: agc工作模式结构体定义
 */
typedef struct {
    D2D_AGC_WorkModeReqUint08                             curMode;      /* 当前该过程工作模式 */
    D2D_AGC_WorkModeReqUint08                             oldMode;      /* 上一次该过程的工作模式 */
    D2D_AGC_WorkModeReqUint08                             reqMode;      /* 新要请求的该过程工作模式 */
    D2D_AGC_WorkModeReqUint08                             reqAction;    /* 新要请求的该过程Action */

    D2D_AGC_WorkModeReqUint08                             oldAction;    /* 上一次该过程的Action */
    D2D_AGC_WorkModeReqUint08                             curSendMode;  /* 当前子帧发送出去的Mode */
    D2D_AGC_WorkModeReqUint08                             schedRelMode; /* 预约删除的Mode */
    D2D_AGC_WorkModeReqUint08                             schedReqMode; /* 预约建立的Mode以及立即生效的删除消息 */
} D2D_WMC_AgcWorkMode;

/*
 * 结构说明: afc工作模式结构体定义
 */
typedef struct {
    D2D_AFC_WorkModeUint08                             curMode;      /* 当前该过程工作模式 */
    D2D_AFC_WorkModeUint08                             oldMode;      /* 上一次该过程的工作模式 */
    D2D_AFC_WorkModeUint08                             reqMode;      /* 新要请求的该过程工作模式 */
    D2D_AFC_WorkModeUint08                             reqAction;    /* 新要请求的该过程Action */

    D2D_AFC_WorkModeUint08                             oldAction;    /* 上一次该过程的Action */
    D2D_AFC_WorkModeUint08                             curSendMode;  /* 当前子帧发送出去的Mode */
    D2D_AFC_WorkModeUint08                             schedRelMode;
    D2D_AFC_WorkModeUint08                             schedReqMode;
} D2D_WMC_AfcWorkMode;

/*
 * 结构说明: tru工作模式结构体定义
 */
typedef struct {
    D2D_TRU_WorkModeReqUint08                    curMode;      /* 当前该过程工作模式 */
    D2D_TRU_WorkModeReqUint08                    oldMode;      /* 上一次该过程的工作模式 */
    D2D_TRU_WorkModeReqUint08                    reqMode;      /* 新要请求的该过程工作模式 */
    D2D_TRU_WorkModeReqUint08                    reqAction;    /* 新要请求的该过程Action */

    D2D_TRU_WorkModeReqUint08                    oldAction;    /* 上一次该过程的Action */
    D2D_TRU_WorkModeReqUint08                    curSendMode;  /* 当前子帧发送出去的Mode */
    D2D_TRU_WorkModeReqUint08                    schedRelMode;
    D2D_TRU_WorkModeReqUint08                    schedReqMode;
} D2D_WMC_TruWorkMode;

/*
 * 结构说明: fec工作模式结构体定义
 */
typedef struct {
    NEUN_FEC_WorkModeReqUint08                    curMode;      /* 当前该过程工作模式 */
    NEUN_FEC_WorkModeReqUint08                    oldMode;      /* 上一次该过程的工作模式 */
    NEUN_FEC_WorkModeReqUint08                    reqMode;      /* 新要请求的该过程工作模式 */
    NEUN_FEC_WorkModeReqUint08                    reqAction;    /* 新要请求的该过程Action */

    NEUN_FEC_WorkModeReqUint08                    oldAction;    /* 上一次该过程的Action */
    NEUN_FEC_WorkModeReqUint08                    schedRelMode;
    NEUN_FEC_WorkModeReqUint08                    schedReqMode;
    UPHY_UINT08                             res;
} D2D_WMC_FecWorkMode;
/*
 * 结构说明: B5000NPHY_TRU_FLAG_STRU待模块上库后修改
 */
typedef struct {
    UPHY_UINT08                              fpuRstFlag;           /* CC 的FPU复位切定时标志 */
    UPHY_UINT08                              blindTimeSwitchFlag;  /* bandscan或者小区初搜时盲切定时标志 */
    UPHY_UINT08                              ssbSwitchFlag;        /* 根据SSB/DEM通路参数变化判断公共模块模式是否重新发送 */
    UPHY_UINT08                              demSwitchFlag;        /* 根据SSB/DEM通路参数变化判断公共模块模式是否重新发送 */

    UPHY_UINT08                              measSwitchFlag;       /* 根据SSB/DEM通路参数变化判断公共模块模式是否重新发送 */
    UPHY_UINT08                              rsv[3];
} D2D_TRU_Flag;

/*
 * 结构说明: WMC的告警信息结构体定义
 */
typedef struct {
    UPHY_UINT16                                 wmcErrNum;                                /* 累计错误个数 */
    D2D_WMC_ErrorTypeUint08                wmcErrType[D2D_WMC_RECORD_ERR_MAX];  /* 错误类型 */
} D2D_WMC_ErrorInfo;


/*
 * 结构说明: 各公共模块工作模式结构体定义
 */
typedef struct {
    D2D_WMC_AgcWorkMode                    agcWorkMode;
    D2D_WMC_AfcWorkMode                    afcWorkMode;
    D2D_WMC_TruWorkMode                    truWorkMode;
    D2D_WMC_FecWorkMode                    fecWorkMode;
} D2D_WMC_WorkMode;

/*
 * 结构说明: wmc中过程状态结构体定义
 */
typedef struct {
    NEUN_PROCESS_IdUint08                              proId;            /* Process ID */
    UPHY_UINT08                                 proBufId;         /* buffer id */
    NEUN_WMC_EvtReqTypeUint16                         oldEvt;           /* 已经处理的Mode Event */

    NEUN_WMC_EvtReqTypeUint16                         newEvt;           /* 新要处理的Mode Event */
    D2D_WMC_EvtReqSortUint08               oldReqSort;       /* 上一次请求的REQ类型 */
    D2D_WMC_EvtReqSortUint08               newReqSort;       /* 新请求的REQ类型 */

    NEUN_WMC_ProcActFlagUint08                  actFlag;          /* NPHY_WMC_PROC_ACT_FLAG_ENUM_UINT08 */
    UPHY_UINT08                                 changeWorkMode;   /* 当前子帧是否要改变WorkMode */
    UPHY_UINT08                                 reqMismatch;      /* 新要处理是否匹配已经处理的请求，不匹配则为NPHY_TRUE */
    UPHY_UINT08                                 newValidModeReq;  /* 当前子帧是否有新的有效workmode请求 */

    UPHY_UINT08                                 inRelShedTime;    /* 此过程目前处于预约删除阶段 */
    UPHY_UINT08                                 res[3];

    D2D_WMC_WorkMode                       workMode;
} D2D_WMC_ProcStatusInfo;

/*
 * 结构说明: 小区信息结构体
 */
typedef struct {
    NEUN_CELL_TypeUint08                               cellType;        /* 小区类型分别对应Cell ID */
    UPHY_UINT08                                 res;
    UPHY_UINT16                                 cellId;

    UPHY_UINT32                                 freqInfo;        /* 小区频点 */
} D2D_WMC_CellSubInfo;

/*
 * 结构说明: 小区相关信息结构体
 */
typedef struct {
    UPHY_UINT32                                 sceneBM;
    D2D_WMC_CellSubInfo                    curCellInfo;
    D2D_WMC_CellSubInfo                    afcOldCellInfo;
    D2D_WMC_CellSubInfo                    curServeCellInfo;
    D2D_WMC_CellSubInfo                    oldServeCellInfo;
    D2D_WMC_CellSubInfo                    curInterCellInfo;
    D2D_WMC_CellSubInfo                    oldInterCellInfo;
    D2D_WMC_CellSubInfo                    truOldCellInfo;
    UPHY_UINT16                                 mainTainServFreqId; /* Tru停止维护服务区帧号维护_频点 */
    UPHY_UINT16                                 mainTainServCellId; /* Tru停止维护服务区帧号维护_Cell */
} D2D_WMC_CellInfo;

/*
 * 结构说明: 预调度目标时间戳
 */
typedef struct {
    UPHY_UINT08                             res[3];
    UPHY_SINT08                             targetSlot;       /* 本CC mode请求的预约目标时间 */
    UPHY_UINT32                             mc;
} D2D_WMC_TargetTimeInfo;

/*
 * 结构说明: 多过程状态结构体
 */
typedef struct {
    UPHY_UINT08                                 aliveProcNum;     /* 当前子帧没有释放的Process个数 */
    UPHY_UINT08                                 relProcNum;       /* 当前子帧释放的Process个数 */
    UPHY_UINT08                                 changeWorkMode;   /* 当前子帧是否要改变WorkMode */
    NEUN_WMC_ProcActFlagUint08                  allProcActFlag;

    D2D_WMC_WorkMode                       finalMode;
    D2D_WMC_BData                          finalData;
} D2D_WMC_AllProcStatusInfo;

/*
 * 结构说明: 数据有效信息结构体
 */
typedef struct {
    UPHY_UINT08                                 nextDataValid;
    UPHY_UINT08                                 lastDataValid;
    UPHY_UINT08                                 curDataValid;
    UPHY_UINT08                                 mfrmValid;

    UPHY_UINT08                                 tddType;
    UPHY_UINT08                                 res[3];
} D2D_WMC_DataValidInfo;

/*
 * 结构说明: 低功耗下电时记录HOLD的Process信息
 */
typedef struct {
    NEUN_PROCESS_IdUint08                              proId;            /* Process ID */
    UPHY_UINT08                                 res;
    NEUN_WMC_EvtReqTypeUint16                         holdEvt;          /* 下电之前接收到的Hold请求 */
} D2D_WMC_PowerSaveProcInfo;

/*
 * 结构说明: WMC过程WMC维护的和过程相关的结构体定义
 */
typedef struct {
    D2D_WMC_AllProcStatusInfo              allProcStatus;
    NEUN_WMC_ProcStatusInfo                     procStatus[D2D_WMC_ALIVE_PROCESS_MAX];
    D2D_WMC_BInfo                          procEvtReqBuf[D2D_WMC_ALIVE_PROCESS_MAX];

    /* Process 有效信息buffer ID 连续从0存储 */
    UPHY_UINT08                                 validProcBufIdx[D2D_WMC_ALIVE_PROCESS_MAX];
    UPHY_UINT08                                 res;
    /* Process 删除信息buffer ID 连续从0存储 */
    UPHY_UINT08                                 relProcBufIdx[D2D_WMC_ALIVE_PROCESS_MAX];
    UPHY_UINT08                                 sendMode;             /* 记录当前CC是否已经发送了workmode */
} D2D_WMC_ProcInfo;

/*
 * 结构说明: C接口fec信息结构体
 */
typedef struct {
    NEUN_SAMPLE_SelTypeUint08                   fecDlSampleRate;  /* afc/tru Dl Cc采样率 */
    UPHY_UINT08                                 rsv[3];
    D2D_TRU_Flag                           fecFpuRstFlg;     /* afc tru Rst flag 最后使用模块清除 */
} D2D_FEC_CData;

/*
 * 结构说明: C接口信息结构体
 */
typedef struct {
    UPHY_UINT08                                 curModeNum;       /* 当前子帧WMC申请的Mode Req总数，WMC发一条Req时加1。 */
    UPHY_UINT08                                 curActionNum;     /* 当前子帧WMC申请的Action Req总数，WMC发一条Req时加1。 */
    UPHY_UINT08                                 res[2];

    D2D_WMC_CModeInfo                      wmcCMode;         /* WMC产生的各公共模块WorkMode */
    D2D_WMC_BData                          wmcBData;         /* Process给WMC的请求数据 */
    D2D_FEC_CData                          fecCData;         /* 各公共模块统一使用FEC接口 */
    D2D_WMC_TimeStamp                      reqTimStamp;      /* 请求发送的时间戳 */
} D2D_WMC_CInfo;

/*
 * 结构说明: WMC的cc公共信息结构体定义
 */
typedef struct {
    /* 当前子帧所有Process申请的Event Req总数，每个Process要发一条Event Req时加1。WMC提供全局接口。 */
    UPHY_UINT08                                 curEvtReqNum;
    UPHY_UINT08                                 curActReqNum;
    UPHY_UINT08                                 scsType;
    UPHY_UINT08                                 res;
} D2D_WMC_CommCcInfo;

/*
 * 结构说明: HL1C给LL1c发送邮箱消息的结构体定义
 */
typedef struct {
    D2D_L1cL1dMsgTypeUint32                msgId;
    D2D_WMC_CInfo                          modeReqBuf;     /* WMC给公共模块的INTERFACE C 数据buffer */
} D2D_WMC_MbxInfo;

/*
 * 结构说明: WMC中modem相关的结构体定义
 */
typedef struct {
    NEUN_MODEM_IdUint08                          modemIndex;
    UPHY_UINT08                                 maxCcNum;
    UPHY_UINT08                                 part1Ctr;
    UPHY_UINT08                                 part2Ctr;

    UPHY_UINT16                                 *evtBlankTab;
    const UPHY_UINT08                           *evt2WorkModeTab;
    const UPHY_UINT08                           *caWorkModeTab;

    UPHY_UINT08                                 curEvtReqNum;     /* 当前子帧所有Process申请的Event Req总。 */
    UPHY_UINT08                                 curActReqNum;     /* 当前子帧所有Process申请的Event Req总。 */
    UPHY_UINT08                                 part1ReqValid;
    UPHY_UINT08                                 res;

    UPHY_UINT32                                 totalEvtReqNum;
    NEUN_WMC_CommCcInfo                         ccCommInfo;
    D2D_WMC_ErrorInfo                      wmcErrInfo;
    /* 上面总共30节 */
    D2D_WMC_BInfo                          wmcEvtReqBuf[D2D_WMC_EVT_REQ_BUF_MAX];         /* Process给WMC的请求数据 */
    NEUN_WMC_BCtrlInfo                     wmcEvtReqCtrl;                                 /* REQ 控制信息 */
    D2D_WMC_BInfo                          wmcActionReqBuf[D2D_WMC_EVT_REQ_BUF_MAX];
    D2D_WMC_MbxInfo                        wmcMbxInfo;                                     /* Hl1c给LL1C的邮箱信息 */
    D2D_WMC_ProcInfo                      *wmcProcInfo;                                    /* WMC维护的和过程相关的状态参数指针 */
} D2D_WMC_ModemInfo;

/*
 * 结构说明: 接口B相关请求信息上报结构体定义
 */
typedef struct {
    NEUN_WMC_OmPbulicVal                        publicVal;
    D2D_WMC_BInfo                          evtReqBuf;     /* Process给WMC的请求数据 */
} D2D_WMC_OmRptB;

/*
 * 结构说明: WMC过程WMC维护的和过程相关的结构体定义
 */
typedef struct {
    D2D_WMC_AllProcStatusInfo              allProcStatus;
    NEUN_WMC_ProcStatusInfo                     procStatus[D2D_WMC_ALIVE_PROCESS_MAX];

    UPHY_UINT08                                 sendMode;             /* 记录当前CC是否已经发送了workmode */
    UPHY_UINT08                                 res[3];
} D2D_WMC_ProcOmRpt;

/*
 * 8 OTHERS定义
 */
typedef UPHY_VOID(*D2D_WMC_WorkModeProc)(const D2D_WMC_CInfo   *cData);

#pragma pack(pop)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of __D2D_OM_DEF_H__ */

