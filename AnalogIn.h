/* mbed Microcontroller Library - AnalogIn
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_ANALOGIN_H
#define MBED_ANALOGIN_H

#include "Base.h"

namespace mbed {

/* Class: AnalogIn
 *  An analog input, used for reading the voltage on a pin  
 */
class AnalogIn :  public Base {

public:

	/* Group: Configuration Methods */	
	
	/* Constructor: AnalogIn
	 *  Create an AnalogIn connected to the specified pin
	 *
	 * Variables:
	 *  pin - AnalogIn pin to connect to (15-20)
	 */
	AnalogIn(int pin);
	
	/* Group: Access Methods */
		
	/* Function: read
	 *  Read the input, measured as a percentage (float)
	 *
	 * Variables:
	 *  returns - A floating-point value representing the current input voltage, 
	 *      measured as a percentage. The returned value will lie between
	 *      0.0f (representing 0v / 0%) and 1.0f (representing 3.3v / 100%).
	 */
    float read();
    
	/* Function: read_v
	 *  Read the input, measured in volts (float)
	 * 
	 * Variables:
	 *  returns - A floating-point value representing the current input voltage, 
	 *      measured in volts. The returned value will lie between
	 *      0.0f (representing 0v / 0%) and 3.3f (representing 3.3v / 100%).
	 */
    float read_v();
    
    /* Function: read_mv
     *  Read the input, measured in milli-volts (int)
	 *
	 * Variables:
	 *  returns - An integer value representing the current input voltage, 
	 *      measured in milli-volts. The returned value will lie between
	 *      0 (representing 0v / 0%) and 3300 (representing 3.3v / 100%).
	 */
    int read_mv();
    
	/* Group: Access Methods Shorthand */
	
    /* Function: operator float
     *  A shorthand for <read>
     */
	operator float();
	
protected:
	
	int _id;
	
};

}

#endif