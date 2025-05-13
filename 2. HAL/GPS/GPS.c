#include "../../MCAL/SYSTICK/Systick_interface.h"
#include "../../MCAL/SYSTICK/Systick_private.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../MCAL/UART/UART_private.h"
#include "../LCD/LCD_interface.h"
#include "../LCD/LCD_private.h"
#include <string.h>
#include <stdlib.h>

uint8_t GPS_logName[] ="$GPRMC,";
uint8_t lat[32];
uint8_t longi[32];
uint8_t dummy;

void intTostr(uint32_t num, uint8_t* str) {
	uint8_t buffer[32]; // Buffer to hold the reversed number
	uint32_t i = 0;
	uint32_t j;

	// Handle the case when the number is 0
	if (num == 0) {
		str[i++] = '0';
		} else {
		// Convert the number to string in reverse order
		while (num > 0) {
			buffer[i++] = (num % 10) + '0'; // Get the last digit and convert to ASCII
			num /= 10;
		}
	}

	// Reverse the string
	for (j = 0; j < i; j++) {
		str[j] = buffer[i - j - 1];
	}
	str[i] = '\0'; // Null-terminate�the�string
}

void GPS_read(void){
	uint8_t recievedChar;
	uint8_t flag;
	uint32_t i,counter1,counter2;
	
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

	
	for(counter1=0 ; counter1<32 ;counter1++){
		recievedChar = UART1_recByte();
		if(recievedChar == ','){
			dummy = UART1_recByte();
			dummy = UART1_recByte();
			break ;
		}
		lat[counter1] = recievedChar;
	}
	

	for(counter2=0 ; counter2 < 32 ;counter2++){
		recievedChar = UART1_recByte();
		if(recievedChar == ','){
			break;
		}
		longi[counter2] = recievedChar;
	}

	
	longi[counter2] = '\0';
	lat[counter1] = '\0';
	
	
}




float GPSlong(void){
	float y;
	int i;
	for (i = 0; i < 32; i++) {
		if (longi[i] != '\0') UART0_sendByte(longi[i]);
	  else break;
	}
	UART0_sendByte(' ');
  y = strtof(longi+1, NULL) ;
  return y;	
}

float GPSlat(void){
	int i;
	float x;
	for (i = 0; i < 32; i++) {
		if (lat[i] != '\0') UART0_sendByte(lat[i]);
		else break;
	}
	UART0_sendByte(' ');
	x = strtof(lat, NULL );

	return x;	
}