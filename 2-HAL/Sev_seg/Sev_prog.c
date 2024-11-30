/*
 * Sev_prog.c
 *
 *  Created on: Jul 25, 2023
 *      Author: LENOVO
 */

#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Sev_config.h"
#include "Sev_interface.h"
#include <util/delay.h>

#if SEV_TYPE == ANODE
static char sev_Anode[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
#elif SEV_TYPE == CATHODE
static char sev_Cathode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
#endif

void Sev_voidInit()
{
	DIO_voidSetPortDir(SEV_PORT,Output_Port);
}

void Sev_voidInitMulti()
{
	DIO_voidSetPortDir(SEV_PORT,Output_Port);
	DIO_voidSetPinDir(SEV_PORT_PINS,SEV_PIN_COMMON_0,Output);
	DIO_voidSetPinDir(SEV_PORT_PINS,SEV_PIN_COMMON_1,Output);
}

void Sev_voidDisplayMulti( u8 copy_u8SevNum0 ,u8 copy_u8SevNum1)
{
#if SEV_TYPE == CATHODE
	int	time = 0;
	while(time < (TIME / 20))
	{
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_1,High);
		Sev_voidDisplay(copy_u8SevNum0);
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_0,Low);
		_delay_ms(10);
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_0,High);
		Sev_voidDisplay(copy_u8SevNum1);
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_1,Low);
		_delay_ms(10);
		time ++;
	}

#elif SEV_TYPE == ANODE

	int	time = 0;
	while(time < (TIME / 20))
	{
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_1,Low);
		Sev_voidDisplay(copy_u8SevNum0);
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_0,High);
		_delay_ms(10);
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_0,Low);
		Sev_voidDisplay(copy_u8SevNum1);
		DIO_voidSetPinValue(SEV_PORT_PINS,SEV_PIN_COMMON_1,High);
		_delay_ms(10);
		time ++;
	}

#endif

}
void Sev_voidDisplay(u8 copy_u8SevNum)
{
#if   SEV_TYPE == CATHODE
	DIO_voidSetPortValue(SEV_PORT,sev_Cathode[copy_u8SevNum]);

#elif SEV_TYPE == ANODE
	DIO_voidSetPortValue(SEV_PORT,sev_Anode[copy_u8SevNum]);

#endif
}
