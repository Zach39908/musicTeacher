#include "menu.h"

Menu::Menu(std::string header) {                              // Constructor
    this->header = header;
}

char Menu::displayAndRead() {                                 // displayAndRead()
    int headerLen = header.length();
    char userInput;
    bool select = true;

    while(select == true) {
        try {
            for(int i=0; i < headerLen+4; i++)
                std::cout << "-";

            std::cout << std::endl << "| " << header << " |" << std::endl;

            for(int i=0; i < headerLen+4; i++)
                std::cout << "-";

            std::cout << std::endl << std::endl;

            for(unsigned int i=0; i < choices.size(); i++) {
                std::cout << i+1 << ". " << choices[i].optionName << "\t(" << choices[i].optionKey << ")" << std::endl;
            }

            std::cout << std::endl << "Choice: "; std::cin >> userInput;
            validate(userInput);
            std::cout << std::endl;
            select = false;
            return userInput;
        }
        catch(...) {
            std::cout << "Try Again." << std::endl << std::endl;
            select = true;
        }
    }
    return '\0';
}

void Menu::validate(char input) {                                     // validate()
    try {
        for(unsigned int i=0; i < choices.size(); i++) {
            if(choices[i].optionKey == input)
                return;
        }

        throw inputExc("Option Not Found.");
    }
    catch(inputExc &error) {
        std::cout << std::endl << "ERROR: " << error.what() << std::endl;
        throw error;
    }
    return;
}

void Menu::add(std::string text, char key) {                          // add()
    menuOptions temp;
    temp.optionName = text;
    temp.optionKey = key;
    choices.push_back(temp);
}

Menu::~Menu() {                                                       // Destructor
    choices.clear();
    header.clear();
}