


int Bluetooth(void)
{
	char Data_in;
	DDRB = 0xff;		/* make PORT as output port */
	UART_VidInit(9600);	/* initialize USART with 9600 baud rate */
	LED = 0;
	
	while(1)
	{
		Data_in = UART_u8Receive();	/* receive data from Bluetooth device*/
		if(Data_in =='1')
		{
			LED |= (1<<PB0);	/* Turn ON LED */
			USART_SendString("LED_ON");/* send status of LED i.e. LED ON */
			
		}
		else if(Data_in =='2')
		{
			LED &= ~(1<<PB0);	/* Turn OFF LED */
			USART_SendString("LED_OFF"); /* send status of LED i.e. LED OFF */
		}
		else
			USART_SendString("Select proper option"); /* send message for selecting proper option */
	}		
}