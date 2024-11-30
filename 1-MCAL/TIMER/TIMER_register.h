/*
 * TIMER_register.h
 *
 *  Created on: Aug 7, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_TIMER_TIMER_REGISTER_H_
#define MCAL_TIMER_TIMER_REGISTER_H_

#include "../../common/STD_types.h"
/*****************TIMER0*******************************/
/******************************************************/
typedef struct {
	u8 TOV0      : 1 ;
	u8 OCF0      : 1 ;
	u8 TOV1      : 1 ;
	u8 OCF1B     : 1 ;
	u8 OCF1A     : 1 ;
	u8 ICF1      : 1 ;
	u8 RESERVED  : 2 ;
}TIFR_REG_t;

#define TIFR_REG ((volatile TIFR_REG_t *)0x58)
/******************************************************/
/******************************************************/
typedef struct {
	u8 TOIE0 : 1 ;
	u8 OCIE0 : 1 ;
	u8 reserved : 6 ;
}TMSK_REG_t;

#define TMSK_REG ((volatile TMSK_REG_t *)0x59)
/******************************************************/
/******************************************************/
typedef struct {
	u8 CS : 3 ;     // clock selection bits
	u8 WGM01 : 1 ;  // wave form generation second bit
	u8 COM : 2 ;    // Compare Match Output Mode
	u8 WGM00 : 1 ;  // wave form generation first bit
	u8 FOC0 : 1 ;   // Force Output Compare
}TCCR0_REG_t;

#define TCCR0_REG ((volatile TCCR0_REG_t *)0x53)
/******************************************************/

#define TCNT0_REG *((volatile u8*)0x52)    // timer0 overflow register
#define OCR0_REG  *((volatile u8*)0x5C)    // timer0 compare match register

/******************************************************/
typedef struct {
	u8 TOIE0     : 1 ;     // timer0 over flow interrupt enable
	u8 OCIE0     : 1 ;     // timer0 compare match interrupt enable
	u8 TOIE1     : 1 ;
	u8 OCIE1B    : 1 ;
	u8 OCIE1A    : 1 ;
	u8 TICIE1    : 1 ;
	u8 RESERVED  : 2 ;
}TIMSK_REG_t;

#define TIMSK_REG ((volatile TIMSK_REG_t *)0x59)
/******************************************************/
/*****************TIMER1*******************************/

typedef struct
{
	u8 WGM10 : 1 ;
	u8 WGM11 : 1 ;
	u8 FOC1  : 2 ;
	u8 COM1  : 4 ;
}TCCR1A_REG_t;

#define TCCR1A_REG ((volatile TCCR1A_REG_t *)0x4F)

/******************************************************/
typedef struct
{
	u8 CS1   :  3;
	u8 WGM12 :  1;
	u8 WGM13 :  1;
	u8 RESERVED:1;
	u8 ICES1 :  1;
	u8 ICNC  :  1;
}TCCR1B_REG_t;

#define TCCR1B_REG ((volatile TCCR1B_REG_t *)0x4E)


/******************************************************/
#define TCNT1H_REG  (*((volatile u8*)0x4D))
#define TCNT1L_REG  (*((volatile u8*)0x4C))
#define TCNT1       (*((volatile u16*)0x4C))

#define OCR1AH_REG  (*((volatile u8*)0x4B))
#define OCR1AL_REG  (*((volatile u8*)0x4A))

#define OCR1BH_REG  (*((volatile u8*)0x49))
#define OCR1BL_REG  (*((volatile u8*)0x48))

#define ICR1H_REG   (*((volatile u8*)0x47))
#define ICR1L_REG   (*((volatile u8*)0x46))
#define ICR1        (*((volatile u16*)0x46))
/*****************************WatchDog Timer***************************/
typedef struct
{
	u8 WDP    : 3;
	u8 WDE    : 1;
	u8 WDTOE  : 1;
	u8 RESERVED:3;
}WDTCR_REG_t;

#define WDTCR_REG     ((volatile WDTCR_REG_t*)0x41)
#endif /* MCAL_TIMER_TIMER_REGISTER_H_ */
