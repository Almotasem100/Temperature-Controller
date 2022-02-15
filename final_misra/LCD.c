/*
 * LCD.c
 *
 * Created: 6/5/2021 9:47:31 PM
 *  Author: nancy
 */ 
#define F_CPU 1000000UL
#include "DIO.h"
#include "Basic_Types.h"
#include "Regesters.h"

#include "LCD.h"
#define LCD_DPRT (PORTA)          /*LCD DATA PORT*/
#define LCD_DDDR (DDRA)      /*LCD DATA DDR*/
#define LCD_DPIN (PINA)          /*LCD DATA PIN*/
#define LCD_CPRT (PORTB)             /*LCD COMMANDS PORT*/
#define LCD_CDDR (DDRB)          /*LCD COMMANDS DDR*/
#define LCD_CPIN (PINB)          /*LCD COMMANDS PIN*/
#define LCD_RS ((u8)1)                 /*LCD RS*/
#define LCD_RW ((u8)2)                 /*LCD RW*/
#define LCD_EN ((u8)0)                 /*LCD EN*/



void lcdCommand(u8 cmnd)
{
    LCD_DPRT = cmnd & (u8)0xF0;          /*send high nibble to D4-D7*/
    LCD_CPRT &=(u8) ~ (u8)((u8)1<<LCD_RS);        /*RS = 0 for command*/
    LCD_CPRT &= (u8)~ (u8)((u8)1<<LCD_RW);        /*RW = 0 for write*/
    LCD_CPRT |= (u8)((u8)1<<LCD_EN);          /*EN = 1 for H-to-L pulse*/
    /*_delay_us(1);            */                    /*make EN pulse wider*/
    LCD_CPRT &=(u8) ~ (u8)((u8)1<<LCD_EN);        /*EN = 0 for H-to-L pulse*/
    /*_delay_us(100);      */                    /*wait*/
    LCD_DPRT = cmnd<<4;                              /*send low nibble to D4-D7*/
    LCD_CPRT |= (u8)((u8)1<<LCD_EN);          /*EN = 1 for H-to-L pulse*/
    /*_delay_us(1);          */                      /*make EN pulse wider*/
    LCD_CPRT &= (u8)~ (u8)((u8)1<<LCD_EN);        /*EN = 0 for H-to-L pulse*/
    /*_delay_us(100);      */                /*wait*/
}

void lcdData(u8 data)
{
    LCD_DPRT = data & (u8)0xF0;          /*send high nibble to D4-D7*/
    LCD_CPRT |= (u8)((u8)1<<LCD_RS);         /*RS = 1 for data*/
    LCD_CPRT &= (u8)~(u8) ((u8)1<<LCD_RW);       /*RW = 0 for write*/
    LCD_CPRT |=(u8) ((u8)1<<LCD_EN);         /*EN = 1 for H-to-L pulse*/
    /*_delay_us(1);       */                        /*make EN pulse wider*/
    LCD_CPRT &= (u8)~ (u8)((u8)1<<LCD_EN);       /*EN = 0 for H-to-L pulse*/
    LCD_DPRT = data<<4;                             /*send low nibble to D4-D7*/
    LCD_CPRT |= (u8)((u8)1<<LCD_EN);         /*EN = 1 for H-to-L pulse*/
    /*_delay_us(1);    */                           /*make EN pulse wider*/
    LCD_CPRT &=(u8) ~ (u8)((u8)1<<LCD_EN);       /*EN = 0 for H-to-L pulse*/
    /*_delay_us(100);       */                      /*wait*/
}

void lcd_init(void)
{
    LCD_DDDR = (u8) 0xFF;
    LCD_CDDR = (u8) 0xFF;
    LCD_CPRT &= (u8)~ (u8)((u8)1<<LCD_EN);       /*LCD_EN = 0*/
    lcdCommand((u8)0x33);                /*send $33 for init*/
    lcdCommand((u8)0x32);                /*send $32 for init*/
    lcdCommand((u8)0x28);                /*init. LCD 2 line, 5x7 matrix*/
    lcdCommand((u8)0x0c);                /*display on, cursor on*/
    lcdCommand((u8)0x01);                /*clear LCD*/
    /*_delay_us(2000);*/
    lcdCommand((u8)0x06);                /*shift cursor right*/
}

void lcd_gotoxy(u8 x, u8  y)
{
    u8 firstCharAdr[] = {0x80, 0xC0, 0x94, 0xD4};
    lcdCommand((firstCharAdr[y-(u8)1] + x) - (u8)1);
    /*_delay_us(100);*/
}

void lcd_print(const char * str)
{
    u8 i = 0;
    while((u8)str[i] != (u8)0)/*Justification for 17.4 the index will never exceed our predected range*/
    {
        lcdData((u8)str[i]);/*Justification for 17.4 the index will never exceed our predected range*/
        i++;
    }
}
