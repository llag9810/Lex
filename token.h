#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class token_type {
public:
    string type_name;
    int type_code;

    token_type(const string &type_name, int type_code)
            : type_name(type_name), type_code(type_code) {}

    token_type(const token_type &rhs)
            : type_name(rhs.type_name), type_code(rhs.type_code) {}

    bool operator==(const token_type &rhs) const {
        return type_code == rhs.type_code;
    }

    const static unordered_map<string, token_type> non_identifier_types;
    const static token_type comment;
    const static token_type error;
};

class token {
public:
    string name;
    const token_type type;

    token(const string &name, const token_type &type)
            : name(name), type(type) {}
};


#endif //COMPILER_TOKEN_H
