/*
 * ADC.c
 *
 * Created: 6/6/2020 4:59:46 PM
 *  Author: Ahmed Alnouby
 */
#include "Basic_Types.h"
#include "ADC.h"
#include "Regesters.h"


void ADC_init(void)
{
    ADMUX|=(u8)((u8)1<<REFS0);
    ADCSRA|=(u8)((u8)1<<ADEN);
    /* adjust ADC clock*/
    ADCSRA|=(u8)((u8)1<<ADPS2);
    ADCSRA|=(u8)((u8)1<<ADPS1);


    ADCSRA|=(u8)((u8)1<<ADATE);
    SFIOR |= (u8)((u8)1<<ADTS2);
    SFIOR |= (u8)((u8)1<<ADTS1);
    SFIOR &=(u8)(~(u8)((u8)1<<ADTS0));
}
void ADC_voff(void)
{
    ADMUX &= (u8)(~(u8)((u8)1<<REFS0));
    ADCSRA &= (u8)(~(u8)((u8)1<<ADEN));
    /* adjust ADC clock*/
    ADCSRA &= (u8)(~(u8)((u8)1<<ADPS2));
    ADCSRA &= (u8)(~(u8)((u8)1<<ADPS1));


    ADCSRA &=(u8)(~(u8)((u8)1<<ADATE));
    SFIOR &= (u8)(~(u8)((u8)1<<ADTS2));
    SFIOR &= (u8)(~(u8)((u8)1<<ADTS1));
    SFIOR &= (u8)(~(u8)((u8)1<<ADTS0));
}

float32_t ADC_float32_tRead(void)
{
    u16 read_val;
    ADCSRA |= (u8)((u8)1<<ADSC);

    while( ((u8)( (u8)(ADCSRA & (u8)( (u8)1 << ADIF) ) >> ADIF)) == (u8) 0 ){

    }
    ADCSRA|=(u8)((u8)1<<ADIF);

    read_val= (u16) ADCL;/*Justification for 10.3 it will read the value from two regesters and ouput it in 1 variable with type u16*/
    read_val|= (u16) ((u16)ADCH << 8);/*Justification for 10.3 it will read the value from two regesters and ouput it in 1 variable with type u16*/

    float32_t volt = (float32_t)read_val /(float32_t)22;
    if (volt >(float32_t)5)
    {
        volt=(float32_t)5;
    }
    return volt ;
}
