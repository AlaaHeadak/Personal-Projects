/*
 * GPIO_init.h
 *
 *  Created on: Oct 19, 2022
 *      Author: LENOVO
 */

#ifndef ARM_MCAL_GPIO_GPIO_INTERFACE_H_
#define ARM_MCAL_GPIO_GPIO_INTERFACE_H_


#define GPIO_MODE_INPUT                0b00
#define GPIO_MODE_OUTPUT               0b01
#define GPIO_MODE_Alternate_function   0b10
#define GPIO_MODE_Analog               0b11


#define GPIO_LOW_SPEED                    0b00
#define GPIO_MEDIUM_SPEED                 0b01
#define GPIO_HIGH_SPEED                   0b10
#define GPIO_VERY_HIGH_SPEED              0b11

#define GPIO_NO_PULL_UP_DOWN              0b00
#define GPIO_PULL_UP                      0b01
#define GPIO_PULL_DOWN                    0b10

#define GPIO_HIGH 1
#define GPIO_LOW  0

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_OPENDRAIN 1
#define GPIO_PUSHPULL 0


void MGPIO_vSetPinMode(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8Mode);

void MGPIO_vSetPinOutputType(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8OutType);

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8OutSpeed);

void MGPIO_vSetPinInputPull(u8 A_u8PortId,u8 A_u8PinNo ,u8 A_u8PullType);

u8   MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo);

void MGPIO_vSetPinVal(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinVal);

void MGPIO_vSetPinVal_fast(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinVal);

void MGPIO_vSetAlternativeFunction(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8AltFun);


#endif /* ARM_MCAL_GPIO_GPIO_INTERFACE_H_ */
