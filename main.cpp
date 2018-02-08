#include <iostream>
#include <map>
#include <string>
#include "header/structure/PriorityQueue.h"
#include "header/io/BitWriter.h"
#include "header/io/FileManager.h"
#include "header/structure/HuffTree.h"
#include "header/structure/Frequency.h"

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

HuffTree<Frequency>* makeTree(int* frequencies){
    PriorityQueue<HuffTree<Frequency>> queue;

    //Generating initial list of Huffman Trees
    for(int i = 0; i < 256; i++){
        if(frequencies[i] > 0) {
            Frequency *frequency = new Frequency((char) i, frequencies[i]);
            HuffTree<Frequency> *huffTree = new HuffTree<Frequency>(frequency);
            queue.enqueue(huffTree, frequencies[i]);
        }
    }

    //Generating main Huffman Tree
    while(queue.getSize() > 1){
        HuffTree<Frequency>* firstTree = queue.dequeue();
        if(queue.getSize() > 0){
            HuffTree<Frequency>* secondTree = queue.dequeue();
            HuffTree<Frequency>* newTree = new HuffTree<Frequency>(new Frequency(firstTree->getRoot()->value->getFrequency() + secondTree->getRoot()->value->getFrequency()), firstTree, secondTree);
            queue.enqueue(newTree, newTree->getRoot()->value->getFrequency());
        }
    }
    return queue.dequeue();
}

int main() {

    FileManager fm;
    int size;
    std::string content = fm.readFile("C:\\Users\\Ian\\Dropbox\\Trabajos\\Redes\\Server.py", &size);
    int* frequencies = getFrequencies(content);
    HuffTree<Frequency> *mainTree = makeTree(frequencies);
    std::map<std::string, Frequency*> *freqMap = new std::map<std::string, Frequency*>();
    mainTree->storeCodes(freqMap);

    std::map<char, std::string> *codeMap = new std::map<char, std::string>();

    for(std::map<std::string, Frequency*>::iterator it = freqMap->begin(); it != freqMap->end(); it++){
        codeMap->insert(std::pair<char, std::string>(it->second->getCharacter(), it->first));
    }

    std::string compressedContent = "";
    for(int i = 0; i < content.size(); i++){
        compressedContent += codeMap->find(content[i])->second;
    }


    //delete freqMap;


    return 0;
}