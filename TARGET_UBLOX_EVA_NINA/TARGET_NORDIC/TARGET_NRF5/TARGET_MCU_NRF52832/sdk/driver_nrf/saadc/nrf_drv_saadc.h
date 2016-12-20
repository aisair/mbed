/* 
 * Copyright (c) 2015 Nordic Semiconductor ASA
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   1. Redistributions of source code must retain the above copyright notice, this list 
 *      of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form, except as embedded into a Nordic Semiconductor ASA 
 *      integrated circuit in a product or a software update for such product, must reproduce 
 *      the above copyright notice, this list of conditions and the following disclaimer in 
 *      the documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Nordic Semiconductor ASA nor the names of its contributors may be 
 *      used to endorse or promote products derived from this software without specific prior 
 *      written permission.
 *
 *   4. This software, with or without modification, must only be used with a 
 *      Nordic Semiconductor ASA integrated circuit.
 *
 *   5. Any software provided in binary or object form under this license must not be reverse 
 *      engineered, decompiled, modified and/or disassembled. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */


/**
 * @addtogroup nrf_saadc SAADC HAL and driver
 * @ingroup    nrf_drivers
 * @brief      @tagAPI52 Successive Approximation Analog-to-Digital Converter (SAADC) APIs.
 * @details The SAADC HAL provides basic APIs for accessing the registers of the SAADC peripheral. 
 * The SAADC driver provides APIs on a higher level.
 *
 * @defgroup nrf_drv_saadc SAADC driver
 * @{
 * @ingroup  nrf_saadc
 *
 * @brief    @tagAPI52 Successive Approximation Analog-to-Digital Converter (SAADC) driver.
 */

#ifndef NRF_DRV_SAADC_H__
#define NRF_DRV_SAADC_H__

#include "nrf_drv_config.h"
#include "nrf_saadc.h"
#include "sdk_errors.h"

/**
 * @brief Value that should be set as high limit to disable limit detection.
 */
#define NRF_DRV_SAADC_LIMITH_DISABLED (2047)
/**
 * @brief Value that should be set as low limit to disable limit detection.
 */
#define NRF_DRV_SAADC_LIMITL_DISABLED (-2048)

/**
 * @brief Macro for setting @ref nrf_drv_saadc_config_t to default settings.
 */
#define NRF_DRV_SAADC_DEFAULT_CONFIG                \
{                                                   \
    .resolution         = SAADC_CONFIG_RESOLUTION,  \
    .oversample         = SAADC_CONFIG_OVERSAMPLE,  \
    .interrupt_priority = SAADC_CONFIG_IRQ_PRIORITY \
}

/**
 * @brief Macro for setting @ref nrf_saadc_channel_config_t to default settings
 *        in single ended mode.
 *
 * @param PIN_P Analog input.
 */
#define NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(PIN_P) \
{                                                      \
    .resistor_p = NRF_SAADC_RESISTOR_DISABLED,         \
    .resistor_n = NRF_SAADC_RESISTOR_DISABLED,         \
    .gain       = NRF_SAADC_GAIN1_6,                   \
    .reference  = NRF_SAADC_REFERENCE_INTERNAL,        \
    .acq_time   = NRF_SAADC_ACQTIME_10US,              \
    .mode       = NRF_SAADC_MODE_SINGLE_ENDED,         \
    .pin_p      = (nrf_saadc_input_t)(PIN_P),          \
    .pin_n      = NRF_SAADC_INPUT_DISABLED             \
}

/**
 * @brief Macro for setting @ref nrf_saadc_channel_config_t to default settings
 *        in differential mode.
 *
 * @param PIN_P Positive analog input.
 * @param PIN_N Negative analog input.
 */
#define NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_DIFFERENTIAL(PIN_P, PIN_N) \
{                                                                       \
    .resistor_p = NRF_SAADC_RESISTOR_DISABLED,                          \
    .resistor_n = NRF_SAADC_RESISTOR_DISABLED,                          \
    .gain       = NRF_SAADC_GAIN1_6,                                    \
    .reference  = NRF_SAADC_REFERENCE_INTERNAL,                         \
    .acq_time   = NRF_SAADC_ACQTIME_10US,                               \
    .mode       = NRF_SAADC_MODE_DIFFERENTIAL,                          \
    .pin_p      = (nrf_saadc_input_t)(PIN_P),                           \
    .pin_n      = (nrf_saadc_input_t)(PIN_N)                            \
}

/**
 * @brief Analog-to-digital converter driver configuration structure.
 */
typedef struct
{
    nrf_saadc_resolution_t resolution;         ///< Resolution configuration.
    nrf_saadc_oversample_t oversample;         ///< Oversampling configuration.
    uint8_t                interrupt_priority; ///< Interrupt priority.
} nrf_drv_saadc_config_t;

/**
 * @brief Driver event types.
 */
typedef enum
{
    NRF_DRV_SAADC_EVT_DONE,    ///< Event generated when the buffer is filled with samples.
    NRF_DRV_SAADC_EVT_LIMIT,   ///< Event generated after one of the limits is reached.
} nrf_drv_saadc_evt_type_t;

/**
 * @brief Analog-to-digital converter driver done event data.
 */
typedef struct
{
    nrf_saadc_value_t *      p_buffer; ///< Pointer to buffer with converted samples.
    uint16_t                 size;     ///< Number of samples in the buffer.
} nrf_drv_saadc_done_evt_t;

/**
 * @brief Analog-to-digital converter driver limit event data.
 */
typedef struct
{
    uint8_t                  channel;    ///< Channel on which the limit was detected.
    nrf_saadc_limit_t        limit_type; ///< Type of limit detected.
} nrf_drv_saadc_limit_evt_t;

/**
 * @brief Analog-to-digital converter driver event structure.
 */
typedef struct
{
    nrf_drv_saadc_evt_type_t type;      ///< Event type.
    union
    {
        nrf_drv_saadc_done_evt_t  done; ///< Data for @ref NRF_DRV_SAADC_EVT_DONE event.
        nrf_drv_saadc_limit_evt_t limit;///< Data for @ref NRF_DRV_SAADC_EVT_LIMIT event.
    } data;
} nrf_drv_saadc_evt_t;

/**
 * @brief ADC event handler.
 *
 * @param[in] p_event     Pointer to an ADC event. The event structure is allocated on
 *                        the stack, so it is valid only within the context of
 *                        the event handler.
 */
typedef void (*nrf_drv_saadc_event_handler_t)(nrf_drv_saadc_evt_t const * p_event);

/**
 * @brief Function for initializing the SAADC.
 *
 * @param[in] p_config      Pointer to a configuration structure. If NULL, the default one is used.
 * @param[in] event_handler Event handler provided by the user.
 *
 * @retval    NRF_SUCCESS If initialization was successful.
 * @retval    NRF_ERROR_INVALID_STATE If the driver is already initialized.
 * @retval    NRF_ERROR_INVALID_PARAM If event_handler is NULL.
 */
ret_code_t nrf_drv_saadc_init(nrf_drv_saadc_config_t const * p_config,
                              nrf_drv_saadc_event_handler_t event_handler);

/**
 * @brief Function for uninitializing the SAADC.
 *
 * This function stops all ongoing conversions and disables all channels.
 */
void nrf_drv_saadc_uninit(void);

/**
 * @brief Function for getting the address of a SAMPLE SAADC task.
 *
 * @return     Task address.
 */
__STATIC_INLINE uint32_t nrf_drv_saadc_sample_task_get(void)
{
    return nrf_saadc_task_address_get(NRF_SAADC_TASK_SAMPLE);
}


/**
 * @brief Function for initializing an SAADC channel.
 *
 * This function configures and enables the channel.
 *
 * @retval NRF_SUCCESS             If initialization was successful.
 * @retval NRF_ERROR_INVALID_STATE If the ADC was not initialized.
 * @retval NRF_ERROR_NO_MEM        If the specified channel was already allocated.
 */
ret_code_t nrf_drv_saadc_channel_init(uint8_t channel, 
                                      nrf_saadc_channel_config_t const * const p_config);


/**
 * @brief Function for uninitializing an SAADC channel.
 *
 * @retval NRF_SUCCESS    If uninitialization was successful.
 * @retval NRF_ERROR_BUSY If the ADC is busy.
 */
ret_code_t nrf_drv_saadc_channel_uninit(uint8_t channel);

/**
 * @brief Function for starting SAADC sampling.
 *
 * @retval NRF_SUCCESS    If ADC sampling was triggered.
 * @retval NRF_ERROR_BUSY If ADC is in idle state.
 */
ret_code_t nrf_drv_saadc_sample(void);

/**
 * @brief Blocking function for executing a single ADC conversion.
 *
 * This function selects the desired input, starts a single conversion,
 * waits for it to finish, and returns the result.
 *
 * The function will fail if ADC is busy.
 *
 * @param[in]  channel Channel.
 * @param[out] p_value Pointer to the location where the result should be placed.
 *
 * @retval NRF_SUCCESS    If conversion was successful.
 * @retval NRF_ERROR_BUSY If the ADC driver is busy.
 */
ret_code_t nrf_drv_saadc_sample_convert(uint8_t channel, nrf_saadc_value_t * p_value);

/**
 * @brief Function for issuing conversion of data to the buffer.
 *
 * This function is non-blocking. The application is notified about filling the buffer by the event handler.
 * Conversion will be done on all enabled channels. If the ADC is in idle state, the function will set up Easy
 * DMA for the conversion. The ADC will be ready for sampling and wait for the SAMPLE task. It can be
 * triggered manually by the @ref nrf_drv_saadc_sample function or by PPI using the @ref NRF_SAADC_TASK_SAMPLE
 * task. If one buffer is already set and the conversion is ongoing, calling this function will
 * result in queuing the given buffer. The driver will start filling the issued buffer when the first one is
 * completed. If the function is called again before the first buffer is filled, it will return with error.
 *
 * @param[in] buffer Result buffer.
 * @param[in] size   Buffer size in words.
 *
 * @retval NRF_SUCCESS    If conversion was successful.
 * @retval NRF_ERROR_BUSY If the driver already has two buffers set.
 */
ret_code_t nrf_drv_saadc_buffer_convert(nrf_saadc_value_t * buffer, uint16_t size);

/**
 * @brief Function for retrieving the SAADC state.
 *
 * @retval true  If the ADC is busy.
 * @retval false If the ADC is ready.
 */
bool nrf_drv_saadc_is_busy(void);

/**
 * @brief Function for aborting ongoing and buffered conversions.
 * @note @ref NRF_DRV_SAADC_EVT_DONE event will be generated if there is a conversion in progress.
 *       Event will contain number of words in the sample buffer.
 */
void nrf_drv_saadc_abort(void);

/**
 * @brief Function for setting the SAADC channel limits.
 *        When limits are enabled and the result exceeds the defined bounds, the limit handler function is called.
 *
 * @param[in] channel SAADC channel number.
 * @param[in] limit_low Lower limit (valid values from @ref NRF_DRV_SAADC_LIMITL_DISABLED to
 *            @ref NRF_DRV_SAADC_LIMITH_DISABLED). Conversion results below this value will trigger
 *            the handler function. Set to @ref NRF_DRV_SAADC_LIMITL_DISABLED to disable this limit.
 * @param[in] limit_high Upper limit (valid values from @ref NRF_DRV_SAADC_LIMITL_DISABLED to
 *            @ref NRF_DRV_SAADC_LIMITH_DISABLED). Conversion results above this value will trigger
 *            the handler function. Set to @ref NRF_DRV_SAADC_LIMITH_DISABLED to disable this limit.
 */
void nrf_drv_saadc_limits_set(uint8_t channel, int16_t limit_low, int16_t limit_high);

/**
 * @brief Function for converting a GPIO pin number to an analog input pin number used in the channel
 *        configuration.
 *
 * @param[in]  pin GPIO pin.
 *
 * @return     Value representing an analog input pin. The function returns @ref NRF_SAADC_INPUT_DISABLED
 *             if the specified pin is not an analog input.
 */
__STATIC_INLINE nrf_saadc_input_t nrf_drv_saadc_gpio_to_ain(uint32_t pin)
{
    // AIN0 - AIN3
    if (pin >= 2 && pin <= 5)
    {
        //0 means "not connected", hence this "+ 1"
        return (nrf_saadc_input_t)(pin - 2 + 1);
    }
    // AIN4 - AIN7
    else if (pin >= 28 && pin <= 31)
    {
        return (nrf_saadc_input_t)(pin - 24 + 1);
    }
    else
    {
        return NRF_SAADC_INPUT_DISABLED;
    }
}

#endif // NRF_DRV_SAADC_H__

/** @} */
