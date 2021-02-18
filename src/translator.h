#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <map>
#include <string>

class Translator
{
    std::map<char, std::string> *m_alphabet;

    std::string toUpper(std::string input);
    void validateLetters(std::string letters);
    void validateMorse(std::string morse);

public:
    Translator();

    std::string lettersToMorse(std::string letters);
    std::string morseToLetters(std::string morse);
};

#endif
