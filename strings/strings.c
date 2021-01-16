#include "string.h"

unsigned long djb2(char *string){

    unsigned long hash = 5381;
    int c;

    while ((c = *string++))
        hash = ((hash << 5) + hash) + c;

    return hash;

}