/* mbed Microcontroller Library
 * Copyright (c) 2008 ARM Limited. All rights reserved. 
 */

#ifndef MBED_RPC_H
#define MBED_RPC_H

/* Section rpc
 *  Helpers for rpc handling.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Base.h"

namespace mbed {

/* Function parse_arg
 *  Parses and returns a value from a string.
 *
 * Variable
 *  arg - The string to pase
 *  next - If not NULL a pointer to after the last 
 *    character parsed is written here
 */
template<typename T> T parse_arg(const char *arg, const char **next);

/* signed integer types */

template<> inline char parse_arg<char>(const char *arg, const char **next) {
    if(next != NULL) *next = arg+1;
    return *arg;
}

template<> inline short int parse_arg<short int>(const char *arg, const char **next) {
    return strtol(arg, const_cast<char**>(next), 10);
}

template<> inline long int parse_arg<long int>(const char *arg, const char **next) {
    return strtol(arg, const_cast<char**>(next), 10);
}

template<> inline int parse_arg<int>(const char *arg, const char **next) {
    return strtol(arg, const_cast<char**>(next), 10);
}

template<> inline long long parse_arg<long long>(const char *arg, const char **next) {
    return strtoll(arg, const_cast<char**>(next), 10);
}

/* unsigned integer types */

template<> inline unsigned char parse_arg<unsigned char>(const char *arg, const char **next) {
    if(next != NULL) *next = arg+1;
    return *arg;
}

template<> inline unsigned short int parse_arg<unsigned short int>(const char *arg, const char **next) {
    return strtoul(arg, const_cast<char**>(next), 10);
}

template<> inline unsigned long int parse_arg<unsigned long int>(const char *arg, const char **next) {
    return strtoul(arg, const_cast<char**>(next), 10);
}

template<> inline unsigned int parse_arg<unsigned int>(const char *arg, const char **next) {
    return strtoul(arg, const_cast<char**>(next), 10);
}

template<> inline unsigned long long parse_arg<unsigned long long>(const char *arg, const char **next) {
    return strtoull(arg, const_cast<char**>(next), 10);
}

/* floating types */

template<> inline float parse_arg<float>(const char *arg, const char **next) {
#if !defined(__ARMCC_VERSION) || __ARMCC_VERSION >= 310000
    return strtof(arg,const_cast<char**>(next));
#else
    return strtod(arg,const_cast<char**>(next));
#endif
}

template<> inline double parse_arg<double>(const char *arg, const char **next) {
    return strtod(arg,const_cast<char**>(next));
}

template<> inline long double parse_arg<long double>(const char *arg, const char **next) {
    return strtod(arg,const_cast<char**>(next));
}


/* Function write_result
 *  Writes a value in to a result string in an appropriate manner
 *
 * Variable
 *  val - The value to write
 *  result - A pointer to the array to write the value into
 */
template<typename T> void write_result(T val, char *result);

/* signed integer types */

template<> inline void write_result<char>(char val, char *result) {
    result[0] = val;
    result[1] = '\0';
}

template<> inline void write_result<short int>(short int val, char *result) {
    sprintf(result, "%hi", val); 
}

template<> inline void write_result<int>(int val, char *result) {
    sprintf(result, "%i", val); 
}

template<> inline void write_result<long int>(long int val, char *result) {
    sprintf(result, "%li", val); 
}

template<> inline void write_result<long long int>(long long int val, char *result) {
    sprintf(result, "%lli", val); 
}

/* unsigned integer types */

template<> inline void write_result<unsigned char>(unsigned char val, char *result) {
    result[0] = val;
    result[1] = '\0';
}

template<> inline void write_result<unsigned short int>(unsigned short int val, char *result) {
    sprintf(result, "%hu", val); 
}

template<> inline void write_result<unsigned int>(unsigned int val, char *result) {
    sprintf(result, "%u", val); 
}

template<> inline void write_result<unsigned long int>(unsigned long int val, char *result) {
    sprintf(result, "%lu", val); 
}

template<> inline void write_result<unsigned long long int>(unsigned long long int val, char *result) {
    sprintf(result, "%llu", val); 
}

/* floating types */

template<> inline void write_result<float>(float val, char *result) {
    sprintf(result, "%g", val); 
}

template<> inline void write_result<double>(double val, char *result) {
    sprintf(result, "%g", val); 
}

template<> inline void write_result<long double>(long double val, char *result) {
    sprintf(result, "%Lg", val); 
}


/* Function generic_caller
 */
template<class T, void (T::*member)()> 
void generic_caller(Base *this_ptr, const char *arguments, char *result) { 
    (static_cast<T*>(this_ptr)->*member)(); 
    if(result != NULL) {
    	result[0] = '\0';
    }
}


/* Function generic_caller
 */
template<class T, typename A1, void (T::*member)(A1)> 
void generic_caller(Base *this_ptr, const char *arguments, char *result) {
    const char *next = arguments;

    if(*next == ',' || *next == ' ') next++;
    A1 arg1 = parse_arg<A1>(next,NULL);

    (static_cast<T*>(this_ptr)->*member)(arg1); 
    if(result != NULL) {
        result[0] = '\0';
    }
}


/* Function generic_caller
 */
template<class T, typename A1, typename A2, void (T::*member)(A1,A2)> 
void generic_caller(Base *this_ptr, const char *arguments, char *result) {
    const char *next = arguments;

    if(*next == ',' || *next == ' ') next++;
    A1 arg1 = parse_arg<A1>(next,&next);

    if(*next == ',' || *next == ' ') next++;
    A2 arg2 = parse_arg<A2>(next,NULL);

    (static_cast<T*>(this_ptr)->*member)(arg1,arg2);
    if(result != NULL) {
        result[0] = '\0';
    }
}


/* Function generic_caller
 */
template<typename R, class T, R (T::*member)()> 
void generic_caller(Base *this_ptr, const char *arguments, char *result) { 
    R res = (static_cast<T*>(this_ptr)->*member)();
    if(result != NULL) {
        write_result<R>(res, result);
    }
}


/* Function generic_caller
 */
template<typename R, class T, typename A1, R (T::*member)(A1)> 
void generic_caller(Base *this_ptr, const char *arguments, char *result) {
    const char *next = arguments;

    if(*next == ',' || *next == ' ') next++;
    A1 arg1 = parse_arg<A1>(next,NULL);

    R res = (static_cast<T*>(this_ptr)->*member)(arg1);
    if(result != NULL) {
        write_result<R>(res, result);
    }
}


/* Function generic_caller
 */
template<typename R, class T, typename A1, typename A2, R (T::*member)(A1,A2)> 
void generic_caller(Base *this_ptr, const char *arguments, char *result) {
    const char *next = arguments;

    if(*next == ',' || *next == ' ') next++;
    A1 arg1 = parse_arg<A1>(next,&next);

    if(*next == ',' || *next == ' ') next++;
    A2 arg2 = parse_arg<A2>(next,NULL);

    R res = (static_cast<T*>(this_ptr)->*member)(arg1,arg2);
    if(result != NULL) {
        write_result<R>(res, result);
    }
}

struct rpc_method { 
    const char *name;
    void (*caller)(Base*, const char*, char*);
};
    
#define RPC_METHOD_END { NULL, NULL }


/* Function rpc
 *  Parse a string describing a call and then do it
 *
 * Variables
 *  call - A pointer to a string describing the call, which has
 *    the form /object/method arg ... argn. Arguments are
 *    delimited by space characters, and the string is terminated
 *    by a null character.
 *  result - A pointer to an array to write the result into.
 */
bool rpc(const char *buf, char *result = 0);

} /* namespace mbed */

#endif
