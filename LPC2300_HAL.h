/* mbed Microcontroller Library - LPC2300 HAL
 * Copyright (c) 2007-2008, sford
 *
 * This should be anything specific to abstraction the LPC2300
 *
 * The HAL has no state associated with it. It is just a nice way to poke registers	
 * It is still specific to the chip, but a neat interface and a bit more general
 * it is subject ot change and not exposed to the general user
 */
 
#ifndef MBED_LPC2300_HAL_H
#define MBED_LPC2300_HAL_H

#include "LPC23xx.h"

namespace LPC2300 {

/* Section: LPC2300 */

//===================================================================
// General
//===================================================================

typedef volatile unsigned int reg32;

#define NOT_CONNECTED (-1)

//===================================================================
// Pin Connect Block
//===================================================================

/* Function: pin_function
 *  Set the port function (0-3)
 */
void pin_function(int port, int function);

/* Function: pin_pullup
 *  Set the port resistor to pullup
 */
void pin_pullup(int port);

/* Function: pin_pulldown
 *  Set the port resistor to pulldown
 */
void pin_pulldown(int port);

/* Function: pin_pullnone
 *  Set the port resistor to none
 */
void pin_pullnone(int port);

//===================================================================
// GPIO
//===================================================================

struct GPIORF {
	volatile unsigned int dir; 	// 0x00
	volatile unsigned int _nc;	// 0x04
	volatile unsigned int _nc2;	// 0x08
	volatile unsigned int _nc3;	// 0x0C
	volatile unsigned int mask;	// 0x10
	volatile unsigned int pin;	// 0x14
	volatile unsigned int set;	// 0x18
	volatile unsigned int clr;	// 0x1C
};	

/* Function: gpio_input
 *  Set the port GPIO as an input
 */
void gpio_input(int port);

/* Function: gpio_output
 *  Set the port GPIO as an output
 */
void gpio_output(int port);

/* Function: gpio_write
 *  Write a value to the GPIO port (v & 1)
 */
void gpio_write(int port, int v);

/* Function: gpio_read
 *  Read a value from the GPIO port (0 or 1)
 */
int gpio_read(int port);

//===================================================================
// GPIO IRQs
//===================================================================

struct GPIOInterruptsRF {
	reg32 StatR;	// 0x00
	reg32 StatF;	// 0x04
	reg32 Clr;		// 0x08
	reg32 EnR;		// 0x0C
	reg32 EnF;		// 0x10
};	

/* Function: gpio_irq_enable_rising
 *  Enable the rising edge interrupt
 */
void gpio_irq_enable_rising(int port);		

/* Function: gpio_irq_enable_falling
 *  Enable the falling edge interrupt
 */
void gpio_irq_enable_falling(int port);

/* Function: gpio_irq_disable_rising
 *  Disable the rising edge interrupt
 */
void gpio_irq_disable_rising(int port);

/* Function: gpio_irq_disable_falling
 *  Disable the falling edge interrupt
 */
void gpio_irq_disable_falling(int port);

/* Function: gpio_irq_clear
 *  Clear rising and falling interrupt for the port
 */
void gpio_irq_clear(int port);

int gpio_irq_pending();
int gpio_irq_pending_rising(int port);
int gpio_irq_pending_falling(int port);

//===================================================================
// Analog-to-Digital Converter
//===================================================================

/* Function: adc_poweron
 *  Turn on the ADC
 */
void adc_poweron();

/* Function: adc_poweroff
 *  Turn off the ADC
 */
void adc_poweroff();

/* Function: adc_init
 *  Setup the ADC ready for reading
 */
void adc_init();

/* Function: adc_read
 *  Read the value of the ADC (10-bit, id 0-5)
 */
int adc_read(int id);

//===================================================================
// Digital-to-Analog Converter
//===================================================================

/* Function: dac_poweron
 *  Turn on the DAC
 */
void dac_poweron();

/* Function: dac_poweroff
 *  Turn off the DAC
 */
void dac_poweroff();

/* Function: dac_init
 *  Setup the DAC ready for writinbg
 */
void dac_init();

/* Function: dac_write
 *  Write a value to the DAC (10-bit)
 */
void dac_write(int value);

/* Function: dac_read
 *  Read the value currently set as the DAC output (10-bit)
 */
int dac_read();

//===================================================================
// PWM
//===================================================================

struct LPC2368_PWM_RF {
	reg32 IR;  // 0x00 - Interrupt Register
	reg32 TCR; // 0x04 - Timer Control Register
	reg32 TC;  // 0x08 - Timer Counter
	reg32 PR;  // 0x0C - Prescale Register
	reg32 PC;  // 0x10 - Prescale Counter
	reg32 MCR; // 0x14 - Match Control Register
	reg32 MR0; // 0x18 - Match Register 0
	reg32 MR1; // 0x1C - Match Register 1
	reg32 MR2; // 0x20 - Match Register 2
	reg32 MR3; // 0x24 - Match Register 3
	reg32 CCR; // 0x28 - Capture Control Register
	reg32 CR0; // 0x2C - Capture Register 1
	reg32 CR1; // 0x30 - Capture Register 2
	reg32 CR2; // 0x34 - Capture Register 3
	reg32 CR3; // 0x38 - Capture Register 4
	reg32 EMR; // 0x3C - External Match Register
	reg32 MR4; // 0x40 - Match Register 4
	reg32 MR5; // 0x44 - Match Register 5
	reg32 MR6; // 0x48 - Match Register 6
	reg32 PCR; // 0x4C - PWM Control Register
	reg32 LER; // 0x50 - Load Enable Register
	reg32 _nc[7]; // 0x54-0x6C
	reg32 CTCR; // 0x70 - Count Control Register
};

#define LPC2368_PWM  ((LPC2368_PWM_RF*)0xE0018000)

#define TCR_CNT_EN	(1 << 0)
#define TCR_RESET	(1 << 1)
#define TCR_PWM_EN	(1 << 3)

//===================================================================
// SPI Master (SSP)
//===================================================================

struct SPIRF {
	reg32 CR0; 		// 0x00
	reg32 CR1;		// 0x04
	reg32 DR;		// 0x08
	reg32 SR;		// 0x0C
	reg32 CPSR;		// 0x10
	reg32 IMSC;		// 0x14
	reg32 RIS;		// 0x18
	reg32 MIS;		// 0x1C
	reg32 ICR;		// 0x20
	reg32 DMACR;	// 0x24
};	

void ssp_format(int id, int bits, int phase, int polarity);
void ssp_frequency(int id, int hz);
void ssp_enable(int id);
void ssp_disable(int id);


int  ssp_read(int id);
void ssp_write(int id, int value);
int  ssp_readable(int id);
int  ssp_writeable(int id);

void ssp_poweron(int id);
void ssp_poweroff(int id);

/*
int  ssp_busy(int id);
void ssp_clear(int id);
*/


//===================================================================
// Uart
//===================================================================

struct UartRF {
	union {
		reg32 RBR; // 0x00 - Receive Buffer Register [DLAB=0]
		reg32 THR; // 0x00 - Transmit Holding Register [DLAB=0]
		reg32 DLL; // 0x00 - Divisor Latch (LSB) [DLAB=1]
	};
	union {
		reg32 DLM; // 0x04 - Divisor Latch (MSB) [DLAB=1]
		reg32 IER; // 0x04 - Interrupt Enable Register [DLAB=0]
	};
	union { 
		reg32 IIR; // 0x08 - Interrupt ID Register
		reg32 FCR; // 0x08 - Fifo Control Register
	};
	reg32 LCR; // 0x0C - Line Control Register
	reg32 MCR; // 0x10 - Modem Control Register (UART1 only)
	reg32 LSR; // 0x14 - Line Status Register
	reg32 MSR; // 0x18 - Modem Status Register (UART1 only)
	reg32 SCR; // 0x1C - Scratch Pad Register
	reg32 ACR; // 0x20 - Auto-baud Control Register
	reg32 ICR; // 0x24 - IrDA Control Register (UART3 only)
	reg32 FDR; // 0x28 - Fractional Divider Register
	reg32 _nc; // 0x2C - unused
	reg32 TER; // 0x30 - Transmit Enable Register
};	

enum Parity {
	None = 0,
	Odd,
	Even,
	Forced1,
	Forced0
};
	
/* Function: uart_poweron
 *  Turn on the Uart power
 */	
void uart_poweron(int id);

/* Function: uart_poweroff
 *  Turn off the Uart power
 */	
void uart_poweroff(int id);

void uart_baud(int id, int baudrate);
void uart_format(int id, int data_bits, Parity parity, int stop_bits);
void uart_enable(int id);
void uart_disable(int id);

int uart_getc(int id);
void uart_putc(int id, int c);
int uart_readable(int id);
int uart_writable(int id);

// I2C

struct I2CRF {
	reg32 I2CONSET; // 0x00 - I2C Control Set Register
	reg32 I2STAT;  	// 0x04 - I2C Status Register
	reg32 I2DAT; 	// 0x08 - I2C Data Register
	reg32 I2ADR; 	// 0x0C - I2C Slave Address Register
	reg32 I2SCLH; 	// 0x10 - SCH Duty Cycle Register High
	reg32 I2SCLL; 	// 0x14 - SCL Duty Cycle Register Low
	reg32 I2CONCLR; // 0x18 - I2C Control Clear Register
};	


void i2c_poweron(int id);
void i2c_poweroff(int id);
void i2c_frequency(int id, int hz);
void i2c_enable(int id);
void i2c_conset(int id, int start, int stop, int interrupt, int acknowledge);
void i2c_conclr(int id, int start, int stop, int interrupt, int acknowledge);
void i2c_wait_SI(int id);
void i2c_clear_SI(int id);
int i2c_status(int id);
int i2c_start(int id, int address);
int i2c_write(int id, int value);
void i2c_stop(int id);
int i2c_read(int id, int last);
int i2c_read(int id);
int i2c_readlast(int id);

// Timer


struct TimerRF {
	reg32 ir;	// 0x00
	reg32 tcr;	// 0x04
	reg32 tc;	// 0x08
	reg32 pr;	// 0x0C
	reg32 pc;	// 0x10
	reg32 mcr;	// 0x14
	reg32 mr0;	// 0x18
	reg32 mr1;	// 0x1C
	reg32 mr2;	// 0x20
	reg32 mr3;	// 0x24
	reg32 ccr;	// 0x28
	reg32 cr0;	// 0x2C
	reg32 cr1;	// 0x30
	reg32 cr2;	// 0x34
	reg32 cr3;	// 0x38
	reg32 emr;	// 0x3C
	reg32 _nc[12];	// 0x40-0x6C
	reg32 ctcr;	// 0x70
};	

/* Function: timer_poweron
 *  Turn on the Timer power
 */	
void timer_poweron(int id);

/* Function: timer_poweroff
 *  Turn off the Timer power
 */	
void timer_poweroff(int id);

void timer_start(int id, int hz);
int timer_read(int id);

//===================================================================
// VIC
//===================================================================

struct VicRF {
	reg32 IRQStatus;	// 0x000
	reg32 FIQStatus;	// 0x004
	reg32 RawIntr;		// 0x008
	reg32 IntSelect;	// 0x00C
	reg32 IntEnable;	// 0x010
	reg32 IntEnClr;		// 0x014
	reg32 SoftInt;		// 0x018
	reg32 SoftIntClear;	// 0x01C
	reg32 Protection;	// 0x020
	reg32 SWPriorityMask;	// 0x024
	reg32 _nc[54];		// 0x028-0x0FC
	reg32 VectAddr[32];	// 0x100-0x17C	
	reg32 _nc2[32];		// 0x180-0x1FC
	reg32 VectPriority[32];	// 0x200-0x27C
	reg32 _nc3[800];		// 0x280-0xEFC
	reg32 Address;		// 0xF00
};

void vic_init();
void vic_vector(int id, void (*fptr)(void) /*__irq*/ , int priority);
void vic_enable(int id);
void vic_disable(int id);
void vic_priority(int id, int priority);
void vic_acknowledge();



} // namespace LPC2300

#endif