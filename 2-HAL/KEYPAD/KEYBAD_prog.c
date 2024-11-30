/*
 * KEYBAD_prog.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Mo
 */
#include"../../common/Bit_Math.h"
#include"../../common/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KEYBAD_config.h"
#include "KEYBAD_interface.h"
static u8 KEYPAD_u8GetValue();

u8 COLOUMN[4] ={COLOUMN_PIN0,COLOUMN_PIN1,COLOUMN_PIN2,COLOUMN_PIN3};
u8 ROW[4]     ={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};
u8 KEYPAD[4][4]={{'7','8','9','/'},
		         {'4','5','6','*'},
		         {'1','2','3','-'},
		         {'C','0','=','+'}};


void KEYPAD_voidInit(void)
{
	DIO_voidSetPinDir(COLOUMN_PORT,COLOUMN_PIN0,Input);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN_PIN0,High);

	DIO_voidSetPinDir(COLOUMN_PORT,COLOUMN_PIN1,Input);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN_PIN1,High);

	DIO_voidSetPinDir(COLOUMN_PORT,COLOUMN_PIN2,Input);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN_PIN2,High);

	DIO_voidSetPinDir(COLOUMN_PORT,COLOUMN_PIN3,Input);
	DIO_voidSetPinValue(COLOUMN_PORT,COLOUMN_PIN3,High);

	DIO_voidSetPinDir(ROW_PORT,ROW_PIN0,Output);
	DIO_voidSetPinDir(ROW_PORT,ROW_PIN1,Output);
	DIO_voidSetPinDir(ROW_PORT,ROW_PIN2,Output);
	DIO_voidSetPinDir(ROW_PORT,ROW_PIN3,Output);

	DIO_voidSetPinValue(ROW_PORT,ROW_PIN0,High);
	DIO_voidSetPinValue(ROW_PORT,ROW_PIN1,High);
	DIO_voidSetPinValue(ROW_PORT,ROW_PIN2,High);
	DIO_voidSetPinValue(ROW_PORT,ROW_PIN3,High);
}



static u8 KEYPAD_u8GetValue()
{
	u8 count_C,count_R;
	u8 Value = 0;

	for(count_R = 0;count_R < 4 ;count_R++)
	{
		DIO_voidSetPinValue(ROW_PORT,ROW[count_R],Low);
		for(count_C = 0;count_C < 4 ;count_C++)
		{
			u8 getValue = DIO_u8GetPinValue(COLOUMN_PORT,COLOUMN[count_C]);
			if(getValue == Low)
			{
				while(DIO_u8GetPinValue(COLOUMN_PORT,COLOUMN[count_C]) == Low);
				DIO_voidSetPinValue(ROW_PORT,ROW[count_R],High);
				Value = KEYPAD[count_C][count_R];
				return Value;
			}
		}
		DIO_voidSetPinValue(ROW_PORT,ROW[count_R],High);
	}
	return KEYPAD_NO_PRESSED_KEY;
}

u8 KEYPAD_u8GetKeyValue(){
	u8 key=KEYPAD_u8GetValue();
	while(key == 0xff){
		key=KEYPAD_u8GetValue();
	}
	return key;
}

