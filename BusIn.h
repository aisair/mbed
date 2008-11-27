/* mbed Microcontroller Library - BusIn
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_BUSIN_H
#define MBED_BUSIN_H

#include "Base.h"
#include "DigitalIn.h"

namespace mbed {

/* Class: BusIn
 *  A digital input bus, used for reading the state of a collection of pins
 */
class BusIn : public Base {

public:

	/* Group: Configuration Methods */

	/* Constructor: BusIn
	 *  Create an BusIn, connected to the specified pins
	 *
	 * Variables:
	 *  p<n> - DigitalIn pin to connect to bus bit <n> (5-30, NOT_CONNECTED)
     *
     * Note:
     *  It is only required to specify as many pin variables as is required
     *  for the bus; the rest will default to NOT_CONNECTED
	 */ 
    BusIn(int p0, int p1 = NOT_CONNECTED, int p2 = NOT_CONNECTED, int p3 = NOT_CONNECTED,
          int p4 = NOT_CONNECTED, int p5 = NOT_CONNECTED, int p6 = NOT_CONNECTED, int p7 = NOT_CONNECTED,
          int p8 = NOT_CONNECTED, int p9 = NOT_CONNECTED, int p10 = NOT_CONNECTED, int p11 = NOT_CONNECTED,
          int p12 = NOT_CONNECTED, int p13 = NOT_CONNECTED, int p14 = NOT_CONNECTED, int p15 = NOT_CONNECTED, 
          const char *name = NULL);
		
	virtual ~BusIn();
	
	/* Group: Access Methods */
		
	/* Function: read
	 *  Read the value of the input bus
	 *
	 * Variables:
	 *  returns - An integer with each bit corresponding to the value read from the associated DigitalIn pin
	 */
    int read();
	
	/* Group: Access Method Shorthand */
		
	/* Function: operator int()
	 *  A shorthand for <read>
	 */
	operator int();

    virtual const struct rpc_method *rpc_methods();
		
protected:
	
	DigitalIn* _pin[16];
	
};

}

#endif

