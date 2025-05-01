
#include <stdint.h>
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

void SystemInit(){};
int main(void) {
  
    GPIO_Port_Init(PORTF);
	GPIO_Port_Init(PORTC);    

    while (1) {
			GPIO_Write_Port(PORTF,0x0C);
     //GPIO_Write_Pin(PORTF, PIN_2, High);
	   //GPIO_Write_Pin(PORTF, PIN_3, High);
	   GPIO_Write_Pin(PORTC, PIN_7, High);
    }

    return 0;
}
