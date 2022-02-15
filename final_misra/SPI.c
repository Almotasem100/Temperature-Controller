/*
 * SPI.c
 *
 * Created: 9/5/2017 8:35:09 PM
 * 
 */ 


#include "Regesters.h"
#include "Basic_Types.h"
#include "DIO.h"
#include "SPI.h"
#include "TC72.h"
/*#include <util/delay.h>*/

void SPI_master_init(void)
{
    /*Set SS / MOSI / SCK  as output pins for master*/
    DIO_set_bit_dir((u8)1,(u8)4,(u8)1);
    DIO_set_bit_dir((u8)1,(u8)5,(u8)1);
    DIO_set_bit_dir((u8)1,(u8)7,(u8)1);
    /*Enable Master mode*/
    SPCR |= (u8)((u8)1<<MSTR);
    /*Set clock to fosc/128*/
    SPCR|= (u8)((u8)1<<SPR0);
    SPCR|= (u8)((u8)1<<SPR1);
    /*SPI mode 0*/
    SPCR |= (u8)((u8)1<<CPHA);
    SPCR &= (u8)(~(u8)((u8)1<<CPOL));
    /*Enable SPI*/
    SPCR |= (u8)((u8)1<<SPE);
}
void SPI_master_off(void){
    SPCR &= (u8)~((u8)((u8)1<<SPE));
}

u8 SPI_master_transmit_char(u8 Data)
{
    /*Clear SS to send data to slave*/
    /*Put data on SPDR*/
     SPDR=Data;
    /*Wait until the transmission is finished*/
     while( (u8)( (SPSR & (u8)((u8)1<<SPIF) )>>SPIF) == (u8)0){}
     /*read SPDR*/
     return SPDR ;
}






