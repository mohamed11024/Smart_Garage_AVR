/*
 * TIMER_interface.h
 *
 *  Created on: Aug 7, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

void TIMER0_VoidInit(void (*copy_TIMER0_Int)(void));
void TIMER0_voidPWM(u8 copy_u8DutyCycle);

void TIMER1_VoidInit(void);
void TIMER1_VoidSetTCNT(u16 copy_u8Data);
u16 TIMER1_VoidGetTCNT(void);
void TIMER1_VoidSetICR(u16 copy_u8Data);
u16 TIMER1_VoidGetICR(void);

void WD_timer_voidEnabel(u8 copy_u8Time);
void WD_timer_voidDisabel(void);

typedef enum{
    ms16_3=0,
    ms32_5=1,
    ms65  =2,
    s_13  =3,
    s_26  =4,
    s_52  =5,
    s1    =6,
    s2_1  =7
}WDT_SECONDS;

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
