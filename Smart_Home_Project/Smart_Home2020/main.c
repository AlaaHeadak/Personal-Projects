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
	char Door[] 	      = "3Door";
	char TEMP[] 	      = "1Temp";
	char LDR[] 	      = "2LDR";
	char Servo[] 	      = "4Servo";
	char error[] 	      = "Wrong ID";
	char welcome[] 	      = "welcome!";
	char no_more_trials[] = "No more trials";
	int error_counter = 0, digit_counter = 0;
	u8 key=0;
	u8 pressedkey = 0;
	u8 Flag_correct = 0;
	u8 Operation_Chosen=0;
	u8 flag_error=0;
	u8 operation;
	u8 temper;
	u8 ldr;
	u8 flag=0;
	u8 light;
	u8 name=0;
	u8 flag_name=0;





	LCD_VidInt();
	KPD_VidInit();
	ADC_Init();
	TIMER1_VidInit();
	UART_VidInit();
	DIO_VidSetPinDirection(1,0,1);
				DIO_VidSetPinDirection(1,1,1);
				DIO_VidSetPinDirection(1,2,1);
				DIO_VidSetPinDirection(1,3,1);
				DIO_VidSetPinDirection(1,4,1);
				DIO_VidSetPinDirection(1,5,1);
				DIO_VidSetPinDirection(1,6,1);
				DIO_VidSetPinDirection(1,7,1);
				DIO_VidSetPortValue(1,0b00111111);
	while (1)

	{
		LCD_Clear();
		while(name<4)
		{

			LCD_VidSetPosition(0, 0);
			LCD_VidWriteString("Enter your name");
			name= UART_u8Receive();
			UART_VidSendData(name);
			LCD_VidSetPosition(1, 0);
			LCD_VidWriteData(name);
			name++;
			_delay_ms(4000);

		}
		while (error_counter < 3 && Flag_correct == 0 && flag_error==0)
		{
			LCD_Clear();
			LCD_VidSetPosition(0, 0);
			LCD_VidWriteString(&msg);
			LCD_VidSetPosition(1, 0);
			//_delay_ms(10000);
			digit_counter=0;
			pressedkey=0;
			while(digit_counter<4)
			{
				//key = KPD_U8GetPressedKey();
				key=	UART_u8Receive();
				UART_VidSendData(key);
				if (key != 0)
				{
					if (key >= 48 && key <= 57)
					{
						key= key-48; //instead of switch case
						LCD_VidWriteData(key+48);
						pressedkey = pressedkey * 10 + key;
						_delay_ms(2000);
						digit_counter++;
					}
				}
			}
			if (Passward == pressedkey)
			{
				_delay_ms(5000);
				LCD_Clear();
				_delay_ms(5000);
				LCD_VidWriteString(&welcome);
				Flag_correct = 1;
				flag_error=1;
			}
			else if (Passward != pressedkey && flag_error==0)
			{



				_delay_ms(5000);
				LCD_Clear();
				_delay_ms(5000);
				DIO_VidSetPinValue(3,6,1);
				LCD_VidWriteString(&error);
				error_counter++;
				Flag_correct = 0;
				u8 num[4]={0b00111111,0b00000110,0b01011011,0b01001111};
				DIO_VidSetPortValue(1,num[error_counter]);
				_delay_ms(4000);


			}
		}
		if((error_counter >= 3) && (Flag_correct== 0) &&(flag==0))
		{
			DIO_VidSetPinDirection(3,6,1);
			DIO_VidSetPinValue(3,6,1);
			_delay_ms(5000);
			LCD_Clear();
			_delay_ms(5000);
			LCD_VidWriteString(&no_more_trials);
			_delay_ms(5000);


		}


		 if ((error_counter <3) && (Flag_correct == 1))
		{
			_delay_ms(5000);
			LCD_Clear();
			_delay_ms(5000);
			LCD_VidSetPosition(0, 0);
			LCD_VidWriteString(&TEMP);
			LCD_VidSetPosition(0, 8);
			LCD_VidWriteString("2Light");
			LCD_VidSetPosition(1, 0);
			LCD_VidWriteString("3Door");
			LCD_VidSetPosition(1, 6);
			LCD_VidWriteString(&Servo);
			LCD_VidSetPosition(1, 12);
			LCD_VidWriteString("5LDR");
			_delay_ms(5000);
			Flag_correct =0;
			flag=1;
		}


		while(Operation_Chosen !=1 && flag==1)
		{
			//operation = KPD_U8GetPressedKey();
//			operation = UART_u8Receive();
//			UART_VidSendData(operation);
			if(operation!=0)
			{
				if (operation >= 48 && operation <= 57)
									{
					operation= operation-48; //instead of switch case
										LCD_VidWriteData(operation+48);
										pressedkey = pressedkey * 10 + key;
										_delay_ms(2000);

									}

				operation = UART_u8Receive();
				UART_VidSendData(operation);

				switch (operation)
				{
					case '1':
						LCD_Clear();
						while (1)
						{
						LCD_VidSetPosition(0, 0);
						LCD_VidWriteString("temper = ");
						temper = TEMP_Read(0);
						LCD_VidWriteData(temper);
						_delay_ms(3000);
						if(temper>=30)
						{
							DIO_VidSetPinDirection(3,6,1);
							DIO_VidSetPinValue(3,6,1);

						}
						else
						{
							DIO_VidSetPinDirection(3,6,1);
							DIO_VidSetPinValue(3,6,0);

						}
						}

						break;

					case '2':
						LCD_Clear();
						LCD_VidSetPosition(0, 0);
						LCD_VidWriteString("Light on/of");
						DIO_VidSetPinDirection(3,7,1);
						while (1)
					{
							light= UART_u8Receive();
							UART_VidSendData(light);
							if (light=='a')
							{
								DIO_VidSetPinValue(3,7,1);
							}
							else if (light=='b')
							{
								DIO_VidSetPinValue(3,7,0);
							}
						}
						break;
					case '3':
						LCD_Clear();
						LCD_VidSetPosition(0, 0);
						DIO_VidSetPinDirection(0,2,1);
						DIO_VidSetPinDirection(0,3,1);

						while (1)
						{
						LCD_Clear();
						LCD_VidWriteString("Safety Door");

						DIO_VidSetPinValue(0,2,1);
						_delay_ms(3000);

						DIO_VidSetPinValue(0,2,0);
						_delay_ms(3000);

						DIO_VidSetPinValue(0,3,1);
						_delay_ms(3000);

						DIO_VidSetPinValue(0,3,0);
						_delay_ms(3000);


						}
						break;
					case '4':
						LCD_Clear();
						DIO_VidSetPinDirection(3,5,1);
						while(1)
						{
						LCD_Clear();
						LCD_VidWriteString("Servo Motor");

							TIMER1_Set_Duty(31);
							_delay_ms(1000);

							TIMER1_Set_Duty(62);
							_delay_ms(1000);

							TIMER1_Set_Duty(100);
							_delay_ms(1000);
						}
						break;

					case '5':
						LCD_Clear();
						LCD_VidSetPosition(0, 0);
						LCD_VidWriteString("LDR = ");
						while (1)
						{
						ldr = ADC_ReadValue(1);
						LCD_VidWriteNum(ldr);
						_delay_ms(3000);
						}
						break;

				}

			}
		}
	}


}
