#include "GPIO.H"
#define GPIO_OTYPER_OFFSET (0x04/4) //car il passe à 16
#define OSPEED_OFFSET  (0x08/4)
#define ODR_OFFSET ( 0x14/4)
#define IDR_OFFSET ( 0x10/4)
void AssertValid(void)
{
  __asm("NOP");
}
void AssertFailed(void)
{
  while(1){}
}
#define EMB_ASSERT(Exp) ((Exp) ? AssertValid() : AssertFailed())

void GPIO_Clock_Enable(uint32_t *GPIOx)
                       
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  
  uint16_t *RCCAHB1 = (uint16_t*)(0x40023830);
 
  
  if (GPIOx == GPIOA)
  {
    *RCCAHB1 |= (1<<0);
  }
    
  if (GPIOx == GPIOB)
  {
    *RCCAHB1 |= (1<<1);
  }
  if (GPIOx == GPIOC)
  {
    *RCCAHB1 |= (1<<2);
  }
  if (GPIOx == GPIOD)
  {
    *RCCAHB1 |= (1<<3);
  }
    
}
 void GPIO_Config(uint32_t *GPIOx,uint8_t Pin, uint8_t Mode, uint8_t Type,uint8_t Speed )
{ 
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  EMB_ASSERT(Mode >= INPUT && Mode <= ANALOG_INPUT );
  EMB_ASSERT(Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN);
  EMB_ASSERT(Speed >= LOW_SPEED && Mode <= VERY_HIGH_SPEED );
  
  *GPIOx &= ~(0x3 << Pin*2);
  *GPIOx |= (Mode << Pin*2);
  if(Mode == OUTPUT)
  {
    *(GPIOx + GPIO_OTYPER_OFFSET) &= ~(1 << Pin);
    *(GPIOx + GPIO_OTYPER_OFFSET) |= (Type << Pin);
    
    *(GPIOx + OSPEED_OFFSET) &= ~(0X3 << Pin*2);
    *(GPIOx + OSPEED_OFFSET) |= (Speed << Pin*2);
  }
  else
  {
    //Misra
  }
}
 void GPIO_Write_Port(uint32_t *GPIOx, uint16_t PortValue )
{
   EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
   EMB_ASSERT(PortValue >=0 && PortValue <= 65535 ); // 2*16-1
   
    *(GPIOx + ODR_OFFSET) = PortValue;
}
 void GPIO_Write_Pin(uint32_t *GPIOx, uint8_t Pin, uint8_t PinValue )
 {
   EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
   EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
   EMB_ASSERT(PinValue == 0 ||  PinValue == 1 );
   
   *(GPIOx + ODR_OFFSET) &= ~(1<<Pin);
   *(GPIOx + ODR_OFFSET) |= (PinValue<<Pin);
 }

uint16_t GPIO_Read_Port (uint32_t *GPIOx)
 {
    EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
    
    return (*(GPIOx + IDR_OFFSET));
  }
uint8_t GPIO_Read_Pin (uint32_t *GPIOx, uint8_t Pin )
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  
  return ((*(GPIOx + IDR_OFFSET) >> Pin) & 1);
}
  