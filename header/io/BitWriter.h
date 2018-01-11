//
// Created by Ian on 10-Jan-18.
//

#ifndef COMPRESSOR_BITWRITER_H
#define COMPRESSOR_BITWRITER_H

#include <string>

using namespace std;

class BitWriter{
private:
    bool debugMode;
    string route;
    void writeDebugMode(string);
    void writeNormalMode(string);
public:
    BitWriter(bool, string);
    void writeBits(string);
};
#endif //COMPRESSOR_BITWRITER_H
