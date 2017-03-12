#include <stm32f4xx.h>

#define LCD_PORT_E
 #define LCD_RS   				 7
 #define LCD_E    				 8
 #define LCD_DB4  				 9
 #define LCD_DB5  				 10
 #define LCD_DB6  				 11
 #define LCD_DB7  				 12
#include "lcd.h"


unsigned int TimmingDelay=0;

void SysTick_Handler(void)
{
	if(TimmingDelay !=0)
  {
    TimmingDelay --;
  }
}

void Delay(unsigned int time)
{
  TimmingDelay = time;
  while(TimmingDelay !=0);
}

int main (void)
{
	
	lcd_init();
	SysTick_Config(SystemCoreClock/1000);

    
  
	while(1)
	{
		lcd_clear();
		lcd_putsf("STM32F407VET6");
		Delay(2000);	
			
	}
}
