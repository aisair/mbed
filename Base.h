/* mbed Microcontroller Library - Base
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_BASE_H
#define MBED_BASE_H

#define MBED_BASE_NUM_OBJECTS 	128		// max # base objects
#define MBED_BASE_SIZE_NAME 	16 		// max size of object name, including the null-termination

#include "rt_sys.h"

namespace mbed {

class Base {

public: 

	Base();
	virtual ~Base();

	void name(const char* name);
	const char* name();
	const char* type();
	
	static Base* lookup(const char* name);
	
	virtual FILEHANDLE sys_open(const char* name, int openmode);

protected: 

	const char* _type;					// The class type
	char _name[MBED_BASE_SIZE_NAME];	// The class instance name	
	
	static int _uid;								// The counter used to generate the uid's 
	static Base* _objects[MBED_BASE_NUM_OBJECTS]; 	// Pointers to all the objects to enable things like rpc
	
};

} // namespace mbed

#endif