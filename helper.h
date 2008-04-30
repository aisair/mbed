/* mbed Microcontroller Library - Helper
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_HELPER_H
#define MBED_HELPER_H

/* Section: helper
 *  A collection of useful functions not found in the standard C libraries
 */
 
namespace mbed {

/* Function: min
 *  Return the minimum of two integers
 */
int min(int a, int b);

/* Function: min
 *  Return the minimum of two floating-point numbers
 */
float min(float a, float b);

/* Function: max
 *  Return the maximum of two integers
 */
int max(int a, int b);

/* Function: max
 *  Return the maximum of two floating-point numbers
 */
float max(float a, float b);

/* Function: clamp
 *  Return the value, clamped between a minimum and maximum integer value
 */
int clamp(int value, int minimum, int maximum);

/* Function: clamp
 *  Return the value, clamped between a minimum and maximum floating-point value
 */
float clamp(float value, float minimum, float maximum);

} // namespace mbed

#endif

