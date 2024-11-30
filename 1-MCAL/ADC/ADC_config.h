/*
 * ADC_config.h
 *
 *  Created on: Aug 5, 2023
 *      Author: MO
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

// Choose REF_SELEC: 1- AREF 2-AVCC 3-INTERNAL
#define REF_SELEC     INTERNAL
#define AREF                   0b00 //Internal Vref turned off
#define AVCC                   0b01 //AVCC with external capacitor at AREF pin
#define INTERNAL               0b11 //Internal 2.56V Voltage Reference with external capacitor at AREF pin
/*******************************************************/
// Choose ADJUST_RESULT: 1-LEFT_ADJUST 2-RIGHT_ADJUST
#define ADJUST_RESULT         RIGHT_ADJUST
#define LEFT_ADJUST           0b1
#define RIGHT_ADJUST          0b0
/*******************************************************/
// Choose ADC_ENABLE: 1-ENABLE 2-DISABLE
#define ADC_ENABLE            ENABLE

/*******************************************************/
// Choose INTERRUPT_ENABLE: 1-ENABLE 2-DISABLE
#define INTERRUPT_ENABLE            DISABLE
/*******************************************************/
// Choose   DIVISION_FACTOR: 1-DF2 2-DF4 3-DF8 4-DF16 5-DF32 6-DF64 7-DF128
#define DIVISION_FACTOR        DF32 //Prescaler Select Bits
#define DF2                    0b000
#define DF4                    0b010
#define DF8                    0b011
#define DF16                   0b100
#define DF32                   0b101
#define DF64                   0b110
#define DF128                  0b111
/*******************************************************/
// Choose ADC_START_CONVERSION : 1-START_CONVERSION 2-STOP_CONVERSION
#define ADC_START_CONVERSION            START_CONVERSION
#define START_CONVERSION                      0b1
#define STOP_CONVERSION                       0b0
/*******************************************************/
#define ERROR_TIME    0
#endif /* MCAL_ADC_ADC_CONFIG_H_ */
