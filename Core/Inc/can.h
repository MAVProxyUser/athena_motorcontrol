/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    can.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

#ifdef STM32F446
extern CAN_HandleTypeDef hcan1;

/* USER CODE BEGIN Private defines */
#endif
//#define P_MIN -12.5f
//#define P_MAX 12.5f
//#define V_MIN -65.0f
//#define V_MAX 65.0f
#define KP_MIN 0.0f
//#define KP_MAX 500.0f
#define KD_MIN 0.0f
//#define KD_MAX 5.0f
#define T_MIN -18.0f
#define T_MAX 18.0f
#ifdef STM32F446
/* USER CODE END Private defines */

void MX_CAN1_Init(void);

/* USER CODE BEGIN Prototypes */
typedef struct{
	uint8_t id;
	uint8_t data[8];
	CAN_RxHeaderTypeDef rx_header;
	CAN_FilterTypeDef filter;
}CANRxMessage ;

typedef struct{
	uint8_t id;
	uint8_t data[6];
	CAN_TxHeaderTypeDef tx_header;
}CANTxMessage ;

void can_rx_init(CANRxMessage *msg);
void can_tx_init(CANTxMessage *msg);
void pack_reply(CANTxMessage *msg, uint8_t id, float p, float v, float t);
void unpack_cmd(CANRxMessage msg, float *commands);
/* USER CODE END Prototypes */

#else
void can_rx_init(can_receive_message_struct *msg);
void can_tx_init(can_trasnmit_message_struct *msg);
void pack_reply(can_trasnmit_message_struct *msg, uint8_t id, float p, float v, float t);
void unpack_cmd(can_receive_message_struct msg, float *commands);

void MX_CAN0_Init(void);
#endif
#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

