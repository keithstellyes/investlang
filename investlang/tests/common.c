#include <stdarg.h>

#include "lex.yy.h"
#include "tests/common.h"

// to test print "Hello, World!"
// do_tests(input_file, TOKEN_IDENTIFIER, "print", 
//          STRING_LITERAL, "Hello, World!", TOKENS)
void do_tests(FILE *in_file, ...)
{
    yyset_in(in_file);

    va_list args;
    va_start(args, in_file);
    token_type expected = va_arg(args, token_type);
    while(expected != NO_MORE_TOKENS) {
       yylex();
       asserttoktype(expected, last_token.type);
       if(token_type_hastext(expected)) {
           char *text = va_arg(args, char*);
	   if(expected == TOKEN_STRING_LIT) {
               last_token.text++;
	       char *last_token_end = last_token.text + strlen(last_token.text);
	       while(*(last_token_end) != '"') last_token_end--;
	       assert(last_token_end > last_token.text);
	       *last_token_end = '\0';
	   }
	   assertstr(text, last_token.text);
       }
       expected = va_arg(args, token_type);
    }
    va_end(args);
}
