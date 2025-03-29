#include "CodeWriter.h"
#include "Parser.h"

CodeWriter::CodeWriter(std::string &fileName){
      size_t slash = fileName.find_last_of("/\\");
      size_t dot = fileName.find_last_of(".");

      size_t start = (slash == std::string::npos) ? 0 : slash + 1;

      if (dot == std::string::npos ||  dot < start)
      {
        baseName = fileName.substr(start);
      }
      else
      {
        baseName = fileName.substr(start, dot - start);
      }

      outFile.open(std::format("{}.asm", baseName));

}

void CodeWriter::writeArithmetic(std::string command)
{
  if (command == "add") {
    outFile << "add";
  }
}

