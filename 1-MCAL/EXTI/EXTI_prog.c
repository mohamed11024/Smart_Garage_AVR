/*
 * EXTI_prog.c
 *
 *  Created on: Aug 1, 2023
 *      Author: LENOVO
 */

#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"

void (*CallBackFunc[3])(void)=  {NULL_PTR,NULL_PTR,NULL_PTR};

void EXTI1_voidInit(void)
{
	DIO_voidSetPinDir(GroupD,PIN3,Input);
	DIO_voidSetPinValue(GroupD,PIN3,High);

#if INTRRUPT1_SENSE == FALLING_EDGE
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);

#elif INTRRUPT1_SENSE == ANY_CHANGE
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);

#elif INTRRUPT1_SENSE == RISING_EDGE
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);

#elif INTRRUPT1_SENSE == LOW_LEVEL
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);

#endif

	set_Bit(EXTI_GICR,EXTI_GICR_INT1);
}
void EXTI1_voidDisable(void)
{
	clr_Bit(EXTI_GICR,EXTI_GICR_INT1);
}
void EXTI1_voiEnable(u8 INTRRUPT_SENSE)
{
	DIO_voidSetPinDir(GroupD,PIN3,Input);
	DIO_voidSetPinValue(GroupD,PIN3,High);

if( INTRRUPT_SENSE == FALLING_EDGE)
{
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
}
else if (INTRRUPT_SENSE == ANY_CHANGE)
{
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);
}
else if( INTRRUPT_SENSE == RISING_EDGE)
{
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);
}
else if( INTRRUPT_SENSE == LOW_LEVEL)
{
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC11);
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);
}

	set_Bit(EXTI_GICR,EXTI_GICR_INT1);
}
void EXTI0_voidInit(void)
{
	DIO_voidSetPinDir(GroupD,PIN2,Input);
	DIO_voidSetPinValue(GroupD,PIN2,High);

#if INTRRUPT0_SENSE == FALLING_EDGE
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC00);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC01);

#elif INTRRUPT0_SENSE == ANY_CHANGE
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC01);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC00);

#elif INTRRUPT0_SENSE == RISING_EDGE
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC00);
	set_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC01);

#elif INTRRUPT0_SENSE == LOW_LEVEL
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC00);
	clr_Bit(EXTI_MCUCR,EXTI_MCUSR_ISC10);

#endif

	set_Bit(EXTI_GICR,EXTI_GICR_INT0);
}

void EXTI2_voidInit(void)
{
	DIO_voidSetPinDir(GroupB,PIN2,Input);
	DIO_voidSetPinValue(GroupB,PIN2,High);

#if INTRRUPT2_SENSE == FALLING_EDGE
clr_Bit(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);

#elif INTRRUPT2_SENSE == RISING_EDGE
set_Bit(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);

#endif

	set_Bit(EXTI_GICR,EXTI_GICR_INT2);
}
void EXTI0_voidSetCallBack(void (*copy_PtrToFUN)(void))
{
  CallBackFunc[0] = copy_PtrToFUN;
}
void EXTI1_voidSetCallBack(void (*copy_PtrToFUN)(void))
{
	  CallBackFunc[1] = copy_PtrToFUN;
}
void EXTI2_voidSetCallBack(void (*copy_PtrToFUN)(void))
{
	  CallBackFunc[2] = copy_PtrToFUN;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	CallBackFunc[0]();
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	CallBackFunc[1]();
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	CallBackFunc[2]();
}
