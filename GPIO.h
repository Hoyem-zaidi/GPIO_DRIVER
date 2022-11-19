

#ifndef __GPIO_H
#define __GPIO_H
#include <stdint.h>

    
#define GPIOA (uint32_t*)0x40020000 

#define GPIOB (uint32_t*)0x40020400 

#define GPIOC (uint32_t*)0x40020800 

#define GPIOD (uint32_t*)0x40020c00 


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define INPUT         0x0u
#define OUTPUT        0x1u
#define ALTERNATE     0x2u
#define ANALOG_INPUT  0x3u

#define OUTPUT_PUSH_PULL    0x0u
#define OUTPUT_OPEN_DRAIN   0x1u

#define LOW_SPEED         0x0u
#define MEDIUM_SPEED      0x1u
#define HIGH_SPEED     0x2u
#define VERY_HIGH_SPEED  0x3u

#define SET  1u
#define RESET  0u

 void GPIO_Clock_Enable(uint32_t *GPIOx);
 void GPIO_Config(uint32_t *GPIOx,uint8_t Pin, uint8_t Mode, uint8_t Type, uint8_t Speed);
 
 void GPIO_Write_Port(uint32_t *GPIOx, uint16_t PortValue );
 void GPIO_Write_Pin(uint32_t *GPIOx,uint8_t Pin, uint8_t PinValue );
 
 uint16_t GPIO_Read_Port (uint32_t *GPIOx);
 uint8_t GPIO_Read_Pin (uint32_t *GPIOx, uint8_t Pin); 
#endif