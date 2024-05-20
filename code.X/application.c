/* 
 * File:   application.c
 * Author: FiX-DEll
 *
 * Created on April 20, 2024, 1:34 AM
 */


#include "application.h"

uint8 counter = 9, rising_edge = 1, open_bin = 0, read_once = 1, object_exist = 0;
uint16 start = 0, end = 0, overflow = 0;
float time = 0, distance = 0, clk_time = 0.000004;

int main() {
    timer1_inti(&tmr1);
    sensor_initialize(&trigger, CCP1);
    servo_initialize(&servo, CCP2);
    /*Initial position is 0 degree so the bin is closed. */
    servo0();
    while(1)
    {
        /*condition will be true if an object is existed in front of the bin*/
        if(object_exist)
        {
            /*-read_once is a flag that guarantees entering this condition only one time
               when there is an object because it turns the bin state from open to close
               and vise versa.
              -this condition will be true if the object is existed in front of the 
               bin at distance ranges from 3 to 15 cm. */
            
            if (distance >= 3 && distance <= 15 && read_once) 
            {
                open_bin = !open_bin;
                read_once = 0;
            }
            /*this condition set read_once flag for the next read. */
            else if (distance > 15) 
            {
                read_once = 1;
            }
            object_exist = 0;
        }
       
       /*when open pin flag is 1 the bin opens so servo makes the bin cover at 
         90 degree position. */
       if(open_bin)
        {
            servo90();
        }
        /*when open pin flag is 0 the bin closes so servo makes the bin cover at 
         0 degree position. */
        else
        {
            servo0();
        }
    }

    return (EXIT_SUCCESS);
}

/* -Initialize the trigger pin that will have the trigger signal of the sensor.
   -select the capture and compare module that is used at capture mode to capture 
    the echo signal of the sensor. */
void sensor_initialize(pin_config_t* trigger_pin, ccp_select_t ccp_select)
{
    gpio_pin_initialize(trigger_pin);
    switch(ccp_select)
    {
        case CCP1:
          ccp1_init(&ccp1);
          break;
        case CCP2:
          ccp2_init(&ccp2); 
          break;
    }
}

/* -initialize the pin that is connected to the servo pin to output the suitable 
    pwm signal 
    -select the capture and compare module that is used at compare mode to work with 
     timer1 and generate pwm signal*/
void servo_initialize(pin_config_t* servo_pin, ccp_select_t ccp_select)
{
    gpio_pin_initialize(servo_pin);
    switch(ccp_select)
    {
        case CCP1:
          ccp1_init(&ccp1);
          break;
        case CCP2:
          ccp2_init(&ccp2); 
          break;
    }
}

/* this value makes the pwm duty cycle 6.76 */
void servo0(void)
{
    ccp2_register_write(60874);
}

/* this value makes the pwm duty cycle 12.08 */
void servo90(void)
{
    ccp2_register_write(61140);
}


/* - output the pwm high siganl
   - output the trigger signal for ultrasonic sensor*/
void timer1_isr(void)
{
    gpio_pin_write_logic(&servo, GPIO_HIGH);
    counter++;
    if(10 == counter)
    {
         gpio_pin_write_logic(&trigger, GPIO_HIGH);
            __delay_us(10);
         gpio_pin_write_logic(&trigger, GPIO_LOW);
         counter = 0;
    }
}


/* output the pwm low signal when the timer1 register value equals the 
   ccp2 register value */
void ccp2_isr(void)
{
    gpio_pin_write_logic(&servo, GPIO_LOW);
}


/* - first, ccp1 mode is initialized at capture rising edge. when the echo signal is 
     rising edge the function saves ccp1 register value and changes the mode to 
     capture falling edge. when the echo signal is falling edge the function 
     saves ccp1 register value and calculate the time of pulse and then calculate 
     the distance */
void ccp1_isr(void)
{
    if(1 == rising_edge)
    {
        start = CCPR1;
        ccp1_change_mode(CCPX_CAPTURE_FALLING_EDGE);
        rising_edge = 0;
    }
    else
    {
        end = CCPR1;
        ccp1_change_mode(CCPX_CAPTURE_RISING_EDGE);
        rising_edge = 1;
        object_exist = 1;
        
        if(0 == overflow)
            {
               time = (end - start) * clk_time; 
            }
        else
            {
                time = (overflow - 1) * clk_time; 
                time += (end - tmr1.initial_value) * clk_time;
                time += (65536 - start) * clk_time;
            }
            
            distance = (time * 34000) / 2; 
    }
}

