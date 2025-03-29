//
// Created by bayba on 3/23/2025.
//

#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <format>



class CodeWriter {
public:
    explicit CodeWriter(std::string &fileName);
    void writeArithmetic(std::string command);

private:
    std::ofstream outFile;
    std::string baseName;
};



#endif //CODEWRITER_H
