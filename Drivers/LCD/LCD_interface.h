#ifndef LCD_interface
#define LCD_interface

void LCD_Init();
void LCD_Enable();
void LCD_Write(uint8_t DATA);
void LCD_Send_CMD(uint8_t CMD);
void LCD_Send_DATA(uint8_t DATA);
void LCD_Send_Char(uint8_t Char);
void LCD_Send_String(uint8_t *Str);
void LCD_Clear_Display();
void LCD_Clear_Write_String(uint8_t *Str);
void LCD_MoveCursor(uint8_t Row, uint8_t Col);


#endif
