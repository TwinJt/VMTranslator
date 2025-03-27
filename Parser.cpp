//
// Created by bayba on 3/23/2025.
//

#include "Parser.h"

Parser::Parser(std::string &fileName) {
    fin.open(fileName);

    if (!fin.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
    }

    stackCommands["push"] = "C_PUSH";
    stackCommands["pop"] = "C_POP";

    stackCommands["add"] = "C_ARITHMETIC";
    stackCommands["sub"] = "C_ARITHMETIC";
    stackCommands["neg"] = "C_ARITHMETIC";
    stackCommands["eq"] = "C_ARITHMETIC";
    stackCommands["gt"] = "C_ARITHMETIC";
    stackCommands["lt"] = "C_ARITHMETIC";
    stackCommands["and"] = "C_ARITHMETIC";
    stackCommands["not"] = "C_ARITHMETIC";
    stackCommands["or"] = "C_ARITHMETIC";

}

void Parser::advance() {
    std::string line;

    bool commandFound = false;

    while (!commandFound && std::getline(fin, line)) {

        if (const unsigned long comment = line.find("//"); comment != std::string::npos) {
            line.erase(comment, line.length() - comment);
        }
        commandFound = !line.empty();
    }
    currentCommand = line;
}

bool Parser::hadMoreLines() const {
    if (!fin.eof()) {
        return true;
    }
    return false;
}

std::string Parser::commandType() {
    return
}

std::string Parser::argOne(){
    return arg1;
}

int Parser::argTwo() const{
    return arg2;
}
