#include "translator.h"
#include "window.h"

#include <iostream>
#include <string>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    app.exec();
}

/*
std::string getInput();

int main(int argc, char *argv[])
{
    if (argc == 1) {
	int sel = 1;
	std::string input;
	std::string translated;
	Translator t;

	std::cout << "Select operation:\n" << std::endl;
	std::cout << "1. Letters to morse" << std::endl;
	std::cout << "2. Morse to letters\n" << std::endl;
	std::cout << ": ";
	std::cin >> sel;
	std::cin.ignore();

	if (sel == 1)
	    std::cout << "Enter letters to translate: ";
	else if (sel == 2)
	    std::cout << "Enter morse code to translate: ";
	else {
	    std::cout << "Invalid input." << std::endl;
	    exit(-1);
	}

	input = getInput();

	if (sel == 1) {
	    try {
		translated = t.lettersToMorse(input);
	    } catch (int e) {
		std::cout << "Invalid letters. Can only consist of A-Z and 0-9." << std::endl;
		exit(-1);
	    }
	} else {
	   try {
		translated = t.morseToLetters(input);
	    } catch (int e) {
		std::cout << "Invalid morse code. Can only consist of '.', '-' and ' '." << std::endl;
		exit(-1);
	    }
	}

	std::cout << input << " translates to:" << std::endl;
	std::cout << translated << std::endl;
    } else {

    }
}


std::string getInput()
{
    std::string input;
    std::getline(std::cin, input);

    return input;
}
*/
