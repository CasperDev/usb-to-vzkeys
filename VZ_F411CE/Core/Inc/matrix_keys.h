#ifndef __MATRIX_KEYS__
#define __MATRIX_KEYS__

#include "stdint.h"
#include "stdbool.h"

#define ROW0 1
#define ROW1 2
#define ROW2 3
#define ROW3 0
#define ROW4 7
#define ROW5 4
#define ROW6 5
#define ROW7 6
#define COL0 0
#define COL1 3
#define COL2 5
#define COL3 2
#define COL4 4
#define COL5 1

#define MAKEADDR(row,col) ((row << 3)|((col & 0x07) & 0x3f))

#define VZK_R		MAKEADDR(ROW0,COL5)
#define VZK_Q		MAKEADDR(ROW0,COL4)
#define VZK_E		MAKEADDR(ROW0,COL3)
#define VZK_W		MAKEADDR(ROW0,COL1)
#define VZK_T		MAKEADDR(ROW0,COL0)
#define VZK_F		MAKEADDR(ROW1,COL5)
#define VZK_A		MAKEADDR(ROW1,COL4)
#define VZK_D		MAKEADDR(ROW1,COL3)
#define VZK_CTRL	MAKEADDR(ROW1,COL2)
#define VZK_S		MAKEADDR(ROW1,COL1)
#define VZK_G		MAKEADDR(ROW1,COL0)
#define VZK_V		MAKEADDR(ROW2,COL5)
#define VZK_Z		MAKEADDR(ROW2,COL4)
#define VZK_C		MAKEADDR(ROW2,COL3)
#define VZK_SHIFT	MAKEADDR(ROW2,COL2)
#define VZK_X		MAKEADDR(ROW2,COL1)
#define VZK_B		MAKEADDR(ROW2,COL0)
#define VZK_4		MAKEADDR(ROW3,COL5)
#define VZK_1		MAKEADDR(ROW3,COL4)
#define VZK_3		MAKEADDR(ROW3,COL3)
#define VZK_2		MAKEADDR(ROW3,COL1)
#define VZK_5		MAKEADDR(ROW3,COL0)
#define VZK_M		MAKEADDR(ROW4,COL5)
#define VZK_SPACE	MAKEADDR(ROW4,COL4)
#define VZK_COMMA	MAKEADDR(ROW4,COL3)
#define VZK_PERIOD	MAKEADDR(ROW4,COL1)
#define VZK_N		MAKEADDR(ROW4,COL0)
#define VZK_7		MAKEADDR(ROW5,COL5)
#define VZK_0		MAKEADDR(ROW5,COL4)
#define VZK_8		MAKEADDR(ROW5,COL3)
#define VZK_MINUS	MAKEADDR(ROW5,COL2)
#define VZK_9		MAKEADDR(ROW5,COL1)
#define VZK_6		MAKEADDR(ROW5,COL0)
#define VZK_U		MAKEADDR(ROW6,COL5)
#define VZK_P		MAKEADDR(ROW6,COL4)
#define VZK_I		MAKEADDR(ROW6,COL3)
#define VZK_RETURN	MAKEADDR(ROW6,COL2)
#define VZK_O		MAKEADDR(ROW6,COL1)
#define VZK_Y		MAKEADDR(ROW6,COL0)
#define VZK_J		MAKEADDR(ROW7,COL5)
#define VZK_SEMI	MAKEADDR(ROW7,COL4)
#define VZK_K		MAKEADDR(ROW7,COL3)
#define VZK_COLON	MAKEADDR(ROW7,COL2)
#define VZK_L		MAKEADDR(ROW7,COL1)
#define VZK_H		MAKEADDR(ROW7,COL0)

#define VZK_NONE	0xff

#define ADD_SHFT	0x40
#define ADD_CTRL	0x80



void MT8816_Reset();
void MT8816_SwitchOn(uint8_t addr);
int switchUsbKey(uint8_t usbkey);
void switchUsbKeys(uint8_t *keys, bool fshift, bool fctrl);
void sendSequence();


#endif // __MATRIX_KEYS__
