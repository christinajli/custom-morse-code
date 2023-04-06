CFLAGS = -Wall -std=c++17

output: main.o morseTree.o
	g++ $(CFLAGS) main.o morseTree.o -o output

main.o: translate.hpp main.cpp
	g++ -c $(CFLAGS) main.cpp

morseTree.o: morseTree.cpp morseTree.hpp
	g++ -c $(CFLAGS) morseTree.cpp

test_tree: test_morseTree.o morseTree.o
	g++ $(CFLAGS) test_morseTree.o morseTree.o -o test_tree

test_morseTree.o: test_morseTree.cpp
	g++ -c $(CFLAGS) test_morseTree.cpp

test_main: test_translate.o morseTree.o
	g++ $(CFLAGS) test_translate.o morseTree.o -o test_main

test_translate.o: translate.hpp test_translate.cpp
	g++ -c $(CFLAGS) test_translate.cpp

clean:
	rm *.o output test_tree test_main