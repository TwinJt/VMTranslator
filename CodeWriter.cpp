//
// Created by bayba on 3/23/2025.
//

#include "CodeWriter.h"

std::string CodeWriter::writeArithmetic(const std::string &command) {
    if (command == "add") {
        return "@SP\n"
                    "M=M-1\n"
                   "A=M\n"
                   "D=M\n"
                   "A=A-1\n"
                   "M=D+M\n";
    }

    if (command == "sub") {
        return "@SP"
       "M=M-1"
       "A=M"
       "D=M"
       "A=A-1"
       "M=D-M";
    }
    if (command == "neg") {
        return "@SP"
       "A=M-1"
       "D=M"
       "M=-D";
    }
    if (command == "eq") {
        return "@EQ"
       "D;JEQ"
       "@END"
       "0;JMP"
       "(EQ)"
       "@SP"
       "A=M-1"
       "M=-1"
       "(END)"
       "@SP"
       "A=M-1"
       "M=0";
    }
    if (command == "gt") {
        return "@SP"
              "M=M-1"
              "A=M"
              "D=M"
              "A=A-1"
              "D=M-D"
              "@GT"
              "D;JGT"
              "@END"
              "0;JMP"
              "(GT)"
              "@SP"
              "A=M-1"
              "M=-1"
              "(END)"
              "A=M-1"
              "M=0";
    }
    return " ";
}
