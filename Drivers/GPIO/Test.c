#include <stdint.h>
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

void SystemInit(){};
int main(void) {
  
    GPIO_Port_Init(PORTF);
    GPIO_Digital_PIN_MODE(PORTF, PIN_1, OUTPUT, NoPull);

    

    while (1) {
       GPIO_Write_Pin(PORTF, 1, High);
    }

    return 0;
}
