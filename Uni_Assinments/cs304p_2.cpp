#include <iostream>
#include <cstdlib>
#include <ctime>

class Score {
private:
    int score;

public:
    Score(int initialScore) : score(initialScore) {}

    Score& operator++() {
        ++score;
        return *this;
    }

    Score& operator--() {
        --score;
        return *this;
    }
    Score operator--(int) {
        Score temp = *this;
        score--;
        return temp;
    }

    int getScore() const {
        return score;
    }
};

class GuessingGame {
private:
    int targetNumber;
    Score playerScore;

    int generateRandomNumber() const {
        return rand() % 10 + 1;
    }

public:
    GuessingGame() : playerScore(5) {
        targetNumber = generateRandomNumber();
    }

    void play() {
        std::cout << "Virtual Guessing Game Starts!\n";
        std::cout << "The virtual player will guess a number between 1 and 10.\n";
        std::cout << "Score decreases for incorrect guesses and increases for correct ones.\n";

        int attempt = 1;

        while (playerScore.getScore() > 0) {
            int guess = generateRandomNumber();
            std::cout << "Attempt " << attempt << ": Virtual player guesses " << guess << ". ";

            if (guess > targetNumber) {
                --playerScore;
                std::cout << "Too high! Score decreases. ";
            } else if (guess < targetNumber) {
                playerScore--;
                std::cout << "Too low! Score decreases. ";
            } else {
                ++playerScore;
                std::cout << "Correct! Score increases!\n";
                std::cout << "The virtual player guessed the correct number: " << targetNumber << "\n";
                break;
            }

            std::cout << "Current score: " << playerScore.getScore() << "\n";
            attempt++;
        }

        if (playerScore.getScore() == 0) {
            std::cout << "Game Over! The virtual player ran out of score.\n";
            std::cout << "The correct number was: " << targetNumber << "\n";
        }

        std::cout << "Final score: " << playerScore.getScore() << "\n";
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); 
    GuessingGame game;
    game.play();

    return 0;
}