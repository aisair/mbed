/* mbed Microcontroller Library - stackheap
 * Copyright (c) 2007-2008, sford
 */
 
#ifndef MBED_STACKHEAP_H
#define MBED_STACKHEAP_H

namespace mbed {

/* Section: stackheap
 *  Useful functions for seeing what is going on with the stack and heap
 */

/* Function: code_base
 *  Return the address of the fixed base of the code region
 */
int code_base();

/* Function: code_limit
 *  Return the address of the top of the code region
 */
int code_limit();

/* Function: rw_base
 *  Return the address of the fixed base of the rw region
 */
int rw_base();

/* Function: rw_limit
 *  Return the address of the top of the rw region
 */
int rw_limit();

/* Function: heap_base
 *  Return the address of the fixed base of the heap
 */
int heap_base();

/* Function: heap_limit
 *  Return the address of the current top of the heap
 */
int heap_limit();

/* Function: stack_base
 *  Return the address of the fixed base of the stack
 */
int stack_base();

/* Function: stack_limit
 *  Return the address of the current top of the stack
 */
//int stack_limit();

/* Function: code_size
 *  Return the size of the code region
 */
int code_size();

/* Function: rw_size
 *  Return the size of the rw region
 */
int rw_size();

/* Function: heap_size
 *  Return the current size of the heap pool allocated
 */
int heap_size();

/* Function: stack_size
 *  Return the current size of the stack used
 */
//int stack_size();


inline int stack_limit() {
	return __current_sp();
}

inline int stack_size() {
	return stack_base() - stack_limit();
}

} // namespace mbed

#endif

