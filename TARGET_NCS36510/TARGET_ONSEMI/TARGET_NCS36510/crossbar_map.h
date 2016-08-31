/**
******************************************************************************
* @file crossbar_map.h
* @brief CROSSBAR hw module register map
* @internal
* @author ON Semiconductor
* $Rev: 3318 $
* $Date: 2015-03-27 16:29:34 +0530 (Fri, 27 Mar 2015) $
******************************************************************************
* @copyright (c) 2012 ON Semiconductor. All rights reserved.
* ON Semiconductor is supplying this software for use with ON Semiconductor
* processor based microcontrollers only.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* ON SEMICONDUCTOR SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,
* INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
* @endinternal
*
* @ingroup crossbar
*
* @details
*/

#ifndef CROSSB_MAP_H_
#define CROSSB_MAP_H_

/*************************************************************************************************
*                                                                                                *
*  Header files                                                                                  *
*                                                                                                *
*************************************************************************************************/

#include "architecture.h"

/**************************************************************************************************
*                                                                                                 *
*  Type definitions                                                                               *
*                                                                                                 *
**************************************************************************************************/

/* Crossbar Control HW Structure Overlay */
typedef struct {
    __IO uint32_t DIOCTRL0; /**< Switch IO0 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL1; /**< Switch IO1 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL2; /**< Switch IO2 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL3; /**< Switch IO3 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL4; /**< Switch IO4 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL5; /**< Switch IO5 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL6; /**< Switch IO6 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL7; /**< Switch IO7 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL8; /**< Switch IO8 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL9; /**< Switch IO9 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL10; /**< Switch IO10 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL11; /**< Switch IO11 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL12; /**< Switch IO12 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL13; /**< Switch IO13 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL14; /**< Switch IO14 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL15; /**< Switch IO15 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL16; /**< Switch IO16 to GPIO(default) or peripheral device */
    __IO uint32_t DIOCTRL17; /**< Switch IO17 to GPIO(default) or peripheral device */
} CrossbReg_t, *CrossbReg_pt;

#endif /* CROSSB_MAP_H_ */
