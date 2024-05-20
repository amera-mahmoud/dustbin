/* 
 * File:   mcal_internal_interrupt.h
 * Author: FiX-DEll
 *
 * Created on March 10, 2024, 9:01 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/*------------------------Include section-------------------------------*/
#include "mcal_interrupt_config.h"

/*------------------------Data Type Declaration section-----------------*/
/*------------------------Macro Declaration section---------------------*/
/*------------------------Macro Function Declaration section------------*/

#if TIMER1_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE
#define TIMER1_Interrupt_Enable()     (PIE1bits.TMR1IE = 1)
#define TIMER1_Interrupt_Disable()    (PIE1bits.TMR1IE = 0)
#define TIMER1_Interrupt_ClearFlag()  (PIR1bits.TMR1IF = 0)

#endif 

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define CCP1_Interrupt_Enable()     (PIE1bits.CCP1IE = 1)
#define CCP1_Interrupt_Disable()    (PIE1bits.CCP1IE = 0)
#define CCP1_Interrupt_ClearFlag()  (PIR1bits.CCP1IF = 0)

#endif 

#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define CCP2_Interrupt_Enable()     (PIE2bits.CCP2IE = 1)
#define CCP2_Interrupt_Disable()    (PIE2bits.CCP2IE = 0)
#define CCP2_Interrupt_ClearFlag()  (PIR2bits.CCP2IF = 0)

#endif 



/*------------------------Function Declaration section------------------*/
void all_interrupt_enable();
void all_interrupt_disable();

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

