#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED
#include "Basic_Types.h"

void PWM_init(void); /*I do not get this warning*/
void PWM_fast(float32_t duty_cycle);
void PWM_off(void);

#endif /* PWM_H_INCLUDED */
