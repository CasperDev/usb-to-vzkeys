#include "matrix_keys.h"
#include "stm32f4xx_hal.h"
#include "main.h"


const uint8_t usb2matrix[] = {
	// 0x00 // KEY_NONE KEY_ERRORROLLOVER KEY_POSTFAIL KEY_ERRORUNDEFINED
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,
	// 0x04 // KEY_A KEY_B KEY_C KEY_D
	VZK_A, VZK_B, VZK_C, VZK_D,
	// 0x08 // KEY_E KEY_F KEY_G KEY_H   KEY_I KEY_J KEY_K KEY_L
	VZK_E, VZK_F, VZK_G, VZK_H, VZK_I, VZK_J, VZK_K, VZK_L,

	// 0x10 // KEY_M KEY_N KEY_O KEY_P   KEY_Q KEY_R KEY_S KEY_T
	VZK_M, VZK_N, VZK_O, VZK_P, VZK_Q, VZK_R, VZK_S, VZK_T,
	// 0x18 // KEY_U KEY_V KEY_W KEY_X   KEY_Y KEY_Z KEY_1 KEY_2
	VZK_U, VZK_V, VZK_W, VZK_X, VZK_Y, VZK_Z, VZK_1, VZK_2,

	// 0x20 // KEY_3 KEY_4 KEY_5 KEY_6   KEY_7 KEY_8 KEY_9 KEY_0
	VZK_3, VZK_4, VZK_5, VZK_6, VZK_7, VZK_8, VZK_9, VZK_0,
	// 0x28 // KEY_ENTER KEY_ESCAPE KEY_BACKSPACE KEY_TAB
	VZK_RETURN, VZK_NONE, VZK_NONE, VZK_NONE, // TODO: ESC, BACKSPACE Add CTRL???
	// 0x2c // KEY_SPACEBAR KEY_MINUSE KEY_EQUAL KEY_OBRACKET
	VZK_SPACE, VZK_MINUS, VZK_NONE, ADD_SHFT|VZK_O,

	// 0x30 // KEY_CBRACKET KEY_BACKSLASH KEY_TILDE KEY_SEMICOLON
	ADD_SHFT|VZK_P, ADD_SHFT|VZK_M, VZK_NONE, VZK_SEMI,
	// 0x34 // KEY_SINGLE KEY_GRAVE KEY_COMMA KEY_DOT
	VZK_COLON, VZK_NONE, VZK_COMMA, VZK_PERIOD,
	// 0x38 // KEY_SLASH KEY_CAPS KEY_F1 KEY_F2 KEY_F3 KEY_F4 KEY_F5 KEY_F6
	VZK_SPACE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,

	// 0x40 // KEY_F7 KEY_F8 KEY_F9 KEY_F10  KEY_F11 KEY_F12 KEY_PRINTSCREEN KEY_SCROLL
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,
	// 0x48 // KEY_PAUSE KEY_INSERT KEY_HOME KEY_PAGEUP KEY_DELETE KEY_END1 KEY_PAGEDOWN KEY_RIGHTARROW
	VZK_NONE,ADD_CTRL|VZK_L,VZK_NONE,VZK_NONE,ADD_CTRL|VZK_SEMI,VZK_NONE,VZK_NONE,ADD_CTRL|VZK_COMMA,

	// 0x50 // KEY_LEFTARROW KEY_DOWNARROW KEY_UPARROW KEY_KEYPAD_NUM_LOCK KEY_KEYPAD_SLASH KEY_KEYPAD_ASTERIKS KEY_KEYPAD_MINUS KEY_KEYPAD_PLUS
	ADD_CTRL|VZK_M,ADD_CTRL|VZK_SPACE,ADD_CTRL|VZK_PERIOD,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE
};

/*	// 0x58 // KEY_KEYPAD_ENTER KEY_KEYPAD_1_END KEY_KEYPAD_2_DOWN_ARROW KEY_KEYPAD_3_PAGEDN KEY_KEYPAD_4_LEFT_ARROW KEY_KEYPAD_5 KEY_KEYPAD_6_RIGHT_ARROW KEY_KEYPAD_7_HOME
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,

	// 0x60 // KEY_KEYPAD_8_UP_ARROW KEY_KEYPAD_9_PAGEUP KEY_KEYPAD_0_INSERT KEY_KEYPAD_DECIMAL_SEPARATOR_DELETE
	// 0x64 // KEY_NONUS_BACK_SLASH_VERTICAL_BAR KEY_APPLICATION KEY_POWER KEY_KEYPAD_EQUAL
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,
	// 0x68 // KEY_F13 KEY_F14 KEY_F15 KEY_F16 KEY_F17 KEY_F18 KEY_F19 KEY_F20
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,

	// 0x70 // KEY_F21 KEY_F22 KEY_F23 KEY_F24 KEY_EXECUTE KEY_HELP KEY_MENU KEY_SELECT
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,
	// 0x78 // KEY_STOP KEY_AGAIN KEY_UNDO KEY_CUT KEY_COPY KEY_PASTE KEY_FIND KEY_MUTE
	VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,VZK_NONE,

	// 0x80 // KEY_VOLUME_UP KEY_VOLUME_DOWN KEY_LOCKING_CAPS_LOCK KEY_LOCKING_NUM_LOCK KEY_LOCKING_SCROLL_LOCK KEY_KEYPAD_COMMA KEY_KEYPAD_EQUAL_SIGN KEY_INTERNATIONAL1
	0,0,0,0,0,0,0,0,
	// 0x88 // KEY_INTERNATIONAL2 KEY_INTERNATIONAL3 KEY_INTERNATIONAL4 KEY_INTERNATIONAL5 KEY_INTERNATIONAL6 KEY_INTERNATIONAL7 KEY_INTERNATIONAL8 KEY_INTERNATIONAL9
	0,0,0,0,0,0,0,0,

	// 0x90 // KEY_LANG1 KEY_LANG2 KEY_LANG3 KEY_LANG4 KEY_LANG5 KEY_LANG6 KEY_LANG7 KEY_LANG8
	0,0,0,0,0,0,0,0,
	// 0x98 // KEY_LANG9 KEY_ALTERNATE_ERASE KEY_SYSREQ KEY_CANCEL KEY_CLEAR KEY_PRIOR KEY_RETURN KEY_SEPARATOR
	0,0,0,0,0,0,0,0,

	// 0xa0 // KEY_OUT KEY_OPER KEY_CLEAR_AGAIN KEY_CRSEL KEY_EXSEL -- -- --
	0,0,0,0,0,0,0,0,
	// 0xa8 // -- -- -- -- -- -- -- --
	0,0,0,0,0,0,0,0,

	// 0xb0 // KEY_KEYPAD_00 KEY_KEYPAD_000 KEY_THOUSANDS_SEPARATOR KEY_DECIMAL_SEPARATOR KEY_CURRENCY_UNIT KEY_CURRENCY_SUB_UNIT KEY_KEYPAD_OPARENTHESIS KEY_KEYPAD_CPARENTHESIS
	0,0,0,0,0,0,0,0,
	// 0xb8 // KEY_KEYPAD_OBRACE KEY_KEYPAD_CBRACE KEY_KEYPAD_TAB KEY_KEYPAD_BACKSPACE KEY_KEYPAD_A KEY_KEYPAD_B KEY_KEYPAD_C KEY_KEYPAD_D
	0,0,0,0,0,0,0,0,

	// 0xc0 // KEY_KEYPAD_E KEY_KEYPAD_F KEY_KEYPAD_XOR KEY_KEYPAD_CARET KEY_KEYPAD_PERCENT KEY_KEYPAD_LESS KEY_KEYPAD_GREATER KEY_KEYPAD_AMPERSAND
	0,0,0,0,0,0,0,0,
	// 0xc8 // KEY_KEYPAD_LOGICAL_AND KEY_KEYPAD_VERTICAL_BAR KEY_KEYPAD_LOGIACL_OR KEY_KEYPAD_COLON KEY_KEYPAD_NUMBER_SIGN KEY_KEYPAD_SPACE KEY_KEYPAD_AT KEY_KEYPAD_EXCLAMATION_MARK
	0,0,0,0,0,0,0,0,

	// 0xd0 // KEY_KEYPAD_MEMORY_STORE KEY_KEYPAD_MEMORY_RECALL KEY_KEYPAD_MEMORY_CLEAR KEY_KEYPAD_MEMORY_ADD KEY_KEYPAD_MEMORY_SUBTRACT KEY_KEYPAD_MEMORY_MULTIPLY KEY_KEYPAD_MEMORY_DIVIDE KEY_KEYPAD_PLUSMINUS
	0,0,0,0,0,0,0,0,
	// 0xd8 // KEY_KEYPAD_CLEAR KEY_KEYPAD_CLEAR_ENTRY KEY_KEYPAD_BINARY KEY_KEYPAD_OCTAL KEY_KEYPAD_DECIMAL KEY_KEYPAD_HEXADECIMAL -- --
	0,0,0,0,0,0,0,0,

	// 0xe0 // KEY_LEFTCONTROL KEY_LEFTSHIFT KEY_LEFTALT KEY_LEFT_GUI
	VZK_CTRL, VZK_SHIFT, 0, 0,
	// 0xe4 // KEY_RIGHTCONTROL KEY_RIGHTSHIFT KEY_RIGHTALT KEY_RIGHT_GUI
	VZK_CTRL, VZK_SHIFT, 0, 0,
	// 0xe8...0xef
	0,0,0,0,0,0,0,0,
	// 0xf0..0xff
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
}; */

const int USB2MATRIX_LEN = sizeof(usb2matrix) / sizeof(uint8_t);

// GPIO Defined:
// AX0..2,AY0..2 - GPIOA 0..5 (KAX0..KAX2,KAY0..KAY2)
// RESET,STROBE,DATA - GPIOB (KRESET,KSTROBE,KDATA)

void MT8816_delay()
{
	for(int i=0;i<50;i++)
		__NOP();
}

void MT8816_Reset()
{
	// clear RESET,STROBE, DATA
	uint32_t setreset = (KRESET_Pin | KSTROBE_Pin | KDATA_Pin) << 16;
	GPIOB->BSRR = setreset;
	// reset pulse (High)
	GPIOB->BSRR = KRESET_Pin;
	GPIOB->BSRR = KRESET_Pin << 16;
}

void MT8816_SwitchOn(uint8_t addr)
{
	// build 32bit set-reset value for addr AX0..2,AY0..2
	uint8_t notAddr = (~addr) & 0x3f;
	uint32_t setreset = (notAddr << 16) | addr;
	GPIOA->BSRR = setreset;
	//MT8816_delay();
	// set DATA pin
	GPIOB->BSRR = KDATA_Pin;
	// strobe pulse (High)
	GPIOB->BSRR = KSTROBE_Pin;
	//MT8816_delay();
	GPIOB->BSRR = KSTROBE_Pin << 16;
	// reset DATA pin
	GPIOB->BSRR = KDATA_Pin << 16;
}

void MT8816_SwitchOff(uint8_t addr)
{
	// build 32bit set-reset value for addr AX0..2,AY0..2
	uint8_t notAddr = (~addr) & 0x3f;
	uint32_t setreset = (notAddr << 16) | addr;
	GPIOA->BSRR = setreset;
	//MT8816_delay();
	// reset DATA pin
	GPIOB->BSRR = KDATA_Pin << 16;
	// strobe pulse (High)
	GPIOB->BSRR = KSTROBE_Pin;
	//MT8816_delay();
	GPIOB->BSRR = KSTROBE_Pin << 16;
}

int switchUsbKey(uint8_t usbkey)
{
	if (usbkey < USB2MATRIX_LEN)
	{
		uint8_t vzkey = usb2matrix[usbkey];
		if (vzkey != VZK_NONE) {
			MT8816_SwitchOn(vzkey & 0x3f);
			return vzkey & (ADD_SHFT|ADD_CTRL);
		}
	}
	return 0;
}

uint8_t SEQ_BACKSPACE[] = { ADD_CTRL | VZK_M, ADD_CTRL | VZK_SEMI, VZK_NONE };
uint8_t* sequence = NULL;

void switchUsbKeys(uint8_t *keys, bool fshift, bool fctrl)
{
	// ignore if any error (0 means keys off)
	if (*keys > 0 && *keys < 4) return;
	// reset all keys before switch any
	MT8816_Reset();
	// shift & ctrl flags
	int flags = (fshift ? ADD_SHFT : 0) | (fctrl ? ADD_CTRL : 0);
	// switch on pressed keys
	for (int i=0;i<6;++i) {
		// sequenced key?
		if (*keys == 0x2a) // BACKSPACE
			sequence = &SEQ_BACKSPACE[0];
		 else
			 flags |= switchUsbKey(*keys++);
	}
	// switch Shift
	if (flags & ADD_SHFT)
		MT8816_SwitchOn(VZK_SHIFT);
	// switch Ctrl
	if (flags & ADD_CTRL)
		MT8816_SwitchOn(VZK_CTRL);
	//sendSequence();
}

void sendSequence()
{
	if (sequence == NULL) return;
	//sequence = &SEQ_BACKSPACE[0];

	while (*sequence != VZK_NONE) {
		uint8_t key = *sequence;
		sequence++;
		MT8816_SwitchOn(key & 0x3f);
		// switch Shift
		if (key & ADD_SHFT)
			MT8816_SwitchOn(VZK_SHIFT);
		// switch Ctrl
		if (key & ADD_CTRL)
			MT8816_SwitchOn(VZK_CTRL);
		HAL_Delay(20);
		MT8816_SwitchOff(key & 0x3f);
		// switch Shift
		if (key & ADD_SHFT)
			MT8816_SwitchOff(VZK_SHIFT);
		// switch Ctrl
		if (key & ADD_CTRL)
			MT8816_SwitchOff(VZK_CTRL);
		//HAL_Delay(100);
	}
	sequence = NULL;
}