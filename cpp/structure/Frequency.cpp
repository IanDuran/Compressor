//
// Created by Ian on 16-Jan-18.
//

#include "../../header/structure/Frequency.h"

Frequency::Frequency(char character, int frequency) {
    this->character = character;
    this->frequency = frequency;
}

Frequency::Frequency(int frequency) {
    this->character = 0;
    this->frequency = frequency;
}

int Frequency::getFrequency() {
    return this->frequency;
}

char Frequency::getCharacter() {
    return this->character;
}
