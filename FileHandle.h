/* mbed Microcontroller Library - FileHandle
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_FILEHANDLE_H
#define MBED_FILEHANDLE_H

namespace mbed { 

/* Class: FileHandle
 *  An OO equivalent of the internal FILEHANDLE variable
 *  and associated _sys_* functions
 *
 * FileHandle is an abstract class, needing at least sys_write and
 * sys_read to be implmented for a simple interactive device
 *
 * No one ever directly tals to/instanciates a FileHandle - it gets 
 * created by FileSystem, and wrapped up by stdio
 */
class FileHandle {

public:

	//virtual ~FileHandle() { }
	
	/* Function: sys_write
	 *  Write the contents of a buffer to the file
     *
     * Parameters:
     *  buffer - the buffer to write from
     *  length - the number of characters to write
     *  mode   - the mode of the file, 0 (normal) or 1 (binary); this may be unused?
     *
	 * Returns:
	 *  0 on success, -1 on error, or the number of characters not written on partial success
     */
	virtual	int sys_write(const unsigned char* buffer, unsigned int length, int mode) = 0;

	virtual	int sys_close() = 0;
	
	/* Function: sys_read
	 *  Reads the contents of the file into a buffer
	 *
     * Parameters:
     *  buffer - the buffer to read in to
     *  length - the number of characters to read
     *  mode   - the mode of the file, 0 (normal) or 1 (binary); this may be unused?
     *
     * Returns:
     *  0 on success, -1 on error, or the number of characters not read on partial success. EOF is 
     *  signaled by setting the top bit (0x80000000) of the return value. 
	 */
	virtual	int sys_read(unsigned char* buffer, unsigned int length, int mode) = 0;
	
	/* Function: sys_istty
	 *  Check if the handle is for a interactive terminal device 
	 *
	 * If so, unbuffered behaviour is used by default
	 *
	 * Returns:
	 *  0 - no
	 *  1 - yes
	 */
	virtual	int sys_istty() = 0 ;

	/* Function: sys_seek
 	 *  Move the file position to a given offset from the file start
 	 *
 	 * Returns:
 	 *  0 on success, -1 on failure or unsupported
 	 */
	virtual	int sys_seek(int position) = 0;
	
	/* Function: sys_ensure
	 *  Flush any OS buffers associated with the FileHandle, ensuring it
	 *  is up to date on disk
	 *
	 * Returns:
	 *  0 on success or un-needed, -1 on error
 	 */
	virtual	int sys_ensure() = 0;
	
	/* Function: sys_flen
	 *  Find the current length of the file
	 *
	 * Returns:
	 *  The current length of the file, or -1 on error
	 */
	virtual	int sys_flen() = 0;
		
};

} // namespace mbed

#endif

