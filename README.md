# Hangman-out
Hangman is a word-guessing game where the player tries to guess a word by suggesting letters within a limited number of guesses. In a C++ implementation of the game, a Question is selected from a file, and the player's guesses are compared to the word, with incorrect guesses leading to the drawing of a stick figure being "hanged". The game continues until the player either correctly guesses the word or runs out of guesses.


A C++ implementation of Hangman game typically involves the following:

Select a Question from a pre-defined text file  of Questions.
Display the word to the player with each letter replaced by a blank space.
Allow the player to input a letter as their guess.
Check if the guessed letter is present in the word and reveal the letters accordingly.
If the guessed letter is incorrect, draw one part of a stick figure until the complete figure is drawn, indicating that the player is "hanged".
Continue the game until the player correctly guesses the word or runs out of guesses.
Display a win or lose message to the player at the end of the game.
