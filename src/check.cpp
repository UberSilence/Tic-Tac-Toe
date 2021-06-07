#include <iostream>
#include "include/messages.h"
#include "include/check.h"
#include "include/game.h"

bool boardFullCheck(char board[3][3]) {
    int counter = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 'X' || board[i][j] == '0') 
                counter = counter + 1;
    if (counter == 9) 
        return true; 
    return false;
}

bool isUsed(char board[3][3], int choice) {
    switch(choice) {
        case 1:
            if (board[0][0] == 'X' || board[0][0] == '0')
                return true;
            else
                return false;
            break;
        case 2:
            if (board[0][1] == 'X' || board[0][1] == '0')
                return true;
            else
                return false;
            break;
        case 3:
            if (board[0][2] == 'X' || board[0][2] == '0')
                return true;
            else
                return false;
            break;
        case 4:
            if (board[1][0] == 'X' || board[1][0] == '0')
                return true;
            else
                return false;
            break;
        case 5:
            if (board[1][1] == 'X' || board[1][1] == '0')
                return true;
            else
                return false;
            break;
        case 6:
            if (board[1][2] == 'X' || board[1][2] == '0')
                return true;
            else
                return false;
            break;
        case 7:
            if (board[2][0] == 'X' || board[2][0] == '0')
                return true;
            else
                return false;
            break;
        case 8:
            if (board[2][1] == 'X' || board[2][1] == '0')
                return true;
            else
                return false;
            break;
        case 9:
            if (board[2][2] == 'X' || board[2][2] == '0')
                return true;
            else
                return false;
            break;
    }
    return false;
}

int winnerCheck(char board[3][3]) {
    // rows checking
    int counting = 0;

    for (int i = 0; i < 3; i++) {
        counting = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')
                counting += 1;
            else if (board[i][j] == '0')
                counting -= 1;
            else
                counting += 0;
        }
        if (counting == 3)
            return true;
        else if (counting == -3)
            return true;
    }

    // columns checking
    for (int i = 0; i < 3; i++) {
        counting = 0;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == 'X')
                counting += 1;
            else if (board[j][i] == '0')
                counting -= 1;
            else
                counting += 0;
        }
        if (counting == 3)
            return true;
        else if (counting == -3)
            return true;
    }

    // 1 diagonal checking
    counting = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][i] == 'X')
            counting += 1;
        else if (board[i][i] == '0')
            counting -= 1;
        else
            counting += 0;
    }
    if (counting == 3)
        return true;
    else if (counting == -3)
        return true;

    // 2 diagonal checking
    counting = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][2-i] == 'X')
            counting += 1;
        else if (board[i][2-i] == '0')
            counting -= 1;
        else
            counting += 0;
    }
    if (counting == 3)
        return true;
    else if (counting == -3)
        return true;

    return false;
}