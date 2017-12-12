#include "token.h"

const unordered_map<string, token_type> token_type::non_identifier_types {
        {"begin", token_type("BEGINSY", 1)},
        {"end", token_type("ENDSY", 2)},
        {"if", token_type("IFSY", 3)},
        {"then", token_type("THENSY", 4)},
        {"else", token_type("ELSESY", 5)},
        {"+", token_type("PLUSSY", 22)},
        {"-", token_type("MINUSSY", 23)},
        {"*", token_type("STARSY", 24)},
        {"/", token_type("DIVISY", 25)},
        {"(", token_type("LPARSY", 26)},
        {")", token_type("RPARSY", 27)},
        {",", token_type("COMMASY", 28)},
        {";", token_type("SEMISY", 29)},
        {":", token_type("COLONSY", 30)},
        {":=", token_type("ASSIGNSY", 31)},
        {"=", token_type("EQUSY", 32)}
};

const token_type token_type::comment("COMMENT", 0);
const token_type token_type::error("ERROR", -1);