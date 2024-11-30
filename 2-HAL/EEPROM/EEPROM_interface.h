/*
 * EEPROM_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: LENOVO
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidSendData(u8 copy_u8Address,u8 copy_u8AddressByte,u8 copy_u8AData);
u8 EEPROM_voidReceiveData(u8 copy_u8Address,u8 copy_u8AddressByte);
void EEPROM_voidInit(void);
#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
