//keymap.h

#include <winuser.h>

#define KTAB_SIZE 0xFF

//some undefined VK values
#define VK_UNDEF 0x00
#define VK_NUL VK_UNDEF
#define VK_SOH VK_UNDEF
#define VK_STX VK_UNDEF
#define VK_ETX VK_UNDEF
#define VK_EOT VK_UNDEF
#define VK_ENQ VK_UNDEF
#define VK_ACK VK_UNDEF
#define VK_BEL VK_UNDEF
#define VK_VT VK_UNDEF
#define VK_FF VK_UNDEF 
#define VK_SO VK_UNDEF
#define VK_SI VK_UNDEF
#define VK_DLE VK_UNDEF
#define VK_DC1 VK_UNDEF
#define VK_DC2 VK_UNDEF
#define VK_DC3 VK_UNDEF
#define VK_DC4 VK_UNDEF
#define VK_NAK VK_UNDEF
#define VK_SYN VK_UNDEF
#define VK_ETB VK_UNDEF
#define VK_CAN VK_UNDEF
#define VK_EM VK_UNDEF
#define VK_SUB VK_UNDEF
#define VK_FS VK_UNDEF
#define VK_GS VK_UNDEF
#define VK_RS VK_UNDEF
#define VK_US VK_UNDEF

// some more undefined vk values
#define VK_0 	0x30
#define VK_1 	0x31
#define VK_2 	0x32
#define VK_3 	0x33
#define VK_4 	0x34
#define VK_5 	0x35
#define VK_6 	0x36
#define VK_7 	0x37
#define VK_8 	0x38
#define VK_9 	0x39
#define VK_A 	0x41
#define VK_B 	0x42
#define VK_C 	0x43
#define VK_D 	0x44
#define VK_E 	0x45
#define VK_F 	0x46
#define VK_G 	0x47
#define VK_H 	0x48
#define VK_I 	0x49
#define VK_J 	0x4A
#define VK_K 	0x4B
#define VK_L 	0x4C
#define VK_M 	0x4D
#define VK_N 	0x4E
#define VK_O 	0x4F
#define VK_P 	0x50
#define VK_Q 	0x51
#define VK_R 	0x52
#define VK_S 	0x53
#define VK_T 	0x54
#define VK_U 	0x55
#define VK_V 	0x56
#define VK_W 	0x57
#define VK_X 	0x58
#define VK_Y 	0x59
#define VK_Z 	0x5A

// the struct used to save a ASCII <-> VK_ table
struct KTABLE{
     byte kByte[1];
     char txt[15];
     byte kVKval; //the VK value to send for kChar/kByte
     bool kShift;
};

typedef KTABLE* pKTABLE;

// the translation tabel for ASCII to VK_ values
struct KTABLE vkTable[] = {
	{0x00, "NUL", VK_NUL, false}, 
	{0x01, "SOH", VK_SOH, false}, 
	{0x02, "STX", VK_STX, false}, 
	{0x03, "ETX", VK_ETX, false}, 
	{0x04, "EOT", VK_EOT, false}, 
	{0x05, "ENQ", VK_ENQ, false}, 
	{0x06, "ACK", VK_ACK, false}, 
	{0x07, "BEL", VK_BEL, false}, 
	{0x08, "BS", VK_BACK, false}, 
	{0x09, "HT", VK_TAB, false}, 
	{0x0A, "LF", VK_RETURN, false}, 
	{0x0B, "VT", VK_VT, false}, 
	{0x0C, "FF", VK_FF, false}, 
	{0x0D, "CR", VK_RETURN, false}, 
	{0x0E, "SO", VK_SO, false}, 
	{0x0F, "SI", VK_SI, false}, 
	{0x10, "DLE", VK_DLE, false}, 
	{0x11, "DC1", VK_DC1, false}, 
	{0x12, "DC2", VK_DC2, false}, 
	{0x13, "DC3", VK_DC3, false}, 
	{0x14, "DC4", VK_DC4, false}, 
	{0x15, "NAK", VK_NAK, false}, 
	{0x16, "SYN", VK_SYN, false}, 
	{0x17, "ETB", VK_ETB, false}, 
	{0x18, "CAN", VK_CAN, false}, 
	{0x19, "EM", VK_EM, false}, 
	{0x1A, "SUB", VK_SUB, false}, 
	{0x1B, "ESC", VK_ESCAPE, false}, 
	{0x1C, "FS", VK_FS, false}, 
	{0x1D, "GS", VK_GS, false}, 
	{0x1E, "RS", VK_RS, false}, 
	{0x1F, "US", VK_US, false}, 
	{0x20, " ", VK_SPACE, false}, 
	{0x21, "!", VK_1, true}, 
	{0x22, "\"", VK_APOSTROPHE, true}, 
	{0x23, "#", VK_3, true}, 
	{0x24, "$", VK_4, true}, 
	{0x25, "%", VK_5, true}, 
	{0x26, "&", VK_7, true}, 
	{0x27, "'", VK_APOSTROPHE, false}, 
	{0x28, "(", VK_9, true}, 
	{0x29, ")", VK_0, true}, 
	{0x2A, "*", VK_8, true}, 
	{0x2B, "+", VK_EQUAL, true}, 
	{0x2C, ",", VK_COMMA, false}, 
	{0x2D, "-", VK_HYPHEN, false}, 
	{0x2E, ".", VK_PERIOD, false}, 
	{0x2F, "/", VK_SLASH, false}, 
	{0x30, "0", VK_0, false}, 
	{0x31, "1", VK_1, false}, 
	{0x32, "2", VK_2, false}, 
	{0x33, "3", VK_3, false}, 
	{0x34, "4", VK_4, false}, 
	{0x35, "5", VK_5, false}, 
	{0x36, "6", VK_6, false}, 
	{0x37, "7", VK_7, false}, 
	{0x38, "8", VK_8, false}, 
	{0x39, "9", VK_9, false}, 
	{0x3A, ":", VK_SEMICOLON, true}, 
	{0x3B, ";", VK_SEMICOLON, false}, 
	{0x3C, "<", VK_COMMA, true}, 
	{0x3D, "=", VK_EQUAL, false}, 
	{0x3E, ">", VK_PERIOD, true}, 
	{0x3F, "?", VK_SLASH, true}, 
	{0x40, "@", VK_2, true}, 
	{0x41, "A", VK_A, true}, 
	{0x42, "B", VK_B, true}, 
	{0x43, "C", VK_C, true}, 
	{0x44, "D", VK_D, true}, 
	{0x45, "E", VK_E, true}, 
	{0x46, "F", VK_F, true}, 
	{0x47, "G", VK_G, true}, 
	{0x48, "H", VK_H, true}, 
	{0x49, "I", VK_I, true}, 
	{0x4A, "J", VK_J, true}, 
	{0x4B, "K", VK_K, true}, 
	{0x4C, "L", VK_L, true}, 
	{0x4D, "M", VK_M, true}, 
	{0x4E, "N", VK_N, true}, 
	{0x4F, "O", VK_O, true}, 
	{0x50, "P", VK_P, true}, 
	{0x51, "Q", VK_Q, true}, 
	{0x52, "R", VK_R, true}, 
	{0x53, "S", VK_S, true}, 
	{0x54, "T", VK_T, true}, 
	{0x55, "U", VK_U, true}, 
	{0x56, "V", VK_V, true}, 
	{0x57, "W", VK_W, true}, 
	{0x58, "X", VK_X, true}, 
	{0x59, "Y", VK_Y, true}, 
	{0x5A, "Z", VK_Z, true}, 

    {0x41, "a", VK_A, false}, 
    {0x42, "b", VK_B, false}, 
    {0x43, "c", VK_C, false}, 
    {0x44, "d", VK_D, false}, 
    {0x45, "e", VK_E, false}, 
    {0x46, "f", VK_F, false}, 
    {0x47, "g", VK_G, false}, 
    {0x48, "h", VK_H, false}, 
    {0x49, "i", VK_I, false}, 
    {0x4A, "j", VK_J, false}, 
    {0x4B, "k", VK_K, false}, 
    {0x4C, "l", VK_L, false}, 
    {0x4D, "m", VK_M, false}, 
    {0x4E, "n", VK_N, false}, 
    {0x4F, "o", VK_O, false}, 
    {0x50, "p", VK_P, false}, 
    {0x51, "q", VK_Q, false}, 
    {0x52, "r", VK_R, false}, 
    {0x53, "s", VK_S, false}, 
    {0x54, "t", VK_T, false}, 
    {0x55, "u", VK_U, false}, 
    {0x56, "v", VK_V, false}, 
    {0x57, "w", VK_W, false}, 
    {0x58, "x", VK_X, false}, 
    {0x59, "y", VK_Y, false}, 
    {0x5A, "z", VK_Z, false}, 

	{0x5B, "[", VK_LBRACKET, false}, 
	{0x5C, "\\", VK_BACKSLASH, false}, 
	{0x5D, "]", VK_RBRACKET, false}, 
	{0x5E, "^", VK_6, true}, 
	{0x5F, "_", VK_HYPHEN, true}, 
	{0x60, "`", VK_BACKQUOTE, false}, 

	{0x61, "a", VK_A, false}, 
	{0x62, "b", VK_B, false}, 
	{0x63, "c", VK_C, false}, 
	{0x64, "d", VK_D, false}, 
	{0x65, "e", VK_E, false}, 
	{0x66, "f", VK_F, false}, 
	{0x67, "g", VK_G, false}, 
	{0x68, "h", VK_H, false}, 
	{0x69, "i", VK_I, false}, 
	{0x6A, "j", VK_J, false}, 
	{0x6B, "k", VK_K, false}, 
	{0x6C, "l", VK_L, false}, 
	{0x6D, "m", VK_M, false}, 
	{0x6E, "n", VK_N, false}, 
	{0x6F, "o", VK_O, false}, 
	{0x70, "p", VK_P, false}, 
	{0x71, "q", VK_Q, false}, 
	{0x72, "r", VK_R, false}, 
	{0x73, "s", VK_S, false}, 
	{0x74, "t", VK_T, false}, 
	{0x75, "u", VK_U, false}, 
	{0x76, "v", VK_V, false}, 
	{0x77, "w", VK_W, false}, 
	{0x78, "x", VK_X, false}, 
	{0x79, "y", VK_Y, false}, 
	{0x7A, "z", VK_Z, false}, 

	{0x7B, "{", VK_LBRACKET, true}, 
	{0x7C, "|", VK_BACKSLASH, true}, 
	{0x7D, "}", VK_RBRACKET, true}, 
	{0x7E, "~", VK_BACKQUOTE, true}, 
	{0x7F, "DEL", VK_DELETE, false},
//this will not come from ASCII barcode readers
	{0x80, "\x80", 0x80, true}, 
	{0x81, "\x81", 0x81, true}, 
	{0x82, "\x82", 0x82, true}, 
	{0x83, "\x83", 0x83, true}, 
	{0x84, "\x84", 0x84, true}, 
	{0x85, "\x85", 0x85, true}, 
	{0x86, "\x86", 0x86, true}, 
	{0x87, "\x87", 0x87, true}, 
	{0x88, "\x88", 0x88, true}, 
	{0x89, "\x89", 0x89, true}, 
	{0x8A, "\x8A", 0x8A, true}, 
	{0x8B, "\x8B", 0x8B, true}, 
	{0x8C, "\x8C", 0x8C, true}, 
	{0x8D, "\x8D", 0x8D, true}, 
	{0x8E, "\x8E", 0x8E, true}, 
	{0x8F, "\x8F", 0x8F, true}, 
	{0x90, "\x90", 0x90, true}, 
	{0x91, "\x91", 0x91, true}, 
	{0x92, "\x92", 0x92, true}, 
	{0x93, "\x93", 0x93, true}, 
	{0x94, "\x94", 0x94, true}, 
	{0x95, "\x95", 0x95, true}, 
	{0x96, "\x96", 0x96, true}, 
	{0x97, "\x97", 0x97, true}, 
	{0x98, "\x98", 0x98, true}, 
	{0x99, "\x99", 0x99, true}, 
	{0x9A, "\x9A", 0x9A, true}, 
	{0x9B, "\x9B", 0x9B, true}, 
	{0x9C, "\x9C", 0x9C, true}, 
	{0x9D, "\x9D", 0x9D, true}, 
	{0x9E, "\x9E", 0x9E, true}, 
	{0x9F, "\x9F", 0x9F, true}, 
	{0xA0, "\xA0", 0xA0, true}, 
	{0xA1, "�", 0xA1, true}, 
	{0xA2, "�", 0xA2, true}, 
	{0xA3, "�", 0xA3, true}, 
	{0xA4, "�", 0xA4, true}, 
	{0xA5, "�", 0xA5, true}, 
	{0xA6, "�", 0xA6, true}, 
	{0xA7, "�", 0xA7, true}, 
	{0xA8, "�", 0xA8, true}, 
	{0xA9, "�", 0xA9, true}, 
	{0xAA, "�", 0xAA, true}, 
	{0xAB, "�", 0xAB, true}, 
	{0xAC, "�", 0xAC, true}, 
	{0xAD, "�", 0xAD, true}, 
	{0xAE, "�", 0xAE, true}, 
	{0xAF, "�", 0xAF, true}, 
	{0xB0, "�", 0xB0, true}, 
	{0xB1, "�", 0xB1, true}, 
	{0xB2, "�", 0xB2, true}, 
	{0xB3, "�", 0xB3, true}, 
	{0xB4, "�", 0xB4, true}, 
	{0xB5, "�", 0xB5, true}, 
	{0xB6, "�", 0xB6, true}, 
	{0xB7, "�", 0xB7, true}, 
	{0xB8, "�", 0xB8, true}, 
	{0xB9, "�", 0xB9, true}, 
	{0xBA, "�", 0xBA, true}, 
	{0xBB, "�", 0xBB, true}, 
	{0xBC, "�", 0xBC, true}, 
	{0xBD, "�", 0xBD, true}, 
	{0xBE, "�", 0xBE, true}, 
	{0xBF, "�", 0xBF, true}, 
	{0xC0, "�", 0xC0, true}, 
	{0xC1, "�", 0xC1, true}, 
	{0xC2, "�", 0xC2, true}, 
	{0xC3, "�", 0xC3, true}, 
	{0xC4, "�", 0xC4, true}, 
	{0xC5, "�", 0xC5, true}, 
	{0xC6, "�", 0xC6, true}, 
	{0xC7, "�", 0xC7, true}, 
	{0xC8, "�", 0xC8, true}, 
	{0xC9, "�", 0xC9, true}, 
	{0xCA, "�", 0xCA, true}, 
	{0xCB, "�", 0xCB, true}, 
	{0xCC, "�", 0xCC, true}, 
	{0xCD, "�", 0xCD, true}, 
	{0xCE, "�", 0xCE, true}, 
	{0xCF, "�", 0xCF, true}, 
	{0xD0, "�", 0xD0, true}, 
	{0xD1, "�", 0xD1, true}, 
	{0xD2, "�", 0xD2, true}, 
	{0xD3, "�", 0xD3, true}, 
	{0xD4, "�", 0xD4, true}, 
	{0xD5, "�", 0xD5, true}, 
	{0xD6, "�", 0xD6, true}, 
	{0xD7, "�", 0xD7, true}, 
	{0xD8, "�", 0xD8, true}, 
	{0xD9, "�", 0xD9, true}, 
	{0xDA, "�", 0xDA, true}, 
	{0xDB, "�", 0xDB, true}, 
	{0xDC, "�", 0xDC, true}, 
	{0xDD, "�", 0xDD, true}, 
	{0xDE, "�", 0xDE, true}, 
	{0xDF, "�", 0xDF, true}, 
	{0xE0, "�", 0xE0, true}, 
	{0xE1, "�", 0xE1, true}, 
	{0xE2, "�", 0xE2, true}, 
	{0xE3, "�", 0xE3, true}, 
	{0xE4, "�", 0xE4, true}, 
	{0xE5, "�", 0xE5, true}, 
	{0xE6, "�", 0xE6, true}, 
	{0xE7, "�", 0xE7, true}, 
	{0xE8, "�", 0xE8, true}, 
	{0xE9, "�", 0xE9, true}, 
	{0xEA, "�", 0xEA, true}, 
	{0xEB, "�", 0xEB, true}, 
	{0xEC, "�", 0xEC, true}, 
	{0xED, "�", 0xED, true}, 
	{0xEE, "�", 0xEE, true}, 
	{0xEF, "�", 0xEF, true}, 
	{0xF0, "�", 0xF0, true}, 
	{0xF1, "�", 0xF1, true}, 
	{0xF2, "�", 0xF2, true}, 
	{0xF3, "�", 0xF3, true}, 
	{0xF4, "�", 0xF4, true}, 
	{0xF5, "�", 0xF5, true}, 
	{0xF6, "�", 0xF6, true}, 
	{0xF7, "�", 0xF7, true}, 
	{0xF8, "�", 0xF8, true}, 
	{0xF9, "�", 0xF9, true}, 
	{0xFA, "�", 0xFA, true}, 
	{0xFB, "�", 0xFB, true}, 
	{0xFC, "�", 0xFC, true}, 
	{0xFD, "�", 0xFD, true}, 
	{0xFE, "�", 0xFE, true}, 
	{0xFF, "�", 0xFF, true}
};



