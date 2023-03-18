CFLAGS = -Wall -std=c++17

output: main.o morseTree.o
	g++ $(CFLAGS) main.o morseTree.o -o output

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp

morseTree.o: morseTree.cpp morseTree.hpp
	g++ -c $(CFLAGS) morseTree.cpp

test_tree: test_morseTree.o morseTree.o
	g++ $(CFLAGS) test_morseTree.o morseTree.o -o test_tree

test_morseTree.o: test_morseTree.cpp
	g++ -c $(CFLAGS) test_morseTree.cpp

clean:
	rm *.o output test_tree