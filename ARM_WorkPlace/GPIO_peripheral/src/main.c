#include "LIB/STD_TYPES.h"
#include "ARM_MCAL/RCC/RCC_Interface.h"
#include "ARM_MCAL/GPIO/GPIO_Interface.h"



int main(void)
{
	MRCC_vInit();

	MRCC_vEnableClock(RCC_AHB1, RCC_GPIOAEN);

	MGPIO_vSetPinMode(GPIO_PORTA, 0, GPIO_MODE_OUTPUT );
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA, 0,GPIO_LOW_SPEED);
	MGPIO_vSetPinOutputType(GPIO_PORTA, 0, GPIO_PUSHPULL);
	MGPIO_vSetPinVal(GPIO_PORTA, 0,GPIO_HIGH);

	while(1)
	{

	}

}
