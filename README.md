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

The number of ADC samples is defined as ADC_SAMPLES_SIZE in ILI9486_funcs.cpp and the array ADCval[ADC_SAMPLES_SIZE] to store 2000 collected samples. Since the way to display the samples on screen depends on ADC_SAMPLES_SIZE, so the function updateADCPoints() to show up the samples is constrained to 2000, so then 2000 samples splits into 400 pairs of 5 and each maximum value of 5 is used to display on the screen as a color.

If you want to generally run a test on LCD to see the pixels or how the LCD generally functions, so run the command myLCD.test1().

The code is written by C++

## INSTALLATION    
- Install Keil ARM, Keil.STM32F4xx_DFP.2.13.0, ST-Link driver
- Open the main project Nucleo_read_analog_value.uvprojx by Keil to upload the code
- Enjoy

## DEMO
[Latest vid](https://www.youtube.com/watch?v=H7QsbLGEz44)

![ScreenShot](https://raw.githubusercontent.com/khaman1/ILI9486-ADC/master/Demo/20180724_190016.jpg)
