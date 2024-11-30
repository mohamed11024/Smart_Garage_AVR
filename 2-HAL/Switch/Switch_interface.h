/*
 * Switch_interface.h
 *
 *  Created on: Jul 25, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_
void Switch_voidInit(u8 copy_u8SwitchPort,u8 copy_u8SwitchPin);

u8 Switch_u8GetValue(u8 copy_u8SwitchPort,u8 copy_u8SwitchPin);

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
