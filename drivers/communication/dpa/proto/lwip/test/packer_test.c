#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <asm/current.h>
#include <linux/atomic.h>
#include <linux/socket.h>
#include <linux/bitops.h>
#include <net/tcp.h>
#include "packer_sock.h"

int test_pack_sock_create(void)
{
    int af_family;
    int type;
    char buf[128];
    PACKER_BUFFER(packer0, buf, sizeof(buf));
    printk("packer0:%p, %d, %d\n", packer0.base, packer0.size, packer0.curr);

    PACKER_BUFFER(packer1, buf, sizeof(buf));
    printk("packer1:%p, %d, %d\n", packer1.base, packer1.size, packer1.curr);

    af_family = 0xabcd;
    type = 0x1234;
    pack_sock_create(&packer0, af_family, type);

    unpack_sock_create(&packer1, &af_family, &type);

    if (af_family != 0xabcd || type != 0x1234) {
        printk("af_family:%d, type:%d\n", af_family, type);
        return -1;
    }

    return 0;
}
