#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"SPI_Register.h"


void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DIO_VidSetPinDirection (1,5,1);
DIO_VidSetPinDirection (1,7,1);
DIO_VidSetPinDirection (1,6,0);
DIO_VidSetPinDirection (1,4,1);

/* Enable SPI, Master, set clock rate fck/16 */

u8 SPCR_Help = 0; 
SET_BIT(SPCR_Help,6);
SET_BIT(SPCR_Help,5);
SET_BIT(SPCR_Help,4);

// clock 16
SET_BIT(SPCR_Help,0);
CLR_BIT(SPCR_Help,1);
SPCR = SPCR_Help; 
}



u8 SPI_Transciever(u8 Data)
{
	/* Start transmission */
	SPDR = cData;

	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void main (void)
{
	while (1)
	{
	x=SPI_Transciever(5);

	if (x==5)
	{
		//toggle led 
	}
	}
}




void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
DDR_SPI = (1<<DD_MISO);
/* Enable SPI */
SPCR = (1<<6);
}





