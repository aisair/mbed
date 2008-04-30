/* mbed Microcontroller Library - Serial
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_SERIAL_H
#define MBED_SERIAL_H

#include "Stream.h"

namespace mbed {

/* Class: Serial
 *  A serial port (UART) for communication with other serial devices
 */
class Serial : public Stream {

public:

	/* Group: Configuration Methods */
	 
	/* Constructor: Serial
	 *  Create a Serial port, connected to the specified transmit and receive pins
	 *
	 * Variables:
	 *  tx - Transmit pin 
	 *  rx - Receive pin
	 *
	 * Pin Options:
	 *  (9, 10) or (13, 14) or (28, 27)
     */
	Serial(int tx, int rx);


	/* Function: baud
	 *  Set the baud rate of the serial port
	 *  
	 * Variables:
	 *  baudrate - The baudrate of the serial port (default = 9600).
	 *      Standard baud rates up to 921600 are supported.
	 */
	void baud(int baudrate);

	enum Parity {
		None = 0,
		Odd = 1,
		Even = 2,
		Forced1 = 3,
		Forced0 = 4
	};

	/* Function: format
	 *  Set the transmission format used by the Serial port
	 *
	 * Variables:
	 *  bits - The number of bits in a word (5-8; default = 8)
	 *  parity - The type of parity used (None, Odd, Even, Forced1, Forced0; default = None)
	 *  stop - The number of stop bits (1 or 2; default = 1)
	 */	
	void format(int bits, int parity, int stop); 

	
	/* Group: Access Methods */

#if 0 // Inhereted from Stream, for documentation only

	/* Function: putc
	 *  Write a character
	 *
	 * Variables:
	 *  c - The character to write to the serial port
	 */
	int putc(int c);

	/* Function: getc
	 *  Read a character
	 *
	 * Variables:
	 *  returns - The character read from the serial port
	 */
	int getc();
		
	/* Function: printf
	 *  Write a formated string
	 *
	 * Variables:
	 *  format - A printf-style format string, followed by the 
	 *      variables to use in formating the string.
	 */
    int printf(const char* format, ...);

	/* Function: scanf
	 *  Read a formated string 
	 *
	 * Variables:
	 *  format - A scanf-style format string,
	 *      followed by the pointers to variables to store the results. 
	 */
    int scanf(const char* format, ...);
		 
#endif
	 	 	 
	/* Function: readable
	 *  Determine if there is a character available to read
	 *
	 * Variables:
	 *  returns - 1 if there is a character available to read, else 0
	 */
	int readable();

	/* Function: writeable
	 *  Determine if there is space available to write a character
	 * 
	 * Variables:
	 *  returns - 1 if there is space to write a character, else 0
	 */
	int writeable();	
	
protected:

	virtual int _getc();	
	virtual int _putc(int c);
	
	int _id;
	
};

}

#endif

