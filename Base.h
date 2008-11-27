/* mbed Microcontroller Library - Base
 * Copyright (c) 2006-2008 ARM Limited. All rights reserved.
 * sford, jbrawn
 */
 
#ifndef MBED_BASE_H
#define MBED_BASE_H

#include <cstdlib>

namespace mbed {

/* Class Base
 *  The base class for most things
 */
class Base {

public: 
    
    Base(const char *name = NULL);

    virtual ~Base();

    /* Function register_object
     *  Registers this object with the given name, so that it can be
     *  looked up with lookup. If this object has already been
     *  registered, then this just changes the name.
     *
     * Variables
     *   name - The name to give the object. If NULL we do nothing.
     */
    void register_object(const char *name);

    /* Function name
     *  Returns the name of the object, or NULL if it has no name.
     */
    const char *name();

    /* Function rpc
     *  Call the given method with the given arguments, and write the
     *  result into the string pointed to by result. The default
     *  implementation calls rpc_methods to determine the supported
     *  methods.
     *
     * Variables
     *  method - The name of the method to call.
     *  arguments - A list of arguments separated by spaces.
     *  result - A pointer to a string to write the result into. May
     *    be NULL, in which case nothing is written.
     *  returns - true if method corresponds to a valid rpc method, or
     *    false otherwise.
     */
    virtual bool rpc(const char *method, const char *arguments, char *result);	

    /* Function rpc_method
     *  Returns a pointer to an array describing the rpc methods
     *  supported by this object, terminated by RPC_METHOD_END.
     *
     * Example
     *
     * > class Example : public Base {
     * >   int foo(int a, int b) { return a + b; }
     * >   virtual const struct rpc_method *rpc_methods() {
     * >     static const rpc_method rpc_methods[] = {
     * >       { "foo", generic_caller<int, Example, int, int, &Example::foo> },
     * >       RPC_METHOD_END
     * >     };
     * >     return rpc_methods;
     * >   }
     * > };
     */
    virtual const struct rpc_method *rpc_methods();

    /* Function rpc
     *  Use the lookup function to lookup an object and, if
     *  successful, call its rpc method
     *
     * Variables
     *  returns - false if name does not correspond to an object,
     *    otherwise the return value of the call to the object's rpc
     *    method.
     */
    static bool rpc(const char *name, const char *method, const char *arguments, char *result);

    /* Function lookup
     *  Lookup and return the object that has the given name.
     *
     * Variables
     *  name - the name to lookup.
     *  len - the length of name.
     */
    static Base *lookup(const char *name, unsigned int len);

protected: 

    static Base *_head;
    Base *_next;
    const char *_name;

};

/* Macro MBED_OBJECT_NAME_MAX
 *  The maximum size of object name (including terminating null byte)
 *  that will be recognised when using fopen to open a FileLike
 *  object, or when using the rpc function.
 */ 
#define MBED_OBJECT_NAME_MAX 32

/* Macro MBED_METHOD_NAME_MAX
 *  The maximum size of rpc method name (including terminating null
 *  byte) that will be recognised by the rpc function (in rpc.h).
 */ 
#define MBED_METHOD_NAME_MAX 32

} // namespace mbed

#endif

