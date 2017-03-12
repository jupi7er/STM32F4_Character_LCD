![alt text][logo]

[logo]: /Medias/CYMERA_20170312_210715.jpg "Logo Title Text 2"
# STM32F4_Character_LCD
STM32F4 simple Character LCD project without Run Time Environment configuration 
# Getting Started
1. Hardware:
  1. STM32F407VET6
  2. J-link or ST-link programmer
  3. 5v powersupply
  4. 2*16 character LCD
  5. R=100
  6. Potentiometer=1K
2. IDE:
 * I use Keil IDE for making my projects , and this project was made by µVision V5.21.1.0

# STM32F407VET6 board
For this project I used STM32F407VET6 board which comes from China ,and I don't use the original Discovery Board.
![Alt text](/Medias/-font-b-STM32F407VET6-b-font-font-b-Development-b-font-font-b-Board-b-font.jpg?raw=true "Optional Title")
# Programmer
For programming Arm Microcontrollers I've used J-link debugger and it's a clone J-link which I'm using it, it works very well for me and I've not had any big issue with it.
![Alt text](/Medias/20120421095420359.jpg?raw=true "Optional Title")
# 2*16 Character LCD
This is the common 2*16 character LCD which you can find it in everywhere.About the driver I think it's hd44780 but I'm not sure.
![Alt text](/Medias/fce6.png?raw=true "Optional Title")
# Potentiometer
We use Potentiometer for adjusting the contrast of our LCD.
# Schematic
![Alt text](/Medias/LCD.png?raw=true "Optional Title")
# Some Explanation
```c
lcd_init();
```
This function initializes the LCD.
```c
SysTick_Config(SystemCoreClock/1000);
```
In this line I used SysTick timer for making precise delays.
