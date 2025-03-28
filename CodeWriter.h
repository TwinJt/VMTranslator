//
// Created by bayba on 3/23/2025.
//

#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <format>

#include "Parser.h"


class CodeWriter {
public:
    explicit CodeWriter(std::string &fileName);
    void writeArithmetic(const std::string &command);
    void writePushPop( std::string& segment, std::string& i);

private:
    std::string baseName;
    std::ofstream outFile;
    std::string line_Num;
};



#endif //CODEWRITER_H
