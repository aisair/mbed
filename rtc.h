/* mbed Microcontroller Library - rtc
 * Copyright (c) 2008, sford
 */
 
#ifndef MBED_RTC_TIME_H
#define MBED_RTC_TIME_H

#include <time.h>

#ifdef __ARMCC_VERSION

typedef unsigned long clockid_t;
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
#define CLOCK_REALTIME (clockid_t)1

#endif

/* Section: rtc
 *  Functions for manipulating the RTC (real-time clock).
 */

extern "C" {

/* Function: time
 *  Returns the number of seconds since the epoch (00:00:00 UTC,
 *  January 1, 1970), and also stores the return value in the address
 *  pointed to by timer if it is non-NULL.
 */
time_t time(time_t *timer);

/* Function: time_str
 *  Returns a pointer to a string representing the current time
 *  in human readable form, as generated by ctime()
 */
char *time_str();

/* Function: stime
 *  Sets the current time, measured in seconds since the epoch, using
 *  the value pointed to by timer.
 */
void stime(const time_t *timer);

/* Function: set_time
 *  Sets the current time, specifying year through to day
 */
void set_time(int year, int month, int day, int hour, int minute, int second);

/* Function: clock_settime
 *  Sets the time of the clock specified by clock_id, which must be
 *  CLOCK_REALTIME, according to the value of *tp.
 */
int clock_settime(clockid_t clock_id, const struct timespec *tp);

/* Function: clock_gettime
 *  Sets *tp to be the current time of the clock specified by
 *  clock_id, which must be CLOCK_REALTIME.
 */
int clock_gettime(clockid_t clock_id, struct timespec *tp);

/* Function: clock_getres
 *  Sets *tp to be the resolution of the clock specified by clock_id,
 *  which must be CLOCK_REALTIME.
 */
int clock_getres(clockid_t clock_id, struct timespec *tp);

/* Function: create_time
 *  A convenience function for constructing a time_t value.
 */
time_t create_time(int year, int month, int day, int hour, int minute, int second);

}

#endif

