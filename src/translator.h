#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <map>
#include <string>

class Translator
{
    std::map<const char, const std::string> *m_alphabet;

    std::string toUpper(const std::string &input);
    void validateLetters(const std::string &letters);
    void validateMorse(const std::string &morse);

public:
    Translator();

    std::string lettersToMorse(const std::string &letters);
    std::string morseToLetters(const std::string &morse);
};

#endif
