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

#define NO_DELAY 0
#define STD_DELAY 5

uint8_t trig_status_buff[30];

void MP3_get_trigger_status(UART_HandleTypeDef *huart1);
void MP3_wait_for_song_finish(UART_HandleTypeDef *huart1);
void MP3_run_trig_cmd(UART_HandleTypeDef *huart1, uint8_t, uint8_t, uint16_t);

#endif /* INC_MP3_TRIGGER_H_ */
