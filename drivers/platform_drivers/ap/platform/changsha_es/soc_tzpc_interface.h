#ifndef __SOC_TZPC_INTERFACE_H__
#define __SOC_TZPC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TZPC_AO_R0SIZE_ADDR(base) (base)
#define SOC_TZPC_AO_DECPROT0STAT_ADDR(base) ((base) + 0x800UL)
#define SOC_TZPC_AO_DECPROT0SET_ADDR(base) ((base) + 0x804UL)
#define SOC_TZPC_AO_DECPROT0CLR_ADDR(base) ((base) + 0x808UL)
#define SOC_TZPC_AO_DECPROT1STAT_ADDR(base) ((base) + 0x80CUL)
#define SOC_TZPC_AO_DECPROT1SET_ADDR(base) ((base) + 0x810UL)
#define SOC_TZPC_AO_DECPROT1CLR_ADDR(base) ((base) + 0x814UL)
#define SOC_TZPC_AO_DECPROT2STAT_ADDR(base) ((base) + 0x818UL)
#define SOC_TZPC_AO_DECPROT2SET_ADDR(base) ((base) + 0x81CUL)
#define SOC_TZPC_AO_DECPROT2CLR_ADDR(base) ((base) + 0x820UL)
#define SOC_TZPC_AO_DECPROT3STAT_ADDR(base) ((base) + 0x824UL)
#define SOC_TZPC_AO_DECPROT3SET_ADDR(base) ((base) + 0x828UL)
#define SOC_TZPC_AO_DECPROT3CLR_ADDR(base) ((base) + 0x82CUL)
#define SOC_TZPC_AO_DECPROT4STAT_ADDR(base) ((base) + 0x830UL)
#define SOC_TZPC_AO_DECPROT4SET_ADDR(base) ((base) + 0x834UL)
#define SOC_TZPC_AO_DECPROT4CLR_ADDR(base) ((base) + 0x838UL)
#define SOC_TZPC_AO_DECPROT5STAT_ADDR(base) ((base) + 0x83CUL)
#define SOC_TZPC_AO_DECPROT5SET_ADDR(base) ((base) + 0x840UL)
#define SOC_TZPC_AO_DECPROT5CLR_ADDR(base) ((base) + 0x844UL)
#define SOC_TZPC_AO_DECPROT6STAT_ADDR(base) ((base) + 0x848UL)
#define SOC_TZPC_AO_DECPROT6SET_ADDR(base) ((base) + 0x84CUL)
#define SOC_TZPC_AO_DECPROT6CLR_ADDR(base) ((base) + 0x850UL)
#define SOC_TZPC_AO_DECPROT7STAT_ADDR(base) ((base) + 0x854UL)
#define SOC_TZPC_AO_DECPROT7SET_ADDR(base) ((base) + 0x858UL)
#define SOC_TZPC_AO_DECPROT7CLR_ADDR(base) ((base) + 0x85CUL)
#define SOC_TZPC_AO_DECPROT8STAT_ADDR(base) ((base) + 0x860UL)
#define SOC_TZPC_AO_DECPROT8SET_ADDR(base) ((base) + 0x864UL)
#define SOC_TZPC_AO_DECPROT8CLR_ADDR(base) ((base) + 0x868UL)
#define SOC_TZPC_AO_DECPROT9STAT_ADDR(base) ((base) + 0x86CUL)
#define SOC_TZPC_AO_DECPROT9SET_ADDR(base) ((base) + 0x870UL)
#define SOC_TZPC_AO_DECPROT9CLR_ADDR(base) ((base) + 0x874UL)
#define SOC_TZPC_AO_DECPROT10STAT_ADDR(base) ((base) + 0x878UL)
#define SOC_TZPC_AO_DECPROT10SET_ADDR(base) ((base) + 0x87CUL)
#define SOC_TZPC_AO_DECPROT10CLR_ADDR(base) ((base) + 0x880UL)
#define SOC_TZPC_AO_DECPROT11STAT_ADDR(base) ((base) + 0x884UL)
#define SOC_TZPC_AO_DECPROT11SET_ADDR(base) ((base) + 0x888UL)
#define SOC_TZPC_AO_DECPROT11CLR_ADDR(base) ((base) + 0x88CUL)
#define SOC_TZPC_AO_DECPROT12STAT_ADDR(base) ((base) + 0x890UL)
#define SOC_TZPC_AO_DECPROT12SET_ADDR(base) ((base) + 0x894UL)
#define SOC_TZPC_AO_DECPROT12CLR_ADDR(base) ((base) + 0x898UL)
#define SOC_TZPC_AO_DECPROT13STAT_ADDR(base) ((base) + 0x89CUL)
#define SOC_TZPC_AO_DECPROT13SET_ADDR(base) ((base) + 0x8A0UL)
#define SOC_TZPC_AO_DECPROT13CLR_ADDR(base) ((base) + 0x8A4UL)
#define SOC_TZPC_AO_DECPROT14STAT_ADDR(base) ((base) + 0x8A8UL)
#define SOC_TZPC_AO_DECPROT14SET_ADDR(base) ((base) + 0x8ACUL)
#define SOC_TZPC_AO_DECPROT14CLR_ADDR(base) ((base) + 0x8B0UL)
#define SOC_TZPC_AO_DECPROT15STAT_ADDR(base) ((base) + 0x8B4UL)
#define SOC_TZPC_AO_DECPROT15SET_ADDR(base) ((base) + 0x8B8UL)
#define SOC_TZPC_AO_DECPROT15CLR_ADDR(base) ((base) + 0x8BCUL)
#define SOC_TZPC_AO_DECPROT16STAT_ADDR(base) ((base) + 0x8C0UL)
#define SOC_TZPC_AO_DECPROT16SET_ADDR(base) ((base) + 0x8C4UL)
#define SOC_TZPC_AO_DECPROT16CLR_ADDR(base) ((base) + 0x8C8UL)
#define SOC_TZPC_AO_DECPROT17STAT_ADDR(base) ((base) + 0x8CCUL)
#define SOC_TZPC_AO_DECPROT17SET_ADDR(base) ((base) + 0x8D0UL)
#define SOC_TZPC_AO_DECPROT17CLR_ADDR(base) ((base) + 0x8D4UL)
#define SOC_TZPC_AO_REG1_STAT_ADDR(base) ((base) + 0xA04UL)
#define SOC_TZPC_AO_LOCK_ADDR(base) ((base) + 0xF00UL)
#else
#define SOC_TZPC_AO_R0SIZE_ADDR(base) (base)
#define SOC_TZPC_AO_DECPROT0STAT_ADDR(base) ((base) + 0x800)
#define SOC_TZPC_AO_DECPROT0SET_ADDR(base) ((base) + 0x804)
#define SOC_TZPC_AO_DECPROT0CLR_ADDR(base) ((base) + 0x808)
#define SOC_TZPC_AO_DECPROT1STAT_ADDR(base) ((base) + 0x80C)
#define SOC_TZPC_AO_DECPROT1SET_ADDR(base) ((base) + 0x810)
#define SOC_TZPC_AO_DECPROT1CLR_ADDR(base) ((base) + 0x814)
#define SOC_TZPC_AO_DECPROT2STAT_ADDR(base) ((base) + 0x818)
#define SOC_TZPC_AO_DECPROT2SET_ADDR(base) ((base) + 0x81C)
#define SOC_TZPC_AO_DECPROT2CLR_ADDR(base) ((base) + 0x820)
#define SOC_TZPC_AO_DECPROT3STAT_ADDR(base) ((base) + 0x824)
#define SOC_TZPC_AO_DECPROT3SET_ADDR(base) ((base) + 0x828)
#define SOC_TZPC_AO_DECPROT3CLR_ADDR(base) ((base) + 0x82C)
#define SOC_TZPC_AO_DECPROT4STAT_ADDR(base) ((base) + 0x830)
#define SOC_TZPC_AO_DECPROT4SET_ADDR(base) ((base) + 0x834)
#define SOC_TZPC_AO_DECPROT4CLR_ADDR(base) ((base) + 0x838)
#define SOC_TZPC_AO_DECPROT5STAT_ADDR(base) ((base) + 0x83C)
#define SOC_TZPC_AO_DECPROT5SET_ADDR(base) ((base) + 0x840)
#define SOC_TZPC_AO_DECPROT5CLR_ADDR(base) ((base) + 0x844)
#define SOC_TZPC_AO_DECPROT6STAT_ADDR(base) ((base) + 0x848)
#define SOC_TZPC_AO_DECPROT6SET_ADDR(base) ((base) + 0x84C)
#define SOC_TZPC_AO_DECPROT6CLR_ADDR(base) ((base) + 0x850)
#define SOC_TZPC_AO_DECPROT7STAT_ADDR(base) ((base) + 0x854)
#define SOC_TZPC_AO_DECPROT7SET_ADDR(base) ((base) + 0x858)
#define SOC_TZPC_AO_DECPROT7CLR_ADDR(base) ((base) + 0x85C)
#define SOC_TZPC_AO_DECPROT8STAT_ADDR(base) ((base) + 0x860)
#define SOC_TZPC_AO_DECPROT8SET_ADDR(base) ((base) + 0x864)
#define SOC_TZPC_AO_DECPROT8CLR_ADDR(base) ((base) + 0x868)
#define SOC_TZPC_AO_DECPROT9STAT_ADDR(base) ((base) + 0x86C)
#define SOC_TZPC_AO_DECPROT9SET_ADDR(base) ((base) + 0x870)
#define SOC_TZPC_AO_DECPROT9CLR_ADDR(base) ((base) + 0x874)
#define SOC_TZPC_AO_DECPROT10STAT_ADDR(base) ((base) + 0x878)
#define SOC_TZPC_AO_DECPROT10SET_ADDR(base) ((base) + 0x87C)
#define SOC_TZPC_AO_DECPROT10CLR_ADDR(base) ((base) + 0x880)
#define SOC_TZPC_AO_DECPROT11STAT_ADDR(base) ((base) + 0x884)
#define SOC_TZPC_AO_DECPROT11SET_ADDR(base) ((base) + 0x888)
#define SOC_TZPC_AO_DECPROT11CLR_ADDR(base) ((base) + 0x88C)
#define SOC_TZPC_AO_DECPROT12STAT_ADDR(base) ((base) + 0x890)
#define SOC_TZPC_AO_DECPROT12SET_ADDR(base) ((base) + 0x894)
#define SOC_TZPC_AO_DECPROT12CLR_ADDR(base) ((base) + 0x898)
#define SOC_TZPC_AO_DECPROT13STAT_ADDR(base) ((base) + 0x89C)
#define SOC_TZPC_AO_DECPROT13SET_ADDR(base) ((base) + 0x8A0)
#define SOC_TZPC_AO_DECPROT13CLR_ADDR(base) ((base) + 0x8A4)
#define SOC_TZPC_AO_DECPROT14STAT_ADDR(base) ((base) + 0x8A8)
#define SOC_TZPC_AO_DECPROT14SET_ADDR(base) ((base) + 0x8AC)
#define SOC_TZPC_AO_DECPROT14CLR_ADDR(base) ((base) + 0x8B0)
#define SOC_TZPC_AO_DECPROT15STAT_ADDR(base) ((base) + 0x8B4)
#define SOC_TZPC_AO_DECPROT15SET_ADDR(base) ((base) + 0x8B8)
#define SOC_TZPC_AO_DECPROT15CLR_ADDR(base) ((base) + 0x8BC)
#define SOC_TZPC_AO_DECPROT16STAT_ADDR(base) ((base) + 0x8C0)
#define SOC_TZPC_AO_DECPROT16SET_ADDR(base) ((base) + 0x8C4)
#define SOC_TZPC_AO_DECPROT16CLR_ADDR(base) ((base) + 0x8C8)
#define SOC_TZPC_AO_DECPROT17STAT_ADDR(base) ((base) + 0x8CC)
#define SOC_TZPC_AO_DECPROT17SET_ADDR(base) ((base) + 0x8D0)
#define SOC_TZPC_AO_DECPROT17CLR_ADDR(base) ((base) + 0x8D4)
#define SOC_TZPC_AO_REG1_STAT_ADDR(base) ((base) + 0xA04)
#define SOC_TZPC_AO_LOCK_ADDR(base) ((base) + 0xF00)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TZPC_R0SIZE_ADDR(base) (base)
#define SOC_TZPC_DECPROT0STAT_ADDR(base) ((base) + 0x800UL)
#define SOC_TZPC_DECPROT0SET_ADDR(base) ((base) + 0x804UL)
#define SOC_TZPC_DECPROT0CLR_ADDR(base) ((base) + 0x808UL)
#define SOC_TZPC_DECPROT1STAT_ADDR(base) ((base) + 0x80CUL)
#define SOC_TZPC_DECPROT1SET_ADDR(base) ((base) + 0x810UL)
#define SOC_TZPC_DECPROT1CLR_ADDR(base) ((base) + 0x814UL)
#define SOC_TZPC_DECPROT2STAT_ADDR(base) ((base) + 0x818UL)
#define SOC_TZPC_DECPROT2SET_ADDR(base) ((base) + 0x81CUL)
#define SOC_TZPC_DECPROT2CLR_ADDR(base) ((base) + 0x820UL)
#define SOC_TZPC_DECPROT3STAT_ADDR(base) ((base) + 0x824UL)
#define SOC_TZPC_DECPROT3SET_ADDR(base) ((base) + 0x828UL)
#define SOC_TZPC_DECPROT3CLR_ADDR(base) ((base) + 0x82CUL)
#define SOC_TZPC_DECPROT4STAT_ADDR(base) ((base) + 0x830UL)
#define SOC_TZPC_DECPROT4SET_ADDR(base) ((base) + 0x834UL)
#define SOC_TZPC_DECPROT4CLR_ADDR(base) ((base) + 0x838UL)
#define SOC_TZPC_DECPROT5STAT_ADDR(base) ((base) + 0x83CUL)
#define SOC_TZPC_DECPROT5SET_ADDR(base) ((base) + 0x840UL)
#define SOC_TZPC_DECPROT5CLR_ADDR(base) ((base) + 0x844UL)
#define SOC_TZPC_DECPROT6STAT_ADDR(base) ((base) + 0x848UL)
#define SOC_TZPC_DECPROT6SET_ADDR(base) ((base) + 0x84CUL)
#define SOC_TZPC_DECPROT6CLR_ADDR(base) ((base) + 0x850UL)
#define SOC_TZPC_DECPROT7STAT_ADDR(base) ((base) + 0x854UL)
#define SOC_TZPC_DECPROT7SET_ADDR(base) ((base) + 0x858UL)
#define SOC_TZPC_DECPROT7CLR_ADDR(base) ((base) + 0x85CUL)
#define SOC_TZPC_DECPROT8STAT_ADDR(base) ((base) + 0x860UL)
#define SOC_TZPC_DECPROT8SET_ADDR(base) ((base) + 0x864UL)
#define SOC_TZPC_DECPROT8CLR_ADDR(base) ((base) + 0x868UL)
#define SOC_TZPC_DECPROT9STAT_ADDR(base) ((base) + 0x874UL)
#define SOC_TZPC_DECPROT9SET_ADDR(base) ((base) + 0x878UL)
#define SOC_TZPC_DECPROT9CLR_ADDR(base) ((base) + 0x87CUL)
#define SOC_TZPC_DECPROT10STAT_ADDR(base) ((base) + 0x880UL)
#define SOC_TZPC_DECPROT10SET_ADDR(base) ((base) + 0x884UL)
#define SOC_TZPC_DECPROT10CLR_ADDR(base) ((base) + 0x888UL)
#define SOC_TZPC_DECPROT11STAT_ADDR(base) ((base) + 0x88CUL)
#define SOC_TZPC_DECPROT11SET_ADDR(base) ((base) + 0x890UL)
#define SOC_TZPC_DECPROT11CLR_ADDR(base) ((base) + 0x894UL)
#define SOC_TZPC_DECPROT21STAT_ADDR(base) ((base) + 0x898UL)
#define SOC_TZPC_DECPROT12SET_ADDR(base) ((base) + 0x89CUL)
#define SOC_TZPC_DECPROT12CLR_ADDR(base) ((base) + 0x8A0UL)
#define SOC_TZPC_REG0_STAT_ADDR(base) ((base) + 0x86CUL)
#define SOC_TZPC_REG1_STAT_ADDR(base) ((base) + 0x870UL)
#define SOC_TZPC_PERI_LOCK_ADDR(base) ((base) + 0xF00UL)
#else
#define SOC_TZPC_R0SIZE_ADDR(base) (base)
#define SOC_TZPC_DECPROT0STAT_ADDR(base) ((base) + 0x800)
#define SOC_TZPC_DECPROT0SET_ADDR(base) ((base) + 0x804)
#define SOC_TZPC_DECPROT0CLR_ADDR(base) ((base) + 0x808)
#define SOC_TZPC_DECPROT1STAT_ADDR(base) ((base) + 0x80C)
#define SOC_TZPC_DECPROT1SET_ADDR(base) ((base) + 0x810)
#define SOC_TZPC_DECPROT1CLR_ADDR(base) ((base) + 0x814)
#define SOC_TZPC_DECPROT2STAT_ADDR(base) ((base) + 0x818)
#define SOC_TZPC_DECPROT2SET_ADDR(base) ((base) + 0x81C)
#define SOC_TZPC_DECPROT2CLR_ADDR(base) ((base) + 0x820)
#define SOC_TZPC_DECPROT3STAT_ADDR(base) ((base) + 0x824)
#define SOC_TZPC_DECPROT3SET_ADDR(base) ((base) + 0x828)
#define SOC_TZPC_DECPROT3CLR_ADDR(base) ((base) + 0x82C)
#define SOC_TZPC_DECPROT4STAT_ADDR(base) ((base) + 0x830)
#define SOC_TZPC_DECPROT4SET_ADDR(base) ((base) + 0x834)
#define SOC_TZPC_DECPROT4CLR_ADDR(base) ((base) + 0x838)
#define SOC_TZPC_DECPROT5STAT_ADDR(base) ((base) + 0x83C)
#define SOC_TZPC_DECPROT5SET_ADDR(base) ((base) + 0x840)
#define SOC_TZPC_DECPROT5CLR_ADDR(base) ((base) + 0x844)
#define SOC_TZPC_DECPROT6STAT_ADDR(base) ((base) + 0x848)
#define SOC_TZPC_DECPROT6SET_ADDR(base) ((base) + 0x84C)
#define SOC_TZPC_DECPROT6CLR_ADDR(base) ((base) + 0x850)
#define SOC_TZPC_DECPROT7STAT_ADDR(base) ((base) + 0x854)
#define SOC_TZPC_DECPROT7SET_ADDR(base) ((base) + 0x858)
#define SOC_TZPC_DECPROT7CLR_ADDR(base) ((base) + 0x85C)
#define SOC_TZPC_DECPROT8STAT_ADDR(base) ((base) + 0x860)
#define SOC_TZPC_DECPROT8SET_ADDR(base) ((base) + 0x864)
#define SOC_TZPC_DECPROT8CLR_ADDR(base) ((base) + 0x868)
#define SOC_TZPC_DECPROT9STAT_ADDR(base) ((base) + 0x874)
#define SOC_TZPC_DECPROT9SET_ADDR(base) ((base) + 0x878)
#define SOC_TZPC_DECPROT9CLR_ADDR(base) ((base) + 0x87C)
#define SOC_TZPC_DECPROT10STAT_ADDR(base) ((base) + 0x880)
#define SOC_TZPC_DECPROT10SET_ADDR(base) ((base) + 0x884)
#define SOC_TZPC_DECPROT10CLR_ADDR(base) ((base) + 0x888)
#define SOC_TZPC_DECPROT11STAT_ADDR(base) ((base) + 0x88C)
#define SOC_TZPC_DECPROT11SET_ADDR(base) ((base) + 0x890)
#define SOC_TZPC_DECPROT11CLR_ADDR(base) ((base) + 0x894)
#define SOC_TZPC_DECPROT21STAT_ADDR(base) ((base) + 0x898)
#define SOC_TZPC_DECPROT12SET_ADDR(base) ((base) + 0x89C)
#define SOC_TZPC_DECPROT12CLR_ADDR(base) ((base) + 0x8A0)
#define SOC_TZPC_REG0_STAT_ADDR(base) ((base) + 0x86C)
#define SOC_TZPC_REG1_STAT_ADDR(base) ((base) + 0x870)
#define SOC_TZPC_PERI_LOCK_ADDR(base) ((base) + 0xF00)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_TZPC_AO_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT0STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT0STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT0STAT_AO_DECPROT0STAT_START (0)
#define SOC_TZPC_AO_DECPROT0STAT_AO_DECPROT0STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT0SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT0SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT0SET_AO_DECPROT0SET_START (0)
#define SOC_TZPC_AO_DECPROT0SET_AO_DECPROT0SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT0CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT0CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT0CLR_AO_DECPROT0CLR_START (0)
#define SOC_TZPC_AO_DECPROT0CLR_AO_DECPROT0CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT1STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT1STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT1STAT_AO_DECPROT1STAT_START (0)
#define SOC_TZPC_AO_DECPROT1STAT_AO_DECPROT1STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT1SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT1SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT1SET_AO_DECPROT1SET_START (0)
#define SOC_TZPC_AO_DECPROT1SET_AO_DECPROT1SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT1CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT1CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT1CLR_AO_DECPROT1CLR_START (0)
#define SOC_TZPC_AO_DECPROT1CLR_AO_DECPROT1CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT2STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT2STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT2STAT_AO_DECPROT2STAT_START (0)
#define SOC_TZPC_AO_DECPROT2STAT_AO_DECPROT2STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT2SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT2SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT2SET_AO_DECPROT2SET_START (0)
#define SOC_TZPC_AO_DECPROT2SET_AO_DECPROT2SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT2CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT2CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT2CLR_AO_DECPROT2CLR_START (0)
#define SOC_TZPC_AO_DECPROT2CLR_AO_DECPROT2CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT3STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT3STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT3STAT_AO_DECPROT3STAT_START (0)
#define SOC_TZPC_AO_DECPROT3STAT_AO_DECPROT3STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT3SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT3SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT3SET_AO_DECPROT3SET_START (0)
#define SOC_TZPC_AO_DECPROT3SET_AO_DECPROT3SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT3CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT3CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT3CLR_AO_DECPROT3CLR_START (0)
#define SOC_TZPC_AO_DECPROT3CLR_AO_DECPROT3CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT4STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT4STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT4STAT_AO_DECPROT4STAT_START (0)
#define SOC_TZPC_AO_DECPROT4STAT_AO_DECPROT4STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT4SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT4SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT4SET_AO_DECPROT4SET_START (0)
#define SOC_TZPC_AO_DECPROT4SET_AO_DECPROT4SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT4CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT4CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT4CLR_AO_DECPROT4CLR_START (0)
#define SOC_TZPC_AO_DECPROT4CLR_AO_DECPROT4CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT5STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT5STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT5STAT_AO_DECPROT5STAT_START (0)
#define SOC_TZPC_AO_DECPROT5STAT_AO_DECPROT5STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT5SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT5SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT5SET_AO_DECPROT5SET_START (0)
#define SOC_TZPC_AO_DECPROT5SET_AO_DECPROT5SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT5CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT5CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT5CLR_AO_DECPROT5CLR_START (0)
#define SOC_TZPC_AO_DECPROT5CLR_AO_DECPROT5CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT6STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT6STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT6STAT_AO_DECPROT6STAT_START (0)
#define SOC_TZPC_AO_DECPROT6STAT_AO_DECPROT6STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT6SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT6SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT6SET_AO_DECPROT6SET_START (0)
#define SOC_TZPC_AO_DECPROT6SET_AO_DECPROT6SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT6CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT6CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT6CLR_AO_DECPROT6CLR_START (0)
#define SOC_TZPC_AO_DECPROT6CLR_AO_DECPROT6CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT7STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT7STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT7STAT_AO_DECPROT7STAT_START (0)
#define SOC_TZPC_AO_DECPROT7STAT_AO_DECPROT7STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT7SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT7SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT7SET_AO_DECPROT7SET_START (0)
#define SOC_TZPC_AO_DECPROT7SET_AO_DECPROT7SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT7CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT7CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT7CLR_AO_DECPROT7CLR_START (0)
#define SOC_TZPC_AO_DECPROT7CLR_AO_DECPROT7CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT8STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT8STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT8STAT_AO_DECPROT8STAT_START (0)
#define SOC_TZPC_AO_DECPROT8STAT_AO_DECPROT8STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT8SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT8SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT8SET_AO_DECPROT8SET_START (0)
#define SOC_TZPC_AO_DECPROT8SET_AO_DECPROT8SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT8CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT8CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT8CLR_AO_DECPROT8CLR_START (0)
#define SOC_TZPC_AO_DECPROT8CLR_AO_DECPROT8CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT9STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT9STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT9STAT_AO_DECPROT9STAT_START (0)
#define SOC_TZPC_AO_DECPROT9STAT_AO_DECPROT9STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT9SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT9SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT9SET_AO_DECPROT9SET_START (0)
#define SOC_TZPC_AO_DECPROT9SET_AO_DECPROT9SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT9CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT9CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT9CLR_AO_DECPROT9CLR_START (0)
#define SOC_TZPC_AO_DECPROT9CLR_AO_DECPROT9CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT10STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT10STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT10STAT_AO_DECPROT10STAT_START (0)
#define SOC_TZPC_AO_DECPROT10STAT_AO_DECPROT10STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT10SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT10SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT10SET_AO_DECPROT10SET_START (0)
#define SOC_TZPC_AO_DECPROT10SET_AO_DECPROT10SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT10CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT10CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT10CLR_AO_DECPROT10CLR_START (0)
#define SOC_TZPC_AO_DECPROT10CLR_AO_DECPROT10CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT11STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT11STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT11STAT_AO_DECPROT11STAT_START (0)
#define SOC_TZPC_AO_DECPROT11STAT_AO_DECPROT11STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT11SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT11SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT11SET_AO_DECPROT11SET_START (0)
#define SOC_TZPC_AO_DECPROT11SET_AO_DECPROT11SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT11CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT11CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT11CLR_AO_DECPROT11CLR_START (0)
#define SOC_TZPC_AO_DECPROT11CLR_AO_DECPROT11CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT12STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT12STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT12STAT_AO_DECPROT12STAT_START (0)
#define SOC_TZPC_AO_DECPROT12STAT_AO_DECPROT12STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT12SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT12SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT12SET_AO_DECPROT12SET_START (0)
#define SOC_TZPC_AO_DECPROT12SET_AO_DECPROT12SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT12CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT12CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT12CLR_AO_DECPROT12CLR_START (0)
#define SOC_TZPC_AO_DECPROT12CLR_AO_DECPROT12CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT13STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT13STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT13STAT_AO_DECPROT13STAT_START (0)
#define SOC_TZPC_AO_DECPROT13STAT_AO_DECPROT13STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT13SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT13SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT13SET_AO_DECPROT13SET_START (0)
#define SOC_TZPC_AO_DECPROT13SET_AO_DECPROT13SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT13CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT13CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT13CLR_AO_DECPROT13CLR_START (0)
#define SOC_TZPC_AO_DECPROT13CLR_AO_DECPROT13CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT14STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT14STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT14STAT_AO_DECPROT14STAT_START (0)
#define SOC_TZPC_AO_DECPROT14STAT_AO_DECPROT14STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT14SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT14SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT14SET_AO_DECPROT14SET_START (0)
#define SOC_TZPC_AO_DECPROT14SET_AO_DECPROT14SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT14CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT14CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT14CLR_AO_DECPROT14CLR_START (0)
#define SOC_TZPC_AO_DECPROT14CLR_AO_DECPROT14CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT15STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT15STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT15STAT_AO_DECPROT15STAT_START (0)
#define SOC_TZPC_AO_DECPROT15STAT_AO_DECPROT15STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT15SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT15SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT15SET_AO_DECPROT15SET_START (0)
#define SOC_TZPC_AO_DECPROT15SET_AO_DECPROT15SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT15CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT15CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT15CLR_AO_DECPROT15CLR_START (0)
#define SOC_TZPC_AO_DECPROT15CLR_AO_DECPROT15CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT16STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT16STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT16STAT_AO_DECPROT16STAT_START (0)
#define SOC_TZPC_AO_DECPROT16STAT_AO_DECPROT16STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT16SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT16SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT16SET_AO_DECPROT16SET_START (0)
#define SOC_TZPC_AO_DECPROT16SET_AO_DECPROT16SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT16CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT16CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT16CLR_AO_DECPROT16CLR_START (0)
#define SOC_TZPC_AO_DECPROT16CLR_AO_DECPROT16CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT17STAT : 32;
    } reg;
} SOC_TZPC_AO_DECPROT17STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT17STAT_AO_DECPROT17STAT_START (0)
#define SOC_TZPC_AO_DECPROT17STAT_AO_DECPROT17STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT17SET : 32;
    } reg;
} SOC_TZPC_AO_DECPROT17SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT17SET_AO_DECPROT17SET_START (0)
#define SOC_TZPC_AO_DECPROT17SET_AO_DECPROT17SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_DECPROT17CLR : 32;
    } reg;
} SOC_TZPC_AO_DECPROT17CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT17CLR_AO_DECPROT17CLR_START (0)
#define SOC_TZPC_AO_DECPROT17CLR_AO_DECPROT17CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_REG1_STAT : 32;
    } reg;
} SOC_TZPC_AO_REG1_STAT_UNION;
#endif
#define SOC_TZPC_AO_REG1_STAT_AO_REG1_STAT_START (0)
#define SOC_TZPC_AO_REG1_STAT_AO_REG1_STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int AO_LOCK : 32;
    } reg;
} SOC_TZPC_AO_LOCK_UNION;
#endif
#define SOC_TZPC_AO_LOCK_AO_LOCK_START (0)
#define SOC_TZPC_AO_LOCK_AO_LOCK_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_TZPC_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT0STAT : 32;
    } reg;
} SOC_TZPC_DECPROT0STAT_UNION;
#endif
#define SOC_TZPC_DECPROT0STAT_DECPROT0STAT_START (0)
#define SOC_TZPC_DECPROT0STAT_DECPROT0STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT0SET : 32;
    } reg;
} SOC_TZPC_DECPROT0SET_UNION;
#endif
#define SOC_TZPC_DECPROT0SET_DECPROT0SET_START (0)
#define SOC_TZPC_DECPROT0SET_DECPROT0SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT0CLR : 32;
    } reg;
} SOC_TZPC_DECPROT0CLR_UNION;
#endif
#define SOC_TZPC_DECPROT0CLR_DECPROT0CLR_START (0)
#define SOC_TZPC_DECPROT0CLR_DECPROT0CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT1STAT : 32;
    } reg;
} SOC_TZPC_DECPROT1STAT_UNION;
#endif
#define SOC_TZPC_DECPROT1STAT_DECPROT1STAT_START (0)
#define SOC_TZPC_DECPROT1STAT_DECPROT1STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT1SET : 32;
    } reg;
} SOC_TZPC_DECPROT1SET_UNION;
#endif
#define SOC_TZPC_DECPROT1SET_DECPROT1SET_START (0)
#define SOC_TZPC_DECPROT1SET_DECPROT1SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT1CLR : 32;
    } reg;
} SOC_TZPC_DECPROT1CLR_UNION;
#endif
#define SOC_TZPC_DECPROT1CLR_DECPROT1CLR_START (0)
#define SOC_TZPC_DECPROT1CLR_DECPROT1CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT2STAT : 32;
    } reg;
} SOC_TZPC_DECPROT2STAT_UNION;
#endif
#define SOC_TZPC_DECPROT2STAT_DECPROT2STAT_START (0)
#define SOC_TZPC_DECPROT2STAT_DECPROT2STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT2SET : 32;
    } reg;
} SOC_TZPC_DECPROT2SET_UNION;
#endif
#define SOC_TZPC_DECPROT2SET_DECPROT2SET_START (0)
#define SOC_TZPC_DECPROT2SET_DECPROT2SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT2CLR : 32;
    } reg;
} SOC_TZPC_DECPROT2CLR_UNION;
#endif
#define SOC_TZPC_DECPROT2CLR_DECPROT2CLR_START (0)
#define SOC_TZPC_DECPROT2CLR_DECPROT2CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT3STAT : 32;
    } reg;
} SOC_TZPC_DECPROT3STAT_UNION;
#endif
#define SOC_TZPC_DECPROT3STAT_DECPROT3STAT_START (0)
#define SOC_TZPC_DECPROT3STAT_DECPROT3STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT3SET : 32;
    } reg;
} SOC_TZPC_DECPROT3SET_UNION;
#endif
#define SOC_TZPC_DECPROT3SET_DECPROT3SET_START (0)
#define SOC_TZPC_DECPROT3SET_DECPROT3SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT3CLR : 32;
    } reg;
} SOC_TZPC_DECPROT3CLR_UNION;
#endif
#define SOC_TZPC_DECPROT3CLR_DECPROT3CLR_START (0)
#define SOC_TZPC_DECPROT3CLR_DECPROT3CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT4STAT : 32;
    } reg;
} SOC_TZPC_DECPROT4STAT_UNION;
#endif
#define SOC_TZPC_DECPROT4STAT_DECPROT4STAT_START (0)
#define SOC_TZPC_DECPROT4STAT_DECPROT4STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT4SET : 32;
    } reg;
} SOC_TZPC_DECPROT4SET_UNION;
#endif
#define SOC_TZPC_DECPROT4SET_DECPROT4SET_START (0)
#define SOC_TZPC_DECPROT4SET_DECPROT4SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT4CLR : 32;
    } reg;
} SOC_TZPC_DECPROT4CLR_UNION;
#endif
#define SOC_TZPC_DECPROT4CLR_DECPROT4CLR_START (0)
#define SOC_TZPC_DECPROT4CLR_DECPROT4CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT5STAT : 32;
    } reg;
} SOC_TZPC_DECPROT5STAT_UNION;
#endif
#define SOC_TZPC_DECPROT5STAT_DECPROT5STAT_START (0)
#define SOC_TZPC_DECPROT5STAT_DECPROT5STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT5SET : 32;
    } reg;
} SOC_TZPC_DECPROT5SET_UNION;
#endif
#define SOC_TZPC_DECPROT5SET_DECPROT5SET_START (0)
#define SOC_TZPC_DECPROT5SET_DECPROT5SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT5CLR : 32;
    } reg;
} SOC_TZPC_DECPROT5CLR_UNION;
#endif
#define SOC_TZPC_DECPROT5CLR_DECPROT5CLR_START (0)
#define SOC_TZPC_DECPROT5CLR_DECPROT5CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT6STAT : 32;
    } reg;
} SOC_TZPC_DECPROT6STAT_UNION;
#endif
#define SOC_TZPC_DECPROT6STAT_DECPROT6STAT_START (0)
#define SOC_TZPC_DECPROT6STAT_DECPROT6STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT6SET : 32;
    } reg;
} SOC_TZPC_DECPROT6SET_UNION;
#endif
#define SOC_TZPC_DECPROT6SET_DECPROT6SET_START (0)
#define SOC_TZPC_DECPROT6SET_DECPROT6SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT6CLR : 32;
    } reg;
} SOC_TZPC_DECPROT6CLR_UNION;
#endif
#define SOC_TZPC_DECPROT6CLR_DECPROT6CLR_START (0)
#define SOC_TZPC_DECPROT6CLR_DECPROT6CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT7STAT : 32;
    } reg;
} SOC_TZPC_DECPROT7STAT_UNION;
#endif
#define SOC_TZPC_DECPROT7STAT_DECPROT7STAT_START (0)
#define SOC_TZPC_DECPROT7STAT_DECPROT7STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT7SET : 32;
    } reg;
} SOC_TZPC_DECPROT7SET_UNION;
#endif
#define SOC_TZPC_DECPROT7SET_DECPROT7SET_START (0)
#define SOC_TZPC_DECPROT7SET_DECPROT7SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT7CLR : 32;
    } reg;
} SOC_TZPC_DECPROT7CLR_UNION;
#endif
#define SOC_TZPC_DECPROT7CLR_DECPROT7CLR_START (0)
#define SOC_TZPC_DECPROT7CLR_DECPROT7CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT8STAT : 32;
    } reg;
} SOC_TZPC_DECPROT8STAT_UNION;
#endif
#define SOC_TZPC_DECPROT8STAT_DECPROT8STAT_START (0)
#define SOC_TZPC_DECPROT8STAT_DECPROT8STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT8SET : 32;
    } reg;
} SOC_TZPC_DECPROT8SET_UNION;
#endif
#define SOC_TZPC_DECPROT8SET_DECPROT8SET_START (0)
#define SOC_TZPC_DECPROT8SET_DECPROT8SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT8CLR : 32;
    } reg;
} SOC_TZPC_DECPROT8CLR_UNION;
#endif
#define SOC_TZPC_DECPROT8CLR_DECPROT8CLR_START (0)
#define SOC_TZPC_DECPROT8CLR_DECPROT8CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT9STAT : 32;
    } reg;
} SOC_TZPC_DECPROT9STAT_UNION;
#endif
#define SOC_TZPC_DECPROT9STAT_DECPROT9STAT_START (0)
#define SOC_TZPC_DECPROT9STAT_DECPROT9STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT9SET : 32;
    } reg;
} SOC_TZPC_DECPROT9SET_UNION;
#endif
#define SOC_TZPC_DECPROT9SET_DECPROT9SET_START (0)
#define SOC_TZPC_DECPROT9SET_DECPROT9SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT9CLR : 32;
    } reg;
} SOC_TZPC_DECPROT9CLR_UNION;
#endif
#define SOC_TZPC_DECPROT9CLR_DECPROT9CLR_START (0)
#define SOC_TZPC_DECPROT9CLR_DECPROT9CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT10STAT : 32;
    } reg;
} SOC_TZPC_DECPROT10STAT_UNION;
#endif
#define SOC_TZPC_DECPROT10STAT_DECPROT10STAT_START (0)
#define SOC_TZPC_DECPROT10STAT_DECPROT10STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT10SET : 32;
    } reg;
} SOC_TZPC_DECPROT10SET_UNION;
#endif
#define SOC_TZPC_DECPROT10SET_DECPROT10SET_START (0)
#define SOC_TZPC_DECPROT10SET_DECPROT10SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT10CLR : 32;
    } reg;
} SOC_TZPC_DECPROT10CLR_UNION;
#endif
#define SOC_TZPC_DECPROT10CLR_DECPROT10CLR_START (0)
#define SOC_TZPC_DECPROT10CLR_DECPROT10CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT11STAT : 32;
    } reg;
} SOC_TZPC_DECPROT11STAT_UNION;
#endif
#define SOC_TZPC_DECPROT11STAT_DECPROT11STAT_START (0)
#define SOC_TZPC_DECPROT11STAT_DECPROT11STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT11SET : 32;
    } reg;
} SOC_TZPC_DECPROT11SET_UNION;
#endif
#define SOC_TZPC_DECPROT11SET_DECPROT11SET_START (0)
#define SOC_TZPC_DECPROT11SET_DECPROT11SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT11CLR : 32;
    } reg;
} SOC_TZPC_DECPROT11CLR_UNION;
#endif
#define SOC_TZPC_DECPROT11CLR_DECPROT11CLR_START (0)
#define SOC_TZPC_DECPROT11CLR_DECPROT11CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT12STAT : 32;
    } reg;
} SOC_TZPC_DECPROT21STAT_UNION;
#endif
#define SOC_TZPC_DECPROT21STAT_DECPROT12STAT_START (0)
#define SOC_TZPC_DECPROT21STAT_DECPROT12STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT12SET : 32;
    } reg;
} SOC_TZPC_DECPROT12SET_UNION;
#endif
#define SOC_TZPC_DECPROT12SET_DECPROT12SET_START (0)
#define SOC_TZPC_DECPROT12SET_DECPROT12SET_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int DECPROT12CLR : 32;
    } reg;
} SOC_TZPC_DECPROT12CLR_UNION;
#endif
#define SOC_TZPC_DECPROT12CLR_DECPROT12CLR_START (0)
#define SOC_TZPC_DECPROT12CLR_DECPROT12CLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int REG0_STAT : 32;
    } reg;
} SOC_TZPC_REG0_STAT_UNION;
#endif
#define SOC_TZPC_REG0_STAT_REG0_STAT_START (0)
#define SOC_TZPC_REG0_STAT_REG0_STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int REG1_STAT : 32;
    } reg;
} SOC_TZPC_REG1_STAT_UNION;
#endif
#define SOC_TZPC_REG1_STAT_REG1_STAT_START (0)
#define SOC_TZPC_REG1_STAT_REG1_STAT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int PERI_LOCK : 32;
    } reg;
} SOC_TZPC_PERI_LOCK_UNION;
#endif
#define SOC_TZPC_PERI_LOCK_PERI_LOCK_START (0)
#define SOC_TZPC_PERI_LOCK_PERI_LOCK_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
