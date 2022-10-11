#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

#define output 1

void BUZZER_operate(u8 Port, u8 pin, u8 value)
{
	DIO_VidSetPinDirection(Port ,pin, output);
	
	DIO_VidSetPinValue( Port ,  pin , value);
	
	
}
