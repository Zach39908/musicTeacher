#include "chordIdentifier.h"

using namespace std;

int main() {
    char input, input2, input3;
    noteIdentifier *n1, *n2;
    chordIdentifier *c1, *c2, *c3, *c4;
    
    try {
        n1 = new noteIdentifier("trebleNotation.txt");
        n2 = new noteIdentifier("bassNotation.txt");
        c1 = new chordIdentifier("trebleMajor.txt");
        c2 = new chordIdentifier("bassMajor.txt");
        c3 = new chordIdentifier("trebleMinor.txt");
        c4 = new chordIdentifier("bassMinor.txt");
    }
    catch(...) {
        cout << "Terminating ..." << endl;
        return 0;
    }

    cout << endl << "-----------------" << endl << "MUSIC TEACHER V.1" << endl << "-----------------" << endl << endl;

    cout << std::endl;
    cout << "    /|    /|     /|\n";
    cout << "   / |   / |    / |\n";
    cout << "  |  |  |  |   |  |\n";
    cout << "  | ()  | ()   | ()\n";
    cout << " ()    ()     ()   \n";
    cout << endl;

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
            while(input2 != 'b' || input2 != 't' || input2 == 'B' || input2 == 'T') {
                cout << "Bass Clef (b) or Treble Clef (t): "; cin >> input2;

                if(input2 == 'b' || input2 == 'B') {
                     while(input3 != 'M' || input3 != 'm') {
                        cout << endl << "Major (M) or minor (m) Chords: "; cin >> input3;

                        if(input3 == 'M') {
                            cout << endl;
                            c2->chordMenu(input3);
                            break;
                        }
                        else if(input3 == 'm') {
                            cout << endl;
                            c4->chordMenu(input3);
                            break;
                        }
                        else if(input3 == 'q') {
                            break;
                        }
                    }
                    break;
                }
                else if(input2 == 't' || input2 == 'T') {
                    while(input3 != 'M' || input3 != 'm') {
                        cout << endl << "Major (M) or minor (m) Chords: "; cin >> input3;

                        if(input3 == 'M') {
                            cout << endl;
                            c1->chordMenu(input3);
                            break;
                        }
                        else if(input3 == 'm') {
                            cout << endl;
                            c3->chordMenu(input3);
                            break;
                        }
                        else if(input3 == 'q') {
                            break;
                        }
                    }
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

            case 'q':
            return 0;
        }
    }
}
