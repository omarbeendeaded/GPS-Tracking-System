
#include <stdint.h>
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

void SystemInit(){};
int main(void) {
  
    GPIO_Port_Init(PORTF);
	  GPIO_Port_Init(PORTB);    

    while (1) {
     GPIO_Write_Pin(PORTF, PIN_2, High);
		 if (GPIO_Read_pin(PORTF,PIN_2)){
				GPIO_Write_Pin(PORTF, PIN_3, High);
		 }
    }

    return 0;
}
