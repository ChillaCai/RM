//
// Created by chill on 2024/10/3.
//
#include "main.h"
#include "tim.h"
#include "usart.h"

extern uint8_t rx_buff[8];
extern uint8_t tx_buff[8];
extern volatile uint8_t tx_flag;
extern volatile uint8_t rx_flag;
extern volatile uint8_t head;
extern volatile uint8_t tail;
extern const uint8_t tx_size;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  if (huart == &huart6){
    tx_buff[tail] = rx_buff[0];

    HAL_UART_Receive_DMA(&huart6, rx_buff, 1);
  }
}

//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
//  tx_flag = 0;
//}
