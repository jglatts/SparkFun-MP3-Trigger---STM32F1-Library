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

MP3_STATE MP3_UART_Init(UART_HandleTypeDef* huart1) {
	  huart1->Instance = USART1;
	  huart1->Init.BaudRate = 38400;
	  huart1->Init.WordLength = UART_WORDLENGTH_8B;
	  huart1->Init.StopBits = UART_STOPBITS_1;
	  huart1->Init.Parity = UART_PARITY_NONE;
	  huart1->Init.Mode = UART_MODE_TX_RX;
	  huart1->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	  huart1->Init.OverSampling = UART_OVERSAMPLING_16;
	  return (HAL_UART_Init(huart1) == HAL_OK) ? MP3_OK : MP3_ERROR;
}

void MP3_Run_Trig_Cmd(UART_HandleTypeDef* const huart1, uint8_t cmd, uint8_t num, uint16_t delay)
{
	HAL_UART_Transmit(huart1, &cmd, sizeof(cmd), HAL_MAX_DELAY);
	HAL_UART_Transmit(huart1, &num, sizeof(num), HAL_MAX_DELAY);
	HAL_Delay(delay);
}

void MP3_Play_Song(UART_HandleTypeDef* const huart1, uint8_t song_num)
{
	MP3_Run_Trig_Cmd(huart1, 'p', song_num, 300);
}

void MP3_Get_Trigger_Status(UART_HandleTypeDef* const huart1)
{
	MP3_Run_Trig_Cmd(huart1, 'S', '1', NO_DELAY);
	HAL_UART_Receive(huart1, trig_status_buff, sizeof(trig_status_buff), 50);
}

void MP3_Wait_For_Song_Finish(UART_HandleTypeDef* const huart1)
{
	uint8_t trig_msg = 0;
	while (trig_msg == 0)
	{
		HAL_UART_Receive(huart1, &trig_msg, sizeof(trig_msg), 50);
	}
}
