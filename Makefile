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

rmmod:
	sudo rmmod helloworld

test: insmod dmesg rmmod