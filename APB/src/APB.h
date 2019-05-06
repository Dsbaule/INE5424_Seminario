#include <stdint.h>

struct APB_Signals
{
    uint32_t    PADDR;
    uint8_t     PSELx;
    uint8_t     PENABLE;
    uint8_t     PWRITE;
    uint32_t    PWDATA;
    uint8_t     PREADY;
    uint32_t    PRDATA;
    uint8_t     PSLVERR;
};
