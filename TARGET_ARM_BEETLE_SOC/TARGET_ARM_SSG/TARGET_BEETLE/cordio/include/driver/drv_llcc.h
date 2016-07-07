/*************************************************************************************************/
/*!
 *  \file   drv_llcc.h
 *
 *  \brief  LLCC driver.
 *
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: LicenseRef-PBL
 *
 * This file and the related binary are licensed under the
 * Permissive Binary License, Version 1.0 (the "License");
 * you may not use these files except in compliance with the License.
 *
 * You may obtain a copy of the License here:
 * LICENSE-permissive-binary-license-1.0.txt and at
 * https://www.mbed.com/licenses/PBL-1.0
 *
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*************************************************************************************************/

#ifndef __DRV_LLCC_H
#define __DRV_LLCC_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
** INCLUDES
***************************************************************************************************/

#include "chip.h"
#include "board.h"

/***************************************************************************************************
** CONSTANTS
***************************************************************************************************/

/*--------------------------------------------------------------------------------------------------
** ENABLE/DISABLE, ON/OFF DEFINES
**
** DESCRIPTION: For clarity in enable parameters.
--------------------------------------------------------------------------------------------------*/

#ifndef DRV_ENABLE
#define DRV_ENABLE  1
#endif

#ifndef DRV_DISABLE
#define DRV_DISABLE  0
#endif

#ifndef DRV_ON
#define DRV_ON  1
#endif

#ifndef DRV_OFF
#define DRV_OFF  0
#endif

/***************************************************************************************************
** TYPES
***************************************************************************************************/

typedef void (*DRV_LLCC_WD_CALLBACK_t) (uint8_t type, uint8_t *pData, void *pContext, int32_t error);
typedef void (*DRV_LLCC_RD_CALLBACK_t) (uint8_t type, uint8_t *pData, uint8_t align, uint16_t len);
typedef void * (*DRV_LLCC_ALLOC_CALLBACK_t) (uint16_t len);

/*--------------------------------------------------------------------------------------------------
** struct drv_llcc
**
** DESCRIPTION: Access structure of driver.
--------------------------------------------------------------------------------------------------*/

struct drv_llcc {
    /*----------------------------------------------------------------------------------------------
     ** Initialize()
     **
     ** DESCRIPTION: Initialize ESS IPCC interface
     ** RETURNS:     0 or error (if not 0)
     ---------------------------------------------------------------------------------------------*/
    int32_t (*Initialize)(void);

    /*----------------------------------------------------------------------------------------------
     ** Reset()
     **
     ** DESCRIPTION: Take the ESS IPCC into or out of reset.
     ** PARAMETERS:  on  If not 0, take the ESS IPCC out of reset
     ---------------------------------------------------------------------------------------------*/
    void (*Reset)(int32_t on);

    /*----------------------------------------------------------------------------------------------
     ** SetTxHandler()
     **
     ** DESCRIPTION: Set handler for transmit events
     ** PARAMETERS:  cb       Pointer to callback; if NULL, the default handler is set
     ---------------------------------------------------------------------------------------------*/
    void (*SetTxHandler)(DRV_LLCC_WD_CALLBACK_t cb);

    /*----------------------------------------------------------------------------------------------
     ** SetRxHandler()
     **
     ** DESCRIPTION: Set handler for receive events
     ** PARAMETERS:  cb       Pointer to callback; if NULL, the default handler is set
     ---------------------------------------------------------------------------------------------*/
    void (*SetRxHandler)(DRV_LLCC_RD_CALLBACK_t cb);

     /*----------------------------------------------------------------------------------------------
     ** SetAllocHandler()
     **
     ** DESCRIPTION: Set handler for allocate requests
     ** PARAMETERS:  cb       Pointer to callback; if NULL, the default handler is set
     ---------------------------------------------------------------------------------------------*/
    void (*SetAllocHandler)(DRV_LLCC_ALLOC_CALLBACK_t cb);

    /*----------------------------------------------------------------------------------------------
     ** Write()
     **
     ** DESCRIPTION: Write to write channel
     ** PARAMETERS:  cmd      Command to send
     **              data     Pointer to buffer with data to send
     **              num      Number of bytes to write
     **              context  Context associated with this write
     ** RETURNS:     Number of bytes written or error (if less than 0)
     ---------------------------------------------------------------------------------------------*/
     int32_t (*Write)(uint32_t cmd, const uint8_t *data, uint16_t num, void *context);
};

#ifdef __cplusplus
}
#endif

#endif /* __DRV_LLCC_H */
