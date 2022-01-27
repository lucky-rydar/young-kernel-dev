#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/gpio.h>

#define TAG "helloworld: "
#define LOGI(str) printk(KERN_INFO TAG ": " str);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert W. Oliver II");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

int helloworld_parallel(void*) {
    int i = 0;
    while(!kthread_should_stop()) {
        printk(KERN_INFO TAG "n second of thread=(%d)\n", i++);
        msleep(1000);
    }
    return 0;
}

static struct task_struct* counter_thread;

static int __init helloworld_init(void) {
    printk(KERN_INFO TAG "Hello, World!\n");
    
    counter_thread = kthread_create(helloworld_parallel, NULL, "second counter thread");
    if(counter_thread) {
        wake_up_process(counter_thread);
    } else {
        printk(KERN_ERR TAG "Cant create a thread\n");
    }

    return 0;
}

static void __exit helloworld_exit(void) {
    kthread_stop(counter_thread);
    
    printk(KERN_INFO TAG "Goodbye, World!\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);