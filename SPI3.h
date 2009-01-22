/* mbed Microcontroller Library - SPI3
 * Copyright (c) 2007-2009, sford
 */
 
#ifndef MBED_SPI3_H
#define MBED_SPI3_H

#include "Base.h"
#include "LPC2300.h"

namespace mbed {

/* Class: SPI3
 *  A SPI Master, used for communicating with 3-wire SPI slave devices 
 *
 *  3-wire SPI devices use the same line for input an output, and should be connected to both
 *  the mosi and miso pins on the mbed Microcontroller
 */ 

class SPI3 : public Base {

public:
	
	/* Constructor: SPI3
	 *  Create a 3-wire SPI master connected to the specified pins
	 *
	 * Variables:
	 *  mosi - SPI Master Out, Slave In pin
	 *  miso - SPI Master In, Slave Out pin
	 *  sclk - SPI Clock pin
     *
	 * Pin Options:
	 *  (5, 6, 7) or (11, 12, 13)
	 */
	SPI3(int mosi, int miso, int sclk, const char *name=NULL);
	
	/* Function: format
	 *  Configure the data transmission format
	 *
	 * Variables:
	 *  bits - Number of bits per SPI frame (4 - 16, default = 8)
	 *  mode - Clock polarity and phase mode (0 - 3, default = 0)
     *
 	 * > mode | POL PHA 
     * > -----+--------	 
     * >   0  |  0   0 
	 * >   1  |  0   1
     * >   2  |  1   0 
	 * >   3  |  1   1
	 */
	void format(int bits = 8, int mode = 0);

	// old one...
	void format(int bits = 8, int polarity = 0, int phase = 0);
	
	/* Function: frequency
	 *  Set the bus clock frequency
	 *
	 * Variables:
	 *  hz - SCLK frequency in hz (default = 1MHz)
	 */
	void frequency(int hz = 1000000);
			
	/* Function: write
	 *  Set the direction to output and write to the SPI Slave
	 *
     * Variables:
     *  value - Data to be sent to the SPI slave
	 */
  	void write(int value);

	/* Function: read
 	 *  Set the direction to input, read from the SPI Slave
	 *
     * Variables:
     *  returns - Response from the SPI slave
	 */
	int read();
	
    virtual const struct rpc_method *get_rpc_methods();
    static struct rpc_class *get_rpc_class();

protected:

	void configure();
	
	int _id;

	int _uid;
	static int _uidcounter;
		
	int _bits, _polarity, _phase, _hz;
	static int _config[2];	
 	const LPC2300::PortMap*  mosi_portmap; 
};

}

#endif

