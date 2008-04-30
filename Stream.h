/* mbed Microcontroller Library - Stream
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_STREAM_H
#define MBED_STREAM_H

#include "Base.h"

namespace mbed {

class Stream : public Base {

public:

	Stream();

	int putc(int c);
	int getc();
    int printf(const char* format, ...);
    int scanf(const char* format, ...);

	int _backspace();
	
protected:

	virtual int _putc(int c) = 0;
	virtual int _getc() = 0;

	int _back;
	int _last;
	
};

} // namespace mbed

#endif

