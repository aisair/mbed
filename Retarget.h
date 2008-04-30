/* mbed Microcontroller Library - Retarget
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_RETARGET_H
#define MBED_RETARGET_H

#include "stdio.h"
#include "rt_sys.h"

//===================================================================
// System
//===================================================================

extern "C" void mbed_startup();
extern "C" int $Sub$$main();
extern "C" void $Sub$$_sys_exit(int return_code);

//===================================================================
// Pre-stdio
//===================================================================

extern "C" int $Sub$$fputc(int c, FILE* f);
extern "C" int $Sub$$fgetc(FILE* f);
extern "C" int $Sub$$__backspace(FILE* f);
extern "C" void $Sub$$_ttywrch(int c);

//===================================================================
// Post-stdio
//===================================================================

extern "C" FILEHANDLE $Sub$$_sys_open(const char* name, int openmode);
extern "C" int $Sub$$_sys_close(FILEHANDLE fh);
extern "C" int $Sub$$_sys_write(FILEHANDLE fh, const unsigned char* buffer, unsigned int length, int mode);
extern "C" int $Sub$$_sys_read(FILEHANDLE fh, unsigned char* buffer, unsigned int length, int mode);
extern "C" int $Sub$$_sys_istty(FILEHANDLE fh);
extern "C" int $Sub$$_sys_seek(FILEHANDLE fh, int position);
extern "C" int $Sub$$_sys_ensure(FILEHANDLE fh);
extern "C" int $Sub$$_sys_flen(FILEHANDLE fh);


#endif

