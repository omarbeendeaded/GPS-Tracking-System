
#include <stdint.h>
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/GPIO/GPIO_Private.h"
#include "../../MCAL/SYSTICK/Systick_interface.h"
#include "../../MCAL/SYSTICK/Systick_private.h"




void LCD_Enable(){
    GPIO_Write_Pin(LCD_CTRL_Port, E_Pin, High);
    Systick_Wait_1us(10);
    GPIO_Write_Pin(LCD_CTRL_Port, E_Pin, Low);
    //Systick_Wait_1us(1);
} 
void LCD_Write(uint8_t DATA) {
    // Send higher nibble (bits 7–4) 0100
    GPIO_Write_Pin(LCD_DATA_Port, PIN_4, (DATA >> 4) & 0x01);
    GPIO_Write_Pin(LCD_DATA_Port, PIN_5, (DATA >> 5) & 0x01);
    GPIO_Write_Pin(LCD_DATA_Port, PIN_6, (DATA >> 6) & 0x01);
    GPIO_Write_Pin(LCD_DATA_Port, PIN_7, (DATA >> 7) & 0x01);
		//LCD_DATA_Port &= 0xF0;
    LCD_Enable();
	
    // Send lower nibble (bits 3–0)
    GPIO_Write_Pin(LCD_DATA_Port, PIN_4, (DATA >> 0) & 0x01);
    GPIO_Write_Pin(LCD_DATA_Port, PIN_5, (DATA >> 1) & 0x01);
    GPIO_Write_Pin(LCD_DATA_Port, PIN_6, (DATA >> 2) & 0x01);
    GPIO_Write_Pin(LCD_DATA_Port, PIN_7, (DATA >> 3) & 0x01);
    LCD_Enable();
} 
/*
void LCD_Write(uint8_t DATA){
    GPIO_Write_Port(LCD_DATA_Port, DATA&0xF0);
    LCD_Enable();
    GPIO_Write_Port(LCD_DATA_Port, (DATA&0x0F)<<4);
    LCD_Enable();
}*/

void LCD_Send_CMD(uint8_t CMD){
    GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Low); //RS=0 --> Write Command
    LCD_Write(CMD);
    Systick_Wait_1us(100);
}

void LCD_Send_DATA(uint8_t DATA){
    GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,High); //RS=1 --> Write Data
    LCD_Write(DATA);
    Systick_Wait_1us(100);
}

void LCD_Init(){
    GPIO_Port_Init(LCD_DATA_Port);
		GPIO_Port_Init(LCD_CTRL_Port);
	  Systick_Wait_1ms(30);
		LCD_Send_CMD(0x30);
		Systick_Wait_1ms(5);
		LCD_Send_CMD(0x30);
		Systick_Wait_1ms(1);
		LCD_Send_CMD(0x30);
		Systick_Wait_1ms(20);
		LCD_Send_CMD(0x20);
		Systick_Wait_1ms(20);
	
    //LCD_Send_CMD(Four_BitMode);
		LCD_Send_DATA(0x02);
		LCD_Enable();
		LCD_Send_DATA(0x20);
		LCD_Enable();
		LCD_Send_DATA(0x80);
		LCD_Enable();
		Systick_Wait_1us(40);
	
		LCD_Send_CMD(LCD_DisplayOn);
		Systick_Wait_1us(40);
    LCD_Send_CMD(LCD_Clear);
    Systick_Wait_1ms(2);
		LCD_Send_CMD(LCD_EntryMode);
    //LCD_Send_CMD(First_Row);
}

void LCD_Send_Char(uint8_t Char){
    LCD_Send_DATA(Char);
}

void LCD_Send_String(uint8_t *Str){
	uint16_t i;
  i = 0;
	while (Str[i] != '\0'){
		LCD_Send_DATA(Str[i]);
		i++;
	}
}

void LCD_Clear_Display(){ // Clears the screen
    LCD_Send_CMD(LCD_Clear);
		Systick_Wait_1ms(2);
		//LCD_Enable();
}

void LCD_Clear_Write_String(uint8_t *Str){ // Clears the screen then writes on it
    LCD_Clear_Display();
    LCD_Send_String(Str);
}

void LCD_MoveCursor(uint8_t Row, uint8_t Col){
		uint8_t CursorPosition;
    GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Low); // RS=0

	CursorPosition = Col; // Starting position based on column
	if (Row == Row1) { // Set DDRAM address for the first row
		LCD_Send_CMD(LCD_SET_DDRAM_ADDR | (0x00 + CursorPosition));
		} 
        else if (Row == Row2) { // Set DDRAM address for the second row
		LCD_Send_CMD(LCD_SET_DDRAM_ADDR | (0x40 + CursorPosition));
	}
	//LCD_Enable();
}
