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
	LCD_Init();
	//LCD_Send_Char(0);
	//LCD_Send_Char('B');
	LCD_Send_String("First Row");
	LCD_MoveCursor(Row2,0);
	LCD_Send_String("Second Row");
	while (1) {
		//LCD_Send_Char('A');
		//Systick_Wait_1ms(1000);
		//LCD_Clear_Display();
		//Systick_Wait_1ms(1000);
		//LCD_Send_Char('B');
		//LCD_Send_Char('C');
	}
	
}