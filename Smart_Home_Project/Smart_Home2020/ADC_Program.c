
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Register.h"


void ADC_Init(void)
{
	//select Vref = ACVV = 5v
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	//select right adjust result
	CLR_BIT(ADMUX,5);
	
	// select channel
	ADMUX = ADMUX | 0b00000000;
	
	//enable ADC
	SET_BIT(ADCSRA,7);
	
	//select single conversion
	CLR_BIT(ADCSRA,5);
	
	//ADC Interrupt Disable
	CLR_BIT(ADCSRA,3);
	
	// prescaler select bits
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,1);
	
	
}

u16 ADC_ReadValue(u8 CH_NUM)
{
	
	//select channel
	ADMUX=ADMUX&0b11100000;
	ADMUX=ADMUX|CH_NUM;
	
	// start conversion
	SET_BIT(ADCSRA,6);
	
	//wait until end conversion
	while(GET_BIT(ADCSRA,4)==0);
	{
		
	}
	
	// clear ADIF
	SET_BIT(ADCSRA,4);
	return ADC_D;
	
}



