//
// Created by bayba on 3/23/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>


class Parser {
    public:
    explicit Parser(std::string &fileName);
    void advance();
    bool hadMoreLines() const;

    std::string commandType();
    std::string argOne();
    int argTwo() const;


    private:
    std::ifstream fin;
    std::map<std::string, std::string> stackCommands;
    std::string currentCommand;
};



#endif //PARSER_H
