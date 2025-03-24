//
// Created by bayba on 3/23/2025.
//

#include "Parser.h"

Parser::Parser(std::string &fileName) {
    fin.open(fileName);

    if (!fin.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
    }


}

