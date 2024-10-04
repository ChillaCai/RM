//
// Created by chill on 2024/10/3.
//
#include "main.h"
#include "usart.h"

extern uint8_t rx_buff[BUFFSIZE];
extern uint8_t tx_buff[BUFFSIZE];
extern volatile uint8_t tx_flag;
extern volatile uint8_t head;
extern volatile uint8_t tail;
extern volatile HAL_StatusTypeDef rx_status;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  if (huart == &huart6){
    tx_buff[tail] = rx_buff[0];
    tail = (tail + 1) % BUFFSIZE;
    HAL_UART_Receive_IT(&huart6, rx_buff, 1);
  }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  tx_flag = 0;
}
