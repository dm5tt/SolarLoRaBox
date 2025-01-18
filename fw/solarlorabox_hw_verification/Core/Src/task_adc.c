/*
 * task_adc.c
 *
 *  Created on: Jan 18, 2025
 *      Author: had
 */

#include <stdio.h>

#include "adc.h"
#include "app_freertos.h"

/* Function to read specific ADC channel */
uint16_t read_adc_channel(uint32_t channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    /* Configure for the selected ADC channel */
    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;

    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    {
        Error_Handler();
    }

    /* Start ADC conversion */
    HAL_ADC_Start(&hadc1);

    /* Wait for conversion complete */
    if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK)
    {
        return HAL_ADC_GetValue(&hadc1);
    }

    return 0;
}

/* Function to read both ADC channels and calculate voltages */
void read_adc_voltages(void)
{
    uint16_t adc_raw6, adc_raw7;
    float voltage6, voltage7;
    float vref = 3.0f;  // Internal VREF voltage

    /* Variables for voltage divider calculations */
    float r1_ch6 = 1.0f;  // Add your voltage divider R1 value for channel 6
    float r2_ch6 = 1.0f;  // Add your voltage divider R2 value for channel 6
    float r1_ch7 = 910.0f;  // Add your voltage divider R1 value for channel 7
    float r2_ch7 = 130.0f;  // Add your voltage divider R2 value for channel 7
    float divided_voltage6, divided_voltage7;

    /* Read ADC channel 6 */
    adc_raw6 = read_adc_channel(ADC_CHANNEL_6);

    /* Read ADC channel 7 */
    adc_raw7 = read_adc_channel(ADC_CHANNEL_7);

    /* Calculate voltages using VREF */
    voltage6 = (float)adc_raw6 * vref / 4095.0f;  // For 12-bit ADC
    voltage7 = (float)adc_raw7 * vref / 4095.0f;  // For 12-bit ADC

    /* Calculate actual input voltages considering voltage dividers */
    /* Uncomment and modify when you have your voltage divider values */

    divided_voltage6 = voltage6 * ((r1_ch6 + r2_ch6) / r2_ch6);
    divided_voltage7 = voltage7 * ((r1_ch7 + r2_ch7) / r2_ch7);


    /* Print results */
    // printf("ADC Channel 6 Raw: %d, Voltage: %.3f V\r\n", adc_raw6, voltage6);
    // printf("ADC Channel 7 Raw: %d, Voltage: %.3f V\r\n", adc_raw7, voltage7);

    /* Uncomment to print divided voltages when voltage dividers are configured */

    printf("Channel 6 Input Voltage: %.3f V\r\n", divided_voltage6);
    printf("Channel 7 Input Voltage: %.3f V\r\n", divided_voltage7);

}


void task_adc(void *argument) {

	/* Infinite loop */
	for (;;) {
		osDelay(1000);
		read_adc_voltages();

	}
	/* USER CODE END defaultTask */
}
