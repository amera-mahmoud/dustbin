#include "mcal_interrupt_manager.h"

void __interrupt() InterruptManager(void)
{  
#if CCP1_INTERRUPT_FEATURE_ENABLE  ==  INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_OCCUR == PIR1bits.CCP1IF))
    {
        CCP1_ISR();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if CCP2_INTERRUPT_FEATURE_ENABLE  ==  INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE2bits.CCP2IE) && (INTERRUPT_OCCUR == PIR2bits.CCP2IF))
    {
        CCP2_ISR();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if TIMER1_INTERRUPT_FEATURE_ENABLE  ==  INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_OCCUR == PIR1bits.TMR1IF))
    {
       TIMER1_ISR();
    }
    else
    {
        /*nothing*/
    }
#endif
      

    
}

