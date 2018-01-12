#include <iostream>
#include "header/structure/PriorityQueue.h"
#include "header/io/BitWriter.h"
#include "header/io/FileManager.h"
int main() {
    FileManager fm;
    int size;
    fm.readFile("C:\\Users\\Ian\\Dropbox\\Trabajos\\Redes\\Server.py", &size);
    return 0;
}