#include <stdint.h>
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "../GPIO/GPIO_Interface.h"
#include "../GPIO/GPIO_Private.h"
#include "../SYSTICK/Systick_interface.h"
#include "../SYSTICK/Systick_private.h"

void SystemInit(){};

int main(){
	Systick_Init();
	while (1) {
		LCD_Init();
		LCD_Send_Char('A');
	}
	
}