//
// Created by Ian on 16-Jan-18.
//

#ifndef COMPRESSOR_FREQUENCY_H
#define COMPRESSOR_FREQUENCY_H


class Frequency {
private:
    char character;
    int frequency;
public:
    Frequency(char, int);
    explicit Frequency(int);
    int getFrequency();
    char getCharacter();
};

bool operator < (const Frequency &otherFrequency){
    return this->frequency < otherFrequency.frequency;
}

bool operator >= (const Frequency &otherFrequency){
    return this->frequency >= otherFrequency.frequency;
}
#endif //COMPRESSOR_FREQUENCY_H
