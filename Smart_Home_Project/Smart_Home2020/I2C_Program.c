
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"I2C_Interface.h"
#include"I2C_Register.h"

void I2C_VoidMasterInit(void)
{
	//set prescaler value 0
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	
	//CLK 100KHZ
	TWBR=32;
	
	//enable I2C peripheral
	SET_BIT(TWCR,TWCR_TWEN);
	TWAR=0b00110011;
	
}

void I2C_VoidSlaveInit(u8 Copy_u8Address)
{
	TWAR=Copy_u8Address<<1;
	
	//enable Ack
	SET_BIT(TWCR,TWCR_TWEA);
	
	//enable I2C peripheral
	SET_BIT(TWCR,TWCR_TWEN);
	
}

void I2C_VidSendStartCondition(void)
{
	//send start condition
	SET_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag
	SET_BIT(TWCR,TWCR_TWINT);
	
	//wait the flag
	while (GET_BIT(TWCR, TWCR_TWINT)==0);
	
	//check ack
	if ((TWSR & 0xF8)!= I2C_SC_ACK)
	{
		Local_enuReturnState = I2C_SC_Error;
	}
	return Local_enuReturnState;
	
}

u8 I2C_enuSendRepeatedStartCondition(void)
{
	I2C_Error_State Local_enuReturnState=I2C_ok;
	
	//send start condition
	SET_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag
	SET_BIT(TWCR,TWCR_TWINT);
	
	//wait the flag
	while (GET_BIT(TWCR, TWCR_TWINT)==0);
	
	//check ack
	if ((TWSR & 0xF8)!= I2C_RSC_ACK)
	{
		Local_enuReturnState = I2C_RSC_Error;
	}
	return Local_enuReturnState;
	
}

u8 I2C_SendSlaveAddWithWrite(u8 Copy_u8SlaveAdd)
{
	TWDR= Copy_u8SlaveAdd<<1;
	
	//write operation
	CLR_BIT(TWDR,0);
	
	//clear start condition bit
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag
	SET_BIT(TWCR,TWCR_TWINT);
	
	//waiting the flag
	while (GET_BIT(TWCR, TWCR_TWINT)==0);
	
	//check ack
	if ((TWSR & 0xF8)!= I2C_MT_SLA_W_ACK)
	{
		Local_enuReturnState = I2C_MT_SLA_W_Error;
	}
	return Local_enuReturnState;
	
}

u8 I2C_SendSlaveAddWithRead(u8 Copy_u8SlaveAdd)
{
	TWDR= Copy_u8SlaveAdd<<1;
	
	//write operation
	CLR_BIT(TWDR,0);
	
	//clear start condition bit
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag
	SET_BIT(TWCR,TWCR_TWINT);
	
	//waiting the flag
	while (GET_BIT(TWCR, TWCR_TWINT)==0);
	
	//check ack
	if ((TWSR & 0xF8)!= I2C_MT_SLA_W_ACK)
	{
		Local_enuReturnState = I2C_MT_SLA_W_Error;
	}
	return Local_enuReturnState;
	
}




u8 I2C_enuMasterReadDataByte(u8 Copy_u8ReturnData)
{
	I2C_Error_State Local_enuReturnState=I2C_ok;

	
	//clear flag
	SET_BIT(TWCR,TWCR_TWINT);
	
	//waiting the flag
	while (GET_BIT(TWCR, TWCR_TWINT)==0);
	
	//check ack
	if ((TWSR & 0xF8)!= I2C_MR_Data_ACK)
	{
		Local_enuReturnState = I2C_MR_Data_Error;
	}
	else 
	{
		Copy_u8ReturnData=TWDR;
	}
	return Local_enuReturnState;
	
}

void I2C_VidSendStopCondition (void)
{
	SET_BIT(TWCR,TWCR_TWSTO);
	
	SET_BIT(TWCR,TWCR_TWINT);
}













