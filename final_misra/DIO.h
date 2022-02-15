#ifndef DIO_H_
#define DIO_H_
/* defining the registers in this way will violate MISRA rule 11.3 and will 
generate many of warning in DIO ,ADC,PWM,Timer,LCD and SPI files 
Becouse we write in the content of a pointer The error show it self But that is alright fo us Embedded Engineer*/



/*breaks MISRA rule 1.1
(MISRA rules require that you build in strict ANSI mode.
This means it is an error to use any feature not specified in the ANSI standard.
In your case, these features are the keywords cregister and interrupt.
The net effect is you cannot use interrupt and cregister and, at the same time, conform to MISRA.)*/

/*
#define PORTA (*((volatile unsigned char *const)( 0x3B)))
#define DDRA (*((volatile unsigned char *const)(0x3A)))
#define PINA (*((volatile unsigned char *const)(0x39)))

#define PORTB  (*((volatile unsigned char *const)(0x38)))
#define DDRB  (*((volatile unsigned char *const)(0x37)))
#define PINB  (*((volatile unsigned char *const)(0x36)))

#define PORTC  (*((volatile unsigned char *const)( 0x35)))
#define DDRC  (*((volatile unsigned char *const)(0x34)))
#define PINC  (*((volatile unsigned char *const)( 0x33)))

#define PORTD  (*((volatile unsigned char *const)(0x32)))
#define DDRD  (*((volatile unsigned char *const)( 0x31)))
#define PIND  (*((volatile unsigned char *const)( 0x30)))
*/
#include"Basic_Types.h"

void DIO_set_bit_dir(u8 port,u8 bit , u8 dir);


u8 DIO_read_bit(u8 port,u8 bit);
void DIO_write_bit(u8 port,u8 bit , u8 value);
void DIO_toggle_bit(u8 port,u8 bit);
void DIO_set_port_dir(u8 port , u8 dir);
void DIO_write_port(u8 port, u8 value);
u8 DIO_read_port(u8 port);
void DIO_connect_pullup(u8 port,u8 bit,u8 connect);
void DIO_write_low_nibble(u8 port,u8 value);
void DIO_write_high_nibble(u8 port,u8 value);
void DIO_and_port(u8 port , u8 value);
void DIO_or_port(u8 port , u8 value); 


u8 READ_BIT(u8 REG,u8 BIT);

#endif
