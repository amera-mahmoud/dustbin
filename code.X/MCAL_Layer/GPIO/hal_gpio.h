/* 
 * File:   hal_gpio.h
 * Author: FiX-DEll
 *
 * Created on March 8, 2024, 10:58 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/************************Include Section**************************************/
#include "../mcal_std_types.h"

/************************Data Type Declaration Section************************/
typedef struct
{
    uint8 port      :3;
    uint8 pin       :3;
    uint8 logic     :1;
    uint8 direction :1;
}pin_config_t;

typedef enum
{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH
}logic_t;

typedef enum
{
    GPIO_DIRECTION_OUTPUT,
    GPIO_DIRECTION_INPUT  
}direction_t;

/************************Macro Declaration Section****************************/
#define PIN_MASK  (uint8)0x01
#define PORT_MASK (uint8)0xFF

#define PORT_PIN_MAX_NUM 8
#define PORT_MAX_NUM     5

/************************Macro Function Declaration Section*******************/
#define SET_BIT(REG, BIT_POSN)    (REG |=  (PIN_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)  (REG &= ~(PIN_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN) (REG ^=  (PIN_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)   ((REG >> BIT_POSN) & PIN_MASK)

/************************Function Declaration Section*************************/
#if GPIO_PIN_PORT_CONFIGURATION == GPIO_CONFIGURATION_ENABLE
std_ReturnType gpio_pin_direction_initialize(const pin_config_t* pin_config);
std_ReturnType gpio_pin_get_direction_status(const pin_config_t* pin_config, direction_t* direction_status);
std_ReturnType gpio_pin_write_logic(const pin_config_t* pin_config, logic_t logic);
std_ReturnType gpio_pin_read_logic(const pin_config_t* pin_config, logic_t* logic);
std_ReturnType gpio_pin_toggle_logic(const pin_config_t* pin_config);
std_ReturnType gpio_pin_initialize(const pin_config_t* pin_config);
#endif

#if GPIO_PORT_CONFIGURATION == GPIO_CONFIGURATION_ENABLE
std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8 direction);
std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8* direction_status);
std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);
std_ReturnType gpio_port_read_logic(port_index_t port, uint8* logic);
std_ReturnType gpio_port_toggle_logic(port_index_t port);
#endif

#endif	/* HAL_GPIO_H */

