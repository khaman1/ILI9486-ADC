#include "main.h"
#include "ILI9486.h"
#include "Arial12x12.h"
#include "Arial24x23.h"
#include "Arial43x48_numb.h"


DigitalOut led(PC_3);



PinName LCD_DATA[8] = {D8, D9, D2, D3, D4, D5, D6, D7};
ILI9486 myLCD(BUS_8, LCD_DATA, A3, A4, A2, A1, A0); 
 
int main() 
{	
	
	
	myLCD.init();

	//myLCD.test1();
	myLCD.drawXYaxis();
	wait(1);
	
	led=1;
	myLCD.updateADCPoints();
	led=0;
	
}
