#include <iostream>
#include "Parser.h"
#include "CodeWriter.h"

int main() {
    std::string fileName = "/Users/jarrett/Desktop/HELLO.txt";
    Parser parser(fileName);
    parser.advance();
    std::cout << parser.commandType() << std::endl;
    std::string m = parser.argOne();
    std::cout << CodeWriter::writeArithmetic(m);

    return 0;
}