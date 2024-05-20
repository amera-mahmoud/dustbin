#include "mcal_internal_interrupt.h"

void all_interrupt_enable()
{
    Global_Interrupt_Enable();
    Peripheral_Interrupt_Enable();
}
void all_interrupt_disable()
{
    Global_Interrupt_Disable();
    Peripheral_Interrupt_Disable();
}
