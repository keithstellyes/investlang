#ifndef PARSER_H
#define PARSER_H
/*
 * 2018-02-14 (PST)
 * I WILL PROBABLY USE C++ FOR THE PARSER!
 */
#include "tokens.h"
#include "lex.yy.h"
// the parser uses the lexer generated by flex
typedef enum statement_type_t {
    function_call,
    meta_call,
    var_declaration,
    var_assignment
} statement_type_t;

typedef enum expr_type_t {
    string_lit
} expr_type_t;

typedef identifier_t char*;

typedef struct expr_t {
    expr_type_t type;

} expr_t;

typedef struct function_call_t {
    identifier_t callee;

} function_call_t;

typedef struct statement_t {
    statement_type type;
    union {
        // function_call, meta_call
        identifier callee,
        
    }
} statement_t;

typedef struct parser_opts_t {
    // the input file for the parser
    FILE *input_file;
} parser_opts_t;

void init_parser(parser_opts_t *opts);

void p_statement();

#endif
