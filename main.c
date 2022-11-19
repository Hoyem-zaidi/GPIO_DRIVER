/**
  ******************************************************************************
  * @file    main.c
  * @author  Hoyem Zaidi
  * @brief   Memory management 
  * @version V1.0.0
  * @date    05-11-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "GPIO.h"
    
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
int main()
{
  GPIO_Clock_Enable(GPIOD);
  GPIO_Config(GPIOD,PIN12,OUTPUT,OUTPUT_OPEN_DRAIN, LOW_SPEED);
  GPIO_Write_Pin(GPIOD, PIN12, SET);
  GPIO_Write_Pin(GPIOD, PIN12, RESET);
  
  uint8_t ReadPinTest = GPIO_Read_Pin(GPIOD, PIN12);
 while(1)
 {
 }
  
}


/**************************************END OF FILE**************************************/
