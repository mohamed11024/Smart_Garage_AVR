/*
 * ADC_prog.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Mo
 */
#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_register.h"



void ADC_voidInit()
{
ADC_ADMUX  ->REFS  = REF_SELEC; //Reference Selection Bits
ADC_ADMUX  ->ADLAR = ADJUST_RESULT;//ADC Adjust Result
ADC_ADCSRA ->ADPS  = DIVISION_FACTOR;//ADC Prescaler Select Bits
ADC_ADCSRA ->ADEN  = ADC_ENABLE; // ADC Enable
}

u16  ADC_u8GetReading(u8 copy_u8ADC_Channnel)
{
	u16 Count = 0 ;
	u16 Data  = 0 ;
	ADC_ADMUX  ->MUX = copy_u8ADC_Channnel ;//Choose channel of ADC 1-Single_ADC0 2-Single_ADC1 3-......
	ADC_ADCSRA ->ADSC= ADC_START_CONVERSION;// Start conversion
	while(ADC_ADCSRA ->ADIF == 0 && Count < 10000)
	{
		Count++;
	}
	if(ADC_ADCSRA ->ADIF == 1 )
	{
	Data = ADC_DATA ;
	ADC_ADCSRA ->ADIF = 1 ;
	return Data ;
	}
	else
		return ERROR_TIME;
}
u32  ADC_u32RangeToRange(u16 x,u16 x1,u16 y1,u16 x2,u16 y2)
{
	u32 y = 0;
	y = (((x - x1)+(y2-y1))/(x2-x1))+y1 ;
	return y ;
}
