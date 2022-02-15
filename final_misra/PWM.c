/*#include <avr/io.h>*/
#include "PWM.h"
#include "Basic_Types.h"
#include "Regesters.h"

void PWM_init(void){

    /* fast pwm mode */
    TCCR1A |= (u8)((u8)((u8)1 << COM1B1) | (u8)((u8)1 << WGM11) | (u8)((u8)1 << WGM10));
    /* CS10= 1 means no prescaler, WGM12= 1 means clear time on compare match mode is enabled  */
    TCCR1B |= (u8)((u8)((u8)1 << CS10) | (u8)((u8)1 << WGM12));
    /* set OC1B as output (PD04) */
    DDRD |= (u8)((u8)1 << DDD4);
}


void PWM_fast(float32_t duty_cycle){
    /*frequency*/
    OCR1A = (u16)1000;
    /* (0-1023) */
    if ((float32_t)duty_cycle > (float32_t)0)
    {
        OCR1B = (u16)duty_cycle;
    }
    else
    {
        OCR1B = (u16)0;

    }
}


void PWM_off(void){
    /*frequency*/
    OCR1A = (u8)0;
    /* (0-1023) */
    OCR1B = (u8)0;
}
