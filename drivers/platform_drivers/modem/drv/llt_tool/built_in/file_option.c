#include <bsp_print.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <securec.h>
#include "return_code.h"
#include <bsp_file_ops.h>
#include "file_option.h"

#define MAX_READ_BUFFER_SIZE 4096
#define MAX_DIR_BUFFER_SIZE 4096
#define PATH_SIZE 512

int create_file(char* path)
{
    struct file* filp;

    if (!path) {
        bsp_err("path or info is Null\n");
        return -NULL_POINTER;
    }

    filp = filp_open(path, O_CREAT | O_RDONLY, 0644);
    if (IS_ERR(filp)) {
        bsp_err("fail to create/open file %s: %d\n", path, PTR_ERR(filp));
        return -CREATE_FILE_FAIL;
    }

    filp_close(filp, NULL);
    return ACORE_SUCCESS;
}

int write_to_file(char* path, unsigned char* info, unsigned int size, unsigned long long offset)
{
    struct file* filp;
    ssize_t ret = 0;

    if (!path || !info) {
        bsp_err("path or info is Null\n");
        return -NULL_POINTER;
    }

    filp = filp_open(path, O_CREAT | O_WRONLY, 0644);
    if (IS_ERR(filp)) {
        bsp_err("fail to create/open file %s: %d\n", path, PTR_ERR(filp));
        return -CREATE_FILE_FAIL;
        }
    ret = kernel_write(filp, info, size, (loff_t *)&offset);

    if (ret < 0) {
        bsp_err("fail to write file %s: %d\n", path, PTR_ERR(filp));
    }
    filp_close(filp, NULL);
    return ret;
}

int read_from_file(char* path, unsigned char* info, unsigned int size, unsigned long long offset)
{
    struct file* filp;
    ssize_t ret;

    if (!path || !info) {
        bsp_err("path or info is Null\n");
        return -NULL_POINTER;
    }

    if (size > MAX_READ_BUFFER_SIZE) {
        bsp_err("read size is too big\n");
        return -FILE_READ_TOO_LONG;
    }

    filp = filp_open(path, O_RDONLY, 0644);
    if (IS_ERR(filp)) {
        bsp_err("fail to open file %s: %d\n", path, PTR_ERR(filp));
        return -FILE_NOT_EXIST;
    }

    ret = kernel_read(filp, info, size, (loff_t *)&offset);
    if (ret < 0) {
        bsp_err("fail read from file %s: %d\n", path, PTR_ERR(filp));
    }

    filp_close(filp, NULL);
    return ret;
}

int open_directory(char* dir)
{
    struct file* filp;

    if (!dir) {
        bsp_err("dir or info is Null\n");
        return -NULL_POINTER;
    }

    filp = filp_open(dir, O_DIRECTORY | O_RDONLY, 0644);
    if (IS_ERR(filp)) {
        bsp_err("fail to open dir %s: %d\n", dir, PTR_ERR(filp));
        return -FILE_NOT_EXIST;
    }
    filp_close(filp, NULL);
    return ACORE_SUCCESS;
}

int create_directory(char* dir)
{
    char *temp = NULL;
    int ret, len;

    if (dir == NULL || strlen(dir) >= PATH_SIZE) {
        bsp_err("illegal dir for mkdir, len=%d, dir:%s\n", strlen(dir), dir);
        return -NULL_POINTER;
    }
    ret = bsp_eaccess(dir);
    if (ret == 0) {
        bsp_err("path already exist, not need mkdir again\n");
        return ACORE_SUCCESS;
    }

    for (temp = (dir) + 1; *temp ; temp++) {
        if (*temp == '/') {
            *temp = '\0';
            ret = bsp_eaccess(dir);
            if (ret == 0) {
                *temp = '/';
                continue;
            }
            ret = bsp_file_mkdir(dir, 0755);
            if (ret != 0) {
                bsp_err("failed mkdir, return:%d, path:%s\n", ret, dir);
                return -CREATE_FILE_FAIL;
            }
            bsp_err("finish mkdir:%s\n", dir);
            *temp = '/';
        }
    }

    len = strlen(dir);
    if ( dir[len -1] != '/') {
        ret = bsp_file_mkdir(dir, 0755);
        if (ret != 0) {
            bsp_err("failed make last dir, return:%d, path:%s\n", ret, dir);
            return -CREATE_FILE_FAIL;
        }
    }

    bsp_err("success mkdir:%s\n", dir);
    return ACORE_SUCCESS;
}