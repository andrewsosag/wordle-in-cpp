wordle: main.o game.o dictionary.o
	g++ main.o game.o dictionary.o -o wordle

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp game.h
	g++ -c game.cpp

dictionary.o: dictionary.cpp dictionary.h
	g++ -c dictionary.cpp

clean:
	rm *.o wordle