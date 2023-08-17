/******************************************************************************
 *
 * FILE NAME: app.c
 *
 * AUTHOR: Ahmed Gamal Helmy
 *
 * DESCRIPTION: source file for application
 *
 *******************************************************************************/



#include "app.h"


int main (void){
	uint16 distance;
	/************************Enable I bit *************************************/
	SREG |=(1<<7);
	/***********************initialize LCD and UlteraSonic ********************/
	LCD_init();
	Ultrasonic_init();

	/*****************************DISPLAY "DISTANCE"***************************/
	LCD_displayStringRowColumn(1,0,"Distance = ");

	while (1){
        /**********************read distance from ultrasonic*********************/
		distance=Ultrasonic_readDistance() ;
	    /*******************display distance from ultrasonic*********************/
		LCD_moveCursor(1,11);
		LCD_intgerToString(distance);
		if(distance<100)
		{
			LCD_displayCharacter(' ');
		}

	}
}
