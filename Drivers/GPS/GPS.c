#include "../UART/UART_interface.h"
#include "../UART/UART_private.h"
#include "../LCD/LCD_interface.h"
#include "../LCD/LCD_private.h"
#include <string.h>
#include <stdlib.h>

char GPS_logName[] ="$GPRMC,";
char lat[15];
char longi[15];
char dummy;


void GPS_read(void){
	char recievedChar;
	char flag;
	int i,counter1,counter2;
	
		UART0_sendByte('C');
	UART0_sendByte('o');
	UART0_sendByte('o');
	UART0_sendByte('r');
	UART0_sendByte('d');
	UART0_sendByte('s');
	UART0_sendByte(':');
	UART0_sendByte(' ');
	do{
		
		do{
			flag = 1 ;
			for(i=0 ; i<7 ;i++){
				
				if(UART1_recByte() != GPS_logName[i]){
					flag = 0; 
					break ;
				 }
			 }
		} while(flag==0);

		do {
			recievedChar = UART1_recByte();
			if ( (recievedChar == 'A') || (recievedChar == 'V') )
				flag=0;
		} while(flag==1);

		if (recievedChar == 'A'){
			flag = 1; 
			dummy = UART1_recByte(); 
		}
	} while(flag==0);

	
	for(counter1=0 ; counter1<15 ;counter1++){
		recievedChar = UART1_recByte();
		if(recievedChar == ','){
			dummy = UART1_recByte();
			dummy = UART1_recByte();
			break ;
		}
		lat[counter1] = recievedChar;
		UART0_sendByte(recievedChar);
	}
	
	UART0_sendByte(' ');

	for(counter2=0 ; counter2<15 ;counter2++){
		recievedChar = UART1_recByte();
		if(recievedChar == ','){
			break;
		}
		longi[counter2] = recievedChar;
		UART0_sendByte(recievedChar);
	}

	UART0_sendByte('\n');
	
	longi[counter2 - 1] = '\0';
	lat[counter1 - 1] = '\0';
}

float GPSlat(void){
	float x;
	//char* end;
	LCD_Clear_Write_String(lat);
	x = strtof(lat, NULL) / 100;
  return x;	
}

float GPSlong(void){
	float y;
	LCD_Clear_Write_String(longi);
  y = strtof(longi, NULL) / 100;
  return y;	
}