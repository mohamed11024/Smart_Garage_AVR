/*
 * LCD_interface.h
 *
 *  Created on: Jul 29, 2023
 *      Author: Mo
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


/*********************LCD 8 PIN*******************/
void LCD_voidWriteCommand(u8 copy_u8Command);
void LCD_voidInit();
void LCD_voidIClear();
void LCD_voidGoToXY(u8 copy_u8Coloumn,u8 copy_u8Row);
void LCD_voidWriteChar(u8 copy_u8Char);
void LCD_voidWriteString(char *copy_u8Char);
void LCD_voidWriteNumber(s16 copy_u8Num);
void LCD_voidCreatCustmChar(u8 copy_u8Adress,u8 *customChar);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
