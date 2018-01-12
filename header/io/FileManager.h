//
// Created by Ian on 12-Jan-18.
//

#ifndef COMPRESSOR_FILEMANAGER_H
#define COMPRESSOR_FILEMANAGER_H

#include <string>

class FileManager {
public:
    char* readFile(std::string, int*);
    void writeToFile(std::string, char[], int);
private:
};


#endif //COMPRESSOR_FILEMANAGER_H
