# Wordle in C++

Wordle is a popular web-based game where players try to guess a 5 letter word within 6 tries. After each guess, the player can see how many letters are correct, and how many are in the correct position. Using this information, the player tries to make a more accurate guess on their next attempt.

This is a remake of Wordle in C++98 using OOP

## Setup
1. Download all files except for README.md
2. Compile using "make"
```bash
make
```
3. Run using "./game"
```bash
./game
```

## Usage
1. The computer picks a random five letter word.
2. The player will try to guess the word.
3. If the guess is incorrect, the computer returns how the player performed.
4. The game ends when the player is able to guess the secret word.

Use the cheat code `"xxxxx"` to reveal the secret word.

## How it Works
1. If the correct word is guessed, the program will exit
```c++
// If guess matches secret word, report stats and quit
if (userGuess.compare(secret) == 0){
    cout << "Correct! You got it in " << numguesses << " guesses," << endl;
    endGame = true;
```
2. If the guess is incorrect, the program uses algorithms to calculate how many letters are matching, and how many letters are in the correct position
```c++
cout << "Matching: " << countMatchingLetters(userGuess) << endl;
cout << "In-place: " << countInPlaceLetters(userGuess) << endl;
```
3. The program loops until the player guesses the correct word

