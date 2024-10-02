#include <errno.h>
#include <string.h>

#include "mmencode.h"
#include "table.h"

#define LO_MASK 0x000f
#define HI_MASK 0x00f0
#define BITS_IN_NIBBLE 4

int mm_encode(FILE *src, FILE *dst, FILE *logs) 
{
    /*START:adding logs*/
    char logsBuff[50];
    sprintf(logsBuff,"Enter Function:mm_encode, Line:%d\n", __LINE__);
    fputs(logsBuff, logs);
    /*END:adding logs*/

    char buf[BUFSIZ]; // BUFSIZE is 8192 in stdio.h 
    unsigned char hi; // char type stores the integer value of the ASCII code, instead of the code itself 
    unsigned char lo;
    int i;

    char *tbl[] = ENCODE_INIT; // array of string

    if (!src || !dst) {
        errno = EINVAL; // in errno.h
        return -1;
    }

    while(!feof(src)) {
        
        if(!fgets(buf, sizeof(buf), src)) {
            break;
        }

        for(i=0; i<strlen(buf); i++) {
            lo = (buf[i] & LO_MASK); // bitwise AND operation on two numbers
            hi = (buf[i] & HI_MASK) >> BITS_IN_NIBBLE;  // bitsise AND, right shift operations
            fputs(tbl[hi], dst);
            fputs(tbl[lo], dst);
        }
    }
    fclose(dst); // need close or not? 

    /*END:adding logs*/
    sprintf(logsBuff,"Exit Function:mm_encode, Line:%d\n", __LINE__);
    fputs(logsBuff, logs);
    /*END:adding logs*/

    return 0;
}