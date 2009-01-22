/* mbed Microcontroller Library - LPC2300 MAP
 * Copyright (c) 2007-2008, sford
 *
 * This should be anything to do with the mapping of the LPC2300 on to the particular board implementation
 */

#ifndef MBED_LPC2300_MAP_H
#define MBED_LPC2300_MAP_H

//===================================================================
// Define the target board
//===================================================================

//#define TARGET_MBED64 1
#define TARGET_PHAT40 1
//#define TARGET_BREAKOUT 1

//===================================================================

#if TARGET_MBED64

enum {
	LED1 = 65,
	LED2 = 66,
	LED3 = 67,
	LED4 = 68,
	USBTX = 69,
	USBRX = 70
};

#define LED1_PORT  	(4*32 + 28)
#define LED2_PORT	(3*32 + 25)
#define LED3_PORT	(4*32 + 29)
#define LED4_PORT	(3*32 + 26)

#elif TARGET_PHAT40

enum {  
  NC = 0,   // Not Connected 
	LED1 = 32,
	LED2 = 33,
	LED3 = 34,
	LED4 = 35,
	USBTX = 36,
	USBRX = 37
};

#define LED1_PORT  	(1*32 + 18)
#define LED2_PORT	(1*32 + 20)
#define LED3_PORT	(1*32 + 21)
#define LED4_PORT	(1*32 + 23)

#else
#error "UNRECOGNISED TARGET"
#endif

namespace LPC2300 {

#define PORT(x,y)     	((x*32 + y))
#define LIST_END 		0xFF
#define NOT_AVAILABLE 	0xFF

struct PortMap {
	unsigned char port;   	// P0.0 (0) to P4.31 (159)
	unsigned char id;		// Resource ID
	unsigned char function;	// Pin function
};

/* returns NOT_AVAILABLE if no port matches the pin */
int pin_to_port(int pin);

/* returns NULL if no map matches the pin */
const PortMap* get_port_map(const PortMap* map, int pin);

extern const PortMap ADC_PORTMAP[];
extern const PortMap DAC_PORTMAP[];
extern const PortMap PWM_PORTMAP[]; 

} // namespace LPC2300

#endif

