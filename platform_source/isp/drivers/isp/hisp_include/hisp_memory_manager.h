
#ifndef HISP_MEMORY_MANAGER_H
#define HISP_MEMORY_MANAGER_H

int hisp_driver_mem_map_addr(unsigned int master, struct hisp_mem_type type,
		      struct hisp_map_info_s *info, struct hisp_mem_info_s *mem);

int hisp_driver_mem_unmap_addr(unsigned int master, struct hisp_mem_type type,
			struct hisp_mem_info_s mem_info);

#if defined(ISP_LINX_CPU_SUPPORT)
void hisp_mem_list_clean(unsigned int master);
#elif defined(CONFIG_ISP_BUF_PRIVATIZE)
void hisp_mem_list_clean(void);
#endif

#endif /* HISP_MEMORY_MANAGER_H */

