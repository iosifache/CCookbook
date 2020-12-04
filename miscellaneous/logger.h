#ifndef _LOGGER_H_

#define _LOGGER_H_

#include <stdio.h>

/*
 * If a variable is set, print a new line terminated, formatted string
 */
#define LOGGER(enable, format, ...) \
    if (enable){ \
        printf(format "\n", __VA_ARGS__); \
        fflush(stdout); \
    }\

#endif