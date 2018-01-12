//
// Created by Ian on 10-Jan-18.
//

#include <fstream>
#include "../../header/io/BitWriter.h"

BitWriter::BitWriter(bool debugMode = false, string route = "") {
    this->debugMode = debugMode;
    this->route = route;
}

void BitWriter::writeBits(string bits) {
    if(debugMode)
        this->writeDebugMode(bits);
    else
        this->writeNormalMode(bits);
}

void BitWriter::writeDebugMode(string bits) {
    ofstream output (route, ofstream::out | ofstream::trunc);
    for (string::iterator it = bits.begin(); it != bits.end(); it++) {
        output << *it;
    }
    output.close();
}

void BitWriter::writeNormalMode(string bits) {
    ofstream output(route, ofstream::out | ofstream::trunc | ofstream::binary);
    output <<  bits.size() % 8;
    for(string::iterator it = bits.begin(); it != bits.end(); it++){
        unsigned char currByte = 0;
        for(int i = 0; i < 8, it != bits.end(); i++, it++){
            if(*it == '0')
                currByte = currByte & (char)0b11111110;
            else
                currByte = currByte | (char)0b00000001;

            currByte <<= 1;
        }
        currByte >>= 1;
        if(it == bits.end()){
            int size = bits.size();
            while(size % 8 != 0){
                currByte <<= 1;
                size++;
            }
            it--;
        }
        output << currByte;
    }
    output.close();
}


