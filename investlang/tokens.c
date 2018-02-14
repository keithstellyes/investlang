#include <stdlib.h>
#include <string.h>

#include "tokens.h"

int tokkw(token_type type)
{
	last_token.type = type;
	last_token.text = NULL;
	return 0;
}

int tok(token_type type, char *text)
{
	last_token.type = type;
	last_token.text = malloc(strlen(text) + sizeof('\0'));
	strcpy(last_token.text, text);
	return 0;
}
