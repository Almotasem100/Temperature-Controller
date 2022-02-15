#include "DIO.h"
#include "Basic_Types.h"
#include "Regesters.h"


void DIO_set_bit_dir(u8 port, u8 bit , u8 dir){
	switch(port){
		case (u8) 0 : /*port A*/
		if (dir==(u8) 1){
			DDRA |= (u8)( (u8)1 << bit) ;
		}
		else{
			DDRA &= (u8)(~ (u8)( (u8)1 << bit )) ;
		}
		break;
		case (u8) 1: /*port B*/
		if (dir==(u8) 1){
			DDRB |= (u8)((u8)1 << bit)  ;
		}
		else{
			DDRB &= (u8)(~ (u8)((u8)1 << bit )) ;
		}
		break;
		case (u8) 2 : /*port c*/
		if (dir==(u8) 1){
			DDRC |= (u8)((u8)1 << bit) ;
		}
		else{
			DDRC &= (u8)( ~(u8)((u8)1 << bit )) ;
		}
		break;
		case (u8) 3 : /*port D*/
		if (dir==(u8) 1){
			DDRD|= (u8)((u8)1 << bit) ;
		}
		else{
			DDRD &= (u8)(~(u8)((u8)1 << bit ) );
		}
		break;
		default :
		break;
	}
}
u8 DIO_read_bit(u8 port,u8 bit){
	u8 val;
	switch(port){
		case (u8) 0:
		val= (u8)( (PINA & (u8)((u8)1<<bit) ) >> bit ) ;
		break;
		case (u8) 1:
		val= (u8)( (PINB & (u8)((u8)1<<bit) ) >> bit ) ;
		break;
		case (u8) 2:
		val= (u8)( (PINC & (u8)((u8)1<<bit) ) >> bit );
		break;
		case (u8) 3:
		val=(u8)( (PIND & (u8)((u8)1<<bit) ) >> bit );
		break;
		default :
		break;
	}
	return val;
}
void DIO_write_bit(u8 port,u8 bit , u8 value){
	switch(port){
		case (u8) 0 : /*port A*/
		if (value==(u8) 1){
			PORTA |= (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTA &= (u8)(~(u8)((u8)1 << bit ) ) ;
		}
		break;
		case (u8) 1: /*port B*/
		if (value==(u8) 1){
			PORTB |= (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTB &= (u8)(~(u8)((u8)1 << bit ) ) ;
		}
		break;
		case (u8) 2 : /*port c*/
		if (value==(u8) 1){
			PORTC |= (u8)( (u8)1 << bit) ;
		}
		else{
			PORTC &= (u8)(~(u8)((u8)1 << bit ) );
		}
		break;
		case (u8) 3 : /*port D */
		if (value==(u8) 1){
			PORTD|= (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTD &= (u8)(~(u8)((u8)1 << bit ) ) ;
		}
		break;
		default :
		break;
	}
}
void DIO_toggle_bit(u8 port,u8 bit){
	switch(port){
		case (u8) 0:
		PORTA ^= (u8)( (u8)1 << bit) ;
		break;
		case (u8) 1:
		PORTB ^= (u8)( (u8)1 << bit)  ;
		break;
		case (u8) 2:
		PORTC ^= (u8)( (u8)1 << bit)  ;
		break;
		case (u8) 3:
		PORTD ^= (u8)( (u8)1 << bit)  ;
		break;
		default :
		break;
	}
}
void DIO_set_port_dir(u8 port , u8 dir){
	switch(port){
		case (u8) 0:
		if (dir==(u8) 1){
			DDRA=(u8) 0xff;
		}
		else{
			DDRA=(u8)0x00;
		}
		break;
		case (u8) 1:
		if (dir==(u8) 1){
			DDRB=(u8)0xff;
		}
		else{
			DDRB=(u8)0x00;
		}
		break;
		case (u8) 2:
		if (dir==(u8)1){
			DDRC=(u8)0xff;
		}
		else{
			DDRC=(u8)0x00;
		}
		break;
		case (u8) 3:
		if (dir==(u8) 1){
			DDRD=(u8)0xff;
		}
		else{
			DDRD=(u8)0x00;
		}
		break;
		default :
		break;
	}
}
void DIO_write_port(u8 port, u8 value){
	switch(port){
		case (u8) 0:
		PORTA=(u8)value;
		break;
		case (u8) 1:
		PORTB=value;
		break;
		case (u8) 2:
		PORTC=value;
		break;
		case (u8) 3:
		PORTD=value;
		break;
		default :
		break;
	}
}
u8 DIO_read_port(u8 port){
	u8 data;
	switch(port){
		case (u8) 0:
		data=PINA;
		break;
		case (u8) 1:
		data=PINB;
		break;
		case (u8) 2:
		data=PINC;
		break;
		case (u8) 3:
		data=PIND;
		break;
		default :
		break;
	}
	return data;
}

void DIO_connect_pullup(u8 port,u8 bit,u8 connect){
	switch(port){
		case (u8) 0:
		if (connect==(u8) 1){
			PORTA |=  (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTA &= (u8)(~(u8)((u8)1 << bit ) ) ;
		}
		break;
		case (u8) 1:
		if (connect==(u8)1){
			PORTB |=  (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTB &= (u8)(~(u8)((u8)1 << bit ) ) ;
		}
		break;
		case (u8) 2:
		if (connect==(u8) 1){
			PORTC |=  (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTC &= (u8)(~(u8)((u8)1 << bit ) );
		}
		break;
		case (u8) 3:
		if (connect==(u8) 1){
			PORTD |=  (u8)( (u8)1 << bit)  ;
		}
		else{
			PORTD &= (u8)(~(u8)((u8)1 << bit ) ) ;
		}
		break;
		default :
		break;
	}
}

void DIO_write_low_nibble(u8 port,u8 value){
	value &= (u8) 0x0f;
	switch(port){
		case (u8) 0:
		PORTA &= (u8) 0xf0;
		PORTA |= value;
		break;
		case (u8) 1 :
		PORTB &= (u8) 0xf0;
		PORTB |=value;
		break;
		case (u8) 2:
		PORTC &= (u8) 0xf0;
		PORTC|=value;
		break;
		case (u8) 3:
		PORTD &= (u8) 0xf0;
		PORTD|=value;
		break;
		default :
		break;
	}
}

void DIO_write_high_nibble(u8 port,u8 value){
	value<<=4;
	switch(port){
		case (u8) 0:
		PORTA &= (u8) 0x0f;
		PORTA |= value;
		break;
		case (u8) 1:
		PORTB &= (u8) 0x0f;
		PORTB |= value;
		break;
		case (u8) 2:
		PORTC &= (u8) 0x0f;
		PORTC |= value;
		break;
		case (u8) 3:
		PORTD &= (u8) 0x0f;
		PORTD |= value;
		break;
		default :
		break;
	}
}

void DIO_and_port(u8 port , u8 value){
	switch(port){
		case (u8) 0:
		PORTA &= value;
		break;

		case (u8) 1:
		PORTB &= value;
		break;

		case (u8) 2:
		PORTC &= value;
		break;

		case (u8) 3:
		PORTD &= value;
		break;
		default :
		break;


	}
}
void DIO_or_port(u8 port , u8 value){
	switch(port){
		case (u8) 0:
		PORTA |= value;
		break;

		case (u8) 1:
		PORTB |= value;
		break;

		case (u8) 2:
		PORTC |= value;
		break;

		case (u8) 3:
		PORTD |= value;
		break;
		default :
		break;

	}
}

