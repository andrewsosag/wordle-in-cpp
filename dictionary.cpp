#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

// Dictionary Constructor
// Get words from text file using ifstream
// Insert words into set and vector (if valid)
Dictionary::Dictionary(string filename){
    ifstream file(filename);
    string word;
    
    while (getline(file, word)){
        if (isLegalSecretWord(word) && !validWord(word)){
            words.insert(word);
            secrets.push_back(word);
        } else if (!validWord(word)){
            words.insert(word);
        }
    }
    file.close();
}

// Function determines if string is in dictionary
// Returns true if string is already in set
bool Dictionary::validWord(string word) {
    if (words.find(word) != words.end()) {
        return true;
    } else {
        return false;
    }
}

// Returns a random word from secrets vector
// Seeds srand with time(NULL) for randomness
string Dictionary::getLegalSecretWord(){
    srand(time(NULL));
    int randomIndex = rand() % secrets.size();

    return secrets[randomIndex];
}

// Function checks if string parameter only has unique characters
bool Dictionary::isLegalSecretWord(string word){
    bool unique;
    // Brute force comparison of each letter
    // Return true if no letters match
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 5; j++){
            if (word[i] != word[j]) {
                unique = true;
            } else {
                return false;
            }
        }
    }
    return unique;
}

