/*
 * mp3_trigger.c
 *
 * Implementation file for SparkFun MP3 Trigger library
 *
 *  Created on: Nov 27, 2020
 *      Author: johng
 */
#include "stm32f1xx_hal.h"
#include "mp3_trigger.h"

void MP3_run_trig_cmd(UART_HandleTypeDef* const huart1, uint8_t cmd, uint8_t num, uint16_t delay)
{
	HAL_UART_Transmit(huart1, &cmd, sizeof(cmd), HAL_MAX_DELAY);
	HAL_UART_Transmit(huart1, &num, sizeof(num), HAL_MAX_DELAY);
	HAL_Delay(delay);
}

void MP3_get_trigger_status(UART_HandleTypeDef* const huart1)
{
	MP3_run_trig_cmd(huart1, 'S', '1', NO_DELAY);
	HAL_UART_Receive(huart1, trig_status_buff, sizeof(trig_status_buff), 50);
}

void MP3_wait_for_song_finish(UART_HandleTypeDef* const huart1)
{
	uint8_t trig_msg = 0;
	while (trig_msg == 0)
	{
		HAL_UART_Receive(huart1, &trig_msg, sizeof(trig_msg), 50);
	}

}


