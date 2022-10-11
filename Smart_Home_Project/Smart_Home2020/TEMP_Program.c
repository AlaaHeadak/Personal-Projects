#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Register.h"
#include "ADC_Interface.h"

u8 TEMP_Read(u8 pin)
{

 ADC_Init();

 return ADC_ReadValue(pin);
}