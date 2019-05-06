#ifndef APB_TEST_H
#define APB_TEST_H

#define INITIALDATA 0000536000;
#define INCREMENT 0005500000;

#include "APB.h"
#include "APB_Master.h"
#include "APB_Slave.h"

volatile unsigned int * const UART0DR = (unsigned int *)0x10009000;

void print_uart0(const char *s) {
    while(*s != '\0') { /* Loop until end of string */
        *UART0DR = (unsigned int)(*s); /* Transmit char */
        s++; /* Next char */
    }
}
void print_uint32_uart0(uint32_t value) {
    char string[] = "0000000000";
    for(int i = 9; i >= 0; i--) {
        string[i] = '0' + (value % 10);
        value /= 10;
    }
    print_uart0(string);
}
void prettyPrint(int address, uint32_t value, uint8_t direction) {
    print_uart0("Data: ");
    print_uint32_uart0(value);
    if(direction)
        print_uart0(" sent to address ");
    else
        print_uart0(" received from address ");
    char string[] = "0\n";
    string[0] = '0' + address;
    print_uart0(string);
}

void sendData(struct APB_Signals * APB_bus, uint32_t * data, uint32_t address) {
    while(!sendDataMaster(APB_bus, data, address))
        runSlave(APB_bus);
}

void readData(struct APB_Signals * APB_bus, uint32_t * data, uint32_t address) {
    while(!readDataMaster(APB_bus, data, address))
        runSlave(APB_bus);
}S

void c_entry() {
    struct APB_Signals APB_bus;

    uint32_t data = INITIALDATA;

    print_uart0("\n");

    for (int i = 0; i < 3; i++) {
        sendData(&APB_bus, &data, i);
        prettyPrint(i, data, 1);
        data += INCREMENT;
    }

    print_uart0("\n");

    for (int i = 0; i < 3; i++) {
        readData(&APB_bus, &data, i);
        prettyPrint(i, data, 0);
        data += INCREMENT;
    }
}

#endif
