/* mbed Microcontroller Library - DigitalIn
 * Copyright (c) 2006-2009 ARM Limited. All rights reserved.
 * sford
 */ 
 
#ifndef MBED_DIGITALIN_H
#define MBED_DIGITALIN_H

#include "Base.h"
#include "LPC2300.h"
#include "FunctionPointer.h"

namespace mbed {

/* Class: DigitalIn
 *  A digital input, used for reading the state of a pin
 *
 * Example:
 * > // Flash an LED while a DigitalIn is true
 * >
 * > #include "mbed.h"
 * >
 * > DigitalIn enable(5);
 * > DigitalOut led(1);
 * >
 * > int main() {
 * >     while(1) {
 * >         if(enable) {
 * >             led = !led;
 * >         }
 * >         wait(0.25);
 * >     }
 * > }
 *
 * Implementation Note:
 *  pin 19 and 20 can not be used with the rise/fall methods
 */
class DigitalIn : public Base {

public:

	/* Constructor: DigitalIn
	 *  Create a DigitalIn connected to the specified pin
	 *
	 * Variables:
	 *  pin - DigitalIn pin to connect to (5-30)
     *  name - (optional) A string to identify the object
	 */
	DigitalIn(int pin, const char *name = NULL);

	/* Function: read
	 *  Read the input, represented as 0 or 1 (int)
	 *
	 * Variables:
	 *  returns - An integer representing the state of the input pin, 
	 *      0 for logical 0 (0v) and 1 for logical 1 (3.3v)
	 */	
    int read();
 
	/* Function: rise
	 *  Attach a function to call when a rising edge occurs on the input
	 *
	 * Variables:
	 *  fptr - A pointer to a void function, or 0 to set as none
	 */
	void rise(void (*fptr)(void));

	/* Function: rise
	 *  Attach a member function to call when a rising edge occurs on the input
     *     
     * Variables:
     *  tptr - pointer to the object to call the member function on
     *  mptr - pointer to the member function to be called
     */
    template<typename T>
    void rise(T* tptr, void (T::*mptr)(void)) {
		_rise.attach(tptr, mptr);
		setup_interrupt(1, 1);
    }

	/* Function: fall
	 *  Attach a function to call when a falling edge occurs on the input
	 *
	 * Variables:
	 *  fptr - A pointer to a void function, or 0 to set as none
	 */
	void fall(void (*fptr)(void));

	/* Function: fall
	 *  Attach a member function to call when a falling edge occurs on the input
     *     
     * Variables:
     *  tptr - pointer to the object to call the member function on
     *  mptr - pointer to the member function to be called
     */
    template<typename T>
    void fall(T* tptr, void (T::*mptr)(void)) {
		_fall.attach(tptr, mptr);
		setup_interrupt(0, 1);
	}
		
    /* Function: operator int()
     *  An operator shorthand for <read()>
     */
	operator int();
 	
 	// interrupt
 	static void _irq(); 
	static DigitalIn *_irq_objects[48];

	// rpc
    virtual const struct rpc_method *get_rpc_methods();
    static struct rpc_class *get_rpc_class();

protected:

	LPC2300::GPIORF* _rf;
	unsigned int _mask;
	int _id;

	void setup_interrupt(int rising, int enable);
	FunctionPointer _rise;
	FunctionPointer _fall;
};

}

#endif

