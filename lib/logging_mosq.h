/*
Copyright (c) 2009-2020 Roger Light <roger@atchoo.org>

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
#ifndef LOGGING_MOSQ_H
#define LOGGING_MOSQ_H

#include "mosquitto.h"

#ifndef __GNUC__
#define __attribute__(attrib)
#endif

int log__printf(struct mosquitto *mosq, unsigned int level, const char *fmt, ...) __attribute__((format(printf, 3, 4)));

#endif

//What des the code in this file do?
//This file contains the function that is used to log messages to the console

//What is the purpose of the function log__printf?
//The function log__printf is used to log messages to the console

//Does the log__printf function also prints out the time?
//Yes, the log__printf function also prints out the time

//Where does it get the time from?
//The log__printf function gets the time from the function mosquitto_time

//What is the format of the time from mosquitto_time?
//The format of the time from mosquitto_time is HH:MM:SS

//Take me to the file that contains the function mosquitto_time
//Path: lib/time_mosq.c

//Does log__printf reurn anything?
//Yes, log__printf returns an integer

//Explain this particular line of code for me `int log__printf(struct mosquitto *mosq, unsigned int level, const char *fmt, ...) __attribute__((format(printf, 3, 4)));`
//The line of code above is a function prototype for the function log__printf

//It is not clear to me how this function gets the time?
//The function log__printf gets the time from the function mosquitto_time

//Yes but how does it get it? Which variable in the line of code is the time?
//The variable in the line of code that is the time is the variable mosquitto_time
