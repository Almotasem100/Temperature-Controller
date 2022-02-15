#ifndef display_manager_
#define display_manager_
#include "Basic_Types.h"

void display_welcome(void);
void update_current(u8 currentTemp);
void update_set(u8 setTemp);
void display_state(u8 setTemperature, u8 currentTemperature, u8 state);
void update_state(u8 state);
#endif /* display_manager_ */
