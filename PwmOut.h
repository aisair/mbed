/* mbed Microcontroller Library - PwmOut
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_PWMOUT_H
#define MBED_PWMOUT_H

#include "Base.h"

namespace mbed {

/* Class: PwmOut
 *  A pulse-width modulation digital output
 *
 * Implementation Note:
 *  The period is is common to all PwmOut's, so changing it on one PwmOut will change them all!
 */
class PwmOut : public Base {

public:

	/* Constructor: PwmOut
	 *  Create a PwmOut connected to the specified pin
	 *
	 * Variables:
	 *  pin - PwmOut pin to connect to (21-26)
	 */	
	PwmOut(int pin, const char *name = NULL);

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
	
	/* Function: period
	 *  Set the PWM period, specified in seconds (float)
	 */
	void period(float seconds);

	/* Function: period_ms
	 *  Set the PWM period, specified in milli-seconds (int)
	 */
	void period_ms(int ms);

	/* Function: period_us
	 *  Set the PWM period, specified in micro-seconds (int)
	 */
	void period_us(int us);

	/* Function: pulsewidth
	 *  Set the PWM pulsewidth, specified in seconds (float)
	 */	
	void pulsewidth(float seconds);
		
	/* Function: pulsewidth_ms
	 *  Set the PWM pulsewidth, specified in milli-seconds (int)
	 */	
	void pulsewidth_ms(int ms);
	
	/* Function: pulsewidth_us
	 *  Set the PWM pulsewidth, specified in micro-seconds (int)
	 */	
	void pulsewidth_us(int us);

	/* Function: operator=
	 *  A operator shorthand for <write()>
	 */
	PwmOut& operator= (float percent);
	PwmOut& operator= (PwmOut& rhs);

	/* Function: operator float()
	 *  An operator shorthand for <read()>
	 */
	operator float();

	// functions to be dropped in time...
	void write_v(float v);
	void write_mv(int mv);

    virtual const struct rpc_method *get_rpc_methods();
    static struct rpc_class *get_rpc_class();

	
protected:

	int _id;
};

}

#endif

