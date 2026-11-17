#include <bsp_print.h>
#include <bsp_version.h>
#include <securec.h>
#include <bsp_file_ops.h>
#include <mdrv_memory.h>
#include <mdrv_memory_layout.h>
#include <linux/io.h>
#include <bsp_slice.h>
#include "return_code.h"
#include "write_cov_file.h"
#include "file_option.h"

#define PATH_SIZE 512
#define COV_DIR "/data/hisi_logs"
#define LPMCU_MEM_NAME "lpmcu_ddr"
#define DPA_MEM_NAME "usshm_dpa_cov"

int autogen_file_name(char* file_path, char* dir_path, char* project_name, char* project_id)
{
    uint32_t timestamp = bsp_get_slice_value();
    int ret;

    ret = sprintf_s(file_path, PATH_SIZE, "%s/linuxavatar_%s_%s_%u", dir_path, project_name, project_id, timestamp);
    if (ret < 0) {
        bsp_err("write cov_path failed ret=%d, project_id:%s, project_name:%s\n", ret, project_id, project_name);
        return -STRING_FORMAT_FAIL;
    }

    return 0;
}

static int _write_cov_file(char * vaddr, unsigned int size)
{
    int ret;
    struct file* filp;
    char dir_path[PATH_SIZE];
    char file_path[PATH_SIZE];
    struct cov_data_hdr* cov_msg = NULL;

    cov_msg = (struct cov_data_hdr *)vaddr;
    if(cov_msg->data_len > (unsigned long)size) {
        bsp_err("illegal length of cov_data data_len:%llu, mem_size:%u\n", cov_msg->data_len, size);
        return -STRING_LEN_ERROR;
    }

    if ((cov_msg->build_id[0] == '\0') || (cov_msg->project_name[0] == '\0')) {
        bsp_err("blank param of cov_data build_id:%s, project_name:%s, data_ptr:%p\n", \
                cov_msg->build_id, cov_msg->project_name, cov_msg->data);
        return -STRING_LEN_ERROR;
    }
    if ((strlen(cov_msg->build_id) >= HITEST_STR_LEN) || (strlen(cov_msg->project_name) >= HITEST_STR_LEN)) {
        bsp_err("illegal param of cov_data build_id:%s, project_name:%s, data_ptr:%p\n", \
                cov_msg->build_id, cov_msg->project_name, cov_msg->data);
        return -STRING_LEN_ERROR;
    }

    ret = strcpy_s(dir_path, PATH_SIZE, COV_DIR);
    if (ret != 0) {
        bsp_err("copy dir_path for cov_file failed dir:%s, ret=%d\n", dir_path, ret);
        return -STRING_FORMAT_FAIL;
    }
    if (create_directory(dir_path) < 0) {
        bsp_err("unable mkdir for cov_file dir:%s\n", dir_path);
        return -CREATE_FILE_FAIL;
    }

    ret = autogen_file_name(file_path, dir_path, cov_msg->project_name, cov_msg->build_id);
    if (ret < 0) {
        bsp_err("write path for cov fialed\n");
        return -STRING_FORMAT_FAIL;
    }

    filp = filp_open(file_path, O_RDONLY, 0644);
    if (! IS_ERR(filp)) {
        bsp_err("already exist file, remove it and write again, file:%s\n", file_path);
        ret = bsp_unlink(file_path);
        if (ret == 0) {
        bsp_err("delete file :%s successfully\n", file_path);
        }
        else {
            bsp_err("failed delete file ret=%d file_path:%s\n", ret, file_path);
            return -ACORE_FAIL;
        }
    }

    ret = write_to_file(file_path, cov_msg->data, cov_msg->data_len, 0);
    if (ret < 0) {
        bsp_err("fail to write cov_file %s:\n", file_path);
        return -ACORE_FAIL;
    }

    bsp_err("finish write cov_data to file:%s\n", file_path);

    memset_s((void *)vaddr, size, 0, size);
    
    return ACORE_SUCCESS;
}

char * _get_mem_addr(const char *mem_name, unsigned int *size)
{
    const bsp_version_info_s* version_info = bsp_get_version_info();
    unsigned long phy_addr = 0;
    char *vaddr = NULL;

    if (version_info == NULL) {
        bsp_err("get version info failed\n");
        return NULL;
    }

    // MBB && lpmcu_mem
    if (version_info->product_type == 0 && strcmp(mem_name, LPMCU_MEM_NAME) == 0) {
        phy_addr = mdrv_mem_region_get(LPMCU_MEM_NAME, size);
        if (phy_addr == 0 || *size == 0) {
            bsp_err("failed get lpmcu shared_mem: phy=%ld, size=%d\n", phy_addr, *size);
            return NULL;
        }
        vaddr = (char *)ioremap_wc((void *)phy_addr, *size);
        if (vaddr == NULL) {
            bsp_err("map lpmcu_ddr phy to vir failed\n");
            return NULL;
        }
        bsp_err("get lpmcu share mem success\n");
        return vaddr;
    }

    // PHONE && dpa_mem
    else if(version_info->product_type != 0 && strcmp(mem_name, DPA_MEM_NAME) == 0) {
        vaddr = mdrv_mem_share_get(DPA_MEM_NAME, &phy_addr, size, SHM_UNSEC);
        if (phy_addr == 0 || *size == 0 || vaddr == NULL) {
            bsp_err("failed get dpa share_mem: phy=%ld,var=%lu,size=%d\n", phy_addr, vaddr, *size);
            return NULL;
        }
        bsp_err("get dpa share mem success\n");
        return vaddr;
    }

    // else not support
    else {
        bsp_err("Error: product_type=%hhu, share_mem=%s, not support cov", version_info->product_type, mem_name);
        return NULL;
    }
}

int _write_cov(const char *mem_name)
{
    char *vaddr = NULL;
    unsigned int size = 0;

    vaddr = (char *)_get_mem_addr(mem_name, &size);
    if (vaddr == NULL || size == 0) {
        bsp_err("failed get share mem vaddr, var=%lu,size=%d\n", vaddr, size);
        return -NULL_POINTER;
    }
    bsp_err("get share mem vaddr success\n");

    return _write_cov_file(vaddr, size);
}

int write_lpmcu_cov() 
{
    return _write_cov(LPMCU_MEM_NAME);
}
int write_dpa_cov() 
{
    return _write_cov(DPA_MEM_NAME);
}