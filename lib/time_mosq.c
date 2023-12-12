/*
Copyright (c) 2013-2020 Roger Light <roger@atchoo.org>

All rights reserved. This program and the accompanying materials
are made available under the terms of the Eclipse Public License 2.0
and Eclipse Distribution License v1.0 which accompany this distribution.

The Eclipse Public License is available at
   https://www.eclipse.org/legal/epl-2.0/
and the Eclipse Distribution License is available at
  http://www.eclipse.org/org/documents/edl-v10.php.

SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause

Contributors:
   Roger Light - initial implementation and documentation.
*/

#include "config.h"

#ifdef __APPLE__
#include <mach/mach.h>
#include <mach/mach_time.h>
#endif

#ifdef WIN32
#if !(defined(_MSC_VER) && _MSC_VER <= 1500)
#  define _WIN32_WINNT _WIN32_WINNT_VISTA
#endif
#  include <windows.h>
#else
#  include <unistd.h>
#endif
#include <time.h>

#include "mosquitto.h"
#include "time_mosq.h"

time_t mosquitto_time(void)
{
#ifdef WIN32
	return GetTickCount64()/1000;
#elif _POSIX_TIMERS>0 && defined(_POSIX_MONOTONIC_CLOCK)
	struct timespec tp;

#ifdef CLOCK_BOOTTIME
	clock_gettime(CLOCK_BOOTTIME, &tp);
#else
	clock_gettime(CLOCK_MONOTONIC, &tp);
#endif
	return tp.tv_sec;
#elif defined(__APPLE__)
	static mach_timebase_info_data_t tb;
    uint64_t ticks;
	uint64_t sec;

	ticks = mach_absolute_time();

	if(tb.denom == 0){
		mach_timebase_info(&tb);
	}
	sec = ticks*tb.numer/tb.denom/1000000000;

	return (time_t)sec;
#else
	return time(NULL);
#endif
}


//What does time(NULL) return?
//time(NULL) returns the current time in seconds since 1970-01-01 00:00:00 +0000 (UTC)

//What do I need to do to return the time in milliseconds?
//To return the time in milliseconds, you need to multiply the time in seconds by 1000

//But since the original time is in seconds, converting it to milliseconds will result in a loss of precision.
//How do I avoid this loss of precision?
//To avoid this loss of precision, you need to use a data type that can hold a larger number of bits than the time in seconds

//What data type can hold a larger number of bits than the time in seconds?
//The data type that can hold a larger number of bits than the time in seconds is the data type long long

//Can you update the above code to always return the time in milliseconds using the data type long long? Show the updated code below
//The updated code is shown below.