cmake_minimum_required(VERSION 3.8)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp lexer.cpp lexer.h token.cpp token.h parser.cpp parser.h)
add_executable(Compiler ${SOURCE_FILES})