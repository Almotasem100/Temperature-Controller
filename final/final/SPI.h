/*
 * SPI.h
 *
 * Created: 6/1/2021 4:50:07 PM
 *  Author: Remon
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Basic_Types.h"

void SPI_master_init(void);/*misra rule 1.1 (don't understand it)*/
u8 SPI_master_transmit_char(u8 Data);
void SPI_master_off(void);





#endif /* SPI_H_ */
