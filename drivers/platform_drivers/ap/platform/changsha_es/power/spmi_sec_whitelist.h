#ifndef __SPMI_SEC_WHITELIST_H__
#define __SPMI_SEC_WHITELIST_H__ 
#define SPMI_SLAVEID_PMU 9
#define SPMI_SLAVEID_SUBPMU1 2
#define SPMI_SLAVEID_SUBPMU2 3
#define SPMI_SLAVEID_EOF 16
struct spmi_sec_reg {
    unsigned char sid;
    unsigned short addr;
};
static struct spmi_sec_reg spmi_sec_whitelist_pmu[] = {
    {SPMI_SLAVEID_PMU, 0xC58},
    {SPMI_SLAVEID_PMU, 0xC59},
    {SPMI_SLAVEID_PMU, 0xC68},
    {SPMI_SLAVEID_EOF, 0x0},
};
static struct spmi_sec_reg spmi_sec_whitelist_subpmu1[] = {
    {SPMI_SLAVEID_SUBPMU1, 0xC1A},
    {SPMI_SLAVEID_SUBPMU1, 0xC1B},
    {SPMI_SLAVEID_EOF, 0x0},
};
static struct spmi_sec_reg spmi_sec_whitelist_subpmu2[] = {
    {SPMI_SLAVEID_SUBPMU2, 0xC1A},
    {SPMI_SLAVEID_SUBPMU2, 0xC1B},
    {SPMI_SLAVEID_EOF, 0x0},
};
static struct spmi_sec_reg* spmi_sec_whitelist[SPMI_SLAVEID_EOF] = {
    [SPMI_SLAVEID_PMU] = spmi_sec_whitelist_pmu,
    [SPMI_SLAVEID_SUBPMU1] = spmi_sec_whitelist_subpmu1,
    [SPMI_SLAVEID_SUBPMU2] = spmi_sec_whitelist_subpmu2,
};
#endif
