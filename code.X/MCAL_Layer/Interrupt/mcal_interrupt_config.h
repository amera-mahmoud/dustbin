/* 
 * File:   mcal_interrupt_config.h
 * Author: FiX-DEll
 *
 * Created on March 8, 2024, 11:58 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/*------------------------Include section-------------------------------*/
#include "../GPIO/hal_gpio.h"
#include "mcal_interrupt_cfg.h"

/*------------------------Data Type Declaration section-----------------*/
/*------------------------Macro Declaration section---------------------*/
#define INTERRUPT_DISABLE 0X00
#define INTERRUPT_ENABLE  0X01

#define INTERRUPT_NOT_OCCUR 0x00
#define INTERRUPT_OCCUR     0X01

/*------------------------Macro Function Declaration section------------*/
#define Global_Interrupt_Enable()       (INTCONbits.GIE = 1)
#define Global_Interrupt_Disable()      (INTCONbits.GIE = 0)

#define Peripheral_Interrupt_Enable()   (INTCONbits.PEIE = 1)
#define Peripheral_Interrupt_Disable()  (INTCONbits.PEIE = 0)
/*------------------------Function Declaration section------------------*/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

