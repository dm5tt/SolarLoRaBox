/*
 * task_uart.c
 *
 *  Created on: Jan 17, 2025
 *      Author: had
 */

#include <stdio.h>

#include "spi.h"
#include "gpio.h"
#include "app_freertos.h"

void task_flash(void *argument) {

	/* 0x90 = Read Device ID
	 * 0x00 0x00 0x00 0x00 = Dummy Address
	 */
	uint8_t request[4] = { 0x90, 0x00, 0x00, 0x00 };

	uint8_t response[2] = { 0 };


	/* Infinite loop */
	for (;;) {
		osDelay(1000);

		HAL_GPIO_WritePin(GPIOA, FLASH_CS_Pin, GPIO_PIN_RESET);

		HAL_SPI_Transmit(&hspi2, request, sizeof(request), HAL_MAX_DELAY);
		HAL_SPI_Receive(&hspi2, response, sizeof(response), HAL_MAX_DELAY);

		HAL_GPIO_WritePin(GPIOA, FLASH_CS_Pin, GPIO_PIN_SET);

		printf("Flash ID: ");

		for (size_t tmp = 0; tmp < sizeof(response); tmp++) {
			printf("%x ", response[tmp]);
		}

		printf("\r\n");

	}
	/* USER CODE END defaultTask */
}
