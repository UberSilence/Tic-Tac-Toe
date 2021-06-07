#ifndef GAME_H
#define GAME_H

void boardInitialization(char board[3][3]);
void clearScreen();
int generateRandomNumber();
int randomizer();
void game(char * name, int playerScore, int botScore);
void resetScore(char * name, int playerScore, int botScore);

#endif