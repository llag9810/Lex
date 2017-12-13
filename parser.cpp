#include <iostream>
#include "parser.h"
#include "lexer.h"

string parser::statement(const token &sym1) {
    string debug;
    token sym = sym1;
    while (sym.name == ";") {
        sym = lex.getsym();
    }

    if (sym.type == token_type::non_identifier_types.at("if")) {
        debug += "if";
        token new_sym = lex.getsym();
        debug += expr(new_sym);
        new_sym = lex.getsym();
        if (!(sym.type == token_type::non_identifier_types.at("then"))) {
            error(new_sym);
        } else {
            debug += "else";
            new_sym = lex.getsym();
            debug += statement(new_sym);
        }
    } else {
        debug += var(sym);
        auto &it = *lex.sym_p;
        it--;
        it--;
        token new_sym = lex.getsym();
        string s = new_sym.name;
        if (new_sym.name != ":=") {
            error(new_sym);
        } else {
            debug += " := ";
            new_sym = lex.getsym();
            debug += expr(new_sym);
        }
    }
    std::cout << debug + " is a statement.\n";
    return debug;
}

string parser::var(const token &sym1) {
    string debug;
    token sym = sym1;
    while (sym.name == ";") {
        sym = lex.getsym();
    }
    if (!(sym.type == token_type("IDSY", 20))) {
        error(sym);
    } else {
        debug += sym.name;
        token new_sym = lex.getsym();
        if (new_sym.name == "[") {
            new_sym = lex.getsym();
            debug += expr(new_sym);
            new_sym = lex.getsym();
            if (new_sym.name != "]") {
                error(new_sym);
            }
            debug += "]";
        }
    }

    std::cout << debug +" is a variable.\n";
    return debug;
}

string parser::expr(const token &sym1) {
    string debug;
    token sym = sym1;
    while (sym.name == ";") {
        sym = lex.getsym();
    }
    debug += term(sym);
    --*lex.sym_p;
    token new_sym = lex.getsym();
    while (new_sym.name == "+" || new_sym.name == "-") {
        debug += new_sym.name;
        new_sym = lex.getsym();
        debug += term(new_sym);
    }

    std::cout << debug + " is an expression" << std::endl;
    return debug;
}

string parser::term(const token &sym1) {
    string debug;
    token sym = sym1;
    while (sym.name == ";") {
        sym = lex.getsym();
    }
    debug += factor(sym);
    --*lex.sym_p;
    token new_sym = lex.getsym();
    while (new_sym.name == "*" || new_sym.name == "/") {
        debug += new_sym.name;
        new_sym = lex.getsym();
        debug += factor(new_sym);
    }
    std::cout << debug + " is a term.\n" << std::endl;
    return debug;
}

string parser::factor(const token &sym1) {
    string debug;
    token sym = sym1;
    while (sym.name == ";") {
        sym = lex.getsym();
    }
      if (sym.name == "(") {
          debug += "(";
          token new_sym = lex.getsym();
          debug += expr(new_sym);
          new_sym = lex.getsym();
          if (sym.name != ")") {
              error(new_sym);
          }
          debug += ")";
      } else {
          --(*lex.sym_p);
          token new_sym = lex.getsym();
          debug += var(new_sym);
      }
    std::cout << debug + " is a factor. \n" << std::endl;
    return debug;
}

void parser::error(const token &sym) {
    //std::cout << sym.name + " error. \n" << std::endl;
}

