/*
 * TIMER.c
 *
 * Created: 5/16/2021 2:28:55 PM
 *  Author: remon
 */ 
/* #include "macros.h"*/
#include "Regesters.h"
#include "DIO.h"
#include "TIMER.h"
#include "Basic_Types.h"

void TIMER_init0_CTC_interrupt(u8 value){
    /*select mode*/
    TCCR0 |= (u8)((u8)1<<WGM01);
    TCCR0 &= (u8)((u8)~(u8)((u8)1<<WGM00));
    /*enable global interrupt*/

    /*sei();*/
    /*misra violation beacaude this function is from another library */

    /*define clock(prescaler)*/
    TCCR0 |= (u8)((u8)1<<CS00);
    TCCR0 &= (u8)(~(u8)((u8)1<<CS01));
    TCCR0 |= (u8)((u8)1<<CS02);
    /*compare value*/
    OCR0=value;
    /*enable compare interrupt*/
    TIMSK |= (u8)((u8)1<<OCIE0);
}



void TimerOff(void)
{
    TIMSK &= (u8)~((u8)((u8)1<<OCIE0));
    TIMSK &= (u8)~((u8)((u8)1<<TOIE1));
    TIMSK &= (u8)~((u8)((u8)1<<TOIE2));
    TIMSK &= (u8)~((u8)((u8)1<<TOIE0));
    TIMSK &= (u8)~((u8)((u8)1<<TOIE1));
    TIMSK &= (u8)~((u8)((u8)1<<TOIE2));
}




