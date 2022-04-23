#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <set>
#include <vector>

class Dictionary{
  public:
    Dictionary(std::string filename); // construct object with text file 
    bool validWord(std::string word); // check if word is in Dictionary 
    std::string getLegalSecretWord(); // return a random word (w/out repeated letters)
  private:
    bool isLegalSecretWord(std::string word); // check if word only has unique letters
    std::set<std::string> words; //all words in dictionary
    std::vector<std::string> secrets;	//only words from dictionary with unique letters
};

#endif