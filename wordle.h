#ifndef WORDLE_H
#define WORDLE_H

#include <string>
#include "dictionary.h"

class Wordle{
 public:
  Wordle(std::string filename=""); // game constructor
  ~Wordle(); // game destructor
  void play(); // public interface to play game
 private:
  int countMatchingLetters(std::string); // find common letters in any order
  int countInPlaceLetters(std::string);  // find common letters in place
  Dictionary *dict; // legal words for the game
  int numguesses; // track number of guesses used
  bool cheated; // flag set to true if cheat code is used
  std::string secret; // word to guess
};

#endif
