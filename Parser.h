//
// Created by bayba on 3/23/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
enum command_Types
{
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
};

class Parser {
    public:
    explicit Parser(const std::string &fileName);
    void advance();
    bool hadMoreLines() const;
    command_Types commandType();
    std::string arg1();
    int arg2();


    private:
    std::ifstream fin;
    std::string currentCommand;

    unsigned long long typeStart{};
    unsigned long long typeEnd{};
    std::string command;

    unsigned long long segmentStart{};
    unsigned long long segmentEnd{};
    std::string segment;

    unsigned long long indexStart{};
    unsigned long long indexEnd{};
    std::string index;
};



#endif //PARSER_H
