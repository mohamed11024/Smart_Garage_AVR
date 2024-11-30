/*
 * ADC.interface.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Mo
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

typedef enum
{
    Single_ADC0,
	Single_ADC1,
	Single_ADC2,
	Single_ADC3,
	Single_ADC4,
	Single_ADC5,
	Single_ADC6,
	Single_ADC7
}ADC_Channels;
void ADC_voidInit();
u16  ADC_u8GetReading(u8 copy_u8ADC_Channnel);
u32  ADC_u32RangeToRange(u16 x,u16 x1,u16 y1,u16 x2,u16 y2);
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
