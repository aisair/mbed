/* Copyright 2008 ARM Limited. All rights reserved. */

#ifndef MBED_FILESYSTEMLIKE_H
#define MBED_FILESYSTEMLIKE_H

#include "Base.h"
#include "FileHandle.h"
#ifdef __ARMCC_VERSION
# define O_RDONLY 0
# define O_WRONLY 1
# define O_RDWR   2
# define O_CREAT  0x0200
# define O_TRUNC  0x0400
# define O_APPEND 0x0008
#else
# include <sys/fcntl.h>
#endif

namespace mbed {

/* Class FileSystemLike
 *  A filesystem-like object is one that can be used to open files
 *  though it by fopen("/name/filename", mode)
 *
 *  Implementations must define at least open (the default definitions
 *  of the rest of the functions just return error values).
 */
class FileSystemLike : public Base {

 public:

    /* Constructor FileSystemLike
     *
     * Variables
     *  name - The name to use for the filesystem.
     */
    FileSystemLike(const char *name) : Base(name) {}

    /* Function open
     *
     * Variables
     *  filename - The name of the file to open.
     *  flags - One of O_RDONLY, O_WRONLY, or O_RDWR, OR'd with
     *    zero or more of O_CREAT, O_TRUNC, or O_APPEND.
     *  returns - A pointer to a FileHandle object representing the
     *   file on success, or NULL on failure.
     */
    virtual FileHandle *open(const char *filename, int flags) = 0;

    /* Function remove
     *  Remove a file from the filesystem.
     *
     * Variables
     *  filename - the name of the file to remove.
     *  returns - 0 on success, -1 on failure.
     */
    virtual int remove(const char *filename) { return -1; };

    /* Function rename
     *  Rename a file in the filesystem.
     *
     * Variables
     *  oldname - the name of the file to rename.
     *  newname - the name to rename it to.
     *  returns - 0 on success, -1 on failure.
     */
    virtual int rename(const char *oldname, const char *newname) { return -1; };

    // TODO other filesystem functions (mkdir, rm, rn, ls etc)
    
};

} // namespace mbed

#endif
