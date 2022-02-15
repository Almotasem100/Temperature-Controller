#ifndef heater_control_H_
#define heater_control_H_
#include "Basic_Types.h"



void duty_cycle_control(u8 set_temp, u8 crt_temp, float32_t pot_value);
void heaterOff(void);
float32_t ADC_read(void);
void PwmOff(void);
void heaterOn(void);

#endif
