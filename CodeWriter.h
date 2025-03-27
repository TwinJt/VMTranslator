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
    CodeWriter(std::string &fileName);
    void writeArithmetic(const std::string &command);

    private:
    std::string baseName;
    std::ofstream outFile
;
};



#endif //CODEWRITER_H
