/*
 * mp3_trigger.h
 *
 * Header file for SparkFun MP3 Trigger library
 *
 *  Created on: Nov 27, 2020
 *      Author: johng
 */
#ifndef INC_MP3_TRIGGER_H_
#define INC_MP3_TRIGGER_H_

#include "stm32f1xx_hal.h"

typedef enum {
	MP3_ERROR,
	MP3_OK
} MP3_State;

#define NO_DELAY 0
#define STD_DELAY 5

uint8_t trig_status_buff[30];

MP3_State MP3_UART_Init(UART_HandleTypeDef*);
MP3_State MP3_Get_Trigger_Status(UART_HandleTypeDef*);
MP3_State MP3_Wait_For_Song_Finish(UART_HandleTypeDef*);
void MP3_Run_Trig_Cmd(UART_HandleTypeDef*, uint8_t, uint8_t, uint16_t);
void MP3_Play_Song(UART_HandleTypeDef*, uint8_t);
void MP3_Play_All_Songs(UART_HandleTypeDef*, uint8_t);

#endif /* INC_MP3_TRIGGER_H_ */
