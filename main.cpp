#include <iostream>
#include <fstream>
#include "token.h"
#include "lexer.h"
#include "parser.h"

int main() {
    string s;
    std::fstream fs;


    fs.open("test.txt");
    while (fs) {
        s += fs.get();
    }
    s = s.substr(0, s.length() - 1);
    auto it = s.cbegin();
    lexer l(it);

    while (it != s.cend()) {
        token t = l.getsym();
        std::cout << t.name + "\t" + t.type.type_name << std::endl;
    }

    fs.open("test2.txt");
    s = "";
    while (fs) {
        s += fs.get();
    }
    auto it2 = s.cbegin();
    lexer l2(it2);
    parser p(l2);
    p.statement(l2.getsym());
    return 0;
}