#include <iostream>
#include "token.h"
#include "lexer.h"

int main() {
    string s = "BEGIN a := 5; b := 2; a = a + b; END if a = 2 then b = 1 else b = b * 1113 /* 123 */";
    lexer l;
    auto it = s.cbegin();
    while (it != s.end()) {
        token t = l.getsym(it);
        std::cout << t.name + " " + t.type.type_name << std::endl;
    }
    return 0;
}