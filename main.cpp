#include <iostream>
#include <string>
#include "header/structure/PriorityQueue.h"
#include "header/io/BitWriter.h"
#include "header/io/FileManager.h"
int main() {
    FileManager fm;
    int size;
    std::string content = fm.readFile("C:\\Users\\Ian\\Dropbox\\Trabajos\\Redes\\Server.py", &size);
    std::cout << content << std::endl;
    return 0;
}