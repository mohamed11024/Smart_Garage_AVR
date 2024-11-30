/*
 * LCD_prog.c
 *
 *  Created on: Jul 29, 2023
 *      Author: Mo
 */

/********************************************************************************/
/********************************LCD 4x20***************************************/
/******************************************************************************/

#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>
#include "LCD_config.h"

void LCD_voidWriteCommand(u8 copy_u8Command)
{
#if LCD_MODE == EIGHT_PIN
	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_RS,Low);   // set Value of RS as LOW to send Command
	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_RW,Low);   // set Value of RW as LOW to Write on LCD
	DIO_voidSetPortValue(LCD_DATAPORT,copy_u8Command);// write command on port of data

	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_E,High);   // set Value of E as HIGH ( enable pulse)
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_E,Low);   //  set Value of E as LOW ( unenable pulse)
	_delay_ms(2);

#elif LCD_MODE  == FOUR_PIN
	DIO_voidSetPinValue(LCD4_RS_PORT,LCD4_RS_PIN,Low); // set Value of RS as LOW to send Command
	DIO_voidSetPinValue(LCD4_RW_PORT,LCD4_RW_PIN,Low);// set Value of RW as LOW to Write on LCD
	/********************************************************************************/
	/************* write command on Most port of data********************************/
	DIO_voidSetPinValue(LCD4_D7_PORT,LCD4_D7_PIN,get_Bit(copy_u8Command,PIN7));
	DIO_voidSetPinValue(LCD4_D6_PORT,LCD4_D6_PIN,get_Bit(copy_u8Command,PIN6));
	DIO_voidSetPinValue(LCD4_D5_PORT,LCD4_D5_PIN,get_Bit(copy_u8Command,PIN5));
	DIO_voidSetPinValue(LCD4_D4_PORT,LCD4_D4_PIN,get_Bit(copy_u8Command,PIN4));

	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,Low);

	/********************************************************************************/
	/************* write command on Least port of data********************************/
	DIO_voidSetPinValue(LCD4_D7_PORT,LCD4_D7_PIN,get_Bit(copy_u8Command,PIN3));
	DIO_voidSetPinValue(LCD4_D6_PORT,LCD4_D6_PIN,get_Bit(copy_u8Command,PIN2));
	DIO_voidSetPinValue(LCD4_D5_PORT,LCD4_D5_PIN,get_Bit(copy_u8Command,PIN1));
	DIO_voidSetPinValue(LCD4_D4_PORT,LCD4_D4_PIN,get_Bit(copy_u8Command,PIN0));

	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,Low);


#endif
}

void LCD_voidInit()
{
#if LCD_MODE == EIGHT_PIN
	DIO_voidSetPinDir(LCD_CTRLPORT,LCD_RS,Output);	//set Direction of RS as OUTPUT
	DIO_voidSetPinDir(LCD_CTRLPORT,LCD_RW,Output);	//set Direction of RW as OUTPUT
	DIO_voidSetPinDir(LCD_CTRLPORT,LCD_E,Output);	//set Direction of E as OUTPUT
	DIO_voidSetPortDir(LCD_DATAPORT,Output_Port);	//set Direction of DATA PORT as OUTPUT

	_delay_ms(40);
	LCD_voidWriteCommand(0x38);
	_delay_ms(2);
	LCD_voidWriteCommand(0x0E);
	_delay_ms(2);
	LCD_voidWriteCommand(0x01);
	_delay_ms(2);
	LCD_voidWriteCommand(0x06);
#elif LCD_MODE  == FOUR_PIN
	/**************set Direction of DATA PINS as OUTPUT*******************/
	DIO_voidSetPinDir(LCD4_D7_PORT,LCD4_D7_PIN,Output);
	DIO_voidSetPinDir(LCD4_D6_PORT,LCD4_D6_PIN,Output);
	DIO_voidSetPinDir(LCD4_D5_PORT,LCD4_D5_PIN,Output);
	DIO_voidSetPinDir(LCD4_D4_PORT,LCD4_D4_PIN,Output);

	DIO_voidSetPinDir(LCD4_E_PORT,LCD4_E_PIN,Output);   //set Direction of E as OUTPUT
	DIO_voidSetPinDir(LCD4_RS_PORT,LCD4_RS_PIN,Output); //set Direction of RS as OUTPUT
	DIO_voidSetPinDir(LCD4_RW_PORT,LCD4_RW_PIN,Output); //set Direction of RW as OUTPUT

	_delay_ms(40);
	LCD_voidWriteCommand(0x02);

	LCD_voidWriteCommand(0x28);

	LCD_voidWriteCommand(0x0C);

	LCD_voidWriteCommand(0x01);

	LCD_voidWriteCommand(0x06);

#endif
}
void LCD_voidIClear()
{
	LCD_voidWriteCommand(0x01);
}


void LCD_voidWriteChar(u8 copy_u8Char)
{
#if LCD_MODE == EIGHT_PIN

	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_RS,High);   // set Value of RS as HIGH to send DATA
	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_RW,Low);   // set Value of RW as LOW to Write on LCD
	DIO_voidSetPortValue(LCD_DATAPORT,copy_u8Char);// Display on port of data

	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_E,High);   // set Value of E as HIGH ( enable pulse)
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRLPORT,LCD_E,Low);   //  set Value of E as LOW ( unenable pulse)

#elif LCD_MODE  == FOUR_PIN
	DIO_voidSetPinValue(LCD4_RS_PORT,LCD4_RS_PIN,High); // set Value of RS as HIGH to send DATA
	DIO_voidSetPinValue(LCD4_RW_PORT,LCD4_RW_PIN,Low);// set Value of RW as LOW to Write on LCD
	/********************************************************************************/
	/************* write DATA on Most port of data********************************/
	DIO_voidSetPinValue(LCD4_D7_PORT,LCD4_D7_PIN,get_Bit(copy_u8Char,PIN7));
	DIO_voidSetPinValue(LCD4_D6_PORT,LCD4_D6_PIN,get_Bit(copy_u8Char,PIN6));
	DIO_voidSetPinValue(LCD4_D5_PORT,LCD4_D5_PIN,get_Bit(copy_u8Char,PIN5));
	DIO_voidSetPinValue(LCD4_D4_PORT,LCD4_D4_PIN,get_Bit(copy_u8Char,PIN4));

	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,Low);
	_delay_ms(2);
	/********************************************************************************/
	/************* write DATA on Least port of data********************************/
	DIO_voidSetPinValue(LCD4_D7_PORT,LCD4_D7_PIN,get_Bit(copy_u8Char,PIN3));
	DIO_voidSetPinValue(LCD4_D6_PORT,LCD4_D6_PIN,get_Bit(copy_u8Char,PIN2));
	DIO_voidSetPinValue(LCD4_D5_PORT,LCD4_D5_PIN,get_Bit(copy_u8Char,PIN1));
	DIO_voidSetPinValue(LCD4_D4_PORT,LCD4_D4_PIN,get_Bit(copy_u8Char,PIN0));

	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,High);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD4_E_PORT,LCD4_E_PIN,Low);
	_delay_ms(2);
#endif
}

void LCD_voidGoToXY(u8 copy_u8Coloumn,u8 copy_u8Row)
{
	u8 adress =0x80;
	if(copy_u8Row == 0 )
	{
		adress += copy_u8Coloumn;
	}
	else if(copy_u8Row == 1)
	{
		adress += (copy_u8Coloumn + 0x40);

	}
	else if(copy_u8Row == 2)
	{
		adress += (copy_u8Coloumn + 0x14);

	}
	else if(copy_u8Row == 3)
	{
		adress += (copy_u8Coloumn + 0x54);
	}
	LCD_voidWriteCommand(adress);
}

void LCD_voidWriteString(char *copy_u8Char)
{
	u8 count = 0 ;
	while(copy_u8Char[count]!='\0')
	{
		LCD_voidWriteChar(copy_u8Char[count]);
		count++;
	}
}

void LCD_voidWriteNumber(s16 copy_u8Num)
{
	u8 Number[10];
	u8 count = 0;
	do
	{
		Number[count] = (copy_u8Num%10) + '0' ;
		copy_u8Num /=10;
		count++;

	}while(copy_u8Num!= 0);
	for(int i =(count-1);i >=0 ;i--)
	{
		LCD_voidWriteChar(Number[i]);
	}
}

void LCD_voidCreatCustmChar(u8 copy_u8Adress,u8 *customChar)
{
	u8 count = 0;
	LCD_voidWriteCommand((copy_u8Adress*8)+0x40);
	for(count = 0;count <=7 ;count++)
	{
		LCD_voidWriteChar(customChar[count]);
	}
}



/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/
/********************************FYAD IN ARABIC****************************************/
/*
u8 f[] = {
  0x00,
  0x02,
  0x00,
  0x07,
  0x05,
  0x1F,
  0x00,
  0x00
};
u8 y[] = {
  0x00,
  0x00,
  0x00,
  0x01,
  0x01,
  0x1F,
  0x0A,
  0x00
};
u8 a[] = {
  0x00,
  0x04,
  0x04,
  0x04,
  0x04,
  0x07,
  0x00,
  0x00
};

u8 d[] = {
  0x00,
  0x04,
  0x03,
  0x15,
  0x17,
  0x08,
  0x00,
  0x00
};

LCD_voidCreatCustmChar(0,f);
LCD_voidCreatCustmChar(1,y);
LCD_voidCreatCustmChar(2,a);
LCD_voidCreatCustmChar(3,d);
*/
