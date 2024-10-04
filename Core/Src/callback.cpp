//
// Created by chill on 2024/10/3.
//
#include "main.h"
#include "tim.h"
#include "usart.h"

extern uint8_t rx_buff[8];
extern uint8_t tx_buff[8];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  if (huart == &huart6){
    tx_buff[0] = rx_buff[0];
    HAL_UART_Receive_IT(&huart6, rx_buff, 1);
  }
}

//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
//}
