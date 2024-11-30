/*
 * Sev_config.h
 *
 *  Created on: Jul 25, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SEV_SEG_SEV_CONFIG_H_
#define HAL_SEV_SEG_SEV_CONFIG_H_


/***********************************one 7 segment***********************/
#define SEV_PORT               GroupB //Port is used by 7 segment
//Choose if 7 segment is CATHODE or ANODE .
#define SEV_TYPE               CATHODE

#define ANODE   0
#define CATHODE 1
/************************************************************************/
/***********************************Multi 7 segment***********************/
#define SEV_PORT_PINS          GroupD //Port is used by common pins of 7 segment
#define SEV_PIN_COMMON_0       PIN0 // comon bin of 7 segment 1
#define SEV_PIN_COMMON_1       PIN1 // comon bin of 7 segment 1
#define TIME                   1000    //time(in ms) needed to display number
/************************************************************************/

#endif /* HAL_SEV_SEG_SEV_CONFIG_H_ */
