/* mbed Microcontroller Library - AnalogOut
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_ANALOGOUT_H
#define MBED_ANALOGOUT_H

#include "Base.h"

namespace mbed {

/* Class: AnalogOut
 *  An analog output, used for setting the voltage on a pin
 */
class AnalogOut : public Base {

public:

	/* Group: Configuration Methods */
	
	/* Constructor: AnalogOut
	 *  Create an AnalogOut connected to the specified pin
	 * 
	 * Variables:
	 *  pin - AnalogOut pin to connect to (18)
	 */
	AnalogOut(int pin, const char *name = NULL);
	
	/* Group: Access Methods */
		
	/* Function: write
	 *  Set the output voltage, specified as a percentage (float)
	 *
	 * Variables:
	 *  percent - A floating-point value representing the output voltage, 
	 *    specified as a percentage. The value should lie between
	 *    0.0f (representing 0v / 0%) and 1.0f (representing 3.3v / 100%).
	 *    Values outside this range will be saturated to 0.0f or 1.0f.	 
	 */
    void write(float percent);
    
	/* Function: write_v
	 *  Set the output voltage, specified in volts (float)
	 *
	 * Variables:
	 *  v - A floating-point value representing the output voltage, 
	 *    specified in volts. The value should lie between
	 *    0.0f (representing 0v / 0%) and 3.3f (representing 3.3v / 100%).
	 *    Values outside this range will be saturated to 0.0f or 3.3f.	 
	 */	
    void write_v(float v);

	/* Function: write_mv
	 *  Set the output voltage, specified in mili-volts (int)
	 *
	 * Variables:
	 *  mv - An integer value representing the output voltage, 
	 *    specified in milli-volts. The value should lie between
	 *    0 (representing 0v / 0%) and 3300 (representing 3.3v / 100%).
	 *    Values outside this range will be saturated to 0 or 3300.	 
	 */	
    void write_mv(int mv);
    
    /* Function: read
	 *  Return the current output voltage setting, measured as a percentage (float)
     *
     * Variables:
	 *  returns - A floating-point value representing the current voltage being output on the pin, 
	 *    measured as a percentage. The returned value will lie between
	 *    0.0f (representing 0v / 0%) and 1.0f (representing 3.3v / 100%).
	 *
	 * Note:
	 *  This value may not match exactly the value set by a previous <write>.
	 */	
    float read();

   	/* Group: Access Method Shorthand */ 

    /* Function: operator=
     *  A shorthand for <write>
     */
	AnalogOut& operator= (float percent);
	AnalogOut& operator= (AnalogOut& rhs);

    /* Function: operator float()
	 *  A shorthand for <read>
	 */	
	operator float();

    virtual const struct rpc_method *rpc_methods();
		
};

}

#endif

