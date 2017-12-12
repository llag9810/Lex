#include "lexer.h"

using std::string;
using std::unordered_map;

const vector<string> lexer::reserve_words =
        {"begin", "end", "if", "then", "else", "int", "float", "main"};

token lexer::getsym(string::const_iterator &sym) {
    while (std::isspace(sym[0])) {
        ++sym;
    }
    char c = sym[0];
    if (std::isalpha(sym[0])) {
        string token_name;
        while (std::isalpha(sym[0]) || std::isdigit(sym[0])) {
            token_name += sym[0];
            ++sym;
        }
        std::transform(token_name.begin(), token_name.end(), token_name.begin(), tolower);

        if (is_reserve(token_name)) {
            return token(token_name, token_type::non_identifier_types.at(token_name));
        }

        return token(token_name, token_type("IDSY", 20));
    } else if (std::isdigit(sym[0])) {
        string token_name;
        while (std::isdigit(sym[0])) {
            token_name += sym[0];
            ++sym;
        }
        return token(token_name, token_type("INTSY", 21));
    } else if (std::ispunct(sym[0]) && sym[0] != '/' && sym[0] != ':') {
        string token_name = string(1, sym[0]);
        ++sym;
        return token(token_name, token_type::non_identifier_types.at(token_name));
    } else if (sym[0] == '/') {
        if (sym[1] == '*') {
            ++sym;
            while (*++sym != '*' || sym[1] != '/') {}
            sym += 2;
            return token("", token_type::comment);
        } else {
            ++sym;
            return token("/", token_type::non_identifier_types.at("/"));
        }
    } else if (sym[0] == ':') {
        if (*++sym == '=') {
            ++sym;
            return token(":=", token_type::non_identifier_types.at(":="));
        } else {
            ++sym;
            return token(":", token_type::non_identifier_types.at(":"));
        }
    } else {
        return token("error", token_type::error);
    }
}

bool lexer::is_reserve(const string &word) {
    bool result = std::find(reserve_words.cbegin(), reserve_words.cend(), word) != reserve_words.cend();
    return result;
}
