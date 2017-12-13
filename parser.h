//
// Created by yifan on 12/13/17.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include "token.h"
#include "lexer.h"

class parser {
public:
    lexer lex;
    string statement(const token &sym);
    string var(const token &sym);
    string expr(const token &sym);
    string term(const token &sym);
    string factor(const token &sym);
    void error(const token &sym);

    parser(const lexer &l) : lex(l) {}
};


#endif //COMPILER_PARSER_H
