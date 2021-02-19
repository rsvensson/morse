#include "translator.h"
#include <algorithm>
#include <list>

Translator::Translator()
    : m_alphabet(new std::map<const char, const std::string>)
{
    m_alphabet->insert(std::pair<const char, const std::string>('A', ".-"));
    m_alphabet->insert(std::pair<const char, const std::string>('B', "-..."));
    m_alphabet->insert(std::pair<const char, const std::string>('C', "-.-."));
    m_alphabet->insert(std::pair<const char, const std::string>('D', "-.."));
    m_alphabet->insert(std::pair<const char, const std::string>('E', "."));
    m_alphabet->insert(std::pair<const char, const std::string>('F', "..-."));
    m_alphabet->insert(std::pair<const char, const std::string>('G', "--."));
    m_alphabet->insert(std::pair<const char, const std::string>('H', "...."));
    m_alphabet->insert(std::pair<const char, const std::string>('I', ".."));
    m_alphabet->insert(std::pair<const char, const std::string>('J', ".---"));
    m_alphabet->insert(std::pair<const char, const std::string>('K', "-.-"));
    m_alphabet->insert(std::pair<const char, const std::string>('L', ".-.."));
    m_alphabet->insert(std::pair<const char, const std::string>('M', "--"));
    m_alphabet->insert(std::pair<const char, const std::string>('N', "-."));
    m_alphabet->insert(std::pair<const char, const std::string>('O', "---"));
    m_alphabet->insert(std::pair<const char, const std::string>('P', ".--."));
    m_alphabet->insert(std::pair<const char, const std::string>('Q', "--.-"));
    m_alphabet->insert(std::pair<const char, const std::string>('R', ".-."));
    m_alphabet->insert(std::pair<const char, const std::string>('S', "..."));
    m_alphabet->insert(std::pair<const char, const std::string>('T', "-"));
    m_alphabet->insert(std::pair<const char, const std::string>('U', "..-"));
    m_alphabet->insert(std::pair<const char, const std::string>('V', "...-"));
    m_alphabet->insert(std::pair<const char, const std::string>('W', ".--"));
    m_alphabet->insert(std::pair<const char, const std::string>('X', "-..-"));
    m_alphabet->insert(std::pair<const char, const std::string>('Y', "-.--"));
    m_alphabet->insert(std::pair<const char, const std::string>('Z', "--.."));
    m_alphabet->insert(std::pair<const char, const std::string>('1', ".----"));
    m_alphabet->insert(std::pair<const char, const std::string>('2', "..---"));
    m_alphabet->insert(std::pair<const char, const std::string>('3', "...--"));
    m_alphabet->insert(std::pair<const char, const std::string>('4', "....-"));
    m_alphabet->insert(std::pair<const char, const std::string>('5', "....."));
    m_alphabet->insert(std::pair<const char, const std::string>('6', "-...."));
    m_alphabet->insert(std::pair<const char, const std::string>('7', "--..."));
    m_alphabet->insert(std::pair<const char, const std::string>('8', "---.."));
    m_alphabet->insert(std::pair<const char, const std::string>('9', "----."));
    m_alphabet->insert(std::pair<const char, const std::string>('0', "-----"));
    m_alphabet->insert(std::pair<const char, const std::string>('?', "..--.."));
    m_alphabet->insert(std::pair<const char, const std::string>('!', "..--."));
    m_alphabet->insert(std::pair<const char, const std::string>(',', "--..--"));
    m_alphabet->insert(std::pair<const char, const std::string>('.', ".-.-.-"));
    m_alphabet->insert(std::pair<const char, const std::string>('-', "-....-"));
    m_alphabet->insert(std::pair<const char, const std::string>('(', "-.--."));
    m_alphabet->insert(std::pair<const char, const std::string>(')', "-.--.-"));
    m_alphabet->insert(std::pair<const char, const std::string>('@', ".--.-."));
    m_alphabet->insert(std::pair<const char, const std::string>('/', "-..-."));
    m_alphabet->insert(std::pair<const char, const std::string>('%', ".--.."));
    m_alphabet->insert(std::pair<const char, const std::string>('"', ".-..-."));
    m_alphabet->insert(std::pair<const char, const std::string>('\'', ".----."));
    m_alphabet->insert(std::pair<const char, const std::string>(';', "-.-.-."));
    m_alphabet->insert(std::pair<const char, const std::string>(':', "---..."));
    m_alphabet->insert(std::pair<const char, const std::string>('&', ". ..."));
    m_alphabet->insert(std::pair<const char, const std::string>('$', "...-..-"));
    m_alphabet->insert(std::pair<const char, const std::string>('_', "..--.-"));
    m_alphabet->insert(std::pair<const char, const std::string>(' ', " "));
}

std::string Translator::toUpper(const std::string &input)
{
    std::string uppercase = input;
    std::transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);

    return uppercase;
}

void Translator::validateLetters(const std::string &letters)
{
    for (const char &letter : letters) {
	if (m_alphabet->find(letter) == m_alphabet->cend())
	    throw -1;
    }
}

void Translator::validateMorse(const std::string &morse)
{
    for (const char &el : morse) {
	if (el != '.' && el != '-' && el != ' ')
	    throw -1;
    }
}

std::string Translator::lettersToMorse(const std::string &letters)
{
    validateLetters(toUpper(letters));

    std::string morse;
    for (char &letter : toUpper(letters)) {
	std::map<const char, const std::string>::iterator pair;
	pair = m_alphabet->find(letter);
	morse.append(pair->second);
	morse.append(" ");
    }

    return morse;
}

std::string Translator::morseToLetters(const std::string &morse)
{
    validateMorse(morse);

    int cnt = 0;
    std::list<std::string> elements;
    std::string letters;

    /* Get the individual morse code parts */
    for (size_t i=0; i < morse.length(); i++) {
	if (morse.at(i) == ' ') { // A space signifies the end of a part
	    elements.push_back(morse.substr(cnt, i-cnt));
	    cnt = i+1;
	} else if (i == morse.length() - 1) // Last part doesn't end with space
	    elements.push_back(morse.substr(cnt));
    }

    /* Search for the morse code values in the map */
    for (auto &el : elements) {
	for (auto &it : *m_alphabet) {
	    if (it.second == el) {
		letters.push_back(it.first);
		break;
	    }
	}
    }

    return letters;
}
