/*
 * I2C_prog.c
 *
 *  Created on: Aug 19, 2023
 *      Author: LENOVO
 */
#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "I2C_interface.h"
#include "I2C_register.h"
#include "I2C_config.h"
/***************************************************/
void I2C_voidInterruptEnable(void);
void I2C_voidTWE_Enable(void);
void I2C_voidStartCondDisable(void);
void I2C_voidAckEnable(void);
void I2C_voidClearFlag(void);
u8 I2C_u8GetFlag(void);
u8   I2C_u8ReadStatus(void);
void I2C_voidPrescalerValue(void);
u8 I2C_u8GetData(void);
/**********************************************MASTER***************************************************************/
void I2C_voidMasterInit(void)
{
    DIO_voidSetPinDir(GroupC,PIN0,Output);//Set SCL(CLK) pin as output
    DIO_voidSetPinDir(GroupC,PIN1,Output);//Set SDA(DATA) pin as output

	I2C_voidAckEnable();
	//I2C_voidInterruptEnable();
	I2C_voidPrescalerValue();
	I2C_voidSetMyAddress();//Set my address
	I2C_voidTWE_Enable();
}

TWI_ERROR_STATUS I2C_voidStartCondEnable(void)
{
	u8 ErrorState = 0;
	TWCR_REG ->TWSTA = ENABLE ;
	I2C_voidClearFlag();       //Clear flag
	while(I2C_u8GetFlag() != 1);// read Flag
	if(I2C_u8ReadStatus()!= START_COND_STATUS)//check status
	{
		ErrorState=  START_ERROR;
	}
	else
	{
	ErrorState= NO_ERROR;
	}
	return ErrorState ;
}
TWI_ERROR_STATUS I2C_voidR_StartCondEnable(void)
{
	u8 ErrorState = 0;
	TWCR_REG ->TWSTA = ENABLE ;
	I2C_voidClearFlag();       //Clear flag
	while(I2C_u8GetFlag() != 1);// read Flag
	if(I2C_u8ReadStatus()!= R_START_COND_STATUS)//check status
	{
		ErrorState=  START_ERROR;
	}
	else
	{
	ErrorState= NO_ERROR;
	}
	return ErrorState ;
}

TWI_ERROR_STATUS I2C_voidWriteSlaveAddress(u8 copy_u8Address)
{
	u8 ErrorState =0;
	TWDR_REG = (copy_u8Address << 1);//
	TWDR_REG |= 0b0; //Write(0) or read(1)
	I2C_voidStartCondDisable();//Disable start condition
	I2C_voidClearFlag();//Clear flag

	while(I2C_u8GetFlag() != 1);// read Flag
	if(I2C_u8ReadStatus()!= SEND_ADDRESS_STATUS)//check status
	{
		ErrorState=  SLAVE_ADDRESS_WRITE_ERROR;
	}
	else
	{
		ErrorState = NO_ERROR;
	}
	return ErrorState;
}
TWI_ERROR_STATUS I2C_voidReadSlaveAddress(u8 copy_u8Address)
{
	u8 ErrorState =0;
	TWDR_REG = (copy_u8Address << 1);//
	TWDR_REG |= 0b1; //Write(0) or read(1)
	I2C_voidStartCondDisable();//Disable start condition
	I2C_voidClearFlag();//Clear flag

	while(I2C_u8GetFlag() != 1);// read Flag
	if(I2C_u8ReadStatus()!= READ_ADDRESS_STATUS)//check status
	{
		ErrorState=  SLAVE_ADDRESS_WRITE_ERROR;
	}
	else
	{
		ErrorState = NO_ERROR;
	}
	return ErrorState;
}
TWI_ERROR_STATUS I2C_voidMasterSendData(u8 copy_u8Data)
{
	u8 ErrorState =0;
	TWDR_REG = copy_u8Data;
	I2C_voidClearFlag();//Clear flag

	while(I2C_u8GetFlag() != 1);// read Flag
	if(I2C_u8ReadStatus()!= SEND_DATA_STATUS)//check status
	{
		ErrorState=  SEND_BYTE_ERROR;
	}
	else
	{
		ErrorState = NO_ERROR;
	}
	return ErrorState;
}

TWI_ERROR_STATUS I2C_u8MasterReceiveData(u8 * copy_u8Data)
{
	u8 ErrorState = 0;
	I2C_voidClearFlag();//Clear flag
	while(I2C_u8GetFlag() != 1);// read Flag
	if(I2C_u8ReadStatus()!= READ_DATA_STATUS)//check status
	{
		ErrorState=  READ_BYTE_ERROR;
	}
	else
	{
		*copy_u8Data = I2C_u8GetData();//Get data
		ErrorState= NO_ERROR;
	}
return ErrorState ;
}
void I2C_voidStopCond(void)
{
	TWCR_REG ->TWSTO = ENABLE ;
	I2C_voidClearFlag();//Clear flag
}
/*************************************************SLAVE************************************************************/



/*********************************************************************************************************************/
void I2C_voidInterruptEnable(void)
{
	TWCR_REG ->TWIE =  ENABLE ;
}
void I2C_voidTWE_Enable(void)
{
	TWCR_REG ->TWEN =  ENABLE ;
}

void I2C_voidStartCondDisable(void)
{
	TWCR_REG ->TWSTA = DISABLE ;
}
void I2C_voidAckEnable(void)
{
	TWCR_REG ->TWEA  = ENABLE;
}
void I2C_voidClearFlag(void)
{
	TWCR_REG ->TWINT = ENABLE;
}
u8 I2C_u8GetFlag(void)
{
	return TWCR_REG ->TWINT ;
}
u8   I2C_u8ReadStatus(void)
{
	u8 status = TWSR_REG ->TWS ;
	status &= 0b11111000 ;//mask
	return status ;
}
void I2C_voidPrescalerValue(void)
{
	TWSR_REG ->TWPS = Prescaler_Value;
}


void I2C_voidSetMyAddress(void)
{
	TWAR_REG->TWA = MY_ADDRESS ;
	TWAR_REG->TWGCE= GENERAL_MODE;     // General Mode Enable
}
u8 I2C_u8GetData(void)
{
	return TWDR_REG ;
}
