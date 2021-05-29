#include <fstream>
#include "notation.h"
#include "menu.h"

using namespace std;

class noteIdentifier {
    Note *head;
    Note *last;
    Note* firstToDisplay;

    public:

    noteIdentifier(std::string);
    Note* operator[](int index);
    std::string writeNotation(std::ifstream &, Note*);
    void addNode(Note*);
    void displayList();
    void displayNote(Note*);
    void defaultList(std::ifstream &);
    void browseList();
    void goToFirst();
    void display1();
    void operator++();
    void operator--();
    void loadFile(std::string);
    void noteMenu();
    ~noteIdentifier();
};