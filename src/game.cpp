#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "include/messages.h"
#include "include/check.h"
#include "include/game.h"

void boardInitialization(char board[3][3]) {
    int k = 49;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                    board[i][j] = char(k);
                    k++;
            }
}

void resetScore(char * name, int playerScore, int botScore) {
    playerScore = 0;
    botScore = 0;
    std::cout << "New score: " << name << " (0-0) Bot";
    menu(name, playerScore, botScore);
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int generateRandomNumber() {
    return (rand() % 9) + 1;
}

int randomizer() {
    return (rand() % 2) + 1;
}

void resetscore() {

}

void game(char * name, int playerScore, int botScore) {
    char board[3][3];
    boardInitialization(board);

    char player,bot,winner;
    bool playerTurn, botTurn;
    bool isTableFull = false;
    bool alreadyUsed;
    bool isWinner = false;
    int choice;

    int n = randomizer();
    if (n == 1) {
        clearScreen();
        std::cout << "The magic begins... You've been chosen to be X. You'll have the first play.\n";
        player = 'X';
        bot = '0';
        playerTurn = true;
        botTurn = false;
        std::this_thread::sleep_for (std::chrono::seconds(3));
    } else if (n == 2) {
        clearScreen();
        std::cout << "The magic begins... You've been chosen to be 0. What a shame, you'll have the second play.\n";
        player = '0';
        bot = 'X';
        playerTurn = false;
        botTurn = true;
        std::this_thread::sleep_for (std::chrono::seconds(3));
    }

    while(isTableFull == false && isWinner == false) {
        if (playerTurn == true) {
            boardShow(board);
            std::cout << "It's your turn! Pick a number in order to replace it with " << player << ".";
            do {
            std::cout << "\nYour choice: ";
            std::cin >> choice;
            alreadyUsed = isUsed(board, choice);
            } while (alreadyUsed == true);
            switch(choice) {
                case 1:
                    board[0][0] = player;
                    break;
                case 2:
                    board[0][1] = player;
                    break;
                case 3:
                    board[0][2] = player;
                    break;
                case 4:
                    board[1][0] = player;
                    break;
                case 5:
                    board[1][1] = player;
                    break;
                case 6:
                    board[1][2] = player;
                    break;
                case 7:
                    board[2][0] = player;
                    break;
                case 8:
                    board[2][1] = player;
                    break; 
                case 9:
                    board[2][2] = player;
                    break;
            }
            playerTurn = false;
            botTurn = true;
        } else if (botTurn == true) {
            boardShow(board);
            std::cout << "It's Bot's turn now. Wait until he picks a spot to replace it with " << bot << "\n";
            do {
            choice = generateRandomNumber();
            alreadyUsed = isUsed(board, choice);
            } while (alreadyUsed == true);
            std::this_thread::sleep_for (std::chrono::seconds(3));
            switch(choice) {
                case 1:
                    board[0][0] = bot;
                    break;
                case 2:
                    board[0][1] = bot;
                    break;
                case 3:
                    board[0][2] = bot;
                    break;
                case 4:
                    board[1][0] = bot;
                    break;
                case 5:
                    board[1][1] = bot;
                    break;
                case 6:
                    board[1][2] = bot;
                    break;
                case 7:
                    board[2][0] = bot;
                    break;
                case 8:
                    board[2][1] = bot;
                    break; 
                case 9:
                    board[2][2] = bot;
                    break;
            }
            playerTurn = true;
            botTurn = false;
        }
        clearScreen();
        isTableFull = boardFullCheck(board);
        isWinner = winnerCheck(board);
    }
    boardShow(board);
    if (isTableFull == false) {
        if (playerTurn ==  false && botTurn == true)
            winner = player;
        else if (playerTurn == true && botTurn == false)
            winner = bot;
    } else
        winner = 'Z';

    endMessage(winner, player, bot, playerScore, botScore, name);
}