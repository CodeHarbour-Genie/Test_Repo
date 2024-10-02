#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>

#define MEOWMEOW_VERSION "0.1.0"
#define CMD_MEOW "meow"
#define CMD_UMMEOW "unmeow"
#define LOGS_PATH "./debug_logs.txt"

typedef enum {
    QUIET = 0,
    TERSE = 1,
    CHATTY = 2,
} verbosity_t;

typedef struct options {
    FILE *in_stream;
    FILE *out_stream;
    FILE *logs_stream;
    verbosity_t verbose;
} options_t;

#define OPTIONS_INT { stdin, stdout, stdout, QUIET } 

#endif