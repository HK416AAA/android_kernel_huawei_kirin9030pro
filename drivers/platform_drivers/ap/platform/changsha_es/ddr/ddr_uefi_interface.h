#ifndef __DDR_UEFI_INTERFACE_H__
#define __DDR_UEFI_INTERFACE_H__ 
#include <global_ddr_map.h>
#include <ddr_define.h>
#include <ddr/ddr_release_message.h>
#define UEFI_DDRINFO_PHYINFO_SHARE_BASE HISI_SUB_RESERVED_UEFI_DDRINFO_SHARE_BASE
#define UEFI_DDRINFO_PHYINFO_SHARE_SIZE 0x1000
typedef ddr_release_message_str DDR_RELEASE_MESSAGE_STR;
#endif
