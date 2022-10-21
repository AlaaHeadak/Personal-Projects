/*
 * GPIO_Program.c
 *
 *  Created on: Oct 19, 2022
 *      Author: LENOVO
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Configuration.h"
#include "GPIO_prv.h"


void MGPIO_vSetPinMode(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8Mode)
{
	switch(A_u8PortId)
		{
		case GPIO_PORTA:
			//clearing the destined 2 bits
			GPIOA->MODER &= ~(0b11<<(A_u8PinNo*2));
			//writing the mode on those 2 bits after clearing
			GPIOA->MODER |= (A_u8Mode<<(A_u8PinNo*2));

			break;

		case GPIO_PORTB:
			GPIOB->MODER &= ~(0b11<<(A_u8PinNo*2));
			GPIOB->MODER |= (A_u8Mode<<(A_u8PinNo*2));

			break;

		case GPIO_PORTC:
			GPIOC->MODER &= ~(0b11<<(A_u8PinNo*2));
			GPIOC->MODER |= (A_u8Mode<<(A_u8PinNo*2));

			break;
}
}

void MGPIO_vSetPinOutputType(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8OutType)
{
	if(A_u8OutType == GPIO_OPENDRAIN)
		{
			switch(A_u8PortId)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->OTYPER, A_u8PinNo);
				break;

			case GPIO_PORTB:
				SET_BIT(GPIOB->OTYPER, A_u8PinNo);
				break;

			case GPIO_PORTC:
				SET_BIT(GPIOC->OTYPER, A_u8PinNo);
				break;
			}

		}
		else if(A_u8OutType == GPIO_PUSHPULL)
		{
			switch(A_u8PortId)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIOA->OTYPER, A_u8PinNo);
				break;
			case GPIO_PORTB:
				CLR_BIT(GPIOB->OTYPER, A_u8PinNo);
				break;
			case GPIO_PORTC:
				CLR_BIT(GPIOC->OTYPER, A_u8PinNo);
				break;
			}
		}
}

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8OutSpeed)
{
	switch(A_u8PortId)
			{
			case GPIO_PORTA:
				//clearing the destined 2 bits
				GPIOA->OSPEEDR &= ~(0b11<<(A_u8PinNo*2));
				//writing the mode on those 2 bits after clearing
				GPIOA->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));

				break;

			case GPIO_PORTB:
				GPIOB->OSPEEDR &= ~(0b11<<(A_u8PinNo*2));
				GPIOB->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));

				break;

			case GPIO_PORTC:
				GPIOC->OSPEEDR &= ~(0b11<<(A_u8PinNo*2));
				GPIOC->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));

				break;
	}

}

void MGPIO_vSetPinInputPull(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8PullType)
{
	switch(A_u8PortId)
				{
				case GPIO_PORTA:
					//clearing the destined 2 bits
					GPIOA->PUPDR &= ~(0b11<<(A_u8PinNo*2));
					//writing the mode on those 2 bits after clearing
					GPIOA->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));

					break;

				case GPIO_PORTB:
					GPIOB->PUPDR &= ~(0b11<<(A_u8PinNo*2));
					GPIOB->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));

					break;

				case GPIO_PORTC:
					GPIOC->PUPDR &= ~(0b11<<(A_u8PinNo*2));
					GPIOC->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));

					break;
		}


}

u8   MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo)
{
	u8 L_u8PinValue = 0;
		switch(A_u8PortId)
		{
		case GPIO_PORTA:
			L_u8PinValue = GET_BIT(GPIOA->IDR, A_u8PinNo);
			 break;
		case GPIO_PORTB:
			L_u8PinValue = GET_BIT(GPIOB->IDR, A_u8PinNo);
			 break;
		case GPIO_PORTC:
			L_u8PinValue = GET_BIT(GPIOC->IDR, A_u8PinNo);
			 break;
		}

		return L_u8PinValue;

}

void MGPIO_vSetPinVal(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinVal)
{
	if(A_u8PinVal == GPIO_HIGH)
		{
			switch(A_u8PortId)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->ODR,A_u8PinNo );
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->ODR,A_u8PinNo );
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->ODR,A_u8PinNo );
				break;
			}
		}
		else if(A_u8PinVal == GPIO_LOW)
		{
			switch(A_u8PortId)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIOA->ODR,A_u8PinNo );
				break;
			case GPIO_PORTB:
				CLR_BIT(GPIOB->ODR,A_u8PinNo );
				break;
			case GPIO_PORTC:
				CLR_BIT(GPIOC->ODR,A_u8PinNo );
				break;
			}

		}

}

void MGPIO_vSetPinVal_fast(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinVal)
{
	if(A_u8PinVal == GPIO_HIGH)
			{
				switch(A_u8PortId)
				{
				case GPIO_PORTA:
					SET_BIT(GPIOA->BSRR,A_u8PinNo );
					break;
				case GPIO_PORTB:
					SET_BIT(GPIOB->BSRR,A_u8PinNo );
					break;
				case GPIO_PORTC:
					SET_BIT(GPIOC->BSRR,A_u8PinNo );
					break;
				}
			}
			else if(A_u8PinVal == GPIO_LOW)
			{
				switch(A_u8PortId)
				{
				case GPIO_PORTA:
					CLR_BIT(GPIOA->BSRR,A_u8PinNo );
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->BSRR,A_u8PinNo );
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->BSRR,A_u8PinNo );
					break;
				}

			}


}

void MGPIO_vSetAlternativeFunction(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8AltFun)
{
}
