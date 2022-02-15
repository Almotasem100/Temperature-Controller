/*
 * ADC.h
 *
 * Created: 6/6/2020 4:59:46 PM
 *  Author: Ahmed Alnouby
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "Basic_Types.h"
/*
#define ADCSRA       (*((PtReg) (0X26)))
#define ADMUX        (*((PtReg) (0X27)))
#define ADCL         (*((PtReg) (0X24)))
#define ADCH         (*((PtReg) (0X25)))
#define SFIOR        (*((PtReg) (0X50)))


#define REFS0       ((vu8 ) (6 ))
#define ADEN       ((vu8  ) ( 7))
#define ADPS2       ((vu8  ) (2 ))
#define ADPS1       ((vu8  ) ( 1))
#define ADSC       ((vu8  ) (6 ))
#define ADIF       ((vu8  ) (4 ))

#define ADPS0       ((vu8  ) (0 ))
#define ADATE       ((vu8  ) (5 ))
#define ADTS2       ((vu8  ) (7 ))
#define ADTS1       ((vu8  ) (6 ))
#define ADTS0       ((vu8  ) (5 ))
*/



void ADC_init(void);
void ADC_voff(void);
float32_t ADC_float32_tRead(void);

#endif /* ADC_H_ */
