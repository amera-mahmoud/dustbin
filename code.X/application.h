/* 
 * File:   application.h
 * Author: FiX-DEll
 *
 * Created on April 20, 2024, 1:34 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


#include "MCAL_Layer/GPIO/hal_gpio.h"
#include "MCAL_Layer/Timer/hal_Timer1.h"
#include "MCAL_Layer/CCP/hal_ccp.h"

extern timer1_config_t tmr1;
extern ccp1_config_t ccp1;
extern ccp2_config_t ccp2;
extern pin_config_t servo;
extern pin_config_t trigger;

/*Interrupt service routine function for timer 1*/
void timer1_isr(void);
/*Interrupt service routine function for ccp 1*/
void ccp1_isr(void);
/*Interrupt service routine function for ccp 2*/
void ccp2_isr(void);

/*Trigger the ultrasonice sensor*/
void sensor_trigger(pin_config_t* trigger_pin);
/*Initialize the ultrasonice sensor*/
void sensor_initialize(pin_config_t* trigger_pin, ccp_select_t ccp_select);
/*Initialize the servo motor*/
void servo_initialize(pin_config_t* servo_pin, ccp_select_t ccp_select);
/*make servo motor at 0 degree*/
void servo0(void);
/*make servo motor at 90 degree*/
void servo90(void);



#endif	/* APPLICATION_H */

