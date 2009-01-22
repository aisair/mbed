/* mbed Microcontroller Library - Timer
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_TIMER_H
#define MBED_TIMER_H

#include "Base.h"

namespace mbed {

/* Class: Timer
 *  A general purpose timer 
 */
class Timer : public Base {

public:

	Timer(const char *name = NULL);
	
	/* Group: Access Methods */
		
	/* Function: start
	 *  Start the timer
	 */
	void start(); 
	
	/* Function: stop
	 *  Stop the timer
	 */
	void stop(); 
	
	/* Function: reset
	 *  Reset the timer to 0. 
	 *
	 * If it was already counting, it will continue
	 */
	void reset();

	/* Function: read
	 *  Get the time passed in seconds
	 */
	float read();
	
	/* Function: read_ms
	 *  Get the time passed in mili-seconds
	 */
	int read_ms();

	/* Function: read_us
	 *  Get the time passed in micro-seconds
	 */
	int read_us();

	operator float();

	int slicetime();
	
        int _running;          // whether the timer is running
	unsigned int _start;   // the start time of the latest slice
	int _time;             // any accumulated time from previous slices

    virtual const struct rpc_method *get_rpc_methods();
    static struct rpc_class *get_rpc_class();

};

}

#endif

