#ifndef __SOC_FCM_KARMA_INTERFACE_H__
#define __SOC_FCM_KARMA_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_KARMA_KARMA_GLOBAL_ENABLE_ADDR(base) ((base) + (0x0000UL))
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ADDR(base) ((base) + (0x0004UL))
#define SOC_FCM_KARMA_DCPTABLECONTROL_ADDR(base) ((base) + (0x0008UL))
#define SOC_FCM_KARMA_DCPBASICCONTROL_ADDR(base) ((base) + (0x000CUL))
#define SOC_FCM_KARMA_REPCONTROLCONTROL_ADDR(base) ((base) + (0x0010UL))
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ADDR(base) ((base) + (0x0014UL))
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADDR(base) ((base) + (0x0018UL))
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_ADDR(base) ((base) + (0x001CUL))
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_ADDR(base) ((base) + (0x0020UL))
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_ADDR(base) ((base) + (0x0024UL))
#define SOC_FCM_KARMA_ADBbasiccontrol_ADDR(base) ((base) + (0x0028UL))
#define SOC_FCM_KARMA_ADBefficiencyTH_ADDR(base) ((base) + (0x002CUL))
#define SOC_FCM_KARMA_ADBDMCcontrol_ADDR(base) ((base) + (0x0030UL))
#define SOC_FCM_KARMA_clearcontrol_ADDR(base) ((base) + (0x0034UL))
#define SOC_FCM_KARMA_BEADPthreshold1_ADDR(base) ((base) + (0x0038UL))
#define SOC_FCM_KARMA_BEADPthreshold2_ADDR(base) ((base) + (0x003CUL))
#define SOC_FCM_KARMA_BEADPthreshold3_ADDR(base) ((base) + (0x0040UL))
#define SOC_FCM_KARMA_BEADPthreshold4_ADDR(base) ((base) + (0x0044UL))
#define SOC_FCM_KARMA_BEADPthreshold5_ADDR(base) ((base) + (0x0048UL))
#define SOC_FCM_KARMA_KARMAstatus_ADDR(base) ((base) + (0x004CUL))
#define SOC_FCM_KARMA_BEADPstatus1_ADDR(base) ((base) + (0x0050UL))
#define SOC_FCM_KARMA_BEADPstatus2_ADDR(base) ((base) + (0x0054UL))
#define SOC_FCM_KARMA_BEADPstatus3_ADDR(base) ((base) + (0x0058UL))
#define SOC_FCM_KARMA_systemconfiguration_ADDR(base) ((base) + (0x005CUL))
#define SOC_FCM_KARMA_PMEVCNTRN_EL0_ADDR(base,n) ((base) + (0x1000+(n)*8UL))
#define SOC_FCM_KARMA_PMCCNTR_EL0_LOW_ADDR(base) ((base) + (0x10F8UL))
#define SOC_FCM_KARMA_PMCCNTR_EL0_HIGH_ADDR(base) ((base) + (0x10FCUL))
#define SOC_FCM_KARMA_PMEVTYPERN_EL0_ADDR(base,n) ((base) + (0x1400+(n)*4UL))
#define SOC_FCM_KARMA_PMCNTENSET_EL0_ADDR(base) ((base) + (0x1C00UL))
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_ADDR(base) ((base) + (0x1C20UL))
#define SOC_FCM_KARMA_PMOVSCLR_EL0_ADDR(base) ((base) + (0x1C80UL))
#define SOC_FCM_KARMA_PMOVSSET_EL0_ADDR(base) ((base) + (0x1CC0UL))
#define SOC_FCM_KARMA_PMCR_EL0_ADDR(base) ((base) + (0x1E04UL))
#else
#define SOC_FCM_KARMA_KARMA_GLOBAL_ENABLE_ADDR(base) ((base) + (0x0000))
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ADDR(base) ((base) + (0x0004))
#define SOC_FCM_KARMA_DCPTABLECONTROL_ADDR(base) ((base) + (0x0008))
#define SOC_FCM_KARMA_DCPBASICCONTROL_ADDR(base) ((base) + (0x000C))
#define SOC_FCM_KARMA_REPCONTROLCONTROL_ADDR(base) ((base) + (0x0010))
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ADDR(base) ((base) + (0x0014))
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADDR(base) ((base) + (0x0018))
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_ADDR(base) ((base) + (0x001C))
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_ADDR(base) ((base) + (0x0020))
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_ADDR(base) ((base) + (0x0024))
#define SOC_FCM_KARMA_ADBbasiccontrol_ADDR(base) ((base) + (0x0028))
#define SOC_FCM_KARMA_ADBefficiencyTH_ADDR(base) ((base) + (0x002C))
#define SOC_FCM_KARMA_ADBDMCcontrol_ADDR(base) ((base) + (0x0030))
#define SOC_FCM_KARMA_clearcontrol_ADDR(base) ((base) + (0x0034))
#define SOC_FCM_KARMA_BEADPthreshold1_ADDR(base) ((base) + (0x0038))
#define SOC_FCM_KARMA_BEADPthreshold2_ADDR(base) ((base) + (0x003C))
#define SOC_FCM_KARMA_BEADPthreshold3_ADDR(base) ((base) + (0x0040))
#define SOC_FCM_KARMA_BEADPthreshold4_ADDR(base) ((base) + (0x0044))
#define SOC_FCM_KARMA_BEADPthreshold5_ADDR(base) ((base) + (0x0048))
#define SOC_FCM_KARMA_KARMAstatus_ADDR(base) ((base) + (0x004C))
#define SOC_FCM_KARMA_BEADPstatus1_ADDR(base) ((base) + (0x0050))
#define SOC_FCM_KARMA_BEADPstatus2_ADDR(base) ((base) + (0x0054))
#define SOC_FCM_KARMA_BEADPstatus3_ADDR(base) ((base) + (0x0058))
#define SOC_FCM_KARMA_systemconfiguration_ADDR(base) ((base) + (0x005C))
#define SOC_FCM_KARMA_PMEVCNTRN_EL0_ADDR(base,n) ((base) + (0x1000+(n)*8))
#define SOC_FCM_KARMA_PMCCNTR_EL0_LOW_ADDR(base) ((base) + (0x10F8))
#define SOC_FCM_KARMA_PMCCNTR_EL0_HIGH_ADDR(base) ((base) + (0x10FC))
#define SOC_FCM_KARMA_PMEVTYPERN_EL0_ADDR(base,n) ((base) + (0x1400+(n)*4))
#define SOC_FCM_KARMA_PMCNTENSET_EL0_ADDR(base) ((base) + (0x1C00))
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_ADDR(base) ((base) + (0x1C20))
#define SOC_FCM_KARMA_PMOVSCLR_EL0_ADDR(base) ((base) + (0x1C80))
#define SOC_FCM_KARMA_PMOVSSET_EL0_ADDR(base) ((base) + (0x1CC0))
#define SOC_FCM_KARMA_PMCR_EL0_ADDR(base) ((base) + (0x1E04))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mainenable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_KARMA_KARMA_GLOBAL_ENABLE_UNION;
#endif
#define SOC_FCM_KARMA_KARMA_GLOBAL_ENABLE_mainenable_START (0)
#define SOC_FCM_KARMA_KARMA_GLOBAL_ENABLE_mainenable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rep_disable : 1;
        unsigned int dcp_disable : 1;
        unsigned int ARBFIFOdepth : 3;
        unsigned int STGINFIFOdepth : 3;
        unsigned int ACPFIFOdepth : 7;
        unsigned int ACPoutstanding : 5;
        unsigned int L3requesttypemask : 4;
        unsigned int L3requestIDmask : 8;
    } reg;
} SOC_FCM_KARMA_KARMAGLOBALCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_rep_disable_START (0)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_rep_disable_END (0)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_dcp_disable_START (1)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_dcp_disable_END (1)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ARBFIFOdepth_START (2)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ARBFIFOdepth_END (4)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_STGINFIFOdepth_START (5)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_STGINFIFOdepth_END (7)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ACPFIFOdepth_START (8)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ACPFIFOdepth_END (14)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ACPoutstanding_START (15)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_ACPoutstanding_END (19)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_L3requesttypemask_START (20)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_L3requesttypemask_END (23)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_L3requestIDmask_START (24)
#define SOC_FCM_KARMA_KARMAGLOBALCONTROL_L3requestIDmask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PT_only_stride : 1;
        unsigned int DCONFstart : 5;
        unsigned int DCONFINClow : 3;
        unsigned int DCONFINChigh : 3;
        unsigned int DCONFDEClow : 3;
        unsigned int DCONFDEChigh : 3;
        unsigned int PTcounterallclearenable : 1;
        unsigned int DCONFlevel : 5;
        unsigned int PTLRUdisable : 1;
        unsigned int SCONFthreshold : 5;
        unsigned int Canceldisable : 1;
        unsigned int DCPselfbypassdisable : 1;
    } reg;
} SOC_FCM_KARMA_DCPTABLECONTROL_UNION;
#endif
#define SOC_FCM_KARMA_DCPTABLECONTROL_PT_only_stride_START (0)
#define SOC_FCM_KARMA_DCPTABLECONTROL_PT_only_stride_END (0)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFstart_START (1)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFstart_END (5)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFINClow_START (6)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFINClow_END (8)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFINChigh_START (9)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFINChigh_END (11)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFDEClow_START (12)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFDEClow_END (14)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFDEChigh_START (15)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFDEChigh_END (17)
#define SOC_FCM_KARMA_DCPTABLECONTROL_PTcounterallclearenable_START (18)
#define SOC_FCM_KARMA_DCPTABLECONTROL_PTcounterallclearenable_END (18)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFlevel_START (19)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCONFlevel_END (23)
#define SOC_FCM_KARMA_DCPTABLECONTROL_PTLRUdisable_START (24)
#define SOC_FCM_KARMA_DCPTABLECONTROL_PTLRUdisable_END (24)
#define SOC_FCM_KARMA_DCPTABLECONTROL_SCONFthreshold_START (25)
#define SOC_FCM_KARMA_DCPTABLECONTROL_SCONFthreshold_END (29)
#define SOC_FCM_KARMA_DCPTABLECONTROL_Canceldisable_START (30)
#define SOC_FCM_KARMA_DCPTABLECONTROL_Canceldisable_END (30)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCPselfbypassdisable_START (31)
#define SOC_FCM_KARMA_DCPTABLECONTROL_DCPselfbypassdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PTenableevenhightL3hitrate : 1;
        unsigned int SCONFincrement : 5;
        unsigned int PTenableeventheDMDisstrideincrement : 1;
        unsigned int SCONFdecrement : 5;
        unsigned int PTbypassSTG : 1;
        unsigned int SCONFstart : 5;
        unsigned int NA : 2;
        unsigned int PFcost : 4;
        unsigned int DefaultDCPDEG : 6;
        unsigned int L3Ptraintarget : 2;
    } reg;
} SOC_FCM_KARMA_DCPBASICCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_DCPBASICCONTROL_PTenableevenhightL3hitrate_START (0)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PTenableevenhightL3hitrate_END (0)
#define SOC_FCM_KARMA_DCPBASICCONTROL_SCONFincrement_START (1)
#define SOC_FCM_KARMA_DCPBASICCONTROL_SCONFincrement_END (5)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PTenableeventheDMDisstrideincrement_START (6)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PTenableeventheDMDisstrideincrement_END (6)
#define SOC_FCM_KARMA_DCPBASICCONTROL_SCONFdecrement_START (7)
#define SOC_FCM_KARMA_DCPBASICCONTROL_SCONFdecrement_END (11)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PTbypassSTG_START (12)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PTbypassSTG_END (12)
#define SOC_FCM_KARMA_DCPBASICCONTROL_SCONFstart_START (13)
#define SOC_FCM_KARMA_DCPBASICCONTROL_SCONFstart_END (17)
#define SOC_FCM_KARMA_DCPBASICCONTROL_NA_START (18)
#define SOC_FCM_KARMA_DCPBASICCONTROL_NA_END (19)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PFcost_START (20)
#define SOC_FCM_KARMA_DCPBASICCONTROL_PFcost_END (23)
#define SOC_FCM_KARMA_DCPBASICCONTROL_DefaultDCPDEG_START (24)
#define SOC_FCM_KARMA_DCPBASICCONTROL_DefaultDCPDEG_END (29)
#define SOC_FCM_KARMA_DCPBASICCONTROL_L3Ptraintarget_START (30)
#define SOC_FCM_KARMA_DCPBASICCONTROL_L3Ptraintarget_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DefaultREPdegree : 6;
        unsigned int ACshift : 4;
        unsigned int REPdistance : 5;
        unsigned int REPdistanceopposite : 5;
        unsigned int MAXREPDEG : 6;
        unsigned int SameblockupdatePAenable : 1;
        unsigned int Carryoverdisable : 1;
        unsigned int DVMsynccleardisable : 1;
        unsigned int Inflightrequestclear : 1;
        unsigned int InitDMDindexforRTCsignature : 1;
        unsigned int Pafilterdisable : 1;
    } reg;
} SOC_FCM_KARMA_REPCONTROLCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_REPCONTROLCONTROL_DefaultREPdegree_START (0)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_DefaultREPdegree_END (5)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_ACshift_START (6)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_ACshift_END (9)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_REPdistance_START (10)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_REPdistance_END (14)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_REPdistanceopposite_START (15)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_REPdistanceopposite_END (19)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_MAXREPDEG_START (20)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_MAXREPDEG_END (25)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_SameblockupdatePAenable_START (26)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_SameblockupdatePAenable_END (26)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_Carryoverdisable_START (27)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_Carryoverdisable_END (27)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_DVMsynccleardisable_START (28)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_DVMsynccleardisable_END (28)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_Inflightrequestclear_START (29)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_Inflightrequestclear_END (29)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_InitDMDindexforRTCsignature_START (30)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_InitDMDindexforRTCsignature_END (30)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_Pafilterdisable_START (31)
#define SOC_FCM_KARMA_REPCONTROLCONTROL_Pafilterdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ForceSTGbypass : 1;
        unsigned int DisableSTGbypass : 1;
        unsigned int PTbuffernumber : 2;
        unsigned int forcefetchonly16requestforPT : 1;
        unsigned int STGbypasscounterlowdelta : 5;
        unsigned int PTpatterncounterTH : 3;
        unsigned int STGbypasscounterhighdelta : 5;
        unsigned int Defaultactiveprefetchsource : 1;
        unsigned int Adaptiveactiveprefetchsource : 1;
        unsigned int ADPintervalthreshold : 2;
        unsigned int ForceDCPTAGhitforupdate : 1;
        unsigned int ForceDCPTAGhitforlookup : 1;
        unsigned int ADBdisable : 1;
        unsigned int ForceRCGenable : 1;
        unsigned int K3toK1blockenable : 1;
        unsigned int K4toK1blockenable : 1;
        unsigned int ReflowPASSalwaysneedDCPpipeline : 1;
        unsigned int don_tupdRTCifdumyR5 : 1;
        unsigned int ACPfifodropfromheaddisable : 1;
        unsigned int CSREPgeneratepatterdisable : 1;
    } reg;
} SOC_FCM_KARMA_STGCONTROLCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceSTGbypass_START (0)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceSTGbypass_END (0)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_DisableSTGbypass_START (1)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_DisableSTGbypass_END (1)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_PTbuffernumber_START (2)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_PTbuffernumber_END (3)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_forcefetchonly16requestforPT_START (4)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_forcefetchonly16requestforPT_END (4)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_STGbypasscounterlowdelta_START (5)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_STGbypasscounterlowdelta_END (9)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_PTpatterncounterTH_START (10)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_PTpatterncounterTH_END (12)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_STGbypasscounterhighdelta_START (13)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_STGbypasscounterhighdelta_END (17)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_Defaultactiveprefetchsource_START (18)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_Defaultactiveprefetchsource_END (18)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_Adaptiveactiveprefetchsource_START (19)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_Adaptiveactiveprefetchsource_END (19)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ADPintervalthreshold_START (20)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ADPintervalthreshold_END (21)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceDCPTAGhitforupdate_START (22)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceDCPTAGhitforupdate_END (22)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceDCPTAGhitforlookup_START (23)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceDCPTAGhitforlookup_END (23)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ADBdisable_START (24)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ADBdisable_END (24)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceRCGenable_START (25)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ForceRCGenable_END (25)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_K3toK1blockenable_START (26)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_K3toK1blockenable_END (26)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_K4toK1blockenable_START (27)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_K4toK1blockenable_END (27)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ReflowPASSalwaysneedDCPpipeline_START (28)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ReflowPASSalwaysneedDCPpipeline_END (28)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_don_tupdRTCifdumyR5_START (29)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_don_tupdRTCifdumyR5_END (29)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ACPfifodropfromheaddisable_START (30)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_ACPfifodropfromheaddisable_END (30)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_CSREPgeneratepatterdisable_START (31)
#define SOC_FCM_KARMA_STGCONTROLCONTROL_CSREPgeneratepatterdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_mulcore_th0 : 7;
        unsigned int BEADP_dcpe_th0 : 7;
        unsigned int ADBSREPDEG2 : 4;
        unsigned int ADBSREPDEG3 : 4;
        unsigned int REPtrackerupdatewhenhalfDEGorTH : 1;
        unsigned int REPtrackerupdateTH : 3;
        unsigned int ACupdateeveryDMD : 1;
        unsigned int ADBintervelTH : 5;
    } reg;
} SOC_FCM_KARMA_ADBREPDEGCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_BEADP_mulcore_th0_START (0)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_BEADP_mulcore_th0_END (6)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_BEADP_dcpe_th0_START (7)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_BEADP_dcpe_th0_END (13)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADBSREPDEG2_START (14)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADBSREPDEG2_END (17)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADBSREPDEG3_START (18)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADBSREPDEG3_END (21)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_REPtrackerupdatewhenhalfDEGorTH_START (22)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_REPtrackerupdatewhenhalfDEGorTH_END (22)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_REPtrackerupdateTH_START (23)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_REPtrackerupdateTH_END (25)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ACupdateeveryDMD_START (26)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ACupdateeveryDMD_END (26)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADBintervelTH_START (27)
#define SOC_FCM_KARMA_ADBREPDEGCONTROL_ADBintervelTH_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_acphit_th0 : 7;
        unsigned int BEADP_l3hit_th0 : 7;
        unsigned int BEADP_ddrbw_th0 : 7;
        unsigned int BEADP_dcp_enable : 1;
        unsigned int BEADP_rep_enable : 1;
        unsigned int BEADP_acp_enable : 1;
        unsigned int MAXDCPDEG : 6;
        unsigned int DMDREQinjectdisable : 1;
        unsigned int AdaptiveMAXREPdegreedisable : 1;
    } reg;
} SOC_FCM_KARMA_ADBDCPDEGCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_acphit_th0_START (0)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_acphit_th0_END (6)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_l3hit_th0_START (7)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_l3hit_th0_END (13)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_ddrbw_th0_START (14)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_ddrbw_th0_END (20)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_dcp_enable_START (21)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_dcp_enable_END (21)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_rep_enable_START (22)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_rep_enable_END (22)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_acp_enable_START (23)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_BEADP_acp_enable_END (23)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_MAXDCPDEG_START (24)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_MAXDCPDEG_END (29)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_DMDREQinjectdisable_START (30)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_DMDREQinjectdisable_END (30)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_AdaptiveMAXREPdegreedisable_START (31)
#define SOC_FCM_KARMA_ADBDCPDEGCONTROL_AdaptiveMAXREPdegreedisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_dcpeff_th2 : 7;
        unsigned int BEADP_repeff_th2 : 7;
        unsigned int BEADP_toteff_th1 : 7;
        unsigned int BEADP_hzd_sel1 : 5;
        unsigned int BEADP_hzd_th1 : 2;
        unsigned int L3averageT4 : 4;
    } reg;
} SOC_FCM_KARMA_ADBACCOSTCONTROL_UNION;
#endif
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_dcpeff_th2_START (0)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_dcpeff_th2_END (6)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_repeff_th2_START (7)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_repeff_th2_END (13)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_toteff_th1_START (14)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_toteff_th1_END (20)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_hzd_sel1_START (21)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_hzd_sel1_END (25)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_hzd_th1_START (26)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_BEADP_hzd_th1_END (27)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_L3averageT4_START (28)
#define SOC_FCM_KARMA_ADBACCOSTCONTROL_L3averageT4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_hzd_th2 : 7;
        unsigned int BEADP_acphit_th2 : 7;
        unsigned int BEADP_l3hit_th2 : 7;
        unsigned int BEADP_toteff_th2 : 7;
        unsigned int ADPrateCNTshiftvalue : 3;
        unsigned int intervelifanyCNTOV : 1;
    } reg;
} SOC_FCM_KARMA_ADAPTIVEPARAMETER_UNION;
#endif
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_hzd_th2_START (0)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_hzd_th2_END (6)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_acphit_th2_START (7)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_acphit_th2_END (13)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_l3hit_th2_START (14)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_l3hit_th2_END (20)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_toteff_th2_START (21)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_BEADP_toteff_th2_END (27)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_ADPrateCNTshiftvalue_START (28)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_ADPrateCNTshiftvalue_END (30)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_intervelifanyCNTOV_START (31)
#define SOC_FCM_KARMA_ADAPTIVEPARAMETER_intervelifanyCNTOV_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ADBPREPefficiencyhighthreshold : 6;
        unsigned int PLDalsotrainPT : 1;
        unsigned int ACPFIFOtimeoutTH : 3;
        unsigned int ADBPREPefficiencylowthreshold : 6;
        unsigned int filterL3hitforREPgeneration : 1;
        unsigned int REP_DCPgoodonlyincreasewhentheDMDmissL3 : 1;
        unsigned int ACPFIFOtimeoutdropenable : 1;
        unsigned int STGhashenable : 1;
        unsigned int ADBPcyclegap : 4;
        unsigned int ADBPdisable : 1;
        unsigned int DDRutilizationwhendisabled : 2;
        unsigned int DCPacross4Kenable : 1;
        unsigned int TSoverflowACupdatedecrementvalue : 3;
        unsigned int don_tupdateTSisallBM1 : 1;
    } reg;
} SOC_FCM_KARMA_ADBbasiccontrol_UNION;
#endif
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPREPefficiencyhighthreshold_START (0)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPREPefficiencyhighthreshold_END (5)
#define SOC_FCM_KARMA_ADBbasiccontrol_PLDalsotrainPT_START (6)
#define SOC_FCM_KARMA_ADBbasiccontrol_PLDalsotrainPT_END (6)
#define SOC_FCM_KARMA_ADBbasiccontrol_ACPFIFOtimeoutTH_START (7)
#define SOC_FCM_KARMA_ADBbasiccontrol_ACPFIFOtimeoutTH_END (9)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPREPefficiencylowthreshold_START (10)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPREPefficiencylowthreshold_END (15)
#define SOC_FCM_KARMA_ADBbasiccontrol_filterL3hitforREPgeneration_START (16)
#define SOC_FCM_KARMA_ADBbasiccontrol_filterL3hitforREPgeneration_END (16)
#define SOC_FCM_KARMA_ADBbasiccontrol_REP_DCPgoodonlyincreasewhentheDMDmissL3_START (17)
#define SOC_FCM_KARMA_ADBbasiccontrol_REP_DCPgoodonlyincreasewhentheDMDmissL3_END (17)
#define SOC_FCM_KARMA_ADBbasiccontrol_ACPFIFOtimeoutdropenable_START (18)
#define SOC_FCM_KARMA_ADBbasiccontrol_ACPFIFOtimeoutdropenable_END (18)
#define SOC_FCM_KARMA_ADBbasiccontrol_STGhashenable_START (19)
#define SOC_FCM_KARMA_ADBbasiccontrol_STGhashenable_END (19)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPcyclegap_START (20)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPcyclegap_END (23)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPdisable_START (24)
#define SOC_FCM_KARMA_ADBbasiccontrol_ADBPdisable_END (24)
#define SOC_FCM_KARMA_ADBbasiccontrol_DDRutilizationwhendisabled_START (25)
#define SOC_FCM_KARMA_ADBbasiccontrol_DDRutilizationwhendisabled_END (26)
#define SOC_FCM_KARMA_ADBbasiccontrol_DCPacross4Kenable_START (27)
#define SOC_FCM_KARMA_ADBbasiccontrol_DCPacross4Kenable_END (27)
#define SOC_FCM_KARMA_ADBbasiccontrol_TSoverflowACupdatedecrementvalue_START (28)
#define SOC_FCM_KARMA_ADBbasiccontrol_TSoverflowACupdatedecrementvalue_END (30)
#define SOC_FCM_KARMA_ADBbasiccontrol_don_tupdateTSisallBM1_START (31)
#define SOC_FCM_KARMA_ADBbasiccontrol_don_tupdateTSisallBM1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ADBPDCPefficiencyhighthreshold : 6;
        unsigned int STGupdateevenCMDmasked : 1;
        unsigned int L3hitrateTH : 3;
        unsigned int ADBPDCPefficiencylowthreshold : 6;
        unsigned int STGupdateevenIDismasked : 1;
        unsigned int REP_DCPfiltermodeforL3hitrequst : 2;
        unsigned int filterDCPforL3hitrequests : 1;
        unsigned int ADBPDCONFACCTH : 5;
        unsigned int ADBPEFFPFCNTshift : 2;
        unsigned int BEADPmulticpuCNTdisablebigcore : 1;
        unsigned int STGupdateallCMD : 1;
        unsigned int STGupdateallID : 1;
        unsigned int REPDEGadaptivechange : 1;
        unsigned int DCPDEGadaptivechange : 1;
    } reg;
} SOC_FCM_KARMA_ADBefficiencyTH_UNION;
#endif
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPDCPefficiencyhighthreshold_START (0)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPDCPefficiencyhighthreshold_END (5)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateevenCMDmasked_START (6)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateevenCMDmasked_END (6)
#define SOC_FCM_KARMA_ADBefficiencyTH_L3hitrateTH_START (7)
#define SOC_FCM_KARMA_ADBefficiencyTH_L3hitrateTH_END (9)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPDCPefficiencylowthreshold_START (10)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPDCPefficiencylowthreshold_END (15)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateevenIDismasked_START (16)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateevenIDismasked_END (16)
#define SOC_FCM_KARMA_ADBefficiencyTH_REP_DCPfiltermodeforL3hitrequst_START (17)
#define SOC_FCM_KARMA_ADBefficiencyTH_REP_DCPfiltermodeforL3hitrequst_END (18)
#define SOC_FCM_KARMA_ADBefficiencyTH_filterDCPforL3hitrequests_START (19)
#define SOC_FCM_KARMA_ADBefficiencyTH_filterDCPforL3hitrequests_END (19)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPDCONFACCTH_START (20)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPDCONFACCTH_END (24)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPEFFPFCNTshift_START (25)
#define SOC_FCM_KARMA_ADBefficiencyTH_ADBPEFFPFCNTshift_END (26)
#define SOC_FCM_KARMA_ADBefficiencyTH_BEADPmulticpuCNTdisablebigcore_START (27)
#define SOC_FCM_KARMA_ADBefficiencyTH_BEADPmulticpuCNTdisablebigcore_END (27)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateallCMD_START (28)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateallCMD_END (28)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateallID_START (29)
#define SOC_FCM_KARMA_ADBefficiencyTH_STGupdateallID_END (29)
#define SOC_FCM_KARMA_ADBefficiencyTH_REPDEGadaptivechange_START (30)
#define SOC_FCM_KARMA_ADBefficiencyTH_REPDEGadaptivechange_END (30)
#define SOC_FCM_KARMA_ADBefficiencyTH_DCPDEGadaptivechange_START (31)
#define SOC_FCM_KARMA_ADBefficiencyTH_DCPDEGadaptivechange_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_l3hit_th3 : 7;
        unsigned int BEADP_BW_select2 : 1;
        unsigned int BEADP_BW_th2 : 6;
        unsigned int PT_4Kbuffernumber : 2;
        unsigned int DMCaveratecounterT3 : 5;
        unsigned int PT_4Ktimeoutthreshold : 3;
        unsigned int DDRintervalnumber : 4;
        unsigned int DDRaverageincreasecyclenumber : 3;
        unsigned int CSADPalgorithmdisable : 1;
    } reg;
} SOC_FCM_KARMA_ADBDMCcontrol_UNION;
#endif
#define SOC_FCM_KARMA_ADBDMCcontrol_BEADP_l3hit_th3_START (0)
#define SOC_FCM_KARMA_ADBDMCcontrol_BEADP_l3hit_th3_END (6)
#define SOC_FCM_KARMA_ADBDMCcontrol_BEADP_BW_select2_START (7)
#define SOC_FCM_KARMA_ADBDMCcontrol_BEADP_BW_select2_END (7)
#define SOC_FCM_KARMA_ADBDMCcontrol_BEADP_BW_th2_START (8)
#define SOC_FCM_KARMA_ADBDMCcontrol_BEADP_BW_th2_END (13)
#define SOC_FCM_KARMA_ADBDMCcontrol_PT_4Kbuffernumber_START (14)
#define SOC_FCM_KARMA_ADBDMCcontrol_PT_4Kbuffernumber_END (15)
#define SOC_FCM_KARMA_ADBDMCcontrol_DMCaveratecounterT3_START (16)
#define SOC_FCM_KARMA_ADBDMCcontrol_DMCaveratecounterT3_END (20)
#define SOC_FCM_KARMA_ADBDMCcontrol_PT_4Ktimeoutthreshold_START (21)
#define SOC_FCM_KARMA_ADBDMCcontrol_PT_4Ktimeoutthreshold_END (23)
#define SOC_FCM_KARMA_ADBDMCcontrol_DDRintervalnumber_START (24)
#define SOC_FCM_KARMA_ADBDMCcontrol_DDRintervalnumber_END (27)
#define SOC_FCM_KARMA_ADBDMCcontrol_DDRaverageincreasecyclenumber_START (28)
#define SOC_FCM_KARMA_ADBDMCcontrol_DDRaverageincreasecyclenumber_END (30)
#define SOC_FCM_KARMA_ADBDMCcontrol_CSADPalgorithmdisable_START (31)
#define SOC_FCM_KARMA_ADBDMCcontrol_CSADPalgorithmdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clearenable : 1;
        unsigned int CPUIDmaskforPTalgorithm : 8;
        unsigned int ACPsendreadrequest : 1;
        unsigned int BEADP_l3hit_th4 : 7;
        unsigned int BEADP_l3BW_th3 : 7;
        unsigned int BEADP_ACPhit_th3 : 7;
        unsigned int ADBintervelsource : 1;
    } reg;
} SOC_FCM_KARMA_clearcontrol_UNION;
#endif
#define SOC_FCM_KARMA_clearcontrol_clearenable_START (0)
#define SOC_FCM_KARMA_clearcontrol_clearenable_END (0)
#define SOC_FCM_KARMA_clearcontrol_CPUIDmaskforPTalgorithm_START (1)
#define SOC_FCM_KARMA_clearcontrol_CPUIDmaskforPTalgorithm_END (8)
#define SOC_FCM_KARMA_clearcontrol_ACPsendreadrequest_START (9)
#define SOC_FCM_KARMA_clearcontrol_ACPsendreadrequest_END (9)
#define SOC_FCM_KARMA_clearcontrol_BEADP_l3hit_th4_START (10)
#define SOC_FCM_KARMA_clearcontrol_BEADP_l3hit_th4_END (16)
#define SOC_FCM_KARMA_clearcontrol_BEADP_l3BW_th3_START (17)
#define SOC_FCM_KARMA_clearcontrol_BEADP_l3BW_th3_END (23)
#define SOC_FCM_KARMA_clearcontrol_BEADP_ACPhit_th3_START (24)
#define SOC_FCM_KARMA_clearcontrol_BEADP_ACPhit_th3_END (30)
#define SOC_FCM_KARMA_clearcontrol_ADBintervelsource_START (31)
#define SOC_FCM_KARMA_clearcontrol_ADBintervelsource_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_hzd_th5 : 7;
        unsigned int BEADP_bw_th5 : 7;
        unsigned int BEADP_acphit_th5 : 7;
        unsigned int BEADP_l3hit_th5 : 7;
        unsigned int BEADPtotallevels : 2;
        unsigned int BEADPACPlevels : 2;
    } reg;
} SOC_FCM_KARMA_BEADPthreshold1_UNION;
#endif
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_hzd_th5_START (0)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_hzd_th5_END (6)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_bw_th5_START (7)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_bw_th5_END (13)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_acphit_th5_START (14)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_acphit_th5_END (20)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_l3hit_th5_START (21)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADP_l3hit_th5_END (27)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADPtotallevels_START (28)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADPtotallevels_END (29)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADPACPlevels_START (30)
#define SOC_FCM_KARMA_BEADPthreshold1_BEADPACPlevels_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_hzd_th6 : 7;
        unsigned int BEADP_bw_th6 : 7;
        unsigned int BEADP_acphit_th6 : 7;
        unsigned int BEADP_l3hit_th6 : 7;
        unsigned int BEADPACPoutstandinglevels : 2;
        unsigned int BEADPACPhacklevels : 2;
    } reg;
} SOC_FCM_KARMA_BEADPthreshold2_UNION;
#endif
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_hzd_th6_START (0)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_hzd_th6_END (6)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_bw_th6_START (7)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_bw_th6_END (13)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_acphit_th6_START (14)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_acphit_th6_END (20)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_l3hit_th6_START (21)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADP_l3hit_th6_END (27)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADPACPoutstandinglevels_START (28)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADPACPoutstandinglevels_END (29)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADPACPhacklevels_START (30)
#define SOC_FCM_KARMA_BEADPthreshold2_BEADPACPhacklevels_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_repeff_th7 : 7;
        unsigned int BEADP_dcpeff_th7 : 7;
        unsigned int BEADP_l3bw_th4 : 7;
        unsigned int BEADP_acp_th4 : 7;
        unsigned int BEADPDEG0hack : 2;
        unsigned int BEADPinterveltimeren : 1;
        unsigned int BEADPclrtimeren : 1;
    } reg;
} SOC_FCM_KARMA_BEADPthreshold3_UNION;
#endif
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_repeff_th7_START (0)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_repeff_th7_END (6)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_dcpeff_th7_START (7)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_dcpeff_th7_END (13)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_l3bw_th4_START (14)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_l3bw_th4_END (20)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_acp_th4_START (21)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADP_acp_th4_END (27)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADPDEG0hack_START (28)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADPDEG0hack_END (29)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADPinterveltimeren_START (30)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADPinterveltimeren_END (30)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADPclrtimeren_START (31)
#define SOC_FCM_KARMA_BEADPthreshold3_BEADPclrtimeren_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_toteff_th8 : 7;
        unsigned int BEADP_acphit_th8 : 7;
        unsigned int BEADP_hzd_th8 : 7;
        unsigned int BEADP_BW_th8 : 9;
        unsigned int BEADPPTtotalADPTH : 1;
        unsigned int BEADPgenertateforhit : 1;
    } reg;
} SOC_FCM_KARMA_BEADPthreshold4_UNION;
#endif
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_toteff_th8_START (0)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_toteff_th8_END (6)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_acphit_th8_START (7)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_acphit_th8_END (13)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_hzd_th8_START (14)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_hzd_th8_END (20)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_BW_th8_START (21)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADP_BW_th8_END (29)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADPPTtotalADPTH_START (30)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADPPTtotalADPTH_END (30)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADPgenertateforhit_START (31)
#define SOC_FCM_KARMA_BEADPthreshold4_BEADPgenertateforhit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L3averageT3 : 5;
        unsigned int BEADP_bw_th0 : 7;
        unsigned int PTtrafficelimitTH : 3;
        unsigned int BEADPhazardsel2 : 1;
        unsigned int ADPforceDCPhittotalintervelenable : 1;
        unsigned int ADPforceDCPhitACPenable : 1;
        unsigned int ADPforceDCPhitEFFenable : 1;
        unsigned int ADPforcedecrementDCPenable : 1;
        unsigned int ADPforcedecrementREPenable : 1;
        unsigned int ADPforcedecrementREPselect : 1;
        unsigned int ADPforcedecrementEFFselect : 1;
        unsigned int BEADPGPUBWTH0 : 5;
        unsigned int ACshiftsystemfeedback : 4;
    } reg;
} SOC_FCM_KARMA_BEADPthreshold5_UNION;
#endif
#define SOC_FCM_KARMA_BEADPthreshold5_L3averageT3_START (0)
#define SOC_FCM_KARMA_BEADPthreshold5_L3averageT3_END (4)
#define SOC_FCM_KARMA_BEADPthreshold5_BEADP_bw_th0_START (5)
#define SOC_FCM_KARMA_BEADPthreshold5_BEADP_bw_th0_END (11)
#define SOC_FCM_KARMA_BEADPthreshold5_PTtrafficelimitTH_START (12)
#define SOC_FCM_KARMA_BEADPthreshold5_PTtrafficelimitTH_END (14)
#define SOC_FCM_KARMA_BEADPthreshold5_BEADPhazardsel2_START (15)
#define SOC_FCM_KARMA_BEADPthreshold5_BEADPhazardsel2_END (15)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforceDCPhittotalintervelenable_START (16)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforceDCPhittotalintervelenable_END (16)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforceDCPhitACPenable_START (17)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforceDCPhitACPenable_END (17)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforceDCPhitEFFenable_START (18)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforceDCPhitEFFenable_END (18)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementDCPenable_START (19)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementDCPenable_END (19)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementREPenable_START (20)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementREPenable_END (20)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementREPselect_START (21)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementREPselect_END (21)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementEFFselect_START (22)
#define SOC_FCM_KARMA_BEADPthreshold5_ADPforcedecrementEFFselect_END (22)
#define SOC_FCM_KARMA_BEADPthreshold5_BEADPGPUBWTH0_START (23)
#define SOC_FCM_KARMA_BEADPthreshold5_BEADPGPUBWTH0_END (27)
#define SOC_FCM_KARMA_BEADPthreshold5_ACshiftsystemfeedback_START (28)
#define SOC_FCM_KARMA_BEADPthreshold5_ACshiftsystemfeedback_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int karmaidle : 1;
        unsigned int PTmemorylatencyteststate : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_KARMA_KARMAstatus_UNION;
#endif
#define SOC_FCM_KARMA_KARMAstatus_karmaidle_START (0)
#define SOC_FCM_KARMA_KARMAstatus_karmaidle_END (0)
#define SOC_FCM_KARMA_KARMAstatus_PTmemorylatencyteststate_START (1)
#define SOC_FCM_KARMA_KARMAstatus_PTmemorylatencyteststate_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L3bandwith : 8;
        unsigned int L3utilization : 8;
        unsigned int multicorebandwith : 8;
        unsigned int DDRutilization : 7;
        unsigned int backendADPleveldecvld : 1;
    } reg;
} SOC_FCM_KARMA_BEADPstatus1_UNION;
#endif
#define SOC_FCM_KARMA_BEADPstatus1_L3bandwith_START (0)
#define SOC_FCM_KARMA_BEADPstatus1_L3bandwith_END (7)
#define SOC_FCM_KARMA_BEADPstatus1_L3utilization_START (8)
#define SOC_FCM_KARMA_BEADPstatus1_L3utilization_END (15)
#define SOC_FCM_KARMA_BEADPstatus1_multicorebandwith_START (16)
#define SOC_FCM_KARMA_BEADPstatus1_multicorebandwith_END (23)
#define SOC_FCM_KARMA_BEADPstatus1_DDRutilization_START (24)
#define SOC_FCM_KARMA_BEADPstatus1_DDRutilization_END (30)
#define SOC_FCM_KARMA_BEADPstatus1_backendADPleveldecvld_START (31)
#define SOC_FCM_KARMA_BEADPstatus1_backendADPleveldecvld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int REPgoodratio : 6;
        unsigned int reserved_0 : 6;
        unsigned int DCPgoodratio : 6;
        unsigned int reserved_1 : 4;
        unsigned int totalgoodratio : 6;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_FCM_KARMA_BEADPstatus2_UNION;
#endif
#define SOC_FCM_KARMA_BEADPstatus2_REPgoodratio_START (0)
#define SOC_FCM_KARMA_BEADPstatus2_REPgoodratio_END (5)
#define SOC_FCM_KARMA_BEADPstatus2_DCPgoodratio_START (12)
#define SOC_FCM_KARMA_BEADPstatus2_DCPgoodratio_END (17)
#define SOC_FCM_KARMA_BEADPstatus2_totalgoodratio_START (22)
#define SOC_FCM_KARMA_BEADPstatus2_totalgoodratio_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L3hitrate : 6;
        unsigned int reserved_0 : 6;
        unsigned int acphitrate : 6;
        unsigned int reserved_1 : 4;
        unsigned int hazardrate : 6;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_FCM_KARMA_BEADPstatus3_UNION;
#endif
#define SOC_FCM_KARMA_BEADPstatus3_L3hitrate_START (0)
#define SOC_FCM_KARMA_BEADPstatus3_L3hitrate_END (5)
#define SOC_FCM_KARMA_BEADPstatus3_acphitrate_START (12)
#define SOC_FCM_KARMA_BEADPstatus3_acphitrate_END (17)
#define SOC_FCM_KARMA_BEADPstatus3_hazardrate_START (22)
#define SOC_FCM_KARMA_BEADPstatus3_hazardrate_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GIDmaskvector : 16;
        unsigned int ADBSEFF0 : 4;
        unsigned int ADBSEFF1 : 4;
        unsigned int ADBSEFF2 : 4;
        unsigned int ADBSEFF3 : 4;
    } reg;
} SOC_FCM_KARMA_systemconfiguration_UNION;
#endif
#define SOC_FCM_KARMA_systemconfiguration_GIDmaskvector_START (0)
#define SOC_FCM_KARMA_systemconfiguration_GIDmaskvector_END (15)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF0_START (16)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF0_END (19)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF1_START (20)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF1_END (23)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF2_START (24)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF2_END (27)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF3_START (28)
#define SOC_FCM_KARMA_systemconfiguration_ADBSEFF3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eventcountern : 32;
    } reg;
} SOC_FCM_KARMA_PMEVCNTRN_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMEVCNTRN_EL0_eventcountern_START (0)
#define SOC_FCM_KARMA_PMEVCNTRN_EL0_eventcountern_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lowerpatofcyclecounter : 32;
    } reg;
} SOC_FCM_KARMA_PMCCNTR_EL0_LOW_UNION;
#endif
#define SOC_FCM_KARMA_PMCCNTR_EL0_LOW_lowerpatofcyclecounter_START (0)
#define SOC_FCM_KARMA_PMCCNTR_EL0_LOW_lowerpatofcyclecounter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int upperpatofcyclecounter : 32;
    } reg;
} SOC_FCM_KARMA_PMCCNTR_EL0_HIGH_UNION;
#endif
#define SOC_FCM_KARMA_PMCCNTR_EL0_HIGH_upperpatofcyclecounter_START (0)
#define SOC_FCM_KARMA_PMCCNTR_EL0_HIGH_upperpatofcyclecounter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evtcount : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_FCM_KARMA_PMEVTYPERN_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMEVTYPERN_EL0_evtcount_START (0)
#define SOC_FCM_KARMA_PMEVTYPERN_EL0_evtcount_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 1;
        unsigned int p1 : 1;
        unsigned int p2 : 1;
        unsigned int p3 : 1;
        unsigned int p4 : 1;
        unsigned int p5 : 1;
        unsigned int p6 : 1;
        unsigned int p7 : 1;
        unsigned int p8 : 1;
        unsigned int p9 : 1;
        unsigned int p10 : 1;
        unsigned int p11 : 1;
        unsigned int reserved : 19;
        unsigned int c : 1;
    } reg;
} SOC_FCM_KARMA_PMCNTENSET_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p0_START (0)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p0_END (0)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p1_START (1)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p1_END (1)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p2_START (2)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p2_END (2)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p3_START (3)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p3_END (3)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p4_START (4)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p4_END (4)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p5_START (5)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p5_END (5)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p6_START (6)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p6_END (6)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p7_START (7)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p7_END (7)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p8_START (8)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p8_END (8)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p9_START (9)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p9_END (9)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p10_START (10)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p10_END (10)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p11_START (11)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_p11_END (11)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_c_START (31)
#define SOC_FCM_KARMA_PMCNTENSET_EL0_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 1;
        unsigned int p1 : 1;
        unsigned int p2 : 1;
        unsigned int p3 : 1;
        unsigned int p4 : 1;
        unsigned int p5 : 1;
        unsigned int p6 : 1;
        unsigned int p7 : 1;
        unsigned int p8 : 1;
        unsigned int p9 : 1;
        unsigned int p10 : 1;
        unsigned int p11 : 1;
        unsigned int reserved : 19;
        unsigned int c : 1;
    } reg;
} SOC_FCM_KARMA_PMCNTENCLR_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p0_START (0)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p0_END (0)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p1_START (1)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p1_END (1)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p2_START (2)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p2_END (2)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p3_START (3)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p3_END (3)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p4_START (4)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p4_END (4)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p5_START (5)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p5_END (5)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p6_START (6)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p6_END (6)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p7_START (7)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p7_END (7)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p8_START (8)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p8_END (8)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p9_START (9)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p9_END (9)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p10_START (10)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p10_END (10)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p11_START (11)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_p11_END (11)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_c_START (31)
#define SOC_FCM_KARMA_PMCNTENCLR_EL0_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 1;
        unsigned int p1 : 1;
        unsigned int p2 : 1;
        unsigned int p3 : 1;
        unsigned int p4 : 1;
        unsigned int p5 : 1;
        unsigned int p6 : 1;
        unsigned int p7 : 1;
        unsigned int p8 : 1;
        unsigned int p9 : 1;
        unsigned int p10 : 1;
        unsigned int p11 : 1;
        unsigned int reserved : 19;
        unsigned int c : 1;
    } reg;
} SOC_FCM_KARMA_PMOVSCLR_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p0_START (0)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p0_END (0)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p1_START (1)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p1_END (1)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p2_START (2)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p2_END (2)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p3_START (3)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p3_END (3)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p4_START (4)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p4_END (4)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p5_START (5)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p5_END (5)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p6_START (6)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p6_END (6)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p7_START (7)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p7_END (7)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p8_START (8)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p8_END (8)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p9_START (9)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p9_END (9)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p10_START (10)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p10_END (10)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p11_START (11)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_p11_END (11)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_c_START (31)
#define SOC_FCM_KARMA_PMOVSCLR_EL0_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 1;
        unsigned int p1 : 1;
        unsigned int p2 : 1;
        unsigned int p3 : 1;
        unsigned int p4 : 1;
        unsigned int p5 : 1;
        unsigned int p6 : 1;
        unsigned int p7 : 1;
        unsigned int p8 : 1;
        unsigned int p9 : 1;
        unsigned int p10 : 1;
        unsigned int p11 : 1;
        unsigned int reserved : 19;
        unsigned int c : 1;
    } reg;
} SOC_FCM_KARMA_PMOVSSET_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMOVSSET_EL0_p0_START (0)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p0_END (0)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p1_START (1)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p1_END (1)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p2_START (2)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p2_END (2)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p3_START (3)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p3_END (3)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p4_START (4)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p4_END (4)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p5_START (5)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p5_END (5)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p6_START (6)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p6_END (6)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p7_START (7)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p7_END (7)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p8_START (8)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p8_END (8)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p9_START (9)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p9_END (9)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p10_START (10)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p10_END (10)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p11_START (11)
#define SOC_FCM_KARMA_PMOVSSET_EL0_p11_END (11)
#define SOC_FCM_KARMA_PMOVSSET_EL0_c_START (31)
#define SOC_FCM_KARMA_PMOVSSET_EL0_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enable : 1;
        unsigned int p : 1;
        unsigned int c : 1;
        unsigned int reserved_0 : 3;
        unsigned int lclongcyclecounterenable : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_FCM_KARMA_PMCR_EL0_UNION;
#endif
#define SOC_FCM_KARMA_PMCR_EL0_enable_START (0)
#define SOC_FCM_KARMA_PMCR_EL0_enable_END (0)
#define SOC_FCM_KARMA_PMCR_EL0_p_START (1)
#define SOC_FCM_KARMA_PMCR_EL0_p_END (1)
#define SOC_FCM_KARMA_PMCR_EL0_c_START (2)
#define SOC_FCM_KARMA_PMCR_EL0_c_END (2)
#define SOC_FCM_KARMA_PMCR_EL0_lclongcyclecounterenable_START (6)
#define SOC_FCM_KARMA_PMCR_EL0_lclongcyclecounterenable_END (6)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
