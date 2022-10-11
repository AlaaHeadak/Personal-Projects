#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_Config.h"
#include "avr/delay.h"


	u8 KPD_Number[4][4]={ {'1','2','3','4'},
	{'5','6','7','8'},
	{'9','=','+','-'},
	{'/','*','0','C'}
	};




void KPD_VidInit(void)
{
	// set intput pins direction
	DIO_VidSetPinDirection(KPD_PORT,ROW0,0);
	DIO_VidSetPinDirection(KPD_PORT,ROW1,0);
	DIO_VidSetPinDirection(KPD_PORT,ROW2,0);
	DIO_VidSetPinDirection(KPD_PORT,ROW3,0);
	// set output pins direction
	DIO_VidSetPinDirection(KPD_PORT,COL0,1);
	DIO_VidSetPinDirection(KPD_PORT,COL1,1);
	DIO_VidSetPinDirection(KPD_PORT,COL2,1);
	DIO_VidSetPinDirection(KPD_PORT,COL3,1);

	DIO_VidSetPortValue(KPD_PORT,0b11111111);
}


u8 KPD_U8GetPressedKey(void)
{
	u8 col=0;
	u8 row=0;
	u8 x=KEY_NOT_PRESSED;

	// the outer for loop for col
	for (col=4; col<8; col++)
	{
		DIO_VidSetPinValue(KPD_PORT,col,0);
		for (row=0;row<4;row++)
		{
			if (DIO_U8GetPinValue(KPD_PORT,row)==0)
			{
				x= KPD_Number[row][col-4];
				while (DIO_U8GetPinValue(KPD_PORT,row)==0);
				_delay_ms(2);
			}
		}
		DIO_VidSetPinValue(KPD_PORT,col,1);
	}
	return x;
}
