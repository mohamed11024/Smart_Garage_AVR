/*
 * I2C_register.h
 *
 *  Created on: Aug 19, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_I2C_I2C_REGISTER_H_
#define MCAL_I2C_I2C_REGISTER_H_

#define TWBR_REG      (*((volatile u8*)0x20))
#define TWDR_REG      (*((volatile u8*)0x23))

/**********************************************************/
typedef struct
{
	u8 TWGCE    : 1;//General call
	u8 TWA      : 7;//My Address

}TWAR_REG_t;

#define TWAR_REG      (((volatile TWAR_REG_t*)0x22))
/**********************************************************/
/**********************************************************/
typedef struct
{
	u8 TWIE    : 1;//TWI Interrupt Enable
	u8 Reserved: 1;
	u8 TWEN    : 1;//TWI Enable Bit
	u8 TWWC    : 1;//TWI Write Collision Flag
	u8 TWSTO   : 1;//TWI STOP Condition Bit
	u8 TWSTA   : 1;//TWI START Condition Bit
	u8 TWEA    : 1;//TWI Enable Acknowledge Bit
	u8 TWINT   : 1;//TWI Interrupt Flag

}TWCR_REG_t;

#define TWCR_REG      (((volatile TWCR_REG_t*)0x56))
/**********************************************************/
typedef struct
{
	u8 TWPS    : 2;
	u8 Reserved: 1;
	u8 TWS     : 5;
}TWSR_REG_t;

#define TWSR_REG      (((volatile TWSR_REG_t*)0x21))

/**********************************************************/


#endif /* MCAL_I2C_I2C_REGISTER_H_ */
