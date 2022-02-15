/*
 * LCD.h
 *
 * Created: 6/5/2021 9:48:09 PM
 *  Author: nancy
 */ 
#ifndef LCD_H_
#define LCD_H_
#include "Basic_Types.h"

/*void delay_us(int d);*/
void lcdCommand(u8 cmnd);
void lcdData(u8 data);
void lcd_init(void);
void lcd_gotoxy(u8 x, u8 y);
void lcd_print(const char * str);

#endif /* LCD_H_ */
