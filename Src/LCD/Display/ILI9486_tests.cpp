// (c) 2017 Outernet Inc

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ILI9486.h"

#define min(a,b) (((a) < (b)) ? (a) : (b))

void ILI9486::testFillScreen() {
    fillScreen(ILI9486_BLACK);
    fillScreen(ILI9486_RED);
    fillScreen(ILI9486_GREEN);
    fillScreen(ILI9486_BLUE);
    fillScreen(ILI9486_BLACK);
		
}




void ILI9486::testText() {
	fillScreen(ILI9486_BLACK);
	setRotation(1);
	
	setCursor(0, 0);
	setTextColor(ILI9486_WHITE);  setTextSize(1);
	print("Hello World!");
	setTextColor(ILI9486_YELLOW); setTextSize(2);
	print(1234.56);
	setTextColor(ILI9486_RED);    setTextSize(3);
	print(0xDEADBEEF, 16);
	println();
	setTextColor(ILI9486_GREEN);
	setTextSize(5);
	print("Groop");
	setTextSize(2);
	print("I implore thee,");
	setTextSize(1);
	print("my foonting turlingdromes.");
	print("And hooptiously drangle me");
	print("with crinkly bindlewurdles,");
	print("Or I will rend thee");
	print("in the gobberwarts");
	print("with my blurglecruncheon,");
	print("see if I don't!");
	
	setRotation(0);
}

void ILI9486::testLines(uint16_t color) {
	unsigned long tt;
	int x1, y1, x2, y2,
		w = width(),
		h = height();

	fillScreen(ILI9486_BLACK);

	x1 = y1 = 0;
	y2    = h - 1;

	for(x2=0; x2<w; x2+=6) drawLine(x1, y1, x2, y2, color);
	x2    = w - 1;
	for(y2=0; y2<h; y2+=6) drawLine(x1, y1, x2, y2, color);
	tt     = 1; // fillScreen doesn't count against timing

	fillScreen(ILI9486_BLACK);

	x1    = w - 1;
	y1    = 0;
	y2    = h - 1;

	for(x2=0; x2<w; x2+=6) drawLine(x1, y1, x2, y2, color);
	x2    = 0;
	for(y2=0; y2<h; y2+=6) drawLine(x1, y1, x2, y2, color);
	tt    += 1;

	fillScreen(ILI9486_BLACK);

	x1    = 0;
	y1    = h - 1;
	y2    = 0;

	for(x2=0; x2<w; x2+=6) drawLine(x1, y1, x2, y2, color);
	x2    = w - 1;
	for(y2=0; y2<h; y2+=6) drawLine(x1, y1, x2, y2, color);
	tt    += 1;

	fillScreen(ILI9486_BLACK);

	x1    = w - 1;
	y1    = h - 1;
	y2    = 0;

	for(x2=0; x2<w; x2+=6) drawLine(x1, y1, x2, y2, color);
	x2    = 0;
	for(y2=0; y2<h; y2+=6) drawLine(x1, y1, x2, y2, color);


}

void ILI9486::testFastLines(uint16_t color1, uint16_t color2) {
	int  x, y, w = width(), h = height();

	fillScreen(ILI9486_BLACK);
	for(y=0; y<h; y+=5) drawFastHLine(0, y, w, color1);
	for(x=0; x<w; x+=5) drawFastVLine(x, 0, h, color2);
}

void ILI9486::testRects(uint16_t color) {
	int n, i, i2,
		cx = width()  / 2,
		cy = height() / 2;

	//fillScreen(ILI9486_BLACK);
	n     = min(width(), height());

	for(i=2; i<n; i+=6) {
		i2 = i / 2;
		drawRect(cx-i2, cy-i2, i, i, color);
	}
}

void ILI9486::testFilledRects(uint16_t color1, uint16_t color2) {
	unsigned long tt = 0;
	int           n, i, i2,
				cx = width()  / 2 - 1,
				cy = height() / 2 - 1;

	fillScreen(ILI9486_BLACK);
	n = min(width(), height());

	for(i=n; i>0; i-=6) {
		i2    = i / 2;
		fillRect(cx-i2, cy-i2, i, i, color1);
		tt    += 1;
		// Outlines are not included in timing results
		drawRect(cx-i2, cy-i2, i, i, color2);
	}
}

void ILI9486::testFilledCircles(uint8_t radius, uint16_t color) {
	int x, y, w = width(), h = height(), r2 = radius * 2;

	fillScreen(ILI9486_BLACK);

	for(x=radius; x<w; x+=r2)
		for(y=radius; y<h; y+=r2)
			fillCircle(x, y, radius, color);
}

void ILI9486::testCircles(uint8_t radius, uint16_t color) {
	int           x, y, r2 = radius * 2,
				w = width()  + radius,
				h = height() + radius;

	// Screen is not cleared for this one -- this is
	// intentional and does not affect the reported time.

	for(x=0; x<w; x+=r2)
		for(y=0; y<h; y+=r2)
			drawCircle(x, y, radius, color);

}

void ILI9486::testTriangles() {
	int           n, i, cx = width()  / 2 - 1,
					  cy = height() / 2 - 1;

	fillScreen(ILI9486_BLACK);
	n     = min(cx, cy);

	for(i=0; i<n; i+=5) 
		drawTriangle(
		  cx    , cy - i, // peak
		  cx - i, cy + i, // bottom left
		  cx + i, cy + i, // bottom right
		  color565(0, 0, i));
}

	
	
void ILI9486::testFilledTriangles() {
	int i, cx = width()  / 2 - 1,
		cy = height() / 2 - 1;

	fillScreen(ILI9486_BLACK);

	for(i=min(cx,cy); i>10; i-=5) {
		fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
		  color565(0, i, i));

		drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
		  color565(i, i, 0));
	}
}

void ILI9486::testRoundRects() {
	int           w, i, i2,
				cx = width()  / 2 - 1,
				cy = height() / 2 - 1;

	fillScreen(ILI9486_BLACK);
	w     = min(width(), height());
	
	for(i=0; i<w; i+=6) {
		i2 = i / 2;
		drawRoundRect(cx-i2, cy-i2, i, i, i/8, color565(i, 0, 0));
	}
}



void ILI9486::testFilledRoundRects() {
	int i, i2,
		cx = width()  / 2 - 1,
		cy = height() / 2 - 1;

	fillScreen(ILI9486_BLACK);

	for(i=min(width(), height()); i>20; i-=6) {
		i2 = i / 2;
		fillRoundRect(cx-i2, cy-i2, i, i, i/8, color565(0, i, 0));
	}
}


void ILI9486::test1() {
	testFillScreen();
	testText();
	testFastLines(ILI9486_BLACK, ILI9486_WHITE);
	testRects(ILI9486_RED);
	testFilledCircles(10,ILI9486_DARKCYAN);
	testTriangles();
	testFilledTriangles();
	testRoundRects();
}

void ILI9486::test2(){
	
}
