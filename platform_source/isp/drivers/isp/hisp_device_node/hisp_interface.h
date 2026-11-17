
#ifndef HISP_INTERFACE_H
#define HISP_INTERFACE_H

typedef struct _hisp_pu_info_t {
	unsigned int reserved;
	int result;
}  hisp_pu_info_t;

typedef struct _hisp_pd_info_t {
	unsigned int reserved;
	int result;
}  hisp_pd_info_t;

typedef struct _hisp_set_clk_t {
	unsigned int type;
	unsigned int clk_level;
	int result;
} hisp_set_clk_t;

typedef struct _hisp_mem_map_t {
	unsigned int master_type;
	unsigned int mem_type;
	int fd;
	unsigned int size;
	unsigned int prot;
	unsigned int isp_core_iova;
	unsigned long long mapped_addr;
	unsigned int mapped_size;
	int result;
} hisp_mem_map_t;

typedef struct _hisp_mem_unmap_t {
	unsigned int master_type;
	unsigned int mem_type;
	unsigned int reserve;
	unsigned int isp_core_iova;
	unsigned long long unmap_addr;
	unsigned int unmap_size;
	int result;
} hisp_mem_unmap_t;

typedef struct _isp_msg_t {
	void *data;
	unsigned int size;
	int result;
} isp_msg_t;

typedef enum {
	ISP_DEV_UNINITIAL = 0,
	ISP_DEV_INITIAL,
	ISP_DEV_OPEN,
	ISP_DEV_POWER_UP,
	ISP_DEV_STATE_MAX
} isp_dev_state;

#define HISP_IOCTL_POWER_UP       _IOWR('i', 0x01, hisp_pu_info_t)
#define HISP_IOCTL_POWER_DOWN     _IOWR('i', 0x02, hisp_pd_info_t)
#define HISP_IOCTL_SET_CLK_RATE   _IOWR('i', 0x03, hisp_set_clk_t)
#define HISP_IOCTL_MEM_MAP        _IOWR('i', 0x04, hisp_mem_map_t)
#define HISP_IOCTL_MEM_UNMAP      _IOWR('i', 0x05, hisp_mem_unmap_t)
#define HISP_IOCTL_RPMSG_SEND     _IOWR('i', 0x06, isp_msg_t)
#define HISP_IOCTL_RPMSG_RECV     _IOWR('i', 0x07, isp_msg_t)

#define ISP_RPMSG_RECV_TIMEOUT_TIME 3
#ifndef DEBUG_HISP
#define MAX_HISP_CANN 1
#endif

#endif /* HISP_INTERFACE_H */

