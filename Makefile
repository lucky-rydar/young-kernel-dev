KDIR ?= /lib/modules/`uname -r`/build

obj-m += helloworld.o

all:
	echo $(PWD)
	make -C ${KDIR} M=$(PWD) modules
clean:
	make -C ${KDIR} M=$(PWD) clean

insmod: all
	sudo insmod helloworld.ko

dmesg:
	sudo dmesg | grep "helloworld: "

dmesg_clear:
	sudo dmesg -C

rmmod:
	-sudo rmmod helloworld

test: all rmmod dmesg_clear insmod dmesg  