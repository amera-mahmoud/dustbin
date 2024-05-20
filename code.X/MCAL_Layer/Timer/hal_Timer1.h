/* 
 * File:   hal_Timer1.h
 * Author: FiX-DEll
 *
 * Created on March 12, 2024, 1:50 AM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/*------------------------Include section-------------------------------*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/*------------------------Data Type Declaration section-----------------*/
typedef enum
{
    PRESCALER_DIV_BY_1,
    PRESCALER_DIV_BY_2,
    PRESCALER_DIV_BY_4,
    PRESCALER_DIV_BY_8
}prescaler_select_bits_t;

typedef struct
{
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*TIMER1_InterruptHandler)(void);
#endif
    uint16 initial_value;
    uint8 timer_mode         :2;
    uint8 timer1_oscilator   :1;
    uint8 extclk_sync        :1;
    uint8 prescaler_select   :2;
}timer1_config_t;
/*------------------------Macro Declaration section---------------------*/
#define TMR1_TIMER_MODE   0x00
#define TMR1_COUNTER_MODE 0x01


#define TMR1_OSCILATOR_DISABLE_CFG 0x00 
#define TMR1_OSCILATOR_ENABLE_CFG  0x01

#define TMR1_EXTCLK_SYNC_DISABLE  0x00
#define TMR1_EXTCLK_SYNC_ENABLE   0x01

/*------------------------Macro Function Declaration section------------*/
#define TIMER1_ENABLE()  (T1CONbits.TMR1ON = 1)
#define TIMER1_DISABLE() (T1CONbits.TMR1ON = 0)

#define TIMER1_TIMER_MODE()         (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_MODE()       (T1CONbits.TMR1CS = 1)

#define TIMER1_OSCILATOR_ENABLE()  (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSCILATOR_DISABLE() (T1CONbits.T1OSCEN = 0)

#define TIMER1_EXTCLK_SYNC_ENABLE()  (T1CONbits.T1SYNC = 0)
#define TIMER1_EXTCLK_SYNC_DISABLE() (T1CONbits.T1SYNC = 1)

#define TIMER1_PRESCALER_SELECT(_CONFIG)  (T1CONbits.T1CKPS = _CONFIG)

/*------------------------Function Declaration section------------------*/
std_ReturnType timer1_inti(timer1_config_t* tmr1_obj);
std_ReturnType timer1_deinti(timer1_config_t* tmr1_obj);
std_ReturnType timer1_register_write(timer1_config_t* tmr1_obj, uint16 value);
std_ReturnType timer1_register_read(timer1_config_t* tmr1_obj, uint16* value);



#endif	/* HAL_TIMER1_H */

