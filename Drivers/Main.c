#include "GPIO/GPIO_Interface.h"
#include "GPIO/GPIO_Private.h"
#include "SYSTICK/Systick_interface.h"
#include "SYSTICK/Systick_private.h"
#include "LCD/LCD_interface.h"
#include "LCD/LCD_private.h"
#include "UART/UART_interface.h"
#include "UART/UART_private.h"
#include "GPS/GPS.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define  EARTH_RADIUS 6371000.0000f
#define pi 3.14159265359f
#define red 1
#define yellow 2
 #define green 3


void SystemInit(){};

void int2str(uint32_t num, uint8_t* str) ;

///////////////////////////////////////////////// Buzzer OP  //////////////////////////////////////////////////////////////

void Buzzervoid_ON (uint8_t PORT, uint8_t PIN)
{
    GPIO_Port_Init(PORT); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, High);                                                     
}

void Buzzervoid_OFF (uint8_t PORT, uint8_t PIN)
{
    GPIO_Port_Init(PORT); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, Low);
}

///////////////////////////////////////////////// LED OP  //////////////////////////////////////////////////////////////
void LEDvoid_ON (uint8_t PORT, uint8_t PIN)
{
    GPIO_Port_Init(PORT); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, High);                                                     
}

void LEDvoid_OFF (uint8_t PORT, uint8_t PIN)
{
    GPIO_Port_Init(PORT); // select port: PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
                                                          // select pin: PIN_0 ....
                                                          // select mode: OUTPUT
                                                          // polarity: NoPull
    GPIO_Write_Pin(PORT, PIN, Low);
}


////////////////////////////////////////////////////////// Int to String //////////////////////////////////////////////////
void int2str(uint32_t num, uint8_t* str) {
	uint8_t buffer[16]; // Buffer to hold the reversed number
	uint32_t i = 0;
	uint32_t  j;

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
	str[i] = '\0'; // Null-terminate the string
}
	
///////////////////////////////////////////////// Distance Formatting  //////////////////////////////////////////////////////////////
   
float ToDegree (float angle){
	uint8_t temp[32];
	float minutes;
	uint32_t degree = (uint32_t)angle/100 ; 
	minutes = angle -(float)degree*100;

	return (degree + (minutes/60) );

}	


float ToRad(float angle){
	return angle * pi/180;
}
	
	// get angle from degree to rad 


double GetDistance (double currentLong,double currentLat, double destlong,double  destlat){
  uint8_t buf[32];
	uint8_t temp[32];
	double a;
	double c;
	
	double currentLongRad , currentLatRad,destlongRad, destlatRad, longDiff,latDiff;
	currentLongRad = ToRad(ToDegree(currentLong));
	currentLatRad = ToRad(ToDegree(currentLat));
	destlongRad = ToRad(ToDegree(destlong));
	destlatRad = ToRad(ToDegree(destlat));

	longDiff = fabs(destlongRad - currentLongRad) ;
	latDiff  = fabs(destlatRad - currentLatRad) ; 
	

	a = powf(sinf(latDiff/2.0),2)+ cosf(currentLatRad)*cosf(destlatRad)*powf(sinf(longDiff/2.0),2);// haversine formula a = sin2((qb-qa)/2)+ cos(qa)*cos(qb)*sin2((ib-ia)/2)
	
	c = 2*atanf(sqrtf(a)/sqrtf(1.0 - a));
	
	return fabs(EARTH_RADIUS * c) ; 
}


///////////////////////////////////////////////// Find The Closest Location ////////////////////////////////////////////////////////////

uint32_t compare_distance(double currentlong, double currentlat) {
		uint8_t buf[32];
    //double longitude[6] = {3003.82004, 3003.86237, 3003.93685, 3003.83299, 3003.90824,3003.84692};
    //double latitude[6] = {3116.70529, 3116.66735, 3116.70473, 3116.82818,3116.79777,3116.74445};
		double longitude[5] = {3003.86237, 3003.93685, 3003.82004, 3003.83299, 3003.90824};
    double latitude[5] = {3116.66735, 3116.70473, 3116.70529, 3116.82818,3116.79777};
    double min_distance = 20000000;
		double distance;
		uint32_t k, i=0 ;

    for ( k=0; k<5; k++) {
        distance = GetDistance (currentlong, currentlat, longitude[k], latitude[k]);
				distance = fabs(distance);

				if (min_distance > distance) {
					min_distance = distance;
				 i = k;
       }
    }
	return i; 
}


///////////////////////////////////////////////// Led Set On Distance //////////////////////////////////////////////////////////////

void Led_Set (double distance){
    if(distance >= 75 ) {
            LEDvoid_ON (PORTF, red); 
            LEDvoid_OFF (PORTF, yellow); 
            LEDvoid_OFF(PORTF, green);
            Buzzervoid_OFF(PORTE,5 );
    }
    else if (distance> 20 && distance<75) {
            LEDvoid_ON (PORTF, yellow); 
            LEDvoid_OFF (PORTF, red); 
            LEDvoid_OFF(PORTF, green);
            Buzzervoid_OFF(PORTE,5 );
    }
    else if (distance<=20){
						LEDvoid_ON (PORTF, green); 
            LEDvoid_OFF (PORTF, red); 
            LEDvoid_OFF(PORTF, yellow);
            Buzzervoid_ON (PORTE, 5);
    }
    }




///////////////////////////////////////////////// Main Program ////////////////////////////////////////////////////////////////////
int main(){
    double currentLat;
    double currentLong;
    double distance;
		uint32_t disss; 
		uint32_t k;
		uint8_t strDist[16];
    uint8_t location[5] = {0, 1, 2 , 3 , 4};
		uint8_t temp[32];
    double longitude[6] = {3003.86237, 3003.93685, 3003.82004, 3003.83299, 3003.90824};
    double latitude[6] = {3116.66735, 3116.70473, 3116.70529, 3116.82818,3116.79777};
		//double longitude[5] = {3003.82004, 3003.86237, 3003.93685, 3003.83299, 3003.90824};
    //double latitude[5] = {3116.70529, 3116.66735, 3116.70473, 3116.82818,3116.79777};
    double destlong;
    double destlat; 

    Systick_Init();
		LCD_Init();
		LCD_Send_String("Systick Init");
		LCD_Clear_Write_String("LCD Init");
		UART0_init();
    UART1_init();
		LCD_Clear_Write_String("GPS Init");
    while(1){
				GPS_read();
				longitude[5] = GPSlong();
        latitude[5] = GPSlat();
        k = compare_distance (latitude[5] , longitude[5]);
        destlong = longitude[0];
        destlat= latitude[0];
        //distance = GetDistance (destlong, destlat, 3116.74980, 3003.83220);
				distance = GetDistance (latitude[5],longitude[5], longitude[k],latitude[k]);
				Led_Set(distance);
				int2str((uint32_t)distance, strDist);

        switch (k){
					
            case 0 :
            LCD_Clear_Write_String("Civil Building");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 1 :
            LCD_Clear_Write_String("Fountain");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 2 :
            LCD_Clear_Write_String("Credit Building");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 3 :
            LCD_Clear_Write_String("Hall C/D");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break;
            case 4 :
            LCD_Clear_Write_String("Library");
            LCD_MoveCursor( Row2, 0 );
            LCD_Send_String(strDist);
            LCD_Send_String(" meters");
            break; }
			
		}
	
		
}

