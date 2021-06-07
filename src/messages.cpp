#include <iostream>
#include "include/messages.h"
#include "include/check.h"
#include "include/game.h"

void endMessage(char winner, char player, char bot, int playerScore, int botScore, char * name) {
    if (winner == player) {
        std::cout << "Congratulations! You won this Tic-Tac-Toe match against my tremendous, phenomenal, great Bot.\n\n";
        playerScore += 1;
        menu(name, playerScore, botScore);
    } else if (winner == bot) {
        std::cout << "Unfortunately, you lost this Tic-Tac-Toe match against a Bot, be ashamed!\n\n";
        botScore += 1;
        menu(name, playerScore, botScore);
    } else {
        std::cout << "Draw! No one won this match, I thought you would do better...\n\n";
        menu(name, playerScore, botScore);
    }  
}

void greeting(char * name) {
    std::cout << "******************************\n";
    std::cout << "****** TIC-TAC-TOE GAME ******\n";
    std::cout << "******  BY UBERSILENCE  ******\n";
    std::cout << "******    UPDATE 1.0    ******\n";
    std::cout << "******************************\n";
    std::cout << "\nEnter your nickname: ";
    std::cin >> name;
    clearScreen();
    int playerScore = 0, botScore = 0;
    menu(name, playerScore, botScore);
}

void menu(char * name, int playerScore, int botScore) {
    int choice;
    std::cout << "****** CURRENT SCORE: " << name << " (" << playerScore << "-" << botScore << ") Bot ******\n";
    std::cout << "* What do you want to do next, " << name << "?\n";
    std::cout << "1 - Play another game with the bot.\n";
    std::cout << "2 - Reset your score.\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        game(name, playerScore, botScore);
        break;
    case 2:
        resetScore(name, playerScore, botScore);
        break;
    default:
        break;
    }
}

void boardShow(char board[3][3]) {
    std::cout << "- " << "- " << "- " << "- " << "- " << "- " << "- " << std::endl;
    std::cout << "| " << "  | " << "  | " << "  |" << std::endl;
    std::cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << std::endl;
    std::cout << "| " << "  | " << "  | " << "  |" << std::endl;
    std::cout << "- " << "- " << "- " << "- " << "- " << "- " << "- " << std::endl;
    std::cout << "| " << "  | " << "  | " << "  |" << std::endl;
    std::cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << std::endl;
    std::cout << "| " << "  | " << "  | " << "  |" << std::endl;
    std::cout << "- " << "- " << "- " << "- " << "- " << "- " << "- " << std::endl;
    std::cout << "| " << "  | " << "  | " << "  |" << std::endl;
    std::cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << std::endl;
    std::cout << "| " << "  | " << "  | " << "  |" << std::endl;
    std::cout << "- " << "- " << "- " << "- " << "- " << "- " << "- " << std::endl;
}