#include "application.h"

/*Initialize timer 1*/
timer1_config_t tmr1 = {
  .TIMER1_InterruptHandler = timer1_isr,
  .timer_mode = TMR1_TIMER_MODE,
  .initial_value = 60536,
  .prescaler_select = PRESCALER_DIV_BY_8
};

/*Initialize capture and compare module 1 at capture state*/
ccp1_config_t ccp1 = {
  .CCP1_InterruptHandler = ccp1_isr,
  .mode = CCPX_CAPTURE_RISING_EDGE  
};

/*Initialize capture and compare module 2 at compare state*/
ccp2_config_t ccp2 = {
  .CCP2_InterruptHandler = ccp2_isr,
  .mode = CCPX_COMPAER_IO_STATE  
};

/*Initialize servo motor output pin*/
pin_config_t servo = {
  .port = PORTD_INDEX, 
  .pin = PIN0,
  .direction = GPIO_DIRECTION_OUTPUT,
  .logic = GPIO_LOW  
};

/*Initialize ultrasonice sensor trigger pin*/
pin_config_t trigger = {
  .port = PORTC_INDEX,
  .pin = PIN1,
  .direction = GPIO_DIRECTION_OUTPUT,
  .logic = GPIO_LOW  
};

