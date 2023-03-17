CFLAGS = -Wall -std=c++17
output: main.o morseTree.o
	g++ $(CFLAGS) main.o morseTree.o -o output

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp

morseTree.o: morseTree.cpp morseTree.hpp
	g++ -c $(CFLAGS) morseTree.cpp

clean:
	rm *.o output