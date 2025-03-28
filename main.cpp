#include "Parser.h"

int main() {
    std::string fileName = R"(C:\Users\bayba\CLionProjects\VM Translator\vmtest.vm)";
    Parser parser(fileName);
    while (parser.hadMoreLines())
    {
        parser.advance();
        std::cout << parser.arg1() << std::endl;
    }
    return 0;
}