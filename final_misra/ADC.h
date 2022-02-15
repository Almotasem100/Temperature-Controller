/*
 * ADC.h
 *
 * Created: 6/6/2020 4:59:46 PM
 *  Author: Ahmed Alnouby
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "Basic_Types.h"



void ADC_init(void);
void ADC_voff(void);
float32_t ADC_float32_tRead(void);

#endif /* ADC_H_ */
