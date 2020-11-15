#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "delay.h"

  
void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
	
  GPIO_InitTypeDef  GPIO_InitStructure;
	delay_init(84);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  while(1){
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		Delay(0x7FFFFF);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		Delay(0x7FFFFF);
	
	}
}



