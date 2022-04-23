#include "game.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
// Dynamically allocates dictionary object
// Picks random word from dictionary
Cinco::Cinco(string filename) {
    dict = new Dictionary(filename); 
    secret = dict->getLegalSecretWord();
}

// Destructor
Cinco::~Cinco() {
    // Free dynamically allocated dictionary
    delete dict;
}

// Game interface
void Cinco::play() {
    cout << "I'm thinking of a five letter word..." << endl;
    int numguesses = 0;
    string userGuess;
    bool endGame = false, cheated = false;
    while (!endGame) {
        // Input user guess and increase guess count
        cout << "Your guess? ";
        cin >> userGuess;
        // Convert user input to lowercase
        for (int i = 0; i < 5; i++){
            userGuess[i] = tolower(userGuess[i]);
        }
        numguesses++;

        // if guess matches secret word, report stats and quit
        if (userGuess.compare(secret) == 0){
            if (cheated == true) {
                cout << "Correct! You got it in " << numguesses << " guesses," << endl;
                cout << "but only by cheating." << endl;
                endGame = true;
            } else {
            cout << "Correct! You got it in " << numguesses << " guesses." << endl;
            endGame = true;
            }
        // if cheat code is entered, output answer
        } else if (userGuess.compare("xxxxx") == 0){
            cout << "Secret Word is: " << secret << endl;
            cheated = true;
        // else guess is incorrect, report stats
        } else { 
            cout << "Matching: " << countMatchingLetters(userGuess) << endl;
            cout << "In-place: " << countInPlaceLetters(userGuess) << endl;
        }
    }
    return;
}

// Return number of common letters
int Cinco::countMatchingLetters(string guess) {
  string tempSecret = secret;
  sort(begin(guess), end(guess));
  sort(begin(tempSecret), end(tempSecret));
  string intersection;
  set_intersection(begin(guess), end(guess), begin(tempSecret), end(tempSecret),
                        back_inserter(intersection));
  return intersection.size();
}

// Return number of letters in correct place
int Cinco::countInPlaceLetters(string guess) {
    int matchCount = 0;
    //cout << "'" << guess << "'" << endl;
    //cout << "'" << secret << "'" << endl;
    // If corresponding indexes match, increase count
    for (int i = 0; i < 5; i++) {
        if (guess[i] == secret[i]) {
            matchCount++;
        }
    }
    return matchCount;
}