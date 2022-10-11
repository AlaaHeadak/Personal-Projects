#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_




void DIO_VidSetPinDirection(u8 Port , u8 Pin_Num , u8 State);

void DIO_VidSetPortDirection(u8 Port , u8 Direction);

void DIO_VidSetPinValue(u8 Port , u8 Pin_Num , u8 Value);

void DIO_VidSetPortValue(u8 Port , u8 Value);

u8 DIO_U8GetPinValue(u8 Port , u8 Pin_Num );

void DIO_VidTogglePin(u8 Port , u8 Pin);


#endif
