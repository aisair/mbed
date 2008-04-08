/* mbed Microcontroller Library - BusOut
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_BUSOUT_H
#define MBED_BUSOUT_H

#include "Base.h"
#include "DigitalOut.h"

namespace mbed {

/* Class: BusOut
 *  A digital output bus, used for setting the state of a collection of pins
 */
class BusOut : public Base {

public:

	/* Group: Configuration Methods */
	
	/* Constructor: BusOut
	 *  Create an BusOut, connected to the specified pins
	 *
	 * Variables:
	 *  p<n> - DigitalOut pin to connect to bus bit <n> (5-30, NOT_CONNECTED)
     *
     * Note:
     *  It is only required to specify as many pin variables as is required
     *  for the bus; the rest will default to NOT_CONNECTED
   	 */ 
	BusOut(int p0, int p1 = NOT_CONNECTED, int p2 = NOT_CONNECTED, int p3 = NOT_CONNECTED,
		  int p4 = NOT_CONNECTED, int p5 = NOT_CONNECTED, int p6 = NOT_CONNECTED, int p7 = NOT_CONNECTED,
		  int p8 = NOT_CONNECTED, int p9 = NOT_CONNECTED, int p10 = NOT_CONNECTED, int p11 = NOT_CONNECTED,
		  int p12 = NOT_CONNECTED, int p13 = NOT_CONNECTED, int p14 = NOT_CONNECTED, int p15 = NOT_CONNECTED);

	virtual ~BusOut();

	/* Group: Access Methods */
		
	/* Function: write
	 *  Write the value to the output bus
	 *
	 * Variables:
	 *  value - An integer specifying a bit to write for every corresponding DigitalOut pin
	 */
    void write(int value);

		
	/* Function: read
	 *  Read the value currently output on the bus
	 *
	 * Variables:
	 *  returns - An integer with each bit corresponding to associated DigitalOut pin setting
	 */
    int read();

	/* Group: Access Method Shorthand */
	   
   	/* Function: operator=
	 *  A shorthand for <write>
	 */
	BusOut& operator= (int v);
	BusOut& operator= (BusOut& rhs);
		
	/* Function: operator int()
	 *  A shorthand for <read>
	 */
	operator int();

protected:

	DigitalOut* _pin[16];
			
};

} // namespace mbed

#endif