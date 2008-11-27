/* mbed Microcontroller Library - Debug
 * Copyright (c) 2007-2008, sford
 */

#ifndef MBED_DEBUG_H
#define MBED_DEBUG_H

namespace mbed {

/* Section: debug
 *  Error reporting and debugging functions 
 */

// As seen by user, for documentation purposes only
#if 0 
/* Function: ERROR
 *  Report a fatal runtime error. Attempts to report the specified error message through the
 * USB serial port, then dies with a fatal runtime error (siren lights)
 *
 * Variables:
 *  format - printf-style format string, followed by associated variables
 */
void ERROR(const char* format, ...);
#endif 

#define ERROR(FMT, ...) mbed_error(__FILE__, __LINE__, FMT, ##__VA_ARGS__) 
void mbed_error(const char* file, int line, const char* fmt=0, ...) __attribute__((noreturn));

// Internal use for "official" errors
void mbed_error(const char* file, int line, int code, const char* fmt=0, ...) __attribute__((noreturn));

// As seen by user, for documentation purposes only
#if 0
/* Function: ASSERT
 *  Assert a condition is true, and report a fatal runtime error on failure. If
 * the condition is true (non-zero), the function simply returns. If the
 * condition is false (0), it attempts to report the specified error message through the
 * USB serial port, then dies with a fatal runtime error (siren lights)
 *
 * Variables:
 *  condition - The condition variable to be tested. 0 causes an error to be reported
 *  format - printf-style format string, followed by associated variables
 */
void ASSERT(int condition, const char* fmt = 0, ...);
#endif

#define ASSERT(COND, ...) (COND ? (void)0 : mbed_error(__FILE__, __LINE__, ##__VA_ARGS__))

// As seen by user, for documentation purposes only
#if 0 
/* Function: DEBUG
 *  Report a debug message. Attempts to report the specified 
 * debug message through the USB serial port.
 *
 * Variables:
 *  format - printf-style format string, followed by associated variables
 */
void DEBUG(const char* format, ...);
#endif

// Actual macro and prototype
#define DEBUG(...) mbed_debug(__FILE__, __LINE__, __VA_ARGS__)
void mbed_debug(const char* file, int line, const char* format, ...);


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

