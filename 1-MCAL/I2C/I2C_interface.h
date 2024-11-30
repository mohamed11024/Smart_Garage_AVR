/*
 * I2C_interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

//Choose Prescaler_Value : 1-PRESCALER1 2-PRESCALER4 3-PRESCALER16 4-PRESCALER64
#define Prescaler_Value   PRESCALER1
#define PRESCALER1        0b00
#define PRESCALER4        0b01
#define PRESCALER16       0b10
#define PRESCALER64       0b11
/**************************************************************/
#define MY_ADDRESS    0b0010101
#define GENERAL_MODE  0b0
/**************************************************************/
typedef enum
{
	NO_ERROR,
	START_ERROR,
	REPEATED_STSRT_ERROR,
	SLAVE_ADDRESS_WRITE_ERROR,
	SLAVE_ADDRESS_READ_ERROR,
	SEND_BYTE_ERROR,
	READ_BYTE_ERROR

}TWI_ERROR_STATUS;
/**************************************************************/

void I2C_voidMasterInit(void);
TWI_ERROR_STATUS I2C_voidStartCondEnable(void);
TWI_ERROR_STATUS I2C_voidR_StartCondEnable(void);
TWI_ERROR_STATUS I2C_voidWriteSlaveAddress(u8 copy_u8Address);
TWI_ERROR_STATUS I2C_voidReadSlaveAddress(u8 copy_u8Address);
TWI_ERROR_STATUS I2C_voidMasterSendData(u8 copy_u8Data);
void I2C_voidStopCond(void);
TWI_ERROR_STATUS I2C_u8MasterReceiveData(u8 * copy_u8Data);
void I2C_voidSetMyAddress(void);

#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
