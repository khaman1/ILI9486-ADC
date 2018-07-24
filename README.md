# ILI9486-ADC

This project is programmed on NUCLEO-f446re with a MCUFriend 3.5" ILI9486 display. There are some additional pins needed for the project as well:

- ADC pin: A5 (Potentiometer)
- 2 LED pins: PC3
- LCD shield: hooked into the NUCLEO as followed:

    LCD       |     NUCLEO
    
    D0-D7     |     D8, D9, D2, D3, D4, D5, D6, D7 
    
    CS        |     A3
    
    RST       |     A4 
    
    DC        |     A2
    
    WR        |     A1 
    
    RD        |     A0
    
## INSTALLATION    
- Install Keil ARM, Keil.STM32F4xx_DFP.2.13.0, ST-Link driver
- Open the main project Nucleo_read_analog_value.uvprojx by Keil to upload the code
- Enjoy

## DEMO
[Latest vid](https://www.youtube.com/watch?v=H7QsbLGEz44)

![ScreenShot](https://raw.githubusercontent.com/khaman1/ILI9486-ADC/master/Demo/20180724_190016.jpg)
