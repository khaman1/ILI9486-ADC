// (c) 2017 Outernet Inc

#ifndef _ILI9486_DEFS_H_
#define _ILI9486_DEFS_H_


extern const unsigned char font[];	
enum mirror_t {X,Y,XY,NONE};
///////////// ILI9486 DIMENSION ////////////
////////////////////////////////////////////
#define ILI9486_TFTWIDTH   		320
#define ILI9486_TFTHEIGHT  		480


///////////// ILI9486 REGISTERS ////////////
////////////////////////////////////////////
#define ILI9486_NOP        		0x00
#define ILI9486_SWRESET    		0x01
#define ILI9486_RDDID      		0x04
#define ILI9486_RDDST      		0x09

#define ILI9486_SLPIN      		0x10
#define ILI9486_SLPOUT     		0x11
#define ILI9486_PTLON      		0x12
#define ILI9486_NORON      		0x13

#define ILI9486_RDMODE     		0x0A
#define ILI9486_RDMADCTL   		0x0B
#define ILI9486_RDPIXFMT   		0x0C
#define ILI9486_RDIMGFMT   		0x0D
#define ILI9486_RDSELFDIAG 		0x0F

#define ILI9486_INVOFF     		0x20
#define ILI9486_INVON      		0x21
#define ILI9486_GAMMASET   		0x26
#define ILI9486_DISPOFF    		0x28
#define ILI9486_DISPON     		0x29

#define ILI9486_CASET      		0x2A
#define ILI9486_PASET      		0x2B
#define ILI9486_RAMWR      		0x2C
#define ILI9486_RAMRD      		0x2E

#define ILI9486_PTLAR      		0x30
#define ILI9486_MADCTL     		0x36
#define ILI9486_VSCRSADD   		0x37
#define ILI9486_PIXFMT     		0x3A

#define ILI9486_FRMCTR1    		0xB1
#define ILI9486_FRMCTR2    		0xB2
#define ILI9486_FRMCTR3    		0xB3
#define ILI9486_INVCTR     		0xB4
#define ILI9486_DFUNCTR    		0xB6

#define ILI9486_PWCTR1     		0xC0
#define ILI9486_PWCTR2     		0xC1
#define ILI9486_PWCTR3     		0xC2
#define ILI9486_PWCTR4     		0xC3
#define ILI9486_PWCTR5     		0xC4
#define ILI9486_VMCTR1     		0xC5
#define ILI9486_VMCTR2     		0xC7

#define ILI9486_RDID1      		0xDA
#define ILI9486_RDID2      		0xDB
#define ILI9486_RDID3      		0xDC
#define ILI9486_RDID4      		0xDD

#define ILI9486_GMCTRP1    		0xE0
#define ILI9486_GMCTRN1    		0xE1



///////////// ILI9486 COLORS ///////////////
////////////////////////////////////////////
#define ILI9486_BLACK       	0x0000      /*   0,   0,   0 */
#define ILI9486_NAVY        	0x000F      /*   0,   0, 128 */
#define ILI9486_DARKGREEN   	0x03E0      /*   0, 128,   0 */
#define ILI9486_DARKCYAN    	0x03EF      /*   0, 128, 128 */
#define ILI9486_MAROON      	0x7800      /* 128,   0,   0 */
#define ILI9486_PURPLE      	0x780F      /* 128,   0, 128 */
#define ILI9486_OLIVE       	0x7BE0      /* 128, 128,   0 */
#define ILI9486_LIGHTGREY   	0xC618      /* 192, 192, 192 */
#define ILI9486_DARKGREY    	0x7BEF      /* 128, 128, 128 */
#define ILI9486_BLUE        	0x001F      /*   0,   0, 255 */
#define ILI9486_GREEN       	0x07E0      /*   0, 255,   0 */
#define ILI9486_CYAN        	0x07FF      /*   0, 255, 255 */
#define ILI9486_RED         	0xF800      /* 255,   0,   0 */
#define ILI9486_MAGENTA     	0xF81F      /* 255,   0, 255 */
#define ILI9486_YELLOW      	0xFFE0      /* 255, 255,   0 */
#define ILI9486_WHITE       	0xFFFF      /* 255, 255, 255 */
#define ILI9486_ORANGE      	0xFD20      /* 255, 165,   0 */
#define ILI9486_GREENYELLOW 	0xAFE5      /* 173, 255,  47 */
#define ILI9486_PINK        	0xF81F


//////////// ILI9486 ROTATION //////////////
////////////////////////////////////////////
#define MADCTL_MY           	0x80
#define MADCTL_MX           	0x40
#define MADCTL_MV           	0x20
#define MADCTL_ML           	0x10
#define MADCTL_RGB          	0x00
#define MADCTL_BGR          	0x08
#define MADCTL_MH           	0x04


#endif

