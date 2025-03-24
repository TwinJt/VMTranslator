cmake_minimum_required(VERSION 3.30)
project(VM_Translator)

set(CMAKE_CXX_STANDARD 26)

add_executable(VM_Translator main.cpp
        Parser.cpp
        Parser.h
        CodeWriter.cpp
        CodeWriter.h)
