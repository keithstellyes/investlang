#include <stdio.h>
#include "lex.yy.h"
#include "tokens.h"

int main(int argc, char **argv)
{
    yyset_in(stdin);
    yyset_out(stdout);
    yylex();
    token t = last_token;
    yylex();
    yylex();
    printf("%d", t.type);
    if(t.text != NULL) printf("%s", t.text);
    printf("\n");
}
