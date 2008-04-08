/* mbed Microcontroller Library - SPI
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_SPI_H
#define MBED_SPI_H

#include "Base.h"
#include "LPC2300.h"

namespace mbed {

/* Class: SPI
 *  A SPI Master, used for communicating with SPI slave devices
 */ 
class SPI : public Base {

public:

	/* Group: Configuration Methods */
	
	/* Constructor: SPI
	 *  Create a SPI master connected to the specified pins
	 *
	 * Variables:
	 *  mosi - SPI Master Out, Slave In pin
	 *  miso - SPI Master In, Slave Out pin
	 *  sclk - SPI Clock pin
     *
	 * Pin Options:
	 *  (5, 6, 7) or (11, 12, 13)
	 */
	SPI(int mosi, int miso, int sclk);
	
	/* Function: format
	 *  Set the transmission format
	 *
	 * Variables:
	 *  bits - Number of bits per frame (4 - 16, default = 8)
	 *  polarity - Clock polarity, 0 = Steady state low (default), 1 = Steady state high  
	 *  phase - Clock phase, 0 = Capture on first edge (default), 1 = Capture on second edge
	 */
	void format(int bits = 8, int polarity = 0, int phase = 0);
	
	/* Function: frequency
	 *  Set the bus clock frequency
	 *
	 * Variables:
	 *  hz - SCLK frequency in hz (default = 1MHz)
	 */
	void frequency(int hz = 1000000);
	
	/* Group: Access Methods */
		
	/* Function: write
	 *  Write to the SPI Slave and return the response
	 *
     * Variables:
     *  value - Data to be sent to the SPI slave
     *  returns - Response from the SPI slave
	 */
  	int write(int value);

protected:

	void configure();
	
	int _id;

	int _uid;
	static int _uidcounter;
		
	int _bits, _polarity, _phase, _hz;
	static int _config[2];	
};

}

#endif