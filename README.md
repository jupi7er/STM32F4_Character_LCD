![alt text][logo]

[logo]: /Medias/6299.jpg "Logo Title Text 2"
# STM32_GPIO_RTEcfg
STM32F4 Blinky project with Run Time Environment 
# Getting Started
1. Hardware:
  1. STM32F407VET6
  2. J-link or ST-link programmer
  3. 5v powersupply
2. IDE:
 * I use Keil IDE for making my projects , and this project was made by µVision V5.21.1.0

# STM32F407VET6 board
For this project I used STM32F407VET6 board which comes from China ,and I don't use the original Discovery Board.
![Alt text](/Medias/-font-b-STM32F407VET6-b-font-font-b-Development-b-font-font-b-Board-b-font.jpg?raw=true "Optional Title")
# Programmer
For programming Arm Microcontrollers I've used J-link debugger and it's a clone J-link which I'm using it, it works very well for me and I've not had any big issue with it.
![Alt text](/Medias/20120421095420359.jpg?raw=true "Optional Title")
# Some Explanation
```c
GPIOA->MODER = 1<<12;
GPIOA->ODR = 1<<6;        /* PA6 defined as Output */
GPIOA->BSRR = 1<<6;        /* turn off  the LED */
```
In these three lines I configured PA6 as an output pin(I used PA6 becuase this pin connected to an onboard LED on my STM board)
```c
SysTick_Config(SystemCoreClock/1000);
```
In this line I used SysTick timer for making Precise delays.
```c
GPIOA->BSRR = 1<<6;
Delay(1);	
GPIOA->BSRR = 1<<22;
Delay(1);
```
We use BSRR register for toggling outputs.
