/*
 * GIE_prog.c
 *
 *  Created on: Aug 1, 2023
 *      Author: LENOVO
 */

#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "GIE_interface.h"
#include "GIE_config.h"
#include "GIE_private.h"
#include "GIE_register.h"



void GIE_voidEnable(void)
{
	set_Bit(GIE_SREG,GIE_SREG_PIN);
}

void GIE_voidDisable(void)
{
	clr_Bit(GIE_SREG,GIE_SREG_PIN);
}
