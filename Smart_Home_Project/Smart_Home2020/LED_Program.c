#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

#define output 1

void LED_operate(u8 Port, u8 pin, u8 value)
{
	DIO_VidSetPinDirection(Port ,pin, output);
	
	DIO_VidSetPinValue(Port , pin, value);
	
	
}

void LED_Toggle(u8 Port , u8 pin)
{
	
	DIO_VidSetPinDirection(Port ,pin, output);
	
	 DIO_VidTogglePin(Port , pin);

}
