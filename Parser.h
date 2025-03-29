//
// Created by bayba on 3/23/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

enum commands
{
    C_PUSH,
    C_POP,
    C_ARITHMETIC
};

class Parser
{
public:
    explicit Parser(std::string &fileName);
    void advance();

    bool hadMoreLines() const;
    commands commandType() const;

    std::string arg1() const;
    std::string arg2();


private:
    std::ifstream fin;
    std::string currentCommand;
};



#endif //PARSER_H
