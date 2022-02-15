#include "KEYPAD.h"
#include "DIO.h"
#include "Basic_Types.h"
#include "Regesters.h"

void KEYPAD_init(void){
	DIO_set_bit_dir((u8) PORT, (u8) 0, (u8) 1); /*output*/
	DIO_set_bit_dir((u8) PORT, (u8) 1, (u8) 1); /*output*/
	DIO_set_bit_dir((u8) PORT, (u8) 2, (u8) 1); /*output*/
	DIO_set_bit_dir((u8) PORT, (u8) 3, (u8) 1); /*output*/
	DIO_set_bit_dir((u8) PORT, (u8) 4, (u8) 0); /*input*/
	DIO_set_bit_dir((u8) PORT, (u8) 5, (u8) 0); /*input*/
	DIO_set_bit_dir((u8) PORT, (u8) 6, (u8) 0); /*input*/
	DIO_set_bit_dir((u8) PORT, (u8) 7, (u8) 0); /*input*/
	DIO_connect_pullup((u8) PORT, (u8) 4, (u8) 1);
	DIO_connect_pullup((u8) PORT, (u8) 5, (u8) 1);
	DIO_connect_pullup((u8) PORT, (u8) 6, (u8) 1);

}
u8 KEYPAD_read(void){
	u8 arr[4][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,0,12}
	};
	u8 col,row,x;
	u8 returnValue = NOTPRESSED;
	for(row = (u8) 0; row < (u8) 4; row++){
		DIO_write_bit((u8) PORT, (u8) 0, (u8) 1);
		DIO_write_bit((u8) PORT, (u8) 1, (u8) 1);
		DIO_write_bit((u8) PORT, (u8) 2, (u8) 1);
		DIO_write_bit((u8) PORT, (u8) 3, (u8) 1);
		DIO_write_bit((u8) PORT, row, (u8) 0);
		for(col = (u8) 0;col < (u8) 3;col++){
			x = DIO_read_bit((u8) PORT, col + (u8) 4);
			if(x == (u8) 0){
				returnValue=arr[row][col];
				break;
			}
		}
		if(x == (u8) 0){
			break;
		}
	}
	return returnValue;
}
