#ifndef _STRINGS_H

#define _STRINGS_H

/*
 * Computes djb2 (non-cryptographic) hash, created by Dan Bernstein
 * 
 * Source: http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned long djb2(char *string);

#endif