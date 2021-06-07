#include <iostream>
#include "include/messages.h"
#include "include/check.h"
#include "include/game.h"

int main() {
    char name[30];
    int playerScore = 0, botScore = 0;
    greeting(name);
    game(name, playerScore, botScore);
    std::cout << "\nEnd of the game. Press ENTER to close.";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
    return 0;
}