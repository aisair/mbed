/* mbed Microcontroller Library - DebugTracer
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_DEBUGTRACER_H
#define MBED_DEBUGTRACER_H

#include "Base.h"
#include "stdio.h"

#define MAX_TRACER_DEPTH 32

namespace mbed {

//#define METHOD(name) 	
//#define FUNCTION(name)	
#define METHOD(name) 	DebugTracer _tracer_instance(name, this)
#define FUNCTION(name)	DebugTracer _tracer_instance(name)

/* Class: DebugTracer
 *  A code instrumentation utility
 * 
 * This object adds a function name or methodname/object instance 
 * to a stack on construction, and removes it on destruvtion. It 
 * can therefore be used at the start of functions to trace entry, exit
 * and the call graph/stack.
 *
 * Wrapped in macros and with altered implementations, the same instrumentation can:
 *  - be #defined away to nothing
 *  - provide the call stack on encountering an error
 *  - trace the runtime call graph (for the whole program run, or programatically on/off) 
 *
 *
 * Example:
 *
 * Function example
 * > void foo(int x) { FUNCTION("foo");
 * >    // normal code
 *
 * Class method example
 * > void Foo::bar(int x) { METHOD("bar");
 * >     // normal code
 */
class DebugTracer {

public:

	/* Constructor: DebugTracer
	 *  Record the method and object instance it is called on
	 *  to the call stack
	 */
	DebugTracer(char* method, Base* object = 0) {
		_functions[_depth] = method;
		_objects[_depth] = object;
		_depth++;
	}
	
	/* Destructor: ~DebugTracer
	 *  Pop from the call stack
	 */
	~DebugTracer() {
		_depth--;
	}

	static void stack() {
		fprintf(stderr, "Trace (depth = %d):\n", _depth);
		for(int i=0; i<_depth; i++) { 
			// indent
			for(int j=0; j<i; j++) {
				fprintf(stderr, "  ");
			}
			if(_objects[i]) {
				fprintf(stderr, "%s::", _objects[i]->type());
			}
			fprintf(stderr, "%s\n", _functions[i]);
		}
	}

	static int enabled;
	
protected:
	
	static Base* _objects[MAX_TRACER_DEPTH];
	static char* _functions[MAX_TRACER_DEPTH];
	static int _depth;

};

} // namespace mbed

#endif