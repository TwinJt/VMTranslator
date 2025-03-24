//
// Created by bayba on 3/23/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


class Parser {
    public:
    Parser(std::string &fileName);

    private:
    std::ifstream fin;
    std::stringstream ss;

};



#endif //PARSER_H
