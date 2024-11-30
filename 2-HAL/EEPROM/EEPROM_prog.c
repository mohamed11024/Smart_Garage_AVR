/*
 * EEPROM_prog.c
 *
 *  Created on: Aug 21, 2023
 *      Author: LENOVO
 */
#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include <util/delay.h>

void EEPROM_voidInit(void)
{
	I2C_voidMasterInit();
}

void EEPROM_voidSendData(u8 copy_u8Address,u8 copy_u8AddressByte,u8 copy_u8AData)
{
	I2C_voidStartCondEnable();
	I2C_voidWriteSlaveAddress(copy_u8Address);
	I2C_voidMasterSendData(copy_u8AddressByte);
	I2C_voidMasterSendData(copy_u8AData);
    I2C_voidStopCond();
    _delay_ms(10);
}
u8 EEPROM_voidReceiveData(u8 copy_u8Address,u8 copy_u8AddressByte)
{
	u8 Data = 0;
	I2C_voidStartCondEnable();
	I2C_voidWriteSlaveAddress(copy_u8Address);
	I2C_voidMasterSendData(copy_u8AddressByte);
    I2C_voidR_StartCondEnable();
	I2C_voidReadSlaveAddress(copy_u8Address);
	I2C_u8MasterReceiveData(&Data);
    I2C_voidStopCond();
    return Data ;
}
