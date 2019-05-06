mkdir -p obj

arm-none-eabi-as -mcpu=cortex-a9 -g src/startup.s -o obj/startup.o

arm-none-eabi-gcc -c -mcpu=cortex-a9 -g src/APB_test.c -o obj/APB_test.o
arm-none-eabi-gcc -c -mcpu=cortex-a9 -g src/APB_Slave.c -o obj/APB_Slave.o
arm-none-eabi-gcc -c -mcpu=cortex-a9 -g src/APB_Master.c -o obj/APB_Master.o

arm-none-eabi-ld -T src/test.ld obj/APB_Slave.o obj/APB_Master.o obj/APB_test.o obj/startup.o -o obj/test.elf

arm-none-eabi-objcopy -O binary obj/test.elf obj/test.bin

qemu-system-arm -M realview-pbx-a9 -m 128M -nographic -kernel obj/test.bin
