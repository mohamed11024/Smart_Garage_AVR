/*
 * TIMER_config.h
 *
 *  Created on: Aug 7, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_
/******************************************************/

//choose TIMER0_GENERATION_MODE: 1-NORMAL0 2-PWM0 3-CTC0 4-FAST_PWM0
#define TIMER0_GENERATION_MODE   FAST_PWM0
#define NORMAL0                 0
#define PWM0                    1
#define CTC0                    2
#define FAST_PWM0               3
/******************************************************/

#define PRELOAD_VALUE           0
/******************************************************/
//Compare Output Mode, Fast PWM Mode
#define CLR_CM_SET_TOP0         0b10
#define SET_CM_CT0              0b11
/****************************************************/
// Choose PRESCALLER0 : 1-PS1 2-PS8 3-PS64 4-PS256 5-PS1024
#define PRESCALLER0     PS256
#define PS1             0b001
#define PS8             0b010
#define PS64            0b011
#define PS256           0b100
#define PS1024          0b101
/******************************************************/
#define COMPARE                  0x0f
#define DUTY_CYCLE()      (COMPARE/0xff)

typedef enum
{
	PRESCALLER1_0,
	PRESCALLER1_1,
	PRESCALLER1_8,
	PRESCALLER1_64,
	PRESCALLER1_256,
	PRESCALLER1_1024,
	PRESCALLER1_EX_Falling,
	PRESCALLER1_EX_Rising,

}PRESCALLER1;
typedef enum
{
	Normal1
}TIMER1_GENERATION_MODE;
#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
