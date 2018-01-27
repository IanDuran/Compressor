#include <iostream>
#include <string>
#include "header/structure/PriorityQueue.h"
#include "header/io/BitWriter.h"
#include "header/io/FileManager.h"

int* getFrequencies(std::string bytes){
    auto* frequencies = new int[256];
    for (int j = 0; j < 256; ++j) {
        frequencies[j] = 0;
    }

    for(int i = 0; i < bytes.size(); i++){
        frequencies[(int) bytes[i]]++;
    }
    return frequencies;
}

int main() {
    FileManager fm;
    int size;
    std::string content = fm.readFile("C:\\Users\\Ian\\Dropbox\\Trabajos\\Redes\\Server.py", &size);
    int total = 0;
    int* frequencies = getFrequencies(content);
    for (int i = 0; i < 256; ++i) {
        if(frequencies[i] != 0) {
            std::cout << (char) i << ": " << frequencies[i] << endl;
            total+= frequencies[i];
        }
    }

    std::cout << "Size should be " << size << ": " << total << std::endl;
    return 0;
}