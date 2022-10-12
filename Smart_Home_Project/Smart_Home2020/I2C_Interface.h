#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_



void I2C_VoidMasterInit(void);
void I2C_VoidSlaveInit(u8 Copy_u8Address);
void I2C_VidSendStartCondition(void);
u8 I2C_SendSlaveAddWithWrite(u8 Copy_u8SlaveAdd);
u8 I2C_enuSendRepeatedStartCondition(void);
u8 I2C_SendSlaveAddWithRead(u8 Copy_u8SlaveAdd);
u8 I2C_enuMasterReadDataByte(u8 Copy_u8ReturnData);
void I2C_VidSendStopCondition (void);

#endif