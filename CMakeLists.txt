cmake_minimum_required(VERSION 3.8)
project(Compressor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp header/structure/PriorityQueue.h header/structure/PriorityQueue.h header/io/BitWriter.h cpp/io/BitWriter.cpp header/io/BitReader.h cpp/io/BitReader.cpp header/structure/HuffTree.h cpp/io/FileManager.cpp header/io/FileManager.h cpp/structure/Frequency.cpp header/structure/Frequency.h)
add_executable(Compressor ${SOURCE_FILES})