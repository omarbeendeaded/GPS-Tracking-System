#include <stdint.h>
#include "driverlib/sysctl.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_PRIV.h"

void delay_ms(uint32_t ms) {
    SysCtlDelay((120000000 / 3 / 1000) * ms); 
}

void LCD_Enable(){
    MCAL_GPIO_Write_Pin(LCD_CTRL_Port, E_PIN, Pin_High);
    delay_ms(1);
    MCAL_GPIO_Write_Pin(LCD_CTRL_Port, E_PIN, Pin_Low);
    delay_ms(1);
}

void LCD_Write(uint8_t DATA){
    MCAL_GPIO_Write_Port(LCD_DATA_Port, DATA&0xF0);
    LCD_Enable();
    MCAL_GPIO_Write_Port(LCD_DATA_Port, (DATA&0x0F)<<4);
    LCD_Enable();
}

void LCD_Send_CMD(uint8_t CMD){
    MCAL_GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Pin_Low); //RS=0 --> Write Command
    LCD_Write(CMD);
    delay_ms(10);
}

void LCD_Send_DATA(uint8_t DATA){
    MCAL_GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Pin_High); //RS=1 --> Write Data
    LCD_Write(DATA);
    delay_ms(10);
}

void LCD_Init(){
    delay_ms(30);
    MCAL_GPIO_Init(LCD_DATA_Port);
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
    uint16_t i = 0;
	while (Str[i] != '\0'){
		LCD_Send_DATA(Str[i]);
		i++;
	}
}

void LCD_Clear(){ // Clears the screen
    LCD_Send_CMD(LCD_Clear);
	LCD_Enable();
}

void LCD_Clear_Write_String(uint8_t *Str){ // Clears the screen then writes on it
    LCD_Clear();
    LCD_Send_String(Str);
}

void LCD_MoveCursor(uint8_t Row, uint8_t Col){
    MCAL_GPIO_Write_Pin(LCD_CTRL_Port,RS_Pin,Pin_Low); // RS=0

	uint8_t CursorPosition = Col; // Starting position based on column
	if (Row == Row1) { // Set DDRAM address for the first row
		LCD_Send_CMD(LCD_SET_DDRAM_ADDR | (0x00 + CursorPosition));
		} 
        else if (Row == Row2) { // Set DDRAM address for the second row
		LCD_Send_CMD(LCD_SET_DDRAM_ADDR | (0x40 + CursorPosition));
	}
	LCD_Enable();
}
