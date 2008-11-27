/* mbed Microcontroller Library - PwmOut
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_PWMOUT_H
#define MBED_PWMOUT_H

#include "Base.h"

namespace mbed {

/* Class: PwmOut
 *  A pulse-width modulation digital output
 */
class PwmOut : public Base {

public:

	/* Group: Configuration Methods */
	
	/* Constructor: PwmOut
	 *  Create a PwmOut connected to the specified pin
	 *
	 * Variables:
	 *  pin - PwmOut pin to connect to (21-26)
	 */	
	PwmOut(int pin, const char *name = NULL);

	/* Group: Access Methods (Analog-like) */
		
	/* Function: write
	 *  Set the ouput duty-cycle, specified as a percentage (float)
	 *
	 * Variables:
	 *  percent - A floating-point value representing the output duty-cycle, 
	 *    specified as a percentage. The value should lie between
	 *    0.0f (representing 0v / on 0%) and 1.0f (representing 3.3v / on 100%).
	 *    Values outside this range will be saturated to 0.0f or 1.0f.	 
	 */
    void write(float percent);

	/* Function: write_v
	 *  Set the output duty-cycle, specified in volts (float)
	 *
	 * Variables:
	 *  v - A floating-point value representing the output duty-cycle, 
	 *    specified in volts. The value should lie between
	 *    0.0f (representing 0v / 0% on) and 3.3f (representing 3.3v / 100% on).
	 *    Values outside this range will be saturated to 0.0f or 3.3f.	 
	 */	
	void write_v(float v);

	/* Function: write_mv
	 *  Set the output duty-cycle, specified in mili-volts (int)
	 *
	 * Variables:
	 *  mv - An integer value representing the output duty-cycle, 
	 *    specified in milli-volts. The value should lie between
	 *    0 (representing 0v / 0% on) and 3300 (representing 3.3v / 100% on).
	 *    Values outside this range will be saturated to 0 or 3300.	 
	 */	
	void write_mv(int mv);

	/* Function: read
	 *  Return the current output duty-cycle setting, measured as a percentage (float)
     *
     * Variables:
	 *  returns - A floating-point value representing the current duty-cycle being output on the pin, 
	 *    measured as a percentage. The returned value will lie between
	 *    0.0f (representing 0v / 0% on) and 1.0f (representing 3.3v / 100% on).
	 *
	 * Note:
	 *  This value may not match exactly the value set by a previous <write>.
	 */	
    float read();

	/* Group: Access Methods (Pulse-width) */
	
	/* Function: period
	 *  Set the PWM period, specified in seconds (float)
	 *
	 * Note:
	 *  This is common to all PwmOut's, so changing it on one will change them all
	 */
	void period(float seconds);

	/* Function: pulsewidth
	 *  Set the PWM pulsewidth, specified in seconds (float)
	 */	
	void pulsewidth(float seconds);
		
	/* Function: period_ms
	 *  Set the PWM period, specified in milli-seconds (int)
	 *
	 * Note:
	 *  This is common to all PwmOut's, so changing it on one will change them all
	 */
	void period_ms(int ms);

	/* Function: pulsewidth_ms
	 *  Set the PWM pulsewidth, specified in milli-seconds (int)
	 */	
	void pulsewidth_ms(int ms);
	
	/* Function: period_us
	 *  Set the PWM period, specified in micro-seconds (int)
	 *
	 * Note:
	 *  This is common to all PwmOut's, so changing it on one will change them all
	 */
	void period_us(int us);
	
	/* Function: pulsewidth_us
	 *  Set the PWM pulsewidth, specified in micro-seconds (int)
	 */	
	void pulsewidth_us(int us);

	/* Group: Access Method Shorthand */

	/* Function: operator=
	 *  A shorthand for <write>
	 */
	PwmOut& operator= (float percent);
	PwmOut& operator= (PwmOut& rhs);

	/* Function: operator float()
	 *  A shorthand for <read>
	 */
	operator float();

    virtual const struct rpc_method *rpc_methods();
	
protected:

	int _id;
};

}

#endif

