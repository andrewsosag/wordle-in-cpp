game: main.o wordle.o dictionary.o
	g++ main.o wordle.o dictionary.o -o game

main.o: main.cpp
	g++ -c main.cpp

wordle.o: wordle.cpp wordle.h
	g++ -c wordle.cpp

dictionary.o: dictionary.cpp dictionary.h
	g++ -c dictionary.cpp

clean:
	rm *.o wordle