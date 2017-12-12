//
// Created by yifan on 12/12/17.
//

#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H
#include "token.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

class lexer {
public:
    token getsym(string::const_iterator &sym);
private:
    bool is_reserve(const string &word);
    const static vector<string> reserve_words;
};


#endif //COMPILER_LEXER_H
