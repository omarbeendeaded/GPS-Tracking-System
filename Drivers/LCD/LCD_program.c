#include <stdint.h>
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "../GPIO/GPIO_Interface.h"
#include "../GPIO/GPIO_Private.h"
#include "../SYSTICK/Systick_interface.h"
#include "../SYSTICK/Systick_private.h"

uint16_t i;
uint8_t CursorPosition;

void LCD_Enable(){
    GPIO_Write_Pin(LCD_CTRL_Port, E_Pin, High);
    Systick_Wait_1ms(1);
    GPIO_Write_Pin(LCD_CTRL_Port, E_Pin, Low);
    Systick_Wait_1ms(1);
}

void LCD_Write(uint8_t DATA){
    GPIO_Write_Port(LCD_DATA_Port, DATA&0xF0);
    LCD_Enable();
    GPIO_Write_Port(LCD_DATA_Port, (DATA&0x0F)<<4);
    LCD_Enable();
}

void LCD_Send_CMD(uint8_t CMD){
    GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Low); //RS=0 --> Write Command
    LCD_Write(CMD);
    Systick_Wait_1ms(10);
}

void LCD_Send_DATA(uint8_t DATA){
    GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,High); //RS=1 --> Write Data
    LCD_Write(DATA);
    Systick_Wait_1ms(10);
}

void LCD_Init(){
    Systick_Wait_1ms(30);
    GPIO_Port_Init(LCD_DATA_Port);
    LCD_Send_CMD(Four_BitMode);
    LCD_Send_CMD(LCD_EntryMode);
    LCD_Send_CMD(LCD_Clear);
    LCD_Send_CMD(LCD_DisplayOn);
    LCD_Send_CMD(First_Row);
}

void LCD_Send_Char(uint8_t Char){
    LCD_Send_DATA(Char);
}

void LCD_Send_String(uint8_t *Str){
  i = 0;
	while (Str[i] != '\0'){
		LCD_Send_DATA(Str[i]);
		i++;
	}
}

void LCD_Clear_Display(){ // Clears the screen
    LCD_Send_CMD(LCD_Clear);
	LCD_Enable();
}

void LCD_Clear_Write_String(uint8_t *Str){ // Clears the screen then writes on it
    LCD_Clear_Display();
    LCD_Send_String(Str);
}

void LCD_MoveCursor(uint8_t Row, uint8_t Col){
    GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Low); // RS=0

	CursorPosition = Col; // Starting position based on column
	if (Row == Row1) { // Set DDRAM address for the first row
		LCD_Send_CMD(LCD_SET_DDRAM_ADDR | (0x00 + CursorPosition));
		} 
        else if (Row == Row2) { // Set DDRAM address for the second row
		LCD_Send_CMD(LCD_SET_DDRAM_ADDR | (0x40 + CursorPosition));
	}
	LCD_Enable();
}
