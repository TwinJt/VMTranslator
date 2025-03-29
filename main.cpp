#include "Parser.h"
int main() {
    std::string fileName = "C:\\Users\\bayba\\CLionProjects\\VM Translator\\SimpleAdd.vm";
    Parser parser(fileName);
    while (parser.hadMoreLines())
    {
        parser.advance();

        if (parser.commandType() == C_ARITHMETIC)
        {
            std::cout << parser.arg1() << std::endl;
        }
        else if (parser.commandType() == C_PUSH || parser.commandType() == C_POP)
        {
            std::cout << parser.arg1() << std::endl;
            std::cout << parser.arg2() << std::endl;
        }
    }
    return 0;
}