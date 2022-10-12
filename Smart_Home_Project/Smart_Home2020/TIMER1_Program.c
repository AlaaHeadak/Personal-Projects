#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"TIMER_Register.h"

void TIMER1_VidInit(void)
{
	//select timer 1
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,3);
	SET_BIT(TCCR1A,4);
	
	//select non_inverted mode
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	
	//prescaler 256
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	ICR1=625;
	
}

void TIMER1_Set_Duty(u8 Duty)
{
	OCR1A=Duty;
}
