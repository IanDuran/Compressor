//
// Created by Ian on 12-Jan-18.
//

#include "../../header/io/FileManager.h"
#include <fstream>
#include <iostream>

char *FileManager::readFile(std::string route, int* size) {
    std::ifstream input(route, std::ifstream::in | std::ifstream::binary);

    //Getting file's size
    std::streampos begin, end;
    begin = input.tellg();
    input.seekg(0, std::ifstream::end);
    end = input.tellg();
    *size = (int)(end - begin);

    //Repositioning cursor
    input.seekg(0, std::ifstream::beg);

    //Reading bytes
    char* fileBytes = new char[*size];
    input.read(fileBytes, *size);
    input.close();
    return fileBytes;
}

void FileManager::writeToFile(std::string route, char* bytes, int size) {
    std::ofstream output(route, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
    for (int i = 0; i < size; ++i) {
        output << bytes[i];
    }
    output.close();
}
