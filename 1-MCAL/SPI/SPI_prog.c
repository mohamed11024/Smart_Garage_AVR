/*
 * SPI_prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: LENOVO
 */

#include"../../common/STD_types.h"
#include"../../common/Bit_Math.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include"SPI_register.h"

u8 * SPI_recieve = NULL_PTR;
u8 * SPI_recieveFalg = NULL_PTR;

void SPI_voidInit(void)
{
	SPCR_REG ->SPIE = DISABLE        ; //Interrupt Enable
	SPCR_REG ->MSTR = MS_SELECT     ;//(Master =1) /(Slave =0) Select
#if MS_SELECT == MASTER
	DIO_voidSetPinDir(GroupB,PIN4,Output); // make ss output
	DIO_voidSetPinDir(GroupB,PIN5,Output); //MOSI Master O/P
	DIO_voidSetPinDir(GroupB,PIN6,Input);  // MISO Master I/P
	DIO_voidSetPinDir(GroupB,PIN7,Output); //clock as Output
#elif MS_SELECT == SLAVE
	DIO_voidSetPinDir(GroupB,PIN4,Input); // make ss Input
	DIO_voidSetPinDir(GroupB,PIN5,Input); //MOSI Slave Input
	DIO_voidSetPinDir(GroupB,PIN6,Output);  // MISO Slave Output
	DIO_voidSetPinDir(GroupB,PIN7,Input);   //clock as Input
#endif
	SPCR_REG ->CPOL = Clock_Polarity;//When this bit is written to one, SCK is high when idle. When CPOL is written to zero,
	SPCR_REG ->CPHA = Clock_PHASE   ;//data is sampled on the leading(first) or trailing (last) edge of SCK.
	/********************Oscillator Clock frequency fosc = fosc/8***************/
	SPCR_REG ->SPR0 = 0b01          ;
	SPCR_REG ->SPR1 = 0b0           ;
	SPSR_REG ->SPI2X= 0b01          ;
	/******************************************************************/
	SPCR_REG ->SPE  = ENABLE        ; //SPI Enable
}
u8 SPI_u8SentReceive(u8 copy_u8Data)
{
	SPDR_REG = copy_u8Data ;
	while(SPSR_REG ->SPIF == 0);
	return SPDR_REG ;
}
void SPI_u8SentReceiveAsynch(u8 copy_u8Data,u8*Receive,u8*Flag)
{
	SPCR_REG ->SPIE = ENABLE       ; //Interrupt Enable
	SPI_recieve = Receive;
	*Flag = 0 ;
	SPI_recieveFalg=Flag;
	SPDR_REG = copy_u8Data ;
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	*SPI_recieve = SPDR_REG;
	*SPI_recieveFalg = 1;
}
