/*
 * SPI_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#define DATA_ORDER    MSB
#define LSB            1  //Least significant bit
#define MSB            0  //Most significant bit
/*******************************************************/
#define MS_SELECT       MASTER
#define MASTER            1
#define SLAVE             0
/*******************************************************/
#define Clock_Polarity    LOW
#define HIGH               1
#define LOW                0
/*******************************************************/
#define Clock_PHASE       LEADING
#define LEADING              0
#define TRELLING             1
/*******************************************************/

void SPI_voidInit(void);

u8 SPI_u8SentReceive(u8 copy_u8Data);

void SPI_u8SentReceiveAsynch(u8 copy_u8Data,u8*Receive,u8*Flag);
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
