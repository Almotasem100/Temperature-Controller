#ifndef KEYPAD_H_
#define KEYPAD_H_
#define PORT 2
#define NOTPRESSED 0xFF

#include"Basic_Types.h"

void KEYPAD_init(void);
u8 KEYPAD_read(void);




#endif /* KEYPAD_H_ */
