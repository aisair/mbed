/* mbed Microcontroller Library - SemihostFileHandle
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_SEMIHOSTFILEHANDLE_H
#define MBED_SEMIHOSTFILEHANDLE_H

#include "rt_sys.h"
#include "FileHandle.h"

extern "C" int $Super$$_sys_close(FILEHANDLE fh);
extern "C" int $Super$$_sys_write(FILEHANDLE fh, const unsigned char* buffer, unsigned int length, int mode);
extern "C" int $Super$$_sys_read(FILEHANDLE fh, unsigned char* buffer, unsigned int length, int mode);
extern "C" int $Super$$_sys_istty(FILEHANDLE fh);
extern "C" int $Super$$_sys_seek(FILEHANDLE fh, int position);
extern "C" int $Super$$_sys_ensure(FILEHANDLE fh);
extern "C" long $Super$$_sys_flen(FILEHANDLE fh);

namespace mbed { 

/* Class SemihostFileHandle
 *  Implements a FileHandle for talking to the standard Semihosting implementation
 */
class SemihostFileHandle : public FileHandle {

public:

	/* Constructor SemihostFileHandle
	 *  Create a SemihostFileHandle using a standard FILEHANDLE
	 */
	SemihostFileHandle(FILEHANDLE fh) { 
		_fh = fh; 
	}
	
	virtual int sys_close() { 
		return $Super$$_sys_close(_fh);
	}
	//	virtual ~SemihostFileHandle() { 
	//	$Super$$_sys_close(_fh);
	//}

	virtual	int sys_write(const unsigned char* buffer, unsigned int length, int mode) {
		return $Super$$_sys_write(_fh, buffer, length, mode);
	}
	
	virtual	int sys_read(unsigned char* buffer, unsigned int length, int mode) {
		return $Super$$_sys_read(_fh, buffer, length, mode);
	}
	
	virtual	int sys_istty() {
		return $Super$$_sys_istty(_fh);
	}
	
	virtual	int sys_seek(int position) {
		return $Super$$_sys_seek(_fh, position);
	}
	
	virtual	int sys_ensure() {
		return $Super$$_sys_ensure(_fh);
	}
	
	virtual	int sys_flen() {
		return $Super$$_sys_flen(_fh);
	}	

protected:

	FILEHANDLE _fh;

};

} // namespace mbed

#endif