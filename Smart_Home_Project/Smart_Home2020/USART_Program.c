
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"USART_Register.h"

void UART_VidInit(void)
{
	u8 UCSRC_Help = 0;   //0000 0000
	SET_BIT(UCSRC_Help,7);  //1000 0000
	//select normal mode
	CLR_BIT(UCSRA,1);
	CLR_BIT(UCSRA,0);
	
	//enable UART RX AND TX
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	
	//character size =8 bits
	CLR_BIT(UCSRB,2);
	SET_BIT(UCSRC_Help,1);   //1000 0010
	SET_BIT(UCSRC_Help,2);   //1000 0110 
	
	//stop bit =1bit
	CLR_BIT(UCSRC_Help,3);   //1000 0110	
	
	//mode select = Async
	CLR_BIT(UCSRC_Help,6);   //1000 0110
	
	//parity mode = disable
	CLR_BIT(UCSRC_Help,4);   //1000 0110 
	CLR_BIT(UCSRC_Help,5);
	
	UCSRC = UCSRC_Help;
	
	// baud rate =9600
	UBRRL=51;
	UBRRH=0;
	
}

void UART_VidSendData(u8 Copy_Data)
{
	while (0==GET_BIT(UCSRA,5));
	UDR=Copy_Data;
}

u8 UART_u8Receive(void)
{
	u8 x;
	while (0==GET_BIT(UCSRA,7));
	x= UDR;
	return x;
}





