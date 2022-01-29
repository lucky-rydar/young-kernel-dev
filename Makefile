KDIR ?= /lib/modules/`uname -r`/build

obj-m += lkm.o

all:
	echo $(PWD)
	make -C ${KDIR} M=$(PWD) modules
clean:
	make -C ${KDIR} M=$(PWD) clean

insmod: all
	sudo insmod lkm.ko

dmesg:
	sudo dmesg | grep "lkm: "

rmmod:
	sudo rmmod lkm

test: insmod dmesg rmmod