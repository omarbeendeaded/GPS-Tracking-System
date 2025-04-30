#include "../UART/UART_interface.h"
#include "../UART/UART_private.h"
#include <string.h>
#include <stdlib.h>

char GPS_logName[] ="$GPRMC,";
char lat[15];
char longi[15];
char dummy;


void GPS_read(void){

char recievedChar ;
char flag ;
int i,counter1,counter2;
do{
	
	do{
		flag = 1 ;
		for(i=0 ; i<7 ;i++){
			
			if(UART_recByte() != GPS_logName[i]){
				flag = 0; 
				break ;
			 }
		 }
	}while(flag==0);

	do{
		recievedChar = UART_recByte();
		if ( (recievedChar == 'A') || (recievedChar == 'V') )
			flag=0;
	}while(flag==1);

	if (recievedChar == 'A'){
		flag=1; 
		dummy = UART_recByte(); 
	}
}while(flag==0);

for(counter1=0 ; counter1<15 ;counter1++){
	recievedChar = UART_recByte();
  if(recievedChar == ','){
		dummy = UART_recByte();
		dummy = UART_recByte();
		break ;
	}
  lat[counter1] = recievedChar;
 }

	for(counter2=0 ; counter2<15 ;counter2++){
	recievedChar = UART_recByte();
  if(recievedChar == ','){
		break;
	}
  longi[counter2] = recievedChar;
  }


}

float GPSlat(void){
	float x;
	x = atof(lat);
  return x;	
}

float GPSlong(void){
	float y;
  y = atof(longi);
  return y;	
}