/* mbed Microcontroller Library - DigitalOut
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_DIGITALOUT_H
#define MBED_DIGITALOUT_H

#include "Base.h"
#include "LPC2300.h"

namespace mbed {

/* Class: DigitalOut
 *  A digital output, used for setting the state of a pin
 */
class DigitalOut : public Base {

public:

	/* Constructor: DigitalOut
	 *  Create a DigitalOut connected to the specified pin
	 *
	 * Variables:
	 *  pin - DigitalOut pin to connect to (5-30)
	 */
	DigitalOut(int pin);

	/* Function: write
	 *  Set the output, specified as 0 or 1 (int)
	 *
	 * Variables:
	 *  value - An integer specifying the pin output value, 
	 *      0 for logical 0 (0v) and 1 (or any other non-zero value) for logical 1 (3.3v).
	 */
    void write(int value);

	/* Function: read
	 *  Return the output setting, represented as 0 or 1 (int)
	 *
	 * Variables:
	 *  returns - An integer representing the output setting of the pin, 
	 *      0 for logical 0 (0v) and 1 for logical 1 (3.3v)
	 */
    int read();
   
	/* Function: operator=
	 *  A shorthand for <write>
	 */
	DigitalOut& operator= (int v);
	DigitalOut& operator= (DigitalOut& rhs);
	
    /* Function: operator int()
     *  A shorthand for <read>
     */
	operator int();

protected:
	
	LPC2300::GPIORF* _rf;
	unsigned int _mask;
	int _id;
				
};

}

#endif

