#include <iostream>
#include <vector>
#include <string>
#include "exception.h"

struct menuOptions {
    std::string optionName;
    char optionKey;
};

class Menu {
    std::string header;
    std::vector<menuOptions> choices;

    public :
    
    Menu(std::string header);
    char displayAndRead();
    void validate(char input);
    void add(std::string text, char key);
    ~Menu();
};