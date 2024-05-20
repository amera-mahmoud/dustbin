/* 
 * File:   mcal_std_types.h
 * Author: FiX-DEll
 *
 * Created on March 8, 2024, 10:45 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/************************Include Section**************************************/
#include "compiler.h"
#include "std_liberaries.h"
#include "pic16f877A.h"
#include "device_config.h"

/************************Data Type Declaration Section************************/
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;
typedef signed char    sint8;
typedef signed short   sint16;
typedef signed long    sint32;

typedef uint8 std_ReturnType;


/************************Macro Declaration Section****************************/
#define E_NOT_OK  (std_ReturnType)0X00;
#define E_OK      (std_ReturnType)0X01;

#define _XTAL_FREQ 8000000
/************************Macro Function Declaration Section*******************/
/************************Function Declaration Section*************************/

#endif	/* MCAL_STD_TYPES_H */

