/*
 * LED_prog.c
 *
 *  Created on: Jul 25, 2023
 *      Author: LENOVO
 */


#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

void LED_voidInit(u8 copy_u8LedPort, u8 copy_u8LedPin )
{
	DIO_voidSetPinDir(copy_u8LedPort,  copy_u8LedPin ,Output );
}
void LED_voidOn(u8 copy_u8LedPort, u8 copy_u8LedPin )
{
	DIO_voidSetPinValue(copy_u8LedPort,  copy_u8LedPin ,High);
}
void LED_voidOff(u8 copy_u8LedPort, u8 copy_u8LedPin )
{
	DIO_voidSetPinValue(copy_u8LedPort,copy_u8LedPin ,Low);
}
