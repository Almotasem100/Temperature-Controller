#ifndef BASIC_TYPES_HEADER
#define BASIC_TYPES_HEADER

#define F_CPU 1000000UL

typedef unsigned short int u16;
typedef float  float32_t;
typedef unsigned char  u8;
typedef volatile unsigned char  vu8;
typedef  volatile unsigned char *const PtReg;
typedef  volatile unsigned short int *const PtReg16;
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#endif

