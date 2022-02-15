/*
 * final.c
 *
 * Created: 6/6/2021 11:02:19 PM
 * Author : ELnoby,Galal,Nancy,Moatasem,Zahran, Remon
 */

#define F_CPU 1000000UL
#include "display_manager.h"
#include "TC72.h"
#include "KEYPAD.h"
#include "heater_control.h"
#include "TIMER.h"

#include "Regesters.h"
#include "Basic_Types.h"



/*
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
*/

#define ERROR_STATE         ((u8) 4)
#define NORMAL_STATE        ((u8) 3)
#define OPERATIONAL_STATE   ((u8) 2)
#define STANDBY_STATE       ((u8) 1)



volatile u8 IsrTimerFlag = 0;
volatile float32_t Vr = 2.5;
volatile u8 Three_min_flag = 0;
u8 CurrentTemp = 25;
u8 SetTemp = 25;
volatile u8  read_res_counter=0;
volatile u8  read_temp_counter=0;
volatile u16 three_min_error_counter=0;
volatile u8 ErrorFlag=0;

u16 main(void);

u16 main(void)
{
    u8 CurrentState = STANDBY_STATE;
    u8 KeyPadVal = 0xff;
    /*inits -------------------------*/
    KEYPAD_init();
    TC72_init_continuos();
    heaterOn();
    /*-----------------------------*/
    display_welcome();
    while (ErrorFlag==(u8)0)
    {
        switch(CurrentState)
        {
            case STANDBY_STATE:
                heaterOff();
                TimerOff();
                display_state(SetTemp, CurrentTemp, STANDBY_STATE);
                //_delay_ms(500);
                update_state((u8)5);

                do
                {
                    KeyPadVal = KEYPAD_read(); /*get tens value*/
                    if (KeyPadVal == (u8) 12)
                    {
                        CurrentState = OPERATIONAL_STATE;
                        break;
                    }

                } while ((KeyPadVal == (u8) 0xff) || (KeyPadVal == (u8) 10));
                _delay_ms(300);

                if(KeyPadVal == (u8) 12){
                    break;
                }

                SetTemp = KeyPadVal;
                KeyPadVal = (u8) 0xff;

                do
                {
                    KeyPadVal = KEYPAD_read(); /*get tens value*/
                    if (KeyPadVal == (u8) 12)
                    {
                        CurrentState = OPERATIONAL_STATE;
                        break;
                    }
                } while ((KeyPadVal ==(u8) 0xff) || (KeyPadVal == (u8)10));

                if(KeyPadVal != (u8) 12)
                {
                    SetTemp *= (u8)10;
                    SetTemp += KeyPadVal;
                    KeyPadVal = (u8)0xff;
                }

                while(KEYPAD_read() != (u8) 12)
                {
                    CurrentState = OPERATIONAL_STATE;
                }
                _delay_ms(500);
                break;

            case NORMAL_STATE:
                TIMER_init0_CTC_interrupt((u8) 0x62);
                update_state(CurrentState);
                update_set(SetTemp);
                update_current(CurrentTemp);
                duty_cycle_control(SetTemp,CurrentTemp,(float32_t) 0);
                if(KEYPAD_read() == (u8) 12)
                {
                    CurrentState = STANDBY_STATE;
                }

                if((((CurrentTemp >= SetTemp) && ((CurrentTemp - SetTemp) <= (u8) 5))==0 )&& (((CurrentTemp <= SetTemp) && ((SetTemp - CurrentTemp) <= (u8) 5))==0))
                {
                    CurrentState = OPERATIONAL_STATE;
                }

                break;

            case OPERATIONAL_STATE:
                TIMER_init0_CTC_interrupt((u8) 0x62);
                update_state(CurrentState);
                update_set(SetTemp);
                update_current(CurrentTemp);
                duty_cycle_control(SetTemp,CurrentTemp,Vr);
                if(KEYPAD_read() == (u8) 12)
                {
                    CurrentState = STANDBY_STATE;
                }
                if((CurrentTemp >= SetTemp) && ((CurrentTemp - SetTemp) <= (u8) 5))
                {
                    CurrentState = NORMAL_STATE;
                }
                if((CurrentTemp <= SetTemp) && ((SetTemp - CurrentTemp) <= (u8) 5))
                {
                    CurrentState = NORMAL_STATE;
                }
                if((CurrentTemp > SetTemp) && ((CurrentTemp - SetTemp) > (u8) 10))
                {
                    CurrentState = ERROR_STATE;
                }
                if((SetTemp > CurrentTemp) && ((SetTemp - CurrentTemp) > (u8) 5) && Three_min_flag)
                {
                    CurrentState = ERROR_STATE;
                }

                break;

            case ERROR_STATE:
                update_state(CurrentState);
                update_set(SetTemp);
                update_current(CurrentTemp);
                //_delay_ms(1000);
                heaterOff();
                TimerOff();
                TC72_off_continuos();
                duty_cycle_control((u8)SetTemp,(u8)CurrentTemp,(float32_t)0);
                ErrorFlag= (u8) 1;
                break;
            default:
                CurrentState = ERROR_STATE;
                break;
        }
    }
    while(1){};
}



ISR(TIMER0_COMP_vect){
    read_res_counter++;
    read_temp_counter++;

    if (read_temp_counter == (u8) 2)
    {
        read_temp_counter=(u8)0;
        CurrentTemp= TC72_get_temp();
    }

    if (read_res_counter == (u8) 5)
    {
        read_res_counter= (u8) 0;
        Vr= ADC_read();
    }

    if((CurrentTemp < SetTemp) && ((SetTemp-CurrentTemp) >  (u8) 5))
    {
        three_min_error_counter++;
    }

    if (three_min_error_counter >= (u16) 1800)
    {
        Three_min_flag=(u8)1;
    }

    if ((three_min_error_counter <=  (u16) 1800 )&& (((CurrentTemp < SetTemp) && ((SetTemp-CurrentTemp) >  (u8) 5)) ==0))
    {
        three_min_error_counter= (u16) 0;
    }

}
