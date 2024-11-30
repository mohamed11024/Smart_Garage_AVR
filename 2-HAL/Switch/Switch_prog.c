/*
 * Switch_prog.c
 *
 *  Created on: Jul 25, 2023
 *      Author: LENOVO
 */
#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"


void Switch_voidInit(u8 copy_u8SwitchPort,u8 copy_u8SwitchPin)
{
DIO_voidSetPinDir(copy_u8SwitchPort,copy_u8SwitchPin,Input);
DIO_voidSetPinValue(copy_u8SwitchPort,copy_u8SwitchPin,High);
}

u8 Switch_u8GetValue(u8 copy_u8SwitchPort,u8 copy_u8SwitchPin)
{
 return DIO_u8GetPinValue(copy_u8SwitchPort, copy_u8SwitchPin);
}
