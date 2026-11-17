

/*
 * 1 Other header include
 */
#ifndef __NPHY_SCHED_OM_DEF_H__
#define __NPHY_SCHED_OM_DEF_H__

#include "uphy_om_interface.h"/*lint !e537*/
#include "neun_basedef_macro.h"/*lint !e537*/
#include "neun_hl1c_ll1d_interface.h"
#include "neun_sdra_msg.h"
#include "uphy_trace_interface.h"/*lint !e537*/
#include "uphy_om_def.h"/*lint !e537*/

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*
 * 2. Macro definitions
 */
#define NPHY_MAX_SYMBOL_INT_NUM                         4 /* MAX Symbol INT number for each slot */

#define NPHY_MAX_DCI_NUM                                7
#define NPHY_MAX_PDS_NUM                                3
#define NPHY_MAX_CSI_NUM                                2
#define NPHY_MAX_DCI_FUNC_NUM                           8
#define NPHY_SCHED_MBX_FUN_NUM                          20

#define NPHY_L1D_SCHED_FUNC_NUM                         24

/*
 * 3. Enumerations declarations
 */



/*
 * 5. SG 数据结构定义, 算法需要绘图的
 */
typedef struct {
    UPHY_TRACE_Header   header;
    uint32_t            funcNum;
    UPHY_TRACE_TaskData data[NPHY_L1D_SCHED_FUNC_NUM];
} NPHY_OM_Ll1dCycleRpt;


/*
 * Struct Description: 邮箱发送核 ID
 */
enum NPHY_DL_MailSrcId {
    NPHY_DL_HL1C_L = 0,
    NPHY_DL_HL1C_H,
    NPHY_DL_SDR,
    NPHY_DL_CORE_ERR_BUTT
};

typedef uint8_t NPHY_DL_MailSrcIdUint08;

/*
 * Struct Description: 邮箱cycle统计
 */
typedef struct {
    NPHY_DL_MailSrcIdUint08 srcPid;
    uint8_t rsv;
    uint16_t cycleCount;
    NEUN_L1C_L1dMsgTypeUint32 l1cMsgId;
    NEUN_LL1C_SdrMSG sdrMsgId;
} NPHY_SCHED_DlFunInfo;

/*
 * Struct Description: 邮箱cycle统计
 */
typedef struct {
    UPHY_TRACE_Header   header;
    uint8_t funcNum;
    uint8_t modemId;
    uint16_t totalCycle;
    NPHY_SCHED_DlFunInfo func[NPHY_SCHED_MBX_FUN_NUM];
} NPHY_SCHED_MailCounter;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* #ifndef __NPHY_SCHED_OM_DEF_H__ */
