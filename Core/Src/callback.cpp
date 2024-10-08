//
// Created by chill on 2024/10/3.
//
#include "main.h"
#include "usart.h"

extern uint8_t rx_buff[80];
// extern uint8_t tx_buff[8];
extern volatile uint8_t tx_flag;
extern volatile uint8_t rx_flag;
extern volatile uint8_t head;
extern volatile uint8_t tail;
extern const uint8_t tx_size;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
  if (huart == &huart6){
    HAL_UART_Transmit_DMA(huart, rx_buff, Size);
    HAL_UARTEx_ReceiveToIdle_DMA(&huart6, rx_buff, sizeof(rx_buff));
  }
}

//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
//  tx_flag = 0;
//}
