mkdir -p obj

arm-none-eabi-as -mcpu=cortex-a9 -g src/startup.s -o obj/startup.o -w

arm-none-eabi-gcc -cpp -mcpu=cortex-a9 src/test.cpp -o obj/test.o -w
arm-none-eabi-gcc -cpp -mcpu=cortex-a9 src/master.cpp -o obj/master.o -w
arm-none-eabi-gcc -cpp -mcpu=cortex-a9 src/slave.cpp -o obj/slave.o -w

arm-none-eabi-ld -T src/test.ld obj/master.o obj/slave.o obj/test.o obj/startup.o -o obj/test.elf

arm-none-eabi-objcopy -O binary obj/test.elf obj/test.bin

qemu-system-arm -M realview-pbx-a9 -cpu cortex-a9 -m 128M -nographic -kernel obj/test.bin
