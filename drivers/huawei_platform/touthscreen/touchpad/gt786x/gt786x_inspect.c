/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include <linux/math64.h>
#include <linux/firmware.h>
#include <linux/fs.h>
#include "hm_os_sys.h"
#include "goodix_ts_log.h"
#include "goodix_ts_core.h"
#include "goodix_ts_utils.h"
#include "gt786x_inspect.h"

static u8 gt7861_drv_map[] = {45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28,
                              255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
static u8 gt7861_sen_map[] = {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 11, 12, 13, 14, 15, 17,
                              18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
struct gtx8_ts_test g_ts_test;

struct short_record {
    u32 master;
    u32 slave;
    u16 short_code;
    u8 group1;
    u8 group2;
};

static void gtx8_check_setting_group(struct gtx8_ts_test *ts_test, struct short_record *r_data);

#if SAVE_IN_CSV
void gtx8_save_test_result(struct gtx8_ts_test *ts_test);
#endif
/**
 * print_matrix - Prints a matrix of integers in a formatted manner.
 *
 * @row: The number of rows in the matrix.
 * @col: The number of columns in the matrix.
 * @data: Pointer to the matrix data stored as a 1D array of unsigned 16-bit integers (u16).
 *
 * This function iterates through the matrix data and formats each row into a string buffer.
 * Each element in the row is separated by a comma and aligned to a width of 5 characters.
 * The formatted row is then logged using the ts_info function.
 * An additional newline is logged after printing all rows.
 *
 * Note:
 * - The size of the buffer (buff) is defined by PRINT_MSG_MAX_LEN.
 * - Ensure that the buffer size is sufficient to hold the formatted row data.
 */

void print_matrix(int row, int col, u16* data)
{
    int i, j;
    char buff[PRINT_MSG_MAX_LEN] = {0};

    for (i = 0; i < row; i++) {
        int position = 0;
        for (j = 0; j < col; j++) {
            position += snprintf_s(buff + position, sizeof(buff) - position, sizeof(buff) - position,
                                   "%5d,", data[i * col + j]);
        }
        ts_info("%s\n", buff);
    }
    ts_info("\n");
}

/***********************************************************************
* Function Name  : gtx8_get_cfg_value
* Description    : read config data specified by sub-bag number and inside-bag offset.
* config	 : pointer to config data
* buf		 : output buffer
* len		 : data length want to read, if len = 0, get full bag data
* sub_bag_num    : sub-bag number
* offset         : offset inside sub-bag
* Return         : int(return offset with config[0], < 0 failed)
*******************************************************************************/
static int gtx8_get_cfg_value(struct gtx8_ts_test *ts_test, u8 *config, u8 *buf, u8 len, u8 sub_bag_num, u8 offset)
{
    u8 *sub_bag_ptr = NULL;
    u8 i = 0;

    sub_bag_ptr = &config[TS_CFG_HEADER_SIZE];
    for (i = 0; i < config[GOODIX_CFG_BAG_HEADER_SIZE]; i++) {
        if (sub_bag_ptr[0] == sub_bag_num) {
            break;
        }
        sub_bag_ptr += GOODIX_CFG_BAG_SIZE(sub_bag_ptr[1]);
    }

    if (i >= config[GOODIX_CFG_BAG_HEADER_SIZE]) {
        ts_err("Cann't find the specifiled bag num %d\n", sub_bag_num);
        return -EINVAL;
    }

    if (GOODIX_CFG_BAG_SIZE(sub_bag_ptr[1]) < offset + len) {
        ts_err("Sub bag len less then you want to read: %d < %d\n", GOODIX_CFG_BAG_SIZE(sub_bag_ptr[1]), offset + len);
        return -EINVAL;
    }

    if (len) {
        memcpy_s(buf, len, sub_bag_ptr + offset, len);
    } else {
        memcpy_s(buf, len, sub_bag_ptr, GOODIX_CFG_BAG_SIZE(sub_bag_ptr[1]));
    }
    return (sub_bag_ptr + offset - config);
}

/*
 * parse driver and sensor num only on screen
 */
#define CFG_DATA_DRV_NUM_SIZE       2
#define CFG_DATA_DRV_NUM_BAG_INDEX  1
#define CFG_DATA_DRV_NUM_BAG_OFFSET 14

#define CFG_DATA_SEN_NUM_SIZE       1
#define CFG_DATA_SEN_NUM_BAG_INDEX  1
#define CFG_DATA_SEN_NUM_BAG_OFFSET 10
/**
 * gtx8_get_channel_num - Get the number of sensor and driver channels.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure.
 * @sen_num: Pointer to store the number of sensor channels.
 * @drv_num: Pointer to store the number of driver channels.
 * @cfg_data: Pointer to the configuration data.
 *
 * This function retrieves the number of sensor and driver channels from the
 * configuration data. It reads the respective values from the configuration
 * using the gtx8_get_cfg_value function and validates the retrieved values.
 *
 * Return: 0 on success, -EINVAL on failure.
 */
int gtx8_get_channel_num(struct gtx8_ts_test *ts_test, u32 *sen_num, u32 *drv_num, u8 *cfg_data)
{
    int ret = 0;
    u8 buf[3] = {0};
    u8 *temp_cfg_data = cfg_data;

    if (!sen_num || !drv_num || !temp_cfg_data) {
        ts_err("%s: invalid param\n", __func__);
        return -EINVAL;
    }

    /* Read the driver number from the configuration data */
    ret = gtx8_get_cfg_value(ts_test, temp_cfg_data, buf, CFG_DATA_DRV_NUM_SIZE,
                             CFG_DATA_DRV_NUM_BAG_INDEX, CFG_DATA_DRV_NUM_BAG_OFFSET);
    if (ret > 0) {
        *drv_num = buf[0] + buf[1];
    } else {
        ts_err("Failed read drv_num reg\n");
        return -EINVAL;
    }

    /* Read the sensor number from the configuration data */
    ret = gtx8_get_cfg_value(ts_test, temp_cfg_data, buf, CFG_DATA_SEN_NUM_SIZE,
                             CFG_DATA_SEN_NUM_BAG_INDEX, CFG_DATA_SEN_NUM_BAG_OFFSET);
    if (ret > 0) {
        *sen_num = buf[0];
    } else {
        ts_err("Failed read sen_num reg\n");
        return -EINVAL;
    }

    ts_info("drv_num:%d,sen_num:%d\n", *drv_num, *sen_num);

    /* Validate the retrieved driver and sensor numbers */
    if (*drv_num > MAX_DRV_NUM || *drv_num <= 0
        || *sen_num > MAX_SEN_NUM || *sen_num <= 0) {
        ts_err("invalid sensor or driver num\n");
        return -EINVAL;
    }

    return 0;
}

/*******************************************************************************
* Function Name  : cfg_update_chksum
* Description    : update check sum
* Input          : u32 *config
* Input          : u16 cfg_len
* Output         : u8 *config
* Return         : none
*******************************************************************************/
#define GTX8_CFG_BAG_MAX_SIZE   255
static void cfg_update_chksum(struct gtx8_ts_test *ts_test, u8 *config, u16 cfg_len)
{
    u16 pack_map_len_arr[GTX8_CFG_BAG_MAX_SIZE];
    u16 pack_len_tmp = 0, pack_id_tmp = 0, cur_pos = 0, check_sum_u16 = 0;
    u16 i = 0, j = 0;
    u8 check_sum = 0, chksum_len = GOODIX_CFG_BAG_CHECKSUM_SIZE;

    if (cfg_len < TS_CFG_HEADER_SIZE) {
        return;
    }
    /* Head:4 bytes    |byte0:version|byte1:config refresh|byte2:package total num|byte3:check sum| */
    pack_map_len_arr[pack_id_tmp] = TS_CFG_HEADER_SIZE;
    for (i = TS_CFG_HEADER_SIZE; i < cfg_len;) {
        pack_id_tmp++;
        pack_len_tmp = GOODIX_CFG_BAG_SIZE(config[i + 1]);
        pack_map_len_arr[pack_id_tmp] = pack_len_tmp;
        i += pack_len_tmp;
    }

    cur_pos = 0;
    for (i = 0; i <= pack_id_tmp; i++) {
        check_sum = 0;
        check_sum_u16 = 0;
        for (j = cur_pos; j < cur_pos + pack_map_len_arr[i] - chksum_len; j++) {
            check_sum += config[j];
            check_sum_u16 += config[j];
        }
        if (chksum_len == sizeof(u8)) {
            config[cur_pos + pack_map_len_arr[i] - chksum_len] = (u8)(0 - check_sum);
        } else if (chksum_len == sizeof(u16)) {
            config[cur_pos + pack_map_len_arr[i] - chksum_len] = GOODIX_VAL_H(check_sum_u16);
            config[cur_pos + pack_map_len_arr[i] - chksum_len + 1] = GOODIX_VAL_L(check_sum_u16);
        }
        cur_pos += pack_map_len_arr[i];
    }
}

/* @flash_cfg: config data read from IC.
 * @file_cfg: config data from file.
 */
static int gtx8_config_compare(struct goodix_ts_config *flash_cfg, struct goodix_ts_config *file_cfg)
{
    if (flash_cfg->length != file_cfg->length) {
        ts_info("config compare failed: config length unequal %d!=%d",
            flash_cfg->length, file_cfg->length);
        return RESULT_ERR;
    }
    if (checksum_u8(flash_cfg->data, GTX8_CONFIG_HEAD_LEN)) {
        ts_info("config compare failed: config header checksum error");
        return RESULT_ERR;
    }
    if (flash_cfg->data[0] != file_cfg->data[0]) {
        ts_info("config compare failed: config version unequal");
        return RESULT_ERR;
    }

    if (memcmp(flash_cfg->data + GTX8_CONFIG_HEAD_LEN,
               file_cfg->data + GTX8_CONFIG_HEAD_LEN,
               flash_cfg->length - GTX8_CONFIG_HEAD_LEN)) {
        ts_info("config compare failed: config data unequal");
        return RESULT_ERR;
    }
    return 0;
}

#define GTX8_SET_RAM_CONFIG_FLAG  (0x01 << 1)
static int init_test_config(struct gtx8_ts_test *ts_test)
{
    int ret = 0;
    struct goodix_ts_config *test_config = &(ts_test->test_config);

    test_config->data[1] |= GTX8_SET_RAM_CONFIG_FLAG; // ram config

    cfg_update_chksum(ts_test, test_config->data, test_config->length);
    test_config->initialized = VALUE_TRUE;
    strcpy_s(test_config->name, sizeof(test_config->name), "test_config");
    return ret;
}

static void goto_next_line(char **ptr)
{
    do {
        *ptr = *ptr + 1;
    } while (**ptr != '\n' && **ptr != '\0');
    if (**ptr == '\0') {
        return;
    }
    *ptr = *ptr + 1;
}

static void copy_this_line(char *dest, char *src)
{
    char *copy_from, *copy_to;

    copy_from = src;
    copy_to = dest;
    do {
        *copy_to = *copy_from;
        copy_from++;
        copy_to++;
    } while ((*copy_from != '\n') && (*copy_from != '\r') && (*copy_from != '\0'));
    *copy_to = '\0';
}

/**
 * getrid_space - Removes spaces, carriage returns, and newlines from input data.
 * @data: Pointer to the input data buffer. The cleaned data will be written back to this buffer.
 * @len: Length of the input data buffer.
 *
 * This function processes the input buffer `data` and removes all occurrences of
 * spaces (' '), carriage returns ('\r'), and newlines ('\n'). The cleaned data
 * is written back to the original buffer, and the function returns the length
 * of the cleaned data.
 *
 * Memory is dynamically allocated to temporarily store the cleaned data. If
 * memory allocation fails, the function logs an error and returns -ESRCH.
 *
 * Return: The length of the cleaned data on success, or -ESRCH if memory
 * allocation fails.
 */
static int getrid_space(s8* data, s32 len)
{
    u8* buf = NULL;
    s32 i, count = 0;

    buf = (char*)kzalloc(len + 1, GFP_KERNEL);
    if (buf == NULL) {
        ts_err("get space kzalloc error");
        return -ESRCH;
    }

    for (i = 0; i < len; i++) {
        if (data[i] == ' ' || data[i] == '\r' || data[i] == '\n') {
            continue;
        }
        buf[count++] = data[i];
    }

    buf[count++] = '\0';

    memcpy_s(data, len + 1, buf, count);
    kfree(buf);

    return count;
}

/**
 * parse_valid_data - Parses valid data from a buffer and stores it in a matrix.
 * @buf_start: Pointer to the start of the buffer containing the data to parse.
 * @buf_size: Size of the buffer in bytes.
 * @ptr: Pointer to the current position in the buffer.
 * @data: Pointer to the output matrix where parsed data will be stored.
 * @rows: Number of rows in the output matrix.
 * @cols: Number of columns in the output matrix.
 *
 * This function processes the data in the buffer starting from @buf_start
 * and extracts valid data into a matrix of dimensions @rows x @cols. The
 * parsed data is stored in the memory pointed to by @data. The function
 * ensures that the parsing does not exceed the buffer size specified by
 * @buf_size.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int parse_valid_data(char *buf_start, loff_t buf_size,
    char *ptr, u16 *data, u32 rows, u32 cols)
{
    int i = 0, j = 0;
    char *token = NULL, *tok_ptr = NULL, *row_data = NULL;
    long temp_val;

    if (!ptr || !data) {
        ts_err("invalid param");
        return -EINVAL;
    }

    if (!(row_data = (char *)kzalloc(MAX_LINE_LEN, GFP_KERNEL))) {
        return -ENOMEM;
    }

    for (i = 0; i < rows; i++) {
        memset_s(row_data, MAX_LINE_LEN, 0, MAX_LINE_LEN);
        copy_this_line(row_data, ptr);
        getrid_space(row_data, strlen(row_data));
        tok_ptr = row_data;
        while ((token = strsep(&tok_ptr, ","))) {
            if (strlen(token) == 0) {
                continue;
            }
            if (kstrtol(token, 0, &temp_val)) {
                kfree(row_data);
                return -EINVAL;
            }
            if (temp_val >= MAX_U16_VALUE) {
                ts_err("csv value exceed limit: %ld > %d", temp_val, MAX_U16_VALUE);
                kfree(row_data);
                return -EINVAL;
            }
            if (j >= (rows * cols)) {
                ts_err("csv line exceed limits %d > %d", j, cols);
                kfree(row_data);
                return -EINVAL;
            }
            data[j++] = (u16)temp_val;
        }
        if (i == rows - 1) {
            break;
        }
        goto_next_line(&ptr);   // next row
        if (!ptr || (0 == strlen(ptr)) || (ptr >= (buf_start + buf_size))) {
            ts_info("invalid ptr, return");
            kfree(row_data);
            return -EPERM;
        }
    }
    kfree(row_data);
    return 0;
}

/**
 * parse_csvfile - Parses a CSV file buffer to extract specific data.
 *
 * @buf: Pointer to the buffer containing the CSV file content.
 * @size: Size of the buffer in bytes.
 * @target_name: Name of the target item to locate in the CSV file.
 * @data: Pointer to the output buffer where parsed data will be stored.
 * @rows: Number of rows expected in the parsed data.
 * @cols: Number of columns expected in the parsed data.
 *
 * This function searches for a specific target item in the provided CSV file
 * buffer and extracts its associated data into the provided output buffer.
 * It performs the following steps:
 * 1. Searches for the target name in the buffer.
 * 2. Moves to the next line after the target name.
 * 3. Validates and parses the data if the target is found.
 *
 * Return:
 *  - 0 on success.
 *  - -EINTR if the target name is not found or data is NULL.
 *  - -EIO if the line after the target name is empty.
 *  - -ENXIO if the buffer size is invalid.
 */
static int parse_csvfile(char *buf, size_t size, char *target_name, u16 *data, u32 rows, u32 cols)
{
    int ret = 0;
    char *ptr = NULL;
    int read_ret;

    read_ret = size;
    if (read_ret > 0) {
        ptr = buf;
        ptr = strstr(ptr, target_name);
        if (!ptr) {
            ts_info("load %s failed 1, maybe not this item", target_name);
            return -EINTR;
        }

        goto_next_line(&ptr);
        if (!ptr || (strlen(ptr) == 0)) {
            ts_err("load %s failed 2!", target_name);
            return -EIO;
        }
        
        if (data) {
            ret = parse_valid_data(buf, size, ptr, data, rows, cols);
        } else {
            ts_err("load %s failed 3!", target_name);
            return -EINTR;
        }
    } else {
        ts_err("ret=%d, read_ret=%d", ret, read_ret);
        ret = -ENXIO;
    }

    return ret;
}

/**
 * gtx8_get_inspect_cfg - Load and initialize inspection configurations
 * @ts_test: Pointer to the test structure containing configuration data
 *
 * This function retrieves the normal and test configuration files for the
 * touchscreen inspection process. It loads the firmware data into the
 * corresponding configuration structures and initializes the test configuration.
 *
 * Return: 0 on success, -EINVAL if any configuration file fails to load.
 */

static int gtx8_get_inspect_cfg(struct gtx8_ts_test *ts_test)
{
    struct goodix_ts_config *ts_config = NULL;
    const struct firmware *firmware;

    /* get normal config file */
    firmware = goodix_request_firmware(NORMAL_CONFIG_FILE_NAME);
    if (!firmware) {
        ts_err("failed get normal config: %s", NORMAL_CONFIG_FILE_NAME);
        return -EINVAL;
    }

    ts_config = &ts_test->normal_config;
    ts_config->length = firmware->size;
    memcpy_s(ts_config->data, GOODIX_CFG_MAX_SIZE, firmware->data, ts_config->length);
    release_firmware(firmware);

    /* get test config file */
    firmware = goodix_request_firmware(TEST_CONFIG_FILE_NAME);
    if (!firmware) {
        ts_err("failed get test config: %s", TEST_CONFIG_FILE_NAME);
        return -EINVAL;
    }

    ts_config = &ts_test->test_config;
    ts_config->length = firmware->size;
    memcpy_s(ts_config->data, GOODIX_CFG_MAX_SIZE, firmware->data, ts_config->length);
    init_test_config(ts_test);
    release_firmware(firmware);
    return 0;
}

/* get a copy of test limit file */
static char *gtx8_get_limit_file_copy(const char *name, int *fw_size)
{
    const struct firmware *firmware;
    char *temp_buf = NULL;

    /* get test limit file */
    firmware = goodix_request_firmware(name);
    if (!firmware) {
        ts_err("failed get test limits: %s", name);
        return NULL;
    }
    if (firmware->size <= 0) {
        ts_err("invalid firmware size %d", firmware->size);
        goto err_firmware;
    }

    temp_buf = kzalloc(firmware->size + 1, GFP_KERNEL);
    if (!temp_buf) {
        ts_err("kzalloc failed.");
        goto err_firmware;
    }
    memcpy_s(temp_buf, firmware->size + 1, firmware->data, firmware->size);
    *fw_size = firmware->size;
    release_firmware(firmware);
    ts_info("get test limits %s, size %d", name, *fw_size);
    return temp_buf;

err_firmware:
    release_firmware(firmware);
    return NULL;
}

static int gtx8_parse_rawdata_limits(struct ts_test_params *test_params, char *fw_data, int fw_size)
{
    int ret;
    u32 rows, cols;

    rows = test_params->drv_num; // Row
    cols = test_params->sen_num; // Col

    /* obtain mutual_raw min */
    ret = parse_csvfile(fw_data, fw_size, CSV_TP_SPECIAL_RAW_MIN,
        test_params->min_limits, rows, cols);
    if (ret < 0) {
        ts_err("Failed get min_limits");
        return -EINVAL;
    }
    ts_info("parse_csvfile %s OK", CSV_TP_SPECIAL_RAW_MIN);

    /* obtain mutual_raw max */
    ret = parse_csvfile(fw_data, fw_size, CSV_TP_SPECIAL_RAW_MAX,
        test_params->max_limits, rows, cols);
    if (ret < 0) {
        ts_err("Failed get max_limits");
        return -EINVAL;
    }
    ts_info("parse_csvfile %s OK", CSV_TP_SPECIAL_RAW_MAX);

    /* obtain delta limit */
    ret = parse_csvfile(fw_data, fw_size, CSV_TP_SPECIAL_RAW_DELTA,
                        test_params->deviation_limits, rows, cols);
    if (ret < 0) {
        ts_err("Failed get delta limit");
        return -EINVAL;
    }
    ts_info("parse_csvfile %s OK", CSV_TP_SPECIAL_RAW_DELTA);
    return 0;
}

#define FW_VERSION_LIMIT_LINES        1
#define SHOT_THRESHOLD_LIMT_LINES     1
#define SHOT_THRESHOLD_NODE_NUMS      7
static int gtx8_init_testlimits(struct gtx8_ts_test *ts_test)
{
    struct ts_test_params *test_params = &ts_test->test_params;
    u16 data_buf[10] = {0};
    char *temp_buf = NULL;
    int fw_size = 0, ret, i;

    if (gtx8_get_inspect_cfg(ts_test)) {
        return -EINVAL;
    }

    temp_buf = gtx8_get_limit_file_copy(TEST_LIMITS_FILE_NAME, &fw_size);
    if (!temp_buf) {
        return -EINVAL;
    }
    
    if ((ret = gtx8_parse_rawdata_limits(test_params, temp_buf, fw_size)) != 0) {
        goto exit_free;
    }

    /* obtain fw version */
    ret = parse_csvfile(temp_buf, fw_size, CSV_TP_TARGET_FW_VERSION,
                        data_buf, FW_VERSION_LIMIT_LINES, FW_VERSION_SIZE);
    if (ret < 0) {
        ts_err("Failed get fw version limit");
        goto exit_free;
    }
    ts_info("parse_csvfile %s OK", CSV_TP_TARGET_FW_VERSION);

    for (i = 0; i < FW_VERSION_SIZE; i++) {
        test_params->fw_vid[i] = (u8)data_buf[i];
    }
     /* obtain short_params */
    ret = parse_csvfile(temp_buf, fw_size, CSV_TP_SHORT_THRESHOLD,
                        data_buf, SHOT_THRESHOLD_LIMT_LINES, SHOT_THRESHOLD_NODE_NUMS);
    if (ret < 0) {
        ts_info("Can't find short shortciurt_threshold, skip this item");
        goto exit_free;
    } else {
        ts_info("parse_csvfile %s OK", CSV_TP_SHORT_THRESHOLD);
        test_params->short_threshold = data_buf[0];
        test_params->r_drv_drv_threshold = data_buf[1];
        test_params->r_drv_sen_threshold = data_buf[INDEX_2];
        test_params->r_sen_sen_threshold = data_buf[INDEX_3];
        test_params->r_drv_gnd_threshold = data_buf[INDEX_4];
        test_params->r_sen_gnd_threshold = data_buf[INDEX_5];
        test_params->avdd_value = data_buf[INDEX_6];
    }

exit_free:
    if (temp_buf) {
        kfree(temp_buf);
    }
    return ret;
}

static int gtx8_init_params(struct gtx8_ts_test *ts_test)
{
    struct ts_test_params *test_params = &ts_test->test_params;

    test_params->rawdata_addr = GTP_RAWDATA_ADDR_7861;
    test_params->max_drv_num = MAX_DRV_NUM_7861;
    test_params->max_sen_num = MAX_SEN_NUM_7861;
    test_params->drv_map = gt7861_drv_map;
    test_params->sen_map = gt7861_sen_map;

    return 0;
}

/* init cmd data */
static int gtx8_init_cmds(struct gtx8_ts_test *ts_test)
{
    int ret = 0;

    /* init rawdata cmd */
    goodix_cmd_init(&ts_test->rawdata_cmd, GTX8_CMD_RAWDATA, 0, GT786X_CMD_REG);
    goodix_cmd_init(&ts_test->normal_cmd, GTX8_CMD_NORMAL, 0, GT786X_CMD_REG);

    return ret;
}

/* gtx8_read_origconfig
 *
 * read original config data
 */
static int gtx8_cache_origconfig(struct gtx8_ts_test *ts_test)
{
    int ret = -ENODEV;

    ret = gt786x_hw_ops.read_config(&ts_test->orig_config.data[0], GOODIX_CFG_MAX_SIZE);
    if (ret < 0) {
        ts_err("Failed to read original config data\n");
        return ret;
    }

    ts_test->orig_config.length = ret;
    strcpy_s(ts_test->orig_config.name, sizeof(ts_test->orig_config.name), "original_config");
    ts_test->orig_config.initialized = VALUE_TRUE;

    return NO_ERR;
}

/* gtx8_tptest_prepare
 *
 * preparation before tp test
 */
static int gtx8_tptest_prepare(struct gtx8_ts_test *ts_test)
{
    int ret = 0;

    ts_info("TP test preparation\n");
    ret = gtx8_cache_origconfig(ts_test);
    if (ret) {
        ts_err("Failed cache origin config\n");
        return ret;
    }

    /* init cmd */
    ret = gtx8_init_cmds(ts_test);
    if (ret) {
        ts_err("Failed init cmd\n");
        return ret;
    }

    /* init reg addr and short cal map */
    ret = gtx8_init_params(ts_test);
    if (ret) {
        ts_err("Failed init register address\n");
        return ret;
    }

    /* get sensor and driver num currently in use */
    ret = gtx8_get_channel_num(ts_test, &ts_test->test_params.sen_num,
                    &ts_test->test_params.drv_num, ts_test->orig_config.data);
    if (ret) {
        ts_err("Failed get channel num:%d\n", ret);
        ts_test->test_params.sen_num = MAX_DRV_NUM;
        ts_test->test_params.drv_num = MAX_SEN_NUM;
        return ret;
    }

    /* parse test limits from csv */
    ret = gtx8_init_testlimits(ts_test);
    if (ret) {
        ts_err("Failed to init testlimits from csv:%d\n", ret);
        return ret;
    }

    return ret;
}

static int gtx8_check_and_resend_config(struct gtx8_ts_test *ts_test)
{
    int ret = -ENODEV;

    /* cache flash config */
    memset_s(ts_test->orig_config.data, GOODIX_CFG_MAX_SIZE, 0, GOODIX_CFG_MAX_SIZE);
    ret = gt786x_hw_ops.read_config(&ts_test->orig_config.data[0], GOODIX_CFG_MAX_SIZE);
    if (ret < 0) {
        ts_err("Failed to read original config data\n");
        return ret;
    }
    ts_test->orig_config.length = ret;

    if (!gtx8_config_compare(&ts_test->orig_config, &ts_test->normal_config)) {
        ts_info("Config check pass");
        return 0;
    }

    ts_info("Found unexpected config, try recover");
    ret = gt786x_hw_ops.send_config(&ts_test->normal_config);
    if (ret) {
        ts_err("Failed recover normal config:%d\n", ret);
    }
    return ret;
}

/* gtx8_tptest_finish
 *
 * finish test
 */
static int gtx8_tptest_finish(struct gtx8_ts_test *ts_test)
{
    int ret = RESULT_ERR;

    ts_info("TP test finish\n");
    ret = gt786x_hw_ops.reset();
    if (ret) {
        ts_err("%s: chip reset failed\n", __func__);
    }
    gtx8_check_and_resend_config(ts_test);
    return ret;
}

#define GOODIX_RETRY_20         20
#define GOODIX_DATA_POLL_DELAY  5
#define GOODIX_DATA_READY_MASK  0x80
/* poll data ready flag and read data */
static int gtx8_poll_read(struct gtx8_ts_test *ts_test, unsigned int addr, unsigned char *data, unsigned int len)
{
    const struct goodix_ts_hw_ops *hw_ops = &gt786x_hw_ops;
    int ret;
    int retry;
    unsigned char val;

    val = 0;
    hw_ops->write(GT786X_COOR_REG, &val, sizeof(val));

    retry = GOODIX_RETRY_20;
    while (retry--) {
        sys_delay_ms(GOODIX_DATA_POLL_DELAY);
        ret = hw_ops->read(GT786X_COOR_REG, &val, sizeof(val));
        if (ret < 0) {
            ts_err("read failed");
            return ret;
        }
        if (val & GOODIX_DATA_READY_MASK) {
            break;
        }
    }
    if (retry < 0) {
        ts_err("rawdata is not ready, status:%x", val);
        return -EINVAL;
    }

    return hw_ops->read(addr, data, len);
}

/**
 * gtx8_cache_rawdata - cache rawdata
 */
static int gtx8_cache_rawdata(struct gtx8_ts_test *ts_test)
{
    int i = 0, j = 0;
    int ret = -EINVAL;
    u32 rawdata_size = 0;
    u16 rawdata_addr = 0;

    ts_test->rawdata.size = 0;
    rawdata_size = ts_test->test_params.sen_num * ts_test->test_params.drv_num;

    if (rawdata_size > MAX_DRV_NUM * MAX_SEN_NUM || rawdata_size <= 0) {
        ts_err("Invalid rawdata size(%u)\n", rawdata_size);
        return ret;
    }

    rawdata_addr = ts_test->test_params.rawdata_addr;
    for (j = 0; j < GTX8_RETRY_NUM_3; j++) {
        /* read rawdata */
        ret = gtx8_poll_read(ts_test, rawdata_addr, (u8 *)&ts_test->rawdata.data[0],
                rawdata_size * sizeof(u16));
        if (ret < 0) {
            ts_err("Failed to read rawdata:%d\n", ret);
            continue;
        }

        for (i = 0; i < rawdata_size; i++) {
            ts_test->rawdata.data[i] = be16_to_cpu(ts_test->rawdata.data[i]);
        }
        ts_test->rawdata.size = rawdata_size;
        break;
    }
    if (j >= GTX8_RETRY_NUM_3) {
        ts_err("Failed to read rawdata\n");
        return -EINVAL;
    }

    return 0;
}

static int gtx8_captest_prepare(struct gtx8_ts_test *ts_test)
{
    int ret;

    ret = gt786x_hw_ops.send_config(&ts_test->test_config);
    if (ret) {
        ts_err("Failed to send test config:%d\n", ret);
    } else {
        ts_info("Success send test config\n");
    }
    return ret;
}

static void gtx8_rawcapacitance_test_spec(struct gtx8_ts_test *ts_test, u8 *p_beyond_max_cnt, u8 *p_beyond_min_cnt)
{
    int i = 0;
    struct ts_test_params *test_params;
    struct ts_test_rawdata *rawdata;
    test_params = &ts_test->test_params;
    rawdata = &ts_test->rawdata;
    for (i = 0; i < ts_test->rawdata.size; i++) {
        if (rawdata->data[i] > test_params->max_limits[i]) {
            p_beyond_max_cnt[i]++;
        }
        if (rawdata->data[i] < test_params->min_limits[i]) {
            p_beyond_min_cnt[i]++;
        }
    }
}

static int gtx8_accord_test_spec(struct gtx8_ts_test *ts_test, u8 *p_beyond_cnt, int frame_cnt)
{
    struct ts_test_params *test_params = &ts_test->test_params;
    struct ts_test_rawdata *rawdata = &ts_test->rawdata;
    int cols = test_params->drv_num;
    u32 sc_data_num = test_params->drv_num * test_params->sen_num;
    u32 max_val = 0, rawdata_val = 0, up = 0, down = 0, left = 0, right = 0;
    int i = 0, ret = 0;

    if (cols <= 0) {
        ts_err("%s: parmas invalid\n", __func__);
        return RESULT_ERR;
    }
    ts_test->accord_arr[frame_cnt].size = sc_data_num;

    for (i = 0; i < sc_data_num; i++) {
        rawdata_val = rawdata->data[i];
        max_val = 0;
        /* calculate deltacpacitance with above node */
        if (i - cols >= 0) {
            up = abs(rawdata_val - rawdata->data[i - cols]);
            max_val = up > max_val ? up : max_val;
        }

        /* calculate deltacpacitance with bellow node */
        if (i + cols < sc_data_num) {
            down = abs(rawdata_val - rawdata->data[i + cols]);
            max_val = down > max_val ? down : max_val;
        }

        /* calculate deltacpacitance with left node */
        if (i % cols) {
            left = abs(rawdata_val - rawdata->data[i - 1]);
            max_val = left > max_val ? left : max_val;
        }

        /* calculate deltacpacitance with right node */
        if ((i + 1) % cols) {
            right = abs(rawdata_val - rawdata->data[i + 1]);
            max_val = right > max_val ? right : max_val;
        }

        /* float to integer */
        if (rawdata_val) {
            max_val *= FLOAT_AMPLIFIER;
            max_val = (u32)DIV_S64(max_val, rawdata_val);
            if (max_val > test_params->deviation_limits[i]) {
                p_beyond_cnt[i]++;
            }

            /* bak accord */
            ts_test->accord_arr[frame_cnt].data[i] = max_val;
        } else {
            ts_err("Find rawdata=0 when calculate deltacapacitance:[%d][%d]\n",
                (u32)DIV_S64(i, cols), i % cols);
            ret = RESULT_ERR;
            ts_test->accord_arr[frame_cnt].data[i] = 0;
        }
    }
    return ret;
}


/**
 * gtx8_rawdata_result_analyze - Analyzes raw data results for the GTX8 touchscreen test.
 * @ts_test: Pointer to the touchscreen test structure.
 * @p_beyond_max_cnt: Pointer to store the count of values beyond the maximum threshold.
 * @p_beyond_min_cnt: Pointer to store the count of values beyond the minimum threshold.
 * @p_beyond_accord_cnt: Pointer to store the count of values within the acceptable range.
 * @frame_cnt: Number of frames to analyze.
 *
 * This function processes the raw data from the GTX8 touchscreen test and categorizes
 * the data into counts of values exceeding the maximum threshold, below the minimum
 * threshold, and within the acceptable range.
 *
 * Returns: Status of the analysis operation.
 */
#define HIGH_LIMIT_RATIO 9
#define LOW_LIMIT_RATIO  1
#define MAGNIFY_TIMES_10 10
static int gtx8_rawdata_result_analyze(struct gtx8_ts_test *ts_test, u8 *p_beyond_max_cnt,
    u8 *p_beyond_min_cnt, u8 *p_beyond_accord_cnt, u8 frame_cnt)
{
    int ret = 0, i = 0;
    int low_ratio = LOW_LIMIT_RATIO, high_ratio = HIGH_LIMIT_RATIO;
    struct ts_test_params *test_params = &ts_test->test_params;
    struct ts_test_rawdata *rawdata = &ts_test->rawdata;

    ts_test->test_result[GTP_CAP_TEST] = GTP_TEST_PASS;
    ts_test->test_result[GTP_DELTA_TEST] = GTP_TEST_PASS;
    for (i = 0; i < rawdata->size; i++) {
        /* analyze max test */
        if (p_beyond_max_cnt[i] * MAGNIFY_TIMES_10 / frame_cnt >= high_ratio) {
            ts_err("max_cnt:%d, rawdata[%d][%d]:%u > max_limit:%u, NG\n", p_beyond_max_cnt[i],
                (u32)DIV_S64(i, test_params->drv_num), i % test_params->drv_num,
                rawdata->data[i], test_params->max_limits[i]);
            ts_test->test_result[GTP_CAP_TEST] = GTP_PANEL_REASON;
        } else if (p_beyond_min_cnt[i] * MAGNIFY_TIMES_10 / frame_cnt > low_ratio) {
            ts_test->test_result[GTP_CAP_TEST] = GTP_PANEL_REASON;
            ret = -1;
        }
        /* analyze min test */
        if (p_beyond_min_cnt[i] * MAGNIFY_TIMES_10 / frame_cnt >= high_ratio) {
            ts_err("min_cnt:%d,rawdata[%d][%d]:%u < min_limit:%u, NG\n", p_beyond_min_cnt[i],
                (u32)DIV_S64(i, test_params->drv_num), i % test_params->drv_num,
                rawdata->data[i], test_params->min_limits[i]);
            ts_test->test_result[GTP_CAP_TEST] = GTP_PANEL_REASON;
        } else if (p_beyond_min_cnt[i] * MAGNIFY_TIMES_10 / frame_cnt > low_ratio) {
            ts_test->test_result[GTP_CAP_TEST] = GTP_PANEL_REASON;
            ret = -1;
        }
    }
    for (i = 0; i < test_params->drv_num * test_params->sen_num; i++) {
        /* analyze accord test */
        if (p_beyond_accord_cnt[i]*MAGNIFY_TIMES_10 >= high_ratio) {
            ts_err("beyond accord cnt:%d,rawdata[%d][%d]:%u, deviation_limit:%u, NG\n",
                p_beyond_accord_cnt[i],
                (u32)DIV_S64(i, test_params->drv_num), i % test_params->drv_num,
                rawdata->data[i], test_params->deviation_limits[i]);
            ts_test->test_result[GTP_DELTA_TEST] = GTP_PANEL_REASON;
        } else if (p_beyond_accord_cnt[i]*MAGNIFY_TIMES_10 > low_ratio) {
            ts_test->test_result[GTP_DELTA_TEST] = GTP_PANEL_REASON;
            ret = -1;
        }
    }
    return ret;
}

/**
 * gtx8_rawdata_test_spec - Perform raw data test on the GTX8 touchscreen.
 */
static int gtx8_rawdata_test_spec(struct gtx8_ts_test *ts_test)
{
    int ret = NO_ERR;
    u16 i = 0, data_len = 0;
    u8 *p_beyond_max_limit_cnt = ts_test->open_res.beyond_max_limit_cnt;
    u8 *p_beyond_min_limit_cnt = ts_test->open_res.beyond_min_limit_cnt;
    u8 *p_beyond_accord_limit_cnt = ts_test->open_res.beyond_accord_limit_cnt;

    data_len = MAX_DRV_NUM*MAX_SEN_NUM;
    /* init beyond buffer */
    memset_s(p_beyond_max_limit_cnt, data_len, 0, data_len);
    memset_s(p_beyond_min_limit_cnt, data_len, 0, data_len);
    memset_s(p_beyond_accord_limit_cnt, data_len, 0, data_len);

    ts_test->test_result[GTP_CAP_TEST] = SYS_SOFTWARE_REASON;
    ts_test->test_result[GTP_DELTA_TEST] = SYS_SOFTWARE_REASON;

    /* rawdata test */
    for (i = 0; i < TOTAL_FRAME_NUM; i++) {
        ret = gtx8_cache_rawdata(ts_test);
        if (ret < 0) {
            /* Failed read rawdata */
            ts_err("Read rawdata failed\n");
            return ret;
        }

        /* bak rawdata */
        memcpy_s(ts_test->rawdata_arr[i].data, ts_test->rawdata.size*sizeof(u16),
                 ts_test->rawdata.data, ts_test->rawdata.size*sizeof(u16));
        ts_test->rawdata_arr[i].size = ts_test->rawdata.size;

        gtx8_rawcapacitance_test_spec(ts_test, p_beyond_max_limit_cnt, p_beyond_min_limit_cnt);
        ret = gtx8_accord_test_spec(ts_test, p_beyond_accord_limit_cnt, i);
        if (ret) {
            ts_test->test_result[GTP_DELTA_TEST] = GTP_PANEL_REASON;
            ts_err("DeltaCap test failed\n");
        }
        if ((i+1) % TOTAL_FRAME_NUM == 0) {
            ret = gtx8_rawdata_result_analyze(ts_test, p_beyond_max_limit_cnt,
                p_beyond_min_limit_cnt, p_beyond_accord_limit_cnt, i+1);
            if (!ret) {
                return ret;
            }
        }
    }

    return RAWDATA_UNSTABLE;
}

/*
 * gtx8_capacitance_test - Perform capacitance test on the GTX8 touchscreen.
 */
static void gtx8_capacitance_test(struct gtx8_ts_test *ts_test)
{
    int round;
    int ret = 0;
    u8 buf[1];

    ret = gtx8_captest_prepare(ts_test);
    if (ret) {
        ts_err("Captest prepare failed\n");
        ts_test->test_result[GTP_CAP_TEST] = SYS_SOFTWARE_REASON;
        ts_test->test_result[GTP_DELTA_TEST] = SYS_SOFTWARE_REASON;
        return;
    }
    /* read rawdata and calculate result,  statistics fail times */

    sys_delay_ms(GOODIX_DELAY_50MS);
    ret = gt786x_hw_ops.send_cmd(&ts_test->rawdata_cmd);
    if (ret) {
        ts_err("%s:Failed send rawdata cmd:ret%d\n", __func__, ret);
        goto capac_test_exit;
    } else {
        ts_info("%s: Success change to rawdata mode\n", __func__);
    }
    sys_delay_ms(GOODIX_DELAY_50MS);

    round = MAX_FRAME_TEST_ROUND;
    while (round--) {
        if (gtx8_rawdata_test_spec(ts_test) == RAWDATA_UNSTABLE) {
            continue;
        }
        break;
    }

capac_test_exit:
    gt786x_hw_ops.send_cmd(&ts_test->normal_cmd);
    buf[0] = 0x00;
    gt786x_hw_ops.write(GT786X_COOR_REG, buf, sizeof(buf));
    return;
}

char *gtx8_str_n_cat(char *dest, char *src, size_t dest_size)
{
    size_t dest_len = 0;

    dest_len = strnlen(dest, dest_size);
    return strncat_s(&dest[dest_len], dest_size - dest_len, src, dest_size - dest_len - 1);
}

char *gtx8_strncatint(char *dest, int src, char *format, size_t dest_size)
{
    char src_str[MAX_STR_LEN] = {0};
    int count;

    count = snprintf_s(src_str, MAX_STR_LEN, MAX_STR_LEN, format, src);
    if (count == -1) {
        ts_err("src_str snprintf_s fail");
    }
    return gtx8_str_n_cat(dest, src_str, dest_size);
}

static void gtx8_print_test_data(struct gtx8_ts_test *ts_test)
{
    int i;

    ts_info("============fw version test item: %d============\n", ts_test->test_result[GTP_VERSION_TEST]);
    ts_info("file version::");
    ts_info_array(ts_test->test_params.fw_vid, sizeof(ts_test->test_params.fw_vid));
    ts_info("running fw version:");
    ts_info_array(ts_test->fw_ver.vid, sizeof(ts_test->fw_ver.vid));
    ts_info("============version test item============\n");

    ts_info("============config test item: %d============\n", ts_test->test_result[GTP_CONFIG_TEST]);
    ts_info("file config data:%d\n", ts_test->normal_config.length);
    ts_info_array(ts_test->normal_config.data, ts_test->normal_config.length);

    ts_info("flash config data:%d\n", ts_test->orig_config.length);
    ts_info_array(ts_test->orig_config.data, ts_test->orig_config.length);
    ts_info("============config test item============\n");

    ts_info("============cap test item: %d============\n", ts_test->test_result[GTP_CAP_TEST]);
    ts_info("min cap limits:\n");
    print_matrix(ts_test->test_params.drv_num, ts_test->test_params.sen_num,
                 ts_test->test_params.min_limits);
    ts_info("max cap limits:\n");
    print_matrix(ts_test->test_params.drv_num, ts_test->test_params.sen_num,
                 ts_test->test_params.max_limits);
    for (i = 0; i < TOTAL_FRAME_NUM; i++) {
        ts_info("frame[%d] rawdata:\n", i);
        print_matrix(ts_test->test_params.drv_num, ts_test->test_params.sen_num,
                     ts_test->rawdata_arr[i].data);
    }
    ts_info("============cap test item============\n");

    ts_info("============delta test item: %d============\n", ts_test->test_result[GTP_DELTA_TEST]);
    ts_info("deviation limits:\n");
    print_matrix(ts_test->test_params.drv_num, ts_test->test_params.sen_num,
                 ts_test->test_params.deviation_limits);

    for (i = 0; i < TOTAL_FRAME_NUM; i++) {
        ts_info("frame[%d] accord data:\n", i);
        print_matrix(ts_test->test_params.drv_num, ts_test->test_params.sen_num, ts_test->accord_arr[i].data);
    }
    ts_info("============delta test item============\n");
}

static void gtx8_put_test_result(struct gtx8_ts_test *ts_test)
{
    int i = 0;
    int have_bus_error = 0;
    int have_panel_error = 0;

    gtx8_print_test_data(ts_test);
    /* check if there have bus error */
    for (i = 0; i < MAX_TEST_ITEMS; i++) {
        if (ts_test->test_result[i] == SYS_SOFTWARE_REASON) {
            have_bus_error = 1;
        } else if (ts_test->test_result[i] == GTP_PANEL_REASON) {
            have_panel_error = 1;
        }
    }
    ts_info("Have bus error:%d, have_panel_error:%d\n", have_bus_error, have_panel_error);
    if (have_bus_error || have_panel_error) {
        gtx8_str_n_cat(ts_test->test_info, "[FAIL]-", TS_RAWDATA_RESULT_MAX);
    } else {
        gtx8_str_n_cat(ts_test->test_info, "[PASS]-", TS_RAWDATA_RESULT_MAX);
    }
    if (have_bus_error) {
        gtx8_str_n_cat(ts_test->test_info, "0F-", TS_RAWDATA_RESULT_MAX);
    } else {
        gtx8_str_n_cat(ts_test->test_info, "0P-", TS_RAWDATA_RESULT_MAX);
    }
    for (i = 1; i < MAX_TEST_ITEMS; i++) {
        /* if have tested, show result */
        if (ts_test->test_result[i]) {
            if (ts_test->test_result[i] == GTP_TEST_PASS) {
                gtx8_strncatint(ts_test->test_info, i, "%dP-", TS_RAWDATA_RESULT_MAX);
            } else {
                gtx8_strncatint(ts_test->test_info, i, "%dF-", TS_RAWDATA_RESULT_MAX);
            }
        }
        ts_info("test_result_info [%d]%d\n", i, ts_test->test_result[i]);
    }

    gtx8_str_n_cat(ts_test->test_info, "-GT", TS_RAWDATA_RESULT_MAX);
    gtx8_str_n_cat(ts_test->test_info, ts_test->fw_ver.pid, TS_RAWDATA_RESULT_MAX);
    gtx8_str_n_cat(ts_test->test_info, "\n", TS_RAWDATA_RESULT_MAX);
    ts_info("ts_test->test_info:%s\n", ts_test->test_info);
}

#define GTX8_ENTER_SHOT_MODE_CMD    0x0B
#define GTX8_SHORT_FW_RUNNING_FLAG  0xAA
/**
 * gtx8_enter_short_test_mode - Enter short test mode for GTX8 touchscreen.
 *
 * This function switches the GTX8 touchscreen into short test mode by sending
 * the appropriate command and verifying that the firmware is running in the
 * correct mode. It retries the operation if necessary and resets the device
 * if the mode switch fails.
 *
 * Return: 0 on success, or a negative error code on failure.
 */

static const u8 SHORT_PID[] = { '0', '3', '_', 'O', 'S', 'T', 0, 0 };
static int _do_check_short_fw_status(void)
{
    u8 short_fw_ver[12] = {0};
    int i, ret;
    u8 status;

    /* check firmware running */
    for (i = 0; i < GOODIX_RETRY_20; i++) {
        ts_info("Check firmware running..");
        ret = gt786x_hw_ops.read(SHORT_STATUS_REG, &status, sizeof(status));   /* SHORT_STATUS_REG is 0x5095 */
        if (!ret && status == GTX8_SHORT_FW_RUNNING_FLAG) {
            if (!gt786x_hw_ops.read(SHORT_FW_VER_REG, short_fw_ver, sizeof(short_fw_ver)) &&
                !memcmp(short_fw_ver, SHORT_PID, sizeof(SHORT_PID))) {
                ts_info("Short firmware is running\n");
                return 0;
            }
            ts_info("Short fw pid unequal %*ph", sizeof(short_fw_ver), short_fw_ver);
        }
        ts_info("retry check ret %d, status 0x%x", ret, status);
        sys_delay_ms(GOODIX_DELAY_10MS);
    }
    return -EINVAL;
}

static int gtx8_enter_short_test_mode(void)
{
    int ret, retry = GTX8_RETRY_NUM_3;
    struct goodix_ts_cmd short_code_cmd;

    goodix_cmd_init(&short_code_cmd, GTX8_ENTER_SHOT_MODE_CMD, 0, GT786X_CMD_REG);

    ts_info("Short test prepare+\n");
    while (--retry) {
        /* switch to shrot test system */
        ret = gt786x_hw_ops.send_cmd(&short_code_cmd); /* bagan test command */
        if (ret) {
            ts_err("Can not switch to short test system\n");
            return ret;
        }
        sys_delay_ms(GOODIX_DELAY_50MS);

        if (!_do_check_short_fw_status()) {
            return 0;
        }

        ts_info("retry send enter short fw cmd");
        gt786x_hw_ops.reset();
    }

    ts_err("Failed enter short test mode");
    return -EINVAL;
}

#define GTX8_START_RUN_SHOT_TEST_FLAG   0x01

/**
 * gtx8_short_test_prepare - Prepares the short test for the GTX8 touchscreen.
 * @ts_test: Pointer to the GTX8 touchscreen test structure.
 *
 * This function sets up the necessary configurations and resources
 * required to perform a short test on the GTX8 touchscreen device.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_short_test_prepare(struct gtx8_ts_test *ts_test)
{
    int ret = 0;
    u8 data[MAX_DRV_NUM + MAX_SEN_NUM] = {0};

    if (gtx8_enter_short_test_mode()) {
        return -EINVAL;
    }

    ts_info("Firmware in short test mode\n");

    data[0] = GOODIX_VAL_H(ts_test->test_params.short_threshold);
    data[1] = GOODIX_VAL_L(ts_test->test_params.short_threshold);

    /* write tx/tx, tx/rx, rx/rx short threshold value */
    ret = gt786x_hw_ops.write(TXRX_THRESHOLD_REG, data, sizeof(u16));
    if (ret < 0) {
        ts_err("Failed write tx/tx, tx/rx, rx/rx short threshold value\n");
        return ret;
    }
    data[0] = GOODIX_VAL_H(GNDAVDD_SHORT_VALUE);
    data[1] = GOODIX_VAL_L(GNDAVDD_SHORT_VALUE);
    /* write default txrx/gndavdd short threshold value */
    ret = gt786x_hw_ops.write(GNDVDD_THRESHOLD_REG, data, sizeof(u16));  /* SHORT THRESHOLD_REG */
    if (ret < 0) {
        ts_err("Failed write txrx/gndavdd short threshold value\n");
        return ret;
    }

    /* Write ADC dump data num */
    data[0] = GOODIX_VAL_H(ADC_DUMP_NUM);
    data[1] = GOODIX_VAL_L(ADC_DUMP_NUM);
    ret = gt786x_hw_ops.write(ADC_DUMP_NUM_REG, data, sizeof(u16));
    if (ret < 0) {
        ts_err("Failed write ADC dump data number\n");
        return ret;
    }

    /* write 0x01 to 0x5095 start short test */
    data[0] = GTX8_START_RUN_SHOT_TEST_FLAG;
    ret = gt786x_hw_ops.write(SHORT_STATUS_REG, data, sizeof(u8)); /* SHORT_STATUS_REG 0X5095 */
    if (ret) {
        ts_err("Failed write running dsp reg\n");
        return ret;
    }

    ts_info("Short test prepare-\n");
    return 0;
}

#define GTX8_INVALID_CHN_NUM    255
static u32 map_die2pin(struct ts_test_params *test_params, u32 chn_num)
{
    int i = 0;
    u32 res = GTX8_INVALID_CHN_NUM;

    if (chn_num & DRV_CHANNEL_FLAG) {
        chn_num = (chn_num & ~DRV_CHANNEL_FLAG) + MAX_SEN_NUM;
    }
    for (i = 0; i < test_params->max_sen_num; i++) {
        if (test_params->sen_map[i] == chn_num) {
            res = i;
            break;
        }
    }

    /* res != 255 mean found the corresponding channel num */
    if (res != GTX8_INVALID_CHN_NUM) {
        return res;
    }

    /* if cannot find in SenMap try find in DrvMap */
    for (i = 0; i < test_params->max_drv_num; i++) {
        if (test_params->drv_map[i] == chn_num) {
            res = i;
            break;
        }
    }
    if (i >= test_params->max_drv_num) {
        ts_err("Faild found corrresponding channel num:%d\n", chn_num);
    } else {
        res |= DRV_CHANNEL_FLAG;
    }
    return res;
}

static void gtx8_save_short_res(struct gtx8_ts_test *ts_test, u16 chn1, u16 chn2, int r)
{
    int i = 0, offset = 0;
    u8 repeat_cnt = 0;
    u8 repeat = 0;
    struct ts_short_res *short_res = &ts_test->short_res;

    if (chn1 == chn2 || short_res->short_num >= MAX_SHORT_NUM) {
        return;
    }

    for (i = 0; i < short_res->short_num; i++) {
        repeat_cnt = 0;
        if (short_res->short_msg[SHORT_MSG_SIZE*i+0] == chn1) {
            repeat_cnt++;
        }
        if (short_res->short_msg[SHORT_MSG_SIZE*i+0] == chn2) {
            repeat_cnt++;
        }
        if (short_res->short_msg[SHORT_MSG_SIZE*i+1] == chn1) {
            repeat_cnt++;
        }
        if (short_res->short_msg[SHORT_MSG_SIZE*i+1] == chn2) {
            repeat_cnt++;
        }
        if (repeat_cnt > 1) {
            repeat = 1;
            break;
        }
    }
    if (repeat == 0) {
        short_res->short_msg[SHORT_MSG_SIZE*short_res->short_num + offset++] = chn1;
        short_res->short_msg[SHORT_MSG_SIZE*short_res->short_num + offset++] = chn2;
        short_res->short_msg[SHORT_MSG_SIZE*short_res->short_num + offset++] = GOODIX_VAL_H(r);
        short_res->short_msg[SHORT_MSG_SIZE*short_res->short_num + offset++] = GOODIX_VAL_L(r);
        if (short_res->short_num < MAX_SHORT_NUM) {
            short_res->short_num++;
        }
    }
}

#define GTX8_SHOT_TO_GND_FLAG 0x8000
static int gtx8_check_resistance_to_gnd(struct gtx8_ts_test *ts_test, u16 adc_signal, u32 pos)
{
    long r = 0;
    u16 r_th = 0, avdd_value = 0;
    u32 chn_id_tmp = 0;
    u32 pin_num = 0;
    struct ts_test_params *test_params = &ts_test->test_params;

    avdd_value = test_params->avdd_value;
    if (adc_signal == 0 || adc_signal == GTX8_SHOT_TO_GND_FLAG) {
        adc_signal |= 1;
    }

    if ((adc_signal & GTX8_SHOT_TO_GND_FLAG) == 0) {
        /* short to GND */
        r = SHORT_TO_GND_RESISTER(adc_signal);
    } else {
        /* short to VDD */
        r = SHORT_TO_VDD_RESISTER(adc_signal, avdd_value);
    }
    r = (long)DIV_S64(r, RESISTER_MAGNIFY_TIMES);
    r = r > MAX_U16_VALUE ? MAX_U16_VALUE : r;
    r = r < 0 ? 0 : r;

    if (pos < MAX_DRV_NUM) {
        r_th = test_params->r_drv_gnd_threshold;
    } else {
        r_th = test_params->r_sen_gnd_threshold;
    }
    chn_id_tmp = pos;
    if (chn_id_tmp < MAX_DRV_NUM) {
        chn_id_tmp |= DRV_CHANNEL_FLAG;
    } else {
        chn_id_tmp -= MAX_DRV_NUM;
    }
    if (r < r_th) {
        pin_num = map_die2pin(test_params, chn_id_tmp);
        gtx8_save_short_res(ts_test, pin_num,
                            (adc_signal & GTX8_SHOT_TO_GND_FLAG) ? CHN_VDD : CHN_GND, r);
        ts_err("%s%d shortcircut to %s,R=%ldK,R_Threshold=%dK\n",
               (pin_num & DRV_CHANNEL_FLAG) ? "DRV" : "SEN",
               (pin_num & ~DRV_CHANNEL_FLAG),
               (adc_signal & GTX8_SHOT_TO_GND_FLAG) ? "VDD" : "GND", r, r_th);

        return RESULT_ERR;
    }
    return NO_ERR;
}

#define GTX8_SHORT_RESISTANCE_CALC_ALPHA1  81
#define GTX8_SHORT_RESISTANCE_CALC_ALPHA2  64
static u32 gtx8_short_resistance_calc(struct gtx8_ts_test *ts_test,
                                      struct short_record *r_data, u16 self_capdata, u8 flag)
{
    u16 lineSenNum = 0;
    u8 DieNumber1 = 0, DieNumber2 = 0;
    int DieNumber1_max = 3;
    long r = 0;

    lineSenNum = MAX_SEN_NUM;

    if (flag == 0) {
        if (r_data->group1 != r_data->group2) {	    /* different Group */
            r = DIV_S64(self_capdata * GTX8_SHORT_RESISTANCE_CALC_ALPHA1 * FLOAT_AMPLIFIER, r_data->short_code);
            r -= (GTX8_SHORT_RESISTANCE_CALC_ALPHA1 * FLOAT_AMPLIFIER);
        } else {
            DieNumber1 = ((r_data->master & DRV_CHANNEL_FLAG) == DRV_CHANNEL_FLAG) ?
                (r_data->master + lineSenNum) : r_data->master;
            DieNumber2 = ((r_data->slave & DRV_CHANNEL_FLAG) == DRV_CHANNEL_FLAG) ?
                (r_data->slave + lineSenNum) : r_data->slave;
            DieNumber1 = (DieNumber1 >= DieNumber2) ?
                (DieNumber1 - DieNumber2) : (DieNumber2 - DieNumber1);
            if ((DieNumber1 > DieNumber1_max) && (r_data->group1 == 0)) {
                r = DIV_S64(self_capdata * GTX8_SHORT_RESISTANCE_CALC_ALPHA1 * FLOAT_AMPLIFIER, r_data->short_code);
                r -= (GTX8_SHORT_RESISTANCE_CALC_ALPHA1 * FLOAT_AMPLIFIER);
            } else {
                r = DIV_S64(self_capdata * GTX8_SHORT_RESISTANCE_CALC_ALPHA2 * FLOAT_AMPLIFIER, r_data->short_code);
                r -= (GTX8_SHORT_RESISTANCE_CALC_ALPHA2 * FLOAT_AMPLIFIER);
            }
        }
    } else {
        r = DIV_S64(self_capdata * GTX8_SHORT_RESISTANCE_CALC_ALPHA1 * FLOAT_AMPLIFIER, r_data->short_code);
        r -= (GTX8_SHORT_RESISTANCE_CALC_ALPHA1 * FLOAT_AMPLIFIER);
    }

    r = (long)DIV_S64(r, FLOAT_AMPLIFIER);
    r = r > MAX_U16_VALUE ? MAX_U16_VALUE : r;

    return r >= 0 ? r : 0;
}

#define ADC_SIGNAL_HEADER_SIZE 4
#define GTX8_MAX_ADC_RAW_DATA 0xffff
static int gt786x_drv_drv_short_check(struct gtx8_ts_test *ts_test, u16 *self_capdata, u8 short_num, char *data_buf)
{
    struct ts_test_params *test_params = &ts_test->test_params;
    u16 data_addr, adc_signal, short_die_num;
    int ret, size, i, j, find_short_chn = 0;
    u32 r_threshold = 0, short_r = 0, master_pin_num, slave_pin_num;
    struct short_record temp_short_info;

    /* drv&drv shortcircut check */
    data_addr = DRVxDRV_SHORT_NUM_ADDR;
    for (i = 0; i < short_num; i++) {
        size = SHORT_CAL_SIZE(MAX_DRV_NUM);     /* 4 + MAX_DRV_NUM * 2 + 2; */
        ret = gt786x_hw_ops.read(data_addr, data_buf, size);
        if (ret) {
            ts_err("Failed read drv-to-drv short rawdata\n");
            return -EINVAL;
        }

        r_threshold = test_params->r_drv_drv_threshold;
        short_die_num = be16_to_cpup((const __be16 *)(&data_buf[0]));
        if (short_die_num > MAX_DRV_NUM + MAX_SEN_NUM || short_die_num < MAX_SEN_NUM) {
            ts_info("invalid short pad num:%d\n", short_die_num);
            continue;
        }

        /* j start position need recheck */
        short_die_num -= MAX_SEN_NUM;
        for (j = short_die_num + 1; j < MAX_DRV_NUM; j++) {
            adc_signal = be16_to_cpup((const __be16 *)(&data_buf[ADC_SIGNAL_HEADER_SIZE + j * sizeof(u16)]));
            if (adc_signal <= test_params->short_threshold) {
                continue;
            }

            temp_short_info.master = short_die_num | DRV_CHANNEL_FLAG;
            temp_short_info.slave = j | DRV_CHANNEL_FLAG;
            temp_short_info.short_code = adc_signal;
            gtx8_check_setting_group(ts_test, &temp_short_info);

            if (self_capdata[short_die_num] == GTX8_MAX_ADC_RAW_DATA || self_capdata[short_die_num] == 0) {
                ts_info("invalid self_capdata:0x%x\n", self_capdata[short_die_num]);
                continue;
            }

            short_r = gtx8_short_resistance_calc(ts_test, &temp_short_info, self_capdata[short_die_num], 0);
            if (short_r < 0) {
                return -EINVAL;
            }

            if (short_r < r_threshold) {
                master_pin_num = map_die2pin(test_params, temp_short_info.master);
                slave_pin_num = map_die2pin(test_params, temp_short_info.slave);
                gtx8_save_short_res(ts_test, master_pin_num, slave_pin_num, short_r);
                ts_err("Tx/Tx short circut:R=%dK,R_Threshold=%dK\n", short_r, r_threshold);
                find_short_chn++;
            }
        }
        data_addr += size;
    }
    return find_short_chn;
}

static int gt786x_sen_sen_short_check(struct gtx8_ts_test *ts_test, u16 *self_capdata, u8 short_num, char *data_buf)
{
    struct ts_test_params *test_params = &ts_test->test_params;
    u16 data_addr, adc_signal, short_die_num;
    int ret, size, i, j, find_short_chn = 0;
    u32 r_threshold = 0, short_r = 0, master_pin_num, slave_pin_num;
    struct short_record temp_short_info;

    data_addr = SENxSEN_SHORT_NUM_ADDR;
    for (i = 0; i < short_num; i++) {
        size = SHORT_CAL_SIZE(MAX_SEN_NUM); /* 4 + MAX_SEN_NUM * 2 + 2; */
        ret = gt786x_hw_ops.read(data_addr, data_buf, size);
        if (ret) {
            ts_err("Failed read sen-to-sen short rawdata\n");
            return -EINVAL;
        }

        r_threshold = ts_test->test_params.r_sen_sen_threshold;
        short_die_num = be16_to_cpup((const __be16 *)(&data_buf[0]));
        if (short_die_num > MAX_SEN_NUM) {
            continue;
        }

        for (j = short_die_num + 1; j < MAX_SEN_NUM; j++) {
            adc_signal = be16_to_cpup((const __be16 *)(&data_buf[ADC_SIGNAL_HEADER_SIZE + j * sizeof(u16)]));
            if (adc_signal <= ts_test->test_params.short_threshold) {
                continue;
            }

            temp_short_info.master = short_die_num;
            temp_short_info.slave = j;
            temp_short_info.short_code = adc_signal;
            gtx8_check_setting_group(ts_test, &temp_short_info);

            if (self_capdata[short_die_num + MAX_DRV_NUM] == GTX8_MAX_ADC_RAW_DATA ||
                self_capdata[short_die_num + MAX_DRV_NUM] == 0) {
                ts_info("invalid self_capdata:0x%x\n", self_capdata[short_die_num + MAX_DRV_NUM]);
                continue;
            }

            short_r = gtx8_short_resistance_calc(ts_test, &temp_short_info,
                                                 self_capdata[short_die_num + MAX_DRV_NUM], 0);
            if (short_r < 0) {
                return -EINVAL;
            }
            if (short_r < r_threshold) {
                master_pin_num = map_die2pin(test_params, temp_short_info.master);
                slave_pin_num = map_die2pin(test_params, temp_short_info.slave);
                gtx8_save_short_res(ts_test, master_pin_num, slave_pin_num, short_r);
                ts_err("Rx/Rx short circut:R=%dK,R_Threshold=%dK\n", short_r, r_threshold);
                find_short_chn++;
            }
        }
        data_addr += size;
    }
    return find_short_chn;
}

static int gt786x_sen_drv_short_check(struct gtx8_ts_test *ts_test, u16 *self_capdata, u8 short_num, char *data_buf)
{
    struct ts_test_params *test_params = &ts_test->test_params;
    u16 data_addr, adc_signal, short_die_num;
    int ret, size, i, j, find_short_chn = 0;
    u32 r_threshold = 0, short_r = 0, master_pin_num, slave_pin_num;
    struct short_record temp_short_info;

    data_addr = SENxDRV_SHORT_NUM_ADDR;
    for (i = 0; i < short_num; i++) {
        size =  SHORT_CAL_SIZE(MAX_DRV_NUM); /* size = 4 + MAX_SEN_NUM * 2 + 2; */
        ret = gt786x_hw_ops.read(data_addr, data_buf, size);
        if (ret) {
            ts_err("Failed read sen-to-drv short rawdata\n");
            return -EINVAL;
        }

        r_threshold = ts_test->test_params.r_drv_sen_threshold;
        short_die_num = be16_to_cpup((const __be16 *)(&data_buf[0]));
        if (short_die_num > MAX_SEN_NUM) {
            continue;
        }

        for (j = 0; j < MAX_DRV_NUM; j++) {
            adc_signal = be16_to_cpup((const __be16 *)(&data_buf[4 + j * 2]));
            if (adc_signal <= ts_test->test_params.short_threshold) {
                continue;
            }

            temp_short_info.master = short_die_num;
            temp_short_info.slave = j | DRV_CHANNEL_FLAG;
            temp_short_info.short_code = adc_signal;
            gtx8_check_setting_group(ts_test, &temp_short_info);

            if (self_capdata[short_die_num + MAX_DRV_NUM] == GTX8_MAX_ADC_RAW_DATA ||
                self_capdata[short_die_num + MAX_DRV_NUM] == 0) {
                ts_info("invalid self_capdata:0x%x\n", self_capdata[short_die_num + MAX_DRV_NUM]);
                continue;
            }

            short_r = gtx8_short_resistance_calc(ts_test, &temp_short_info,
                                                 self_capdata[short_die_num + MAX_DRV_NUM], 0);
            if (short_r < 0) {
                return -EINVAL;
            }
            if (short_r < r_threshold) {
                master_pin_num = map_die2pin(test_params, temp_short_info.master);
                slave_pin_num = map_die2pin(test_params, temp_short_info.slave);
                gtx8_save_short_res(ts_test, master_pin_num, slave_pin_num, short_r);
                ts_err("Rx/Tx short circut:R=%dK,R_Threshold=%dK\n", short_r, r_threshold);
                find_short_chn++;
            }
        }
        data_addr += size;
    }
    return find_short_chn;
}

#define GTX8_SHORT_RESULT_MASK 0x0F
static int _do_chn2chn_short_check(struct gtx8_ts_test *ts_test, u8 *data_buf)
{
    int ret = 0, find_short_chn_num = 0, size = 0, i;
    u8 short_status[3] = {0};
    u16 self_capdata[MAX_DRV_NUM + MAX_SEN_NUM] = {0};

    /* read self-capdata+ */
    size = (MAX_DRV_NUM + MAX_SEN_NUM) * sizeof(u16);
    ret = gt786x_hw_ops.read(DRV_SELF_CODE_REG, data_buf, size);  /* DRV_SELF_CODE_REG   0xa8e0 */
    if (ret) {
        ts_err("Failed read selfcap rawdata\n");
        return -EINVAL;
    }
    for (i = 0; i < MAX_DRV_NUM + MAX_SEN_NUM; i++) {
        self_capdata[i] = be16_to_cpup((const __be16 *)(&data_buf[i * sizeof(u16)])) & 0x7fff;
    }
    /* read self-capdata- */

    /* read tx tx short number
    **   short_status[0]: tr tx
    **   short_status[1]: tr rx
    **   short_status[2]: rx rx
    */
    ret = gt786x_hw_ops.read(TX_SHORT_NUM, &short_status[0], sizeof(short_status));
    if (ret) {
        ts_err("Failed read tx-to-tx short rawdata\n");
        return -EINVAL;
    }
    ts_info("Tx&Tx:%d,Rx&Rx:%d,Tx&Rx:%d\n", short_status[0], short_status[1], short_status[INDEX_2]);

    /* drv&drv shortcircut check */
    if ((ret = gt786x_drv_drv_short_check(ts_test, self_capdata, short_status[0], data_buf)) < 0) {
        return -EINVAL;
    }
    find_short_chn_num += ret;

    /* sen&sen shortcircut check */
    if ((ret = gt786x_sen_sen_short_check(ts_test, self_capdata, short_status[1], data_buf)) < 0) {
        return -EINVAL;
    }
    find_short_chn_num += ret;

    /* sen&drv shortcircut check */
    if ((ret = gt786x_sen_drv_short_check(ts_test, self_capdata, short_status[INDEX_2], data_buf)) < 0) {
        return -EINVAL;
    }
    find_short_chn_num += ret;
    return find_short_chn_num;
}

static int gtx8_shortcircut_analysis(struct gtx8_ts_test *ts_test)
{
    int ret = 0, find_short_chn_num = 0, size = 0, i;
    u16 adc_signal = 0;
    u8 short_flag = 0, *data_buf = NULL;

    ret = gt786x_hw_ops.read(TEST_RESTLT_REG, &short_flag, sizeof(short_flag)); /* TEST_RESTLT_REG  0x8401 */
    if (ret < 0) {
        ts_err("Read TEST_TESULT_REG falied\n");
        goto shortcircut_analysis_error;
    } else if ((short_flag & GTX8_SHORT_RESULT_MASK) == 0x00) {
        ts_info("No shortcircut\n");
        return NO_ERR;
    }

    data_buf = sys_malloc((MAX_DRV_NUM + MAX_SEN_NUM) * sizeof(u16));
    if (!data_buf) {
        goto shortcircut_analysis_error;
    }

    /* shortcircut to gnd&vdd */
    if (short_flag & 0x08) {
        /* read diff code, diff code will be used to calculate
        * resistance between channel and GND */
        size = (MAX_DRV_NUM + MAX_SEN_NUM) * sizeof(u16);
        ret = gt786x_hw_ops.read(DIFF_CODE_REG, data_buf, size); /* DIFF_CODE_REG   0xA97A */
        if (ret < 0) {
            ts_err("Failed read to-gnd rawdata\n");
            goto shortcircut_analysis_error;
        }
        for (i = 0; i < size; i += sizeof(u16)) {
            adc_signal = be16_to_cpup((const __be16 *)(&data_buf[i]));
            ret = gtx8_check_resistance_to_gnd(ts_test, adc_signal, i >> 1); /* i >> 1 = i / 2 */
            if (ret) {
                ts_err("Resistance to-gnd test failed\n");
                find_short_chn_num++;
            }
        }
    }

    ret = _do_chn2chn_short_check(ts_test, data_buf);
    if (ret < 0) {
        goto shortcircut_analysis_error;
    }
    find_short_chn_num += ret;

shortcircut_analysis_error:
    if (data_buf != NULL) {
        sys_free(data_buf);
        data_buf = NULL;
    }
    return ret < 0 ? ret : find_short_chn_num;
}

static void gtx8_version_test(struct gtx8_ts_test *ts_test)
{
    int ret;
    struct goodix_ts_version *fw_ver = &ts_test->fw_ver;

    ts_test->test_result[GTP_VERSION_TEST] = GTP_TEST_PASS;
    ret = gt786x_hw_ops.read_version(fw_ver);
    if (ret) {
        ts_err("Failed read version\n");
        ts_test->test_result[GTP_VERSION_TEST] = SYS_SOFTWARE_REASON;
        return;
    }
    if (memcmp(fw_ver->vid, ts_test->test_params.fw_vid, sizeof(ts_test->test_params.fw_vid))) {
        ts_err("Version test failed\n");
        ts_info("chip vid:");
        ts_info_array(fw_ver->vid, sizeof(fw_ver->vid));
        ts_info("patch vid:");
        ts_info_array(ts_test->test_params.fw_vid, sizeof(ts_test->test_params.fw_vid));
        ts_test->test_result[GTP_VERSION_TEST] = GTP_PANEL_REASON;
        return;
    }
}

static void gtx8_config_test(struct gtx8_ts_test *ts_test)
{
    ts_test->test_result[GTP_CONFIG_TEST] = GTP_TEST_PASS;
    if (ts_test->orig_config.initialized == 0) {
        ts_err("Failed to get original config\n");
        ts_test->test_result[GTP_CONFIG_TEST] = SYS_SOFTWARE_REASON;
        return;
    }

    if (!gtx8_config_compare(&ts_test->orig_config, &ts_test->normal_config)) {
        ts_info("Config test pass\n");
        return;
    }

    ts_test->test_result[GTP_CONFIG_TEST] = GTP_PANEL_REASON;
}

#define GOODIX_DELAY_2S     2000
#define GOODIX_RETRY_110    110
#define GT786X_SHORT_TEST_END_FLAG 0x88
static void gtx8_shortcircut_test(struct gtx8_ts_test *ts_test)
{
    int i = 0;
    int ret = 0;
    u8 data[2] = {0};

    ts_test->short_res.short_num = 0;
    ts_test->test_result[GTP_SHORT_TEST] = GTP_TEST_PASS;
    ret = gtx8_short_test_prepare(ts_test);
    if (ret < 0) {
        ts_err("Failed enter short test mode\n");
        ts_test->test_result[GTP_SHORT_TEST] = SYS_SOFTWARE_REASON;
        return;
    }

    sys_delay_ms(GOODIX_DELAY_2S);

    for (i = 0; i < GOODIX_RETRY_110; i++) {
        sys_delay_ms(GOODIX_DELAY_50MS);
        ts_info("waitting for short test end...:retry=%d\n", i);
        ret = gt786x_hw_ops.read(SHORT_TESTEND_REG, data, 1); /* SHORT_TESTEND_REG   0x8400 */
        if (ret) {
            ts_err("Failed get short test result: retry%d\n", i);
        } else if (data[0] == GT786X_SHORT_TEST_END_FLAG) { /* test ok */
            break;
        }
    }

    if (i >= GOODIX_RETRY_110) {
        ts_err("Wait short test finish timeout:reg_val=0x%x\n", data[0]);
        ts_test->test_result[GTP_SHORT_TEST] = SYS_SOFTWARE_REASON;
        return;
    }

    ret = gtx8_shortcircut_analysis(ts_test);
    if (ret) {
        ts_test->test_result[GTP_SHORT_TEST] = GTP_PANEL_REASON;
        ts_err("Short test failed\n");
    } else {
        ts_err("Short test success\n");
    }
}
static u8 get_chn_group_nor(u8 chn)
{
    static const u8 group_map[] = {
        5, 5, 5, 5, 5, 5, 5,  // chn 0~6
        4, 4, 4, 4, 4,         // chn 7~11
        3, 3,                  // chn 12~13
        2, 2, 2, 2, 2, 2, 2,   // chn 14~20
        1, 1, 1, 1, 1,         // chn 21~25
        0, 0,                  // chn 26~27
        0, 0,                  // chn 28~29
        5, 5, 5, 5, 5, 5, 5,   // chn 30~36
        4, 4, 4, 4, 4,         // chn 37~41
        3, 3,                  // chn 42~43
        2, 2, 2, 2, 2, 2, 2,   // chn 44~50
        1, 1, 1, 1, 1,         // chn 51~55
        0, 0                   // chn 56~57
    };

    if (chn < sizeof(group_map)) {
        return group_map[chn];
    }
    return 0;  // Default group for out-of-range chn
}

#define GOODIX_CHN_NUM_MASK 0x7F
static void gtx8_check_setting_group(struct gtx8_ts_test *ts_test, struct short_record *r_data)
{
    u32 master = 0;
    u32 slave = 0;

    if (r_data->master & DRV_CHANNEL_FLAG) {
        master = MAX_SEN_NUM;
    }

    if (r_data->slave & DRV_CHANNEL_FLAG) {
        slave = MAX_SEN_NUM;
    }

    master += (r_data->master & GOODIX_CHN_NUM_MASK);
    slave += (r_data->slave & GOODIX_CHN_NUM_MASK);

    r_data->group1 = get_chn_group_nor(master);
    r_data->group2 = get_chn_group_nor(slave);
}

static void goodix_ts_irq_enable(struct gtx8_ts_test *ts_test, int enable)
{
    if (enable) {
        // enable irq
    } else {
        // disable irq
    }
}

/* Do TP inspect
 * return : -EINVAL if enter sofeware error. 0 if all test items pass,
 *   otherwise return the test result every bit represents a test item,
 *   bit=0 for test succssm, bit=1 for test fail.
 *   bit0: reserved.
 *   bit1: cap test.
 *   bit2: delta test.
 *   bit3: short test.
 *   bit4: version test.
 *   bit5: config test.
 */
int gtx8_do_inspect(void)
{
    int ret = 0, i;
    struct gtx8_ts_test *gts_test = &g_ts_test;

    memset_s(gts_test, sizeof(*gts_test), 0, sizeof(*gts_test));
    /* close irq and esd */
    goodix_ts_irq_enable(gts_test, 0);

    gt786x_hw_ops.hid_mode_switch(0);

    ret = gtx8_tptest_prepare(gts_test);
    if (ret) {
        ts_err("%s: Failed parse test peremeters, exit test\n", __func__);
        ret = -EINVAL;
        goto exit_finish;
    }
    ts_info("%s: TP test prepare OK\n", __func__);

    gtx8_version_test(gts_test);
    gtx8_config_test(gts_test);
    gtx8_capacitance_test(gts_test);
    msleep(GOODIX_DELAY_20MS);
    gtx8_shortcircut_test(gts_test);

    gtx8_put_test_result(gts_test);

#ifdef SAVE_IN_CSV
    gtx8_save_test_result(gts_test);
#endif
    gtx8_tptest_finish(gts_test);

    ret = 0;
    for (i = 1; i < MAX_TEST_ITEMS; i++) {
        /* if have tested, show result */
        if (gts_test->test_result[i] && (gts_test->test_result[i] > GTP_TEST_PASS)) {
            ret |= (1 << i);
        }
    }

exit_finish:
    goodix_ts_irq_enable(gts_test, 0);
    return ret;
}
