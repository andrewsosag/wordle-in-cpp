#include "wordle.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
    Constructor
    Dynamically allocates dictionary object
    and picks random word from dictionary
*/
Wordle::Wordle(string filename) {
    dict = new Dictionary(filename); 
    secret = dict->getLegalSecretWord();
}

/*
    Destructor
    Frees dynamically allocated dictionary object
*/
Wordle::~Wordle() {
    delete dict;
}

/*
    Game Interface
    Controls user input and progress of game
*/
void Wordle::play() {
    int numguesses = 0;
    string userGuess;
    bool endGame = false, cheated = false;
    cout << "I'm thinking of a five letter word..." << endl;

    while (!endGame) {
        // Input user guess and increase guess count
        cout << "Your guess? ";
        cin >> userGuess;
        numguesses++;
        
        // Convert user input to lowercase
        for (int i = 0; i < 5; i++){
            userGuess[i] = tolower(userGuess[i]);
        }
        
        // If guess matches secret word, report stats and quit
        if (userGuess.compare(secret) == 0){
            if (cheated == true) {
                cout << "Correct! You got it in " << numguesses << " guesses," << endl;
                cout << "but only by cheating." << endl;
                endGame = true;
            } else {
            cout << "Correct! You got it in " << numguesses << " guesses." << endl;
            endGame = true;
            }
        // If cheat code is entered, output answer
        } else if (userGuess.compare("xxxxx") == 0){
            cout << "Secret Word is: " << secret << endl;
            cheated = true;
        // Else guess is incorrect, report stats
        } else { 
            cout << "Matching: " << countMatchingLetters(userGuess) << endl;
            cout << "In-place: " << countInPlaceLetters(userGuess) << endl;
        }
    }
    return;
}

/*
    Return number of common letters
    Function sorts guess and secret
    and returns the size of their intersection
*/
int Wordle::countMatchingLetters(string guess) {
  string tempSecret = secret;
  sort(guess.begin(), guess.end());
  sort(tempSecret.begin(), tempSecret.end());
  string intersection;
  set_intersection(begin(guess), end(guess), begin(tempSecret), end(tempSecret),
                        back_inserter(intersection));
  return intersection.size();
}

/*
    Function returns letters in correct place
    Compares each index of guess and secret
    to find number of matching indexes
*/
int Wordle::countInPlaceLetters(string guess) {
    int matchCount = 0;
    for (int i = 0; i < 5; i++) {
        if (guess[i] == secret[i]) {
            matchCount++;
        }
    }
    return matchCount;
}