#include <iostream>
#include "game.h"
#include "dictionary.h"

using namespace std;

int main() {
    cout << "Remake of Wordle (written in C++)" << endl;
    cout << "by Andrew Sosa Guaita" << endl;
    
    // Create path to text file containing words
    string filePath = "./words.txt";
    
    // Create game object and commence game
    Cinco game(filePath);
    game.play();

    return 0;
}
