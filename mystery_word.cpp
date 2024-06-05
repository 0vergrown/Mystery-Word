#include <iostream> // Includes the input/output stream library
#include <string> // Includes the string library to use string data type
#include <cstdlib> // Includes libraries for general purpose functions, including random number generation
#include <ctime> // Includes the time library to work with time-related functions
#include <Windows.h> // Includes the Windows-specific header for Windows API functions

using namespace std; // Uses the standard namespace to avoid typing 'std::' before standard functions and types

int main() {

    // Print the game title and instructions
    cout << "   Mystery Word!  " << endl;
    cout << "  ===============  " << endl;
    cout << "ENTER = Play | ESC = Quit" << endl;

    // Infinite loop to keep checking if the player wants to play or quit
    while (true) {

        // Check if the ESC key is pressed to quit the game
        if (GetAsyncKeyState(VK_ESCAPE)) {
            cout << "You Quit The Game!" << endl;
            return 0; // Exit the program
        }

        // Check if the ENTER key is pressed to start the game
        if (GetAsyncKeyState(VK_RETURN)) {
            cout << "Let's Play!" << endl;

            // Initialize random seed based on the current time
            srand(time(0));

            // Array of possible words to guess
            const string word_list[30] = {
              "bad",
              "easy",
              "lol",
              "Hurt",
              "gay",
              "code",
              "hate",
              "kill",
              "ice",
              "fire",
              "icecream",
              "hangman",
              "destroy",
              "computer",
              "book",
              "dictionary",
              "technology",
              "power",
              "thunder",
              "controller",
              "dexterity",
              "keyboard",
              "thunderous",
              "blizzard",
              "hazardous",
              "algorithm",
              "destruction",
              "operation",
              "assignment",
              "despicable"
            };

            // Select a random word from the list
            string word = word_list[rand() % 30];

            // Create a masked word filled with dashes
            string masked_word(word.length(), '-');

            // Number of allowed incorrect guesses
            int attempts = 6;

            // Display the masked word and invite player to guess
            cout << "Let's Play! Guess the word: " << masked_word << endl;

            // Game loop runs as long as there are attempts left or word is not guessed
            while (attempts > 0 && masked_word != word) {
                cout << "Enter your guess (one letter): ";
                char guess;
                cin >> guess;

                // Flag to check if the guessed letter is in the word
                bool found = false;
                for (int if_letter_position = 0; if_letter_position < word.length(); if_letter_position++) {
                    if (word[if_letter_position] == guess) {
                        masked_word[if_letter_position] = guess; // Reveal the letter in the masked word
                        found = true;
                    }
                }

                // Handle incorrect guesses
                if (!found) {
                    attempts--; // Decrease the number of attempts left
                    cout << "Wrong guess! " << attempts << " attempts left." << endl;
                }
                else {
                    cout << "Good guess!" << endl;
                }

                // Display the current state of the guessed word
                cout << "Current word: " << masked_word << endl;

                // Check if the word is completely guessed
                if (masked_word == word) {
                    cout << "Congratulations! You guessed the word: " << word << endl;
                    break; // Exit the loop if word is guessed correctly
                }

                // Handle running out of attempts
                if (attempts == 0) {
                    cout << "Out of attempts! The word was: " << word << endl;
                }
            }

            return 0; // Exit after one round for simplicity...
        }
    }
}
