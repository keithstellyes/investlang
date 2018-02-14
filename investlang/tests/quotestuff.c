#include "common.h"

TESTS("print \"\\\"Hi!\\\"\"\n",
    TOKEN_ID, "print",
    TOKEN_STRING_LIT, "\\\"Hi!\\\"",
    TOKEN_STMT_END, NO_MORE_TOKENS)
