#include <iostream>
#include <stdlib.h>
#include <string>

enum Choice {
    rock = 0,
    paper = 1,
    scissor = 2
};

Choice getChoiceFromString(const std::string& choice) {
    if (choice == "rock") return rock;
    if (choice == "paper") return paper;
    if (choice == "scissor") return scissor;
    throw std::invalid_argument("Invalid choice");
}

std::string getStringFromChoice(Choice choice) {
    switch (choice) {
        case rock: return "rock";
        case paper: return "paper";
        case scissor: return "scissor";
        default: throw std::invalid_argument("Invalid choice");
    }
}

int main() {
    std::string choice;
    int random;
    random = rand() % 3;

    std::cout << "Enter the choice (rock, paper, scissor):\n";
    std::cin >> choice;

    try {
        Choice userChoice = getChoiceFromString(choice);
        Choice randomChoice = static_cast<Choice>(random);

        std::cout << "Random choice: " << getStringFromChoice(randomChoice) << "\n";
        std::cout << "User choice: " << getStringFromChoice(userChoice) << "\n";

        if (randomChoice == userChoice) {
            std::cout << "It's a tie!\n";
        } else if ((userChoice == rock && randomChoice == scissor) ||
                   (userChoice == paper && randomChoice == rock) ||
                   (userChoice == scissor && randomChoice == paper)) {
            std::cout << "You win!\n";
        } else {
            std::cout << "You lose!\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}