#include "noteIdentifier.h"

using namespace std;

class chordIdentifier : public noteIdentifier {
    Note *head;
    Note *last;
    Note *firstToDisplay;

    public:

    chordIdentifier(string);
    void chordMenu(char);
};