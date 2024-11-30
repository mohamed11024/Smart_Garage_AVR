/*
 * Sev_interface.h
 *
 *  Created on: Jul 25, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SEV_SEG_SEV_INTERFACE_H_
#define HAL_SEV_SEG_SEV_INTERFACE_H_


void Sev_voidInit(void);
void Sev_voidDisplay(u8 copy_u8SevNum);

void Sev_voidInitMulti(void);
void Sev_voidDisplayMulti( u8 copy_u8SevNum0 ,u8 copy_u8SevNum1);

#endif /* HAL_SEV_SEG_SEV_INTERFACE_H_ */
