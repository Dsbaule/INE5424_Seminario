mkdir -p obj

arm-none-eabi-as -mcpu=cortex-a9 -g src/startup.s -o obj/startup.o

arm-none-eabi-gcc -cpp -mcpu=cortex-a9 -g src/module.cpp -o obj/module.o

arm-none-eabi-ld -T src/test.ld \
    obj/module.o obj/startup.o -o obj/test.elf

arm-none-eabi-objcopy -O binary obj/test.elf obj/test.bin

qemu-system-arm -M realview-pbx-a9 -m 128M -nographic -kernel obj/test.bin
