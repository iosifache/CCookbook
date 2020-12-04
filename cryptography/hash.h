#ifndef _HASH_H

#define _HASH_H

#include "../miscellaneous/data_types.h"

#define MD5_LENGTH_IN_BYTES 16

/*
 * Compute MD5 hash for a given string and place it into an already allocted
 * buffer
 */
int md5(const char *string, uint length, char *hash);

#endif