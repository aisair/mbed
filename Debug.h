/* mbed Microcontroller Library - Debug
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_DEBUG_H
#define MBED_DEBUG_H

#include <cstdio>
#include <cstdlib>
#define __ASSERT_MSG
#include <assert.h>

namespace mbed {

/* Section: debug
 *  Error reporting and debugging functions 
 */

void mbedinfo(std::FILE *fp = stdout);

#define error(...) (std::fprintf(stderr, __VA_ARGS__), std::abort())

// As seen by user, for documentation purposes only
#if 0 
/* Function: error
 *  Report a fatal runtime error. Attempts to report the specified error message through the
 * USB serial port, then dies with a fatal runtime error (siren lights)
 *
 * Variables:
 *  format - printf-style format string, followed by associated variables
 */
void error(const char* format, ...);
#endif 

void ERROR(const char* format, ...);// __attribute__((deprecated));
void ASSERT(int condition, const char* format = 0, ...);// __attribute__((deprecated));
void DEBUG(const char* format, ...);// __attribute__((deprecated));

/* Function: DEBUG_LED1
 *  Set the state of LED1
 */
void DEBUG_LED1(int v);

/* Function: DEBUG_LED2
 *  Set the state of LED2
 */
void DEBUG_LED2(int v);

/* Function: DEBUG_LED3
 *  Set the state of LED3
 */
void DEBUG_LED3(int v);

/* Function: DEBUG_LED4
 *  Set the state of LED4
 */
void DEBUG_LED4(int v);

} // namepsace mbed

#endif

