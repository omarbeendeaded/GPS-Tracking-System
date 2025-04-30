#include <stdint.h>
#include "GPIO_Interface.h"
#include "GPIO_Interface.h"

int main(void) {
  
    GPIO_PortPin_Init(PORTF, 1);
    GPIO_Digital_PIN_MODE(PORTF, 1, OUTPUT, NoPull);

    

    while (1) {
       GPIO_Write_Pin(PORTF, 1, High);
    }

    return 0;
}
