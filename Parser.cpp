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


void Parser::advance() {
    std::string line;

    if (std::getline(fin, line))
    {
        if (const size_t whitespace = line.find_first_not_of(" \t\n\r");whitespace != std::string::npos)
        {
            line  = line.substr(whitespace);
        }

        if (const size_t commentPos = line.find("//"); commentPos != std::string::npos)
        {
            line.resize(commentPos);
        }
        currentCommand = line;
    }
}


bool Parser::hadMoreLines() const {
    return !fin.eof();
}

std::string Parser::commandType() const
{
    if (!currentCommand.starts_with("push"))
    {
        if (!currentCommand.starts_with("pop"))
        {
            return "C_ARITHMETIC";
        }
        return "C_POP";
    }
    return "C_PUSH";
}

std::string Parser::arg1() const
{



    if (commandType() == "C_ARITHMETIC")
    {
        return currentCommand.substr(pos1);
    }

    if (commandType() == "C_PUSH" || commandType() == "C_POP")
    {
        pos1 = currentCommand.find(' ', pos1);
    }
    return "Invalid!";
}

std::string Parser::arg2()
{

    return "";
}