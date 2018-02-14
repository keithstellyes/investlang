#include "common.h"

TESTS(
"print \"Hello, World!\"\n", 
TOKEN_ID, "print", 
TOKEN_STRING_LIT, "Hello, World!", 
TOKEN_STMT_END, NO_MORE_TOKENS);
