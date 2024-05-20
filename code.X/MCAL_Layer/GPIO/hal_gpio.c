#include "hal_gpio.h"

/*Reference to the Data Direction Control Register*/
static volatile uint8* tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/*Reference to the Port Status Register*/
static volatile uint8* port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

#if GPIO_PIN_PORT_CONFIGURATION == GPIO_CONFIGURATION_ENABLE
std_ReturnType gpio_pin_direction_initialize(const pin_config_t* pin_config) {
    std_ReturnType ret = E_NOT_OK;
    if ((NULL == pin_config)|| (pin_config->pin > PORT_PIN_MAX_NUM-1)) 
    {
        ret = E_NOT_OK;
    } 
    else 
    {
        switch(pin_config->direction)
        {
             case GPIO_DIRECTION_OUTPUT:
                 CLEAR_BIT(*tris_registers[pin_config->port], pin_config->pin);
                 ret = E_OK;
                 break;
             case GPIO_DIRECTION_INPUT:
                 SET_BIT(*tris_registers[pin_config->port], pin_config->pin);
                 ret = E_OK;
                 break;
            default:
              ret = E_NOT_OK;  
        }
    }
    return ret;
}

std_ReturnType gpio_pin_get_direction_status(const pin_config_t* pin_config, direction_t* direction_status) 
{
    std_ReturnType ret = E_NOT_OK;
    if ((NULL == pin_config)||(NULL == direction_status) || (pin_config->pin > PORT_PIN_MAX_NUM-1)) 
    {
        ret = E_NOT_OK;
    } 
    else 
    {
        *direction_status = READ_BIT(*tris_registers[pin_config->port], pin_config->pin);
        ret = E_OK;
    }
    return ret;
}

std_ReturnType gpio_pin_write_logic(const pin_config_t* pin_config, logic_t logic) 
{
    std_ReturnType ret = E_NOT_OK;
    if ((NULL == pin_config)|| (pin_config->pin > PORT_PIN_MAX_NUM-1)) 
    {
        ret = E_NOT_OK;
    } 
    else 
    {
        switch(logic)
        {
            case GPIO_LOW:
               CLEAR_BIT(*port_registers[pin_config->port], pin_config->pin);
               ret = E_OK;
               break;
            case GPIO_HIGH:
                SET_BIT(*port_registers[pin_config->port], pin_config->pin);
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

std_ReturnType gpio_pin_read_logic(const pin_config_t* pin_config, logic_t* logic) 
{
    std_ReturnType ret = E_NOT_OK;
    if ((NULL == pin_config)|| (NULL == logic) || (pin_config->pin > PORT_PIN_MAX_NUM-1)) 
    {
        ret = E_NOT_OK;
    } 
    else 
    {
        *logic = READ_BIT(*port_registers[pin_config->port], pin_config->pin);
        ret = E_OK;
    }
    return ret;
}


std_ReturnType gpio_pin_toggle_logic(const pin_config_t* pin_config) 
{
    std_ReturnType ret = E_NOT_OK;
    if ((NULL == pin_config)|| (pin_config->pin > PORT_PIN_MAX_NUM-1)) 
    {
        ret = E_NOT_OK;
    } 
    else 
    {
        TOGGLE_BIT(*port_registers[pin_config->port],pin_config->pin);
        ret = E_OK;
    }
    return ret;
}


std_ReturnType gpio_pin_initialize(const pin_config_t* pin_config) 
{
    std_ReturnType ret = E_NOT_OK;
    if ((NULL == pin_config)|| (pin_config->pin > PORT_PIN_MAX_NUM-1)) 
    {
        ret = E_NOT_OK;
    } 
    else 
    {
        ret = gpio_pin_direction_initialize(pin_config);
        ret &= gpio_pin_write_logic(pin_config, pin_config->logic);
    }
    return ret;
}
#endif

#if GPIO_PORT_CONFIGURATION == GPIO_CONFIGURATION_ENABLE
std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8 direction)
{
    std_ReturnType ret = E_NOT_OK;
    if(port > PORT_MAX_NUM-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *tris_registers[port] = direction;
        ret = E_OK;
    }
    return ret;
}

std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8* direction_status)
{
    std_ReturnType ret = E_NOT_OK;
    if((port > PORT_MAX_NUM-1) || (NULL == direction_status))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = *tris_registers[port];
        ret = E_OK;
    }
    return ret;
}

std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic)
{
    std_ReturnType ret = E_NOT_OK;
    if(port > PORT_MAX_NUM-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
       *port_registers[port] = logic;
       ret = E_OK;
    }
    return ret;
}

std_ReturnType gpio_port_read_logic(port_index_t port, uint8* logic)
{
    std_ReturnType ret = E_NOT_OK;
    if((port > PORT_MAX_NUM-1) || (NULL == logic))
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*if(*port_registers[port] != *lat_registers[port])
           ret = E_NOT_OK;*/
       *logic = *port_registers[port];
        ret = E_OK;
    }
    return ret;
}

std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    std_ReturnType ret = E_NOT_OK;
    if(port > PORT_MAX_NUM-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //*tris_registers[port] = ~*tris_registers[port];
        //*lat_registers[port] = *lat_registers[port] ^ 0xFF;
        *port_registers[port] ^= PORT_MASK;
        ret = E_OK;
    }
    return ret;
}
#endif


