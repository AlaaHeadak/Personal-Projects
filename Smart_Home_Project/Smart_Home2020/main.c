/*
 * main.c
 *
 *  Created on: Nov 29, 2020
 *      Author: LENOVO
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "LCD_Interface.h"
#include "KPD_Interface.h"
#include "LDR_Interface.h"
#include "TEMP_Interface.h"
#include "LED_Interface.h"
#include "BUZ_Interface.h"
#include "USART_Interface.h"
#include "TIMER1_Interface.h"
#include <avr/io.h>



void main(void)

{
	char Passward 	      = 1234;
	char msg[] 	      = "Enter your ID:";
	char Stop[] 	      = "3-Stop";
	char TEMP[] 	      = "1-Temp";
	char LDR[] 	      = "2-LDR";
	char error[] 	      = "Error!";
	char welcome[] 	      = "welcome!";
	char no_more_trials[] = "System Reset";
	int error_counter = 0, digit_counter = 0;
	u8 key=0;
	u8 pressedkey = 0;
	u8 Flag_correct = 0;
	u8 operation;
	u8 temp;
	u8 ldr;


	LCD_VidInt();
	KPD_VidInit();
	while (1){

		LCD_Clear();
		while (error_counter < 3 && Flag_correct == 0){
			LCD_VidSetPosition(0, 0);
			LCD_VidWriteString(&msg);
			LCD_VidSetPosition(1, 0);
			//_delay_ms(10000);
			digit_counter=0;
			pressedkey=0;
			while(digit_counter<4){
				key = KPD_U8GetPressedKey();
				if (key != 0){
					if (key >= 48 && key <= 57){
						key= key-48; //instead of switch case
						LCD_VidWriteData(key+48);
						pressedkey = pressedkey * 10 + key;
						_delay_ms(2000);
						digit_counter++;
					}
				}
				else{

				}

			}
			if (Passward == pressedkey){
				_delay_ms(5000);
				LCD_Clear();
				_delay_ms(5000);
				LCD_VidWriteString(&welcome);
				Flag_correct = 1;
			}
			else{
				_delay_ms(5000);
				LCD_Clear();
				_delay_ms(5000);
				LCD_VidWriteString(&error);
				error_counter++;
				Flag_correct = 0;
			}

		}
		if((error_counter >= 3) && (Flag_correct== 0)){
			_delay_ms(5000);
			LCD_Clear();
			_delay_ms(5000);
			LCD_VidWriteString(&no_more_trials);

		}
		else if ((error_counter <3) && (Flag_correct == 1)){
			_delay_ms(5000);
			LCD_Clear();
			_delay_ms(5000);
			LCD_VidSetPosition(0, 0);
			LCD_VidWriteString(&TEMP);
			LCD_VidSetPosition(0, 8);
			LCD_VidWriteString(&LDR);
			LCD_VidSetPosition(1, 3);
			LCD_VidWriteString(&Stop);
			_delay_ms(5000);
			operation = KPD_U8GetPressedKey();
			if(operation!=0){
				switch (operation){
					case '1':
						LCD_Clear();
						temp = TEMP_Read(1);
						LCD_VidWriteData(temp);
						break;

					case '2':
						LCD_Clear();
						ldr = LDR_Read(0);
						LCD_VidWriteData(LDR);
						break;

					case '3':
						LCD_Clear();
						break;
				}
			}
		}
	}


}


