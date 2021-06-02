#include "chordIdentifier.h"

using namespace std;

chordIdentifier::chordIdentifier(string file) : noteIdentifier(file) {}

void chordIdentifier::chordMenu(char select) {
    char input;                                                 
    string userNote;

    Menu chordIdentMenu("CHORD IDENTIFIER MENU");                                     // Creating menu and options for Chord Identifier.

    if(select == 'M') {
        chordIdentMenu.add("Identify a Major Chord", 'i');
        chordIdentMenu.add("Display all Major Chords", 'd');
        chordIdentMenu.add("Browse List of Major Chords", 'b');
        chordIdentMenu.add("Quit to Main Menu", 'q');
    }
    else if(select == 'm') {
        chordIdentMenu.add("Identify a minor chord", 'i');
        chordIdentMenu.add("Display all minor chords", 'd');
        chordIdentMenu.add("Browse List of minor chords", 'b');
        chordIdentMenu.add("Quit to Main Menu", 'q');
    }
    else {
        cout << endl << "Incorrect user selection..." << endl;
        return;
    }

    cout << "'#' = sharps, 'b' = flats, 'x' = double sharps, 'bb' = double flats, '[]' = natural" << endl;

    while(input != 'q') {                                                           // Loop until user quits.
        input = chordIdentMenu.displayAndRead();

        switch(input) {
            case 'i':                                                                                       // If user enters 'M' they enter a Major Chord and it's charted out as a triad.
            cout << "Enter a note for it's major chord: "; cin >> userNote;
            cout << endl;
            if(userNote == "C" || userNote == "B#" || userNote == "c" || userNote == "b#") {                // C and B# are the same note.
                displayNote((*this)[0]);
            }
            else if(userNote == "C#" || userNote == "c#") {
                displayNote((*this)[1]);
            }
            else if(userNote == "D" || userNote == "d") {
                displayNote((*this)[2]);
            }
            else if(userNote == "D#" || userNote == "d#") {
                displayNote((*this)[3]);
            }
            else if(userNote == "E" || userNote == "Fb" || userNote == "e" || userNote == "fb") {           // E and Fb are the same note.
                displayNote((*this)[4]);
            }
            else if(userNote == "F" || userNote == "E#" || userNote == "f" || userNote == "e#") {           // F and E# are the same note.
                displayNote((*this)[5]);
            }
            else if(userNote == "F#"  || userNote == "f#") {
                displayNote((*this)[6]);
            }
            else if(userNote == "G" || userNote == "g") {
                displayNote((*this)[7]);
            }
            else if(userNote == "G#" || userNote == "g#") {
                displayNote((*this)[8]);
            }
            else if(userNote == "A" || userNote == "a") {
                displayNote((*this)[9]);
            }
            else if(userNote == "A#" || userNote == "a#") {
                displayNote((*this)[10]);
            }
            else if(userNote == "B" || userNote == "Cb" || userNote == "b" || userNote == "cb") {           // B and Cb are the same note.
                displayNote((*this)[11]);
            }
            else if(userNote == "Db" || userNote == "db") {
                displayNote((*this)[12]);
            }
            else if(userNote == "Eb" || userNote == "eb") {
                displayNote((*this)[13]);
            }
            else if(userNote == "Gb" || userNote == "gb") {
                displayNote((*this)[14]);
            }
            else if(userNote == "Ab" || userNote == "ab") {
                displayNote((*this)[15]);
            }
            else if(userNote == "Bb" || userNote == "bb") {
                displayNote((*this)[16]);
            }
            else {
                cout << "Note Not Found." << endl;
            }
            cout << endl;
            break;

            case 'd':
            (*this).displayList();
            break;

            case 'b':
            browseList();
            break;

            case 'q':
            return;
        }
    }
}