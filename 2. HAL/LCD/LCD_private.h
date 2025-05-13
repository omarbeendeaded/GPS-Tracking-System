#ifndef LCD_PRIV
#define LCD_PRIV



#define LCD_Clear            0x01          // replace all characters with ASCII 'space'
#define LCD_Home             0x02          // return cursor to first position on first line
#define LCD_EntryMode        0x06          // shift cursor from left to right on read/write
#define LCD_DisplayOff       0x08          // turn display off
#define LCD_DisplayOn        0x0F          // display on & cursor blink
#define Set5x7FontSize    	 0x20		   // set font size to 5x7
#define Four_BitMode	     0x28		   // select 4-bit mode
#define LCD_FunctionReset    0x30          // reset the LCD
#define First_Row            0x80          // set cursor position in first row
#define Second_Row           0xC0          // set cursor position in second row
#define CURSOR_OFF           0x0C		   // Cursor off
#define CURSOR_ON            0x0E		   // Cursor on


// for MoveCursor
#define Row1 0
#define Row2 1
#define LCD_SET_DDRAM_ADDR 0x80

#endif