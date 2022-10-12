#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_


void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);

#endif