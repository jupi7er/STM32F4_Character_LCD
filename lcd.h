

#ifndef lcd_INCLUDED_
#define lcd_INCLUDED_


#ifdef   LCD_PORT_A
#define  PIO_enable	   				RCC->AHB1ENR |= 1<<0 
#define  PIO_SetOutput	   		GPIOA->ODR 
#define  PIO_ClearOutput	   	GPIOA->ODR
#define  PIO_CfgOutput  			GPIOA->MODER
#endif

#ifdef   LCD_PORT_B
#define  PIO_enable	   				RCC->AHB1ENR |= 1<<1
#define  PIO_SetOutput	      GPIOB->ODR 
#define  PIO_ClearOutput	   	GPIOB->ODR
#define  PIO_CfgOutput  			GPIOB->MODER
#endif

#ifdef   LCD_PORT_C
#define  PIO_enable	   				RCC->AHB1ENR |= 1<<2
#define  PIO_SetOutput	      GPIOC->ODR 
#define  PIO_ClearOutput	   	GPIOC->ODR
#define  PIO_CfgOutput  			GPIOC->MODER
#endif

#ifdef   LCD_PORT_D
#define  PIO_enable	   				RCC->AHB1ENR |= 1<<3
#define  PIO_SetOutput	      GPIOD->ODR 
#define  PIO_ClearOutput	   	GPIOD->ODR
#define  PIO_CfgOutput  			GPIOD->MODER
#endif

#ifdef   LCD_PORT_E
#define  PIO_enable	   				RCC->AHB1ENR |= 1<<4
#define  PIO_SetOutput	      GPIOE->ODR 
#define  PIO_ClearOutput	   	GPIOE->ODR
#define  PIO_CfgOutput  			GPIOE->MODER
#endif

#define F_CPU 28000000
#define clcd_minDelay()	cwait(F_CPU/10000)
#define clcd_Delay()	cwait(F_CPU/1000)
void lcd_init(void);
void lcd_putchar(char ch);
void lcd_command(char cmd);
void lcd_gotoxy(char x, char y);
void lcd_clear(void);
void lcd_clear_line(char y);
void lcd_shift_left(char n);
void lcd_shift_right(char n);
void lcd_puts(int num);
void lcd_putsf(char* data);
void lcd_define_char(const char *pc,char char_code);
//=========================================================
void cwait (volatile int t) {
  for (;t; t--);
}
// ============================================================================
void setD4567(char val)
{
	PIO_ClearOutput &= ~((1<<LCD_DB4)|(1<<LCD_DB5)|(1<<LCD_DB6)|(1<<LCD_DB7));
	if (val & 0x80)
		PIO_SetOutput |=(1<<LCD_DB7);
	if (val & 0x40)
		PIO_SetOutput |=(1<<LCD_DB6);
	if (val & 0x20)
		PIO_SetOutput |=(1<<LCD_DB5);
	if (val & 0x10)
		PIO_SetOutput |=(1<<LCD_DB4);
}
// ============================================================================
void lcd_putchar(char ch)
{
	PIO_SetOutput |=(1<<LCD_RS);
	setD4567(ch);
	PIO_SetOutput|=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput &= ~(1<<LCD_E);
	clcd_minDelay();
	setD4567(ch<<4);
	PIO_SetOutput|=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput&= ~(1<<LCD_E);
	clcd_Delay();
}
// ============================================================================
void lcd_command(char cmd)	//Sends Command to LCD
{
	PIO_ClearOutput&= ~(1<<LCD_RS);
	setD4567(cmd);
	PIO_SetOutput |=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput&= ~(1<<LCD_E);
	clcd_minDelay();
	setD4567(cmd<<4);
	PIO_SetOutput |=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput &= ~(1<<LCD_E);
	clcd_Delay();
}
// ============================================================================
void config_pin(int x)
{
		switch (x)
	{
		case 0 :
		{
			PIO_CfgOutput &= 0xFFFFFFFC;
			PIO_CfgOutput |= (0<<1 | 1<<0);	
			break;
		}
		case 1 :
		{
			PIO_CfgOutput &= 0xFFFFFFF3;
			PIO_CfgOutput |= (0<<3 | 1<<2);
			break;
		}
		case 2 :
		{
			PIO_CfgOutput &= 0xFFFFFFCF;
			PIO_CfgOutput |= (0<<5 | 1<<4);
			break;
		}
		case 3 :
		{	
			PIO_CfgOutput &= 0xFFFFFF3F;
			PIO_CfgOutput |= (0<<7 | 1<<6);
			break;
		}
		case 4 :
		{
			PIO_CfgOutput &= 0xFFFFFCFF;
			PIO_CfgOutput |= (0<<9 | 1<<8);
			break;
		}
		case 5 :
		{
			PIO_CfgOutput &= 0xFFFFF3FF;
			PIO_CfgOutput |= (0<<11 | 1<<10);
			break;
		}
		case 6 :
		{
			PIO_CfgOutput &= 0xFFFFCFFF;
			PIO_CfgOutput |= (0<<13 | 1<<12);
			break;
		}
		case 7 :
		{
			PIO_CfgOutput &= 0xFFFF3FFF;
			PIO_CfgOutput |= (0<<15 | 1<<14);
			break;
		}
		case 8 :
		{
			PIO_CfgOutput &= 0xFFFCFFFF;
			PIO_CfgOutput |= (0<<17 | 1<<16);
			break;
		}
		case 9 :
		{
			PIO_CfgOutput &= 0xFFF3FFFF;
			PIO_CfgOutput |= (0<<19 | 1<<18);
			break;
		}
		case 10 :
		{
			PIO_CfgOutput &= 0xFFCFFFFF;
			PIO_CfgOutput |= (0<<21 | 1<<20);
			break;
		}
		case 11 :
		{
			PIO_CfgOutput &= 0xFF3FFFFF;
			PIO_CfgOutput |= (0<<23 | 1<<22);
			break;
		}
		case 12 :
		{
			PIO_CfgOutput &= 0xFCFFFFFF;
			PIO_CfgOutput |= (0<<25 | 1<<24);
			break;
		}
		case 13 :
		{
			PIO_CfgOutput &= 0xF3FFFFFF;
			PIO_CfgOutput |= (0<<27 | 1<<26);
			break;
		}
		case 14 :
		{
			PIO_CfgOutput &= 0xCFFFFFFF;
			PIO_CfgOutput |= (0<<29 | 1<<28);
			break;
		}
		case 15 :
		{
			PIO_CfgOutput &= 0x3FFFFFFF;
			PIO_CfgOutput |= (0<<31 | 1<<30);
			break;
		}
	}
}
void lcd_init()
{
	PIO_enable;
	config_pin(LCD_RS);
	config_pin(LCD_E);
	config_pin(LCD_DB4);
	config_pin(LCD_DB5);
	config_pin(LCD_DB6);
	config_pin(LCD_DB7);	
	clcd_Delay();
	setD4567(0);
	setD4567((1<<5)|(1<<4));
	PIO_SetOutput|=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput &= ~(1<<LCD_E);
	clcd_Delay();
	setD4567((1<<5)|(1<<4));
	PIO_SetOutput |=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput &= ~(1<<LCD_E);
	clcd_Delay();
	setD4567(1<<5);
	PIO_SetOutput |= (1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput &= ~(1<<LCD_E);
	clcd_Delay();
	lcd_command(0x28);
	lcd_command(0x0c);
	clcd_Delay();
}
//=============================================================================
void lcd_gotoxy(char y, char x)	//Cursor to X Y position
{
	char DDRAMAddr;
x=x-1;
	switch(y)
	{
		case 1: DDRAMAddr = 0x00+x; break;
		case 2: DDRAMAddr = 0x40+x; break;
		case 3: DDRAMAddr = 0x14+x; break;
		case 4: DDRAMAddr = 0x54+x; break;
		default: DDRAMAddr = 0x00+x;
	}
	lcd_command(1<<7 | DDRAMAddr);
}
// ============================================================================
void lcd_define_char(const char *pc,char char_code)
{
	char a , i;
	a = ((char_code<<3)|0x40) & 0xff;
	for (i = 0; i < 8 ;i++)
	{
		lcd_command(a++);
		clcd_Delay();
		lcd_putchar(pc[i]);
		clcd_Delay();
	}
}
// ============================================================================
void lcd_clear(void)				//Clears LCD
{
	lcd_command(0x01);
lcd_command(0x02);
	clcd_Delay();
	clcd_Delay();
}
//============================================================
void lcd_shift_left(char n)	//Scrol n of characters Right
{
	char i;
	for (i = 0 ; i < n ; i++)
	{
		lcd_command(0x1E);
		clcd_Delay();
	}
}
//========================================================
void lcd_shift_right(char n)	//Scrol n of characters Left
{
	char i;
	for (i = 0 ; i < n ; i++)
	{
		lcd_command(0x18);
		clcd_Delay();
	}
}

// ============================================================================
void lcd_puts(int num)
{
 int i,j;
 char zero,ch[10];
 if(num==0)
   {
    zero=num;
    zero+=48;
    lcd_putchar(zero);
   }
  else if(num>0)
    { 
     for(i=0;num>0;i++)
        {
         ch[i]=num%10;
         num/=10;
        }
     for(j=i-1;j>=0;j--)
        {
         ch[j]+=48;
         lcd_putchar(ch[j]);
        }
    }
  else if(num<0)
    {
     num*=-1;
     for(i=0;num>0;i++)
        {
         ch[i]=num%10;
         num/=10;
        }
     lcd_putchar('-');
     for(j=i-1;j>=0;j--)
        {
         ch[j]+=48;
         lcd_putchar(ch[j]);
        }
    }
}
//=============================================================================
void lcd_putsf(char* data)	//Outputs string to LCD
{
	char *p;
	p = data;
	if (!p)
		return;
	for(; *p ; )
	{
		lcd_putchar(*p);
		p++;
	}
}
//=============================================================
void Display_off(void)
{
	lcd_command(0x08);
	clcd_Delay();
}
//=============================================================
void Display_on(void)
{
	lcd_command(0x0C);
	clcd_Delay();
}
//=============================================================
void cursor_off(void)
{
	lcd_command(0x0C);
	clcd_Delay();
}
//=============================================================
void cursor_on(void)
{
	lcd_command(0x0E);
	clcd_Delay();
}
//=============================================================
void cursor_blink(void)
{
	lcd_command(0x0F);
	clcd_Delay();
}
#endif
