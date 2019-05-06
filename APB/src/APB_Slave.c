#include "APB.h"
#include "APB_Slave.h"

int values[] = {0, 0, 0};

void runSlave(struct APB_Signals * APB_bus) {
    if (APB_bus->PENABLE && (APB_bus->PSELx == 1)) {
        if (APB_bus->PWRITE) {
            values[APB_bus->PADDR] = APB_bus->PWDATA;
            APB_bus->PREADY = 1;
        } else {
            APB_bus->PRDATA = values[APB_bus->PADDR];
            APB_bus->PREADY = 1;
        }
    }
}
