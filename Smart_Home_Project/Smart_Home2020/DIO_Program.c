#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"

void DIO_VidSetPinDirection(u8 Port , u8 Pin_Num , u8 State)
{
	if (State == 1)  //direction is output
	{
		switch(Port)
		{
			case 0: SET_BIT(DDRA,Pin_Num);  break;
			case 1: SET_BIT(DDRB,Pin_Num);  break;
			case 2: SET_BIT(DDRC,Pin_Num);  break;
			case 3: SET_BIT(DDRD,Pin_Num);  break;
		}
	}
	else if (State == 0)
	{
		switch(Port)
		{
			case 0: CLR_BIT(DDRA,Pin_Num);  break;
			case 1: CLR_BIT(DDRB,Pin_Num);  break;
			case 2: CLR_BIT(DDRC,Pin_Num);  break;
			case 3: CLR_BIT(DDRD,Pin_Num);  break;
		}
	}
}


void DIO_VidSetPinValue(u8 Port , u8 Pin_Num , u8 Value)
{
	if (Value == 1)  //value is true
	{
		switch(Port)
		{
			case 0: SET_BIT(PORTA,Pin_Num);  break;
			case 1: SET_BIT(PORTB,Pin_Num);  break;
			case 2: SET_BIT(PORTC,Pin_Num);  break;
			case 3: SET_BIT(PORTD,Pin_Num);  break;
		}
	}
	else if (Value == 0)	
	{
		switch(Port)
		{
			case 0: CLR_BIT(PORTA,Pin_Num);  break;
			case 1: CLR_BIT(PORTB,Pin_Num);  break;
			case 2: CLR_BIT(PORTC,Pin_Num);  break;
			case 3: CLR_BIT(PORTD,Pin_Num);  break;
		}
	}
	
}


void DIO_VidSetPortDirection(u8 Port , u8 Direction)
{
		switch(Port)
		{
			case 0: DDRA= Direction;  break;
			case 1: DDRB= Direction;  break;
			case 2: DDRC= Direction;  break;
			case 3: DDRD= Direction;  break;
		}		
}
void DIO_VidSetPortValue(u8 Port , u8 Value)
{
	switch(Port)
	{
		case 0: PORTA= Value;  break;
		case 1: PORTB= Value;  break;
		case 2: PORTC= Value;  break;
		case 3: PORTD= Value;  break;
	}
}
u8 DIO_U8GetPinValue( u8 port , u8 pin )
{
	u8 x;
	switch (port)
	{
	case 0 : x =GET_BIT(PINA,pin); break;
	case 1 : x =GET_BIT(PINB,pin); break;
	case 2 : x =GET_BIT(PINC,pin); break;
	case 3 : x =GET_BIT(PIND,pin); break;
	}
	return x;

}

void DIO_VidTogglePin(u8 Port , u8 Pin)
{
	switch(Port)
	{
		case 0: TOGGLE_BIT(PORTA,Pin);  break;
		case 1: TOGGLE_BIT(PORTB,Pin);  break;
		case 2: TOGGLE_BIT(PORTC,Pin);  break;
		case 3: TOGGLE_BIT(PORTD,Pin);  break;
	}
}
