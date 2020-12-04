#ifndef _STRINGS_H

#define _STRINGS_H

/*
 *  Compute djb2 (non-cryptographic) hash, created by Dan Bernstein
 */
unsigned long djb2(char *string){

    unsigned long hash = 5381;
    int c;

    while ((c = *string++))
        hash = ((hash << 5) + hash) + c;

    return hash;

}

#endif