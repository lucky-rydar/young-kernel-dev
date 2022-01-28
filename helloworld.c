#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/gpio.h>

#define TAG "helloworld: "

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert W. Oliver II");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static int __init helloworld_init(void) {
    printk(KERN_INFO TAG "Hello, World!\n");
    return 0;
}

static void __exit helloworld_exit(void) {
    printk(KERN_INFO TAG "Goodbye, World!\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);