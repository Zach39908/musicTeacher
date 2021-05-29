all:
	g++ main.cpp noteIdentifier.cpp menu.cpp -g -Wall -Wpedantic -Wextra
	
clean:
	rm a.out