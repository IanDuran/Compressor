#include <iostream>
#include "header/structure/PriorityQueue.h"
#include "header/io/BitWriter.h"
int main() {
    BitWriter bw(false, "C:\\Users\\Ian\\CLionProjects\\Compressor\\CompressionOutput\\Output.txt");
    bw.writeBits("01000001");
    return 0;
}