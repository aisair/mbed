/* mbed Microcontroller Library - SemihostFileSystem
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_LOCALFILESYSTEM_H
#define MBED_LOCALFILESYSTEM_H

#include "FileSystemLike.h"

namespace mbed {

/* Class: LocalFileSystem
 *  A filesystem for accessing the local mbed Microcontroller USB disk drive. 
 *
 *  This allows programs to read and write files on the same disk drive that is used to program the 
 *  mbed Microcontroller. Once created, the standard C file access functions are used to open, 
 *  read and write files.
 *
 * Example:
 * > #include "mbed.h"
 * >
 * > LocalFileSystem local("local");             // Create the local filesystem under the name "local"
 * >
 * > int main() {
 * >     FILE *fp = fopen("/local/out.txt", "w");  // Open "out.txt" on the local file system for writing
 * >     fprintf(fp, "Hello World!");              
 * >     fclose(fp);                               
 * > }
 *
 * Implementation Notes:
 *  If the microcontroller program makes an access to the local drive, it will be marked as "removed"
 *  on the Host computer. This means it is no longer accessible from the Host Computer.
 *
 *  The drive will only re-appear when the microcontroller program exists. Note that if the program does
 *  not exit, you will need to hold down reset on the mbed Microcontroller to be able to see the drive again!
 */
class LocalFileSystem : public FileSystemLike {

public:

    LocalFileSystem(const char* n) : FileSystemLike(n) {

    }
	
    virtual FileHandle *open(const char* name, int flags);
    virtual int remove(const char *filename);

};

} // namespace mbed

#endif
