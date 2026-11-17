## 使用说明

* hm_os_sys.c/h

  该文件用于定义系统相关的操作函数，例如i2c读写，延时，内存申请等。需要客户手动确认。

* gt7861_test_limits.csv

  该文件用于定义测试阈值。需要FAE同事确认和修改。

* gt7861_test_cfg.bin

  该文件为测试配置文件。

* 初始化i2c设备

  使用dev_i2c_init(struct i2c_client *client) 初始化i2c_client设备，用于实现i2c读写操作。

* gt786x_inspect.c
  
  测试相关函数实现。调用 gtx8_do_inspect() 启动测试。测试阈值文件通过内核API request_firmware()
  从文件gt7861_test_threshold.csv中解析。
  函数gtx8_do_inspect()返回值说明：
  返回值小于0表示测试过程遇到软件异常。
  测试返回值等于0表示所有测试通过。
  测试返回值大于0表示有测试项失败。返回值的bit位值1表示对应测试项失败。bit映射表如下
  bit0: reserved.
  bit1: cap test.
  bit2: delta test.
  bit3: short test.
  bit4: version test.
  bit5: config test.

  定义宏 `SAVE_IN_CSV` 可以使能测试结果保存到文件。保存文件位置通过`GOODIX_RESULT_SAVE_PATH`修改。
  
* gt786x_fwupdate.c
  
  升级相关函数实现。调用goodix_fw_update_proc() 开始升级。升级配置和固件通过kernel API request_firmware()获取，
  默认文件名为gt7861_firmware.bin和gt7861_normal_cfg.bin。