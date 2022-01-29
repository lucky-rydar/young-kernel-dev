#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/gpio.h>

#define TAG "lkm: "

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Didur M.");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.0.1");

static int __init lkm_init(void) {
    printk(KERN_INFO TAG "Hello, World!\n");
    return 0;
}

static void __exit lkm_exit(void) {
    printk(KERN_INFO TAG "Goodbye, World!\n");
}

module_init(lkm_init);
module_exit(lkm_exit);