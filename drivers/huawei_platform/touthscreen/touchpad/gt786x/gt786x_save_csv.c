/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include <linux/fs.h>
#include <linux/slab.h>
#include "goodix_ts_log.h"
#include "gt786x_inspect.h"


#ifdef SAVE_IN_CSV

#define MAX_DATA_BUFFER						28000

/**
 * fw_write - Write data to file
 */
static ssize_t fs_write(const void* buf, size_t size, struct file* fp)
{
    loff_t pos;
    ssize_t len;

    pos = fp->f_pos;
    len = kernel_write(fp, buf, size, &pos);
    fp->f_pos = pos;

    return len;
}

/**
 * gtx8_save_test_config - Save test config to file
 */
static int gtx8_save_test_config(struct gtx8_ts_test *ts_test, struct file *fp)
{
    int ret = 0;
    int i;
    int bytes = 0;
    char *data;
    struct goodix_ts_config *cfg = &ts_test->test_config;

    if (cfg->length <= 0) {
        ts_info("Can't find vaild test config");
        return 0;
    }

    data = kzalloc(MAX_DATA_BUFFER, GFP_KERNEL);
    if (!data) {
        ts_err("alloc memory failed");
        return -ENOMEM;
    }

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<OrderConfig>\n");
    for (i = 0; i < cfg->length; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "0x%02x,", cfg->data[i]);
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</OrderConfig>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("test config write failed");
        goto save_end;
    }

save_end:
    kfree(data);
    return ret;
}

/**
 * gtx8_format_test_result_header - Format test result header
 */
static int gtx8_format_test_result_header(struct gtx8_ts_test *ts_test, char *data)
{
    bool result = false;
    int bytes = 0, i;

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<TESTLOG>\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<Header>\n");
    /* sava test result */
    for (i = 0; i < MAX_TEST_ITEMS; i++) {
        if ((ts_test->test_result[i] > 0) &&
            (ts_test->test_result[i] != GTP_TEST_PASS)) {
                result = true;
                break;
        }
    }
    if (result) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<Result>NG</Result>\n");
    } else {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<Result>OK</Result>\n");
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<DeviceType>GT%s</DeviceType>\n",
                       ts_test->fw_ver.pid);
    return bytes;
}

/**
 * gtx8_format_test_item_result - Format test item result
 */
static int gtx8_format_test_item_result(char *buffer, char test_result, const char *item_name)
{
    if (!test_result) {
        return 0;
    }

    if (test_result == GTP_TEST_PASS) {
        return sprintf_s(buffer, MAX_DATA_BUFFER, "<Item name=\"%s Test\" result=\"OK\"/>\n", item_name);
    }
    return sprintf_s(buffer, MAX_DATA_BUFFER, "<Item name=\"%s Test\" result=\"NG\"/>\n", item_name);
}

/**
 * gtx8_save_header - Save test result header to file
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @fp: Pointer to the file structure where the header will be saved.
 *
 * This function writes the test result header information from the
 * gtx8_ts_test structure to the specified file. It ensures that the
 * header is properly formatted and saved for further analysis or
 * debugging purposes.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_save_header(struct gtx8_ts_test *ts_test, struct file *fp)
{
    int ret, bytes = 0;
    char *data = NULL;

    data = kzalloc(MAX_DATA_BUFFER, GFP_KERNEL);
    if (!data) {
        ts_err("alloc memory failed");
        return -ENOMEM;
    }
    bytes = gtx8_format_test_result_header(ts_test, data);
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("header write failed");
        goto save_end;
    }

    /* save test config */
    ret = gtx8_save_test_config(ts_test, fp);
    if (ret < 0)  {
        ts_err("save test config failed");
        goto save_end;
    }

    bytes = 0;
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER, "</Header>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("header write failed");
        goto save_end;
    }

    /* item list */
    bytes = 0;
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER, "<ItemList>\n");
    bytes += gtx8_format_test_item_result(&data[bytes], ts_test->test_result[GTP_CAP_TEST], "Rawdata MAX/MIN");
    bytes += gtx8_format_test_item_result(&data[bytes], ts_test->test_result[GTP_DELTA_TEST],
                                          "Rawdata Adjcent Deviation");
    bytes += gtx8_format_test_item_result(&data[bytes], ts_test->test_result[GTP_SHORT_TEST], "Short");
    bytes += gtx8_format_test_item_result(&data[bytes], ts_test->test_result[GTP_VERSION_TEST], "Firmware Version");
    bytes += gtx8_format_test_item_result(&data[bytes], ts_test->test_result[GTP_CONFIG_TEST], "Config");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</ItemList>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("item list write failed");
        goto save_end;
    }

save_end:
    kfree(data);
    return ret;
}


/**
 * gtx8_save_tail - Save the closing tag of the test log to the file.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @fp: Pointer to the file structure where the closing tag will be saved.
 *
 * This function writes the closing XML tag for the test log to the specified file.
 * It ensures proper formatting and finalizes the test log file.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_save_tail(struct gtx8_ts_test *ts_test, struct file *fp)
{
    int ret = 0;
    int bytes = 0;
    char *data = NULL;

    data = kzalloc(MAX_DATA_BUFFER, GFP_KERNEL);
    if (!data) {
        return -ENOMEM;
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER, "</TESTLOG>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("tail write failed");
    }
    kfree(data);
    return ret;
}

/**
 * gtx8_format_short_chn_result - Format and save short channel test results.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @data: Buffer to store formatted data.
 * @fp: Pointer to the file structure where the results will be saved.
 *
 * This function formats the short channel test results and writes them to the specified file.
 * It includes details such as the number of short circuits and their respective resistance values.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
#define GTX8_CHN_NUM_MASK 0x7F
#define OFF_SIZE_8 8
static int gtx8_format_short_chn_result(struct gtx8_ts_test *ts_test, char *data, struct file *fp)
{
    int bytes, ret, chn1, chn2, r, i;

    /* save short result */
    if (ts_test->test_result[GTP_SHORT_TEST]) {
        return 0;
    }

    bytes = sprintf_s(data, MAX_DATA_BUFFER, "<Item name=\"Short Test\">\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ShortNum>%d</ShortNum>\n",
                       ts_test->short_res.short_num);
    for (i = 0; i < ts_test->short_res.short_num; i++) {
        chn1 = ts_test->short_res.short_msg[SHORT_MSG_SIZE * i];
        chn2 = ts_test->short_res.short_msg[SHORT_MSG_SIZE * i + 1];
        r = (ts_test->short_res.short_msg[SHORT_MSG_SIZE * i + INDEX_2] << OFF_SIZE_8) +
            ts_test->short_res.short_msg[SHORT_MSG_SIZE * i + INDEX_3];
        if (chn1 == CHN_VDD) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ShortMess Chn1=\"VDD\" ");
        } else if (chn1 == CHN_GND) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ShortMess Chn1=\"GND\" ");
        } else if (chn1 & DRV_CHANNEL_FLAG) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ShortMess Chn1=\"Tx%d\" ",
                               chn1 & GTX8_CHN_NUM_MASK);
        } else {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ShortMess Chn1=\"Rx%d\" ",
                               chn1 & GTX8_CHN_NUM_MASK);
        }
        if (chn2 == CHN_VDD) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes,
                               "Chn2=\"VDD\" ShortResistor= \"%dKom\"/>\n", r);
        } else if (chn2 == CHN_GND) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes,
                               "Chn2=\"GND\" ShortResistor= \"%dKom\"/>\n", r);
        } else if (chn2 & DRV_CHANNEL_FLAG) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes,
                               "Chn2=\"Tx%d\" ShortResistor= \"%dKom\"/>\n",
                               chn2 & GTX8_CHN_NUM_MASK, r);
        } else {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes,
                               "Chn2=\"Rx%d\" ShortResistor= \"%dKom\"/>\n",
                               chn2 & GTX8_CHN_NUM_MASK, r);
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</Item>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("short res write fail.");
        return ret;
    }
    return 0;
}

/**
 * gtx8_format_max_rawdata_result - Format and save maximum raw data results.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @tx: Number of driver channels (rows).
 * @rx: Number of sensor channels (columns).
 * @data: Buffer to store formatted data.
 * @fp: Pointer to the file structure where the results will be saved.
 *
 * This function formats the maximum raw data results and writes them to the specified file.
 * It includes details such as maximum raw limits and counts of values exceeding the upper limit.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_format_max_rawdata_result(struct gtx8_ts_test *ts_test, int tx, int rx, char *data, struct file *fp)
{
    int ret, bytes, i;

    bytes = sprintf_s(data, MAX_DATA_BUFFER, "<Item name=\"Rawdata Test Sets\">\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<TotalFrameCnt>%d</TotalFrameCnt>\n", TOTAL_FRAME_NUM);
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<MaxRawLimit>\n");
    for (i = 0; i < tx * rx; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,",
            ts_test->test_params.max_limits[i]);
        if ((i + 1) % rx == 0) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</MaxRawLimit>\n");
    /* BeyondRawdataUpperLimit */
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<BeyondRawdataUpperLimitCnt>\n");
    for (i = 0; i < tx * rx; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,",
                           ts_test->open_res.beyond_max_limit_cnt[i]);
        if ((i + 1) % rx == 0) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</BeyondRawdataUpperLimitCnt>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("rawdata limit write failed");
        return ret;
    }
    return 0;
}

/**
 * gtx8_format_min_rawdata_result - Format and save minimum raw data results.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @tx: Number of driver channels (rows).
 * @rx: Number of sensor channels (columns).
 * @data: Buffer to store formatted data.
 * @fp: Pointer to the file structure where the results will be saved.
 *
 * This function formats the minimum raw data results and writes them to the specified file.
 * It includes details such as minimum raw limits and counts of values below the lower limit.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_format_min_rawdata_result(struct gtx8_ts_test *ts_test, int tx, int rx, char *data, struct file *fp)
{
    int ret, bytes, i;

    bytes = sprintf_s(data, MAX_DATA_BUFFER, "<MinRawLimit>\n");
    for (i = 0; i < tx * rx; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,",
            ts_test->test_params.min_limits[i]);
        if ((i + 1) % rx == 0) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</MinRawLimit>\n");
    /* BeyondRawdataLower limit */
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<BeyondRawdataLowerLimitCnt>\n");
    for (i = 0; i < tx * rx; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,",
                           ts_test->open_res.beyond_min_limit_cnt[i]);
        if ((i + 1) % rx == 0) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</BeyondRawdataLowerLimitCnt>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("rawdata limit write failed");
        return ret;
    }
    return 0;
}

/**
 * gtx8_format_accord_data_result - Format and save accord data results.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @tx: Number of driver channels (rows).
 * @rx: Number of sensor channels (columns).
 * @data: Buffer to store formatted data.
 * @fp: Pointer to the file structure where the results will be saved.
 *
 * This function formats the accord data results and writes them to the specified file.
 * It includes details such as maximum accord limits and counts of values exceeding the limit.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_format_accord_data_result(struct gtx8_ts_test *ts_test, int tx, int rx, char *data, struct file *fp)
{
    int ret, bytes, i;

    bytes = sprintf_s(data, MAX_DATA_BUFFER, "<MaxAccordLimit>\n");
    for (i = 0; i < tx * rx; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,",
            ts_test->test_params.deviation_limits[i]);
        if ((i + 1) % rx == 0) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</MaxAccordLimit>\n");
    /* BeyondAccordLimitCnt */
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<BeyondAccordLimitCnt>\n");
    for (i = 0; i < tx * rx; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,",
            ts_test->open_res.beyond_accord_limit_cnt[i]);
        if ((i + 1) % rx == 0) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
        }
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</BeyondAccordLimitCnt>\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</Item>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("rawdata limit write failed");
        return ret;
    }
    return 0;
}

/**
 * gtx8_format_version_result - Format and save firmware version test results.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @tx: Number of driver channels (rows).
 * @rx: Number of sensor channels (columns).
 * @data: Buffer to store formatted data.
 * @fp: Pointer to the file structure where the results will be saved.
 *
 * This function formats the firmware version test results and writes them to the specified file.
 * It includes details such as the target firmware version and the read-out firmware version.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_format_version_result(struct gtx8_ts_test *ts_test, int tx, int rx, char *data, struct file *fp)
{
    int ret, bytes, i;

    bytes = sprintf_s(data, MAX_DATA_BUFFER, "<Item name=\"Firmware Version Test Sets\">\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<TargetFirmwareVersion>\n");
    for (i = 0; i < FW_VERSION_SIZE; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "0x%x,", ts_test->test_params.fw_vid[i]);
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</TargetFirmwareVersion>\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ReadOutFirmwareVersion>\n");
    for (i = 0; i < FW_VERSION_SIZE; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "0x%x,", ts_test->fw_ver.vid[i]);
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</ReadOutFirmwareVersion>\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</Item>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("firmware version write failed");
        return ret;
    }
    return 0;
}

/**
 * gtx8_format_config_result - Format and save configuration test results.
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @data: Buffer to store formatted data.
 * @fp: Pointer to the file structure where the results will be saved.
 *
 * This function formats the configuration test results and writes them to the specified file.
 * It includes details such as the target configuration data and the read-out configuration data.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_format_config_result(struct gtx8_ts_test *ts_test, char *data, struct file *fp)
{
    int ret, bytes, i;

    bytes = sprintf_s(data, MAX_DATA_BUFFER, "<Item name=\"Config Test Sets\">\n");
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<TargetConfigData>\n");
    for (i = 0; i < ts_test->normal_config.length; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "0x%x,", ts_test->normal_config.data[i]);
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</TargetConfigData>\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<ReadOutConfigData>\n");
    for (i = 0; i < ts_test->orig_config.length; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "0x%x,", ts_test->orig_config.data[i]);
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</ReadOutConfigData>\n");

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</Item>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("firmware version write failed");
        return ret;
    }
    return 0;
}

/**
 * gtx8_save_limits - Save test limits to file
 *
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @fp: Pointer to the file structure where the limits will be saved.
 *
 * This function saves various test limits such as raw data limits,
 * short circuit thresholds, and other parameters to the specified file.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_save_limits(struct gtx8_ts_test *ts_test, struct file *fp)
{
    int ret, bytes;
    char *data = NULL;
    int tx = ts_test->test_params.drv_num; // row
    int rx = ts_test->test_params.sen_num; // col

    data = kzalloc(MAX_DATA_BUFFER, GFP_KERNEL);
    if (!data) {
        return -ENOMEM;
    }

    bytes = sprintf_s(data, MAX_DATA_BUFFER - bytes, "<TestItems>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("short res write fail.");
        goto save_end;
    }

    if (gtx8_format_short_chn_result(ts_test, data, fp)) {
        goto save_end;
    }

    if (gtx8_format_max_rawdata_result(ts_test, tx, rx, data, fp)) {
        goto save_end;
    }

    /* rawdata min limit */
    if (gtx8_format_min_rawdata_result(ts_test, tx, rx, data, fp)) {
        goto save_end;
    }

    /* Max Accord limit */
    if (gtx8_format_accord_data_result(ts_test, tx, rx, data, fp)) {
        goto save_end;
    }

    /* version test */
    if (gtx8_format_version_result(ts_test, tx, rx, data, fp)) {
        goto save_end;
    }

    /* config test */
    if (gtx8_format_config_result(ts_test, data, fp)) {
        goto save_end;
    }

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</TestItems>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("limit write fail.");
    }
save_end:
    kfree(data);
    return ret;
}

/**
 * gtx8_save_rawdata - Save raw data from the touchscreen test structure to a file.
 * @ts_test: Pointer to the touchscreen test structure containing raw data.
 * @fp: Pointer to the file where the raw data will be saved.
 *
 * This function is responsible for saving the raw data collected during
 * touchscreen testing into the specified file for further analysis or debugging.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_save_rawdata(struct gtx8_ts_test *ts_test, struct file *fp)
{
    int i, j, ret, bytes = 0;
    char *data = NULL;
    int tx = ts_test->test_params.drv_num;
    int rx = ts_test->test_params.sen_num;
    int len = tx * rx;

    data = kzalloc(MAX_DATA_BUFFER, GFP_KERNEL);
    if (!data) {
        return -ENOMEM;
    }
    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<RawDataRecord>\n");
    for (i = 0; i < TOTAL_FRAME_NUM; i++) {
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<DataContent No.=\"%d\" DataCount=\"%d\" >\n",
                           i, len);
        for (j = 0; j < len; j++) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,", ts_test->rawdata_arr[i].data[j]);
            if ((j + 1) % rx == 0) {
                bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
            }
        }
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</DataContent>\n");

        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "<RawAccord No.=\"%d\" DataCount=\"%d\">\n", i, len);
        for (j = 0; j < len; j++) {
            bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "%d,", ts_test->accord_arr[i].data[j]);
            if ((j + 1) % rx == 0) {
                bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "\n");
            }
        }
        bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</RawAccord>\n");
        ret = fs_write(data, bytes, fp);
        if (ret < 0) {
            ts_err("rawdata write fail.");
            goto save_end;
        }
        bytes = 0;
    }

    bytes += sprintf_s(&data[bytes], MAX_DATA_BUFFER - bytes, "</RawDataRecord>\n");
    ret = fs_write(data, bytes, fp);
    if (ret < 0) {
        ts_err("rawdata write fail.");
    }
save_end:
    kfree(data);
    return ret;
}


/**
 * gtx8_save_data - Save test data to a file.
 * @ts_test: Pointer to the gtx8_ts_test structure containing test data.
 * @fp: Pointer to the file where the data will be saved.
 *
 * This function is responsible for saving the test data from the
 * gtx8_ts_test structure into the specified file.
 *
 * Return: 0 on success, or a negative error code on failure.
 */
static int gtx8_save_data(struct gtx8_ts_test *ts_test, struct file *fp)
{
    int ret;
    const char *start_lable = "<DataRecord>\n";
    const char *end_lable = "</DataRecord>\n";

    ret = fs_write(start_lable, strlen(start_lable), fp);
    if (ret < 0) {
        ts_err("rawdata record lable failed");
        return ret;
    }

    ret = gtx8_save_rawdata(ts_test, fp);
    if (ret < 0) {
        return ret;
    }

    ret = fs_write(end_lable, strlen(end_lable), fp);
    if (ret < 0) {
        ts_err("rawdata data record lable fail.");
    }
    return ret;
}

#define FILE_RIGHT 0666
void gtx8_save_test_result(struct gtx8_ts_test *ts_test)
{
    int ret = 0;
    struct file *fp = NULL;

    fp = filp_open(GOODIX_RESULT_SAVE_PATH, O_CREAT | O_WRONLY | O_TRUNC, FILE_RIGHT);
    if (IS_ERR(fp)) {
        ts_err("create file:%s failed, fp:%ld", GOODIX_RESULT_SAVE_PATH, PTR_ERR(fp));
        return;
    }

    ret = gtx8_save_header(ts_test, fp);
    if (ret < 0) {
        goto save_end;
    }

    /* save limits */
    ret = gtx8_save_limits(ts_test, fp);
    if (ret < 0) {
        goto save_end;
    }

    /* save data */
    ret = gtx8_save_data(ts_test, fp);
    if (ret < 0) {
        goto save_end;
    }
    /* save tail */
    ret = gtx8_save_tail(ts_test, fp);
    if (ret < 0) {
        goto save_end;
    }

    ts_info("the test result save in %s", GOODIX_RESULT_SAVE_PATH);

save_end:
    filp_close(fp, NULL);
}
#endif
