//
// Created by bayba on 3/23/2025.
//

#include "Parser.h"
#include <string_view>

Parser::Parser(const std::string &fileName) {
    fin.open(fileName);

    if (!fin.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
    }


}

void Parser::advance() {
    std::string line;

    bool commandFound = false;

    while (!commandFound && std::getline(fin, line)) {
        if (const unsigned long long comment = line.find("//"); comment != std::string_view::npos) {
            line.erase(comment, line.length() - comment );
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

command_Types Parser::commandType()
{
    typeStart = currentCommand.find_first_not_of(" \t");
    typeEnd = currentCommand.find_first_of(" \t", typeStart);

    command = currentCommand.substr(typeStart, typeEnd - typeStart);
    if (command != "push")
    {
        if (command != "pop")
        {
            return C_ARITHMETIC;
        }
        return C_POP;
    }
    return C_PUSH;
}

std::string Parser::arg1()
{
    if (const int currentType = commandType(); currentType != C_ARITHMETIC)
    {
        segmentStart = currentCommand.find_first_not_of(" \t", typeEnd);
        segmentEnd = currentCommand.find_first_of(" \t", segmentStart);
        segment = currentCommand.substr(segmentStart, segmentEnd - segmentStart);
        return segment;
    }
    return command;
}

int Parser::arg2()
{
    indexStart = currentCommand.find_first_not_of(" \t", segmentEnd);
    indexEnd = currentCommand.find_first_of(" \t", indexStart);
    index = currentCommand.substr(indexStart, indexEnd - indexStart);
    return stoi(index);
}