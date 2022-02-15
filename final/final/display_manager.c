#define F_CPU 1000000UL

#include "LCD.h"
#include "display_manager.h"
#include "Basic_Types.h"
#include "Regesters.h"

void display_welcome(void)
{
	lcd_init();
	u8 i = 0;
	u8 counter = 0;
	for (counter = (u8)0; counter < (u8)3; counter++)
	{
		for(i = (u8)10; i > (u8)0; i--)
		{
			lcdCommand((u8)0x01);
			_delay_ms(2);
			lcd_gotoxy((u8)i, (u8)1);
			lcd_print("WELCOME");
			_delay_ms(100);
		}
		for(i = (u8)1; i < (u8)11; i++)
		{
			lcdCommand((u8)0x01);
			_delay_ms(2);
			lcd_gotoxy((u8)i, (u8)1);
			lcd_print("WELCOME");
			_delay_ms(100);
		}
	}
}

void display_state(u8 setTemperature, u8 currentTemperature, u8 state)
{
	lcdCommand((u8)0x01);
	_delay_ms(2);
	lcd_gotoxy((u8)1, (u8)1);
	lcd_print("SET:");
	lcdData((setTemperature/(u8)10)+(u8)48);
	lcdData((setTemperature%(u8)10)+(u8)48);
	lcd_gotoxy((u8)10, (u8)1);
	lcd_print("CRT:");
	lcdData((currentTemperature/(u8)10)+(u8)48);
	lcdData((currentTemperature%(u8)10)+(u8)48);
	lcd_gotoxy((u8)1, (u8)2);
	lcd_print("STATE:");
	switch(state){
		case (u8)1:
		lcd_print("STANDBY");
		break;
		case (u8)2:
		lcd_print("OPERATION");
		break;
		case (u8)3:
		lcd_print("NORMAL");
		break;
		case (u8)4:
		lcd_print("ERROR");
		break;
		case (u8)5:
		lcd_print("SET_TEMP");
		break;
		default:
		lcd_print("ERROR");
		break;
	}
}

void update_set(u8 setTemp)
{

	lcd_gotoxy((u8)5, (u8)1);
	lcdData((setTemp/(u8)10) + (u8)48);
	lcdData((setTemp%(u8)10) + (u8)48);
}

void update_current(u8 currentTemp)
{
	lcd_gotoxy((u8)14, (u8)1);
	lcdData((currentTemp/(u8)10) + (u8)48);
	lcdData((currentTemp %(u8)10) + (u8)48);
}

void update_state(u8 state)
{
	lcd_gotoxy((u8) 7, (u8) 2);
	switch(state){
		case (u8)1:
		lcd_print("STANDBY  ");
		break;
		case (u8)2:
		lcd_print("OPERATION");
		break;
		case (u8)3:
		lcd_print("NORMAL    ");
		break;
		case (u8)4:
		lcd_print("ERROR    ");
		break;
		case (u8)5:
		lcd_print("SET_TEMP ");
		break;
		default:
		lcd_print("ERROR    ");
		break;
	}
}


