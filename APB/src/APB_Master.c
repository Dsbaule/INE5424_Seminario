#include "APB.h"
#include "APB_Master.h"

uint8_t currentState = 0;

uint8_t sendDataMaster(struct APB_Signals * APB_bus, uint32_t * data, uint32_t address) {
    switch (currentState) {
        case 0:
            APB_bus->PADDR = address;
            APB_bus->PWDATA = *data;
            APB_bus->PWRITE = 1;
            APB_bus->PSELx = 1;
            currentState = 1;
            return 0;
        case 1:
            APB_bus->PENABLE = 1;
            APB_bus->PREADY = 0;
            currentState = 2;
            return 0;
        case 2:
            if(APB_bus->PREADY) {
                APB_bus->PENABLE = 0;
                APB_bus->PSELx = 0;
                currentState = 0;
                return 1;
            }
            return 0;
    }
}

uint8_t readDataMaster(struct APB_Signals * APB_bus, uint32_t * data, uint32_t address) {
    switch (currentState) {
        case 0:
            APB_bus->PADDR = address;
            APB_bus->PWRITE = 0;
            APB_bus->PSELx = 1;
            currentState = 1;
            return 0;
        case 1:
            APB_bus->PENABLE = 1;
            APB_bus->PREADY = 0;
            currentState = 2;
            return 0;
        case 2:
            if(APB_bus->PREADY) {
                *data = APB_bus->PRDATA;
                APB_bus->PENABLE = 0;
                APB_bus->PSELx = 0;
                currentState = 0;
                return 1;
            }
            return 0;
    }
}
