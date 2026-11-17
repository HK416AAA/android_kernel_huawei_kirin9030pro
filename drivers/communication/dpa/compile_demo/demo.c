#include <linux/module.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/firmware.h>

unsigned int g_dpa_compile_demo_addr = 0xADE00000;

unsigned int dpa_compile_demo(unsigned int addr)
{
    int ret;
    struct platform_device *pdev = NULL;
    const struct firmware *fw = NULL;
    const char* dev_name = NULL;
    int ovcs_id = 0;
    u32 val;

    struct device_node *parent_node = NULL;
    const char *dpa_name = "dpa,demo";
    const char *fipc_name = "modem,fipc_device";

    pdev = platform_device_alloc("dpa_dto_load",PLATFORM_DEVID_NONE);
    if (IS_ERR(pdev)) {
        printk(KERN_ERR "pdev alloc err\n");
    }
    printk(KERN_ERR "platform_device_alloc\n");

    ret = platform_device_add(pdev);
    if (ret) {
        printk(KERN_ERR "pdev add err\n");
        platform_device_put(pdev);
        return ret;
    }
    printk(KERN_ERR "platform_device_add\n");
    ret = request_firmware(&fw, "dpa_dto.dtb", &pdev->dev);
    if (ret) {
        printk(KERN_ERR "request_firmware add err %d\n", ret);
        platform_device_del(pdev);
        platform_device_put(pdev);
        return ret;
    }
    printk(KERN_ERR "request_firmware %d\n", fw->size);
    ret = of_overlay_fdt_apply((void *)fw->data, fw->size, &ovcs_id);
    release_firmware(fw);
    if (ret) {
        printk(KERN_ERR "of_overlay_fdt_apply err %d\n", ret);
        platform_device_del(pdev);
        platform_device_put(pdev);
        return ret;
    }

    parent_node = of_find_compatible_node(NULL, NULL, dpa_name);
    if (parent_node == NULL) {
        printk(KERN_ERR "%s of_find_compatible_node didn't find !\n", dpa_name);
        return -1;
    }
    printk(KERN_ERR "dpa demo callback\n");

    ret = of_property_read_u32(parent_node, "dma_mask_bit", &val);
    if (ret) {
        printk(KERN_ERR "dma_mask_bit failed!\n");
        return -1;
    }
    pr_err("dma_mask_bit %d\n", val);

    parent_node = of_find_compatible_node(NULL, NULL, fipc_name);
    if (parent_node == NULL) {
        printk(KERN_ERR "%s of_find_compatible_node didn't find !\n", fipc_name);
        return -1;
    }
    printk(KERN_ERR "fipc demo callback\n");

    ret = of_property_read_u32(parent_node, "irq_type", &val);
    if (ret) {
        printk(KERN_ERR "irq_type failed!\n");
        return -1;
    }
    pr_err("irq_type %d\n", val);

    ret = of_property_read_string(parent_node, "fipc_dev_name", &dev_name);
    if (ret) {
        printk(KERN_ERR "fipc_dev_name failed!\n");
        return -1;
    }
    pr_err("fipc_dev_name %s\n", dev_name);

    g_dpa_compile_demo_addr = addr;
    return g_dpa_compile_demo_addr;
}

int dpa_compile_demo_init(void)
{
    printk(KERN_ERR "dpa demo init\n");
    return 0;
}

#ifdef CONFIG_DPA_COMPILE_DEMO
module_init(dpa_compile_demo_init);
MODULE_LICENSE("GPL");
#endif