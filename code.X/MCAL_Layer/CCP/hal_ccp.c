#include "hal_ccp.h"

void (*ccp1_InterruptHandler)(void) = NULL;

std_ReturnType ccp1_init(const ccp1_config_t* ccp1_obj)
{
    std_ReturnType ret = E_NOT_OK;
    if(NULL == ccp1_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
        CCP1_DISABLE();
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP1_Interrupt_Disable();
         all_interrupt_disable();
         CCP1_Interrupt_ClearFlag();
         ccp1_InterruptHandler = ccp1_obj->CCP1_InterruptHandler;
         CCP1_Interrupt_Enable();
         all_interrupt_enable();
#endif
       CCP1_MODE(ccp1_obj->mode);  
       if((CCPX_CAPTURE_FALLING_EDGE == ccp1_obj->mode)
               || (CCPX_CAPTURE_RISING_EDGE == ccp1_obj->mode))
       {
           TRISCbits.TRISC2 = 1;
       }
    }
    return ret;
}

void ccp1_change_mode(uint8 mode)
{
    CCP1_DISABLE();
    CCP1_MODE(mode); 
    CCP1_Interrupt_ClearFlag();
}

void ccp1_register_write(uint16 value)
{
    CCPR1 = value;
}

uint16 ccp1_register_read()
{
    uint16 value = CCPR1;
    return value;
}

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void CCP1_ISR(void)
{
    CCP1_Interrupt_ClearFlag();
    if(ccp1_InterruptHandler)
        ccp1_InterruptHandler();
}
#endif

/**************************************************************************/
void (*ccp2_InterruptHandler)(void) = NULL;

std_ReturnType ccp2_init(const ccp2_config_t* ccp2_obj)
{
    std_ReturnType ret = E_NOT_OK;
    if(NULL == ccp2_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
        CCP2_DISABLE();
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP2_Interrupt_Disable();
         all_interrupt_disable();
         CCP2_Interrupt_ClearFlag();
         ccp2_InterruptHandler = ccp2_obj->CCP2_InterruptHandler;
         CCP2_Interrupt_Enable();
         all_interrupt_enable();
#endif
       CCP2_MODE(ccp2_obj->mode);  
       if((CCPX_CAPTURE_FALLING_EDGE == ccp2_obj->mode)
               || (CCPX_CAPTURE_RISING_EDGE == ccp2_obj->mode))
       {
           TRISCbits.TRISC1 = 1;
       }
    }
    return ret;
}

void ccp2_change_mode(uint8 mode)
{
    CCP2_DISABLE();
    CCP2_MODE(mode); 
    CCP2_Interrupt_ClearFlag();
}

void ccp2_register_write(uint16 value)
{
    CCPR2 = value;
}

uint16 ccp2_register_read()
{
    uint16 value = CCPR2;
    return value;
}

#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void CCP2_ISR(void)
{
    CCP2_Interrupt_ClearFlag();
    if(ccp2_InterruptHandler)
        ccp2_InterruptHandler();
}
#endif