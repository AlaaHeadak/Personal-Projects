
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"


void LCD_VidInt(void)
{
	DIO_VidSetPortDirection(2 ,0b11111111);
	DIO_VidSetPinDirection(3 , 0 , 1);
	DIO_VidSetPinDirection(3 , 1 , 1);
	DIO_VidSetPinDirection(3 , 2 , 1);
	_delay_ms(50);             // wait more than 30 ms
	LCD_VidWriteCommand(0b00111000);  // funcion set : use 8 pins mode,use 2 lines , font
	_delay_ms(1);             // wait more than 30 micro s
	LCD_VidWriteCommand(0b00001100);  // display on \off control  : turn desplay on,off the curser,off curser blinking
	_delay_ms(1);             // wait more than 30 micro s
	LCD_VidWriteCommand(0b00000001);  // display clear 
	_delay_ms(2);             // wait more than 1.7 m s
	
}

void LCD_VidSetPosition(u8 Row, u8 Col)
{
	if (Row==0)
	{
		LCD_VidWriteCommand(128+Col);
	}
	if (Row==1)
	{
		LCD_VidWriteCommand(128+64+Col);
	}
}

void LCD_VidWriteData(u8 Data)
{
	 DIO_VidSetPinValue(3 , 0 , 1);     //RS = 1 to select data
	 DIO_VidSetPinValue(3 , 1 , 0);     //Rw = 0 to write data
	 DIO_VidSetPortValue(2 , Data);		// PORTC = Data
	
	// enable
	DIO_VidSetPinValue(3 , 2 , 1);     //enable = 1 
	_delay_ms(1);
	DIO_VidSetPinValue(3 , 2 , 0);     //enable = 0 
	_delay_ms(1);
}

void LCD_VidWriteCommand(u8 Command)
{
	 DIO_VidSetPinValue(3 , 0 , 0);     //RS = 0 to select command
	 DIO_VidSetPinValue(3 , 1 , 0);     //Rw = 0 to write command
	 DIO_VidSetPortValue(2 , Command);		// PORTC = Command
	
	// enable
	DIO_VidSetPinValue(3 , 2 , 1);     //enable = 1 
	_delay_ms(1);
	DIO_VidSetPinValue(3 , 2 , 0);     //enable = 0 
	_delay_ms(1);
}
void LCD_Clear()
{
	LCD_VidWriteCommand (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_VidWriteCommand (0x80);		/* Cursor at home position */
}


void LCD_VidWriteString(u8 *StringOfCharacters)
{
while(*StringOfCharacters > 0)
{
	LCD_VidWriteData(*StringOfCharacters++);
}
}


void LCD_VidWriteNum(u16 num)
{
	u8 rev=0;
	u8 rem=0;
	u8 i=0;
	u8 zero_flag=0;
	while(num >0)
	{
		 rem= num % 10;
		 if (rem==0){
			 zero_flag++;
		 }
		 rev =rev*10+rem;
		num/=10;
		}
	while(rev >1)
	{
		 rem= rev % 10;
		 LCD_VidWriteData(rem+48);
		rev/=10;
		for(i=0;i<zero_flag;i++){
			LCD_VidWriteData(0+48);
		}
		}
}

