#ifndef _ILI9486_H_
#define _ILI9486_H_


#include "main.h"
#include "Adafruit_GFX.h"
#include "ILI9486_defs.h"
#include "Protocols.h"
#include "BUS8.h"	
	


class ILI9486: public Adafruit_GFX{
	private: 
		Protocols* proto;
		int orientation;
		
	public:
		
		ILI9486 (proto_t displayproto, PinName* buspins, PinName CS, PinName reset, PinName DC, PinName WR, PinName RD);
		
		// SPI functions
		void 		BusEnable(bool enable);
    void    writeCMD(uint8_t data);
		void 		writeCMD16(uint16_t cmd);
		void		writeU8(uint8_t data);
		void    writeU16(uint16_t data);
		void 		wr_gram(unsigned short data);
		void		wr_gram(unsigned short data, unsigned int count);
		
		void		reset();
		void 		delayms(int num);
			
		// LCD functions
		void		init();		
		void		setBacklight(bool state);
		void 		setAddrWindow(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1);
		uint16_t 	color565(uint8_t r, uint8_t g, uint8_t b);
		void 		setRotation(uint8_t m);
		void 		invertDisplay(bool i);
		
		void		writePixels(uint16_t * colors, uint32_t len);
		void 		drawHline(int x0, int y, int x1, int lineWidth, unsigned short color);
		void 		drawVline(int x, int y0, int y1, int lineWidth, unsigned short color);
		void 		drawArrow(int x, int y, int orientation);
		void 		drawPoint(int x, int y, int pixelSize, int color);
		void 		drawRGBBitmap(int16_t x, int16_t y, uint16_t *pcolors, int16_t w, int16_t h);
		void 		mirrorXY(mirror_t mode);
		void 		drawXYaxis();
		void 		updateADCPoints();
		
		
		// LCD Tests
		void 		testFillScreen();
		void 		testText();
		void 		testLines(uint16_t color);
		void 		testFastLines(uint16_t color1, uint16_t color2);
		void 		testRects(uint16_t color);
		void 		testFilledRects(uint16_t color1, uint16_t color2);
		void 		testFilledCircles(uint8_t radius, uint16_t color);
		void 		testCircles(uint8_t radius, uint16_t color);
		void 		testTriangles();
		void 		testFilledTriangles();
		void 		testRoundRects();
		void 		testFilledRoundRects();
		
		
		void		test1();
		void		test2();
		
		// Virtual funnctions over Adafruit_GFX
		void 		drawPixel(int16_t x, int16_t y, uint16_t color);
		void 		fillScreen(uint16_t color);
		
		
};

#endif
