#include <iostream> // Includes the input/output stream library
#include <string> // Includes the string library to use string data type
#include <cstdlib> // Includes libraries for general purpose functions, including random number generation
#include <ctime> // Includes the time library to work with time-related functions

int main() {

    std::string user_input; // Variable to store user input
    bool exit_game = false; // Boolean flag to control the game loop

    // Print the game title and instructions
    std::cout << "   Mystery Word!  " << '\n';
    std::cout << "  ===============  " << '\n';
    std::cout << "Y = Play | N = Quit" << '\n';
    std::cin >> user_input; // Take initial user input

    // Main game loop continues as long as exit_game is not true
    while (!exit_game) {
        if (user_input == "n") {
            std::cout << "You Quit The Game!" << '\n';
            exit_game = true; // Set exit_game to true, indicating the game should end
            continue; // Skip to the next iteration of the loop, which will then end because exit_game is true
        }

        // If user chooses to play the game
        if (user_input == "y") {
            std::cout << "Let's Play!" << '\n';

            // Initialize random seed based on the current time
            srand(time(0));

            // Array of possible words to guess
            const std::string word_list[30] = {
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
            std::string word = word_list[rand() % 30];

            // Create a masked word filled with dashes
            std::string masked_word(word.length(), '-');

            // Number of allowed incorrect guesses
            int attempts = 6;

            // Display the masked word and invite player to guess
            std::cout << "Let's Play! Guess the word: " << masked_word << '\n';

            // Game loop runs as long as there are attempts left or word is not guessed
            while (attempts > 0 && masked_word != word) {
                std::cout << "Enter your guess (one letter): ";
                char guess;
                std::cin >> guess;

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
                    std::cout << "Wrong guess! " << attempts << " attempts left." << '\n';
                }
                else {
                    std::cout << "Good guess!" << '\n';
                }

                // Display the current state of the guessed word
                std::cout << "Current word: " << masked_word << '\n';

                // Check if the word is completely guessed
                if (masked_word == word) {
                    std::cout << "Congratulations! You guessed the word: " << word << '\n';
                    break; // Exit the loop if word is guessed correctly
                }

                // Handle running out of attempts
                if (attempts == 0) {
                    std::cout << "Out of attempts! The word was: " << word << '\n';
                }
            }

        }

        // Prompt user to play again if they have not chosen to exit
        if (!exit_game) {
            std::cout << "Want To Play Again (y/n): " << '\n';
            std::cin >> user_input; // Take user input to continue or exit
        }
    }
}
