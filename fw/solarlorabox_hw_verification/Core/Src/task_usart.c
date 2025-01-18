/*
 * task_uart.c
 *
 *  Created on: Jan 17, 2025
 *      Author: had
 */

#include <stdio.h>

#include "usart.h"
#include "app_freertos.h"




void task_usart(void *argument) {
	/* USER CODE BEGIN defaultTask */
	printf("Hello SolarLoraBox!\r\n");

	/* Infinite loop */
	for (;;) {
		osDelay(1000);
	}
	/* USER CODE END defaultTask */
}
