#include "hal_Timer1.h"

void (*TIMER1_InterruptHandler)(void) = NULL;
uint16 volatile preload_timer1 = 0;

std_ReturnType timer1_inti(timer1_config_t* tmr1_obj)
{
    std_ReturnType ret = E_NOT_OK;
    if(NULL == tmr1_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
        /*disable timer*/
        TIMER1_DISABLE();
        /*configure timer mode*/
        if(TMR1_TIMER_MODE == tmr1_obj->timer_mode)
            TIMER1_TIMER_MODE();
        else if(TMR1_COUNTER_MODE == tmr1_obj->timer_mode)
        {
            TIMER1_COUNTER_MODE();
            /*configure timer oscilator*/
            if (TMR1_OSCILATOR_ENABLE_CFG == tmr1_obj->timer1_oscilator)
                TIMER1_OSCILATOR_ENABLE();
            else if (TMR1_OSCILATOR_DISABLE_CFG == tmr1_obj->timer1_oscilator)
                TIMER1_OSCILATOR_DISABLE();
            else
                ret = E_NOT_OK;
            /*configure synchronization*/
            if (TMR1_EXTCLK_SYNC_ENABLE == tmr1_obj->extclk_sync)
                TIMER1_EXTCLK_SYNC_ENABLE();
            else if (TMR1_EXTCLK_SYNC_DISABLE == tmr1_obj->extclk_sync)
                TIMER1_EXTCLK_SYNC_DISABLE();
            else
                ret = E_NOT_OK;
        }
        else
            ret = E_NOT_OK;
         
        /*configure prescaler*/
        TIMER1_PRESCALER_SELECT(tmr1_obj->prescaler_select);
        /*configure initial value*/
        TMR1H = 0;
        TMR1L = 0;
        TMR1H = (uint8)((tmr1_obj->initial_value) >> 8);
        TMR1L = (uint8)(tmr1_obj->initial_value);
        preload_timer1 = tmr1_obj->initial_value;
        /*configure interrupt*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        /*diable interrupt*/
         all_interrupt_disable();
        TIMER1_Interrupt_Disable();
        /*clear flag*/
        TIMER1_Interrupt_ClearFlag();
        /*configure handler callback*/
        TIMER1_InterruptHandler = tmr1_obj->TIMER1_InterruptHandler;
        /*priority*/
        /*enable interrupt*/
        TIMER1_Interrupt_Enable();
         all_interrupt_enable();
#endif
        /*enable timer*/
        TIMER1_ENABLE();
    }
    return ret;
}

std_ReturnType timer1_deinti(timer1_config_t* tmr1_obj)
{
    std_ReturnType ret = E_NOT_OK;
    if(NULL == tmr1_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TIMER1_DISABLE();
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_Interrupt_Disable();
#endif
        ret = E_OK;
    }
    return ret;
}

std_ReturnType timer1_register_write(timer1_config_t* tmr1_obj, uint16 value)
{
    std_ReturnType ret = E_NOT_OK;
    if(NULL == tmr1_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TMR1H = 0;
        TMR1L = 0;
        TMR1H = (uint8)(value >> 8);
        TMR1L = (uint8)(value);
        ret = E_OK;
        preload_timer1 = value;
    }
    return ret;
}

std_ReturnType timer1_register_read(timer1_config_t* tmr1_obj, uint16* value)
{
    std_ReturnType ret = E_NOT_OK;
    uint8 tmr1l = 0, tmr1h;
    if((NULL == tmr1_obj)||(NULL == value))
    {
        ret = E_NOT_OK;
    }
    else
    {
        tmr1l = TMR1L;
        tmr1h = TMR1H;
        *value = (uint16)(tmr1l) + (uint16)(tmr1h << 8);
        ret = E_OK;
    }
    return ret;
}


#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void TIMER1_ISR(void)
{
    TIMER1_Interrupt_ClearFlag();
    TMR1H = (uint8)(preload_timer1 >> 8);
    TMR1L = (uint8)(preload_timer1);
    if(TIMER1_InterruptHandler)
    {
        TIMER1_InterruptHandler();
    }
}
#endif
