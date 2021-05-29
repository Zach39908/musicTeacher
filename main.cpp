#include "noteIdentifier.h"

using namespace std;

int main() {
    char input, input2;
    noteIdentifier *n1, *n2;
    
    try {
        n1 = new noteIdentifier("trebleNotation.txt");
    }
    catch(...) {
        cout << "Terminating ..." << endl;
        return 0;
    }

    try {
        n2 = new noteIdentifier("bassNotation.txt");
    }
    catch(...) {
        cout << "Terminating ..." << endl;
        return 0;
    }

    cout << endl << "----------------" << endl << "SONG CREATOR V.1" << endl << "----------------" << endl << endl;

    std::cout << std::endl;
    std::cout << "    /|    /|     /|\n";
    std::cout << "   / |   / |    / |\n";
    std::cout << "  |  |  |  |   |  |\n";
    std::cout << "  | ()  | ()   | ()\n";
    std::cout << " ()    ()     ()   \n";
    std::cout << std::endl;

    Menu mainMenu("MAIN MENU");
    mainMenu.add("Note Identifier", 'n');
    mainMenu.add("Chord Identifier", 'c');
    mainMenu.add("Quit", 'q');

    while(input != 'q') {
        input = mainMenu.displayAndRead();

        switch(input) {
            case 'n':
            while(input2 != 'b' || input2 != 't' || input2 == 'B' || input2 == 'T') {
                cout << "Bass Clef (b) or Treble Clef (t): "; cin >> input2;
                if(input2 == 'b' || input2 == 'B') {
                    cout << endl;
                    n2->noteMenu();
                    break;
                }
                else if(input2 == 't' || input2 == 'T') {
                    cout << endl;
                    n1->noteMenu();
                    break;
                }
                else if(input2 == 'q') {
                    break;
                }
                else {
                    cout << endl << "Unknown Selecion, Try Again." << endl << endl;
                }
            }
            cout << endl;
            break;

            case 'c':
            cout << "Still Developing Chord Identifier..." << endl << endl;
            break;

            case 'q':
            return 0;
        }
    }
}
