/* mbed Microcontroller Library - I2C
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_I2C_H
#define MBED_I2C_H

#include "Base.h"

namespace mbed {

/* Class: I2C
 *  An I2C Master, used for communicating with I2C slave devices
 */
class I2C : public Base {

public:

	/* Group: Configuration Methods */

	/* Constructor: I2C
	 *  Create an I2C Master interface, connected to the specified pins
	 *
	 * Variables:
	 *  sda - I2C data line pin
	 *  scl - I2C clock line pin
     *
	 * Pin Options:
	 *  (9, 10) or (28, 27)	 
	 */
	I2C(int sda, int scl, const char *name = NULL);
	
	/* Function: frequency
	 *  Set the frequency of the I2C interface
	 *
	 * Variables:
	 *  hz - The bus frequency in hertz
	 */
	void frequency(int hz);
	
	/* Group: Access Methods */
		
	/* Function: read
	 *  Read from an I2C slave
	 *
	 * Variables:
	 *  address - 7-bit I2C slave address (0-127)
	 *  data - Pointer to the byte-array to read data in to 
	 *  length - Number of bytes to read
	 */ 
	void read(int address, char* data, int length); 

	/* Function: write
	 *  Write to an I2C slave
	 *
	 * Variables:
	 *  address - 7-bit I2C slave address (0-127)
	 *  data - Pointer to the byte-array data to send 
	 *  length - Number of bytes to send
	 */ 
	void write(int address, char* data, int length);

protected:

	void configure();
	
	int _id;

	int _uid;
	static int _uidcounter;
		
	int _hz;
	static int _config[3];	
		
};

}

#endif

