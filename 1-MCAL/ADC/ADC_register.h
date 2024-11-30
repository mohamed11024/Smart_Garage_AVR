/*
 * ADC_register.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Mo
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

typedef struct
{
	u8 MUX  : 5 ;
	u8 ADLAR: 1 ;
	u8 REFS : 2 ;
}ADC_ADMUX_t;

typedef struct
{
	u8 ADPS : 3;
	u8 ADIE : 1;
	u8 ADIF : 1;
	u8 ADATE: 1;
	u8 ADSC : 1;
	u8 ADEN : 1;
}ADC_ADCSRA_t;

typedef struct
{
	u8 reserved : 5 ;
	u8 ADTS     : 3 ;

}ADC_SFIOR_t;

#define ADC_ADMUX  ((volatile ADC_ADMUX_t*)0x27)
#define ADC_ADCSRA ((volatile ADC_ADCSRA_t*)0x26)
#define ADC_SFIOR  ((volatile ADC_SFIOR_t*)0x50)

#define ADC_DATA   *((volatile u16*)0x24)
#define ADC_ADCL   *((volatile u8*)0x24)
#define ADC_ADCH   *((volatile u8*)0x25)


#endif /* MCAL_ADC_ADC_REGISTER_H_ */
