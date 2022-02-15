/*
 * Regesters.h
 *
 *  Created on: Jun 8, 2021
 *      Author: kuro-
 */

#ifndef REGESTERS_HEADER_
#define REGESTERS_HEADER_

#include"Basic_Types.h"

#define ADCSRA       (*((PtReg) (0X26)))
#define ADMUX        (*((PtReg) (0X27)))
#define ADCL         (*((PtReg) (0X24)))
#define ADCH         (*((PtReg) (0X25)))
#define SFIOR        (*((PtReg) (0X50)))
#define TCCR0        (*((PtReg) (0x53)))
#define TIMSK        (*((PtReg) (0x59)))
#define OCR0         (*((PtReg) (0x5C)))
#define TCCR1A       (*((PtReg) (0x4F)))
#define TCCR1B       (*((PtReg) (0x4E)))
#define OCR1A        (*((PtReg16) (0x4a)))
#define OCR1B        (*((PtReg16) (0x48)))

#define PORTA (*((PtReg)( 0x3B)))
#define DDRA (*((PtReg)(0x3A)))
#define PINA (*((PtReg)(0x39)))

#define PORTB  (*((PtReg)(0x38)))
#define DDRB  (*((PtReg)(0x37)))
#define PINB  (*((PtReg)(0x36)))

#define PORTC  (*((PtReg)( 0x35)))
#define DDRC  (*((PtReg)(0x34)))
#define PINC  (*((PtReg)( 0x33)))

#define PORTD  (*((PtReg)(0x32)))
#define DDRD  (*((PtReg)( 0x31)))
#define PIND  (*((PtReg)( 0x30)))

#define SPCR (*((PtReg)( 0x2D)))
#define SPSR (*((PtReg)( 0x2E)))
#define SPDR (*((PtReg)( 0x2F)))

#define SPIF ((vu8 ) (7 ))
#define SPE ((vu8 ) (6 ))
#define SPR0 ((vu8 ) (0 ))
#define SPR1 ((vu8 ) (1 ))
#define CPHA ((vu8 ) (2 ))
#define CPOL ((vu8 ) (3 ))
#define MSTR ((vu8 ) (4 ))
#define CPHA ((vu8 ) (2 ))


#define REFS0       ((vu8 ) (6 ))
#define ADEN       ((vu8  ) ( 7))
#define ADPS2       ((vu8  ) (2 ))
#define ADPS1       ((vu8  ) ( 1))
#define ADSC       ((vu8  ) (6 ))
#define ADIF       ((vu8  ) (4 ))
#define ADPS0       ((vu8  ) (0 ))
#define ADATE       ((vu8  ) (5 ))
#define ADTS2       ((vu8  ) (7 ))
#define ADTS1       ((vu8  ) (6 ))
#define ADTS0       ((vu8  ) (5 ))

#define DDD4       ((vu8  ) (4 ))
#define COM1B1       ((vu8  ) (5 ))
#define WGM11       ((vu8  ) (1 ))
#define WGM10       ((vu8  ) (0 ))
#define CS10       ((vu8  ) (0 ))
#define WGM12       ((vu8  ) (3 ))
#define OCIE0       ((vu8  ) (1 ))
#define TOIE1       ((vu8  ) (2 ))
#define TOIE2       ((vu8  ) (6 ))
#define TOIE0       ((vu8  ) (0 ))
#define CS00       ((vu8  ) (0 ))
#define CS01       ((vu8  ) (1 ))
#define CS02       ((vu8  ) (2 ))
#define WGM00       ((vu8  ) (6 ))
#define WGM01       ((vu8  ) (3 ))

/* defining the registers in this way will violate MISRA rule 11.3 and will 
generate many of warning in DIO ,ADC,PWM,Timer,LCD and SPI files 
Becouse we write in the content of a pointer The error show it self But that is alright fo us Embedded Engineer*/



/*breaks MISRA rule 1.1
(MISRA rules require that you build in strict ANSI mode.
This means it is an error to use any feature not specified in the ANSI standard.
In your case, these features are the keywords cregister and interrupt.
The net effect is you cannot use interrupt and cregister and, at the same time, conform to MISRA.)*/


#endif /* REGESTERS_HEADER_ */
