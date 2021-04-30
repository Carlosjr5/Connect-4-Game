/*
Created by Carlos Jimenez Rodriguez, Last date modifided: 29/04/2021.
*/

//Getting the definition of each characters.
#include "conect4.h"

//Checks for the conect 4 vertically
int countUp(int x, int y, char player, char board[ROW][COLUMNS]) {
    int yStart = (y - Conect >= 0) ? y - Conect + 1 : 0;
    int count = 0;
    for (; yStart <= y; yStart++) {
        if (board[yStart][x] == player) {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

//Checks for the conect 4 horrizontally 
int countRight(int x, int y, char player, char board[ROW][COLUMNS]) {
    int xEnd = (x + Conect < COLUMNS) ? x + Conect - 1 : COLUMNS - 1;
    int count = 0;
    for (; x <= xEnd; x++) {
        if (board[y][x] == player) {
            count++;
        } else {
            count = 0;
        }
    }
    return count;
}

//Checks for the conect 4 diagonal up to the right
int countUpRight(int x, int y, char player, char board[ROW][COLUMNS]) {
    int xEnd = (x + Conect < COLUMNS) ? x + Conect - 1 : COLUMNS - 1;
    int yStart = (y - Conect >= 0) ? y - Conect + 1 : 0;
    int count = 0;
    while (x <= xEnd && yStart <= y) {
        if (board[y][x] == player) {
            count++;
        } else {
            count = 0;
        }
        x++;
        y--;
    }
    return count;
}

//Checks for the conect 4 diagonal down right
int countDownRight(int x, int y, char player, char board[ROW][COLUMNS]) {
    int xEnd = (x + Conect < COLUMNS) ? x + Conect - 1 : COLUMNS - 1;
    int yEnd = (y + Conect < ROW) ? y + Conect - 1 : ROW - 1;
    int count = 0;
    while (x <= xEnd && y <= yEnd) {
        if (board[y][x] == player) {
            count++;
        } else {
            count = 0;
        }
        x++;
        y++;
    }
    return count;
}

//Wins who has 4 Conected up, right, up right or down right.
//Checks for the 4 pieces conected aligned. 
int winner(char player, char board[ROW][COLUMNS]) {

    int y;
    for (y = 0; y < ROW; y++) {
        int x;
        for (x = 0; x < COLUMNS; x++) {
            int COUNTUP = countUp(x, y, player, board);
            if (COUNTUP >= Conect) {
                return ConectUp;
            }
            if (countRight(x, y, player, board) >= Conect) {
                return ConectRight;
            }
            if (countUpRight(x, y, player, board) >= Conect) {
                return ConectUpRight;
            }
            if (countDownRight(x, y, player, board) >= Conect) {
                return ConectDownRight;
            }
        }
    }
    return NoConect;
}
