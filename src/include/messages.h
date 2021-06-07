#ifndef MESSAGES_H
#define MESSAGES_H

void endMessage(char winner, char player, char bot, int playerScore, int botScore, char * name);
void greeting(char * name);
void menu(char * name, int playerScore, int botScore);
void boardShow(char board[3][3]);

#endif