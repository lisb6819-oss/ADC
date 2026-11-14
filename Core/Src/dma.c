/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    dma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "dma.h"
#include "adc.h"
#include "stm32f1xx_hal_def.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>

/* USER CODE BEGIN 0 */
extern uint16_t values[4];
extern char message[50];

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/* USER CODE BEGIN 2 */
 void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
  if (hadc = &hadc1) {
    sprintf(message, "%d %d %d %d",values[0],values[1],values[2],values[3]);
    HAL_UART_Transmit(&huart2,message,strlen(message),HAL_MAX_DELAY);
  }
 }
/* USER CODE END 2 */

