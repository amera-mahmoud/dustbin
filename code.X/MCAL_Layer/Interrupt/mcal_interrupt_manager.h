/* 
 * File:   mcal_interrupt_manager.h
 * Author: FiX-DEll
 *
 * Created on March 8, 2024, 11:56 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/*------------------------Include section-------------------------------*/
#include "mcal_interrupt_config.h"

/*------------------------Data Type Declaration section-----------------*/
/*------------------------Macro Declaration section---------------------*/
/*------------------------Macro Function Declaration section------------*/
/*------------------------Function Declaration section------------------*/
void TIMER1_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);



#endif	/* MCAL_INTERRUPT_MANAGER_H */

