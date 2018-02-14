%{
#include "tokens.h"
%}

DIGIT		[0-9]
ID		[a-zA-Z][a-zA-Z0-9]*
KW_NUMBER	"number"
KW_ASSET	"asset"
KW_STRING	"string"
LPAREN		"("
RPAREN		")"
LCURLY		"{"
RCURLY		"}"
WS		[ \t]*
STRING_LIT	\"(\\.|[^"\\])*\"
STMT_END	[\n;]

%% 

{KW_NUMBER}	{ return tokkw(TOKEN_KW_NUMBER); }
{KW_ASSET}	{ return tokkw(TOKEN_KW_ASSET);  }
{KW_STRING}	{ return tokkw(TOKEN_KW_STRING); }
{LPAREN}	{ return tokkw(TOKEN_LPAREN);    }
{RPAREN}	{ return tokkw(TOKEN_RPAREN);    }
{LCURLY}	{ return tokkw(TOKEN_LCURLY);    }
{RCURLY}	{ return tokkw(TOKEN_RCURLY);    }
{STMT_END}	{ return tokkw(TOKEN_STMT_END);  }
{ID}		{ return tok(TOKEN_ID, yytext);  }
{STRING_LIT}	{ return tok(TOKEN_STRING_LIT, yytext); }
{WS}		{ }


%%
