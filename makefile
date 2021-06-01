all:
	g++ main.cpp noteIdentifier.cpp chordIdentifier.cpp menu.cpp -g -Wall -Wpedantic -Wextra
	
clean:
	rm a.out