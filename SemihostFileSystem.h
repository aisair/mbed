/* mbed Microcontroller Library - SemihostFileSystem
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_SEMIHOSTFILESYSTEM_H
#define MBED_SEMIHOSTFILESYSTEM_H

#include "rt_sys.h"

#include "SemihostFileHandle.h"

extern "C" FILEHANDLE $Super$$_sys_open(const char *name, int openmode);

namespace mbed {

/* Class SemihostFileSystem
 *  A file system invoking the standard semihosting implementation
 */
class SemihostFileSystem : public Base {

public:

	SemihostFileSystem(char* n) {
		name(n);
		_type = "SemihostFileSystem";
	}
	
	virtual FILEHANDLE sys_open(const char* name, int openmode) {
		FILEHANDLE fh = $Super$$_sys_open(name, openmode);
		FileHandle* fhc = new SemihostFileHandle(fh);
		return (FILEHANDLE)fhc;
	}
	
};

} // namespace mbed

#endif