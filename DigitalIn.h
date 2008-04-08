/* mbed Microcontroller Library - DigitalIn
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_DIGITALIN_H
#define MBED_DIGITALIN_H

#include "Base.h"
#include "LPC2300.h"

typedef void (*VoidFunctionPointer)(void);

namespace mbed {

/* Class: DigitalIn
 *  A digital input, used for reading the state of a pin
 */
 
class DigitalIn : public Base {

public:

	/* Group: Configuration Methods */
	
	/* Constructor: DigitalIn
	 *  Create a DigitalIn connected to the specified pin
	 *
	 * Variables:
	 *  pin - DigitalIn pin to connect to (5-30)
	 */
	DigitalIn(int pin);

	/* Function: rise
	 *  Attach a function to call when a rising edge occurs on the input
	 *
	 * Variables:
	 *  fptr - A pointer to a void function, or 0 to set as none
	 */
	void rise(void (*fptr)(void));

	/* Function: fall
	 *  Attach a function to call when a falling edge occurs on the input
	 *
	 * Variables:
	 *  fptr - A pointer to a void function, or 0 to set as none
	 */
	void fall(void (*fptr)(void));
		
   	/* Group: Access Methods */ 

	/* Function: read
	 *  Read the input, represented as 0 or 1 (int)
	 *
	 * Variables:
	 *  returns - An integer representing the state of the input pin, 
	 *      0 for logical 0 (0v) and 1 for logical 1 (3.3v)
	 */	
    int read();
    

	/* Group: Access Method Shorthand */

    /* Function: operator int()
     *  A shorthand for <read>
     */
	operator int();
 	
 	static void _irq(); // Called on a GPIO interrupt
 	
protected:

	LPC2300::GPIORF* _rf;
	unsigned int _mask;
	int _id;

	static VoidFunctionPointer _rising[48];
	static VoidFunctionPointer _falling[48];

};

}

#endif