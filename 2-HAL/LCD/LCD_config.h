/*
 * LCD_confif.h
 *
 *  Created on: Jul 29, 2023
 *      Author: Mo
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
/******************************************************/
/******************* 8 PIN MODE ***********************/
#define LCD_CTRLPORT   GroupB
#define LCD_DATAPORT   GroupC
#define LCD_RS   PIN2
#define LCD_RW   PIN1
#define LCD_E    PIN0
/******************************************************/
/***************************LCD MODE*******************/
/********Choose 1-FOUR_PIN  2-EIGHT_PIN ****************/
#define LCD_MODE   FOUR_PIN
#define FOUR_PIN    4
#define EIGHT_PIN   8
/******************************************************/
/******************* 4 PIN MODE ***********************/

#define LCD4_D7_PIN           PIN7
#define LCD4_D6_PIN           PIN6
#define LCD4_D5_PIN           PIN5
#define LCD4_D4_PIN           PIN4

#define LCD4_D7_PORT          GroupA
#define LCD4_D6_PORT          GroupA
#define LCD4_D5_PORT          GroupA
#define LCD4_D4_PORT          GroupA

#define LCD4_RS_PIN           PIN0
#define LCD4_RW_PIN           PIN1
#define LCD4_E_PIN            PIN2
#define LCD4_RS_PORT          GroupC
#define LCD4_RW_PORT          GroupC
#define LCD4_E_PORT           GroupC


#endif /* HAL_LCD_LCD_CONFIG_H_ */
