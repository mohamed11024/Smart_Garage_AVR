/*
 * TIMER_prog.c
 *
 *  Created on: Aug 7, 2023
 *      Author: LENOVO
 */
#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"

static void (*Timer0_Interrupt)(void) = NULL_PTR;

void __vector_11(void) __attribute__((signal));


void TIMER0_VoidInit(void (*copy_TIMER0_Int)(void))
{
#if TIMER0_GENERATION_MODE ==  NORMAL0 //Choose generation mode as normal mode
	TCCR0_REG ->WGM00 = 0b01 ;
	TCCR0_REG ->WGM01 = 0b00 ;
	TCCR0_REG ->CS    = 0b101; //clkI/O/1024 (From prescaler)
	TIMSK_REG ->TOIE0 = 0b1  ;  //Enable Overflow Interrupt Enable
	TCNT0_REG = PRELOAD_VALUE;
	Timer0_Interrupt = copy_TIMER0_Int;

#elif TIMER0_GENERATION_MODE ==  FAST_PWM0//Choose generation mode as FAST PWM
	DIO_voidSetPinDir(GroupB,PIN3,Output);
	TCCR0_REG ->WGM00 = 0b1;
	TCCR0_REG ->WGM01 = 0b1;
	TCCR0_REG ->COM   = CLR_CM_SET_TOP0; //Clear OC0 on compare match, set OC0 at TOP
	OCR0_REG  = DUTY_CYCLE() ; //Choose Duty cycle
	TIMSK_REG ->OCIE0 = 0b1 ;//Compare match intterupt enable
	TCCR0_REG ->CS    = PRESCALLER0; //Clock Select Bit Description
#endif
}

void __vector_11(void)
{
	Timer0_Interrupt();
	TCNT0_REG = PRELOAD_VALUE;
}
void TIMER0_voidPWM(u8 copy_u8DutyCycle)
{
#if TIMER0_GENERATION_MODE ==  PWM0//Choose generation mode as PWM
	u8 DutyCycle = 0 ;
	DutyCycle = ((F32)((F32)copy_u8DutyCycle/100)*0xff);
	DIO_voidSetPinDir(GroupB,PIN3,Output);
	TCCR0_REG ->WGM00 = 0b1;
	TCCR0_REG ->WGM01 = 0b0;
	TCCR0_REG ->COM   = CLR_CM_SET_TOP0; //Clear OC0 on compare match, set OC0 at TOP
	OCR0_REG  = DutyCycle ; //Choose Duty cycle
	TCCR0_REG ->CS    = PRESCALLER0; //Clock Select Bit Description
#elif TIMER0_GENERATION_MODE ==  FAST_PWM0//Choose generation mode as PWM
	u8 DutyCycle = 0 ;
	DutyCycle = ((F32)((F32)copy_u8DutyCycle/100)*0xff);
	DIO_voidSetPinDir(GroupB,PIN3,Output);
	TCCR0_REG ->WGM00 = 0b1;
	TCCR0_REG ->WGM01 = 0b1;
	TCCR0_REG ->COM   = CLR_CM_SET_TOP0; //Clear OC0 on compare match, set OC0 at TOP
	OCR0_REG  = DutyCycle ; //Choose Duty cycle
	TCCR0_REG ->CS    = PRESCALLER0; //Clock Select Bit Description
#endif
}

void TIMER1_VoidInit(void)
{
#if TIMER1_GENERATION_MODE ==  NORMAL1 //Choose generation mode as normal mode

TCCR1A_REG ->WGM10 = 0b0           ;//Normal mode
TCCR1A_REG ->WGM11 = 0b0           ;
TCCR1B_REG ->WGM12 = 0b0           ;
TCCR1B_REG ->WGM13 = 0b0           ;
TCCR1B_REG ->CS1   = PRESCALLER1_8 ;//set Prescaller
//TIMSK_REG  ->TOIE1 = 0b01          ;//Overflow Interrupt Enable

#elif

#endif
}

void TIMER1_VoidSetTCNT(u16 copy_u8Data)
{
	TCNT1 = copy_u8Data ;
}
u16 TIMER1_VoidGetTCNT(void)
{
return TCNT1 ;
}
void TIMER1_VoidSetICR(u16 copy_u8Data)
{
	ICR1 = copy_u8Data ;
}
u16 TIMER1_VoidGetICR(void)
{
	return ICR1 ;
}
void WD_timer_voidEnabel(WDT_SECONDS copy_u8Time)
{
	WDTCR_REG ->WDP = copy_u8Time ;
	WDTCR_REG ->WDE = 0b01        ;
}
void WD_timer_voidDisabel(void)
{
	WDTCR_REG->WDTOE = 1  ;
	WDTCR_REG ->WDE  = 1  ;
	WDTCR_REG ->WDE  = 0  ;

}
