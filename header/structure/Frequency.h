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
    friend bool operator < (const Frequency &, const Frequency &);
    friend bool operator >= (const Frequency &, const Frequency &);
};

bool operator < (const Frequency &thisFrequency, const Frequency &otherFrequency){
    return thisFrequency.frequency < otherFrequency.frequency;
}

bool operator >= (const Frequency &thisFrequency, const Frequency &otherFrequency){
    return thisFrequency.frequency >= otherFrequency.frequency;
}
#endif //COMPRESSOR_FREQUENCY_H
