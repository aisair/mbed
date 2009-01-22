/* mbed Microcontroller Library - AnalogIn
 * Copyright (c) 2006-2009 ARM Limited. All rights reserved.
 * sford
 */ 

#ifndef MBED_ANALOGIN_H
#define MBED_ANALOGIN_H

#include "Base.h"

namespace mbed {

/* Class: AnalogIn
 *  An analog input, used for reading the voltage on a pin 
 *
 * Example:
 * > // Print messages when the AnalogIn is greater than 50%
 * >
 * > #include "mbed.h"
 * >
 * > AnalogIn temperature(20);
 * >
 * > int main() {
 * >     while(1) {
 * >         if(temperature > 0.5) {
 * >             printf("Too hot! (%f)", temperature.read());             
 * >         }
 * >     }
 * > }
 */
class AnalogIn :  public Base {

public:

    /* Constructor: AnalogIn
     *  Create an AnalogIn, connected to the specified pin
     *
     * Variables:
     *  pin - AnalogIn pin to connect to (15 - 20)
     *  name - (optional) A string to identify the object
     */
	AnalogIn(int pin, const char *name = NULL);
	
    /* Function: read
     * Read the input voltage, represented as a float in the range [0.0, 1.0]
     *
     * Variables:
     *  returns - A floating-point value representing the current input voltage,
     *            measured as a percentage (0.0 = 0v, 1.0 = 3.3v)
     */
    float read();	

    /* Function: read_u16
     *  Read the input voltage, represented as an unsigned short in the range [0x0, 0xFFFF]
     *
     * Variables:
     *  returns - 16-bit unsigned short representing the current input voltage,
     *            normalised to a 16-bit value (0x0000 = 0v, 0xFFFF = 3.3v)
     */
    unsigned short read_u16();

    // functions to be removed in time...
    float read_v();
    int read_mv();
	
    /* Function: operator float
     *  An operator shorthand for <read()>
     *
     * The float() operator can be used as a shorthand for <read()> to simplify common code sequences
     *
     * Example:
     * > float x = volume.read();
     * > float x = volume;
     * >
     * > if(volume.read() > 0.25) { ... }
     * > if(volume > 0.25) { ... }
     */
	operator float();

    virtual const struct rpc_method *get_rpc_methods();
    static struct rpc_class *get_rpc_class();

protected:
	
	int _id;
	
};

}

#endif

