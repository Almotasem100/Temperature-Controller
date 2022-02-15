/*
 * TC72.c
 *
 * Created: 6/1/2021 10:37:08 PM
 *  Author: Remon
 */ 
#include "Regesters.h"

#include "DIO.h"
#include "SPI.h"
#include "TC72.h"
/*#include <util/delay.h>*/
#include "Basic_Types.h"

void TC72_init_continuos(void){
    SPI_master_init();
    DIO_write_bit((u8)1,(u8)4,(u8)0);
    DIO_write_bit((u8)1,(u8)4,(u8)1);
    SPI_master_transmit_char((u8)0x80);
    SPI_master_transmit_char((u8)0x04);
}
void TC72_off_continuos(void){
    SPI_master_off();
}

u8 TC72_get_temp(void){
    u8 data;
    DIO_write_bit((u8)1,(u8)4,(u8)0);
    DIO_write_bit((u8)1,(u8)4,(u8)1);
    data=SPI_master_transmit_char((u8)0x02);
    data=(signed char)SPI_master_transmit_char((u8)0x00);
    return data;

}

