/* 
 * File:   hal_ccp.h
 * Author: FiX-DEll
 *
 * Created on April 18, 2024, 3:38 AM
 */

#ifndef HAL_CCP_H
#define	HAL_CCP_H


/*------------------------Include section-------------------------------*/
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/*------------------------Data Type Declaration section-----------------*/
typedef enum
{
    CCP1,
    CCP2
}ccp_select_t;

typedef struct
{
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*CCP1_InterruptHandler)(void);
#endif
    uint8 mode      :4;
}ccp1_config_t;

typedef struct
{
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*CCP2_InterruptHandler)(void);
#endif
    uint8 mode      :4;
}ccp2_config_t;



/*------------------------Macro Declaration section---------------------*/
#define CCPX_DISABLE              0
#define CCPX_COMPAER_IO_STATE     10
#define CCPX_CAPTURE_FALLING_EDGE 4
#define CCPX_CAPTURE_RISING_EDGE  5

/*------------------------Macro Function Declaration section------------*/
#define CCP1_DISABLE()      (CCP1CONbits.CCP1M = 0)
#define CCP1_MODE(_CONFIG)  (CCP1CONbits.CCP1M = _CONFIG)

#define CCP2_DISABLE()      (CCP2CONbits.CCP2M = 0)
#define CCP2_MODE(_CONFIG)  (CCP2CONbits.CCP2M = _CONFIG)
                                        
/*------------------------Function Declaration section------------------*/
std_ReturnType ccp1_init(const ccp1_config_t* ccp1_obj);
void ccp1_change_mode(uint8 mode);
void ccp1_register_write(uint16 value);
uint16 ccp1_register_read();

std_ReturnType ccp2_init(const ccp2_config_t* ccp2_obj);
void ccp2_change_mode(uint8 mode);
void ccp2_register_write(uint16 value);
uint16 ccp2_register_read();


#endif	/* HAL_CCP_H */

