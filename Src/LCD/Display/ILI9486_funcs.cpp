// (c) 2017 Outernet Inc

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include "ILI9486.h"
#include "BUS8.h"
//#include "ADC.h"
/*******************************************************************
* NAME :            void ILI9486::set_background
*
* DESCRIPTION :    Set the full screen with a specific color
*
* INPUTS :
*       PARAMETERS:
*           color can be found in ILI9486_defs.h
*
*/
void ILI9486::fillScreen(uint16_t color)
{
	setAddrWindow (0, 0, ILI9486_TFTWIDTH - 1, ILI9486_TFTHEIGHT - 1);
	
	wr_gram(color,ILI9486_TFTWIDTH*ILI9486_TFTHEIGHT);
}


/*******************************************************************
* NAME :            void ILI9486::set_window
*
* DESCRIPTION :     Create a window in ILI9486
*
* INPUTS :
*       PARAMETERS:
*           x0,x1,y0,y1 are the 2 2-D coordinates to locate the the pointer 
*
*/
void ILI9486::setAddrWindow (uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1)
{
    writeCMD(ILI9486_CASET);
    writeU16(x0);
    writeU16(y0);
    writeCMD(ILI9486_PASET);
    writeU16(x1);
    writeU16(y1);
    writeCMD(ILI9486_RAMWR);
}

void ILI9486::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	setAddrWindow(x,y,x+1,y+1);
	wr_gram(color);
}

uint16_t ILI9486::color565(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void ILI9486::setRotation(uint8_t m) {
  writeCMD(ILI9486_MADCTL);
  rotation = m % 4; // can't be higher than 3
  switch (rotation) {
   case 0:
     writeU8(MADCTL_MX | MADCTL_BGR);
     _width  = ILI9486_TFTWIDTH;
     _height = ILI9486_TFTHEIGHT;
     break;
   case 1:
     writeU8(MADCTL_MV | MADCTL_BGR);
     _width  = ILI9486_TFTHEIGHT;
     _height = ILI9486_TFTWIDTH;
     break;
  case 2:
    writeU8(MADCTL_MY | MADCTL_BGR);
     _width  = ILI9486_TFTWIDTH;
     _height = ILI9486_TFTHEIGHT;
    break;
   case 3:
     writeU8(MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR);
     _width  = ILI9486_TFTHEIGHT;
     _height = ILI9486_TFTWIDTH;
     break;
  }

}



void ILI9486::invertDisplay(bool i) {
	writeCMD(i ? ILI9486_INVON : ILI9486_INVOFF);
}



void ILI9486::writePixels(uint16_t * colors, uint32_t len){
    for(int i=0; i<len; i++)
		writeU8(colors[i]);
}



void ILI9486::drawRGBBitmap(int16_t x, int16_t y,
	uint16_t *pcolors, int16_t w, int16_t h) {

    int16_t x2, y2; // Lower-right coord
    if(( x             >= _width ) ||      // Off-edge right
       ( y             >= _height) ||      // " top
       ((x2 = (x+w-1)) <  0      ) ||      // " left
       ((y2 = (y+h-1)) <  0)     ) return; // " bottom

    int16_t bx1=0, by1=0, // Clipped top-left within bitmap
            saveW=w;      // Save original bitmap width value
    if(x < 0) { // Clip left
        w  +=  x;
        bx1 = -x;
        x   =  0;
    }
    if(y < 0) { // Clip top
        h  +=  y;
        by1 = -y;
        y   =  0;
    }
    if(x2 >= _width ) w = _width  - x; // Clip right
    if(y2 >= _height) h = _height - y; // Clip bottom

    pcolors += by1 * saveW + bx1; // Offset bitmap ptr to clipped top-left

    setAddrWindow(x, y, w, h); // Clipped area
    while(h--) { // For each (clipped) scanline...
      writePixels(pcolors, w); // Push one (clipped) row
      pcolors += saveW; // Advance pointer by one full (unclipped) line
    }
}

void ILI9486::mirrorXY(mirror_t mode)
{
    switch (mode)
    {
        case(NONE):
         //   wr_cmd8(0xA0);
            writeCMD16(0xA0C8); // this is in real Y mirror command, but seems most displays have COMs wired inverted, so assume this is the default no-y-mirror
            break;
        case(X):
        //    wr_cmd8(0xA1);
            writeCMD16(0xA1C8);
            break;
        case(Y):
        //    wr_cmd8(0xA0);
            writeCMD16(0xA0C0);
            break;
        case(XY):
        //    wr_cmd8(0xA1);
            writeCMD16(0xA1C0);
            break;
    }
}


void ILI9486::drawHline(int x0, int y, int x1, int lineWidth, unsigned short color)
{
	for(int i=0; i<lineWidth; i++)
		drawLine(x0,y+i,x1,y+i,color);
}
void ILI9486::drawVline(int x, int y0, int y1, int lineWidth, unsigned short color)
{
	for(int i=0; i<lineWidth; i++)
		drawLine(x+i,y0,x+i,y1,color);
}

void ILI9486::drawArrow(int x, int y, int orientation)
{
	int t = 8,i;
	
	for(i=0; i<t; i++)
		switch(orientation)
		{
			case 0: // pointing UP
				for(i=0; i<t; i++)
					drawHline(x-(t-i), y-i, x+(t-i), 2, ILI9486_WHITE);
				
				break;
			
			case 1:	// pointing RIGHT
				for(i=0; i<t; i++)
					drawVline(x-(t-i), y-(t-i), y+(t-i), 2, ILI9486_WHITE);			
			
				break;
			
			case 3:	// pointing LEFT
				for(i=0; i<t; i++)
					drawVline(x+(t-i), y-(t-i), y+(t-i), 2, ILI9486_WHITE);			
			
				break;
		}		
}

void ILI9486::drawPoint(int x, int y, int pixelSize, int color)
{
	for(int i=0; i<pixelSize; i++)
		for(int j=0; j<pixelSize; j++)
			drawPixel(x+i, y-j, color);
}

void ILI9486::drawXYaxis()
{
	fillScreen(ILI9486_BLACK);
	setRotation(1);
	//drawLine
	drawHline(30,265,width()-30,3,ILI9486_WHITE);
	drawVline(30,265,30,3,ILI9486_WHITE);
	
	drawArrow(31,30,0);  // UP 		arrow
	drawArrow(width()-25,265,1);// RIGHT	arrow
	
	// drawText
	// X
	setCursor(width()-18, 258);
	setTextColor(ILI9486_WHITE);  setTextSize(2);
	print("X");
	
	// Y
	setCursor(26, 5);
	print("Y");
	
	
	
	// Draw initial points
	for(int row=0; row<16; row++)
		for(int col=0; col<25; col++)
			fillCircle(60+15*col,250-15*row,4,ILI9486_RED);

	// Button and Text
	fillRoundRect(170,275,185,36,5,ILI9486_DARKCYAN);
	
	setCursor(230, 278);
	setTextSize(2);
	print("Press");
	
	setCursor(190, 298);
	setTextSize(1);
	print("to start the calibration!");
}






#define ADC_SAMPLES_SIZE 2000
AnalogIn analog_val(A5);
Serial pc(USBTX, USBRX);



void ILI9486::updateADCPoints()
{
	int max;
	int cnt = 0;
	int val;
	int idx,row,col;
	
	if(ADC_SAMPLES_SIZE == 2000)
	{
		for(int i=1;i <= ADC_SAMPLES_SIZE; i++)
		{
			if(i%5==1)				max = INT_MIN;
			
			val = analog_val.read()*3300;
			
			if(max < val) 		max = val;
			
			if(i%5==0) // Update to LCD
			{
				//calculate X Y
				idx = i/5-1;
				row = idx/25;
				col = idx - row*25;
				
				//printf("row=%d, col=%d, i=%d\n",row,col,i);
				fillCircle(60+15*col,250-15*row,4,max);
			}
		}
	}
	
	//pc.printf("%.0f", analog_val.read()*3300);
}
////	takeADCSamples();
////	
////	//pc.printf("measure =");
////	
////	for(int row=0; row<10; row++)
////		for(int col=0; col<40; col++)
////		{
////			fillCircle(50+20*col,245-20*row,5,max[row*40+col]);	
////			//pc.printf(" %.0fmV ", max[row*40+col]);
////		}
////	
////}