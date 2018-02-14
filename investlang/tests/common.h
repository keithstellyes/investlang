#ifndef TESTS_COMMON_H
#define TESTS_COMMON_H

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "tokens.h"

#define NO_MORE_TOKENS TOKEN_RESERVED
#define streq(a, b) (strcmp(a,b)==0)
#define assert_printf(cond, args...) do {\
    if(!(cond)) {\
        fprintf(stderr, "Assertion failed!\n");\
        fprintf(stderr, args);\
        fprintf(stderr, "\n");\
        exit(-1);\
    }\
}while(0);

#define assertstr(expect, actual) assert_printf(streq(expect,actual), "Expected: %s"\
    "\nActual: %s", expect, actual)

#define asserttoktype(expect, actual) assert_printf(expect==actual, \
    "Expected: %d\nActual:%d", expect, actual)

void do_tests(FILE *in_file, ...);

#define TESTS_FROM_FILE(f, args...) int main(int argc, char **argv) {\
    do_tests(f, args); return 0; }

#define TESTS(s, args...) TESTS_FROM_FILE(fmemopen(s, strlen(s)+1, "r"), args)

#endif
