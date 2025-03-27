//
// Created by bayba on 3/23/2025.
//

#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <iostream>



class CodeWriter {
public:
    static std::string writeArithmetic(const std::string &command);
    std::string writePushPop(std::string command, std::string segment, int i);
};



#endif //CODEWRITER_H
