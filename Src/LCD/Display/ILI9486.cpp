#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

#include "ILI9486.h"


using namespace std;

/*******************************************************************
* NAME :            ILI9341::ILI9341(const char* LCDSpiPort)
*
* DESCRIPTION :     ILI9341 Constructor
*
* INPUTS :
*       PARAMETERS:
*           const char* LCDSpiPort: The SPI port to communicate with ILI9341. Usually it looks like "/dev/spidev32765.0" which can be found in /dev/ folder
*			There are another pins need to be set: DC, RST, BL(BackLight) that can be modified in ILI9341_defs.h
*
*/

ILI9486::ILI9486(proto_t displayproto, PinName* buspins, PinName CS, PinName reset, PinName DC, PinName WR, PinName RD)
:Adafruit_GFX(ILI9486_TFTWIDTH,ILI9486_TFTHEIGHT)
{
	PinName pins[16];
	for(int i=0; i<8; i++) pins[i]=buspins[i];
	for(int i=8; i<16; i++) pins[i]=NC;
	
	proto = new BUS8(pins, CS, reset, DC, WR, RD);
	
	BusEnable(true); //TFT class forwards to Protocol class
	
	
	
}

void ILI9486::BusEnable(bool enable)
{
	proto->BusEnable(enable);
}

void ILI9486::reset ()
{
	proto->hw_reset();
}

void ILI9486::writeCMD(uint8_t cmd)
{
	proto->wr_cmd8(cmd);
}

void ILI9486::writeCMD16(uint16_t cmd)
{
	proto->wr_cmd16(cmd);
}

void ILI9486::writeU8(uint8_t data)
{
	proto->wr_data8(data);
}

void ILI9486::writeU16(uint16_t data)
{
	proto->wr_data16(data);
}

void ILI9486::wr_gram(unsigned short data)
{
	proto->wr_gram(data);
}

void ILI9486::wr_gram(unsigned short data, unsigned int count)
{
	proto->wr_gram(data, count);
}

void ILI9486::delayms(int n)
{
	wait(((float)n)/1000);
}

void ILI9486::init()
{
    /* Start Initial Sequence ----------------------------------------------------*/
    
    writeCMD(0xF1);
    writeU8(0x36);
    writeU8(0x04);
    writeU8(0x00);
    writeU8(0x3C);
    writeU8(0x0F);
    writeU8(0x8F);


    writeCMD(0xF2);
    writeU8(0x18);
    writeU8(0xA3);
    writeU8(0x12);
    writeU8(0x02);
    writeU8(0xb2);
    writeU8(0x12);
    writeU8(0xFF);
    writeU8(0x10);
    writeU8(0x00);

    writeCMD(0xF8);
    writeU8(0x21);
    writeU8(0x04);

    writeCMD(0xF9);
    writeU8(0x00);
    writeU8(0x08);  

    writeCMD(0xC0);
    writeU8(0x0f); //13
    writeU8(0x0f); //10

    writeCMD(0xC1);
    writeU8(0x42); //43

    writeCMD(0xC2);
    writeU8(0x22);

    writeCMD(0xC5);
    writeU8(0x01); //00
    writeU8(0x29); //4D
    writeU8(0x80);

    writeCMD(0xB6);
    writeU8(0x00);
    writeU8(0x02); //42
    writeU8(0x3b);

    writeCMD(0xB1);
    writeU8(0xB0); //C0
    writeU8(0x11);

    writeCMD(0xB4);
    writeU8(0x02); //01

    writeCMD(0xE0);
    writeU8(0x0F);
    writeU8(0x18);
    writeU8(0x15);
    writeU8(0x09);
    writeU8(0x0B);
    writeU8(0x04);
    writeU8(0x49);
    writeU8(0x64);
    writeU8(0x3D);
    writeU8(0x08);
    writeU8(0x15);
    writeU8(0x06);
    writeU8(0x12);
    writeU8(0x07);
    writeU8(0x00);

    writeCMD(0xE1);
    writeU8(0x0F);
    writeU8(0x38);
    writeU8(0x35);
    writeU8(0x0a);
    writeU8(0x0c);
    writeU8(0x03);
    writeU8(0x4A);
    writeU8(0x42);
    writeU8(0x36);
    writeU8(0x04);
    writeU8(0x0F);
    writeU8(0x03);
    writeU8(0x1F);
    writeU8(0x1B);
    writeU8(0x00);

    writeCMD(0x20);                     // display inversion OFF
  
    writeCMD(0x36);      // MEMORY_ACCESS_CONTROL (orientation stuff)
    writeU8(0x48);
     
    writeCMD(0x3A);      // COLMOD_PIXEL_FORMAT_SET
    writeU8(0x55);     // 16 bit pixel 

    writeCMD(0x13); // Nomal Displaymode
    
    writeCMD(0x11);                     // sleep out
    delayms(150);
     
    writeCMD(0x29);                     // display on
    delayms(150);
}







