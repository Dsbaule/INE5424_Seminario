#ifndef APB_MASTER_H
#define APB_MASTER_H

uint8_t sendDataMaster(struct APB_Signals * APB_bus, uint32_t * data, uint32_t address);
uint8_t readDataMaster(struct APB_Signals * APB_bus, uint32_t * data, uint32_t address);

#endif
