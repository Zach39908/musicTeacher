#include <string>

// NOTE LL NODE
struct Note {
    std::string noteName;
    std::string noteNotation;
    char noteClef;
    int barAmount;
    Note *next;
    Note *prev;
};

// CHORD LL NODE
struct Chord {
    std::string chordName;
    std::string chordNotation;
    char chordClef;
    int barAmount;
    Chord *next;
    Chord *prev;
};