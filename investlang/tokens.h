#ifndef TOKENS_H
#define TOKENS_H

typedef enum token_type {
	// a value that shall never be returned by the lexer.
	TOKEN_RESERVED   = -1,
	TOKEN_KW_NUMBER  = 0, 
	TOKEN_KW_ASSET   = 1, 
	TOKEN_KW_STRING  = 2,
	TOKEN_STRING_LIT = 3,
	TOKEN_ID         = 4,
	TOKEN_LPAREN     = 5, 
	TOKEN_RPAREN     = 6, 
	TOKEN_LCURLY     = 7, 
	TOKEN_RCURLY     = 8, 
	TOKEN_STMT_END   = 9, 
} token_type;

typedef struct token {
	token_type type;
	char *text;
} token;

token last_token;

int tokkw(token_type type);
int tok(token_type type, char *text);
#define token_type_hastext(type) (type >= TOKEN_STRING_LIT && type <= TOKEN_ID)

#endif
