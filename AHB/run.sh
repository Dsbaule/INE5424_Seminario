mkdir -p obj

arm-none-eabi-as -mcpu=cortex-a9 -g src/startup.s -o obj/startup.o -w
