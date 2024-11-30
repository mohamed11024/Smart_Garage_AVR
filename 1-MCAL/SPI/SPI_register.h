/*
 * SPI_register.h
 *
 *  Created on: Aug 15, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_

typedef struct
{
	u8 SPI2X    :1;
	u8 RESERVED :5;
	u8 WCOL     :1;
	u8 SPIF     :1;
}SPSR_REG_t;

#define SPSR_REG ((volatile SPSR_REG_t*)0x2E)

typedef struct
{
	u8 SPR0    :1;
	u8 SPR1    :1;
	u8 CPHA    :1;
	u8 CPOL    :1;
	u8 MSTR    :1;
	u8 DORD    :1;
	u8 SPE     :1;
	u8 SPIE    :1;
}SPCR_REG_t;

#define SPCR_REG   ((volatile SPCR_REG_t*)0x2D)
#define SPDR_REG   (*((volatile u8*)0x2F))

#endif /* MCAL_SPI_SPI_REGISTER_H_ */
