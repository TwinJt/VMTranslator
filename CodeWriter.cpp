//
// Created by bayba on 3/23/2025.
//

#include "CodeWriter.h"


CodeWriter::CodeWriter(std::string& fileName)
{
    const unsigned long long slash = fileName.find_last_of("/\\");
    const unsigned long long fileNameStart = (slash == std::string::npos) ? 0 : slash + 1;

    const unsigned long long extention = fileName.find_last_of('.');
    if (extention == std::string::npos || extention < fileNameStart)
    {
        baseName = fileName.substr(fileNameStart);
    }
    baseName = fileName.substr(fileNameStart, extention - fileNameStart);

    outFile = std::ofstream(std::format("{}.asm", baseName));

    outFile << "//SP"
    "\n@256"
    "\nD=A"

    "\n@SP"
    "\nM=D"
    "\n";
}
void CodeWriter::writePushPop(command_Types, std::string &segment, std::string &i)
{
    if constexpr (C_PUSH)
    {
        std::cout << segment;
        if (segment == "constant")
        {
            outFile << std::format("//push {} {}", segment, i);
            outFile << std::format("\n@{}", i);
            outFile << "\nD=A"

            "\n@SP"
            "\nA=M"
            "\nM=D"

            "\n@SP"
            "\nM=M+1"
            "\n";
        }
    }
}
void CodeWriter::writeArithmetic(const std::string &command)
{
    if (command == "add")
    {
        outFile << "//add"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nM=D+M"
        "\n";
    }
    if (command == "sub")
    {
        outFile << "//sub"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nM=D-M"
        "\n";
    }
    if (command == "neg")
    {
        outFile << "//neg"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nM=D-M"
        "\n";
    }
    if (command == "eq")
    {
        outFile << "//eq"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nD=D-M"
        "\n@EQ_{}"
        "\nD;JEQ"
        "\n@END"
        "\n0;JMP"

        "\n(EQ)"
        "\n@SP"
        "\nA=M-1"
        "\nM=-1"

        "\n(END)"
        "\n@SP"
        "\nA=M-1"
        "\nM=0"
        "\n";
    }
    if (command == "gt")
    {
        outFile << "//gt"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nD=M-D"

        "\n@GT"
        "\nD;JGT"

        "\n@END"
        "\n0;JMP"

        "\n(GT)"
        "\n@SP"
        "\nA=M-1"
        "\nM=-1"

        "\n(END)"
        "\nA=M-1"
        "\nM=0";
    }
    if (command == "lt")
    {
        outFile << "//lt"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nD=M-D"

        "\n@LT"
        "\nD;JLT"

        "\n@END"
        "\n0;JMP"

        "\n(LT)"
        "\n@SP"
        "\nA=M-1"
        "\nM=-1"

        "\n(END)"
        "\n@SP"
        "\nA=M-1"
        "\nM=0"
        "\n";
    }
    if (command == "and")
    {
        outFile << "//and"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nM=M&D"
        "\n";
    }
    if (command == "or")
    {
        outFile << "//or"
        "\n@SP"
        "\nM=M-1"
        "\nA=M"
        "\nD=M"
        "\nA=A-1"
        "\nM=M|D"
        "\n";
    }
    if (command == "not")
    {
        outFile << "//not"
        "\n@SP"
        "\nA=M-1"
        "\nM=!M"
        "\n";
    }
}





