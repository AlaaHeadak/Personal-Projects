#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "ARM_MCAL/RCC/RCC_interface.h"
#include "ARM_MCAL/RCC/RCC_private.h"
#include "ARM_MCAL/RCC/RCC_configuration.h"

#include "ARM_MCAL/GPIO/GPIO_interface.h"
#include "ARM_MCAL/GPIO/GPIO_private.h"
#include "ARM_MCAL/GPIO/GPIO_configurations.h"

#include "ARM_MCAL/EXTI/EXTI_interface.h"
#include "ARM_MCAL/EXTI/EXTI_private.h"
#include "ARM_MCAL/EXTI/EXTI_configuration.h"

int main(void)
{
	MRCC_voidInit();
	MRCC_voidPeripheralEnable(AHB1,GPIOAEN);
	MGPIO_voidSetPinDirection(GPIOA_PORT,PIN0,OUTPUT_PUSH_PULL,MEDIUM_SPEED);
	MGPIO_voidSetPinValue(GPIOA_PORT,PIN0,HIGH);




	while(1)
	{

	}

}
