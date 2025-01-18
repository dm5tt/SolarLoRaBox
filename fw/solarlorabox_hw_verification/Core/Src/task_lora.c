/*
 * task_lora.c
 *
 *  Created on: Jan 18, 2025
 *      Author: had
 */

#include <stdio.h>

#include "spi.h"
#include "gpio.h"
#include "app_freertos.h"

void task_lora(void *argument) {

	/* 0x1d = Read one or several registers
	 * 0x0320 = Product ID String
	 */
	uint8_t request[4] = { 0x1D, 0x03, 0x20 };
	uint8_t response[16] = { 0 };

	/* Infinite loop */
	for (;;) {
		osDelay(1000);

		HAL_GPIO_WritePin(GPIOA, RADIO_CS_Pin, GPIO_PIN_RESET);

		HAL_SPI_Transmit(&hspi1, request, sizeof(request), HAL_MAX_DELAY);
		HAL_SPI_Receive(&hspi1, response, sizeof(response), HAL_MAX_DELAY);

		HAL_GPIO_WritePin(GPIOA, RADIO_CS_Pin, GPIO_PIN_SET);

		printf("LoRa Product ID: %s\r\n", response);

	}
	/* USER CODE END defaultTask */
}
