#include "Basic_Types.h"
#include "PWM.h"
#include "heater_control.h"
#include "Basic_Types.h"
#include "adc.h"
#include "Regesters.h"

void duty_cycle_control(u8 set_temp, u8 crt_temp, float32_t pot_value){

    float32_t target_V;
    float32_t duty_cycle_pwm;



    target_V =(float32_t) (((float32_t) ((float32_t)set_temp -(float32_t) crt_temp) /(float32_t)100.0)* (float32_t)10.0);

    duty_cycle_pwm = (float32_t) (((((pot_value)*(float32_t)2)/(float32_t)10.0) * (target_V))/(float32_t)10.0) * (float32_t)1022.0;


    PWM_fast(duty_cycle_pwm);
}
void heaterOff(void)
{
    PWM_off();
    ADC_voff();
}

float32_t ADC_read(void)
{
    ADC_init();
    float32_t volt =ADC_float32_tRead();
    ADC_voff();
    return volt;
}
void PwmOff(void)
{
    PWM_off();
}
void heaterOn(void)
{
    PWM_init();
}
