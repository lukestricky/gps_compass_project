/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DATA_DD_Pin GPIO_PIN_2
#define DATA_DD_GPIO_Port GPIOC
#define RD_DD_Pin GPIO_PIN_3
#define RD_DD_GPIO_Port GPIOC
#define SD_CD_Pin GPIO_PIN_4
#define SD_CD_GPIO_Port GPIOC
#define CS_DD_Pin GPIO_PIN_2
#define CS_DD_GPIO_Port GPIOB
#define WR_DD_Pin GPIO_PIN_10
#define WR_DD_GPIO_Port GPIOB
#define extra2_Pin GPIO_PIN_13
#define extra2_GPIO_Port GPIOB
#define extra3_Pin GPIO_PIN_14
#define extra3_GPIO_Port GPIOB
#define DEBUG_TX_Pin GPIO_PIN_6
#define DEBUG_TX_GPIO_Port GPIOC
#define DEBUG_RX_Pin GPIO_PIN_7
#define DEBUG_RX_GPIO_Port GPIOC
#define GPS_RX_Pin GPIO_PIN_9
#define GPS_RX_GPIO_Port GPIOA
#define GPS_TX_Pin GPIO_PIN_10
#define GPS_TX_GPIO_Port GPIOA
#define button1_Pin GPIO_PIN_15
#define button1_GPIO_Port GPIOA
#define extra1_Pin GPIO_PIN_10
#define extra1_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOB
#define COMPASS_SCL_Pin GPIO_PIN_6
#define COMPASS_SCL_GPIO_Port GPIOB
#define COMPASS_SDA_Pin GPIO_PIN_7
#define COMPASS_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
