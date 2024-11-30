/*
 * EXTI_interface.h
 *
 *  Created on: Aug 1, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_
//choose INTRRUPT0_SENSE : 1-ANY_CHANGE 2-FALLING_EDGE 3-RISING_EDGE 4-LOW_LEVEL
#define INTRRUPT0_SENSE  RISING_EDGE
#define ANY_CHANGE       0
#define FALLING_EDGE     1
#define RISING_EDGE      2
#define LOW_LEVEL        3
/*****************************************************************************/

void EXTI0_voidInit(void);
void EXTI1_voidInit(void);
void EXTI1_voidDisable(void);
void EXTI1_voiEnable(u8 INTRRUPT_SENSE);
void EXTI2_voidInit(void);

void EXTI0_voidSetCallBack(void (*copy_PtrToFUN)(void));
void EXTI1_voidSetCallBack(void (*copy_PtrToFUN)(void));
void EXTI2_voidSetCallBack(void (*copy_PtrToFUN)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
