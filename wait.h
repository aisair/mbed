/* mbed Microcontroller Library - wait
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_WAIT_H
#define MBED_WAIT_H

namespace mbed {

/* Section: wait
 *  Useful waiting around functions
 */

/* Function: wait
 *  Wait the specified number of seconds (float)
 */
void wait(float s);

/* Function: wait_ms
 *  Wait the specified number of milli-seconds (int)
 */
void wait_ms(int ms);

/* Function: wait_us
 *  Wait the specified number of micro-seconds (int)
 */
void wait_us(int us);

}

#endif