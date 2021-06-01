#include "noteIdentifier.h"

using namespace std;

const int noteListSize = 17;

noteIdentifier::noteIdentifier(string fileName) {
    head = NULL;
    last = NULL;
    firstToDisplay = NULL;
    try {
        loadFile(fileName);                                                 // Loads input file and validates / initializes default note list.
    }
    catch(inputExc &err) {
        cout << "Quitting Program..." << endl;                              // Quits if input file is not found.
        throw err;
    }
}

Note* noteIdentifier::operator[](int index) {
    Note* current = head;
    if(index < 0 || index >= noteListSize) {  
        cout << "Error: Invalid Index" << endl; 
        return NULL;
    }
    for(int i=0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return current; 
}

void noteIdentifier::loadFile(string fileName) {
    ifstream noteFile;
    
    try {
        noteFile.open(fileName);

        if(!noteFile.is_open()) {                                           // If input file is not found, throw exception.
            throw inputExc("No Input File Found.");
        }
        defaultList(noteFile);                                              // Initializes default LL of music notes.
    }
    catch(inputExc &error) {                                                 // If exception is thrown, output error message and re-throw to constructor.
        cout << endl << error.what() << endl << endl;
        throw error;
    }
}

void noteIdentifier::addNode(Note *newNode) {
    if(newNode == NULL) {
        return;
    }
    
    if(head == NULL) {                                                      // LL is empty, adding first node.
        newNode->prev = NULL;
        head = newNode;
        last = newNode;
    }
    else {                                                                  // LL is not empty, add new node.
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
}

void noteIdentifier::displayList() {
    Note *current = head;

    for(current = head; current != last; current = current->next) {         // Loop through entire list until it reaches the last node, outputs name and notation for each node.
        cout << current->noteName << endl;
        cout << current->noteNotation << endl << endl;
    }

    cout << current->noteName << endl;                // Outputs last node.
    cout << current->noteNotation << endl << endl;
}

void noteIdentifier::displayNote(Note *temp) {
    cout << temp->noteName << ":" << endl;
    cout << temp->noteNotation << endl;
}

void noteIdentifier::display1() {
    if(head == NULL) {
        return;
    }
    else if(firstToDisplay == NULL) {
        return;
    }
    else {
        displayNote(firstToDisplay);
        cout << endl;
    }
}

void noteIdentifier::goToFirst() {
    if(head == NULL) {
        return;
    }
    else {
        firstToDisplay = head;
        display1();
    }
}

void noteIdentifier::operator++() {
    if(firstToDisplay == last) {
        return;
    }
    else {
        firstToDisplay = firstToDisplay->next;
        display1();
    }
}

void noteIdentifier::operator--() {
    if(firstToDisplay == head) {
        return;
    }
    else {
        firstToDisplay = firstToDisplay->prev;
        display1();
    }
}

void noteIdentifier::browseList() {
    char userSelect;

    Menu browseMenu("BROWSE LIST");
    browseMenu.add("Next Note", '>');
    browseMenu.add("Previous Note", '<');
    browseMenu.add("Quit to Note Identifier", 'q');

    goToFirst();

    while(userSelect != 'q') {
        userSelect = browseMenu.displayAndRead();

        switch(userSelect) {
            case '>':
            ++(*this);
            break;

            case '<':
            --(*this);
            break;

            case 'q':
            return;
        }
    }
}

noteIdentifier::~noteIdentifier() {
    Note *current = NULL;                                                   // Set temporary "current" pointer to the head node.

    for(current = head; current != NULL; current = current->next) {         // Moves head the to next node, deletes the current node, remaps current to the new head node.
        head = head->next;
        delete current;
        current = head;
    }

    current = NULL;
    head = NULL;
    last = NULL;
}

string noteIdentifier::writeNotation(ifstream &inputFile, Note *temp) {
    string letter, notation, line;

    while(getline(inputFile, letter)) {                                                 // Search noteNotation.txt until we reach the parameter Note's noteName.
        letter.pop_back();
        
        if(letter == temp->noteName) {
            break;
        }
        
        letter.clear();
    }

    if(temp->noteName == "Bb") {                                                        // If the parameter's noteName is "Bb" then we're on the last node in the txt file, so we loop until eof.
        while(getline(inputFile, line)) {
            notation += line;                                                           // Concenate string notation with "line" for each new getline.
            notation += "\n";                                                           // Add on a "\n" to the end of each line in the string.
        }

        notation.pop_back();
    }

    while(getline(inputFile, line)) {                                                   // Otherwise, loop through lines until we reach the next node's noteName in the txt file.
        line.pop_back();

        if(line == temp->next->noteName) {
            notation.pop_back();
            line.pop_back();
            line.pop_back();
            break;
        }

        notation += line;                                                               // Concenate string notation with "line" for each new getline.
        notation += "\n";                                                               // Add on a "\n" to the end of each line in the string.
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    return notation;
}

// noteMenu() function below (large)

void noteIdentifier::noteMenu() {
    char input;                                                 
    string userNote;

    Menu noteIdentMenu("NOTE IDENTIFIER MENU");                                     // Creating menu and options for Note Identifier.
    noteIdentMenu.add("Identify a note", 'i');
    noteIdentMenu.add("Display all 12 Notes", 'd');
    noteIdentMenu.add("Browse List", 'b');
    noteIdentMenu.add("Quit to Main Menu", 'q');

    cout << "'#' = sharps, 'b' = flats, 'x' = double sharps, 'bb' = double flats, '[]' = natural" << endl << endl;

    while(input != 'q') {                                                           // Loop until user quits.
        input = noteIdentMenu.displayAndRead();

        switch(input) {
            case 'i':                                                                                       // If user enters 'i' they enter a note and it's charted out.
            cout << "Enter a note: "; cin >> userNote;
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
            cout << endl;
            break;

            case 'b':
            browseList();
            break;

            case 'q':
            return;
        }
    }
}

// defaultList() function below (large):

void noteIdentifier::defaultList(ifstream &iFile) {
    Note *c = new Note;                                                                // Initialize data member values for each music note to go in the default list.     C (0)
    c->noteName = "C";
    c->noteClef = 'T';
    c->barAmount = 1;
    addNode(c);

    Note *cSharp = new Note;                                                           // C# (1)
    cSharp->noteName = "C#";
    cSharp->noteClef = 'T';
    cSharp->barAmount = 1;
    addNode(cSharp);

    Note *d = new Note;                                                                // D (2)
    d->noteName = "D";
    d->noteClef = 'T';
    d->barAmount = 1;
    addNode(d);

    Note *dSharp = new Note;                                                           // D# (3)
    dSharp->noteName = "D#";
    dSharp->noteClef = 'T';
    dSharp->barAmount = 1;
    addNode(dSharp);

    Note *e = new Note;                                                                // E (4)
    e->noteName = "E";
    e->noteClef = 'T';
    e->barAmount = 1;
    addNode(e);

    Note *f = new Note;                                                                // F (5)
    f->noteName = "F";
    f->noteClef = 'T';
    f->barAmount = 1;
    addNode(f);

    Note *fSharp = new Note;                                                           // F# (6)
    fSharp->noteName = "F#";
    fSharp->noteClef = 'T';
    fSharp->barAmount = 1;
    addNode(fSharp);

    Note *g = new Note;                                                                // G (7)
    g->noteName = "G";
    g->noteClef = 'T';
    g->barAmount = 1;
    addNode(g);

    Note *gSharp = new Note;                                                           // G# (8)
    gSharp->noteName = "G#";
    gSharp->noteClef = 'T';
    gSharp->barAmount = 1;
    addNode(gSharp);

    Note *a = new Note;                                                                // A (9)
    a->noteName = "A";
    a->noteClef = 'T';
    a->barAmount = 1;
    addNode(a);

    Note *aSharp = new Note;                                                           // A# (10)
    aSharp->noteName = "A#";
    aSharp->noteClef = 'T';
    aSharp->barAmount = 1;
    addNode(aSharp);

    Note *b = new Note;                                                                // B (11)
    b->noteName = "B";
    b->noteClef = 'T';
    b->barAmount = 1;
    addNode(b);

    Note *dFlat = new Note;                                                                // Db (12)
    dFlat->noteName = "Db";
    dFlat->noteClef = 'T';
    dFlat->barAmount = 1;
    addNode(dFlat);

    Note *eFlat = new Note;                                                                // Eb (13)
    eFlat->noteName = "Eb";
    eFlat->noteClef = 'T';
    eFlat->barAmount = 1;
    addNode(eFlat);

    Note *gFlat = new Note;                                                                // Gb (14)
    gFlat->noteName = "Gb";
    gFlat->noteClef = 'T';
    gFlat->barAmount = 1;
    addNode(gFlat);

    Note *aFlat = new Note;                                                                // Ab (15)
    aFlat->noteName = "Ab";
    aFlat->noteClef = 'T';
    aFlat->barAmount = 1;
    addNode(aFlat);

    Note *bFlat = new Note;                                                                // Bb (16)
    bFlat->noteName = "Bb";
    bFlat->noteClef = 'T';
    bFlat->barAmount = 1;
    addNode(bFlat);

    c->noteNotation = writeNotation(iFile, c);                         // Initializing noteNotation string for each default note in the list.
    cSharp->noteNotation = writeNotation(iFile, cSharp);
    d->noteNotation = writeNotation(iFile, d);
    dSharp->noteNotation = writeNotation(iFile, dSharp);
    e->noteNotation = writeNotation(iFile, e);
    f->noteNotation = writeNotation(iFile, f);
    fSharp->noteNotation = writeNotation(iFile, fSharp);
    g->noteNotation = writeNotation(iFile, g);
    gSharp->noteNotation = writeNotation(iFile, gSharp);
    a->noteNotation = writeNotation(iFile, a);
    aSharp->noteNotation = writeNotation(iFile, aSharp);
    b->noteNotation = writeNotation(iFile, b);
    dFlat->noteNotation = writeNotation(iFile, dFlat);
    eFlat->noteNotation = writeNotation(iFile, eFlat);
    gFlat->noteNotation = writeNotation(iFile, gFlat);
    aFlat->noteNotation = writeNotation(iFile, aFlat);
    bFlat->noteNotation = writeNotation(iFile, bFlat);
}