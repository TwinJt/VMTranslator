//
// Created by bayba on 3/23/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class Parser
{
public:
    Parser(std::string &fileName);
    void advance();

    bool hadMoreLines() const;
    std::string commandType() const;

    std::string arg1() const;
    std::string arg2();


private:
    std::ifstream fin;
    std::string currentCommand;
};



#endif //PARSER_H
