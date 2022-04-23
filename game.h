#ifndef CINCO_H
#define CINCO_H

#include <string>
#include "dictionary.h"

class Cinco{
 public:
  Cinco(std::string filename="");  // or char * or const char *
  ~Cinco();
  void play(); // public interface to play game of cinco
  //std::string getSecret() { return secret; }
  //void setSecret() { secret = dict.getLegalSecretWord(); }
 private:
  // count functions compare string param with the secret word
  int countMatchingLetters(std::string); // find common letters in any order
  int countInPlaceLetters(std::string);  // find common letters in place
  Dictionary *dict; // legal words for the game
  int numguesses; // track number of guesses used
  bool cheated; // flag set to true if cheat code is used
  std::string secret; // word to guess
};

#endif
