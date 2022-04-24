// Wordle Game written in C++
// by Andrew Sosa Guaita
// main.cpp

#include <iostream>
#include "wordle.h"
#include "dictionary.h"

using namespace std;

int main() {
    cout << "Remake of Wordle (written in C++)" << endl;
    cout << "by Andrew Sosa Guaita" << endl;
    
    // Insert file path to text file containing dictionary
    string filePath = "./words.txt";
    
    // Create game object and commence game
    Wordle game(filePath);
    game.play();

    return 0;
}
